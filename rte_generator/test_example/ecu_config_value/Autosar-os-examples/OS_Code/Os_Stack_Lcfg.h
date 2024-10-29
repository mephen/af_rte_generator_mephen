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
 *              File: Os_Stack_Lcfg.h
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_STACK_LCFG_H
# define OS_STACK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_Stack_Types.h"

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

# define OS_START_SEC_STACK_IO_TASK_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: IO_Task */
/* User: [IO_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_IO_Task_Dyn, OS_CFG_SIZE_IO_TASK_STACK);

# define OS_STOP_SEC_STACK_IO_TASK_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core error stack: OsCore0_Error */
/* User: [ErrorHook_OsCore0, OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Error_Dyn, OS_CFG_SIZE_OSCORE0_ERROR_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ERROR_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore0_Init */
/* User: [OsCore0, Os_CoreInitHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Init_Dyn, OS_CFG_SIZE_OSCORE0_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore0_Isr_Core */
/* User: [ADC0_SG1_CAT2_ISR, ADC1_SG1_CAT2_ISR, CanIsrGlobalRxFifo_0, CanIsrStatus_0, CanIsrTx_0, CounterIsr_OsCounter_10ms, CounterIsr_SystemTimer, EXT_INTP_CH03_CAT2_ISR, EXT_INTP_CH07_CAT2_ISR, EXT_INTP_CH17_CAT2_ISR, INTIIC0EE, INTIIC0RI, INTIIC0TEI, IRQDmaChannel2TransmitComplete, IRQDmaChannel5ReceiveComplete, IRQDmaChannel5TransmitComplete, SPI_CSIH0_TIR_CAT2_ISR, SPI_CSIH2_TIR_CAT2_ISR, SPI_CSIH3_TIR_CAT2_ISR, TAUD0_CH00_CAT2_ISR, TAUD0_CH01_CAT2_ISR, TAUD0_CH02_CAT2_ISR, TAUD0_CH04_CAT2_ISR, WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_LEVEL1_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared ISR level stack: OsCore0_Isr_Level1 */
/* User: [TAUD0_CH05_CAT2_ISR] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Level1_Dyn, OS_CFG_SIZE_OSCORE0_ISR_LEVEL1_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_LEVEL1_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore0_Kernel */
/* User: [OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Kernel_Dyn, OS_CFG_SIZE_OSCORE0_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core shutdown stack: OsCore0_Shutdown */
/* User: [OsCore0, ShutdownHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Shutdown_Dyn, OS_CFG_SIZE_OSCORE0_SHUTDOWN_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_SHUTDOWN_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO1001_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio1001 */
/* User: [Default_Init_Task] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio1001_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO1001_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO1001_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO13_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio13 */
/* User: [MyTask] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio13_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO13_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO13_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio4294967295 */
/* User: [IdleTask_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio5 */
/* User: [OsTask_Background] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio5_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO5_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO5_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_APPLINITDEINIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_ApplInitDeInit */
/* User: [OsTask_ApplInitDeInit] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_ApplInitDeInit_Dyn, OS_CFG_SIZE_OSTASK_APPLINITDEINIT_STACK);

# define OS_STOP_SEC_STACK_OSTASK_APPLINITDEINIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_APPLMAINFUNCTIONS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_ApplMainFunctions */
/* User: [OsTask_ApplMainFunctions] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_ApplMainFunctions_Dyn, OS_CFG_SIZE_OSTASK_APPLMAINFUNCTIONS_STACK);

# define OS_STOP_SEC_STACK_OSTASK_APPLMAINFUNCTIONS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_APPLTIMEDINITDEINIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_ApplTimedInitDeInit */
/* User: [OsTask_ApplTimedInitDeInit] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_ApplTimedInitDeInit_Dyn, OS_CFG_SIZE_OSTASK_APPLTIMEDINITDEINIT_STACK);

# define OS_STOP_SEC_STACK_OSTASK_APPLTIMEDINITDEINIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_APPLVERIFY_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_ApplVerify */
/* User: [OsTask_ApplVerify] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_ApplVerify_Dyn, OS_CFG_SIZE_OSTASK_APPLVERIFY_STACK);

# define OS_STOP_SEC_STACK_OSTASK_APPLVERIFY_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_BSWMAINFUNCTIONS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_BswMainFunctions */
/* User: [OsTask_BswMainFunctions] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_BswMainFunctions_Dyn, OS_CFG_SIZE_OSTASK_BSWMAINFUNCTIONS_STACK);

# define OS_STOP_SEC_STACK_OSTASK_BSWMAINFUNCTIONS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_COMMUNICATION_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_Communication */
/* User: [OsTask_Communication] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_Communication_Dyn, OS_CFG_SIZE_OSTASK_COMMUNICATION_STACK);

# define OS_STOP_SEC_STACK_OSTASK_COMMUNICATION_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_DCMSESSIONCHANGES_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_DcmSessionChanges */
/* User: [OsTask_DcmSessionChanges] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_DcmSessionChanges_Dyn, OS_CFG_SIZE_OSTASK_DCMSESSIONCHANGES_STACK);

# define OS_STOP_SEC_STACK_OSTASK_DCMSESSIONCHANGES_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_DIMMING_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_Dimming */
/* User: [OsTask_Dimming] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_Dimming_Dyn, OS_CFG_SIZE_OSTASK_DIMMING_STACK);

# define OS_STOP_SEC_STACK_OSTASK_DIMMING_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_NVMACCESS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_NvmAccess */
/* User: [OsTask_NvmAccess] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_NvmAccess_Dyn, OS_CFG_SIZE_OSTASK_NVMACCESS_STACK);

# define OS_STOP_SEC_STACK_OSTASK_NVMACCESS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_SELFDIAGNOSTICS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_SelfDiagnostics */
/* User: [OsTask_SelfDiagnostics] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_SelfDiagnostics_Dyn, OS_CFG_SIZE_OSTASK_SELFDIAGNOSTICS_STACK);

# define OS_STOP_SEC_STACK_OSTASK_SELFDIAGNOSTICS_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSTASK_TOUCH_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Task stack: OsTask_Touch */
/* User: [OsTask_Touch] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsTask_Touch_Dyn, OS_CFG_SIZE_OSTASK_TOUCH_STACK);

# define OS_STOP_SEC_STACK_OSTASK_TOUCH_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: IO_Task */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_IO_Task;

