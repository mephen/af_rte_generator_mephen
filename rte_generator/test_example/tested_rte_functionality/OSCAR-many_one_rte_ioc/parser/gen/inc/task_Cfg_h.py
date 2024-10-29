from generator.config import config 
from generator import globals as gr
from gen.cores import task_cores, isr_cores


global config
global task_cores
global isr_cores
gr.genfile = open(gr.inc_path+"task_Cfg.h",'w')

def translate_hex(dnumber):
    num=hex(dnumber)
    num = num.split("x")
    num = "0"+ "x"+ num[-1].zfill(8)
    return num

apps = config.getList("/AUTOSAR", "OsApplication")
tasks = config.getList("/AUTOSAR", "OsTask")
isrs = config.getList("/AUTOSAR", "OsIsr")
task_core0 = task_cores['core0']
task_core1 = task_cores['core1']
extended_task_core0 = []
extended_task_core1 = []
isr_core0 = isr_cores['core0']
isr_core1 = isr_cores['core1']
isr2_core0 = []
isr2_core1 = []


for task in task_core0:
    if config.getValue("/AUTOSAR/" + task , "OsTaskType") == "EXTENDED":
        extended_task_core0.append(task)
for task in task_core1:    
    if config.getValue("/AUTOSAR/" + task , "OsTaskType") == "EXTENDED":
        extended_task_core1.append(task)

for isr in isr_core0:
    if config.getValue("/AUTOSAR/"+ isr, "OsIsrCategory") == "CATEGORY_2":
        isr2_core0.append(isr)
for isr in isr_core1:
    if config.getValue("/AUTOSAR/"+ isr, "OsIsrCategory") == "CATEGORY_2":
        isr2_core1.append(isr)



gr.printFile("#ifndef TASK_CFG_H")
gr.printFile("#define TASK_CFG_H\n")

gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"")
gr.printFile("#include \"memprot.h\"")
gr.printFile("#include \"resource_Cfg.h\"")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"isr_Cfg.h\"")

gr.printFile("/*==================[macros]=================================================*/\n")
gr.printFile("/* Brief Count of all task(include extended task) */")
gr.printFile("/* The count includes basic/extended tasks and \"1 idle\" task, \"1 sys\" task (no isr2 task)*/")
gr.printFile("#define TASKS_COUNT_CORE0 {}U".format(str(len(task_core0)+2)))
gr.printFile("#define TASKS_COUNT_CORE1 {}U".format(str(len(task_core1)+2)))
gr.printFile("#define TASKS_COUNT {}U".format(str(len(task_core0)+len(task_core1)+4)))


gr.printFile("/* Brief Count of extended task */")
gr.printFile("#define EXTENDED_TASKS_COUNT_CORE0 {}U".format(len(extended_task_core0)))
gr.printFile("#define EXTENDED_TASKS_COUNT_CORE1 {}U".format(len(extended_task_core1)))
gr.printFile("#define EXTENDED_TASKS_COUNT {}U".format(str(len(extended_task_core0)+len(extended_task_core1))))


gr.printFile("/* Brief Count of ISR2 task */")
gr.printFile("#define ISR2_TASKS_COUNT_CORE0 {}U".format(len(isr2_core0)))
gr.printFile("#define ISR2_TASKS_COUNT_CORE1 {}U".format(len(isr2_core1)))
gr.printFile("#define ISR2_TASKS_COUNT {}U".format(str(len(isr2_core0)+len(isr2_core1))))

total_task_core0 = len(task_core0) + len(isr2_core0) + 2
total_task_core1 = len(task_core1) + len(isr2_core1) + 2
total_task = total_task_core0 + total_task_core1
gr.printFile("/* Brief Count of task object*/")
gr.printFile("/* Idle task, sys task, basic task, extended task, ISR2 task have task object*/")
gr.printFile("#define TASK_OBJECTS_COUNT_CORE0 {}U".format((total_task_core0)))
gr.printFile("#define TASK_OBJECTS_COUNT_CORE1 {}U".format((total_task_core1)))
gr.printFile("#define TASK_OBJECTS_COUNT {}U".format(total_task))

if task_core0 != []:
    gr.printFile("/* core0 */")
    gr.printFile("#define IdleTask_core0  0x00000000")
    count = 1
    for task in task_core0:
        gr.printFile("#define {}             {}".format(task, translate_hex(count)))
        count += 1
    for i in isr2_core0:
        count += 1
    gr.printFile("#define SysTask_core0   {}\n".format(translate_hex(count)))

if task_core1 != []:
    gr.printFile("/* core1 */")
    gr.printFile("#define IdleTask_core1  0x00010000")
    count = pow(16,4)+1
    for task in task_core1:
        gr.printFile("#define {}             {}".format(task, translate_hex(count)))
        count += 1
    for i in isr2_core1:
        count += 1
    gr.printFile("#define SysTask_core1   {}\n".format(translate_hex(count)))

