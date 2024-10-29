#ifndef OS_H
#define OS_H

/*In AUTOSAR SPEC: AUTOSAR OS always exists in an environment 
  where LOCALMESSAGESONLY is undefined (7.1.2.1 Restrictions on OSEK OS) */
#ifdef LOCALMESSAGESONLY
    #undef LOCALMESSAGESONLY
#endif

/* In AUTOSAR SPEC: In OSEK OS users must declare OS objects with specific macros 
   (e.g. DeclareTask(), ...). An AUTOSAR OS implementation shall not depend on    
   such declarations and shall (for backwards compatibility)                      
   supply macros without functionality */
//TODO

/* return value of OSEK System Services */
#define E_OK ((StatusType)0U)
#define E_OS_ACCESS ((StatusType)1U)
#define E_OS_CALLEVEL ((StatusType)2U)
#define E_OS_ID ((StatusType)3U)
#define E_OS_LIMIT ((StatusType)4U)
#define E_OS_NOFUNC ((StatusType)5U)
#define E_OS_RESOURCE ((StatusType)6U)
#define E_OS_STATE ((StatusType)7U)
#define E_OS_VALUE ((StatusType)8U)
#define E_OS_SYS_OK_MULTIACTIVATATION ((StatusType)9U)
#define E_OS_SYS_NOFUNC ((StatusType)10U)
#define E_OS_SYS_COREID ((StatusType)11U)
#define E_OS_SERVICEID ((StatusType)12U)
#define E_OS_INTERFERENCE_DEADLOCK ((StatusType)13U)
#define E_OS_NESTING_DEADLOCK ((StatusType)14U)
#define E_OS_SYS_OK_CROSSCORE ((StatusType)15U) // CROSSCORE ok and skip same error check
#define E_OS_SPINLOCK ((StatusType)16U)
#define E_OS_ILLEGAL_ADDRESS ((StatusType)17U)
#define E_OS_MISSINGEND ((StatusType)18U)
#define E_OS_DISABLEDINT ((StatusType)19U)
#define E_OS_PARAM_POINTER ((StatusType)20U)
#define E_OS_CORE ((StatusType)21U)

/* below using in protection-hook */
#define E_OS_PROTECTION_MEMORY ((StatusType)23U)
#define E_OS_PROTECTION_TIME ((StatusType)24U)
#define E_OS_PROTECTION_ARRIVAL ((StatusType)25U)
#define E_OS_PROTECTION_LOCKED ((StatusType)26U)
#define E_OS_STACKFAULT ((StatusType)27U)
#define E_OS_PROTECTION_EXCEPTION ((StatusType)28U)

/* below using in IOC*/
#define IOC_E_OK ((StatusType)0U)
#define IOC_E_NOK ((StatusType)1U)
#define IOC_E_LOST_DATA ((StatusType)64U)
#define IOC_E_LIMIT ((StatusType)130U)
#define IOC_E_NO_DATA ((StatusType)131U)
#define IOC_E_LENGTH ((StatusType)132U)


/* Who are you? */
#define E_OS_RESTART_WITHOUT_RESTART_TASK_IN_PROTECTION_HOOK ((StatusType)29U)
/* state of a task */
#define SUSPENDED ((TaskStateType)0U)
#define READY ((TaskStateType)1U)
#define RUNNING ((TaskStateType)2U)
#define WAITING ((TaskStateType)3U)
#define INVALID_STATE ((TaskStateType)4U)

/* return value of protection hook */
//20220606 to follow SPEC 21-11 ver.
//we change these to ProtectionReturnType in typedefine.h
// #define PRO_IGNORE ((uint8)0U)
// #define PRO_TERMINATETASKISR ((uint8)1U)
// #define PRO_TERMINATEAPPL ((uint8)2U)
// #define PRO_TERMINATEAPPL_RESTART ((uint8)3U)
// #define PRO_SHUTDOWN ((uint8)4U)

/* The following definitions are bit mask of system flag. *
 * These flags are used to check the state of OS.         *
 * Some system services are limited in different state.   */
#define IN_TASK                 ((1U)<<0)
#define IN_ISR1_HANDLER         ((1U)<<1)
#define IN_ISR2_TASK            ((1U)<<2)
#define IN_ERROR_HOOK           ((1U)<<3)
#define IN_PRE_TASK_HOOK        ((1U)<<4)
#define IN_POST_TASK_HOOK       ((1U)<<5)
#define IN_STARTUP_HOOK         ((1U)<<6)
#define IN_SHUTDOWN_HOOK        ((1U)<<7)
#define IN_ALARM_CALLBACK       ((1U)<<8)
#define SERVICE_DISABLE_ALL_INT ((1U)<<9)
#define SERVICE_SUSPEND_ALL_INT ((1U)<<10)
#define SERVICE_SUSPEND_OS_INT  ((1U)<<11)
#define IN_PROTECTION_HOOK      ((1U)<<12)      
#define IN_OSAPP_STARTUP_HOOK   ((1U)<<13)      
#define IN_OSAPP_SHUTDOWN_HOOK  ((1U)<<14)      
#define IN_OSAPP_ERROR_HOOK     ((1U)<<15)      
#define IN_IOC_CALLBACK         ((1U)<<16)      
#define IN_PROTECTION_HANDLER ((1U)<<17)

