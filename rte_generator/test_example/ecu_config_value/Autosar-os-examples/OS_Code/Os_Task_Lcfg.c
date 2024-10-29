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
 *              File: Os_Task_Lcfg.c
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_TASK_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Core.h"
#include "Os_Error.h"
#include "Os_Ioc.h"
#include "Os_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Scheduler_Types.h"
#include "Os_Stack_Lcfg.h"
#include "Os_TaskInt.h"
#include "Os_Thread.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"


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

/*! Dynamic task data: Default_Init_Task */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_Default_Init_Task_Dyn;

/*! Dynamic task data: IO_Task */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_IO_Task_Dyn;

/*! Dynamic task data: IdleTask_OsCore0 */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_IdleTask_OsCore0_Dyn;

/*! Dynamic task data: MyTask */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_MyTask_Dyn;

/*! Dynamic task data: OsTask_ApplInitDeInit */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_ApplInitDeInit_Dyn;

/*! Dynamic task data: OsTask_ApplMainFunctions */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_ApplMainFunctions_Dyn;

/*! Dynamic task data: OsTask_ApplTimedInitDeInit */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_ApplTimedInitDeInit_Dyn;

/*! Dynamic task data: OsTask_ApplVerify */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_ApplVerify_Dyn;

/*! Dynamic task data: OsTask_Background */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_Background_Dyn;

/*! Dynamic task data: OsTask_BswMainFunctions */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_BswMainFunctions_Dyn;

/*! Dynamic task data: OsTask_Communication */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_Communication_Dyn;

/*! Dynamic task data: OsTask_DcmSessionChanges */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_DcmSessionChanges_Dyn;

/*! Dynamic task data: OsTask_Dimming */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_Dimming_Dyn;

/*! Dynamic task data: OsTask_NvmAccess */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_NvmAccess_Dyn;

/*! Dynamic task data: OsTask_SelfDiagnostics */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_SelfDiagnostics_Dyn;

/*! Dynamic task data: OsTask_Touch */
OS_LOCAL VAR(Os_TaskType, OS_VAR_NOINIT) OsCfg_Task_OsTask_Touch_Dyn;

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


/*! Task configuration data: Default_Init_Task */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_Default_Init_Task =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_Default_Init_Task,
    /* .Context               = */ &OsCfg_Hal_Context_Default_Init_Task_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio1001,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_Default_Init_Task_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)0uL,
  /* .TaskId                 = */ Default_Init_Task,
  /* .RunningPriority        = */ (Os_TaskPrioType)0uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OSDEFAULTAPPMODE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: IO_Task */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IO_Task =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IO_Task,
    /* .Context               = */ &OsCfg_Hal_Context_IO_Task_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_IO_Task,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_IO_Task_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)13uL,
  /* .TaskId                 = */ IO_Task,
  /* .RunningPriority        = */ (Os_TaskPrioType)13uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: IdleTask_OsCore0 */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_IdleTask_OsCore0 =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_IdleTask_OsCore0,
    /* .Context               = */ &OsCfg_Hal_Context_IdleTask_OsCore0_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio4294967295,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_IdleTask_OsCore0_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)15uL,
  /* .TaskId                 = */ IdleTask_OsCore0,
  /* .RunningPriority        = */ (Os_TaskPrioType)15uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_ANY,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: MyTask */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_MyTask =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_MyTask,
    /* .Context               = */ &OsCfg_Hal_Context_MyTask_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio13,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_MyTask_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)12uL,
  /* .TaskId                 = */ MyTask,
  /* .RunningPriority        = */ (Os_TaskPrioType)0uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)2uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_ApplInitDeInit */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_ApplInitDeInit =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_ApplInitDeInit,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_ApplInitDeInit_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_ApplInitDeInit,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_ApplInitDeInit_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)11uL,
  /* .TaskId                 = */ OsTask_ApplInitDeInit,
  /* .RunningPriority        = */ (Os_TaskPrioType)11uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_ApplMainFunctions */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_ApplMainFunctions =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_ApplMainFunctions,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_ApplMainFunctions_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_ApplMainFunctions,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_ApplMainFunctions_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)7uL,
  /* .TaskId                 = */ OsTask_ApplMainFunctions,
  /* .RunningPriority        = */ (Os_TaskPrioType)7uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_ApplTimedInitDeInit */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_ApplTimedInitDeInit =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_ApplTimedInitDeInit,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_ApplTimedInitDeInit_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_ApplTimedInitDeInit,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_ApplTimedInitDeInit_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)10uL,
  /* .TaskId                 = */ OsTask_ApplTimedInitDeInit,
  /* .RunningPriority        = */ (Os_TaskPrioType)10uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_ApplVerify */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_ApplVerify =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_ApplVerify,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_ApplVerify_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_ApplVerify,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_ApplVerify_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)9uL,
  /* .TaskId                 = */ OsTask_ApplVerify,
  /* .RunningPriority        = */ (Os_TaskPrioType)9uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_Background */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Background =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_Background,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_Background_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Task_Prio5,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_Background_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)14uL,
  /* .TaskId                 = */ OsTask_Background,
  /* .RunningPriority        = */ (Os_TaskPrioType)14uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)FALSE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_BswMainFunctions */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_BswMainFunctions =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_BswMainFunctions,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_BswMainFunctions_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_BswMainFunctions,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_BswMainFunctions_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)6uL,
  /* .TaskId                 = */ OsTask_BswMainFunctions,
  /* .RunningPriority        = */ (Os_TaskPrioType)6uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_Communication */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Communication =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_Communication,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_Communication_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_Communication,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_Communication_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)4uL,
  /* .TaskId                 = */ OsTask_Communication,
  /* .RunningPriority        = */ (Os_TaskPrioType)4uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_DcmSessionChanges */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_DcmSessionChanges =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_DcmSessionChanges,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_DcmSessionChanges_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_DcmSessionChanges,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_DcmSessionChanges_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)5uL,
  /* .TaskId                 = */ OsTask_DcmSessionChanges,
  /* .RunningPriority        = */ (Os_TaskPrioType)5uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_Dimming */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Dimming =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_Dimming,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_Dimming_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_Dimming,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_Dimming_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)2uL,
  /* .TaskId                 = */ OsTask_Dimming,
  /* .RunningPriority        = */ (Os_TaskPrioType)2uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_NvmAccess */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_NvmAccess =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_NvmAccess,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_NvmAccess_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_NvmAccess,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_NvmAccess_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)1uL,
  /* .TaskId                 = */ OsTask_NvmAccess,
  /* .RunningPriority        = */ (Os_TaskPrioType)1uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_SelfDiagnostics */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_SelfDiagnostics =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_SelfDiagnostics,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_SelfDiagnostics_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_SelfDiagnostics,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_SelfDiagnostics_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)8uL,
  /* .TaskId                 = */ OsTask_SelfDiagnostics,
  /* .RunningPriority        = */ (Os_TaskPrioType)8uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};


