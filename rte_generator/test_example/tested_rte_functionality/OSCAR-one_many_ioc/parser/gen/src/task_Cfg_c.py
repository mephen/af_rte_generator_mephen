from generator.config import config 
from generator import globals as gr
from gen.cores import task_cores, isr_cores, app_core0, app_core1

global config
global task_cores
global isr_cores
global app_core0
global app_core1
gr.genfile = open(gr.src_path+"task_Cfg.c",'w')

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("#include \"event_Cfg.h\"")
gr.printFile("#include \"application_Cfg.h\"")
gr.printFile("#include \"spinlock_Cfg.h\"")
gr.printFile("#include \"memsection.h\"")
gr.printFile("#include \"memprot_Cfg.h\"\n")
gr.printFile("/*==================[macros and definitions]=================================*/\n")
gr.printFile("/*==================[internal data declaration]==============================*/\n")
gr.printFile("/*==================[internal functions declaration]=========================*/\n")
gr.printFile("/*==================[internal data definition]===============================*/\n")

#..............................................................................................#
apps = config.getList("/AUTOSAR", "OsApplication")
tasks = config.getList("/AUTOSAR", "OsTask")
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



#.....................................................................................
gr.printFile("/* core 0 */")
gr.printFile("#pragma section ALL_TASK_ISR_STACK_PE1")
gr.printFile("/* Brief idle task stack */")
gr.printFile("uint8 StackTaskIdleTask_core0[StackTaskIdleTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];")
gr.printFile("/* Brief sys task stack */")
gr.printFile("uint8 StackTaskSysTask_core0[StackTaskSysTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];")

for task in task_core0:
    gr.printFile ("/* Brief {} stack */".format(task))
    gr.printFile ("uint8 StackTask{}[ StackTask{}_SIZE + STACK_MONITOR_APPEND_SIZE];".format(task, task))
    
for isr in isr2_core0:
    gr.printFile ("/* Brief {} stack */".format(isr))
    gr.printFile ("uint8 StackIsr2Task{}[StackIsr2Task{}_SIZE + STACK_MONITOR_APPEND_SIZE];".format(isr, isr))

#..................................................................................
gr.printFile("\n/* core 1 */")
gr.printFile("#pragma section ALL_TASK_ISR_STACK_PE2")
gr.printFile("/* Brief idle task stack */")
gr.printFile("uint8 StackTaskIdleTask_core1[StackTaskIdleTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];")
gr.printFile("/* Brief sys task stack */")
gr.printFile("uint8 StackTaskSysTask_core1[StackTaskSysTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];")

for task in task_core1:
    gr.printFile ("/* Brief {} stack */".format(task))
    gr.printFile ("uint8 StackTask{}[ StackTask{}_SIZE + STACK_MONITOR_APPEND_SIZE];".format(task, task))
    
for isr in isr2_core1:
    gr.printFile ("/* Brief {} stack */".format(isr))
    gr.printFile ("uint8 StackIsr2Task{}[StackIsr2Task{}_SIZE + STACK_MONITOR_APPEND_SIZE];".format(isr, isr))

#........................................

gr.printFile("\n#pragma section")
gr.printFile("/* Brief idle task context */")
gr.printFile("TaskContextType ContextIdleTask_core0;")
gr.printFile("/* Brief sys task context */")
gr.printFile("TaskContextType ContextSysTask_core0;")
for task in task_core0:
    gr.printFile ("/* Brief {} context */".format(task))
    gr.printFile ("TaskContextType Context{};".format(task))
for isr in isr2_core0:
    gr.printFile ("/* Brief {} context */".format(isr))
    gr.printFile ("TaskContextType Context{};".format(isr))

gr.printFile("\nTaskVarType *ReadyList_core0[READYLISTS_COUNT_CORE0];\n")
gr.printFile("TaskVarType *ReadyListTail_core0[READYLISTS_COUNT_CORE0];\n")
#.....................................................................

gr.printFile("/* Brief idle task context */")
gr.printFile("TaskContextType ContextIdleTask_core1;")
gr.printFile("/* Brief sys task context */")
gr.printFile("TaskContextType ContextSysTask_core1;")

