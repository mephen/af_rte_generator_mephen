#ifndef RTE_EVENT_CFG_H
#define RTE_EVENT_CFG_H

#include "Rte_Type.h"

/*T02*/
#define SwcModeSwitchEvent_EV_AC_ModeSwitch_T02 0
#define RteTimingEvent_RteEV_timing1_T02 1
#define RteInitEvent_RteEV_init1_T02 2
extern Event RteTimingEvent_RteEV_timing1;
extern Event *rte_event_t02[3];

/*T03*/
#define RteInitEvent_RteEV_init2_T03 0
extern Event RteInitEvent_RteEV_init2;
extern Event *rte_event_t03[1];

/*T14*/
#define SwcModeSwitchEvent_EV_Mode0_Entry_T14 0
#define SwcModeSwitchEvent_EV_Mode1_Entry_T14 1
#define SwcModeSwitchEvent_EV_Mode2_Entry_T14 2
extern Event *rte_event_t14[3];

/*T13*/
#define SwcModeSwitchEvent_EV_Mode0_Exit_T13 0
#define SwcModeSwitchEvent_EV_Mode1_Exit_T13 1
#define SwcModeSwitchEvent_EV_Mode2_Exit_T13 2
extern Event *rte_event_t13[3];

/*T12*/
#define SwcModeSwitchEvent_EV_Mode0_Transition_T12 0
#define SwcModeSwitchEvent_EV_Mode1_Transition_T12 1
#define SwcModeSwitchEvent_EV_Mode2_Transition_T12 2
extern Event *rte_event_t12[3];

/*T15*/
#define SwcModeSwitchEvent_EV_0_T15 0
#define SwcModeSwitchEvent_EV_1_T15 1
#define SwcModeSwitchEvent_EV_2_T15 2
#define SwcModeSwitchEvent_EV_3_T15 3
extern Event *rte_event_t15[4];

/*T16(background task)*/
#define RteBackgroundEvent_RteEV_background1_T16 0
extern Event *rte_event_t16[1];

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

#endif
