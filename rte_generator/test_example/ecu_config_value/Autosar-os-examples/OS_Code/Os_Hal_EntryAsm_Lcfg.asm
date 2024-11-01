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
 *              File: Os_Hal_EntryAsm_Lcfg.asm
 *   Generation Time: 2023-02-15 09:54:35
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Os_Cfg.h"
#include "Os_Hal_Compiler_ASM.h"

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

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/
 

 /**********************************************************************************************************************
 *  EXCEPTION VECTOR TABLE CORE 0
 *********************************************************************************************************************/

  OS_HAL_ASM_SECTION_TEXT(.OS_EXCVEC_CORE0_CODE)
  OS_HAL_ASM_ALIGN512()

  
  OS_HAL_ASM_EXC(core0_0x0000, RESET_CORE0)
  
  OS_HAL_ASM_EXC(core0_0x0010, Os_Hal_UnhandledExc)   
    
  OS_HAL_ASM_EXC(core0_0x0020, Os_Hal_UnhandledExc)   
    
  OS_HAL_ASM_EXC(core0_0x0030, Os_Hal_UnhandledExc)   
    
  OS_HAL_ASM_EXC(core0_0x0040, Os_Hal_UnhandledExc)    
  
  OS_HAL_ASM_EXC(core0_0x0050, Os_Hal_UnhandledExc)     
  
  OS_HAL_ASM_EXC(core0_0x0060, Os_Hal_UnhandledExc)     
  
  OS_HAL_ASM_EXC(core0_0x0070, Os_Hal_UnhandledExc)     
  
  OS_HAL_ASM_EXC(core0_0x0080, Os_Hal_UnhandledExc)     
  
  OS_HAL_ASM_EXC(core0_0x0090, Os_Hal_UnhandledExc)  
  
  OS_HAL_ASM_EXC(core0_0x00a0, Os_Hal_UnhandledExc)

  OS_HAL_ASM_EXC(core0_0x00b0, Os_Hal_UnhandledExc)

  OS_HAL_ASM_EXC(core0_0x00c0, Os_Hal_UnhandledExc)

  OS_HAL_ASM_EXC(core0_0x00d0, Os_Hal_UnhandledExc)

  OS_HAL_ASM_EXC(core0_0x00e0, Os_Hal_UnhandledExc)

  OS_HAL_ASM_EXC(core0_0x00f0, Os_Hal_UnhandledExc)

  OS_HAL_ASM_EXC(core0_0x0100, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x0110, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x0120, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x0130, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x0140, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x0150, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x0160, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x0170, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x0180, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x0190, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x01a0, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x01b0, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x01c0, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x01d0, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x01e0, Os_Hal_UnhandledIrq)

  OS_HAL_ASM_EXC(core0_0x01f0, Os_Hal_UnhandledIrq)

  
  
