//---------------------------------------------------------------------------------------------------------------
//App4.c
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

TASK(T16)
{
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }
    PrintText("T16(Background Task)\r\n\0");

    //(bsw) trigger all BackgroundEvents
    /*
    for ( int i = 0 ; i<(sizeof(bsw_event_t16)/sizeof(bsw_event_t16[0])) ; i++ ) {
        GetLock(&lock, lock_bit);
        trigger_event(bsw_event_t16[i]);
        ReleaseLock(&lock, lock_bit);
    }
    */

    //(swc) trigger all BackgroundEvents
    for ( int i = 0 ; i<(sizeof(rte_event_t16)/sizeof(rte_event_t16[0])) ; i++ ) {
        GetLock(&lock, lock_bit);
        trigger_rteevent(rte_event_t16[i]);
        ReleaseLock(&lock, lock_bit);
    }

    //check all BackgroundEvents to determine whether to execute them
    //bsw
    /*
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t16)/sizeof(bsw_event_t16[0])) ; i++ ) {
            GetLock(&lock, lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t16[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t16[i]);
            uint16 ev_type = get_event_type(bsw_event_t16[i]);
            ReleaseLock(&lock, lock_bit);
    
            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&lock, lock_bit);
                    set_entity_execute(bsw_event_t16[i]);
                    ReleaseLock(&lock, lock_bit);
    
                    switch(ev_type) {
                        case BswBackgroundEvent:
                            bsw_event_t16[i]->Entity_FuncPtr();
                            break;
                        default:
                            bsw_event_t16[i]->Entity_FuncPtr();
                            break;
                    }
    
                    GetLock(&lock, lock_bit);
                    clear_entity_execute(bsw_event_t16[i]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_event(bsw_event_t16[i]);
                ev_triggerred = get_event_counter(bsw_event_t16[i]);
                ReleaseLock(&lock, lock_bit);
                count++;
            }
        };
    };
    */

    //swc
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(rte_event_t16)/sizeof(rte_event_t16[0])) ; i++ ) {
            GetLock(&lock, lock_bit);
            uint16 ev_triggerred = get_rteevent_counter(rte_event_t16[i]);
            uint16 ev_disablemode = get_rteevent_disablemode(rte_event_t16[i]);
            uint16 ev_type = get_rteevent_type(rte_event_t16[i]);
            ReleaseLock(&lock, lock_bit);
    
            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&lock, lock_bit);
                    set_runnable_execute(rte_event_t16[i]);
                    ReleaseLock(&lock, lock_bit);
    
                    switch(ev_type) {
                        case BackgroundEvent:
                            rte_event_t16[i]->Runnable_FuncPtr();
                            break;
                        default:
                            rte_event_t16[i]->Runnable_FuncPtr();
                            break;
                    }
    
                    GetLock(&lock, lock_bit);
                    clear_runnable_execute(rte_event_t16[i]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_event(rte_event_t16[i]);
                ev_triggerred = get_rteevent_counter(rte_event_t16[i]);
                ReleaseLock(&lock, lock_bit);
                count++;
            }
        };
    };

    TerminateTask();
}
//---------------------------------------------------------------------------------------------------------------
//App1.c
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
//---------------------------------------------------------------------------------------------------------------
//App3.c
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

TASK(T04)
{
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }
    PrintText("hello T04\r\n\0");

    //bsw
    /*
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t04)/sizeof(bsw_event_t04[0])) ; i++ ){
            GetLock(&lock, lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t04[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t04[i]);
            uint16 ev_type = get_event_type(bsw_event_t04[i]);
            ReleaseLock(&lock, lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&lock, lock_bit);
                    set_entity_execute(bsw_event_t04[i]);
                    ReleaseLock(&lock, lock_bit);

                    switch(ev_type) {
                        case BswTimingEvent:
                            bsw_event_t04[i]->Entity_FuncPtr();
                            break;
                        case BswModeSwitchEvent:
                            bsw_event_t04[i]->Entity_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                            }
                            break;
                        default:
                            bsw_event_t04[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&lock, lock_bit);
                    clear_entity_execute(bsw_event_t04[i]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_event(bsw_event_t04[i]);
                ev_triggerred = get_event_counter(bsw_event_t04[i]);
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
        for(int ev_t04_index =0; ev_t04_index<(sizeof(rte_event_t04)/sizeof(rte_event_t04[0]));ev_t04_index++){
            GetLock(&lock, lock_bit);
            uint8 ev_triggerred = get_rteevent_counter(rte_event_t04[ev_t04_index]); //use local var to store global var to avoid race condition
            uint8 ev_disablemode = get_rteevent_disablemode(rte_event_t04[ev_t04_index]);
            uint8 ev_type = get_rteevent_type(rte_event_t04[ev_t04_index]);
            ReleaseLock(&lock, lock_bit);

            //task priority may cause the runnable pending(even if the rte_event is triggerred). Rte event may be triggerred multiple times, so we need to use "while-loop" to check rte_event_counter
            while(ev_triggerred){ //check if the event is triggered
                if(!(ev_disablemode)){ //check if the event can activate corresponding runnable
                    GetLock(&lock, lock_bit);
                    set_runnable_execute(rte_event_t04[ev_t04_index]);//set_runnable_execute before invoking the runnable
                    ReleaseLock(&lock, lock_bit);

                    switch (ev_type){ //check RTEEvent type
                        case SwcModeSwitchEvent:
                            rte_event_t04[ev_t04_index]->Runnable_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                                // PrintText("T02 SetEvent T02 event1\r\n\0");
                            }
                            break;
                        default:
                            rte_event_t04[ev_t04_index]->Runnable_FuncPtr();
                            break;
                    }

                    GetLock(&lock, lock_bit);
                    clear_runnable_execute(rte_event_t04[ev_t04_index]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_rteevent(rte_event_t04[ev_t04_index]); //release the event
                ev_triggerred = get_rteevent_counter(rte_event_t04[ev_t04_index]);
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