gr.printFile("#define INVALID_TASK_ID 0X00020010\n")

gr.printFile("#define StackTaskIdleTask_core0_SIZE 512")
gr.printFile("#define StackTaskSysTask_core0_SIZE 512")
for task in task_core0:
    stack = config.getValue("/AUTOSAR/" + task, "OsTaskStackSize")
    if stack == False:
        gr.printFile ("#define StackTask{}_SIZE 512".format(task))
    else:
        gr.printFile ("#define StackTask{}_SIZE {}".format(task, stack))

for isr in isr_core0:
    if config.getValue("/AUTOSAR/" + isr, "OsIsrCategory") == "CATEGORY_2":
        stack = config.getValue("/AUTOSAR/" + isr, "OsIsrStackSize")
        if stack == False:
            gr.printFile ("#define StackIsr2Task{}_SIZE 512".format(isr))
        else:
            gr.printFile ("#define StackIsr2Task{}_SIZE {}".format(isr, stack))
gr.printFile("\n")


gr.printFile("#define StackTaskIdleTask_core1_SIZE 512")
gr.printFile("#define StackTaskSysTask_core1_SIZE 512")
for task in task_core1:
    stack = config.getValue("/AUTOSAR/" + task, "OsTaskStackSize")
    if stack == False:
        gr.printFile ("#define StackTask{}_SIZE 512".format(task))
    else:
        gr.printFile ("#define StackTask{}_SIZE {}".format(task, stack))

for isr in isr_core1:
    if config.getValue("/AUTOSAR/" + isr, "OsIsrCategory") == "CATEGORY_2":
        stack = config.getValue("/AUTOSAR/" + isr, "OsIsrStackSize")
        if stack == False:
            gr.printFile ("#define StackIsr2Task{}_SIZE 512".format(isr))
        else:
            gr.printFile ("#define StackIsr2Task{}_SIZE {}".format(isr, stack))
gr.printFile("\n")


gr.printFile("#define task_static_prio_idle_core0 0")
task_priority_core0 = {}
for task in task_core0:
    task_priority_core0[task] = int(config.getValue("/AUTOSAR/" + task, "OsTaskPriority"))
    #task_priority.sort()
#sorted(task_priority_core0.items(), key=lambda x:x[1])

count = 1
rank=sorted(task_priority_core0.items(), key =lambda x : x[1])
for i in range(len(rank)):
    if rank[i][1] >= count:
        task_priority_core0[rank[i][0]] = count
        count += 1

for task in task_core0:
    gr.printFile("#define task_static_prio_{} {}".format(task, task_priority_core0[task]))

isr2_priority_core0 = {}
for task in isr2_core0:
    isr2_priority_core0[task] = int(config.getValue("/AUTOSAR/" + task, "OsIsrPriority"))
    #task_priority.sort()
#sorted(isr2_priority_core0.items(), key=lambda x:x[1])

rank = sorted(isr2_priority_core0.items(), key =lambda x : x[1], reverse=True)
#rank = rank.reverse()
for i in range(len(rank)):
    isr2_priority_core0[rank[i][0]] = count
    count += 1

for task in isr2_core0:
    gr.printFile("#define task_static_prio_{} {}".format(task, isr2_priority_core0[task]))

gr.printFile("#define task_static_prio_sys_core0 {}\n".format(count))


gr.printFile("#define task_static_prio_idle_core1 0")
task_priority_core1 = {}
for task in task_core1:
    task_priority_core1[task] = int(config.getValue("/AUTOSAR/" + task, "OsTaskPriority"))
    #task_priority.sort()

count = 1
rank=sorted(task_priority_core1.items(), key =lambda x : x[1])
for i in range(len(rank)):
    if rank[i][1] >= count:
        task_priority_core1[rank[i][0]] = count
        count += 1
for task in task_core1:
    gr.printFile("#define task_static_prio_{} {}".format(task, task_priority_core1[task]))

isr2_priority_core1 = {}
for task in isr2_core1:
    isr2_priority_core1[task] = int(config.getValue("/AUTOSAR/" + task, "OsIsrPriority"))

rank = sorted(isr2_priority_core1.items(), key =lambda x : x[1], reverse=True)
for i in range(len(rank)):
    isr2_priority_core1[rank[i][0]] = count
    count += 1

for task in isr2_core1:
    gr.printFile("#define task_static_prio_{} {}".format(task, isr2_priority_core1[task]))

gr.printFile("#define task_static_prio_sys_core1 {}".format(count))

gr.printFile("/* Brief NON_PREEMPTIVE macro definition */")
gr.printFile("#define NON_PREEMPTIVE OSEK_DISABLE")


