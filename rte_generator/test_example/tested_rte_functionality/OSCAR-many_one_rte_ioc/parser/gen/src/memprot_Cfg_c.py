from generator.config import config 
from generator import globals
import os 
from gen.cores import task_cores, isr_cores, app_core0, app_core1
#import generator.generators as gr

global config
global task_cores
global isr_cores
global app_core0
global app_core1
globals.genfile = open(globals.src_path+"memprot_Cfg.c",'w')

apps = config.getList("/AUTOSAR", "OsApplication")
tasks = config.getList("/AUTOSAR", "OsTask")
isrs = config.getList("/AUTOSAR", "OsIsr")
peripheraAreas = config.getList("/AUTOSAR", "OsPeripheralArea")
task_core0 = task_cores['core0']
task_core1 = task_cores['core1']
isr2_core0 = []
isr2_core1 = []

for isr in isr_cores['core0']:
    if config.getValue("/AUTOSAR/"+ isr, "OsIsrCategory") == "CATEGORY_2":
        isr2_core0.append(isr)

for isr in isr_cores['core1']:    
    if config.getValue("/AUTOSAR/"+ isr, "OsIsrCategory") == "CATEGORY_2":
        isr2_core1.append(isr)



globals.printFile("#include \"typedefine.h\"")
globals.printFile("#include \"application_Cfg.h\"")
globals.printFile("#include \"memsection.h\"")
globals.printFile("#include \"memprot_Cfg.h\"")
globals.printFile("#include \"memprot.h\"")
globals.printFile("#include \"task_Cfg.h\"\n")
globals.printFile("#pragma section\n")

globals.printFile("OsPeriAreaInfoType OsPeriAreaInfoArr[OsPeriAreaID_COUNT] = {")
for peri in peripheraAreas:
    globals.printFile("    {")
    globals.printFile("        PERI_{}_ID,".format(peri))
    globals.printFile("        (uint32)0,")
    globals.printFile("        (uint32)0,")
    peri_app = config.getList("/AUTOSAR/" + peri , "OsPeripheralAreaAccessingApplication")
    if peri_app != []:
        globals.printFileSpace("        0 ")
        for app in peri_app:
            if app == peri_app[-1]:
                globals.printFile("| (1 << {}) ".format(app))
            else:
                globals.printFileSpace("| (1 << {}) ".format(app))
    else:
        globals.printFile("        0 ")
    globals.printFile("    },")
globals.printFile("};\n")



globals.printFile("/* core0 */")
globals.printFile("extern uint8 StackTaskIdleTask_core0[StackTaskIdleTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];")
globals.printFile("extern uint8 StackTaskSysTask_core0[StackTaskSysTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];")

if task_core0 != []:
    for task in task_core0:
        globals.printFile("extern uint8 StackTask{}[StackTask{}_SIZE + STACK_MONITOR_APPEND_SIZE];".format(task, task))
globals.printFile("")

if isr2_core0 != []:
    for isr2 in isr2_core0:
        globals.printFile("extern uint8 StackIsr2Task{}[StackIsr2Task{}_SIZE + STACK_MONITOR_APPEND_SIZE];".format(isr2, isr2))
globals.printFile("")

globals.printFile("/* core1 */")
globals.printFile("extern uint8 StackTaskIdleTask_core1[StackTaskIdleTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];")
globals.printFile("extern uint8 StackTaskSysTask_core1[StackTaskSysTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];")

if task_core1 != []:
    for task in task_core1:
        globals.printFile("extern uint8 StackTask{}[StackTask{}_SIZE + STACK_MONITOR_APPEND_SIZE];".format(task, task))
globals.printFile("")

if isr2_core1 != []:
    for isr2 in isr2_core1:
        globals.printFile("extern uint8 StackIsr2Task{}[StackIsr2Task{}_SIZE + STACK_MONITOR_APPEND_SIZE];".format(isr2, isr2))
globals.printFile("")


globals.printFile("/* The first 3 Memory protection register is same forever */")
globals.printFile("MemProtAreaType MemProtArea_OS[3] = {")
globals.printFile("    /* Area 0, kernel text */")
globals.printFile("    {")
globals.printFile("        (uint32)(0),")
globals.printFile("        (uint32)(_ERETENTION_RAM_text),")
globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SX | MPAT_SR | MPAT_UX | MPAT_UR")
globals.printFile("    },")
globals.printFile("    /* Area 1, All const */")
globals.printFile("    {")
globals.printFile("        (uint32)(_S_const),")
globals.printFile("        (uint32)(_EGLOBAL_RAM_B_const),")
globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SR | MPAT_UR")
globals.printFile("    },")
globals.printFile("    /* Area 2, Shared library  */")
globals.printFile("    {")
globals.printFile("        (uint32)(_SUSER_SHARED_SEC_bss),")
globals.printFile("        (uint32)(_EUSER_SHARED_SEC_data_R),")
globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR ")
globals.printFile("    },")
globals.printFile("};")

