from generator.config import config
from gen.cores import app_cores, ST_cores, app_core0, app_core1
from generator import globals as gr

global config
global app_cores, ST_cores, app_core0, app_core1
gr.genfile = open(gr.src_path+"application_Cfg.c",'w')

App_Count = 0
Trusted_App_Count = 0
Trusted_Function_Count = 0

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"application_Cfg.h\"")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"alarm_Cfg.h\"")
gr.printFile("#include \"counter.h\"")
gr.printFile("#include \"scheduletable_Cfg.h\"")
gr.printFile("#include \"isr_Cfg.h\"")
gr.printFile("#include \"trustedFunc_Cfg.h\"")
gr.printFile("#include \"memsection.h\"")
gr.printFile("#include \"memprot_Cfg.h\"")
gr.printFile("#include \"resource_Cfg.h\"")


gr.printFile("/*==================[macros and definitions]=================================*/\n")
gr.printFile("/*==================[internal data declaration]==============================*/\n")
gr.printFile("/*==================[internal functions declaration]=========================*/\n")
gr.printFile("/*==================[external functions declaration]=========================*/\n")
gr.printFile("/* Brief per-OsApp Hook */")
apps = config.getList("/AUTOSAR","OsApplication")
for app in apps:
    gr.printFile("extern void StartupHook_OSAPP_{}(void);".format(app))
    gr.printFile("extern void ShutdownHook_OSAPP_{}(StatusType Error);".format(app))
    gr.printFile("extern void ErrorHook_OSAPP_{}(StatusType Error);\n".format(app))
    
gr.printFile("/*==================[internal data definition]===============================*/\n")
gr.printFile("#pragma section\n")
gr.printFile("#define ZERO_OBJECT_DUMMY_COUNT 1\n")

for app in apps:
    count1 = config.getCount("/AUTOSAR/" + app,"OsAppTaskRef")
    count2 = config.getCount("/AUTOSAR/" + app,"OsAppCounterRef")
    counterST = 0
    sts = config.getList("/AUTOSAR/" + app,"OsAppScheduleTableRef")
    for st in sts:
        scheduleTableSync = config.getValue("/AUTOSAR/" + st, "OsScheduleTableSync")
        scheduleTblSyncStrategy = config.getValue("/AUTOSAR/" + st + "/" + scheduleTableSync, "OsScheduleTblSyncStrategy")
        if scheduleTblSyncStrategy == "EXPLICIT":
            counterST += 1
    count3 = config.getCount("/AUTOSAR/" + app,"OsAppAlarmRef")
    count4 = config.getCount("/AUTOSAR/" + app,"OsAppScheduleTableRef")
    count5 = config.getCount("/AUTOSAR/" + app,"OsAppIsrRef")
    gr.printFile("#define TASKS_COUNT_{} {}".format(app, count1))
    gr.printFile("#define COUNTERS_COUNT_{} {}".format(app, count2 + counterST))
    gr.printFile("#define ALARMS_COUNT_{} {}".format(app, count3 + count4))
    gr.printFile("#define SCHEDULETABLES_COUNT_{} {}".format(app, count4))
    gr.printFile("#define ISRS_COUNT_{} {}".format(app, count5))
    count6 = config.getCount("/AUTOSAR/" + app, "OsApplicationTrustedFunction")
    gr.printFile("#define TRUSTEDFUNC_COUNT_{} {}\n".format(app, count6))


