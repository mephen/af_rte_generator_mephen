#define RTE_EVENT_CFG_C

#include "Rte_Event_Cfg.h"
#include "Swc.h"
#include "SWC_LifeCycle1/Rte_LifeCycle1.h"


Event SwcModeSwitchEvent_EV_AC_ModeSwitch = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_AC_ModeSwitch};

Event RteTimingEvent_RteEV_timing1 = {(uint16) TimingEvent, RTE_RUNNABLE_RTE_timing1};

Event RteInitEvent_RteEV_init1 = {(uint16) InitEvent, RTE_RUNNABLE_RTE_init1};

Event RteInitEvent_RteEV_init2 = {(uint16) InitEvent, RTE_RUNNABLE_RTE_init2};

Event SwcModeSwitchEvent_EV_0 = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_0};

Event SwcModeSwitchEvent_EV_1 = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_1};

Event SwcModeSwitchEvent_EV_2 = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_2};

Event SwcModeSwitchEvent_EV_3 = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_3};

Event SwcModeSwitchEvent_EV_Mode0_Entry = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_Mode0_Entry};

Event SwcModeSwitchEvent_EV_Mode0_Exit = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_Mode0_Exit};

Event SwcModeSwitchEvent_EV_Mode0_Transition = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_Mode0_Transition};

Event SwcModeSwitchEvent_EV_Mode1_Entry = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_Mode1_Entry};

Event SwcModeSwitchEvent_EV_Mode1_Exit = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_Mode1_Exit};

Event SwcModeSwitchEvent_EV_Mode1_Transition = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_Mode1_Transition};

Event SwcModeSwitchEvent_EV_Mode2_Entry = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_Mode2_Entry};

Event SwcModeSwitchEvent_EV_Mode2_Exit = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_Mode2_Exit};

Event SwcModeSwitchEvent_EV_Mode2_Transition = {(uint16) SwcModeSwitchEvent, RTE_RUNNABLE_RE_Mode2_Transition};

Event RteBackgroundEvent_RteEV_background1 = {(uint16) BackgroundEvent, RTE_RUNNABLE_RTE_background1};

Event *rte_event_t02[3] = {
    &SwcModeSwitchEvent_EV_AC_ModeSwitch,
    &RteTimingEvent_RteEV_timing1,
    &RteInitEvent_RteEV_init1,
};

Event *rte_event_t03[1] = {
    &RteInitEvent_RteEV_init2,
};

Event *rte_event_t14[3] = {
    &SwcModeSwitchEvent_EV_Mode0_Entry,
    &SwcModeSwitchEvent_EV_Mode1_Entry,
    &SwcModeSwitchEvent_EV_Mode2_Entry,
};

Event *rte_event_t13[3] = {
    &SwcModeSwitchEvent_EV_Mode0_Exit,
    &SwcModeSwitchEvent_EV_Mode1_Exit,
    &SwcModeSwitchEvent_EV_Mode2_Exit,
};

Event *rte_event_t12[3] = {
    &SwcModeSwitchEvent_EV_Mode0_Transition,
    &SwcModeSwitchEvent_EV_Mode1_Transition,
    &SwcModeSwitchEvent_EV_Mode2_Transition,
};

Event *rte_event_t15[4] = {
    &SwcModeSwitchEvent_EV_0,
    &SwcModeSwitchEvent_EV_1,
    &SwcModeSwitchEvent_EV_2,
    &SwcModeSwitchEvent_EV_3,
};

Event *rte_event_t16[1] = {
    &RteBackgroundEvent_RteEV_background1,
};

