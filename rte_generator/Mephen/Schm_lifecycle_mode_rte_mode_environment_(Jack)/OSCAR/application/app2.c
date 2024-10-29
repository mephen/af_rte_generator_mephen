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
#include "application.h"
#include "trustedFunc_Cfg.h"

#include "SchM.h"
#include "Swc.h"
#include "Share_Function.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

/************* OSAPP_A02 *****************/
#pragma section OSAPP_A02_SEC

int app2_test_data = 0x22;

/* Brief StartupHook */
void StartupHook_OSAPP_A02(void)
{
    // PrintText("APP A02: \r\n");
    PrintText("    I'm in App A02 StartupHook\r\n");
    // PrintText("    Start up success!\r\n");
}

/* Brief ShutdownHook */
void ShutdownHook_OSAPP_A02(StatusType Error)
{
    // PrintText("APP A02: \r\n");
    PrintText("    I'm in APP A02 ShutdownHook\r\n");
    // PrintText("    Bye!\r\n");
}

/* Brief ErrorHook */
void ErrorHook_OSAPP_A02(StatusType Error)
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
        PrintText("[ErrorHook]: \r\n");
        break;
    }
}

void TRUSTED_TF_YUURI( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF YUURI\r\n\0");
}
void TRUSTED_TF_HITORIE( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para)
{
    PrintText("TF HITORIE\r\n\0");
}

#pragma section ISR_I101_SEC
ISR(I101)
{
    PrintText("isr 101 in osapp 02\r\n\0");
}

#pragma section ISR_I102_SEC
ISR(I102)
{
    PrintText("isr 102 in osapp 02\r\n\0");
}

#pragma section ISR_I103_SEC
ISR(I103)
{
    PrintText("isr 103 in osapp 02\r\n\0");
}

#pragma section ISR_I104_SEC
ISR(I104)
{
    PrintText("isr 104 in osapp 02\r\n\0");
}

#pragma section LOCAL_RAM_PE1
uint16 local = 100;

#define lifecycle 1

#pragma section TASK_T101_SEC
TASK(T11)
{
    // uint32 temp = 555;
    // uint32 *temp2;
    PrintText("t11\r\n\0");
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }

#if lifecycle
    if (init_flag_1 == 0) {
        init_flag_1 = 1;
    } else {
        core1_period_counter();
    }
#endif

    TerminateTask();
}

// int count_1 = 0;
#pragma section TASK_T102_SEC
TASK(T12)
{
    PrintText("t12\r\n\0");
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }

    //bsw
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t12)/sizeof(bsw_event_t12[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t12[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t12[i]);
            uint16 ev_type = get_event_type(bsw_event_t12[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t12[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswModeSwitchEvent:
                            bsw_event_t12[i]->Entity_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                            }
                            break;
                        default:
                            bsw_event_t12[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t12[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t12[i]);
                ev_triggerred = get_event_counter(bsw_event_t12[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    //swc
    for ( int i = 0 ; i<(sizeof(rte_event_t12)/sizeof(rte_event_t12[0])) ; i++ ) {
        while (get_event_counter(rte_event_t12[i]) != 0) {
            if (get_event_disablemode(rte_event_t12[i]) == 0) {
                GetLock(&share_function_lock_q,share_function_lock_bit);
                set_entity_execute(rte_event_t12[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                switch(get_event_type(rte_event_t12[i])) {
                    case SwcModeSwitchEvent:
                        rte_event_t12[i]->Entity_FuncPtr();
                        modes_witch_count++;
                        if (modes_witch_count == mode_mamager_wakeup_count) {
                            SetEvent(T02, event1);
                        }
                        break;
                    case ModeSwitchedAckEvent:
                        break;
                    default:
                        rte_event_t12[i]->Entity_FuncPtr();
                        break;
                }

                GetLock(&share_function_lock_q,share_function_lock_bit);
                clear_entity_execute(rte_event_t12[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
            }
            GetLock(&share_function_lock_q,share_function_lock_bit);
            release_event(rte_event_t12[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        }
    };
    TerminateTask();
}

#pragma section TASK_T103_SEC
TASK(T13)
{
    PrintText("t13\r\n\0");
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<10000 ; i++){
        temp++;
    }
    //bsw
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t13)/sizeof(bsw_event_t13[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t13[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t13[i]);
            uint16 ev_type = get_event_type(bsw_event_t13[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t13[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswModeSwitchEvent:
                            bsw_event_t13[i]->Entity_FuncPtr();
                            modes_witch_count++;
                            if (modes_witch_count == mode_mamager_wakeup_count) {
                                SetEvent(T02, event1);
                            }
                            break;
                        default:
                            bsw_event_t13[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t13[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t13[i]);
                ev_triggerred = get_event_counter(bsw_event_t13[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    //swc
    for ( int i = 0 ; i<(sizeof(rte_event_t13)/sizeof(rte_event_t13[0])) ; i++ ) {
        while (get_event_counter(rte_event_t13[i]) != 0) {
            if (get_event_disablemode(rte_event_t13[i]) == 0) {
                GetLock(&share_function_lock_q,share_function_lock_bit);
                set_entity_execute(rte_event_t13[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                switch(get_event_type(rte_event_t13[i])) {
                    case SwcModeSwitchEvent:
                        rte_event_t13[i]->Entity_FuncPtr();
                        modes_witch_count++;
                        if (modes_witch_count == mode_mamager_wakeup_count) {
                            SetEvent(T02, event1);
                        }
                        break;
                    case ModeSwitchedAckEvent:
                        break;
                    default:
                        rte_event_t13[i]->Entity_FuncPtr();
                        break;
                }

                GetLock(&share_function_lock_q,share_function_lock_bit);
                clear_entity_execute(rte_event_t13[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
            }
            GetLock(&share_function_lock_q,share_function_lock_bit);
            release_event(rte_event_t13[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);
        }
    };
    TerminateTask();
}