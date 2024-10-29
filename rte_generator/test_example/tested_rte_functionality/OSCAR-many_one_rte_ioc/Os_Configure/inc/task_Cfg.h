/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009 Mariano Cerdeiro
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

#ifndef TASK_CFG_H
#define TASK_CFG_H

/* This file content the generated configuration of task */

/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "memprot.h"
#include "resource_Cfg.h"
#include "os_Cfg.h"
#include "isr_Cfg.h"
/*==================[macros]=================================================*/

/* Brief Count of all task(include extended task) */
/* The count includes basic/extended tasks and "1 idle" task, "1 sys" task (no isr2 task)*/
#define TASKS_COUNT_CORE0 8U
#define TASKS_COUNT_CORE1 8U
#define TASKS_COUNT 16U
/* Brief Count of extended task */
#define EXTENDED_TASKS_COUNT_CORE0 5U
#define EXTENDED_TASKS_COUNT_CORE1 2U
#define EXTENDED_TASKS_COUNT 7U
/* Brief Count of ISR2 task */
#define ISR2_TASKS_COUNT_CORE0 4U
#define ISR2_TASKS_COUNT_CORE1 4U
#define ISR2_TASKS_COUNT 8U
/* Brief Count of task object*/
/* Idle task, sys task, basic task, extended task, ISR2 task have task object*/
#define TASK_OBJECTS_COUNT_CORE0 12U
#define TASK_OBJECTS_COUNT_CORE1 12U
#define TASK_OBJECTS_COUNT 24U

/* Brief Task Definition */
/* 小心，不要讓命名中 有部分 是其他人名字的全部 */
/* 例如，不要有一個叫 T01 , 另一個叫 RST011 */
/* 因為 RST011 中間的 RS"T01"1 可能會不小心被 T01 的定義換掉 */
/* core0 */
#define IdleTask_core0  0x00000000
#define T01             0x00000001
#define T02             0x00000002
#define T04             0x00000003
#define T05             0x00000004
#define T03             0x00000005
#define T06             0x00000006
#define SysTask_core0  0x0000000B

/* core1 */
#define IdleTask_core1  0x00010000
#define T11             0x00010001
#define T14             0x00010002
#define T12             0x00010003
#define T13             0x00010004
#define T15             0x00010005
#define T16             0x00010006
#define SysTask_core1  0x0000000B

#define INVALID_TASK_ID    0X00020010     

#define StackTaskIdleTask_core0_SIZE 512
#define StackTaskSysTask_core0_SIZE 512
#define StackTaskT01_SIZE 512
#define StackTaskT02_SIZE 512
#define StackTaskT03_SIZE 512
#define StackTaskT04_SIZE 512
#define StackTaskT05_SIZE 512
#define StackTaskT06_SIZE 512
//#define StackTaskRST07_SIZE 512
//#define StackTaskRST08_SIZE 512
#define StackIsr2TaskI002_SIZE 512
#define StackIsr2TaskI003_SIZE 512
#define StackIsr2TaskI005_SIZE 512
#define StackIsr2TaskI006_SIZE 512
#define StackTaskSysTask_core0_SIZE 512

#define StackTaskIdleTask_core1_SIZE 512
#define StackTaskSysTask_core1_SIZE 512
#define StackTaskT11_SIZE 512
#define StackTaskT12_SIZE 512
#define StackTaskT13_SIZE 512
#define StackTaskT14_SIZE 512
#define StackTaskT15_SIZE 512
#define StackTaskT16_SIZE 512
//#define StackTaskRST17_SIZE 512
//#define StackTaskRST18_SIZE 512
#define StackIsr2TaskI102_SIZE 512
#define StackIsr2TaskI103_SIZE 512
#define StackIsr2TaskI105_SIZE 512
#define StackIsr2TaskI106_SIZE 512
#define StackTaskSysTask_core1_SIZE 512

#define task_static_prio_idle_core0 0
#define task_static_prio_T01 2
#define task_static_prio_T02 2
#define task_static_prio_T04 3
#define task_static_prio_T05 2
#define task_static_prio_T03 2
#define task_static_prio_T06 1
// #define task_static_prio_RST07 3
// #define task_static_prio_RST08 3
#define task_static_prio_I002 7     //isr2Tasks prio is based on normal tasks
#define task_static_prio_I003 6     //and interrupt setting
#define task_static_prio_I005 5
#define task_static_prio_I006 4
#define task_static_prio_sys_core0 8  //sysTasks prio is based on all tasks/isr2-task

#define task_static_prio_idle_core1 0
#define task_static_prio_T11 3
#define task_static_prio_T14 2
#define task_static_prio_T12 2
#define task_static_prio_T13 3
#define task_static_prio_T15 1
#define task_static_prio_T16 3
// #define task_static_prio_RST17 3
// #define task_static_prio_RST18 3
#define task_static_prio_I102 7     //isr2Tasks prio is based on normal tasks
#define task_static_prio_I103 6     //and interrupt setting
#define task_static_prio_I105 5
#define task_static_prio_I106 4
#define task_static_prio_sys_core1 8  //sysTasks prio is based on all tasks/isr2-task

