#include "iodefine.h"
#include "board.h"
#include "os.h"
#include "timer.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "counter.h"
#include "alarm.h"
#include "task.h"
#include "isr2.h"
#include "event.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "string_format_test.h"
#include "systemcall.h"
#include "application.h"
#include "ISRInit.h"
#include "isr_Cfg.h"
#include "spinlock.h"
#include "resource.h"
#include "memsection.h"
#include "trustedFunc_Cfg.h"

#include "SchM.h"
#include "Swc.h"
#include "Share_Function.h"
#include "Rte_Main.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* OSAPP_A01 *****************/
#pragma section OSAPP_A03_SEC
uint16 App_A03_test_data_1 = 1;
#pragma section OSAPP_A01_SEC

int app1_test_data = 2;
uint16 App_test_data_2 = 2;

/* Brief StartupHook */
void StartupHook_OSAPP_app_lion(void)
{
    // Memory fault test
    // App_A03_test_data_1 = 0x1234;

    // PrintText("APP lion: \r\n");
    PrintText("    I'm in app lion StartupHook\r\n");
    // PrintText("    Start up success!\r\n");
}

/* Brief ShutdownHook */
void ShutdownHook_OSAPP_app_lion(StatusType Error)
{
    // Memory fault test
    // App_A03_test_data_1 = 0x1234;

    // PrintText("APP lion: \r\n");
    PrintText("    I'm in app lion ShutdownHook\r\n");
    // PrintText("    Bye!\r\n");
}

/* Brief ErrorHook */
void ErrorHook_OSAPP_app_lion(StatusType Error)
{

    PrintText("App lion Error Hook:\r\n");
    switch (Error)
    {
    case E_OS_ACCESS:
        PrintText("[ErrorHook]: E_OS_ACCESS\r\n");
        break;
    case E_OS_CALLEVEL:
        PrintText("[ErrorHook]: E_OS_CALLEVEL\r\n");
        break;
    case E_OS_ID:
        PrintText("[ErrorHook]: E_OS_ID\r\n");
        break;
    case E_OS_LIMIT:
        PrintText("[ErrorHook]: E_OS_LIMIT\r\n");
        break;
    case E_OS_NOFUNC:
        PrintText("[ErrorHook]: E_OS_NOFUNC\r\n");
        break;
    case E_OS_RESOURCE:
        PrintText("[ErrorHook]: E_OS_RESOURCE\r\n");
        break;
    case E_OS_STATE:
        PrintText("[ErrorHook]: E_OS_STATE\r\n");
        break;
    case E_OS_VALUE:
        PrintText("[ErrorHook]: E_OS_VALUE\r\n");
        break;
    case E_OS_SYS_NOFUNC:
        PrintText("[ErrorHook]: E_OS_SYS_NOFUNC\r\n");
        break;
    case E_OS_SERVICEID:
        PrintText("[ErrorHook]: E_OS_SERVICEID\r\n");
        break;
    case E_OS_INTERFERENCE_DEADLOCK:
        PrintText("[ErrorHook]: E_OS_INTERFERENCE_DEADLOCK\r\n");
        break;
    case E_OS_SYS_OK_CROSSCORE:
        PrintText("[ErrorHook]: E_OS_SYS_OK_CROSSCORE\r\n");
        break;
    case E_OS_SPINLOCK:
        PrintText("[ErrorHook]: E_OS_SPINLOCK\r\n");
        break;
    case E_OS_DISABLEDINT:
        PrintText("[ErrorHook]: E_OS_DISABLEDINT\r\n");
        break;
    default:
        PrintText("[App lion ErrorHook]: \r\n");
        break;
    }
}

void TRUSTED_TF_AIMER( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF AIMER\r\n\0");
    uint32 temp = 0;
    uint32* tt = &temp;
    for(uint32 i=0; i<40000;i++){
        temp = temp + 1;
    }

    // CallTrustedFunction(TF_IKURA, &temp);
}
void TRUSTED_TF_IKURA( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF IKURA\r\n\0");
    uint32 temp = 0;
    uint32* tt = &temp;
    ActivateTask(T03);
    CallTrustedFunction(TF_YORUSHIKA, &temp);
}
void TRUSTED_TF_YORUSHIKA( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF YORUSHIKA\r\n\0");
}

