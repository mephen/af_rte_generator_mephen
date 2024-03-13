/*==================[inclusions]=============================================*/
#include "counter_Cfg.h"
#include "os_Cfg.h"
#include "application_Cfg.h"

#pragma section

/* Brief CounterVar Array */
CounterVarType CounterVar_core0[COUNTERS_COUNT_CORE0] = {
    /* Counter counter2 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0 /* current counter count */
    },
    /* Counter counter4 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0 /* current counter count */
    },
    /* Counter counter_ST2 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0 /* current counter count */
    },
    /* Counter counter_ST3 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0 /* current counter count */
    },
};
/* Brief CounterVar Array */
CounterVarType CounterVar_core1[COUNTERS_COUNT_CORE1] = {
    /* Counter counter1 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0 /* current counter count */
    },
    /* Counter counter3 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0 /* current counter count */
    },
    /* Counter counter_ST1 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0 /* current counter count */
    },
};

/* Brief CounterConst Array */
const CounterConstType CounterConst_core0[COUNTERS_COUNT_CORE0] = {
    /* Counter counter2 */
    {
        500, /* maximum value of counter */
        10, /* minimum count for a cyclic alarm linked to the counter */
        10, /* the number of hardware ticks to count once */
        HARDWARE /* osCounterType */
    },
    /* Counter counter4 */
    {
        500, /* maximum value of counter */
        10, /* minimum count for a cyclic alarm linked to the counter */
        10, /* the number of hardware ticks to count once */
        HARDWARE /* osCounterType */
    },
    /* Counter counter_ST2 */
    {
        False, /* maximum value of counter */
        False, /* minimum count for a cyclic alarm linked to the counter */
        False, /* the number of hardware ticks to count once */
        False /* osCounterType */
    },
    /* Counter counter_ST3 */
    {
        False, /* maximum value of counter */
        False, /* minimum count for a cyclic alarm linked to the counter */
        False, /* the number of hardware ticks to count once */
        False /* osCounterType */
    },
};
/* Brief CounterConst Array */
const CounterConstType CounterConst_core1[COUNTERS_COUNT_CORE1] = {
    /* Counter counter1 */
    {
        500, /* maximum value of counter */
        10, /* minimum count for a cyclic alarm linked to the counter */
        10, /* the number of hardware ticks to count once */
        HARDWARE /* osCounterType */
    },
    /* Counter counter3 */
    {
        500, /* maximum value of counter */
        10, /* minimum count for a cyclic alarm linked to the counter */
        10, /* the number of hardware ticks to count once */
        HARDWARE /* osCounterType */
    },
    /* Counter counter_ST1 */
    {
        False, /* maximum value of counter */
        False, /* minimum count for a cyclic alarm linked to the counter */
        False, /* the number of hardware ticks to count once */
        False /* osCounterType */
    },
};
CounterAutosarType CounterAutosar_core0[COUNTERS_COUNT_CORE0] = {
    /* Counter counter2 */
    {
        App1, /* owner application of the counter */
        0 | (1 << App1), /* application mask */
    },
    /* Counter counter4 */
    {
        App3, /* owner application of the counter */
        0 | (1 << App3), /* application mask */
    },
    /* Counter counter_ST2 */
    {
    },
    /* Counter counter_ST3 */
    {
    },
};
CounterAutosarType CounterAutosar_core1[COUNTERS_COUNT_CORE1] = {
    /* Counter counter1 */
    {
        App2, /* owner application of the counter */
        0 | (1 << App2), /* application mask */
    },
    /* Counter counter3 */
    {
        App4, /* owner application of the counter */
        0 | (1 << App4), /* application mask */
    },
    /* Counter counter_ST1 */
    {
    },
};
#pragma section
