from generator.config import config 
from generator import globals as gr
from gen.cores import task_cores, isr_cores

global config
global task_cores
global isr_cores
gr.genfile = open(gr.src_path+"timingprot_Cfg.c",'w')

#/* get tasks */
apps = config.getList("/AUTOSAR", "OsApplication")
#tasks = config.getList("/AUTOSAR", "OsTask")
isrs = config.getList("/AUTOSAR", "OsIsr")
task_core0 = task_cores['core0']
task_core1 = task_cores['core1']
extended_task_core0 = []
extended_task_core1 = []
isr_core0 = isr_cores['core0']
isr_core1 = isr_cores['core1']
isr2_core0 = []
isr2_core1 = []

for task in task_core0:
    if config.getValue("/AUTOSAR/" + task , "OsTaskType") == "EXTENDED":
        extended_task_core0.append(task)
for task in task_core1:    
    if config.getValue("/AUTOSAR/" + task , "OsTaskType") == "EXTENDED":
        extended_task_core1.append(task)

for isr in isr_core0:
    if config.getValue("/AUTOSAR/"+ isr, "OsIsrCategory") == "CATEGORY_2":
        isr2_core0.append(isr)
for isr in isr_core1:
    if config.getValue("/AUTOSAR/"+ isr, "OsIsrCategory") == "CATEGORY_2":
        isr2_core1.append(isr)
#............................................................................................#
gr.printFile("#include \"typedefine.h\"")
gr.printFile("#include \"timingprot_Cfg.h\"\n")
gr.printFile("#pragma section\n")

gr.printFile("/** core 0 **/")
gr.printFile("TimingProtCounterType TaskExecutingCounter_core0[TASK_OBJECTS_COUNT_CORE0] = {")
gr.printFile("    /* Task IdleTask */")
gr.printFile("    {")
gr.printFile("        IDLETASKBUDGET, // ProtectionType")
gr.printFile("        0, // Bound")
gr.printFile("        0, // Counter")
gr.printFile("        NULL, // *PreTimgingCounter")
gr.printFile("        NULL // *NextTimingCounter")
gr.printFile("    },")

for task in task_core0:
    gr.printFile("    /* Task {} */".format(task))
    gr.printFile("    {")
    gr.printFile("        EXECUTEBUDGET, // ProtectionType")
    gr.printFile("        0, // Bound")
    gr.printFile("        0, // Counter")
    gr.printFile("        NULL, // *PreTimgingCounter")
    gr.printFile("        NULL // *NextTimingCounter")
    gr.printFile("    },")

for task in isr2_core0:
    gr.printFile("    /* Isr {} Task*/".format(task))
    gr.printFile("    {")
    gr.printFile("        EXECUTEBUDGET, // ProtectionType")
    gr.printFile("        0, // Bound")
    gr.printFile("        0, // Counter")
    gr.printFile("        NULL, // *PreTimgingCounter")
    gr.printFile("        NULL // *NextTimingCounter")
    gr.printFile("    },")
gr.printFile("};\n")
#................................................................................

gr.printFile("TimingProtCounterType TaskArrivalCounter_core0[TASK_OBJECTS_COUNT_CORE0] ={")
gr.printFile("    /* Task IdleTask */")
gr.printFile("    {")
gr.printFile("        IDLETASKBUDGET, // ProtectionType")
gr.printFile("        1, // Bound")
gr.printFile("        1, // Counter")
gr.printFile("        NULL, // *PreTimgingCounter")
gr.printFile("        NULL // *NextTimingCounter")
gr.printFile("    },")

for task in task_core0:
    gr.printFile("    /* Task {} */".format(task))
    gr.printFile("    {")
    gr.printFile("        TIMEFRAME, // ProtectionType")
    OsTaskTimingProtection = config.getValue("/AUTOSAR/" + task , "OsTaskTimingProtection")
    if OsTaskTimingProtection != False:
        ExecuteBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskExecutionBudget")
        OsTaskTimeFrame = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskTimeFrame")
        gr.printFile("        {}, // Bound".format(float(OsTaskTimeFrame)+1))
        gr.printFile("        {}, // Counter".format(float(OsTaskTimeFrame)+1))
    else:
        gr.printFile("        10000, // Bound")
        gr.printFile("        10000, // Counter")
    gr.printFile("        NULL, // *PreTimgingCounter")
    gr.printFile("        NULL // *NextTimingCounter")
    gr.printFile("    },")

