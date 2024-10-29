#include "Bsw_Event_Cfg.h"
#include "SchM.h"
#include "Share_Function.h"

Event BswModeSwitchEvent_EV_Engine_ModeSwitch = {(uint16) BswModeSwitchEvent, SCHM_BE_Engine_ModeSwitch};
Event BswModeSwitchEvent_EV_Engine_Test = {(uint16) BswModeSwitchEvent, SCHM_BE_Engine_Test};
Event BswModeSwitchedAckEvent_EV_Engine_ModeSwitchAck = {(uint16) BswModeSwitchedAckEvent, SCHM_BE_Engine_ModeSwitchAck};
Event BswModeSwitchEvent_EV_10 = {(uint16) BswModeSwitchEvent, SCHM_BE_0};
Event BswModeSwitchEvent_EV_11 = {(uint16) BswModeSwitchEvent, SCHM_BE_1};
Event BswModeSwitchEvent_EV_12 = {(uint16) BswModeSwitchEvent, SCHM_BE_2};
Event BswModeSwitchEvent_EV_13 = {(uint16) BswModeSwitchEvent, SCHM_BE_3};
Event BswModeSwitchEvent_EV_14 = {(uint16) BswModeSwitchEvent, SCHM_BE_4};
Event BswModeSwitchEvent_EV_15 = {(uint16) BswModeSwitchEvent, SCHM_BE_5};
Event BswModeSwitchEvent_EV_bsw_Mode0_Exit = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode0_Exit};
Event BswModeSwitchEvent_EV_bsw_Mode0_Transition = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode0_Transition};
Event BswModeSwitchEvent_EV_bsw_Mode0_Entry = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode0_Entry};
Event BswModeSwitchEvent_EV_bsw_Mode1_Exit = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode1_Exit};
Event BswModeSwitchEvent_EV_bsw_Mode1_Transition = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode1_Transition};
Event BswModeSwitchEvent_EV_bsw_Mode1_Entry = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode1_Entry};
Event BswModeSwitchEvent_EV_bsw_Mode2_Exit = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode2_Exit};
Event BswModeSwitchEvent_EV_bsw_Mode2_Transition = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode2_Transition};
Event BswModeSwitchEvent_EV_bsw_Mode2_Entry = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode2_Entry};
Event BswModeSwitchEvent_EV_bsw_Mode3_Exit = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode3_Exit};
Event BswModeSwitchEvent_EV_bsw_Mode3_Transition = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode3_Transition};
Event BswModeSwitchEvent_EV_bsw_Mode3_Entry = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode3_Entry};
Event BswModeSwitchEvent_EV_bsw_Mode4_Exit = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode4_Exit};
Event BswModeSwitchEvent_EV_bsw_Mode4_Transition = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode4_Transition};
Event BswModeSwitchEvent_EV_bsw_Mode4_Entry = {(uint16) BswModeSwitchEvent, SCHM_BE_Mode4_Entry};
Event BswBackgroundEvent_EV_background1 = {(uint16) BswBackgroundEvent, SCHM_BE_background1};
Event BswTimingEvent_EV_timing1 = {(uint16) BswTimingEvent, SCHM_BE_timing1};
Event BswBackgroundEvent_EV_background2 = {(uint16) BswBackgroundEvent, SCHM_BE_background2};
Event BswTimingEvent_EV_timing2 = {(uint16) BswTimingEvent, SCHM_BE_timing2};

Event *bsw_event_t03[1] = {
    &BswModeSwitchedAckEvent_EV_Engine_ModeSwitchAck,
};

Event *bsw_event_t02[2] = {
    &BswModeSwitchEvent_EV_Engine_ModeSwitch,
    &BswTimingEvent_EV_timing1,
};

Event *bsw_event_t15[6] = {
    &BswModeSwitchEvent_EV_11,
    &BswModeSwitchEvent_EV_10,
    &BswModeSwitchEvent_EV_12,
    &BswModeSwitchEvent_EV_13,
    &BswModeSwitchEvent_EV_14,
    &BswModeSwitchEvent_EV_15,
};

Event *bsw_event_t13[5] = {
    &BswModeSwitchEvent_EV_bsw_Mode0_Exit,
    &BswModeSwitchEvent_EV_bsw_Mode1_Exit,
    &BswModeSwitchEvent_EV_bsw_Mode2_Exit,
    &BswModeSwitchEvent_EV_bsw_Mode3_Exit,
    &BswModeSwitchEvent_EV_bsw_Mode4_Exit,
};

Event *bsw_event_t12[5] = {
    &BswModeSwitchEvent_EV_bsw_Mode0_Transition,
    &BswModeSwitchEvent_EV_bsw_Mode1_Transition,
    &BswModeSwitchEvent_EV_bsw_Mode2_Transition,
    &BswModeSwitchEvent_EV_bsw_Mode3_Transition,
    &BswModeSwitchEvent_EV_bsw_Mode4_Transition,
};

Event *bsw_event_t14[5] = {
    &BswModeSwitchEvent_EV_bsw_Mode1_Entry,
    &BswModeSwitchEvent_EV_bsw_Mode2_Entry,
    &BswModeSwitchEvent_EV_bsw_Mode3_Entry,
    &BswModeSwitchEvent_EV_bsw_Mode4_Entry,
    &BswTimingEvent_EV_timing2,
};

Event *bsw_event_t16[2] = {
    &BswBackgroundEvent_EV_background1,
    &BswBackgroundEvent_EV_background2,
};

