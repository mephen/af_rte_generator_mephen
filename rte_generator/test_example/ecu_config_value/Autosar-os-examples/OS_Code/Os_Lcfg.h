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
 *              File: Os_Lcfg.h
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_LCFG_H
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


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

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_Default_Init_Task_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Default_Init_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_DEFAULT_INIT_TASK_CODE) Os_Task_Default_Init_Task(void);

# define OS_STOP_SEC_Default_Init_Task_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_IO_Task_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  IO_Task()
 *********************************************************************************************************************/
extern FUNC(void, OS_IO_TASK_CODE) Os_Task_IO_Task(void);

# define OS_STOP_SEC_IO_Task_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_MyTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  MyTask()
 *********************************************************************************************************************/
extern FUNC(void, OS_MYTASK_CODE) Os_Task_MyTask(void);

# define OS_STOP_SEC_MyTask_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_ApplInitDeInit_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_ApplInitDeInit()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APPLINITDEINIT_CODE) Os_Task_OsTask_ApplInitDeInit(void);

# define OS_STOP_SEC_OsTask_ApplInitDeInit_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_ApplMainFunctions_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_ApplMainFunctions()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APPLMAINFUNCTIONS_CODE) Os_Task_OsTask_ApplMainFunctions(void);

# define OS_STOP_SEC_OsTask_ApplMainFunctions_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_ApplTimedInitDeInit_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_ApplTimedInitDeInit()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APPLTIMEDINITDEINIT_CODE) Os_Task_OsTask_ApplTimedInitDeInit(void);

# define OS_STOP_SEC_OsTask_ApplTimedInitDeInit_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_ApplVerify_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_ApplVerify()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_APPLVERIFY_CODE) Os_Task_OsTask_ApplVerify(void);

# define OS_STOP_SEC_OsTask_ApplVerify_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_Background_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_Background()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_BACKGROUND_CODE) Os_Task_OsTask_Background(void);

# define OS_STOP_SEC_OsTask_Background_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_BswMainFunctions_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_BswMainFunctions()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_BSWMAINFUNCTIONS_CODE) Os_Task_OsTask_BswMainFunctions(void);

# define OS_STOP_SEC_OsTask_BswMainFunctions_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_Communication_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_Communication()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_COMMUNICATION_CODE) Os_Task_OsTask_Communication(void);

# define OS_STOP_SEC_OsTask_Communication_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_DcmSessionChanges_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_DcmSessionChanges()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_DCMSESSIONCHANGES_CODE) Os_Task_OsTask_DcmSessionChanges(void);

# define OS_STOP_SEC_OsTask_DcmSessionChanges_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_Dimming_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_Dimming()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_DIMMING_CODE) Os_Task_OsTask_Dimming(void);

# define OS_STOP_SEC_OsTask_Dimming_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_NvmAccess_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_NvmAccess()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_NVMACCESS_CODE) Os_Task_OsTask_NvmAccess(void);

# define OS_STOP_SEC_OsTask_NvmAccess_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_SelfDiagnostics_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_SelfDiagnostics()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_SELFDIAGNOSTICS_CODE) Os_Task_OsTask_SelfDiagnostics(void);

# define OS_STOP_SEC_OsTask_SelfDiagnostics_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_OsTask_Touch_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  OsTask_Touch()
 *********************************************************************************************************************/
extern FUNC(void, OS_OSTASK_TOUCH_CODE) Os_Task_OsTask_Touch(void);

# define OS_STOP_SEC_OsTask_Touch_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ADC0_SG1_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ADC0_SG1_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC0_SG1_CAT2_ISR_CODE) Os_Isr_ADC0_SG1_CAT2_ISR(void);

# define OS_STOP_SEC_ADC0_SG1_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ADC1_SG1_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ADC1_SG1_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC1_SG1_CAT2_ISR_CODE) Os_Isr_ADC1_SG1_CAT2_ISR(void);

# define OS_STOP_SEC_ADC1_SG1_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrGlobalRxFifo_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrGlobalRxFifo_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRGLOBALRXFIFO_0_CODE) Os_Isr_CanIsrGlobalRxFifo_0(void);

# define OS_STOP_SEC_CanIsrGlobalRxFifo_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrStatus_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrStatus_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRSTATUS_0_CODE) Os_Isr_CanIsrStatus_0(void);

# define OS_STOP_SEC_CanIsrStatus_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsrTx_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsrTx_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISRTX_0_CODE) Os_Isr_CanIsrTx_0(void);

# define OS_STOP_SEC_CanIsrTx_0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CddUart_DmaChannel2TransmitCompleteNotification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CddUart_DmaChannel2TransmitCompleteNotification()
 *********************************************************************************************************************/
extern FUNC(void, OS_CDDUART_DMACHANNEL2TRANSMITCOMPLETENOTIFICATION_CODE) Os_Isr_CddUart_DmaChannel2TransmitCompleteNotification(void);

