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
#include "ioc.h"
#include "lock.h"

#include "Share_Function.h"
#include "Rte_Main.h"
#include "Rte_Event_Cfg.h"
#include "SWC_LifeCycle/Rte_SWC_LifeCycle.h"
#include "SWC_Mode_A/Rte_SWC_Mode_A.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

static uint8 lock = 0;
static uint8 lock_bit = 1;

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


#pragma section TASK_T001_SEC
uint32 temp1 = 10;
TASK(T01)
{
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }
    PrintText("T01(RTE Task)\r\n\0");
    TaskStateType get_task_state;

    //simulation of lifecycle in EcuM
    if (init_flag_0 == 0) {
        EcuM_StartupTwo(); //lifecycle test: disable events, execute on-entry Entitys, activate background task, set RTE state
        init_flag_0 = 1;
    } else {
        core0_period_counter();
    }

    GetTaskState(T16, &get_task_state);
    if (get_task_state == SUSPENDED) {
        ActivateTask(T16); //ActivateTask low priority task(background task)
    }
    TerminateTask();
}

#pragma section TASK_T002_SEC
int T02_Global = 0;
TASK(T02)
{
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }
    PrintText("hello T02\r\n\0");

    //bsw
    /*
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t02)/sizeof(bsw_event_t02[0])) ; i++ ){
            GetLock(&lock, lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t02[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t02[i]);
            uint16 ev_type = get_event_type(bsw_event_t02[i]);
            ReleaseLock(&lock, lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&lock, lock_bit);
                    set_entity_execute(bsw_event_t02[i]);
                    ReleaseLock(&lock, lock_bit);

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

                    GetLock(&lock, lock_bit);
                    clear_entity_execute(bsw_event_t02[i]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_event(bsw_event_t02[i]);
                ev_triggerred = get_event_counter(bsw_event_t02[i]);
                ReleaseLock(&lock, lock_bit);
                count++;
            }
        };
    };
    */

    //swc
    TaskStateType get_task_state;
    int count = 1;
    //avoid the situation that a runnable of Task_A use Rte api to trigger a Rte event of another Task_B
    //but Task_B has checked the Rte event before Task_A triggers it, and Task_B is still running.(may cause some triggerred RTE events be ignored)
    while(count){
        count = 0;
        for(int ev_t02_index =0; ev_t02_index<(sizeof(rte_event_t02)/sizeof(rte_event_t02[0]));ev_t02_index++){
            GetLock(&lock, lock_bit);
            uint8 ev_triggerred = get_rteevent_counter(rte_event_t02[ev_t02_index]); //use local var to store global var to avoid race condition
            uint8 ev_disablemode = get_rteevent_disablemode(rte_event_t02[ev_t02_index]);
            uint8 ev_type = get_rteevent_type(rte_event_t02[ev_t02_index]);
            ReleaseLock(&lock, lock_bit);

            //task priority may cause the runnable pending(even if the rte_event is triggerred). Rte event may be triggerred multiple times, so we need to use "while-loop" to check rte_event_counter
            while(ev_triggerred){ //check if the event is triggered
                if(!(ev_disablemode)){ //check if the event can activate corresponding runnable
                    GetLock(&lock, lock_bit);
                    set_runnable_execute(rte_event_t02[ev_t02_index]);//set_runnable_execute before invoking the runnable
                    ReleaseLock(&lock, lock_bit);

                    switch (ev_type){ //check RTEEvent type
                        case SwcModeSwitchEvent:
                            rte_event_t02[ev_t02_index]->Runnable_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                                // PrintText("T02 SetEvent T02 event1\r\n\0");
                            }
                            break;
                        default:
                            rte_event_t02[ev_t02_index]->Runnable_FuncPtr();
                            break;
                    }

                    GetLock(&lock, lock_bit);
                    clear_runnable_execute(rte_event_t02[ev_t02_index]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_rteevent(rte_event_t02[ev_t02_index]); //release the event
                ev_triggerred = get_rteevent_counter(rte_event_t02[ev_t02_index]);
                ReleaseLock(&lock, lock_bit);
                count++;
            }
        }
    }

    GetTaskState(T16, &get_task_state);
    if (get_task_state == SUSPENDED) {
        ActivateTask(T16); //ActivateTask low priority task(background task)
    }

    TerminateTask();
}

