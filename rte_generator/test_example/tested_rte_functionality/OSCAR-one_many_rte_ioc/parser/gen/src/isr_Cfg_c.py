from generator.config import config
from gen.cores import isr_cores 
from generator import globals as gr

global config
global isr_cores
gr.genfile = open(gr.src_path+"isr_Cfg.c",'w')

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"isr_Cfg.h\"")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("#include \"isr2.h\"")
gr.printFile("#include \"system.h\"")
gr.printFile("#include \"os.h\"")
gr.printFile("#include \"task.h\"")
gr.printFile("#include \"dr7f701527.dvf.h\"")
gr.printFile("#include \"scheduler.h\"\n")

gr.printFile("extern int PrintText(char *TextArray);")
gr.printFile("extern int PrintText_R35(char *TextArray);\n")

isrs = config.getList("/AUTOSAR","OsIsr")
apps = config.getList("/AUTOSAR","OsApplication")

core0_isr1s = []
core0_isr2s = []
core1_isr1s = []
core1_isr2s = []

for isr in isr_cores['core0']:
    isrcat = config.getValue("/AUTOSAR/" + isr,"OsIsrCategory")
    if(isrcat == "CATEGORY_1"):
        core0_isr1s.append(isr) 
    elif (isrcat == "CATEGORY_2"):
        core0_isr2s.append(isr)
for isr in isr_cores['core1']:
    isrcat = config.getValue("/AUTOSAR/" + isr,"OsIsrCategory")            
    if(isrcat == "CATEGORY_1"):
        core1_isr1s.append(isr) 
    elif (isrcat == "CATEGORY_2"):
        core1_isr2s.append(isr)


gr.printFile("IsrConstType Isr_const_core0[ISR_ALL_COUNT_CORE0] = {")
for isr in core0_isr2s:
    gr.printFile("    {")
    gr.printFile("        {},".format(isr))
    gr.printFile("        ISR_CAT_2,")
    priority = config.getValue("/AUTOSAR/" + isr, "OsIsrPriority")
    gr.printFile("        {},//uint8 ISRprio;".format(priority))
    channel = config.getValue("/AUTOSAR/" + isr, "OsIsrInterruptSource")
    gr.printFile("        {},//uint16 ISRchannel;".format(channel))
    gr.printFile("        ({} + TASKS_COUNT_CORE0 - 1),       //TaskType ISR2TaskRefIndex;".format(isr))
    gr.printFile("    },")
        
for isr in core0_isr1s:
    gr.printFile("    {")
    gr.printFile("        {},".format(isr))
    gr.printFile("        ISR_CAT_1,")
    priority = config.getValue("/AUTOSAR/" + isr, "OsIsrPriority")
    gr.printFile("        {},//uint8 ISRprio;".format(priority))
    channel = config.getValue("/AUTOSAR/" + isr, "OsIsrInterruptSource")
    gr.printFile("        {},//uint16 ISRchannel;".format(channel))
    gr.printFile("        0,       //TaskType ISR2TaskRefIndex;".format(isr))
    gr.printFile("    },")

gr.printFile("};")

gr.printFile("IsrConstType Isr_const_core1[ISR_ALL_COUNT_CORE1] = {")
for isr in core1_isr2s:
    gr.printFile("    {")
    gr.printFile("        {},".format(isr))
    gr.printFile("        ISR_CAT_2,")
    priority = config.getValue("/AUTOSAR/" + isr, "OsIsrPriority")
    gr.printFile("        {},//uint8 ISRprio;".format(priority))
    channel = config.getValue("/AUTOSAR/" + isr, "OsIsrInterruptSource")
    gr.printFile("        {},//uint16 ISRchannel;".format(channel))
    gr.printFile("        ({} + TASKS_COUNT_CORE1 - 1),       //TaskType ISR2TaskRefIndex;".format(isr))
    gr.printFile("    },")
        
for isr in core1_isr1s:
    gr.printFile("    {")
    gr.printFile("        {},".format(isr))
    gr.printFile("        ISR_CAT_1,")
    priority = config.getValue("/AUTOSAR/" + isr, "OsIsrPriority")
    gr.printFile("        {},//uint8 ISRprio;".format(priority))
    channel = config.getValue("/AUTOSAR/" + isr, "OsIsrInterruptSource")
    gr.printFile("        {},//uint16 ISRchannel;".format(channel))
    gr.printFile("        0,       //TaskType ISR2TaskRefIndex;".format(isr))
    gr.printFile("    },")

gr.printFile("};")



gr.printFile("IsrConstRefType Isr_const[OsNumberOfCores] = {")
gr.printFile("    Isr_const_core0,")
gr.printFile("    Isr_const_core1,")
gr.printFile("};")


gr.printFile("IsrAutosarType IsrAutosar_core0[ISR_ALL_COUNT_CORE0] = {")
for isr in core0_isr2s:
    gr.printFile("    //{}".format(isr))
    gr.printFile("    {")
    application = config.getList("/AUTOSAR/" + isr, "OsIsrAccessingApplication")
    for app in apps:
        temp = config.getList("/AUTOSAR/" + app ,"OsAppIsrRef")
        if isr in temp:
            gr.printFile("        {},".format(app))
    if application != []:
        gr.printFileSpace("        0 ")
        for app in application:
            gr.printFileSpace("| (1 << {}) ".format(app)) 
        gr.printFile(",") 
    else:
        gr.printFileSpace("        0,")
    gr.printFile("    },")