globals.printFile("/* Stack area */")
globals.printFile("MemProtAreaType MemStackArea[2] = {")
globals.printFile("    {")
globals.printFile("        (_SALL_TASK_ISR_STACK_PE1_bss),") 
globals.printFile("        (_EALL_TASK_ISR_STACK_PE1_bss),")
globals.printFile("        0,")
globals.printFile("    },")
globals.printFile("    {")
globals.printFile("        (_SALL_TASK_ISR_STACK_PE2_bss),") 
globals.printFile("        (_EALL_TASK_ISR_STACK_PE2_bss),")
globals.printFile("        0,")
globals.printFile("    },")
globals.printFile("};")


globals.printFile("MemProtAreaType MemProtArea_SysTask_core0[2] = {")
globals.printFile("    /* Area 5, Task global data */")
globals.printFile("    {")
globals.printFile("        (uint32)(_STASK_SysTask_core0_bss), //S_bss") 
globals.printFile("        (uint32)(_ETASK_SysTask_core0_data_R), //E_data_R")
globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR ")
globals.printFile("    },")
globals.printFile("    /* Area 6, Task stack */")
globals.printFile("    {")
globals.printFile("        (uint32)(StackTaskSysTask_core0),")
globals.printFile("        (uint32)(StackTaskSysTask_core0 + StackTaskSysTask_core0_SIZE),")
globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR ")
globals.printFile("    },")
globals.printFile("};")

globals.printFile("MemProtAreaType MemProtArea_SysTask_core1[2] = {")
globals.printFile("    /* Area 5, Task global data */")
globals.printFile("    {")
globals.printFile("        (uint32)(_STASK_SysTask_core1_bss), //S_bss") 
globals.printFile("        (uint32)(_ETASK_SysTask_core1_data_R), //E_data_R")
globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR ")
globals.printFile("    },")
globals.printFile("    /* Area 6, Task stack */")
globals.printFile("    {")
globals.printFile("        (uint32)(StackTaskSysTask_core1),")
globals.printFile("        (uint32)(StackTaskSysTask_core1 + StackTaskSysTask_core1_SIZE),")
globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR ")
globals.printFile("    },")
globals.printFile("};")




globals.printFile("/* All Task Memory protection section bound and setting */")  
if tasks != []:
    print(tasks)
    for task in tasks:
        globals.printFile("MemProtAreaType MemProtArea_{}[2] = {}".format(task, "{"))
        globals.printFile("    /* Area 5, Task global data */")
        globals.printFile("    {")
        globals.printFile("        (uint32)(_STASK_{}_SEC_bss), //S_bss".format(task))
        globals.printFile("        (uint32)(_ETASK_{}_SEC_data_R), //E_data_R".format(task))
        globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR") 
        globals.printFile("    },")
        globals.printFile("    /* Area 6, Task stack */")
        globals.printFile("    {")
        globals.printFile("        (uint32)(StackTask{}),".format(task))
        globals.printFile("        (uint32)(StackTask{} + StackTask{}_SIZE),".format(task, task))
        globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR") 
        globals.printFile("    },")
        globals.printFile("};")

if isr2_core0 != []:
    for isr2 in isr2_core0:
        globals.printFile("MemProtAreaType MemProtArea_{}[2] = {}".format(isr2, "{"))
        globals.printFile("    /* Area 5, Task global data */")
        globals.printFile("    {")
        globals.printFile("        (uint32)(_SISR_{}_SEC_bss), //S_bss".format(isr2))
        globals.printFile("        (uint32)(_EISR_{}_SEC_data_R), //E_data_R".format(isr2))
        globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR") 
        globals.printFile("    },")
        globals.printFile("    /* Area 6, Task stack */")
        globals.printFile("    {")
        globals.printFile("        (uint32)(StackIsr2Task{}),".format(isr2))
        globals.printFile("        (uint32)(StackIsr2Task{} + StackIsr2Task{}_SIZE),".format(isr2, isr2))
        globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR") 
        globals.printFile("    },")
        globals.printFile("};")

if isr2_core1 != []:
    for isr2 in isr2_core1:
        globals.printFile("MemProtAreaType MemProtArea_{}[2] = {}".format(isr2, "{"))
        globals.printFile("    /* Area 5, Task global data */")
        globals.printFile("    {")
        globals.printFile("        (uint32)(_SISR_{}_SEC_bss), //S_bss".format(isr2))
        globals.printFile("        (uint32)(_EISR_{}_SEC_data_R), //E_data_R".format(isr2))
        globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR") 
        globals.printFile("    },")
        globals.printFile("    /* Area 6, Task stack */")
        globals.printFile("    {")
        globals.printFile("        (uint32)(StackIsr2Task{}),".format(isr2))
        globals.printFile("        (uint32)(StackIsr2Task{} + StackIsr2Task{}_SIZE),".format(isr2, isr2))
        globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR") 
        globals.printFile("    },")
        globals.printFile("};")

