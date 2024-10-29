/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009, 2015 Mariano Cerdeiro
 * Copyright 2014, ACSE & CADIEEL
 *      ACSE: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *      CADIEEL: http://www.cadieel.org.ar
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef OS_CFG_H
#define OS_CFG_H

/* This file content the generated configuration of os */

/*==================[inclusions]=============================================*/
#include "typedefine.h"
#define MAX_TF_NESTED_CALL 10
/*==================[macros]=================================================*/
/* Brief ERROR_CHECKING_STANDARD */
#define ERROR_CHECKING_STANDARD   1
/* Brief ERROR_CHECKING_EXTENDED */
#define ERROR_CHECKING_EXTENDED   2

/* Brief Error Checking Type */
#define ERROR_CHECKING_TYPE ERROR_CHECKING_EXTENDED
/* Brief pre task hook enable-disable macro */
#define HOOK_ENABLE_PRETASKHOOK DISABLE
/* Brief post task hook enable-disable macro */
#define HOOK_ENABLE_POSTTASKHOOK DISABLE
/* Brief error hook enable-disable macro */
#define HOOK_ENABLE_ERRORHOOK ENABLE
/* Brief startup hook enable-disable macro */
#define HOOK_ENABLE_STARTUPHOOK ENABLE
/* Brief shutdown hook enable-disable macro */
#define HOOK_ENABLE_SHUTDOWNHOOK ENABLE
/* Brief shutdown hook enable-disable macro */
#define HOOK_ENABLE_PROTECTIONHOOK ENABLE

/* Brief shutdown hook enable-disable macro */
/* Brief application error hook enable-disable macro */
#define HOOK_ENABLE_OSAPP_ERRORHOOK ENABLE
/* Brief application startup hook enable-disable macro */
#define HOOK_ENABLE_OSAPP_STARTUPHOOK ENABLE
/* Brief application shutdown hook enable-disable macro */
#define HOOK_ENABLE_OSAPP_SHUTDOWNHOOK ENABLE

/* Brief USE_RES_SCHEDULER macro definition */
#define USE_RES_SCHEDULER DISABLE

/* define whether to use software stack monitoring */
#define ENABLE_SOFTWARE_STACK_MONITOR DISABLE

/* define whether interrupt source will be auto enabled when AllowAccess() is called */
#define ALLOWACCESS_AUTO_ENABLE_ALL_ISR_IN_OSAPP DISABLE

/* define whether interrupt source will be auto enabled when AllowAccess() is called */
#define ENABLE_SYSTEM_ERROR_HOOK_IN_TIMER_INT DISABLE

/* Brief Definition of the Application Mode */
#define DONOTCARE   0
#define AppMode1    1

/* Brief Core Definition */
/* The core id starts from 0 */
#define OS_CORE_ID_0        0
#define OS_CORE_ID_1        1
#define OS_CORE_ID_MASTER   OS_CORE_ID_0

#define OS_CORE_ID_INVALID  2

/* Define of SysTaskActionQueue length */
#define SysTaskActionQueueLength 20
#define PSWKERNELMODE 0
#define PSWUSERMODE 0x40000000


/* Brief ECUC_PARTITION Definition */
/* record in ApplicationVarType, Not use in current autosar os 20221007 */
#define ECUC_PARTITION_DEFAULT_ID 0
#define ECUC_PARTITION_1_ID 1
#define ECUC_PARTITION_2_ID 2
#define ECUC_PARTITION_3_ID 3
#define ECUC_PARTITION_4_ID 4

/* The maximum number of core */
#define TotalNumberOfCores  ((uint16)2)
#define OsNumberOfCores     ((uint16)2)

#define EcucPartitionSettingNum ((uint16)1)

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/


extern SimuEcucPartitionSettingType EcucPartitionSettingArr[EcucPartitionSettingNum];

extern SystemVarType SystemVar_core0;

extern SystemObjectsType SystemObjects_core0;

extern CurrentTaskType CurrentTask_core0;

extern SystemReadyListType SystemReadyList_core0;

extern SystemVarType SystemVar_core1;

extern SystemObjectsType SystemObjects_core1;

extern CurrentTaskType CurrentTask_core1;

extern SystemReadyListType SystemReadyList_core1;

extern SystemVarRefType SystemVar[OsNumberOfCores];

extern SystemObjectsRefType SystemObjects[OsNumberOfCores];

extern SystemObjectAutosarRefType SystemObjectAutosar[OsNumberOfCores];

extern CurrentTaskRefType CurrentTask[OsNumberOfCores];

extern ApplicationType ExecutingApp[OsNumberOfCores];

extern SystemReadyListRefType SystemReadyList[OsNumberOfCores];

extern CoreIdType CoreIdPhyToLogArray[TotalNumberOfCores];

extern CoreStatusType CoreStatus[TotalNumberOfCores];

extern uint16 NumberOfActivatedCore;

extern uint8 TasksCountArray[OsNumberOfCores];
extern uint8 Isr2TaskCountArray[TotalNumberOfCores];
extern uint8 TasksObjectCountArray[OsNumberOfCores];
extern uint8 IsrCountArray[OsNumberOfCores];

extern AppModeType AppModeArray[TotalNumberOfCores];

extern uint8 CoreIntFlag[OsNumberOfCores];
extern LockType CoreParaLock[OsNumberOfCores];
extern ServiceParaType CrossCoreServicePara[OsNumberOfCores];

extern uint8 app_start_up_hook_err_flag[OsNumberOfCores];
extern uint8 app_shut_down_hook_err_flag[OsNumberOfCores];

extern uint32 CurrentExecServiceID[OsNumberOfCores];              /* used for info in error-hook */
extern ServiceParaType DebugServicePara[OsNumberOfCores];         /* used for info in error-hook */

#define MAX_STACK_FOR_NESTED_TF_CALL 8
extern ApplicationRefType TF_NestedOwnerArray[OsNumberOfCores];

extern AppsInCoreType SystemAppsInCore[OsNumberOfCores];

extern IdleModeType NowIdleMode[OsNumberOfCores];
extern IdleModeType NextIdleMode[OsNumberOfCores];
extern LockType lockForIdleMode[OsNumberOfCores];



/* SysTask */
extern TaskType beforeSysTask[OsNumberOfCores]; 
extern SysTaskInformationType SysTaskAction_core0[SysTaskActionQueueLength];
extern SysTaskInformationType SysTaskAction_core1[SysTaskActionQueueLength];
extern SysTaskActionQueueType *SysTaskActionQueue[OsNumberOfCores];

extern SysTaskInformationType* const CurrentAction[OsNumberOfCores];
extern SysTaskInformationType CurrentAction_core0;
extern SysTaskInformationType CurrentAction_core1;

extern const uint32 TempConst;

/*==================[external functions declaration]=========================*/
/* Brief ErrorHook */
extern void ErrorHook(StatusType Error);


/*==================[end of file]============================================*/
#endif /* #ifndef OS_CFG_H */

