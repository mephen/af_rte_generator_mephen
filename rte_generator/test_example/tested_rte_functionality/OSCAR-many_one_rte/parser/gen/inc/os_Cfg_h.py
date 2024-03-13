from generator.config import config 
from generator import globals as gr
#import generator.generators as gr

global config
gr.genfile = open(gr.inc_path+"os_Cfg.h",'w')

gr.printFile("#ifndef OS_CFG_H")
gr.printFile("#define OS_CFG_H")
gr.printFile("/* This file content the generated configuration of os */")
gr.printFile("/*==================[inclusions]=============================================*/")
gr.printFile("#include \"typedefine.h\"\n")
gr.printFile("#define MAX_TF_NESTED_CALL 10")
gr.printFile("/*==================[macros]=================================================*/")
gr.printFile("/* Brief ERROR_CHECKING_STANDARD */")
gr.printFile("#define ERROR_CHECKING_STANDARD   1")
gr.printFile("/* Brief ERROR_CHECKING_EXTENDED */")
gr.printFile("#define ERROR_CHECKING_EXTENDED   2")



os = config.getValue("/AUTOSAR","OsOS")
if os == False:
    gr.error ("More than one OS defined in the configuration")      
    exit()      #return

#/* ERROR CHECKING TYPE */
attribute = config.getValue("/AUTOSAR/" + os,"OsStatus")
gr.printFile ("/* Brief Error Checking Type */")
if ( attribute == "EXTENDED" ):
    gr.printFile ("#define ERROR_CHECKING_TYPE ERROR_CHECKING_EXTENDED")
elif ( attribute == "STANDARD" ):
    gr.printFile ("#define ERROR_CHECKING_TYPE ERROR_CHECKING_STANDARD")
else:
    gr.error ("Wrong OS Status configuration")
    exit()     #return

oshook = config.getValue("/AUTOSAR/" + os ,"OsHooks")
#/* PRETASKHOOK */
pretaskhook=config.getValue("/AUTOSAR/" + os + "/" + oshook ,"OsPreTaskHook")
gr.printFile ("/* Brief pre task hook enable-disable macro */")
if(pretaskhook == False):
    gr.warning("PRETASKHOOK isn't defined on the configuration, set disable as default")
    gr.printFile ("#define HOOK_ENABLE_PRETASKHOOK DISABLE")

elif(pretaskhook == "TRUE"):
    gr.printFile ("#define HOOK_ENABLE_PRETASKHOOK ENABLE")

elif(pretaskhook == "FALSE"):
    gr.printFile ("#define HOOK_ENABLE_PRETASKHOOK DISABLE")
else:
    gr.error("PRETASKHOOK set to an invalid value {}".format(pretaskhook))

#/* POSTTAKHOOK */
posttaskhook = config.getValue("/AUTOSAR/" + os + "/" + oshook ,"OsPostTaskHook")
gr.printFile ("/* Brief post task hook enable-disable macro */")
if(posttaskhook == False):
    gr.warning("POSTTASKHOOK isn't defined on the configuration, set disable as default")
    gr.printFile ("#define HOOK_ENABLE_POSTTASKHOOK DISABLE")
elif(posttaskhook == "TRUE"):
    gr.printFile ("#define HOOK_ENABLE_POSTTASKHOOK ENABLE")
elif(posttaskhook == "FALSE"):
    gr.printFile ("#define HOOK_ENABLE_POSTTASKHOOK DISABLE")
else:
    gr.error("POSTTASKHOOK set to an invalid value {}".format(posttaskhook))


#/* ERRORHOOK */
errorhook = config.getValue("/AUTOSAR/" + os + "/" + oshook ,"OsErrorHook")
gr.printFile ("/* Brief error hook enable-disable macro */")
if(errorhook == False):
    gr.warning("ERRORHOOK configuration not found in oil configuration, set disable as default")
    gr.printFile ("#define HOOK_ENABLE_ERRORHOOK DISABLE")