/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/


  OS_HAL_ASM_SECTION_TEXT(.OS_INTVEC_CORE0_CODE)
  OS_HAL_ASM_ALIGN512()

  
  /* Irq Channel 0 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 1 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 2 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 3 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 4 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 5 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 6 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 7 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 8 */ OS_HAL_ASM_WORD(Os_Hal_Irq_TAUD0_CH00_CAT2_ISR) 
  /* Irq Channel 9 */ OS_HAL_ASM_WORD(Os_Hal_Irq_TAUD0_CH02_CAT2_ISR) 
  /* Irq Channel 10 */ OS_HAL_ASM_WORD(Os_Hal_Irq_TAUD0_CH04_CAT2_ISR) 
  /* Irq Channel 11 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 12 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 13 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 14 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 15 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 16 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 17 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 18 */ OS_HAL_ASM_WORD(Os_Hal_Irq_ADC0_SG1_CAT2_ISR) 
  /* Irq Channel 19 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 20 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 21 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 22 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 23 */ OS_HAL_ASM_WORD(Os_Hal_Irq_CanIsrGlobalRxFifo_0) 
  /* Irq Channel 24 */ OS_HAL_ASM_WORD(Os_Hal_Irq_CanIsrStatus_0) 
  /* Irq Channel 25 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 26 */ OS_HAL_ASM_WORD(Os_Hal_Irq_CanIsrTx_0) 
  /* Irq Channel 27 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 28 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 29 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 30 */ OS_HAL_ASM_WORD(Os_Hal_Irq_SPI_CSIH0_TIR_CAT2_ISR) 
  /* Irq Channel 31 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 32 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 33 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 34 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 35 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 36 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 37 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 38 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 39 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 40 */ OS_HAL_ASM_WORD(Os_Hal_Irq_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR) 
  /* Irq Channel 41 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 42 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 43 */ OS_HAL_ASM_WORD(Os_Hal_Irq_EXT_INTP_CH03_CAT2_ISR) 
  /* Irq Channel 44 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 45 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 46 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 47 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 48 */ OS_HAL_ASM_WORD(Os_Hal_Irq_TAUD0_CH01_CAT2_ISR) 
  /* Irq Channel 49 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 50 */ OS_HAL_ASM_WORD(Os_Hal_Irq_TAUD0_CH05_CAT2_ISR) 
  /* Irq Channel 51 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 52 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 53 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 54 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 55 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 56 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 57 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 58 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 59 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 60 */ OS_HAL_ASM_WORD(Os_Hal_Irq_IRQDmaChannel5TransmitComplete) 
  /* Irq Channel 61 */ OS_HAL_ASM_WORD(Os_Hal_Irq_IRQDmaChannel5ReceiveComplete) 
  /* Irq Channel 62 */ OS_HAL_ASM_WORD(Os_Hal_Irq_IRQDmaChannel2TransmitComplete) 
  /* Irq Channel 63 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 64 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 65 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 66 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 67 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 68 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 69 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 70 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 71 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 72 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 73 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 74 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 75 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 76 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 77 */ OS_HAL_ASM_WORD(Os_Hal_Irq_INTIIC0EE) 
  /* Irq Channel 78 */ OS_HAL_ASM_WORD(Os_Hal_Irq_INTIIC0RI) 
  /* Irq Channel 79 */ OS_HAL_ASM_WORD(Os_Hal_Irq_INTIIC0TEI) 
  /* Irq Channel 80 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 81 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 82 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 83 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 84 */ OS_HAL_ASM_WORD(Os_Hal_Irq_CounterIsr_SystemTimer) 
  /* Irq Channel 85 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 86 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 87 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 88 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 89 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 90 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 91 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 92 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 93 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 94 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 95 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 96 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 97 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 98 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 99 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 100 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 101 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 102 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 103 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 104 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 105 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 106 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 107 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 108 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 109 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 110 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 111 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 112 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 113 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 114 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 115 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 116 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 117 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 118 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 119 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 120 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 121 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 122 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 123 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 124 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 125 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 126 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 127 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 128 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 129 */ OS_HAL_ASM_WORD(Os_Hal_Irq_EXT_INTP_CH07_CAT2_ISR) 
  /* Irq Channel 130 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 131 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 132 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 133 */ OS_HAL_ASM_WORD(Os_Hal_Irq_SPI_CSIH2_TIR_CAT2_ISR) 
  /* Irq Channel 134 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 135 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 136 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 137 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 138 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 139 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 140 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 141 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 142 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 143 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 144 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 145 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 146 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 147 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 148 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 149 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 150 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 151 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 152 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 153 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 154 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 155 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 156 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 157 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 158 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 159 */ OS_HAL_ASM_WORD(Os_Hal_Irq_SPI_CSIH3_TIR_CAT2_ISR) 
  /* Irq Channel 160 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 161 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 162 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 163 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 164 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 165 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 166 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 167 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 168 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 169 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 170 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 171 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 172 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 173 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 174 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 175 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 176 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 177 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 178 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 179 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 180 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 181 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 182 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 183 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 184 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 185 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 186 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 187 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 188 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 189 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 190 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 191 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 192 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 193 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 194 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 195 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 196 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 197 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 198 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 199 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 200 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 201 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 202 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 203 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 204 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 205 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 206 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 207 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 208 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 209 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 210 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 211 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 212 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 213 */ OS_HAL_ASM_WORD(Os_Hal_Irq_ADC1_SG1_CAT2_ISR) 
  /* Irq Channel 214 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 215 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 216 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 217 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 218 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 219 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 220 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 221 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 222 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 223 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 224 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 225 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 226 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 227 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 228 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 229 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 230 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 231 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 232 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 233 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 234 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 235 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 236 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 237 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 238 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 239 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 240 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 241 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 242 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 243 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 244 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 245 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 246 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 247 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 248 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 249 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 250 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 251 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 252 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 253 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 254 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 255 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 256 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 257 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 258 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 259 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 260 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 261 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 262 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 263 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 264 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 265 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 266 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 267 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 268 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 269 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 270 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 271 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 272 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 273 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 274 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 275 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 276 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 277 */ OS_HAL_ASM_WORD(Os_Hal_Irq_CounterIsr_OsCounter_10ms) 
  /* Irq Channel 278 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 279 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 280 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 281 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 282 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 283 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 284 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 285 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 286 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 287 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 288 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 289 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 290 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 291 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 292 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 293 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 294 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 295 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 296 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 297 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 298 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 299 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 300 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 301 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 302 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 303 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 304 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 305 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 306 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 307 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 308 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 309 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 310 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 311 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 312 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 313 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 314 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 315 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 316 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 317 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 318 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 319 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 320 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 321 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 322 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 323 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 324 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 325 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 326 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 327 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 328 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 329 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 330 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 331 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 332 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 333 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 334 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 335 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 336 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 337 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 338 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 339 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 340 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 341 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 342 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 343 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 344 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 345 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 346 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 347 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 348 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 349 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 350 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 351 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 352 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 353 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 354 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 355 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 356 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 357 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 358 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 359 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 360 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 361 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 362 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 363 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 364 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 365 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 366 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 367 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 368 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 369 */ OS_HAL_ASM_WORD(Os_Hal_Irq_EXT_INTP_CH17_CAT2_ISR) 
  /* Irq Channel 370 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 371 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 372 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 373 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 374 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 375 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 
  /* Irq Channel 376 */ OS_HAL_ASM_WORD(Os_Hal_UnhandledIrq) 


