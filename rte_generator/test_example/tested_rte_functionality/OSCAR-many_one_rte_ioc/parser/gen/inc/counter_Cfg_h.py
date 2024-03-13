from generator.config import config 
from generator import globals as gr
from gen.cores import counter_cores, ST_cores

global config
global counter_cores, ST_cores
global counter_core0, counter_core1
gr.genfile = open(gr.inc_path+"counter_Cfg.h",'w')

counter_core0 = counter_cores['core0']
for st in ST_cores['core0']:
    scheduleTableSync = config.getValue("/AUTOSAR/" + st, "OsScheduleTableSync")
    scheduleTblSyncStrategy = config.getValue("/AUTOSAR/" + st + "/" + scheduleTableSync, "OsScheduleTblSyncStrategy")
    if scheduleTblSyncStrategy == "EXPLICIT":
        counterST = "counter_" + st
        counter_core0.append(counterST)

counter_core1 = counter_cores['core1']
if ST_cores['core1'] != []:
    for st in ST_cores['core1']:
        scheduleTableSync = config.getValue("/AUTOSAR/" + st, "OsScheduleTableSync")
        scheduleTblSyncStrategy = config.getValue("/AUTOSAR/" + st + "/" + str(scheduleTableSync), "OsScheduleTblSyncStrategy")
        if scheduleTblSyncStrategy == "EXPLICIT":
            counterST = "counter_" + st
            counter_core1.append(counterST)

def translate_hex(dnumber):
    num=hex(dnumber)
    num = num.split("x")
    num = "0"+ "x"+ num[-1].zfill(8)
    return num


gr.printFile("#ifndef COUNTER_CFG_H")
gr.printFile("#define COUNTER_CFG_H\n")

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"\n")

gr.printFile("/*==================[macros]=================================================*/")
#counters = config.getList("/AUTOSAR","OsCounter")
#apps = config.getList("/AUTOSAR","OsApplication")


gr.printFile("#define COUNTERS_COUNT_CORE0 {}".format(len(counter_core0)))
gr.printFile("#define COUNTERS_COUNT_CORE1 {}".format(len(counter_core1)))
Counter_Count = len(counter_core0) + len(counter_core1)
gr.printFile("#define COUNTERS_COUNT {}\n".format(Counter_Count))

for counter in counter_core0:
    gr.printFile("/* brief Definition of the Counter {} */".format(counter))
    index = counter_core0.index(counter)
    gr.printFile("#define {} {}".format(counter, translate_hex(index)))

for counter in counter_core1:
    gr.printFile("/* brief Definition of the Counter {} */".format(counter))
    index = counter_core1.index(counter) + 65536
    gr.printFile("#define {} {}".format(counter, translate_hex(index)))

gr.printFile("\n")
gr.printFile("#define INVALID_COUNTER_ID 0x00020000\n")

gr.printFile("/* brief Definition of the Counter DriveCounter */")
gr.printFile("#define DriveCounter 0\n")

gr.printFile("/*==================[external data declaration]=========================*/")
if len(counter_core0) > 0 or len(counter_core1) > 0:
    gr.printFile("/* brief Counter Var Structure */")
    gr.printFile("extern CounterVarType CounterVar_core0[COUNTERS_COUNT_CORE0];")
    gr.printFile("extern CounterVarType CounterVar_core1[COUNTERS_COUNT_CORE1];\n")

    gr.printFile("/* brief Counter Const Structure */")
    gr.printFile("extern const CounterConstType CounterConst_core0[COUNTERS_COUNT_CORE0];")
    gr.printFile("extern const CounterConstType CounterConst_core1[COUNTERS_COUNT_CORE1];\n")

    gr.printFile("/* brief Accessible App of Counter */")
    gr.printFile("extern CounterAutosarType CounterAutosar_core0[COUNTERS_COUNT_CORE0];")
    gr.printFile("extern CounterAutosarType CounterAutosar_core1[COUNTERS_COUNT_CORE1];\n")



gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* #ifndef COUNTER_CFG_H */")