elif(errorhook == "TRUE"):
    gr.printFile ("#define HOOK_ENABLE_ERRORHOOK ENABLE")

elif(errorhook == "FALSE"):
    gr.printFile ("#define HOOK_ENABLE_ERRORHOOK DISABLE")

else:
    gr.error("ERRORHOOK set to an invalid value {}".format(errorhook))


#/* STARTUPHOOK */
startuphook=config.getValue("/AUTOSAR/" + os + "/" + oshook ,"OsStartupHook")
gr.printFile ("/* Brief startup hook enable-disable macro */")
if(startuphook == False):
    gr.warning("STARTUPHOO configuration not found in oil configuration, set disable as default")
    gr.printFile ("#define HOOK_ENABLE_STARTUPHOOK DISABLE")

elif(startuphook == "TRUE"):
    gr.printFile ("#define HOOK_ENABLE_STARTUPHOOK ENABLE")

elif(startuphook == "FALSE"):
    gr.printFile ("#define HOOK_ENABLE_STARTUPHOOK DISABLE")

else:
    gr.error("STARTUPHOOK set to an invalid value {}".format(startuphook))
    

#/* SHUTDOWNHOOK */
shutdownhook=config.getValue("/AUTOSAR/" + os + "/" + oshook ,"OsShutdownHook")
gr.printFile ("/* Brief shutdown hook enable-disable macro */")
if(shutdownhook == False):
    gr.warning("SHUTDOWNHOOK configuration not found in oil configuration, set disable as default")
    gr.printFile ("#define HOOK_ENABLE_SHUTDOWNHOOK DISABLE")

elif(shutdownhook == "TRUE"):
    gr.printFile ("#define HOOK_ENABLE_SHUTDOWNHOOK ENABLE")

elif(shutdownhook == "FALSE"):
    gr.printFile ("#define HOOK_ENABLE_SHUTDOWNHOOK DISABLE")

else:
    gr.error("SHUTDOWNHOOK set to an invalid value {}".format(shutdownhook))
    gr.printFile ("SHUTDOWNHOOK set to an invalid value {}".format(shutdownhook))


#/* PROTECTIONHOOK */
protectionhook=config.getValue("/AUTOSAR/" + os + "/" + oshook ,"OsProtectionHook")
gr.printFile ("/* Brief protection hook enable-disable macro */")
if(protectionhook == False):
    gr.warning("PROTECTIONHOOK configuration not found in oil configuration, set disable as default")
    gr.printFile ("#define HOOK_ENABLE_PROTECTIONHOOK DISABLE\n")

elif(protectionhook == "TRUE"):
    gr.printFile ("#define HOOK_ENABLE_PROTECTIONHOOK ENABLE\n")

elif(protectionhook == "FALSE"):
    gr.printFile ("#define HOOK_ENABLE_PROTECTIONHOOK DISABLE\n")

else:
    gr.error("SHUTDOWNHOOK set to an invalid value {}".format(protectionhook))
    gr.printFile ("SHUTDOWNHOOK set to an invalid value {}".format(protectionhook))


gr.printFile("/* Brief application error hook enable-disable macro */")
gr.printFile("#define HOOK_ENABLE_OSAPP_ERRORHOOK ENABLE")
gr.printFile("/* Brief application startup hook enable-disable macro */")
gr.printFile("#define HOOK_ENABLE_OSAPP_STARTUPHOOK ENABLE")
gr.printFile("/* Brief application shutdown hook enable-disable macro */")
gr.printFile("#define HOOK_ENABLE_OSAPP_SHUTDOWNHOOK ENABLE\n")


#/* USE RESOURCE SCHEDULER */
schedulerpolicy = config.getValue("/AUTOSAR/" + os, "OsUseResScheduler")
gr.printFile ("/* Brief USE_RES_SCHEDULER macro definition */")
if schedulerpolicy == "FALSE":
    gr.printFile ("#define USE_RES_SCHEDULER DISABLE\n")
