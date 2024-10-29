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
 *              File: Os_Hal_Cfg.h
 *   Generation Time: 2023-02-15 09:54:35
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/


                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CFG_H
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (2u)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (36u)

/* ISR core and level definitions */
# define OS_ISR_ADC0_SG1_CAT2_ISR_CORE      (0)
# define OS_ISR_ADC0_SG1_CAT2_ISR_LEVEL     (0)
# define OS_ISR_ADC1_SG1_CAT2_ISR_CORE      (0)
# define OS_ISR_ADC1_SG1_CAT2_ISR_LEVEL     (0)
# define OS_ISR_CANISRGLOBALRXFIFO_0_CORE      (0)
# define OS_ISR_CANISRGLOBALRXFIFO_0_LEVEL     (0)
# define OS_ISR_CANISRSTATUS_0_CORE      (0)
# define OS_ISR_CANISRSTATUS_0_LEVEL     (0)
# define OS_ISR_CANISRTX_0_CORE      (0)
# define OS_ISR_CANISRTX_0_LEVEL     (0)
# define OS_ISR_COUNTERISR_OSCOUNTER_10MS_CORE      (0)
# define OS_ISR_COUNTERISR_OSCOUNTER_10MS_LEVEL     (0)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE      (0)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_LEVEL     (0)
# define OS_ISR_EXT_INTP_CH03_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH03_CAT2_ISR_LEVEL     (0)
# define OS_ISR_EXT_INTP_CH07_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH07_CAT2_ISR_LEVEL     (0)
# define OS_ISR_EXT_INTP_CH17_CAT2_ISR_CORE      (0)
# define OS_ISR_EXT_INTP_CH17_CAT2_ISR_LEVEL     (0)
# define OS_ISR_INTIIC0EE_CORE      (0)
# define OS_ISR_INTIIC0EE_LEVEL     (3)
# define OS_ISR_INTIIC0RI_CORE      (0)
# define OS_ISR_INTIIC0RI_LEVEL     (3)
# define OS_ISR_INTIIC0TEI_CORE      (0)
# define OS_ISR_INTIIC0TEI_LEVEL     (3)
# define OS_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_CORE      (0)
# define OS_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_LEVEL     (0)
# define OS_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_CORE      (0)
# define OS_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_LEVEL     (0)
# define OS_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_CORE      (0)
# define OS_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_LEVEL     (0)
# define OS_ISR_SPI_CSIH0_TIR_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIH0_TIR_CAT2_ISR_LEVEL     (0)
# define OS_ISR_SPI_CSIH2_TIR_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIH2_TIR_CAT2_ISR_LEVEL     (0)
# define OS_ISR_SPI_CSIH3_TIR_CAT2_ISR_CORE      (0)
# define OS_ISR_SPI_CSIH3_TIR_CAT2_ISR_LEVEL     (0)
# define OS_ISR_TAUD0_CH00_CAT2_ISR_CORE      (0)
# define OS_ISR_TAUD0_CH00_CAT2_ISR_LEVEL     (0)
# define OS_ISR_TAUD0_CH01_CAT2_ISR_CORE      (0)
# define OS_ISR_TAUD0_CH01_CAT2_ISR_LEVEL     (0)
# define OS_ISR_TAUD0_CH02_CAT2_ISR_CORE      (0)
# define OS_ISR_TAUD0_CH02_CAT2_ISR_LEVEL     (0)
# define OS_ISR_TAUD0_CH04_CAT2_ISR_CORE      (0)
# define OS_ISR_TAUD0_CH04_CAT2_ISR_LEVEL     (0)
# define OS_ISR_TAUD0_CH05_CAT2_ISR_CORE      (0)
# define OS_ISR_TAUD0_CH05_CAT2_ISR_LEVEL     (1)
# define OS_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CORE      (0)
# define OS_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_LEVEL     (0)

/* Hardware counter timing macros */

/* Counter timing macros and constants: OsCounter_10ms */
# define OSMAXALLOWEDVALUE_OsCounter_10ms     (1073741823uL) /* 0x3FFFFFFFuL */
# define OSMINCYCLE_OsCounter_10ms            (1uL)
# define OSTICKSPERBASE_OsCounter_10ms        (400000uL)
# define OSTICKDURATION_OsCounter_10ms        (10000000uL)

/*! Macro OS_NS2TICKS_OsCounter_10ms was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_NS2TICKS_OsCounter_10ms(x)     ( (TickType) (((((uint32)(x)) * 1) + 5000000) / 10000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_OsCounter_10ms was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_OsCounter_10ms(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 10000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_OsCounter_10ms was approximated with a deviation of 2.220446049250313E-10ppm. */
# define OS_US2TICKS_OsCounter_10ms(x)     ( (TickType) (((((uint32)(x)) * 1) + 5000) / 10000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_OsCounter_10ms was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2US_OsCounter_10ms(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 10000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_OsCounter_10ms was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_OsCounter_10ms(x)     ( (TickType) (((((uint32)(x)) * 1) + 5) / 10) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_OsCounter_10ms was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_OsCounter_10ms(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 10) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_OsCounter_10ms was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_OsCounter_10ms(x)     ( (TickType) (((((uint32)(x)) * 100) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_OsCounter_10ms was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_OsCounter_10ms(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 50) / 100) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/* Counter timing macros and constants: OsCounter_1ms */
# define OSMAXALLOWEDVALUE_OsCounter_1ms     (2147483647uL) /* 0x7FFFFFFFuL */
# define OSMINCYCLE_OsCounter_1ms            (1uL)
# define OSTICKSPERBASE_OsCounter_1ms        (60000uL)
# define OSTICKDURATION_OsCounter_1ms        (1000000uL)

/* OSEK compatibility for the system timer. */
# define OSMAXALLOWEDVALUE     (OSMAXALLOWEDVALUE_OsCounter_1ms)
# define OSMINCYCLE            (OSMINCYCLE_OsCounter_1ms)
# define OSTICKSPERBASE        (OSTICKSPERBASE_OsCounter_1ms)
# define OSTICKDURATION        (OSTICKDURATION_OsCounter_1ms)

/*! Macro OS_NS2TICKS_OsCounter_1ms was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_OsCounter_1ms(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_OsCounter_1ms was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_OsCounter_1ms(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_OsCounter_1ms was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_OsCounter_1ms(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_OsCounter_1ms was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_OsCounter_1ms(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_OsCounter_1ms was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_OsCounter_1ms(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_OsCounter_1ms was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_OsCounter_1ms(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_OsCounter_1ms was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_OsCounter_1ms(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_OsCounter_1ms was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_OsCounter_1ms(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */




/* Bit mask to be set to SELB_INTC1 register for interrupt routing. */
# define OS_HAL_SELB_INTC1_MASK   (uint16)(0x00000000uL)

/* Bit mask to be set to SELB_INTC2 register for interrupt routing. */
# define OS_HAL_SELB_INTC2_MASK   (uint16)(0x00000000uL)

/* Defines wether G3X or G4X core is supported. */
# define OS_HAL_ASM_CORE_G3X



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
