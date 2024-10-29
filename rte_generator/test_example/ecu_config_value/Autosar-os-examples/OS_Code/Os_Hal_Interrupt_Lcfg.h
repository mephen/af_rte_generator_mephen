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
 *              File: Os_Hal_Interrupt_Lcfg.h
 *   Generation Time: 2023-02-15 09:54:36
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_INTERRUPT_LCFG_H
# define OS_HAL_INTERRUPT_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Hal_Interrupt_Cfg.h"
# include "Os_Hal_Interrupt_Types.h"

/* Os kernel module dependencies */
# include "Os_Interrupt_Types.h"

/* Os hal dependencies */
# include "Os_Hal_Core_Types.h"


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

/*! HAL ISR configuration data: ADC0_SG1_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC0_SG1_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC0_SG1_CAT2_ISR;

/*! HAL ISR configuration data: ADC1_SG1_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_ADC1_SG1_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_ADC1_SG1_CAT2_ISR;

/*! HAL ISR configuration data: CanIsrGlobalRxFifo_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrGlobalRxFifo_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrGlobalRxFifo_0;

/*! HAL ISR configuration data: CanIsrStatus_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrStatus_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrStatus_0;

/*! HAL ISR configuration data: CanIsrTx_0 */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrTx_0;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CanIsrTx_0;

/*! HAL ISR configuration data: CounterIsr_OsCounter_10ms */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_OsCounter_10ms;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_OsCounter_10ms;

/*! HAL ISR configuration data: CounterIsr_SystemTimer */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer;

/*! HAL ISR configuration data: EXT_INTP_CH03_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH03_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH03_CAT2_ISR;

/*! HAL ISR configuration data: EXT_INTP_CH07_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH07_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH07_CAT2_ISR;

/*! HAL ISR configuration data: EXT_INTP_CH17_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_EXT_INTP_CH17_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_EXT_INTP_CH17_CAT2_ISR;

/*! HAL ISR configuration data: INTIIC0EE */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTIIC0EE;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTIIC0EE;

/*! HAL ISR configuration data: INTIIC0RI */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTIIC0RI;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTIIC0RI;

/*! HAL ISR configuration data: INTIIC0TEI */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_INTIIC0TEI;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_INTIIC0TEI;

/*! HAL ISR configuration data: IRQDmaChannel2TransmitComplete */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IRQDmaChannel2TransmitComplete;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IRQDmaChannel2TransmitComplete;

/*! HAL ISR configuration data: IRQDmaChannel5ReceiveComplete */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IRQDmaChannel5ReceiveComplete;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IRQDmaChannel5ReceiveComplete;

/*! HAL ISR configuration data: IRQDmaChannel5TransmitComplete */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IRQDmaChannel5TransmitComplete;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_IRQDmaChannel5TransmitComplete;

/*! HAL ISR configuration data: SPI_CSIH0_TIR_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH0_TIR_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SPI_CSIH0_TIR_CAT2_ISR;

/*! HAL ISR configuration data: SPI_CSIH2_TIR_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH2_TIR_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SPI_CSIH2_TIR_CAT2_ISR;

/*! HAL ISR configuration data: SPI_CSIH3_TIR_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SPI_CSIH3_TIR_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_SPI_CSIH3_TIR_CAT2_ISR;

/*! HAL ISR configuration data: TAUD0_CH00_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH00_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH00_CAT2_ISR;

/*! HAL ISR configuration data: TAUD0_CH01_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH01_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH01_CAT2_ISR;

/*! HAL ISR configuration data: TAUD0_CH02_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH02_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH02_CAT2_ISR;

/*! HAL ISR configuration data: TAUD0_CH04_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH04_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH04_CAT2_ISR;

/*! HAL ISR configuration data: TAUD0_CH05_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_TAUD0_CH05_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_TAUD0_CH05_CAT2_ISR;

/*! HAL ISR configuration data: WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR */
extern CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR;
extern CONST(Os_Hal_IntIsrMapConfigType, OS_CONST) OsCfg_Hal_IntIsrMap_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_HAL_INTERRUPT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.h
 *********************************************************************************************************************/
