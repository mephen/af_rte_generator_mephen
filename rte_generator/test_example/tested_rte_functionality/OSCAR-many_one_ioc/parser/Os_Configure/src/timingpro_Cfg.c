#include "typedefine.h"
#include "timingprot_Cfg.h"

#pragma section

/** core 0 **/
TimingProtCounterType TaskExecutingCounter_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* Task IdleTask */
    {
        IDLETASKBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T01 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T02 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T03 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T04 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T05 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T06 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I005 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I006 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
};

TimingProtCounterType TaskArrivalCounter_core0[TASK_OBJECTS_COUNT_CORE0] ={
    /* Task IdleTask */
    {
        IDLETASKBUDGET, // ProtectionType
        1, // Bound
        1, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T01 */
    {
        TIMEFRAME, // ProtectionType
        1.01, // Bound
        1.01, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T02 */
    {
        TIMEFRAME, // ProtectionType
        1.02, // Bound
        1.02, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T03 */
    {
        TIMEFRAME, // ProtectionType
        1.02, // Bound
        1.02, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T04 */
    {
        TIMEFRAME, // ProtectionType
        1.03, // Bound
        1.03, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T05 */
    {
        TIMEFRAME, // ProtectionType
        1.04, // Bound
        1.04, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T06 */
    {
        TIMEFRAME, // ProtectionType
        1.02, // Bound
        1.02, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I005 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I006 Task*/
    {
        TIMEFRAME, // ProtectionType
        1.02, // Bound
        1.02, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
};

TimingProtCounterType ResourceTimingCounter_core0[RESOURCES_COUNT_CORE0];
TimingProtCounterType InterruptTimingCounter_core0[3];

const LockBudgetType LockBudget_T01[3] = {
    /* All Interrupt */
    {
        0,
        0.02
    },
    /* OS Interrupt */
    {
        1,
        0.02
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999
    },
};
const LockBudgetType LockBudget_T02[6] = {
    /* All Interrupt */
    {
        0,
        0.02
    },
    /* OS Interrupt */
    {
        1,
        0.02
    },
    /* resource resource1 */
    {
        resource1,
        0.02,
    },
    /* resource resource2 */
    {
        resource2,
        0.03,
    },
    /* resource resource3 */
    {
        resource3,
        0.01,
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999
    },
};
const LockBudgetType LockBudget_T03[3] = {
    /* All Interrupt */
    {
        0,
        0.02
    },
    /* OS Interrupt */
    {
        1,
        0.02
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999
    },
};
const LockBudgetType LockBudget_T04[3] = {
    /* All Interrupt */
    {
        0,
        0.02
    },
    /* OS Interrupt */
    {
        1,
        0.02
    },
    /* resource resourceApp3 */
    {
        resourceApp3,
        99999
    },
};
const LockBudgetType LockBudget_T05[6] = {
    /* All Interrupt */
    {
        0,
        0.03
    },
    /* OS Interrupt */
    {
        1,
        0.03
    },
    /* resource resource1 */
    {
        resource1,
        0.03,
    },
    /* resource resource2 */
    {
        resource2,
        0.03,
    },
    /* resource resource3 */
    {
        resource3,
        0.01,
    },
    /* resource resourceApp3 */
    {
        resourceApp3,
        99999
    },
};
const LockBudgetType LockBudget_T06[3] = {
    /* All Interrupt */
    {
        0,
        0.01
    },
    /* OS Interrupt */
    {
        1,
        0.01
    },
    /* resource resourceApp3 */
    {
        resourceApp3,
        99999
    },
};
const LockBudgetType LockBudget_I005[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999
    },
};
const LockBudgetType LockBudget_I006[6] = {
    /* All Interrupt */
    {
        0,
        0.03
    },
    /* OS Interrupt */
    {
        1,
        0.03
    },
    /* resource resource4 */
    {
        resource4,
        0.03,
    },
    /* resource resource5 */
    {
        resource5,
        0.03,
    },
    /* resource resource6 */
    {
        resource6,
        0.01,
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999
    },
};
const TimingProtBudgetType TimingProtBudget_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* idle task */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        NULL /* LockBudgetRef */
    },
    /* Task_T01 */
    {
        0.05, /* ExecuteBudget */
        0.01, /* TimeFrame */
        LockBudget_T01 /* LockBudgetRef */
    },
    /* Task_T02 */
    {
        0.05, /* ExecuteBudget */
        0.02, /* TimeFrame */
        LockBudget_T02 /* LockBudgetRef */
    },
    /* Task_T03 */
    {
        0.05, /* ExecuteBudget */
        0.02, /* TimeFrame */
        LockBudget_T03 /* LockBudgetRef */
    },
    /* Task_T04 */
    {
        0.05, /* ExecuteBudget */
        0.03, /* TimeFrame */
        LockBudget_T04 /* LockBudgetRef */
    },
    /* Task_T05 */
    {
        0.05, /* ExecuteBudget */
        0.04, /* TimeFrame */
        LockBudget_T05 /* LockBudgetRef */
    },
    /* Task_T06 */
    {
        0.05, /* ExecuteBudget */
        0.02, /* TimeFrame */
        LockBudget_T06 /* LockBudgetRef */
    },
    /* isr I005 Task  */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I005 /* LockBudgetRef */
    },
    /* isr I006 Task  */
    {
        0.05, /* ExecuteBudget */
        0.02, /* TimeFrame */
        LockBudget_I006 /* LockBudgetRef */
    },
};

/** core 1 **/
TimingProtCounterType TaskExecutingCounter_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* Task IdleTask */
    {
        IDLETASKBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T11 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T12 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T13 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T14 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T15 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T16 */
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I105 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I106 Task*/
    {
        EXECUTEBUDGET, // ProtectionType
        0, // Bound
        0, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
};

TimingProtCounterType TaskArrivalCounter_core1[TASK_OBJECTS_COUNT_CORE1] ={
    /* Task IdleTask */
    {
        IDLETASKBUDGET, // ProtectionType
        1, // Bound
        1, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T11 */
    {
        TIMEFRAME, // ProtectionType
        1.01, // Bound
        1.01, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T12 */
    {
        TIMEFRAME, // ProtectionType
        1.03, // Bound
        1.03, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T13 */
    {
        TIMEFRAME, // ProtectionType
        1.04, // Bound
        1.04, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T14 */
    {
        TIMEFRAME, // ProtectionType
        1.02, // Bound
        1.02, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T15 */
    {
        TIMEFRAME, // ProtectionType
        1.02, // Bound
        1.02, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Task T16 */
    {
        TIMEFRAME, // ProtectionType
        1.02, // Bound
        1.02, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I105 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
    /* Isr I106 Task*/
    {
        TIMEFRAME, // ProtectionType
        10000, // Bound
        10000, // Counter
        NULL, // *PreTimgingCounter
        NULL // *NextTimingCounter
    },
};

TimingProtCounterType ResourceTimingCounter_core1[RESOURCES_COUNT_CORE0];
TimingProtCounterType InterruptTimingCounter_core1[3];

const LockBudgetType LockBudget_T11[3] = {
    /* All Interrupt */
    {
        0,
        0.02
    },
    /* OS Interrupt */
    {
        1,
        0.02
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999
    },
};
const LockBudgetType LockBudget_T12[3] = {
    /* All Interrupt */
    {
        0,
        0.02
    },
    /* OS Interrupt */
    {
        1,
        0.02
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999
    },
};
const LockBudgetType LockBudget_T13[6] = {
    /* All Interrupt */
    {
        0,
        0.02
    },
    /* OS Interrupt */
    {
        1,
        0.02
    },
    /* resource resource4 */
    {
        resource4,
        0.02,
    },
    /* resource resource5 */
    {
        resource5,
        0.03,
    },
    /* resource resource6 */
    {
        resource6,
        0.01,
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999
    },
};
const LockBudgetType LockBudget_T14[3] = {
    /* All Interrupt */
    {
        0,
        0.02
    },
    /* OS Interrupt */
    {
        1,
        0.02
    },
    /* resource resourceApp4 */
    {
        resourceApp4,
        99999
    },
};
const LockBudgetType LockBudget_T15[3] = {
    /* All Interrupt */
    {
        0,
        0.01
    },
    /* OS Interrupt */
    {
        1,
        0.01
    },
    /* resource resourceApp4 */
    {
        resourceApp4,
        99999
    },
};
const LockBudgetType LockBudget_T16[6] = {
    /* All Interrupt */
    {
        0,
        0.03
    },
    /* OS Interrupt */
    {
        1,
        0.03
    },
    /* resource resource4 */
    {
        resource4,
        0.03,
    },
    /* resource resource5 */
    {
        resource5,
        0.03,
    },
    /* resource resource6 */
    {
        resource6,
        0.01,
    },
    /* resource resourceApp4 */
    {
        resourceApp4,
        99999
    },
};
const LockBudgetType LockBudget_I105[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999
    },
};
const LockBudgetType LockBudget_I106[3] = {
    /* All Interrupt */
    {
        0,
        10000
    },
    /* OS Interrupt */
    {
        1,
        10000
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999
    },
};
const TimingProtBudgetType TimingProtBudget_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* idle task */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        NULL /* LockBudgetRef */
    },
    /* Task_T11 */
    {
        0.05, /* ExecuteBudget */
        0.01, /* TimeFrame */
        LockBudget_T11 /* LockBudgetRef */
    },
    /* Task_T12 */
    {
        0.05, /* ExecuteBudget */
        0.03, /* TimeFrame */
        LockBudget_T12 /* LockBudgetRef */
    },
    /* Task_T13 */
    {
        0.05, /* ExecuteBudget */
        0.04, /* TimeFrame */
        LockBudget_T13 /* LockBudgetRef */
    },
    /* Task_T14 */
    {
        0.05, /* ExecuteBudget */
        0.02, /* TimeFrame */
        LockBudget_T14 /* LockBudgetRef */
    },
    /* Task_T15 */
    {
        0.05, /* ExecuteBudget */
        0.02, /* TimeFrame */
        LockBudget_T15 /* LockBudgetRef */
    },
    /* Task_T16 */
    {
        0.05, /* ExecuteBudget */
        0.02, /* TimeFrame */
        LockBudget_T16 /* LockBudgetRef */
    },
    /* isr I105 Task  */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I105 /* LockBudgetRef */
    },
    /* isr I106 Task  */
    {
        10000, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I106 /* LockBudgetRef */
    },
};

/** system **/

TimingProtCounterType *TimingCounterList[OsNumberOfCores];
SystemTimingCounterType SystemTimingCounter[OsNumberOfCores] = {
    /* Core 0 */
    {
        TaskExecutingCounter_core0,
        TaskArrivalCounter_core0,
        ResourceTimingCounter_core0,
        InterruptTimingCounter_core0,
        TimingProtBudget_core0
    },
    /* Core 1 */
    {
        TaskExecutingCounter_core1,
        TaskArrivalCounter_core1,
        ResourceTimingCounter_core1,
        InterruptTimingCounter_core1,
        TimingProtBudget_core1
    }
};

#pragma section