for task in isr2_core0:
    gr.printFile("    /* Isr {} Task*/".format(task))
    gr.printFile("    {")
    gr.printFile("        TIMEFRAME, // ProtectionType")
    OsIsrTimingProtection = config.getValue("/AUTOSAR/" + task , "OsIsrTimingProtection")
    if OsIsrTimingProtection != False:
        ExecuteBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrExecutionBudget")
        OsIsrTimeFrame = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrTimeFrame")
        gr.printFile("        {}, // Bound".format(float(OsIsrTimeFrame)+1))
        gr.printFile("        {}, // Counter".format(float(OsIsrTimeFrame)+1))
    else:
        gr.printFile("        10000, // Bound")
        gr.printFile("        10000, // Counter")
    gr.printFile("        NULL, // *PreTimgingCounter")
    gr.printFile("        NULL // *NextTimingCounter")
    gr.printFile("    },")
gr.printFile("};\n")

#.........................................................................
gr.printFile("TimingProtCounterType ResourceTimingCounter_core0[RESOURCES_COUNT_CORE0];")
gr.printFile("TimingProtCounterType InterruptTimingCounter_core0[3];\n")
#..........................................................................
for task in task_core0:
    OsTaskTimingProtection = config.getValue("/AUTOSAR/" + task , "OsTaskTimingProtection")
    if OsTaskTimingProtection != False:
        OsTaskResourceLocks = config.getList("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskResourceLock")
        gr.printFile("const LockBudgetType LockBudget_{}[{}] = {}".format(task,len(OsTaskResourceLocks)+3 ,"{"))
        gr.printFile("    /* All Interrupt */")
        gr.printFile("    {")
        gr.printFile("        0,")
        OsTaskAllInterruptLockBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskAllInterruptLockBudget")
        gr.printFile("        {}".format(OsTaskAllInterruptLockBudget))
        gr.printFile("    },")
        gr.printFile("    /* OS Interrupt */")
        gr.printFile("    {")
        gr.printFile("        1,")
        OsTaskOsInterruptLockBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskAllInterruptLockBudget")
        gr.printFile("        {}".format(OsTaskOsInterruptLockBudget))
        gr.printFile("    },")
        if len(OsTaskResourceLocks) != 0:
            for resourceLock in OsTaskResourceLocks:
                resource = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection + "/" + resourceLock, "OsTaskResourceLockResourceRef")
                gr.printFile("    /* resource {} */".format(resource))
                gr.printFile("    {")
                gr.printFile("        {},".format(resource))
                resourceBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection + "/" + resourceLock, "OsTaskResourceLockBudget")
                gr.printFile("        {},".format(resourceBudget))
                gr.printFile("    },")
        
        for app in apps:
            if task in config.getList("/AUTOSAR/" + app , "OsAppTaskRef"):
                gr.printFile("    /* resource resource{} */".format(app))
                gr.printFile("    {")
                gr.printFile("        resource{},".format(app))
                gr.printFile("        99999")
                gr.printFile("    },")

    else:
        gr.printFile("const LockBudgetType LockBudget_{}[3] = {}".format(task, "{"))
        gr.printFile("    /* All Interrupt */")
        gr.printFile("    {")
        gr.printFile("        0,")
        gr.printFile("        10000")
        gr.printFile("    },")
        gr.printFile("    /* OS Interrupt */")
        gr.printFile("    {")
        gr.printFile("        1,")
        gr.printFile("        10000")
        gr.printFile("    },")
        for app in apps:
            if task in config.getList("/AUTOSAR/" + app , "OsAppTaskRef"):
                gr.printFile("    /* resource resource{} */".format(app))
                gr.printFile("    {")
                gr.printFile("        resource{},".format(app))
                gr.printFile("        99999")
                gr.printFile("    },")
    
    gr.printFile("};")
