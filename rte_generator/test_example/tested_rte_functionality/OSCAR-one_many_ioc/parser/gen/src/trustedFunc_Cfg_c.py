from generator.config import config
from gen.cores import trustedFun_cores
from generator import globals as gr
from gen.cores import app_cores, app_core0, app_core1

global config
global trustedFun_cores
global app_cores, app_core0, app_core1
gr.genfile = open(gr.src_path+"trustedFunc_Cfg.c",'w')

trustedFun_core0 = trustedFun_cores['core0']
trustedFun_core1 = trustedFun_cores['core1']

gr.printFile("/* This file content the generated configuration of trustedFunction */\n")
gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"")
gr.printFile("#include \"application_Cfg.h\"")
gr.printFile("#include \"trustedFunc_Cfg.h\"")
gr.printFile("#include \"resource_Cfg.h\"\n")

gr.printFile("#pragma section\n")

gr.printFile("TrustedFuncPtrType* TF_array[2] = {")
gr.printFile("    TF_array_core0,")
gr.printFile("    TF_array_core1,")
gr.printFile("};\n")


if trustedFun_core0 != [] and trustedFun_core1 != [] :


    gr.printFile("TrustedFuncPtrType TF_array_core0[TRUSTED_FUNC_COUNT_CORE0] = {")
    for trustedFun in trustedFun_core0:
        gr.printFile("    TRUSTED_TF_{},".format(trustedFun))
    gr.printFile("};")

    gr.printFile("TrustedFuncPtrType TF_array_core1[TRUSTED_FUNC_COUNT_CORE1] = {")
    for trustedFun in trustedFun_core1:
        gr.printFile("    TRUSTED_TF_{},".format(trustedFun))
    gr.printFile("};")

    gr.printFile("TrustedFunctionAutosarType TrustedFuncAutosar_core0[TRUSTED_FUNC_COUNT_CORE0] = {")

    apps = config.getList("/AUTOSAR", "OsApplication")
    for trustedFun in trustedFun_core0:
        gr.printFile("    /* TRUSTED_TF_{} */".format(trustedFun))
        gr.printFile("    {")
        for app in apps:
            TFs = config.getList("/AUTOSAR/" + app, "OsApplicationTrustedFunction")
            for TF in TFs:
                if config.getValue("/AUTOSAR/" + app + "/" + TF , "OsTrustedFunctionName") == trustedFun:
                    gr.printFile("        {},".format(app))
                    TF_apps = app_core0
                    if TF_apps != []:
                        gr.printFileSpace("        0 ")
                        for app in TF_apps:
                            if app == TF_apps[-1]:
                                gr.printFile("| (1 << {}), ".format(app))
                            else:
                                gr.printFileSpace("| (1 << {}) ".format(app))
                    else:
                        gr.printFile("        0")
        gr.printFile("    },")
    gr.printFile("};")  


    gr.printFile("TrustedFunctionAutosarType TrustedFuncAutosar_core1[TRUSTED_FUNC_COUNT_CORE1] = {")
    for trustedFun in trustedFun_core1:
        gr.printFile("    /* TRUSTED_TF_{} */".format(trustedFun))
        gr.printFile("    {")
        for app in apps:
            TFs = config.getList("/AUTOSAR/" + app, "OsApplicationTrustedFunction")
            for TF in TFs:
                if config.getValue("/AUTOSAR/" + app + "/" + TF , "OsTrustedFunctionName") == trustedFun:
                    gr.printFile("        {},".format(app))
                    TF_apps = app_core1
                    if TF_apps != []:
                        gr.printFileSpace("        0 ")
                        for app in TF_apps:
                            if app == TF_apps[-1]:
                                gr.printFile("| (1 << {}), ".format(app))
                            else:
                                gr.printFileSpace("| (1 << {}) ".format(app))
                    else:
                        gr.printFile("        0")
        gr.printFile("    },")
    gr.printFile("};")  

gr.printFile("#pragma section")