#pragma section ISR_I001_SEC

ISR(I001)
{
    PrintText("isr1 001 in osapp 01\r\n\0");
}

#pragma section ISR_I002_SEC
uint32 temp_I002 = 10;
ISR(I002)
{
    PrintText("isr2 002 in osapp 01\r\n\0");
}

#pragma section ISR_I003_SEC
ISR(I003)
{
    PrintText("isr2 003 in osapp 01\r\n\0");
}

#pragma section ISR_I004_SEC
ISR(I004)
{
    PrintText("isr1 004 in osapp 01\r\n\0");
}
#pragma section OSAPP_A03_SEC
uint16 testforvil = 5;

#define mode 0
#define lifecycle 1
#define swc_mode 0

int init_flag = 0;
int mode_flag = 0;
int sender_receiver_flag = 0;
int client_server_flag = 0;

#pragma section TASK_T001_SEC
uint32 temp1 = 10;
//(highest priority)RTE Task for handling timing event.
TASK(T01)
{
    StatusType result = E_OK;
    AlarmBaseType alarmBase;
    uint32 temp = 0 ;
    PrintText("t1(RTE Task)\r\n\0");
    TaskStateType get_task_state;

//simulation of lifecycle in EcuM
#if lifecycle
    if (init_flag_0 == 0) {
        EcuM_StartupTwo(); //lifecycle test: disable events, execute on-entry Entitys, activate background task, set RTE state
        init_flag_0 = 1;
    } else {
        core0_period_counter();
    }
#endif

//----------------------------------------------------
/*these part just for test*/
//initialization of SchM init mode
#if mode
    // mode
    if (mode_flag == 0) {
        GetTaskState(T02, &get_task_state);
        if (get_task_state == SUSPENDED) {
            ActivateTask(T02);
        }
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_10_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_11_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_12_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_13_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_14_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_15_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->currentmode = RTE_MODE_Engine_MDGroup_INITMODE;
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t02[BswModeSwitchEvent_EV_Engine_ModeSwitch_T02]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        set_event_disablemode(bsw_event_t15[BswModeSwitchEvent_EV_10_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetTaskState(T15, &get_task_state);
        if (get_task_state == SUSPENDED) {
            ActivateTask(T15);
        }
    }
#endif
//initialization of RTE init mode
#if swc_mode
    //swc
    ActivateTask(T02);
    GetLock(&share_function_lock_q,share_function_lock_bit);
    trigger_event(rte_event_t15[SwcModeSwitchEvent_EV_0_T15]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    GetLock(&share_function_lock_q,share_function_lock_bit);
    trigger_event(rte_event_t15[SwcModeSwitchEvent_EV_1_T15]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    GetLock(&share_function_lock_q,share_function_lock_bit);
    trigger_event(rte_event_t15[SwcModeSwitchEvent_EV_2_T15]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    GetLock(&share_function_lock_q,share_function_lock_bit);
    trigger_event(rte_event_t15[SwcModeSwitchEvent_EV_3_T15]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    GetLock(&share_function_lock_q,share_function_lock_bit);
    mode_manager_status[AC_MDGROUP_STATUS]->currentmode = RTE_MODE_AC_MDGroup_INITMODE;
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    GetLock(&share_function_lock_q,share_function_lock_bit);
	trigger_event(rte_event_t02[SwcModeSwitchEvent_EV_AC_ModeSwitch_T02]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    GetLock(&share_function_lock_q,share_function_lock_bit);
	set_event_disablemode(rte_event_t15[SwcModeSwitchEvent_EV_0_T15]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    ActivateTask(T15);
#endif
//----------------------------------------------------
    GetTaskState(T16, &get_task_state);
    if (get_task_state == SUSPENDED) {
        ActivateTask(T16); //ActivateTask low priority task(background task)
    }
    TerminateTask();
}

// int count_0 = 0;
#pragma section TASK_T002_SEC
int T02_Global = 0;
TASK(T02)
{
    PrintText("t2\r\n\0");
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }

//----------------------------------------------------
/*these part just for test*/
#if mode
    /* for test start */
    if (mode_flag == 0) {
        WaitEvent(event1);
        ClearEvent(event1);
    }
    /* for test end */
#endif

#if swc_mode
    /* for test start */
    if (mode_flag == 0) {
        WaitEvent(event1);
        ClearEvent(event1);
    }
    /* for test end */
#endif
//----------------------------------------------------

    //bsw
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t02)/sizeof(bsw_event_t02[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t02[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t02[i]);
            uint16 ev_type = get_event_type(bsw_event_t02[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t02[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswTimingEvent:
                            bsw_event_t02[i]->Entity_FuncPtr();
                            break;
                        case BswModeSwitchEvent:
                            bsw_event_t02[i]->Entity_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                            }
                            break;
                        default:
                            bsw_event_t02[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t02[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t02[i]);
                ev_triggerred = get_event_counter(bsw_event_t02[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    //swc
    count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(rte_event_t02)/sizeof(rte_event_t02[0])) ; i++ ) {
            while (get_event_counter(rte_event_t02[i]) != 0) {
                if (get_event_disablemode(rte_event_t02[i]) == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(rte_event_t02[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(get_event_type(rte_event_t02[i])) {
                        case SwcModeSwitchEvent:
                            rte_event_t02[i]->Entity_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                                // PrintText("T02 SetEvent T02 event1\r\n\0");
                            }
                            break;
                        case ModeSwitchedAckEvent:
                            break;
                        default:
                            rte_event_t02[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(rte_event_t02[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(rte_event_t02[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    }

    /* for test start */
//bsw
#if mode
    // mode
    if (mode_flag == 0) {
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_10_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_11_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_12_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_13_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_14_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t15[BswModeSwitchEvent_EV_15_T15]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        GetTaskState(T15, &get_task_state);
        if (get_task_state == SUSPENDED) {
            ActivateTask(T15);
        }
        WaitEvent(event1);
        ClearEvent(event1);
        mode_flag = 1;
    }
#endif

#if swc_mode
    //swc
    // mode
    GetLock(&share_function_lock_q,share_function_lock_bit);
    trigger_event(rte_event_t15[SwcModeSwitchEvent_EV_0_T15]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    GetLock(&share_function_lock_q,share_function_lock_bit);
    trigger_event(rte_event_t15[SwcModeSwitchEvent_EV_1_T15]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    GetLock(&share_function_lock_q,share_function_lock_bit);
    trigger_event(rte_event_t15[SwcModeSwitchEvent_EV_2_T15]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    GetLock(&share_function_lock_q,share_function_lock_bit);
    trigger_event(rte_event_t15[SwcModeSwitchEvent_EV_3_T15]);
    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    ActivateTask(T15);
    WaitEvent(event1);
    ClearEvent(event1);
#endif
    /* for test end*/
    GetTaskState(T16, &get_task_state);
    if (get_task_state == SUSPENDED) {
        ActivateTask(T16); //ActivateTask low priority task(background task)
    }
    TerminateTask();
}

#pragma section TASK_T003_SEC
TASK(T03)
{
    PrintText("t3\r\n\0");
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }
    //bsw
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t03)/sizeof(bsw_event_t03[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t03[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t03[i]);
            uint16 ev_type = get_event_type(bsw_event_t03[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t03[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswModeSwitchedAckEvent:
                            bsw_event_t03[i]->Entity_FuncPtr();
                            break;
                        default:
                            bsw_event_t03[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t03[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t03[i]);
                ev_triggerred = get_event_counter(bsw_event_t03[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    
    //swc
    count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(rte_event_t03)/sizeof(rte_event_t03[0])) ; i++ ) {
            while (get_event_counter(rte_event_t03[i]) != 0) {
                if (get_event_disablemode(rte_event_t03[i]) == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(rte_event_t03[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(get_event_type(rte_event_t03[i])) {
                        case SwcModeSwitchEvent:
                            rte_event_t03[i]->Entity_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                                // PrintText("T02 SetEvent T02 event1\r\n\0");
                            }
                            break;
                        case ModeSwitchedAckEvent:
                            break;
                        default:
                            rte_event_t03[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(rte_event_t03[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(rte_event_t03[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    }
    GetTaskState(T16, &get_task_state);
    if (get_task_state == SUSPENDED) {
        ActivateTask(T16); //ActivateTask low priority task(background task)
    }
    TerminateTask();
}