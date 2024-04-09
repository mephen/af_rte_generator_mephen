#include "system.h"
#include "task.h"
#include "event.h"
#include "alarm.h"
#include "ScheduleTable.h"
#include "scheduler.h"
#include "ISRInit.h"
#include "core.h"
#include "systemcall.h"
#include "timingprot.h"
#include "memprot.h"
#include "spinlock.h"
#include "task_Cfg.h"
#include "alarm_Cfg.h"
#include "timingprot_Cfg.h"
#include "scheduleTable_Cfg.h"
#include "application.h"
#include "timer.h"
#include "application_Cfg.h"
#include "lock.h"
#include "task.h"
#include "Ioc.h"
extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

#pragma section 

uint8 StartOsSyncFlag = 0;
AlarmBaseType AlarmBaseForSharing;
TickType TickForSharing;
EventMaskType EventMaskForSharing;
TaskStateType TaskStateForSharing;
ScheduleTableStatusType STStatusForSharing;
ApplicationStateType AppStateForSharing;
uint8 ShutdownSyncFlag = 0;

/*********** SELF_AREA per-core variable **********/
#pragma section SELF_AREA

CoreIdType _CoreID;

AppModeType activeApplicationMode;
uint32 systemFlag;
uint32 SysTaskCurrentHandlingApp;

//store kernel & user stack pointer, to imitate stack-switching mechanism 
uint32 mySysStackPtr[1];
uint32 myEISP[1];

int serviceDisableAllInterruptsCounter;
int serviceSuspendAllInterruptsCounter;
int serviceSuspendOSInterruptsCounter;
int InTrustedFunctionCounter;

int kernelDisableAllInterruptsCounter;
int kernelDisableAllISRCounter;
int kernelDisableISR2Counter;
int kernelSystemCallCounter;

int kernelDisableMPUCounter;
int kernelDisableTimerCounter;
int kernelDisableCrossCoreCounter;
int kernelDisableSchedulerCounter;
int kernelDisableISR2Counter;


/***************************************************/


#pragma section

#pragma interrupt INSTRUCTION_EXCEPTION_HANDLER(enable=false, priority=feint, fpu=false, callt=false)
void INSTRUCTION_EXCEPTION_HANDLER(void)
{   /* SWS_Os_00245 */
    ProtectionReturnType result;
    result = PRO_IGNORE;
    DisableMPU();
    
    #if (HOOK_ENABLE_PROTECTIONHOOK == ENABLE)
        systemFlag |= IN_PROTECTION_HOOK;
        result = ProtectionHook(E_OS_PROTECTION_EXCEPTION);
        systemFlag &= ~IN_PROTECTION_HOOK;
    #else
        result = PRO_SHUTDOWN;  /* SWS_Os_00107 */
    #endif  /* HOOK_ENABLE_PROTECTIONHOOK == ENABLE */

    switch (result)
    {
    case PRO_IGNORE:
        /* do nth */
        break;
    case PRO_TERMINATETASKISR:
        TerminateSpecificTaskbyOS(CURRENTTASK.currentID);
        break;
    case PRO_TERMINATEAPPL:
        TerminateApplication(ExecutingApp[_CoreID], NO_RESTART);
        break;
    case PRO_TERMINATEAPPL_RESTART:
        if (ApplicationVar[ ExecutingApp[_CoreID] ].RestartTaskID == 0){
            ShutdownOS(E_OS_PROTECTION_EXCEPTION);
        }
        else{
            TerminateApplication(ExecutingApp[_CoreID], RESTART);
        }
        break;
    case PRO_SHUTDOWN:
        ShutdownOS(E_OS_PROTECTION_EXCEPTION);
        break;
    default:
        break;  /* SWS_Os_00308 */
    }

    EnableMPU();
}


/* SWS_Os_00676, SWS_Os_00574, SWS_Os_00575, SWS_Os_00607*/
void StartCore(CoreIdType CoreID, StatusType *Status)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_STARTCORE;
    para.para1    = CoreID;
    para.para2    = (uint32)Status;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}

void StartOS(AppModeType Mode)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_STARTOS;
    para.para1    = Mode;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}

void ShutdownOS(StatusType Error)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SHUTDOWNOS;
    para.para1    = Error;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}

/* SWS_Os_00674 */
CoreIdType GetCoreID(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETCOREID;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

/* SWS_Os_00672 */
uint32 GetNumberOfActivatedCores(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETNUMBEROFACTIVATEDCORES;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

AppModeType GetActiveApplicationMode (void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_GETACTIVEAPPLICATIONMODE;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return para.result;
}

void ShutdownAllCores(StatusType Error)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SHUTDOWNALLCORES;
    para.para1    = Error;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
    return ;
}

/* SWS_Os_00682 */
void StartNonAutosarCore(CoreIdType CoreID,StatusType* Status)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_STARTNONAUTOSARCORE;
    para.para1    = CoreID;
    para.para2    = (uint32)Status;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}

