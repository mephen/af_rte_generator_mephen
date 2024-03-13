from generator.config import config 
from gen.cores import alarm_cores, ST_cores, app_core0, app_core1
from generator import globals as gr
from gen.inc.alarm_Cfg_h import alarms_core0, alarms_core1
global config
global alarm_cores, ST_cores, app_core0, app_core1
global alarms_core0, alarms_core1
gr.genfile = open(gr.src_path+"alarm_Cfg.c",'w')

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"alarm_Cfg.h\"")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("#include \"event_Cfg.h\"")
gr.printFile("#include \"application_Cfg.h\"")
gr.printFile("#include \"counter_Cfg.h\"")
gr.printFile("#include \"scheduleTable_Cfg.h\"")
gr.printFile("/*==================[external data declaration]==============================*/\n")
gr.printFile("#pragma section\n")

#alarms_core0 = alarm_cores['core0']
#alarms_core1 = alarm_cores['core1']

alarms_autostart_core0 = []
alarms_autostart_core1 = []

alarms_autostart_count_core0 = 0
alarms_autostart_count_core1 = 0

alarms_accessible_app_count = 0

callbacks = []

#/* Define alarms count */
alarms = config.getList("/AUTOSAR", "OsAlarm")
apps = config.getList("/AUTOSAR", "OsApplication")

#alarms_core0 = set(alarms_core0)
#alarms_core0 = list(alarms_core0)

#alarms_core1 = set(alarms_core1)
#alarms_core1 = list(alarms_core1)


if alarms_core0 != []:
    gr.printFile("/* Brief AlarmVar Array */")
    gr.printFile("AlarmVarType AlarmVar_core0[ALARMS_COUNT_CORE0] = {")
    for alarm in alarms_core0:
        if config.getValue("/AUTOSAR/" + alarm, "OsAlarmAutostart"):
            alarms_autostart_core0.append(alarm)
            #gr.printFile(alarm)
        
        gr.printFile("    /* Alarm {} */".format(alarm))
        gr.printFile("    {")
        gr.printFile("        NULL, /* pointer to next AlarmVar */")
        gr.printFile("        NULL, /* Pointer to previous AlarmVar */")
        gr.printFile("        {},".format(alarm))
        gr.printFile("        0, /* Inactive */")
        gr.printFile("        0, /* first absolute tick counts to expire */")
        gr.printFile("        0, /* tick counts to repeat expire after first expire */")
        if alarm == alarms_core0[-1]:
            gr.printFile("    }")
        else:
            gr.printFile("    },")
    gr.printFile("};")

else:
    gr.printFile ("/* There is no alarm defined in core_0*/\n")

if alarms_core1 != []:
    gr.printFile("/* Brief AlarmVar Array */")
    gr.printFile("AlarmVarType AlarmVar_core1[ALARMS_COUNT_CORE1] = {")
    for alarm in alarms_core1:
        if (config.getValue("/AUTOSAR/" + alarm, "OsAlarmAutostart") ):
            alarms_autostart_core1.append(alarm)
            #gr.printFile(alarm)
        
        gr.printFile("    /* Alarm {} */".format(alarm))
        gr.printFile("    {")
        gr.printFile("        NULL, /* pointer to next AlarmVar */")
        gr.printFile("        NULL, /* Pointer to previous AlarmVar */")
        gr.printFile("        {},".format(alarm))
        gr.printFile("        0, /* Inactive */")
        gr.printFile("        0, /* first absolute tick counts to expire */")
        gr.printFile("        0 /* tick counts to repeat expire after first expire */")
        if alarm == alarms_core1[-1]:
            gr.printFile("    }")
        else:
            gr.printFile("    },")
    gr.printFile("};")

else:
    gr.printFile ("/* There is no alarm defined in core_1*/\n")

