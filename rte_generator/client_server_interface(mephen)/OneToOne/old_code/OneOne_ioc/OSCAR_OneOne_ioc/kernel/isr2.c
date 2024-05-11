#include "os.h"
#include "isr2.h"
#include "task.h"
#include "scheduler.h"
#include "task_Cfg.h"
#include "isr_Cfg.h"
#include "os_Cfg.h"
#include "application_Cfg.h"
#include "spinlock_Cfg.h"
#include "system.h"
#include "systemcall.h"
#include "ISRInit.h"
#include "application.h"


/* SWS_Os_00511 SWS_Os_00515 */ 
ISRType GetISRID( void )
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETISRID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}



/* SWS_Os_00813 SWS_Os_91021 */
StatusType ClearPendingInterrupt(ISRType ISRID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_CLEARPENDINGINTERRUPT;
    para.para1    = ISRID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}


/* SWS_Os_00811 SWS_Os_91020 */ 
StatusType EnableInterruptSource(ISRType ISRID, boolean ClearPending)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_ENABLEINTERRUPTSOURCE;
    para.para1    = ISRID;
    para.para2    = ClearPending;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00812 SWS_Os_91019 */
StatusType DisableInterruptSource(ISRType ISRID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_DISABLEINTERRUPTSOURCE;
    para.para1    = ISRID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}


// ActivateISR2 is not a "service"
// so i am not sure error hook should be called or not
// but if not, how to handle error
// or can we prevent?
void ActivateISR2(ISRType IsrID)
{
    uint16 IsrIndex = IsrID & 0xffff;
    CoreIdType IsrCore = IsrID >> 16;
    TaskType Isr2TaskID = SystemObjects[IsrCore]->IsrConst[IsrIndex].ISR2TaskRefIndex;

    ActivateTaskInternal(Isr2TaskID);
    ScheduleKernel();
    // should we use error hook?
    return;
}

/* This function will execute after ISR2 end. */
StatusType TerminateISR2()
{
    StatusType result = E_OK;
    if (result == E_OK)
    {

        /* If ISR2 holding any spinlock and resource before termination, the OS would release them. */
        ReleaseAllLockObject(CURRENTTASK.currentID & 0xffff);
        
        if( CURRENTTASK.CurrentVar->activateCount > 0){
            CURRENTTASK.CurrentVar->activateCount--;
        }

        TerminateTaskInternal();
        ScheduleKernel();
    }


    return result;
}

ISRType SysGetISRID( void ){
    ISRType return_ID = 0; 
    {   
        /* Check the OS state, system service may be limited in some states */
        if( systemFlag & (SERVICE_LIMIT_CAT_ACCESS_CHECK) ){
        
            /* Since the return type is ISRType, the error-code:E_OS_CALLEVEL 
               might be confused when using together with the ID of ISR,
               so here we use INVALID_ISR_ID to indicate error. you can reference to OS SPEC 7.7.3.3*/
            return_ID = INVALID_ISR_ID;    /* 7.7.3.3 Service Calls Made from Wrong Context */
        }
        else if( CURRENTTASK.CurrentConst->Flags.isrTask == 0 ){
            /* SWS_Os_00264 */ /* it is normal task, not isr2-task*/
            return_ID = INVALID_ISR_ID;
        }
        else{
            /* SWS_Os_00263 */
            /* since we append the isr2-task-ID from task-ID, we need subtraction */
            return_ID = CURRENTTASK.currentID - SystemObjects[_CoreID]->tasksCount + 1;   
        }
    }

    return return_ID;
}