#pragma section TASK_T003_SEC
TASK(T03)
{
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }
    PrintText("hello T03\r\n\0");

    //bsw
    /*
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t03)/sizeof(bsw_event_t03[0])) ; i++ ){
            GetLock(&lock, lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t03[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t03[i]);
            uint16 ev_type = get_event_type(bsw_event_t03[i]);
            ReleaseLock(&lock, lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&lock, lock_bit);
                    set_entity_execute(bsw_event_t03[i]);
                    ReleaseLock(&lock, lock_bit);

                    switch(ev_type) {
                        case BswTimingEvent:
                            bsw_event_t03[i]->Entity_FuncPtr();
                            break;
                        case BswModeSwitchEvent:
                            bsw_event_t03[i]->Entity_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                            }
                            break;
                        default:
                            bsw_event_t03[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&lock, lock_bit);
                    clear_entity_execute(bsw_event_t03[i]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_event(bsw_event_t03[i]);
                ev_triggerred = get_event_counter(bsw_event_t03[i]);
                ReleaseLock(&lock, lock_bit);
                count++;
            }
        };
    };
    */

    //swc
    TaskStateType get_task_state;
    int count = 1;
    //avoid the situation that a runnable of Task_A use Rte api to trigger a Rte event of another Task_B
    //but Task_B has checked the Rte event before Task_A triggers it, and Task_B is still running.(may cause some triggerred RTE events be ignored)
    while(count){
        count = 0;
        for(int ev_t03_index =0; ev_t03_index<(sizeof(rte_event_t03)/sizeof(rte_event_t03[0]));ev_t03_index++){
            GetLock(&lock, lock_bit);
            uint8 ev_triggerred = get_rteevent_counter(rte_event_t03[ev_t03_index]); //use local var to store global var to avoid race condition
            uint8 ev_disablemode = get_rteevent_disablemode(rte_event_t03[ev_t03_index]);
            uint8 ev_type = get_rteevent_type(rte_event_t03[ev_t03_index]);
            ReleaseLock(&lock, lock_bit);

            //task priority may cause the runnable pending(even if the rte_event is triggerred). Rte event may be triggerred multiple times, so we need to use "while-loop" to check rte_event_counter
            while(ev_triggerred){ //check if the event is triggered
                if(!(ev_disablemode)){ //check if the event can activate corresponding runnable
                    GetLock(&lock, lock_bit);
                    set_runnable_execute(rte_event_t03[ev_t03_index]);//set_runnable_execute before invoking the runnable
                    ReleaseLock(&lock, lock_bit);

                    switch (ev_type){ //check RTEEvent type
                        case SwcModeSwitchEvent:
                            rte_event_t03[ev_t03_index]->Runnable_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                                // PrintText("T02 SetEvent T02 event1\r\n\0");
                            }
                            break;
                        default:
                            rte_event_t03[ev_t03_index]->Runnable_FuncPtr();
                            break;
                    }

                    GetLock(&lock, lock_bit);
                    clear_runnable_execute(rte_event_t03[ev_t03_index]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_rteevent(rte_event_t03[ev_t03_index]); //release the event
                ev_triggerred = get_rteevent_counter(rte_event_t03[ev_t03_index]);
                ReleaseLock(&lock, lock_bit);
                count++;
            }
        }
    }

    GetTaskState(T16, &get_task_state);
    if (get_task_state == SUSPENDED) {
        ActivateTask(T16); //ActivateTask low priority task(background task)
    }

    TerminateTask();
}
