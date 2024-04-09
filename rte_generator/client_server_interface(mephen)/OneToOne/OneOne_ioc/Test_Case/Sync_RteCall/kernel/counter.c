#include "counter.h"
#include "os_Cfg.h"
#include "system.h"
#include "systemcall.h"
#include "task.h"
#include "alarm.h"
#include "event.h"
#include "ISRinit.h"
#include "counter_Cfg.h"
#include "application.h"
#include "scheduler.h"
/* @2022/03/20 Sam */
/* SWS_Os_00399 */
/* This service increments a software counter */
/* This service increments a software counter count, and tick dosen't change /*

/******************************************************************************
** Function:    IncrementCounter
** Description:
**             This service increments a software counter. 
** Parameter:   CounterID - The Counter to be incremented
** Return:      
**              E_OK - No errors
**              E_OS_ID -  : The CounterID was not valid or counter is implemented 
**              in hardware and can not be incremented by software
******************************************************************************/
StatusType IncrementCounter (CounterType CounterID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_INCREMENTCOUNTER;
    para.para1    = CounterID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* @2022/03/20 Sam */
/* SWS_Os_00383 */
/* retrun counter count */

/******************************************************************************
** Function:    GetCounterValue
** Description:
**             This service reads the current count value of a counter.
** Parameter:   CounterID - The Counter which tick value should be read
** Return:      
**              E_OK - No errors
**              E_OS_ID -  The <CounterID> was not valid
******************************************************************************/
StatusType GetCounterValue (CounterType CounterID, TickRefType Value)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETCOUNTERVALUE;
    para.para1    = (uint32)CounterID;
    para.para2    = (uint32)Value;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* @2022/04/17 Sam */
/* SWS_Os_00392 */

/******************************************************************************
** Function:    GetElapsedValue
** Description:
**             This service gets the number of ticks between the current tick 
**             value and a previously read tick value
** Parameter:   CounterID - The Counter to be read
**              Value - the previously read tick value of the counter
**              ElapsedValue - The difference to the previous read value
** Return:      
**              E_OK - No errors
**              E_OS_VALUE - The given Value was not valid
**              E_OS_ID - The CounterID was not valid
******************************************************************************/
StatusType GetElapsedValue (CounterType CounterID, TickRefType Value, TickRefType ElapsedValue)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETELAPSEDVALUE;
    para.para1    = CounterID;
    para.para2    = (uint32)Value;
    para.para3    = (uint32)ElapsedValue;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}


/* Countertick with softwaretimer */
void CounterTick(CounterType* counterList, uint32 length)
{
#if (COUNTERS_COUNT > 0)
    CounterType current;
    uint32 listindex = 0;
    const AlarmActionInfoType *Action;

    const AlarmConstType *AlarmConst = SystemObjects[_CoreID]->AlarmConst;
    const CounterConstType *CounterConst = SystemObjects[_CoreID]->CounterConst;
    CounterVarType *CounterVar = SystemObjects[_CoreID]->CounterVar;

    for (listindex = 0; listindex < length ; listindex++)
    {
        current = counterList[listindex];
        if(CounterConst[current].osCounterType == SOFTWARE)
            continue;
        /* Check if counter needs count */   
        if (++(CounterVar[current].currentTicks) >= CounterConst[current].ticksPerBase)
        {
            CounterVar[current].currentTicks = 0;
            /* Check if counts overflow */
            if (++CounterVar[current].currentCounts > CounterConst[current].maxAllowedValue)
            {
                CounterVar[current].currentCounts = 0;
            }
#if (ALARMS_COUNT > 0)
            /* Check if `NextAlarm` expire */
            while ((CounterVar[current].NextAlarm != NULL) &&
                    (CounterVar[current].currentCounts == CounterVar[current].NextAlarm->expireCount))
            {
                AlarmVarType *Expire = CounterVar[current].NextAlarm;
                ApplicationType oldApp = ExecutingApp[_CoreID];
                ExecutingApp[_CoreID] = SystemObjectAutosar[_CoreID]->AlarmAutosar[(Expire->ID) & 0xffff].owner;

                RemoveAlarm(Expire->ID);

                /* Do expire action */
                Action = &AlarmConst[(Expire->ID) & 0xffff].AlarmActionInfo;

                switch (AlarmConst[(Expire->ID) & 0xffff].alarmAction)
                {
                case ACTIVATETASK:
                    /* activate task */
                    
                    ActivateTaskInternal(Action->taskID);
                    break;
                // case ALARMCALLBACK:
                //     /* callback */
                //     if (Action->callbackFunction != NULL)
                //     {
                //         systemFlag |= IN_ALARM_CALLBACK;
                //         Action->callbackFunction();
                //         systemFlag &= ~IN_ALARM_CALLBACK;
                //     }
                //     break;
                case SETEVENT:
                    /* set event */
                    SetEvent(Action->taskID, Action->event);
                    break;
                case INCREMENTCOUNTER:
                    /* incrment counter */
                    IncrementCounter(Action->counterID);
                    break;
                case EPCALLBACK:
                    Expire->active = 0; 
                    SchedulTableCallbackFunction(Action->scheduletableID);
                default:
                    /*todo: special  error code */
                    break;
                }
                /* TODO: report an error, handling block */

                /* Check if `NextAlarm` needs cycle */
                if (!Expire->cycle)
                {
                    Expire->active = 0;
                }
                else
                {
                    Expire->expireCount += Expire->cycle;
                    if (Expire->expireCount > CounterConst[current].maxAllowedValue)
                    {
                        Expire->expireCount -= (CounterConst[current].maxAllowedValue + 1);
                    }
                    InsertAlarm(Expire->ID);
                }
                ExecutingApp[_CoreID] = oldApp;
            }
#endif /* #if (ALARMS_COUNT > 0) */
        }
    }
#endif /* #if (COUNTERS_COUNT > 0) */
}

