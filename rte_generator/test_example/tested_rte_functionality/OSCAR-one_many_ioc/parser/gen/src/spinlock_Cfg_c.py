from generator.config import config 
from generator import globals as gr
from gen.cores import task_cores, isr_cores

global config
gr.genfile = open(gr.src_path+"spinlock_Cfg.c",'w')

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"spinlock_Cfg.h\"")
gr.printFile("#include \"application_Cfg.h\"")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"task_Cfg.h\"\n")

gr.printFile("/*==================[macros and definitions]=================================*/\n")
gr.printFile("/*==================[internal data declaration]==============================*/\n")
gr.printFile("/*==================[internal functions declaration]=========================*/\n")
gr.printFile("/*==================[internal data definition]===============================*/\n")
gr.printFile("/*==================[external data definition]===============================*/\n")

gr.printFile("#pragma section\n")
gr.printFile("LockType SpinLockList[SPINLOCKS_COUNT];\n")
gr.printFile("SpinlockConstType SpinlockConst[SPINLOCKS_COUNT] = {")

successor_dict = {}
spinlock_list = []

spinlocks = config.getList("/AUTOSAR","OsSpinlock")
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

for spinlock in spinlock_list:
    gr.printFile("    /* {} */".format(spinlock))
    gr.printFile("    {")
    gr.printFile("        {}, /* spinlock id*/".format(spinlock))
    application = config.getList("/AUTOSAR/" + spinlock, "OsSpinlockAccessingApplication")
    if application != []:
        gr.printFileSpace("        0 ")
        for app in application:
            if app == application[-1] :
                gr.printFileSpace("| (1 << {}), ".format(app),) 
            else:
                gr.printFileSpace("| (1 << {}) ".format(app)) 
        gr.printFile("/* application mask */")
    
    method = config.getValue("/AUTOSAR/" + spinlock, "OsSpinlockLockMethod")
    if method == "LOCK_NOTHING":
        gr.printFile("        0 /* LOCK_NOTHING */")
        
    elif method == "LOCK_ALL_INTERRUPTS":
        gr.printFile("        1 /* LOCK_ALL_INTERRUPTS */")
    
    elif method == "LOCK_CAT2_INTERRUPTS":
        gr.printFile("        2 /* LOCK_CAT2_INTERRUPTS */")
    
    elif method == "LOCK_WITH_RES_SCHEDULER":
        gr.printFile("        3 /* LOCK_WITH_RES_SCHEDULER */")
    
    gr.printFile ("    },")
gr.printFile("};")

gr.printFile("SpinlockVarType SpinlockVar[SPINLOCKS_COUNT] = {")
for spinlock in spinlock_list:
    gr.printFile("    /* {} */".format(spinlock))
    gr.printFile("    {")
    gr.printFile("        {")
    gr.printFile("            OBJECT_INVALID,")
    gr.printFile("            0,")
    gr.printFile("        },")
    gr.printFile("        OS_CORE_ID_INVALID,")
    gr.printFile("        INVALID_TASK_ID")
    gr.printFile("    },")
gr.printFile("};")

gr.printFile("#pragma section")

gr.printFile("/*==================[internal functions definition]==========================*/\n")

gr.printFile("/*==================[external functions definition]==========================*/\n")

gr.printFile("/*==================[end of file]============================================*/\n")


    

    


