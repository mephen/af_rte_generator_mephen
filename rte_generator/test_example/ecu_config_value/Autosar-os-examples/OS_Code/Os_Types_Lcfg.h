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
 *              File: Os_Types_Lcfg.h
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TYPES_LCFG_H
# define OS_TYPES_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* OS-Application identifiers. */
#define SystemApplication_OsCore0 SystemApplication_OsCore0

/* Trusted function identifiers. */

/* Non-trusted function identifiers. */

/* Fast trusted function identifiers. */

/* Task identifiers. */
#define Default_Init_Task Default_Init_Task
#define IO_Task IO_Task
#define IdleTask_OsCore0 IdleTask_OsCore0
#define MyTask MyTask
#define OsTask_ApplInitDeInit OsTask_ApplInitDeInit
#define OsTask_ApplMainFunctions OsTask_ApplMainFunctions
#define OsTask_ApplTimedInitDeInit OsTask_ApplTimedInitDeInit
#define OsTask_ApplVerify OsTask_ApplVerify
#define OsTask_Background OsTask_Background
#define OsTask_BswMainFunctions OsTask_BswMainFunctions
#define OsTask_Communication OsTask_Communication
#define OsTask_DcmSessionChanges OsTask_DcmSessionChanges
#define OsTask_Dimming OsTask_Dimming
#define OsTask_NvmAccess OsTask_NvmAccess
#define OsTask_SelfDiagnostics OsTask_SelfDiagnostics
#define OsTask_Touch OsTask_Touch

/* Category 2 ISR identifiers. */
#define ADC0_SG1_CAT2_ISR ADC0_SG1_CAT2_ISR
#define ADC1_SG1_CAT2_ISR ADC1_SG1_CAT2_ISR
#define CanIsrGlobalRxFifo_0 CanIsrGlobalRxFifo_0
#define CanIsrStatus_0 CanIsrStatus_0
#define CanIsrTx_0 CanIsrTx_0
#define CounterIsr_OsCounter_10ms CounterIsr_OsCounter_10ms
#define CounterIsr_SystemTimer CounterIsr_SystemTimer
#define EXT_INTP_CH03_CAT2_ISR EXT_INTP_CH03_CAT2_ISR
#define EXT_INTP_CH07_CAT2_ISR EXT_INTP_CH07_CAT2_ISR
#define EXT_INTP_CH17_CAT2_ISR EXT_INTP_CH17_CAT2_ISR
#define INTIIC0EE INTIIC0EE
#define INTIIC0RI INTIIC0RI
#define INTIIC0TEI INTIIC0TEI
#define IRQDmaChannel2TransmitComplete IRQDmaChannel2TransmitComplete
#define IRQDmaChannel5ReceiveComplete IRQDmaChannel5ReceiveComplete
#define IRQDmaChannel5TransmitComplete IRQDmaChannel5TransmitComplete
#define SPI_CSIH0_TIR_CAT2_ISR SPI_CSIH0_TIR_CAT2_ISR
#define SPI_CSIH2_TIR_CAT2_ISR SPI_CSIH2_TIR_CAT2_ISR
#define SPI_CSIH3_TIR_CAT2_ISR SPI_CSIH3_TIR_CAT2_ISR
#define TAUD0_CH00_CAT2_ISR TAUD0_CH00_CAT2_ISR
#define TAUD0_CH01_CAT2_ISR TAUD0_CH01_CAT2_ISR
#define TAUD0_CH02_CAT2_ISR TAUD0_CH02_CAT2_ISR
#define TAUD0_CH04_CAT2_ISR TAUD0_CH04_CAT2_ISR
#define TAUD0_CH05_CAT2_ISR TAUD0_CH05_CAT2_ISR
#define WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR

