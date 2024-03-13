from generator.config import config
from gen.cores import app_cores
from generator import globals as gr

global config
global app_cores
gr.genfile = open(gr.inc_path+"application_Cfg.h",'w')


core0_App_Count = 0
core1_App_Count = 0
Trusted_App_Count = 0
Trusted_Function_Count = 0

gr.printFile("#ifndef APPLICATION_CFG_H")
gr.printFile("#define APPLICATION_CFG_H")

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"\n")

gr.printFile("/*==================[macros]=================================================*/")

apps = config.getList("/AUTOSAR","OsApplication")

for app in apps:
    if app_cores[app] == "OS_CORE_ID_0":
        core0_App_Count += 1
    elif app_cores[app] == "OS_CORE_ID_1":
        core1_App_Count += 1
    else:
        gr.error("Which core does the app belong to?")
    
    isTrusted_App = config.getValue("/AUTOSAR/" + app,"OsTrusted")
    if isTrusted_App == "TRUE":
        Trusted_App_Count += 1

    isTrusted_Function = config.getValue("/AUTOSAR/" + app,"OsApplicationTrustedFunction")
    if isTrusted_Function == "TRUE":
        Trusted_Function_Count += 1

gr.printFile ( "#define APPLICATIONS_COUNT_CORE0 {}".format(core0_App_Count) )
gr.printFile ( "#define APPLICATIONS_COUNT_CORE1 {}".format(core1_App_Count) )
gr.printFile ( "#define APPLICATIONS_COUNT {}".format(len(apps)) )
gr.printFile ( "#define TRUSTED_APPLICATIONS_COUNT {}".format(Trusted_App_Count) )
gr.printFile ( "#define TRUSTED_FUNCTIONS_COUNT {}".format(Trusted_Function_Count))

number = 0
for app in apps:
    gr.printFile("#define {} {}".format(app, number))
    number += 1

gr.printFile("#define INVALID_OSAPPLICATION {}".format(number))

gr.printFile("/*==================[external data declaration]=========================*/")
#if(core0_App_Count > 0):
#    gr.printFile("extern ApplicationVarType ApplicationVar_core0[APPLICATIONS_COUNT_CORE0];")
#if(core1_App_Count > 0):
#    gr.printFile("extern ApplicationVarType ApplicationVar_core1[APPLICATIONS_COUNT_CORE1];")
gr.printFile("extern ApplicationVarType ApplicationVar[APPLICATIONS_COUNT];")
gr.printFile("/*the ApplicationObjectsType are currrently used only in application.c*/")
gr.printFile("extern ApplicationObjectsType ApplicationObjects_core0[APPLICATIONS_COUNT_CORE0];")
gr.printFile("extern ApplicationObjectsType ApplicationObjects_core1[APPLICATIONS_COUNT_CORE1];")
gr.printFile("extern LockType lockForApplicationState[APPLICATIONS_COUNT];")

gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* #ifndef APPLICATION_CFG_H */")

