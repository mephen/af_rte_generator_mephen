from generator.config import config
from gen.cores import trustedFun_cores
from generator import globals as gr

global config
global trustedFun_cores
gr.genfile = open(gr.inc_path+"trustedFunc_Cfg.h",'w')

trustedFun_core0 = trustedFun_cores['core0']
trustedFun_core1 = trustedFun_cores['core1']

def translate_hex(dnumber):
    num=hex(dnumber)
    num = num.split("x")
    num = "0"+ "x"+ num[-1].zfill(8)
    return num

gr.printFile("#ifndef TRUSTEDFUNC_CFG_H")
gr.printFile("#define TRUSTEDFUNC_CFG_H")

gr.printFile("/* This file content the generated configuration of task */\n")
gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"")
gr.printFile("/*==================[macros]=================================================*/")

gr.printFile("#define TRUSTED_FUNC_COUNT_CORE0 {}".format(len(trustedFun_core0)))
gr.printFile("#define TRUSTED_FUNC_COUNT_CORE1 {}\n".format(len(trustedFun_core1)))

for trustedFunc in trustedFun_core0:
    gr.printFile("#define TF_{}    {}".format(trustedFunc, translate_hex(trustedFun_core0.index(trustedFunc))))
for trustedFunc in trustedFun_core1:
    gr.printFile("#define TF_{}    {}".format(trustedFunc, translate_hex(trustedFun_core1.index(trustedFunc)+pow(16,4))))

gr.printFile("#define INVALID_TF_ID 0X00020000\n")

gr.printFile("/*============================================================================*/")

gr.printFile("extern TrustedFuncPtrType* TF_array[2];")
if trustedFun_core0 != [] and trustedFun_core1 != [] :
    gr.printFile("extern TrustedFuncPtrType TF_array_core0[TRUSTED_FUNC_COUNT_CORE0];")
    gr.printFile("extern TrustedFuncPtrType TF_array_core1[TRUSTED_FUNC_COUNT_CORE1];")
    gr.printFile("extern TrustedFunctionAutosarType TrustedFuncAutosar_core0[TRUSTED_FUNC_COUNT_CORE0];")
    gr.printFile("extern TrustedFunctionAutosarType TrustedFuncAutosar_core1[TRUSTED_FUNC_COUNT_CORE1];")

gr.printFile("/*============================================================================*/")

apps = config.getList("/AUTOSAR","OsApplication") 
for app in apps:
    gr.printFile("/* {} */".format(app))
    TFs = config.getList("/AUTOSAR/" + app, "OsApplicationTrustedFunction")
    for TF in TFs:
        name = config.getValue("/AUTOSAR/" + app + "/" + TF , "OsTrustedFunctionName")
        gr.printFile("extern void TRUSTED_TF_{}( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);".format(name))


gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* TRUSTEDFUNC_CFG_H */")