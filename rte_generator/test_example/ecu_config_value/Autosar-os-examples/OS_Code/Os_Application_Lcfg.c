/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: VAG AR4 (MSR_Vag_SLP5)
 *          Customer: Innolux Technology Europe B.V.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F7016463AFP-C
 *    License Scope : The usage is restricted to CBD1600802_D03
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Application_Lcfg.c
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_APPLICATION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Application_Cfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Application.h"

/* Os kernel module dependencies */
#include "Os_Alarm_Lcfg.h"
#include "Os_Alarm.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_ScheduleTable_Lcfg.h"
#include "Os_ScheduleTable.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Timer.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic application data: SystemApplication_OsCore0 */
OS_LOCAL VAR(Os_AppType, OS_VAR_NOINIT) OsCfg_App_SystemApplication_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for application alarms: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_AlarmConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_AlarmRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS + 1u] =
{
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_OsAlarm_CddHUIfOnButtonHold),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_OsAlarm_CddHUIfOnZrResetComplete),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_OsAlarm_CddTouchTimeout),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_OsAlarm_CddWakeupDetectClearResetStatus),
  OS_ALARM_CASTCONFIG_ALARMCALLBACK_2_ALARM(OsCfg_Alarm_OsAlarm_CddWdgIfToggleHwWdgClockLevel),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_OsAlarm_SwcComRxWakeupReasonTimeout),
  OS_ALARM_CASTCONFIG_ALARMCALLBACK_2_ALARM(OsCfg_Alarm_OsAlarm_SwcDispCtrlNauchLauf),
  OS_ALARM_CASTCONFIG_ALARMCALLBACK_2_ALARM(OsCfg_Alarm_OsAlarm_SwcDispCtrlRetryDispOn),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_OsAlarm_SwcHidKeysOnButtonHold),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_OsAlarm_SwcHidKeystxConfirmationTimeout),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_OsTask_BswMainFunctions_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE2_OsTask_BswMainFunctions_0_20ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CanTp_CanTp_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CddBoosterMaximMAX20069_CddBstr_Verify),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CddHwrOnUartRxReady),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_CddUart_CddUart_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_IO_Task_0_200ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_OsTask_ApplMainFunctions_0_10ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_OsTask_ApplMainFunctions_0_1ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_OsTask_ApplTimedInitDeInit_0_1ms),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_ShA_Ivd_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateCpuLoad),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateRuntime),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SwcTemperatureCorrection_SwcTempCor_MainFunction),
  OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(OsCfg_Alarm_Rte_Al_TE_SwcTouch_SwcTouch_MainFunction),
  NULL_PTR
};

/*! Object reference table for application counters: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_CounterConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_CounterRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS + 1u] =
{
  OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter_10ms),
  OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter_1ms),
  NULL_PTR
};

/*! Object reference table for application hooks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_HookRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS + 1u] =
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC0_SG1_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC1_SG1_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrGlobalRxFifo_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrStatus_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrTx_0),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_OsCounter_10ms),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH07_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH17_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTIIC0EE),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTIIC0RI),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTIIC0TEI),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IRQDmaChannel2TransmitComplete),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IRQDmaChannel5ReceiveComplete),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IRQDmaChannel5TransmitComplete),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH0_TIR_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH00_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH01_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH02_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH04_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH05_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR),
  NULL_PTR
};

/*! Object reference table for application category 1 (EXTERNAL) ISRs: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_IsrCat1ConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application schedule tables: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_SchTConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_SchTRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for application tasks: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_TaskConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_TaskRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS + 1u] =
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IO_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_MyTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ApplInitDeInit),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ApplMainFunctions),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ApplTimedInitDeInit),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ApplVerify),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Background),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_BswMainFunctions),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Communication),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_DcmSessionChanges),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Dimming),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_NvmAccess),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_SelfDiagnostics),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Touch),
  NULL_PTR
};

/*! Object reference table for application trusted functions: SystemApplication_OsCore0 */
OS_LOCAL CONST(Os_ServiceConfigRefType, OS_CONST) OsCfg_App_SystemApplication_OsCore0_ServiceRefs[OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES + 1u] =
{
  NULL_PTR
};

/*! Application configuration data: SystemApplication_OsCore0 */
CONST(Os_AppConfigType, OS_CONST) OsCfg_App_SystemApplication_OsCore0 =
{
  /* .Dyn                  = */ &OsCfg_App_SystemApplication_OsCore0_Dyn,
  /* .Core                 = */ &OsCfg_Core_OsCore0,
  /* .AccessRightId        = */ OS_APPID2MASK(SystemApplication_OsCore0),
  /* .TaskRefs             = */ OsCfg_App_SystemApplication_OsCore0_TaskRefs,
  /* .TaskCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_TASKS,
  /* .IsrCat2Refs          = */ OsCfg_App_SystemApplication_OsCore0_IsrRefs,
  /* .IsrCat2Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ISRS,
  /* .IsrCat1Refs          = */ OsCfg_App_SystemApplication_OsCore0_Cat1IsrRefs,
  /* .IsrCat1Count         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_CAT1ISRS,
  /* .CounterRefs          = */ OsCfg_App_SystemApplication_OsCore0_CounterRefs,
  /* .CounterCount         = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_COUNTERS,
  /* .AlarmRefs            = */ OsCfg_App_SystemApplication_OsCore0_AlarmRefs,
  /* .AlarmCount           = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_ALARMS,
  /* .SchTRefs             = */ OsCfg_App_SystemApplication_OsCore0_SchTRefs,
  /* .SchTCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SCHTS,
  /* .ServiceFunctions     = */ OsCfg_App_SystemApplication_OsCore0_ServiceRefs,
  /* .ServiceFunctionCount = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_SERVICES,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ NULL_PTR,
  /* .ErrorHookRef         = */ NULL_PTR,
  /* .HookRefs             = */ OsCfg_App_SystemApplication_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_APP_SYSTEMAPPLICATION_OSCORE0_HOOKS,
  /* .RestartTask          = */ NULL_PTR,
  /* .IsTrusted            = */ TRUE,
  /* .IsPriveleged         = */ TRUE,
  /* .HasTimingProtectionDelay = */ FALSE,
  /* .Id                   = */ SystemApplication_OsCore0
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for applications. */
CONSTP2CONST(Os_AppConfigType, OS_CONST, OS_CONST) OsCfg_AppRefs[OS_APPID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  &OsCfg_App_SystemApplication_OsCore0,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Application_Lcfg.c
 *********************************************************************************************************************/
