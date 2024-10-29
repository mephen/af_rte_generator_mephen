#include "application.h"
#include "os.h"
#include "system.h"
#include "scheduler.h"
#include "task.h"
#include "systemcall.h"
#include "application_Cfg.h"
#include "trustedFunc_Cfg.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "scheduleTable_Cfg.h"
#include "memsection.h"
#include "memprot.h"
#include "lock.h"
#include "alarm.h"
#include "memprot_Cfg.h"
#include "ISRInit.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/* SWS_Os_00016, SWS_Os_00514 */
ApplicationType GetApplicationID(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETAPPLICATIONID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00797, SWS_Os_00800 */
ApplicationType GetCurrentApplicationID(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETCURRENTAPPLICATIONID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00256 SWS_Os_00519 */
/* allowed ObjectTypeType defined in SPEC:
OBJECT_TASK
OBJECT_ISR
OBJECT_ALARM
OBJECT_RESOURCE
OBJECT_COUNTER 
OBJECT_SCHEDULETABLE
Also, if the owner OS-App of the object is not in APPLICATION_ACCESSIBLE,
this service will also return NO_ACCESS
*/
ObjectAccessType CheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, uint32 objectID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_CHECKOBJECTACCESS;
    para.para1 = ApplID;
    para.para2 = ObjectType;
    para.para3 = objectID;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return (ObjectAccessType)para.result;
}

/* SWS_Os_00017, SWS_Os_00520 */
/* allowed ObjectTypeType defined in SPEC:
OBJECT_TASK
OBJECT_ISR
OBJECT_ALARM
OBJECT_RESOURCE ->this is not belong to OS-App, so this type will return INVALID_OSAPP
OBJECT_COUNTER 
OBJECT_SCHEDULETABLE
*/
ApplicationType CheckObjectOwnership( ObjectTypeType ObjectType, uint32 objectID)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_CHECKOBJECTOWNERSHIP;
    para.para1 = ObjectType;
    para.para2 = objectID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00258 */
StatusType TerminateApplication(ApplicationType AppID, RestartType RestartOption)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_TERMINATEAPPLICATION;
    para.para1 = AppID;
    para.para2 = RestartOption;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00501 */
StatusType AllowAccess(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_ALLOWACCESS;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00499 SWS_Os_00537 */
StatusType GetApplicationState(ApplicationType Application, ApplicationStateRefType Value)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETAPPLICATIONSTATE;
    para.para1 = Application;
    para.para2 = (uint32)Value;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}



/* SWS_Os_00512 */
/* AccessType using only LSB 4 bits for [IS_STACK, IS_EXECUTABLE, IS_WRITABLE, IS_READABLE]*/
AccessType CheckISRMemoryAccess(ISRType ISRID, MemoryStartAddressType Address, MemorySizeType Size)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_CHECKISRMEMORYACCESS;
    para.para1 = ISRID;
    para.para2 = (uint32)Address;
    para.para3 = Size;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00513 SWS_Os_00517*/
/* AccessType using only LSB 4 bits for [IS_STACK, IS_EXECUTABLE, IS_WRITABLE, IS_READABLE]*/
/* This funciton must be modified */
/* The */
AccessType CheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_CHECKTASKMEMORYACCESS;
    para.para1 = TaskID;
    para.para2 = (uint32)Address;
    para.para3 = Size;
    para.result = E_OK;

    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;    
}


/* SWS_Os_00097 SWS_Os_00518 */
StatusType CallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_CALLTRUSTEDFUNCTION;
    para.para1 = FunctionIndex;
    para.para2 = (uint32)FunctionParams;
    // para.para3 = Size;
    para.result = E_OK;

    pushStack(&para);
    sysCallTrustFunc();
    popStack();
    return para.result;    
}





ApplicationType SysGetApplicationID(void)
{
    uint16 currentTaskIdx;
    ApplicationType result;
    
    if(systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
    }
    /* Check the OS state, system service may be limited in some states */
    else if(systemFlag & SERVICE_LIMIT_CAT4)
    {
    }else{
        currentTaskIdx = (CURRENTTASK.CurrentConst->id) & 0xffff;
        result = SystemObjectAutosar[_CoreID]->TaskAutosar[currentTaskIdx].owner; /* SWS_Os_00261 */ 
    }
    /* SWS_Os_00262 */

    return result;
}

ApplicationType SysGetCurrentApplicationID(void)
{
    ApplicationType result = INVALID_OSAPPLICATION;

    /* SWS_Os_00799 */
    /* since OS-App is a must-do in SC4, we will not hit this SWS_Os_00799 status*/
    if(systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
    }
    /* Check the OS state, system service may be limited in some states */
    else if(systemFlag & SERVICE_LIMIT_CAT4)
    {
    }else{
        result = ExecutingApp[_CoreID]; 
    }
    /* SWS_Os_00798 */

    return result;
}

