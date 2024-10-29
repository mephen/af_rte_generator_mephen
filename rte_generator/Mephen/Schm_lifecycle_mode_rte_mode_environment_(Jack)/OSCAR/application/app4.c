#include "iodefine.h"
#include "board.h"
#include "os.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "event.h"
#include "task.h"
#include "memsection.h"
#include "memprot_Cfg.h"

#include "string_format_test.h"
#include "ISRInit.h"
#include "systemcall.h"

#include "SchM.h"
#include "Swc.h"
#include "Share_Function.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* OSAPP_A04 *****************/
#pragma section OSAPP_A04_SEC

int app4_test_data = 0x44;

/* Brief StartupHook */
void StartupHook_OSAPP_A04(void)
{
    // PrintText("APP A04: \r\n");
    PrintText("    I'm in App A04 StartupHook\r\n");
    // PrintText("    Start up success!\r\n");
}

/* Brief ShutdownHook */
void ShutdownHook_OSAPP_A04(StatusType Error)
{
    // PrintText("APP A04: \r\n");
    PrintText("    I'm in APP A04 ShutdownHook\r\n");
    // PrintText("    Bye!\r\n");
}

/* Brief ErrorHook */
void ErrorHook_OSAPP_A04(StatusType Error)
{
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
        //PrintText("[ErrorHook]: \r\n");
        break;
    }
}

#pragma section ISR_I105_SEC
ISR(I105)
{
    PrintText("isr 105 in osapp 04\r\n\0");
}

#pragma section ISR_I106_SEC
ISR(I106)
{
    PrintText("isr 106 in osapp 04\r\n\0");
}


#define mode 0
#define modeack 0 // The Basic Software Scheduler do not support WaitPoints. Therefore the SchM_SwitchAck never blocks.
#define swc_mode 0

#pragma section TASK_T104_SEC
TASK(T14)
{
    PrintText("t14\r\n\0");
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }
    //bsw
     TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t14)/sizeof(bsw_event_t14[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t14[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t14[i]);
            uint16 ev_type = get_event_type(bsw_event_t14[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t14[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswTimingEvent:
                            bsw_event_t14[i]->Entity_FuncPtr();
                            break;
                        case BswModeSwitchEvent:
                            bsw_event_t14[i]->Entity_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                            }
                            break;
                        default:
                            bsw_event_t14[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t14[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t14[i]);
                ev_triggerred = get_event_counter(bsw_event_t14[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
#if modeack
    // SetEvent(T03, event1);
#endif
    //swc
    for ( int i = 0 ; i<(sizeof(rte_event_t14)/sizeof(rte_event_t14[0])) ; i++ ) {
        while (get_event_counter(rte_event_t14[i]) != 0) {
            if (get_event_disablemode(rte_event_t14[i]) == 0) {
                GetLock(&share_function_lock_q,share_function_lock_bit);
                set_entity_execute(rte_event_t14[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                switch(get_event_type(rte_event_t14[i])) {
                    case SwcModeSwitchEvent:
                        rte_event_t14[i]->Entity_FuncPtr();
                        modes_witch_count++;
                        if (modes_witch_count == mode_mamager_wakeup_count) {
                            SetEvent(T02, event1);
                        }
                        break;
                    case ModeSwitchedAckEvent:
                        break;
                    default:
                        rte_event_t14[i]->Entity_FuncPtr();
                        break;
                }

                GetLock(&share_function_lock_q,share_function_lock_bit);
                clear_entity_execute(rte_event_t14[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
            }
            GetLock(&share_function_lock_q,share_function_lock_bit);
            release_event(rte_event_t14[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        }
    };
    TerminateTask();
}

#pragma section TASK_T105_SEC
TASK(T15)
{
    PrintText("t15\r\n\0");
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }
    //bsw
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t15)/sizeof(bsw_event_t15[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t15[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t15[i]);
            uint16 ev_type = get_event_type(bsw_event_t15[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t15[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswModeSwitchEvent:
                            bsw_event_t15[i]->Entity_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                            }
                            break;
                        default:
                            bsw_event_t15[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t15[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t15[i]);
                ev_triggerred = get_event_counter(bsw_event_t15[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    //swc
    for ( int i = 0 ; i<(sizeof(rte_event_t15)/sizeof(rte_event_t15[0])) ; i++ ) {
        while (get_event_counter(rte_event_t15[i]) != 0) {
            if (get_event_disablemode(rte_event_t15[i]) == 0) {
                GetLock(&share_function_lock_q,share_function_lock_bit);
                set_entity_execute(rte_event_t15[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                switch(get_event_type(rte_event_t15[i])) {
                    case SwcModeSwitchEvent:
                        rte_event_t15[i]->Entity_FuncPtr();
                        modes_witch_count++;
                        if (modes_witch_count == mode_mamager_wakeup_count) {
                            SetEvent(T02, event1);
                        }
                        break;
                    case ModeSwitchedAckEvent:
                        break;
                    default:
                        rte_event_t15[i]->Entity_FuncPtr();
                        break;
                }

                GetLock(&share_function_lock_q,share_function_lock_bit);
                clear_entity_execute(rte_event_t15[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
            }
            GetLock(&share_function_lock_q,share_function_lock_bit);
            release_event(rte_event_t15[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        }
    };
    /* for test start*/
    // mode
#if mode
    SetEvent(T02,event1);
#endif

#if swc_mode
    SetEvent(T02,event1);
#endif

    /* for test end */
    TerminateTask();
}

#pragma section TASK_T106_SEC
//(low priority) background task for handling BackgroundEvents
TASK(T16)
{
    PrintText("t16(background task)\r\n\0");
    //(bsw) trigger all BackgroundEvents
    for ( int i = 0 ; i<(sizeof(bsw_event_t16)/sizeof(bsw_event_t16[0])) ; i++ ) {
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t16[i]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    }
    //(swc) trigger all BackgroundEvents
    for ( int i = 0 ; i<(sizeof(rte_event_t16)/sizeof(rte_event_t16[0])) ; i++ ) {
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(rte_event_t16[i]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    }

    //check all BackgroundEvents to determine whether to execute them
    TaskStateType get_task_state;
    //bsw
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t16)/sizeof(bsw_event_t16[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t16[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t16[i]);
            uint16 ev_type = get_event_type(bsw_event_t16[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t16[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswBackgroundEvent:
                            bsw_event_t16[i]->Entity_FuncPtr();
                            break;
                        default:
                            bsw_event_t16[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t16[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t16[i]);
                ev_triggerred = get_event_counter(bsw_event_t16[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    
    //swc
    count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(rte_event_t16)/sizeof(rte_event_t16[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(rte_event_t16[i]);
            uint16 ev_disablemode = get_event_disablemode(rte_event_t16[i]);
            uint16 ev_type = get_event_type(rte_event_t16[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(rte_event_t16[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswBackgroundEvent:
                            rte_event_t16[i]->Entity_FuncPtr();
                            break;
                        default:
                            rte_event_t16[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(rte_event_t16[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(rte_event_t16[i]);
                ev_triggerred = get_event_counter(rte_event_t16[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    

    TerminateTask();
}