for isr in core0_isr1s:
    gr.printFile("    //{}".format(isr))
    gr.printFile("    {")
    application = config.getList("/AUTOSAR/" + isr, "OsIsrAccessingApplication")
    for app in apps:
        temp = config.getList("/AUTOSAR/" + app ,"OsAppIsrRef")
        if isr in temp:
            gr.printFile("        {},".format(app))
    if application != []:
        gr.printFileSpace("        0 ")
        for app in application:
            gr.printFileSpace("| (1 << {}) ".format(app)) 
        gr.printFile(",")
    else:
        gr.printFileSpace("        0,")
    gr.printFile("    },")

gr.printFile("};\n")

gr.printFile("IsrAutosarType IsrAutosar_core1[ISR_ALL_COUNT_CORE1] = {")
for isr in core1_isr2s:
    gr.printFile("    //{}".format(isr))
    gr.printFile("    {")
    application = config.getList("/AUTOSAR/" + isr, "OsIsrAccessingApplication")
    for app in apps:
        temp = config.getList("/AUTOSAR/" + app ,"OsAppIsrRef")
        if isr in temp:
            gr.printFile("        {},".format(app))
    if application != []:
        gr.printFileSpace("        0 ")
        for app in application:
            gr.printFileSpace("| (1 << {}) ".format(app)) 
        gr.printFile(",")
    else:
        gr.printFileSpace("        0,")
    gr.printFile("    },")

for isr in core1_isr1s:
    gr.printFile("    //{}".format(isr))
    gr.printFile("    {")
    application = config.getList("/AUTOSAR/" + isr, "OsIsrAccessingApplication")
    for app in apps:
        temp = config.getList("/AUTOSAR/" + app ,"OsAppIsrRef")
        if isr in temp:
            gr.printFile("        {},".format(app))
    if application != []:
        gr.printFileSpace("        0 ")
        for app in application:
            gr.printFileSpace("| (1 << {}) ".format(app)) 
        gr.printFile(",")
    else:
        gr.printFileSpace("        0,")
    gr.printFile("    },")

gr.printFile("};\n")

gr.printFile("/*==================[ISR launhcer]========================================*/")
for isr in core0_isr2s:
    gr.printFile("/* {} launhcer*/".format(isr))
    gr.printFile("#pragma interrupt ISR_{}_LAUNCHER(enable = manual, channel = {}, callt = false, fpu = false)".format(isr,44))
    gr.printFile("void ISR_{}_LAUNCHER(void)".format(isr))    
    gr.printFile("{")
    gr.printFile("    DisableMPU();")
    gr.printFile("    ActivateISR2({});".format(isr))
    gr.printFile("    EnableMPU();")
    gr.printFile("}\n")

for isr in core0_isr1s:
    gr.printFile("/* {} launhcer*/".format(isr))
    gr.printFile("#pragma interrupt ISR_{}_LAUNCHER(enable = manual, channel = {}, callt = false, fpu = false)".format(isr,44))
    gr.printFile("void ISR_{}_LAUNCHER(void)".format(isr))    
    gr.printFile("{")
    gr.printFile("    DisableMPU();")
    gr.printFile("    systemFlag |= IN_ISR1_HANDLER;")
    gr.printFile("    MILKSHOP_ISR_{}();".format(isr))
    gr.printFile("    systemFlag &= ~IN_ISR1_HANDLER;")
    gr.printFile("    EnableMPU();")
    gr.printFile("}\n")

for isr in core1_isr2s:
    gr.printFile("/* {} launhcer*/".format(isr))
    gr.printFile("#pragma interrupt ISR_{}_LAUNCHER(enable = manual, channel = {}, callt = false, fpu = false)".format(isr,44))
    gr.printFile("void ISR_{}_LAUNCHER(void)".format(isr))    
    gr.printFile("{")
    gr.printFile("    DisableMPU();")
    gr.printFile("    ActivateISR2({});".format(isr))
    gr.printFile("    EnableMPU();")
    gr.printFile("}\n")

for isr in core1_isr1s:
    gr.printFile("/* {} launhcer*/".format(isr))
    gr.printFile("#pragma interrupt ISR_{}_LAUNCHER(enable = manual, channel = {}, callt = false, fpu = false)".format(isr,44))
    gr.printFile("void ISR_{}_LAUNCHER(void)".format(isr))    
    gr.printFile("{")
    gr.printFile("    DisableMPU();")
    gr.printFile("    systemFlag |= IN_ISR1_HANDLER;")
    gr.printFile("    MILKSHOP_ISR_{}();".format(isr))
    gr.printFile("    systemFlag &= ~IN_ISR1_HANDLER;")
    gr.printFile("    EnableMPU();")
    gr.printFile("}\n")