/*! Stack configuration data: OsCore0_Error */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Error;

/*! Stack configuration data: OsCore0_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Init;

/*! Stack configuration data: OsCore0_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Core;

/*! Stack configuration data: OsCore0_Isr_Level1 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Level1;

/*! Stack configuration data: OsCore0_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Kernel;

/*! Stack configuration data: OsCore0_Shutdown */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Shutdown;

/*! Stack configuration data: OsCore0_Task_Prio1001 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio1001;

/*! Stack configuration data: OsCore0_Task_Prio13 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio13;

/*! Stack configuration data: OsCore0_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio4294967295;

/*! Stack configuration data: OsCore0_Task_Prio5 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio5;

/*! Stack configuration data: OsTask_ApplInitDeInit */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_ApplInitDeInit;

/*! Stack configuration data: OsTask_ApplMainFunctions */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_ApplMainFunctions;

/*! Stack configuration data: OsTask_ApplTimedInitDeInit */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_ApplTimedInitDeInit;

/*! Stack configuration data: OsTask_ApplVerify */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_ApplVerify;

/*! Stack configuration data: OsTask_BswMainFunctions */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_BswMainFunctions;

/*! Stack configuration data: OsTask_Communication */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_Communication;

/*! Stack configuration data: OsTask_DcmSessionChanges */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_DcmSessionChanges;

/*! Stack configuration data: OsTask_Dimming */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_Dimming;

/*! Stack configuration data: OsTask_NvmAccess */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_NvmAccess;

/*! Stack configuration data: OsTask_SelfDiagnostics */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_SelfDiagnostics;

/*! Stack configuration data: OsTask_Touch */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsTask_Touch;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_STACK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.h
 *********************************************************************************************************************/
