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
 *              File: Os_Task_Lcfg.h
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_TASK_LCFG_H
# define OS_TASK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Task_Types.h"

/* Os kernel module dependencies */
# include "Os_Ioc_Types.h"
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

/*! Task configuration data: Default_Init_Task */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task;

/*! Task configuration data: IO_Task */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IO_Task;

/*! Task configuration data: IdleTask_OsCore0 */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore0;

/*! Task configuration data: MyTask */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_MyTask;

/*! Task configuration data: OsTask_ApplInitDeInit */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_ApplInitDeInit;

/*! Task configuration data: OsTask_ApplMainFunctions */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_ApplMainFunctions;

/*! Task configuration data: OsTask_ApplTimedInitDeInit */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_ApplTimedInitDeInit;

/*! Task configuration data: OsTask_ApplVerify */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_ApplVerify;

/*! Task configuration data: OsTask_Background */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Background;

/*! Task configuration data: OsTask_BswMainFunctions */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_BswMainFunctions;

/*! Task configuration data: OsTask_Communication */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Communication;

/*! Task configuration data: OsTask_DcmSessionChanges */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_DcmSessionChanges;

/*! Task configuration data: OsTask_Dimming */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Dimming;

/*! Task configuration data: OsTask_NvmAccess */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_NvmAccess;

/*! Task configuration data: OsTask_SelfDiagnostics */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_SelfDiagnostics;

/*! Task configuration data: OsTask_Touch */
extern CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Touch;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for tasks. */
extern CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_TASK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Task_Lcfg.h
 *********************************************************************************************************************/
