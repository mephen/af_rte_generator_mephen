#ifndef MEMSECTION_H
#define MEMSECTION_H
/* Extern all section tag! */

/* %ResetVectorPE1% */
extern char _SRESET_PE1[];
extern char _ERESET_PE1[];
extern char _SEIINTTBL_PE1[];
extern char _EEIINTTBL_PE1[];
extern char _SSYSTEMCALLTBL[];
extern char _ESYSTEMCALLTBL[];

/* 0x00008000 All .text */
extern char _S_text[];
extern char _E_text[];
extern char _SIOC_RESERVED_SEC_text[];
extern char _EIOC_RESERVED_SEC_text[];
extern char _SUSER_SHARED_SEC_text[];
extern char _EUSER_SHARED_SEC_text[];
extern char _SLOCAL_RAM_PE1_text[];
extern char _ELOCAL_RAM_PE1_text[];
extern char _SLOCAL_RAM_PE2_text[];
extern char _ELOCAL_RAM_PE2_text[];
extern char _SSELF_AREA_text[];
extern char _ESELF_AREA_text[];
extern char _SGLOBAL_RAM_A_text[];
extern char _EGLOBAL_RAM_A_text[];
extern char _SRETENTION_RAM_text[];
extern char _ERETENTION_RAM_text[];

extern char _SOSAPP_A01_SEC_text[];
extern char _EOSAPP_A01_SEC_text[];
extern char _SISR_I001_SEC_text[];
extern char _EISR_I001_SEC_text[];
extern char _SISR_I002_SEC_text[];
extern char _EISR_I002_SEC_text[];
extern char _SISR_I003_SEC_text[];
extern char _EISR_I003_SEC_text[];
extern char _SISR_I004_SEC_text[];
extern char _EISR_I004_SEC_text[];
extern char _STASK_T001_SEC_text[];
extern char _ETASK_T001_SEC_text[];
extern char _STASK_T002_SEC_text[];
extern char _ETASK_T002_SEC_text[];
extern char _STASK_T003_SEC_text[];
extern char _ETASK_T003_SEC_text[];

extern char _SOSAPP_A02_SEC_text[];
extern char _EOSAPP_A02_SEC_text[];
extern char _SISR_I101_SEC_text[];
extern char _EISR_I101_SEC_text[];
extern char _SISR_I102_SEC_text[];
extern char _EISR_I102_SEC_text[];
extern char _SISR_I103_SEC_text[];
extern char _EISR_I103_SEC_text[];
extern char _SISR_I104_SEC_text[];
extern char _EISR_I104_SEC_text[];
extern char _STASK_T101_SEC_text[];
extern char _ETASK_T101_SEC_text[];
extern char _STASK_T102_SEC_text[];
extern char _ETASK_T102_SEC_text[];
extern char _STASK_T103_SEC_text[];
extern char _ETASK_T103_SEC_text[];

extern char _SOSAPP_A03_SEC_text[];
extern char _EOSAPP_A03_SEC_text[];
extern char _SISR_I005_SEC_text[];
extern char _EISR_I005_SEC_text[];
extern char _SISR_I006_SEC_text[];
extern char _EISR_I006_SEC_text[];
extern char _STASK_T004_SEC_text[];
extern char _ETASK_T004_SEC_text[];
extern char _STASK_T005_SEC_text[];
extern char _ETASK_T005_SEC_text[];
extern char _STASK_T006_SEC_text[];
extern char _ETASK_T006_SEC_text[];

extern char _SOSAPP_A04_SEC_text[];
extern char _EOSAPP_A04_SEC_text[];
extern char _SISR_I105_SEC_text[];
extern char _EISR_I105_SEC_text[];
extern char _SISR_I106_SEC_text[];
extern char _EISR_I106_SEC_text[];
extern char _STASK_T104_SEC_text[];
extern char _ETASK_T104_SEC_text[];
extern char _STASK_T105_SEC_text[];
extern char _ETASK_T105_SEC_text[];
extern char _STASK_T106_SEC_text[];
extern char _ETASK_T106_SEC_text[];

