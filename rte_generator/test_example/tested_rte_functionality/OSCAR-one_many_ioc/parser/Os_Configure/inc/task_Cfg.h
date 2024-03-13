#ifndef TASK_CFG_H
#define TASK_CFG_H

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
#define EXTENDED_TASKS_COUNT_CORE0 4U
#define EXTENDED_TASKS_COUNT_CORE1 2U
#define TASKS_COUNT 6U
/* Brief Count of ISR2 task */
#define ISR2_TASKS_COUNT_CORE0 2U
#define ISR2_TASKS_COUNT_CORE1 2U
#define ISR2_TASKS_COUNT 4U
/* Brief Count of task object*/
/* Idle task, sys task, basic task, extended task, ISR2 task have task object*/
#define TASK_OBJECTS_COUNT_CORE0 10U
#define TASK_OBJECTS_COUNT_CORE1 10U
#define TASK_OBJECTS_COUNT 20U
/* core0 */
#define IdleTask_core0  0x00000000
#define T01             0x00000001
#define T02             0x00000002
#define T03             0x00000003
#define T04             0x00000004
#define T05             0x00000005
#define T06             0x00000006
#define SysTask_core0   0x00000007

/* core1 */
#define IdleTask_core1  0x00010000
#define T11             0x00010001
#define T12             0x00010002
#define T13             0x00010003
#define T14             0x00010004
#define T15             0x00010005
#define T16             0x00010006
#define SysTask_core1   0x00010007

#define INVALID_TASK_ID 0X00020000

#define StackTaskIdleTask_core0_SIZE 512
#define StackTaskSysTask_core0_SIZE 512
#define StackTaskT01_SIZE 512
#define StackTaskT02_SIZE 512
#define StackTaskT03_SIZE 512
#define StackTaskT04_SIZE 512
#define StackTaskT05_SIZE 512
#define StackTaskT06_SIZE 512
#define StackIsr2TaskI005_SIZE 512
#define StackIsr2TaskI006_SIZE 512


#define StackTaskIdleTask_core1_SIZE 512
#define StackTaskSysTask_core1_SIZE 512
#define StackTaskT11_SIZE 512
#define StackTaskT12_SIZE 512
#define StackTaskT13_SIZE 512
#define StackTaskT14_SIZE 512
#define StackTaskT15_SIZE 512
#define StackTaskT16_SIZE 512
#define StackIsr2TaskI105_SIZE 512
#define StackIsr2TaskI106_SIZE 512


#define task_static_prio_idle_core0 0
#define task_static_prio_T01 2
#define task_static_prio_T02 3
#define task_static_prio_T03 1
#define task_static_prio_T04 4
#define task_static_prio_T05 5
#define task_static_prio_T06 2
#define task_static_prio_I005 6
#define task_static_prio_I006 7
#define task_static_prio_sys_core0 8

#define task_static_prio_idle_core1 0
#define task_static_prio_T11 2
#define task_static_prio_T12 1
#define task_static_prio_T13 3
#define task_static_prio_T14 2
#define task_static_prio_T15 1
#define task_static_prio_T16 3
#define task_static_prio_I105 5
#define task_static_prio_I106 4
#define task_static_prio_sys_core1 6
/* Brief Count of priority */
#define NORMAL_TASK_PRIO_COUNT_CORE0 6  
#define NORMAL_TASK_PRIO_COUNT_CORE1 4  
#define ISR2_TASK_PRIO_COUNT_CORE0 2  
#define ISR2_TASK_PRIO_COUNT_CORE1 2  
/* Brief Count of all priority numbers, including idle and systask, so will "+1" */
#define READYLISTS_COUNT_CORE0 (NORMAL_TASK_PRIO_COUNT_CORE0 + ISR2_TASK_PRIO_COUNT_CORE0 +1)
#define READYLISTS_COUNT_CORE1 (NORMAL_TASK_PRIO_COUNT_CORE1 + ISR2_TASK_PRIO_COUNT_CORE1 +1)
/* brief TASK_AUTOSTART_COUNT define */ //how many mode
#define TASK_AUTOSTART_AppMode1_COUNT 1
#define TASK_AUTOSTART_AppMode2_COUNT 1
/*==================[external data declaration]==============================*/
extern const TaskConstType TaskConst_core0[TASK_OBJECTS_COUNT_CORE0];
extern const TaskConstType TaskConst_core1[TASK_OBJECTS_COUNT_CORE1];

extern TaskVarType TaskVar_core0[TASK_OBJECTS_COUNT_CORE0];
extern TaskVarType TaskVar_core1[TASK_OBJECTS_COUNT_CORE1];

/* Brief Accessible App of Task */
extern TaskAutosarType TaskAutosar_core0[TASK_OBJECTS_COUNT_CORE0];
extern TaskAutosarType TaskAutosar_core1[TASK_OBJECTS_COUNT_CORE1];

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
