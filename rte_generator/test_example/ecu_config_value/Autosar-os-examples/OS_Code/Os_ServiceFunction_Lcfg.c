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
 *              File: Os_ServiceFunction_Lcfg.c
 *   Generation Time: 2022-07-26 16:44:53
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_SERVICEFUNCTION_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_ServiceFunction_Cfg.h"
#include "Os_ServiceFunction_Lcfg.h"
#include "Os_ServiceFunction.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Common_Types.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os.h"

/* Os externals dependencies */
#include "Platform_Types.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* User file includes */


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

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for trusted functions. */
CONSTP2CONST(Os_ServiceTfConfigType, OS_CONST, OS_CONST)
  OsCfg_TrustedFunctionRefs[OS_TRUSTEDFUNCTIONID_COUNT + 1] =                                /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule10.1_4521 */
{
  NULL_PTR
};

/*! Object reference table for non-trusted functions. */
CONSTP2CONST(Os_ServiceNtfConfigType, OS_CONST, OS_CONST)
  OsCfg_NonTrustedFunctionRefs[OS_NONTRUSTEDFUNCTIONID_COUNT + 1] =                            /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule10.1_4521 */
{
  NULL_PTR
};

/*! Object reference table for fast trusted functions. */
CONSTP2CONST(Os_ServiceFtfConfigType, OS_CONST, OS_CONST)
  OsCfg_FastTrustedFunctionRefs[OS_FASTTRUSTEDFUNCTIONID_COUNT + 1] =                            /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule10.1_4521 */
{
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  END OF FILE: Os_ServiceFunction_Lcfg.c
 *********************************************************************************************************************/
