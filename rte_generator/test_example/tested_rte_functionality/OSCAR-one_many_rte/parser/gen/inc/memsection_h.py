from generator.config import config 
from generator import globals as gr
import os
from gen.cores import app_core0, app_core1
#import generator.generators as gr

global config
global app_core0, app_core1
gr.genfile = open("../device/memsection.h",'w')

apps = config.getList("/AUTOSAR", "OsApplication")


gr.printFile("#ifndef MEMSECTION_H")
gr.printFile("#define MEMSECTION_H")
gr.printFile("/* Extern all section tag! */\n")

gr.printFile("/* %ResetVectorPE1% */")
gr.printFile("extern char _SRESET_PE1[];")
gr.printFile("extern char _ERESET_PE1[];")
gr.printFile("extern char _SEIINTTBL_PE1[];")
gr.printFile("extern char _EEIINTTBL_PE1[];")
gr.printFile("extern char _SSYSTEMCALLTBL[];")
gr.printFile("extern char _ESYSTEMCALLTBL[];\n")


objects = ["","IOC_RESERVED_SEC", "USER_SHARED_SEC", "LOCAL_RAM_PE1", "LOCAL_RAM_PE2", "SELF_AREA"]
gr.printFile("/* 0x00008000 All .text */")
for object in objects:
    gr.printFile("extern char _S{}_text[];".format(object))
    gr.printFile("extern char _E{}_text[];".format(object))

gr.printFile("extern char _SGLOBAL_RAM_A_text[];")
gr.printFile("extern char _EGLOBAL_RAM_A_text[];")
gr.printFile("extern char _SRETENTION_RAM_text[];")
gr.printFile("extern char _ERETENTION_RAM_text[];\n")

for app in apps:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    gr.printFile("extern char _SOSAPP_{}_SEC_text[];".format(app))
    gr.printFile("extern char _EOSAPP_{}_SEC_text[];".format(app))
    
    for Isr in Isrs:
        #if config.getValue("/AUTOSAR/" + Isr, "OsIsrCategory") == "CATEGORY_2":
        gr.printFile("extern char _SISR_{}_SEC_text[];".format(Isr))
        gr.printFile("extern char _EISR_{}_SEC_text[];".format(Isr))

    for task in tasks:
        gr.printFile("extern char _STASK_{}_SEC_text[];".format(task))
        gr.printFile("extern char _ETASK_{}_SEC_text[];".format(task))
    
    gr.printFile("")

gr.printFile("extern char _SGLOBAL_RAM_B_text[];")
gr.printFile("extern char _EGLOBAL_RAM_B_text[];")

gr.printFile("/* 0x00800000 All .const and .data */")
gr.printFile("extern char _SRESET_PE2[];")
gr.printFile("extern char _ERESET_PE2[];")
gr.printFile("extern char _SEIINTTBL_PE2[];")
gr.printFile("extern char _EEIINTTBL_PE2[];\n")
for object in objects:
    gr.printFile("extern char _S{}_const[];".format(object))
    gr.printFile("extern char _E{}_const[];".format(object))

gr.printFile("")
for app in apps:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    gr.printFile("extern char _SOSAPP_{}_SEC_const[];".format(app))
    gr.printFile("extern char _EOSAPP_{}_SEC_const[];".format(app))
    
    for Isr in Isrs:
        #if config.getValue("/AUTOSAR/" + Isr, "OsIsrCategory") == "CATEGORY_2":
        gr.printFile("extern char _SISR_{}_SEC_const[];".format(Isr))
        gr.printFile("extern char _EISR_{}_SEC_const[];".format(Isr))

    for task in tasks:
        gr.printFile("extern char _STASK_{}_SEC_const[];".format(task))
        gr.printFile("extern char _ETASK_{}_SEC_const[];".format(task))
    
    gr.printFile("")

gr.printFile("extern char _SGLOBAL_RAM_A_const[];")
gr.printFile("extern char _EGLOBAL_RAM_A_const[];")
gr.printFile("extern char _SRETENTION_RAM_const[];")
gr.printFile("extern char _ERETENTION_RAM_const[];")
gr.printFile("extern char _SGLOBAL_RAM_B_const[];")
gr.printFile("extern char _EGLOBAL_RAM_B_const[];\n")


