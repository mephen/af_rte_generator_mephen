#include "../Os_Configure/inc/task_Cfg.h"
#include "../Os_Configure/inc/event_Cfg.h"
#include "../Os_Configure/inc/alarm_Cfg.h"
#include "../device/lock.h"
#include "../kernel/os.h"
#include "../kernel/alarm.h"
#include "../kernel/task.h"

#include "Rte_Type.h"
#include "Rte_Main.h"
#include "Bsw_Event_Cfg.h"
#include "Rte_Event_Cfg.h"
#include "Share_Function.h"
//#include "App2Swc_ModeUser.h"

const SchM_ConfigType SchM_ConfigSet1 = {
    .schedulerId = 1,
};
SchM_ConfigType scheduler;
Rte_InitState = RTE_STATE_UNINIT;

void SchM_Start(void) {
    Rte_InitState = RTE_STATE_SCHM_START;
}

//info. of Bsw initialMode
/*
ModeEventInfo mode_manager_initialMode_disable_mode = {
    .event_ptr = {&bsw_event_t15[BswModeSwitchEvent_EV_10_T15], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 1
};
ModeEventInfo mode_manager_initialMode_on_entry = {
    .event_ptr = {NULL},
    .func_ptr = {SCHM_BE_Mode0_Entry, NULL},
    .task = { NULL},
    .num = 0
};
*/

void SchM_Init(const SchM_ConfigType* ConfigPtr) {
    TaskStateType get_task_state;
    if (ConfigPtr != NULL) {
        scheduler.schedulerId = ConfigPtr->schedulerId;
    }

    /*
    // Disable events for initial mode
    set_disable_mode(&mode_manager_initialMode_disable_mode);
    //Execute the on-entry Entitys of all initial modes
    set_event(&mode_manager_initialMode_on_entry);
    activate_task(&mode_manager_initialMode_on_entry);
    */

    GetTaskState(T16, &get_task_state);
    if (get_task_state == SUSPENDED) {
        ActivateTask(T16); //ActivateTask low priority task(background task)
    }
    Rte_InitState = RTE_STATE_SCHM_INIT;
}

void SchM_StartTiming(void) {
    SetRelAlarm(Countalarm1,9999,10000); //activate core0 RTE Task periodically. First activation is at (GCD-1)ms to assure RTE Task runs before timing events
    SetRelAlarm(Countalarm3,9999,10000); //activate core1 RTE Task periodically
    //SetRelAlarm(alarm3,20000,20000); //activate the OS task containing the TimingEvent periodically.
    //SetRelAlarm(alarm1,30000,30000);
}

void SchM_Deinit(void) {
    //CancelAlarm(alarm3);
    //CancelAlarm(alarm1);

    dinit_flag = 1;
    Rte_InitState = RTE_STATE_UNINIT;
}

void SchM_GetVersionInfo(Std_VersionInfoType *versioninfo) {
    versioninfo->vendorID = RTE_VENDOR_ID;
    versioninfo->moduleID = RTE_MODULE_ID;
    versioninfo->sw_patch_version = RTE_SW_PATCH_VERSION;
}

//info. of RTE initialMode
ModeEventInfo RTE_initialMode_disable_mode = {
    .event_ptr = {&rte_event_t04[RteModeSwitchEvent_2_t04], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 1
};
ModeEventInfo RTE_initialMode_on_entry_runnables = {
    .event_ptr = {NULL},
    .func_ptr = {Runnable_modeSwitch_1, NULL},
    .task = { NULL},
    .num = 0
};

//[Rte_06766]:
//About Rte_Start(). If specific modeSwitchEvents(on-entry & init mode) aren't mapped to init containers, Rte_Start() shall trigger those specific modeSwitchEvents
//Similarly, if initEvents aren't mapped to init containers, Rte_Start shall trigger those initEvents
ModeEventInfo RTE_event_triggered_by_RteStart = {
    .event_ptr = {&rte_event_t03[RteInitEvent_1_t03], &rte_event_t03[RteInitEvent_2_t03], &rte_event_t04[RteModeSwitchEvent_1_t04], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 3
};

//[Rte_06767, Rte_06751]:
//Rte_Init(): trigger events contained in init containers
//[Rte_CONSTR_09063] init Containers: contain initEvents & specific modeSwitchEvents(on-entry & init mode)
Std_ReturnType Rte_Start(void){
    Std_ReturnType ret = RTE_E_OK;
    TaskStateType get_task_state;

    //Disable part of events of initial mode (which can't be triggerd in initial mode)
    set_disable_mode(&RTE_initialMode_disable_mode);
    
    //Execute the on-entry Entitys of all initial modes, and activate the task where these on-entry Entitys are mapped
    set_event(&RTE_initialMode_on_entry_runnables);
    activate_task(&RTE_initialMode_on_entry_runnables);

    //Rte_06766
    //if initEvents or specific modeSwitchEvents(on-entry & init mode) aren't mapped to init containers, Rte_Start shall trigger those specific events
    set_event(&RTE_event_triggered_by_RteStart);

    /*If the Rte_StartTiming() does not exist, Rte_Start() shall handle RTE BackgroundEvents & RTE TimingEvents*/
    //handle RTE BackgroundEvents
    GetTaskState(T16, &get_task_state);
    if (get_task_state == SUSPENDED) {
        ActivateTask(T16); //ActivateTask low priority task(background task)
    }

    //handle RTE TimingEvents
    //don't need to set alarms to activate RTE Task and backgroud Task periodically, because their alarms are already set in SchM_StartTiming()
    //if case4 happens, activate the OS task containing the TimingEvent periodically. (case4:In eventToTaskMapping, eventRef, taskRef, and alarmRef are all set)
    ret = SetRelAlarm(alarm4, 20000, 20000); //activate the OS task containing the TimingEvent periodically.

    Rte_InitState = RTE_STATE_START;

    if(ret != RTE_E_OK){
        return RTE_E_LIMIT;
    }
    return ret;
}

//if any RteInitializationRunnableBatch container is configured, create its corresponding Rte_Init_<container> function

//if any Rte_init() exit, create Rte_StartTiming()

//cancel timing_ev related alarms
Std_ReturnType Rte_Stop(void){
    CancelAlarm(alarm4);

    dinit_flag = 1;
    Rte_InitState = RTE_STATE_STOP;
}

/* EcuM for test */
void EcuM_StartupTwo(void) {
    SchM_Start();
    SchM_Init(&SchM_ConfigSet1);
    SchM_StartTiming();
    Rte_Start();
    //if the RteInitializationRunnableBatch container is configured
}

/* EcuM for test */
void EcuM_GoDown(void) {
    Rte_Stop();
    SchM_Deinit();
}