for task in task_core1:
    gr.printFile ("/* Brief {} context */".format(task))
    gr.printFile ("TaskContextType Context{};".format(task))
for isr in isr2_core1:
    gr.printFile ("/* Brief {} context */".format(isr))
    gr.printFile ("TaskContextType Context{};".format(isr))

gr.printFile("\nTaskVarType *ReadyList_core1[READYLISTS_COUNT_CORE1];\n")
gr.printFile("TaskVarType *ReadyListTail_core1[READYLISTS_COUNT_CORE1];\n")
#............................................................................

gr.printFile("const TaskConstType TaskConst_core0[TASK_OBJECTS_COUNT_CORE0] = {")
gr.printFile("    /* Task IdleTask */")
gr.printFile("    {")            
gr.printFile("        TASK_ENTRY(IdleTask),            /* task entry point */")
gr.printFile("        &ContextIdleTask_core0,          /* pointer to task context */")
gr.printFile("        StackTaskIdleTask_core0,         /* pointer to stack memory */")
gr.printFile("        StackTaskIdleTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE,    /* stack size */")
gr.printFile("        IdleTask_core0,                  /* task id */")
gr.printFile("        {      /* task const flags */")
gr.printFile("            0, /* basic task */")
gr.printFile("            1, /* preemptive task */")
gr.printFile("            0  /* not isr2 task */")
gr.printFile("        },")
gr.printFile("        task_static_prio_idle_core0, /* task priority */")
gr.printFile("        1, /* task max activations */")
gr.printFile("        0, /* events mask */")
gr.printFile("        0,  /* resources mask */\n")
        
gr.printFile("        //RomToRamInitTableType RomToRamInitTable")
gr.printFile("        {")
gr.printFile("            0,  /* IdleTask special case */")
gr.printFile("            0,  /* IdleTask special case */")
gr.printFile("            0,  /* IdleTask special case */")
gr.printFile("            0,  /* IdleTask special case */")
gr.printFile("            0   /* IdleTask special case */")
gr.printFile("        }")
gr.printFile("    },")
#.................................
for task in task_core0:
    gr.printFile("    /* Task {} */".format(task))
    gr.printFile("    {")
    gr.printFile("        TASK_ENTRY({}),            /* task entry point */".format(task))
    gr.printFile("        &Context{}, /* pointer to task context */".format(task))
    gr.printFile("        StackTask{},    /* pointer to stack memory */".format(task))
    gr.printFile("        StackTask{}_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */".format(task))
    gr.printFile("        {}, /* task id */".format(task))
    gr.printFile("        {      /* task const flags */")
    if config.getValue("/AUTOSAR/" + task, "OsTaskType") == "EXTENDED":
        gr.printFile("            1, /* extended task */")
    else:
        gr.printFile("            0, /* not extended task */")

    if config.getValue("/AUTOSAR/" + task, "OsTaskSchedule") == "FULL":
        gr.printFile("            1, /* preemptive task */")
    else:
        gr.printFile("            0, /* not preemptive task */")
    
    gr.printFile("            0  /* not isr2 task */")
    gr.printFile("        },")
    gr.printFile("        task_static_prio_{}, /* task priority */".format(task))
    task_max = config.getValue("/AUTOSAR/" + task, "OsTaskActivation")
    if str(task_max) == "False":
        task_max = "FALSE"
    gr.printFile("        {}, /* task max activations */".format(task_max))
    task_events = config.getList("/AUTOSAR/" + task , "OsTaskEventRef")
    if task_events != []:
        gr.printFileSpace("        0 ")
        for event in task_events:
            if event == task_events[-1]:
                gr.printFile("| {},".format(event))
            else:
                gr.printFileSpace("| {} ".format(event))
    else:
        gr.printFile("        0,")

    task_resources = config.getList("/AUTOSAR/" + task , "OsTaskResourceRef")
    for app in app_core0:
        if task in config.getList("/AUTOSAR/" + app , "OsAppTaskRef"):
            resource_app = "resource" + app
            task_resources.append(resource_app)
            break
    
    gr.printFileSpace("        0 ")
    for resource in task_resources:
        if resource == task_resources[-1]:
            gr.printFile("| (1 << ({} & 0xffff)), ".format(resource))
        else:
            gr.printFileSpace("| (1 << ({} & 0xffff)) ".format(resource))

    gr.printFile("\n        //RomToRamInitTableType RomToRamInitTable")
    gr.printFile("        {")
    gr.printFile("            (uint32*)(_STASK_{}_SEC_data),".format(task))
    gr.printFile("            (uint32*)(_ETASK_{}_SEC_data),".format(task))
    gr.printFile("            (uint32*)(_STASK_{}_SEC_data_R),".format(task))
    gr.printFile("            (uint32*)(_STASK_{}_SEC_bss),".format(task))
    gr.printFile("            (uint32*)(_ETASK_{}_SEC_bss)".format(task))
    gr.printFile("        }")
    gr.printFile("    },")

