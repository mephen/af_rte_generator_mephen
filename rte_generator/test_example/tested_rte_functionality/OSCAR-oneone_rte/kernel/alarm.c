#include "alarm.h"
#include "system.h"
#include "systemcall.h"
#include "os_Cfg.h"
#include "counter.h"
#include "lock.h"
#include "core.h"
#include "application_Cfg.h"
#include "application.h"
#include "ISRInit.h"
#include "memprot.h"

/* Autosar System Service  wrapper */
StatusType GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETALARMBASE;
    para.para1    = AlarmID;
    para.para2    = (uint32)Info;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType GetAlarm(AlarmType AlarmID, TickRefType Tick)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETALARM;
    para.para1    = AlarmID;
    para.para2    = (uint32)Tick;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SETRELALARM;
    para.para1    = AlarmID;
    para.para2    = increment;
    para.para3    = cycle;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SETABSALARM;
    para.para1    = AlarmID;
    para.para2    = start;
    para.para3    = cycle;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

StatusType CancelAlarm(AlarmType AlarmID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_CANCELALARM;
    para.para1    = AlarmID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* Alarm management internal function */

void InsertAlarm(AlarmType AlarmID)
{
#if (ALARMS_COUNT > 0)
    uint16 AlarmIndex = AlarmID & 0xffff;
    const AlarmConstType *AlarmConst = SystemObjects[_CoreID]->AlarmConst;
    AlarmVarType *AlarmVar = SystemObjects[_CoreID]->AlarmVar;
    CounterVarType *CounterVar = SystemObjects[_CoreID]->CounterVar;
    AlarmVarType *NewAlarm = &AlarmVar[AlarmIndex];
    CounterVarType *Counter = &CounterVar[AlarmConst[AlarmIndex].counter & 0xffff];
    AlarmVarType *Current = Counter->FirstAlarm;
    AlarmVarType *Prev = NULL;

    if (Current == NULL)
    {
        /* Insert AlarmID to head of the list */
        NewAlarm->NextAlarm = NULL;
        NewAlarm->PrevAlarm = NULL;
        Counter->FirstAlarm = NewAlarm;
        Counter->NextAlarm = NewAlarm;
        return;
    }

    /* Find the place for AlarmID in the list */
    while ((Current != NULL) &&
            (Current->expireCount <= NewAlarm->expireCount))
    {
        Prev = Current;
        Current = Current->NextAlarm;
    }

    if (Current == NULL) /* insert to tail of the list */
    {
        NewAlarm->PrevAlarm = Prev;
        NewAlarm->NextAlarm = NULL;
    }
    else /* insert to somewhere in the list */
    {
        NewAlarm->PrevAlarm = Prev;
        NewAlarm->NextAlarm = Current;
        Current->PrevAlarm = NewAlarm;
    }

    if (Prev == NULL) /* NewAlarm is the first alarm in the list */
    {
        Counter->FirstAlarm = NewAlarm;
    }
    else
    {
        Prev->NextAlarm = NewAlarm;
    }

    /* adjust NextAlarm to NewAlarm if needed */
    if (Counter->currentCounts > Counter->NextAlarm->expireCount)
    {
        if (NewAlarm->expireCount < Counter->NextAlarm->expireCount ||
                NewAlarm->expireCount > Counter->currentCounts)
        {
            Counter->NextAlarm = NewAlarm;
        }
    }
    else if (NewAlarm->expireCount > Counter->currentCounts &&
             NewAlarm->expireCount < Counter->NextAlarm->expireCount)
    {
        Counter->NextAlarm = NewAlarm;
    }
#endif
}

void RemoveAlarm(AlarmType AlarmID)
{
#if (ALARMS_COUNT > 0)
    uint16 AlarmIndex = AlarmID & 0xffff;
    const AlarmConstType *AlarmConst = SystemObjects[_CoreID]->AlarmConst;
    AlarmVarType *AlarmVar = SystemObjects[_CoreID]->AlarmVar;
    CounterVarType *CounterVar = SystemObjects[_CoreID]->CounterVar;
    AlarmVarType *TargetAlarm = &AlarmVar[AlarmIndex];
    CounterVarType *Counter = &CounterVar[AlarmConst[AlarmIndex].counter & 0xffff];

    /* The alarm to remove is the first alarm in list */
    if (Counter->FirstAlarm == TargetAlarm)
    {
        Counter->FirstAlarm = TargetAlarm->NextAlarm;
    }

    /* The alarm to remove is the next alarm to expire */
    if (Counter->NextAlarm == TargetAlarm)
    {
        Counter->NextAlarm = TargetAlarm->NextAlarm;
    }

    /* if target alarm is the last alarm in the list, adjust NextAlarm to FirstAlarm */
    if (Counter->NextAlarm == NULL)
    {
        Counter->NextAlarm = Counter->FirstAlarm;
    }

    /* Remove alarm */
    if (TargetAlarm->PrevAlarm != NULL)
    {
        TargetAlarm->PrevAlarm->NextAlarm = TargetAlarm->NextAlarm;
    }
    if (TargetAlarm->NextAlarm != NULL)
    {
        TargetAlarm->NextAlarm->PrevAlarm = TargetAlarm->PrevAlarm;
    }

#endif
}


/* Alarm management service */
StatusType SysGetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info)
{
#if (ALARMS_COUNT > 0)
    StatusType result = E_OK;
    CoreIdType CoreID = (CoreIdType)(AlarmID >> 16);
    uint16 AlarmIndex = AlarmID & 0xffff;
    const AlarmConstType *AlarmConst = NULL;
    const CounterConstType *CounterConst = NULL;

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT3)
    {
        result = E_OS_SYS_NOFUNC;
    }
    if (result == E_OK && AlarmIndex >= SystemObjects[CoreID]->alarmsCount)
    {
        result = E_OS_ID;
    }
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) &&!CheckWritingAccess(Info))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }

    if(result == E_OK && CoreID != _CoreID)
    {
        /* check access right */
        /* go to the core */
        /* wait the api completed */
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_GETALARMBASE;
        CrossCoreServicePara[CoreID].para1 = AlarmID;
        CrossCoreServicePara[CoreID].para2 = (uint32)&AlarmBaseForSharing;
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1);

        Info->maxallowedvalue = AlarmBaseForSharing.maxallowedvalue;
        Info->mincycle = AlarmBaseForSharing.mincycle;
        Info->ticksperbase = AlarmBaseForSharing.ticksperbase;
        result = CrossCoreServicePara[CoreID].result;
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        disableCrossCoreISR();
        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
    }
    AlarmConst = SystemObjects[_CoreID]->AlarmConst;
    CounterConst = SystemObjects[_CoreID]->CounterConst;

 


    if (result == E_OK)
    {
        Info->maxallowedvalue = CounterConst[AlarmConst[AlarmIndex].counter & 0xffff].maxAllowedValue;
        Info->mincycle = CounterConst[AlarmConst[AlarmIndex].counter & 0xffff].minCycle;
        Info->ticksperbase = CounterConst[AlarmConst[AlarmIndex].counter & 0xffff].ticksPerBase;
    }
    if (result == E_OS_SYS_OK_CROSSCORE)
    {
        result = E_OK;
    }