if app_core0 !=[]:
    gr.printFile("/* core0 */")
    for app in app_core0:
        gr.printFile("/********[{}]*********/".format(app))
        
        tasks = config.getList("/AUTOSAR/" + app,"OsAppTaskRef")
        counters = config.getList("/AUTOSAR/" + app,"OsAppCounterRef")
        alarms = config.getList("/AUTOSAR/" + app,"OsAppAlarmRef")
        ScheduleTables = config.getList("/AUTOSAR/" + app,"OsAppScheduleTableRef")

        if tasks != []:
            gr.printFile("TaskType Tasks_{}[TASKS_COUNT_{}] = {}".format(app, app, "{"))
            for task in tasks:
                if task == tasks[-1]:
                    gr.printFile("    {}".format(task))
                else:
                    gr.printFile("    {},".format(task))
            gr.printFile("};\n")
        else:
            gr.printFile("TaskType Tasks_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_TASK_ID")
            gr.printFile("};\n")

        if counters != []:
            gr.printFile("CounterType Counters_{}[COUNTERS_COUNT_{}] = {}".format(app, app, "{"))
            for counter in counters:
                gr.printFile("    {},".format(counter))
            for st in ScheduleTables:
                scheduleTableSync = config.getValue("/AUTOSAR/" + st, "OsScheduleTableSync")
                scheduleTblSyncStrategy = config.getValue("/AUTOSAR/" + st + "/" + scheduleTableSync, "OsScheduleTblSyncStrategy")
                if scheduleTblSyncStrategy == "EXPLICIT":
                    gr.printFile("    counter_{},".format(st))
            gr.printFile("};\n")
        else:
            gr.printFile("CounterType Counters_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_COUNTER_ID")
            gr.printFile("};\n")    


        if alarms != []:
            gr.printFile("AlarmType Alarms_{}[ALARMS_COUNT_{}] = {}".format(app, app, "{"))
            for alarm in alarms:
                gr.printFile("    {},".format(alarm))
            
            for st in ScheduleTables:
                gr.printFile("    alarm_{},".format(st))
            gr.printFile("};\n")
        else:
            gr.printFile("AlarmType Alarms_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_ALARM_ID")
            gr.printFile("};\n")   

        
        if ScheduleTables != []:
            gr.printFile("ScheduleTableType ScheduleTables_{}[SCHEDULETABLES_COUNT_{}] = {}".format(app, app, "{"))
            for scheduletable in ScheduleTables:
                if scheduletable == ScheduleTables[-1]:
                    gr.printFile("    {}".format(scheduletable))
                else:
                    gr.printFile("    {},".format(scheduletable))
            gr.printFile("};\n")
        else:
            gr.printFile("ScheduleTableType ScheduleTables_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_SCHEDULETABLE_ID")
            gr.printFile("};\n")   
        
        ISRs = config.getList("/AUTOSAR/" + app,"OsAppIsrRef")
        if ISRs != []:
            gr.printFile("ISRType Isrs_{}[ISRS_COUNT_{}] = {}".format(app, app, "{"))
            for isr in ISRs:
                if isr == ISRs[-1]:
                    gr.printFile("    {}".format(isr))
                else:
                    gr.printFile("    {},".format(isr))
            gr.printFile("};\n")
        else:
            gr.printFile("ISRType Isrs_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_ISR_ID")
            gr.printFile("};\n")
        
        TFs = config.getList("/AUTOSAR/" + app, "OsApplicationTrustedFunction")
        if TFs != []:
            gr.printFile("TrustedFunctionIndexType TrustedFunc_{}[TRUSTEDFUNC_COUNT_{}] = {}".format(app, app, "{"))
            for TF in TFs:
                TFname = config.getValue("/AUTOSAR/" + app + "/" + TF , "OsTrustedFunctionName")
                gr.printFile("    TF_{},".format(TFname))
            gr.printFile("};\n")
        else:
            gr.printFile("TrustedFunctionIndexType TrustedFunc_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_TF_ID")
            gr.printFile("};\n")


