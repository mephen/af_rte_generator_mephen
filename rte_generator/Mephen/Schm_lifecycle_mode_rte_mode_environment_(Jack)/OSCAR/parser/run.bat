@echo off

rem 生成代码和配置文件。(不要跑 arxml_to_oil！因為 arxml 有缺漏所以跳過 parse arxml 的步驟，直接用 output.oil 覆蓋 osekout.oil 後執行)
rem python -m gen.arxml_to_oil
python -m gen.hook
python -m gen.app_file
python -m gen.MilkshopAUTOSAR_mtpj
python -m gen.boot_asm
python -m gen.main
python -m gen.main_pe2
python -m gen.inc.alarm_Cfg_h
python -m gen.inc.app_Cfg_h
python -m gen.inc.counter_Cfg_h
python -m gen.inc.event_Cfg_h
python -m gen.inc.ioc_h
python -m gen.inc.isr_Cfg_h
python -m gen.inc.memprot_Cfg_h
python -m gen.inc.os_Cfg_h
python -m gen.inc.resource_Cfg_h
python -m gen.inc.scheduletable_Cfg_h
python -m gen.inc.softwaretimer_h
python -m gen.inc.spinlock_Cfg_h
python -m gen.inc.task_Cfg_h
python -m gen.inc.timingprot_h
python -m gen.inc.trustedFunc_Cfg_h
python -m gen.src.alarm_Cfg_c
python -m gen.src.app_Cfg_c
python -m gen.src.counter_Cfg_c
python -m gen.src.event_Cfg_c
python -m gen.src.ioc_c
python -m gen.src.isr_Cfg_c
python -m gen.src.memprot_Cfg_c
python -m gen.src.os_Cfg_c
python -m gen.src.resource_Cfg_c
python -m gen.src.scheduletable_Cfg_c
python -m gen.src.softwaretimer_c
python -m gen.src.spinlock_Cfg_c
python -m gen.src.task_Cfg_c
python -m gen.src.timingprot_c
python -m gen.src.trustedFunc_Cfg_c
python -m gen.inc.memsection_h
pause