ObjectAccessType SysCheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, uint32 objectID)
{
    ApplicationsMaskType Mask;
    CoreIdType objCoreID;
    uint16 objIndex;
    ObjectAccessType result; 

    Mask = 1 << ApplID;
    objCoreID = objectID >> 16;
    objIndex = objectID & 0xffff;
    result = ACCESS;   //assume available at start

    if (ApplID >= APPLICATIONS_COUNT)
    {
        Mask = 0;   /* SWS_Os_00423 */ /* invalid app-ID */
    }
    else if( systemFlag & (SERVICE_LIMIT_CAT5) )
    {
        Mask = 0;   /* SWS_Os_00088 */  
    }
    else
    {
        /* SWS_Os_00271 */
        switch (ObjectType)
        {
        case OBJECT_TASK:
            if( ApplicationVar[ SystemObjectAutosar[objCoreID]->TaskAutosar->owner ].State != APPLICATION_ACCESSIBLE )
            {
                Mask = 0;   /* SWS_Os_00504 */
            }
            else if (objIndex >= SystemObjectAutosar[objCoreID]->tasksCount)
            {
                Mask = 0;
            }
            else
            {
                Mask &= SystemObjectAutosar[objCoreID]->TaskAutosar[objIndex].applicationsMask;
            }
            break;
        case OBJECT_ISR:
            if( ApplicationVar[ SystemObjectAutosar[objCoreID]->IsrAutosar ->owner ].State != APPLICATION_ACCESSIBLE )
            {
                Mask = 0;   /* SWS_Os_00504 */
            }
            else if (objIndex >= SystemObjects[objCoreID]->isrAllCount)
            {
                Mask = 0;
            }
            else
            {
                Mask &= SystemObjectAutosar[objCoreID]->IsrAutosar[objIndex].applicationsMask;
            }
            break;
        case OBJECT_ALARM:
            if( ApplicationVar[ SystemObjectAutosar[objCoreID]->AlarmAutosar->owner].State != APPLICATION_ACCESSIBLE )
            {
                Mask = 0;   /* SWS_Os_00504 */
            }
            else if (objIndex >= SystemObjectAutosar[objCoreID]->alarmsCount)
            {
                Mask = 0;
            }
            else
            {
                Mask &= SystemObjectAutosar[objCoreID]->AlarmAutosar[objIndex].applicationsMask;
            }
            break;
        case OBJECT_RESOURCE:
            if( ApplicationVar[ SystemObjectAutosar[objCoreID]->AlarmAutosar->owner].State != APPLICATION_ACCESSIBLE )
            {
                Mask = 0;   /* SWS_Os_00504 */
            }
            else if (objIndex >= SystemObjectAutosar[objCoreID]->resourcesCount)
            {
                Mask = 0;
            }
            else
            {   /* TODO: wait RESOURCE's applicationsMask to be implemented, then this should be fixed */
                Mask = (objCoreID == (objectID >> 16)); 
            }
            break;
        case OBJECT_COUNTER:
            if( ApplicationVar[ SystemObjectAutosar[objCoreID]->CounterAutosar->owner].State != APPLICATION_ACCESSIBLE )
            {
                Mask = 0;   /* SWS_Os_00504 */
            }
            else if (objIndex >= SystemObjectAutosar[objCoreID]->countersCount)
            {
                Mask = 0;
            }
            else
            {
                Mask &= SystemObjectAutosar[objCoreID]->CounterAutosar[objIndex].applicationsMask;        
            }
            break;
        case OBJECT_SCHEDULETABLE:
            if( ApplicationVar[ SystemObjectAutosar[objCoreID]->ScheduleTableAutosar->owner].State != APPLICATION_ACCESSIBLE )
            {
                Mask = 0;   /* SWS_Os_00504 */
            }
            else if (objIndex >= SystemObjectAutosar[objCoreID]->scheduletablesCount)
            {
                Mask = 0;
            }
            else
            {
                Mask &= SystemObjectAutosar[objCoreID]->ScheduleTableAutosar[objIndex].applicationsMask;        
            }
            break;
        default:
            Mask = 0;
        }
    }

    if (Mask == 0)  //because at least one bit will be set (the owner), == 0 means err or no-access-right 
    {
        result = NO_ACCESS; /* SWS_Os_00272*/
    }

    return result;
}