#......................................................
for task in isr2_core0:
    gr.printFile("    /* isr {} Task */".format(task))
    gr.printFile("    {")
    gr.printFile("        ISR_ENTRY({}),            /* task entry point */".format(task))
    gr.printFile("        &Context{}, /* pointer to task context */".format(task))
    gr.printFile("        StackIsr2Task{},    /* pointer to stack memory */".format(task))
    gr.printFile("        StackIsr2Task{}_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */".format(task))
    gr.printFile("        {} + TASKS_COUNT_CORE0 -1 ,  /* isr2 task id */".format(task))
    gr.printFile("        {      /* task const flags */")
    gr.printFile("            0, /* not extended task */")
    gr.printFile("            1, /* preemptive task */")
    gr.printFile("            1  /* isr2 task */")
    gr.printFile("        },")
    gr.printFile("        task_static_prio_{}, /* task priority */".format(task))
    gr.printFile("        255, /* task max activations */".format(config.getValue("/AUTOSAR/" + task, "OsTaskActivation")))
    gr.printFile("        0, ")

    isr_resources = config.getList("/AUTOSAR/" + task , "OsIsrResourceRef")
    for app in apps:
        if task in config.getList("/AUTOSAR/" + app , "OsAppIsrRef"):
            resource_app = "resource" + app
            break
    isr_resources.append(resource_app)
    gr.printFileSpace("        0 ")
    for resource in isr_resources:
        if resource == isr_resources[-1]:
            gr.printFile("| (1 << ({} & 0xffff)), ".format(resource))
        else:
            gr.printFileSpace("| (1 << ({} & 0xffff)) ".format(resource))
    
    gr.printFile("\n        //RomToRamInitTableType RomToRamInitTable")
    gr.printFile("        {")
    gr.printFile("            (uint32*)(_SISR_{}_SEC_data),".format(task))
    gr.printFile("            (uint32*)(_EISR_{}_SEC_data),".format(task))
    gr.printFile("            (uint32*)(_SISR_{}_SEC_data_R),".format(task))
    gr.printFile("            (uint32*)(_SISR_{}_SEC_bss),".format(task))
    gr.printFile("            (uint32*)(_EISR_{}_SEC_bss)".format(task))
    gr.printFile("        }")
    gr.printFile("    },")

#.............................................................................
gr.printFile("    /* Task sysTask */")
gr.printFile("    {")
gr.printFile("        TASK_ENTRY(SysTask),            /* task entry point */")
gr.printFile("        &ContextSysTask_core0, /* pointer to task context */")
gr.printFile("        StackTaskSysTask_core0,    /* pointer to stack memory */")
gr.printFile("        StackTaskSysTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */".format(task))
gr.printFile("        SysTask_core0,")
gr.printFile("        {      /* task const flags */")
gr.printFile("            0, /* not extended task */")
gr.printFile("            1, /* not preemptive task */")
gr.printFile("            0  /* not isr2 task */")
gr.printFile("        },")
gr.printFile("        task_static_prio_sys_core0, /* task priority */")
gr.printFile("        255, /* task max activations */")
gr.printFile("        0,")
gr.printFileSpace("        0 ")
for app in app_core0:
    if app == app_core0[-1]:
        gr.printFile("| (1 << (resource{} & 0xffff)), ".format(app))
    else:
        gr.printFileSpace("| (1 << (resource{} & 0xffff)) ".format(app))