core0 = alarm_cores['core0']
core1 = alarm_cores['core1']
if core0 != []:
    gr.printFile("/* Brief AlarmConst Array */")
    gr.printFile("const AlarmConstType AlarmConst_core0[ALARMS_COUNT_CORE0] = {")
    for alarm in core0:
        gr.printFile("    /* Alarm {} */".format(alarm))
        gr.printFile("    {")
        counter = config.getValue("/AUTOSAR/" + alarm ,"OsAlarmCounterRef")
        gr.printFile("        {}, /*counter ID */".format(counter))
        action = config.getValue("/AUTOSAR/" + alarm ,"OsAlarmAction")
        if action != False:
            action_task = config.getValue("/AUTOSAR/" + alarm + "/" + action ,"OsAlarmActivateTask")
            action_setevent = config.getValue("/AUTOSAR/" + alarm + "/"+action ,"OsAlarmSetEvent")
            action_callback = config.getValue("/AUTOSAR/" + alarm + "/"+action ,"OsAlarmCallback")
            action_increase = config.getValue("/AUTOSAR/" + alarm + "/"+action ,"OsAlarmIncrementCounter")
        # gr.printFile("        {}, /* alarm action */".format(action))
        # gr.printFile("        {")
        
        if action_task:
            gr.printFile ("        ACTIVATETASK, /* alarm action */")
            gr.printFile ("        {")
            gr.printFile ("            0, /* no callback */")
            task = config.getValue("/AUTOSAR/" + alarm +"/"+ action +"/"+ action_task, "OsAlarmActivateTaskRef")
            gr.printFile ("            {}, /* TaskID */".format(task))
            gr.printFile ("            0, /* no event */")
            gr.printFile ("            0, /* no counter */")
            gr.printFile ("            0 /* no schduletable */")
        
        if action_setevent:
            gr.printFile ("        SETEVENT, /* alarm action */")
            gr.printFile ("        {")
            gr.printFile ("            0, /* no callback */")
            task = config.getValue("/AUTOSAR/" + alarm +"/"+ action +"/"+ action_setevent, "OsAlarmSetEventTaskRef")
            gr.printFile ("            {}, /* SetEventTaskID */".format(task))
            event = config.getValue("/AUTOSAR/" + alarm +"/"+ action +"/"+ action_setevent, "OsAlarmSetEventRef")
            gr.printFile ("            {}, /* event */".format(event))
            gr.printFile ("            0, /* no counter */")
            gr.printFile ("            0 /* no schduletable */")
        
        if action_increase:
            gr.printFile ("        INCREMENTCOUNTER, /* alarm action */")
            gr.printFile ("        {")
            gr.printFile ("            0, /* no callback */")
            counter = config.getValue("/AUTOSAR/" + alarm +"/"+ action +"/"+ action_increase, "OsAlarmIncrementCounterRef")
            gr.printFile ("            0, /* no task */")
            gr.printFile ("            0, /* no event */")
            gr.printFile ("            {}, /* counter */".format(counter))
            gr.printFile ("            0 /* no schduletable */")
        
        #else:
        #    gr.error("Alarm {} has an invalid action: {}".format(alarm, action))
        
        gr.printFile("        }")
        gr.printFile("    },")
    for st in ST_cores['core0']:
        counter = config.getValue("/AUTOSAR/" + st, "OsScheduleTableCounterRef")
        gr.printFile ("    /* Alarm alarm_{} */".format(st))
        gr.printFile ("    {")
        gr.printFile ("        {}, /*counter*/".format(counter))
        gr.printFile ("        EPCALLBACK, /* alarm action */")
        gr.printFile ("        {")
        gr.printFile ("            0, /* no callback */")
        gr.printFile ("            0, /* no task */")
        gr.printFile ("            0, /* no event */")
        gr.printFile ("            0, /* no counter */")
        gr.printFile ("            {} /* schduletable */".format(st))
        gr.printFile ("        }")
        gr.printFile("    },")
                    
    gr.printFile("};\n")

