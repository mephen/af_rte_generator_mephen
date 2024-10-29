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
 *              File: Os_Hal_Entry_Lcfg.c
 *   Generation Time: 2023-02-15 09:54:36
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_ENTRY_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Entry_Cfg.h"
#include "Os_Hal_Entry_Lcfg.h"
#include "Os_Hal_Entry.h"

/* Os kernel module dependencies */
#include "Os_Isr_Lcfg.h"
#include "Os.h"

/* Os hal dependencies */
#include "Os_Hal_Cfg.h"
#include "Os_Hal_Core_Lcfg.h"
#include "Os_Hal_Interrupt_Cfg.h"
#include "Os_Hal_Trap.h"


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







/**********************************************************************************************************************
 *  INTERRUPT VECTOR TABLE CORE 0
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  CAT2 ISR HANDLER CORE 0
 *********************************************************************************************************************/

  extern void Os_Hal_Irq_ADC0_SG1_CAT2_ISR(void); 

  extern void Os_Hal_Irq_ADC1_SG1_CAT2_ISR(void); 

  extern void Os_Hal_Irq_CanIsrGlobalRxFifo_0(void); 

  extern void Os_Hal_Irq_CanIsrStatus_0(void); 

  extern void Os_Hal_Irq_CanIsrTx_0(void); 

  extern void Os_Hal_Irq_CounterIsr_OsCounter_10ms(void); 

  extern void Os_Hal_Irq_CounterIsr_SystemTimer(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH03_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH07_CAT2_ISR(void); 

  extern void Os_Hal_Irq_EXT_INTP_CH17_CAT2_ISR(void); 

  extern void Os_Hal_Irq_INTIIC0EE(void); 

  extern void Os_Hal_Irq_INTIIC0RI(void); 

  extern void Os_Hal_Irq_INTIIC0TEI(void); 

  extern void Os_Hal_Irq_IRQDmaChannel2TransmitComplete(void); 

  extern void Os_Hal_Irq_IRQDmaChannel5ReceiveComplete(void); 

  extern void Os_Hal_Irq_IRQDmaChannel5TransmitComplete(void); 

  extern void Os_Hal_Irq_SPI_CSIH0_TIR_CAT2_ISR(void); 

  extern void Os_Hal_Irq_SPI_CSIH2_TIR_CAT2_ISR(void); 

  extern void Os_Hal_Irq_SPI_CSIH3_TIR_CAT2_ISR(void); 

  extern void Os_Hal_Irq_TAUD0_CH00_CAT2_ISR(void); 

  extern void Os_Hal_Irq_TAUD0_CH01_CAT2_ISR(void); 

  extern void Os_Hal_Irq_TAUD0_CH02_CAT2_ISR(void); 

  extern void Os_Hal_Irq_TAUD0_CH04_CAT2_ISR(void); 

  extern void Os_Hal_Irq_TAUD0_CH05_CAT2_ISR(void); 

  extern void Os_Hal_Irq_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR(void); 



/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Entry_Lcfg.c
 *********************************************************************************************************************/
