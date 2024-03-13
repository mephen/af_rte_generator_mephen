/*==================[inclusions]=============================================*/
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "counter_Cfg.h"
#include "isr_Cfg.h"
#include "scheduleTable_Cfg.h"
#include "softwaretimer_Cfg.h"
#include "trustedFunc_Cfg.h"

/*==================[macros and definitions]================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

#pragma section

SystemVarType SystemVar_core0;

CurrentTaskType CurrentTask_core0;

CurrentOSContextType CurrentOSContext_core0;
CurrentOSContextRefType CurrentOSContextRef_core0 = &CurrentOSContext_core0;

SystemReadyListType SystemReadyList_core0 = {
    0,                      /* readyListFlag */
    ReadyList_core0,        /* ReadyList */
    ReadyListTail_core0     /* ReadyListTail */
};

SystemObjectsType SystemObjects_core0 = {
    TASKS_COUNT_CORE0,              /* tasksCount */
    EXTENDED_TASKS_COUNT_CORE0,     /* extendedTasksCount */
    ISR2_TASKS_COUNT_CORE0,         /* isr2TaskCount */      //add 20220811
    TASK_OBJECTS_COUNT_CORE0,       /* taskObjectsCount */
    ISR_ALL_COUNT_CORE0,            /* uint8 isrAllCount; */
    RESOURCES_COUNT_CORE0,          /* resourcesCount */
    ALARMS_COUNT_CORE0,             /* alarmsCount */
    ALARMS_AUTOSTART_COUNT_CORE0,   /* alarmAutoStartCount */
    COUNTERS_COUNT_CORE0,           /* countersCount */
    SCHEDULETABLE_COUNT_CORE0,              /* ScheduleTableCount */
    SCHEDULETABLE_AUTOSTART_COUNT_CORE0,    /* AUTOSTARTScheduleTableCOUNT */
    SOFTWARETIMERS_COUNT_CORE0, /* softwareTimerCount */

    TaskConst_core0,        /* TaskConst */
    TaskVar_core0,          /* TaskVar */
    Isr_const_core0,         /* IsrConstType */   //add 20220811
    EventsVar_core0,        /* EventsVar */
    ResourceVar_core0,      /* ResourceVar */

    AlarmConst_core0,       /* AlarmConst */
    AlarmVar_core0,         /* AlramVar */
    NULL,                   /* AutoStartAlarm */
    CounterConst_core0,     /* CounterConst */
    CounterVar_core0,       /* CounterVar */

    ScheduleTableConst_core0,               /* ScheduleTableConst */
    ScheduleTableVar_core0,                 /* ScheduleTableVar */
    NULL,                                   /* AUTOSTARTScheduleTable */

    SoftwareTimerConst_core0,   /* SoftwareTimerConst */
    SoftwareTimerVar_core0,     /* SoftwareTimerVar */
};
SystemVarType SystemVar_core1;

CurrentTaskType CurrentTask_core1;

CurrentOSContextType CurrentOSContext_core1;
CurrentOSContextRefType CurrentOSContextRef_core1 = &CurrentOSContext_core1;

SystemReadyListType SystemReadyList_core1 = {
    0,                      /* readyListFlag */
    ReadyList_core1,        /* ReadyList */
    ReadyListTail_core1     /* ReadyListTail */
};