if apps != []:
    for app in apps:
        globals.printFile("MemProtAreaType MemProtArea_{}[2] = {}".format(app, "{"))
        globals.printFile("    /* Area 3, OS-App text */")
        globals.printFile("    {")
        globals.printFile("        (uint32)(_SOSAPP_{}_SEC_text),".format(app))
        task_list = config.getList("/AUTOSAR/"+ app ,"OsAppTaskRef")
        globals.printFile("        (uint32)(_ETASK_{}_SEC_text),".format(task_list[-1]))
        globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SX | MPAT_SR | MPAT_UX | MPAT_UR") 
        globals.printFile("    },")
        globals.printFile("    /* Area 4, OS-App data */")
        globals.printFile("    {")
        globals.printFile("        (uint32)(_SOSAPP_{}_SEC_bss),".format(app))
        globals.printFile("        (uint32)(_EOSAPP_{}_SEC_data_R),".format(app))
        globals.printFile("        0 | MPAT_E | MPAT_G | MPAT_SR | MPAT_SW | MPAT_UR | MPAT_UW") 
        globals.printFile("    },")
        globals.printFile("};")



globals.printFile("/* All dummy data here */")
globals.printFile("/* The purpose of Dummy data is to remind the OS to generate a section tag */\n")

objects_1 = ["", "IOC_RESERVED_SEC", "USER_SHARED_SEC", "LOCAL_RAM_PE1", "LOCAL_RAM_PE2", "SELF_AREA", "RETENTION_RAM"]
for object in objects_1:
    globals.printFile("#pragma section {}".format(object))
    globals.printFile("const int dummy_{}_const;".format(object))
    globals.printFile("int dummy_{}_data = 1;".format(object))
    globals.printFile("int dummy_{}_bss;".format(object))
    globals.printFile("void dummy_{}_func(){};\n".format(object, "{;}"))

if apps != []:
    for app in apps:
        globals.printFile("#pragma section OSAPP_{}_SEC".format(app))
        globals.printFile("const int dummy_OSAPP_{}_SEC_const;".format(app))
        globals.printFile("int dummy_OSAPP_{}_SEC_data = 1;".format(app))
        globals.printFile("int dummy_OSAPP_{}_SEC_bss;".format(app))
        globals.printFile("void dummy_OSAPP_{}_SEC_func(){};\n".format(app, "{;}"))
    
        isrs = config.getList("/AUTOSAR/"+ app ,"OsAppIsrRef")
        for isr in isrs:
            globals.printFile("#pragma section ISR_{}_SEC".format(isr))
            globals.printFile("const int dummy_ISR_{}_SEC_const;".format(isr))
            globals.printFile("int dummy_ISR_{}_SEC_data = 1;".format(isr))
            globals.printFile("int dummy_ISR_{}_SEC_bss;".format(isr))
            globals.printFile("void dummy_ISR_{}_SEC_func(){};\n".format(isr, "{;}"))

        tasks = config.getList("/AUTOSAR/"+ app ,"OsAppTaskRef")
        for task in tasks:
            globals.printFile("#pragma section TASK_{}_SEC".format(task))
            globals.printFile("const int dummy_TASK_{}_SEC_const;".format(task))
            globals.printFile("int dummy_TASK_{}_SEC_data = 1;".format(task))
            globals.printFile("int dummy_TASK_{}_SEC_bss;".format(task))
            globals.printFile("void dummy_TASK_{}_SEC_func(){};\n".format(task, "{;}"))


objects_2 = ["GLOBAL_RAM_B", "GLOBAL_RAM_A", "TASK_SysTask_core0", "TASK_SysTask_core1"]
for object in objects_2:
    globals.printFile("#pragma section {}".format(object))
    globals.printFile("const int dummy_{}_const;".format(object))
    globals.printFile("int dummy_{}_data = 1;".format(object))
    globals.printFile("int dummy_{}_bss;".format(object))
    globals.printFile("void dummy_{}_func(){};\n".format(object, "{;}"))

"""
globals.printFile("#define AREA_COUNT 2")
globals.printFile("PeripheralAutosarType PeripherilAutosar_core0[AREA_COUNT] = {")
globals.printFile("    {")
globals.printFile("        0 | (1 << App1) | (1 << App3),")
globals.printFile("    },")
globals.printFile("    {")
globals.printFile("        0 | (1 << App4) | (1 << App2),")
globals.printFile("    },")
globals.printFile("};")


globals.printFile("PeripheralAutosarType PeripherilAutosar_core1[AREA_COUNT] = {")
globals.printFile("    {")
globals.printFile("        0 | (1 << App1) | (1 << App3),")
globals.printFile("    },")
globals.printFile("    {")
globals.printFile("        0 | (1 << App4) | (1 << App2),")
globals.printFile("    },")
globals.printFile("};")
"""



globals.printFile("#pragma section") 