#endif /* #if (ALARMS_COUNT > 0) */
#if (ALARMS_COUNT == 0)
    StatusType result = E_OS_ID;
#endif /* #if (ALARMS_COUNT == 0) */
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

StatusType SysGetAlarm(AlarmType AlarmID, TickRefType Tick)
{
#if (ALARMS_COUNT > 0)
    StatusType result = E_OK;
    CounterVarType *CounterVarRef = NULL;
    const CounterConstType *CounterConstRef = NULL;
    CoreIdType CoreID = (CoreIdType)(AlarmID >> 16);
    uint16 AlarmIndex = AlarmID & 0xffff;
    const AlarmConstType *AlarmConst = NULL;
    AlarmVarType *AlarmVar = NULL;
    CounterVarType *CounterVar = NULL;

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT3)
    {
        result = E_OS_SYS_NOFUNC;
    }
    if (result == E_OK && AlarmIndex >= SystemObjects[_CoreID]->alarmsCount)
    {
        result = E_OS_ID;
    }
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(Tick))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }

    if(result == E_OK && CoreID != _CoreID)
    {
        /* check access right */
        /* go to the core */
        /* wait the api completed */
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_GETALARM;
        CrossCoreServicePara[CoreID].para1 = AlarmID;
        CrossCoreServicePara[CoreID].para2 = (uint32)&TickForSharing;
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1);

        *Tick = TickForSharing;
        result = CrossCoreServicePara[CoreID].result;
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        disableCrossCoreISR();
        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
    }
    AlarmConst = SystemObjects[_CoreID]->AlarmConst;
    AlarmVar = SystemObjects[_CoreID]->AlarmVar;
    CounterVar = SystemObjects[_CoreID]->CounterVar;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
    if (result == E_OK && AlarmIndex >= SystemObjects[_CoreID]->alarmsCount)
    {
        result = E_OS_ID;
    }