/*! Task configuration data: OsTask_Touch */
CONST(Os_TaskConfigType, OS_CONST) OsCfg_Task_OsTask_Touch =
{
  /* .Thread                 = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_OsTask_Touch,
    /* .Context               = */ &OsCfg_Hal_Context_OsTask_Touch_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsTask_Touch,
    /* .Dyn                   = */ OS_TASK_CASTDYN_TASK_2_THREAD(OsCfg_Task_OsTask_Touch_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ NULL_PTR,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_TASK,
    /* .PreThreadHook         = */ &Os_TaskCallPreTaskHook,
    /* .InitDuringStartUp     = */ TRUE,
    /* .UsesFpu               = */ FALSE
  },
  /* .HomePriority           = */ (Os_TaskPrioType)3uL,
  /* .TaskId                 = */ OsTask_Touch,
  /* .RunningPriority        = */ (Os_TaskPrioType)3uL,
  /* .MaxActivations         = */ (Os_ActivationCntType)1uL,
  /* .AutostartModes         = */ OS_APPMODE_NONE,
    /* .AccessingApplications = */ OS_APPID2MASK(SystemApplication_OsCore0),  /* PRQA S 0410 */ /* MD_MSR_Dir1.1 */
  /* .NumSchEventsRoundRobin = */ 0uL,
  /* .RoundRobinEnabled      = */ FALSE,
  /* .IsExtended             = */ (boolean)TRUE,
  /* .StackSharing           = */ OS_TASKSCHEDULE_ALLOWED
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for tasks. */
CONSTP2CONST(Os_TaskConfigType, OS_CONST, OS_CONST) OsCfg_TaskRefs[OS_TASKID_COUNT + 1] =   /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_Default_Init_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IO_Task),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_IdleTask_OsCore0),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_MyTask),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ApplInitDeInit),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ApplMainFunctions),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ApplTimedInitDeInit),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_ApplVerify),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Background),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_BswMainFunctions),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Communication),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_DcmSessionChanges),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Dimming),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_NvmAccess),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_SelfDiagnostics),
  OS_TASK_CASTCONFIG_TASK_2_TASK(OsCfg_Task_OsTask_Touch),
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
 *  END OF FILE: Os_Task_Lcfg.c
 *********************************************************************************************************************/
