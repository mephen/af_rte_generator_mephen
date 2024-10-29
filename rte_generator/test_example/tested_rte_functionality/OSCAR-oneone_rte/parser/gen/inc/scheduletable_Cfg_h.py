from generator.config import config 
from generator import globals as gr
from gen.cores import ST_cores
#import generator.generators as gr

global config
global ST_cores
gr.genfile = open(gr.inc_path+"scheduletable_Cfg.h",'w')

scheduleTable_core0 = ST_cores['core0']
scheduleTable_core1 = ST_cores['core1']
scheduleTable_autostart_core0 = []
scheduleTable_autostart_core1 = []
expirypoints = {}

def translate_hex(dnumber):
    num=hex(dnumber)
    num = num.split("x")
    num = "0"+ "x"+ num[-1].zfill(8)
    return num

gr.printFile("#ifndef SCHEDULETABLE_CFG_H")
gr.printFile("#define SCHEDULETABLE_CFG_H\n")
gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"")
gr.printFile("#include \"ScheduleTable.h\"")
gr.printFile("/*==================[macros]=================================================*/")
gr.printFile("/* brief Definition of the DeclareAlarmCallback Macro */")
gr.printFile("#define DeclareCallback(name) void MILKSHOP_CALLBACK_ ## name (void)")

scheduletables = config.getList("/AUTOSAR","OsScheduleTable")
apps = config.getList("/AUTOSAR","OsApplication")

gr.printFile("/* brief count of scheduletables */")
gr.printFile("#define SCHEDULETABLE_COUNT_CORE0 {}".format(len(scheduleTable_core0)))
gr.printFile("#define SCHEDULETABLE_COUNT_CORE1 {}".format(len(scheduleTable_core1)))
gr.printFile("#define SCHEDULETABLE_COUNT {}\n".format(len(scheduleTable_core0)+len(scheduleTable_core1)))

for scheduletable in scheduleTable_core0:
    gr.printFile("/* brief Definition of the ScheduleTable {} */".format(scheduletable))
    gr.printFile("#define {} {}".format(scheduletable, translate_hex(scheduleTable_core0.index(scheduletable))))
    if config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableAutostart") != False:
        scheduleTable_autostart_core0.append(scheduletable)
        
    expirypoints[scheduletable] = pointCount = len(config.getList("/AUTOSAR/" + scheduletable, "OsScheduleTableExpiryPoint"))


for scheduletable in scheduleTable_core1:
    gr.printFile("/* brief Definition of the ScheduleTable {} */".format(scheduletable))
    gr.printFile("#define {} {}".format(scheduletable, translate_hex(scheduleTable_core1.index(scheduletable)+pow(16,4))))
    if config.getValue("/AUTOSAR/" + scheduletable, "OsScheduleTableAutostart") != False:
        scheduleTable_autostart_core1.append(scheduletable)

    expirypoints[scheduletable] = pointCount = len(config.getList("/AUTOSAR/" + scheduletable, "OsScheduleTableExpiryPoint"))

gr.printFile("#define INVALID_SCHEDULETABLE_ID 0x00020000\n")

scheduleTable_autostart_core0 = []
scheduleTable_autostart_core1 = []
gr.printFile("/*brief Definition of the AutoStart  ScheduleTable */")
gr.printFile("#define SCHEDULETABLE_AUTOSTART_COUNT_CORE0 {}".format(len(scheduleTable_autostart_core0)))
gr.printFile("#define SCHEDULETABLE_AUTOSTART_COUNT_CORE1 {}".format(len(scheduleTable_autostart_core1)))
gr.printFile("#define SCHEDULETABLE_AUTOSTART_COUNT {}".format(len(scheduleTable_autostart_core0)+len(scheduleTable_autostart_core1)))

gr.printFile("\n")
gr.printFile("/*==================[external data declaration]=========================*/\n")


gr.printFile("/* brief ScheduleTable Variable Structure */")
gr.printFile("extern ScheduleTableVarType ScheduleTableVar_core0[SCHEDULETABLE_COUNT_CORE0];")
gr.printFile("extern ScheduleTableVarType ScheduleTableVar_core1[SCHEDULETABLE_COUNT_CORE1];\n")

gr.printFile("/* brief ScheduleTable Constant Structure */")
gr.printFile("extern const ScheduleTableConstType ScheduleTableConst_core0[SCHEDULETABLE_COUNT_CORE0];")
gr.printFile("extern const ScheduleTableConstType ScheduleTableConst_core1[SCHEDULETABLE_COUNT_CORE1];\n")

gr.printFile("/* brief Accessible App of ScheduleTable */")
gr.printFile("extern ScheduleTableAutosarType ScheduleTableAutosar_core0[SCHEDULETABLE_COUNT_CORE0];")
gr.printFile("extern ScheduleTableAutosarType ScheduleTableAutosar_core1[SCHEDULETABLE_COUNT_CORE1];\n")

for point in expirypoints:
    gr.printFile("/* brief count of expirypoints */")
    gr.printFile("#define EXPIRYPOINT_COUNT_{} {}".format(point, expirypoints[point]))
    gr.printFile("/* brief ExpiryPoints Structure */")
    gr.printFile("extern ExpiryPointType expirypoint_{}[EXPIRYPOINT_COUNT_{}];\n".format(point, point))
"""
for scheduletable in scheduleTable_core0:
    gr.printFile("/* Brief Callback Declaration of Callback ExpiryPointCallbackFunc{} */".format(scheduletable))
    gr.printFile("DeclareCallback(ExpiryPointCallbackFunc{});".format(scheduletable))

for scheduletable in scheduleTable_core1:
    gr.printFile("/* Brief Callback Declaration of Callback ExpiryPointCallbackFunc{} */".format(scheduletable))
    gr.printFile("DeclareCallback(ExpiryPointCallbackFunc{});".format(scheduletable))
"""
gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* #ifndef SCHEDULETABLE_CFG_H */")