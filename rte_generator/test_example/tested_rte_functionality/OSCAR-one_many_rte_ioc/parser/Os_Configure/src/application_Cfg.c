/*==================[inclusions]=============================================*/
#include "application_Cfg.h"
#include "task_Cfg.h"
#include "os_Cfg.h"
#include "alarm_Cfg.h"
#include "counter.h"
#include "scheduletable_Cfg.h"
#include "isr_Cfg.h"
#include "trustedFunc_Cfg.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "resource_Cfg.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[external functions declaration]=========================*/

/* Brief per-OsApp Hook */
extern void StartupHook_OSAPP_App1(void);
extern void ShutdownHook_OSAPP_App1(StatusType Error);
extern void ErrorHook_OSAPP_App1(StatusType Error);

extern void StartupHook_OSAPP_App2(void);
extern void ShutdownHook_OSAPP_App2(StatusType Error);
extern void ErrorHook_OSAPP_App2(StatusType Error);

extern void StartupHook_OSAPP_App3(void);
extern void ShutdownHook_OSAPP_App3(StatusType Error);
extern void ErrorHook_OSAPP_App3(StatusType Error);

extern void StartupHook_OSAPP_App4(void);
extern void ShutdownHook_OSAPP_App4(StatusType Error);
extern void ErrorHook_OSAPP_App4(StatusType Error);

/*==================[internal data definition]===============================*/

#pragma section

#define ZERO_OBJECT_DUMMY_COUNT 1

#define TASKS_COUNT_App1 3
#define COUNTERS_COUNT_App1 1
#define ALARMS_COUNT_App1 3
#define SCHEDULETABLES_COUNT_App1 0
#define ISRS_COUNT_App1 6
#define TRUSTEDFUNC_COUNT_App1 3

#define TASKS_COUNT_App2 3
#define COUNTERS_COUNT_App2 1
#define ALARMS_COUNT_App2 3
#define SCHEDULETABLES_COUNT_App2 0
#define ISRS_COUNT_App2 6
#define TRUSTEDFUNC_COUNT_App2 1

#define TASKS_COUNT_App3 3
#define COUNTERS_COUNT_App3 3
#define ALARMS_COUNT_App3 4
#define SCHEDULETABLES_COUNT_App3 2
#define ISRS_COUNT_App3 0
#define TRUSTEDFUNC_COUNT_App3 1

#define TASKS_COUNT_App4 3
#define COUNTERS_COUNT_App4 2
#define ALARMS_COUNT_App4 3
#define SCHEDULETABLES_COUNT_App4 1
#define ISRS_COUNT_App4 0
#define TRUSTEDFUNC_COUNT_App4 1

/* core0 */
/********[App1]*********/
TaskType Tasks_App1[TASKS_COUNT_App1] = {
    T01,
    T02,
    T03
};

CounterType Counters_App1[COUNTERS_COUNT_App1] = {
    counter2,
};

AlarmType Alarms_App1[ALARMS_COUNT_App1] = {
    alarm6,
    alarm7,
    alarm8,
};

ScheduleTableType ScheduleTables_App1[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_SCHEDULETABLE_ID
};

ISRType Isrs_App1[ISRS_COUNT_App1] = {
    I001,
    I002,
    I003,
    I004,
    I005,
    I006
};

TrustedFunctionIndexType TrustedFunc_App1[TRUSTEDFUNC_COUNT_App1] = {
    TF_cola,
    TF_juice,
    TF_water,
};

/********[App3]*********/
TaskType Tasks_App3[TASKS_COUNT_App3] = {
    T04,
    T05,
    T06
};

CounterType Counters_App3[COUNTERS_COUNT_App3] = {
    counter4,
    counter_ST2,
    counter_ST3,
};

AlarmType Alarms_App3[ALARMS_COUNT_App3] = {
    alarm9,
    alarm10,
    alarm_ST2,
    alarm_ST3,
};

ScheduleTableType ScheduleTables_App3[SCHEDULETABLES_COUNT_App3] = {
    ST2,
    ST3
};

