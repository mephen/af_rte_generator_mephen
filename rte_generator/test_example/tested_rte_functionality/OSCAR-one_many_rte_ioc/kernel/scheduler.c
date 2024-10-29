#include "scheduler.h"
#include "core.h"
#include "resource.h"
#include "spinlock.h"
#include "system.h"
#include "systemcall.h"
#include "timingprot.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "application_Cfg.h"
#include "timingprot_Cfg.h"
#include "spinlock_Cfg.h"
#include "lock.h"
#include "task.h"
#include "application.h"
/* Count leading zeros */
static inline uint8 Clz(uint32 input)
{
    uint32 focus;
    int n = 32, step = 16;
    do
    {
        focus = input >> step;
        if (focus)
        {
            n -= step;
            input = focus;
        }
        step >>= 1;
    } while (step);
    return (n - input);
}

/* Return TaskID of highest-priority task in ready list */
TaskType GetNextTask(void)
{
    int nextPriority;
    nextPriority = 31 - Clz(READYLISTFLAG);
    return READYLIST[nextPriority]->StaticPtr->id;
}

/* Remove current task from ready list */
void RemoveTask(TaskType TaskID)
{
    uint16 TaskIndex = TaskID & 0xffff;
    TaskVarType *TaskVar = SystemObjects[_CoreID]->TaskVar;
    uint8 priority = TaskVar[TaskIndex].priority;

    READYLIST[priority] = TaskVar[TaskIndex].NextTask;
    TaskVar[TaskIndex].NextTask = NULL;

    if (READYLIST[priority] == NULL) /* Clear ReadyListFlag, if readylist of the priority is empty */
    {
        READYLISTTAIL[priority] = NULL;
        READYLISTFLAG &= ~(1 << priority);
    }
    return;
}

/* Remove specified task from ready list */
//RemoveSpecificTask ?
void RemoveSpecificTask(TaskType TaskID)
{
    uint16 TaskIndex = TaskID & 0xffff;
    TaskVarType *TaskVar = SystemObjects[_CoreID]->TaskVar;
    uint8 priority = TaskVar[TaskIndex].priority;
    TaskVarType *pre = READYLIST[priority];
    TaskVarType *now = READYLIST[priority]->NextTask;
    
    /* if specified task at ready list head */
    if(pre->StaticPtr->id==TaskID)
    {
        READYLIST[priority] = TaskVar[TaskIndex].NextTask;
        TaskVar[TaskIndex].NextTask =NULL;
    }
    else
    {
        while(now->StaticPtr->id!=TaskID)
        {
            pre = pre->NextTask;
            now = now->NextTask;
        }
        pre->NextTask = now->NextTask;
        TaskVar[TaskIndex].NextTask =NULL;
    }
    /* Adjust tail */
    if (READYLIST[priority] == NULL) /* Clear ReadyListFlag, if readylist of the priority is empty */
    {
        READYLISTTAIL[priority] = NULL;
        READYLISTFLAG &= ~(1 << priority);
    }
    else if(READYLISTTAIL[priority]->StaticPtr->id==TaskID)
    {
        READYLISTTAIL[priority]= pre;
    }
    return;
}

/* Add TaskID to head of the ready list basing on its ceiling priority */
void AddReadyHead(TaskType TaskID)
{
    uint16 TaskIndex = TaskID & 0xffff;
    TaskVarType *TaskVar = SystemObjects[_CoreID]->TaskVar;
    uint8 priority = TaskVar[TaskIndex].priority;

    CURRENTTASK.CurrentVar->state = READY;
    if (READYLIST[priority] == NULL) /* Set ReadyListFlag, if the ready list is empty */
    {
        READYLISTTAIL[priority] = &TaskVar[TaskIndex];
        READYLISTFLAG |= (1 << priority);
    }

    TaskVar[TaskIndex].NextTask = READYLIST[priority];
    READYLIST[priority] = &TaskVar[TaskIndex];
    return;
}

void SetPSW(ApplicationType ApplID)
{
    if(ApplID == INVALID_OSAPPLICATION)
    {
        CURRENTTASK.CurrentConst->Context->eipsw = PSWKERNELMODE;
    }
    else
    {
        if(ApplicationVar[ApplID].OsTrusted  == TRUE)
        {
            CURRENTTASK.CurrentConst->Context->eipsw = PSWKERNELMODE;
        }
        else
        {
            CURRENTTASK.CurrentConst->Context->eipsw = PSWUSERMODE;
        }
    }
    return;
}

