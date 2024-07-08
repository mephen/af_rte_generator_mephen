#include "ScheduleTable.h"
#include "system.h"
#include "os.h"
#include "systemcall.h"
#include "typedefine.h"
#include "alarm.h"
#include "counter.h"
#include "os_Cfg.h"
#include "scheduleTable_Cfg.h"
#include "alarm_Cfg.h"
#include "counter_Cfg.h"
#include "lock.h"
#include "core.h"
#include "task.h"
#include "event.h"
#include "application.h"
#include "ISRInit.h"
#include "Scheduler.h"
/*SWS_Os_00347*/
/*This service starts the processing of a schedule table at "Offset" relative to the "Now" value on
the underlying counter.*/
StatusType StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_STARTSCHEDULETABLEREL;
    para.para1    = ScheduleTableID;
    para.para2    = Offset;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/*SWS_Os_00358*/
/*This service starts the processing of a schedule table at an absolute value "Start" on the
underlying counter.*/
StatusType StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_STARTSCHEDULETABLEABS;
    para.para1    = ScheduleTableID;
    para.para2    = Start;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result; 
}

/*SWS_Os_00006*/
/*This service cancels the processing of a schedule table immediately at any point while the
schedule table is running.*/
StatusType StopScheduleTable(ScheduleTableType ScheduleTableID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_STOPSCHEDULETABLE;
    para.para1    = ScheduleTableID;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result; 
}

/*SWS_Os_00191*/
/* This service switches the processing from one schedule table to another schedule table. */
StatusType NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_NEXTSCHEDULETABLE;
    para.para1    = ScheduleTableID_From;
    para.para2    = ScheduleTableID_To;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/*SWS_Os_00201*/
/*This service starts an explicitly synchronized schedule table synchronously.*/
StatusType StartScheduleTableSynchron(ScheduleTableType ScheduleTableID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_STARTSCHEDULETABLESYNCHRON;
    para.para1    = ScheduleTableID;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result; 
}

/*SWS_Os_00199*/
/*This service provides the schedule table with a synchronization count and start synchronization.*/
StatusType SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SYNCSCHEDULETABLE;
    para.para1    = ScheduleTableID;
    para.para2    = Value;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;

}

/*SWS_Os_00422*/
/*This service stops synchronization of a schedule table.*/
StatusType SetScheduleTableAsync(ScheduleTableType ScheduleTableID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SETSCHEDULETABLEASYNC;
    para.para1    = ScheduleTableID;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/*SWS_Os_00227*/
/* This service queries the state of a schedule table (also with respect to synchronization). */
StatusType GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETSCHEDULETABLESTATUS;
    para.para1    = (uint32)ScheduleTableID;
    para.para2    = (uint32)ScheduleStatus;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}


/*ScheduleTable internal function*/

/*Calculate adjusted delay for next expiry point, and update the rest deviation (shouldn't < 0).*/
TickType AdjustExpiryPoint(ScheduleTableType ScheduleTableID)
{
    ScheduleTableVarType *ScheduleTableVar; 
    const ScheduleTableConstType *ScheduleTableConst;
    uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
    ExpiryPointType *expiryPoints;
    uint32 currentEp;
    long long deviation;
    TickType delay;
    long long adjustment;

    ScheduleTableVar = SystemObjects[_CoreID]->ScheduleTableVar;
    ScheduleTableConst = SystemObjects[_CoreID]->ScheduleTableConst;
    expiryPoints = ScheduleTableConst[ScheduleTableIndex].expiryPoints;
    currentEp = ScheduleTableVar[ScheduleTableIndex].currentEPIndex;
    deviation = ScheduleTableVar[ScheduleTableIndex].deviation;


    if(currentEp == ScheduleTableConst[ScheduleTableIndex].EPAmount-1)
    {
        delay = ScheduleTableConst[ScheduleTableIndex].finalDelay;
    }
    else
    {
        delay = expiryPoints[currentEp+1].offset - expiryPoints[currentEp].offset;
    }


    // Deviation is smaller than maxLengthen or larger than maxShorten
    if(deviation >= 0)
    {
        if(deviation > expiryPoints[currentEp].maxLengthen)
        {
            adjustment = expiryPoints[currentEp].maxLengthen;
        }
        else
        {
            adjustment = deviation;
        }

        delay += adjustment;
        ScheduleTableVar[ScheduleTableIndex].deviation -= adjustment;
    }
    else
    {
        if(-deviation > expiryPoints[currentEp].maxShorten)
        {
            adjustment = -(long long)expiryPoints[currentEp].maxShorten;
        }
        else
        {
            adjustment = deviation;
        }

        delay += adjustment;
        ScheduleTableVar[ScheduleTableIndex].deviation -= adjustment;
    }
    // the timing of the status changed is changed to the adjustable expiry point executing.
    // if(ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_RUNNING)
    // {
    //     // If devitation is bigger than the acceptable precision, the schedule table state will change to SCHEDULETABLE_RUNNING.
    //     //  The schedule table in SCHEDULETABLE_RUNNING state is unsynchron
    //     if(deviation > 0 && deviation <= ScheduleTableConst[ScheduleTableIndex].explicitPrecision)
    //     {
    //         ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
    //     }
    //     if(deviation < 0 && -deviation <= ScheduleTableConst[ScheduleTableIndex].explicitPrecision)
    //     {
    //         ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
    //     }
    // }

    return delay;
}