/* Alarm identifiers. */
#define OsAlarm_CddHUIfOnButtonHold OsAlarm_CddHUIfOnButtonHold
#define OsAlarm_CddHUIfOnZrResetComplete OsAlarm_CddHUIfOnZrResetComplete
#define OsAlarm_CddTouchTimeout OsAlarm_CddTouchTimeout
#define OsAlarm_CddWakeupDetectClearResetStatus OsAlarm_CddWakeupDetectClearResetStatus
#define OsAlarm_CddWdgIfToggleHwWdgClockLevel OsAlarm_CddWdgIfToggleHwWdgClockLevel
#define OsAlarm_SwcComRxWakeupReasonTimeout OsAlarm_SwcComRxWakeupReasonTimeout
#define OsAlarm_SwcDispCtrlNauchLauf OsAlarm_SwcDispCtrlNauchLauf
#define OsAlarm_SwcDispCtrlRetryDispOn OsAlarm_SwcDispCtrlRetryDispOn
#define OsAlarm_SwcHidKeysOnButtonHold OsAlarm_SwcHidKeysOnButtonHold
#define OsAlarm_SwcHidKeystxConfirmationTimeout OsAlarm_SwcHidKeystxConfirmationTimeout
#define Rte_Al_TE2_OsTask_BswMainFunctions_0_10ms Rte_Al_TE2_OsTask_BswMainFunctions_0_10ms
#define Rte_Al_TE2_OsTask_BswMainFunctions_0_20ms Rte_Al_TE2_OsTask_BswMainFunctions_0_20ms
#define Rte_Al_TE_CanTp_CanTp_MainFunction Rte_Al_TE_CanTp_CanTp_MainFunction
#define Rte_Al_TE_CddBoosterMaximMAX20069_CddBstr_Verify Rte_Al_TE_CddBoosterMaximMAX20069_CddBstr_Verify
#define Rte_Al_TE_CddHwrOnUartRxReady Rte_Al_TE_CddHwrOnUartRxReady
#define Rte_Al_TE_CddUart_CddUart_MainFunction Rte_Al_TE_CddUart_CddUart_MainFunction
#define Rte_Al_TE_IO_Task_0_200ms Rte_Al_TE_IO_Task_0_200ms
#define Rte_Al_TE_OsTask_ApplMainFunctions_0_10ms Rte_Al_TE_OsTask_ApplMainFunctions_0_10ms
#define Rte_Al_TE_OsTask_ApplMainFunctions_0_1ms Rte_Al_TE_OsTask_ApplMainFunctions_0_1ms
#define Rte_Al_TE_OsTask_ApplTimedInitDeInit_0_1ms Rte_Al_TE_OsTask_ApplTimedInitDeInit_0_1ms
#define Rte_Al_TE_ShA_Ivd_MainFunction Rte_Al_TE_ShA_Ivd_MainFunction
#define Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateCpuLoad Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateCpuLoad
#define Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateRuntime Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateRuntime
#define Rte_Al_TE_SwcTemperatureCorrection_SwcTempCor_MainFunction Rte_Al_TE_SwcTemperatureCorrection_SwcTempCor_MainFunction
#define Rte_Al_TE_SwcTouch_SwcTouch_MainFunction Rte_Al_TE_SwcTouch_SwcTouch_MainFunction

/* Counter identifiers. */
#define OsCounter_10ms OsCounter_10ms
#define OsCounter_1ms OsCounter_1ms

/* ScheduleTable identifiers. */