StatusType SysIncrementCounter(CounterType CounterID)
{

    const AlarmActionInfoType *Action;
    StatusType result = E_OK;
    CoreIdType CoreID = (CoreIdType)(CounterID >> 16);
    uint16 CounterIndex = CounterID & 0xffff;
    const CounterConstType *CounterConst = SystemObjects[CoreID]->CounterConst;
    CounterVarType *CounterVar = SystemObjects[CoreID]->CounterVar;
    const AlarmConstType *AlarmConst = SystemObjects[CoreID]->AlarmConst;

    /* SWS_Os_00629 */
    /* The Counter shall not be incremented by other cores */

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
    /* SWS_Os_00285 */
    /* Counter is not valid or the counter is a hardware counter */
    /* SWS_Os_00589, SWS_Os_00629*/
    if (result == E_OK && CounterIndex >= SystemObjects[CoreID]->countersCount || CounterConst[CounterIndex].osCounterType == HARDWARE)
    {
        result =  E_OS_ID;
    }
    if(CoreID!=_CoreID)
    {
        result =  E_OS_CORE;
    }
    /* check appication mask */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->CounterAutosar[CounterIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->CounterAutosar[CounterIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK)
    {
        /* @2022/03/20 Sam */
        /* SWS_Os_00286 */
        /* SWS_Os_286, SWS_Os_321, SWS_Os_529 */
        /* Add count value by 1 */
        /* wrap if currentCounts exceed */
        if (++CounterVar[CounterIndex].currentCounts > CounterConst[CounterIndex].maxAllowedValue)
        {
            CounterVar[CounterIndex].currentCounts = 0;
        }
            /* Check if `NextAlarm` expire */
            while ((CounterVar[CounterIndex].NextAlarm != NULL) &&
                    (CounterVar[CounterIndex].currentCounts == CounterVar[CounterIndex].NextAlarm->expireCount))
            {
                AlarmVarType *Expire = CounterVar[CounterIndex].NextAlarm;
                ApplicationType oldApp = ExecutingApp[_CoreID];
                ExecutingApp[_CoreID] = SystemObjectAutosar[_CoreID]->AlarmAutosar[(Expire->ID) & 0xffff].owner;

                RemoveAlarm(Expire->ID);

                /* Do expire action */
                Action = &AlarmConst[(Expire->ID) & 0xffff].AlarmActionInfo;

                switch (AlarmConst[(Expire->ID) & 0xffff].alarmAction)
                {
                case ACTIVATETASK:
                    /* activate task */
                    ActivateTaskInternal(Action->taskID);
                    ScheduleKernel();
                    break;
                // case ALARMCALLBACK:
                //     /* callback */
                //     if (Action->callbackFunction != NULL)
                //     {
                //         systemFlag |= IN_ALARM_CALLBACK;
                //         Action->callbackFunction();
                //         systemFlag &= ~IN_ALARM_CALLBACK;
                //     }
                //     break;
                case SETEVENT:
                    /* set event */
                    SetEvent(Action->taskID, Action->event);
                    break;
                case INCREMENTCOUNTER:
                    /* incrment counter */
                    IncrementCounter(Action->counterID);
                    break;
                case EPCALLBACK:
                    /* Schedule Table action */
                    Expire->active = 0; 
                    SchedulTableCallbackFunction(Action->scheduletableID);
                default:
                    /* Do nothing */
                    break;
                }


                /* Check if `NextAlarm` needs cycle */
                if (!Expire->cycle)
                {
                    Expire->active = 0;
                }
                else
                {
                    Expire->expireCount += Expire->cycle;
                    if (Expire->expireCount > CounterConst[CounterIndex].maxAllowedValue)
                    {
                        Expire->expireCount -= (CounterConst[CounterIndex].maxAllowedValue + 1);
                    }
                    InsertAlarm(Expire->ID);
                }
                ExecutingApp[_CoreID] = oldApp;
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
    /*SWS_Os_00530 implicitly implemented*/
}
StatusType  SysGetCounterValue (CounterType CounterID, TickRefType Value)
{
    CoreIdType CoreID = (CoreIdType)(CounterID >> 16);
    uint16 CounterIndex = CounterID & 0xffff;
    CounterVarType *CounterVar = SystemObjects[CoreID]->CounterVar;
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
    /* SWS_Os_00376 */

    if (result== E_OK && CounterIndex >= SystemObjects[CoreID]->countersCount)
    {
        result = E_OS_ID;
    }
    /* SWS_Os_00589 */
    if(CoreID!=_CoreID)
    {
        result =  E_OS_CORE;
    }
    /* check appication mask */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->CounterAutosar[CounterIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->CounterAutosar[CounterIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(Value))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }
    if(result == E_OK)
    {
        /*SWS_Os_00377, SWS_Os_00531*/
        *Value = CounterVar[CounterIndex].currentCounts;
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
    /*SWS_Os_00521 implicitly implemented*/
}
StatusType  SysGetElapsedValue (CounterType CounterID, TickRefType Value, TickRefType ElapsedValue)
{
    StatusType result=E_OK;
    TickType currentTick;
    CoreIdType CoreID = (CoreIdType)(CounterID >> 16);
    uint16 CounterIndex = CounterID & 0xffff;
    const CounterConstType *CounterConst = SystemObjects[CoreID]->CounterConst;
    CounterVarType *CounterVar = SystemObjects[CoreID]->CounterVar;

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
    /* SWS_Os_00381 */
    if (result == E_OK && CounterIndex >= SystemObjects[CoreID]->countersCount)
    {
        result = E_OS_ID;
    }
    /* SWS_Os_00589 */
    if(CoreID!=_CoreID)
    {
        result =  E_OS_CORE;
    }
    /* check appication mask */
    if (result == E_OK && ~(SystemObjectAutosar[CoreID]->CounterAutosar[CounterIndex].applicationsMask) & (1 << ExecutingApp[_CoreID]))
    {
        result = E_OS_ACCESS;
    }
    uint32 ownerID = SystemObjectAutosar[CoreID]->CounterAutosar[CounterIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(Value))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(ElapsedValue))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }
    /* SWS_Os_00391 */
    if (result == E_OK && *Value > CounterConst[CounterIndex].maxAllowedValue)
    {
        result = E_OS_VALUE;
    }
    if(result==E_OK)
    {
        /*SWS_Os_00382*/
        /* check wether counter wrap after last time get Value */
        currentTick = CounterVar[CounterIndex].currentCounts;
        if (currentTick < *Value)
        {
            *ElapsedValue = currentTick + CounterConst->maxAllowedValue + 1 - *Value;
        }
        else
        {
            *ElapsedValue = currentTick - *Value;
        }
        
        /* SWS_Os_00460 */
        /* return the current tick value of the Counter in the <Value> parameter */
        *Value = currentTick;
    }
    /* SWS_Os_00533 no need to implement */
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
    /* SWS_Os_00534 implicitly implemented */
}