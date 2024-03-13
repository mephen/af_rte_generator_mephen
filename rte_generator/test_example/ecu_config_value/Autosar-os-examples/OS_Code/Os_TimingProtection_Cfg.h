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
 *              File: Os_TimingProtection_Cfg.h
 *   Generation Time: 2022-07-26 16:44:53
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TIMINGPROTECTION_CFG_H
# define OS_TIMINGPROTECTION_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SWITCHES
 *********************************************************************************************************************/
/*! \variation Defines whether timing protection module is active:
 *     OS_CFG_TP_NO_CORE     No timing protection configured on any ASR core.
 *     OS_CFG_TP_SOME_CORES  Timing protection configured on some ASR cores.
 *     OS_CFG_TP_ALL_CORES   Timing protection configured for all ASR cores.
 */
# define OS_CFG_TIMING_PROTECTION                (OS_CFG_TP_NO_CORE)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_TIMINGPROTECTION_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_TimingProtection_Cfg.h
 *********************************************************************************************************************/
