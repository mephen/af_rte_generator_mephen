#include "typedefine.h"
#include "timingprot.h"
#include "system.h"
#include "os.h"
#include "task.h"
#include "application.h"
#include "timingprot_Cfg.h"
#include "task_Cfg.h"
#include "resource_Cfg.h"
#include "application_Cfg.h"
#include "os_Cfg.h"
#include "scheduler.h"

void ProtectionHandle(StatusType Error)
{
    ProtectionReturnType result;

    #if (HOOK_ENABLE_PROTECTIONHOOK == ENABLE)
        systemFlag |= IN_PROTECTION_HOOK;
        result = ProtectionHook(Error);
        systemFlag &= ~IN_PROTECTION_HOOK;
    #else
        // result = PRO_SHUTDOWN;  /* SWS_Os_00107 */
        ShutdownOS(Error);
    #endif /* HOOK_ENABLE_PROTECTIONHOOK == ENABLE */

    /* SWS_Os_00064 */
    
    //
    if(!(systemFlag & AFTER_STARTOS))
    {
        if(systemFlag & IN_OSAPP_STARTUP_HOOK)
        {
            TerminateApplication(ExecutingApp[_CoreID], RESTART);
            TerminateSpecificTaskbyOS(CURRENTTASK.currentID);
        }
        else{
            ShutdownOS(Error);
        }
    }
    else if(systemFlag & IN_SHUT_DOWN_OS)
    {
        if(systemFlag & IN_OSAPP_SHUTDOWN_HOOK)
        {
            TerminateApplication(ExecutingApp[_CoreID], NO_RESTART);
            TerminateSpecificTaskbyOS(CURRENTTASK.currentID);
        }
        else{
            ; // ignore
        }
    }
    else 
    {
        if(Error == E_OS_PROTECTION_ARRIVAL && result!=PRO_IGNORE){
            result = PRO_SHUTDOWN;
        }
        if(Error != E_OS_PROTECTION_ARRIVAL && result==PRO_IGNORE){
            result = PRO_SHUTDOWN;
        }
        switch (result)
        {
        case PRO_IGNORE:
            break;
        case PRO_TERMINATETASKISR:
            TerminateSpecificTaskbyOS(CURRENTTASK.currentID);
            ScheduleKernel();
            break;
        case PRO_TERMINATEAPPL:
            SysTerminateApplication(ExecutingApp[_CoreID], NO_RESTART);
            ScheduleKernel();
            break;
        case PRO_TERMINATEAPPL_RESTART:
            if (ApplicationVar[ ExecutingApp[_CoreID] ].RestartTaskID == 0)
            {
                ShutdownOS(Error);
            }
            else
            {
                SysTerminateApplication(ExecutingApp[_CoreID], RESTART);
            }
            break;
        case PRO_SHUTDOWN:
            ShutdownOS(Error);
            break;
        default:
            break;      /* SWS_Os_00308 */
        }
    }
    return;
}
/* Todo: Timning protection linked-list will fault if ProtectionHook Terminate a task */
/* Need to modify the linked list */

/* This function will be called at timer interrupt. */
void TimingProtection()
{
    TimingProtCounterType *Tmp = TimingCounterList[_CoreID];
    uint32 temp1 = SystemObjects[_CoreID]->TaskVar[CurrentTask[_CoreID]->currentID & 0xffff].nestedTrustFuncCounter;
    uint32 temp2 = ApplicationVar[ExecutingApp[_CoreID]].OsTrustedApplicationDelayTimingViolationCall;
    while (Tmp != NULL)
    {
        if(Tmp->Bound != ((uint32)(0)-1))
        {
            Tmp->Counter++;
        }
        if (Tmp->Counter >= Tmp->Bound )
        {
            switch (Tmp->ProtectionType)
            {
            case IDLETASKBUDGET:
                Tmp->Counter = 0;
                break;
            case EXECUTEBUDGET:
                if( SystemObjects[_CoreID]->TaskVar[CurrentTask[_CoreID]->currentID & 0xffff].nestedTrustFuncCounter!=0 &&
                    ApplicationVar[ExecutingApp[_CoreID]].OsTrustedApplicationDelayTimingViolationCall)
                {
                    // Delay the Protection handle
                    SystemObjects[_CoreID]->TaskVar[CurrentTask[_CoreID]->currentID & 0xffff].isDelay = TRUE;
                    break;
                }
                ProtectionHandle(E_OS_PROTECTION_TIME);
                break;
            case INTLOCKBUDGET:
            case RESLOCKBUDGET:
                ProtectionHandle(E_OS_PROTECTION_LOCKED);
                break;
            case TIMEFRAME:
                // Original Inter-arrival Time Protection​
                // resetTimingCounter(Tmp);
                

                // New Inter-arrival Time Protection
                removeTimingCounter(Tmp);
            }
        }
        Tmp = Tmp->NextTimingCounter;
    }
}

