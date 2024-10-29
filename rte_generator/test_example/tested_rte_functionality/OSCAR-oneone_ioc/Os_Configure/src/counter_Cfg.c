/*==================[inclusions]=============================================*/
#include "counter_Cfg.h"
#include "os_Cfg.h"
#include "application_Cfg.h"

#pragma section 

/* Brief CounterVar Array */
CounterVarType CounterVar_core0[COUNTERS_COUNT_CORE0] = {
    /* Counter counter3 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0, /* current counter count */
    },
    /* Counter counter4 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0, /* current counter count */
    },
};

/* Brief CounterVar Array */
CounterVarType CounterVar_core1[COUNTERS_COUNT_CORE1] = {
    /* Counter counter1 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0, /* current counter count */
    },
    /* Counter counter2 */
    {
        NULL, /* pointer to first alarm ready list */
        NULL, /* pointer to next alarm to raise */
        0, /* current system ticks since last count*/
        0, /* current counter count */
    }
};

/* Brief CounterConst Array */
const CounterConstType CounterConst_core0[COUNTERS_COUNT_CORE0] = {
    /* Counter counter3 */
    {
        294967295, /* maximum value of counter */
        1, /* minimum count for a cyclic alarm linked to the counter */
        1, /* the number of hardware ticks to count once */
        HARDWARE, /* osCounterType */
    },
    /* Counter counter4 */
    {
        500, /* maximum value of counter */
        10, /* minimum count for a cyclic alarm linked to the counter */
        10, /* the number of hardware ticks to count once */
        SOFTWARE, /* osCounterType */
    }
};

/* Brief CounterConst Array */
const CounterConstType CounterConst_core1[COUNTERS_COUNT_CORE1] = {
    /* Counter counter1 */
    {
        100, /* maximum value of counter */
        2, /* minimum count for a cyclic alarm linked to the counter */
        10, /* the number of hardware ticks to count once */
        HARDWARE, /* osCounterType */
    },
    /* Counter counter2 */
    {
        500, /* maximum value of counter */
        10, /* minimum count for a cyclic alarm linked to the counter */
        10, /* the number of hardware ticks to count once */
        SOFTWARE, /* osCounterType */
    }
};

CounterAutosarType CounterAutosar_core0[COUNTERS_COUNT_CORE0] = {
    /* Counter counter3 */
    {
        app_lion, /* owner application of the counter */
        0 | (1 << app_lion) /* application mask */
    },
    /* Counter counter4 */
    {
        app3, /* owner application of the counter */
        0 | (1 << app3) /* application mask */
    },
    
};

CounterAutosarType CounterAutosar_core1[COUNTERS_COUNT_CORE1] = {
    /* Counter counter1 */
    {
        app2, /* owner application of the counter */
        0 | (1 << app2) /* application mask */
    },
    /* Counter counter2 */
    {
        app4, /* owner application of the counter */
        0 | (1 << app4) /* application mask */
    }
};

#pragma section