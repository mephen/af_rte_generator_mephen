from generator.config import config 
from generator import globals as gr
from gen.cores import app_core0, app_core1, trustedFun_cores

global config
global app_core0, app_core1, trustedFun_cores
gr.genfile = open(gr.src_path+"os_Cfg.c",'w')


gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("#include \"event_Cfg.h\"")
gr.printFile("#include \"alarm_Cfg.h\"")
gr.printFile("#include \"application_Cfg.h\"")
gr.printFile("#include \"counter_Cfg.h\"")
gr.printFile("#include \"isr_Cfg.h\"")
gr.printFile("#include \"scheduleTable_Cfg.h\"")
gr.printFile("#include \"softwaretimer_Cfg.h\"")
gr.printFile("#include \"trustedFunc_Cfg.h\"\n")
gr.printFile("#include \"Ioc.h\"\n")
gr.printFile("#include \"peripheral.h\"\n")
gr.printFile("/*==================[macros and definitions]================================*/\n")
gr.printFile("/*==================[internal data declaration]==============================*/\n")
gr.printFile("/*==================[internal functions declaration]=========================*/\n")
gr.printFile("/*==================[internal data definition]===============================*/\n")
gr.printFile("/*==================[external data definition]===============================*/\n")

gr.printFile("#pragma section\n")
os = config.getValue("/AUTOSAR","OsOS")
#if os)>1:
#    gr.error ("More than one OS defined in the configuration")      
#    gr.printFile ("More than one OS defined in the configuration\r\n")
#    exit()      #return

core_list = []
core_counts = config.getValue("/AUTOSAR/" + os,"OsNumberOfCores")
core_counts = int(core_counts)
for core_count in range(core_counts):
    core_list.append("core" + str(core_count))

for core_ID in core_list:
    gr.printFile("SystemVarType SystemVar_{};\n".format(core_ID))
    gr.printFile("CurrentTaskType CurrentTask_{};\n".format(core_ID))
    gr.printFile("CurrentOSContextType CurrentOSContext_{};".format(core_ID))
    gr.printFile("CurrentOSContextRefType CurrentOSContextRef_{} = &CurrentOSContext_{};\n".format(core_ID, core_ID))
    
    #gr.printFile("ApplicationType ExecutingApp_{};".format(core_ID))

    gr.printFile("SystemReadyListType SystemReadyList_{} = {}".format(core_ID, "{"))
    gr.printFile("    0,                      /* readyListFlag */")
    gr.printFile("    ReadyList_{},        /* ReadyList */".format(core_ID))
    gr.printFile("    ReadyListTail_{}     /* ReadyListTail */".format(core_ID))
    gr.printFile("};\n")

    gr.printFile("SystemObjectsType SystemObjects_{} = {}".format(core_ID, "{"))
    gr.printFile("    TASKS_COUNT_{},              /* tasksCount */".format(core_ID.upper()))
    gr.printFile("    EXTENDED_TASKS_COUNT_{},     /* extendedTasksCount */".format(core_ID.upper()))
    gr.printFile("    ISR2_TASKS_COUNT_{},         /* isr2TaskCount */      //add 20220811".format(core_ID.upper()))     
    gr.printFile("    TASK_OBJECTS_COUNT_{},       /* taskObjectsCount */".format(core_ID.upper()))
    gr.printFile("    ISR_ALL_COUNT_{},            /* uint8 isrAllCount; */".format(core_ID.upper()))
    gr.printFile("    RESOURCES_COUNT_{},          /* resourcesCount */".format(core_ID.upper()))
    gr.printFile("    ALARMS_COUNT_{},             /* alarmsCount */".format(core_ID.upper()))
    gr.printFile("    ALARMS_AUTOSTART_COUNT_{},   /* alarmAutoStartCount */".format(core_ID.upper()))
    gr.printFile("    COUNTERS_COUNT_{},           /* countersCount */".format(core_ID.upper()))
    gr.printFile("    SCHEDULETABLE_COUNT_{},              /* ScheduleTableCount */".format(core_ID.upper()))
    gr.printFile("    SCHEDULETABLE_AUTOSTART_COUNT_{},    /* AUTOSTARTScheduleTableCOUNT */".format(core_ID.upper()))
    gr.printFile("    SOFTWARETIMERS_COUNT_{}, /* softwareTimerCount */\n".format(core_ID.upper()))

    gr.printFile("    TaskConst_{},        /* TaskConst */".format(core_ID))
    gr.printFile("    TaskVar_{},          /* TaskVar */".format(core_ID))
    gr.printFile("    Isr_const_{},         /* IsrConstType */   //add 20220811".format(core_ID))
    gr.printFile("    EventsVar_{},        /* EventsVar */".format(core_ID))
    gr.printFile("    ResourceVar_{},      /* ResourceVar */\n".format(core_ID))

    gr.printFile("    AlarmConst_{},       /* AlarmConst */".format(core_ID))
    gr.printFile("    AlarmVar_{},         /* AlramVar */".format(core_ID))
    gr.printFile("    NULL,                   /* AutoStartAlarm */")
    gr.printFile("    CounterConst_{},     /* CounterConst */".format(core_ID))
    gr.printFile("    CounterVar_{},       /* CounterVar */\n".format(core_ID))

    gr.printFile("    ScheduleTableConst_{},               /* ScheduleTableConst */".format(core_ID))
    gr.printFile("    ScheduleTableVar_{},                 /* ScheduleTableVar */".format(core_ID))
    gr.printFile("    NULL,                                   /* AUTOSTARTScheduleTable */\n".format(core_ID))

    gr.printFile("    SoftwareTimerConst_{},   /* SoftwareTimerConst */".format(core_ID))
    gr.printFile("    SoftwareTimerVar_{},     /* SoftwareTimerVar */".format(core_ID))
    gr.printFile("};")


