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
 *              File: Os_Hal_Context_Lcfg.c
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic task context data: Default_Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Dyn;

/*! HAL dynamic task context data: IO_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IO_Task_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: MyTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_MyTask_Dyn;

/*! HAL dynamic task context data: OsTask_ApplInitDeInit */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_ApplInitDeInit_Dyn;

/*! HAL dynamic task context data: OsTask_ApplMainFunctions */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_ApplMainFunctions_Dyn;

/*! HAL dynamic task context data: OsTask_ApplTimedInitDeInit */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_ApplTimedInitDeInit_Dyn;

/*! HAL dynamic task context data: OsTask_ApplVerify */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_ApplVerify_Dyn;

/*! HAL dynamic task context data: OsTask_Background */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Background_Dyn;

/*! HAL dynamic task context data: OsTask_BswMainFunctions */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_BswMainFunctions_Dyn;

/*! HAL dynamic task context data: OsTask_Communication */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Communication_Dyn;

/*! HAL dynamic task context data: OsTask_DcmSessionChanges */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_DcmSessionChanges_Dyn;

/*! HAL dynamic task context data: OsTask_Dimming */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Dimming_Dyn;

/*! HAL dynamic task context data: OsTask_NvmAccess */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_NvmAccess_Dyn;

/*! HAL dynamic task context data: OsTask_SelfDiagnostics */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_SelfDiagnostics_Dyn;

/*! HAL dynamic task context data: OsTask_Touch */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Touch_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_HookWrapperOs_CoreInitHook, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapHookReturn, /* PRQA S 0305, 306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL hook context configuration data: ShutdownHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_HookWrapperStatusHook, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapHookReturn, /* PRQA S 0305, 306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Error_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_HookWrapperStatusHook, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapHookReturn, /* PRQA S 0305, 306 */ /* MD_Os_Hal_Rule11.1_0305, MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL ISR2 context configuration data: ADC0_SG1_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC0_SG1_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_ADC0_SG1_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: ADC1_SG1_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC1_SG1_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_ADC1_SG1_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrGlobalRxFifo_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrGlobalRxFifo_0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrGlobalRxFifo_0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrStatus_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrStatus_0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrStatus_0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CanIsrTx_0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrTx_0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CanIsrTx_0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CounterIsr_OsCounter_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_OsCounter_10ms =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Os_TimerPitIsr, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_Os_TimerPitIsr, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH03_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH03_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH03_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH07_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH07_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH07_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: EXT_INTP_CH17_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH17_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_EXT_INTP_CH17_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTIIC0EE */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTIIC0EE =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_I2c_IrqUnit0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTIIC0RI */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTIIC0RI =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_I2c_IrqUnit0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: INTIIC0TEI */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTIIC0TEI =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_I2c_IrqUnit0, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: IRQDmaChannel2TransmitComplete */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IRQDmaChannel2TransmitComplete =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CddUart_DmaChannel2TransmitCompleteNotification, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: IRQDmaChannel5ReceiveComplete */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IRQDmaChannel5ReceiveComplete =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CddUart_DmaChannel5ReceiveCompleteNotification, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: IRQDmaChannel5TransmitComplete */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IRQDmaChannel5TransmitComplete =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_CddUart_DmaChannel5TransmitCompleteNotification, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: SPI_CSIH0_TIR_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH0_TIR_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_SPI_CSIH0_TIR_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: SPI_CSIH2_TIR_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH2_TIR_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_SPI_CSIH2_TIR_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: SPI_CSIH3_TIR_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_SPI_CSIH3_TIR_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: TAUD0_CH00_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH00_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_TAUD0_CH00_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: TAUD0_CH01_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH01_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_TAUD0_CH01_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: TAUD0_CH02_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH02_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_TAUD0_CH02_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: TAUD0_CH04_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH04_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_TAUD0_CH04_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: TAUD0_CH05_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH05_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Level1_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Level1_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_TAUD0_CH05_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL ISR2 context configuration data: WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapIsrEpilogue, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL
}
;

/*! HAL task context configuration data: Default_Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio1001_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio1001_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_Default_Init_Task, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: IO_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IO_Task =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_IO_Task_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_IO_Task_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_IO_Task, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_Os_IdleTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: MyTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MyTask =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio13_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio13_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_MyTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_ApplInitDeInit */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_ApplInitDeInit =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_ApplInitDeInit_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_ApplInitDeInit_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_ApplInitDeInit, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_ApplMainFunctions */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_ApplMainFunctions =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_ApplMainFunctions_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_ApplMainFunctions_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_ApplMainFunctions, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_ApplTimedInitDeInit */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_ApplTimedInitDeInit =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_ApplTimedInitDeInit_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_ApplTimedInitDeInit_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_ApplTimedInitDeInit, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_ApplVerify */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_ApplVerify =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_ApplVerify_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_ApplVerify_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_ApplVerify, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_Background */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Background =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio5_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio5_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_Background, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_BswMainFunctions */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_BswMainFunctions =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_BswMainFunctions_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_BswMainFunctions_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_BswMainFunctions, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_Communication */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Communication =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_Communication_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_Communication_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_Communication, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_DcmSessionChanges */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_DcmSessionChanges =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_DcmSessionChanges_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_DcmSessionChanges_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_DcmSessionChanges, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_Dimming */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Dimming =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_Dimming_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_Dimming_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_Dimming, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_NvmAccess */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_NvmAccess =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_NvmAccess_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_NvmAccess_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_NvmAccess, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_SelfDiagnostics */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_SelfDiagnostics =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_SelfDiagnostics_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_SelfDiagnostics_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_SelfDiagnostics, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL task context configuration data: OsTask_Touch */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Touch =
{
  /* .Os_Hal_SL     = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_Touch_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_SP     = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_Touch_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Entry         = */ (uint32)&Os_Task_OsTask_Touch, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .ReturnAddress = */ (uint32)&Os_TrapTaskMissingTerminateTask, /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .Os_Hal_PSW    = */ (uint32)0x00018000uL,
  /* .Os_Hal_PMR    = */ (uint32)(0x00000000uL & OS_HAL_PMR_MASK),
  /* .Os_Hal_ASID   = */ (uint32)0x000003FFuL  
}
;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn), /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
  /* .StackEnd   = */ (uint32)OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn) /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */
}
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
