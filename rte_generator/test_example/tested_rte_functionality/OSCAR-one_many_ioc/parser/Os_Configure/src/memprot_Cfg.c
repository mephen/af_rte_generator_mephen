#include "typedefine.h"
#include "application_Cfg.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "memprot.h"
#include "task_Cfg.h"

#pragma section

OsPeriAreaInfoType OsPeriAreaInfoArr[OsPeriAreaID_COUNT] = {
};

/* core0 */
extern uint8 StackTaskIdleTask_core0[StackTaskIdleTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskSysTask_core0[StackTaskSysTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];


/* core1 */
extern uint8 StackTaskIdleTask_core1[StackTaskIdleTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskSysTask_core1[StackTaskSysTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];


/* The first 3 Memory protection register is same forever */
MemProtAreaType MemProtArea_OS[3] = {
    /* Area 0, kernel text */
    {
        (uint32)(0),
        (uint32)(_ERETENTION_RAM_text),
        0 | MPAT_E | MPAT_G | MPAT_SX | MPAT_SR | MPAT_UX | MPAT_UR
    },
    /* Area 1, All const */
    {
        (uint32)(_S_const),
        (uint32)(_EGLOBAL_RAM_B_const),
        0 | MPAT_E | MPAT_G | MPAT_SR | MPAT_UR
    },
    /* Area 2, Shared library  */
    {
        (uint32)(_SUSER_SHARED_SEC_bss),
        (uint32)(_EUSER_SHARED_SEC_data_R),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};
/* Stack area */
MemProtAreaType MemStackArea[2] = {
    {
        (_SALL_TASK_ISR_STACK_PE1_bss),
        (_EALL_TASK_ISR_STACK_PE1_bss),
        0,
    },
    {
        (_SALL_TASK_ISR_STACK_PE2_bss),
        (_EALL_TASK_ISR_STACK_PE2_bss),
        0,
    },
};
MemProtAreaType MemProtArea_SysTask_core0[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_SysTask_core0_bss), //S_bss
        (uint32)(_ETASK_SysTask_core0_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskSysTask_core0),
        (uint32)(StackTaskSysTask_core0 + StackTaskSysTask_core0_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};
MemProtAreaType MemProtArea_SysTask_core1[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_SysTask_core1_bss), //S_bss
        (uint32)(_ETASK_SysTask_core1_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskSysTask_core1),
        (uint32)(StackTaskSysTask_core1 + StackTaskSysTask_core1_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};
/* All Task Memory protection section bound and setting */
/* All dummy data here */
/* The purpose of Dummy data is to remind the OS to generate a section tag */

#pragma section 
const int dummy__const;
int dummy__data = 1;
int dummy__bss;
void dummy__func(){;};

#pragma section IOC_RESERVED_SEC
const int dummy_IOC_RESERVED_SEC_const;
int dummy_IOC_RESERVED_SEC_data = 1;
int dummy_IOC_RESERVED_SEC_bss;
void dummy_IOC_RESERVED_SEC_func(){;};

#pragma section USER_SHARED_SEC
const int dummy_USER_SHARED_SEC_const;
int dummy_USER_SHARED_SEC_data = 1;
int dummy_USER_SHARED_SEC_bss;
void dummy_USER_SHARED_SEC_func(){;};

#pragma section LOCAL_RAM_PE1
const int dummy_LOCAL_RAM_PE1_const;
int dummy_LOCAL_RAM_PE1_data = 1;
int dummy_LOCAL_RAM_PE1_bss;
void dummy_LOCAL_RAM_PE1_func(){;};

#pragma section LOCAL_RAM_PE2
const int dummy_LOCAL_RAM_PE2_const;
int dummy_LOCAL_RAM_PE2_data = 1;
int dummy_LOCAL_RAM_PE2_bss;
void dummy_LOCAL_RAM_PE2_func(){;};

#pragma section SELF_AREA
const int dummy_SELF_AREA_const;
int dummy_SELF_AREA_data = 1;
int dummy_SELF_AREA_bss;
void dummy_SELF_AREA_func(){;};

#pragma section RETENTION_RAM
const int dummy_RETENTION_RAM_const;
int dummy_RETENTION_RAM_data = 1;
int dummy_RETENTION_RAM_bss;
void dummy_RETENTION_RAM_func(){;};

#pragma section GLOBAL_RAM_B
const int dummy_GLOBAL_RAM_B_const;
int dummy_GLOBAL_RAM_B_data = 1;
int dummy_GLOBAL_RAM_B_bss;
void dummy_GLOBAL_RAM_B_func(){;};

#pragma section GLOBAL_RAM_A
const int dummy_GLOBAL_RAM_A_const;
int dummy_GLOBAL_RAM_A_data = 1;
int dummy_GLOBAL_RAM_A_bss;
void dummy_GLOBAL_RAM_A_func(){;};

#pragma section TASK_SysTask_core0
const int dummy_TASK_SysTask_core0_const;
int dummy_TASK_SysTask_core0_data = 1;
int dummy_TASK_SysTask_core0_bss;
void dummy_TASK_SysTask_core0_func(){;};

#pragma section TASK_SysTask_core1
const int dummy_TASK_SysTask_core1_const;
int dummy_TASK_SysTask_core1_data = 1;
int dummy_TASK_SysTask_core1_bss;
void dummy_TASK_SysTask_core1_func(){;};

#pragma section