StatusType SysClearPendingInterrupt(ISRType ISRID)
{
    StatusType result = E_OK;
    uint16 IsrIndex = ISRID & 0xffff;
    CoreIdType IsrCore = ISRID >> 16;
    uint32 channel;


#if (ISR2_TASKS_COUNT > 0)
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
    if (result==E_OK &&  IsrIndex >= SystemObjects[IsrCore]->isr2TaskCount)
    {
        result = E_OS_ID;
    }
    if(result==E_OK && _CoreID!=IsrCore)
    {
        result = E_OS_CORE;
    }
    if(result==E_OK &&  ExecutingApp[_CoreID] != SystemObjectAutosar[_CoreID]->IsrAutosar[ISRID].owner )
    {
        /* SWS_Os_91020 ,OS SPEC p.180, i am not sure why SPEC only let the owner use */
        result = E_OS_ACCESS;   
    }
    uint32 ownerID = SystemObjectAutosar[_CoreID]->IsrAutosar[IsrIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK)
    {   
        /* SWS_Os_00813 */ /* SWS_Os_00814 */
        channel = SystemObjects[IsrCore]->IsrConst[IsrIndex].ISRchannel;
        clearpendingISR(channel);
        result = E_OK;
    }
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

StatusType SysEnableInterruptSource(ISRType ISRID, boolean ClearPending){
    StatusType result = E_OK;
    uint16 IsrIndex = ISRID & 0xffff;
    CoreIdType IsrCore = ISRID >> 16;
    uint32 channel;



#if (ISR2_TASKS_COUNT > 0)
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
    if (result==E_OK &&  IsrIndex >= SystemObjects[IsrCore]->isr2TaskCount)
    {
        result = E_OS_ID;
    }
    if(result==E_OK && _CoreID!=IsrCore)
    {
        result = E_OS_CORE;
    }
    if(result==E_OK &&  ExecutingApp[_CoreID] != SystemObjectAutosar[_CoreID]->IsrAutosar[ISRID].owner )
    {
        /* SWS_Os_91020 ,OS SPEC p.180, i am not sure why SPEC only let the owner use */
        result = E_OS_ACCESS;   
    }
    uint32 ownerID = SystemObjectAutosar[_CoreID]->IsrAutosar[IsrIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result == E_OK &&checkISRenabled(SystemObjects[IsrCore]->IsrConst[IsrIndex].ISRchannel))
    {
        /* SWS_Os_00809 nested calling is prohibited */
        result = E_OS_NOFUNC;
    }
    if(result == E_OK)
    {   
        channel = SystemObjects[IsrCore]->IsrConst[IsrIndex].ISRchannel;
        if (ClearPending == TRUE)   /* SWS_Os_00811 */
        {
            clearpendingISR(channel);
        } 
        enableISR(channel);
        result = E_OK;
    }
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

StatusType SysDisableInterruptSource(ISRType ISRID){
    StatusType result = E_OS_NOFUNC;
    uint16 IsrIndex = ISRID & 0xffff;
    CoreIdType IsrCore = ISRID >> 16;
    uint32 channel;


#if (ISR2_TASKS_COUNT > 0)
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
    if (result==E_OK &&  IsrIndex >= SystemObjects[IsrCore]->isr2TaskCount)
    {
        result = E_OS_ID;
    }
    if(result==E_OK && _CoreID!=IsrCore)
    {
        result = E_OS_CORE;
    }
    if(result==E_OK &&  ExecutingApp[_CoreID] != SystemObjectAutosar[_CoreID]->IsrAutosar[ISRID].owner )
    {
        /* SWS_Os_91020 ,OS SPEC p.180, i am not sure why SPEC only let the owner use */
        result = E_OS_ACCESS;   
    }
    uint32 ownerID = SystemObjectAutosar[_CoreID]->IsrAutosar[IsrIndex].owner;
    if(result == E_OK && getAppStateIntenal(ownerID) != APPLICATION_ACCESSIBLE)
    {
        result = E_OS_ACCESS;
    }
    if(result==E_OK && (SystemObjects[IsrCore]->IsrConst[IsrIndex].ISRchannel))
    {
        /* SWS_Os_00809 nested calling is prohibited */
        result = E_OS_NOFUNC;
    }
    if(result==E_OK)
    {
        /* SWS_Os_00812 */
        channel = SystemObjects[IsrCore]->IsrConst[IsrIndex].ISRchannel;
        disableISR(channel);
        result = E_OK;
    }
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