#include "softwaretimer.h"
#include "system.h"
#include "counter.h"
#include "systemcall.h"
#include "softwaretimer_Cfg.h"
#include "application.h"
#include "application_Cfg.h"
#include "memprot.h"

/* Return timer value */
/* This function dosen't define in spec.*/
/* SRS_Frt_00033 */
/*  There shall be a function to achieve an atomic read the of the timer’s value. */
StatusType GetSoftwareTimerValue(SoftwareTimerType SoftwareTimerID, TickRefType Value)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETSOFTWARETIMERVALUE;
    para.para1    = (uint32)SoftwareTimerID;
    para.para2    = (uint32)Value;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;

}

/* Return timer value */
/* This function dosen't define in spec.*/
/* SRS_Frt_00047 */
/*   The SWFRT shall provide a “user” dependent API 
(function / macro) to convert ticks to time. */
StatusType TickToMs(SoftwareTimerType SoftwareTimerID, TickType value ,uint32* time)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_TICKTOMS;
    para.para1    = SoftwareTimerID;
    para.para2    = value;
    para.para3    = (uint32)time;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;

}

StatusType SysGetSoftwareTimerValue (SoftwareTimerType SoftwareTimerID, TickRefType Value)
{
    StatusType result = E_OK;
    CoreIdType CoreID = (CoreIdType)(SoftwareTimerID >> 16);
    uint16 SoftwareTimerIndex = SoftwareTimerID & 0xffff;
    SoftwareTimerVarType *SoftwareTimerVar = SystemObjects[_CoreID]->SoftwareTimerVar;


    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    if (SoftwareTimerIndex >= SystemObjects[CoreID]->SoftwareTimerCount)
    {
        result =  E_OS_ID;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(Value))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }

    /* Get timer value */
    if(result == E_OK)
    {
        *Value = SoftwareTimerVar[SoftwareTimerIndex].currentCounts;
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

StatusType SysTickToMs(SoftwareTimerType SoftwareTimerID,SoftwareTimerTickType value,uint32* time)
{
    StatusType result = E_OK;
    CoreIdType CoreID = (CoreIdType)(SoftwareTimerID >> 16);
    uint16 SoftwareTimerIndex = SoftwareTimerID & 0xffff;
    const SoftwareTimerConstType *SoftwareTimerConst = SystemObjects[_CoreID]->SoftwareTimerConst;
    
    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    if (SoftwareTimerIndex >= SystemObjects[CoreID]->SoftwareTimerCount)
    {
        result =  E_OS_ID;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(value))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(time))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }
    if(result == E_OK)
    {
        *time = SoftwareTimerConst[SoftwareTimerIndex].tickPerBase * value * HARDWARETIMER_PERIOD[_CoreID];
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

/* timer interrupt will call this function to tick softwaretimer */
void TimerTick()
{
    SoftwareTimerType current;
    const SoftwareTimerConstType *SoftwareTimerConst = SystemObjects[_CoreID]->SoftwareTimerConst;
    SoftwareTimerVarType *SoftwareTimerVar = SystemObjects[_CoreID]->SoftwareTimerVar;
    for (current = 0; current < SystemObjects[_CoreID]->SoftwareTimerCount; current++){
        if (++(SoftwareTimerVar[current].currentTicks) >= SoftwareTimerConst[current].tickPerBase){
            SoftwareTimerVar[current].currentTicks = 0;
            
            /* Check if softwaretimer overflow */
            if (++SoftwareTimerVar[current].currentCounts > SoftwareTimerConst[current].maxAllowedValue)
            {
                SoftwareTimerVar[current].currentCounts = 0;
            }
            /* Tick counter */
            if(SoftwareTimerConst[current].listLength!= 0)
            {
                CounterTick(SoftwareTimerConst[current].counterList,SoftwareTimerConst[current].listLength);
            }
        }
    }
}