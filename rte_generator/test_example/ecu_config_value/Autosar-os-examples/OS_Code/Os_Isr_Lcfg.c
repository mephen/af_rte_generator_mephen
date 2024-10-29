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
 *              File: Os_Isr_Lcfg.c
 *   Generation Time: 2023-02-15 09:54:36
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_ISR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Isr_Lcfg.h"
#include "Os_Isr.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_Timer.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"


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

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic ISR data: ADC0_SG1_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC0_SG1_CAT2_ISR_Dyn;

/*! Dynamic ISR data: ADC1_SG1_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_ADC1_SG1_CAT2_ISR_Dyn;

/*! Dynamic ISR data: CanIsrGlobalRxFifo_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrGlobalRxFifo_0_Dyn;

/*! Dynamic ISR data: CanIsrStatus_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrStatus_0_Dyn;

/*! Dynamic ISR data: CanIsrTx_0 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsrTx_0_Dyn;

/*! Dynamic ISR data: CounterIsr_OsCounter_10ms */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_OsCounter_10ms_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimer */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH03_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH07_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH07_CAT2_ISR_Dyn;

/*! Dynamic ISR data: EXT_INTP_CH17_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_EXT_INTP_CH17_CAT2_ISR_Dyn;

/*! Dynamic ISR data: INTIIC0EE */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTIIC0EE_Dyn;

/*! Dynamic ISR data: INTIIC0RI */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTIIC0RI_Dyn;

/*! Dynamic ISR data: INTIIC0TEI */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_INTIIC0TEI_Dyn;

/*! Dynamic ISR data: IRQDmaChannel2TransmitComplete */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_IRQDmaChannel2TransmitComplete_Dyn;

/*! Dynamic ISR data: IRQDmaChannel5ReceiveComplete */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_IRQDmaChannel5ReceiveComplete_Dyn;

/*! Dynamic ISR data: IRQDmaChannel5TransmitComplete */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_IRQDmaChannel5TransmitComplete_Dyn;