/**********************************************************************************************************************
 *  CAT2 ISR HANDLER CORE 0
 *********************************************************************************************************************/

  OS_HAL_ASM_CAT2ISR(ADC0_SG1_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(ADC1_SG1_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(CanIsrGlobalRxFifo_0) 

  OS_HAL_ASM_CAT2ISR(CanIsrStatus_0) 

  OS_HAL_ASM_CAT2ISR(CanIsrTx_0) 

  OS_HAL_ASM_CAT2ISR(CounterIsr_OsCounter_10ms) 

  OS_HAL_ASM_CAT2ISR(CounterIsr_SystemTimer) 

  OS_HAL_ASM_CAT2ISR(EXT_INTP_CH03_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(EXT_INTP_CH07_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(EXT_INTP_CH17_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(INTIIC0EE) 

  OS_HAL_ASM_CAT2ISR(INTIIC0RI) 

  OS_HAL_ASM_CAT2ISR(INTIIC0TEI) 

  OS_HAL_ASM_CAT2ISR(IRQDmaChannel2TransmitComplete) 

  OS_HAL_ASM_CAT2ISR(IRQDmaChannel5ReceiveComplete) 

  OS_HAL_ASM_CAT2ISR(IRQDmaChannel5TransmitComplete) 

  OS_HAL_ASM_CAT2ISR(SPI_CSIH0_TIR_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(SPI_CSIH2_TIR_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(SPI_CSIH3_TIR_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(TAUD0_CH00_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(TAUD0_CH01_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(TAUD0_CH02_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(TAUD0_CH04_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(TAUD0_CH05_CAT2_ISR) 

  OS_HAL_ASM_CAT2ISR(WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR) 



/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_EntryAsm_Lcfg.asm
 *********************************************************************************************************************/
