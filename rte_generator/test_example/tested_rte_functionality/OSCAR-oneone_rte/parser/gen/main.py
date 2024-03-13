from generator.config import config
from generator import globals as gr

global config
gr.genfile = open(gr.application_path + "main.c",'w')

gr.printFile("#include \"iodefine.h\"")
gr.printFile("#include \"board.h\"")
gr.printFile("#include \"os.h\"")
gr.printFile("#include \"timer.h\"")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("#include \"event_Cfg.h\"")
gr.printFile("#include \"alarm_Cfg.h\"")
gr.printFile("#include \"application_Cfg.h\"")
gr.printFile("#include \"counter.h\"")
gr.printFile("#include \"alarm.h\"")
gr.printFile("#include \"task.h\"")
gr.printFile("#include \"isr2.h\"")
gr.printFile("#include \"event.h\"")
gr.printFile("#include \"memsection.h\"")
gr.printFile("#include \"memprot_Cfg.h\"")
gr.printFile("#include \"string_format_test.h\"")
gr.printFile("#include \"systemcall.h\"")
gr.printFile("#include \"application.h\"")
gr.printFile("#include \"ISRInit.h\"")
gr.printFile("#include \"isr_Cfg.h\"")
gr.printFile("#include \"spinlock.h\"")
gr.printFile("#include \"resource.h\"")
gr.printFile("#include \"memsection.h\"\n")


gr.printFile("#pragma section\n")

gr.printFile("void main_pe1(void)")
gr.printFile("{")
gr.printFile("    StatusType result = E_OK;")
gr.printFile("    StartCore(OS_CORE_ID_1, &result);")
gr.printFile("    StartOS(AppMode1);")
gr.printFile("    while (1);")
gr.printFile("}")