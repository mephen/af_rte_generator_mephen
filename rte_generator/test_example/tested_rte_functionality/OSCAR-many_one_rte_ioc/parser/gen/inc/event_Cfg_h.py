from itertools import repeat
from generator.config import config 
from generator import globals as gr


global config
gr.genfile = open(gr.inc_path + "event_Cfg.h",'w')


def translate_hex(dnumber):
    num=hex(dnumber)
    num = num.split("x")
    num = "0"+ "x"+ num[-1].zfill(2)
    return num


gr.printFile("#ifndef EVENT_CFG_H")
gr.printFile("#define EVENT_CFG_H")

gr.printFile("/* This file content the generated configuration of event */")
gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("/*==================[macros]=================================================*/")

gr.printFile("/* Define the events */")
events = config.getList("/AUTOSAR","OsEvent")
events_count = len(events)
if(events_count > 64):
    gr.error("The number of events can not be greater than 64")
else:
    gr.printFile ("/* brief Count of events */")
    gr.printFile ("#define EVENTS_COUNT {}\n".format(events_count))

for event in events:
    value = config.getValue("/AUTOSAR/" + event, "OsEventMask")
    value = int(value)
    gr.printFile ("/* brief Definition of the Event {} */".format(event))
    gr.printFile ("#define {} {}ULL".format(event, translate_hex(value)))

gr.printFile("/*==================[external data declaration]==============================*/")
Isextended =False
tasks = config.getList("/AUTOSAR", "OsTask")
for task in tasks:
    extended = config.getValue("/AUTOSAR/" + task, "OsTaskType")
    if (extended == "EXTENDED"):
        Isextended = True
        break

if(Isextended):
    gr.printFile ("extern EventsVarType EventsVar_core0[EXTENDED_TASKS_COUNT_CORE0];")
    gr.printFile ("extern EventsVarType EventsVar_core1[EXTENDED_TASKS_COUNT_CORE1];\n")
else:
    gr.printFile ("/* There is no extended task that is defined */\n")

gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* #ifndef EVENT_CFG_H */")




'''
for event in events:
    if(config.getValue("/AUTOSAR/" + event, "OsEventMask") == "AUTO"):
        auto_events.append(event)
    else:
        general_events.append(event)

#/* Define general events */
for event in general_events:
    value = config.getValue("/AUTOSAR/" + event, "OsEventMask")
    value = int("0x" + value, 16)

    #/* check the legitimacy */
    if(value & (value-1)):
        gr.error("The MASK value can only set one bit")

    flag[value] = 1
    gr.printFile ("/* brief Definition of the Event $event */")
    gr.printFile ("#define {} 0x{}ULL".format(event, translate_hex(value)))

i = 1
for event in auto_events:
    gr.printFile ("/* brief Definition of the Event {} */".format(event))
    while(flag[i]):
        i = i*2
    flag[i] = 1
    gr.printFile ("#define {} 0x{}ULL".format(event, translate_hex(i)))
'''