from generator.config import config 
from generator import globals as gr
from gen.cores import ST_cores, app_core0, app_core1

global config
global ST_cores, app_core0, app_core1
gr.genfile = open(gr.src_path+"scheduletable_Cfg.c",'w')

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"alarm_Cfg.h\"")
gr.printFile("#include \"alarm.h\"")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("#include \"event_Cfg.h\"")
gr.printFile("#include \"counter.h\"")
gr.printFile("#include \"counter_Cfg.h\"")
gr.printFile("#include \"scheduleTable_Cfg.h\"")
gr.printFile("#include \"application_Cfg.h\"")


gr.printFile("/*==================[declarations]=============================================*/")
gr.printFile("#pragma section\n")

scheduleTable_core0 = ST_cores['core0']
scheduleTable_core1 = ST_cores['core1']
scheduleTable_autostart_core0 = []
scheduleTable_autostart_core1 = []

scheduletables = config.getList("/AUTOSAR","OsScheduleTable")
apps = config.getList("/AUTOSAR","OsApplication")
counters = config.getCount("/AUTOSAR","OsCounter")


for scheduletable in scheduleTable_core0:
    if config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableAutostart") != False:
        scheduleTable_autostart_core0.append(scheduletable)
for scheduletable in scheduleTable_core1:
    if config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableAutostart") != False:
        scheduleTable_autostart_core1.append(scheduletable)

gr.printFile("/* ScheduleTables */")
for scheduletable in scheduletables:
    gr.printFile("//{};".format(scheduletable))


for scheduletable in scheduleTable_core0:
    gr.printFile("ExpiryPointType expirypoints_{}[EXPIRYPOINT_COUNT_{}] = {}".format(scheduletable, scheduletable, "{"))
    task_start = 0
    event_start = 0
    eps = config.getList("/AUTOSAR/"+ scheduletable , "OsScheduleTableExpiryPoint")
    offset_priority = {}
    for ep in eps:
        offset = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTblExpPointOffset")
        offset_priority[ep] = int(offset)
    ep_names = sorted(offset_priority.items(), key =lambda x : x[1])
    for i in range(len(ep_names)):
        ep_name = ep_names[i][0]
        gr.printFile("    {")
        offset = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep_name, "OsScheduleTblExpPointOffset")
        gr.printFile("        {}, /*offset*/".format(offset))
        
        task_activation_count = config.getCount("/AUTOSAR/" + scheduletable + "/" + ep_name, "OsScheduleTableTaskActivation")
        if task_activation_count:
            gr.printFile("        {}, /*task start*/".format(task_start))
            task_start += task_activation_count
            gr.printFile("        {}, /*task end*/".format(task_start))
        else:
            gr.printFile("        0, /*task start*/")
            gr.printFile("        0, /*task end*/")
        
               
        event_setting_count = config.getCount("/AUTOSAR/" + scheduletable + "/" + ep_name, "OsScheduleTableEventSetting")
        if event_setting_count:
            gr.printFile("        {}, /*event start*/".format(event_start))
            event_start += event_setting_count
            gr.printFile("        {}, /*event end*/".format(event_start))
        else:
            gr.printFile("        0, /*event start*/")
            gr.printFile("        0, /*event end*/")

        adjustpoint = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep_name ,"OsScheduleTblAdjustableExpPoint")
        maxshorten = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep_name + "/" + adjustpoint ,"OsScheduleTableMaxShorten")
        gr.printFile("        {}, /*maxShorten*/".format(maxshorten))
        maxlengthen = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep_name + "/"+ adjustpoint ,"OsScheduleTableMaxLengthen")
        gr.printFile("        {}, /*maxLengthen*/".format(maxlengthen))
        gr.printFile("        NULL, /*next*/")
        gr.printFile("    },")
    gr.printFile("};")
    
    taskCount = 0
    for i in range(len(ep_names)):
        ep = ep_names[i][0]
        taskCount += config.getCount("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableTaskActivation")

    gr.printFile("TaskType {}_taskArray[{}] = {}".format(scheduletable, taskCount, "{"))
    for i in range(len(ep_names)):
        ep = ep_names[i][0]
        tasks = config.getList("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableTaskActivation")
        for task in tasks:
            name = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep + "/" + task, "OsScheduleTableActivateTaskRef")
            gr.printFile("    {},".format(name))
    gr.printFile("};")
    

    eventCount = 0
    for i in range(len(ep_names)):
        ep = ep_names[i][0]
        eventCount += config.getCount("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableEventSetting")
    if eventCount > 0:
        gr.printFile("EventSetting {}_eventArray[{}] = {}".format(scheduletable, eventCount, "{"))
        for i in range(len(ep_names)):
            ep = ep_names[i][0]
            events = config.getList("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableEventSetting")
            for event in events:
                gr.printFile("    {")
                eventbytask = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep + "/" + event, "OsScheduleTableSetEventTaskRef")
                gr.printFile("        {},".format(eventbytask))
                eventref = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep + "/" + event, "OsScheduleTableSetEventRef")
                gr.printFile("        {},".format(eventref))
                gr.printFile("    },")
        gr.printFile("};")