ISRType Isrs_App3[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_ISR_ID
};

TrustedFunctionIndexType TrustedFunc_App3[TRUSTEDFUNC_COUNT_App3] = {
    TF_yes,
};

/* core1 */
/********[App2]*********/
TaskType Tasks_App2[TASKS_COUNT_App2] = {
    T11,
    T12,
    T13
};

CounterType Counters_App2[COUNTERS_COUNT_App2] = {
    counter1,
};

AlarmType Alarms_App2[ALARMS_COUNT_App2] = {
    alarm1,
    alarm2,
    alarm3,
};

ScheduleTableType ScheduleTables_App2[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_SCHEDULETABLE_ID
};

ISRType Isrs_App2[ISRS_COUNT_App2] = {
    I101,
    I102,
    I103,
    I104,
    I105,
    I106
};

TrustedFunctionIndexType TrustedFunc_App2[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_TF_ID
};

/********[App4]*********/
TaskType Tasks_App4[TASKS_COUNT_App4] = {
    T14,
    T15,
    T16
};

CounterType Counters_App4[COUNTERS_COUNT_App4] = {
    counter3,
    counter_ST1,
};

AlarmType Alarms_App4[ALARMS_COUNT_App4] = {
    alarm4,
    alarm5,
    alarm_ST1,
};

ScheduleTableType ScheduleTables_App4[SCHEDULETABLES_COUNT_App4] = {
    ST1
};

ISRType Isrs_App4[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_ISR_ID
};

TrustedFunctionIndexType TrustedFunc_App4[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_TF_ID
};

/*==================[external data definition]===============================*/
ApplicationObjectsType ApplicationObjects_core0[APPLICATIONS_COUNT_CORE0] = {
    /* App1 */
    {
        /* Tasks */
        {
            Tasks_App1,
            TASKS_COUNT_App1
        },
        /* Counters */
        {
            Counters_App1,
            COUNTERS_COUNT_App1
        },
        /* Alarms */
        {
            Alarms_App1,
            ALARMS_COUNT_App1
        },
        /* ScheduleTables */
        {
            ScheduleTables_App1,
            SCHEDULETABLES_COUNT_App1
        },
        /* ISRs */
        {
            Isrs_App1,
            ISRS_COUNT_App1
        },
        /* TFs */
        {
            TrustedFunc_App1,
            TRUSTEDFUNC_COUNT_App1
        },
    },
    /* App3 */
    {
        /* Tasks */
        {
            Tasks_App3,
            TASKS_COUNT_App3
        },
        /* Counters */
        {
            Counters_App3,
            COUNTERS_COUNT_App3
        },
        /* Alarms */
        {
            Alarms_App3,
            ALARMS_COUNT_App3
        },
        /* ScheduleTables */
        {
            ScheduleTables_App3,
            SCHEDULETABLES_COUNT_App3
        },
        /* ISRs */
        {
            Isrs_App3,
            ISRS_COUNT_App3
        },
        /* TFs */
        {
            TrustedFunc_App3,
            TRUSTEDFUNC_COUNT_App3
        },
    },
};

ApplicationObjectsType ApplicationObjects_core0[APPLICATIONS_COUNT_CORE1] = {
    /* App2 */
    {
        /* Tasks */
        {
            Tasks_App2,
            TASKS_COUNT_App2
        },
        /* Counters */
        {
            Counters_App2,
            COUNTERS_COUNT_App2
        },
        /* Alarms */
        {
            Alarms_App2,
            ALARMS_COUNT_App2
        },
        /* ScheduleTables */
        {
            ScheduleTables_App2,
            SCHEDULETABLES_COUNT_App2
        },
        /* ISRs */
        {
            Isrs_App2,
            ISRS_COUNT_App2
        },
        /* TFs */
        {
            TrustedFunc_App2,
            TRUSTEDFUNC_COUNT_App2
        },
    },
    /* App4 */
    {
        /* Tasks */
        {
            Tasks_App4,
            TASKS_COUNT_App4
        },
        /* Counters */
        {
            Counters_App4,
            COUNTERS_COUNT_App4
        },
        /* Alarms */
        {
            Alarms_App4,
            ALARMS_COUNT_App4
        },
        /* ScheduleTables */
        {
            ScheduleTables_App4,
            SCHEDULETABLES_COUNT_App4
        },
        /* ISRs */
        {
            Isrs_App4,
            ISRS_COUNT_App4
        },
        /* TFs */
        {
            TrustedFunc_App4,
            TRUSTEDFUNC_COUNT_App4
        },
    },
};

