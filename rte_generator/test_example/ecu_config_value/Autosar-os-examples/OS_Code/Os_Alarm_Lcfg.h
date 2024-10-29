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
 *              File: Os_Alarm_Lcfg.h
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_ALARM_LCFG_H
# define OS_ALARM_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Alarm_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Alarm configuration data: OsAlarm_CddHUIfOnButtonHold */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_CddHUIfOnButtonHold;

/*! Alarm configuration data: OsAlarm_CddHUIfOnZrResetComplete */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_CddHUIfOnZrResetComplete;

/*! Alarm configuration data: OsAlarm_CddTouchTimeout */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_CddTouchTimeout;

/*! Alarm configuration data: OsAlarm_CddWakeupDetectClearResetStatus */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_CddWakeupDetectClearResetStatus;

/*! Alarm configuration data: OsAlarm_CddWdgIfToggleHwWdgClockLevel */
extern CONST(Os_AlarmCallbackConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_CddWdgIfToggleHwWdgClockLevel;

/*! Alarm configuration data: OsAlarm_SwcComRxWakeupReasonTimeout */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_SwcComRxWakeupReasonTimeout;

/*! Alarm configuration data: OsAlarm_SwcDispCtrlNauchLauf */
extern CONST(Os_AlarmCallbackConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_SwcDispCtrlNauchLauf;

/*! Alarm configuration data: OsAlarm_SwcDispCtrlRetryDispOn */
extern CONST(Os_AlarmCallbackConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_SwcDispCtrlRetryDispOn;

/*! Alarm configuration data: OsAlarm_SwcHidKeysOnButtonHold */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_SwcHidKeysOnButtonHold;

/*! Alarm configuration data: OsAlarm_SwcHidKeystxConfirmationTimeout */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_OsAlarm_SwcHidKeystxConfirmationTimeout;

/*! Alarm configuration data: Rte_Al_TE2_OsTask_BswMainFunctions_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_OsTask_BswMainFunctions_0_10ms;

/*! Alarm configuration data: Rte_Al_TE2_OsTask_BswMainFunctions_0_20ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE2_OsTask_BswMainFunctions_0_20ms;

/*! Alarm configuration data: Rte_Al_TE_CanTp_CanTp_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CanTp_CanTp_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_CddBoosterMaximMAX20069_CddBstr_Verify */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CddBoosterMaximMAX20069_CddBstr_Verify;

/*! Alarm configuration data: Rte_Al_TE_CddHwrOnUartRxReady */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CddHwrOnUartRxReady;

/*! Alarm configuration data: Rte_Al_TE_CddUart_CddUart_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_CddUart_CddUart_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_IO_Task_0_200ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_IO_Task_0_200ms;

/*! Alarm configuration data: Rte_Al_TE_OsTask_ApplMainFunctions_0_10ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_OsTask_ApplMainFunctions_0_10ms;

/*! Alarm configuration data: Rte_Al_TE_OsTask_ApplMainFunctions_0_1ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_OsTask_ApplMainFunctions_0_1ms;

/*! Alarm configuration data: Rte_Al_TE_OsTask_ApplTimedInitDeInit_0_1ms */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_OsTask_ApplTimedInitDeInit_0_1ms;

/*! Alarm configuration data: Rte_Al_TE_ShA_Ivd_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_ShA_Ivd_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateCpuLoad */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateCpuLoad;

/*! Alarm configuration data: Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateRuntime */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SwcSelfDiagnostics_SwcSelfDiag_UpdateRuntime;

/*! Alarm configuration data: Rte_Al_TE_SwcTemperatureCorrection_SwcTempCor_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SwcTemperatureCorrection_SwcTempCor_MainFunction;

/*! Alarm configuration data: Rte_Al_TE_SwcTouch_SwcTouch_MainFunction */
extern CONST(Os_AlarmSetEventConfigType, OS_CONST) OsCfg_Alarm_Rte_Al_TE_SwcTouch_SwcTouch_MainFunction;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for alarms. */
extern CONSTP2CONST(Os_AlarmConfigType, OS_CONST, OS_CONST) OsCfg_AlarmRefs[OS_ALARMID_COUNT + 1];            /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ALARM_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Alarm_Lcfg.h
 *********************************************************************************************************************/
