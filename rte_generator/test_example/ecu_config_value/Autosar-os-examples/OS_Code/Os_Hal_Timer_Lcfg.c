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
 *              File: Os_Hal_Timer_Lcfg.c
 *   Generation Time: 2022-07-26 16:44:52
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_TIMER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Timer_Lcfg.h"
#include "Os_Hal_Timer.h"

/* Os kernel module dependencies */

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




/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL timer configuration data: OsCounter_10ms */
CONST(Os_Hal_TimerPitConfigType, OS_CONST) OsCfg_Hal_TimerPit_OsCounter_10ms =
{
  /* Timer Base Address  = */ (uint32)OS_HAL_TIMER_TAUJ2_BASE,
  /* Timer Hardware Type = */ (uint32)OS_HAL_TIMER_TAUJ,
  /* Timer Channel Index = */ (uint32)OS_HAL_TIMER_CH0,
  /* Timer Unit Index    = */ (uint32)OS_HAL_TIMER_TAUJ2,
  /* Timer Reload Value  = */ (uint32)0x00061A7FuL,
  /* Timer ISR Config    = */ (Os_Hal_IntIsrConfigRefType)&OsCfg_Hal_IntIsr_CounterIsr_OsCounter_10ms
};

/*! HAL timer configuration data: OsCounter_1ms */
CONST(Os_Hal_TimerPitConfigType, OS_CONST) OsCfg_Hal_TimerPit_OsCounter_1ms =
{
  /* Timer Base Address  = */ (uint32)OS_HAL_TIMER_OSTM0_BASE,
  /* Timer Hardware Type = */ (uint32)OS_HAL_TIMER_OSTM,
  /* Timer Channel Index = */ (uint32)OS_HAL_TIMER_CH0,
  /* Timer Unit Index    = */ (uint32)OS_HAL_TIMER_OSTM0,
  /* Timer Reload Value  = */ (uint32)0x0000EA5FuL,
  /* Timer ISR Config    = */ (Os_Hal_IntIsrConfigRefType)&OsCfg_Hal_IntIsr_CounterIsr_SystemTimer
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Hal_Timer_Lcfg.c
 *********************************************************************************************************************/
