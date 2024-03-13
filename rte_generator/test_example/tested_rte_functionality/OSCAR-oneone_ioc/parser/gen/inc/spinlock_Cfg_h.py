from generator.config import config 
from generator import globals as gr
#import generator.generators as gr

global config
gr.genfile = open(gr.inc_path+"spinlock_Cfg.h",'w')

successor_dict = {}
spinlock_list = []

gr.printFile("#ifndef SPINLOCK_CFG_H")
gr.printFile("#define SPINLOCK_CFG_H")
gr.printFile("/* This file content the generated configuration of task */")
gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"")
gr.printFile("/*==================[macros]=================================================*/")

spinlocks = config.getList("/AUTOSAR","OsSpinlock")
gr.printFile("#define SPINLOCKS_COUNT {}".format(len(spinlocks)))

for spinlock in spinlocks:
    successor = config.getValue("/AUTOSAR/" + spinlock, "OsSpinlockSuccessor")
    successor_dict[spinlock] = successor
    if successor == False:
        spinlock_list.append(spinlock)

new_successor_dict = {v: k for k, v in successor_dict.items()}

for i in range(len(spinlocks)-1):
    spinlock = new_successor_dict[spinlock_list[i]]
    spinlock_list.append(spinlock)

spinlock_list.reverse()

spinlock_count = 0
for spinlock in spinlock_list:
    gr.printFile("#define {} {}".format(spinlock, spinlock_count))
    spinlock_count += 1
gr.printFile("#define INVALID_SPINLOCK {}".format(spinlock_count))

gr.printFile("/*==================[external data declaration]=========================*/")
if spinlock_count > 0:
    gr.printFile("extern LockType SpinLockList[SPINLOCKS_COUNT];\n")
    gr.printFile("extern SpinlockConstType SpinlockConst[SPINLOCKS_COUNT];\n")
    gr.printFile("extern SpinlockVarType SpinlockVar[SPINLOCKS_COUNT];\n")

gr.printFile("/*==================[external functions declaration]=========================*/")

gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* #ifndef SPINLOCK_CFG_H */")