if app_core1 !=[]:
    gr.printFile("/* core1 */")
    for app in app_core1:
        gr.printFile("/********[{}]*********/".format(app))
        
        tasks = config.getList("/AUTOSAR/" + app,"OsAppTaskRef")
        counters = config.getList("/AUTOSAR/" + app,"OsAppCounterRef")
        alarms = config.getList("/AUTOSAR/" + app,"OsAppAlarmRef")
        ScheduleTables = config.getList("/AUTOSAR/" + app,"OsAppScheduleTableRef")
        
        if tasks != []:
            gr.printFile("TaskType Tasks_{}[TASKS_COUNT_{}] = {}".format(app, app, "{"))
            for task in tasks:
                if task == tasks[-1]:
                    gr.printFile("    {}".format(task))
                else:
                    gr.printFile("    {},".format(task))
            gr.printFile("};\n")
        else:
            gr.printFile("TaskType Tasks_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_TASK_ID")
            gr.printFile("};\n")


        
        if counters != []:
            gr.printFile("CounterType Counters_{}[COUNTERS_COUNT_{}] = {}".format(app, app, "{"))
            for counter in counters:
                gr.printFile("    {},".format(counter))
            for st in ScheduleTables:
                scheduleTableSync = config.getValue("/AUTOSAR/" + st, "OsScheduleTableSync")
                scheduleTblSyncStrategy = config.getValue("/AUTOSAR/" + st + "/" + scheduleTableSync, "OsScheduleTblSyncStrategy")
                if scheduleTblSyncStrategy == "EXPLICIT":
                    gr.printFile("    counter_{},".format(st))
            gr.printFile("};\n")
        else:
            gr.printFile("CounterType Counters_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_COUNTER_ID")
            gr.printFile("};\n")    

        
        if alarms != []:
            gr.printFile("AlarmType Alarms_{}[ALARMS_COUNT_{}] = {}".format(app, app, "{"))
            for alarm in alarms:
                gr.printFile("    {},".format(alarm))
            
            for st in ScheduleTables:
                gr.printFile("    alarm_{},".format(st))
            gr.printFile("};\n")
        else:
            gr.printFile("AlarmType Alarms_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_ALARM_ID")
            gr.printFile("};\n")   

        
        if ScheduleTables != []:
            gr.printFile("ScheduleTableType ScheduleTables_{}[SCHEDULETABLES_COUNT_{}] = {}".format(app, app, "{"))
            for scheduletable in ScheduleTables:
                if scheduletable == ScheduleTables[-1]:
                    gr.printFile("    {}".format(scheduletable))
                else:
                    gr.printFile("    {},".format(scheduletable))
            gr.printFile("};\n")
        else:
            gr.printFile("ScheduleTableType ScheduleTables_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_SCHEDULETABLE_ID")
            gr.printFile("};\n")   
        
        ISRs = config.getList("/AUTOSAR/" + app,"OsAppIsrRef")
        if ISRs != []:
            gr.printFile("ISRType Isrs_{}[ISRS_COUNT_{}] = {}".format(app, app, "{"))
            for isr in ISRs:
                if isr == ISRs[-1]:
                    gr.printFile("    {}".format(isr))
                else:
                    gr.printFile("    {},".format(isr))
            gr.printFile("};\n")
        else:
            gr.printFile("ISRType Isrs_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_ISR_ID")
            gr.printFile("};\n")

        TFs = config.getList("/AUTOSAR/" + app, "OsApplicationTrustedFunction")
        if TFs != []:
            gr.printFile("TrustedFunctionIndexType TrustedFunc_{}[TRUSTEDFUNC_COUNT_{}] = {}".format(app, app, "{"))
            for TF in TFs:
                TFname = config.getValue("/AUTOSAR/" + app + "/" + TF , "OsTrustedFunctionName")
                gr.printFile("    TF_{},".format(TFname))
            gr.printFile("};\n")
        else:
            gr.printFile("TrustedFunctionIndexType TrustedFunc_{}[ZERO_OBJECT_DUMMY_COUNT] = {}".format(app, "{"))
            gr.printFile("    INVALID_TF_ID")
            gr.printFile("};\n")

gr.printFile("/*==================[external data definition]===============================*/")
if app_core0 != []:
    gr.printFile("ApplicationObjectsType ApplicationObjects_core0[APPLICATIONS_COUNT_CORE0] = {")
    for app in app_core0:
        gr.printFile("    /* {} */".format(app))
        gr.printFile("    {")
        gr.printFile("        /* Tasks */")
        gr.printFile("        {")
        gr.printFile("            Tasks_{},".format(app))
        gr.printFile("            TASKS_COUNT_{}".format(app))
        gr.printFile("        },")
        
        gr.printFile("        /* Counters */")
        gr.printFile("        {")
        gr.printFile("            Counters_{},".format(app))
        gr.printFile("            COUNTERS_COUNT_{}".format(app))
        gr.printFile("        },")

        gr.printFile("        /* Alarms */")
        gr.printFile("        {")
        gr.printFile("            Alarms_{},".format(app))
        gr.printFile("            ALARMS_COUNT_{}".format(app))
        gr.printFile("        },")

        gr.printFile("        /* ScheduleTables */")
        gr.printFile("        {")
        gr.printFile("            ScheduleTables_{},".format(app))
        gr.printFile("            SCHEDULETABLES_COUNT_{}".format(app))
        gr.printFile("        },")


        gr.printFile("        /* ISRs */")
        gr.printFile("        {")
        gr.printFile("            Isrs_{},".format(app))
        gr.printFile("            ISRS_COUNT_{}".format(app))
        gr.printFile("        },")

        gr.printFile("        /* TFs */")
        gr.printFile("        {")
        gr.printFile("            TrustedFunc_{},".format(app))
        gr.printFile("            TRUSTEDFUNC_COUNT_{}".format(app))
        gr.printFile("        },")
        
        gr.printFile("    },")
gr.printFile("};\n")


