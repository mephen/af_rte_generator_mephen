from generator.config import config 
from generator import globals as gr
from gen.cores import counter_cores, app_core0, app_core1, ST_cores
from gen.inc.counter_Cfg_h import counter_core0, counter_core1

global config
global counter_cores, app_core0, app_core1, ST_cores
global counter_core0, counter_core1
gr.genfile = open(gr.src_path+"counter_Cfg.c",'w')

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"counter_Cfg.h\"")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"application_Cfg.h\"\n")
gr.printFile("#pragma section\n")

counters = config.getList("/AUTOSAR","OsCounter")
apps = config.getList("/AUTOSAR","OsApplication")


if counter_core0 != []:
    gr.printFile("/* Brief CounterVar Array */")
    gr.printFile("CounterVarType CounterVar_core0[COUNTERS_COUNT_CORE0] = {")
    for counter in counter_core0:
        gr.printFile("    /* Counter {} */".format(counter))
        gr.printFile("    {")
        gr.printFile("        NULL, /* pointer to first alarm ready list */")
        gr.printFile("        NULL, /* pointer to next alarm to raise */")
        gr.printFile("        0, /* current system ticks since last count*/")
        gr.printFile("        0 /* current counter count */")
        gr.printFile("    },")
gr.printFile("};")

if counter_core1 != []:
    gr.printFile("/* Brief CounterVar Array */")
    gr.printFile("CounterVarType CounterVar_core1[COUNTERS_COUNT_CORE1] = {")
    for counter in counter_core1:
        gr.printFile("    /* Counter {} */".format(counter))
        gr.printFile("    {")
        gr.printFile("        NULL, /* pointer to first alarm ready list */")
        gr.printFile("        NULL, /* pointer to next alarm to raise */")
        gr.printFile("        0, /* current system ticks since last count*/")
        gr.printFile("        0 /* current counter count */")
        gr.printFile("    },")
gr.printFile("};\n")


if counter_core0 != []:
    gr.printFile("/* Brief CounterConst Array */")
    gr.printFile("const CounterConstType CounterConst_core0[COUNTERS_COUNT_CORE0] = {")
    for counter in counter_core0:
        gr.printFile("    /* Counter {} */".format(counter))
        gr.printFile("    {")
        if "ST" in counter:
            for st in ST_cores['core0']:
                if st in counter:
                    duration = config.getValue("/AUTOSAR/" + st, "OsScheduleTableDuration")
                    gr.printFile("        {}, /* maximum value of counter */".format(int(duration)-1))
            min_cycle = config.getValue("/AUTOSAR/" + counter, "OsCounterMinCycle")
            gr.printFile("        10, /* minimum count for a cyclic alarm linked to the counter */".format(min_cycle))
            counter_tick = config.getValue("/AUTOSAR/" + counter, "OsCounterTicksPerBase")
            gr.printFile("        10, /* the number of hardware ticks to count once */".format(counter_tick))
            counter_type = config.getValue("/AUTOSAR/" + counter, "OsCounterType")
            gr.printFile("        SOFTWARE /* osCounterType */".format(counter_type))
        else:
            max_value = config.getValue("/AUTOSAR/" + counter, "OsCounterMaxAllowedValue")
            gr.printFile("        {}, /* maximum value of counter */".format(max_value))
            min_cycle = config.getValue("/AUTOSAR/" + counter, "OsCounterMinCycle")
            gr.printFile("        {}, /* minimum count for a cyclic alarm linked to the counter */".format(min_cycle))
            counter_tick = config.getValue("/AUTOSAR/" + counter, "OsCounterTicksPerBase")
            gr.printFile("        {}, /* the number of hardware ticks to count once */".format(counter_tick))
            counter_type = config.getValue("/AUTOSAR/" + counter, "OsCounterType")
            gr.printFile("        {} /* osCounterType */".format(counter_type))
        
        gr.printFile("    },")
gr.printFile("};")

