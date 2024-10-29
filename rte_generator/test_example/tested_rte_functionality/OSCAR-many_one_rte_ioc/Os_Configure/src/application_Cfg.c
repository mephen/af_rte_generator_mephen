/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009, 2014, 2015 Mariano Cerdeiro
 * Copyright 2014, ACSE & CADIEEL
 *      ACSE: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *      CADIEEL: http://www.cadieel.org.ar
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* This file content the generated implementation of os */

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
extern void StartupHook_OSAPP_app_lion(void);
extern void ShutdownHook_OSAPP_app_lion(StatusType Error);
extern void ErrorHook_OSAPP_app_lion(StatusType Error);

extern void StartupHook_OSAPP_A02(void);
extern void ShutdownHook_OSAPP_A02(StatusType Error);
extern void ErrorHook_OSAPP_A02(StatusType Error);

extern void StartupHook_OSAPP_A03(void);
extern void ShutdownHook_OSAPP_A03(StatusType Error);
extern void ErrorHook_OSAPP_A03(StatusType Error);

extern void StartupHook_OSAPP_A04(void);
extern void ShutdownHook_OSAPP_A04(StatusType Error);
extern void ErrorHook_OSAPP_A04(StatusType Error);
/*==================[internal data definition]===============================*/
#pragma section

#define ZERO_OBJECT_DUMMY_COUNT 1   //if XXX_COUNT is 0, we will use this to add dummy data

#define TASK_COUNT_app_lion 3
#define COUNTER_COUNT_app_lion 1
#define ALARM_COUNT_app_lion 4
#define SCHEDULETABLE_COUNT_app_lion 2
#define ISR_COUNT_app_lion 4
#define TRUSTEDFUNC_COUNT_app_lion 3

#define TASKS_APP2_COUNT 3
#define COUNTERS_APP2_COUNT 1
#define ALARMS_APP2_COUNT 2
#define SCHEDULETABLES_APP2_COUNT 1
#define ISRS_APP2_COUNT 4
#define TRUSTED_FUNC_APP2_COUNT 2

#define TASKS_APP3_COUNT 3
#define COUNTERS_APP3_COUNT 1
#define ALARMS_APP3_COUNT 0
#define SCHEDULETABLES_APP3_COUNT 0
#define ISRS_APP3_COUNT 2
#define TRUSTED_FUNC_APP3_COUNT 0

#define TASKS_APP4_COUNT 3
#define COUNTERS_APP4_COUNT 1
#define ALARMS_APP4_COUNT 0
#define SCHEDULETABLES_APP4_COUNT 0
#define ISRS_APP4_COUNT 2
#define TRUSTED_FUNC_APP4_COUNT 0

/* core0 */
/********[app_lion]*********/
TaskType Task_app_lion[TASK_COUNT_app_lion] = {
    T01,
    T02,
    T03,
};
CounterType Counter_app_lion[COUNTER_COUNT_app_lion] = {
    counter3,
};

AlarmType Alarm_app_lion[ALARM_COUNT_app_lion] = {
    alarm3,
    alarm4,
    SCalarm1,
    SCalarm2,
};
ScheduleTableType ScheduleTable_app_lion[SCHEDULETABLE_COUNT_app_lion] = {
    scheduletable1,
    scheduletable2,
};
ISRType Isr_app_lion[ISR_COUNT_app_lion] = {
    I001,
    I002,
    I003,
    I004,
};
TrustedFunctionIndexType TrustedFunc_app_lion[TRUSTEDFUNC_COUNT_app_lion] = {
    TF_AIMER,
    TF_IKURA,
    TF_YORUSHIKA
};

/********[app3]*********/
TaskType Tasks_app3[TASKS_APP3_COUNT] = {
    T04,
    T05,
    T06,
};
CounterType Counters_app3[COUNTERS_APP3_COUNT] = {
    counter4,
};
AlarmType Alarms_app3[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_ALARM_ID,
};
ScheduleTableType ScheduleTable_app3[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_SCHEDULETABLE_ID,
};
ISRType Isr_app3[ISRS_APP3_COUNT] = {
    I005,
    I006,
};
TrustedFunctionIndexType Trusted_func_app3[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_TF_ID,
};