if app_core1 != []:
    gr.printFile("ApplicationObjectsType ApplicationObjects_core1[APPLICATIONS_COUNT_CORE1] = {")
    for app in app_core1:
        gr.printFile("    /* {} */".format(app))
        gr.printFile("    {")
        gr.printFile("        /* Tasks */")
        gr.printFile("        {")
        gr.printFile("            Tasks_{},".format(app))
        gr.printFile("            TASKS_COUNT_{}".format(app))
        gr.printFile("        },")
        
        gr.printFile("        /* Counters */")
        gr.printFile("        {")
        gr.printFile("            Counters_{},".format(app))
        gr.printFile("            COUNTERS_COUNT_{}".format(app))
        gr.printFile("        },")

        gr.printFile("        /* Alarms */")
        gr.printFile("        {")
        gr.printFile("            Alarms_{},".format(app))
        gr.printFile("            ALARMS_COUNT_{}".format(app))
        gr.printFile("        },")

        gr.printFile("        /* ScheduleTables */")
        gr.printFile("        {")
        gr.printFile("            ScheduleTables_{},".format(app))
        gr.printFile("            SCHEDULETABLES_COUNT_{}".format(app))
        gr.printFile("        },")


        gr.printFile("        /* ISRs */")
        gr.printFile("        {")
        gr.printFile("            Isrs_{},".format(app))
        gr.printFile("            ISRS_COUNT_{}".format(app))
        gr.printFile("        },")

        gr.printFile("        /* TFs */")
        gr.printFile("        {")
        gr.printFile("            TrustedFunc_{},".format(app))
        gr.printFile("            TRUSTEDFUNC_COUNT_{}".format(app))
        gr.printFile("        },")
        
        gr.printFile("    },")
gr.printFile("};\n")


gr.printFile("ApplicationVarType ApplicationVar[APPLICATIONS_COUNT] = {")
core0_count = 0
core1_count = 0
for app in apps:
    gr.printFile("    /* Application {} */".format(app))
    gr.printFile("    {")
    gr.printFile("        {},  //ID".format(app))
    gr.printFile("        APPLICATION_ACCESSIBLE,")
    ostrusted = config.getValue("/AUTOSAR/" + app,"OsTrusted")
    gr.printFile("        {},                    //OsTrustedType OsTrusted;".format(ostrusted))
    gr.printFile("        ECUC_PARTITION_DEFAULT_ID,")
    gr.printFile("        {},".format(app_cores[app]))
    ostrusted_protection = config.getValue("/AUTOSAR/" + app,"OsTrustedApplicationWithProtection")
    if ostrusted_protection == False:
        gr.printFile("        FALSE, //uint8 OsTrustedApplicationWithProtection")
    else:
        gr.printFile("        {}, //uint8 OsTrustedApplicationWithProtection".format(ostrusted_protection))
    gr.printFile("        FALSE, //OsTrustedAppWithTimingProt")
    vcall = config.getValue("/AUTOSAR/" + app,"OsTrustedApplicationDelayTimingViolationCall")
    if vcall == False:
        gr.printFile("        FALSE, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this")
    else:
        gr.printFile("        {}, //OsTrustedApplicationDelayTimingViolationCall, only truted-app care this".format(vcall))
    retask = config.getValue("/AUTOSAR/" + app,"OsRestartTask")
    if retask != False:
        gr.printFile("        {}, //RestartTask".format(retask))
    else:
        gr.printFile("        FALSE, //RestartTask")
    if app_cores[app] == "OS_CORE_ID_0":
        index = app_core0.index(app)
        gr.printFile("        &ApplicationObjects_core0[{}],".format(index))
    else:
        index = app_core1.index(app)
        gr.printFile("        &ApplicationObjects_core1[{}],".format(index))

       
    gr.printFile("        //AppHookFuncArrayType AppHookFuncArray")
    gr.printFile("        {")
    gr.printFile("            StartupHook_OSAPP_{},".format(app))
    gr.printFile("            ShutdownHook_OSAPP_{},".format(app))
    gr.printFile("            ErrorHook_OSAPP_{},".format(app))
    gr.printFile("        },\n")

    gr.printFile("        //RomToRamInitTableType RomToRamInitTable")
    gr.printFile("        {")
    gr.printFile("            (uint32*)(_SOSAPP_{}_SEC_data),".format(app))
    gr.printFile("            (uint32*)(_EOSAPP_{}_SEC_data),".format(app))
    gr.printFile("            (uint32*)(_SOSAPP_{}_SEC_data_R),".format(app))
    gr.printFile("            (uint32*)(_SOSAPP_{}_SEC_bss),".format(app))
    gr.printFile("            (uint32*)(_EOSAPP_{}_SEC_bss)".format(app))
    gr.printFile("        },")
    gr.printFile("        MemProtArea_{},".format(app))
    gr.printFile("        resource{},".format(app))
    gr.printFile("    },")


gr.printFile("};")
gr.printFile("LockType lockForApplicationState[APPLICATIONS_COUNT];")

gr.printFile("/*==================[end of file]============================================*/")

gr.printFile("#pragma section")



