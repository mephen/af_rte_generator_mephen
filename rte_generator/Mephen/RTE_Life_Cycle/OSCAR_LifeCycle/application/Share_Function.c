#include "Share_Function.h"
// #include "Rte_Event_Cfg.h"

uint32 share_function_lock_q = 0;
uint32 share_function_lock_bit = 1;
uint32 schm_not_init = 0;
uint32 schm_stop = 0;

int count_0 = 0;
int count_1 = 0;
int init_flag_0 = 0;
int init_flag_1 = 0;
int dinit_flag = 0;
int modes_witch_count = 0;
int mode_mamager_wakeup_count = 0;

void activate_task(ModeEventInfo *current_event_union){
    TaskStateType get_task_state;
    int p = 0;
    int *act_task = current_event_union->task;
    while(*act_task != NULL && p != -1){
        if (act_task[p] != NULL) {
            GetTaskState(act_task[p], &get_task_state);
            if (get_task_state == SUSPENDED) {
                ActivateTask(act_task[p]);
            }
            p++;
        } else {
            p = -1;
        }
    }
    p = 0;
    while(current_event_union->func_ptr != NULL && p != -1) {
        if (current_event_union->func_ptr[p] != NULL) {
            current_event_union->func_ptr[p]();
            p++;
        } else {
            p = -1;
        }
    }
}

void set_disable_mode (ModeEventInfo *current_event_union) {
    if (current_event_union != NULL) {
        Event **event_ptrs = current_event_union->event_ptr;
        int p = 0;
        GetLock(&share_function_lock_q,share_function_lock_bit);
        while(*event_ptrs != NULL && p != -1) {
            Event **current_event_ptr = event_ptrs[p];
            if (current_event_ptr != NULL) {
                Event *current_event = *current_event_ptr;
                set_event_disablemode(current_event);
                p++;
            } else {
                p = -1;
            }
        }
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    }
}

void clear_disable_mode (ModeEventInfo *current_event_union) {
    if (current_event_union != NULL) {
        Event **event_ptrs = current_event_union->event_ptr;
        int p = 0;
        GetLock(&share_function_lock_q,share_function_lock_bit);
        while(*event_ptrs != NULL && p != -1) {
            Event **current_event_ptr = event_ptrs[p];
            if (current_event_ptr != NULL) {
                Event *current_event = *current_event_ptr;
                clear_event_disablemode(current_event);
                p++;
            } else {
                p = -1;
            }
        }
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    }
}

void set_event (ModeEventInfo *current_event_union) {
    if (current_event_union != NULL) {
        Event **event_ptrs = current_event_union->event_ptr;
        int p = 0;
        GetLock(&share_function_lock_q,share_function_lock_bit);
        while(*event_ptrs != NULL && p != -1) {
            Event **current_event_ptr = event_ptrs[p];
            if (current_event_ptr != NULL) {
                Event *current_event = *current_event_ptr;
                trigger_event(current_event);
                p++;
            } else {
                p = -1;
            }
        }
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    }
}

void wait_executed_finish (ModeEventInfo *current_event_union) {
    if (current_event_union != NULL) {
        Event **event_ptrs = current_event_union->event_ptr;
        int p = 0;
        while(*event_ptrs != NULL && p != -1) {
            Event **current_event_ptr = event_ptrs[p];
            if (current_event_ptr != NULL) {
                Event *current_event = *current_event_ptr;
                while (get_entity_execute(current_event) != 0 ) {}
                p++;
            } else {
                p = -1;
            }
        }
    }
}

TimingEventInfo RteTimingEvent_1_info = {
    .event_ptr = &RteTimingEvent_1,
    .event_func_ptr = NULL,
    .event_task = NULL,
    .period_multiple = 2,
};

#define TimingEventCore0_ArraySize 1
TimingEventInfo *TimingEventCore0[TimingEventCore0_ArraySize] = {&RteTimingEvent_1_info};

#define TimingEventCore1_ArraySize 0
TimingEventInfo *TimingEventCore1;

// core0 period counter(gcd)
void core0_period_counter(){
    TaskStateType get_task_state;
    count_0++;
    for (int i=0 ; i<TimingEventCore0_ArraySize ; i++ ){
        if (count_0 % TimingEventCore0[i]->period_multiple == 0 && dinit_flag == 0) {
            if (TimingEventCore0[i]->event_func_ptr == NULL) {
                GetLock(&share_function_lock_q,share_function_lock_bit);
                trigger_event(TimingEventCore0[i]->event_ptr);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                
                //avoid multiple activation of the same task
                if (TimingEventCore0[i]->event_task != NULL) { 
                    GetTaskState(TimingEventCore0[i]->event_task, &get_task_state);
                    if (get_task_state == SUSPENDED) {
                        ActivateTask(TimingEventCore0[i]->event_task);
                    }
                }
            } else { //direct fn. call
                TimingEventCore0[i]->event_func_ptr();
            }
        }
    }
}

// core1 period counter(gcd)
/*
void core1_period_counter(){
    TaskStateType get_task_state;
    count_1++;
    for (int i=0 ; i<TimingEventCore1_ArraySize ; i++ ){
        if (count_1 % TimingEventCore1[i]->period_multiple == 0 && dinit_flag == 0) {
            if (TimingEventCore1[i]->event_func_ptr == NULL) {
                GetLock(&share_function_lock_q,share_function_lock_bit);
                trigger_event(TimingEventCore1[i]->event_ptr);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                if (TimingEventCore1[i]->event_task != NULL) {
                    GetTaskState(TimingEventCore1[i]->event_task, &get_task_state);
                    if (get_task_state == SUSPENDED) {
                        ActivateTask(TimingEventCore1[i]->event_task);
                    }
                }
            } else {
                TimingEventCore1[i]->event_func_ptr();
            }
        }
    }
}
*/