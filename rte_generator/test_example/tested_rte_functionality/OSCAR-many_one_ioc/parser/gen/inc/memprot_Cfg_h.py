from generator.config import config 
from gen.cores import task_cores, isr_cores
from generator import globals as gr
import os

global config
global task_cores
global isr_cores
gr.genfile = open(gr.inc_path+"memprot_Cfg.h",'w')

apps = config.getList("/AUTOSAR", "OsApplication")
tasks = config.getList("/AUTOSAR", "OsTask")
isrs = config.getList("/AUTOSAR", "OsIsr")

peripheralAreas = config.getList("/AUTOSAR", "OsPeripheralArea")
task_core0 = task_cores['core0']
task_core1 = task_cores['core1']
isr2_core0 = []
isr2_core1 = []


for isr in isrs:
    if isr in isr_cores['core0']:
        if config.getValue("/AUTOSAR/"+ isr, "OsIsrCategory") == "CATEGORY_2":
            isr2_core0.append(isr)
    elif isr in isr_cores['core1']: 
        if config.getValue("/AUTOSAR/"+ isr, "OsIsrCategory") == "CATEGORY_2":
            isr2_core1.append(isr)



gr.printFile("#ifndef MEMPROT_CFG_H")
gr.printFile("#define MEMPROT_CFG_H")
gr.printFile("#include \"task_Cfg.h\"\n")

gr.printFile("/* OS Protection Area */")
gr.printFile("extern MemProtAreaType MemProtArea_OS[3];\n")
gr.printFile("extern MemProtAreaType MemStackArea[2];\n")
gr.printFile("extern MemProtAreaType MemProtArea_SysTask_core0[2];")
gr.printFile("extern MemProtAreaType MemProtArea_SysTask_core1[2];\n")

if task_core0 != []:
    for task in task_core0:
        gr.printFile("extern MemProtAreaType MemProtArea_{}[2];".format(task))

if isr2_core0 != []:
    for isr2 in isr2_core0:
        gr.printFile("extern MemProtAreaType MemProtArea_{}[2];".format(isr2))

gr.printFile("")

if task_core1 != []:
    for task in task_core1:
        gr.printFile("extern MemProtAreaType MemProtArea_{}[2];".format(task))

if isr2_core1 != []:
    for isr2 in isr2_core1:
        gr.printFile("extern MemProtAreaType MemProtArea_{}[2];".format(isr2))

gr.printFile("")

if apps != []:
    for app in apps:
        gr.printFile("extern MemProtAreaType MemProtArea_{}[2];".format(app))

gr.printFile("")
if peripheralAreas != []:
    for peri in peripheralAreas:
        periID = config.getValue("/AUTOSAR/"+ peri ,"OsPeripheralAreaId")
        gr.printFile("#define PERI_{}_ID {}".format(peri, periID))

gr.printFile("#define OsPeriAreaID_INVALID {}".format(len(peripheralAreas)))
gr.printFile("#define OsPeriAreaID_COUNT {}".format(len(peripheralAreas)))


gr.printFile("")
gr.printFile("extern OsPeriAreaInfoType OsPeriAreaInfoArr[OsPeriAreaID_COUNT];\n")
gr.printFile("#pragma section\n")
gr.printFile("#endif\n")


