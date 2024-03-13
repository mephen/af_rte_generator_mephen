/*==================[inclusions]=============================================*/
#include "os_Cfg.h"
#include "application_Cfg.h"
#include "softwaretimer_Cfg.h"
#include "counter_Cfg.h"
#pragma section
/*==================[macros]=================================================*/
uint32 HARDWARETIMER_PERIOD[OsNumberOfCores] = {
    1, /* 1ms */
    1, /* 1ms */
};
CounterType CounterList_1[COUNTERS_COUNT_COUNTERLIST_1] = {
    counter2,
    counter4,
    counter_ST2,
    counter_ST3,
};
CounterType CounterList_2[COUNTERS_COUNT_COUNTERLIST_2] = {
    counter1,
    counter3,
    counter_ST1,
};
SoftwareTimerVarType SoftwareTimerVar_core0[SOFTWARETIMERS_COUNT_CORE0] = {
    /* SoftwareTimer softwaretimer1 */
    {
        0, /* current ticks */
        0, /* current counts */
    },
};
SoftwareTimerVarType SoftwareTimerVar_core1[SOFTWARETIMERS_COUNT_CORE1] = {
    /* SoftwareTimer softwaretimer2 */
    {
        0, /* current ticks */
        0, /* current counts */
    },
};
const SoftwareTimerConstType SoftwareTimerConst_core0[SOFTWARETIMERS_COUNT_CORE0] = {
    /* SoftwareTimer softwaretimer1 */
    {
        1000, /* maximum value of softwaretimer */
        1, /* the number of hardware ticks to count once */
        CounterList_1,  /* counter list */
        0 /* counter list length*/
    },
};
const SoftwareTimerConstType SoftwareTimerConst_core1[SOFTWARETIMERS_COUNT_CORE1] = {
    /* SoftwareTimer softwaretimer2 */
    {
        1000, /* maximum value of softwaretimer */
        1, /* the number of hardware ticks to count once */
        CounterList_2,  /* counter list */
        0 /* counter list length*/
    },
};
#pragma section
