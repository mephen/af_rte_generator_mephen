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
 *              File: Os_Alarm_Cfg.h
 *   Generation Time: 2022-07-26 16:44:52
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_ALARM_CFG_H
# define OS_ALARM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether any alarm has a Callback action (STD_ON) or not (STD_OFF) */
# define OS_CFG_ALARM_CALLBACK_USED                     (STD_ON)

/*! Defines whether any alarm has an ActivateTask action (STD_ON) or not (STD_OFF) */
# define OS_CFG_ALARM_ACTIVATETASK_USED                 (STD_OFF)

/*! Defines whether any alarm has a SetEvent action (STD_ON) or not (STD_OFF) */
# define OS_CFG_ALARM_SETEVENT_USED                     (STD_ON)

/*! Defines whether any alarm has an IncrementCounter action (STD_ON) or not (STD_OFF) */
# define OS_CFG_ALARM_INCREMENTCOUNTER_USED             (STD_OFF)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_ALARM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Alarm_Cfg.h
 *********************************************************************************************************************/