/******************************************************************************
** Function:    DisableAllInterrupts
** Description:
**              1. This service disables all interrupts for which the hardware
**                 supports disabling (except for timing interrupt).
**              2. The state before is saved for the EnableAllInterrupts call.
**              3. No API service calls are allowed within this critical section.
** Parameter:   None
** Return:      None
******************************************************************************/
void DisableAllInterrupts(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_DISABLEALLINTERRUPTS;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}

/******************************************************************************
** Function:    EnableAllInterrupts
** Description:
**              1. This service restores the state saved by DisableAllInterrupts.
** Parameter:   None
** Return:      None
******************************************************************************/
void EnableAllInterrupts(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_ENABLEALLINTERRUPTS;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}

/******************************************************************************
** Function:    SuspendAllInterrupts
** Description:
**              1. The behavior is the same as DisableAllInterrupts in our
**                 implementation.
**              2. The state before is saved for the ResumeAllInterrupts call.
**              3. No API service calls beside SuspendAllInterrupts/ResumeAllInterrupts
**                 pairs and SuspendOSInterrupts/ResumeOSInterrupts pairs are allowed
**                 within this critical section.
**              4. If this service is called n times, ResumeAllInterrupts has to
**                 be called n times to enable the interrupts back.
** Parameter:   None
** Return:      None
******************************************************************************/
void SuspendAllInterrupts(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SUSPENDALLINTERRUPTS;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}

/******************************************************************************
** Function:    ResumeAllInterrupts
** Description:
**              1. This service restores the state saved by SuspendAllInterrupts.
**              2. If the service SuspendAllInterrupts is called n times, only
**                 the n call to ResumeAllInterrupts will enable all disabled
**                 interrupts.
** Parameter:   None
** Return:      None
******************************************************************************/
void ResumeAllInterrupts(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_RESUMEALLINTERRUPTS;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}

/******************************************************************************
** Function:    SuspendOSInterrupts
** Description: This function disable the category 2 interrupt(priority 2 and
**              lower ei interrupt in this processor).
**              This service is intended to protect a critical section of code.
**              This section shall be finished by calling the ResumeOSInterrupts
**              service.
** Parameter:   None
** Return:      None
******************************************************************************/
void SuspendOSInterrupts(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_SUSPENDOSINTERRUPTS;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}


/******************************************************************************
** Function:    ResumeOSInterrupts
** Description: This function enable the category 2 interrupt(priority 2 and
**              lower ei interrupt in this processor).
**              Finish a critical section that is protected by
**              SuspendOSInterrupts service.
** Parameter:   None
** Return:      None
******************************************************************************/
void ResumeOSInterrupts(void)
{
    SysServiceParaType para;
    para.serviceID  = SERVICE_RESUMEOSINTERRUPTS;
    para.result = E_OK;
    
    pushStack(&para);
    sysCallSystemService();
    popStack();
}

/******************************************************************************
** internal function 
******************************************************************************/
uint32 CheckCoreSync(void)
{
    uint32 i = 0, j = 0;
    
    // Ensure all cores in beforeStartOS change state to waitFirstSync
    // j is number of the core in waitFirstSync 
    // i is just a variable to iterate the all core
    for (i = 0; i < TotalNumberOfCores; )
    {
        if (CoreStatus[i].CoreActivated == beforeStartOS)
        {
            // check the state unitl the state changed to wiatFirstSync
            i = 0;
            j = 0;
        }
        else
        {
            i++;
            if (CoreStatus[i].CoreActivated == waitFirstSync)
                j++;
        }
    }
    return j;
}