if core1 != []:
    gr.printFile("/* Brief AlarmConst Array */")
    gr.printFile("const AlarmConstType AlarmConst_core1[ALARMS_COUNT_CORE1] = {")
    for alarm in core1:
        gr.printFile("    /* Alarm {} */".format(alarm))
        gr.printFile("    {")
        counter = config.getValue("/AUTOSAR/" + alarm ,"OsAlarmCounterRef")
        gr.printFile("        {}, /*counter ID */".format(counter))
        action = config.getValue("/AUTOSAR/" + alarm ,"OsAlarmAction")
        action_task = config.getValue("/AUTOSAR/" + alarm + "/" + action ,"OsAlarmActivateTask")
        action_setevent = config.getValue("/AUTOSAR/" + alarm + "/"+action ,"OsAlarmSetEvent")
        action_callback = config.getValue("/AUTOSAR/" + alarm + "/"+action ,"OsAlarmCallback")
        action_increase = config.getValue("/AUTOSAR/" + alarm + "/"+action ,"OsAlarmIncrementCounter")
        # gr.printFile("        {}, /* alarm action */".format(action))
        # gr.printFile("        {")
        
        if action_task:
            gr.printFile ("        ACTIVATETASK, /* alarm action */")
            gr.printFile ("        {")
            gr.printFile ("            NULL, /* no callback */")
            task = config.getValue("/AUTOSAR/" + alarm +"/"+ action +"/"+ action_task, "OsAlarmActivateTaskRef")
            gr.printFile ("            {}, /* TaskID */".format(task))
            gr.printFile ("            0, /* no event */")
            gr.printFile ("            0, /* no counter */")
            gr.printFile ("            0 /* no schduletable */")
        
        if action_setevent:
            gr.printFile ("        SETEVENT, /* alarm action */")
            gr.printFile ("        {")
            gr.printFile ("            NULL, /* no callback */")
            task = config.getValue("/AUTOSAR/" + alarm +"/"+ action +"/"+ action_setevent, "OsAlarmSetEventTaskRef")
            gr.printFile ("            {}, /* SetEventTaskID */".format(task))
            event = config.getValue("/AUTOSAR/" + alarm +"/"+ action +"/"+ action_setevent, "OsAlarmSetEventRef")
            gr.printFile ("            {}, /* event */".format(event))
            gr.printFile ("            0, /* no counter */")
            gr.printFile ("            0 /* no schduletable */")
        
        if action_callback:    #EPcallback
            ST = config.getValue("/AUTOSAR/" + alarm +"/"+ action + "/"+ action_callback, "OsAlarmCallbackName")
            gr.printFile ("        EPCALLBACK, /* alarm action */")
            gr.printFile ("        {")
            gr.printFile ("            0, /* no task */")
            gr.printFile ("            0, /* no event */")
            gr.printFile ("            0, /* no counter */")
            gr.printFile ("            {} /* no schduletable */".format(ST))
        
        if action_increase:
            gr.printFile ("        INCREMENTCOUNTER, /* alarm action */")
            gr.printFile ("        {")
            gr.printFile ("            NULL, /* no callback */")
            counter = config.getValue("/AUTOSAR/" + alarm +"/"+ action +"/"+ action_increase, "OsAlarmIncrementCounterRef")
            gr.printFile ("            0, /* no task */")
            gr.printFile ("            0, /* no event */")
            gr.printFile ("            {}, /* counter */".format(counter))
            gr.printFile ("            0 /* no schduletable */")      
        gr.printFile("        }")
        gr.printFile("    },")
    
    for st in ST_cores['core1']:
        counter = config.getValue("/AUTOSAR/" + st, "OsScheduleTableCounterRef")
        gr.printFile ("    /* Alarm alarm_{} */".format(st))
        gr.printFile ("    {")
        gr.printFile ("        {}, /*counter*/".format(counter))
        gr.printFile ("        EPCALLBACK, /* alarm action */")
        gr.printFile ("        {")
        gr.printFile ("            0, /* no callback */")
        gr.printFile ("            0, /* no task */")
        gr.printFile ("            0, /* no event */")
        gr.printFile ("            0, /* no counter */")
        gr.printFile ("            {} /* schduletable */".format(st))
        gr.printFile ("        }")
        gr.printFile("    },")
    gr.printFile("};\n")



