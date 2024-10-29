from generator.config import config
from gen.cores import app_cores
from generator import globals as gr

global config
global app_cores
gr.genfile = open(gr.inc_path+"resource_Cfg.h",'w')

def translate_hex(dnumber):
    num=hex(dnumber)
    num = num.split("x")
    num = "0"+ "x"+ num[-1].zfill(8)
    return num

resources = config.getList("/AUTOSAR","OsResource")
Total_Number = len(resources) 
change_core = int(Total_Number/2)

core0_resourcescount = 0
core1_resourcescount = 0

core0_internalresourcescount = 0
core1_internalresourcescount = 0



gr.printFile("#ifndef RESOURCE_CFG_H")
gr.printFile("#define RESOURCE_CFG_H")
gr.printFile("/* This file content the generated configuration of resource */")

gr.printFile("/*==================[inclusions]=============================================*/")

gr.printFile("#include \"typedefine.h\"")
gr.printFile("#include \"application_Cfg.h\"")

gr.printFile("/*==================[macros]=================================================*/")

# USE RESOURCE SCHEDULER 
os = config.getValue("/AUTOSAR","OsOS")
schedulerpolicy = config.getValue("/AUTOSAR/" + os,"OsUseResScheduler")
if(schedulerpolicy=="TRUE"):
    gr.printFile ("/* brief Definition of the resource RES_SCHEDULER */")
    gr.printFile("#define RES_SCHEDULER_core0 ((0x00000000))")
    #gr.printFile("#define RES_SCHEDULER_core1 ((0x00010000))")

gr.printFile ("\n")

gr.printFile("#define RES_SCHEDULER ((0x00000000))")
for resource in resources:
    Is_core0 = False
    resourceproperty = config.getValue("/AUTOSAR/" + resource, "OsResourceProperty")
    apps = config.getList("/AUTOSAR/" + resource ,"OsResourceAccessingApplication")
    if app_cores[apps[0]] == 'OS_CORE_ID_0' :
        Is_core0 = True
    if (resourceproperty == ""):
        gr.warning("RESOURCEPROPERTY isn't defined on the configuration, set standard as default")
        gr.printFile ("/* brief Definition of the resource {} */\n".format(resource))
        if Is_core0:
            gr.printFile ("#define " + resource + " ((ResourceType)" + translate_hex(core0_resourcescount) + ")\n")
            core0_resourcescount += 1
        else:
            gr.printFile ("#define " + resource + " ((ResourceType)" + translate_hex(core1_resourcescount+65536) + ")\n")
            core1_resourcescount += 1
        
    elif (resourceproperty == "STANDARD"):
        gr.printFile ("/* brief Definition of the standard resource {} */".format(resource))
        if Is_core0:
            gr.printFile ("#define " + resource + " ((ResourceType)" + translate_hex(core0_resourcescount) + ")\n")
            core0_resourcescount += 1
        else:
            gr.printFile ("#define " + resource + " ((ResourceType)" + translate_hex(core1_resourcescount+65536) + ")\n")
            core1_resourcescount += 1

    elif (resourceproperty == "INTERNAL"):
        gr.printFile ("/* brief Definition of the internal resource {} */".format(resource))
        if Is_core0:
            gr.printFile ("#define " + resource + " ((ResourceType)" + translate_hex(core0_internalresourcescount) + ")\n")
            core0_internalresourcescount += 1
        else:
            gr.printFile ("#define " + resource + " ((ResourceType)" + translate_hex(core1_internalresourcescount+65536) + ")\n")
            core1_internalresourcescount += 1
    else:
        gr.error("RESOURCEPROPERTY set to an invalid value {} ".format(resourceproperty))

apps = config.getList("/AUTOSAR", "OsApplication")
for app in apps:
    if app_cores[app] == 'OS_CORE_ID_0' :
        gr.printFile ("#define resource" + app + " ((ResourceType)" + translate_hex(core0_resourcescount) + ")\n")
        core0_resourcescount += 1
    else:
        gr.printFile ("#define resource" + app + " ((ResourceType)" + translate_hex(core1_resourcescount+65536) + ")\n")
        core1_resourcescount += 1