SystemObjectsType SystemObjects_core1 = {
    TASKS_COUNT_CORE1,              /* tasksCount */
    EXTENDED_TASKS_COUNT_CORE1,     /* extendedTasksCount */
    ISR2_TASKS_COUNT_CORE1,         /* isr2TaskCount */      //add 20220811
    TASK_OBJECTS_COUNT_CORE1,       /* taskObjectsCount */
    ISR_ALL_COUNT_CORE1,            /* uint8 isrAllCount; */
    RESOURCES_COUNT_CORE1,          /* resourcesCount */
    ALARMS_COUNT_CORE1,             /* alarmsCount */
    ALARMS_AUTOSTART_COUNT_CORE1,   /* alarmAutoStartCount */
    COUNTERS_COUNT_CORE1,           /* countersCount */
    SCHEDULETABLE_COUNT_CORE1,              /* ScheduleTableCount */
    SCHEDULETABLE_AUTOSTART_COUNT_CORE1,    /* AUTOSTARTScheduleTableCOUNT */
    SOFTWARETIMERS_COUNT_CORE1, /* softwareTimerCount */

    TaskConst_core1,        /* TaskConst */
    TaskVar_core1,          /* TaskVar */
    Isr_const_core1,         /* IsrConstType */   //add 20220811
    EventsVar_core1,        /* EventsVar */
    ResourceVar_core1,      /* ResourceVar */

    AlarmConst_core1,       /* AlarmConst */
    AlarmVar_core1,         /* AlramVar */
    NULL,                   /* AutoStartAlarm */
    CounterConst_core1,     /* CounterConst */
    CounterVar_core1,       /* CounterVar */

    ScheduleTableConst_core1,               /* ScheduleTableConst */
    ScheduleTableVar_core1,                 /* ScheduleTableVar */
    NULL,                                   /* AUTOSTARTScheduleTable */

    SoftwareTimerConst_core1,   /* SoftwareTimerConst */
    SoftwareTimerVar_core1,     /* SoftwareTimerVar */
};
SystemVarRefType SystemVar[OsNumberOfCores] = {
    &SystemVar_core0,
    &SystemVar_core1,
};
CurrentTaskRefType CurrentTask[OsNumberOfCores] = {
    &CurrentTask_core0,
    &CurrentTask_core1,
};
ApplicationType ExecutingApp[OsNumberOfCores] = {
    INVALID_OSAPPLICATION,
    INVALID_OSAPPLICATION,
};
SystemReadyListRefType SystemReadyList[OsNumberOfCores] = {
    &SystemReadyList_core0,
    &SystemReadyList_core1,
};
SystemObjectsRefType SystemObjects[OsNumberOfCores] = {
    &SystemObjects_core0,
    &SystemObjects_core1,
};

SystemObjectAutosarType SystemObjectAutosar_core0 = {
    TASKS_COUNT_CORE0,
    ISR_ALL_COUNT_CORE0,
    ALARMS_COUNT_CORE0,
    COUNTERS_COUNT_CORE0,
    SCHEDULETABLE_COUNT_CORE0,
    RESOURCES_COUNT_CORE0,
    TaskAutosar_core0,
    IsrAutosar_core0,
    AlarmAutosar_core0,
    CounterAutosar_core0,
    ScheduleTableAutosar_core0,
    ResourceAutosar_core0,
    Ioc_channel_sender,
    Ioc_channel_receiver,
    PeripherilAutosar_core0,
    TrustedFuncAutosar_core0,
};

SystemObjectAutosarType SystemObjectAutosar_core1 = {
    TASKS_COUNT_CORE1,
    ISR_ALL_COUNT_CORE1,
    ALARMS_COUNT_CORE1,
    COUNTERS_COUNT_CORE1,
    SCHEDULETABLE_COUNT_CORE1,
    RESOURCES_COUNT_CORE1,
    TaskAutosar_core1,
    IsrAutosar_core1,
    AlarmAutosar_core1,
    CounterAutosar_core1,
    ScheduleTableAutosar_core1,
    ResourceAutosar_core1,
    Ioc_channel_sender,
    Ioc_channel_receiver,
    PeripherilAutosar_core1,
    TrustedFuncAutosar_core1,
};

SystemObjectAutosarRefType SystemObjectAutosar[OsNumberOfCores] = {
    &SystemObjectAutosar_core0,
    &SystemObjectAutosar_core1,
};

ApplicationType AppsInCore_core0[APPLICATIONS_COUNT_CORE0] = {
    App1,
    App3,
};