void SysStartCore(CoreIdType CoreID, StatusType *Status)
{
    *Status = E_OK;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
    if (CoreID > TotalNumberOfCores)
    {
        *Status = E_OS_ID;
        return;
    }
    /* SWS_Os_00678 SWS_Os_00606 */ 
    else if (systemFlag & AFTER_STARTOS)
    {
        *Status = E_OS_ACCESS;
        return;
    }
    /* SWS_Os_00679, SWS_Os_00680 */
    else if (CoreStatus[CoreID].CoreActivated != nonActivatedCore)
    {
        *Status = E_OS_STATE;
        return;
    }
#endif
    _StartCore(CoreID);
    CoreStatus[CoreID].CoreActivated = beforeStartOS; /* SWS_Os_00677 */
    NumberOfActivatedCore += 1;
    return;
    /* SWS_Os_00681 */
}
void SysStartOS(AppModeType Mode)
{
    int core_idx = 0;
#if (ALARMS_AUTOSTART_COUNT > 0)
    AutoStartAlarmType *AutoStartAlarm = NULL;
#endif
#if (SCHEDULETABLE_AUTOSTART_COUNT_CORE0 > 0)
    AutoStartScheduleTableType *AutoStartScheduleTable = NULL;
#endif

    _CoreID = CoreIdPhyToLogArray[GetPhyCoreID()];
    
    //since we initialze all the memory in boot-time
    //systemFlag should be zero now, 
    //if not, there might be something wrong in memory-initialization
    if ( systemFlag )  
    {
        PrintText("Error call with systemFlag in StartOS!\r\n");
        //return;
    }

    // Mask EI interrupt
    __DI();

    //BoardInit();
    SetOSMemProt();
    CrossCoreISRInit();
    InitSchedulerIRQ(); // Scheduler bound to core is set at preBoardInit
    ISRInit();  //User's ISR1 and ISR2 wrapper
    InitReadyList();

    activeApplicationMode = Mode;
    AppModeArray[_CoreID] = Mode;

    CoreStatus[_CoreID].CoreActivated = waitFirstSync;
    
// First Sychrinzation
    while (!StartOsSyncFlag)
    {	
        if (_CoreID == OS_CORE_ID_MASTER)
        {
            while (CheckCoreSync() - CheckCoreSync());
            if (Mode == 0) /* Mode==0 means DONOTCARE*/
            {
                for (core_idx = 0; core_idx < TotalNumberOfCores; ++core_idx)
                {
                    /* AppModeArray[core_idx] != 0 means not DONOTCARE*/
                    if (CoreStatus[core_idx].CoreActivated == waitFirstSync && AppModeArray[core_idx] != 0)
                    {   
                        Mode = AppModeArray[core_idx];
                        break;
                    }
                    while (1);
                }
            }

            for (core_idx = 0; core_idx < TotalNumberOfCores; ++core_idx)
            {
                if (CoreStatus[core_idx].CoreActivated == waitFirstSync)
                {
                    if (AppModeArray[core_idx] == DONOTCARE)
                        AppModeArray[core_idx] = Mode;
                    else if (AppModeArray[core_idx] != Mode)
                        while (1);
                }
            }
            StartOsSyncFlag = 1;
        }
    }


    /* Now the current task is an idle task. 
    The code in the main function does not belong to the idle task, 
    so set needSaveContext to NOSAVE ensure that idle task run correct */
    CURRENTTASK.needSaveContext = NOSAVE; 
#if(HOOK_ENABLE_STARTUPHOOK == ENABLE)
    StartupHook();
#endif

/* Application startuphook */
    uint16 appCount =0;
#if (HOOK_ENABLE_STARTUPHOOK == ENABLE)
    appCount = SystemAppsInCore[_CoreID].AppsCount;
#endif
    for(uint16 i=0; i< appCount + 1; i++)
    {
        if(i==appCount)
        {
            SysTaskInformationType info;
            info.SysTaskAction = BOTSTARTOS;
            info.ApplID = INVALID_OSAPPLICATION; // use INVALID_OSAPPLICATION to indicate that must run at kernel mode
            info.para = Mode;
            EnSysTaskActionQueue(info);
            
        }
        else
        {
            uint16 app_id = SystemAppsInCore[_CoreID].AppsRef[i];
            if(ApplicationVar[app_id].AppHookFuncArray.StartupHookFunc != NULL)
            {
                SysTaskInformationType info;
                info.SysTaskAction = STARTUPHOOK;
                info.ApplID = app_id;
                info.FunctionPointer = (void (*)(StatusType))ApplicationVar[app_id].AppHookFuncArray.StartupHookFunc;
                EnSysTaskActionQueue(info);
            }
        }
        ActivateTaskInternal(SysTaskID[_CoreID]); 
    }
    ScheduleKernel();
    return;
}