/* core1 */
/********[app2]*********/
TaskType Tasks_app2[TASKS_APP2_COUNT] = {
    T11,
    T12,
    T13,
};
CounterType Counters_app2[COUNTERS_APP2_COUNT] = {
    counter1,
};
AlarmType Alarms_app2[ALARMS_APP2_COUNT] = {
    alarm1,
    SCalarm3,
};
ScheduleTableType ScheduleTable_app2[SCHEDULETABLES_APP2_COUNT] = {
    scheduletable3,
};
ISRType Isr_app2[ISRS_APP2_COUNT] = {
    I101,
    I102,
    I103,
    I104,
};
TrustedFunctionIndexType Trusted_func_app2[TRUSTED_FUNC_APP2_COUNT] = {
    TF_YUURI,
    TF_HITORIE
};

/********[app4]*********/
TaskType Tasks_app4[TASKS_APP4_COUNT] = {
    T14,
    T15,
    T16,
};
CounterType Counters_app4[COUNTERS_APP4_COUNT] = {
    counter2,
};
AlarmType Alarms_app4[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_ALARM_ID,
};
ScheduleTableType ScheduleTable_app4[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_SCHEDULETABLE_ID,
};
ISRType Isr_app4[ISRS_APP4_COUNT] = {
    I105,
    I106,
};
TrustedFunctionIndexType Trusted_func_app4[ZERO_OBJECT_DUMMY_COUNT] = {
    INVALID_TF_ID,
};

/*==================[external data definition]===============================*/
ApplicationObjectsType ApplicationObjects_core0[APPLICATIONS_COUNT_CORE0] = {
    /* app_lion */
    {
        /* Tasks */
        {
            Task_app_lion,
            TASK_COUNT_app_lion
        },
        /* Counters */
        {
            Counter_app_lion,
            COUNTER_COUNT_app_lion
        },
        /* Alarms */
        {
            Alarm_app_lion,
            ALARM_COUNT_app_lion
        },
        /* SchedulerTables */
        {
            ScheduleTable_app_lion,
            SCHEDULETABLE_COUNT_app_lion
        },
        /* ISRs */
        {
            Isr_app_lion,
            ISR_COUNT_app_lion
        },
        /* TFs */
        {
            TrustedFunc_app_lion,
            TRUSTEDFUNC_COUNT_app_lion,
        }
    },
    /* app3 */
    {
        /* Tasks */
        {
            Tasks_app3,
            TASKS_APP3_COUNT
        },
        /* Counters */
        {
            Counters_app3,
            COUNTERS_APP3_COUNT
        },
        /* Alarms */
        {
            Alarms_app3,
            ALARMS_APP3_COUNT
        },
        /* SchedulerTables */
        {
            ScheduleTable_app3,
            SCHEDULETABLES_APP3_COUNT
        },
        /* ISRs */
        {
            Isr_app3,
            ISRS_APP3_COUNT
        },
        /* TFs */
        {
            Trusted_func_app3,
            TRUSTED_FUNC_APP3_COUNT,
        }
    }
};

ApplicationObjectsType ApplicationObjects_core1[APPLICATIONS_COUNT_CORE1] = {
    /* app2 */
    {
        /* Tasks */
        {
            Tasks_app2,
            TASKS_APP2_COUNT
        },
        /* Counters */
        {
            Counters_app2,
            COUNTERS_APP2_COUNT
        },
        /* Alarms */
        {
            Alarms_app2,
            ALARMS_APP2_COUNT
        },
        /* SchedulerTables */
        {
            ScheduleTable_app2,
            SCHEDULETABLES_APP2_COUNT
        },
        /* ISRs */
        {
            Isr_app2,
            ISRS_APP2_COUNT
        },
        /* TFs */
        {
            Trusted_func_app2,
            TRUSTED_FUNC_APP2_COUNT,
        }
    },
    /* app4 */
    {
        /* Tasks */
        {
            Tasks_app4,
            TASKS_APP4_COUNT
        },
        /* Counters */
        {
            Counters_app4,
            COUNTERS_APP4_COUNT
        },
        /* Alarms */
        {
            Alarms_app4,
            ALARMS_APP4_COUNT
        },
        /* SchedulerTables */
        {
            ScheduleTable_app4,
            SCHEDULETABLES_APP4_COUNT
        },
        /* ISRs */
        {
            Isr_app4,
            ISRS_APP4_COUNT
        },
        /* TFs */
        {
            Trusted_func_app4,
            TRUSTED_FUNC_APP4_COUNT,
        }
    }
};

