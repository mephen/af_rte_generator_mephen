#include "os_Cfg.h"
#include "application_Cfg.h"
#include "softwaretimer_Cfg.h"
#include "counter_Cfg.h"
#pragma section 


uint32 HARDWARETIMER_PERIOD[OsNumberOfCores] = {
    1, /* 1ms */
    1, /* 1ms */
};

CounterType CounterList_1[COUNTERS_COUNT_COUNTERLIST_1] = {
    counter3,
    counter4,
};

CounterType CounterList_2[COUNTERS_COUNT_COUNTERLIST_2] = {
    counter1,
    counter2,
};

SoftwareTimerVarType SoftwareTimerVar_core0[SOFTWARETIMERS_COUNT_CORE0] ={
    /* SoftwareTimer softwaretimer1 */
    {
        0, /* current ticks */
        0, /* current counts */
    },
    /* SoftwareTimer softwaretimer2 */
    {
        0, /* current ticks */
        0, /* current counts */
    },
};



SoftwareTimerVarType SoftwareTimerVar_core1[SOFTWARETIMERS_COUNT_CORE1] ={
    /* SoftwareTimer softwaretimer3 */
    {
        0, /* current ticks */
        0, /* current counts */
    },
    /* SoftwareTimer softwaretimer4 */
    {
        0, /* current ticks */
        0, /* current counts */
    },
};


const SoftwareTimerConstType SoftwareTimerConst_core0[SOFTWARETIMERS_COUNT_CORE0] ={
    /* SoftwareTimer softwaretimer1 */
    {
        1000, /* maximum value of softwaretimer */
        1, /* the number of hardware ticks to count once */
        CounterList_1,  /* counter list */
        COUNTERS_COUNT_COUNTERLIST_1, /* counter list length*/
    },
    /* SoftwareTimer softwaretimer2 */
    {
        1000, /* maximum value of softwaretimer */
        2, /* the number of hardware ticks to count once */
        NULL, /* counter list */
        0, /* counter list length*/
    }
};


const SoftwareTimerConstType SoftwareTimerConst_core1[SOFTWARETIMERS_COUNT_CORE1] ={
    /* SoftwareTimer softwaretimer1 */
    {
        1000, /* maximum value of softwaretimer */
        1, /* the number of hardware ticks to count once */
        CounterList_2, /* counter list */
        COUNTERS_COUNT_COUNTERLIST_2, /* counter list length*/
    },
    /* SoftwareTimer softwaretimer2 */
    {
        1000, /* maximum value of softwaretimer */
        2, /* the number of hardware ticks to count once */
        NULL, /* counter list */
        0 /* counter list length*/
    }
};



#pragma section
