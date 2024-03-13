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
 *              File: Os_Scheduler_Lcfg.c
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_SCHEDULER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Scheduler_Cfg.h"
#include "Os_Scheduler_Lcfg.h"
#include "Os_Scheduler.h"

/* Os kernel module dependencies */
#include "Os_BitArray.h"
#include "Os_Common.h"
#include "Os_Deque.h"

/* Os hal dependencies */


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

/*! Dynamic scheduler data: OsCore0 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore0_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore0_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore0_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore0 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue7_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes7_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE7_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue8_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes8_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE8_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue9_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes9_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE9_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue10_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes10_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE10_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue11_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes11_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE11_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue12_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes12_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE12_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue13_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes13_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE13_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue14_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes14_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE14_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue15_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes15_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE15_OSCORE0_SLOTS];

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

/*! Task queues configuration data: OsCore0 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore0_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue0_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes0_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE0_OSCORE0_SLOTS
  },
  /* [1] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue1_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes1_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE1_OSCORE0_SLOTS
  },
  /* [2] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue2_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes2_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE2_OSCORE0_SLOTS
  },
  /* [3] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue3_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes3_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE3_OSCORE0_SLOTS
  },
  /* [4] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue4_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes4_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE4_OSCORE0_SLOTS
  },
  /* [5] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue5_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes5_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE5_OSCORE0_SLOTS
  },
  /* [6] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue6_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes6_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE6_OSCORE0_SLOTS
  },
  /* [7] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue7_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes7_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE7_OSCORE0_SLOTS
  },
  /* [8] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue8_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes8_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE8_OSCORE0_SLOTS
  },
  /* [9] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue9_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes9_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE9_OSCORE0_SLOTS
  },
  /* [10] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue10_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes10_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE10_OSCORE0_SLOTS
  },
  /* [11] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue11_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes11_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE11_OSCORE0_SLOTS
  },
  /* [12] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue12_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes12_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE12_OSCORE0_SLOTS
  },
  /* [13] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue13_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes13_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE13_OSCORE0_SLOTS
  },
  /* [14] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue14_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes14_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE14_OSCORE0_SLOTS
  },
  /* [15] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue15_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes15_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE15_OSCORE0_SLOTS
  }
};

/*! Scheduler configuration data: OsCore0 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore0 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore0_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore0_BitField_Dyn,
    /* .Size      = */ (uint16)OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ (uint16)OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore0_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore0_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_Scheduler_Lcfg.c
 *********************************************************************************************************************/