if scheduleTable_core0 != []:
    gr.printFile("const ScheduleTableConstType ScheduleTableConst_core0[SCHEDULETABLE_COUNT_CORE0] = {")
    for scheduletable in scheduleTable_core0:
        gr.printFile("    {")
        scheduleTableSync = config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableSync")
        scheduleTblSyncStrategy = config.getValue("/AUTOSAR/" + scheduletable + "/" + scheduleTableSync, "OsScheduleTblSyncStrategy")
        gr.printFile("        {}, /*syncStrategy*/".format(scheduleTblSyncStrategy))
        if config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableRepeating") == "TRUE":
            gr.printFile("        TRUE, /*repeating*/")
        else:
            gr.printFile("        FALSE, /*repeating*/")
        
        counter = config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableCounterRef")
        gr.printFile("        {}, /*counter*/".format(counter))

        if scheduleTblSyncStrategy == "EXPLICIT":
            gr.printFile("        counter_{}, /*syncCounter*/".format(scheduletable))
        else:
            gr.printFile("        DriveCounter, /*syncCounter*/")

        precision = config.getValue("/AUTOSAR/" + scheduletable + "/" + scheduleTableSync, "OsScheduleTblExplicitPrecision") 
        gr.printFile("        {}, /*ExplicitPrecision*/".format(precision))

        ep_Amount = config.getCount("/AUTOSAR/" + scheduletable, "OsScheduleTableExpiryPoint")
        gr.printFile("        {}, /*EPAmount*/".format(ep_Amount))

        duration = config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableDuration")
        gr.printFile("        {}, /*duration*/".format(duration))

        eps = config.getList("/AUTOSAR/" + scheduletable, "OsScheduleTableExpiryPoint")
        offset_priority = {}
        for ep in eps:
            offset = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTblExpPointOffset")
            offset_priority[ep] = int(offset)
        ep_names = sorted(offset_priority.items(), key =lambda x : x[1])
        initoffset = ep_names[0][1]
        gr.printFile("        {}, /*initOffset*/".format(initoffset))
        finaldelay = int(duration) - ep_names[-1][1]
        gr.printFile("        {}, /*finalDelay*/".format(finaldelay))
           
        gr.printFile("        alarm_{}, /*callbackAlarm*/".format(scheduletable))
        gr.printFile("        expirypoints_{}, /*expiryPoints*/".format(scheduletable))
        
        taskCount = 0
        for i in range(len(ep_names)):
            ep = ep_names[i][0]
            taskCount += config.getCount("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableTaskActivation")     
        if taskCount != 0:
            gr.printFile("        {}_taskArray, /*taskArray*/".format(scheduletable))
        else:
            gr.printFile("        NULL,")

        eventCount = 0
        for i in range(len(ep_names)):
            ep = ep_names[i][0]
            eventCount += config.getCount("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableEventSetting")
        if eventCount != 0:
            gr.printFile("        {}_eventArray /*eventArray*/".format(scheduletable))
        else:
            gr.printFile("        NULL,")
        
        gr.printFile("    },")
    gr.printFile("};")
    
    
    
        
    gr.printFile("ScheduleTableVarType ScheduleTableVar_core0[SCHEDULETABLE_COUNT_CORE0] = {")
    for scheduletable in scheduleTable_core0:
        gr.printFile("    {")
        gr.printFile("        SCHEDULETABLE_STOPPED, /*status*/")
        gr.printFile("        0, /*deviation*/")
        gr.printFile("        0, /*currentEPIndex*/")
        gr.printFile("        SCHEDULETABLE_COUNT_CORE0 /*next*/")
        gr.printFile("    },")