extern char _SGLOBAL_RAM_B_text[];
extern char _EGLOBAL_RAM_B_text[];
/* 0x00800000 All .const and .data */
extern char _SRESET_PE2[];
extern char _ERESET_PE2[];
extern char _SEIINTTBL_PE2[];
extern char _EEIINTTBL_PE2[];

extern char _S_const[];
extern char _E_const[];
extern char _SIOC_RESERVED_SEC_const[];
extern char _EIOC_RESERVED_SEC_const[];
extern char _SUSER_SHARED_SEC_const[];
extern char _EUSER_SHARED_SEC_const[];
extern char _SLOCAL_RAM_PE1_const[];
extern char _ELOCAL_RAM_PE1_const[];
extern char _SLOCAL_RAM_PE2_const[];
extern char _ELOCAL_RAM_PE2_const[];
extern char _SSELF_AREA_const[];
extern char _ESELF_AREA_const[];

extern char _SOSAPP_A01_SEC_const[];
extern char _EOSAPP_A01_SEC_const[];
extern char _SISR_I001_SEC_const[];
extern char _EISR_I001_SEC_const[];
extern char _SISR_I002_SEC_const[];
extern char _EISR_I002_SEC_const[];
extern char _SISR_I003_SEC_const[];
extern char _EISR_I003_SEC_const[];
extern char _SISR_I004_SEC_const[];
extern char _EISR_I004_SEC_const[];
extern char _STASK_T001_SEC_const[];
extern char _ETASK_T001_SEC_const[];
extern char _STASK_T002_SEC_const[];
extern char _ETASK_T002_SEC_const[];
extern char _STASK_T003_SEC_const[];
extern char _ETASK_T003_SEC_const[];

extern char _SOSAPP_A02_SEC_const[];
extern char _EOSAPP_A02_SEC_const[];
extern char _SISR_I101_SEC_const[];
extern char _EISR_I101_SEC_const[];
extern char _SISR_I102_SEC_const[];
extern char _EISR_I102_SEC_const[];
extern char _SISR_I103_SEC_const[];
extern char _EISR_I103_SEC_const[];
extern char _SISR_I104_SEC_const[];
extern char _EISR_I104_SEC_const[];
extern char _STASK_T101_SEC_const[];
extern char _ETASK_T101_SEC_const[];
extern char _STASK_T102_SEC_const[];
extern char _ETASK_T102_SEC_const[];
extern char _STASK_T103_SEC_const[];
extern char _ETASK_T103_SEC_const[];

extern char _SOSAPP_A03_SEC_const[];
extern char _EOSAPP_A03_SEC_const[];
extern char _SISR_I005_SEC_const[];
extern char _EISR_I005_SEC_const[];
extern char _SISR_I006_SEC_const[];
extern char _EISR_I006_SEC_const[];
extern char _STASK_T004_SEC_const[];
extern char _ETASK_T004_SEC_const[];
extern char _STASK_T005_SEC_const[];
extern char _ETASK_T005_SEC_const[];
extern char _STASK_T006_SEC_const[];
extern char _ETASK_T006_SEC_const[];

extern char _SOSAPP_A04_SEC_const[];
extern char _EOSAPP_A04_SEC_const[];
extern char _SISR_I105_SEC_const[];
extern char _EISR_I105_SEC_const[];
extern char _SISR_I106_SEC_const[];
extern char _EISR_I106_SEC_const[];
extern char _STASK_T104_SEC_const[];
extern char _ETASK_T104_SEC_const[];
extern char _STASK_T105_SEC_const[];
extern char _ETASK_T105_SEC_const[];
extern char _STASK_T106_SEC_const[];
extern char _ETASK_T106_SEC_const[];

extern char _SGLOBAL_RAM_A_const[];
extern char _EGLOBAL_RAM_A_const[];
extern char _SRETENTION_RAM_const[];
extern char _ERETENTION_RAM_const[];
extern char _SGLOBAL_RAM_B_const[];
extern char _EGLOBAL_RAM_B_const[];

extern char _S_data[];
extern char _E_data[];
extern char _SIOC_RESERVED_SEC_data[];
extern char _EIOC_RESERVED_SEC_data[];
extern char _SUSER_SHARED_SEC_data[];
extern char _EUSER_SHARED_SEC_data[];
extern char _SLOCAL_RAM_PE1_data[];
extern char _ELOCAL_RAM_PE1_data[];
extern char _SLOCAL_RAM_PE2_data[];
extern char _ELOCAL_RAM_PE2_data[];
extern char _SSELF_AREA_data[];
extern char _ESELF_AREA_data[];