#define IN_SYSCALL              ((1U)<<21)
#define IN_SERVICE_CORSSCORE    ((1U)<<22)
#define IN_TIMER_INTERRUPT      ((1U)<<23)

#define IN_SHUT_DOWN_OS         ((1U)<<30)
#define AFTER_STARTOS           ((1U)<<31)

/* The following definitions are bit mask to check system services */
/* The following definitions are ruled by the Autosar OS spec 7.7.3.2 */
/* This definition is used to check system services  *
 * that can be called by task                        */
#define SERVICE_LIMIT_CAT1  ((IN_ISR1_HANDLER) | (IN_ISR2_TASK) | (IN_ERROR_HOOK) | \
                            (IN_PRE_TASK_HOOK) | (IN_POST_TASK_HOOK) | (IN_STARTUP_HOOK) | \
                            (IN_SHUTDOWN_HOOK) | (IN_OSAPP_STARTUP_HOOK)| (IN_OSAPP_SHUTDOWN_HOOK) | \
                            (IN_OSAPP_ERROR_HOOK) | (IN_ALARM_CALLBACK) | (IN_PROTECTION_HOOK)) 
/* This definition is used to check system services  *
 * that can be called by task and isr2 task          */
#define SERVICE_LIMIT_CAT2  ((IN_ISR1_HANDLER) | (IN_ERROR_HOOK) | \
                            (IN_PRE_TASK_HOOK) | (IN_POST_TASK_HOOK) | (IN_STARTUP_HOOK) | \
                            (IN_SHUTDOWN_HOOK) | (IN_OSAPP_STARTUP_HOOK)| (IN_OSAPP_SHUTDOWN_HOOK) | \
                            (IN_OSAPP_ERROR_HOOK) | (IN_ALARM_CALLBACK) | (IN_PROTECTION_HOOK)) 

/* This definition is used to check system services  *
 * that can be called by task, isr2 task, ErrorHook, *
 * PreTaskHook and PostTaskHook                      */
#define SERVICE_LIMIT_CAT3  ((IN_ISR1_HANDLER) | (IN_STARTUP_HOOK) | (IN_SHUTDOWN_HOOK) | \
                            (IN_ALARM_CALLBACK) | (IN_OSAPP_STARTUP_HOOK)| (IN_OSAPP_SHUTDOWN_HOOK) )


/* This definition is used to check system services  *
 * that can be called by task, isr2 task, ErrorHook, *
 * PreTaskHook, PostTaskHook, StartupHook, ShutdownHook *
 * and ProtectionHook */

#define SERVICE_LIMIT_CAT4  ((IN_ISR1_HANDLER) | (IN_ALARM_CALLBACK) )

/* This definition is used to check system services  *
 * that can be called by task, isr2 task, ErrorHook, *
 * and ProtectionHook */
#define SERVICE_LIMIT_CAT5  ((IN_ISR1_HANDLER) | \
                            (IN_PRE_TASK_HOOK) | (IN_POST_TASK_HOOK) | (IN_STARTUP_HOOK) | \
                            (IN_SHUTDOWN_HOOK) | (IN_OSAPP_STARTUP_HOOK)| (IN_OSAPP_SHUTDOWN_HOOK) | \
                            (IN_ALARM_CALLBACK) ) 

/* This definition is used to check system service   *
 * "ShutdownOS()"                                    */
#define SERVICE_LIMIT_CAT7  ((IN_ISR1_HANDLER) | (IN_PRE_TASK_HOOK) | (IN_POST_TASK_HOOK) | \
                            (IN_SHUTDOWN_HOOK) | (IN_ALARM_CALLBACK) | (SERVICE_DISABLE_ALL_INT) | \
                            (SERVICE_SUSPEND_ALL_INT) | (SERVICE_SUSPEND_OS_INT))


/* when one of these flags are set, some system services can not be used  */
#define SERVICE_LIMIT_CAT_ACCESS_CHECK ( IN_ISR1_HANDLER|IN_PRE_TASK_HOOK|IN_POST_TASK_HOOK| \
                                         IN_STARTUP_HOOK|IN_SHUTDOWN_HOOK|IN_ALARM_CALLBACK| \
                                         IN_OSAPP_STARTUP_HOOK|IN_OSAPP_SHUTDOWN_HOOK        )


#define NOSAVE 0
#define NEEDSAVE 1