StatusType SysStartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset)
{
StatusType result = E_OK;
    ScheduleTableVarType *ScheduleTableVar; 
    const ScheduleTableConstType *ScheduleTableConst;
    const CounterConstType *CounterConst;
    uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

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

    if (result == E_OK && ScheduleTableIndex >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /* Check application accessible */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }

    // ToDo 
    // Cross core
    /* Chapter 7.9.8 describes which API need support cross core */
    // Modify crosscore enum in typedefine
    if(result == E_OK && CoreID != _CoreID)
    {
        /* check access right */
        /* go to the core */
        /* wait the api completed */
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_STARTSCHEDULETABLEREL;
        CrossCoreServicePara[CoreID].para1 = ScheduleTableID;
        CrossCoreServicePara[CoreID].para2 = Offset;
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


    ScheduleTableVar = SystemObjects[_CoreID]->ScheduleTableVar;
    ScheduleTableConst = SystemObjects[_CoreID]->ScheduleTableConst;
    CounterConst = SystemObjects[_CoreID]->CounterConst;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
    /*SWS_Os_00275*/

    /*SWS_Os_00452*/
    if (result == E_OK && ScheduleTableConst[ScheduleTableIndex].syncStrategy == IMPLICIT)
    {
        result = E_OS_ID;
    }
    /*SWS_Os_00332, SWS_Os_00276*/
    if (result == E_OK && (Offset == 0 || Offset > CounterConst[ScheduleTableConst[ScheduleTableIndex].counter].maxAllowedValue - ScheduleTableConst[ScheduleTableIndex].initOffset))
    {
        result = E_OS_VALUE;
    }
#endif
    /*SWS_Os_00277*/
    if (result == E_OK && ScheduleTableVar[ScheduleTableIndex].status != SCHEDULETABLE_STOPPED)
    {
        result = E_OS_STATE;
    }
    /*SWS_Os_00278*/
    if(result == E_OK)
    {

        ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING;

        // Set alarm 
        // A ScheduleTable has a correspond alarm
        // The alarm action type is "callback" 
        SysSetRelAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, Offset + ScheduleTableConst[ScheduleTableIndex].initOffset, 0);
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
    /* SWS_Os_00521 not implement yet */
    /* Available in all Saclability Classes */
}

StatusType SysStartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start)
{
    StatusType result = E_OK;
    ScheduleTableVarType *ScheduleTableVar; 
    const ScheduleTableConstType *ScheduleTableConst;
    const CounterConstType *CounterConst;
    uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

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

    if (result == E_OK && ScheduleTableIndex >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /* Check application accessible */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }

    /* Cross core */
    /* Chapter 7.9.8 describes which API need support cross core */
    if(result == E_OK && CoreID != _CoreID)
    {
        /* check access right */
        /* go to the core */
        /* wait the api completed */
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_STARTSCHEDULETABLEABS;
        CrossCoreServicePara[CoreID].para1 = ScheduleTableID;
        CrossCoreServicePara[CoreID].para2 = Start;
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



    ScheduleTableVar = SystemObjects[_CoreID]->ScheduleTableVar;
    ScheduleTableConst = SystemObjects[_CoreID]->ScheduleTableConst;
    CounterConst = SystemObjects[_CoreID]->CounterConst;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
    /*SWS_Os_00348*/
    if (result == E_OK && ScheduleTableIndex >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /*SWS_Os_00349*/
    if (result == E_OK && Start > CounterConst[ScheduleTableConst[ScheduleTableIndex].counter].maxAllowedValue)
    {
        result = E_OS_VALUE;
    }
#endif
    /*SWS_Os_00350*/
    if (result == E_OK && ScheduleTableVar[ScheduleTableIndex].status != SCHEDULETABLE_STOPPED)
    {
        result = E_OS_STATE;
    }
    /*SWS_Os_00351*/
    if(result == E_OK)
    {
        if (ScheduleTableConst[ScheduleTableIndex].syncStrategy == IMPLICIT)
        {
            ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
        }
        else
        {
            ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING;
        }

        //ScheduleTableVar[ScheduleTableID].currentEPIndex++;
        //set alarm
        SysSetAbsAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, Start + ScheduleTableConst[ScheduleTableIndex].initOffset, 0);
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
    /* SWS_Os_00522 not implement yet */
    /* Available in all Saclability Classes */
}

StatusType SysStopScheduleTable(ScheduleTableType ScheduleTableID)
{
    StatusType result = E_OK;
    ScheduleTableVarType *ScheduleTableVar; 
    const ScheduleTableConstType *ScheduleTableConst;
    uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
    uint16 ScheduleTableIndexNext;
    CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

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

    if (result == E_OK && ScheduleTableIndex >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /* Check application accessible */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }

    /* Cross core */
    /* Chapter 7.9.8 describes which API need support cross core */
    if(result == E_OK && CoreID != _CoreID)
    {
        /* check access right */
        /* go to the core */
        /* wait the api completed */
        enableCrossCoreISR();
        GetLock(&CoreParaLock[CoreID], LOCKBIT);
        CrossCoreServicePara[CoreID].serviceID = SERVICE_STOPSCHEDULETABLE;
        CrossCoreServicePara[CoreID].para1 = ScheduleTableID;
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

    ScheduleTableVar = SystemObjects[_CoreID]->ScheduleTableVar;
    ScheduleTableConst = SystemObjects[_CoreID]->ScheduleTableConst;




    /*SWS_Os_00280*/
    if (result == E_OK && ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_STOPPED)
    {
        result = E_OS_NOFUNC;
    }
    /*SWS_Os_00281*/
    if(result == E_OK)
    {

        ScheduleTableIndexNext = ScheduleTableVar[ScheduleTableIndex].next & 0xffff;
        ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_STOPPED;
        RemoveAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm);
        ScheduleTableVar[ScheduleTableIndex].currentEPIndex = 0;
        ScheduleTableVar[ScheduleTableIndex].deviation = 0;
        /*SWS_Os_00453, in 8.4.12 NextScheduleTable()*/
        if(ScheduleTableIndexNext < SystemObjects[_CoreID]->scheduletableCount && ScheduleTableVar[ScheduleTableIndexNext].status == SCHEDULETABLE_NEXT)
        {
            ScheduleTableVar[ScheduleTableIndexNext].status = SCHEDULETABLE_STOPPED;
            ScheduleTableVar[ScheduleTableIndex].next = SystemObjects[_CoreID]->scheduletableCount;
            // RemoveAlarm(ScheduleTableConst[ScheduleTableIndexNext].callbackAlarm);
            // ScheduleTableVar[ScheduleTableIndexNext].currentEPIndex = 0;
            // ScheduleTableVar[ScheduleTableIndexNext].deviation = 0;
        }

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
    /*SWS_Os_00523 not implement yet*/
    /* Available in all Saclability Classes */
}
StatusType SysNextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To){
    StatusType result = E_OK;
    ScheduleTableVarType *ScheduleTableVar; 
    const ScheduleTableConstType *ScheduleTableConst;
    uint16 ScheduleTableIndexFrom = ScheduleTableID_From & 0xffff;
    uint16 ScheduleTableIndexTo = ScheduleTableID_To & 0xffff;
    CoreIdType CoreID = (CoreIdType)(ScheduleTableID_From >> 16);


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

    if (result == E_OK && ScheduleTableIndexFrom >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /* Check application accessible */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndexFrom].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndexFrom].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    /* Dont need support cross core */
    /* Chapter 7.9.8 describes which API need support cross core */
    
    ScheduleTableVar = SystemObjects[_CoreID]->ScheduleTableVar;
    ScheduleTableConst = SystemObjects[_CoreID]->ScheduleTableConst;



    /*SWS_Os_00282*/
    if (ScheduleTableIndexFrom >= SystemObjects[_CoreID]->scheduletableCount || ScheduleTableIndexTo >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /*SWS_Os_00330*/
    if (ScheduleTableConst[ScheduleTableIndexTo].counter != ScheduleTableConst[ScheduleTableIndexFrom].counter)
    {
        result = E_OS_ID;
    }

    /*SWS_Os_00283*/
    if (ScheduleTableVar[ScheduleTableIndexFrom].status == SCHEDULETABLE_STOPPED
        || ScheduleTableVar[ScheduleTableIndexFrom].status == SCHEDULETABLE_NEXT)
    {
        result = E_OS_NOFUNC;
    }
    /*SWS_Os_00309*/
    if (ScheduleTableVar[ScheduleTableIndexTo].status != SCHEDULETABLE_STOPPED)
    {
        result = E_OS_STATE;
    }
    /*SWS_Os_00484*/
    if(ScheduleTableConst[ScheduleTableIndexTo].syncStrategy != ScheduleTableConst[ScheduleTableIndexFrom].syncStrategy)
    {
        result = E_OS_STATE;
    }
    /* SWS_Os_00284 */
    if(result == E_OK)
    {
        /*SWS_Os_00324*/
        /* If ScheduleTableIndexFrom already set a next scheduletable, the origin next scheduketable must be modify its status to STOPPED */
        if((ScheduleTableVar[ScheduleTableIndexFrom].next & 0xffff ) < SystemObjects[_CoreID]->scheduletableCount)
        {
            if((ScheduleTableVar[ScheduleTableIndexFrom].next & 0xffff ) != ScheduleTableIndexFrom)
            {
                ScheduleTableVar[ScheduleTableVar[ScheduleTableIndexFrom].next].status = SCHEDULETABLE_STOPPED;
            }
        }
        ScheduleTableVar[ScheduleTableIndexFrom].next = ScheduleTableID_To;
        ScheduleTableVar[ScheduleTableIndexTo].status = SCHEDULETABLE_NEXT;
    }
    /*SWS_Os_00505 in callbackfunction*/
    /*SWS_Os_00453 in StopScheduleTable*/
    
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
    /* SWS_Os_00524 not implement yet */
    /* Available in all Saclability Classes */
}
StatusType SysStartScheduleTableSynchron(ScheduleTableType ScheduleTableID){
    StatusType result = E_OK;
    ScheduleTableVarType *ScheduleTableVar; 
    const ScheduleTableConstType *ScheduleTableConst;
    uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

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

    if (result == E_OK && ScheduleTableIndex >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /* Check application accessible */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    /* No need support cross core */
    /* Chapter 7.9.8 describes which API need support cross core */

    ScheduleTableVar = SystemObjects[_CoreID]->ScheduleTableVar;
    ScheduleTableConst = SystemObjects[_CoreID]->ScheduleTableConst;

    /*SWS_Os_00387*/

    if(ScheduleTableConst[ScheduleTableIndex].syncStrategy != EXPLICIT)
    {
        result = E_OS_ID;
    }

    /*SWS_Os_00388*/
    if(ScheduleTableVar[ScheduleTableIndex].status != SCHEDULETABLE_STOPPED)
    {
        result = E_OS_STATE;
    }
    /*SWS_Os_00389*/
    if(result == E_OK)
    {
        ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_WAITING;
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
    /*SWS_Os_00525 not implement yet*/
    /* Available in Scalability Classes 2 and 4. */
}
StatusType SysSyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value){
    StatusType result = E_OK;
	TickType offset;
	TickType positionOnTbl;
	long long deviation;
    ScheduleTableVarType *ScheduleTableVar; 
    const ScheduleTableConstType *ScheduleTableConst;
    const CounterConstType *CounterConst;
    CounterVarType *CounterVar;
    uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

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

    if (result == E_OK && ScheduleTableIndex >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /* Check application accessible */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    /* Dont need support cross core */
    /* Chapter 7.9.8 describes which API need support cross core */

    
    ScheduleTableVar = SystemObjects[_CoreID]->ScheduleTableVar;
    ScheduleTableConst = SystemObjects[_CoreID]->ScheduleTableConst;
    CounterVar = SystemObjects[_CoreID]->CounterVar;
    CounterConst = SystemObjects[_CoreID]->CounterConst;



    /*SWS_Os_00454*/
    if (ScheduleTableConst[ScheduleTableIndex].syncStrategy != EXPLICIT)
    {
        result = E_OS_ID;
    }
    /*SWS_Os_00455*/
    if(Value >=  ScheduleTableConst[ScheduleTableIndex].duration)
    {
        result = E_OS_VALUE;
    }

    /*SWS_Os_00456*/
    if(ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_STOPPED || ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_NEXT)
    {
        result = E_OS_STATE;
    }
    /*SWS_Os_00457*/
    if(result == E_OK)
    {
        if(ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_WAITING)
        {
            ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
            ScheduleTableVar[ScheduleTableIndex].deviation = 0;

            // Something wrong
            // Original :
            // start first ep after sycnCounter's maxAllowedValue + 1 - value + initOffset + 1
            // After Modified :
            // start first ep after sycnCounter's maxAllowedValue + 1 - value + initOffset
            // Figure 7.8 explain clearly
            // offset is the distance from value to the counter wrap around
            offset = CounterConst[ScheduleTableConst[ScheduleTableIndex].syncCounter& 0xffff].maxAllowedValue + 1 - Value;
            SetRelAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, offset + ScheduleTableConst[ScheduleTableIndex].initOffset, 0);
        }
        else if(ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS ||
                ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_RUNNING)
        {
            GetCounterValue(ScheduleTableConst[ScheduleTableIndex].syncCounter, &positionOnTbl);
            deviation = (long long)positionOnTbl - (long long)Value; // SWS_Os_00206
            // If devitation is bigger than the acceptable precision, the schedule table state will change to SCHEDULETABLE_RUNNING.
            //  The schedule table in SCHEDULETABLE_RUNNING state is unsynchron
            if(deviation > 0 && deviation > ScheduleTableConst[ScheduleTableIndex].explicitPrecision)
            {
                ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING;
            }else{
                ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
            }
            if(deviation < 0 && -deviation > ScheduleTableConst[ScheduleTableIndex].explicitPrecision)
            {
                ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING;
            }else{
                ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
            }

            ScheduleTableVar[ScheduleTableIndex].deviation = deviation;
        }
        // set sync counter counts
        CounterVar[ScheduleTableConst[ScheduleTableIndex].syncCounter & 0xffff].currentCounts = Value;
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
    /*SWS_Os_00526 not implement yet*/
    /* Available in Scalability Classes 2 and 4 */
}
StatusType SysSetScheduleTableAsync(ScheduleTableType ScheduleTableID){
    StatusType result = E_OK;
    ScheduleTableVarType *ScheduleTableVar; 
    const ScheduleTableConstType *ScheduleTableConst;
    uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

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

    if (result == E_OK && ScheduleTableIndex >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /* Check application accessible */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    /* Dont need support cross core */
    /* Chapter 7.9.8 describes which API need support cross core */

    
    ScheduleTableVar = SystemObjects[_CoreID]->ScheduleTableVar;
    ScheduleTableConst = SystemObjects[_CoreID]->ScheduleTableConst;



    if (ScheduleTableConst[ScheduleTableIndex].syncStrategy != EXPLICIT)
    {
        result = E_OS_ID;
    }

    /*SWS_Os_00483*/
    if(ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_STOPPED ||
        ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_WAITING ||
        ScheduleTableVar[ScheduleTableIndex].status == SCHEDULETABLE_NEXT)
    {
        result = E_OS_STATE;
    }
    /*SWS_Os_00362, SWS_Os_00323, SWS_Os_00300*/
    if(result == E_OK)
    {
        ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING;
        ScheduleTableVar[ScheduleTableIndex].deviation = 0; // stop sync
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
    /*SWS_Os_00527 not implement yet*/
    /* Available in Scalability Classes 2 and 4 */
}
StatusType SysGetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus){
    StatusType result = E_OK;
    ScheduleTableVarType *ScheduleTableVar; 
    uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

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

    if (result == E_OK && ScheduleTableIndex >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }
    /* Check application accessible */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->ScheduleTableAutosar[ScheduleTableIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(ScheduleStatus))
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
        CrossCoreServicePara[CoreID].serviceID = SERVICE_GETSCHEDULETABLESTATUS;
        CrossCoreServicePara[CoreID].para1 = ScheduleTableID;
        CrossCoreServicePara[CoreID].para2 = (uint32)&STStatusForSharing;
        CrossCoreServicePara[CoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[CoreID] = 1;
        InterruptToCore(CoreID);
        while (CoreIntFlag[CoreID] == 1);

        *ScheduleStatus = STStatusForSharing;
        result = CrossCoreServicePara[CoreID].result;
        ReleaseLock(&CoreParaLock[CoreID], LOCKBIT);
        disableCrossCoreISR();
        if (result == E_OK)
        {
            result = E_OS_SYS_OK_CROSSCORE;
        }
        
    }

    ScheduleTableVar = SystemObjects[_CoreID]->ScheduleTableVar;

    /* Dont need extended statue */
    /* SWS_Os_00293 */    
    if (result == E_OK && ScheduleTableIndex >= SystemObjects[_CoreID]->scheduletableCount)
    {
        result = E_OS_ID;
    }


    /*SWS_Os_00289, SWS_Os_00353, *SWS_Os_00354, SWS_Os_00290, SWS_Os_00291*/
    if(result == E_OK)
    {
        *ScheduleStatus = ScheduleTableVar[ScheduleTableIndex].status;
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
    /*SWS_Os_00528 not implement yet*/
    /* Available in all Scalability Classes */
}

void SchedulTableCallbackFunction(ScheduleTableType ScheduleTableID){
    uint16 ScheduleTableIndex = ScheduleTableID & 0xffff;
    CoreIdType CoreID = (CoreIdType)(ScheduleTableID >> 16);

    const CounterConstType *CounterConst = SystemObjects[CoreID]->CounterConst;
    ScheduleTableVarType *ScheduleTableVar = SystemObjects[CoreID]->ScheduleTableVar; 
    const ScheduleTableConstType *ScheduleTableConst = SystemObjects[CoreID]->ScheduleTableConst;
    CounterVarType *CounterVar = SystemObjects[CoreID]->CounterVar; 
    uint32 epIndex = ScheduleTableVar[ScheduleTableIndex].currentEPIndex;
    uint32 i = 0; // temp variable
    TickType delay = 0; // next expiry time - current time 
    TickType Value = CounterVar[ScheduleTableConst[ScheduleTableIndex].syncCounter].currentCounts;
    EventSetting event;
    long long tempDelay = 0;
    ScheduleTableType nextScheduleTable = ScheduleTableVar[ScheduleTableIndex].next;
    uint16 ScheduleTableIndexnext = nextScheduleTable & 0xffff;   
    // If the current expiry point is the dummy expiry point 
    // Dummy expiry point is to stop the schedule table and start the next schedule table
    if(epIndex == ScheduleTableConst[ScheduleTableIndex].EPAmount)
    {   
        // If next == SCHEDULETABLE_COUNT, this mean that don't have next schedule table.
        if(ScheduleTableIndexnext >= SystemObjects[_CoreID]->scheduletableCount && ScheduleTableVar[ScheduleTableIndexnext].status == SCHEDULETABLE_NEXT)
        {
            ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_STOPPED;
            ScheduleTableVar[ScheduleTableIndex].currentEPIndex = 0;
            ScheduleTableVar[ScheduleTableIndex].deviation = 0;
            if(ScheduleTableConst[ScheduleTableIndex].repeating == TRUE)
            {
                ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING;
                SysSetRelAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, ScheduleTableConst[ScheduleTableIndex].initOffset, 0);
            }
            return;
        }
        else
        {
            // set nxet schedule table
              if(ScheduleTableConst[ScheduleTableIndex].syncStrategy == EXPLICIT && ScheduleTableVar[ScheduleTableIndex].status != SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)
            {
                delay = CounterConst[ScheduleTableConst[ScheduleTableIndex].syncCounter].maxAllowedValue + 1 - Value + ScheduleTableConst[nextScheduleTable].initOffset;
            }
            else
            {
                ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_STOPPED;
                if(ScheduleTableConst[ScheduleTableIndex].syncStrategy == NONE)
                {
                    ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING;
                }
                else
                {
                    ScheduleTableVar[ScheduleTableIndexnext].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
                }
                delay = ScheduleTableConst[ScheduleTableIndexnext].initOffset;
            }
            ScheduleTableVar[ScheduleTableIndexnext].currentEPIndex = 0;
            ScheduleTableVar[ScheduleTableIndexnext].deviation = 0;
            SysSetRelAlarm(ScheduleTableConst[ScheduleTableIndexnext].callbackAlarm, delay, 0);
            return;
        }
    }

    // Expiry point do something
    // activate task and set event
    for(i=ScheduleTableConst[ScheduleTableIndex].expiryPoints[epIndex].taskStart; i<ScheduleTableConst[ScheduleTableIndex].expiryPoints[epIndex].taskEnd; ++i)
    {
        ActivateTaskInternal(ScheduleTableConst[ScheduleTableIndex].taskArray[i]);
        ScheduleKernel();
    }
    for(i=ScheduleTableConst[ScheduleTableIndex].expiryPoints[epIndex].eventStart; i<ScheduleTableConst[ScheduleTableIndex].expiryPoints[epIndex].eventEnd; ++i)
    {
        event = ScheduleTableConst[ScheduleTableIndex].eventArray[i];
        SysSetEvent(event.TaskID, event.Mask);
    }
    // if current expiry point is last point, we add a dummy expiry point to stop schedule table
    if(epIndex == ScheduleTableConst[ScheduleTableIndex].EPAmount-1)
    {
        delay = ScheduleTableConst[ScheduleTableIndex].finalDelay;
    }
    else
    {
        delay = ScheduleTableConst[ScheduleTableIndex].expiryPoints[epIndex+1].offset - ScheduleTableConst[ScheduleTableIndex].expiryPoints[epIndex].offset;
    }

    /* if the current expiry point is last expiry point and final delay==0, there is no need to set dammy expiry point */
    if(delay==0)
    {
        /* set next schedule table if next schedule table exist */  
        if(ScheduleTableIndexnext >= SystemObjects[_CoreID]->scheduletableCount && ScheduleTableVar[ScheduleTableIndexnext].status == SCHEDULETABLE_NEXT)
        {
            ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_STOPPED;
            ScheduleTableVar[ScheduleTableIndex].currentEPIndex = 0;
            ScheduleTableVar[ScheduleTableIndex].deviation = 0;
            if(ScheduleTableConst[ScheduleTableIndex].repeating == TRUE)
            {
                ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING;
                SysSetRelAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, ScheduleTableConst[ScheduleTableIndex].initOffset, 0);
            }
            return;
        }
    }

    if(ScheduleTableVar[ScheduleTableIndex].deviation != 0)
    {
        delay = AdjustExpiryPoint(ScheduleTableID);
    }
    // After adjusting, the Schedule tabel that is EXPLICIT will change the status to SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS 
    // Something wrong?: After user Asynchronous start a exmplicit SchedulTable, it may always in SCHEDULETABLE_RUNNING   
    // until provide the the value of the synchronization Counter
    // else if(ScheduleTableConst[ScheduleTableIndex].syncStrategy == EXPLICIT)
    // {
    //     ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
    // }
    if(ScheduleTableConst[ScheduleTableIndex].syncStrategy == EXPLICIT)
    {
        tempDelay = ScheduleTableConst[ScheduleTableIndex].expiryPoints[epIndex].offset - CounterVar[ScheduleTableConst[ScheduleTableIndex].syncCounter].currentCounts;
        if(tempDelay < 0)
        {
            tempDelay=-tempDelay;
        }
        if(tempDelay <= ScheduleTableConst[ScheduleTableIndex].explicitPrecision)
        {
            ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
        }
        else
        {
            ScheduleTableVar[ScheduleTableIndex].status = SCHEDULETABLE_RUNNING;
        }
    }
    
    ScheduleTableVar[ScheduleTableIndex].currentEPIndex++;

    SysSetRelAlarm(ScheduleTableConst[ScheduleTableIndex].callbackAlarm, delay, 0);
}