#endif

    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT3)
    {
        result = E_OS_SYS_NOFUNC;
    }


    if (result == E_OK && !AlarmVar[AlarmIndex].active)
    {
        result = E_OS_NOFUNC;
    }

    if (result == E_OK)
    {
        CounterVarRef = &CounterVar[AlarmConst[AlarmIndex].counter & 0xffff];
        if (CounterVarRef->currentCounts > AlarmVar[AlarmIndex].expireCount)
        {
            *Tick = CounterConstRef->maxAllowedValue - CounterVarRef->currentCounts + AlarmVar[AlarmIndex].expireCount;
        }
        else
        {
            *Tick = AlarmVar[AlarmIndex].expireCount - CounterVarRef->currentCounts;
        }
    }
    if (result == E_OS_SYS_OK_CROSSCORE)
    {
        result = E_OK;
    }
#endif
#if (ALARMS_COUNT == 0)
    StatusType result = E_OS_ID;
#endif
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
StatusType SysSetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle)
{
#if (ALARMS_COUNT > 0)
    StatusType result = E_OK;
    CounterVarType *CounterVarRef = NULL;
    const CounterConstType *CounterConstRef = NULL;
    CoreIdType CoreID = (CoreIdType)(AlarmID >> 16);
    uint16 AlarmIndex = AlarmID & 0xffff;
    const AlarmConstType *AlarmConst = NULL;
    AlarmVarType *AlarmVar = NULL;
    const CounterConstType *CounterConst = NULL;
    CounterVarType *CounterVar = NULL;
    
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
    if (result == E_OK && AlarmIndex >= SystemObjects[_CoreID]->alarmsCount)
    {
        result = E_OS_ID;
    }
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }

    if (result == E_OK && CoreID != _CoreID)
    {
        /* check access right */
        /* go to the core */
        /* wait the api completed */
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_SETRELALARM;
        CrossCoreServicePara[CoreID].para1 = AlarmID;
        CrossCoreServicePara[CoreID].para2 = increment;
        CrossCoreServicePara[CoreID].para3 = cycle;
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
    AlarmConst = SystemObjects[_CoreID]->AlarmConst;
    AlarmVar = SystemObjects[_CoreID]->AlarmVar;
    CounterConst = SystemObjects[_CoreID]->CounterConst;
    CounterVar = SystemObjects[_CoreID]->CounterVar;


    if (result == E_OK && AlarmIndex >= SystemObjects[_CoreID]->alarmsCount)
    {
        result = E_OS_ID;
    }
    /* @2022/05/01 Sam */
    /* SWS_Os_00304 */
    if (result == E_OK &&
            ((increment > CounterConst[AlarmConst[AlarmIndex].counter & 0xffff].maxAllowedValue) || 
            (increment == 0)))
    {
        result = E_OS_VALUE;
    }

    if (result == E_OK && (cycle != 0) &&
            ((cycle > CounterConst[AlarmConst[AlarmIndex].counter & 0xffff].maxAllowedValue) ||
             (cycle < CounterConst[AlarmConst[AlarmIndex].counter & 0xffff].minCycle)))
    {
        result = E_OS_VALUE;
    }

    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_SYS_NOFUNC;
    }

    if (result == E_OK && AlarmVar[AlarmIndex].active)
    {
        result = E_OS_STATE;
    }
    if (result == E_OK)
    {
        CounterVarRef = &CounterVar[AlarmConst[AlarmIndex].counter & 0xffff];
        CounterConstRef = &CounterConst[AlarmConst[AlarmIndex].counter & 0xffff];

        AlarmVar[AlarmIndex].expireCount = CounterVarRef->currentCounts + increment;
        if (AlarmVar[AlarmIndex].expireCount > CounterConstRef->maxAllowedValue)
        {
            AlarmVar[AlarmIndex].expireCount -= (CounterConstRef->maxAllowedValue + 1);
        }
        AlarmVar[AlarmIndex].cycle = cycle;
        AlarmVar[AlarmIndex].active = 1;

        InsertAlarm(AlarmID);
    }
    if (result == E_OS_SYS_OK_CROSSCORE)
    {
        result = E_OK;
    }