ApplicationType SysCheckObjectOwnership( ObjectTypeType ObjectType, uint32 objectID)
{
    CoreIdType CoreID = objectID >> 16;
    uint16 Index = objectID & 0xffff;
    ApplicationType AppID;

    if( systemFlag & (SERVICE_LIMIT_CAT5) )
    {
        AppID = INVALID_OSAPPLICATION;  
    }else{
    /* SWS_Os_00273 */
        switch (ObjectType)
        {
        case OBJECT_TASK:
            if (Index >= SystemObjectAutosar[CoreID]->tasksCount)
            {
                AppID = INVALID_OSAPPLICATION;
            }
            else
            {
                AppID = SystemObjectAutosar[CoreID]->TaskAutosar[Index].owner;
            }
            break;
        case OBJECT_ISR:
            if (Index >= SystemObjectAutosar[CoreID]->isrsCount)
            {
                AppID = INVALID_OSAPPLICATION;
            }
            else
            {
                AppID = SystemObjectAutosar[CoreID]->IsrAutosar[Index].owner;
            }
            break;
        case OBJECT_ALARM:
            if (Index >= SystemObjectAutosar[CoreID]->alarmsCount)
            {
                AppID = INVALID_OSAPPLICATION;
            }
            else
            {
                AppID = SystemObjectAutosar[CoreID]->AlarmAutosar[Index].owner;
            }
            break;
        case OBJECT_COUNTER:
            if (Index >= SystemObjectAutosar[CoreID]->countersCount)
            {
                AppID = INVALID_OSAPPLICATION;
            }
            else
            {
                AppID = SystemObjectAutosar[CoreID]->CounterAutosar[Index].owner;
            }
            break;
        case OBJECT_SCHEDULETABLE:
            if (Index >= SystemObjectAutosar[CoreID]->scheduletablesCount)
            {
                AppID = INVALID_OSAPPLICATION;
            }
            else
            {
                AppID = SystemObjectAutosar[CoreID]->ScheduleTableAutosar[Index].owner;
            }
            break;
        default:
            AppID = INVALID_OSAPPLICATION; /* SWS_Os_00274 */
        }
    }
    return AppID;
}

