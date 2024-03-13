from generator.config import config
from generator import globals as gr

global config
gr.genfile = open(gr.application_path + "main_pe2.c",'w')

gr.printFile("#include \"iodefine.h\"")
gr.printFile("#include \"board.h\"")
gr.printFile("#include \"os.h\"")
gr.printFile("#include \"os_Cfg.h\"")
gr.printFile("#include \"task_Cfg.h\"")
gr.printFile("#include \"event_Cfg.h\"")
gr.printFile("#include \"alarm_Cfg.h\"")
gr.printFile("#include \"application_Cfg.h\"")
gr.printFile("#include \"event.h\"")
gr.printFile("#include \"task.h\"")
gr.printFile("#include \"memsection.h\"")
gr.printFile("#include \"memprot_Cfg.h\"\n")

gr.printFile("#include \"string_format_test.h\"")
gr.printFile("#include \"ISRInit.h\"")
gr.printFile("#include \"systemcall.h\"\n")

gr.printFile("#pragma section\n")

gr.printFile("extern int PrintText(char *TextArray);")
gr.printFile("extern int PrintText_R35(char *TextArray);\n")

gr.printFile("void main_pe2(void)")
gr.printFile("{")
gr.printFile("    StartOS(DONOTCARE);")
gr.printFile("    while (1);")
gr.printFile("}")

gr.printFile("/************* USER_SHARED_SEC *****************/")
gr.printFile("#pragma section USER_SHARED_SEC")