extern char _SOSAPP_A01_SEC_data[];
extern char _EOSAPP_A01_SEC_data[];
extern char _SISR_I001_SEC_data[];
extern char _EISR_I001_SEC_data[];
extern char _SISR_I002_SEC_data[];
extern char _EISR_I002_SEC_data[];
extern char _SISR_I003_SEC_data[];
extern char _EISR_I003_SEC_data[];
extern char _SISR_I004_SEC_data[];
extern char _EISR_I004_SEC_data[];
extern char _STASK_T001_SEC_data[];
extern char _ETASK_T001_SEC_data[];
extern char _STASK_T002_SEC_data[];
extern char _ETASK_T002_SEC_data[];
extern char _STASK_T003_SEC_data[];
extern char _ETASK_T003_SEC_data[];

extern char _SOSAPP_A02_SEC_data[];
extern char _EOSAPP_A02_SEC_data[];
extern char _SISR_I101_SEC_data[];
extern char _EISR_I101_SEC_data[];
extern char _SISR_I102_SEC_data[];
extern char _EISR_I102_SEC_data[];
extern char _SISR_I103_SEC_data[];
extern char _EISR_I103_SEC_data[];
extern char _SISR_I104_SEC_data[];
extern char _EISR_I104_SEC_data[];
extern char _STASK_T101_SEC_data[];
extern char _ETASK_T101_SEC_data[];
extern char _STASK_T102_SEC_data[];
extern char _ETASK_T102_SEC_data[];
extern char _STASK_T103_SEC_data[];
extern char _ETASK_T103_SEC_data[];

extern char _SOSAPP_A03_SEC_data[];
extern char _EOSAPP_A03_SEC_data[];
extern char _SISR_I005_SEC_data[];
extern char _EISR_I005_SEC_data[];
extern char _SISR_I006_SEC_data[];
extern char _EISR_I006_SEC_data[];
extern char _STASK_T004_SEC_data[];
extern char _ETASK_T004_SEC_data[];
extern char _STASK_T005_SEC_data[];
extern char _ETASK_T005_SEC_data[];
extern char _STASK_T006_SEC_data[];
extern char _ETASK_T006_SEC_data[];

extern char _SOSAPP_A04_SEC_data[];
extern char _EOSAPP_A04_SEC_data[];
extern char _SISR_I105_SEC_data[];
extern char _EISR_I105_SEC_data[];
extern char _SISR_I106_SEC_data[];
extern char _EISR_I106_SEC_data[];
extern char _STASK_T104_SEC_data[];
extern char _ETASK_T104_SEC_data[];
extern char _STASK_T105_SEC_data[];
extern char _ETASK_T105_SEC_data[];
extern char _STASK_T106_SEC_data[];
extern char _ETASK_T106_SEC_data[];

extern char _SGLOBAL_RAM_A_data[];
extern char _EGLOBAL_RAM_A_data[];
extern char _SRETENTION_RAM_data[];
extern char _ERETENTION_RAM_data[];
extern char _SGLOBAL_RAM_B_data[];
extern char _EGLOBAL_RAM_B_data[];

/* 0xFE9E0000 All .bss .data.R in PE2 */
extern char _SLOCAL_RAM_PE2_bss[];
extern char _ELOCAL_RAM_PE2_bss[];
extern char _SLOCAL_RAM_PE2_data_R[];
extern char _LOCAL_RAM_PE2_data_R[];

extern char _SOSAPP_A02_SEC_bss[];
extern char _EOSAPP_A02_SEC_bss[];
extern char _SISR_I101_SEC_bss[];
extern char _EISR_I101_SEC_bss[];
extern char _SISR_I102_SEC_bss[];
extern char _EISR_I102_SEC_bss[];
extern char _SISR_I103_SEC_bss[];
extern char _EISR_I103_SEC_bss[];
extern char _SISR_I104_SEC_bss[];
extern char _EISR_I104_SEC_bss[];
extern char _STASK_T101_SEC_bss[];
extern char _ETASK_T101_SEC_bss[];
extern char _STASK_T102_SEC_bss[];
extern char _ETASK_T102_SEC_bss[];
extern char _STASK_T103_SEC_bss[];
extern char _ETASK_T103_SEC_bss[];

