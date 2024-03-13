from generator.config import config 
from generator import globals as gr
#import generator.generators as gr

global config
gr.genfile = open(gr.inc_path+"timingprot_Cfg.h",'w')


gr.printFile("#ifndef TIMINGPROT_CFG_H")
gr.printFile("#define TIMINGPROT_CFG_H\n")
gr.printFile("#include \"typedefine.h\"")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("#include \"resource_Cfg.h\"")
gr.printFile("#include \"os_Cfg.h\"\n")

gr.printFile("extern TimingProtCounterType TaskExecutingCounter_core0[TASK_OBJECTS_COUNT_CORE0];")
gr.printFile("extern TimingProtCounterType TaskArrivalCounter_core0[TASK_OBJECTS_COUNT_CORE0];")
gr.printFile("extern TimingProtCounterType ResourceTimingCounter_core0[RESOURCES_COUNT_CORE0];")
gr.printFile("extern TimingProtCounterType InterruptTimingCounter_core0[3];\n")

gr.printFile("extern TimingProtCounterType TaskExecutingCounter_core1[TASK_OBJECTS_COUNT_CORE1];")
gr.printFile("extern TimingProtCounterType TaskArrivalCounter_core1[TASK_OBJECTS_COUNT_CORE1];")
gr.printFile("extern TimingProtCounterType ResourceTimingCounter_core1[RESOURCES_COUNT_CORE1];")
gr.printFile("extern TimingProtCounterType InterruptTimingCounter_core1[3];\n")

gr.printFile("extern TimingProtCounterType *TimingCounterList[OsNumberOfCores];")
gr.printFile("extern SystemTimingCounterType SystemTimingCounter[OsNumberOfCores];")
gr.printFile("#endif")