if alarms_core0 != []:
    gr.printFile("AlarmAutosarType AlarmAutosar_core0[ALARMS_COUNT_CORE0] = {")
    for alarm in alarms_core0:
        gr.printFile("    /* Alarm {} */".format(alarm))
        gr.printFile("    {")
        for app in apps:
            temp = config.getList("/AUTOSAR/" + app ,"OsAppAlarmRef")
            if alarm in temp:
                gr.printFile("        {},".format(app))
        
        
        alarm_apps = config.getList("/AUTOSAR/" + alarm ,"OsAlarmAccessingApplication")
        if alarm_apps != []:
            gr.printFileSpace("        0 ")
            for alarm_app in alarm_apps:
                if alarm_app == alarm_apps[-1]:
                    gr.printFile("| (1 << {}) ".format(alarm_app))
                else:
                    gr.printFileSpace("| (1 << {}) ".format(alarm_app))
        elif "ST" in alarm:
            for scheduletable in ST_cores['core0']:
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
                break

        else:
            gr.printFile("        0")
        gr.printFile("    },")
    gr.printFile("};")

if alarms_core1 != []:
    gr.printFile("AlarmAutosarType AlarmAutosar_core1[ALARMS_COUNT_CORE1] = {")
    for alarm in alarms_core1:
        gr.printFile("    /* Alarm {} */".format(alarm))
        gr.printFile("    {")
        for app in apps:
            temp = config.getList("/AUTOSAR/" + app ,"OsAppAlarmRef")
            if alarm in temp:
                gr.printFile("        {},".format(app))
        alarm_apps = config.getList("/AUTOSAR/" + alarm ,"OsAlarmAccessingApplication")
        if alarm_apps != []:
            gr.printFileSpace("        0 ")
            for alarm_app in alarm_apps:
                if alarm_app == alarm_apps[-1]:
                    gr.printFile("| (1 << {}) ".format(alarm_app))
                else:
                    gr.printFileSpace("| (1 << {}) ".format(alarm_app))
        elif "ST" in alarm:
            for scheduletable in ST_cores['core1']:
                for app in app_core1:
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
                break
        else:
            gr.printFile("        0")
        gr.printFile("    },")
    gr.printFile("};")


'''
if alarms_autostart_core0 != []:
    gr.printFile("/* Brief AutoStartAlarm Array */")
    gr.printFile("const AutoStartAlarmType AutoStartAlarm_core0[ALARMS_AUTOSTART_COUNT_CORE0] = {")
    for alarm in alarms_autostart_core0:
        gr.printFile("    {")
        autostart = config.getValue("/AUTOSAR/"+ alarm  ,"OsAlarmAutostart")
        mode = config.getValue("/AUTOSAR/"+ alarm +"/"+ autostart ,"OsAlarmAppModeRef")
        gr.printFile("        {}, /* application mode */".format(mode))
        gr.printFile("        {}, /* Alarm */".format(alarm))
        time = config.getValue("/AUTOSAR/"+ alarm +"/"+ autostart  ,"OsAlarmAlarmTime")
        gr.printFile("        {}, /* alarm time */".format(time))
        time = config.getValue("/AUTOSAR/"+ alarm +"/"+ autostart  ,"OsAlarmCycleTime")
        gr.printFile("        {}, /* cycle time */".format(time))
        gr.printFile("    },")
    gr.printFile("};\n")

if alarms_autostart_core1 != [] :
    gr.printFile("/* Brief AutoStartAlarm Array */")
    gr.printFile("const AutoStartAlarmType AutoStartAlarm_core1[ALARMS_AUTOSTART_COUNT_CORE1] = {")
    for alarm in alarms_autostart_core1:
        gr.printFile("    {")
        autostart = config.getValue("/AUTOSAR/"+ alarm  ,"OsAlarmAutostart")
        mode = config.getValue("/AUTOSAR/"+ alarm +"/"+ autostart ,"OsAlarmAppModeRef")
        gr.printFile("        {}, /* application mode */".format(mode))
        gr.printFile("        {}, /* Alarm */".format(alarm))
        time = config.getValue("/AUTOSAR/"+ alarm +"/"+ autostart  ,"OsAlarmAlarmTime")
        gr.printFile("        {}, /* alarm time */".format(time))
        time = config.getValue("/AUTOSAR/"+ alarm +"/"+ autostart  ,"OsAlarmCycleTime")
        gr.printFile("        {}, /* cycle time */".format(time))
        gr.printFile("    },")
    gr.printFile("};\n")
'''
gr.printFile("#pragma section")







    