for object in objects:
    gr.printFile("extern char _S{}_data[];".format(object))
    gr.printFile("extern char _E{}_data[];".format(object))

gr.printFile("")
for app in apps:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    gr.printFile("extern char _SOSAPP_{}_SEC_data[];".format(app))
    gr.printFile("extern char _EOSAPP_{}_SEC_data[];".format(app))
    
    for Isr in Isrs:
        #if config.getValue("/AUTOSAR/" + Isr, "OsIsrCategory") == "CATEGORY_2":
        gr.printFile("extern char _SISR_{}_SEC_data[];".format(Isr))
        gr.printFile("extern char _EISR_{}_SEC_data[];".format(Isr))

    for task in tasks:
        gr.printFile("extern char _STASK_{}_SEC_data[];".format(task))
        gr.printFile("extern char _ETASK_{}_SEC_data[];".format(task))
    
    gr.printFile("")

gr.printFile("extern char _SGLOBAL_RAM_A_data[];")
gr.printFile("extern char _EGLOBAL_RAM_A_data[];")
gr.printFile("extern char _SRETENTION_RAM_data[];")
gr.printFile("extern char _ERETENTION_RAM_data[];")
gr.printFile("extern char _SGLOBAL_RAM_B_data[];")
gr.printFile("extern char _EGLOBAL_RAM_B_data[];\n")


gr.printFile("/* 0xFEBC0000 All .bss .data.R in PE2 */")
gr.printFile("extern char _SLOCAL_RAM_PE2_bss[];")
gr.printFile("extern char _ELOCAL_RAM_PE2_bss[];")
gr.printFile("extern char _SLOCAL_RAM_PE2_data_R[];")
gr.printFile("extern char _ELOCAL_RAM_PE2_data_R[];\n")

for app in app_core1:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    gr.printFile("extern char _SOSAPP_{}_SEC_bss[];".format(app))
    gr.printFile("extern char _EOSAPP_{}_SEC_bss[];".format(app))
    gr.printFile("extern char _SOSAPP_{}_SEC_data_R[];".format(app))
    gr.printFile("extern char _EOSAPP_{}_SEC_data_R[];".format(app))

    for Isr in Isrs:
        gr.printFile("extern char _SISR_{}_SEC_bss[];".format(Isr))
        gr.printFile("extern char _EISR_{}_SEC_bss[];".format(Isr))
        gr.printFile("extern char _SISR_{}_SEC_data_R[];".format(Isr))
        gr.printFile("extern char _EISR_{}_SEC_data_R[];".format(Isr))

    for task in tasks:
        gr.printFile("extern char _STASK_{}_SEC_bss[];".format(task))
        gr.printFile("extern char _ETASK_{}_SEC_bss[];".format(task))
        gr.printFile("extern char _STASK_{}_SEC_data_R[];".format(task))
        gr.printFile("extern char _ETASK_{}_SEC_data_R[];".format(task))

    gr.printFile("")
gr.printFile("extern char _STASK_SysTask_core1_bss[];")
gr.printFile("extern char _ETASK_SysTask_core1_bss[];")
gr.printFile("extern char _STASK_SysTask_core1_data_R[];")
gr.printFile("extern char _ETASK_SysTask_core1_data_R[];\n")

gr.printFile("extern char _SALL_TASK_ISR_STACK_PE2_bss[];")
gr.printFile("extern char _EALL_TASK_ISR_STACK_PE2_bss[];")
gr.printFile("extern char _Ssystem_pe2_stack_bss[];")
gr.printFile("extern char _Esystem_pe2_stack_bss[];\n")


gr.printFile("/* 0xFEBC0000 All .bss .data.R in PE1 */")
gr.printFile("extern char _SLOCAL_RAM_PE1_bss[];")
gr.printFile("extern char _ELOCAL_RAM_PE1_bss[];")
gr.printFile("extern char _SLOCAL_RAM_PE1_data_R[];")
gr.printFile("extern char _LOCAL_RAM_PE1_data_R[];\n")

