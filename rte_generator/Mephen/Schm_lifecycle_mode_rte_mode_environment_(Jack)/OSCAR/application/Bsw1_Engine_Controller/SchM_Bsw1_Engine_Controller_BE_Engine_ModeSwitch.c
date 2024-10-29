#define SCHM_API_BE_Engine_ModeSwitch
#include "Bsw1_Engine_Controller.h"
#include "../../Os_Configure/inc/event_Cfg.h"
#include "../../Os_Configure/inc/task_Cfg.h"
#include "../../device/lock.h"
#include "../Share_Function.h"
#include "../SchM.h"
#include "../../kernel/os.h"

int IB_Engine_Controller_timeout_count;

ModeEventInfo engine_mdgroup_d_disable_mode = {
    .event_ptr = {&bsw_event_t15[BswModeSwitchEvent_EV_14_T15], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_initmode_disable_mode = {
    .event_ptr = {&bsw_event_t15[BswModeSwitchEvent_EV_10_T15], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_n_disable_mode = {
    .event_ptr = {&bsw_event_t15[BswModeSwitchEvent_EV_13_T15], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_p_disable_mode = {
    .event_ptr = {&bsw_event_t15[BswModeSwitchEvent_EV_10_T15], &bsw_event_t15[BswModeSwitchEvent_EV_11_T15], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 2
};

ModeEventInfo engine_mdgroup_r_disable_mode = {
    .event_ptr = {&bsw_event_t15[BswModeSwitchEvent_EV_12_T15], NULL},
    .func_ptr = {NULL},
    .task = {NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_d_on_exit = {
    .event_ptr = {&bsw_event_t13[BswModeSwitchEvent_EV_bsw_Mode4_Exit_T13], NULL},
    .func_ptr = {NULL},
    .task = {T13, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_initmode_on_exit = {
    .event_ptr = {&bsw_event_t13[BswModeSwitchEvent_EV_bsw_Mode0_Exit_T13], NULL},
    .func_ptr = {NULL},
    .task = {T13, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_n_on_exit = {
    .event_ptr = {&bsw_event_t13[BswModeSwitchEvent_EV_bsw_Mode3_Exit_T13], NULL},
    .func_ptr = {NULL},
    .task = {T13, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_p_on_exit = {
    .event_ptr = {&bsw_event_t13[BswModeSwitchEvent_EV_bsw_Mode1_Exit_T13], NULL},
    .func_ptr = {NULL},
    .task = {T13, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_r_on_exit = {
    .event_ptr = {&bsw_event_t13[BswModeSwitchEvent_EV_bsw_Mode2_Exit_T13], NULL},
    .func_ptr = {NULL},
    .task = {T13, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_d_on_transition = {
    .event_ptr = {&bsw_event_t12[BswModeSwitchEvent_EV_bsw_Mode4_Transition_T12], NULL},
    .func_ptr = {NULL},
    .task = {T12, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_initmode_on_transition = {
    .event_ptr = {&bsw_event_t12[BswModeSwitchEvent_EV_bsw_Mode0_Transition_T12], NULL},
    .func_ptr = {NULL},
    .task = {T12, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_n_on_transition = {
    .event_ptr = {&bsw_event_t12[BswModeSwitchEvent_EV_bsw_Mode3_Transition_T12], NULL},
    .func_ptr = {NULL},
    .task = {T12, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_p_on_transition = {
    .event_ptr = {&bsw_event_t12[BswModeSwitchEvent_EV_bsw_Mode1_Transition_T12], NULL},
    .func_ptr = {NULL},
    .task = {T12, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_r_on_transition = {
    .event_ptr = {&bsw_event_t12[BswModeSwitchEvent_EV_bsw_Mode2_Transition_T12], NULL},
    .func_ptr = {NULL},
    .task = {T12, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_d_on_entry = {
    .event_ptr = {&bsw_event_t14[BswModeSwitchEvent_EV_bsw_Mode4_Entry_T14], NULL},
    .func_ptr = {NULL},
    .task = {T14, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_initmode_on_entry = {
    .event_ptr = {NULL},
    .func_ptr = {SCHM_BE_Mode0_Entry, NULL},
    .task = { NULL},
    .num = 0
};

ModeEventInfo engine_mdgroup_n_on_entry = {
    .event_ptr = {&bsw_event_t14[BswModeSwitchEvent_EV_bsw_Mode3_Entry_T14], NULL},
    .func_ptr = {NULL},
    .task = {T14, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_p_on_entry = {
    .event_ptr = {&bsw_event_t14[BswModeSwitchEvent_EV_bsw_Mode1_Entry_T14], NULL},
    .func_ptr = {NULL},
    .task = {T14, NULL},
    .num = 1
};

ModeEventInfo engine_mdgroup_r_on_entry = {
    .event_ptr = {&bsw_event_t14[BswModeSwitchEvent_EV_bsw_Mode2_Entry_T14], NULL},
    .func_ptr = {NULL},
    .task = {T14, NULL},
    .num = 1
};

ModeEvents engine_mdgroup_d_events = {
    .on_exit = &engine_mdgroup_d_on_exit,
    .on_entry = &engine_mdgroup_d_on_entry,
    .on_transition = &engine_mdgroup_d_on_transition,
    .disable_mode = &engine_mdgroup_d_disable_mode
};

ModeEvents engine_mdgroup_initmode_events = {
    .on_exit = &engine_mdgroup_initmode_on_exit,
    .on_entry = &engine_mdgroup_initmode_on_entry,
    .on_transition = &engine_mdgroup_initmode_on_transition,
    .disable_mode = &engine_mdgroup_initmode_disable_mode
};

ModeEvents engine_mdgroup_n_events = {
    .on_exit = &engine_mdgroup_n_on_exit,
    .on_entry = &engine_mdgroup_n_on_entry,
    .on_transition = &engine_mdgroup_n_on_transition,
    .disable_mode = &engine_mdgroup_n_disable_mode
};

ModeEvents engine_mdgroup_p_events = {
    .on_exit = &engine_mdgroup_p_on_exit,
    .on_entry = &engine_mdgroup_p_on_entry,
    .on_transition = &engine_mdgroup_p_on_transition,
    .disable_mode = &engine_mdgroup_p_disable_mode
};

ModeEvents engine_mdgroup_r_events = {
    .on_exit = &engine_mdgroup_r_on_exit,
    .on_entry = &engine_mdgroup_r_on_entry,
    .on_transition = &engine_mdgroup_r_on_transition,
    .disable_mode = &engine_mdgroup_r_disable_mode
};

ModeEvents *engine_mdgroup[5] = {&engine_mdgroup_d_events, &engine_mdgroup_initmode_events, &engine_mdgroup_n_events, &engine_mdgroup_p_events, &engine_mdgroup_r_events};

// [SWS_Rte_07255]
Std_ReturnType SchM_Switch_Bsw1_Engine_Controller_Engine_MDGroup(SchMModeType mode) {
    TaskStateType get_task_state;
    Std_ReturnType return_value = SCHM_E_OK;
    SchMModeType data;
    ModeEvents *selected_current_mode_event = engine_mdgroup[schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->currentmode];
    ModeEvents *selected_next_mode_event = engine_mdgroup[mode];
    ModeEventInfo *current_event_union;
    IB_Engine_Controller_timeout_count = count_0;

    do {
        //[SWS_Rte_02667] -> Is it in transmission status? (p362)
        switch(schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->switch_status) {
            case notSwitch:
                schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->nextmode = mode;
                schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->switch_status = onSwitch;
                // [SWS_Rte_02661] step1 : activate mode disablings for the next mode
                current_event_union = selected_next_mode_event->disable_mode;
                set_disable_mode(current_event_union);

                // [SWS_Rte_07152] step2 : if synchronous, wait until the newly disabled ExecutableEntity are terminatesd
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

                // [SWS_Rte_02587] step10 : trigger the ModeSwitchedAckEvents.
                GetLock(&share_function_lock_q,share_function_lock_bit);
                trigger_event(bsw_event_t03[BswModeSwitchedAckEvent_EV_Engine_ModeSwitchAck_T03]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                GetTaskState(T03, &get_task_state);
                if (get_task_state == SUSPENDED) {
                    ActivateTask(T03);
                }

                schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->switch_status = notSwitch;
                schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->previousmode = schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->currentmode;
                schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->currentmode = schm_mode_group_set_status[ENGINE_MDGROUP_STATUS]->nextmode;

            case onSwitch:
                // check queue capacity
                return_value = (RTE_Enqueue(schm_mode_group_set_queue[BE_ENGINE_MODESWITCH_QUEUE], &mode, sizeof(SchMModeType)) == RTE_E_OK) ? SCHM_E_OK : SCHM_E_LIMIT;
                return return_value;
        }

        // [SWS_Rte_02668] check queue
        return_value = (RTE_Dequeue(schm_mode_group_set_queue[BE_ENGINE_MODESWITCH_QUEUE], &data, sizeof(SchMModeType)) == RTE_E_OK) ? SCHM_E_OK : SCHM_E_NO_DATA;
        if (return_value != SCHM_E_NO_DATA) {
            mode = &data;
        }

    } while (return_value != SCHM_E_NO_DATA);

    return return_value;
}

void SCHM_BE_Engine_ModeSwitch(){
/* The algorithm of BE_Engine_ModeSwitch */
    PrintText("BE_Engine_ModeSwitch\r\n\0");
    SchM_Switch_Bsw1_Engine_Controller_Engine_MDGroup(RTE_MODE_Engine_MDGroup_P);
    return;
}