/* Brief Count of priority */
#define NORMAL_TASK_PRIO_COUNT_CORE0 4  //include idle task, in the case above, it's 0,1,2,3
#define NORMAL_TASK_PRIO_COUNT_CORE1 4
#define ISR2_TASK_PRIO_COUNT_CORE0 4    //only ISR2 , in the case above, it's 4,5,6,7
#define ISR2_TASK_PRIO_COUNT_CORE1 4

/* Brief Count of all priority numbers, including idle and systask, so will "+1" */   
#define READYLISTS_COUNT_CORE0 (NORMAL_TASK_PRIO_COUNT_CORE0 + ISR2_TASK_PRIO_COUNT_CORE0 +1)
#define READYLISTS_COUNT_CORE1 (NORMAL_TASK_PRIO_COUNT_CORE1 + ISR2_TASK_PRIO_COUNT_CORE1 +1)

/* Brief NON_PREEMPTIVE macro definition */
#define NON_PREEMPTIVE OSEK_DISABLE

/* brief TASK_AUTOSTART_COUNT define */ //how many mode
#define TASK_AUTOSTART_APPMODE1_COUNT 2

/*==================[external data declaration]==============================*/
/*
    Brief Tasks Constants

    Contents all constant and constant pointer needed to
    manage all FreeOSEK tasks
*/
extern const TaskConstType TaskConst_core0[TASK_OBJECTS_COUNT_CORE0];
extern const TaskConstType TaskConst_core1[TASK_OBJECTS_COUNT_CORE1];
//extern const TaskConstType *TaskConst[TASK_OBJECTS_COUNT];

/*
    Brief Tasks Variable

    Contents all variables needed to manage all FreeOSEK tasks
*/
extern TaskVarType TaskVar_core0[TASK_OBJECTS_COUNT_CORE0];
extern TaskVarType TaskVar_core1[TASK_OBJECTS_COUNT_CORE1];
//extern TaskVarType *TaskVar[TASK_OBJECTS_COUNT];

/* Brief Accessible App of Task */
extern TaskAutosarType TaskAutosar_core0[TASK_OBJECTS_COUNT_CORE0];
extern TaskAutosarType TaskAutosar_core1[TASK_OBJECTS_COUNT_CORE1];

/*
    Brief Application Mode

    This variable contents the actual running application mode
*/
extern uint8 ApplicationMode;

/* Brief AutoStart Array */
extern const AutoStartType AutoStart[1];

/* Brief Ready List */
extern TaskVarType *ReadyList_core0[READYLISTS_COUNT_CORE0];
extern TaskVarType *ReadyList_core1[READYLISTS_COUNT_CORE1];

/* Brief Ready List Tail */
/* In order to prevent linear search in AddReady */
extern TaskVarType *ReadyListTail_core0[READYLISTS_COUNT_CORE0];
extern TaskVarType *ReadyListTail_core1[READYLISTS_COUNT_CORE1];


extern TaskType SysTaskID[OsNumberOfCores];

/*==================[external functions declaration]=========================*/
/* Brief Task Declaration of Task IdleTask */
TASK(IdleTask);
TASK(SysTask);
TASK(SysTask_core0);
TASK(SysTask_core1);

/* Brief Task Declaration of Task T01 */
TASK(T01);
/* Brief Task Declaration of Task T02 */
TASK(T02);
/* Brief Task Declaration of Task T03 */
TASK(T03);
/* Brief Task Declaration of Task T04 */
TASK(T04);
/* Brief Task Declaration of Task T05 */
TASK(T05);
/* Brief Task Declaration of Task T06 */
TASK(T06);
/* Brief ISR Declaration of ISR I001 */
ISR(I001);
/* Brief ISR Declaration of ISR I002 */
ISR(I002);
/* Brief ISR Declaration of ISR I003 */
ISR(I003);
/* Brief ISR Declaration of ISR I004 */
ISR(I004);
/* Brief ISR Declaration of ISR I005 */
ISR(I005);
/* Brief ISR Declaration of ISR I006 */
ISR(I006);



/* Brief Task Declaration of Task T11 */
TASK(T11);
/* Brief Task Declaration of Task T12 */
TASK(T12);
/* Brief Task Declaration of Task T13 */
TASK(T13);
/* Brief Task Declaration of Task T14 */
TASK(T14);
/* Brief Task Declaration of Task T15 */
TASK(T15);
/* Brief Task Declaration of Task T16 */
TASK(T16);
/* Brief ISR Declaration of ISR I101 */
ISR(I101);
/* Brief ISR Declaration of ISR I102 */
ISR(I102);
/* Brief ISR Declaration of ISR I103 */
ISR(I103);
/* Brief ISR Declaration of ISR I104 */
ISR(I104);
/* Brief ISR Declaration of ISR I105 */
ISR(I105);
/* Brief ISR Declaration of ISR I106 */
ISR(I106);

/*==================[end of file]============================================*/
#endif /* #ifndef TASK_CFG_H */