void SysStartOSBot(AppModeType Mode){
    uint16 core_idx = 0;

    CoreStatus[_CoreID].CoreActivated = waitSecondSync;
    while (StartOsSyncFlag)
    {
        if (_CoreID == OS_CORE_ID_MASTER)
        {   
            //until all the core have left waitFirstSync (i.e., enter waitSecondSync)
            for (core_idx = 0; core_idx < TotalNumberOfCores; )
            {
                if (CoreStatus[core_idx].CoreActivated != waitFirstSync)
                {
                    core_idx++;
                }
            }
            StartOsSyncFlag = 0;
        }
    }
    
    //since we have finish all the app-start-up-hook;
    //we can now set "needSaveContext" back to NOSAVE
    CURRENTTASK.needSaveContext = NOSAVE; 

    // the "Mode-1" is needed to match the index in AutoStart setting in task_Cfg.c
    Mode = AppModeArray[_CoreID];
    uint32 appID=0;
    for (uint16 i = 0; i < AutoStart[Mode-1].TotalTasks; i++)
    {   
        //the task is in this core (_CoreID)
        if (((AutoStart[Mode-1].TasksRef[i]) >> 16) == _CoreID)
        {
            appID = SystemObjectAutosar[_CoreID]->TaskAutosar[AutoStart[Mode-1].TasksRef[i] & 0xFFFF].owner;
            if(ApplicationVar[appID].State == APPLICATION_ACCESSIBLE)
                ActivateTaskInternal(AutoStart[Mode-1].TasksRef[i]);
        }
    }

#if (ALARMS_AUTOSTART_COUNT > 0)
    AutoStartAlarm = SystemObjects[_CoreID]->AutoStartAlarm;
    for (uint32 i = 0; i < SystemObjects[_CoreID]->alarmsAutoStartConunt; i++)
    {
        //TODO: also allow SetAbsAlarm
        if (AutoStartAlarm[i].Mode == Mode)
        {
            appID = SystemObjectAutosar[_CoreID]->AlarmAutosar[AutoStartAlarm[i].Alarm & 0xFFFF].owner;
            if(ApplicationVar[appID].State == APPLICATION_ACCESSIBLE)
                SysSetRelAlarm(AutoStartAlarm[i].Alarm, AutoStartAlarm[i].AlarmTime, AutoStartAlarm[i].AlarmCycleTime);
        }
    }
#endif

/* SWS_Os_00510 */
/* The Operating System module shall perform the autostart of
ScheduleTables during startup after the autostart of Tasks and Alarms. */
#if (SCHEDULETABLE_AUTOSTART_COUNT > 0)
    AutoStartScheduleTable = SystemObjects[_CoreID]->AutoStartScheduleTable;
    for (uint32 i = 0; i < SystemObjects[_CoreID]->ScheduleTableAutoStartConunt; i++)
    {
        if (AutoStartScheduleTable[i].mode== Mode)
        {
            appID = SystemObjectAutosar[_CoreID].ScheduleTableAutosar[AutoStartScheduleTable[i].scheduleTable & 0xFFFF].owner;
            if(ApplicationVar[appID].State == APPLICATION_ACCESSIBLE)
            {
                if(AutoStartScheduleTable[i].autoStartType == ABSOLUTE){
                    SysStartScheduleTableAbs(AutoStartScheduleTable[i].scheduleTable,AutoStartScheduleTable[i].startValue);
                }else if(AutoStartScheduleTable[i].autoStartType == RELATIVE){
                    SysStartScheduleTableRel(AutoStartScheduleTable[i].scheduleTable,AutoStartScheduleTable[i].startValue);
                }else{
                    SysStartScheduleTableSynchron(AutoStartScheduleTable[i].scheduleTable);
                }   
            }
        
        }
    }
#endif
    /* finish all start os processes */ 
    systemFlag |= AFTER_STARTOS;
}


void SysShutdownOS (StatusType Error)
{
    ApplicationType app_id;

    uint16 appCount = 0;

    /* SWS_Os_00716 */
    /* SWS_Os_00054 */
    /* Should not call by non trusted code */
    app_id = SystemObjectAutosar[_CoreID]->TaskAutosar[CurrentTask[_CoreID]->currentID].owner;
    if(ApplicationVar[app_id].OsTrusted==FALSE){
        return;
    }
    
    if(systemFlag & SERVICE_LIMIT_CAT7)
    {
        /* nothing to do, ShutdownOS only can be called in
           general task, isr2 task, ErrorHook and StartupHook */
        return;
    }

    /* Terminate all application on this core */
    appCount = SystemAppsInCore[_CoreID].AppsCount;
    for(uint16 i = 0; i < appCount; i++)
    {
        uint16 applID = SystemAppsInCore[_CoreID].AppsRef[i];
        if(ApplicationVar[applID].State!= APPLICATION_TERMINATED)
        {
            TerminateAppInternal(applID);
        }
    }

#if (HOOK_ENABLE_OSAPP_SHUTDOWNHOOK == ENABLE)
    appCount = SystemAppsInCore[_CoreID].AppsCount;
#else
    appCount = 0;
#endif
    for(uint16 i=0; i< appCount + 1; i++)
    {
        if(i==appCount)
        {
            SysTaskInformationType info;
            info.SysTaskAction = BOTSHUTDOWNOS;
            info.ApplID = INVALID_OSAPPLICATION; // use INVALID_OSAPPLICATION to indicate that must run at kernel mode
            info.para = Error;
            EnSysTaskActionQueue(info);
            
        }
        else
        {
            uint16 app_id = SystemAppsInCore[_CoreID].AppsRef[i];
            if(ApplicationVar[app_id].AppHookFuncArray.ShutdownHookFunc != NULL)
            {
                SysTaskInformationType info;
                info.SysTaskAction = SHUTDOWNHOOK;
                info.ApplID = app_id;
                info.FunctionPointer = ApplicationVar[app_id].AppHookFuncArray.ShutdownHookFunc;
                EnSysTaskActionQueue(info);
            }
        }
        ActivateTaskInternal(SysTaskID[_CoreID]); 
    }
    ScheduleKernel();
    return;

}