if isr2_core0 != []:
    for task in isr2_core0:
        OsIsrTimingProtection = config.getValue("/AUTOSAR/" + task , "OsIsrTimingProtection")
        if OsIsrTimingProtection != False:
            OsIsrResourceLocks = config.getList("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrResourceLock")
            gr.printFile("const LockBudgetType LockBudget_{}[{}] = {}".format(task,len(OsIsrResourceLocks)+3 ,"{"))
            gr.printFile("    /* All Interrupt */")
            gr.printFile("    {")
            gr.printFile("        0,")
            OsIsrAllInterruptLockBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrAllInterruptLockBudget")
            gr.printFile("        {}".format(OsIsrAllInterruptLockBudget))
            gr.printFile("    },")
            gr.printFile("    /* OS Interrupt */")
            gr.printFile("    {")
            gr.printFile("        1,")
            OsIsrOsInterruptLockBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrAllInterruptLockBudget")
            gr.printFile("        {}".format(OsIsrOsInterruptLockBudget))
            gr.printFile("    },")
            if len(OsIsrResourceLocks) != 0:
                for resourceLock in OsIsrResourceLocks:
                    resource = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection + "/" + resourceLock, "OsIsrResourceLockResourceRef")
                    gr.printFile("    /* resource {} */".format(resource))
                    gr.printFile("    {")
                    gr.printFile("        {},".format(resource))
                    resourceBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection + "/" + resourceLock, "OsIsrResourceLockBudget")
                    gr.printFile("        {},".format(resourceBudget))
                    gr.printFile("    },")
            
            for app in apps:
                if task in config.getList("/AUTOSAR/" + app , "OsAppIsrRef"):
                    gr.printFile("    /* resource resource{} */".format(app))
                    gr.printFile("    {")
                    gr.printFile("        resource{},".format(app))
                    gr.printFile("        99999")
                    gr.printFile("    },")

        else:
            gr.printFile("const LockBudgetType LockBudget_{}[3] = {}".format(task, "{"))
            gr.printFile("    /* All Interrupt */")
            gr.printFile("    {")
            gr.printFile("        0,")
            gr.printFile("        10000")
            gr.printFile("    },")
            gr.printFile("    /* OS Interrupt */")
            gr.printFile("    {")
            gr.printFile("        1,")
            gr.printFile("        10000")
            gr.printFile("    },")
            for app in apps:
                if task in config.getList("/AUTOSAR/" + app , "OsAppIsrRef"):
                    gr.printFile("    /* resource resource{} */".format(app))
                    gr.printFile("    {")
                    gr.printFile("        resource{},".format(app))
                    gr.printFile("        99999")
                    gr.printFile("    },")
        gr.printFile("};")
#.......................................................................
gr.printFile("const TimingProtBudgetType TimingProtBudget_core0[TASK_OBJECTS_COUNT_CORE0] = {")
gr.printFile("    /* idle task */")
gr.printFile("    {")
gr.printFile("        999, /* ExecuteBudget */")
gr.printFile("        1, /* TimeFrame */")
gr.printFile("        NULL /* LockBudgetRef */")
gr.printFile("    },")

for task in task_core0:
    OsTaskTimingProtection = config.getValue("/AUTOSAR/" + task , "OsTaskTimingProtection")
    gr.printFile("    /* Task_{} */".format(task))
    gr.printFile("    {")
    if OsTaskTimingProtection != False:
        ExecuteBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskExecutionBudget")
        gr.printFile("        {}, /* ExecuteBudget */".format(ExecuteBudget))   
        OsTaskTimeFrame = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskTimeFrame")
        gr.printFile("        {}, /* TimeFrame */".format(OsTaskTimeFrame))
        gr.printFile("        LockBudget_{} /* LockBudgetRef */".format(task))
        gr.printFile("    },")
    else:
        gr.printFile("        999, /* ExecuteBudget */")
        gr.printFile("        1, /* TimeFrame */")
        gr.printFile("        LockBudget_{} /* LockBudgetRef */".format(task))
        gr.printFile("    },")

for task in isr2_core0:
    OsIsrTimingProtection = config.getValue("/AUTOSAR/" + task , "OsIsrTimingProtection")
    gr.printFile("    /* isr {} Task  */".format(task))
    gr.printFile("    {")
    if OsIsrTimingProtection != False:
        ExecuteBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrExecutionBudget")
        gr.printFile("        {}, /* ExecuteBudget */".format(ExecuteBudget))
        OsTaskTimeFrame = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrTimeFrame")
        gr.printFile("        {}, /* TimeFrame */".format(OsTaskTimeFrame))
        gr.printFile("        LockBudget_{} /* LockBudgetRef */".format(task))
    else:
        gr.printFile("        999, /* ExecuteBudget */")
        gr.printFile("        1, /* TimeFrame */")
        gr.printFile("        LockBudget_{} /* LockBudgetRef */".format(task))
    gr.printFile("    },")