gr.printFile("\n        //RomToRamInitTableType RomToRamInitTable")
gr.printFile("        {")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("        }")
gr.printFile("    },")   
gr.printFile("};")
#................................................................................

gr.printFile("const TaskConstType TaskConst_core1[TASK_OBJECTS_COUNT_CORE1] = {")
gr.printFile("    /* Task IdleTask */")
gr.printFile("    {")            
gr.printFile("        TASK_ENTRY(IdleTask),            /* task entry point */")
gr.printFile("        &ContextIdleTask_core1,          /* pointer to task context */")
gr.printFile("        StackTaskIdleTask_core1,         /* pointer to stack memory */")
gr.printFile("        StackTaskIdleTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE,    /* stack size */")
gr.printFile("        IdleTask_core1,                  /* task id */")
gr.printFile("        {      /* task const flags */")
gr.printFile("            0, /* basic task */")
gr.printFile("            1, /* preemptive task */")
gr.printFile("            0  /* not isr2 task */")
gr.printFile("        },")
gr.printFile("        task_static_prio_idle_core1, /* task priority */")
gr.printFile("        1, /* task max activations */")
gr.printFile("        0, /* events mask */")
gr.printFile("        0,  /* resources mask */\n")
        
gr.printFile("        //RomToRamInitTableType RomToRamInitTable")
gr.printFile("        {")
gr.printFile("            0,  /* IdleTask special case */")
gr.printFile("            0,  /* IdleTask special case */")
gr.printFile("            0,  /* IdleTask special case */")
gr.printFile("            0,  /* IdleTask special case */")
gr.printFile("            0   /* IdleTask special case */")
gr.printFile("        }")
gr.printFile("    },")
#.................................
for task in task_core1:
    gr.printFile("    /* Task {} */".format(task))
    gr.printFile("    {")
    gr.printFile("        TASK_ENTRY({}),            /* task entry point */".format(task))
    gr.printFile("        &Context{}, /* pointer to task context */".format(task))
    gr.printFile("        StackTask{},    /* pointer to stack memory */".format(task))
    gr.printFile("        StackTask{}_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */".format(task))
    gr.printFile("        {}, /* task id */".format(task))
    gr.printFile("        {      /* task const flags */")
    if config.getValue("/AUTOSAR/" + task, "OsTaskType") == "EXTENDED":
        gr.printFile("            1, /* extended task */")
    else:
        gr.printFile("            0, /* not extended task */")

    if config.getValue("/AUTOSAR/" + task, "OsTaskSchedule") == "FULL":
        gr.printFile("            1, /* preemptive task */")
    else:
        gr.printFile("            0, /* not preemptive task */")
    
    gr.printFile("            0  /* not isr2 task */")
    gr.printFile("        },")
    gr.printFile("        task_static_prio_{}, /* task priority */".format(task))

    if str(task_max) == "False":
        task_max = "FALSE"
    gr.printFile("        {}, /* task max activations */".format(task_max))
    task_events = config.getList("/AUTOSAR/" + task , "OsTaskEventRef")
    if task_events != []:
        gr.printFileSpace("        0 ")
        for event in task_events:
            if event == task_events[-1]:
                gr.printFile("| {},".format(event))
            else:
                gr.printFileSpace("| {} ".format(event))
    else:
        gr.printFile("        0,")

    task_resources = config.getList("/AUTOSAR/" + task , "OsTaskResourceRef")
    for app in app_core1:
        if task in config.getList("/AUTOSAR/" + app , "OsAppTaskRef"):
            resource_app = "resource" + app
            break
    task_resources.append(resource_app)
    gr.printFileSpace("        0 ")
    for resource in task_resources:
        if resource == task_resources[-1]:
            gr.printFile("| (1 << ({} & 0xffff)), ".format(resource))
        else:
            gr.printFileSpace("| (1 << ({} & 0xffff)) ".format(resource))

    gr.printFile("\n        //RomToRamInitTableType RomToRamInitTable")
    gr.printFile("        {")
    gr.printFile("            (uint32*)(_STASK_{}_SEC_data),".format(task))
    gr.printFile("            (uint32*)(_ETASK_{}_SEC_data),".format(task))
    gr.printFile("            (uint32*)(_STASK_{}_SEC_data_R),".format(task))
    gr.printFile("            (uint32*)(_STASK_{}_SEC_bss),".format(task))
    gr.printFile("            (uint32*)(_ETASK_{}_SEC_bss)".format(task))
    gr.printFile("        }")
    gr.printFile("    },")