/* Return protection budget */
HardwareTickType getBound(TaskType TaskID, TimingProtTypeType Type, uint32 key)
{
    const TimingProtBudgetType *Budgets = SystemTimingCounter[_CoreID].TimingBudget;
    uint16 TaskIndex = TaskID & 0xffff;
    uint8 i;
    HardwareTickType returnTick = 0;

    switch (Type)
    {
    case EXECUTEBUDGET:
        returnTick = Budgets[TaskIndex].ExecuteBudget;
        break;
    case TIMEFRAME:
        returnTick = Budgets[TaskIndex].TimeFrame;
        break;
    case INTLOCKBUDGET:
        returnTick = Budgets[TaskIndex].LockBudgetRef[key].LockBudget;
        break;
    case RESLOCKBUDGET:
        for(i = 2; i < RESOURCES_COUNT +2 ; i++)
        {
            if (key == Budgets[TaskIndex].LockBudgetRef[i].LockBudgetID)
            {
                returnTick = Budgets[TaskIndex].LockBudgetRef[i].LockBudget;
                break;
            }
        }
    default:
        break;
    }
    return returnTick;
}

/* Add counter to counter list */
/* Start incremnt counter */
void addTimingCounter(TimingProtCounterType *Counter, TimingProtTypeType Type, HardwareTickType Bound)
{
    /* if timeframe */
    if (Type == TIMEFRAME)
    {
        /* Check inter-arrival error */
        if(Counter->Counter <  Bound)
        {
            ProtectionHandle(E_OS_PROTECTION_ARRIVAL);
            /* If inter-arrival error  occur, the counter must be remove from the counterlist */
            removeTimingCounter(Counter);
        }
        /* Due to task arrival , the TIMEFRAME counter must be reset to zero. */
        Counter->Counter = 1;       
    }
    /* Start counter */
    /* Add counter to counterlist */
    if (TimingCounterList[_CoreID] != NULL)
    {
        TimingCounterList[_CoreID]->PreTimgingCounter = Counter;
    }
    Counter->PreTimgingCounter = NULL;
    Counter->NextTimingCounter = TimingCounterList[_CoreID];
    TimingCounterList[_CoreID] = Counter;

    Counter->ProtectionType = Type;
    Counter->Bound = Bound;
}

/* Remove counter from counter list */
/* Stop increment counter */
void removeTimingCounter(TimingProtCounterType *Counter)
{
    
    if (Counter->NextTimingCounter != NULL)
    {
        Counter->NextTimingCounter->PreTimgingCounter = Counter->PreTimgingCounter;
    }
    if (Counter->PreTimgingCounter != NULL)
    {
        Counter->PreTimgingCounter->NextTimingCounter = Counter->NextTimingCounter;
    }
    else
    {
        TimingCounterList[_CoreID] = Counter->NextTimingCounter;
    }
    // Avoid infite loop
    if(Counter->NextTimingCounter == Counter){
        Counter->NextTimingCounter = NULL;
    }
    Counter->NextTimingCounter = NULL;
    Counter->PreTimgingCounter = NULL;
}

/* Stop counter and reset counter */
void resetTimingCounter(TimingProtCounterType *Counter)
{
    removeTimingCounter(Counter);
    if(Counter->ProtectionType ==  TIMEFRAME){
        // Intialize to bound
        // Make sure next time activation will success 
        Counter->Counter = Counter->Bound;
    }else{
        Counter->Counter = 0;
        Counter->Bound = ((uint32)(0)-1);  // Use ((uint32)(0)-1) represent "invalid"
    }
}