extern char _SOSAPP_A04_SEC_bss[];
extern char _EOSAPP_A04_SEC_bss[];
extern char _SISR_I105_SEC_bss[];
extern char _EISR_I105_SEC_bss[];
extern char _SISR_I106_SEC_bss[];
extern char _EISR_I106_SEC_bss[];
extern char _STASK_T104_SEC_bss[];
extern char _ETASK_T104_SEC_bss[];
extern char _STASK_T105_SEC_bss[];
extern char _ETASK_T105_SEC_bss[];
extern char _STASK_T106_SEC_bss[];
extern char _ETASK_T106_SEC_bss[];

extern char _ETASK_SysTask_core1_bss[];
extern char _STASK_SysTask_core1_bss[];

extern char _SOSAPP_A02_SEC_data_R[];
extern char _EOSAPP_A02_SEC_data_R[];
extern char _SISR_I101_SEC_data_R[];
extern char _EISR_I101_SEC_data_R[];
extern char _SISR_I102_SEC_data_R[];
extern char _EISR_I102_SEC_data_R[];
extern char _SISR_I103_SEC_data_R[];
extern char _EISR_I103_SEC_data_R[];
extern char _SISR_I104_SEC_data_R[];
extern char _EISR_I104_SEC_data_R[];
extern char _STASK_T101_SEC_data_R[];
extern char _ETASK_T101_SEC_data_R[];
extern char _STASK_T102_SEC_data_R[];
extern char _ETASK_T102_SEC_data_R[];
extern char _STASK_T103_SEC_data_R[];
extern char _ETASK_T103_SEC_data_R[];

extern char _SOSAPP_A04_SEC_data_R[];
extern char _EOSAPP_A04_SEC_data_R[];
extern char _SISR_I105_SEC_data_R[];
extern char _EISR_I105_SEC_data_R[];
extern char _SISR_I106_SEC_data_R[];
extern char _EISR_I106_SEC_data_R[];
extern char _STASK_T104_SEC_data_R[];
extern char _ETASK_T104_SEC_data_R[];
extern char _STASK_T105_SEC_data_R[];
extern char _ETASK_T105_SEC_data_R[];
extern char _STASK_T106_SEC_data_R[];
extern char _ETASK_T106_SEC_data_R[];

extern char _ETASK_SysTask_core1_data_R[];
extern char _STASK_SysTask_core1_data_R[];

extern char _SALL_TASK_ISR_STACK_PE2_bss[];
extern char _EALL_TASK_ISR_STACK_PE2_bss[];
extern char _Ssystem_pe2_stack_bss[];
extern char _Esystem_pe2_stack_bss[];

/* 0xFEBC0000 All .bss .data.R in PE1 */
extern char _SLOCAL_RAM_PE1_bss[];
extern char _ELOCAL_RAM_PE1_bss[];
extern char _SLOCAL_RAM_PE1_data_R[];
extern char _LOCAL_RAM_PE1_data_R[];

extern char _SOSAPP_A01_SEC_bss[];
extern char _EOSAPP_A01_SEC_bss[];
extern char _SISR_I001_SEC_bss[];
extern char _EISR_I001_SEC_bss[];
extern char _SISR_I002_SEC_bss[];
extern char _EISR_I002_SEC_bss[];
extern char _SISR_I003_SEC_bss[];
extern char _EISR_I003_SEC_bss[];
extern char _SISR_I004_SEC_bss[];
extern char _EISR_I004_SEC_bss[];
extern char _STASK_T001_SEC_bss[];
extern char _ETASK_T001_SEC_bss[];
extern char _STASK_T002_SEC_bss[];
extern char _ETASK_T002_SEC_bss[];
extern char _STASK_T003_SEC_bss[];
extern char _ETASK_T003_SEC_bss[];