gr.printFile("SystemVarRefType SystemVar[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    &SystemVar_{},".format(core_ID))
gr.printFile("};")

gr.printFile("CurrentTaskRefType CurrentTask[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    &CurrentTask_{},".format(core_ID))
gr.printFile("};")

gr.printFile("ApplicationType ExecutingApp[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    INVALID_OSAPPLICATION,")
gr.printFile("};")

gr.printFile("SystemReadyListRefType SystemReadyList[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    &SystemReadyList_{},".format(core_ID))
gr.printFile("};")

gr.printFile("SystemObjectsRefType SystemObjects[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    &SystemObjects_{},".format(core_ID))
gr.printFile("};\n")

for core_ID in core_list:
    gr.printFile("SystemObjectAutosarType SystemObjectAutosar_{} = {}".format(core_ID, "{"))
    gr.printFile("    TASKS_COUNT_{},".format(core_ID.upper()))
    gr.printFile("    ISR_ALL_COUNT_{},".format(core_ID.upper()))
    gr.printFile("    ALARMS_COUNT_{},".format(core_ID.upper()))
    gr.printFile("    COUNTERS_COUNT_{},".format(core_ID.upper()))
    gr.printFile("    SCHEDULETABLE_COUNT_{},".format(core_ID.upper()))
    gr.printFile("    RESOURCES_COUNT_{},".format(core_ID.upper()))
    gr.printFile("    TRUSTED_FUNC_COUNT_{},".format(core_ID.upper()))
    gr.printFile("    TaskAutosar_{},".format(core_ID))
    gr.printFile("    IsrAutosar_{},".format(core_ID))
    gr.printFile("    AlarmAutosar_{},".format(core_ID))
    gr.printFile("    CounterAutosar_{},".format(core_ID))
    gr.printFile("    ScheduleTableAutosar_{},".format(core_ID))
    gr.printFile("    ResourceAutosar_{},".format(core_ID))
    gr.printFile("    Ioc_channel_sender,")
    gr.printFile("    Ioc_channel_receiver,")
    gr.printFile("    PeripherilAutosar_core0,".format(core_ID))
    
    trustedFun_core = trustedFun_cores[core_ID]
    if trustedFun_core != []: 
        gr.printFile("    TrustedFuncAutosar_{},".format(core_ID))
    else:
        gr.printFile("    FALSE")
    gr.printFile("};\n")

gr.printFile("SystemObjectAutosarRefType SystemObjectAutosar[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    &SystemObjectAutosar_{},".format(core_ID))
gr.printFile("};\n")


for core_ID in core_list:
    gr.printFile("ApplicationType AppsInCore_{}[APPLICATIONS_COUNT_{}] = {}".format(core_ID, core_ID.upper(), "{"))
    apps = config.getList("/AUTOSAR","OsApplication")
    if core_ID == 'core0':
        for app in app_core0:
            gr.printFile("    {},".format(app))
    else:
        for app in app_core1:
            gr.printFile("    {},".format(app))
    gr.printFile("};\n")


gr.printFile("AppsInCoreType SystemAppsInCore[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    {")
    gr.printFile("        AppsInCore_{},".format(core_ID))
    gr.printFile("        APPLICATIONS_COUNT_{},".format(core_ID.upper()))
    gr.printFile("    },\n")
gr.printFile("};\n")