void SysShutdownOSBot (StatusType Error)
{
#if (HOOK_ENABLE_SHUTDOWNHOOK == ENABLE)
    systemFlag |= IN_SHUTDOWN_HOOK;
    ShutdownHook(Error);
    systemFlag &= ~IN_SHUTDOWN_HOOK;
#endif
    //ToDo: reset indivial core
    /* SWS_Os_00425 */
    /* disable all interrupts and enter an endless loop */
    CoreStatus[_CoreID].CoreActivated = shutdown;
    while(1);
    // SWReset();
}

CoreIdType SysGetCoreID(void)
{
    CoreIdType CoreID;
	CoreID = CoreIdPhyToLogArray[GetPhyCoreID()];

    /* SWS_Os_00675 */
    return CoreID;
}

uint32 SysGetNumberOfActivatedCores(void)
{
    uint32 result=0;
    /* Check the OS state, system service may be limited in some states */
    if (result == E_OK && systemFlag & SERVICE_LIMIT_CAT2)
    {
    }
    else
    {
        result = (uint32)(NumberOfActivatedCore);
    }
    

    return result; /* SWS_Os_00673 */
}

AppModeType SysGetActiveApplicationMode (void)
{
    AppModeType result;

    if(systemFlag & (SERVICE_LIMIT_CAT4|IN_PROTECTION_HOOK))
    {
        /* Error call with GetActiveApplicationMode,
           GetActiveApplicationMode can be called in general 
           task, isr2 task, ErrorHook, StartupHook, ShutdownHook,
           PreTaskHook and PostTaskHook */
        PrintText("Error call with GetActiveApplicationMode!\r\n");
    }
    result = activeApplicationMode;

    return result;
}

void SysShutdownAllCores(StatusType Error)
{
    uint16 core_count=0;
    uint16 app_id;
    uint16 appCount = 0;

    /* SWS_Os_00716 */
    /* Should not call by non trusted code */
    app_id = SystemObjectAutosar[_CoreID]->TaskAutosar[CurrentTask[_CoreID]->currentID].owner;
    if(ApplicationVar[app_id].OsTrusted==FALSE){
        return;
    }

    // Set the shutdown master
    for (uint16 core_idx = 0; core_idx < TotalNumberOfCores; core_idx++ )
    {
        if(CoreStatus[core_idx].CoreActivated==shutdownMaster)
        {
            break;
        }
        else
        {
            core_count++;
        }
    }
    if(core_count==TotalNumberOfCores)
    {
        CoreStatus[_CoreID].CoreActivated = shutdownMaster;
    }

    enableCrossCoreISR();
    if(CoreStatus[_CoreID].CoreActivated==shutdownMaster)
    {
        for(uint16 core_idx=0;core_idx<TotalNumberOfCores;core_idx++)
        {
            if(CoreStatus[core_idx].CoreActivated==waitSecondSync)
            {
                GetLock(&CoreParaLock[core_idx], LOCKBIT);
                CrossCoreServicePara[core_idx].serviceID = SERVICE_SHUTDOWNALLCORES;
                CrossCoreServicePara[core_idx].para1 = Error;
                InterruptToCore(core_idx);
                ReleaseLock(&CoreParaLock[core_idx], LOCKBIT);
            }
        }
    }
    disableCrossCoreISR();

    /* Terminate all application on this core */
    appCount = SystemAppsInCore[_CoreID].AppsCount;
    for(uint16 i = 0; i < appCount; i++)
    {
        uint16 applID = SystemAppsInCore[_CoreID].AppsRef[i];
        if(ApplicationVar[applID].State!= APPLICATION_TERMINATED)
        {
            TerminateAppInternal(applID);
        }
    }

/* SWS_Os_00586 */
/* OS application Shutdown Hooks */
#if (HOOK_ENABLE_OSAPP_SHUTDOWNHOOK == ENABLE)
    appCount = SystemAppsInCore[_CoreID].AppsCount;
#else
    appCount = 0;
#endif
    for(uint16 i=0; i< appCount + 1; i++)
    {
        if(i==appCount)
        {
            SysTaskInformationType info;
            info.SysTaskAction = BOTSHUTDOWNALLCORES;
            info.ApplID = INVALID_OSAPPLICATION; // use INVALID_OSAPPLICATION to indicate that must run at kernel mode
            info.para = Error;
            EnSysTaskActionQueue(info);
            
        }
        else
        {
            uint16 app_id = SystemAppsInCore[_CoreID].AppsRef[i];
            if(ApplicationVar[app_id].AppHookFuncArray.ShutdownHookFunc != NULL)
            {
                SysTaskInformationType info;
                info.SysTaskAction = SHUTDOWNHOOK;
                info.ApplID = app_id;
                info.FunctionPointer = ApplicationVar[app_id].AppHookFuncArray.ShutdownHookFunc;
                EnSysTaskActionQueue(info);
            }
        }
        ActivateTaskInternal(SysTaskID[_CoreID]); 
    }
    ScheduleKernel();
    return;
}


