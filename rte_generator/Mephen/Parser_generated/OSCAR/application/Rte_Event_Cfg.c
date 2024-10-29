#include "Rte_Event_Cfg.h"


//task T16
RteEvent RteBackgroundEvent_1 = {(uint16)BackgroundEvent, Runnable_background_1};
RteEvent* rte_event_t16[1] = {
    &RteBackgroundEvent_1, 
};

//task T02
RteEvent RteTimingEvent_1 = {(uint16)TimingEvent, Runnable_timing_1};
RteEvent* rte_event_t02[1] = {
    &RteTimingEvent_1, 
};

//task T03
RteEvent RteInitEvent_2 = {(uint16)InitEvent, Runnable_init_2};
RteEvent RteInitEvent_1 = {(uint16)InitEvent, Runnable_init_1};
RteEvent* rte_event_t03[2] = {
    &RteInitEvent_2, 
    &RteInitEvent_1, 
};

//task T04
RteEvent RteModeSwitchEvent_1 = {(uint16)SwcModeSwitchEvent, Runnable_modeSwitch_1};
RteEvent RteModeSwitchEvent_2 = {(uint16)SwcModeSwitchEvent, Runnable_modeSwitch_2};
RteEvent* rte_event_t04[2] = {
    &RteModeSwitchEvent_1, 
    &RteModeSwitchEvent_2, 
};
