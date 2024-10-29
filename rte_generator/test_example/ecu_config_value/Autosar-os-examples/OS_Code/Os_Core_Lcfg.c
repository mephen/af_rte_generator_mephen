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
 *              File: Os_Core_Lcfg.c
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_CORE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Core_Cfg.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Barrier_Lcfg.h"
#include "Os_Common.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Resource_Lcfg.h"
#include "Os_Scheduler_Lcfg.h"
#include "Os_Spinlock_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Core_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Kernel_Lcfg.h"


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

#define OS_START_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core status: OsCore0 */
OS_LOCAL VAR(Os_CoreAsrStatusType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_Status_Dyn;

#define OS_STOP_SEC_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Thread class data for: OsCore0 */
OS_LOCAL VAR(Os_ThreadClassType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_ThreadClass;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core boot barrier: OsCore0 */
OS_LOCAL VAR(Os_CoreBootBarrierType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_BootBarrier_Dyn;

#define OS_STOP_SEC_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic core data: OsCore0 */
VAR(Os_CoreAsrType, OS_VAR_NOINIT) OsCfg_Core_OsCore0_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for core hooks: OsCore0 */
OS_LOCAL CONST(Os_HookConfigRefType, OS_CONST) OsCfg_Core_OsCore0_HookRefs[OS_CFG_NUM_CORE_OSCORE0_HOOKS + 1u] =
{
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_Os_CoreInitHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ShutdownHook_OsCore0),
  OS_HOOK_CASTCONFIG_STATUSHOOK_2_HOOK(OsCfg_Hook_ErrorHook_OsCore0),
  NULL_PTR
};

/*! Object reference table for core applications: OsCore0 */
OS_LOCAL CONST(Os_AppConfigRefType, OS_CONST) OsCfg_Core_OsCore0_AppRefs[OS_CFG_NUM_CORE_OSCORE0_APPS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core IOC communications: OsCore0 */
OS_LOCAL CONST(Os_IocConfigRefType, OS_CONST) OsCfg_Core_OsCore0_IocRefs[OS_CFG_NUM_CORE_OSCORE0_IOCS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core barriers: OsCore0 */
OS_LOCAL CONST(Os_BarrierBaseConfigRefType, OS_CONST) OsCfg_Core_OsCore0_BarrierRefs[OS_CFG_NUM_BARRIERS + 1u] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */ 
{
  NULL_PTR
};

/*! Object reference table for core resources: OsCore0 */
OS_LOCAL CONST(Os_ResourceConfigRefType, OS_CONST) OsCfg_Core_OsCore0_ResourceRefs[OS_CFG_NUM_CORE_OSCORE0_RESOURCES + 1u] =
{
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_OsResourceEcuM),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddDebugInfo_EACddDbgInfoBuffer),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCom),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrModes),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchMode),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchTrigger),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_SwcDimming_EASwcDimDiagnostics),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_SwcError_EASwcErrorCounters),
  OS_RESOURCE_CASTCONFIG_RESOURCE_2_RESOURCE(OsCfg_Resource_Rte_Res_SwcHWR_EASwcHWRCharDataBuffer),
  NULL_PTR
};

/*! Object reference table for core stacks: OsCore0 */
OS_LOCAL CONST(Os_StackConfigRefType, OS_CONST) OsCfg_Core_OsCore0_StackRefs[OS_CFG_NUM_CORE_OSCORE0_STACKS + 1u] =
{
  (Os_StackConfigRefType) &OsCfg_Stack_IO_Task,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Error,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Init,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Core,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Isr_Level1,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Kernel,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Shutdown,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio1001,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio13,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio4294967295,
  (Os_StackConfigRefType) &OsCfg_Stack_OsCore0_Task_Prio5,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_ApplInitDeInit,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_ApplMainFunctions,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_ApplTimedInitDeInit,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_ApplVerify,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_BswMainFunctions,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_Communication,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_DcmSessionChanges,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_Dimming,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_NvmAccess,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_SelfDiagnostics,
  (Os_StackConfigRefType) &OsCfg_Stack_OsTask_Touch,
  NULL_PTR
};

/*! Object reference table for core ISRs: OsCore0 */
OS_LOCAL CONST(Os_IsrConfigRefType, OS_CONST) OsCfg_Core_OsCore0_IsrRefs[OS_CFG_NUM_CORE_OSCORE0_ISRS + 1u] =
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

