#ifndef RTE_EVENT_CFG_H
#define RTE_EVENT_CFG_H
#include "Rte_Type.h"
#include "SWC_LifeCycle/Rte_SWC_LifeCycle.h"
#include "SWC_Mode_A/Rte_SWC_Mode_A.h"

//RteEvent common status
#define get_rteevent_counter(event) event->status_uint16 & 0x0F
#define trigger_rteevent(event) \
    if((event->status_uint16 & 0x0F) == 0x0F){ \
        event->status_uint16 &= 0xFFF0;\
    }else{ \
        event->status_uint16 += 1; \
    }
#define release_rteevent(event) \
    if((event->status_uint16 & 0x0F) == 0x00){ \
        event->status_uint16 &= 0xFFF0;\
    }else{ \
        event->status_uint16 -= 1; \
    }

#define TimingEvent 0x0000
#define BackgroundEvent 0x0010
#define DataReceivedEvent 0x0020
#define DataReceiveErrorEvent 0x0030
#define DataSendCompletedEvent 0x0040
#define DataWriteCompletedEvent 0x0050
#define OperationInvokedEvent 0x0060
#define AsynchronousServerCallReturnsEvent 0x0070
#define SwcModeSwitchEvent 0x0080
#define ModeSwitchedAckEvent 0x0090
#define SwcModeManagerErrorEvent 0x00A0
#define ExternalTriggerOccurredEvent 0x00B0
#define InternalTriggerOccurredEvent 0x00C0
#define InitEvent 0x00D0
#define TransformerHardErrorEvent 0x00E0
#define OsTaskExecutionEvent 0x00F0
#define get_rteevent_type(event) (event->status_uint16 & 0x1F0)

#define get_rteevent_disablemode(event) ((event->status_uint16 & 0x200) >> 9)
#define set_rteevent_disablemode(event) event->status_uint16 |= 0x200
#define clear_rteevent_disablemode(event) event->status_uint16 &= ~(0x200)

#define get_runnable_execute(event) (event->status_uint16 & 0x400) >> 10
#define set_runnable_execute(event) event->status_uint16 |= 0x400
#define clear_runnable_execute(event) event->status_uint16 &= ~(0x400)

//RteEvent subclass specific status
    //InitEvent: 11th-12th bit for trigger runnable type.
#define ClientRunnable 0x000
#define get_trigger_runnable_type(event) (event->status_uint16 & 0x1800)
    //OperationInvokedEvent: 11th-12th bit for communication type.(bit start from 0)
#define InterEcu 0x000
#define InterPartition 0x800
#define IntraPartition 0x1000
#define get_communication_type(event) (event->status_uint16 & 0x1800)
    //other RteEvent subclass specific status(if needed)


//event array of different task
extern RteEvent* rte_event_t16[1];
extern RteEvent* rte_event_t02[1];
extern RteEvent* rte_event_t03[2];
extern RteEvent* rte_event_t04[2];

//Use macro instead of index to access rte_event array
//The event order in task_ev_arr is important, should follow the c/s comm. flow (init_ev -> op_ev -> async_return_ev)
//(when parsing arxml) according to the runnables that are mapped to task x, find the RTEEvents that task x can use
//task T16
extern RteEvent RteBackgroundEvent_1; 
#define RteBackgroundEvent_1_t16 0 

//task T02
extern RteEvent RteTimingEvent_1; 
#define RteTimingEvent_1_t02 0 

//task T03
extern RteEvent RteInitEvent_1; 
extern RteEvent RteInitEvent_2; 
#define RteInitEvent_1_t03 1 
#define RteInitEvent_2_t03 0 

//task T04
extern RteEvent RteModeSwitchEvent_1; 
extern RteEvent RteModeSwitchEvent_2; 
#define RteModeSwitchEvent_1_t04 0 
#define RteModeSwitchEvent_2_t04 1 

#endif//RTE_EVENT_CFG_H