gr.printFile("};")

gr.printFile("ScheduleTableAutosarType ScheduleTableAutosar_core0[SCHEDULETABLE_COUNT_CORE0] = {")
for scheduletable in scheduleTable_core0:
    gr.printFile("    /* ScheduleTable {} */".format(scheduletable))
    gr.printFile("    {")
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
gr.printFile("};")

for scheduletable in scheduleTable_core0:
    gr.printFile("/* Brief Callback Declaration of Callback ExpiryPointCallbackFunc{} */".format(scheduletable))
    gr.printFile("DeclareCallback(ExpiryPointCallbackFunc{});".format(scheduletable))

#################################################################################################
for scheduletable in scheduleTable_core1:
    gr.printFile("ExpiryPointType expirypoints_{}[EXPIRYPOINT_COUNT_{}] = {}".format(scheduletable, scheduletable, "{"))
    task_start = 0
    event_start = 0
    eps = config.getList("/AUTOSAR/"+ scheduletable , "OsScheduleTableExpiryPoint")
    offset_priority = {}
    for ep in eps:
        offset = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTblExpPointOffset")
        offset_priority[ep] = int(offset)
    ep_names = sorted(offset_priority.items(), key =lambda x : x[1])
    for i in range(len(ep_names)):
        ep_name = ep_names[i][0]
        gr.printFile("    {")
        offset = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep_name, "OsScheduleTblExpPointOffset")
        gr.printFile("        {}, /*offset*/".format(offset))
        
        task_activation_count = config.getCount("/AUTOSAR/" + scheduletable + "/" + ep_name, "OsScheduleTableTaskActivation")
        if task_activation_count:
            gr.printFile("        {}, /*task start*/".format(task_start))
            task_start += task_activation_count
            gr.printFile("        {}, /*task end*/".format(task_start))
        else:
            gr.printFile("        0, /*task start*/")
            gr.printFile("        0, /*task end*/")
        
               
        event_setting_count = config.getCount("/AUTOSAR/" + scheduletable + "/" + ep_name, "OsScheduleTableEventSetting")
        if event_setting_count:
            gr.printFile("        {}, /*event start*/".format(event_start))
            event_start += event_setting_count
            gr.printFile("        {}, /*event end*/".format(event_start))
        else:
            gr.printFile("        0, /*event start*/")
            gr.printFile("        0, /*event end*/")

        adjustpoint = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep_name ,"OsScheduleTblAdjustableExpPoint")
        maxshorten = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep_name + "/" + adjustpoint ,"OsScheduleTableMaxShorten")
        gr.printFile("        {}, /*maxShorten*/".format(maxshorten))
        maxlengthen = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep_name + "/"+ adjustpoint ,"OsScheduleTableMaxLengthen")
        gr.printFile("        {}, /*maxLengthen*/".format(maxlengthen))
        gr.printFile("        NULL, /*next*/")
        gr.printFile("    },")
    gr.printFile("};")
    

    taskCount = 0
    for i in range(len(ep_names)):
        ep = ep_names[i][0]
        taskCount += config.getCount("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableTaskActivation")

    gr.printFile("TaskType {}_taskArray[{}] = {}".format(scheduletable, taskCount, "{"))
    for i in range(len(ep_names)):
        ep = ep_names[i][0]
        tasks = config.getList("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableTaskActivation")
        for task in tasks:
            name = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep + "/" + task, "OsScheduleTableActivateTaskRef")
            gr.printFile("    {},".format(name))
    gr.printFile("};")
    

    eventCount = 0
    for i in range(len(ep_names)):
        ep = ep_names[i][0]
        eventCount += config.getCount("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableEventSetting")
    if eventCount > 0:
        gr.printFile("EventSetting {}_eventArray[{}] = {}".format(scheduletable, eventCount, "{"))
        for i in range(len(ep_names)):
            ep = ep_names[i][0]
            events = config.getList("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableEventSetting")
            for event in events:
                gr.printFile("    {")
                eventbytask = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep + "/" + event, "OsScheduleTableSetEventTaskRef")
                gr.printFile("        {},".format(eventbytask))
                eventref = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep + "/" + event, "OsScheduleTableSetEventRef")
                gr.printFile("        {},".format(eventref))
                gr.printFile("    },")
        gr.printFile("};")