/* Resource identifiers. */
#define OsResourceEcuM OsResourceEcuM
#define Rte_Res_CddDebugInfo_EACddDbgInfoBuffer Rte_Res_CddDebugInfo_EACddDbgInfoBuffer
#define Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager
#define Rte_Res_CddHWRNXPRT1171_EACddHwrCom Rte_Res_CddHWRNXPRT1171_EACddHwrCom
#define Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue
#define Rte_Res_CddHWRNXPRT1171_EACddHwrModes Rte_Res_CddHWRNXPRT1171_EACddHwrModes
#define Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring
#define Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl
#define Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess
#define Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess
#define Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer
#define Rte_Res_CddTouchCypressGen7_EACddTouchMode Rte_Res_CddTouchCypressGen7_EACddTouchMode
#define Rte_Res_CddTouchCypressGen7_EACddTouchTrigger Rte_Res_CddTouchCypressGen7_EACddTouchTrigger
#define Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics
#define Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess
#define Rte_Res_SwcDimming_EASwcDimDiagnostics Rte_Res_SwcDimming_EASwcDimDiagnostics
#define Rte_Res_SwcError_EASwcErrorCounters Rte_Res_SwcError_EASwcErrorCounters
#define Rte_Res_SwcHWR_EASwcHWRCharDataBuffer Rte_Res_SwcHWR_EASwcHWRCharDataBuffer

/* Spinlock identifiers. */

/* Peripheral identifiers. */

/* Barrier identifiers. */

/* Trace thread identifiers (Tasks and ISRs inclusive system objects). */

/* Trace spinlock identifiers (All spinlocks inclusive system objects). */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32  Os_AppAccessMaskType;

/*! OS-Application identifiers. */
typedef enum
{
  SystemApplication_OsCore0 = 0, /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_APPID_COUNT = 1,
  INVALID_OSAPPLICATION = OS_APPID_COUNT
} ApplicationType;

/*! Trusted function identifiers. */
typedef enum
{
  OS_TRUSTEDFUNCTIONID_COUNT = 0
} TrustedFunctionIndexType;

/*! Non-trusted function identifiers. */
typedef enum
{
  OS_NONTRUSTEDFUNCTIONID_COUNT = 0
} Os_NonTrustedFunctionIndexType;

/*! Fast trusted function identifiers. */
typedef enum
{
  OS_FASTTRUSTEDFUNCTIONID_COUNT = 0
} Os_FastTrustedFunctionIndexType;

/*! Task identifiers. */
typedef enum
{
  Default_Init_Task = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IO_Task = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IdleTask_OsCore0 = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  MyTask = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_ApplInitDeInit = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_ApplMainFunctions = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_ApplTimedInitDeInit = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_ApplVerify = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_Background = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_BswMainFunctions = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_Communication = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_DcmSessionChanges = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_Dimming = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_NvmAccess = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_SelfDiagnostics = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsTask_Touch = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_TASKID_COUNT = 16,
  INVALID_TASK = OS_TASKID_COUNT
} TaskType;

/*! Category 2 ISR identifiers. */
typedef enum
{
  ADC0_SG1_CAT2_ISR = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  ADC1_SG1_CAT2_ISR = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrGlobalRxFifo_0 = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrStatus_0 = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CanIsrTx_0 = 4,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_OsCounter_10ms = 5,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  CounterIsr_SystemTimer = 6,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH03_CAT2_ISR = 7,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH07_CAT2_ISR = 8,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  EXT_INTP_CH17_CAT2_ISR = 9,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTIIC0EE = 10,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTIIC0RI = 11,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  INTIIC0TEI = 12,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IRQDmaChannel2TransmitComplete = 13,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IRQDmaChannel5ReceiveComplete = 14,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  IRQDmaChannel5TransmitComplete = 15,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SPI_CSIH0_TIR_CAT2_ISR = 16,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SPI_CSIH2_TIR_CAT2_ISR = 17,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  SPI_CSIH3_TIR_CAT2_ISR = 18,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TAUD0_CH00_CAT2_ISR = 19,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TAUD0_CH01_CAT2_ISR = 20,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TAUD0_CH02_CAT2_ISR = 21,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TAUD0_CH04_CAT2_ISR = 22,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  TAUD0_CH05_CAT2_ISR = 23,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR = 24,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ISRID_COUNT = 25,
  INVALID_ISR = OS_ISRID_COUNT
} ISRType;

