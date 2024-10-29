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
    500000, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* Task T02 */
    {
    EXECUTEBUDGET, // ProtectionType
    100, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL  // *NextTimingCounter
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
    /* Task T03 */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL  // *NextTimingCounter
    },
    /* Task T06 */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I002 Task  */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I003 Task  */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I005 Task  */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I006 Task  */
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
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* Task T02 */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL  // *NextTimingCounter
    },
    /* Task T04 */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* Task T05 */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* Task T03 */
    {
    TIMEFRAME, // ProtectionType
    0, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL  // *NextTimingCounter
    },
    /* Task T06 */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I002 Task  */
    {
    TIMEFRAME, // ProtectionType
    1, // Bound
    1, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I003 Task  */
    {
    TIMEFRAME, // ProtectionType
    1, // Bound
    1, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I005 Task  */
    {
    TIMEFRAME, // ProtectionType
    1, // Bound
    1, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I006 Task  */
    {
    TIMEFRAME, // ProtectionType
    1, // Bound
    1, // Counter
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
        10
    },
    /* OS Interrupt */
    {
        1,
        10
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999,
    }
};

const LockBudgetType LockBudget_T02[6] = {
    /* All Interrupt */
    {
        0,
        20
    },
    /* OS Interrupt */
    {
        1,
        30
    },
    /* resource resource1 */
    {
        resource1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resource3 */
    {
        resource3,
        10
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999,
    },
};

const LockBudgetType LockBudget_T03[3] = {
    /* All Interrupt */
    {
        0,
        20
    },
    /* OS Interrupt */
    {
        1,
        40
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999,
    },
};

const LockBudgetType LockBudget_T04[3] = {
    /* All Interrupt */
    {
        0,
        20
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resourceApp3 */
    {
        resourceApp3,
        99999,
    },
};

const LockBudgetType LockBudget_T05[6] = {
    /* All Interrupt */
    {
        0,
        30
    },
    /* OS Interrupt */
    {
        1,
        30
    },
    /* resource resource1 */
    {
        resource1,
        30
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resource3 */
    {
        resource3,
        10
    },
    /* resource resourceApp3 */
    {
        resourceApp3,
        99999,
    },
};

const LockBudgetType LockBudget_T06[3] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resourceApp3 */
    {
        resourceApp3,
        99999,
    },
};

const LockBudgetType LockBudget_I002[4] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999,
    },
};

const LockBudgetType LockBudget_I003[4] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resourceApp1 */
    {
        resourceApp1,
        99999,
    },
};

const LockBudgetType LockBudget_I005[4] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resourceApp3 */
    {
        resourceApp3,
        99999,
    },
};

const LockBudgetType LockBudget_I006[4] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resourceApp3 */
    {
        resourceApp3,
        99999,
    },
};

const TimingProtBudgetType TimingProtBudget_core0[TASK_OBJECTS_COUNT_CORE0] = {
    /* idle task */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        NULL /* LockBudgetRef */
    },
    /* Task01 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T01 /* LockBudgetRef */
    },
    /* Task02 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T02 /* LockBudgetRef */
    },
    /* Task04 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T04 /* LockBudgetRef */
    },
    /* Task05 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T05 /* LockBudgetRef */
    },
    /* Task03 */
    {
        999, /* ExecuteBudget */
        0, /* TimeFrame */
        LockBudget_T03 /* LockBudgetRef */
    },
    /* Task06 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T06 /* LockBudgetRef */
    },
    /* isr I002 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I002 /* LockBudgetRef */
    },
    /* isr I003 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I003 /* LockBudgetRef */
    },
    /* isr I005 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I005 /* LockBudgetRef */
    },
    /* isr I006 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
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
    500000, // Bound
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
    NULL  // *NextTimingCounter
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
    /* Task T13 */
    {
    EXECUTEBUDGET, // ProtectionType
    1000, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL  // *NextTimingCounter
    },
    /* Task T16 */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I002 Task  */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I003 Task  */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I005 Task  */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I006 Task  */
    {
    EXECUTEBUDGET, // ProtectionType
    0, // Bound
    0, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },

};

