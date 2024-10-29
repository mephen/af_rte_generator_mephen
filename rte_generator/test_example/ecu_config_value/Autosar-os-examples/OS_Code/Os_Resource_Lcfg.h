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
 *              File: Os_Resource_Lcfg.h
 *   Generation Time: 2022-10-20 14:50:26
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_RESOURCE_LCFG_H
# define OS_RESOURCE_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Resource_Types.h"

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

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Resource configuration data: OsResourceEcuM */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_OsResourceEcuM;

/*! Resource configuration data: Rte_Res_CddDebugInfo_EACddDbgInfoBuffer */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddDebugInfo_EACddDbgInfoBuffer;

/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCfgManager;

/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrCom */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrCom;

/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrEventQueue;

/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrModes */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrModes;

/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrMonitoring;

/*! Resource configuration data: Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHWRNXPRT1171_EACddHwrRequestCtrl;

/*! Resource configuration data: Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddHeadUnitInterface_EACddHUIfDeviceAccess;

/*! Resource configuration data: Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddPeripheralControl_EACddPerCtrlDiagAccess;

/*! Resource configuration data: Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddSliderBackLightTiSN1903001_EACddSldrBuffer;

/*! Resource configuration data: Rte_Res_CddTouchCypressGen7_EACddTouchMode */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchMode;

/*! Resource configuration data: Rte_Res_CddTouchCypressGen7_EACddTouchTrigger */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddTouchCypressGen7_EACddTouchTrigger;

/*! Resource configuration data: Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_CddWakeupDetect_EACddWUDetDiagnostics;

/*! Resource configuration data: Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_SwcComHandlerTx_EASwcComTxCmdQueueAccess;

/*! Resource configuration data: Rte_Res_SwcDimming_EASwcDimDiagnostics */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_SwcDimming_EASwcDimDiagnostics;

/*! Resource configuration data: Rte_Res_SwcError_EASwcErrorCounters */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_SwcError_EASwcErrorCounters;

/*! Resource configuration data: Rte_Res_SwcHWR_EASwcHWRCharDataBuffer */
extern CONST(Os_ResourceConfigType, OS_CONST) OsCfg_Resource_Rte_Res_SwcHWR_EASwcHWRCharDataBuffer;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for resources. */
extern CONSTP2CONST(Os_ResourceConfigType, OS_CONST, OS_CONST) OsCfg_ResourceRefs[OS_RESOURCEID_COUNT + 1];       /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_RESOURCE_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Resource_Lcfg.h
 *********************************************************************************************************************/