gr.printFile("CoreIdType CoreIdPhyToLogArray[TotalNumberOfCores] = {")
count = 0
for core_ID in core_list:
    gr.printFile("    OS_CORE_ID_{}, /* PE{} */".format(count, count+1))
    count += 1
gr.printFile("};\n")

gr.printFile("CoreStatusType CoreStatus[TotalNumberOfCores] = {")
gr.printFile("    /* OS_CORE_ID_0 */")
gr.printFile("    {")
gr.printFile("        1, /*is autosar OS */")
gr.printFile("        beforeStartOS /* Activate state */")
gr.printFile("    },")
gr.printFile("    /* OS_CORE_ID_1 */")
gr.printFile("    {")
gr.printFile("        1, /*is autosar OS */")
gr.printFile("        nonActivatedCore /* Activate state */")
gr.printFile("    }")
gr.printFile("};\n")


gr.printFile("uint16 NumberOfActivatedCore = 1;\n")

gr.printFile("SimuEcucPartitionSettingType EcucPartitionSettingArr[EcucPartitionSettingNum] = {")
gr.printFile("    {")
gr.printFile("        \"Renesas Rh850f1h\",")
gr.printFile("        \"Renesas Rh850g3m\",")
gr.printFile("        2,")
gr.printFile("        TRUE,")
gr.printFile("    },")
gr.printFile("};\n")

gr.printFile("AppModeType AppModeArray[TotalNumberOfCores];\n")

gr.printFile("uint8 CoreIntFlag[OsNumberOfCores];\n")

gr.printFile("LockType CoreParaLock[OsNumberOfCores];\n")

gr.printFile("ServiceParaType CrossCoreServicePara[OsNumberOfCores];   /* used for cross-core */\n")

gr.printFile("uint8 app_start_up_hook_err_flag[OsNumberOfCores];")
gr.printFile("uint8 app_shut_down_hook_err_flag[OsNumberOfCores];\n")

gr.printFile("uint32 CurrentExecServiceID[OsNumberOfCores];              /* used for info in error-hook */")
gr.printFile("ServiceParaType DebugServicePara[OsNumberOfCores];         /* used for info in error-hook */\n")


for core_ID in core_list:
    gr.printFile("ApplicationType TF_NestedOwnerArray_{}[MAX_STACK_FOR_NESTED_TF_CALL];".format(core_ID))

gr.printFile("ApplicationRefType TF_NestedOwnerArray[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    TF_NestedOwnerArray_{},".format(core_ID))
gr.printFile("};\n")


gr.printFile("IdleModeType NowIdleMode[OsNumberOfCores];")
gr.printFile("IdleModeType NextIdleMode[OsNumberOfCores];")
gr.printFile("LockType lockForIdleMode[OsNumberOfCores];\n")

gr.printFile("/* SysTask management data */")
for core_ID in core_list:
    gr.printFile("TaskType beforeSysTask_{} = INVALID_TASK_ID;".format(core_ID))

gr.printFile("TaskType beforeSysTask[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    INVALID_TASK_ID,")
gr.printFile("};")

for core_ID in core_list:
    gr.printFile("SysTaskInformationType SysTaskAction_{}[SysTaskActionQueueLength];".format(core_ID))

for core_ID in core_list:
    gr.printFile("SysTaskActionQueueType SysTaskActionQueue_{} = {}".format(core_ID, "{"))
    gr.printFile("    SysTaskAction_{},".format(core_ID))
    gr.printFile("    SysTaskActionQueueLength,")
    gr.printFile("    0,")
    gr.printFile("    0,")
    gr.printFile("    TRUE,")
    gr.printFile("};\n")

gr.printFile("SysTaskActionQueueType *SysTaskActionQueue[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    &SysTaskActionQueue_{},".format(core_ID))
gr.printFile("};\n")

gr.printFile("#pragma section\n") 

gr.printFile("const uint32 TempConst = 10;\n")

gr.printFile("SysTaskInformationType* const CurrentAction[OsNumberOfCores] = {")
for core_ID in core_list:
    gr.printFile("    &CurrentAction_{},".format(core_ID))
gr.printFile("};")
for core_ID in core_list:
    gr.printFile("#pragma section TASK_SysTask_{}".format(core_ID))
    gr.printFile("SysTaskInformationType CurrentAction_{};\n".format(core_ID))


gr.printFile("#pragma section\n")
gr.printFile("/*==================[internal functions definition]==========================*/\n")
gr.printFile("/*==================[external functions definition]==========================*/\n")
gr.printFile("/*==================[end of file]============================================*/\n")
