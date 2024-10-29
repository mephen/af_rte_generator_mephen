#include "task.h"
#include "isr2.h"
#include "system.h"
#include "resource.h"
#include "scheduler.h"
#include "lock.h"
#include "systemcall.h"
#include "timingprot.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "spinlock_Cfg.h"
#include "application_Cfg.h"
#include "timingprot_Cfg.h"
#include "memprot.h"
#include "spinlock.h"
#include "ISRInit.h"
#include "application.h"
#include "system.h"
#include "resource_Cfg.h"
#define PSWUM 0x40000000

StatusType ActivateTask(TaskType TaskID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_ACTIVATETASK;
    para.para1    = TaskID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

// ToDo: Maybe add a parameters TASKID
StatusType TerminateTask(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_TERMINATETASK;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType ChainTask(TaskType TaskID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_CHAINTASK;
    para.para1    = TaskID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType GetTaskID(TaskRefType TaskID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETTASKID;
    para.para1    = (uint32)TaskID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType GetTaskState(TaskType TaskID, TaskStateRefType state)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETTASKSTATE;
    para.para1    = TaskID;
    para.para2    = (uint32)state;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00816 */
/* The operating system shall provide an asynchronous version of
ActivateTask which does not return errors to the caller, but only calls the (global)
error hook (if configured). The function name shall be ActivateTaskAsyn. */
// Todo: Dont call this function twice in a raw,because same interrupt can't pend. 
void ActivateTaskAsyn(TaskType TaskID){
    SysServiceParaType para;
    para.serviceID  = SERVICE_ACTIVATETASK;
    para.para1    = TaskID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return;
}

/* SWS_Os_00769 */
/* This API allows the caller to select the idle mode action which is performed during idle time of
the OS (e.g. if no Task/ISR is active) */
StatusType ControlIdle(CoreIdType CoreID,IdleModeType IdleMode){
    SysServiceParaType para;
    para.serviceID  = SERVICE_CONTROLIDLE;
    para.para1    = (uint32)CoreID;
    para.para2    = (uint32)IdleMode;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* should be registered in task's "lp" when init task obj */
/* This function will be called when user dont can teminate task */
void TerminateTaskObjByOS(){
    SysServiceParaType para;
    para.serviceID  = SERVICE_TERMINATETASKOBJBYOS;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return;
}

/******* Task management internal function *******/
void InitContext(TaskType TaskID)
{
    uint16 TaskIndex = TaskID & 0xffff;
    const TaskConstType *TaskConst = SystemObjects[_CoreID]->TaskConst;
    TaskAutosarType *TaskAutosar = SystemObjectAutosar[_CoreID]->TaskAutosar;

    TaskConst[TaskIndex].Context->sp = (uint32)TaskConst[TaskIndex].stackZone + TaskConst[TaskIndex].stackSize;
    TaskConst[TaskIndex].Context->eipc = (uint32)TaskConst[TaskIndex].entry;

    
    if ( TaskIndex == 0 )   /* in our implemetation, Idle-taskID & 0xffff is always 0 */
    {
        TaskConst[TaskIndex].Context->eipsw = 0x00000000;   /* Idle run in kernel mode */
    }
    else if ( ApplicationVar[ TaskAutosar[TaskIndex].owner].OsTrusted == FALSE) /* SWS_Os_00058 */
    {
        TaskConst[TaskIndex].Context->eipsw = 0x00000000 | PSWUM;   /* non-trusted, user mode */
    }
    else
    {
        TaskConst[TaskIndex].Context->eipsw = 0x00000000;   /* trusted, kernel mode */
    }
    
    if (!TaskConst[TaskIndex].Flags.isrTask)
    {   
        //TODO: should use TerminateSpicificTaskByOs
        //TODO: should check if TaskID is restart-task && OS-App in APPLICATION_TERMINATED
        //      if so, should use TerminateAppByOS
        TaskConst[TaskIndex].Context->lp = (uint32)TerminateTaskObjByOS;
    }
    else
    {
        TaskConst[TaskIndex].Context->lp = (uint32)TerminateTaskObjByOS;
    }
}

void InitTask(TaskType TaskID)
{
    uint16 TaskIndex = TaskID & 0xffff;
    const TaskConstType *TaskConst = SystemObjects[_CoreID]->TaskConst;
    TaskVarType *TaskVar = SystemObjects[_CoreID]->TaskVar;
#if EVENTS_COUNT > 0
    EventsVarType *EventsVar = SystemObjects[_CoreID]->EventsVar;
#endif

    InitContext(TaskID);
    ReInitTaskRomToRamMemArea(TaskID);
    #if (ENABLE_SOFTWARE_STACK_MONITOR == ENABLE)
        ReInitStackMonitorPattern(TaskID);
    #endif
    TaskVar[TaskIndex].Resources = NULL;
    TaskVar[TaskIndex].NextTask = NULL;
    TaskVar[TaskIndex].priority = TaskConst[TaskIndex].staticPriority;
    TaskVar[TaskIndex].INTServiceRecord.DisableAll_Record = 0;
    TaskVar[TaskIndex].INTServiceRecord.SuspendAll_Record = 0;
    TaskVar[TaskIndex].INTServiceRecord.SuspendOS_Record = 0;
    TaskVar[TaskIndex].nestedTrustFuncCounter = 0;
    TaskVar[TaskIndex].executingApp = SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex].owner;
    TaskVar[TaskIndex].isDelay = FALSE;
    if (TaskConst[TaskIndex].Flags.extended)
    {
#if EVENTS_COUNT > 0
        EventsVar[TaskIndex - 1].eventsWait = 0x0;
        EventsVar[TaskIndex - 1].eventsSet = 0x0;
#endif
    }
    return;
}

void AddReady(TaskType TaskID)
{
    uint16 TaskIndex = TaskID & 0xffff;
    TaskVarType *TaskVar = SystemObjects[_CoreID]->TaskVar;
    TaskPriorityType priority = TaskVar[TaskIndex].priority;
    HardwareTickType Bound;

    /* change state of the task from suspended to the ready state */
    TaskVar[TaskIndex].state = READY;

    Bound = getBound(TaskID, TIMEFRAME, 0);
    if(CurrentTask[_CoreID]->currentID != SysTaskID[_CoreID]){
        addTimingCounter(&(SystemTimingCounter[_CoreID].TaskArrivalCounter[TaskIndex]), TIMEFRAME, Bound);
    }
    

    if (READYLIST[priority] == NULL)
    {
        READYLISTFLAG |= (1 << priority);
        READYLIST[priority] = &TaskVar[TaskIndex];
        READYLISTTAIL[priority] = &TaskVar[TaskIndex];
    }
    else
    {
        if (READYLISTTAIL[priority] != NULL)
        {
            READYLISTTAIL[priority]->NextTask = &TaskVar[TaskIndex];
            READYLISTTAIL[priority] = &TaskVar[TaskIndex];
        }
    }
    return;
}

StatusType ActivateTaskInternal(TaskType TaskID)
{
    StatusType retVal = E_OK;
    uint16 TaskIndex = TaskID & 0xffff;
    TaskConstType *TaskConst = (TaskConstType *)SystemObjects[_CoreID]->TaskConst;
    TaskVarType *TaskVar = SystemObjects[_CoreID]->TaskVar;

    if (TaskVar[TaskIndex].state == SUSPENDED)
    {
        /* initialize the task */
        InitTask(TaskID);
        /* add the task to ready list */
        AddReady(TaskID);
        /* increase the activation count */
        TaskVar[TaskIndex].activateCount++;
        /* add timing protection counter */
        //addTimingCounter(&SystemTimingCounter[_CoreID].TaskArrivalCounter[TaskIndex], TIMEFRAME, SystemTimingCounter[_CoreID].TimingBudget[TaskIndex].TimeFrame);
        /* TODO: maintain system flag to indicate reschedule point */
    }
    else
    {
        /* the task is not suspended */
        if (TaskConst[TaskIndex].Flags.extended)
        {
            /* extended task is not allowed multi-activating */
            /* OSEK 4.3 Multiple requesting of task activation */
            /* 15.1.1.1 Conformance classes */
            /* Multiple requesting of task activation for extended tasks is not supported. That is only 
            allowed for basic tasks. */
            retVal = E_OS_LIMIT; /* too many task activations */
        }
        else
        {
            if (TaskConst[TaskIndex].maxActivation > TaskVar[TaskIndex].activateCount)
            {
                /* increase the activation count */
                TaskVar[TaskIndex].activateCount++;
                retVal = E_OS_SYS_OK_MULTIACTIVATATION;
            }
            else
            {
                /* too many task activations */
                /* activation is ignored */
                retVal = E_OS_LIMIT;
            }
        }
    }

    return retVal;
}

void TerminateTaskInternal(void)
{
#if (HOOK_ENABLE_POSTTASKHOOK == ENABLE)
    systemFlag |= IN_POST_TASK_HOOK;
    PostTaskHook();
    systemFlag &= ~IN_POST_TASK_HOOK;
#endif

    //in case that there might be recursive TerminateTask() due to protectionHook
    //NEED double test whether this judgement(!= SUSPENDED) is correct
    if( CURRENTTASK.CurrentVar->state != SUSPENDED){

        ReleaseInternalResource();
        if(CurrentTask[_CoreID]->currentID != SysTaskID[_CoreID])
        {
            resetTimingCounter(&SystemTimingCounter[_CoreID].TaskExecutingCounter[CURRENTTASK.currentID & 0xffff]);            
        }

        
        //we have decreased the activateCount before calling TerminateTaskInternal()
        if (CURRENTTASK.CurrentVar->activateCount > 0)
        {
            InitTask(CURRENTTASK.currentID);
            AddReady(CURRENTTASK.currentID);
        }
        else
        {
            CURRENTTASK.CurrentVar->state = SUSPENDED;
        }

        CURRENTTASK.needSaveContext = NOSAVE;
    }

    return;
}




//void MILKSHOP_TASK_IdleTask(void)
TASK(IdleTask)
{
    while (1)
    {
	        switch (NowIdleMode[_CoreID])
        {
        case IDLE_NO_HALT:
        /* do nothing */
        default:
            break;
        }
    }
        
}

/* This function will enqueue to the systask action queue */
void EnSysTaskActionQueue(SysTaskInformationType info)
{
    SysTaskActionQueueType* SysTaskQueue = SysTaskActionQueue[_CoreID];
    if(SysTaskQueue->isEmpty == FALSE  && SysTaskQueue->head == SysTaskQueue->tail)
    {
        return; //queue is full
    }
    SysTaskQueue->SysTaskInformation[SysTaskQueue->tail] = info;
    SysTaskQueue->tail = (SysTaskQueue->tail + 1) % SysTaskQueue->length;
    SysTaskQueue->isEmpty = FALSE;
    return;
}

/* This function will dequeue from the systask action queue */
void DeSysTaskActionQueue(SysTaskInformationType *info)
{
    SysTaskActionQueueType* SysTaskQueue = SysTaskActionQueue[_CoreID]; 
    if(SysTaskQueue->isEmpty == TRUE)
    {
        return;
    }
    *info = SysTaskQueue->SysTaskInformation[SysTaskQueue->head];
    SysTaskQueue->head = (SysTaskQueue->head + 1) % SysTaskQueue->length;
    if(SysTaskQueue->head == SysTaskQueue->tail)
    {
        SysTaskQueue->isEmpty = TRUE;
    }
    return;
}

/* This is a SysTask Frame */
/* The system task modifies processor mode and access rights based on user permissions, 
and executes user's hook or callback function. */
TASK(SysTask)
{
    uint16 coreID = GetCoreID();
    /* CurrentAction is a array of const pointer to SysTaskInformationType */
    /* Utilize this array to enable the system task to access different core's data based on CoreID, 
    while ensuring the integrity of the array to prevent tampering.*/
    SysTaskInformationType *Action = CurrentAction[coreID];
    if(Action->SysTaskAction == APPLERRORHOOK || Action->SysTaskAction == SHUTDOWNHOOK )
    {    
        Action->FunctionPointer(Action->para);
    }
    else if(Action->SysTaskAction == IOCCALLBACK || Action->SysTaskAction == STARTUPHOOK)
    {
        ((void (*)(void))Action->FunctionPointer)();
    }
    else if (Action->SysTaskAction == BOTSTARTOS)
    {
        SysStartOSBot(Action->para);
    }
    else if (Action->SysTaskAction == BOTSHUTDOWNOS)
    {
        SysShutdownOSBot(Action->para);
    }
    else if(Action->SysTaskAction == BOTSHUTDOWNALLCORES)
    {
        SysShutdownAllCoresBot(Action->para);
    }
    TerminateTask();
}

TaskType GetIdleTaskID(void)
{
	switch ( CoreIdPhyToLogArray[_CoreID] )
	{
	case OS_CORE_ID_0:
		return IdleTask_core0 & 0xffff;
	case OS_CORE_ID_1:
		return IdleTask_core1 & 0xffff;
    default:    //should never happened
        return IdleTask_core0 & 0xffff;
	}
}

/* this function return systask id of this core */
TaskType GetSysTaskID(void)
{
	switch ( CoreIdPhyToLogArray[_CoreID] )
	{
	case OS_CORE_ID_0:
		return SysTask_core0 & 0xffff;
	case OS_CORE_ID_1:
		return SysTask_core1 & 0xffff;
    default:    //should never happened
        return IdleTask_core0 & 0xffff;
	}
}

/* This function will release all lock object that occpuy on TaskID */
void ReleaseAllLockObject(TaskType TaskID)
{
    uint16 TaskIndex = TaskID & 0xffff;
    
    SpinlockVarType *TargetSpinlock = NULL;
    SpinlockIdType TargetSpinlockID;
    ResourceType TargetResourceID;
    ResourceVarType *ResourceVar = SystemObjects[_CoreID]->ResourceVar;
    TaskAutosarType *TaskAutosar = &(SystemObjectAutosar[_CoreID]->TaskAutosar[TaskIndex]);

    while(TaskAutosar->lastLock.objectType!=OBJECT_INVALID)
    {
        if(TaskAutosar->lastLock.objectType == OBJECT_SPINLOCK)
        {
            TargetSpinlockID = TaskAutosar->lastLock.objectId;
            switch (SpinlockConst[TargetSpinlockID].lockMethod)
            {
            case LOCK_ALL_INTERRUPTS:
                kernelEnableAllISR();
                break;
            case LOCK_CAT2_INTERRUPTS:
                kernelEnableISR2();
                break;
            case LOCK_WITH_RES_SCHEDULER:
                SysReleaseResource(RES_SCHEDULER);
                break;
            default:
                break;
            }
            ReleaseLock(&SpinLockList[TargetSpinlockID], 0); /* SWS_Os_00696 */
            TaskAutosar->lastSpinlock = SpinlockVar[TargetSpinlockID].preLock.objectId;
            TaskAutosar->lastLock = SpinlockVar[TargetSpinlockID].preLock;

            SpinlockVar[TargetSpinlockID].ownerCoreID = OS_CORE_ID_INVALID;
            SpinlockVar[TargetSpinlockID].ownerTaskID = INVALID_TASK_ID;
            SpinlockVar[TargetSpinlockID].preLock.objectType = OBJECT_INVALID;          
            continue;
        }
        if(TaskAutosar->lastLock.objectType == OBJECT_RESOURCE)
        {
            TargetResourceID = TaskAutosar->lastLock.objectId & 0xffff;
            TaskAutosar->lastLock.objectId = ResourceVar[TargetResourceID].prelock.objectId;
            TaskAutosar->lastLock.objectType = ResourceVar[TargetResourceID].prelock.objectType;
        
            CURRENTTASK.CurrentVar->priority = ResourceVar[TargetResourceID].previousPriority;
            ResourceVar[TargetResourceID].prelock.objectType = OBJECT_INVALID;
            ResourceVar[TargetResourceID].owner = 0;

            resetTimingCounter(&SystemTimingCounter[_CoreID].ResourceTimingCounter[TargetResourceID]);
            continue;
        }
    }
}

/* This function is abandoned */
void ReleaseAllResource(TaskType TaskID)
{
    uint16 TaskIndex = TaskID & 0xffff;
    TaskVarType *TaskVar = SystemObjects[_CoreID]->TaskVar;
    ResourceVarType *TargetResource = NULL;
    
    /* Release resource */
    while(TaskVar[TaskIndex].Resources != NULL)
    {
        TargetResource = TaskVar[TaskIndex].Resources;
        TaskVar[TaskIndex].Resources = TaskVar[TaskIndex].Resources->NextResource;
        TargetResource->owner = 0;
        TargetResource->NextResource = NULL;
        resetTimingCounter(&SystemTimingCounter[_CoreID].ResourceTimingCounter[(TargetResource->id & 0xffff)]);

    }
}


/* TerminateTask with resource and spinlock released by OS forcibly */
/* Using by protection-hook SysTerminateTaskObjByOS() and TerminateApplication() */
void TerminateSpecificTaskbyOS(TaskType TaskID) 
{
    uint16 TaskIndex;
    TaskVarType *TaskVar;
    uint8 record=0;
    uint8 i=0;

    TaskIndex = TaskID & 0xffff;
    TaskVar = SystemObjects[_CoreID]->TaskVar;

    ReleaseAllLockObject(TaskID);


    /* User didn't call enable-interrupt before task being terminated by OS */
    /* OS will enable interrupt */
    if(TaskVar[TaskIndex].INTServiceRecord.SuspendOS_Record > 0)
    {
        record = TaskVar[TaskIndex].INTServiceRecord.SuspendOS_Record;
        TaskVar[TaskIndex].INTServiceRecord.SuspendOS_Record =0;
        serviceSuspendOSInterruptsCounter -= record;
        resetTimingCounter(&SystemTimingCounter[_CoreID].InterruptTimingCounter[2]);
        for(i=0;i<record;i++)
        {
            kernelEnableISR2();
        }
    }
    if(TaskVar[TaskIndex].INTServiceRecord.SuspendAll_Record > 0)
    {
        record = TaskVar[TaskIndex].INTServiceRecord.SuspendAll_Record;
        TaskVar[TaskIndex].INTServiceRecord.SuspendAll_Record = 0;
        serviceSuspendAllInterruptsCounter -= record;
        resetTimingCounter(&SystemTimingCounter[_CoreID].InterruptTimingCounter[1]);
        for(i=0;i<record;i++)
        {
            kernelEnableAllISR();
        }
    }
    if(TaskVar[TaskIndex].INTServiceRecord.DisableAll_Record > 0)
    {
        record = TaskVar[TaskIndex].INTServiceRecord.DisableAll_Record;
        TaskVar[TaskIndex].INTServiceRecord.DisableAll_Record = 0;
        serviceDisableAllInterruptsCounter -= record;
        resetTimingCounter(&SystemTimingCounter[_CoreID].InterruptTimingCounter[0]);
        for(i=0;i<record;i++)
        {
            kernelEnableAllISR();
        }
    }

    if(TaskVar[TaskIndex].state == SUSPENDED)
    {
        /* do nothing */
    }
    else if(TaskVar[TaskIndex].state == WAITING)
    {
        /* clear waiting bits */
        SystemObjects[_CoreID]->EventsVar[TaskIndex].eventsWait=0;
        TaskVar[TaskIndex].state = SUSPENDED;
    }
    else if(TaskVar[TaskIndex].state == RUNNING)
    {
             
        if( CURRENTTASK.CurrentVar->activateCount > 0)
        {
            CURRENTTASK.CurrentVar->activateCount--;
        }
        TerminateTaskInternal();
        // ScheduleKernel();
    }
    else if(TaskVar[TaskIndex].state == READY)
    {     
        TaskVar[TaskIndex].state = SUSPENDED;
        RemoveSpecificTask(TaskID);
        if (TaskVar[TaskIndex].activateCount > 0){
            TaskVar[TaskIndex].activateCount--;
        }
        if (TaskVar[TaskIndex].activateCount > 0)
        {
            InitTask(TaskID);
            AddReady(TaskID);
        }
    }

    return; 
}

/* terminate current task */
void TerminateCurrentTaskbyOS(){
    
    ApplicationType appID;


    {
        appID = SystemObjectAutosar[_CoreID]->TaskAutosar[CURRENTTASK.currentID].owner;
        if (CURRENTTASK.currentID == ApplicationVar[appID].RestartTaskID){
            ;//TODO: specail handling to terminate the whole app in RestartTask
        }
        ReleaseAllLockObject(CURRENTTASK.currentID);
        if( CURRENTTASK.CurrentVar->activateCount > 0)
        {
            CURRENTTASK.CurrentVar->activateCount--;
        }
        TerminateTaskInternal();
        ScheduleKernel();
    }

}

/* This function will execute after task end without calling TerminateTask() */
void SysTerminateTaskObjByOS()
{
    StatusType result = E_OK;
    TaskType TaskID  = CurrentTask[_CoreID]->currentID;
    TaskType TaskIndex = TaskID & 0xffff;
    const TaskConstType *TaskConst = SystemObjects[_CoreID]->TaskConst;
    TaskVarType *TaskVar = SystemObjects[_CoreID]->TaskVar;
    /* If task isn't ISR2, error will be MISSINGEND */    
    if(!TaskConst[TaskIndex].Flags.isrTask)
    {
        result = E_OS_MISSINGEND;
    }
    else
    {
        /* If task is ISR2, */
        /* if task dosen't release resource, error will be E_OS_RESOURCE */   
        if(TaskVar[TaskIndex].Resources != NULL)
        {
            result = E_OS_RESOURCE;
        }
        /* if task dosen't enable/resume interrupt, error will be E_OS_DISABLEDINT */   
        else if(TaskVar[TaskIndex].INTServiceRecord.DisableAll_Record > 0 || TaskVar[TaskIndex].INTServiceRecord.SuspendAll_Record > 0 || TaskVar[TaskIndex].INTServiceRecord.SuspendOS_Record > 0)
        {
            result = E_OS_DISABLEDINT;
        }
    }


    /* Call Errorhook */
    if(result != E_OK)
    {
        ErrorHook(result);
    }
    TerminateSpecificTaskbyOS(TaskID);
    ScheduleKernel();
    return;
}







StatusType SysActivateTask(TaskType TaskID){
    StatusType result = E_OK;
    CoreIdType CoreID = (CoreIdType)(TaskID >> 16);
    uint16 TaskIndex = TaskID & 0xffff;

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    }
    /* ID is valid */
    if (result == E_OK && TaskIndex >= SystemObjects[CoreID]->tasksCount)
    {
        result = E_OS_ID;
    }
    /* check appication mask */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }


    /* Cross core */
    if (result == E_OK && CoreID != _CoreID)
    {
        /* check access right */
        /* go to the core */
        /* wait the api completed */
        /* Need to modify to a lock, and modify to trylock() */
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_ACTIVATETASK;
        CrossCoreServicePara[CoreID].para1 = TaskID;
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1);

        result = CrossCoreServicePara[CoreID].result;
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        disableCrossCoreISR();

        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
    }       


    if (result == E_OK)
    {
        result = ActivateTaskInternal(TaskID);
    }
    
    if (result == E_OK && CURRENTTASK.CurrentConst->Flags.preemptive)
    {
        ScheduleKernel();
    }
    else if (result == E_OS_SYS_OK_MULTIACTIVATATION || result == E_OS_SYS_OK_CROSSCORE)
    {
        result = E_OK;
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

StatusType SysTerminateTask(void){
    StatusType result = E_OK;
   

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && (systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT)))
    {
        result = E_OS_DISABLEDINT;
    }   
    /* is it possible that when TerminateTask() is called, and currentID is 0? (idle-task) */
    /* CAN WE TERMINATE IDLE TASK? IF WE CANNOT, WHY WE DO NOT CHECK? */
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & ((IN_ISR1_HANDLER) | (IN_ISR2_TASK) | (IN_ERROR_HOOK) | \
                            (IN_PRE_TASK_HOOK) | (IN_POST_TASK_HOOK) | (IN_ALARM_CALLBACK) | (IN_PROTECTION_HOOK)) )
    {
        result = E_OS_CALLEVEL;
    }


    
    if ( result == E_OK && (CURRENTTASK.currentID & 0xffff) == 0)
    {
        result = E_OS_NOFUNC;   
    }
    
    if (result == E_OK && SystemObjectAutosar[_CoreID]->TaskAutosar[(CURRENTTASK.currentID & 0xffff)].lastLock.objectType== OBJECT_RESOURCE)
    {
        result = E_OS_RESOURCE;
    }
    else if (result == E_OK && SystemObjectAutosar[_CoreID]->TaskAutosar[(CURRENTTASK.currentID & 0xffff)].lastLock.objectType== OBJECT_SPINLOCK)
    {
        result = E_OS_SPINLOCK; /* SWS_Os_00612 */
    }

    if (result == E_OK)
    {   
        if( CURRENTTASK.CurrentVar->activateCount > 0){
            CURRENTTASK.CurrentVar->activateCount--;
        }
        TerminateTaskInternal();
        ScheduleKernel();
    }
#if (HOOK_ENABLE_ERRORHOOK == ENABLE)
    
    if (result != E_OK && !(systemFlag & (IN_ERROR_HOOK | IN_OSAPP_ERROR_HOOK  | IN_OSAPP_SHUTDOWN_HOOK | IN_OSAPP_STARTUP_HOOK)))
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
StatusType SysChainTask(TaskType TaskID){
    StatusType result = E_OK;
    CoreIdType CoreID = (CoreIdType)(TaskID >> 16);
    uint16 TaskIndex = TaskID & 0xffff;

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
    if (result == E_OK && TaskIndex >= SystemObjects[_CoreID]->tasksCount)
    {
        result = E_OS_ID;
    }
    if (result == E_OK &&~(SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }

    
    if(result == E_OK && CoreID != _CoreID)
    {
        /* check access right */
        /* go to the core */
        /* wait the api completed */
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_ACTIVATETASK;
        CrossCoreServicePara[CoreID].para1 = TaskID;
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1);

        result = CrossCoreServicePara[CoreID].result;
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        disableCrossCoreISR();
        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
    }



    if (result == E_OK && CURRENTTASK.CurrentVar->Resources != NULL)
    {
        result = E_OS_RESOURCE;
    }
    else if (SystemObjectAutosar[_CoreID]->TaskAutosar[(TaskIndex)].lastSpinlock != INVALID_SPINLOCK)
    {
        result = E_OS_SPINLOCK; /* SWS_Os_00612 */
    }


    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT1)
    {
        result = E_OS_SYS_NOFUNC;
    }

    if (result == E_OK || result == E_OS_SYS_OK_CROSSCORE)
    {
        /* Check OSEK OS spec. 2.2.3 p.52.*/
        /* The service should return to the calling task in case of error.*/
        /* Decrement activateCount here, let ActivateTaskInternal() be able */
        /* to perform correctly in case of the succeeding is identical with the current task. */

        if( CURRENTTASK.CurrentVar->activateCount > 0){
            CURRENTTASK.CurrentVar->activateCount--;
        }

        if (result == E_OK)
        {
            result = ActivateTaskInternal(TaskID);
            if (result == E_OS_SYS_OK_MULTIACTIVATATION)
            {
                result = E_OK;      //??
            }
        }
        else
        {
            result = E_OK;
        }

        if (result == E_OK)
        {
            TerminateTaskInternal();
            ScheduleKernel();
        }
        else
        {
            /* Increment activateCount if error occurred in ActivateTaskInternal(). */
            CURRENTTASK.CurrentVar->activateCount++;
        }

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
StatusType SysGetTaskID(TaskRefType TaskID)
{
    StatusType result = E_OK;

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT3)
    {
        result = E_OS_CALLEVEL;
    }

    if (result == E_OK)
    {
        *TaskID = CURRENTTASK.currentID;
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
StatusType SysGetTaskState(TaskType TaskID, TaskStateRefType state)
{
    StatusType result = E_OK;
    TaskVarType *TaskVar;
    CoreIdType CoreID = (CoreIdType)(TaskID >> 16);
    uint16 TaskIndex = TaskID & 0xffff;

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & (SERVICE_LIMIT_CAT3|IN_PROTECTION_HOOK))
    {
        result = E_OS_CALLEVEL;
    }
    if (result == E_OK && TaskIndex >= SystemObjects[CoreID]->tasksCount)
    {
        result = E_OS_ID;
    }
    if (result == E_OK &&~(SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(state))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }
    if(result == E_OK && CoreID != _CoreID)
    {
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_GETTASKSTATE;
        CrossCoreServicePara[CoreID].para1 = TaskID;
        CrossCoreServicePara[CoreID].para2 = (uint32)(&TaskStateForSharing);
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1);

        *state = TaskStateForSharing;
        result = CrossCoreServicePara[CoreID].result;
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
    }
    TaskVar = SystemObjects[_CoreID]->TaskVar;



    if (result == E_OK)
    {
        *state = TaskVar[TaskIndex].state;
    }
    
    if (result == E_OS_SYS_OK_CROSSCORE)
    {
        result = E_OK;
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
void SysActivateTaskAsyn(TaskType TaskID)
{
    StatusType result = E_OK;
    CoreIdType CoreID = (CoreIdType)(TaskID >> 16);
    uint16 TaskIndex = TaskID & 0xffff;
    
    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    }
    /* ID is valid */
    if (result == E_OK && TaskIndex >= SystemObjects[_CoreID]->tasksCount)
    {
        result = E_OS_ID;
    }
    /* check appication mask */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }

    /* Cross core */
    if (result == E_OK && CoreID != _CoreID)
    {
        
        /* Flow */
        // Get lock 
        // Pass parameter
        // Set interrupt
        // Release Lock
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_ACTIVATETASKASYN;
        CrossCoreServicePara[CoreID].para1 = TaskID;
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];
        
        InterruptToCore(CoreID);
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);

        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
    }

    if (result == E_OK)
    {
        result = ActivateTaskInternal(TaskID);
    }
    if (result == E_OK && CURRENTTASK.CurrentConst->Flags.preemptive)
    {
        ScheduleKernel();
    }
    else if (result == E_OS_SYS_OK_MULTIACTIVATATION || result == E_OS_SYS_OK_CROSSCORE)
    {
        result = E_OK;
    }
    /* No return value, no need Hook */
}
StatusType SysControlIdle(CoreIdType CoreID,IdleModeType IdleMode){
    /* SWS_Os_00770 */
    StatusType result = E_OK;
    

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }    
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    }

    /* SWS_Os_00771 */
    if(result == E_OK && CoreID >= OS_CORE_ID_INVALID || IdleMode >= IDLEMODE_INVALID)
    {
        result  = E_OS_ID;
    }
    if(result == E_OK)
    {
        GetLock(&lockForIdleMode[CoreID],0);
        NextIdleMode[CoreID] = IdleMode;
        ReleaseLock(&lockForIdleMode[CoreID],0);
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