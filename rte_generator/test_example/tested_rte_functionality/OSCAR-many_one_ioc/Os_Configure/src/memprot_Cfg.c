#include "typedefine.h"
#include "application_Cfg.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "memprot.h"
#include "task_Cfg.h"

#pragma section

//typedef void* MemoryStartAddressType;
//typedef uint32 MemorySizeType;

OsPeriAreaInfoType OsPeriAreaInfoArr[OsPeriAreaID_COUNT] = {

    {
        PERI_COOL_ID,
        (uint32)0,
        (uint32)0,
        0, 
    },

    {
        PERI_WOW_ID,
        (uint32)0,
        (uint32)0,
        0 | (1 << app_lion) | (1 << app2) |  (1 << app3) | (1 << app4),
    },
  
    {
        PERI_HAHA_ID,
        (uint32)0,
        (uint32)0,
        0 | (1 << app_lion) | (1 << app2) |  (1 << app3),
    },
   
    {
        PERI_FUN_ID,
        (uint32)0,
        (uint32)0,
        0 | (1 << app_lion) | (1 << app2),
    },
    
    {
        PERI_TRY_ID,
        (uint32)0,
        (uint32)0,
        0 | (1 << app_lion),
    },
};


/* core 0 */
extern uint8 StackTaskIdleTask_core0[StackTaskIdleTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskSysTask_core0[StackTaskSysTask_core0_SIZE + STACK_MONITOR_APPEND_SIZE];

extern uint8 StackTaskT01[StackTaskT01_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT02[StackTaskT02_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT03[StackTaskT03_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT04[StackTaskT04_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT05[StackTaskT05_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT06[StackTaskT06_SIZE + STACK_MONITOR_APPEND_SIZE];

extern uint8 StackIsr2TaskI002[StackIsr2TaskI002_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackIsr2TaskI003[StackIsr2TaskI003_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackIsr2TaskI005[StackIsr2TaskI005_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackIsr2TaskI006[StackIsr2TaskI006_SIZE + STACK_MONITOR_APPEND_SIZE];

/* core 1 */
extern uint8 StackTaskIdleTask_core1[StackTaskIdleTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskSysTask_core1[StackTaskSysTask_core1_SIZE + STACK_MONITOR_APPEND_SIZE];

extern uint8 StackTaskT11[StackTaskT11_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT12[StackTaskT12_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT13[StackTaskT13_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT14[StackTaskT14_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT15[StackTaskT15_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackTaskT16[StackTaskT16_SIZE + STACK_MONITOR_APPEND_SIZE];

extern uint8 StackIsr2TaskI102[StackIsr2TaskI102_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackIsr2TaskI103[StackIsr2TaskI103_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackIsr2TaskI105[StackIsr2TaskI105_SIZE + STACK_MONITOR_APPEND_SIZE];
extern uint8 StackIsr2TaskI106[StackIsr2TaskI106_SIZE + STACK_MONITOR_APPEND_SIZE];


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
MemProtAreaType MemProtArea_T01[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T001_SEC_bss), //S_bss
        (uint32)(_ETASK_T001_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT01),
        (uint32)(StackTaskT01 + StackTaskT01_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T02[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T002_SEC_bss), //S_bss
        (uint32)(_ETASK_T002_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT02),
        (uint32)(StackTaskT02 + StackTaskT02_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T03[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T003_SEC_bss), //S_bss
        (uint32)(_ETASK_T003_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT03),
        (uint32)(StackTaskT03 + StackTaskT03_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T04[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T004_SEC_bss), //S_bss
        (uint32)(_ETASK_T004_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT04),
        (uint32)(StackTaskT04 + StackTaskT04_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T05[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T005_SEC_bss), //S_bss
        (uint32)(_ETASK_T005_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT05),
        (uint32)(StackTaskT05 + StackTaskT05_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T06[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T006_SEC_bss), //S_bss
        (uint32)(_ETASK_T006_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT06),
        (uint32)(StackTaskT06 + StackTaskT06_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T11[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T101_SEC_bss), //S_bss
        (uint32)(_ETASK_T101_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT11),
        (uint32)(StackTaskT11 + StackTaskT11_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T12[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T102_SEC_bss), //S_bss
        (uint32)(_ETASK_T102_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT12),
        (uint32)(StackTaskT12 + StackTaskT12_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T13[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T103_SEC_bss), //S_bss
        (uint32)(_ETASK_T103_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT13),
        (uint32)(StackTaskT13 + StackTaskT13_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T14[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T104_SEC_bss), //S_bss
        (uint32)(_ETASK_T104_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT14),
        (uint32)(StackTaskT14 + StackTaskT14_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T15[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T105_SEC_bss), //S_bss
        (uint32)(_ETASK_T105_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT15),
        (uint32)(StackTaskT15 + StackTaskT15_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_T16[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_STASK_T106_SEC_bss), //S_bss
        (uint32)(_ETASK_T106_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackTaskT16),
        (uint32)(StackTaskT16 + StackTaskT16_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_I002[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_SISR_I002_SEC_bss), //S_bss
        (uint32)(_EISR_I002_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackIsr2TaskI002),
        (uint32)(StackIsr2TaskI002 + StackIsr2TaskI002_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_I003[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_SISR_I003_SEC_bss), //S_bss
        (uint32)(_EISR_I003_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackIsr2TaskI003),
        (uint32)(StackIsr2TaskI003 + StackIsr2TaskI003_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_I005[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_SISR_I005_SEC_bss), //S_bss
        (uint32)(_EISR_I005_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackIsr2TaskI005),
        (uint32)(StackIsr2TaskI005 + StackIsr2TaskI005_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_I006[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_SISR_I006_SEC_bss), //S_bss
        (uint32)(_EISR_I006_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackIsr2TaskI006),
        (uint32)(StackIsr2TaskI006 + StackIsr2TaskI006_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_I102[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_SISR_I102_SEC_bss), //S_bss
        (uint32)(_EISR_I102_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackIsr2TaskI102),
        (uint32)(StackIsr2TaskI102 + StackIsr2TaskI102_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_I103[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_SISR_I103_SEC_bss), //S_bss
        (uint32)(_EISR_I103_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackIsr2TaskI103),
        (uint32)(StackIsr2TaskI103 + StackIsr2TaskI103_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_I105[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_SISR_I105_SEC_bss), //S_bss
        (uint32)(_EISR_I105_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackIsr2TaskI105),
        (uint32)(StackIsr2TaskI105 + StackIsr2TaskI105_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};

MemProtAreaType MemProtArea_I106[2] = {
    /* Area 5, Task global data */
    {
        (uint32)(_SISR_I106_SEC_bss), //S_bss
        (uint32)(_EISR_I106_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
    /* Area 6, Task stack */
    {
        (uint32)(StackIsr2TaskI106),
        (uint32)(StackIsr2TaskI106 + StackIsr2TaskI106_SIZE),
        0 | MPAT_E | MPAT_G | MPAT_SW | MPAT_SR | MPAT_UW | MPAT_UR 
    },
};



/* All OS-App memory protection section bound and setting */
MemProtAreaType MemProtArea_A01[2] = {
    /* Area 3, OS-App text */
    {
        (uint32)(_SOSAPP_A01_SEC_text),
        (uint32)(_ETASK_T003_SEC_text),
        0 | MPAT_E | MPAT_G | MPAT_SX | MPAT_SR | MPAT_UX | MPAT_UR 
    },
    /* Area 4, OS-App data */
    {
        (uint32)(_SOSAPP_A01_SEC_bss), //S_bss
        (uint32)(_EOSAPP_A01_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SR | MPAT_SW | MPAT_UR | MPAT_UW
    },
};

MemProtAreaType MemProtArea_A03[2] = {
    /* Area 3, OS-App text */
    {
        (uint32)(_SOSAPP_A03_SEC_text),
        (uint32)(_ETASK_T006_SEC_text),
        0 | MPAT_E | MPAT_G | MPAT_SX | MPAT_SR | MPAT_UX | MPAT_UR 
    },
    /* Area 4, OS-App data */
    {
        (uint32)(_SOSAPP_A03_SEC_bss), //S_bss
        (uint32)(_EOSAPP_A03_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SR | MPAT_SW | MPAT_UR | MPAT_UW
    },
};

MemProtAreaType MemProtArea_A02[2] = {
    /* Area 3, OS-App text */
    {
        (uint32)(_SOSAPP_A02_SEC_text),
        (uint32)(_ETASK_T103_SEC_text),
        0 | MPAT_E | MPAT_G | MPAT_SX | MPAT_SR | MPAT_UX | MPAT_UR 
    },
    /* Area 4, OS-App data */
    {
        (uint32)(_SOSAPP_A02_SEC_bss), //S_bss
        (uint32)(_EOSAPP_A02_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SR | MPAT_SW | MPAT_UR | MPAT_UW
    },
};

MemProtAreaType MemProtArea_A04[2] = {
    /* Area 3, OS-App text */
    {
        (uint32)(_SOSAPP_A04_SEC_text),
        (uint32)(_ETASK_T106_SEC_text),
        0 | MPAT_E | MPAT_G | MPAT_SX | MPAT_SR | MPAT_UX | MPAT_UR 
    },
    /* Area 4, OS-App data */
    {
        (uint32)(_SOSAPP_A04_SEC_bss), //S_bss
        (uint32)(_EOSAPP_A04_SEC_data_R), //E_data_R
        0 | MPAT_E | MPAT_G | MPAT_SR | MPAT_SW | MPAT_UR | MPAT_UW
    },
};





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

#pragma section OSAPP_A01_SEC
const int dummy_OSAPP_A01_SEC_const;
int dummy_OSAPP_A01_SEC_data = 1;
int dummy_OSAPP_A01_SEC_bss;
void dummy_OSAPP_A01_SEC_func(){;};

#pragma section ISR_I001_SEC
const int dummy_ISR_I001_SEC_const;
int dummy_ISR_I001_SEC_data = 1;
int dummy_ISR_I001_SEC_bss;
void dummy_ISR_I001_SEC_func(){;};

#pragma section ISR_I002_SEC
const int dummy_ISR_I002_SEC_const;
int dummy_ISR_I002_SEC_data = 1;
int dummy_ISR_I002_SEC_bss;
void dummy_ISR_I002_SEC_func(){;};

#pragma section ISR_I003_SEC
const int dummy_ISR_I003_SEC_const;
int dummy_ISR_I003_SEC_data = 1;
int dummy_ISR_I003_SEC_bss;
void dummy_ISR_I003_SEC_func(){;};

#pragma section ISR_I004_SEC
const int dummy_ISR_I004_SEC_const;
int dummy_ISR_I004_SEC_data = 1;
int dummy_ISR_I004_SEC_bss;
void dummy_ISR_I004_SEC_func(){;};

#pragma section TASK_T001_SEC
const int dummy_TASK_T001_SEC_const;
int dummy_TASK_T001_SEC_data = 1;
int dummy_TASK_T001_SEC_bss;
void dummy_TASK_T001_SEC_func(){;};

#pragma section TASK_T002_SEC
const int dummy_TASK_T002_SEC_const;
int dummy_TASK_T002_SEC_data = 1;
int dummy_TASK_T002_SEC_bss;
void dummy_TASK_T002_SEC_func(){;};

#pragma section TASK_T003_SEC
const int dummy_TASK_T003_SEC_const;
int dummy_TASK_T003_SEC_data = 1;
int dummy_TASK_T003_SEC_bss;
void dummy_TASK_T003_SEC_func(){;};

#pragma section OSAPP_A02_SEC
const int dummy_OSAPP_A02_SEC_const;
int dummy_OSAPP_A02_SEC_data = 1;
int dummy_OSAPP_A02_SEC_bss;
void dummy_OSAPP_A02_SEC_func(){;};

#pragma section ISR_I101_SEC
const int dummy_ISR_I101_SEC_const;
int dummy_ISR_I101_SEC_data = 1;
int dummy_ISR_I101_SEC_bss;
void dummy_ISR_I101_SEC_func(){;};

#pragma section ISR_I102_SEC
const int dummy_ISR_I102_SEC_const;
int dummy_ISR_I102_SEC_data = 1;
int dummy_ISR_I102_SEC_bss;
void dummy_ISR_I102_SEC_func(){;};

#pragma section ISR_I103_SEC
const int dummy_ISR_I103_SEC_const;
int dummy_ISR_I103_SEC_data = 1;
int dummy_ISR_I103_SEC_bss;
void dummy_ISR_I103_SEC_func(){;};

#pragma section ISR_I104_SEC
const int dummy_ISR_I104_SEC_const;
int dummy_ISR_I104_SEC_data = 1;
int dummy_ISR_I104_SEC_bss;
void dummy_ISR_I104_SEC_func(){;};

#pragma section TASK_T101_SEC
const int dummy_TASK_T101_SEC_const;
int dummy_TASK_T101_SEC_data = 1;
int dummy_TASK_T101_SEC_bss;
void dummy_TASK_T101_SEC_func(){;};

#pragma section TASK_T102_SEC
const int dummy_TASK_T102_SEC_const;
int dummy_TASK_T102_SEC_data = 1;
int dummy_TASK_T102_SEC_bss;
void dummy_TASK_T102_SEC_func(){;};

#pragma section TASK_T103_SEC
const int dummy_TASK_T103_SEC_const;
int dummy_TASK_T103_SEC_data = 1;
int dummy_TASK_T103_SEC_bss;
void dummy_TASK_T103_SEC_func(){;};

#pragma section OSAPP_A03_SEC
const int dummy_OSAPP_A03_SEC_const;
int dummy_OSAPP_A03_SEC_data = 1;
int dummy_OSAPP_A03_SEC_bss;
void dummy_OSAPP_A03_SEC_func(){;};

#pragma section ISR_I005_SEC
const int dummy_ISR_I005_SEC_const;
int dummy_ISR_I005_SEC_data = 1;
int dummy_ISR_I005_SEC_bss;
void dummy_ISR_I005_SEC_func(){;};

#pragma section ISR_I006_SEC
const int dummy_ISR_I006_SEC_const;
int dummy_ISR_I006_SEC_data = 1;
int dummy_ISR_I006_SEC_bss;
void dummy_ISR_I006_SEC_func(){;};

#pragma section TASK_T004_SEC
const int dummy_TASK_T004_SEC_const;
int dummy_TASK_T004_SEC_data = 1;
int dummy_TASK_T004_SEC_bss;
void dummy_TASK_T004_SEC_func(){;};

#pragma section TASK_T005_SEC
const int dummy_TASK_T005_SEC_const;
int dummy_TASK_T005_SEC_data = 1;
int dummy_TASK_T005_SEC_bss;
void dummy_TASK_T005_SEC_func(){;};

#pragma section TASK_T006_SEC
const int dummy_TASK_T006_SEC_const;
int dummy_TASK_T006_SEC_data = 1;
int dummy_TASK_T006_SEC_bss;
void dummy_TASK_T006_SEC_func(){;};

#pragma section OSAPP_A04_SEC
const int dummy_OSAPP_A04_SEC_const;
int dummy_OSAPP_A04_SEC_data = 1;
int dummy_OSAPP_A04_SEC_bss;
void dummy_OSAPP_A04_SEC_func(){;};

#pragma section ISR_I105_SEC
const int dummy_ISR_I105_SEC_const;
int dummy_ISR_I105_SEC_data = 1;
int dummy_ISR_I105_SEC_bss;
void dummy_ISR_I105_SEC_func(){;};

#pragma section ISR_I106_SEC
const int dummy_ISR_I106_SEC_const;
int dummy_ISR_I106_SEC_data = 1;
int dummy_ISR_I106_SEC_bss;
void dummy_ISR_I106_SEC_func(){;};

#pragma section TASK_T104_SEC
const int dummy_TASK_T104_SEC_const;
int dummy_TASK_T104_SEC_data = 1;
int dummy_TASK_T104_SEC_bss;
void dummy_TASK_T104_SEC_func(){;};

#pragma section TASK_T105_SEC
const int dummy_TASK_T105_SEC_const;
int dummy_TASK_T105_SEC_data = 1;
int dummy_TASK_T105_SEC_bss;
void dummy_TASK_T105_SEC_func(){;};

#pragma section TASK_T106_SEC
const int dummy_TASK_T106_SEC_const;
int dummy_TASK_T106_SEC_data = 1;
int dummy_TASK_T106_SEC_bss;
void dummy_TASK_T106_SEC_func(){;};

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