void SysShutdownAllCoresBot(StatusType Error)
{
    ShutdownSyncFlag = 1 ;
    if(CoreStatus[_CoreID].CoreActivated==shutdownMaster)
    {
        CoreStatus[_CoreID].CoreActivated = waitSyncforshutdown;
        /* SWS_Os_00587 */
        /* Shutdown sychronization */
        for (uint16 core_idx = 0; core_idx < TotalNumberOfCores; )
        {
            if (CoreStatus[core_idx].CoreActivated != waitSecondSync)
            {
                core_idx++;
            }
        }
        ShutdownSyncFlag = 0;
    }

    CoreStatus[_CoreID].CoreActivated = waitSyncforshutdown;
    
    /* SWS_Os_00587 */
    /* Shutdown sychronization */
    while (ShutdownSyncFlag);


    /* SWS_Os_00588 */
    /* Global ShutdownHook */
#if (HOOK_ENABLE_SHUTDOWNHOOK == ENABLE)
    systemFlag |= IN_SHUTDOWN_HOOK;
    ShutdownHook(Error);
    systemFlag &= ~IN_SHUTDOWN_HOOK;
#endif

    while(1);      //endless loop

}


void SysStartNonAutosarCore(CoreIdType CoreID,StatusType* Status)
{
    *Status = E_OK;

    /* Check the OS state, system service may be limited in some states */
    if (systemFlag & SERVICE_LIMIT_CAT1)
    {
        *Status  = E_OS_CALLEVEL;
    }
    /* SWS_Os_00685 */
    if (CoreID > TotalNumberOfCores)
    {
        *Status = E_OS_ID;
        return;
    }
    /* SWS_Os_00683 */ 
    else if (systemFlag & AFTER_STARTOS)
    {
        *Status = E_OS_ACCESS;
        return;
    }
    /* SWS_Os_00684 */
    else if (CoreStatus[CoreID].CoreActivated != nonActivatedCore)
    {
        *Status = E_OS_STATE;
        return;
    }

    _StartCore(CoreID);
    CoreStatus[CoreID].CoreActivated = nonAutosarCore; /* SWS_Os_00677 */
    return;
}

void SysDisableAllInterrupts(void)
{
    HardwareTickType Budget;


    if( systemFlag & IN_ISR1_HANDLER)
    {
        ;/* nothing to do, since our implemetation NOT allow nested interrupt,
            when in the body of ISR1, other interrupt are diabled by hardware */
    }
    else
    {

        if(serviceDisableAllInterruptsCounter == 0)
        {
            // disableallinterrupts cant be nested
            kernelDisableAllISR();
            systemFlag |= SERVICE_DISABLE_ALL_INT;
            CURRENTTASK.CurrentVar->INTServiceRecord.DisableAll_Record++;
            Budget = getBound(CURRENTTASK.currentID, INTLOCKBUDGET, 0);
            addTimingCounter(&SystemTimingCounter[_CoreID].InterruptTimingCounter[0], INTLOCKBUDGET, Budget);
            serviceDisableAllInterruptsCounter++;
        }
        

    }

}

void SysEnableAllInterrupts(void)
{
    if( systemFlag & IN_ISR1_HANDLER)
    {
        ;/* nothing to do, since our implemetation NOT allow nested interrupt,
            when in the body of ISR1, other interrupt are diabled by hardware */
    }
    else
    {
        serviceDisableAllInterruptsCounter--;
        if (serviceDisableAllInterruptsCounter < 0){           
            kernelSystemCallCounter = 0;            
        }
        else if (serviceDisableAllInterruptsCounter == 0){     
            resetTimingCounter(&SystemTimingCounter[_CoreID].InterruptTimingCounter[0]);
            CURRENTTASK.CurrentVar->INTServiceRecord.DisableAll_Record--;
            systemFlag &= ~SERVICE_DISABLE_ALL_INT;
            kernelEnableAllISR();
        }
        else{   /* (serviceDisableAllInterruptsCounter > 0) */
            ; /* do noth, keep in DisableAllInterrupts */
        }
    }
}