void ResetTaskRelatedFlag(void)
{
    systemFlag &= ~(IN_TASK | IN_ISR2_TASK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK | IN_IOC_CALLBACK);
    return;
}

void SetTaskSystemFlag(SysTaskActionType SysTaskAction)
{
    switch (SysTaskAction)
    {
    case STARTUPHOOK:
        systemFlag |= IN_OSAPP_STARTUP_HOOK;
        break;
    case SHUTDOWNHOOK:
        systemFlag |= IN_OSAPP_SHUTDOWN_HOOK;
        break;
    case APPLERRORHOOK:
        systemFlag |= IN_OSAPP_ERROR_HOOK;
        break;
    case IOCCALLBACK:
        systemFlag |= IN_IOC_CALLBACK;
        break;
    default:
        break;
    }
}


void Scheduler(void)
{
    TaskVarType *Current, *Next, *TaskVar;
    TaskType nextID, IdleTask, SysTask;
    uint16 nextIndex;
    HardwareTickType Budget;
    //TaskAutosarType *TaskAutosar = SystemObjectAutosar[_CoreID]->TaskAutosar;
    IdleTask = _CoreID << 16; 
    SysTask = SysTaskID[_CoreID];
    TaskVar = SystemObjects[_CoreID]->TaskVar;
    Current = CURRENTTASK.CurrentVar;
    /* Choose the highest priority task*/
    nextID = GetNextTask();
    
    /*------------------------------------------------------*/
    /* Dedug code */

    /*------------------------------------------------------*/
    /* If current task is non-preemptive task, OS should choose that task 
    after executing SysTask */
    if(nextID == SysTask)
    {
        if(CURRENTTASK.CurrentConst->Flags.preemptive==0)
        {
            beforeSysTask[_CoreID] = CURRENTTASK.CurrentConst->id;
        } 
    }
    else
    {
        if(beforeSysTask[_CoreID] != INVALID_TASK_ID)
        {
            nextID = beforeSysTask[_CoreID];
            beforeSysTask[_CoreID] = INVALID_TASK_ID;
        }
    }
    
    
    nextIndex = nextID & 0xffff;
    Next = &TaskVar[nextIndex];

    /* Reset all flag related to task, ISR2 and SysTask */
    ResetTaskRelatedFlag();

    /* if current task is running, Os must move task to ready list and pause executing  counter */
    if (Current->state == RUNNING)
    {
        /* If preemption occurred, call PostTashHook() and put preempted task back to ready list */
        if (Next->priority > Current->priority)
        {
#if (HOOK_ENABLE_POSTTASKHOOK == ENABLE)
            if (!(systemFlag & IN_ISR2_TASK) && (systemFlag & IN_TASK) && (Current->StaticPtr->id != IdleTask))
            {
                systemFlag |= IN_POST_TASK_HOOK;
                PostTaskHook();
                systemFlag &= ~IN_POST_TASK_HOOK;
            }
#endif

AddReadyHead(CURRENTTASK.currentID);
            if(CurrentTask[_CoreID]->currentID != SysTask)
            {
                removeTimingCounter(&(SystemTimingCounter[_CoreID].TaskExecutingCounter[CURRENTTASK.currentID & 0xffff]));
            }
            
        }
        else
        {
            return;
        }
    }
    
    /* If the next task is not idle task, remove it from ReadyList */
    if (nextIndex != 0)
    {
        RemoveTask(nextID);
    }

    CURRENTTASK.CurrentConst = Next->StaticPtr;
    CURRENTTASK.CurrentVar = Next;
    CURRENTTASK.currentID = Next->StaticPtr->id;
    CURRENTTASK.needSaveContext = NEEDSAVE;
    Next->state = RUNNING;
    
    //CURRENTTASK.CurrentAutosar = &(SystemObjectAutosar[_CoreID]->TaskAutosar[nextIndex]);
    //ExecutingApp[_CoreID] = CURRENTTASK.CurrentAutosar->owner;
    

    if(nextID != SysTask)
    {
        Budget = getBound(nextID, EXECUTEBUDGET, 0);
        if(nextID == IdleTask)
        {
            /* SWS_Os_00802 */
            /* Change idlemode */
            GetLock(&lockForIdleMode[_CoreID],0);
            NowIdleMode[_CoreID] = NextIdleMode[_CoreID];
            ReleaseLock(&lockForIdleMode[_CoreID],0);
            addTimingCounter(&(SystemTimingCounter[_CoreID].TaskExecutingCounter[nextIndex]), IDLETASKBUDGET, Budget);
            SetMemProt();
        }
        else
        {
            addTimingCounter(&(SystemTimingCounter[_CoreID].TaskExecutingCounter[nextIndex]), EXECUTEBUDGET, Budget);
            if (Next->StaticPtr->Flags.isrTask )
            {
                systemFlag |= IN_ISR2_TASK;
            }
            else
            {
                systemFlag |= IN_TASK;
                GetInternalResource();
                #if (HOOK_ENABLE_PRETASKHOOK == ENABLE)
                    if (CURRENTTASK.currentID != IdleTask)
                    {
                        systemFlag |= IN_PRE_TASK_HOOK;
                        PreTaskHook();
                        systemFlag &= ~IN_PRE_TASK_HOOK;
                    }
                #endif
            } 
            ExecutingApp[_CoreID] = TaskVar[nextIndex].executingApp;
            SetMemProt();
            SetAppMemProtWithMPM(ExecutingApp[_CoreID]); 
        }
        
        
    }
    else
    {
        DeSysTaskActionQueue(CurrentAction[_CoreID]);
        SetSystaskMemProt();
        ExecutingApp[_CoreID] = CurrentAction[_CoreID]->ApplID;
        SetAppMemProtWithMPM(CurrentAction[_CoreID]->ApplID);
        SetPSW(CurrentAction[_CoreID]->ApplID);
        SetTaskSystemFlag(CurrentAction[_CoreID]->SysTaskAction);        
    }
    return;
}