/*! Core configuration data: OsCore0 */
CONST(Os_CoreAsrConfigType, OS_CONST) OsCfg_Core_OsCore0 =
{
  /* .Core                 = */
  {
    /* .Status               = */ OS_CORE_CASTSTATUS_COREASRSTATUS_2_CORESTATUS(OsCfg_Core_OsCore0_Status_Dyn),
    /* .HwConfig             = */ &OsCfg_Hal_Core_OsCore0,
    /* .InterruptSourceRefs  = */ OsCfg_Hal_Core_OsCore0_InterruptSourceRefs,
    /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_INTERRUPTSOURCEREFS,
    /* .Id                   = */ OS_CORE_ID_0,
    /* .Trace                = */ NULL_PTR,
    /* .IsAsrCore            = */ TRUE,
    /* .IsAutostart          = */ TRUE,
    /* .IsMasterStartAllowed = */ FALSE,
    /* .HasPrivilegedHardwareAccess = */ TRUE
  },
  /* .Dyn                  = */ &OsCfg_Core_OsCore0_Dyn,
  /* .Scheduler            = */ &OsCfg_Scheduler_OsCore0,
  /* .IdleTask             = */ &OsCfg_Task_IdleTask_OsCore0,
  /* .KernelApp            = */ &OsCfg_App_SystemApplication_OsCore0,
  /* .KernelStack          = */ &OsCfg_Stack_OsCore0_Kernel,
  /* .PreStartTask         = */ NULL_PTR,
  /* .PreStartTaskCallback = */ NULL_PTR,
  /* .StartupHookRef       = */ NULL_PTR,
  /* .ShutdownHookRef      = */ &OsCfg_Hook_ShutdownHook_OsCore0,
  /* .ErrorHookRef         = */ &OsCfg_Hook_ErrorHook_OsCore0,
  /* .ProtectionHookRef    = */ NULL_PTR,
  /* .InitHookRef          = */ &OsCfg_Hook_Os_CoreInitHook_OsCore0,
  /* .HookRefs             = */ OsCfg_Core_OsCore0_HookRefs,
  /* .HookCount            = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_HOOKS,
  /* .AppRefs              = */ OsCfg_Core_OsCore0_AppRefs,
  /* .AppCount             = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_APPS,
  /* .ResourceRefs         = */ OsCfg_Core_OsCore0_ResourceRefs,
  /* .ResourceCount        = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_RESOURCES,
  /* .HwConfig             = */ &OsCfg_Hal_CoreAsr_OsCore0,
  /* .MemoryProtection     = */ NULL_PTR,
  /* .TimingProtection     = */ NULL_PTR,
  /* .StackRefs            = */ OsCfg_Core_OsCore0_StackRefs,
  /* .StackCount           = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_STACKS,
  /* .CoreIdx              = */ OS_COREASRCOREIDX_0,
  /* .XSignal              = */ NULL_PTR,
  /* .IocRefs              = */ OsCfg_Core_OsCore0_IocRefs,
  /* .IocCount             = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_IOCS,
  /* .Barrier              = */ &OsCfg_Barrier_OsCore0,
  /* .BarrierRefs          = */ OsCfg_Core_OsCore0_BarrierRefs,
  /* .BarrierCount         = */ (Os_ObjIdxType)OS_CFG_NUM_BARRIERS,
  /* .ThreadClass          = */ &OsCfg_Core_OsCore0_ThreadClass,
  /* .IsrRefs              = */ OsCfg_Core_OsCore0_IsrRefs,
  /* .IsrCount             = */ (Os_ObjIdxType)OS_CFG_NUM_CORE_OSCORE0_ISRS
}
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for system spinlocks. */
OS_LOCAL CONST(Os_SpinlockConfigRefType, OS_CONST) OsCfg_SystemSpinlockRefs[OS_CFG_NUM_SYSTEM_SPINLOCKS + 1u] =
{
  NULL_PTR
};

/*! Object reference table for core boot barriers. */
CONSTP2VAR(Os_CoreBootBarrierType, AUTOMATIC, OS_CONST) OsCfg_CoreBootBarrierRefs[OS_COREID_COUNT + 1u] =               /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */  
{
  &OsCfg_Core_OsCore0_BootBarrier_Dyn,
  NULL_PTR
};

/*! System configuration data. */
CONST(Os_SystemConfigType, OS_CONST) OsCfg_System =
{
  /* .VersionInfo      = */
  {
    /* .vendorID         = */ OS_VENDOR_ID,
    /* .moduleID         = */ OS_MODULE_ID,
    /* .sw_major_version = */ OS_SW_MAJOR_VERSION,
    /* .sw_minor_version = */ OS_SW_MINOR_VERSION,
    /* .sw_patch_version = */ OS_SW_PATCH_VERSION
  },
  /* .NumberOfAsrCores = */ OS_COREASRCOREIDX_COUNT,
  /* .SpinlockRefs     = */ OsCfg_SystemSpinlockRefs,
  /* .SpinlockCount    = */ (Os_ObjIdxType)OS_CFG_NUM_SYSTEM_SPINLOCKS,
  /* .HwConfig         = */ &OsCfg_Hal_System,
  /* .MemoryProtection = */ NULL_PTR,
  /* .InterruptSourceRefs  = */ OsCfg_Hal_System_InterruptSourceRefs,
  /* .InterruptSourceCount = */ (Os_ObjIdxType)OS_CFG_NUM_SYSTEM_INTERRUPTSOURCEREFS,
  /* .Core2Thread      = */ &OsCfg_Hal_Core2Thread
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
 *  END OF FILE: Os_Core_Lcfg.c
 *********************************************************************************************************************/