gr.printFile("};\n")

gr.printFile("/** core 1 **/")
gr.printFile("TimingProtCounterType TaskExecutingCounter_core1[TASK_OBJECTS_COUNT_CORE1] = {")
gr.printFile("    /* Task IdleTask */")
gr.printFile("    {")
gr.printFile("        IDLETASKBUDGET, // ProtectionType")
gr.printFile("        0, // Bound")
gr.printFile("        0, // Counter")
gr.printFile("        NULL, // *PreTimgingCounter")
gr.printFile("        NULL // *NextTimingCounter")
gr.printFile("    },")

for task in task_core1:
    gr.printFile("    /* Task {} */".format(task))
    gr.printFile("    {")
    gr.printFile("        EXECUTEBUDGET, // ProtectionType")
    gr.printFile("        0, // Bound")
    gr.printFile("        0, // Counter")
    gr.printFile("        NULL, // *PreTimgingCounter")
    gr.printFile("        NULL // *NextTimingCounter")
    gr.printFile("    },")
if isr2_core1 != []:
    for task in isr2_core1:
        gr.printFile("    /* Isr {} Task*/".format(task))
        gr.printFile("    {")
        gr.printFile("        EXECUTEBUDGET, // ProtectionType")
        gr.printFile("        0, // Bound")
        gr.printFile("        0, // Counter")
        gr.printFile("        NULL, // *PreTimgingCounter")
        gr.printFile("        NULL // *NextTimingCounter")
        gr.printFile("    },")
    gr.printFile("};\n")
#................................................................................

gr.printFile("TimingProtCounterType TaskArrivalCounter_core1[TASK_OBJECTS_COUNT_CORE1] ={")
gr.printFile("    /* Task IdleTask */")
gr.printFile("    {")
gr.printFile("        IDLETASKBUDGET, // ProtectionType")
gr.printFile("        1, // Bound")
gr.printFile("        1, // Counter")
gr.printFile("        NULL, // *PreTimgingCounter")
gr.printFile("        NULL // *NextTimingCounter")
gr.printFile("    },")

if isr2_core1 != []:
    for task in task_core1:
        gr.printFile("    /* Task {} */".format(task))
        gr.printFile("    {")
        gr.printFile("        TIMEFRAME, // ProtectionType")
        OsTaskTimingProtection = config.getValue("/AUTOSAR/" + task , "OsTaskTimingProtection")
        if OsTaskTimingProtection != False:
            ExecuteBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskExecutionBudget")
            OsTaskTimeFrame = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskTimeFrame")
            gr.printFile("        {}, // Bound".format(float(OsTaskTimeFrame)+1))
            gr.printFile("        {}, // Counter".format(float(OsTaskTimeFrame)+1))
        else:
            gr.printFile("        10000, // Bound")
            gr.printFile("        10000, // Counter")
        gr.printFile("        NULL, // *PreTimgingCounter")
        gr.printFile("        NULL // *NextTimingCounter")
        gr.printFile("    },")

    for task in isr2_core1:
        gr.printFile("    /* Isr {} Task*/".format(task))
        gr.printFile("    {")
        gr.printFile("        TIMEFRAME, // ProtectionType")
        OsIsrTimingProtection = config.getValue("/AUTOSAR/" + task , "OsIsrTimingProtection")
        if OsIsrTimingProtection != False:
            ExecuteBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrExecutionBudget")
            OsIsrTimeFrame = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrTimeFrame")
            gr.printFile("        {}, // Bound".format(float(OsIsrTimeFrame)+1))
            gr.printFile("        {}, // Counter".format(float(OsIsrTimeFrame)+1))
        else:
            gr.printFile("        10000, // Bound")
            gr.printFile("        10000, // Counter")
        gr.printFile("        NULL, // *PreTimgingCounter")
        gr.printFile("        NULL // *NextTimingCounter")
        gr.printFile("    },")
    gr.printFile("};\n")