# Define the resource count 
if(core0_resourcescount > 31 or core1_resourcescount > 31):
    gr.error("more than 31 resources were defined")

else:
    gr.printFile ("/* brief Count of resources */")
    gr.printFile ("/* the count includes RES_SCHEDULER if the oil set it 'true'*/")
    gr.printFile ("#define RESOURCES_COUNT_CORE0 {}".format(core0_resourcescount))
    gr.printFile ("#define RESOURCES_COUNT_CORE1 {}".format(core1_resourcescount))
    gr.printFile ("#define RESOURCES_COUNT {}".format(core0_resourcescount+core1_resourcescount)+"\n")


    gr.printFile ("/* brief Count of internal resources */")
    gr.printFile ("#define INTERNAL_RESOURCES_COUNT_CORE0 {}".format(core0_internalresourcescount))
    gr.printFile ("#define INTERNAL_RESOURCES_COUNT_CORE1 {}".format(core1_internalresourcescount))
    gr.printFile ("#define INTERNAL_RESOURCES_COUNT {}".format(core0_internalresourcescount+core1_internalresourcescount) + "\n\n")

gr.printFile("/*==================[external data declaration]==============================*/")
gr.printFile("/*")
gr.printFile("    Brief Resource Variable on core 0")
gr.printFile("    Contents all variables needed to manage all resources")
gr.printFile("*/")
if(core0_resourcescount>0):
    gr.printFile("extern ResourceVarType ResourceVar_core0[RESOURCES_COUNT_CORE0];")
    gr.printFile("/* brief Resources Priorities */")
    gr.printFile("extern const TaskPriorityType ResourcesPriority_core0[RESOURCES_COUNT_CORE0];\n")
else:
    gr.printFile ("/* There is no defined resource */\n")

gr.printFile("/*")
gr.printFile("    Brief Resource Variable on core 1")
gr.printFile("    Contents all variables needed to manage all resources")
gr.printFile("*/")

if(core1_resourcescount>0):
    gr.printFile("extern ResourceVarType ResourceVar_core1[RESOURCES_COUNT_CORE1];")
    gr.printFile("/* brief Resources Priorities */")
    gr.printFile("extern const TaskPriorityType ResourcesPriority_core1[RESOURCES_COUNT_CORE1];\n")
else:
    gr.printFile ("/* There is no defined resource */\n")

if(core0_internalresourcescount>0):
    gr.printFile ("extern InternalResourceVarType InternalResourceVar_core0[INTERNAL_RESOURCES_COUNT_CORE0];\n")
    gr.printFile ("/* brief Internal Resources Priorities */\n")
    gr.printFile ("extern const TaskPriorityType InternalResourcesPriority_core0[INTERNAL_RESOURCES_COUNT_CORE0];\n")
else:
    gr.printFile ("/* There is no defined internal resource */\n")

if(core1_internalresourcescount>0):
    gr.printFile ("extern InternalResourceVarType InternalResourceVar_core1[INTERNAL_RESOURCES_COUNT_CORE1];\n")
    gr.printFile ("/* brief Internal Resources Priorities */\n")
    gr.printFile ("extern const TaskPriorityType InternalResourcesPriority_core1[INTERNAL_RESOURCES_COUNT_CORE1];\n")
else:
    gr.printFile ("/* There is no defined internal resource */\n")




gr.printFile("/* brief Accessible App of Counter */")
gr.printFile("extern ResourceAutosarType ResourceAutosar_core0[RESOURCES_COUNT_CORE0];")
gr.printFile("extern ResourceAutosarType ResourceAutosar_core1[RESOURCES_COUNT_CORE1];\n")

gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* #ifndef RESOURCE_CFG_H */")