ApplicationVarType ApplicationVar[APPLICATIONS_COUNT] = {
    /* Application App1 */
    {
        App1,  //ID
        APPLICATION_ACCESSIBLE,
        TRUE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_0,
        TRUE, //uint8 OsTrustedApplicationWithProtection
        FALSE, //OsTrustedAppWithTimingProt
        FALSE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T03, //RestartTask
        &ApplicationObjects_core0[0],
        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_App1,
            ShutdownHook_OSAPP_App1,
            ErrorHook_OSAPP_App1,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_App1_SEC_data),
            (uint32*)(_EOSAPP_App1_SEC_data),
            (uint32*)(_SOSAPP_App1_SEC_data_R),
            (uint32*)(_SOSAPP_App1_SEC_bss),
            (uint32*)(_EOSAPP_App1_SEC_bss)
        },
        MemProtArea_App1,
        resourceApp1,
    },
    /* Application App2 */
    {
        App2,  //ID
        APPLICATION_ACCESSIBLE,
        TRUE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_1,
        TRUE, //uint8 OsTrustedApplicationWithProtection
        FALSE, //OsTrustedAppWithTimingProt
        FALSE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T13, //RestartTask
        &ApplicationObjects_core1[0],
        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_App2,
            ShutdownHook_OSAPP_App2,
            ErrorHook_OSAPP_App2,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_App2_SEC_data),
            (uint32*)(_EOSAPP_App2_SEC_data),
            (uint32*)(_SOSAPP_App2_SEC_data_R),
            (uint32*)(_SOSAPP_App2_SEC_bss),
            (uint32*)(_EOSAPP_App2_SEC_bss)
        },
        MemProtArea_App2,
        resourceApp2,
    },
    /* Application App3 */
    {
        App3,  //ID
        APPLICATION_ACCESSIBLE,
        FALSE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_0,
        False, //uint8 OsTrustedApplicationWithProtection
        FALSE, //OsTrustedAppWithTimingProt
        FALSE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T06, //RestartTask
        &ApplicationObjects_core0[1],
        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_App3,
            ShutdownHook_OSAPP_App3,
            ErrorHook_OSAPP_App3,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_App3_SEC_data),
            (uint32*)(_EOSAPP_App3_SEC_data),
            (uint32*)(_SOSAPP_App3_SEC_data_R),
            (uint32*)(_SOSAPP_App3_SEC_bss),
            (uint32*)(_EOSAPP_App3_SEC_bss)
        },
        MemProtArea_App3,
        resourceApp3,
    },
    /* Application App4 */
    {
        App4,  //ID
        APPLICATION_ACCESSIBLE,
        FALSE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_1,
        False, //uint8 OsTrustedApplicationWithProtection
        FALSE, //OsTrustedAppWithTimingProt
        FALSE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T16, //RestartTask
        &ApplicationObjects_core1[1],
        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_App4,
            ShutdownHook_OSAPP_App4,
            ErrorHook_OSAPP_App4,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_App4_SEC_data),
            (uint32*)(_EOSAPP_App4_SEC_data),
            (uint32*)(_SOSAPP_App4_SEC_data_R),
            (uint32*)(_SOSAPP_App4_SEC_bss),
            (uint32*)(_EOSAPP_App4_SEC_bss)
        },
        MemProtArea_App4,
        resourceApp4,
    },
};
LockType lockForApplicationState[APPLICATIONS_COUNT];
/*==================[end of file]============================================*/
#pragma section
