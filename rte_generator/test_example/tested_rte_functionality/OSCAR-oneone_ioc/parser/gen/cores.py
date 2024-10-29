from generator.config import config

global config
global app_cores
global alarm_cores
global counter_cores
global isr_cores
global ST_cores
global spinlock_cores
global task_cores
global trustedFun_cores
global app_core0
global app_core1

app_cores = {}
alarm_cores = {'core0':[], 'core1':[]}
counter_cores = {'core0':[], 'core1':[]}
isr_cores = {'core0':[], 'core1':[]}
ST_cores = {'core0':[], 'core1':[]}
task_cores = {'core0':[], 'core1':[]}
trustedFun_cores = {'core0':[], 'core1':[]}
app_core0 = []
app_core1 = []

apps = config.getList("/AUTOSAR","OsApplication")
alarms = config.getList("/AUTOSAR", "OsAlarm")
counters = config.getList("/AUTOSAR","OsCounter")
isrs = config.getList("/AUTOSAR", "OsIsr")
STs = config.getList("/AUTOSAR","OsScheduleTable")
tasks = config.getList("/AUTOSAR","OsTask")


Hw = config.getValue("/AUTOSAR" ,"EcucHardware")
core_defs = config.getList("/AUTOSAR/" + Hw ,"EcucCoreDefinition")
for app in apps:
    core_ref = config.getValue("/AUTOSAR/" + app,"OsApplicationCoreRef")
    for core_def in core_defs:
        if core_ref == core_def:
            value = config.getValue("/AUTOSAR/" + Hw + "/" + core_ref,"EcucCoreId")
            app_cores[app] = "OS_CORE_ID_" + value


for app in apps:
    if app_cores[app] == "OS_CORE_ID_0":
        app_core0.append(app)
        if config.getList("/AUTOSAR/" + app ,"OsAppAlarmRef") != []:
            alarm_cores['core0'] += config.getList("/AUTOSAR/" + app ,"OsAppAlarmRef")
        if config.getList("/AUTOSAR/" + app ,"OsAppCounterRef") != []:
            counter_cores['core0'] += config.getList("/AUTOSAR/" + app ,"OsAppCounterRef")
        if config.getList("/AUTOSAR/" + app, "OsAppIsrRef") != []:
            isr_cores['core0'] += config.getList("/AUTOSAR/" + app, "OsAppIsrRef")
        if config.getList("/AUTOSAR/" + app,"OsAppScheduleTableRef") != []:
            ST_cores['core0'] += config.getList("/AUTOSAR/" + app,"OsAppScheduleTableRef")
        if config.getList("/AUTOSAR/" + app,"OsAppTaskRef") != []:
            task_cores['core0'] += config.getList("/AUTOSAR/" + app,"OsAppTaskRef")
        if config.getList("/AUTOSAR/" + app, "OsApplicationTrustedFunction") != []:
            TFs = config.getList("/AUTOSAR/" + app, "OsApplicationTrustedFunction")
            for TF in TFs:
                trustedFun_cores['core0'].append(config.getValue("/AUTOSAR/" + app + "/" + TF , "OsTrustedFunctionName"))
    
    elif app_cores[app] == "OS_CORE_ID_1":
        app_core1.append(app)
        if config.getList("/AUTOSAR/" + app ,"OsAppAlarmRef") != []:
            alarm_cores['core1'] += config.getList("/AUTOSAR/" + app ,"OsAppAlarmRef")
        if config.getList("/AUTOSAR/" + app ,"OsAppCounterRef") != []:
            counter_cores['core1'] += config.getList("/AUTOSAR/" + app ,"OsAppCounterRef")
        if config.getList("/AUTOSAR/" + app, "OsAppIsrRef") != []:
            isr_cores['core1'] += config.getList("/AUTOSAR/" + app, "OsAppIsrRef")
        if config.getList("/AUTOSAR/" + app,"OsAppScheduleTableRef") != []:
            ST_cores['core1'] += config.getList("/AUTOSAR/" + app,"OsAppScheduleTableRef")
        if config.getList("/AUTOSAR/" + app,"OsAppTaskRef") != []:
            task_cores['core1'] += config.getList("/AUTOSAR/" + app,"OsAppTaskRef")
        if config.getList("/AUTOSAR/" + app, "OsApplicationTrustedFunction") != []:
            TFs = config.getList("/AUTOSAR/" + app, "OsApplicationTrustedFunction")
            for TF in TFs:
                trustedFun_cores['core1'].append(config.getValue("/AUTOSAR/" + app + "/" + TF , "OsTrustedFunctionName"))