extern char _SOSAPP_A03_SEC_bss[];
extern char _EOSAPP_A03_SEC_bss[];
extern char _SISR_I005_SEC_bss[];
extern char _EISR_I005_SEC_bss[];
extern char _SISR_I006_SEC_bss[];
extern char _EISR_I006_SEC_bss[];
extern char _STASK_T004_SEC_bss[];
extern char _ETASK_T004_SEC_bss[];
extern char _STASK_T005_SEC_bss[];
extern char _ETASK_T005_SEC_bss[];
extern char _STASK_T006_SEC_bss[];
extern char _ETASK_T006_SEC_bss[];

extern char _ETASK_SysTask_core0_bss[];
extern char _STASK_SysTask_core0_bss[];

extern char _SOSAPP_A01_SEC_data_R[];
extern char _EOSAPP_A01_SEC_data_R[];
extern char _SISR_I001_SEC_data_R[];
extern char _EISR_I001_SEC_data_R[];
extern char _SISR_I002_SEC_data_R[];
extern char _EISR_I002_SEC_data_R[];
extern char _SISR_I003_SEC_data_R[];
extern char _EISR_I003_SEC_data_R[];
extern char _SISR_I004_SEC_data_R[];
extern char _EISR_I004_SEC_data_R[];
extern char _STASK_T001_SEC_data_R[];
extern char _ETASK_T001_SEC_data_R[];
extern char _STASK_T002_SEC_data_R[];
extern char _ETASK_T002_SEC_data_R[];
extern char _STASK_T003_SEC_data_R[];
extern char _ETASK_T003_SEC_data_R[];

extern char _SOSAPP_A03_SEC_data_R[];
extern char _EOSAPP_A03_SEC_data_R[];
extern char _SISR_I005_SEC_data_R[];
extern char _EISR_I005_SEC_data_R[];
extern char _SISR_I006_SEC_data_R[];
extern char _EISR_I006_SEC_data_R[];
extern char _STASK_T004_SEC_data_R[];
extern char _ETASK_T004_SEC_data_R[];
extern char _STASK_T005_SEC_data_R[];
extern char _ETASK_T005_SEC_data_R[];
extern char _STASK_T006_SEC_data_R[];
extern char _ETASK_T006_SEC_data_R[];

extern char _ETASK_SysTask_core0_data_R[];
extern char _STASK_SysTask_core0_data_R[];

extern char _SALL_TASK_ISR_STACK_PE1_bss[];
extern char _EALL_TASK_ISR_STACK_PE1_bss[];
extern char _Ssystem_pe1_stack_bss[];
extern char _Esystem_pe1_stack_bss[];

/* 0xFEDFE000 self os .bss .data.R */
extern char _SSELF_AREA_bss[];
extern char _ESELF_AREA_bss[];
extern char _SSELF_AREA_data_R[];
extern char _ESELF_AREA_data_R[];

/* 0xFEDFE000 self os .bss .data.R */
extern char _SIOC_RESERVED_SEC_bss[];
extern char _EIOC_RESERVED_SEC_bss[];
extern char _SIOC_RESERVED_SEC_data_R[];
extern char _EIOC_RESERVED_SEC_data_R[];
extern char _SGLOBAL_RAM_A_bss[];
extern char _EGLOBAL_RAM_A_bss[];
extern char _SGLOBAL_RAM_A_data_R[];
extern char _EGLOBAL_RAM_A_data_R[];

/* 0xFEF01000 */
extern char _S_bss[];
extern char _E_bss[];
extern char _S_data_R[];
extern char _E_data_R[];
extern char _SRETENTION_RAM_bss[];
extern char _ERETENTION_RAM_bss[];
extern char _SRETENTION_RAM_data_R[];
extern char _ERETENTION_RAM_data_R[];

/* 0xFEF01000 */
extern char _SUSER_SHARED_SEC_bss[];
extern char _EUSER_SHARED_SEC_bss[];
extern char _SUSER_SHARED_SEC_data_R[];
extern char _EUSER_SHARED_SEC_data_R[];
extern char _SGLOBAL_RAM_B_bss[];
extern char _EGLOBAL_RAM_B_bss[];
extern char _SGLOBAL_RAM_B_data_R[];
extern char _EGLOBAL_RAM_B_data_R[];



#endif  /* MEMSECTION_H */


