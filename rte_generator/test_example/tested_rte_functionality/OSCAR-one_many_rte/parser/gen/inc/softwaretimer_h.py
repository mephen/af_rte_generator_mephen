from generator.config import config 
from gen.inc.counter_Cfg_h import counter_core0, counter_core1 
from generator import globals as gr

global config
global counter_core0, counter_core1
gr.genfile = open(gr.inc_path+"softwaretimer_Cfg.h",'w')

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"\n")

gr.printFile("/*==================[macros]=================================================*/")
counters = config.getList("/AUTOSAR","OsCounter")
apps = config.getList("/AUTOSAR","OsApplication")

gr.printFile("#define SOFTWARETIMERS_COUNT_CORE0 1")
gr.printFile("#define SOFTWARETIMERS_COUNT_CORE1 1")
gr.printFile("#define SOFTWARETIMERS_COUNT 2")
gr.printFile("#define COUNTERS_COUNT_COUNTERLIST_1 {}".format(len(counter_core0)))
gr.printFile("#define COUNTERS_COUNT_COUNTERLIST_2 {}".format(len(counter_core1)))

gr.printFile("#define softwaretimer1 0x00000000")
gr.printFile("#define softwaretimer2 0x00010000")

gr.printFile("/*==================[external data declaration]=========================*/\n")
gr.printFile("/* brief Counter Var Structure */")
gr.printFile("extern SoftwareTimerVarType SoftwareTimerVar_core0[SOFTWARETIMERS_COUNT_CORE0];")
gr.printFile("extern SoftwareTimerVarType SoftwareTimerVar_core1[SOFTWARETIMERS_COUNT_CORE1];\n")

gr.printFile("/* brief Counter Const Structure */")
gr.printFile("extern const SoftwareTimerConstType SoftwareTimerConst_core0[SOFTWARETIMERS_COUNT_CORE0];")
gr.printFile("extern const SoftwareTimerConstType SoftwareTimerConst_core1[SOFTWARETIMERS_COUNT_CORE1];")
gr.printFile("extern uint32 HARDWARETIMER_PERIOD[OsNumberOfCores];")