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
 *              File: Os_XSignal_Lcfg.h
 *   Generation Time: 2022-07-26 16:44:53
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_XSIGNAL_LCFG_H
# define OS_XSIGNAL_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_XSignal_Types.h"

/* Os kernel module dependencies */
# include "Os_Error_Types.h"
# include "OsInt.h"

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

/*! Cross-core function identifiers. */
typedef enum
{
  /* USED */
  OS_XSIGFUNCTIONIDX_USEDCOUNT = 0,
  /* UNUSED */
  XSigFunctionIdx_ActivateTask = 0,
  XSigFunctionIdx_CancelAlarm = 1,
  XSigFunctionIdx_ControlIdle = 2,
  XSigFunctionIdx_GetAlarm = 3,
  XSigFunctionIdx_GetApplicationState = 4,
  XSigFunctionIdx_GetCounterValue = 5,
  XSigFunctionIdx_GetErrorHookStackUsage = 6,
  XSigFunctionIdx_GetEvent = 7,
  XSigFunctionIdx_GetISRStackUsage = 8,
  XSigFunctionIdx_GetKernelStackUsage = 9,
  XSigFunctionIdx_GetNonTrustedFunctionStackUsage = 10,
  XSigFunctionIdx_GetProtectionHookStackUsage = 11,
  XSigFunctionIdx_GetScheduleTableStatus = 12,
  XSigFunctionIdx_GetShutdownHookStackUsage = 13,
  XSigFunctionIdx_GetStartupHookStackUsage = 14,
  XSigFunctionIdx_GetTaskStackUsage = 15,
  XSigFunctionIdx_GetTaskState = 16,
  XSigFunctionIdx_HookCallCallback = 17,
  XSigFunctionIdx_NextScheduleTable = 18,
  XSigFunctionIdx_SetAbsAlarm = 19,
  XSigFunctionIdx_SetEvent = 20,
  XSigFunctionIdx_SetRelAlarm = 21,
  XSigFunctionIdx_ShutdownAllCores = 22,
  XSigFunctionIdx_StartScheduleTableAbs = 23,
  XSigFunctionIdx_StartScheduleTableRel = 24,
  XSigFunctionIdx_StopScheduleTable = 25,
  XSigFunctionIdx_TerminateApplication = 26,
  OS_XSIGFUNCTIONIDX_COUNT = 27
} Os_XSigFunctionIdx;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal used services map. */
extern CONST(OSServiceIdType, OS_CONST) OsCfg_XSig_ServiceMap[OS_XSIGFUNCTIONIDX_COUNT + 1u];                           /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_XSIGNAL_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_XSignal_Lcfg.h
 *********************************************************************************************************************/
