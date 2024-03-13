from generator.config import config 
from generator import globals as gr
from gen.cores import app_core0, app_core1
import os

global app_core0, app_core1

new_line = "      <LinkOptionStart-0>"

def addstr(old_str):
    global new_line
    new_line += old_str

global config
apps = config.getList("/AUTOSAR", "OsApplication")

addstr("RESET_PE1,")
addstr("EIINTTBL_PE1,")
addstr("SYSTEMCALLTBL/%ResetVectorPE1%,")

objects = ["","IOC_RESERVED_SEC", "USER_SHARED_SEC", "LOCAL_RAM_PE1", "LOCAL_RAM_PE2", "SELF_AREA"]
objectssss = ["","IOC_RESERVED_SEC", "USER_SHARED_SEC", "LOCAL_RAM_PE2", "LOCAL_RAM_PE1", "SELF_AREA"]
for object in objects:
    addstr("{}.text,".format(object))

addstr("GLOBAL_RAM_A.text,")
addstr("RETENTION_RAM.text,")

for app in apps:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    addstr("OSAPP_{}_SEC.text,".format(app)) 
    for Isr in Isrs:
        addstr("ISR_{}_SEC.text,".format(Isr))

    for task in tasks:
        addstr("TASK_{}_SEC.text,".format(task))


addstr("GLOBAL_RAM_B.text/00008000,")
addstr("RESET_PE2,")
addstr("EIINTTBL_PE2,")

romatoram = []
for object in objects:
    addstr("{}.const,".format(object))
for object in objectssss:
    romatoram.append("{}.data={}.data.R".format(object, object))

romatoram.append("GLOBAL_RAM_A.data=GLOBAL_RAM_A.data.R")
romatoram.append("RETENTION_RAM.data=RETENTION_RAM.data.R")
romatoram.append("GLOBAL_RAM_B.data=GLOBAL_RAM_B.data.R")


for app in apps:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    addstr("OSAPP_{}_SEC.const,".format(app))
    romatoram.append("OSAPP_{}_SEC.data=OSAPP_{}_SEC.data.R".format(app, app))
    for Isr in Isrs:
        romatoram.append("ISR_{}_SEC.data=ISR_{}_SEC.data.R".format(Isr, Isr)) 
        addstr("ISR_{}_SEC.const,".format(Isr))          
            
    for task in tasks:
        addstr("TASK_{}_SEC.const,".format(task))    
        romatoram.append("TASK_{}_SEC.data=TASK_{}_SEC.data.R".format(task,task)) 


addstr("TASK_SysTask_core0.const,")
romatoram.append("TASK_SysTask_core0.data=TASK_SysTask_core0.data.R") 
addstr("TASK_SysTask_core1.const,")
romatoram.append("TASK_SysTask_core1.data=TASK_SysTask_core1.data.R") 
addstr("GLOBAL_RAM_A.const,")
addstr("RETENTION_RAM.const,")
addstr("GLOBAL_RAM_B.const,")


for object in objects:
    addstr("{}.data,".format(object))

for app in apps:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    addstr("OSAPP_{}_SEC.data,".format(app))
    
    for Isr in Isrs:
        addstr("ISR_{}_SEC.data,".format(Isr))
            
    for task in tasks:
        addstr("TASK_{}_SEC.data,".format(task))

addstr("TASK_SysTask_core0.data,")
addstr("TASK_SysTask_core1.data,")
addstr("GLOBAL_RAM_A.data,")
addstr("RETENTION_RAM.data,")
addstr("GLOBAL_RAM_B.data/00800000,")


addstr("LOCAL_RAM_PE2.bss,")
addstr("LOCAL_RAM_PE2.data.R,")

for app in app_core1:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    addstr("OSAPP_{}_SEC.bss,".format(app))
    addstr("OSAPP_{}_SEC.data.R,".format(app))
        
    for Isr in Isrs:
        addstr("ISR_{}_SEC.bss,".format(Isr))
        addstr("ISR_{}_SEC.data.R,".format(Isr))

    for task in tasks:
        addstr("TASK_{}_SEC.bss,".format(task))
        addstr("TASK_{}_SEC.data.R,".format(task))

addstr("TASK_SysTask_core1.bss,")
addstr("TASK_SysTask_core1.data.R,")
addstr("ALL_TASK_ISR_STACK_PE2.bss,")
addstr("system_pe2_stack.bss/FE9E0000,")


addstr("LOCAL_RAM_PE1.bss,")
addstr("LOCAL_RAM_PE1.data.R,")

for app in app_core0:
    tasks = config.getList("/AUTOSAR/" + app, "OsAppTaskRef")
    Isrs = config.getList("/AUTOSAR/" + app, "OsAppIsrRef")

    addstr("OSAPP_{}_SEC.bss,".format(app))
    addstr("OSAPP_{}_SEC.data.R,".format(app))

    for Isr in Isrs:
        addstr("ISR_{}_SEC.bss,".format(Isr))
        addstr("ISR_{}_SEC.data.R,".format(Isr))

    for task in tasks:
        addstr("TASK_{}_SEC.bss,".format(task))
        addstr("TASK_{}_SEC.data.R,".format(task))
    
addstr("TASK_SysTask_core0.bss,")
addstr("TASK_SysTask_core0.data.R,")
addstr("ALL_TASK_ISR_STACK_PE1.bss,")
addstr("system_pe1_stack.bss/FEBC0000,")


addstr("SELF_AREA.bss,SELF_AREA.data.R/FEDFE000,")
addstr("IOC_RESERVED_SEC.bss,IOC_RESERVED_SEC.data.R,GLOBAL_RAM_A.bss,GLOBAL_RAM_A.data.R/FEEF8000,")
addstr(".bss,.data.R,RETENTION_RAM.bss,RETENTION_RAM.data.R/FEF01000,")
addstr("USER_SHARED_SEC.bss,USER_SHARED_SEC.data.R,GLOBAL_RAM_B.bss,GLOBAL_RAM_B.data.R/FEFF8000</LinkOptionStart-0>")


flag = 0
file1 = r"./file/MilkshopAUTOSAR_original.mtpj"
file2 = r"../MilkshopAUTOSAR.mtpj"
with open(file1, "r", encoding = "utf-8") as f1,open(file2, "w", encoding = "utf-8") as f2:
    for line in f1:
        if flag == 0:
            if "<LinkOptionStart-0>" in line:
                line = new_line +"\n"
            elif "<LinkOptionRom-0>" in line:
                flag = 1
            f2.write(line)
        elif flag == 1 :
            for index in romatoram:
                if index != ".data=.data.R":
                    line2 = index +"\n"
                    f2.write(line2)
            flag = 2
            f2.write("</LinkOptionRom-0>\n")
        elif flag == 2:
            f2.write(line)




#with open(file, "w", encoding = "utf-8") as f:
#    f.write(file_data)