StatusType SysTerminateApplication(ApplicationType AppID, RestartType RestartOption)
{
    StatusType result;
    //ApplicationType currentAppID;
    ApplicationType executingAppID;
    CoreIdType TargetCoreID;
    
    result = E_OK;
    executingAppID = ExecutingApp[_CoreID];
    TargetCoreID = ApplicationVar[AppID].CoreRef;

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    if(result == E_OK && systemFlag & ((IN_ISR1_HANDLER) | \
                            (IN_PRE_TASK_HOOK) | (IN_POST_TASK_HOOK) | (IN_STARTUP_HOOK) | \
                            (IN_SHUTDOWN_HOOK) | (IN_OSAPP_STARTUP_HOOK)| (IN_OSAPP_SHUTDOWN_HOOK) | \
                            (IN_OSAPP_ERROR_HOOK) | (IN_ALARM_CALLBACK) | (IN_PROTECTION_HOOK)) )
    {
        result = E_OS_CALLEVEL;
    }
    if (result == E_OK && AppID >= APPLICATIONS_COUNT)
    {
        result = E_OS_ID; /* SWS_Os_00493 */
    }

    if (result == E_OK && RestartOption != RESTART && RestartOption != NO_RESTART)
    {
        /* the value of parameter is not a legal value */
        result = E_OS_VALUE; /* SWS_Os_00459 */
    }

    if (result == E_OK && executingAppID != AppID 
        && ApplicationVar[executingAppID].OsTrusted == FALSE)
    {
        /*if the caller is not a trusted-OSApp, it is only allowed to teminate itself*/
        result = E_OS_ACCESS; /* SWS_Os_00494 */
    }

    if ( result == E_OK && executingAppID != AppID 
        && ( systemFlag & (IN_ERROR_HOOK|IN_OSAPP_ERROR_HOOK) ) )
    {
        /* At OS_SPEC page.70, bottom side little note with Table 7.1: */
        /* if in error-hook, only self-terminate is allowed */
        result = E_OS_ACCESS;
    }
    

    if (result == E_OK && getAppStateIntenal(AppID) == APPLICATION_TERMINATED )  
    {
        result = E_OS_STATE;    /*[SWS_Os_00507]*/
    }

    if (result == E_OK && getAppStateIntenal(AppID) == APPLICATION_RESTARTING 
                       && executingAppID != AppID )  
    {
        /* when OS-App is APPLICATION_RESTARTING, 
           only the App's own restart-task is allowed to call TerminateApplication */
           result = E_OS_STATE;  /*[SWS_Os_00508] */
    }


    if (result == E_OK && getAppStateIntenal(AppID) == APPLICATION_RESTARTING 
                       && executingAppID == AppID 
                       && RestartOption == RESTART ) 
    {
        /* when in APPLICATION_RESTARTING, */
        /* the restart task should call AllowAccess() to restart */
        /* instead of  TerminateApplication with RESTART*/
        result = E_OS_STATE; /*[SWS_Os_00548]*/
    }


    /* below the service finally runs */
    /* cross-core seervice call */
    if (result == E_OK && _CoreID != ApplicationVar[AppID].CoreRef)
    {   
        enableCrossCoreISR();
        GetLock(&CoreParaLock[TargetCoreID], LOCKBIT);

        CrossCoreServicePara[TargetCoreID].serviceID = SERVICE_GETAPPLICATIONSTATE;
        CrossCoreServicePara[TargetCoreID].para1 = (uint32)AppID;
        CrossCoreServicePara[TargetCoreID].para2 = (uint32)RestartOption;
        CrossCoreServicePara[TargetCoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[TargetCoreID] = 1;
        InterruptToCore(TargetCoreID);
        while (CoreIntFlag[TargetCoreID] == 1){
            ; /*wait till it finish*/
        }
        ReleaseLock(&CoreParaLock[TargetCoreID], LOCKBIT);
        result = CrossCoreServicePara[TargetCoreID].result;
        disableCrossCoreISR();
        if( result == E_OS_STATE){
            /* since we check the state first at local core 
               and check the state again at remote core, 
               the only reason that cause E_OS_STATE is SWS_Os_00507 & SWS_Os_00508,
               and the only way E_OS_STATE can happen is that:
               the app's state is changed during the time when InterruptToCore pending.
               Therfore, we set the result back to E_OK,
               to mimic that it successfully terminate the app, as SWS_Os_00615 stated */
            result = E_OK;  /* SWS_Os_00615 */
        }

        
    }
    else if( result == E_OK )   /* start terminating in local core */
    {       
        /* Restart-task not configured */
        if( ApplicationVar[AppID].RestartTaskID == 0 )
        {
            if( systemFlag | IN_PROTECTION_HANDLER && RestartOption == RESTART ){
                ShutdownOS(E_OS_RESTART_WITHOUT_RESTART_TASK_IN_PROTECTION_HOOK);   /* SWS_Os_00287 */
            }
            else{
                TerminateAppInternal(AppID);
            }

            setAppStateIntenal(AppID, APPLICATION_TERMINATED);
        }
        /* Restarte-task configured */
        else
        {
            /* first, we conduct the terminating process*/
            TerminateAppInternal(AppID);

            if ( RestartOption == RESTART ){
                /* second, if user actually want to restart, we need to re-init memory*/
                ReInitOSAppRomToRamMemArea(AppID); 
                setAppStateIntenal(AppID, APPLICATION_RESTARTING);
                /* activate the Restart-task if it is configured */
                ActivateTaskInternal(ApplicationVar[AppID].RestartTaskID); /* SWS_Os_00287 */
            }
            else{
                setAppStateIntenal(AppID, APPLICATION_TERMINATED);
                /* activate the Restart-task if it is configured */
                ActivateTaskInternal(ApplicationVar[AppID].RestartTaskID); /* SWS_Os_00287 */
            }
        }
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

StatusType SysAllowAccess(void)
{
    StatusType result;
    uint16 taskIdx; 
    ApplicationType CurrentApp;

    result = E_OK;
    taskIdx = (CURRENTTASK.CurrentConst->id) & 0xffff;
    CurrentApp = SystemObjectAutosar[_CoreID]->TaskAutosar[taskIdx].owner;

    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    }
    if ( getAppStateIntenal(CurrentApp) == APPLICATION_RESTARTING )
    {
        setAppStateIntenal(CurrentApp, APPLICATION_ACCESSIBLE); /* SWS_Os_00498 */

        #if (ALLOWACCESS_AUTO_ENABLE_ALL_ISR_IN_OSAPP)
            EnableAppISR(CurrentApp);
        #endif
        
        result = E_OK;
    }
    else
    {   /* Only allow to switch APPLICATION_RESTARTING to APPLICATION_ACCESSIBLE */
        /* Other cases result in E_OS_STATE */
        result = E_OS_STATE; /* SWS_Os_00497 */
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

StatusType SysGetApplicationState(ApplicationType Application, ApplicationStateRefType Value)
{
    StatusType result;
    CoreIdType TargetCoreID;
    
    //error information block
    {
        /* TODO */
        /* CurrentExecServiceID[ _CoreID ] = this service ID; */
        /* modify DebugServicePara[_CoreID], just like cross-core CrossCoreServicePara */
    }

    result = E_OK;
    TargetCoreID = ApplicationVar[Application].CoreRef;
    /* SWS_Os_00092、SWS_Os_00093 */
    /* Check the OS state, system service may be limited when interrupts are disabled/suspended by a Task/ISR/Hook */
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if(result == E_OK && systemFlag & SERVICE_LIMIT_CAT4)
    {
        result = E_OS_CALLEVEL;
    }
    if (result == E_OK && Application >= APPLICATIONS_COUNT)
    {
        result = E_OS_ID;    /* SWS_Os_00495 */
    }
    if(result == E_OK && !(systemFlag & IN_SERVICE_CORSSCORE) && !CheckWritingAccess(Value))
    {
        result = E_OS_ILLEGAL_ADDRESS;
    }
    if(result == E_OK && TargetCoreID != _CoreID)
    {   /* cross-core seervice call */

        /* when there is a out-parameter in Service */
        /* variable like AppStateForSharing is needed. Because in some embebed-board,   */
        /* data in separated to two cores and core cannot access the other core's data */
        /* so the result should be first save in a share-memory region.  */
        /* The remote core will read the value by AppStateForSharing in the above block */

        GetLock(&CoreParaLock[TargetCoreID], LOCKBIT);
        CrossCoreServicePara[TargetCoreID].serviceID = SERVICE_GETAPPLICATIONSTATE;
        CrossCoreServicePara[TargetCoreID].para1 = (uint32)Application;
        CrossCoreServicePara[TargetCoreID].para2 = (uint32)(&AppStateForSharing);
        CrossCoreServicePara[TargetCoreID].App = ExecutingApp[_CoreID];

        CoreIntFlag[TargetCoreID] = 1;
        InterruptToCore(TargetCoreID);
        while (CoreIntFlag[TargetCoreID] == 1){
            ; /*wait till it finish*/
        }

        /* back from remote core */
        (*Value) = AppStateForSharing;  /* read the value stored by remote core */
        result = CrossCoreServicePara[TargetCoreID].result;
        ReleaseLock(&CoreParaLock[TargetCoreID], LOCKBIT);
        
        if (result == E_OK)
        {   /* used to prevent error-checking, which is already done in the remote core */
            result = E_OS_SYS_OK_CROSSCORE;     
        }

    }
    else if (result == E_OK) /* local core service call */
    {   
        /* no need to call getAppStateIntenal() because remote core need to use 
           InterruptToCore(), and the actual access action is always done on local core*/
        (*Value) = ApplicationVar[Application].State;     /* SWS_Os_00496 */
    }

    if (result == E_OS_SYS_OK_CROSSCORE)
    {   /* this have to be done before error-hook handling block */
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

AccessType SysCheckISRMemoryAccess(ISRType ISRID, MemoryStartAddressType Address, MemorySizeType Size)
{
    uint16 i;
    AccessType result;
    TaskType ISR2TaskRefID;
    CoreIdType CoreID;
    uint8 trustWithMemProt;
    MemProtAreaType *MemProtectArea_task, *MemProtectArea_app, *MemProtectArea_OS;
    uint32 stack_area_bgn;
    uint32 stack_area_end;

    {   
        result = 0;
        CoreID = ISRID >> 16;

        /* Check the OS state, system service may be limited in some states */
        // since AccessType is uint32, and we only use the 4 LSB bit,
        // we use the 4th(from 0) bit to indicate err
        
        if( systemFlag & (SERVICE_LIMIT_CAT5) )
        {
            result = (0x1 << 4); /* SWS_Os_00088 */ //use 4th bit indicate err 
        }
        else if( (ISRID & 0xffff) >=  SystemObjects[_CoreID]->isrAllCount ){
            result = (0x1 << 4);  /* SWS_Os_00268 */ //use 4th bit indicate err
        }

                
        if ( result != 0 ) /* err-detected, not valid */
        {   
            result = 0; //reset to 0, indicate no access  /* SWS_Os_00268 */ /* SWS_Os_00088 */
        }
        else /* no err detect, start checking */
        {     
            // get stack boundery
            stack_area_bgn = MemStackArea[CoreID].MPLAn;
            stack_area_end = MemStackArea[CoreID].MPUAn;

            // check stack
            if( (uint32)Address >= stack_area_bgn 
                && (uint32)((uint8*)Address + Size) <= stack_area_end )
            {
                result |= (0x08);   //is stack (3th bit)
            }

            //check trusted
            if( ApplicationVar[ SystemObjectAutosar[ CoreID ]->IsrAutosar[ ISRID&0xffff ].owner].OsTrusted == TRUE )
            {   
                //Again, since we only use the 4 LSB bit in AccessType, we use the 8th(from 0) bit to indicate trust
                //we will clear this bit before return
                result |= (0x1 << 8);   //this ISR is in a trusted OS-app
            }

            
            // check access right
            // in current version implementation, areaCount is always 7
            // MPLAn is lower bound , MPUAn is upper bound
            // scan each area, we assume all the areas should not be overlap
            trustWithMemProt = ApplicationVar[ SystemObjectAutosar[ CoreID ]->IsrAutosar[ ISRID&0xffff ].owner].OsTrustedApplicationWithProtection;
            ISR2TaskRefID = SystemObjects[ CoreID ]->IsrConst[ ISRID & 0xffff ].ISR2TaskRefIndex;
            
            MemProtectArea_OS = MemProtArea_OS;
            // check os related area
            for (i = 0; i < 3; ++i)
            {   
                //fit into an area bound
                if( (uint32)Address >= MemProtectArea_OS[i].MPLAn  
                     && (uint32)((uint8*)Address + Size) <= MemProtectArea_OS[i].MPUAn )
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_OS[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_OS[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                    
                    break;  //we assume all the 7 areas should not be overlapped
                }
            }

            MemProtectArea_task = SystemObjectAutosar[ CoreID ]->TaskAutosar[ ISR2TaskRefID & 0xffff ].MemArea;
            // check task related area
            for (i = 0; i < 2; ++i)
            {   
                //fit into an area bound
                if( (uint32)Address >= MemProtectArea_task[i].MPLAn  
                     && (uint32)((uint8*)Address + Size) <= MemProtectArea_task[i].MPUAn )
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_task[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_task[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                    
                    break;  //we assume all the 7 areas should not be overlapped
                }
            }
            // check App related area
            MemProtectArea_app =  ApplicationVar[ SystemObjectAutosar[ CoreID ]->IsrAutosar[ ISRID&0xffff ].owner].MemArea;        
            for (i = 0; i < 2; ++i)
            {   
                //fit into an area bound
                if( (uint32)Address >= MemProtectArea_app[i].MPLAn  
                     && (uint32)((uint8*)Address + Size) <= MemProtectArea_app[i].MPUAn )
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                    
                    break;  //we assume all the 7 areas should not be overlapped
                }
            }

            // check text(area 0, 3) overlap
            if(MemProtectArea_OS[0].MPUAn == MemProtectArea_app[0].MPLAn)
            {
                if((uint32)Address >= MemProtectArea_OS[0].MPLAn  
                     && (uint32)((uint8*)Address + Size) <= MemProtectArea_app[0].MPUAn)
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                }
            }
            
            uint32 addressbegin;
            uint32 addressend;
            boolean overlap = FALSE;

            // check data(area 5, 6) overlap
            if(MemProtectArea_app[1].MPUAn == MemProtectArea_task[1].MPLAn)
            {
                addressbegin = MemProtectArea_app[1].MPLAn;
                addressend = MemProtectArea_task[1].MPUAn;
            }
            // check data(area 5, 6) overlap
            if(MemProtectArea_task[0].MPUAn == MemProtectArea_task[1].MPLAn)
            {
                addressbegin = MemProtectArea_task[0].MPLAn;
                addressend = MemProtectArea_task[1].MPUAn;
            }
            // check data(area 5, 6, 7) overlap
            if(MemProtectArea_app[1].MPUAn == MemProtectArea_task[1].MPLAn && MemProtectArea_task[0].MPUAn == MemProtectArea_task[1].MPLAn)
            {
                addressbegin = MemProtectArea_app[1].MPLAn;
                addressend = MemProtectArea_task[1].MPUAn;
            }
            // check data(area 5, 6, 7) overlap
            if(overlap == TRUE)
            {
                if((uint32)Address >= addressbegin  
                     && (uint32)((uint8*)Address + Size) <=addressend)
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                }
            }

            result &= ~(0x1 << 8);  //clear the bit for trusted check
        }
    }

    return result;
}
AccessType SysCheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size)
{
        uint16 i;
    AccessType result;
    CoreIdType CoreID;
    uint8 trustWithMemProt;
    MemProtAreaType *MemProtectArea_task, *MemProtectArea_app, *MemProtectArea_OS;
    uint32 stack_area_bgn;
    uint32 stack_area_end;
    {   
        result = 0;
        CoreID = TaskID >> 16;

        /* Check the OS state, system service may be limited in some states */
        // since AccessType is uint32, and we only use the 4 LSB bit,
        // we use the 4th(from 0) bit to indicate err
        
        if( systemFlag & (SERVICE_LIMIT_CAT5) )
        {
            result = (0x1 << 4); /* SWS_Os_00088 */ //use 4th bit indicate err 
        }
        else if( (TaskID & 0xffff) >= SystemObjects[_CoreID]->tasksCount ){
            result = (0x1 << 4);  /* SWS_Os_00270 */ //use 4th bit indicate err
        }

                
        if ( result != 0 ) /* err-detected, not valid */
        {   
            result = 0; //reset to 0, indicate no access  /* SWS_Os_00270 */ /* SWS_Os_00088 */
        }
        else /* no err detect, start checking */
        {     
             //get stack boundery
            stack_area_bgn = MemStackArea[CoreID].MPLAn;
            stack_area_end = MemStackArea[CoreID].MPUAn;

            //check stack
            if( (uint32)Address >= stack_area_bgn 
                && (uint32)((uint8*)Address + Size) <= stack_area_end )
            {
                result |= (0x08);   //is stack (3th bit)
            }

            //check trusted
            if( ApplicationVar[ SystemObjectAutosar[ CoreID ]->TaskAutosar[ TaskID&0xffff ].owner ].OsTrusted == TRUE )
            {   
                //Again, since we only use the 4 LSB bit in AccessType, we use the 8th(from 0) bit to indicate trust
                //we will clear this bit before return
                result |= (0x1 << 8);   //this ISR is in a trusted OS-app
            }

            
            //check access right
            //in current version implementation, areaCount is always 7
            //MPLAn is lower bound , MPUAn is upper bound
            //scan each area, we assume all the areas should not be overlap
            trustWithMemProt = ApplicationVar[ SystemObjectAutosar[ CoreID ]->TaskAutosar[ TaskID&0xffff ].owner].OsTrustedApplicationWithProtection;
            
            MemProtectArea_OS = MemProtArea_OS;
            // check os related area
            for (i = 0; i < 3; ++i)
            {   
                //fit into an area bound
                if( (uint32)Address >= MemProtectArea_OS[i].MPLAn  
                     && (uint32)((uint8*)Address + Size) <= MemProtectArea_OS[i].MPUAn )
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_OS[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_OS[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                    
                    break;  //we assume all the 7 areas should not be overlapped
                }
            }

            MemProtectArea_task = SystemObjectAutosar[ CoreID ]->TaskAutosar[ TaskID&0xffff ].MemArea;
            // check task related area
            for (i = 0; i < 2; ++i)
            {   
                //fit into an area bound
                if( (uint32)Address >= MemProtectArea_task[i].MPLAn  
                     && (uint32)((uint8*)Address + Size) <= MemProtectArea_task[i].MPUAn )
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_task[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_task[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                    
                    break;  //we assume all the 7 areas should not be overlapped
                }
            }

            // check App related area
            MemProtectArea_app =  ApplicationVar[ SystemObjectAutosar[ CoreID ]->TaskAutosar[TaskID&0xffff].owner].MemArea;        
            for (i = 0; i < 2; ++i)
            {   
                //fit into an area bound
                if( (uint32)Address >= MemProtectArea_app[i].MPLAn  
                     && (uint32)((uint8*)Address + Size) <= MemProtectArea_app[i].MPUAn )
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                    
                    break;  //we assume all the 7 areas should not be overlapped
                }
            }
            // check text(area 0, 3) overlap
            if(MemProtectArea_OS[0].MPUAn == MemProtectArea_app[0].MPLAn)
            {
                if((uint32)Address >= MemProtectArea_OS[0].MPLAn  
                     && (uint32)((uint8*)Address + Size) <= MemProtectArea_app[0].MPUAn)
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                }
            }
            
            uint32 addressbegin;
            uint32 addressend;
            boolean overlap = FALSE;

            // check data(area 5, 6) overlap
            if(MemProtectArea_app[1].MPUAn == MemProtectArea_task[1].MPLAn)
            {
                addressbegin = MemProtectArea_app[1].MPLAn;
                addressend = MemProtectArea_task[1].MPUAn;
            }
            // check data(area 5, 6) overlap
            if(MemProtectArea_task[0].MPUAn == MemProtectArea_task[1].MPLAn)
            {
                addressbegin = MemProtectArea_task[0].MPLAn;
                addressend = MemProtectArea_task[1].MPUAn;
            }
            // check data(area 5, 6, 7) overlap
            if(MemProtectArea_app[1].MPUAn == MemProtectArea_task[1].MPLAn && MemProtectArea_task[0].MPUAn == MemProtectArea_task[1].MPLAn)
            {
                addressbegin = MemProtectArea_app[1].MPLAn;
                addressend = MemProtectArea_task[1].MPUAn;
            }
            // check data(area 5, 6, 7) overlap
            if(overlap == TRUE)
            {
                if((uint32)Address >= addressbegin 
                     && (uint32)((uint8*)Address + Size) <=addressend)
                {
                    if( result & (0x1 << 8) && trustWithMemProt == WithMemProt )
                    {
                        //trusted app 
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_SX | MPAT_SW | MPAT_SR ) ) >> 3; 
                    }
                    else if( result & (0x1 << 8))
                    {   //trusted app & OsTrustedApplicationWithProtection == FALSE
                        //there is no restriction for trusted, in this case.
                        result |= 0x07; //execute/wrtie/read all allow, (0th, 1th, 2th bits)
                    }
                    else
                    {   // non-trusted ISRID
                        //check execute/wrtie/read at the same time
                        result |= ( MemProtectArea_app[i].MPATn & ( MPAT_UX | MPAT_UW | MPAT_UR ) ) >> 0;
                    }
                }
            }

            result &= ~(0x1 << 8);  //clear the bit for trusted check
        }
    }

    return result;
}

StatusType SysCallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams){
    
}


/******* OS-Application management internal function *******/

/* getAppStateIntenal: this function should only be called in critical section e.g., system service */
ApplicationStateType getAppStateIntenal(ApplicationType Application){
    ApplicationStateType state;
    GetLock(&lockForApplicationState[Application], LOCKBIT);
    state = ApplicationVar[Application].State;
    ReleaseLock(&lockForApplicationState[Application], LOCKBIT);
    return state;
}

/* setAppStateIntenal: this function should only be called in critical section e.g., system service */
void setAppStateIntenal(ApplicationType Application, ApplicationStateType value){
    GetLock(&lockForApplicationState[Application], LOCKBIT);
    ApplicationVar[Application].State = value;
    ReleaseLock(&lockForApplicationState[Application], LOCKBIT);
    return;
}

void TerminateAppInternal(ApplicationType AppID){
    TerminateAppTask(AppID);
    DisableAppISR(AppID);
    StopAppAlarm(AppID);
    StopAppScheduleTable(AppID);
}

void TerminateAppTask(ApplicationType Application)
{
    uint16 i; 
    uint16 task_num;
    TaskType *TaskID_arr;
    task_num = ApplicationVar[Application].Objects->Tasks.objectsCount;
    TaskID_arr = (TaskType*)(ApplicationVar[Application].Objects->Tasks.objectsRef);
    
    for (i = 0; i < task_num; i++)
    {
        TerminateSpecificTaskbyOS(TaskID_arr[i]);
    }
}

void DisableAppISR(ApplicationType Application)
{
    uint16 i =0 ; 
    uint16 isr_num;
    ISRType *IsrID_array;
    TaskType isr2TaskID;
    uint16 channel;

    isr_num = ApplicationVar[Application].Objects->ISRs.objectsCount;
    IsrID_array = (ISRType*)(ApplicationVar[Application].Objects->ISRs.objectsRef);
    /* first diable interrupt source to prevent interrupt being triggerd*/
    for (i = 0; i < isr_num; i++)
    {
        channel = SystemObjects[_CoreID]->IsrConst[IsrID_array[i] & 0xffff].ISRchannel;
        disableISR(channel);
        clearpendingISR(channel);
    }

    /* then clear the remaining isr2-task of this OS-App in the system */
    for (i = 0; i < isr_num; i++)
    {   
        if( (Isr_const[_CoreID][ IsrID_array[i] & 0xffff ]).ISRcategory == ISR_CAT_2 ){
            isr2TaskID = (Isr_const[_CoreID][ IsrID_array[i] & 0xffff ]).ISR2TaskRefIndex;
            TerminateSpecificTaskbyOS(isr2TaskID);
        }
    }
}

void EnableAppISR(ApplicationType Application)
{
    uint16 i; 
    uint16 isr_num;
    ISRType *IsrID_array;
    uint16 channel;

    isr_num = ApplicationVar[Application].Objects->ISRs.objectsCount;
    IsrID_array = (ISRType*)(ApplicationVar[Application].Objects->ISRs.objectsRef);
    
    for (i = 0; i < isr_num; i++)
    {
        channel = SystemObjects[_CoreID]->IsrConst[IsrID_array[i] & 0xffff].ISRchannel;
        clearpendingISR(channel);
        enableISR(channel);
        
    }
}

void StopAppAlarm(ApplicationType Application)
{
#if (ALARMS_COUNT > 0)
    uint16 i;
    AlarmVarType *alarmVar_arr = SystemObjects[_CoreID]->AlarmVar;
    uint16 alarm_num = ApplicationVar[Application].Objects->Alarms.objectsCount;
    AlarmType *alarmID_arr = (AlarmType*)(ApplicationVar[Application].Objects->Alarms.objectsRef);
    
    for (i = 0; i < alarm_num; i++)
    {
        if (alarmVar_arr[ alarmID_arr[i] & 0xffff ].active != 0)
        {
            //CancelAlarm( alarmID_arr[i] ); //need further check
            RemoveAlarm( alarmID_arr[i] );
            alarmVar_arr[ alarmID_arr[i] & 0xffff].active = 0;
        }
    }
#endif
}

void StopAppScheduleTable(ApplicationType Application)
{   
    uint16 i;
    uint16 SchTbl_num = ApplicationVar[Application].Objects->ScheduleTables.objectsCount;
    ScheduleTableType *SchTblID_arr = ApplicationVar[Application].Objects->ScheduleTables.objectsRef;
    ScheduleTableConstType *SchTblConst_arr = (ScheduleTableConstType *)SystemObjects[_CoreID]->ScheduleTableConst;
    ScheduleTableVarType *SchTblVar_arr = SystemObjects[_CoreID]->ScheduleTableVar;
    ScheduleTableType nextSchTblID;
    
    for (i = 0; i < SchTbl_num; ++i){
        if(SchTblID_arr[i]==INVALID_SCHEDULETABLE_ID)
        {
            break;
        }
        SchTblVar_arr[ SchTblID_arr[i] ].status = SCHEDULETABLE_STOPPED;
        RemoveAlarm( SchTblConst_arr[ SchTblID_arr[i] ].callbackAlarm );

        //below need further check
        nextSchTblID = SchTblVar_arr[ SchTblID_arr[i] ].next;
        if( nextSchTblID < SCHEDULETABLE_COUNT)
        {
            SchTblVar_arr[ nextSchTblID ].status = SCHEDULETABLE_STOPPED;
            RemoveAlarm(SchTblConst_arr[ nextSchTblID ].callbackAlarm );
        }
    }
}

void SetAPPErrorHookAction(StatusType Error)
{
    SysTaskInformationType info;
    info.ApplID = ExecutingApp[_CoreID];
    info.SysTaskAction = APPLERRORHOOK;
    info.FunctionPointer = ApplicationVar[ExecutingApp[_CoreID]].AppHookFuncArray.ErrorHookFunc;
    info.para =  Error;
    EnSysTaskActionQueue(info);
}

void APPErrorHook(StatusType Error)
{
    SetAPPErrorHookAction(Error);
    ActivateTaskInternal(SysTaskID[_CoreID]);
    ScheduleKernel();
}

StatusType TrustfunctionChecking(TrustedFunctionIndexType FunctionID, TrustedFunctionParameterRefType FunctionParams)
{
    StatusType result = E_OK;
    TrustedFunctionIndexType FunctionIndex = FunctionID  & 0xffff;
    TaskType Taskindex = CurrentTask[_CoreID]->currentID & 0xffff;
    
    if(result == E_OK && systemFlag & (SERVICE_DISABLE_ALL_INT | SERVICE_SUSPEND_ALL_INT | SERVICE_SUSPEND_OS_INT))
    {
        result = E_OS_DISABLEDINT;
    }
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
        result = E_OS_CALLEVEL;
    }
    if( result == E_OK && FunctionIndex >= SystemObjectAutosar[_CoreID]->trustfunctoncount )
    {
        result = E_OS_SERVICEID;
    }
    if( result == E_OK && SystemObjects[_CoreID]->TaskVar[Taskindex].nestedTrustFuncCounter >= MAX_TF_NESTED_CALL)
    {
        result = E_OS_SERVICEID;
    }

    return result;
}