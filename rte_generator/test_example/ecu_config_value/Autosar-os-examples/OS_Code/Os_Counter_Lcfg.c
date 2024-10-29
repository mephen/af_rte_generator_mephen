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
 *              File: Os_Counter_Lcfg.c
 *   Generation Time: 2022-07-26 16:44:52
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_COUNTER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Counter_Cfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"

/* Os kernel module dependencies */
#include "Os_Application_Lcfg.h"
#include "Os_Cfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_PriorityQueue.h"
#include "Os_Timer.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Timer_Lcfg.h"


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

/*! Dynamic counter data: OsCounter_10ms */
OS_LOCAL VAR(Os_TimerSwType, OS_VAR_NOINIT) OsCfg_Counter_OsCounter_10ms_Dyn;
OS_LOCAL VAR(Os_PriorityQueueType, OS_VAR_NOINIT) OsCfg_Counter_OsCounter_10ms_JobQueue_Dyn;
OS_LOCAL VAR(Os_PriorityQueueNodeType, OS_VAR_NOINIT)
  OsCfg_Counter_OsCounter_10ms_JobQueueNodes_Dyn[OS_CFG_NUM_COUNTER_OSCOUNTER_10MS_JOBS + 1u];

/*! Dynamic counter data: OsCounter_1ms */
OS_LOCAL VAR(Os_TimerSwType, OS_VAR_NOINIT) OsCfg_Counter_OsCounter_1ms_Dyn;
OS_LOCAL VAR(Os_PriorityQueueType, OS_VAR_NOINIT) OsCfg_Counter_OsCounter_1ms_JobQueue_Dyn;
OS_LOCAL VAR(Os_PriorityQueueNodeType, OS_VAR_NOINIT)
  OsCfg_Counter_OsCounter_1ms_JobQueueNodes_Dyn[OS_CFG_NUM_COUNTER_OSCOUNTER_1MS_JOBS + 1u];

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


/*! Counter configuration data: OsCounter_10ms */
CONST(Os_TimerPitConfigType, OS_CONST) OsCfg_Counter_OsCounter_10ms =
{
  /* .SwCounter = */
  {
  /* .Counter = */
  {
    /* .Characteristics       = */
    {
      /* .MaxAllowedValue      = */ OSMAXALLOWEDVALUE_OsCounter_10ms,
      /* .MaxCountingValue     = */ OS_TIMERPIT_GETMAXCOUNTINGVALUE(OSMAXALLOWEDVALUE_OsCounter_10ms),
      /* .MaxDifferentialValue = */ OS_TIMERPIT_GETMAXDIFFERENTIALVALUE(OSMAXALLOWEDVALUE_OsCounter_10ms),
      /* .MinCycle             = */ OSMINCYCLE_OsCounter_10ms,
      /* .TicksPerBase         = */ OSTICKSPERBASE_OsCounter_10ms
    },
    /* .JobQueue              = */
    {
      /* .Queue     = */ OsCfg_Counter_OsCounter_10ms_JobQueueNodes_Dyn,
      /* .Dyn       = */ &OsCfg_Counter_OsCounter_10ms_JobQueue_Dyn,
      /* .QueueSize = */ (Os_PriorityQueueNodeIdxType)OS_CFG_NUM_COUNTER_OSCOUNTER_10MS_JOBS
    },
    /* .DriverType            = */ OS_TIMERTYPE_PERIODIC_TICK,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  },
  /* .Dyn     = */ &OsCfg_Counter_OsCounter_10ms_Dyn
},
  /* .HwConfig  = */ &OsCfg_Hal_TimerPit_OsCounter_10ms
};


/*! Counter configuration data: OsCounter_1ms */
CONST(Os_TimerPitConfigType, OS_CONST) OsCfg_Counter_OsCounter_1ms =
{
  /* .SwCounter = */
  {
  /* .Counter = */
  {
    /* .Characteristics       = */
    {
      /* .MaxAllowedValue      = */ OSMAXALLOWEDVALUE_OsCounter_1ms,
      /* .MaxCountingValue     = */ OS_TIMERPIT_GETMAXCOUNTINGVALUE(OSMAXALLOWEDVALUE_OsCounter_1ms),
      /* .MaxDifferentialValue = */ OS_TIMERPIT_GETMAXDIFFERENTIALVALUE(OSMAXALLOWEDVALUE_OsCounter_1ms),
      /* .MinCycle             = */ OSMINCYCLE_OsCounter_1ms,
      /* .TicksPerBase         = */ OSTICKSPERBASE_OsCounter_1ms
    },
    /* .JobQueue              = */
    {
      /* .Queue     = */ OsCfg_Counter_OsCounter_1ms_JobQueueNodes_Dyn,
      /* .Dyn       = */ &OsCfg_Counter_OsCounter_1ms_JobQueue_Dyn,
      /* .QueueSize = */ (Os_PriorityQueueNodeIdxType)OS_CFG_NUM_COUNTER_OSCOUNTER_1MS_JOBS
    },
    /* .DriverType            = */ OS_TIMERTYPE_PERIODIC_TICK,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0)  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  },
  /* .Dyn     = */ &OsCfg_Counter_OsCounter_1ms_Dyn
},
  /* .HwConfig  = */ &OsCfg_Hal_TimerPit_OsCounter_1ms
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for counters. */
CONSTP2CONST(Os_CounterConfigType, OS_CONST, OS_CONST) OsCfg_CounterRefs[OS_COUNTERID_COUNT + 1u] =            /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter_10ms),
  OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(OsCfg_Counter_OsCounter_1ms),
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
 *  END OF FILE: Os_Counter_Lcfg.c
 *********************************************************************************************************************/