/*! Dynamic ISR data: SPI_CSIH0_TIR_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIH0_TIR_CAT2_ISR_Dyn;

/*! Dynamic ISR data: SPI_CSIH2_TIR_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR_Dyn;

/*! Dynamic ISR data: SPI_CSIH3_TIR_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_Dyn;

/*! Dynamic ISR data: TAUD0_CH00_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TAUD0_CH00_CAT2_ISR_Dyn;

/*! Dynamic ISR data: TAUD0_CH01_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TAUD0_CH01_CAT2_ISR_Dyn;

/*! Dynamic ISR data: TAUD0_CH02_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TAUD0_CH02_CAT2_ISR_Dyn;

/*! Dynamic ISR data: TAUD0_CH04_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TAUD0_CH04_CAT2_ISR_Dyn;

/*! Dynamic ISR data: TAUD0_CH05_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_TAUD0_CH05_CAT2_ISR_Dyn;

/*! Dynamic ISR data: WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: ADC0_SG1_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC0_SG1_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC0_SG1_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_ADC0_SG1_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC0_SG1_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC0_SG1_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC0_SG1_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_ADC0_SG1_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ ADC0_SG1_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: ADC1_SG1_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC1_SG1_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_ADC1_SG1_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_ADC1_SG1_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC1_SG1_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_ADC1_SG1_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_ADC1_SG1_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_ADC1_SG1_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ ADC1_SG1_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsrGlobalRxFifo_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrGlobalRxFifo_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrGlobalRxFifo_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrGlobalRxFifo_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrGlobalRxFifo_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrGlobalRxFifo_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrGlobalRxFifo_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrGlobalRxFifo_0_HwConfig,
  /* .IsrId                     = */ CanIsrGlobalRxFifo_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsrStatus_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrStatus_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrStatus_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrStatus_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrStatus_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrStatus_0_HwConfig,
  /* .IsrId                     = */ CanIsrStatus_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CanIsrTx_0 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrTx_0_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsrTx_0,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsrTx_0,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrTx_0 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsrTx_0,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsrTx_0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsrTx_0_HwConfig,
  /* .IsrId                     = */ CanIsrTx_0,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_OsCounter_10ms */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_OsCounter_10ms_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_OsCounter_10ms,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CounterIsr_OsCounter_10ms,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_OsCounter_10ms =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_OsCounter_10ms,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_OsCounter_10ms_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CounterIsr_OsCounter_10ms_HwConfig,
  /* .IsrId                     = */ CounterIsr_OsCounter_10ms,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter_10ms)
};
/*! ISR configuration data: CounterIsr_SystemTimer */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CounterIsr_SystemTimer_HwConfig,
  /* .IsrId                     = */ CounterIsr_SystemTimer,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter_1ms)
};
/*! ISR configuration data: EXT_INTP_CH03_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH03_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH03_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH03_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH03_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: EXT_INTP_CH07_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH07_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH07_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH07_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH07_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH07_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH07_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH07_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH07_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: EXT_INTP_CH17_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH17_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_EXT_INTP_CH17_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_EXT_INTP_CH17_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH17_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_EXT_INTP_CH17_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_EXT_INTP_CH17_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_EXT_INTP_CH17_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ EXT_INTP_CH17_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTIIC0EE */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTIIC0EE_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTIIC0EE,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTIIC0EE,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTIIC0EE =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTIIC0EE,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTIIC0EE_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTIIC0EE_HwConfig,
  /* .IsrId                     = */ INTIIC0EE,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTIIC0RI */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTIIC0RI_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTIIC0RI,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTIIC0RI,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTIIC0RI =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTIIC0RI,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTIIC0RI_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTIIC0RI_HwConfig,
  /* .IsrId                     = */ INTIIC0RI,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: INTIIC0TEI */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTIIC0TEI_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_INTIIC0TEI,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_INTIIC0TEI,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTIIC0TEI =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_INTIIC0TEI,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_INTIIC0TEI_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_INTIIC0TEI_HwConfig,
  /* .IsrId                     = */ INTIIC0TEI,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: IRQDmaChannel2TransmitComplete */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel2TransmitComplete_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_IRQDmaChannel2TransmitComplete,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_IRQDmaChannel2TransmitComplete,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel2TransmitComplete =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IRQDmaChannel2TransmitComplete,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_IRQDmaChannel2TransmitComplete_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_IRQDmaChannel2TransmitComplete_HwConfig,
  /* .IsrId                     = */ IRQDmaChannel2TransmitComplete,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: IRQDmaChannel5ReceiveComplete */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel5ReceiveComplete_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_IRQDmaChannel5ReceiveComplete,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_IRQDmaChannel5ReceiveComplete,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel5ReceiveComplete =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IRQDmaChannel5ReceiveComplete,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_IRQDmaChannel5ReceiveComplete_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_IRQDmaChannel5ReceiveComplete_HwConfig,
  /* .IsrId                     = */ IRQDmaChannel5ReceiveComplete,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: IRQDmaChannel5TransmitComplete */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel5TransmitComplete_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_IRQDmaChannel5TransmitComplete,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_IRQDmaChannel5TransmitComplete,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel5TransmitComplete =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IRQDmaChannel5TransmitComplete,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_IRQDmaChannel5TransmitComplete_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_IRQDmaChannel5TransmitComplete_HwConfig,
  /* .IsrId                     = */ IRQDmaChannel5TransmitComplete,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SPI_CSIH0_TIR_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH0_TIR_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SPI_CSIH0_TIR_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SPI_CSIH0_TIR_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH0_TIR_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIH0_TIR_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIH0_TIR_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SPI_CSIH0_TIR_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ SPI_CSIH0_TIR_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SPI_CSIH2_TIR_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SPI_CSIH2_TIR_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SPI_CSIH2_TIR_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIH2_TIR_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ SPI_CSIH2_TIR_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: SPI_CSIH3_TIR_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_SPI_CSIH3_TIR_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_SPI_CSIH3_TIR_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_SPI_CSIH3_TIR_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ SPI_CSIH3_TIR_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TAUD0_CH00_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH00_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TAUD0_CH00_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TAUD0_CH00_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH00_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TAUD0_CH00_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TAUD0_CH00_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TAUD0_CH00_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ TAUD0_CH00_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TAUD0_CH01_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH01_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TAUD0_CH01_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TAUD0_CH01_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH01_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TAUD0_CH01_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TAUD0_CH01_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TAUD0_CH01_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ TAUD0_CH01_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TAUD0_CH02_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH02_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TAUD0_CH02_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TAUD0_CH02_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH02_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TAUD0_CH02_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TAUD0_CH02_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TAUD0_CH02_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ TAUD0_CH02_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TAUD0_CH04_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH04_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TAUD0_CH04_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TAUD0_CH04_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH04_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TAUD0_CH04_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TAUD0_CH04_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TAUD0_CH04_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ TAUD0_CH04_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: TAUD0_CH05_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH05_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_TAUD0_CH05_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_TAUD0_CH05_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH05_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_TAUD0_CH05_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Level1,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_TAUD0_CH05_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_TAUD0_CH05_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ TAUD0_CH05_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_HwConfig,
  /* .IsrId                     = */ WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC0_SG1_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_ADC1_SG1_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrGlobalRxFifo_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrStatus_0),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsrTx_0),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_OsCounter_10ms),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH07_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_EXT_INTP_CH17_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTIIC0EE),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTIIC0RI),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_INTIIC0TEI),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IRQDmaChannel2TransmitComplete),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IRQDmaChannel5ReceiveComplete),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_IRQDmaChannel5TransmitComplete),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH0_TIR_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH00_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH01_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH02_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH04_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_TAUD0_CH05_CAT2_ISR),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR),
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
 *  END OF FILE: Os_Isr_Lcfg.c
 *********************************************************************************************************************/