#......................................................
for task in isr2_core1:
    gr.printFile("    /* isr {} Task */".format(task))
    gr.printFile("    {")
    gr.printFile("        ISR_ENTRY({}),            /* task entry point */".format(task))
    gr.printFile("        &Context{}, /* pointer to task context */".format(task))
    gr.printFile("        StackIsr2Task{},    /* pointer to stack memory */".format(task))
    gr.printFile("        StackIsr2Task{}_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */".format(task))
    gr.printFile("        {} + TASKS_COUNT_CORE1 -1 ,  /* isr2 task id */".format(task))
    gr.printFile("        {      /* task const flags */")
    gr.printFile("            0, /* not extended task */")
    gr.printFile("            1, /* preemptive task */")
    gr.printFile("            1  /* isr2 task */")
    gr.printFile("        },")
    gr.printFile("        task_static_prio_{}, /* task priority */".format(task))
    gr.printFile("        255, /* task max activations */")
    gr.printFile("        0, ")

    isr_resources = config.getList("/AUTOSAR/" + task , "OsIsrResourceRef")
    for app in app_core1:
        if task in config.getList("/AUTOSAR/" + app , "OsAppIsrRef"):
            resource_app = "resource" + app
            break
    isr_resources.append(resource_app)
    gr.printFileSpace("        0 ")
    for resource in isr_resources:
        if resource == isr_resources[-1]:
            gr.printFile("| (1 << ({} & 0xffff)), ".format(resource))
        else:
            gr.printFileSpace("| (1 << ({} & 0xffff)) ".format(resource))
    
    gr.printFile("\n        //RomToRamInitTableType RomToRamInitTable")
    gr.printFile("        {")
    gr.printFile("            (uint32*)(_SISR_{}_SEC_data),".format(task))
    gr.printFile("            (uint32*)(_EISR_{}_SEC_data),".format(task))
    gr.printFile("            (uint32*)(_SISR_{}_SEC_data_R),".format(task))
    gr.printFile("            (uint32*)(_SISR_{}_SEC_bss),".format(task))
    gr.printFile("            (uint32*)(_EISR_{}_SEC_bss)".format(task))
    gr.printFile("        }")
    gr.printFile("    },")

#.............................................................................
gr.printFile("    /* Task sysTask */")
gr.printFile("    {")
gr.printFile("        TASK_ENTRY(SysTask),            /* task entry point */")
gr.printFile("        &ContextSysTask_core1, /* pointer to task context */")
gr.printFile("        StackTaskSysTask_core1,    /* pointer to stack memory */")
gr.printFile("        StackTaskSysTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE, /* stack size */".format(task))
gr.printFile("        SysTask_core1,")
gr.printFile("        {      /* task const flags */")
gr.printFile("            0, /* not extended task */")
gr.printFile("            1, /* not preemptive task */")
gr.printFile("            0  /* not isr2 task */")
gr.printFile("        },")
gr.printFile("        task_static_prio_sys_core1, /* task priority */")
gr.printFile("        255, /* task max activations */")
gr.printFile("        0,")
gr.printFileSpace("        0 ")
for app in app_core1:
    if app == app_core1[-1]:
        gr.printFile("| (1 << (resource{} & 0xffff)), ".format(app))
    else:
        gr.printFileSpace("| (1 << (resource{} & 0xffff)) ".format(app))

gr.printFile("\n        //RomToRamInitTableType RomToRamInitTable")
gr.printFile("        {")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("            0,  /* SysTask special case */")
gr.printFile("        }")
gr.printFile("    },")   
gr.printFile("};\n")
#...................................................................................