/*! Alarm identifiers. */
typedef enum
{
  OsAlarm_CddHUIfOnButtonHold = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsAlarm_CddHUIfOnZrResetComplete = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsAlarm_CddTouchTimeout = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsAlarm_CddWakeupDetectClearResetStatus = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsAlarm_CddWdgIfToggleHwWdgClockLevel = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsAlarm_SwcComRxWakeupReasonTimeout = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsAlarm_SwcDispCtrlNauchLauf = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsAlarm_SwcDispCtrlRetryDispOn = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsAlarm_SwcHidKeysOnButtonHold = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsAlarm_SwcHidKeystxConfirmationTimeout = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_OsTask_BswMainFunctions_0_10ms = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE2_OsTask_BswMainFunctions_0_20ms = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CanTp_CanTp_MainFunction = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CddBoosterMaximMAX20069_CddBstr_Verify = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CddHwrOnUartRxReady = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_CddUart_CddUart_MainFunction = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_IO_Task_0_200ms = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_OsTask_ApplMainFunctions_0_10ms = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_OsTask_ApplMainFunctions_0_1ms = 18,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_OsTask_ApplTimedInitDeInit_0_1ms = 19,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_ShA_Ivd_MainFunction = 20,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateCpuLoad = 21,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateRuntime = 22,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SwcTemperatureCorrection_SwcTempCor_MainFunction = 23,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Al_TE_SwcTouch_SwcTouch_MainFunction = 24,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_ALARMID_COUNT = 25
} AlarmType;

/*! Counter identifiers. */
typedef enum
{
  OsCounter_10ms = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OsCounter_1ms = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_COUNTERID_COUNT = 2
} CounterType;

/*! ScheduleTable identifiers. */
typedef enum
{
  OS_SCHTID_COUNT = 0
} ScheduleTableType;

/*! Resource identifiers. */
typedef enum
{
  OsResourceEcuM = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddDebugInfo_EACddDbgInfoBuffer = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddHWRNXPRT1171_EACddHwrCom = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddHWRNXPRT1171_EACddHwrModes = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddTouchCypressGen7_EACddTouchMode = 11,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddTouchCypressGen7_EACddTouchTrigger = 12,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics = 13,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess = 14,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_SwcDimming_EASwcDimDiagnostics = 15,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_SwcError_EASwcErrorCounters = 16,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Rte_Res_SwcHWR_EASwcHWRCharDataBuffer = 17,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_RESOURCEID_COUNT = 18
} ResourceType;

/*! Spinlock identifiers. */
typedef enum
{
  OS_SPINLOCKID_COUNT = 0,
  INVALID_SPINLOCK = OS_SPINLOCKID_COUNT
} SpinlockIdType;

/*! Peripheral identifiers. */
typedef enum
{
  OS_PERIPHERALID_COUNT = 0
} Os_PeripheralIdType;

/*! Barrier identifiers. */
typedef enum
{
  OS_BARRIERID_COUNT = 0
} Os_BarrierIdType;

/*! Trace thread identifiers (Tasks and ISRs inclusive system objects). */
typedef enum
{
  OS_TRACE_THREADID_COUNT = 0,
  OS_TRACE_INVALID_THREAD = OS_TRACE_THREADID_COUNT + 1
} Os_TraceThreadIdType;

/*! Trace spinlock identifiers (All spinlocks inclusive system objects). */
typedef enum
{
  OS_TRACE_NUMBER_OF_CONFIGURED_SPINLOCKS = OS_SPINLOCKID_COUNT,
  OS_TRACE_NUMBER_OF_ALL_SPINLOCKS = OS_SPINLOCKID_COUNT + 0u,  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
  OS_TRACE_INVALID_SPINLOCK = OS_TRACE_NUMBER_OF_ALL_SPINLOCKS + 1
} Os_TraceSpinlockIdType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TYPES_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Types_Lcfg.h
 *********************************************************************************************************************/