gr.printFile("/* Brief Count of priority */")
gr.printFile("#define NORMAL_TASK_PRIO_COUNT_CORE0 {}  ".format(max(task_priority_core0.values())+1))
gr.printFile("#define NORMAL_TASK_PRIO_COUNT_CORE1 {}  ".format(max(task_priority_core1.values())+1))
if isr2_priority_core0 != {}:
    gr.printFile("#define ISR2_TASK_PRIO_COUNT_CORE0 {}  ".format(max(isr2_priority_core0.values())-max(task_priority_core0.values())))
    gr.printFile("#define ISR2_TASK_PRIO_COUNT_CORE1 {}  ".format(max(isr2_priority_core1.values())-max(task_priority_core1.values())))
else:
    gr.printFile("#define ISR2_TASK_PRIO_COUNT_CORE0 0  ")
    gr.printFile("#define ISR2_TASK_PRIO_COUNT_CORE1 0  ")

gr.printFile("/* Brief Count of all priority numbers, including idle and systask, so will \"+1\" */")   
gr.printFile("#define READYLISTS_COUNT_CORE0 (NORMAL_TASK_PRIO_COUNT_CORE0 + ISR2_TASK_PRIO_COUNT_CORE0 +1)")
gr.printFile("#define READYLISTS_COUNT_CORE1 (NORMAL_TASK_PRIO_COUNT_CORE1 + ISR2_TASK_PRIO_COUNT_CORE1 +1)")


gr.printFile("/* brief TASK_AUTOSTART_COUNT define */ //how many mode")
appmodes = config.getList("/AUTOSAR", "OsAppMode")


for appmode in appmodes:
    count = 0
    for task in tasks:
        task_appmode = config.getValue("/AUTOSAR/" + task, "OsTaskAutostart")
        if task_appmode != False:
            names = config.getList("/AUTOSAR/" + task + "/" + task_appmode, "OsTaskAppModeRef")
            if appmode in names:
                count += 1
    gr.printFile("#define TASK_AUTOSTART_{}_COUNT {}".format(appmode, count))


gr.printFile("/*==================[external data declaration]==============================*/")
gr.printFile("extern const TaskConstType TaskConst_core0[TASK_OBJECTS_COUNT_CORE0];")
gr.printFile("extern const TaskConstType TaskConst_core1[TASK_OBJECTS_COUNT_CORE1];\n")

gr.printFile("extern TaskVarType TaskVar_core0[TASK_OBJECTS_COUNT_CORE0];")
gr.printFile("extern TaskVarType TaskVar_core1[TASK_OBJECTS_COUNT_CORE1];\n")

gr.printFile("/* Brief Accessible App of Task */")
gr.printFile("extern TaskAutosarType TaskAutosar_core0[TASK_OBJECTS_COUNT_CORE0];")
gr.printFile("extern TaskAutosarType TaskAutosar_core1[TASK_OBJECTS_COUNT_CORE1];\n")

gr.printFile("extern uint8 ApplicationMode;\n")

gr.printFile("/* Brief AutoStart Array */")

gr.printFile("extern const AutoStartType AutoStart[{}];\n".format(len(appmodes)))

gr.printFile("/* Brief Ready List */")
gr.printFile("extern TaskVarType *ReadyList_core0[READYLISTS_COUNT_CORE0];")
gr.printFile("extern TaskVarType *ReadyList_core1[READYLISTS_COUNT_CORE1];\n")

gr.printFile("/* Brief Ready List Tail */")
gr.printFile("/* In order to prevent linear search in AddReady */")
gr.printFile("extern TaskVarType *ReadyListTail_core0[READYLISTS_COUNT_CORE0];")
gr.printFile("extern TaskVarType *ReadyListTail_core1[READYLISTS_COUNT_CORE1];\n")
gr.printFile("extern TaskType SysTaskID[OsNumberOfCores];\n")

gr.printFile("/*==================[external functions declaration]=========================*/")
gr.printFile("/* Brief Task Declaration of Task IdleTask */")
gr.printFile("TASK(IdleTask);")
gr.printFile("TASK(SysTask);")
gr.printFile("TASK(SysTask_core0);")
gr.printFile("TASK(SysTask_core1);")


for task in task_core0:
    gr.printFile("/* Brief Task Declaration of Task {} */".format(task))
    gr.printFile("TASK({});".format(task))
for isr in isr_core0:
    gr.printFile("/* Brief ISR Declaration of ISR {} */".format(isr))
    gr.printFile("ISR({});".format(isr))
gr.printFile("\n")

for task in task_core1:
    gr.printFile("/* Brief Task Declaration of Task {} */".format(task))
    gr.printFile("TASK({});".format(task))
for isr in isr_core1:
    gr.printFile("/* Brief ISR Declaration of ISR {} */".format(isr))
    gr.printFile("ISR({});".format(isr))
gr.printFile("\n")

gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* #ifndef TASK_CFG_H */")