void InitReadyList(void)
{
    TaskType IdleID;
    TaskVarType *TaskVar;
    const TaskConstType *TaskConst;
    IdleID = _CoreID << 16;
    TaskVar = SystemObjects[_CoreID]->TaskVar;
    TaskConst = SystemObjects[_CoreID]->TaskConst;

    InitTask(IdleID);
    READYLIST[0] = &TaskVar[0];
    READYLISTTAIL[0] = &TaskVar[0];
    READYLISTFLAG = 0X0001;

    CURRENTTASK.CurrentConst = &TaskConst[0];
    CURRENTTASK.CurrentVar = &TaskVar[0];
    CURRENTTASK.CurrentVar->activateCount++;
    CURRENTTASK.currentID = IdleID;
    CURRENTTASK.CurrentVar->state = RUNNING;

    //since we run app-start-up-hook in sysTask 
    //we need to save context even in start up procedure
    //CURRENTTASK.needSaveContext = NOSAVE;
    CURRENTTASK.needSaveContext = NEEDSAVE; 

    addTimingCounter(&(SystemTimingCounter[_CoreID].TaskExecutingCounter[0]), IDLETASKBUDGET, 999);
}

/* 20221131 please check if the code below is updated as Scheduler() ??*/
StatusType Schedule(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SCHEDULE;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType SysSchedule(void){
    StatusType result = E_OK;
    ResourceVarType *ResourceHead = (ResourceVarType *)CURRENTTASK.CurrentVar->Resources;
    InternalResourceVarType *InternalResource = CURRENTTASK.CurrentVar->InternalResource;
    /* Calling task is a preemptive task without internal resource assigned */
    uint16 currentIndex = (CURRENTTASK.currentID ) & 0xffff;


#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }    
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT1)
    {
        result = E_OS_CALLEVEL;
    }
    if (result == E_OK && ResourceHead != NULL)
    {
        result = E_OS_RESOURCE;
    }
    /* SWS_Os_00624 */
    if (result == E_OK && SystemObjectAutosar[_CoreID]->TaskAutosar[currentIndex].lastSpinlock != INVALID_SPINLOCK)
    {
        result = E_OS_SPINLOCK;
    }
#endif /* (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED) */

    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT1)
    {
        result = E_OS_SYS_NOFUNC;
    }

    if (result == E_OK && ((InternalResource == NULL) && (CURRENTTASK.CurrentConst->Flags.preemptive == 1)))
    {
        return result;
    }

    if (result == E_OK)
    {

        ReleaseInternalResource();
        ScheduleKernel();

        GetInternalResource();
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (result != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
    {
        /* System error hook */
        systemFlag |= IN_ERROR_HOOK;
        ErrorHook(result);
        systemFlag &= ~IN_ERROR_HOOK;
        /* App error hook */
        
#if (HOOK_ENABLE_OSAPP_ERRORHOOK == ENABLE)
        if(ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc != NULL)
        {
            APPErrorHook(result);
        }
#endif
    }
#endif


    return result;
}