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
 *              File: Os_Isr_Lcfg.h
 *   Generation Time: 2023-02-15 09:54:36
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_ISR_LCFG_H
# define OS_ISR_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Isr_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"
# include "Os_Timer_Types.h"
# include "Os_XSignal_Types.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: ADC0_SG1_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC0_SG1_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC0_SG1_CAT2_ISR;

/*! ISR configuration data: ADC1_SG1_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_ADC1_SG1_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_ADC1_SG1_CAT2_ISR;

/*! ISR configuration data: CanIsrGlobalRxFifo_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrGlobalRxFifo_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrGlobalRxFifo_0;

/*! ISR configuration data: CanIsrStatus_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrStatus_0;

/*! ISR configuration data: CanIsrTx_0 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsrTx_0_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsrTx_0;

/*! ISR configuration data: CounterIsr_OsCounter_10ms */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_OsCounter_10ms_HwConfig;
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_OsCounter_10ms;

/*! ISR configuration data: CounterIsr_SystemTimer */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_HwConfig;
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer;

/*! ISR configuration data: EXT_INTP_CH03_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH03_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH07_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH07_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH07_CAT2_ISR;

/*! ISR configuration data: EXT_INTP_CH17_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH17_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_EXT_INTP_CH17_CAT2_ISR;

/*! ISR configuration data: INTIIC0EE */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTIIC0EE_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTIIC0EE;

/*! ISR configuration data: INTIIC0RI */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTIIC0RI_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTIIC0RI;

/*! ISR configuration data: INTIIC0TEI */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_INTIIC0TEI_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_INTIIC0TEI;

/*! ISR configuration data: IRQDmaChannel2TransmitComplete */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel2TransmitComplete_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel2TransmitComplete;

/*! ISR configuration data: IRQDmaChannel5ReceiveComplete */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel5ReceiveComplete_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel5ReceiveComplete;

/*! ISR configuration data: IRQDmaChannel5TransmitComplete */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel5TransmitComplete_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_IRQDmaChannel5TransmitComplete;

/*! ISR configuration data: SPI_CSIH0_TIR_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH0_TIR_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH0_TIR_CAT2_ISR;

/*! ISR configuration data: SPI_CSIH2_TIR_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH2_TIR_CAT2_ISR;

/*! ISR configuration data: SPI_CSIH3_TIR_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_SPI_CSIH3_TIR_CAT2_ISR;

/*! ISR configuration data: TAUD0_CH00_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH00_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH00_CAT2_ISR;

/*! ISR configuration data: TAUD0_CH01_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH01_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH01_CAT2_ISR;

/*! ISR configuration data: TAUD0_CH02_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH02_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH02_CAT2_ISR;

/*! ISR configuration data: TAUD0_CH04_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH04_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH04_CAT2_ISR;

/*! ISR configuration data: TAUD0_CH05_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH05_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_TAUD0_CH05_CAT2_ISR;

/*! ISR configuration data: WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
extern CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ISR_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Isr_Lcfg.h
 *********************************************************************************************************************/
