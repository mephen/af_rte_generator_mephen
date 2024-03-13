from generator.config import config
from gen.cores import isr_cores 
from generator import globals as gr

def translate_hex(dnumber):
    num=hex(dnumber)
    num = num.split("x")
    num = "0"+ "x"+ num[-1].zfill(8)
    return num

global config
global isr_cores
gr.genfile = open(gr.inc_path+"Isr_Cfg.h",'w')

gr.printFile("#ifndef ISR_CFG_H")
gr.printFile("#define ISR_CFG_H")
gr.printFile("#/* This file content the generated configuration of isr */")
gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"iodefine.h\"")
gr.printFile("#/*==================[macros]=================================================*/\n")

#/*==================[external functions declaration]=========================*/

isrs = config.getList("/AUTOSAR","OsIsr")

core0_isr1s = []
core0_isr2s = []
core1_isr1s = []
core1_isr2s = []

for isr in isrs:
    isrcat = config.getValue("/AUTOSAR/" + isr,"OsIsrCategory")
    if(isrcat == "CATEGORY_1"):
        if isr in isr_cores['core0']:
            core0_isr1s.append(isr)
        elif isr in isr_cores['core1']:
            core1_isr1s.append(isr)
    elif (isrcat == "CATEGORY_2"):
        if isr in isr_cores['core0']:
            core0_isr2s.append(isr)
        elif isr in isr_cores['core1']:
            core1_isr2s.append(isr)



gr.printFile("#define ISR1_COUNT_CORE0 {}U".format(len(core0_isr1s)))
gr.printFile("#define ISR2_COUNT_CORE0 {}U".format(len(core0_isr2s)))
gr.printFile("#define ISR_ALL_COUNT_CORE0 {}U\n".format(len(isr_cores['core0'])))

gr.printFile("#define ISR1_COUNT_CORE1 {}U".format(len(core1_isr1s)))
gr.printFile("#define ISR2_COUNT_CORE1 {}U".format(len(core1_isr2s)))
gr.printFile("#define ISR_ALL_COUNT_CORE1 {}U\n".format(len(isr_cores['core1'])))
gr.printFile("#define ISR_ALL_COUNT_ALL_CORE {}U\n".format(len(isrs)))

gr.printFile("/* core0 */")
for isr in core0_isr2s:
    index = core0_isr2s.index(isr)
    gr.printFile("#define {} {}".format(isr, translate_hex(index)))
    
for isr in core0_isr1s:
    index = core0_isr1s.index(isr)
    index = index + len(core0_isr2s)
    gr.printFile("#define {} {}  //isr1".format(isr, translate_hex(index)))

gr.printFile("/* core1 */")
for isr in core1_isr2s:
    index = core1_isr2s.index(isr)
    index = core1_isr2s.index(isr)+pow(16,4)
    gr.printFile("#define {} {}".format(isr, translate_hex(index)))
    
for isr in core1_isr1s:
    index = core1_isr1s.index(isr)
    index = index + len(core1_isr2s) + pow(16, 4)
    gr.printFile("#define {} {}  //isr1".format(isr, translate_hex(index)))

gr.printFile("#define INVALID_ISR_ID   0X00020000\n")

gr.printFile("extern IsrConstType Isr_const_core0[ISR_ALL_COUNT_CORE0];")
gr.printFile("extern IsrConstType Isr_const_core1[ISR_ALL_COUNT_CORE1];")
gr.printFile("extern IsrConstRefType Isr_const[OsNumberOfCores];\n")

gr.printFile("extern IsrAutosarType IsrAutosar_core0[ISR_ALL_COUNT_CORE0];")
gr.printFile("extern IsrAutosarType IsrAutosar_core1[ISR_ALL_COUNT_CORE1];\n")

gr.printFile("/*==================[external functions declaration]=========================*/")
gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* #ifndef ISR_CFG_H */")
