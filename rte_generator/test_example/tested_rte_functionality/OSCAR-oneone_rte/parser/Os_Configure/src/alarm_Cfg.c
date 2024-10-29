/*==================[inclusions]=============================================*/
#include "alarm_Cfg.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "application_Cfg.h"
#include "counter_Cfg.h"
#include "scheduleTable_Cfg.h"
/*==================[external data declaration]==============================*/

#pragma section

/* Brief AlarmVar Array */
AlarmVarType AlarmVar_core0[ALARMS_COUNT_CORE0] = {
    /* Alarm alarm8 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm8,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm7 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm7,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm10 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm10,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm6 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm6,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm9 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm9,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm_ST2 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm_ST2,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm_ST3 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm_ST3,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0, /* tick counts to repeat expire after first expire */
    }
};
/* Brief AlarmVar Array */
AlarmVarType AlarmVar_core1[ALARMS_COUNT_CORE1] = {
    /* Alarm alarm4 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm4,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0 /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm1 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm1,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0 /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm2 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm2,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0 /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm3 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm3,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0 /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm5 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm5,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0 /* tick counts to repeat expire after first expire */
    },
    /* Alarm alarm_ST1 */
    {
        NULL, /* pointer to next AlarmVar */
        NULL, /* Pointer to previous AlarmVar */
        alarm_ST1,
        0, /* Inactive */
        0, /* first absolute tick counts to expire */
        0 /* tick counts to repeat expire after first expire */
    }
};
/* Brief AlarmConst Array */
const AlarmConstType AlarmConst_core0[ALARMS_COUNT_CORE0] = {
    /* Alarm alarm6 */
    {
        counter2, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            0, /* no callback */
            T03, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm7 */
    {
        counter2, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            0, /* no callback */
            T01, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm8 */
    {
        counter2, /*counter ID */
        SETEVENT, /* alarm action */
        {
            0, /* no callback */
            T01, /* SetEventTaskID */
            event2, /* event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm9 */
    {
        counter4, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            0, /* no callback */
            T04, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm10 */
    {
        counter4, /*counter ID */
        SETEVENT, /* alarm action */
        {
            0, /* no callback */
            T05, /* SetEventTaskID */
            event1, /* event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm_ST2 */
    {
        counter1, /*counter*/
        EPCALLBACK, /* alarm action */
        {
            0, /* no callback */
            0, /* no task */
            0, /* no event */
            0, /* no counter */
            ST2 /* schduletable */
        }
    },
    /* Alarm alarm_ST3 */
    {
        counter1, /*counter*/
        EPCALLBACK, /* alarm action */
        {
            0, /* no callback */
            0, /* no task */
            0, /* no event */
            0, /* no counter */
            ST3 /* schduletable */
        }
    },
};

/* Brief AlarmConst Array */
const AlarmConstType AlarmConst_core1[ALARMS_COUNT_CORE1] = {
    /* Alarm alarm1 */
    {
        counter1, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T11, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm2 */
    {
        counter1, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T12, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm3 */
    {
        counter1, /*counter ID */
        SETEVENT, /* alarm action */
        {
            NULL, /* no callback */
            T12, /* SetEventTaskID */
            event1, /* event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm4 */
    {
        counter3, /*counter ID */
        SETEVENT, /* alarm action */
        {
            NULL, /* no callback */
            T14, /* SetEventTaskID */
            event2, /* event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm5 */
    {
        counter3, /*counter ID */
        ACTIVATETASK, /* alarm action */
        {
            NULL, /* no callback */
            T16, /* TaskID */
            0, /* no event */
            0, /* no counter */
            0 /* no schduletable */
        }
    },
    /* Alarm alarm_ST1 */
    {
        counter3, /*counter*/
        EPCALLBACK, /* alarm action */
        {
            0, /* no callback */
            0, /* no task */
            0, /* no event */
            0, /* no counter */
            ST1 /* schduletable */
        }
    },
};

AlarmAutosarType AlarmAutosar_core0[ALARMS_COUNT_CORE0] = {
    /* Alarm alarm8 */
    {
        App1,
        0
    },
    /* Alarm alarm7 */
    {
        App1,
        0 | (1 << App2) 
    },
    /* Alarm alarm10 */
    {
        App3,
        0 | (1 << App1) 
    },
    /* Alarm alarm6 */
    {
        App1,
        0
    },
    /* Alarm alarm9 */
    {
        App3,
        0
    },
    /* Alarm alarm_ST2 */
    {
        0
    },
    /* Alarm alarm_ST3 */
    {
        0
    },
};
AlarmAutosarType AlarmAutosar_core1[ALARMS_COUNT_CORE1] = {
    /* Alarm alarm4 */
    {
        App4,
        0 | (1 << App2) | (1 << App3) 
    },
    /* Alarm alarm1 */
    {
        App2,
        0
    },
    /* Alarm alarm2 */
    {
        App2,
        0 | (1 << App1) 
    },
    /* Alarm alarm3 */
    {
        App2,
        0
    },
    /* Alarm alarm5 */
    {
        App4,
        0
    },
    /* Alarm alarm_ST1 */
    {
        0
    },
};
/* Brief AutoStartAlarm Array */
const AutoStartAlarmType AutoStartAlarm_core0[ALARMS_AUTOSTART_COUNT_CORE0] = {
    {
        AppMode1, /* application mode */
        alarm9, /* Alarm */
        100, /* alarm time */
        100, /* cycle time */
    },
};

/* Brief AutoStartAlarm Array */
const AutoStartAlarmType AutoStartAlarm_core1[ALARMS_AUTOSTART_COUNT_CORE1] = {
    {
        AppMode1, /* application mode */
        alarm1, /* Alarm */
        100, /* alarm time */
        0, /* cycle time */
    },
};

#pragma section
