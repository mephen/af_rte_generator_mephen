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

#pragma section TASK_T104_SEC
TASK(T14)
{
    //PrintText("hello t14\r\n\0");
    TerminateTask();
}

#pragma section TASK_T105_SEC
TASK(T15)
{
    //PrintText("hello t15\r\n\0");
    TerminateTask();
}

#pragma section TASK_T106_SEC
TASK(T16)
{
    uint32 temp=0; // avoid inter-arrival protection
    for(uint32 i=0; i<15000 ; i++){
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