#.........................................................................
gr.printFile("TimingProtCounterType ResourceTimingCounter_core1[RESOURCES_COUNT_CORE1];")
gr.printFile("TimingProtCounterType InterruptTimingCounter_core1[3];\n")
#..........................................................................
if isr2_core1 != []:
    for task in task_core1:
        OsTaskTimingProtection = config.getValue("/AUTOSAR/" + task , "OsTaskTimingProtection")
        if OsTaskTimingProtection != False:
            OsTaskResourceLocks = config.getList("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskResourceLock")
            gr.printFile("const LockBudgetType LockBudget_{}[{}] = {}".format(task,len(OsTaskResourceLocks)+3 ,"{"))
            gr.printFile("    /* All Interrupt */")
            gr.printFile("    {")
            gr.printFile("        0,")
            OsTaskAllInterruptLockBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskAllInterruptLockBudget")
            gr.printFile("        {}".format(OsTaskAllInterruptLockBudget))
            gr.printFile("    },")
            gr.printFile("    /* OS Interrupt */")
            gr.printFile("    {")
            gr.printFile("        1,")
            OsTaskOsInterruptLockBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskAllInterruptLockBudget")
            gr.printFile("        {}".format(OsTaskOsInterruptLockBudget))
            gr.printFile("    },")
            if len(OsTaskResourceLocks) != 0:
                for resourceLock in OsTaskResourceLocks:
                    resource = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection + "/" + resourceLock, "OsTaskResourceLockResourceRef")
                    gr.printFile("    /* resource {} */".format(resource))
                    gr.printFile("    {")
                    gr.printFile("        {},".format(resource))
                    resourceBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection + "/" + resourceLock, "OsTaskResourceLockBudget")
                    gr.printFile("        {},".format(resourceBudget))
                    gr.printFile("    },")
            
            for app in apps:
                if task in config.getList("/AUTOSAR/" + app , "OsAppTaskRef"):
                    gr.printFile("    /* resource resource{} */".format(app))
                    gr.printFile("    {")
                    gr.printFile("        resource{},".format(app))
                    gr.printFile("        99999")
                    gr.printFile("    },")

        else:
            gr.printFile("const LockBudgetType LockBudget_{}[3] = {}".format(task, "{"))
            gr.printFile("    /* All Interrupt */")
            gr.printFile("    {")
            gr.printFile("        0,")
            gr.printFile("        10000")
            gr.printFile("    },")
            gr.printFile("    /* OS Interrupt */")
            gr.printFile("    {")
            gr.printFile("        1,")
            gr.printFile("        10000")
            gr.printFile("    },")
            for app in apps:
                if task in config.getList("/AUTOSAR/" + app , "OsAppTaskRef"):
                    gr.printFile("    /* resource resource{} */".format(app))
                    gr.printFile("    {")
                    gr.printFile("        resource{},".format(app))
                    gr.printFile("        99999")
                    gr.printFile("    },")
        
        gr.printFile("};")

    for task in isr2_core1:
        OsIsrTimingProtection = config.getValue("/AUTOSAR/" + task , "OsIsrTimingProtection")
        if OsIsrTimingProtection != False:
            OsIsrResourceLocks = config.getList("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrResourceLock")
            gr.printFile("const LockBudgetType LockBudget_{}[{}] = {}".format(task,len(OsIsrResourceLocks)+3 ,"{"))
            gr.printFile("    /* All Interrupt */")
            gr.printFile("    {")
            gr.printFile("        0,")
            OsIsrAllInterruptLockBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrAllInterruptLockBudget")
            gr.printFile("        {}".format(OsIsrAllInterruptLockBudget))
            gr.printFile("    },")
            gr.printFile("    /* OS Interrupt */")
            gr.printFile("    {")
            gr.printFile("        1,")
            OsIsrOsInterruptLockBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrAllInterruptLockBudget")
            gr.printFile("        {}".format(OsIsrOsInterruptLockBudget))
            gr.printFile("    },")
            if len(OsIsrResourceLocks) != 0:
                for resourceLock in OsIsrResourceLocks:
                    resource = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection + "/" + resourceLock, "OsIsrResourceLockResourceRef")
                    gr.printFile("    /* resource {} */".format(resource))
                    gr.printFile("    {")
                    gr.printFile("        {},".format(resource))
                    resourceBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection + "/" + resourceLock, "OsIsrResourceLockBudget")
                    gr.printFile("        {},".format(resourceBudget))
                    gr.printFile("    },")
            
            for app in apps:
                if task in config.getList("/AUTOSAR/" + app , "OsAppIsrRef"):
                    gr.printFile("    /* resource resource{} */".format(app))
                    gr.printFile("    {")
                    gr.printFile("        resource{},".format(app))
                    gr.printFile("        99999")
                    gr.printFile("    },")

        else:
            gr.printFile("const LockBudgetType LockBudget_{}[3] = {}".format(task, "{"))
            gr.printFile("    /* All Interrupt */")
            gr.printFile("    {")
            gr.printFile("        0,")
            gr.printFile("        10000")
            gr.printFile("    },")
            gr.printFile("    /* OS Interrupt */")
            gr.printFile("    {")
            gr.printFile("        1,")
            gr.printFile("        10000")
            gr.printFile("    },")
            for app in apps:
                if task in config.getList("/AUTOSAR/" + app , "OsAppIsrRef"):
                    gr.printFile("    /* resource resource{} */".format(app))
                    gr.printFile("    {")
                    gr.printFile("        resource{},".format(app))
                    gr.printFile("        99999")
                    gr.printFile("    },")
        gr.printFile("};")

