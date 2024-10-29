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
 *              File: Os_Hal_Context_Lcfg.h
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CONTEXT_LCFG_H
# define OS_HAL_CONTEXT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Context_Types.h"

/* Os kernel module dependencies */
# include "Os_Core_Cfg.h"

/* Os hal dependencies */
# include "Os_Hal_Os_Types.h"


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

# define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic ISR2 level context data: Level3 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn;

/*! HAL dynamic task context data: Default_Init_Task */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Dyn;


/*! HAL dynamic task context data: IO_Task */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IO_Task_Dyn;


/*! HAL dynamic task context data: IdleTask_OsCore0 */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;


/*! HAL dynamic task context data: MyTask */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_MyTask_Dyn;


/*! HAL dynamic task context data: OsTask_ApplInitDeInit */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_ApplInitDeInit_Dyn;


/*! HAL dynamic task context data: OsTask_ApplMainFunctions */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_ApplMainFunctions_Dyn;


/*! HAL dynamic task context data: OsTask_ApplTimedInitDeInit */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_ApplTimedInitDeInit_Dyn;


/*! HAL dynamic task context data: OsTask_ApplVerify */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_ApplVerify_Dyn;


/*! HAL dynamic task context data: OsTask_Background */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Background_Dyn;


/*! HAL dynamic task context data: OsTask_BswMainFunctions */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_BswMainFunctions_Dyn;


/*! HAL dynamic task context data: OsTask_Communication */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Communication_Dyn;


/*! HAL dynamic task context data: OsTask_DcmSessionChanges */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_DcmSessionChanges_Dyn;


/*! HAL dynamic task context data: OsTask_Dimming */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Dimming_Dyn;


/*! HAL dynamic task context data: OsTask_NvmAccess */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_NvmAccess_Dyn;


/*! HAL dynamic task context data: OsTask_SelfDiagnostics */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_SelfDiagnostics_Dyn;


/*! HAL dynamic task context data: OsTask_Touch */
extern VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Touch_Dyn;


/*! HAL exception context data: OsCore0 */
extern VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

# define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0;

/*! HAL hook context configuration data: ShutdownHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore0;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0;

/*! HAL ISR2 context configuration data: ADC0_SG1_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC0_SG1_CAT2_ISR;

/*! HAL ISR2 context configuration data: ADC1_SG1_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ADC1_SG1_CAT2_ISR;

/*! HAL ISR2 context configuration data: CanIsrGlobalRxFifo_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrGlobalRxFifo_0;

/*! HAL ISR2 context configuration data: CanIsrStatus_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrStatus_0;

/*! HAL ISR2 context configuration data: CanIsrTx_0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CanIsrTx_0;

/*! HAL ISR2 context configuration data: CounterIsr_OsCounter_10ms */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_OsCounter_10ms;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer;

/*! HAL ISR2 context configuration data: EXT_INTP_CH03_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH03_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH07_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH07_CAT2_ISR;

/*! HAL ISR2 context configuration data: EXT_INTP_CH17_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_EXT_INTP_CH17_CAT2_ISR;

/*! HAL ISR2 context configuration data: INTIIC0EE */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTIIC0EE;

/*! HAL ISR2 context configuration data: INTIIC0RI */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTIIC0RI;

/*! HAL ISR2 context configuration data: INTIIC0TEI */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_INTIIC0TEI;

/*! HAL ISR2 context configuration data: IRQDmaChannel2TransmitComplete */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IRQDmaChannel2TransmitComplete;

/*! HAL ISR2 context configuration data: IRQDmaChannel5ReceiveComplete */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IRQDmaChannel5ReceiveComplete;

/*! HAL ISR2 context configuration data: IRQDmaChannel5TransmitComplete */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IRQDmaChannel5TransmitComplete;

/*! HAL ISR2 context configuration data: SPI_CSIH0_TIR_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH0_TIR_CAT2_ISR;

/*! HAL ISR2 context configuration data: SPI_CSIH2_TIR_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH2_TIR_CAT2_ISR;

/*! HAL ISR2 context configuration data: SPI_CSIH3_TIR_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_SPI_CSIH3_TIR_CAT2_ISR;

/*! HAL ISR2 context configuration data: TAUD0_CH00_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH00_CAT2_ISR;

/*! HAL ISR2 context configuration data: TAUD0_CH01_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH01_CAT2_ISR;

/*! HAL ISR2 context configuration data: TAUD0_CH02_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH02_CAT2_ISR;

/*! HAL ISR2 context configuration data: TAUD0_CH04_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH04_CAT2_ISR;

/*! HAL ISR2 context configuration data: TAUD0_CH05_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_TAUD0_CH05_CAT2_ISR;

/*! HAL ISR2 context configuration data: WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR;

/*! HAL task context configuration data: Default_Init_Task */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task;

/*! HAL task context configuration data: IO_Task */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IO_Task;

/*! HAL task context configuration data: IdleTask_OsCore0 */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0;

/*! HAL task context configuration data: MyTask */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_MyTask;

/*! HAL task context configuration data: OsTask_ApplInitDeInit */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_ApplInitDeInit;

/*! HAL task context configuration data: OsTask_ApplMainFunctions */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_ApplMainFunctions;

/*! HAL task context configuration data: OsTask_ApplTimedInitDeInit */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_ApplTimedInitDeInit;

/*! HAL task context configuration data: OsTask_ApplVerify */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_ApplVerify;

/*! HAL task context configuration data: OsTask_Background */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Background;

/*! HAL task context configuration data: OsTask_BswMainFunctions */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_BswMainFunctions;

/*! HAL task context configuration data: OsTask_Communication */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Communication;

/*! HAL task context configuration data: OsTask_DcmSessionChanges */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_DcmSessionChanges;

/*! HAL task context configuration data: OsTask_Dimming */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Dimming;

/*! HAL task context configuration data: OsTask_NvmAccess */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_NvmAccess;

/*! HAL task context configuration data: OsTask_SelfDiagnostics */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_SelfDiagnostics;

/*! HAL task context configuration data: OsTask_Touch */
extern CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Touch;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
extern CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
extern CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u];

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_CONTEXT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.h
 *********************************************************************************************************************/
