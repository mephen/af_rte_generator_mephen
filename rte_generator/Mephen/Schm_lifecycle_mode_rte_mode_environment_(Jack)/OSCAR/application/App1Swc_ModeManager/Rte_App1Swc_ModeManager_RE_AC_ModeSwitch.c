#define RTE_RUNNABLEAPI_RE_AC_ModeSwitch
#include "App1Swc_ModeManager_Mode.h"
#include "../../Os_Configure/inc/event_Cfg.h"
#include "../../Os_Configure/inc/task_Cfg.h"
#include "../../device/lock.h"
#include "Share_Function.h"

ModeEventInfo ac_mdgroup_code_disable_mode = {
    .event_ptr = {&rte_event_t15[SwcModeSwitchEvent_EV_1_T15], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_heat_disable_mode = {
    .event_ptr = {&rte_event_t15[SwcModeSwitchEvent_EV_2_T15], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_initmode_disable_mode = {
    .event_ptr = {&rte_event_t15[SwcModeSwitchEvent_EV_0_T15], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_code_on_exit = {
    .event_ptr = {&rte_event_t13[SwcModeSwitchEvent_EV_Mode1_Exit_T13], NULL},
    .func_ptr = {NULL},
    .task = {T13, NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_heat_on_exit = {
    .event_ptr = {&rte_event_t13[SwcModeSwitchEvent_EV_Mode2_Exit_T13], NULL},
    .func_ptr = {NULL},
    .task = {T13, NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_initmode_on_exit = {
    .event_ptr = {&rte_event_t13[SwcModeSwitchEvent_EV_Mode0_Exit_T13], NULL},
    .func_ptr = {NULL},
    .task = {T13, NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_code_on_transition = {
    .event_ptr = {&rte_event_t12[SwcModeSwitchEvent_EV_Mode1_Transition_T12], NULL},
    .func_ptr = {NULL},
    .task = {T12, NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_heat_on_transition = {
    .event_ptr = {&rte_event_t12[SwcModeSwitchEvent_EV_Mode2_Transition_T12], NULL},
    .func_ptr = {NULL},
    .task = {T12, NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_initmode_on_transition = {
    .event_ptr = {&rte_event_t12[SwcModeSwitchEvent_EV_Mode0_Transition_T12], NULL},
    .func_ptr = {NULL},
    .task = {T12, NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_code_on_entry = {
    .event_ptr = {&rte_event_t14[SwcModeSwitchEvent_EV_Mode1_Entry_T14], NULL},
    .func_ptr = {NULL},
    .task = {T14, NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_heat_on_entry = {
    .event_ptr = {&rte_event_t14[SwcModeSwitchEvent_EV_Mode2_Entry_T14], NULL},
    .func_ptr = {NULL},
    .task = {T14, NULL},
    .num = 1
};

ModeEventInfo ac_mdgroup_initmode_on_entry = {
    .event_ptr = {&rte_event_t14[SwcModeSwitchEvent_EV_Mode0_Entry_T14], NULL},
    .func_ptr = {NULL},
    .task = {T14, NULL},
    .num = 1
};

ModeEvents ac_mdgroup_code_events = {
    .on_exit = &ac_mdgroup_code_on_exit,
    .on_entry = &ac_mdgroup_code_on_entry,
    .on_transition = &ac_mdgroup_code_on_transition,
    .disable_mode = &ac_mdgroup_code_disable_mode
};

ModeEvents ac_mdgroup_heat_events = {
    .on_exit = &ac_mdgroup_heat_on_exit,
    .on_entry = &ac_mdgroup_heat_on_entry,
    .on_transition = &ac_mdgroup_heat_on_transition,
    .disable_mode = &ac_mdgroup_heat_disable_mode
};

ModeEvents ac_mdgroup_initmode_events = {
    .on_exit = &ac_mdgroup_initmode_on_exit,
    .on_entry = &ac_mdgroup_initmode_on_entry,
    .on_transition = &ac_mdgroup_initmode_on_transition,
    .disable_mode = &ac_mdgroup_initmode_disable_mode
};

ModeEvents *ac_mdgroup[3] = {&ac_mdgroup_code_events, &ac_mdgroup_heat_events, &ac_mdgroup_initmode_events};

// Signature: [SWS_Rte_02631]
void Rte_Switch_ModeSwitchInterface_PPort_AC_MDGroup(RteModeType mode) {
    Std_ReturnType return_value = RTE_E_OK;
    RteModeType data;
    ModeEvents *selected_current_mode_event = ac_mdgroup[mode_manager_status[AC_MDGROUP_STATUS]->currentmode];
    ModeEvents *selected_next_mode_event = ac_mdgroup[mode];
    ModeEventInfo *current_event_union;
    do {
        //[SWS_Rte_02667] -> Is it in transmission status? (p362)
        switch(mode_manager_status[AC_MDGROUP_STATUS]->switch_status) {
            case notSwitch:
                mode_manager_status[AC_MDGROUP_STATUS]->nextmode = mode;
                mode_manager_status[AC_MDGROUP_STATUS]->switch_status = onSwitch;
                // [SWS_Rte_02661] step1 : activate mode disablings for the next mode
                current_event_union = selected_next_mode_event->disable_mode;
                set_disable_mode(current_event_union);

                // [SWS_Rte_07152] step2 : if synchronous, wait until the newly disabled RunnableEntitys are terminatesd
                wait_executed_finish(current_event_union);

                // step3, step4 : [SWS_Rte_02562], [SWS_Rte_07153] : on-exit ExecutableEntity
                current_event_union = selected_current_mode_event->on_exit;
                set_event(current_event_union);
                modes_witch_count = 0;
                mode_mamager_wakeup_count = current_event_union->num;
                activate_task(current_event_union);
                // synchronous, wait until onExit ExecutableEntity are terminatesd
                WaitEvent(event1);
                ClearEvent(event1);

                // step5, step6 : [SWS_Rte_02707], [SWS_Rte_02708] : on-transition ExecutableEntitys
                current_event_union = selected_next_mode_event->on_transition;
                set_event(current_event_union);
                modes_witch_count = 0;
                mode_mamager_wakeup_count = current_event_union->num;
                activate_task(current_event_union);
                // synchronous, wait until onTransition ExecutableEntity are terminatesd
                WaitEvent(event1);
                ClearEvent(event1);

                // step7, step8 : [SWS_Rte_02564], [SWS_Rte_07154] : on-entry ExecutableEntitys
                current_event_union = selected_next_mode_event->on_entry;
                set_event(current_event_union);
                modes_witch_count = 0;
                mode_mamager_wakeup_count = current_event_union->num;
                activate_task(current_event_union);
                // synchronous, wait until onEntry ExecutableEntity are terminatesd
                WaitEvent(event1);
                ClearEvent(event1);

                // [SWS_Rte_02563] step9 : deactivate the previous mode disablings
                current_event_union = selected_current_mode_event->disable_mode;
                clear_disable_mode(current_event_union);
                current_event_union = selected_next_mode_event->disable_mode;
                set_disable_mode(current_event_union);

                mode_manager_status[AC_MDGROUP_STATUS]->switch_status = notSwitch;
                mode_manager_status[AC_MDGROUP_STATUS]->previousmode = mode_manager_status[AC_MDGROUP_STATUS]->currentmode;
                mode_manager_status[AC_MDGROUP_STATUS]->currentmode = mode_manager_status[AC_MDGROUP_STATUS]->nextmode;

                break;
            case onSwitch:
                // check queue capacity
                return_value = RTE_Enqueue(&mode_manager_queue[RE_AC_MODESWITCH_QUEUE], &mode, sizeof(RteModeType));
                return;
        }

        // [SWS_Rte_02668] check queue
        return_value = RTE_Dequeue(&mode_manager_queue[RE_AC_MODESWITCH_QUEUE], &data, sizeof(RteModeType));
        if (return_value != RTE_E_NO_DATA) {
            mode = &data;
        }

    } while (return_value != RTE_E_NO_DATA);

    return;
}

void RTE_RUNNABLE_RE_AC_ModeSwitch(){
/* The algorithm of RE_AC_ModeSwitch */
    PrintText("RE_AC_ModeSwitch\r\n\0");
    Rte_Switch_ModeSwitchInterface_PPort_AC_MDGroup(RTE_MODE_AC_MDGroup_CODE);
    return;
}