void SysSuspendAllInterrupts(void)
{
    HardwareTickType Budget;

    if( systemFlag & IN_ISR1_HANDLER)
    {
        ;/* nothing to do, since our implemetation NOT allow nested interrupt,
            when in the body of ISR1, other interrupt are diabled by hardware */
    }
    else
    {
        if(serviceSuspendAllInterruptsCounter == 0)
        {
            kernelDisableAllISR();
            systemFlag |= SERVICE_SUSPEND_ALL_INT;
            CURRENTTASK.CurrentVar->INTServiceRecord.SuspendAll_Record++;
            Budget = getBound(CURRENTTASK.currentID, INTLOCKBUDGET, 0);
            addTimingCounter(&SystemTimingCounter[_CoreID].InterruptTimingCounter[1], INTLOCKBUDGET, Budget);
        }
        serviceSuspendAllInterruptsCounter++;
    }

}
void SysResumeAllInterrupts(void)
{
    if( systemFlag & IN_ISR1_HANDLER)
    {
        ;/* nothing to do, since our implemetation NOT allow nested interrupt,
            when in the body of ISR1, other interrupt are diabled by hardware */
    }
    else
    {
        serviceSuspendAllInterruptsCounter--;
        if (serviceSuspendAllInterruptsCounter < 0){           
            serviceSuspendAllInterruptsCounter = 0;            
        }
        else if(serviceSuspendAllInterruptsCounter == 0){
            resetTimingCounter(&SystemTimingCounter[_CoreID].InterruptTimingCounter[1]);
            CURRENTTASK.CurrentVar->INTServiceRecord.SuspendAll_Record--;
            systemFlag &= ~SERVICE_SUSPEND_ALL_INT;
            kernelEnableAllISR();
        }
        else{   /* (serviceSuspendAllInterruptsCounter > 0) */
            ; /* do noth, keep in SuspendAllInterrupts */
        }
    }
}
void SysSuspendOSInterrupts(void)
{
    HardwareTickType Budget;
    if( systemFlag & IN_ISR1_HANDLER)
    {
        ;/* nothing to do, since our implemetation NOT allow nested interrupt,
            when in the body of ISR1, other interrupt are diabled by hardware */
    }
    else
    {
        if(serviceSuspendOSInterruptsCounter == 0)
        {
            /* disable scheduler */
            kernelDisableISR2();
            disableSchedulerIRQ();
            disableCrossCoreISR();
            systemFlag |= SERVICE_SUSPEND_OS_INT;
            CURRENTTASK.CurrentVar->INTServiceRecord.SuspendOS_Record++;
            Budget = getBound(CURRENTTASK.currentID, INTLOCKBUDGET, 1);
            addTimingCounter(&SystemTimingCounter[_CoreID].InterruptTimingCounter[2], INTLOCKBUDGET, Budget);
        }
        serviceSuspendOSInterruptsCounter++;
    }
}

void SysResumeOSInterrupts(void)
{
    if( systemFlag & IN_ISR1_HANDLER)
    {
        ;/* nothing to do, since our implemetation NOT allow nested interrupt,
            when in the body of ISR1, other interrupt are diabled by hardware */
    }
    else
    {
        serviceSuspendOSInterruptsCounter--;
        if (serviceSuspendOSInterruptsCounter < 0){           
            serviceSuspendOSInterruptsCounter = 0;            
        }
        else if(serviceSuspendOSInterruptsCounter == 0){
            resetTimingCounter(&SystemTimingCounter[_CoreID].InterruptTimingCounter[2]);
            CURRENTTASK.CurrentVar->INTServiceRecord.SuspendOS_Record--;
            systemFlag &= ~SERVICE_SUSPEND_OS_INT;
            kernelEnableISR2();
            enableCrossCoreISR();
            enableSchedulerIRQ();
        }
        else{   /* (serviceSuspendOSInterruptsCounter > 0) */
            ; /* do noth, keep in SuspendOSInterrupts */
        }
    }
}