#endif /* #if (ALARMS_COUNT > 0) */
#if (ALARMS_COUNT == 0)
    StatusType result = E_OS_ID;
#endif
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
StatusType SysSetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle)
{
#if (ALARMS_COUNT > 0)
    StatusType result = E_OK;
    CoreIdType CoreID = (CoreIdType)(AlarmID >> 16);
    uint16 AlarmIndex = AlarmID & 0xffff;
    const AlarmConstType *AlarmConst = NULL;
    AlarmVarType *AlarmVar = NULL;
    const CounterConstType *CounterConst = NULL;

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
    if (result == E_OK && AlarmIndex >= SystemObjects[_CoreID]->alarmsCount)
    {
        result = E_OS_ID;
    }
    if (result == E_OK &&~(SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }

    if (result == E_OK && CoreID != _CoreID)
    {
        /* check access right */
        /* go to the core */
        /* wait the api completed */
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_SETABSALARM;
        CrossCoreServicePara[CoreID].para1 = AlarmID;
        CrossCoreServicePara[CoreID].para2 = start;
        CrossCoreServicePara[CoreID].para3 = cycle;
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1);

        result = CrossCoreServicePara[CoreID].result;
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        enableCrossCoreISR();
        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
    }
    AlarmConst = SystemObjects[_CoreID]->AlarmConst;
    AlarmVar = SystemObjects[_CoreID]->AlarmVar;
    CounterConst = SystemObjects[_CoreID]->CounterConst;

    if (result == E_OK && AlarmIndex >= SystemObjects[_CoreID]->alarmsCount)
    {
        result = E_OS_ID;
    }

    if (result == E_OK &&
            start > CounterConst[AlarmConst[AlarmIndex].counter & 0xffff].maxAllowedValue)
    {
        result = E_OS_VALUE;
    }

    if (result == E_OK && (cycle != 0) &&
            ((cycle > CounterConst[AlarmConst[AlarmIndex].counter & 0xffff].maxAllowedValue) ||
             (cycle < CounterConst[AlarmConst[AlarmIndex].counter & 0xffff].minCycle)))
    {
        result = E_OS_VALUE;
    }


    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_SYS_NOFUNC;
    }

    if (result == E_OK && AlarmVar[AlarmIndex].active)
    {
        result = E_OS_STATE;
    }

    if (result == E_OK)
    {
        AlarmVar[AlarmIndex].expireCount = start;
        AlarmVar[AlarmIndex].cycle = cycle;
        AlarmVar[AlarmIndex].active = 1;
        InsertAlarm(AlarmID);
    }
    if (result == E_OS_SYS_OK_CROSSCORE)
    {
        result = E_OK;
    }
#endif /* #if (ALARMS_COUNT > 0) */
#if (ALARMS_COUNT == 0)
    StatusType result = E_OS_ID;
#endif /* (ALARMS_COUNT == 0) */
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

StatusType SysCancelAlarm(AlarmType AlarmID)
{
#if (ALARMS_COUNT > 0)
    StatusType result = E_OK;
    CoreIdType CoreID = (CoreIdType)(AlarmID >> 16);
    uint16 AlarmIndex = AlarmID & 0xffff;
    AlarmVarType *AlarmVar;

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
    if (result == E_OK && AlarmIndex >= SystemObjects[CoreID]->alarmsCount)
    {
        result = E_OS_ID;
    }
    if (result == E_OK &&~(SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->AlarmAutosar[AlarmIndex].owner;
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
        CrossCoreServicePara[CoreID].serviceID = SERVICE_CANCELALARM;
        CrossCoreServicePara[CoreID].para1 = AlarmID;
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
    AlarmVar = SystemObjects[_CoreID]->AlarmVar;
#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
    if (result == E_OK && AlarmIndex >= SystemObjects[_CoreID]->alarmsCount)
    {
        result = E_OS_ID;
    }
#endif

    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_SYS_NOFUNC;
    }

    if (result == E_OK && !AlarmVar[AlarmIndex].active)
    {
        result = E_OS_NOFUNC;
    }

    if (result == E_OK)
    {
        RemoveAlarm(AlarmID);
        AlarmVar[AlarmIndex].active = 0;
    }
    if (result == E_OS_SYS_OK_CROSSCORE)
    {
        result = E_OK;
    }
#endif
#if (ALARMS_COUNT == 0)
    StatusType result = E_OS_ID;
#endif
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