#define SERVICE_ACTIVATETASK 0X40
#define SERVICE_ALLOWACCESS 0X41
#define SERVICE_CALLTRUSTEDFUNCTION 0X42
#define SERVICE_CANCELALARM 0X43
#define SERVICE_CHAINTASK 0X44
#define SERVICE_CHECKISRMEMORYACCESS  0X45
#define SERVICE_CHECKOBJECTACCESS 0X46
#define SERVICE_CHECKOBJECTOWNERSHIP  0X47
#define SERVICE_CHECKTASKMEMORYACCESS 0X48
#define SERVICE_CLEAREVENT  0X49
#define SERVICE_CONTROLIDLE 0X4A
#define SERVICE_DISABLEALLINTERRUPTS  0X4B
#define SERVICE_ENABLEALLINTERRUPTS 0X4C
#define SERVICE_GETACTIVEAPPLICATIONMODE  0X4D
#define SERVICE_GETALARM  0X4E
#define SERVICE_GETALARMBASE  0X4F
#define SERVICE_GETAPPLICATIONID  0X50
#define SERVICE_GETAPPLICATIONSTATE 0X51
#define SERVICE_GETCOREID 0X52
#define SERVICE_GETCOUNTERVALUE 0X53
#define SERVICE_GETELAPSEDVALUE  0X54
#define SERVICE_GETEVENT  0X55
#define SERVICE_GETISRID  0X56
#define SERVICE_GETNUMBEROFACTIVATEDCORES 0X57
#define SERVICE_GETRESOURCE 0X58
#define SERVICE_GETSCHEDULETABLESTATUS  0X59
#define SERVICE_GETSPINLOCK 0X5A
#define SERVICE_GETTASKID 0X5B
#define SERVICE_GETTASKSTATE  0X5C
#define SERVICE_INCREMENTCOUNTER  0X5D
#define SERVICE_NEXTSCHEDULETABLE 0X5E
#define SERVICE_RELEASERESOURCE 0X5F
#define SERVICE_RELEASESPINLOCK 0X60
#define SERVICE_RESUMEALLINTERRUPTS 0X61
#define SERVICE_RESUMEOSINTERRUPTS  0X62
#define SERVICE_SCHEDULE  0X63
#define SERVICE_SETABSALARM 0X64
#define SERVICE_SETEVENT  0X65
#define SERVICE_SETRELALARM 0X66
#define SERVICE_SETSCHEDULETABLEASYNC 0X67
#define SERVICE_SHUTDOWNALLCORES  0X68
#define SERVICE_SHUTDOWNOS  0X69
#define SERVICE_STARTCORE 0X6A
#define SERVICE_STARTOS 0X6B
#define SERVICE_STARTNONAUTOSARCORE 0X6C
#define SERVICE_STARTSCHEDULETABLEABS 0X6D
#define SERVICE_STARTSCHEDULETABLEREL 0X6E
#define SERVICE_STARTSCHEDULETABLESYNCHRON 0X6F
#define SERVICE_STOPSCHEDULETABLE  0X70
#define SERVICE_SUSPENDALLINTERRUPTS 0X71
#define SERVICE_SUSPENDOSINTERRUPTS 0X72
#define SERVICE_SYNCSCHEDULETABLE 0X73
#define SERVICE_TERMINATEAPPLICATION 0X74
#define SERVICE_TERMINATETASK 0X75
#define SERVICE_TRYTOGETSPINLOCK 0X76
#define SERVICE_WAITEVENT 0X77
#define SERVICE_GETAPPLICATIONMODE 0X78
#define SERVICE_ACTIVATETASKASYN 0X79
#define SERVICE_SETEVENTASYN 0X7A
#define SERVICE_CLEARPENDINGINTERRUPT 0X7B
#define SERVICE_ENABLEINTERRUPTSOURCE 0X7C
#define SERVICE_DISABLEINTERRUPTSOURCE 0X7D
#define SERVICE_GETSOFTWARETIMERVALUE 0X7E
#define SERVICE_TICKTOMS 0X7F
#define SERVICE_GETCURRENTAPPLICATIONID 0X80
#define SERVICE_CALLBACKFUNCTION 0X81
#define SERVICE_IOC 0X82
#define READPERIPGERAL8 0X83
#define READPERIPGERAL16 0X84
#define READPERIPGERAL32 0X85
#define WRITEPERIPGERAL8 0X86
#define WRITEPERIPGERAL16 0X87
#define WRITEPERIPGERAL32 0X88
#define MODIFYPERIPGERAL8 0X89
#define MODIFYPERIPGERAL16 0X8A
#define MODIFYPERIPGERAL32 0X8B
#define SERVICE_TERMINATETASKOBJBYOS 0X8C



#define IDLE_NO_HALT 0x00
#define IDLEMODE_INVALID 0x01

#endif /* #ifndef OS_H */