gr.printFile("TaskAutosarType TaskAutosar_core0[TASK_OBJECTS_COUNT_CORE0] = {")
gr.printFile("    /* Task IdleTask */")
gr.printFile("    {")
gr.printFile("        INVALID_OSAPPLICATION,")
gr.printFile("        0,")
gr.printFile("        INVALID_SPINLOCK,")
gr.printFile("        NULL")
gr.printFile("    },")
for task in task_core0:
    gr.printFile("    /* Task {} */".format(task))
    gr.printFile("    {")
    for app in apps:
        if task in config.getList("/AUTOSAR/" + app,"OsAppTaskRef"):
            gr.printFile("        {},".format(app))
            break
    task_apps = config.getList("/AUTOSAR/" + task,"OsTaskAccessingApplication")
    if task_apps != []:
        gr.printFileSpace("        0 ")
        for task_app in task_apps:
            if task_app == task_apps[-1]:
                gr.printFile("| (1 << {}), ".format(task_app))
            else:
                gr.printFileSpace("| (1 << {}) ".format(task_app))
    else:
        gr.printFile("        0,")
    gr.printFile("        INVALID_SPINLOCK,")
    gr.printFile("        MemProtArea_{} /* MemArea */".format(task))
    gr.printFile("    },")

for isr in isr2_core0:
    gr.printFile("    /* isrTask {} */".format(isr))
    gr.printFile("    {")
    for app in apps:
        if isr in config.getList("/AUTOSAR/" + app,"OsAppIsrRef"):
            gr.printFile("        {},".format(app))
            gr.printFile("        0 | (1 << {}),".format(app))
            break
    gr.printFile("        INVALID_SPINLOCK,")
    gr.printFile("        MemProtArea_{} /* MemArea */".format(isr))
    gr.printFile("    },")

gr.printFile("    /* Task SysTask */")
gr.printFile("    {")
gr.printFile("        INVALID_OSAPPLICATION,")
gr.printFile("        0,")
gr.printFile("        INVALID_SPINLOCK,")
gr.printFile("        MemProtArea_SysTask_core0 /* MemArea */")
gr.printFile("    },")
gr.printFile("};\n")
#................................................................................

gr.printFile("TaskAutosarType TaskAutosar_core1[TASK_OBJECTS_COUNT_CORE1] = {")
gr.printFile("    /* Task IdleTask */")
gr.printFile("    {")
gr.printFile("        INVALID_OSAPPLICATION,")
gr.printFile("        0,")
gr.printFile("        INVALID_SPINLOCK,")
gr.printFile("        NULL")
gr.printFile("    },")
for task in task_core1:
    gr.printFile("    /* Task {} */".format(task))
    gr.printFile("    {")
    for app in apps:
        if task in config.getList("/AUTOSAR/" + app,"OsAppTaskRef"):
            gr.printFile("        {},".format(app))
            break
    task_apps = config.getList("/AUTOSAR/" + task,"OsTaskAccessingApplication")
    if task_apps != []:
        gr.printFileSpace("        0 ")
        for task_app in task_apps:
            if task_app == task_apps[-1]:
                gr.printFile("| (1 << {}), ".format(task_app))
            else:
                gr.printFileSpace("| (1 << {}) ".format(task_app))
    else:
        gr.printFile("        0,")
    gr.printFile("        INVALID_SPINLOCK,")
    gr.printFile("        MemProtArea_{} /* MemArea */".format(task))
    gr.printFile("    },")

for isr in isr2_core1:
    gr.printFile("    /* isrTask {} */".format(isr))
    gr.printFile("    {")
    for app in apps:
        if isr in config.getList("/AUTOSAR/" + app,"OsAppIsrRef"):
            gr.printFile("        {},".format(app))
            gr.printFile("        0 | (1 << {}),".format(app))
            break
    gr.printFile("        INVALID_SPINLOCK,")
    gr.printFile("        MemProtArea_{} /* MemArea */".format(isr))
    gr.printFile("    },")

gr.printFile("    /* Task SysTask */")
gr.printFile("    {")
gr.printFile("        INVALID_OSAPPLICATION,")
gr.printFile("        0,")
gr.printFile("        INVALID_SPINLOCK,")
gr.printFile("        MemProtArea_SysTask_core1 /* MemArea */")
gr.printFile("    },")
gr.printFile("};")