# define OS_STOP_SEC_CddUart_DmaChannel2TransmitCompleteNotification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CddUart_DmaChannel5ReceiveCompleteNotification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CddUart_DmaChannel5ReceiveCompleteNotification()
 *********************************************************************************************************************/
extern FUNC(void, OS_CDDUART_DMACHANNEL5RECEIVECOMPLETENOTIFICATION_CODE) Os_Isr_CddUart_DmaChannel5ReceiveCompleteNotification(void);

# define OS_STOP_SEC_CddUart_DmaChannel5ReceiveCompleteNotification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CddUart_DmaChannel5TransmitCompleteNotification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CddUart_DmaChannel5TransmitCompleteNotification()
 *********************************************************************************************************************/
extern FUNC(void, OS_CDDUART_DMACHANNEL5TRANSMITCOMPLETENOTIFICATION_CODE) Os_Isr_CddUart_DmaChannel5TransmitCompleteNotification(void);

# define OS_STOP_SEC_CddUart_DmaChannel5TransmitCompleteNotification_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH03_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH03_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH03_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH03_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH03_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH07_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH07_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH07_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH07_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH07_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_EXT_INTP_CH17_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  EXT_INTP_CH17_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_EXT_INTP_CH17_CAT2_ISR_CODE) Os_Isr_EXT_INTP_CH17_CAT2_ISR(void);

# define OS_STOP_SEC_EXT_INTP_CH17_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_I2c_IrqUnit0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  I2c_IrqUnit0()
 *********************************************************************************************************************/
extern FUNC(void, OS_I2C_IRQUNIT0_CODE) Os_Isr_I2c_IrqUnit0(void);

# define OS_STOP_SEC_I2c_IrqUnit0_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SPI_CSIH0_TIR_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SPI_CSIH0_TIR_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIH0_TIR_CAT2_ISR_CODE) Os_Isr_SPI_CSIH0_TIR_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIH0_TIR_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SPI_CSIH2_TIR_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SPI_CSIH2_TIR_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIH2_TIR_CAT2_ISR_CODE) Os_Isr_SPI_CSIH2_TIR_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIH2_TIR_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SPI_CSIH3_TIR_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SPI_CSIH3_TIR_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_SPI_CSIH3_TIR_CAT2_ISR_CODE) Os_Isr_SPI_CSIH3_TIR_CAT2_ISR(void);

# define OS_STOP_SEC_SPI_CSIH3_TIR_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_TAUD0_CH00_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TAUD0_CH00_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_TAUD0_CH00_CAT2_ISR_CODE) Os_Isr_TAUD0_CH00_CAT2_ISR(void);

# define OS_STOP_SEC_TAUD0_CH00_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_TAUD0_CH01_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TAUD0_CH01_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_TAUD0_CH01_CAT2_ISR_CODE) Os_Isr_TAUD0_CH01_CAT2_ISR(void);

# define OS_STOP_SEC_TAUD0_CH01_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_TAUD0_CH02_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TAUD0_CH02_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_TAUD0_CH02_CAT2_ISR_CODE) Os_Isr_TAUD0_CH02_CAT2_ISR(void);

# define OS_STOP_SEC_TAUD0_CH02_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_TAUD0_CH04_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TAUD0_CH04_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_TAUD0_CH04_CAT2_ISR_CODE) Os_Isr_TAUD0_CH04_CAT2_ISR(void);

# define OS_STOP_SEC_TAUD0_CH04_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_TAUD0_CH05_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  TAUD0_CH05_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_TAUD0_CH05_CAT2_ISR_CODE) Os_Isr_TAUD0_CH05_CAT2_ISR(void);

# define OS_STOP_SEC_TAUD0_CH05_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE) Os_Isr_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR(void);

# define OS_STOP_SEC_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CddWdgIf_ToggleHwWdgClockLevel_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CddWdgIf_ToggleHwWdgClockLevel()
 *********************************************************************************************************************/
extern FUNC(void, OS_CDDWDGIF_TOGGLEHWWDGCLOCKLEVEL_CODE) CddWdgIf_ToggleHwWdgClockLevel(void);

# define OS_STOP_SEC_CddWdgIf_ToggleHwWdgClockLevel_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SwcDispCtrl_NauchLaufExpired_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SwcDispCtrl_NauchLaufExpired()
 *********************************************************************************************************************/
extern FUNC(void, OS_SWCDISPCTRL_NAUCHLAUFEXPIRED_CODE) SwcDispCtrl_NauchLaufExpired(void);

# define OS_STOP_SEC_SwcDispCtrl_NauchLaufExpired_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SwcDispCtrl_RetryDispOn_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SwcDispCtrl_RetryDispOn()
 *********************************************************************************************************************/
extern FUNC(void, OS_SWCDISPCTRL_RETRYDISPON_CODE) SwcDispCtrl_RetryDispOn(void);

# define OS_STOP_SEC_SwcDispCtrl_RetryDispOn_CODE
# include "Os_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