elif schedulerpolicy == "TRUE":
    gr.printFile ("#define USE_RES_SCHEDULER ENABLE\n")
else:
    gr.warning("USERESSCHEDULER configuration not found in oil configuration, disabling as default")
    gr.printFile ("#define USE_RES_SCHEDULER DISABLE\n")


#/* USE software stack monitoring */
monitor = config.getValue("/AUTOSAR/" + os, "OsStackMonitoring")
gr.printFile ("/* define whether to use software stack monitoring */")
if monitor == "FALSE":
    gr.printFile ("#define ENABLE_SOFTWARE_STACK_MONITOR DISABLE\n")
elif monitor == "TRUE":
    gr.printFile ("#define ENABLE_SOFTWARE_STACK_MONITOR ENABLE\n")
else:
    gr.warning("USERESSCHEDULER configuration not found in oil configuration, disabling as default")
    gr.printFile ("#define ENABLE_SOFTWARE_STACK_MONITOR DISABLE\n")


gr.printFile("/* define whether interrupt source will be auto enabled when AllowAccess() is called */")
gr.printFile("#define ALLOWACCESS_AUTO_ENABLE_ALL_ISR_IN_OSAPP DISABLE")

gr.printFile("/* define whether interrupt source will be auto enabled when AllowAccess() is called */")
gr.printFile("#define ENABLE_SYSTEM_ERROR_HOOK_IN_TIMER_INT DISABLE")


#/* Define the Application Modes */
gr.printFile ("/* Brief Definition of the Application Mode */")
gr.printFile ("#define DONOTCARE 0")
count = 0
for mode in config.getList("/AUTOSAR","OsAppMode"):
    count += 1
    gr.printFile ("#define {} {}".format(mode, count))
gr.printFile ("\n")


gr.printFile("/* Brief Core Definition */")
gr.printFile("/* The core id starts from 0 */")
core_counts = int(config.getValue("/AUTOSAR/" + os,"OsNumberOfCores"))
for core_count in range(core_counts):
    gr.printFile("#define OS_CORE_ID_{}        {}".format(core_count, core_count))

gr.printFile("#define OS_CORE_ID_MASTER   OS_CORE_ID_0\n")
gr.printFile("#define OS_CORE_ID_INVALID  {}\n".format(core_counts))

gr.printFile("/* Define of SysTaskActionQueue length */")
gr.printFile("#define SysTaskActionQueueLength 20")
gr.printFile("#define PSWKERNELMODE 0")
gr.printFile("#define PSWUSERMODE 0x40000000")


gr.printFile("/* Brief ECUC_PARTITION Definition */")
gr.printFile("/* record in ApplicationVarType, Not use in current autosar os 20221007 */")
gr.printFile("#define ECUC_PARTITION_DEFAULT_ID 0")
apps = config.getList("/AUTOSAR" ,"OsApplication")
count = 1
for app in apps:
    partition = config.getValue("/AUTOSAR/" + app , "OsAppEcucPartitionRef")
    gr.printFile("#define ECUC_{}_ID {}".format(partition, count))
    count += 1

gr.printFile("\n")
gr.printFile("/* The maximum number of core */")
gr.printFile("#define TotalNumberOfCores  ((uint16){})".format(core_counts) )
gr.printFile("#define OsNumberOfCores     ((uint16){})".format(core_counts) )
gr.printFile("#define EcucPartitionSettingNum ((uint16)1)")
#gr.printFile("#define EcucPartitionSettingNum ((uint16){})".format(core_counts))

gr.printFile("/*==================[typedef]================================================*/")
gr.printFile("/*==================[external functions declaration]=========================*/")

gr.printFile("extern SimuEcucPartitionSettingType EcucPartitionSettingArr[EcucPartitionSettingNum];\n")

for core_ID in range(int(core_counts)):
    gr.printFile("extern SystemVarType SystemVar_core{};\n".format(core_ID))
    gr.printFile("extern SystemObjectsType SystemObjects_core{};\n".format(core_ID))
    gr.printFile("extern CurrentTaskType CurrentTask_core{};\n".format(core_ID))
    gr.printFile("extern SystemReadyListType SystemReadyList_core{};\n".format(core_ID))