#......................................................................
gr.printFile ("TaskVarType TaskVar_core0[TASK_OBJECTS_COUNT_CORE0] = {")
gr.printFile ("    /* Task IdleTask */")
gr.printFile ("    {")
gr.printFile ("        &TaskConst_core0[0], /* TaskConst pointer */")
gr.printFile ("        NULL, /* pointer to resources */")
gr.printFile ("        NULL, /* pointer to next task */")
gr.printFile ("        0,    /* the number of activations */")
gr.printFile ("        task_static_prio_idle_core0,    /* task priority */")
gr.printFile ("        0,    /* task state */")
gr.printFile ("        NULL,  /* point to the internal resource */")
gr.printFile ("    },")

num = 1
for task in task_core0 :
    gr.printFile ("    /* Task {} */".format(task))
    gr.printFile ("    {")
    gr.printFile ("        &TaskConst_core0[{}], /* TaskConst pointer */".format(num))
    num += 1
    gr.printFile ("        NULL, /* pointer to resources */")
    gr.printFile ("        NULL, /* pointer to next task */")
    gr.printFile ("        0,    /* the number of activations */")
    gr.printFile ("        task_static_prio_{},".format(task))
    gr.printFile ("        0,    /* task state */")
    gr.printFile ("        NULL,  /* point to the internal resource */")
    for app in app_core0:
        if task in config.getList("/AUTOSAR/" + app,"OsAppTaskRef"):
            gr.printFile("        {}, /* the executing application id */".format(app))
    gr.printFile ("        0, /* nesting trust function count */")
    gr.printFile ("    },")


for task in isr2_core0 :
    gr.printFile ("    /* IsrTask {} */".format(task))
    gr.printFile ("    {")
    gr.printFile ("        &TaskConst_core0[{}], /* TaskConst pointer */".format(num))
    num += 1
    gr.printFile ("        NULL, /* pointer to resources */")
    gr.printFile ("        NULL, /* pointer to next task */")
    gr.printFile ("        0,    /* the number of activations */")
    gr.printFile ("        task_static_prio_{},".format(task))
    gr.printFile ("        0,    /* task state */")
    gr.printFile ("        NULL,  /* point to the internal resource */")
    for app in app_core0:
        if task in config.getList("/AUTOSAR/" + app,"OsAppIsrRef"):
            gr.printFile("        {}, /* the executing application id */".format(app))
    gr.printFile ("        0, /* nesting trust function count */")
    gr.printFile ("    },")

gr.printFile ("/* Task SysTask */")
gr.printFile ("    {")
gr.printFile ("        &TaskConst_core0[{}], /* TaskConst pointer */".format(num))
gr.printFile ("        NULL, /* pointer to resources */")
gr.printFile ("        NULL, /* pointer to next task */")
gr.printFile ("        0,    /* the number of activations */")
gr.printFile ("        task_static_prio_sys_core0,    /* task priority */")
gr.printFile ("        0,    /* task state */")
gr.printFile ("        NULL  /* point to the internal resource */")
gr.printFile ("    },")
gr.printFile ("};")
#...............................................................................

gr.printFile ("TaskVarType TaskVar_core1[TASK_OBJECTS_COUNT_CORE1] = {")
gr.printFile ("    /* Task IdleTask */")
gr.printFile ("    {")
gr.printFile ("        &TaskConst_core1[0], /* TaskConst pointer */")
gr.printFile ("        NULL, /* pointer to resources */")
gr.printFile ("        NULL, /* pointer to next task */")
gr.printFile ("        0,    /* the number of activations */")
gr.printFile ("        task_static_prio_idle_core1,    /* task priority */")
gr.printFile ("        0,    /* task state */")
gr.printFile ("        NULL,  /* point to the internal resource */")
gr.printFile ("    },")

