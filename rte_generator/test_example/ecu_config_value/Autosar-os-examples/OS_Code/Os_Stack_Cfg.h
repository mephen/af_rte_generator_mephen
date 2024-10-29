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
 *              File: Os_Stack_Cfg.h
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_STACK_CFG_H
# define OS_STACK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether stack monitoring is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMONITORING                  (STD_ON)

/*! Defines whether stack measurement is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMEASUREMENT                 (STD_ON)

/* Configured stack sizes (Total: 38912 Byte) */
# define OS_CFG_SIZE_IO_TASK_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_ERROR_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK     (2048uL)
# define OS_CFG_SIZE_OSCORE0_ISR_LEVEL1_STACK     (2048uL)
# define OS_CFG_SIZE_OSCORE0_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO1001_STACK     (2048uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO13_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK     (2048uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO5_STACK     (2048uL)
# define OS_CFG_SIZE_OSTASK_APPLINITDEINIT_STACK     (2048uL)
# define OS_CFG_SIZE_OSTASK_APPLMAINFUNCTIONS_STACK     (2048uL)
# define OS_CFG_SIZE_OSTASK_APPLTIMEDINITDEINIT_STACK     (2048uL)
# define OS_CFG_SIZE_OSTASK_APPLVERIFY_STACK     (1024uL)
# define OS_CFG_SIZE_OSTASK_BSWMAINFUNCTIONS_STACK     (2048uL)
# define OS_CFG_SIZE_OSTASK_COMMUNICATION_STACK     (2048uL)
# define OS_CFG_SIZE_OSTASK_DCMSESSIONCHANGES_STACK     (3072uL)
# define OS_CFG_SIZE_OSTASK_DIMMING_STACK     (3072uL)
# define OS_CFG_SIZE_OSTASK_NVMACCESS_STACK     (1024uL)
# define OS_CFG_SIZE_OSTASK_SELFDIAGNOSTICS_STACK     (2048uL)
# define OS_CFG_SIZE_OSTASK_TOUCH_STACK     (2048uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