TimingProtCounterType TaskArrivalCounter_core1[TASK_OBJECTS_COUNT_CORE1] = {
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
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* Task T14 */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL  // *NextTimingCounter
    },
    /* Task T13 */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* Task T15 */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* Task T12 */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL  // *NextTimingCounter
    },
    /* Task T16 */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I002 Task  */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I003 Task  */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I005 Task  */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
    /* isr I006 Task  */
    {
    TIMEFRAME, // ProtectionType
    20, // Bound
    20, // Counter
    NULL, // *PreTimgingCounter
    NULL // *NextTimingCounter
    },
};

TimingProtCounterType ResourceTimingCounter_core1[RESOURCES_COUNT_CORE1];

TimingProtCounterType InterruptTimingCounter_core1[3];

const LockBudgetType LockBudget_T11[3] = {
    /* All Interrupt */
    {
        0,
        20
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999,
    },
};

const LockBudgetType LockBudget_T12[3] = {
    /* All Interrupt */
    {
        0,
        20
    },
    /* OS Interrupt */
    {
        1,
        40
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999,
    },
};

const LockBudgetType LockBudget_T13[6] = {
    /* All Interrupt */
    {
        0,
        20
    },
    /* OS Interrupt */
    {
        1,
        30
    },
    /* resource resource1 */
    {
        resource1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resource3 */
    {
        resource3,
        10
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999,
    },
};

const LockBudgetType LockBudget_T14[3] = {
    /* All Interrupt */
    {
        0,
        20
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999,
    },
};

const LockBudgetType LockBudget_T15[3] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resourceApp2 */
    {
        resourceApp4,
        99999,
    },
};

const LockBudgetType LockBudget_T16[6] = {
    /* All Interrupt */
    {
        0,
        30
    },
    /* OS Interrupt */
    {
        1,
        30
    },
    /* resource resource1 */
    {
        resource1,
        30
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resource3 */
    {
        resource3,
        10
    },
    /* resource resourceApp4 */
    {
        resourceApp4,
        99999,
    },
};

const LockBudgetType LockBudget_I102[4] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999,
    },
};

const LockBudgetType LockBudget_I103[4] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resourceApp2 */
    {
        resourceApp2,
        99999,
    },
};

const LockBudgetType LockBudget_I105[4] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resourceApp4 */
    {
        resourceApp4,
        99999,
    },
};

const LockBudgetType LockBudget_I106[4] = {
    /* All Interrupt */
    {
        0,
        10
    },
    /* OS Interrupt */
    {
        1,
        20
    },
    /* resource resource2 */
    {
        resource2,
        30
    },
    /* resource resourceApp4 */
    {
        resourceApp4,
        99999,
    },
};

const TimingProtBudgetType TimingProtBudget_core1[TASK_OBJECTS_COUNT_CORE1] = {
    /* idle task */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        NULL /* LockBudgetRef */
    },
    /* Task11 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T11 /* LockBudgetRef */
    },
    /* Task14 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T14 /* LockBudgetRef */
    },
    /* Task12 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T12 /* LockBudgetRef */
    },
    /* Task13 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T13 /* LockBudgetRef */
    },
    /* Task15 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T15 /* LockBudgetRef */
    },
    /* Task16 */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_T16 /* LockBudgetRef */
    },
    /* isr I102 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I102 /* LockBudgetRef */
    },
    /* isr I103 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I103 /* LockBudgetRef */
    },
    /* isr I105 Task  */
    {
        999, /* ExecuteBudget */
        1, /* TimeFrame */
        LockBudget_I105 /* LockBudgetRef */
    },
    /* isr I106 Task  */
    {
        999, /* ExecuteBudget */
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