num = 1
for task in task_core1 :
    gr.printFile ("    /* Task {} */".format(task))
    gr.printFile ("    {")
    gr.printFile ("        &TaskConst_core1[{}], /* TaskConst pointer */".format(num))
    num += 1
    gr.printFile ("        NULL, /* pointer to resources */")
    gr.printFile ("        NULL, /* pointer to next task */")
    gr.printFile ("        0,    /* the number of activations */")
    gr.printFile ("        task_static_prio_{},".format(task))
    gr.printFile ("        0,    /* task state */")
    gr.printFile ("        NULL,  /* point to the internal resource */")
    for app in app_core1:
        if task in config.getList("/AUTOSAR/" + app,"OsAppTaskRef"):
            gr.printFile("        {}, /* the executing application id */".format(app))
    gr.printFile ("        0, /* nesting trust function count */")
    gr.printFile ("    },")


for task in isr2_core1:
    gr.printFile ("    /* IsrTask {} */".format(task))
    gr.printFile ("    {")
    gr.printFile ("        &TaskConst_core1[{}], /* TaskConst pointer */".format(num))
    num += 1
    gr.printFile ("        NULL, /* pointer to resources */")
    gr.printFile ("        NULL, /* pointer to next task */")
    gr.printFile ("        0,    /* the number of activations */")
    gr.printFile ("        task_static_prio_{},".format(task))
    gr.printFile ("        0,    /* task state */")
    gr.printFile ("        NULL,  /* point to the internal resource */")
    for app in app_core1:
        if task in config.getList("/AUTOSAR/" + app,"OsAppIsrRef"):
            gr.printFile("        {}, /* the executing application id */".format(app))
    gr.printFile ("        0, /* nesting trust function count */")
    gr.printFile ("    },")

gr.printFile ("/* Task SysTask */")
gr.printFile ("    {")
gr.printFile ("        &TaskConst_core1[{}], /* TaskConst pointer */".format(num))
gr.printFile ("        NULL, /* pointer to resources */")
gr.printFile ("        NULL, /* pointer to next task */")
gr.printFile ("        0,    /* the number of activations */")
gr.printFile ("        task_static_prio_sys_core0,    /* task priority */")
gr.printFile ("        0,    /* task state */")
gr.printFile ("        NULL  /* point to the internal resource */")
gr.printFile ("    },")
gr.printFile ("};")
#...............................................................................

appmodes = config.getList("/AUTOSAR", "OsAppMode")

for appmode in appmodes:
    tasksinmode = []
    for task in tasks:
        autostart = config.getValue("/AUTOSAR/" + task, "OsTaskAutostart")
        if autostart != False:
            taskappmodes = config.getList("/AUTOSAR/" + task + "/" + autostart, "OsTaskAppModeRef")
            for taskappmode in taskappmodes:
                if taskappmode == appmode:
                    tasksinmode.append(task)

    if tasksinmode != []:
        gr.printFile ("/* brief List of Auto Start Tasks in Application Mode "+ appmode +" */")
        gr.printFile ("const TaskType TasksAutoStart{}[TASK_AUTOSTART_{}_COUNT]  = {}".format(appmode, appmode, "{"))
        for task in tasksinmode:
            gr.printFile ("   {},".format(task))
        gr.printFile("};")



gr.printFile ("/* brief AutoStart Array */")
gr.printFile ("const AutoStartType AutoStart[{}]  = {}".format(len(appmodes),"{"))
for appmode in appmodes:
    gr.printFile ("   /* Application Mode "+appmode+" */")
    gr.printFile ("    {")
    gr.printFile ("        TASK_AUTOSTART_{}_COUNT, /* Total Auto Start Tasks in this Application Mode */".format(appmode))
    gr.printFile ("        (TaskRefType)TasksAutoStart{} /* Pointer to the list of Auto Start Stacks on this Application Mode */".format(appmode))
    gr.printFile ("    },")
gr.printFile ("};\n")

gr.printFile("TaskType SysTaskID[OsNumberOfCores] = {")
os = config.getValue("/AUTOSAR","OsOS")
core_counts = int(config.getValue("/AUTOSAR/" + os,"OsNumberOfCores"))
for i in range(core_counts):
    gr.printFile("    SysTask_core{},".format(i))
gr.printFile("};\n")

gr.printFile ("#pragma section")