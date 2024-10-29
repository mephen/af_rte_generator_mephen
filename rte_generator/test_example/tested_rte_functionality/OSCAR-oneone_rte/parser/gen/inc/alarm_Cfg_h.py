from generator.config import config 
from gen.cores import alarm_cores, ST_cores
from generator import globals as gr

global config
global alarm_cores, ST_cores
global alarms_core0, alarms_core1
gr.genfile = open(gr.inc_path+"alarm_Cfg.h",'w')

def translate_hex(dnumber):
    num=hex(dnumber)
    num = num.split("x")
    num = "0"+ "x"+ num[-1].zfill(8)
    return num


gr.printFile("#ifndef ALARM_CFG_H")
gr.printFile("#define ALARM_CFG_H")

gr.printFile("/* This file content the generated configuration of alarm */")
gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"")
gr.printFile("/*==================[macros]=================================================*/")
gr.printFile("/* Brief Definition of the DeclareAlarmCallback Macro */")
gr.printFile("#define DeclareCallback(name) void MILKSHOP_CALLBACK_ ## name (void)")


alarms = config.getList("/AUTOSAR", "OsAlarm")
alarms_autostart_core0 = []
alarms_autostart_core1 = []
callbacks = []

#/* Define alarms count */
alarms_core0 = alarm_cores['core0']
alarms_core0 = set(alarms_core0)
alarms_core0 = list(alarms_core0)
for st in ST_cores['core0']:
    alarmST = "alarm_" + st
    alarms_core0.append(alarmST)
alarms_count_core0 = len(alarms_core0)

alarms_core1 = alarm_cores['core1']
alarms_core1 = set(alarms_core1)
alarms_core1 = list(alarms_core1)
for st in ST_cores['core1']:
    alarmST = "alarm_" + st
    alarms_core1.append(alarmST)
alarms_count_core1 = len(alarms_core1)

alarms_count = alarms_count_core0 + alarms_count_core1


for alarm in alarms_core0:
    if config.getValue("/AUTOSAR/" + alarm, "OsAlarmAutostart"):
        alarms_autostart_core0.append(alarm)
       
    #/* get the callback function name */
    action = config.getValue("/AUTOSAR/" + alarm, "OsAlarmAction")
    if(action == "OsAlarmCallback"):
        callbacks.append( config.getValue("/AUTOSAR/" + alarm + "/OsAlarmCallback", "OsAlarmCallbackName"))

for alarm in alarms_core1:
    if config.getValue("/AUTOSAR/" + alarm, "OsAlarmAutostart"):
        alarms_autostart_core1.append(alarm)
       
    #/* get the callback function name */
    action = config.getValue("/AUTOSAR/" + alarm, "OsAlarmAction")
    if(action == "OsAlarmCallback"):
        callbacks.append( config.getValue("/AUTOSAR/" + alarm + "/OsAlarmCallback", "OsAlarmCallbackName"))



gr.printFile ("/* brief ALARMS_COUNT define */")
gr.printFile ("#define ALARMS_COUNT_CORE0 {} ".format(alarms_count_core0) )
gr.printFile ("#define ALARMS_COUNT_CORE1 {} ".format(alarms_count_core1) )
gr.printFile ("#define ALARMS_COUNT {} ".format(alarms_count) )

alarms_autostart_core0 = []
alarms_autostart_core1 = []
alarms_autostart_count = len(alarms_autostart_core0) + len(alarms_autostart_core1)
gr.printFile ("/* brief ALARMS_AUTOSTART_COUNT define */")
gr.printFile ("#define ALARMS_AUTOSTART_COUNT_CORE0 {} ".format( len(alarms_autostart_core0) ))
gr.printFile ("#define ALARMS_AUTOSTART_COUNT_CORE1 {} ".format( len(alarms_autostart_core1) ))
gr.printFile ("#define ALARMS_AUTOSTART_COUNT {} ".format(alarms_autostart_count) )


count = 0
for alarm in alarms_core0:
    gr.printFile ("/* brief Definition of the Alarm {} */".format(alarm))
    gr.printFile ("#define {} {}".format( alarm , translate_hex(count)) )
    count += 1

gr.printFile("\n")

count = 65536
for alarm in alarms_core1:
    gr.printFile ("/* brief Definition of the Alarm {} */".format(alarm))
    gr.printFile ("#define {} {}".format( alarm , translate_hex(count)) )
    count += 1

gr.printFile("\n")
gr.printFile("#define INVALID_ALARM_ID 0x00020000\n")

gr.printFile("/*==================[external data declaration]=========================*/")
if(alarms_count > 0):
    gr.printFile ("/* brief Alarm Variable Structure */")
    gr.printFile ("extern AlarmVarType AlarmVar_core0[ALARMS_COUNT_CORE0];")
    gr.printFile ("extern AlarmVarType AlarmVar_core1[ALARMS_COUNT_CORE1];\n")

    gr.printFile ("/* brief Alarm Constant Structure */")
    gr.printFile ("extern const AlarmConstType AlarmConst_core0[ALARMS_COUNT_CORE0];")
    gr.printFile ("extern const AlarmConstType AlarmConst_core1[ALARMS_COUNT_CORE1];\n")

    gr.printFile("/* brief Accessible App of Alarm */")
    gr.printFile("extern AlarmAutosarType AlarmAutosar_core0[ALARMS_COUNT_CORE0];")
    gr.printFile("extern AlarmAutosarType AlarmAutosar_core1[ALARMS_COUNT_CORE1];\n")

####
alarms_autostart_count = 0
if(alarms_autostart_count > 0):
    gr.printFile ("/* brief AutoStartAlarm Structure */")
    gr.printFile ("extern const AutoStartAlarmType AutoStartAlarm_core0[ALARMS_AUTOSTART_COUNT_CORE0];")
    gr.printFile ("extern const AutoStartAlarmType AutoStartAlarm_core1[ALARMS_AUTOSTART_COUNT_CORE1];\n")



gr.printFile("/*==================[end of file]============================================*/")
gr.printFile ("#endif /* #ifndef ALARM_CFG_H */")
