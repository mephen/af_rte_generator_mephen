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
 *              File: Os_Hal_Interrupt_Lcfg.c
 *   Generation Time: 2023-02-15 09:54:36
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_INTERRUPT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Core.h"


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

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL ISR configuration data: ADC0_SG1_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC0_SG1_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 18uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 18uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)18uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC0_SG1_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: ADC1_SG1_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC1_SG1_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 213uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 213uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)213uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC1_SG1_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrGlobalRxFifo_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrGlobalRxFifo_0 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 23uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 23uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)23uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrGlobalRxFifo_0 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrStatus_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrStatus_0 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 24uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 24uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)24uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrStatus_0 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CanIsrTx_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrTx_0 =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 26uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 26uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)26uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrTx_0 =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CounterIsr_OsCounter_10ms */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_OsCounter_10ms =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 277uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 277uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)277uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_OsCounter_10ms =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 84uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 84uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)84uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH03_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH03_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 43uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 43uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)43uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH03_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH07_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH07_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 129uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 129uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)129uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH07_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: EXT_INTP_CH17_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH17_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 369uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 369uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)369uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH17_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTIIC0EE */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTIIC0EE =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 77uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 77uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)77uL,
  /* .IntLevel    = */ (uint32)3uL,
  /* .IntMask     = */ (uint32)(0x0000FFF8uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTIIC0EE =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTIIC0RI */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTIIC0RI =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 78uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 78uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)78uL,
  /* .IntLevel    = */ (uint32)3uL,
  /* .IntMask     = */ (uint32)(0x0000FFF8uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTIIC0RI =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: INTIIC0TEI */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTIIC0TEI =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 79uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 79uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)79uL,
  /* .IntLevel    = */ (uint32)3uL,
  /* .IntMask     = */ (uint32)(0x0000FFF8uL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTIIC0TEI =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: IRQDmaChannel2TransmitComplete */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IRQDmaChannel2TransmitComplete =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 62uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 62uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)62uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IRQDmaChannel2TransmitComplete =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: IRQDmaChannel5ReceiveComplete */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IRQDmaChannel5ReceiveComplete =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 61uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 61uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)61uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IRQDmaChannel5ReceiveComplete =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: IRQDmaChannel5TransmitComplete */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IRQDmaChannel5TransmitComplete =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 60uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 60uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)60uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IRQDmaChannel5TransmitComplete =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: SPI_CSIH0_TIR_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH0_TIR_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 30uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 30uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)30uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SPI_CSIH0_TIR_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: SPI_CSIH2_TIR_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH2_TIR_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 133uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 133uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)133uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SPI_CSIH2_TIR_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: SPI_CSIH3_TIR_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 159uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 159uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)159uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SPI_CSIH3_TIR_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: TAUD0_CH00_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH00_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 8uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 8uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)8uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH00_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: TAUD0_CH01_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH01_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 48uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 48uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)48uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH01_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: TAUD0_CH02_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH02_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 9uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 9uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)9uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH02_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: TAUD0_CH04_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH04_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC1_BASE + (OS_HAL_EIC_OFFSET * 10uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD1_BASE + (OS_HAL_IBD_OFFSET * 10uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)10uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH04_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: TAUD0_CH05_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH05_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 50uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 50uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)50uL,
  /* .IntLevel    = */ (uint32)1uL,
  /* .IntMask     = */ (uint32)(0x0000FFFEuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH05_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
};

/*! HAL ISR configuration data: WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR =
{
  /* .EICBaseAddr = */ (Os_Hal_EICnRefType)(OS_HAL_INTC2_BASE + (OS_HAL_EIC_OFFSET * 40uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IBDBaseAddr = */ (Os_Hal_IBDnRefType)(OS_HAL_EIBD2_BASE + (OS_HAL_IBD_OFFSET * 40uL)),           /* PRQA S 0303 */ /* MD_Os_Hal_Rule11.4_0303 */
  /* .IntChannel  = */ (uint32)40uL,
  /* .IntLevel    = */ (uint32)0uL,
  /* .IntMask     = */ (uint32)(0x0000FFFFuL & OS_HAL_PMR_MASK),
  /* .CoreID      = */ (uint32)0uL
};

CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR =
{
  /* .Dummy         = */ (uint32)0
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
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.c
 *********************************************************************************************************************/