ApplicationType AppsInCore_core1[APPLICATIONS_COUNT_CORE1] = {
    App2,
    App4,
};

AppsInCoreType SystemAppsInCore[OsNumberOfCores] = {
    {
        AppsInCore_core0,
        APPLICATIONS_COUNT_CORE0,
    },

    {
        AppsInCore_core1,
        APPLICATIONS_COUNT_CORE1,
    },

};

CoreIdType CoreIdPhyToLogArray[TotalNumberOfCores] = {
    OS_CORE_ID_0, /* PE1 */
    OS_CORE_ID_1, /* PE2 */
};

CoreStatusType CoreStatus[TotalNumberOfCores] = {
    /* OS_CORE_ID_0 */
    {
        1, /*is autosar OS */
        beforeStartOS /* Activate state */
    },
    /* OS_CORE_ID_1 */
    {
        1, /*is autosar OS */
        nonActivatedCore /* Activate state */
    }
};

uint16 NumberOfActivatedCore = 1;

SimuEcucPartitionSettingType EcucPartitionSettingArr[EcucPartitionSettingNum] = {
    {
        "Renesas Rh850f1h",
        "Renesas Rh850g3m",
        2,
        TRUE,
    },
};

AppModeType AppModeArray[TotalNumberOfCores];

uint8 CoreIntFlag[OsNumberOfCores];

LockType CoreParaLock[OsNumberOfCores];

ServiceParaType CrossCoreServicePara[OsNumberOfCores];   /* used for cross-core */

uint8 app_start_up_hook_err_flag[OsNumberOfCores];
uint8 app_shut_down_hook_err_flag[OsNumberOfCores];

uint32 CurrentExecServiceID[OsNumberOfCores];              /* used for info in error-hook */
ServiceParaType DebugServicePara[OsNumberOfCores];         /* used for info in error-hook */

ApplicationType TF_NestedOwnerArray_core0[MAX_STACK_FOR_NESTED_TF_CALL];
ApplicationType TF_NestedOwnerArray_core1[MAX_STACK_FOR_NESTED_TF_CALL];
ApplicationRefType TF_NestedOwnerArray[OsNumberOfCores] = {
    TF_NestedOwnerArray_core0,
    TF_NestedOwnerArray_core1,
};

IdleModeType NowIdleMode[OsNumberOfCores];
IdleModeType NextIdleMode[OsNumberOfCores];
LockType lockForIdleMode[OsNumberOfCores];

/* SysTask management data */
TaskType beforeSysTask_core0 = INVALID_TASK_ID;
TaskType beforeSysTask_core1 = INVALID_TASK_ID;
TaskType beforeSysTask[OsNumberOfCores] = {
    INVALID_TASK_ID,
    INVALID_TASK_ID,
};
SysTaskInformationType SysTaskAction_core0[SysTaskActionQueueLength];
SysTaskInformationType SysTaskAction_core1[SysTaskActionQueueLength];
SysTaskActionQueueType SysTaskActionQueue_core0 = {
    SysTaskAction_core0,
    SysTaskActionQueueLength,
    0,
    0,
    TRUE,
};

SysTaskActionQueueType SysTaskActionQueue_core1 = {
    SysTaskAction_core1,
    SysTaskActionQueueLength,
    0,
    0,
    TRUE,
};

SysTaskActionQueueType *SysTaskActionQueue[OsNumberOfCores] = {
    &SysTaskActionQueue_core0,
    &SysTaskActionQueue_core1,
};

#pragma section

const uint32 TempConst = 10;

SysTaskInformationType* const CurrentAction[OsNumberOfCores] = {
    &CurrentAction_core0,
    &CurrentAction_core1,
};
#pragma section TASK_SysTask_core0
SysTaskInformationType CurrentAction_core0;

#pragma section TASK_SysTask_core1
SysTaskInformationType CurrentAction_core1;

#pragma section

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*==================[end of file]============================================*/