#.......................................................................
gr.printFile("const TimingProtBudgetType TimingProtBudget_core1[TASK_OBJECTS_COUNT_CORE1] = {")
gr.printFile("    /* idle task */")
gr.printFile("    {")
gr.printFile("        999, /* ExecuteBudget */")
gr.printFile("        1, /* TimeFrame */")
gr.printFile("        NULL /* LockBudgetRef */")
gr.printFile("    },")

if isr2_core1 != []:
    for task in task_core1:
        OsTaskTimingProtection = config.getValue("/AUTOSAR/" + task , "OsTaskTimingProtection")
        gr.printFile("    /* Task_{} */".format(task))
        gr.printFile("    {")
        if OsTaskTimingProtection != False:
            ExecuteBudget = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskExecutionBudget")
            gr.printFile("        {}, /* ExecuteBudget */".format(ExecuteBudget))   
            OsTaskTimeFrame = config.getValue("/AUTOSAR/" + task + "/" + OsTaskTimingProtection, "OsTaskTimeFrame")
            gr.printFile("        {}, /* TimeFrame */".format(OsTaskTimeFrame))
            gr.printFile("        LockBudget_{} /* LockBudgetRef */".format(task))
            gr.printFile("    },")
        else:
            gr.printFile("        10000, /* ExecuteBudget */")
            gr.printFile("        1, /* TimeFrame */")
            gr.printFile("        LockBudget_{} /* LockBudgetRef */".format(task))
            gr.printFile("    },")

    for task in isr2_core1:
        OsIsrTimingProtection = config.getValue("/AUTOSAR/" + task , "OsIsrTimingProtection")
        gr.printFile("    /* isr {} Task  */".format(task))
        gr.printFile("    {")
        if OsIsrTimingProtection != False:
            ExecuteBudget = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrExecutionBudget")
            gr.printFile("        {}, /* ExecuteBudget */".format(ExecuteBudget))
            OsTaskTimeFrame = config.getValue("/AUTOSAR/" + task + "/" + OsIsrTimingProtection, "OsIsrTimeFrame")
            gr.printFile("        {}, /* TimeFrame */".format(OsTaskTimeFrame))
            gr.printFile("        LockBudget_{} /* LockBudgetRef */".format(task))
        else:
            gr.printFile("        10000, /* ExecuteBudget */")
            gr.printFile("        1, /* TimeFrame */")
            gr.printFile("        LockBudget_{} /* LockBudgetRef */".format(task))
        gr.printFile("    },")

gr.printFile("};\n")






#..............................................................................#
gr.printFile("/** system **/\n")
gr.printFile("TimingProtCounterType *TimingCounterList[OsNumberOfCores];")
gr.printFile("SystemTimingCounterType SystemTimingCounter[OsNumberOfCores] = {")
gr.printFile("    /* Core 0 */")
gr.printFile("    {")
gr.printFile("        TaskExecutingCounter_core0,")
gr.printFile("        TaskArrivalCounter_core0,")
gr.printFile("        ResourceTimingCounter_core0,")
gr.printFile("        InterruptTimingCounter_core0,")
gr.printFile("        TimingProtBudget_core0")
gr.printFile("    },")
gr.printFile("    /* Core 1 */")
gr.printFile("    {")
gr.printFile("        TaskExecutingCounter_core1,")
gr.printFile("        TaskArrivalCounter_core1,")
gr.printFile("        ResourceTimingCounter_core1,")
gr.printFile("        InterruptTimingCounter_core1,")
gr.printFile("        TimingProtBudget_core1")
gr.printFile("    }")
gr.printFile("};\n")

gr.printFile("#pragma section")