gr.printFile("extern SystemVarRefType SystemVar[OsNumberOfCores];\n")
gr.printFile("extern SystemObjectsRefType SystemObjects[OsNumberOfCores];\n")
gr.printFile("extern SystemObjectAutosarRefType SystemObjectAutosar[OsNumberOfCores];\n")

gr.printFile("extern CurrentTaskRefType CurrentTask[OsNumberOfCores];\n")
gr.printFile("extern ApplicationType ExecutingApp[OsNumberOfCores];\n")
gr.printFile("extern SystemReadyListRefType SystemReadyList[OsNumberOfCores];\n")
gr.printFile("extern CoreIdType CoreIdPhyToLogArray[TotalNumberOfCores];\n")
gr.printFile("extern CoreStatusType CoreStatus[TotalNumberOfCores];\n")

gr.printFile("extern uint16 NumberOfActivatedCore;\n")
gr.printFile("extern uint8 TasksCountArray[OsNumberOfCores];")
gr.printFile("extern uint8 Isr2TaskCountArray[TotalNumberOfCores];")
gr.printFile("extern uint8 TasksObjectCountArray[OsNumberOfCores];")
gr.printFile("extern uint8 IsrCountArray[OsNumberOfCores];\n")

gr.printFile("extern AppModeType AppModeArray[TotalNumberOfCores];\n")

gr.printFile("extern uint8 CoreIntFlag[OsNumberOfCores];")
gr.printFile("extern LockType CoreParaLock[OsNumberOfCores];")
gr.printFile("extern ServiceParaType CrossCoreServicePara[OsNumberOfCores];")

gr.printFile("extern uint8 app_start_up_hook_err_flag[OsNumberOfCores];")
gr.printFile("extern uint8 app_shut_down_hook_err_flag[OsNumberOfCores];")

gr.printFile("extern uint32 CurrentExecServiceID[OsNumberOfCores];              /* used for info in error-hook */")
gr.printFile("extern ServiceParaType DebugServicePara[OsNumberOfCores];         /* used for info in error-hook */")

gr.printFile("#define MAX_STACK_FOR_NESTED_TF_CALL 8")
gr.printFile("extern ApplicationRefType TF_NestedOwnerArray[OsNumberOfCores];")

gr.printFile("extern AppsInCoreType SystemAppsInCore[OsNumberOfCores];\n")

gr.printFile("extern IdleModeType NowIdleMode[OsNumberOfCores];")
gr.printFile("extern IdleModeType NextIdleMode[OsNumberOfCores];")
gr.printFile("extern LockType lockForIdleMode[OsNumberOfCores];")

gr.printFile("/* SysTask */")
gr.printFile("extern TaskType beforeSysTask[OsNumberOfCores];") 
gr.printFile("extern SysTaskInformationType SysTaskAction_core0[SysTaskActionQueueLength];")
gr.printFile("extern SysTaskInformationType SysTaskAction_core1[SysTaskActionQueueLength];")
gr.printFile("extern SysTaskActionQueueType *SysTaskActionQueue[OsNumberOfCores];\n")

gr.printFile("extern SysTaskInformationType* const CurrentAction[OsNumberOfCores];")
gr.printFile("extern SysTaskInformationType CurrentAction_core0;")
gr.printFile("extern SysTaskInformationType CurrentAction_core1;\n")






gr.printFile("/*==================[external functions declaration]=========================*/")
#errorhook=config.getValue("/AUTOSAR/" + os,"ERRORHOOK")
if (errorhook == "TRUE"):
    gr.printFile ("/* Brief ErrorHook */")
    gr.printFile ("extern void ErrorHook(StatusType Error);")



gr.printFile("/*==================[end of file]============================================*/")
gr.printFile("#endif /* #ifndef OS_CFG_H */")

