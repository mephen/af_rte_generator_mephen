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
 *              File: Os_Scheduler_Cfg.h
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_SCHEDULER_CFG_H
# define OS_SCHEDULER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether round robin scheduling is enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_SCHEDULE_ROUND_ROB_ENABLED       (STD_OFF)

/*! Defines the number of all task queues. */
# define OS_CFG_NUM_TASKQUEUES                   (16u)

/* Number of task queue activation slots: OsCore0 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE4_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE5_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE6_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE7_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE8_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE9_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE10_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE11_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE12_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE13_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE14_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE15_OSCORE0_SLOTS     (2u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_SCHEDULER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Cfg.h
 *********************************************************************************************************************/