if scheduleTable_core1 != []:
    gr.printFile("const ScheduleTableConstType ScheduleTableConst_core1[SCHEDULETABLE_COUNT_CORE1] = {")
    for scheduletable in scheduleTable_core1:
        gr.printFile("    {")
        scheduleTableSync = config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableSync")
        scheduleTblSyncStrategy = config.getValue("/AUTOSAR/" + scheduletable + "/" + str(scheduleTableSync), "OsScheduleTblSyncStrategy")
        gr.printFile("        {}, /*syncStrategy*/".format(scheduleTblSyncStrategy))
        if config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableRepeating") == "TRUE":
            gr.printFile("        TRUE, /*repeating*/")
        else:
            gr.printFile("        FALSE, /*repeating*/")
        
        counter = config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableCounterRef")
        gr.printFile("        {}, /*counter*/".format(counter))

        if scheduleTblSyncStrategy == "EXPLICIT":
            gr.printFile("        counter_{}, /*syncCounter*/".format(scheduletable))
        else:
            gr.printFile("        DriveCounter, /*syncCounter*/")

        precision = config.getValue("/AUTOSAR/" + scheduletable + "/" + str(scheduleTableSync), "OsScheduleTblExplicitPrecision") 
        gr.printFile("        {}, /*ExplicitPrecision*/".format(precision))

        ep_Amount = config.getCount("/AUTOSAR/" + scheduletable, "OsScheduleTableExpiryPoint")
        gr.printFile("        {}, /*EPAmount*/".format(ep_Amount))

        duration = config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableDuration")
        gr.printFile("        {}, /*duration*/".format(duration))

        eps = config.getList("/AUTOSAR/" + scheduletable, "OsScheduleTableExpiryPoint")
        offset_priority = {}
        for ep in eps:
            offset = config.getValue("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTblExpPointOffset")
            offset_priority[ep] = int(offset)
        
        
        ep_names = sorted(offset_priority.items(), key =lambda x : x[1])
        
        initoffset = ep_names[0][1]
        gr.printFile("        {}, /*initOffset*/".format(initoffset))
        finaldelay = int(duration) - ep_names[-1][1]
        gr.printFile("        {}, /*finalDelay*/".format(finaldelay))

        gr.printFile("        alarm_{}, /*callbackAlarm*/".format(scheduletable))
        gr.printFile("        expirypoints_{}, /*expiryPoints*/".format(scheduletable))
        
        taskCount = 0
        for i in range(len(ep_names)):
            ep = ep_names[i][0]
            taskCount += config.getCount("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableTaskActivation")     
        if taskCount != 0:
            gr.printFile("        {}_taskArray, /*taskArray*/".format(scheduletable))
        else:
            gr.printFile("        NULL,")

        eventCount = 0
        for i in range(len(ep_names)):
            ep = ep_names[i][0]
            eventCount += config.getCount("/AUTOSAR/" + scheduletable + "/" + ep, "OsScheduleTableEventSetting")
        if eventCount != 0:
            gr.printFile("        {}_eventArray /*eventArray*/".format(scheduletable))
        else:
            gr.printFile("        NULL,")
        
        gr.printFile("    },")
    gr.printFile("};")
    
    
    
        
    gr.printFile("ScheduleTableVarType ScheduleTableVar_core1[SCHEDULETABLE_COUNT_CORE1] = {")
    for scheduletable in scheduleTable_core1:
        gr.printFile("    {")
        gr.printFile("        SCHEDULETABLE_STOPPED, /*status*/")
        gr.printFile("        0, /*deviation*/")
        gr.printFile("        0, /*currentEPIndex*/")
        gr.printFile("        SCHEDULETABLE_COUNT_CORE1 /*next*/")
        gr.printFile("    },")

gr.printFile("};")

gr.printFile("ScheduleTableAutosarType ScheduleTableAutosar_core1[SCHEDULETABLE_COUNT_CORE1] = {")
for scheduletable in scheduleTable_core1:
    gr.printFile("    /* ScheduleTable {} */".format(scheduletable))
    gr.printFile("    {")
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
gr.printFile("};")

for scheduletable in scheduleTable_core1:
    gr.printFile("/* Brief Callback Declaration of Callback ExpiryPointCallbackFunc{} */".format(scheduletable))
    gr.printFile("DeclareCallback(ExpiryPointCallbackFunc{});".format(scheduletable))