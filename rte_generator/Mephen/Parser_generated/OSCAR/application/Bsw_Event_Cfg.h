#ifndef BSW_EVENT_CFG_H
#define BSW_EVENT_CFG_H

#include "Rte_Type.h"

/*T03*/
#define BswModeSwitchedAckEvent_EV_Engine_ModeSwitchAck_T03 0
extern Event BswModeSwitchedAckEvent_EV_Engine_ModeSwitchAck;
extern Event *bsw_event_t03[1];

/*T02*/
#define BswModeSwitchEvent_EV_Engine_ModeSwitch_T02 0
extern Event BswModeSwitchEvent_EV_Engine_ModeSwitch;
#define BswTimingEvent_EV_timing1_T02 1
extern Event BswTimingEvent_EV_timing1;
extern Event *bsw_event_t02[2];

/*T15*/
#define BswModeSwitchEvent_EV_11_T15 0
extern Event BswModeSwitchEvent_EV_11;
#define BswModeSwitchEvent_EV_10_T15 1
extern Event BswModeSwitchEvent_EV_10;
#define BswModeSwitchEvent_EV_12_T15 2
extern Event BswModeSwitchEvent_EV_12;
#define BswModeSwitchEvent_EV_13_T15 3
extern Event BswModeSwitchEvent_EV_13;
#define BswModeSwitchEvent_EV_14_T15 4
extern Event BswModeSwitchEvent_EV_14;
#define BswModeSwitchEvent_EV_15_T15 5
extern Event BswModeSwitchEvent_EV_15;
extern Event *bsw_event_t15[6];

/*T13*/
#define BswModeSwitchEvent_EV_bsw_Mode0_Exit_T13 0
extern Event BswModeSwitchEvent_EV_bsw_Mode0_Exit;
#define BswModeSwitchEvent_EV_bsw_Mode1_Exit_T13 1
extern Event BswModeSwitchEvent_EV_bsw_Mode1_Exit;
#define BswModeSwitchEvent_EV_bsw_Mode2_Exit_T13 2
extern Event BswModeSwitchEvent_EV_bsw_Mode2_Exit;
#define BswModeSwitchEvent_EV_bsw_Mode3_Exit_T13 3
extern Event BswModeSwitchEvent_EV_bsw_Mode3_Exit;
#define BswModeSwitchEvent_EV_bsw_Mode4_Exit_T13 4
extern Event BswModeSwitchEvent_EV_bsw_Mode4_Exit;
extern Event *bsw_event_t13[5];

/*T12*/
#define BswModeSwitchEvent_EV_bsw_Mode0_Transition_T12 0
extern Event BswModeSwitchEvent_EV_bsw_Mode0_Transition;
#define BswModeSwitchEvent_EV_bsw_Mode1_Transition_T12 1
extern Event BswModeSwitchEvent_EV_bsw_Mode1_Transition;
#define BswModeSwitchEvent_EV_bsw_Mode2_Transition_T12 2
extern Event BswModeSwitchEvent_EV_bsw_Mode2_Transition;
#define BswModeSwitchEvent_EV_bsw_Mode3_Transition_T12 3
extern Event BswModeSwitchEvent_EV_bsw_Mode3_Transition;
#define BswModeSwitchEvent_EV_bsw_Mode4_Transition_T12 4
extern Event BswModeSwitchEvent_EV_bsw_Mode4_Transition;
extern Event *bsw_event_t12[5];

/*T14*/
#define BswModeSwitchEvent_EV_bsw_Mode1_Entry_T14 0
extern Event BswModeSwitchEvent_EV_bsw_Mode1_Entry;
#define BswModeSwitchEvent_EV_bsw_Mode2_Entry_T14 1
extern Event BswModeSwitchEvent_EV_bsw_Mode2_Entry;
#define BswModeSwitchEvent_EV_bsw_Mode3_Entry_T14 2
extern Event BswModeSwitchEvent_EV_bsw_Mode3_Entry;
#define BswModeSwitchEvent_EV_bsw_Mode4_Entry_T14 3
extern Event BswModeSwitchEvent_EV_bsw_Mode4_Entry;
#define BswTimingEvent_EV_timing2_T14 4
extern Event BswTimingEvent_EV_timing2;
extern Event *bsw_event_t14[5];

/*T16*/
#define BswBackgroundEvent_EV_background1_T16 0
extern Event BswBackgroundEvent_EV_background1;
#define BswBackgroundEvent_EV_background2_T16 1
extern Event BswBackgroundEvent_EV_background2;
extern Event *bsw_event_t16[2];

#define BswAsynchronousServerCallReturnsEvent 0x00
#define BswBackgroundEvent 0x10
#define BswDataReceivedEvent 0x20
#define BswExternalTriggerOccurredEvent 0x30
#define BswInternalTriggerOccurredEvent 0x40
#define BswModeManagerErrorEvent 0x50
#define BswModeSwitchEvent 0x60
#define BswModeSwitchedAckEvent 0x70
#define BswOsTaskExecutionEvent 0x80
#define BswTimingEvent 0x90
#define BswOperationInvokedEvent 0xA0

#endif