for app in app_core0:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    gr.printFile("extern char _SOSAPP_{}_SEC_bss[];".format(app))
    gr.printFile("extern char _EOSAPP_{}_SEC_bss[];".format(app))
    gr.printFile("extern char _SOSAPP_{}_SEC_data_R[];".format(app))
    gr.printFile("extern char _EOSAPP_{}_SEC_data_R[];".format(app))

    for Isr in Isrs:
        gr.printFile("extern char _SISR_{}_SEC_bss[];".format(Isr))
        gr.printFile("extern char _EISR_{}_SEC_bss[];".format(Isr))
        gr.printFile("extern char _SISR_{}_SEC_data_R[];".format(Isr))
        gr.printFile("extern char _EISR_{}_SEC_data_R[];".format(Isr))

    for task in tasks:
        gr.printFile("extern char _STASK_{}_SEC_bss[];".format(task))
        gr.printFile("extern char _ETASK_{}_SEC_bss[];".format(task))
        gr.printFile("extern char _STASK_{}_SEC_data_R[];".format(task))
        gr.printFile("extern char _ETASK_{}_SEC_data_R[];".format(task))

    gr.printFile("")
gr.printFile("extern char _STASK_SysTask_core0_bss[];")
gr.printFile("extern char _ETASK_SysTask_core0_bss[];")
gr.printFile("extern char _STASK_SysTask_core0_data_R[];")
gr.printFile("extern char _ETASK_SysTask_core0_data_R[];\n")

gr.printFile("extern char _SALL_TASK_ISR_STACK_PE1_bss[];")
gr.printFile("extern char _EALL_TASK_ISR_STACK_PE1_bss[];")
gr.printFile("extern char _Ssystem_pe1_stack_bss[];")
gr.printFile("extern char _Esystem_pe1_stack_bss[];\n")


gr.printFile("/* 0xFEDFE000 self os .bss .data.R */")
gr.printFile("extern char _SSELF_AREA_bss[];")
gr.printFile("extern char _ESELF_AREA_bss[];")
gr.printFile("extern char _SSELF_AREA_data_R[];")
gr.printFile("extern char _ESELF_AREA_data_R[];\n")

gr.printFile("/* 0xFEDFE000 self os .bss .data.R */")
gr.printFile("extern char _SIOC_RESERVED_SEC_bss[];")
gr.printFile("extern char _EIOC_RESERVED_SEC_bss[];")
gr.printFile("extern char _SIOC_RESERVED_SEC_data_R[];")
gr.printFile("extern char _EIOC_RESERVED_SEC_data_R[];")
gr.printFile("extern char _SGLOBAL_RAM_A_bss[];")
gr.printFile("extern char _EGLOBAL_RAM_A_bss[];")
gr.printFile("extern char _SGLOBAL_RAM_A_data_R[];")
gr.printFile("extern char _EGLOBAL_RAM_A_data_R[];\n")

gr.printFile("/* 0xFEF01000 */")
gr.printFile("extern char _S_bss[];")
gr.printFile("extern char _E_bss[];")
gr.printFile("extern char _S_data_R[];")
gr.printFile("extern char _E_data_R[];")
gr.printFile("extern char _SRETENTION_RAM_bss[];")
gr.printFile("extern char _ERETENTION_RAM_bss[];")
gr.printFile("extern char _SRETENTION_RAM_data_R[];")
gr.printFile("extern char _ERETENTION_RAM_data_R[];\n")

gr.printFile("/* 0xFEF01000 */")
gr.printFile("extern char _SUSER_SHARED_SEC_bss[];")
gr.printFile("extern char _EUSER_SHARED_SEC_bss[];")
gr.printFile("extern char _SUSER_SHARED_SEC_data_R[];")
gr.printFile("extern char _EUSER_SHARED_SEC_data_R[];")
gr.printFile("extern char _SGLOBAL_RAM_B_bss[];")
gr.printFile("extern char _EGLOBAL_RAM_B_bss[];")
gr.printFile("extern char _SGLOBAL_RAM_B_data_R[];")
gr.printFile("extern char _EGLOBAL_RAM_B_data_R[];\n")
gr.printFile("#endif  /* MEMSECTION_H */")































