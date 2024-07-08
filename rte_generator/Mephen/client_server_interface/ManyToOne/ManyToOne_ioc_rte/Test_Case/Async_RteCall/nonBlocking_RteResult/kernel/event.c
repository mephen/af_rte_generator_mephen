#include "event.h"
#include "system.h"
#include "scheduler.h"
#include "resource.h"
#include "timingprot.h"
#include "event_Cfg.h"
#include "systemcall.h"
#include "os_Cfg.h"
#include "timingprot_Cfg.h"
#include "spinlock_Cfg.h"
#include "lock.h"
#include "task.h"
#include "application.h"
#include "ISRInit.h"

#define EVENTSVAR(ID) EventsVar[##ID - 1]

StatusType SetEvent(TaskType TaskID, EventMaskType Mask)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SETEVENT;
    para.para1    = TaskID;
    para.para2    = Mask;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType ClearEvent(EventMaskType Mask)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_CLEAREVENT;
    para.para1    = Mask;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType GetEvent(TaskType TaskID, EventMaskRefType Event)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETEVENT;
    para.para1    = TaskID;
    para.para2    = (uint32)Event;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType WaitEvent(EventMaskType Mask)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_WAITEVENT;
    para.para1    = Mask;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* Asynchronus version of SetEvent */
void SetEventAsyn(TaskType TaskID, EventMaskType Mask)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SETEVENTASYN;
    para.para1    = TaskID;
    para.para2    = Mask;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}


