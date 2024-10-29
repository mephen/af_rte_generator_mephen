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
 *              File: Os_Resource_Lcfg.c
 *   Generation Time: 2022-10-20 14:50:26
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_RESOURCE_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Resource_Lcfg.h"
#include "Os_Resource.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"

/* Os hal dependencies */
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

/*! Dynamic resource data: OsResourceEcuM */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_OsResourceEcuM_Dyn;

/*! Dynamic resource data: Rte_Res_CddDebugInfo_EACddDbgInfoBuffer */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddDebugInfo_EACddDbgInfoBuffer_Dyn;

/*! Dynamic resource data: Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager_Dyn;

/*! Dynamic resource data: Rte_Res_CddHWRNXPRT1171_EACddHwrCom */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCom_Dyn;

/*! Dynamic resource data: Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue_Dyn;

/*! Dynamic resource data: Rte_Res_CddHWRNXPRT1171_EACddHwrModes */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrModes_Dyn;

/*! Dynamic resource data: Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring_Dyn;

/*! Dynamic resource data: Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl_Dyn;

/*! Dynamic resource data: Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess_Dyn;

/*! Dynamic resource data: Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess_Dyn;

/*! Dynamic resource data: Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer_Dyn;

/*! Dynamic resource data: Rte_Res_CddTouchCypressGen7_EACddTouchMode */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchMode_Dyn;

/*! Dynamic resource data: Rte_Res_CddTouchCypressGen7_EACddTouchTrigger */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchTrigger_Dyn;

/*! Dynamic resource data: Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics_Dyn;

/*! Dynamic resource data: Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess_Dyn;

/*! Dynamic resource data: Rte_Res_SwcDimming_EASwcDimDiagnostics */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_SwcDimming_EASwcDimDiagnostics_Dyn;

/*! Dynamic resource data: Rte_Res_SwcError_EASwcErrorCounters */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_SwcError_EASwcErrorCounters_Dyn;

/*! Dynamic resource data: Rte_Res_SwcHWR_EASwcHWRCharDataBuffer */
OS_LOCAL VAR(Os_ResourceType, OS_VAR_NOINIT) OsCfg_Resource_Rte_Res_SwcHWR_EASwcHWRCharDataBuffer_Dyn;

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


/*! Resource configuration data: OsResourceEcuM */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_OsResourceEcuM =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_OsResourceEcuM_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ OsResourceEcuM,
  /* .CeilingPriority = */ 6
};


/*! Resource configuration data: Rte_Res_CddDebugInfo_EACddDbgInfoBuffer */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddDebugInfo_EACddDbgInfoBuffer =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddDebugInfo_EACddDbgInfoBuffer_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddDebugInfo_EACddDbgInfoBuffer,
  /* .CeilingPriority = */ 2
};


/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager,
  /* .CeilingPriority = */ 3
};


/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrCom */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCom =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCom_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddHWRNXPRT1171_EACddHwrCom,
  /* .CeilingPriority = */ 3
};


/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue,
  /* .CeilingPriority = */ 3
};


/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrModes */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrModes =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrModes_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddHWRNXPRT1171_EACddHwrModes,
  /* .CeilingPriority = */ 3
};


/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring,
  /* .CeilingPriority = */ 3
};


/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl,
  /* .CeilingPriority = */ 3
};


/*! Resource configuration data: Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess,
  /* .CeilingPriority = */ 3
};


/*! Resource configuration data: Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess,
  /* .CeilingPriority = */ 6
};


/*! Resource configuration data: Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer,
  /* .CeilingPriority = */ 6
};


/*! Resource configuration data: Rte_Res_CddTouchCypressGen7_EACddTouchMode */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchMode =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchMode_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddTouchCypressGen7_EACddTouchMode,
  /* .CeilingPriority = */ 6
};


/*! Resource configuration data: Rte_Res_CddTouchCypressGen7_EACddTouchTrigger */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchTrigger =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchTrigger_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddTouchCypressGen7_EACddTouchTrigger,
  /* .CeilingPriority = */ 5
};


/*! Resource configuration data: Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics,
  /* .CeilingPriority = */ 6
};


/*! Resource configuration data: Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess,
  /* .CeilingPriority = */ 2
};


/*! Resource configuration data: Rte_Res_SwcDimming_EASwcDimDiagnostics */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_SwcDimming_EASwcDimDiagnostics =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_SwcDimming_EASwcDimDiagnostics_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_SwcDimming_EASwcDimDiagnostics,
  /* .CeilingPriority = */ 6
};


/*! Resource configuration data: Rte_Res_SwcError_EASwcErrorCounters */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_SwcError_EASwcErrorCounters =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_SwcError_EASwcErrorCounters_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_SwcError_EASwcErrorCounters,
  /* .CeilingPriority = */ 2
};


/*! Resource configuration data: Rte_Res_SwcHWR_EASwcHWRCharDataBuffer */
CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_SwcHWR_EASwcHWRCharDataBuffer =
{
  /* .Lock            = */
  {
    /* .Dyn                   = */ OS_RESOURCE_CASTDYN_RESOURCE_2_LOCK(OsCfg_Resource_Rte_Res_SwcHWR_EASwcHWRCharDataBuffer_Dyn),
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
    /* .Type                  = */ OS_LOCKTYPE_RESOURCE_STANDARD
  },
  /* .Core            = */ &OsCfg_Core_OsCore0,
  /* .ResourceId      = */ Rte_Res_SwcHWR_EASwcHWRCharDataBuffer,
  /* .CeilingPriority = */ 3
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for resources. */
CONSTP2CONST(Os_ResourceConfigType, OS_CONST, OS_CONST) OsCfg_ResourceRefs[OS_RESOURCEID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
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
 *  END OF FILE: Os_Resource_Lcfg.c
 *********************************************************************************************************************/
