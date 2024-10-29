from itertools import repeat
from generator.config import config 
from generator import globals as gr
from gen.cores import task_cores

global config
global task_cores

gr.genfile = open(gr.src_path + "event_Cfg.c",'w')

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"event_Cfg.h\"")

gr.printFile("/*==================[external data definition]===============================*/")
gr.printFile("#pragma section")



gr.printFile("/* Brief EventsVar Array */")
gr.printFile("EventsVarType EventsVar_core0[EXTENDED_TASKS_COUNT_CORE0] = {")
for task in task_cores['core0']:
    extended = config.getValue("/AUTOSAR/" + task, "OsTaskType")
    if extended == "EXTENDED":
        gr.printFile ("    /* Task {} */".format(task))
        gr.printFile ("    {")
        gr.printFile ("        0, /* eventsSet */")
        gr.printFile ("        0  /* eventsWait */")
        gr.printFile ("    },")
gr.printFile ("};\n")

gr.printFile ("EventsVarType EventsVar_core1[EXTENDED_TASKS_COUNT_CORE1] = {")
for task in task_cores['core1']:
    type = config.getValue("/AUTOSAR/" + task, "OsTaskType")
    if type == "EXTENDED":
        gr.printFile ("    /* Task {} */".format(task))
        gr.printFile ("    {")
        gr.printFile ("        0, /* eventsSet */")
        gr.printFile ("        0  /* eventsWait */")
        gr.printFile ("    },")
gr.printFile ("};\n")

gr.printFile ("#pragma section")