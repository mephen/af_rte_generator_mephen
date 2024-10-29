from generator.config import config 
from gen.inc.counter_Cfg_h import counter_core0, counter_core1
from generator import globals as gr

global config
global counter_core0, counter_core1
gr.genfile = open(gr.src_path+"softwaretimer_Cfg.c",'w')

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"application_Cfg.h\"")
gr.printFile("#include \"softwaretimer_Cfg.h\"")
gr.printFile("#include \"counter_Cfg.h\"")
gr.printFile("#pragma section")
 
gr.printFile("/*==================[macros]=================================================*/")
os = config.getValue("/AUTOSAR","OsOS")

gr.printFile("uint32 HARDWARETIMER_PERIOD[OsNumberOfCores] = {")
gr.printFile("    1, /* 1ms */")
if config.getValue("/AUTOSAR/" + os,"OsNumberOfCores") == "2":
    gr.printFile("    1, /* 1ms */")
gr.printFile("};")

if counter_core0 !=[]:
    gr.printFile("CounterType CounterList_1[COUNTERS_COUNT_COUNTERLIST_1] = {")
    for counter in counter_core0:
        gr.printFile("    {},".format(counter))
gr.printFile("};")

if counter_core1 !=[]:
    gr.printFile("CounterType CounterList_2[COUNTERS_COUNT_COUNTERLIST_2] = {")
    for counter in counter_core1:
        gr.printFile("    {},".format(counter))
gr.printFile("};")

if counter_core0 != []:
    gr.printFile("SoftwareTimerVarType SoftwareTimerVar_core0[SOFTWARETIMERS_COUNT_CORE0] = {")
    gr.printFile("    /* SoftwareTimer softwaretimer1 */")
    gr.printFile("    {")
    gr.printFile("        0, /* current ticks */")
    gr.printFile("        0, /* current counts */")
    gr.printFile("    },")
    gr.printFile("};")

if counter_core1 != []:
    gr.printFile("SoftwareTimerVarType SoftwareTimerVar_core1[SOFTWARETIMERS_COUNT_CORE1] = {")
    gr.printFile("    /* SoftwareTimer softwaretimer2 */")
    gr.printFile("    {")
    gr.printFile("        0, /* current ticks */")
    gr.printFile("        0, /* current counts */")
    gr.printFile("    },")
    gr.printFile("};")

if counter_core0 != []:
    gr.printFile("const SoftwareTimerConstType SoftwareTimerConst_core0[SOFTWARETIMERS_COUNT_CORE0] = {")
    gr.printFile("    /* SoftwareTimer softwaretimer1 */")
    gr.printFile("    {")
    gr.printFile("        1000, /* maximum value of softwaretimer */")
    gr.printFile("        1, /* the number of hardware ticks to count once */")
    gr.printFile("        CounterList_1,  /* counter list */")
    gr.printFile("        0 /* counter list length*/")
    gr.printFile("    },")
    gr.printFile("};")

if counter_core1 != []:
    gr.printFile("const SoftwareTimerConstType SoftwareTimerConst_core1[SOFTWARETIMERS_COUNT_CORE1] = {")
    gr.printFile("    /* SoftwareTimer softwaretimer2 */")
    gr.printFile("    {")
    gr.printFile("        1000, /* maximum value of softwaretimer */")
    gr.printFile("        1, /* the number of hardware ticks to count once */")
    gr.printFile("        CounterList_2,  /* counter list */")
    gr.printFile("        0 /* counter list length*/")
    gr.printFile("    },")
    gr.printFile("};")    

gr.printFile("#pragma section")