StatusType SysSetEvent(TaskType TaskID, EventMaskType Mask){
    StatusType result = E_OK;
    TaskVarType *TaskVar;
    const TaskConstType *TaskConst;
    EventsVarType *EventsVar;
    uint16 TaskIndex = TaskID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(TaskID >> 16);

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
    if (result == E_OK && TaskIndex > SystemObjects[_CoreID]->tasksCount)
    {
        /* Task not exist */
        result = E_OS_ID;
    }
    if (~(SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
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
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_SETEVENT;
        CrossCoreServicePara[CoreID].para1 = TaskID;
        CrossCoreServicePara[CoreID].para2 = Mask;
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
    TaskVar = SystemObjects[_CoreID]->TaskVar;
    TaskConst = SystemObjects[_CoreID]->TaskConst;
    EventsVar = SystemObjects[_CoreID]->EventsVar;


    
    if (result == E_OK && TaskConst[TaskIndex].Flags.extended!=1)
    {
        /* Task is not extended task */
        result = E_OS_ACCESS;
    }

    if (result == E_OK && TaskVar[TaskIndex].state == SUSPENDED)
    {
        /* Task is suspended */
        result = E_OS_STATE;
    }

    if (result == E_OK && (Mask & ~(TaskConst[TaskIndex].eventsMask)))
    {
        /* Set events not owned by TaskID, this error is not defined in OSEK OS spec. */
        result = E_OS_SYS_NOFUNC;
    }


    

    if (result == E_OK)
    {
        /* Only set events owned by TaskID */
        Mask &= TaskConst[TaskIndex].eventsMask;

        /* Set event */
#if EVENTS_COUNT > 0
        EVENTSVAR(TaskIndex).eventsSet |= Mask;

        if (TaskVar[TaskIndex].state == WAITING && (EVENTSVAR(TaskIndex).eventsWait & Mask))
        {
            /* Clear eventsWait */
            EVENTSVAR(TaskIndex).eventsWait = 0;

            /* Add task to ready state */
            AddReady(TaskID);
            /* Add timing protection counter */
            addTimingCounter(&SystemTimingCounter[_CoreID].TaskArrivalCounter[TaskIndex], TIMEFRAME, SystemTimingCounter[_CoreID].TimingBudget[TaskIndex].TimeFrame);

            /* Reschedule if current tasks is preemptive */
            if (CURRENTTASK.CurrentConst->Flags.preemptive)
            {
                ScheduleKernel();
            }
        }
#endif
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

StatusType SysClearEvent(EventMaskType Mask){
    StatusType result = E_OK;
    uint16 currentIndex = (CURRENTTASK.currentID) & 0xffff;
    EventsVarType *EventsVar = SystemObjects[_CoreID]->EventsVar;
    const TaskConstType *TaskConst;

    TaskConst = SystemObjects[_CoreID]->TaskConst;

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    if (result == E_OK && TaskConst[currentIndex].Flags.extended!=1)
    {
        /* Current task is not extended task */
        result = E_OS_ACCESS;
    }

    if (result == E_OK && (systemFlag & SERVICE_LIMIT_CAT1))
    {
        result = E_OS_CALLEVEL;
    }


    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT1)
    {
        result = E_OS_SYS_NOFUNC;
    }

    if (result == E_OK)
    {
#if EVENTS_COUNT > 0
        EVENTSVAR(currentIndex).eventsSet &= ~Mask;
#endif
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
StatusType SysGetEvent(TaskType TaskID, EventMaskRefType Event){
    StatusType result = E_OK;
    TaskVarType *TaskVar;
    const TaskConstType *TaskConst;
    EventsVarType *EventsVar;
    uint16 TaskIndex = TaskID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(TaskID >> 16);

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    if (~(SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(Event))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }
    if(result == E_OK && CoreID != _CoreID)
    {
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_GETEVENT;
        CrossCoreServicePara[CoreID].para1 = TaskID;
        CrossCoreServicePara[CoreID].para2 = (uint32)&EventMaskForSharing;
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1);

        *Event = EventMaskForSharing;
        result = CrossCoreServicePara[CoreID].result;
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        disableCrossCoreISR();
        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
    }
    TaskVar = SystemObjects[_CoreID]->TaskVar;
    TaskConst = SystemObjects[_CoreID]->TaskConst;
    EventsVar = SystemObjects[_CoreID]->EventsVar;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
    if (result == E_OK && TaskIndex > SystemObjects[_CoreID]->tasksCount)
    {
        /* Task not exist */
        result = E_OS_ID;
    }

    if (result == E_OK && TaskConst[TaskIndex].Flags.extended!=1)
    {
        /* Task is not extended task */
        result = E_OS_ACCESS;
    }

    if (result == E_OK && TaskVar[TaskIndex].state == SUSPENDED)
    {
        /* Task is suspended */
        result = E_OS_STATE;
    }
#endif

    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT3)
    {
        result = E_OS_SYS_NOFUNC;
    }

    if (result == E_OK)
    {

    #if EVENTS_COUNT > 0
        *Event = EVENTSVAR(TaskIndex).eventsSet;
    #else
        *Event = 0;
    #endif

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

StatusType SysWaitEvent(EventMaskType Mask){
    StatusType result = E_OK;
    uint16 currentIndex = (CURRENTTASK.currentID ) & 0xffff;
    EventsVarType *EventsVar = SystemObjects[_CoreID]->EventsVar;
    const TaskConstType *TaskConst;


    TaskConst = SystemObjects[_CoreID]->TaskConst;
    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    if (TaskConst[currentIndex].Flags.extended!=1)
    {
        /* Current task is not extended task */
        result = E_OS_ACCESS;
    }

    if (result == E_OK && CURRENTTASK.CurrentVar->Resources)
    {
        /* Current task is holding resources */
        result = E_OS_RESOURCE;
    }

    if (result == E_OK && (systemFlag & SERVICE_LIMIT_CAT1))
    {
        /* System is in interrupt status */
        result = E_OS_CALLEVEL;
    }

    if (result == E_OK && (Mask & ~(CURRENTTASK.CurrentConst->eventsMask)))
    {
        /* Wait for events not owned by current task, this error is not defined in OSEK OS spec. */
        result = E_OS_SYS_NOFUNC;
    }
    if (SystemObjectAutosar[_CoreID]->TaskAutosar[currentIndex].lastSpinlock != INVALID_SPINLOCK)
    {
        /* SWS_Os_00622 */
        /* check if Task has occupied a spinlock */
        result = E_OS_SPINLOCK;
    }


    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT1)
    {
        result = E_OS_SYS_NOFUNC;
    }

    if (result == E_OK)
    {
        /* Tasks could only wait for events owned by itself */
        Mask &= CURRENTTASK.CurrentConst->eventsMask;

        /* Set waiting event */
#if EVENTS_COUNT > 0
        EVENTSVAR(currentIndex).eventsWait = Mask;

        if (EVENTSVAR(currentIndex).eventsSet & Mask || !Mask)
        {
            /* The event to be wait is already set */
            /* Clear waiting event */
            EVENTSVAR(currentIndex).eventsWait = 0;

            return result;
        }
#endif

        /* Changing current task to waiting */
#if (HOOK_ENABLE_POSTTASKHOOK == ENABLE)
        systemFlag |= IN_POST_TASK_HOOK;
        PostTaskHook();
        systemFlag &= ~IN_POST_TASK_HOOK;
#endif
        CURRENTTASK.CurrentVar->state = WAITING;
        resetTimingCounter(&SystemTimingCounter[_CoreID].TaskExecutingCounter[currentIndex]);
        ReleaseInternalResource();
        ScheduleKernel();

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
void SysSetEventAsyn(TaskType TaskID, EventMaskType Mask){
    StatusType result = E_OK;
    TaskVarType *TaskVar;
    const TaskConstType *TaskConst;
    EventsVarType *EventsVar;
    uint16 TaskIndex = TaskID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(TaskID >> 16);

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
    if (result == E_OK && TaskIndex > SystemObjects[_CoreID]->tasksCount)
    {
        /* Task not exist */
        result = E_OS_ID;
    }
    if (~(SystemObjectAutosar[CoreID]->TaskAutosar[TaskIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
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
        CrossCoreServicePara[CoreID].serviceID = SERVICE_SETEVENTASYN;
        CrossCoreServicePara[CoreID].para1 = TaskID;
        CrossCoreServicePara[CoreID].para2 = Mask;
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];
        
        InterruptToCore(CoreID);

        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        disableCrossCoreISR();
        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
    }
    TaskVar = SystemObjects[_CoreID]->TaskVar;
    TaskConst = SystemObjects[_CoreID]->TaskConst;
    EventsVar = SystemObjects[_CoreID]->EventsVar;
    if (result == E_OK && TaskConst[TaskIndex].Flags.extended!=1)
    {
        /* Task is not extended task */
        result = E_OS_ACCESS;
    }
    if (result == E_OK && TaskVar[TaskIndex].state == SUSPENDED)
    {
        /* Task is suspended */
        result = E_OS_STATE;
    }
    if (result == E_OK && (Mask & ~(TaskConst[TaskIndex].eventsMask)))
    {
        /* Set events not owned by TaskID, this error is not defined in OSEK OS spec. */
        result = E_OS_SYS_NOFUNC;
    }
    if (result == E_OK)
    {

        /* Only set events owned by TaskID */
        Mask &= TaskConst[TaskIndex].eventsMask;

        /* Set event */
#if EVENTS_COUNT > 0
        EVENTSVAR(TaskIndex).eventsSet |= Mask;

        if (TaskVar[TaskIndex].state == WAITING && (EVENTSVAR(TaskIndex).eventsWait & Mask))
        {
            /* Clear eventsWait */
            EVENTSVAR(TaskIndex).eventsWait = 0;

            /* Add task to ready state */
            AddReady(TaskID);
            /* Add timing protection counter */
            addTimingCounter(&SystemTimingCounter[_CoreID].TaskArrivalCounter[TaskIndex], TIMEFRAME, SystemTimingCounter[_CoreID].TimingBudget[TaskIndex].TimeFrame);

            /* Reschedule if current tasks is preemptive */
            if (CURRENTTASK.CurrentConst->Flags.preemptive)
            {
                ScheduleKernel();
            }
        }
#endif
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
}