if counter_core1 != []:
    gr.printFile("/* Brief CounterConst Array */")
    gr.printFile("const CounterConstType CounterConst_core1[COUNTERS_COUNT_CORE1] = {")
    for counter in counter_core1:
        gr.printFile("    /* Counter {} */".format(counter))
        gr.printFile("    {")
        if "ST" in counter:
            gr.printFile("        500, /* maximum value of counter */".format(max_value))
            min_cycle = config.getValue("/AUTOSAR/" + counter, "OsCounterMinCycle")
            gr.printFile("        10, /* minimum count for a cyclic alarm linked to the counter */".format(min_cycle))
            counter_tick = config.getValue("/AUTOSAR/" + counter, "OsCounterTicksPerBase")
            gr.printFile("        10, /* the number of hardware ticks to count once */".format(counter_tick))
            counter_type = config.getValue("/AUTOSAR/" + counter, "OsCounterType")
            gr.printFile("        HARDWARE /* osCounterType */".format(counter_type))
        else:
            max_value = config.getValue("/AUTOSAR/" + counter, "OsCounterMaxAllowedValue")
            gr.printFile("        {}, /* maximum value of counter */".format(max_value))
            min_cycle = config.getValue("/AUTOSAR/" + counter, "OsCounterMinCycle")
            gr.printFile("        {}, /* minimum count for a cyclic alarm linked to the counter */".format(min_cycle))
            counter_tick = config.getValue("/AUTOSAR/" + counter, "OsCounterTicksPerBase")
            gr.printFile("        {}, /* the number of hardware ticks to count once */".format(counter_tick))
            counter_type = config.getValue("/AUTOSAR/" + counter, "OsCounterType")
            gr.printFile("        {} /* osCounterType */".format(counter_type))
        gr.printFile("    },")
gr.printFile("};")

if counter_core0 != []:
    gr.printFile("CounterAutosarType CounterAutosar_core0[COUNTERS_COUNT_CORE0] = {")
    for counter in counter_core0:
        if "ST" in counter:
            gr.printFile("    /* Counter {} */".format(counter))
            gr.printFile("    {")
            for scheduletable in ST_cores['core0']:
                scheduleTableSync = config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableSync")
                scheduleTblSyncStrategy = config.getValue("/AUTOSAR/" + scheduletable + "/" + scheduleTableSync, "OsScheduleTblSyncStrategy")
                if scheduleTblSyncStrategy == "EXPLICIT":
                    if scheduletable in counter:
                        for app in app_core0:
                            if scheduletable in config.getList("/AUTOSAR/" + app ,"OsAppScheduleTableRef"):
                                gr.printFile("        {},".format(app))
                                break
                        application = config.getList("/AUTOSAR/" + scheduletable ,"OsSchTblAccessingApplication")
                        if application != []:
                            gr.printFileSpace("        0 ")
                            for app in application:
                                gr.printFileSpace("| (1 << {}) ".format(app)) 
                            gr.printFile(",")
                        else:
                            gr.printFileSpace("        0,")
            gr.printFile("    },")

        else:
            gr.printFile("    /* Counter {} */".format(counter))
            gr.printFile("    {")
            for app in apps:
                counter_app = config.getValue("/AUTOSAR/" + app,"OsAppCounterRef")
                if counter == counter_app:
                    gr.printFile("        {}, /* owner application of the counter */".format(app))
                    gr.printFile("        0 | (1 << {}), /* application mask */".format(app))    
            gr.printFile("    },")
gr.printFile("};")

if counter_core1 != []:
    gr.printFile("CounterAutosarType CounterAutosar_core1[COUNTERS_COUNT_CORE1] = {")
    for counter in counter_core1:
        if "ST" in counter:
            gr.printFile("    /* Counter {} */".format(counter))
            gr.printFile("    {")
            for scheduletable in ST_cores['core1']:
                scheduleTableSync = config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableSync")
                scheduleTblSyncStrategy = config.getValue("/AUTOSAR/" + scheduletable + "/" + scheduleTableSync, "OsScheduleTblSyncStrategy")
                if scheduleTblSyncStrategy == "EXPLICIT":
                    if scheduletable in counter:
                        for app in app_core0:
                            if scheduletable in config.getList("/AUTOSAR/" + app ,"OsAppScheduleTableRef"):
                                gr.printFile("        {},".format(app))
                                break
                        application = config.getList("/AUTOSAR/" + scheduletable ,"OsSchTblAccessingApplication")
                        if application != []:
                            gr.printFileSpace("        0 ")
                            for app in application:
                                gr.printFileSpace("| (1 << {}) ".format(app)) 
                            gr.printFile(",")
                        else:
                            gr.printFileSpace("        0,")
            gr.printFile("    },")

        else:
            gr.printFile("    /* Counter {} */".format(counter))
            gr.printFile("    {")
            for app in apps:
                counter_app = config.getValue("/AUTOSAR/" + app,"OsAppCounterRef")
                if counter == counter_app:
                    gr.printFile("        {}, /* owner application of the counter */".format(app))
                    gr.printFile("        0 | (1 << {}), /* application mask */".format(app))    
            gr.printFile("    },")
gr.printFile("};")

gr.printFile("#pragma section")