ApplicationVarType ApplicationVar[APPLICATIONS_COUNT] = {
    /* Application app_lion */
    {
        app_lion,                       //ApplicationType id;
        APPLICATION_ACCESSIBLE,     //ApplicationStateType State;
        TRUE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,   //EcucPartitionIdType EcuRef;
        OS_CORE_ID_0,               //CoreIdType CoreRef;
        TRUE,  //uint8 OsTrustedApplicationWithProtection
        FALSE,  //uint8 OsTrustedAppWithTimingProt
        TRUE,  //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T03,                        //TaskType RestartTaskID;
        &ApplicationObjects_core0[0],   //ApplicationObjectsRefType Objects;

        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_app_lion,
            ShutdownHook_OSAPP_app_lion,
            ErrorHook_OSAPP_app_lion,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_A01_SEC_data),
            (uint32*)(_EOSAPP_A01_SEC_data),
            (uint32*)(_SOSAPP_A01_SEC_data_R),
            (uint32*)(_SOSAPP_A01_SEC_bss),
            (uint32*)(_EOSAPP_A01_SEC_bss)
        },
        MemProtArea_A01,
        resourceApp1,
    },
    /* Application app2 */
    {
        app2,
        APPLICATION_ACCESSIBLE,
        TRUE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_1,
        FALSE, //uint8 OsTrustedApplicationWithProtection 
        FALSE, //OsTrustedAppWithTimingProt
        TRUE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T13,
        &ApplicationObjects_core1[0],

        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_A02,
            ShutdownHook_OSAPP_A02,
            ErrorHook_OSAPP_A02,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_A02_SEC_data),
            (uint32*)(_EOSAPP_A02_SEC_data),
            (uint32*)(_SOSAPP_A02_SEC_data_R),
            (uint32*)(_SOSAPP_A02_SEC_bss),
            (uint32*)(_EOSAPP_A02_SEC_bss)
        },
        MemProtArea_A02,
        resourceApp2,
    },
    /* Application app3 */
    {
        app3,
        APPLICATION_ACCESSIBLE,
        TRUE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_0,
        FALSE, //uint8 OsTrustedApplicationWithProtection 
        FALSE, //OsTrustedAppWithTimingProt
        FALSE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T06,
        &ApplicationObjects_core0[1],

        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_A03,
            ShutdownHook_OSAPP_A03,
            ErrorHook_OSAPP_A03,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_A03_SEC_data),
            (uint32*)(_EOSAPP_A03_SEC_data),
            (uint32*)(_SOSAPP_A03_SEC_data_R),
            (uint32*)(_SOSAPP_A03_SEC_bss),
            (uint32*)(_EOSAPP_A03_SEC_bss)
        },
        MemProtArea_A03,
        resourceApp3,
    },
    /* Application app4 */
    {
        app4,
        APPLICATION_ACCESSIBLE,
        TRUE,                    //OsTrustedType OsTrusted;
        ECUC_PARTITION_DEFAULT_ID,
        OS_CORE_ID_1,
        FALSE, //uint8 OsTrustedApplicationWithProtection 
        FALSE, //OsTrustedAppWithTimingProt
        FALSE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this
        T16,
        &ApplicationObjects_core1[1],

        //AppHookFuncArrayType AppHookFuncArray
        {
            StartupHook_OSAPP_A04,
            ShutdownHook_OSAPP_A04,
            ErrorHook_OSAPP_A04,
        },

        //RomToRamInitTableType RomToRamInitTable
        {
            (uint32*)(_SOSAPP_A04_SEC_data),
            (uint32*)(_EOSAPP_A04_SEC_data),
            (uint32*)(_SOSAPP_A04_SEC_data_R),
            (uint32*)(_SOSAPP_A04_SEC_bss),
            (uint32*)(_EOSAPP_A04_SEC_bss)
        },
        MemProtArea_A04,
        resourceApp4
    }
};

LockType lockForApplicationState[APPLICATIONS_COUNT];

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*==================[end of file]============================================*/

#pragma section