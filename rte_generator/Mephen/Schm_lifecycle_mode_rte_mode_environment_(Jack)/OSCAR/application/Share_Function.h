#include "SchM_Mode_Data_Management_Cfg.h"
#include "SchM_Client_Server_Data_Management_Cfg.h"
#include "Bsw_Event_Cfg.h"
#include "Rte_Event_Cfg.h"
#include "../device/lock.h"
#include "SchM.h"
#include "../Os_Configure/inc/alarm_Cfg.h"
#include "../Os_Configure/inc/task_Cfg.h"
#include "../Os_Configure/inc/event_Cfg.h"
#include "../../kernel/os.h"

#define N 20

typedef struct {
    Event *event_ptr[N];
    void (*func_ptr[N])(void); //for direct function call
    int task[N]; //It's NULL when RteMappedToTaskRef of this event is defined
    int num; //entity number. It's 0 in direct function call situation
} ModeEventInfo;

typedef struct {
    Event *event_ptr;
    void (*event_func_ptr)(void);
    int event_task;
    int period_multiple; // timing event period is several times of gcd
} TimingEventInfo;

typedef struct {
    Event *event_ptr[N];
    void (*func_ptr[N])(void);
    int task[N];
} TriggerEventInfo;

typedef struct {
    ModeEventInfo *on_exit;
    ModeEventInfo *on_entry;
    ModeEventInfo *on_transition;
    ModeEventInfo *disable_mode;
} ModeEvents;

extern void activate_task(ModeEventInfo *current_event_union);
extern void set_disable_mode (ModeEventInfo *current_event_union);
extern void clear_disable_mode (ModeEventInfo *current_event_union);
extern void set_event (ModeEventInfo *current_event_union);
extern void wait_executed_finish (ModeEventInfo *current_event_union);

extern void core0_period_counter();
extern void core1_period_counter();

#define get_event_counter(event) event->status_uint16 & 0x0F
#define trigger_event(event) \
    if ((event->status_uint16 & 0x0F) == 0x0F) { \
        event->status_uint16 &= 0xFFF0;\
    } else { \
        event->status_uint16 += 1; \
    }
#define release_event(event) \
    if ((event->status_uint16 & 0x0F) == 0x00) { \
        event->status_uint16 &= 0xFFF0;\
    } else { \
    event->status_uint16 -= 1; \
    }

#define get_event_type(event) (event->status_uint16 & 0x1F0)

#define get_event_disablemode(event) (event->status_uint16 & 0x200) >> 9
#define set_event_disablemode(event) event->status_uint16 |= 0x200
#define clear_event_disablemode(event) event->status_uint16 &= ~(0x200)

#define get_entity_execute(event) (event->status_uint16 & 0x400) >> 10
#define set_entity_execute(event) event->status_uint16 |= 0x400
#define clear_entity_execute(event) event->status_uint16 &= ~(0x400)

//BswTimingEvent
#define ClientRunnable 0x1800
#define get_trigger_runnable_type(event) (event->status_uint16 & 0x1800)

//OperationInvokedEvent specific status: 11th-12th bit for communication type.(bit start from 0)
#define InterEcu 0x0000
#define InterPartition 0x800
#define IntraPartition 0x1000
#define get_communication_type(event) (event->status_uint16 & 0x1800)

extern uint32 share_function_lock_q;
extern uint32 share_function_lock_bit;

extern uint32 schm_not_init;
extern uint32 schm_stop;

extern int count_0;
extern int count_1;
extern int init_flag_0;
extern int init_flag_1;
extern int dinit_flag;
extern int modes_witch_count;
extern int mode_mamager_wakeup_count;

// client-server for core0
// client-server for core1