#pragma interrupt ServiceCrossCore(enable = manual, channel = 0, callt = false, fpu = false)
void ServiceCrossCore(void)
{
    ApplicationType oldApp;
    /* ServiceCrossCore is an interrupt handler */
    /* so it's already in kernel mode */
    /* we might need to set "enable = false" */
    DisableMPU();

    systemFlag |= (IN_SERVICE_CORSSCORE);
    oldApp = ExecutingApp[_CoreID];
    ExecutingApp[_CoreID] = CrossCoreServicePara[_CoreID].App;

    switch (CrossCoreServicePara[_CoreID].serviceID)
    {
    case SERVICE_CALLBACKFUNCTION:
        CrossCoreServicePara[_CoreID].result = SetCallbackfunctionAction(CrossCoreServicePara[_CoreID].para1, CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_ACTIVATETASK:
        CrossCoreServicePara[_CoreID].result = SysActivateTask((TaskType)CrossCoreServicePara[_CoreID].para1);
        break;
    case SERVICE_GETTASKSTATE:
        CrossCoreServicePara[_CoreID].result = SysGetTaskState( (TaskType)CrossCoreServicePara[_CoreID].para1, (TaskStateRefType)CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_SETEVENT:
        CrossCoreServicePara[_CoreID].result = SysSetEvent( (TaskType)CrossCoreServicePara[_CoreID].para1, (EventMaskType)CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_GETEVENT:
        CrossCoreServicePara[_CoreID].result = SysGetEvent( (TaskType)CrossCoreServicePara[_CoreID].para1, (EventMaskRefType)CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_GETALARMBASE:
        CrossCoreServicePara[_CoreID].result = SysGetAlarmBase((AlarmType )CrossCoreServicePara[_CoreID].para1, (AlarmBaseRefType )CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_GETALARM:
        CrossCoreServicePara[_CoreID].result = SysGetAlarm((AlarmType)CrossCoreServicePara[_CoreID].para1, (TickRefType)CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_SETRELALARM:
        CrossCoreServicePara[_CoreID].result = SysSetRelAlarm((AlarmType)CrossCoreServicePara[_CoreID].para1, (TickType)CrossCoreServicePara[_CoreID].para2, (TickType)CrossCoreServicePara[_CoreID].para3);
        break;
    case SERVICE_SETABSALARM:
        CrossCoreServicePara[_CoreID].result = SysSetAbsAlarm((AlarmType)CrossCoreServicePara[_CoreID].para1, (TickType)CrossCoreServicePara[_CoreID].para2, (TickType)CrossCoreServicePara[_CoreID].para3);
        break;
    case SERVICE_CANCELALARM:
        CrossCoreServicePara[_CoreID].result = SysCancelAlarm((AlarmType)CrossCoreServicePara[_CoreID].para1);
        break;
    case SERVICE_STARTSCHEDULETABLEREL:
        CrossCoreServicePara[_CoreID].result = SysStartScheduleTableRel((ScheduleTableType)CrossCoreServicePara[_CoreID].para1, (TickType)CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_STARTSCHEDULETABLEABS:
        CrossCoreServicePara[_CoreID].result = SysStartScheduleTableAbs((ScheduleTableType)CrossCoreServicePara[_CoreID].para1, (TickType)CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_STOPSCHEDULETABLE:
        CrossCoreServicePara[_CoreID].result = SysStopScheduleTable((ScheduleTableType)CrossCoreServicePara[_CoreID].para1);
        break;
    case SERVICE_GETSCHEDULETABLESTATUS:
        CrossCoreServicePara[_CoreID].result = SysGetScheduleTableStatus((ScheduleTableType)CrossCoreServicePara[_CoreID].para1,(ScheduleTableStatusRefType)CrossCoreServicePara[_CoreID].para2);
        break;                            
    case SERVICE_ACTIVATETASKASYN:
        SysActivateTaskAsyn(CrossCoreServicePara[_CoreID].para1);
        break;
    case SERVICE_SETEVENTASYN:
        SysSetEventAsyn((TaskType)CrossCoreServicePara[_CoreID].para1, (EventMaskType)CrossCoreServicePara[_CoreID].para2);
        break;    
    case SERVICE_GETAPPLICATIONSTATE:
        CrossCoreServicePara[_CoreID].result = SysGetApplicationState((ApplicationType)CrossCoreServicePara[_CoreID].para1, (ApplicationStateRefType)CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_TERMINATEAPPLICATION:
        CrossCoreServicePara[_CoreID].result = SysTerminateApplication((ApplicationType)CrossCoreServicePara[_CoreID].para1, (RestartType)CrossCoreServicePara[_CoreID].para2);
        break;
    case SERVICE_SHUTDOWNALLCORES:
        SysShutdownAllCores((StatusType)CrossCoreServicePara[_CoreID].para1);
    default:
        ;
    }

    ExecutingApp[_CoreID] = oldApp;
	CoreIntFlag[_CoreID]  = 0;
    systemFlag &= ~(IN_SERVICE_CORSSCORE);

    EnableMPU();
    return;
}

