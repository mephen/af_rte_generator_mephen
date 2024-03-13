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
 *              File: Os_Link_Core0.ld
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CODE SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_INTVEC_CODE )
.OS_INTVEC_CORE0_CODE ALIGN(512) :> .
_OS_INTVEC_CORE0_CODE_START = ADDR(.OS_INTVEC_CORE0_CODE);
. = ALIGN(4);
_OS_INTVEC_CORE0_CODE_END = . - 1;
_OS_INTVEC_CORE0_CODE_LIMIT = .;
__OS_INTVEC_CORE0_CODE_START = _OS_INTVEC_CORE0_CODE_START;
__OS_INTVEC_CORE0_CODE_END = _OS_INTVEC_CORE0_CODE_END;
__OS_INTVEC_CORE0_CODE_LIMIT = _OS_INTVEC_CORE0_CODE_LIMIT;
#endif

#if defined ( OS_LINK_EXCVEC_CODE )
.OS_EXCVEC_CORE0_CODE ALIGN(512) :> .
_OS_EXCVEC_CORE0_CODE_START = ADDR(.OS_EXCVEC_CORE0_CODE);
. = ALIGN(4);
_OS_EXCVEC_CORE0_CODE_END = . - 1;
_OS_EXCVEC_CORE0_CODE_LIMIT = .;
__OS_EXCVEC_CORE0_CODE_START = _OS_EXCVEC_CORE0_CODE_START;
__OS_EXCVEC_CORE0_CODE_END = _OS_EXCVEC_CORE0_CODE_END;
__OS_EXCVEC_CORE0_CODE_LIMIT = _OS_EXCVEC_CORE0_CODE_LIMIT;
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
.OS_ADC0_SG1_CAT2_ISR_CODE ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_CODE_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_CODE_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_CODE_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_CODE_START = _OS_ADC0_SG1_CAT2_ISR_CODE_START;
__OS_ADC0_SG1_CAT2_ISR_CODE_END = _OS_ADC0_SG1_CAT2_ISR_CODE_END;
__OS_ADC0_SG1_CAT2_ISR_CODE_LIMIT = _OS_ADC0_SG1_CAT2_ISR_CODE_LIMIT;
.OS_ADC1_SG1_CAT2_ISR_CODE ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_CODE_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_CODE_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_CODE_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_CODE_START = _OS_ADC1_SG1_CAT2_ISR_CODE_START;
__OS_ADC1_SG1_CAT2_ISR_CODE_END = _OS_ADC1_SG1_CAT2_ISR_CODE_END;
__OS_ADC1_SG1_CAT2_ISR_CODE_LIMIT = _OS_ADC1_SG1_CAT2_ISR_CODE_LIMIT;
.OS_CanIsrGlobalRxFifo_0_CODE ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_CODE_START = ADDR(.OS_CanIsrGlobalRxFifo_0_CODE);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_CODE_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_CODE_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_CODE_START = _OS_CanIsrGlobalRxFifo_0_CODE_START;
__OS_CanIsrGlobalRxFifo_0_CODE_END = _OS_CanIsrGlobalRxFifo_0_CODE_END;
__OS_CanIsrGlobalRxFifo_0_CODE_LIMIT = _OS_CanIsrGlobalRxFifo_0_CODE_LIMIT;
.OS_CanIsrStatus_0_CODE ALIGN(4) :> .
_OS_CanIsrStatus_0_CODE_START = ADDR(.OS_CanIsrStatus_0_CODE);
. = ALIGN(4);
_OS_CanIsrStatus_0_CODE_END = . - 1;
_OS_CanIsrStatus_0_CODE_LIMIT = .;
__OS_CanIsrStatus_0_CODE_START = _OS_CanIsrStatus_0_CODE_START;
__OS_CanIsrStatus_0_CODE_END = _OS_CanIsrStatus_0_CODE_END;
__OS_CanIsrStatus_0_CODE_LIMIT = _OS_CanIsrStatus_0_CODE_LIMIT;
.OS_CanIsrTx_0_CODE ALIGN(4) :> .
_OS_CanIsrTx_0_CODE_START = ADDR(.OS_CanIsrTx_0_CODE);
. = ALIGN(4);
_OS_CanIsrTx_0_CODE_END = . - 1;
_OS_CanIsrTx_0_CODE_LIMIT = .;
__OS_CanIsrTx_0_CODE_START = _OS_CanIsrTx_0_CODE_START;
__OS_CanIsrTx_0_CODE_END = _OS_CanIsrTx_0_CODE_END;
__OS_CanIsrTx_0_CODE_LIMIT = _OS_CanIsrTx_0_CODE_LIMIT;
.OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE ALIGN(4) :> .
_OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE_START = ADDR(.OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE);
. = ALIGN(4);
_OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE_END = . - 1;
_OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE_LIMIT = .;
__OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE_START = _OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE_START;
__OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE_END = _OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE_END;
__OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE_LIMIT = _OS_CddUart_DmaChannel2TransmitCompleteNotification_CODE_LIMIT;
.OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE ALIGN(4) :> .
_OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE_START = ADDR(.OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE);
. = ALIGN(4);
_OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE_END = . - 1;
_OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE_LIMIT = .;
__OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE_START = _OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE_START;
__OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE_END = _OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE_END;
__OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE_LIMIT = _OS_CddUart_DmaChannel5ReceiveCompleteNotification_CODE_LIMIT;
.OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE ALIGN(4) :> .
_OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE_START = ADDR(.OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE);
. = ALIGN(4);
_OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE_END = . - 1;
_OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE_LIMIT = .;
__OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE_START = _OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE_START;
__OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE_END = _OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE_END;
__OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE_LIMIT = _OS_CddUart_DmaChannel5TransmitCompleteNotification_CODE_LIMIT;
.OS_CddWdgIf_ToggleHwWdgClockLevel_CODE ALIGN(4) :> .
_OS_CddWdgIf_ToggleHwWdgClockLevel_CODE_START = ADDR(.OS_CddWdgIf_ToggleHwWdgClockLevel_CODE);
. = ALIGN(4);
_OS_CddWdgIf_ToggleHwWdgClockLevel_CODE_END = . - 1;
_OS_CddWdgIf_ToggleHwWdgClockLevel_CODE_LIMIT = .;
__OS_CddWdgIf_ToggleHwWdgClockLevel_CODE_START = _OS_CddWdgIf_ToggleHwWdgClockLevel_CODE_START;
__OS_CddWdgIf_ToggleHwWdgClockLevel_CODE_END = _OS_CddWdgIf_ToggleHwWdgClockLevel_CODE_END;
__OS_CddWdgIf_ToggleHwWdgClockLevel_CODE_LIMIT = _OS_CddWdgIf_ToggleHwWdgClockLevel_CODE_LIMIT;
.OS_Default_Init_Task_CODE ALIGN(4) :> .
_OS_Default_Init_Task_CODE_START = ADDR(.OS_Default_Init_Task_CODE);
. = ALIGN(4);
_OS_Default_Init_Task_CODE_END = . - 1;
_OS_Default_Init_Task_CODE_LIMIT = .;
__OS_Default_Init_Task_CODE_START = _OS_Default_Init_Task_CODE_START;
__OS_Default_Init_Task_CODE_END = _OS_Default_Init_Task_CODE_END;
__OS_Default_Init_Task_CODE_LIMIT = _OS_Default_Init_Task_CODE_LIMIT;
.OS_EXT_INTP_CH03_CAT2_ISR_CODE ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_CODE_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_CODE_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_CODE_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_CODE_START = _OS_EXT_INTP_CH03_CAT2_ISR_CODE_START;
__OS_EXT_INTP_CH03_CAT2_ISR_CODE_END = _OS_EXT_INTP_CH03_CAT2_ISR_CODE_END;
__OS_EXT_INTP_CH03_CAT2_ISR_CODE_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_CODE_LIMIT;
.OS_EXT_INTP_CH07_CAT2_ISR_CODE ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_CODE_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_CODE_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_CODE_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_CODE_START = _OS_EXT_INTP_CH07_CAT2_ISR_CODE_START;
__OS_EXT_INTP_CH07_CAT2_ISR_CODE_END = _OS_EXT_INTP_CH07_CAT2_ISR_CODE_END;
__OS_EXT_INTP_CH07_CAT2_ISR_CODE_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_CODE_LIMIT;
.OS_EXT_INTP_CH17_CAT2_ISR_CODE ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_CODE_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_CODE_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_CODE_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_CODE_START = _OS_EXT_INTP_CH17_CAT2_ISR_CODE_START;
__OS_EXT_INTP_CH17_CAT2_ISR_CODE_END = _OS_EXT_INTP_CH17_CAT2_ISR_CODE_END;
__OS_EXT_INTP_CH17_CAT2_ISR_CODE_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_CODE_LIMIT;
.OS_I2c_IrqUnit0_CODE ALIGN(4) :> .
_OS_I2c_IrqUnit0_CODE_START = ADDR(.OS_I2c_IrqUnit0_CODE);
. = ALIGN(4);
_OS_I2c_IrqUnit0_CODE_END = . - 1;
_OS_I2c_IrqUnit0_CODE_LIMIT = .;
__OS_I2c_IrqUnit0_CODE_START = _OS_I2c_IrqUnit0_CODE_START;
__OS_I2c_IrqUnit0_CODE_END = _OS_I2c_IrqUnit0_CODE_END;
__OS_I2c_IrqUnit0_CODE_LIMIT = _OS_I2c_IrqUnit0_CODE_LIMIT;
.OS_IO_Task_CODE ALIGN(4) :> .
_OS_IO_Task_CODE_START = ADDR(.OS_IO_Task_CODE);
. = ALIGN(4);
_OS_IO_Task_CODE_END = . - 1;
_OS_IO_Task_CODE_LIMIT = .;
__OS_IO_Task_CODE_START = _OS_IO_Task_CODE_START;
__OS_IO_Task_CODE_END = _OS_IO_Task_CODE_END;
__OS_IO_Task_CODE_LIMIT = _OS_IO_Task_CODE_LIMIT;
.OS_MyTask_CODE ALIGN(4) :> .
_OS_MyTask_CODE_START = ADDR(.OS_MyTask_CODE);
. = ALIGN(4);
_OS_MyTask_CODE_END = . - 1;
_OS_MyTask_CODE_LIMIT = .;
__OS_MyTask_CODE_START = _OS_MyTask_CODE_START;
__OS_MyTask_CODE_END = _OS_MyTask_CODE_END;
__OS_MyTask_CODE_LIMIT = _OS_MyTask_CODE_LIMIT;
.OS_OsTask_ApplInitDeInit_CODE ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_CODE_START = ADDR(.OS_OsTask_ApplInitDeInit_CODE);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_CODE_END = . - 1;
_OS_OsTask_ApplInitDeInit_CODE_LIMIT = .;
__OS_OsTask_ApplInitDeInit_CODE_START = _OS_OsTask_ApplInitDeInit_CODE_START;
__OS_OsTask_ApplInitDeInit_CODE_END = _OS_OsTask_ApplInitDeInit_CODE_END;
__OS_OsTask_ApplInitDeInit_CODE_LIMIT = _OS_OsTask_ApplInitDeInit_CODE_LIMIT;
.OS_OsTask_ApplMainFunctions_CODE ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_CODE_START = ADDR(.OS_OsTask_ApplMainFunctions_CODE);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_CODE_END = . - 1;
_OS_OsTask_ApplMainFunctions_CODE_LIMIT = .;
__OS_OsTask_ApplMainFunctions_CODE_START = _OS_OsTask_ApplMainFunctions_CODE_START;
__OS_OsTask_ApplMainFunctions_CODE_END = _OS_OsTask_ApplMainFunctions_CODE_END;
__OS_OsTask_ApplMainFunctions_CODE_LIMIT = _OS_OsTask_ApplMainFunctions_CODE_LIMIT;
.OS_OsTask_ApplTimedInitDeInit_CODE ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_CODE_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_CODE);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_CODE_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_CODE_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_CODE_START = _OS_OsTask_ApplTimedInitDeInit_CODE_START;
__OS_OsTask_ApplTimedInitDeInit_CODE_END = _OS_OsTask_ApplTimedInitDeInit_CODE_END;
__OS_OsTask_ApplTimedInitDeInit_CODE_LIMIT = _OS_OsTask_ApplTimedInitDeInit_CODE_LIMIT;
.OS_OsTask_ApplVerify_CODE ALIGN(4) :> .
_OS_OsTask_ApplVerify_CODE_START = ADDR(.OS_OsTask_ApplVerify_CODE);
. = ALIGN(4);
_OS_OsTask_ApplVerify_CODE_END = . - 1;
_OS_OsTask_ApplVerify_CODE_LIMIT = .;
__OS_OsTask_ApplVerify_CODE_START = _OS_OsTask_ApplVerify_CODE_START;
__OS_OsTask_ApplVerify_CODE_END = _OS_OsTask_ApplVerify_CODE_END;
__OS_OsTask_ApplVerify_CODE_LIMIT = _OS_OsTask_ApplVerify_CODE_LIMIT;
.OS_OsTask_Background_CODE ALIGN(4) :> .
_OS_OsTask_Background_CODE_START = ADDR(.OS_OsTask_Background_CODE);
. = ALIGN(4);
_OS_OsTask_Background_CODE_END = . - 1;
_OS_OsTask_Background_CODE_LIMIT = .;
__OS_OsTask_Background_CODE_START = _OS_OsTask_Background_CODE_START;
__OS_OsTask_Background_CODE_END = _OS_OsTask_Background_CODE_END;
__OS_OsTask_Background_CODE_LIMIT = _OS_OsTask_Background_CODE_LIMIT;
.OS_OsTask_BswMainFunctions_CODE ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_CODE_START = ADDR(.OS_OsTask_BswMainFunctions_CODE);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_CODE_END = . - 1;
_OS_OsTask_BswMainFunctions_CODE_LIMIT = .;
__OS_OsTask_BswMainFunctions_CODE_START = _OS_OsTask_BswMainFunctions_CODE_START;
__OS_OsTask_BswMainFunctions_CODE_END = _OS_OsTask_BswMainFunctions_CODE_END;
__OS_OsTask_BswMainFunctions_CODE_LIMIT = _OS_OsTask_BswMainFunctions_CODE_LIMIT;
.OS_OsTask_Communication_CODE ALIGN(4) :> .
_OS_OsTask_Communication_CODE_START = ADDR(.OS_OsTask_Communication_CODE);
. = ALIGN(4);
_OS_OsTask_Communication_CODE_END = . - 1;
_OS_OsTask_Communication_CODE_LIMIT = .;
__OS_OsTask_Communication_CODE_START = _OS_OsTask_Communication_CODE_START;
__OS_OsTask_Communication_CODE_END = _OS_OsTask_Communication_CODE_END;
__OS_OsTask_Communication_CODE_LIMIT = _OS_OsTask_Communication_CODE_LIMIT;
.OS_OsTask_DcmSessionChanges_CODE ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_CODE_START = ADDR(.OS_OsTask_DcmSessionChanges_CODE);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_CODE_END = . - 1;
_OS_OsTask_DcmSessionChanges_CODE_LIMIT = .;
__OS_OsTask_DcmSessionChanges_CODE_START = _OS_OsTask_DcmSessionChanges_CODE_START;
__OS_OsTask_DcmSessionChanges_CODE_END = _OS_OsTask_DcmSessionChanges_CODE_END;
__OS_OsTask_DcmSessionChanges_CODE_LIMIT = _OS_OsTask_DcmSessionChanges_CODE_LIMIT;
.OS_OsTask_Dimming_CODE ALIGN(4) :> .
_OS_OsTask_Dimming_CODE_START = ADDR(.OS_OsTask_Dimming_CODE);
. = ALIGN(4);
_OS_OsTask_Dimming_CODE_END = . - 1;
_OS_OsTask_Dimming_CODE_LIMIT = .;
__OS_OsTask_Dimming_CODE_START = _OS_OsTask_Dimming_CODE_START;
__OS_OsTask_Dimming_CODE_END = _OS_OsTask_Dimming_CODE_END;
__OS_OsTask_Dimming_CODE_LIMIT = _OS_OsTask_Dimming_CODE_LIMIT;
.OS_OsTask_NvmAccess_CODE ALIGN(4) :> .
_OS_OsTask_NvmAccess_CODE_START = ADDR(.OS_OsTask_NvmAccess_CODE);
. = ALIGN(4);
_OS_OsTask_NvmAccess_CODE_END = . - 1;
_OS_OsTask_NvmAccess_CODE_LIMIT = .;
__OS_OsTask_NvmAccess_CODE_START = _OS_OsTask_NvmAccess_CODE_START;
__OS_OsTask_NvmAccess_CODE_END = _OS_OsTask_NvmAccess_CODE_END;
__OS_OsTask_NvmAccess_CODE_LIMIT = _OS_OsTask_NvmAccess_CODE_LIMIT;
.OS_OsTask_SelfDiagnostics_CODE ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_CODE_START = ADDR(.OS_OsTask_SelfDiagnostics_CODE);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_CODE_END = . - 1;
_OS_OsTask_SelfDiagnostics_CODE_LIMIT = .;
__OS_OsTask_SelfDiagnostics_CODE_START = _OS_OsTask_SelfDiagnostics_CODE_START;
__OS_OsTask_SelfDiagnostics_CODE_END = _OS_OsTask_SelfDiagnostics_CODE_END;
__OS_OsTask_SelfDiagnostics_CODE_LIMIT = _OS_OsTask_SelfDiagnostics_CODE_LIMIT;
.OS_OsTask_Touch_CODE ALIGN(4) :> .
_OS_OsTask_Touch_CODE_START = ADDR(.OS_OsTask_Touch_CODE);
. = ALIGN(4);
_OS_OsTask_Touch_CODE_END = . - 1;
_OS_OsTask_Touch_CODE_LIMIT = .;
__OS_OsTask_Touch_CODE_START = _OS_OsTask_Touch_CODE_START;
__OS_OsTask_Touch_CODE_END = _OS_OsTask_Touch_CODE_END;
__OS_OsTask_Touch_CODE_LIMIT = _OS_OsTask_Touch_CODE_LIMIT;
.OS_SPI_CSIH0_TIR_CAT2_ISR_CODE ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_CODE_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_CODE_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_CODE_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_CODE_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_CODE_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_CODE_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_CODE_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_CODE_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_CODE_LIMIT;
.OS_SPI_CSIH2_TIR_CAT2_ISR_CODE ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_CODE_LIMIT;
.OS_SPI_CSIH3_TIR_CAT2_ISR_CODE ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_CODE_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_CODE_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_CODE_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_CODE_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_CODE_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_CODE_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_CODE_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_CODE_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_CODE_LIMIT;
.OS_SwcDispCtrl_NauchLaufExpired_CODE ALIGN(4) :> .
_OS_SwcDispCtrl_NauchLaufExpired_CODE_START = ADDR(.OS_SwcDispCtrl_NauchLaufExpired_CODE);
. = ALIGN(4);
_OS_SwcDispCtrl_NauchLaufExpired_CODE_END = . - 1;
_OS_SwcDispCtrl_NauchLaufExpired_CODE_LIMIT = .;
__OS_SwcDispCtrl_NauchLaufExpired_CODE_START = _OS_SwcDispCtrl_NauchLaufExpired_CODE_START;
__OS_SwcDispCtrl_NauchLaufExpired_CODE_END = _OS_SwcDispCtrl_NauchLaufExpired_CODE_END;
__OS_SwcDispCtrl_NauchLaufExpired_CODE_LIMIT = _OS_SwcDispCtrl_NauchLaufExpired_CODE_LIMIT;
.OS_SwcDispCtrl_RetryDispOn_CODE ALIGN(4) :> .
_OS_SwcDispCtrl_RetryDispOn_CODE_START = ADDR(.OS_SwcDispCtrl_RetryDispOn_CODE);
. = ALIGN(4);
_OS_SwcDispCtrl_RetryDispOn_CODE_END = . - 1;
_OS_SwcDispCtrl_RetryDispOn_CODE_LIMIT = .;
__OS_SwcDispCtrl_RetryDispOn_CODE_START = _OS_SwcDispCtrl_RetryDispOn_CODE_START;
__OS_SwcDispCtrl_RetryDispOn_CODE_END = _OS_SwcDispCtrl_RetryDispOn_CODE_END;
__OS_SwcDispCtrl_RetryDispOn_CODE_LIMIT = _OS_SwcDispCtrl_RetryDispOn_CODE_LIMIT;
.OS_TAUD0_CH00_CAT2_ISR_CODE ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_CODE_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_CODE_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_CODE_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_CODE_START = _OS_TAUD0_CH00_CAT2_ISR_CODE_START;
__OS_TAUD0_CH00_CAT2_ISR_CODE_END = _OS_TAUD0_CH00_CAT2_ISR_CODE_END;
__OS_TAUD0_CH00_CAT2_ISR_CODE_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_CODE_LIMIT;
.OS_TAUD0_CH01_CAT2_ISR_CODE ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_CODE_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_CODE_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_CODE_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_CODE_START = _OS_TAUD0_CH01_CAT2_ISR_CODE_START;
__OS_TAUD0_CH01_CAT2_ISR_CODE_END = _OS_TAUD0_CH01_CAT2_ISR_CODE_END;
__OS_TAUD0_CH01_CAT2_ISR_CODE_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_CODE_LIMIT;
.OS_TAUD0_CH02_CAT2_ISR_CODE ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_CODE_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_CODE_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_CODE_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_CODE_START = _OS_TAUD0_CH02_CAT2_ISR_CODE_START;
__OS_TAUD0_CH02_CAT2_ISR_CODE_END = _OS_TAUD0_CH02_CAT2_ISR_CODE_END;
__OS_TAUD0_CH02_CAT2_ISR_CODE_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_CODE_LIMIT;
.OS_TAUD0_CH04_CAT2_ISR_CODE ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_CODE_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_CODE_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_CODE_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_CODE_START = _OS_TAUD0_CH04_CAT2_ISR_CODE_START;
__OS_TAUD0_CH04_CAT2_ISR_CODE_END = _OS_TAUD0_CH04_CAT2_ISR_CODE_END;
__OS_TAUD0_CH04_CAT2_ISR_CODE_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_CODE_LIMIT;
.OS_TAUD0_CH05_CAT2_ISR_CODE ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_CODE_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_CODE_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_CODE_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_CODE_START = _OS_TAUD0_CH05_CAT2_ISR_CODE_START;
__OS_TAUD0_CH05_CAT2_ISR_CODE_END = _OS_TAUD0_CH05_CAT2_ISR_CODE_END;
__OS_TAUD0_CH05_CAT2_ISR_CODE_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_CODE_LIMIT;
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CODE_LIMIT;
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_EXCVEC_CODE
# undef OS_LINK_EXCVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_FAR )
.OS_CORE0_CONST ALIGN(4) :> .
_OS_CORE0_CONST_START = ADDR(.OS_CORE0_CONST);
. = ALIGN(4);
_OS_CORE0_CONST_END = . - 1;
_OS_CORE0_CONST_LIMIT = .;
__OS_CORE0_CONST_START = _OS_CORE0_CONST_START;
__OS_CORE0_CONST_END = _OS_CORE0_CONST_END;
__OS_CORE0_CONST_LIMIT = _OS_CORE0_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_NEAR )
.OS_CORE0_CONST_FAST ALIGN(4) :> .
_OS_CORE0_CONST_FAST_START = ADDR(.OS_CORE0_CONST_FAST);
. = ALIGN(4);
_OS_CORE0_CONST_FAST_END = . - 1;
_OS_CORE0_CONST_FAST_LIMIT = .;
__OS_CORE0_CONST_FAST_START = _OS_CORE0_CONST_FAST_START;
__OS_CORE0_CONST_FAST_END = _OS_CORE0_CONST_FAST_END;
__OS_CORE0_CONST_FAST_LIMIT = _OS_CORE0_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_INTVEC_CONST )
.OS_INTVEC_CORE0_CONST ALIGN(512) :> .
_OS_INTVEC_CORE0_CONST_START = ADDR(.OS_INTVEC_CORE0_CONST);
. = ALIGN(4);
_OS_INTVEC_CORE0_CONST_END = . - 1;
_OS_INTVEC_CORE0_CONST_LIMIT = .;
__OS_INTVEC_CORE0_CONST_START = _OS_INTVEC_CORE0_CONST_START;
__OS_INTVEC_CORE0_CONST_END = _OS_INTVEC_CORE0_CONST_END;
__OS_INTVEC_CORE0_CONST_LIMIT = _OS_INTVEC_CORE0_CONST_LIMIT;
#endif

#if defined ( OS_LINK_EXCVEC_CONST )
.OS_EXCVEC_CORE0_CONST ALIGN(512) :> .
_OS_EXCVEC_CORE0_CONST_START = ADDR(.OS_EXCVEC_CORE0_CONST);
. = ALIGN(4);
_OS_EXCVEC_CORE0_CONST_END = . - 1;
_OS_EXCVEC_CORE0_CONST_LIMIT = .;
__OS_EXCVEC_CORE0_CONST_START = _OS_EXCVEC_CORE0_CONST_START;
__OS_EXCVEC_CORE0_CONST_END = _OS_EXCVEC_CORE0_CONST_END;
__OS_EXCVEC_CORE0_CONST_LIMIT = _OS_EXCVEC_CORE0_CONST_LIMIT;
#endif


#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR )
.OS_SystemApplication_OsCore0_CONST ALIGN(4) :> .
_OS_SystemApplication_OsCore0_CONST_START = ADDR(.OS_SystemApplication_OsCore0_CONST);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_CONST_END = . - 1;
_OS_SystemApplication_OsCore0_CONST_LIMIT = .;
__OS_SystemApplication_OsCore0_CONST_START = _OS_SystemApplication_OsCore0_CONST_START;
__OS_SystemApplication_OsCore0_CONST_END = _OS_SystemApplication_OsCore0_CONST_END;
__OS_SystemApplication_OsCore0_CONST_LIMIT = _OS_SystemApplication_OsCore0_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR )
.OS_SystemApplication_OsCore0_CONST_FAST ALIGN(4) :> .
_OS_SystemApplication_OsCore0_CONST_FAST_START = ADDR(.OS_SystemApplication_OsCore0_CONST_FAST);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_CONST_FAST_END = . - 1;
_OS_SystemApplication_OsCore0_CONST_FAST_LIMIT = .;
__OS_SystemApplication_OsCore0_CONST_FAST_START = _OS_SystemApplication_OsCore0_CONST_FAST_START;
__OS_SystemApplication_OsCore0_CONST_FAST_END = _OS_SystemApplication_OsCore0_CONST_FAST_END;
__OS_SystemApplication_OsCore0_CONST_FAST_LIMIT = _OS_SystemApplication_OsCore0_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT )

.ROM_OS_SystemApplication_OsCore0_VAR ROM(.OS_SystemApplication_OsCore0_VAR) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR);
_ROM_OS_SystemApplication_OsCore0_VAR_END = . - 1;
_ROM_OS_SystemApplication_OsCore0_VAR_LIMIT = .;
__ROM_OS_SystemApplication_OsCore0_VAR_START = _ROM_OS_SystemApplication_OsCore0_VAR_START;
__ROM_OS_SystemApplication_OsCore0_VAR_END = _ROM_OS_SystemApplication_OsCore0_VAR_END;
__ROM_OS_SystemApplication_OsCore0_VAR_LIMIT = _ROM_OS_SystemApplication_OsCore0_VAR_LIMIT;

.ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT ROM(.OS_SystemApplication_OsCore0_VAR_ZERO_INIT) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT);
_ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START = _ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START;
__ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END = _ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END;
__ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_LIMIT = _ROM_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_LIMIT;

.ROM_OS_SystemApplication_OsCore0_VAR_FAST ROM(.OS_SystemApplication_OsCore0_VAR_FAST) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST);
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_END = . - 1;
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_LIMIT = .;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_START = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_START;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_END = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_END;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_LIMIT = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_LIMIT;

.ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT ROM(.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT);
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_LIMIT;

.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE ROM(.OS_SystemApplication_OsCore0_VAR_NOCACHE) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE);
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_END = . - 1;
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_LIMIT = .;
__ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_START = _ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_START;
__ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_END = _ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_END;
__ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_LIMIT = _ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_LIMIT;

.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT ROM(.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT);
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START = _ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START;
__ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END = _ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END;
__ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT = _ROM_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT;

.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE ROM(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE);
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END = . - 1;
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_LIMIT = .;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_LIMIT = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_LIMIT;

.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT ROM(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT) :> .
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT);
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END;
__ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _ROM_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR )
.OS_Default_Init_Task_CONST ALIGN(4) :> .
_OS_Default_Init_Task_CONST_START = ADDR(.OS_Default_Init_Task_CONST);
. = ALIGN(4);
_OS_Default_Init_Task_CONST_END = . - 1;
_OS_Default_Init_Task_CONST_LIMIT = .;
__OS_Default_Init_Task_CONST_START = _OS_Default_Init_Task_CONST_START;
__OS_Default_Init_Task_CONST_END = _OS_Default_Init_Task_CONST_END;
__OS_Default_Init_Task_CONST_LIMIT = _OS_Default_Init_Task_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR )
.OS_Default_Init_Task_CONST_FAST ALIGN(4) :> .
_OS_Default_Init_Task_CONST_FAST_START = ADDR(.OS_Default_Init_Task_CONST_FAST);
. = ALIGN(4);
_OS_Default_Init_Task_CONST_FAST_END = . - 1;
_OS_Default_Init_Task_CONST_FAST_LIMIT = .;
__OS_Default_Init_Task_CONST_FAST_START = _OS_Default_Init_Task_CONST_FAST_START;
__OS_Default_Init_Task_CONST_FAST_END = _OS_Default_Init_Task_CONST_FAST_END;
__OS_Default_Init_Task_CONST_FAST_LIMIT = _OS_Default_Init_Task_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT )

.ROM_OS_Default_Init_Task_VAR ROM(.OS_Default_Init_Task_VAR) :> .
_ROM_OS_Default_Init_Task_VAR_START = ADDR(.ROM_OS_Default_Init_Task_VAR);
_ROM_OS_Default_Init_Task_VAR_END = . - 1;
_ROM_OS_Default_Init_Task_VAR_LIMIT = .;
__ROM_OS_Default_Init_Task_VAR_START = _ROM_OS_Default_Init_Task_VAR_START;
__ROM_OS_Default_Init_Task_VAR_END = _ROM_OS_Default_Init_Task_VAR_END;
__ROM_OS_Default_Init_Task_VAR_LIMIT = _ROM_OS_Default_Init_Task_VAR_LIMIT;

.ROM_OS_Default_Init_Task_VAR_NOINIT ROM(.OS_Default_Init_Task_VAR_NOINIT) :> .
_ROM_OS_Default_Init_Task_VAR_NOINIT_START = ADDR(.ROM_OS_Default_Init_Task_VAR_NOINIT);
_ROM_OS_Default_Init_Task_VAR_NOINIT_END = . - 1;
_ROM_OS_Default_Init_Task_VAR_NOINIT_LIMIT = .;
__ROM_OS_Default_Init_Task_VAR_NOINIT_START = _ROM_OS_Default_Init_Task_VAR_NOINIT_START;
__ROM_OS_Default_Init_Task_VAR_NOINIT_END = _ROM_OS_Default_Init_Task_VAR_NOINIT_END;
__ROM_OS_Default_Init_Task_VAR_NOINIT_LIMIT = _ROM_OS_Default_Init_Task_VAR_NOINIT_LIMIT;

.ROM_OS_Default_Init_Task_VAR_ZERO_INIT ROM(.OS_Default_Init_Task_VAR_ZERO_INIT) :> .
_ROM_OS_Default_Init_Task_VAR_ZERO_INIT_START = ADDR(.ROM_OS_Default_Init_Task_VAR_ZERO_INIT);
_ROM_OS_Default_Init_Task_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_Default_Init_Task_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_Default_Init_Task_VAR_ZERO_INIT_START = _ROM_OS_Default_Init_Task_VAR_ZERO_INIT_START;
__ROM_OS_Default_Init_Task_VAR_ZERO_INIT_END = _ROM_OS_Default_Init_Task_VAR_ZERO_INIT_END;
__ROM_OS_Default_Init_Task_VAR_ZERO_INIT_LIMIT = _ROM_OS_Default_Init_Task_VAR_ZERO_INIT_LIMIT;

.ROM_OS_Default_Init_Task_VAR_FAST ROM(.OS_Default_Init_Task_VAR_FAST) :> .
_ROM_OS_Default_Init_Task_VAR_FAST_START = ADDR(.ROM_OS_Default_Init_Task_VAR_FAST);
_ROM_OS_Default_Init_Task_VAR_FAST_END = . - 1;
_ROM_OS_Default_Init_Task_VAR_FAST_LIMIT = .;
__ROM_OS_Default_Init_Task_VAR_FAST_START = _ROM_OS_Default_Init_Task_VAR_FAST_START;
__ROM_OS_Default_Init_Task_VAR_FAST_END = _ROM_OS_Default_Init_Task_VAR_FAST_END;
__ROM_OS_Default_Init_Task_VAR_FAST_LIMIT = _ROM_OS_Default_Init_Task_VAR_FAST_LIMIT;

.ROM_OS_Default_Init_Task_VAR_FAST_NOINIT ROM(.OS_Default_Init_Task_VAR_FAST_NOINIT) :> .
_ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_Default_Init_Task_VAR_FAST_NOINIT);
_ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_START = _ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_START;
__ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_END = _ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_END;
__ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT = _ROM_OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT ROM(.OS_Default_Init_Task_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT);
_ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START = _ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START;
__ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END = _ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END;
__ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT
# undef OS_LINK_CONST_TASK_DEFAULT_INIT_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IO_TASK ) || defined ( OS_LINK_CONST_TASK_IO_TASK_FAR )
.OS_IO_Task_CONST ALIGN(4) :> .
_OS_IO_Task_CONST_START = ADDR(.OS_IO_Task_CONST);
. = ALIGN(4);
_OS_IO_Task_CONST_END = . - 1;
_OS_IO_Task_CONST_LIMIT = .;
__OS_IO_Task_CONST_START = _OS_IO_Task_CONST_START;
__OS_IO_Task_CONST_END = _OS_IO_Task_CONST_END;
__OS_IO_Task_CONST_LIMIT = _OS_IO_Task_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IO_TASK ) || defined ( OS_LINK_CONST_TASK_IO_TASK_NEAR )
.OS_IO_Task_CONST_FAST ALIGN(4) :> .
_OS_IO_Task_CONST_FAST_START = ADDR(.OS_IO_Task_CONST_FAST);
. = ALIGN(4);
_OS_IO_Task_CONST_FAST_END = . - 1;
_OS_IO_Task_CONST_FAST_LIMIT = .;
__OS_IO_Task_CONST_FAST_START = _OS_IO_Task_CONST_FAST_START;
__OS_IO_Task_CONST_FAST_END = _OS_IO_Task_CONST_FAST_END;
__OS_IO_Task_CONST_FAST_LIMIT = _OS_IO_Task_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IO_TASK ) || defined ( OS_LINK_CONST_TASK_IO_TASK_INIT )

.ROM_OS_IO_Task_VAR ROM(.OS_IO_Task_VAR) :> .
_ROM_OS_IO_Task_VAR_START = ADDR(.ROM_OS_IO_Task_VAR);
_ROM_OS_IO_Task_VAR_END = . - 1;
_ROM_OS_IO_Task_VAR_LIMIT = .;
__ROM_OS_IO_Task_VAR_START = _ROM_OS_IO_Task_VAR_START;
__ROM_OS_IO_Task_VAR_END = _ROM_OS_IO_Task_VAR_END;
__ROM_OS_IO_Task_VAR_LIMIT = _ROM_OS_IO_Task_VAR_LIMIT;

.ROM_OS_IO_Task_VAR_NOINIT ROM(.OS_IO_Task_VAR_NOINIT) :> .
_ROM_OS_IO_Task_VAR_NOINIT_START = ADDR(.ROM_OS_IO_Task_VAR_NOINIT);
_ROM_OS_IO_Task_VAR_NOINIT_END = . - 1;
_ROM_OS_IO_Task_VAR_NOINIT_LIMIT = .;
__ROM_OS_IO_Task_VAR_NOINIT_START = _ROM_OS_IO_Task_VAR_NOINIT_START;
__ROM_OS_IO_Task_VAR_NOINIT_END = _ROM_OS_IO_Task_VAR_NOINIT_END;
__ROM_OS_IO_Task_VAR_NOINIT_LIMIT = _ROM_OS_IO_Task_VAR_NOINIT_LIMIT;

.ROM_OS_IO_Task_VAR_ZERO_INIT ROM(.OS_IO_Task_VAR_ZERO_INIT) :> .
_ROM_OS_IO_Task_VAR_ZERO_INIT_START = ADDR(.ROM_OS_IO_Task_VAR_ZERO_INIT);
_ROM_OS_IO_Task_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_IO_Task_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_IO_Task_VAR_ZERO_INIT_START = _ROM_OS_IO_Task_VAR_ZERO_INIT_START;
__ROM_OS_IO_Task_VAR_ZERO_INIT_END = _ROM_OS_IO_Task_VAR_ZERO_INIT_END;
__ROM_OS_IO_Task_VAR_ZERO_INIT_LIMIT = _ROM_OS_IO_Task_VAR_ZERO_INIT_LIMIT;

.ROM_OS_IO_Task_VAR_FAST ROM(.OS_IO_Task_VAR_FAST) :> .
_ROM_OS_IO_Task_VAR_FAST_START = ADDR(.ROM_OS_IO_Task_VAR_FAST);
_ROM_OS_IO_Task_VAR_FAST_END = . - 1;
_ROM_OS_IO_Task_VAR_FAST_LIMIT = .;
__ROM_OS_IO_Task_VAR_FAST_START = _ROM_OS_IO_Task_VAR_FAST_START;
__ROM_OS_IO_Task_VAR_FAST_END = _ROM_OS_IO_Task_VAR_FAST_END;
__ROM_OS_IO_Task_VAR_FAST_LIMIT = _ROM_OS_IO_Task_VAR_FAST_LIMIT;

.ROM_OS_IO_Task_VAR_FAST_NOINIT ROM(.OS_IO_Task_VAR_FAST_NOINIT) :> .
_ROM_OS_IO_Task_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_IO_Task_VAR_FAST_NOINIT);
_ROM_OS_IO_Task_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_IO_Task_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_IO_Task_VAR_FAST_NOINIT_START = _ROM_OS_IO_Task_VAR_FAST_NOINIT_START;
__ROM_OS_IO_Task_VAR_FAST_NOINIT_END = _ROM_OS_IO_Task_VAR_FAST_NOINIT_END;
__ROM_OS_IO_Task_VAR_FAST_NOINIT_LIMIT = _ROM_OS_IO_Task_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_IO_Task_VAR_FAST_ZERO_INIT ROM(.OS_IO_Task_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_IO_Task_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_IO_Task_VAR_FAST_ZERO_INIT);
_ROM_OS_IO_Task_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_IO_Task_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_IO_Task_VAR_FAST_ZERO_INIT_START = _ROM_OS_IO_Task_VAR_FAST_ZERO_INIT_START;
__ROM_OS_IO_Task_VAR_FAST_ZERO_INIT_END = _ROM_OS_IO_Task_VAR_FAST_ZERO_INIT_END;
__ROM_OS_IO_Task_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_IO_Task_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_IO_TASK
# undef OS_LINK_CONST_TASK_IO_TASK
#endif

#ifdef OS_LINK_CONST_TASK_IO_TASK_FAR
# undef OS_LINK_CONST_TASK_IO_TASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_IO_TASK_NEAR
# undef OS_LINK_CONST_TASK_IO_TASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_IO_TASK_INIT
# undef OS_LINK_CONST_TASK_IO_TASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR )
.OS_IdleTask_OsCore0_CONST ALIGN(4) :> .
_OS_IdleTask_OsCore0_CONST_START = ADDR(.OS_IdleTask_OsCore0_CONST);
. = ALIGN(4);
_OS_IdleTask_OsCore0_CONST_END = . - 1;
_OS_IdleTask_OsCore0_CONST_LIMIT = .;
__OS_IdleTask_OsCore0_CONST_START = _OS_IdleTask_OsCore0_CONST_START;
__OS_IdleTask_OsCore0_CONST_END = _OS_IdleTask_OsCore0_CONST_END;
__OS_IdleTask_OsCore0_CONST_LIMIT = _OS_IdleTask_OsCore0_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR )
.OS_IdleTask_OsCore0_CONST_FAST ALIGN(4) :> .
_OS_IdleTask_OsCore0_CONST_FAST_START = ADDR(.OS_IdleTask_OsCore0_CONST_FAST);
. = ALIGN(4);
_OS_IdleTask_OsCore0_CONST_FAST_END = . - 1;
_OS_IdleTask_OsCore0_CONST_FAST_LIMIT = .;
__OS_IdleTask_OsCore0_CONST_FAST_START = _OS_IdleTask_OsCore0_CONST_FAST_START;
__OS_IdleTask_OsCore0_CONST_FAST_END = _OS_IdleTask_OsCore0_CONST_FAST_END;
__OS_IdleTask_OsCore0_CONST_FAST_LIMIT = _OS_IdleTask_OsCore0_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT )

.ROM_OS_IdleTask_OsCore0_VAR ROM(.OS_IdleTask_OsCore0_VAR) :> .
_ROM_OS_IdleTask_OsCore0_VAR_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR);
_ROM_OS_IdleTask_OsCore0_VAR_END = . - 1;
_ROM_OS_IdleTask_OsCore0_VAR_LIMIT = .;
__ROM_OS_IdleTask_OsCore0_VAR_START = _ROM_OS_IdleTask_OsCore0_VAR_START;
__ROM_OS_IdleTask_OsCore0_VAR_END = _ROM_OS_IdleTask_OsCore0_VAR_END;
__ROM_OS_IdleTask_OsCore0_VAR_LIMIT = _ROM_OS_IdleTask_OsCore0_VAR_LIMIT;

.ROM_OS_IdleTask_OsCore0_VAR_NOINIT ROM(.OS_IdleTask_OsCore0_VAR_NOINIT) :> .
_ROM_OS_IdleTask_OsCore0_VAR_NOINIT_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_NOINIT);
_ROM_OS_IdleTask_OsCore0_VAR_NOINIT_END = . - 1;
_ROM_OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT = .;
__ROM_OS_IdleTask_OsCore0_VAR_NOINIT_START = _ROM_OS_IdleTask_OsCore0_VAR_NOINIT_START;
__ROM_OS_IdleTask_OsCore0_VAR_NOINIT_END = _ROM_OS_IdleTask_OsCore0_VAR_NOINIT_END;
__ROM_OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT = _ROM_OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT;

.ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT ROM(.OS_IdleTask_OsCore0_VAR_ZERO_INIT) :> .
_ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT);
_ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START = _ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START;
__ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END = _ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END;
__ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_LIMIT = _ROM_OS_IdleTask_OsCore0_VAR_ZERO_INIT_LIMIT;

.ROM_OS_IdleTask_OsCore0_VAR_FAST ROM(.OS_IdleTask_OsCore0_VAR_FAST) :> .
_ROM_OS_IdleTask_OsCore0_VAR_FAST_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_FAST);
_ROM_OS_IdleTask_OsCore0_VAR_FAST_END = . - 1;
_ROM_OS_IdleTask_OsCore0_VAR_FAST_LIMIT = .;
__ROM_OS_IdleTask_OsCore0_VAR_FAST_START = _ROM_OS_IdleTask_OsCore0_VAR_FAST_START;
__ROM_OS_IdleTask_OsCore0_VAR_FAST_END = _ROM_OS_IdleTask_OsCore0_VAR_FAST_END;
__ROM_OS_IdleTask_OsCore0_VAR_FAST_LIMIT = _ROM_OS_IdleTask_OsCore0_VAR_FAST_LIMIT;

.ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT ROM(.OS_IdleTask_OsCore0_VAR_FAST_NOINIT) :> .
_ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT);
_ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START = _ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START;
__ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END = _ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END;
__ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT = _ROM_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT ROM(.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT);
_ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START = _ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START;
__ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END = _ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END;
__ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_MYTASK ) || defined ( OS_LINK_CONST_TASK_MYTASK_FAR )
.OS_MyTask_CONST ALIGN(4) :> .
_OS_MyTask_CONST_START = ADDR(.OS_MyTask_CONST);
. = ALIGN(4);
_OS_MyTask_CONST_END = . - 1;
_OS_MyTask_CONST_LIMIT = .;
__OS_MyTask_CONST_START = _OS_MyTask_CONST_START;
__OS_MyTask_CONST_END = _OS_MyTask_CONST_END;
__OS_MyTask_CONST_LIMIT = _OS_MyTask_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_MYTASK ) || defined ( OS_LINK_CONST_TASK_MYTASK_NEAR )
.OS_MyTask_CONST_FAST ALIGN(4) :> .
_OS_MyTask_CONST_FAST_START = ADDR(.OS_MyTask_CONST_FAST);
. = ALIGN(4);
_OS_MyTask_CONST_FAST_END = . - 1;
_OS_MyTask_CONST_FAST_LIMIT = .;
__OS_MyTask_CONST_FAST_START = _OS_MyTask_CONST_FAST_START;
__OS_MyTask_CONST_FAST_END = _OS_MyTask_CONST_FAST_END;
__OS_MyTask_CONST_FAST_LIMIT = _OS_MyTask_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_MYTASK ) || defined ( OS_LINK_CONST_TASK_MYTASK_INIT )

.ROM_OS_MyTask_VAR ROM(.OS_MyTask_VAR) :> .
_ROM_OS_MyTask_VAR_START = ADDR(.ROM_OS_MyTask_VAR);
_ROM_OS_MyTask_VAR_END = . - 1;
_ROM_OS_MyTask_VAR_LIMIT = .;
__ROM_OS_MyTask_VAR_START = _ROM_OS_MyTask_VAR_START;
__ROM_OS_MyTask_VAR_END = _ROM_OS_MyTask_VAR_END;
__ROM_OS_MyTask_VAR_LIMIT = _ROM_OS_MyTask_VAR_LIMIT;

.ROM_OS_MyTask_VAR_NOINIT ROM(.OS_MyTask_VAR_NOINIT) :> .
_ROM_OS_MyTask_VAR_NOINIT_START = ADDR(.ROM_OS_MyTask_VAR_NOINIT);
_ROM_OS_MyTask_VAR_NOINIT_END = . - 1;
_ROM_OS_MyTask_VAR_NOINIT_LIMIT = .;
__ROM_OS_MyTask_VAR_NOINIT_START = _ROM_OS_MyTask_VAR_NOINIT_START;
__ROM_OS_MyTask_VAR_NOINIT_END = _ROM_OS_MyTask_VAR_NOINIT_END;
__ROM_OS_MyTask_VAR_NOINIT_LIMIT = _ROM_OS_MyTask_VAR_NOINIT_LIMIT;

.ROM_OS_MyTask_VAR_ZERO_INIT ROM(.OS_MyTask_VAR_ZERO_INIT) :> .
_ROM_OS_MyTask_VAR_ZERO_INIT_START = ADDR(.ROM_OS_MyTask_VAR_ZERO_INIT);
_ROM_OS_MyTask_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_MyTask_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_MyTask_VAR_ZERO_INIT_START = _ROM_OS_MyTask_VAR_ZERO_INIT_START;
__ROM_OS_MyTask_VAR_ZERO_INIT_END = _ROM_OS_MyTask_VAR_ZERO_INIT_END;
__ROM_OS_MyTask_VAR_ZERO_INIT_LIMIT = _ROM_OS_MyTask_VAR_ZERO_INIT_LIMIT;

.ROM_OS_MyTask_VAR_FAST ROM(.OS_MyTask_VAR_FAST) :> .
_ROM_OS_MyTask_VAR_FAST_START = ADDR(.ROM_OS_MyTask_VAR_FAST);
_ROM_OS_MyTask_VAR_FAST_END = . - 1;
_ROM_OS_MyTask_VAR_FAST_LIMIT = .;
__ROM_OS_MyTask_VAR_FAST_START = _ROM_OS_MyTask_VAR_FAST_START;
__ROM_OS_MyTask_VAR_FAST_END = _ROM_OS_MyTask_VAR_FAST_END;
__ROM_OS_MyTask_VAR_FAST_LIMIT = _ROM_OS_MyTask_VAR_FAST_LIMIT;

.ROM_OS_MyTask_VAR_FAST_NOINIT ROM(.OS_MyTask_VAR_FAST_NOINIT) :> .
_ROM_OS_MyTask_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_MyTask_VAR_FAST_NOINIT);
_ROM_OS_MyTask_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_MyTask_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_MyTask_VAR_FAST_NOINIT_START = _ROM_OS_MyTask_VAR_FAST_NOINIT_START;
__ROM_OS_MyTask_VAR_FAST_NOINIT_END = _ROM_OS_MyTask_VAR_FAST_NOINIT_END;
__ROM_OS_MyTask_VAR_FAST_NOINIT_LIMIT = _ROM_OS_MyTask_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_MyTask_VAR_FAST_ZERO_INIT ROM(.OS_MyTask_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_MyTask_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_MyTask_VAR_FAST_ZERO_INIT);
_ROM_OS_MyTask_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_MyTask_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_MyTask_VAR_FAST_ZERO_INIT_START = _ROM_OS_MyTask_VAR_FAST_ZERO_INIT_START;
__ROM_OS_MyTask_VAR_FAST_ZERO_INIT_END = _ROM_OS_MyTask_VAR_FAST_ZERO_INIT_END;
__ROM_OS_MyTask_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_MyTask_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_MYTASK
# undef OS_LINK_CONST_TASK_MYTASK
#endif

#ifdef OS_LINK_CONST_TASK_MYTASK_FAR
# undef OS_LINK_CONST_TASK_MYTASK_FAR
#endif

#ifdef OS_LINK_CONST_TASK_MYTASK_NEAR
# undef OS_LINK_CONST_TASK_MYTASK_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_MYTASK_INIT
# undef OS_LINK_CONST_TASK_MYTASK_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT_FAR )
.OS_OsTask_ApplInitDeInit_CONST ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_CONST_START = ADDR(.OS_OsTask_ApplInitDeInit_CONST);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_CONST_END = . - 1;
_OS_OsTask_ApplInitDeInit_CONST_LIMIT = .;
__OS_OsTask_ApplInitDeInit_CONST_START = _OS_OsTask_ApplInitDeInit_CONST_START;
__OS_OsTask_ApplInitDeInit_CONST_END = _OS_OsTask_ApplInitDeInit_CONST_END;
__OS_OsTask_ApplInitDeInit_CONST_LIMIT = _OS_OsTask_ApplInitDeInit_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT_NEAR )
.OS_OsTask_ApplInitDeInit_CONST_FAST ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_CONST_FAST_START = ADDR(.OS_OsTask_ApplInitDeInit_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_CONST_FAST_END = . - 1;
_OS_OsTask_ApplInitDeInit_CONST_FAST_LIMIT = .;
__OS_OsTask_ApplInitDeInit_CONST_FAST_START = _OS_OsTask_ApplInitDeInit_CONST_FAST_START;
__OS_OsTask_ApplInitDeInit_CONST_FAST_END = _OS_OsTask_ApplInitDeInit_CONST_FAST_END;
__OS_OsTask_ApplInitDeInit_CONST_FAST_LIMIT = _OS_OsTask_ApplInitDeInit_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT_INIT )

.ROM_OS_OsTask_ApplInitDeInit_VAR ROM(.OS_OsTask_ApplInitDeInit_VAR) :> .
_ROM_OS_OsTask_ApplInitDeInit_VAR_START = ADDR(.ROM_OS_OsTask_ApplInitDeInit_VAR);
_ROM_OS_OsTask_ApplInitDeInit_VAR_END = . - 1;
_ROM_OS_OsTask_ApplInitDeInit_VAR_LIMIT = .;
__ROM_OS_OsTask_ApplInitDeInit_VAR_START = _ROM_OS_OsTask_ApplInitDeInit_VAR_START;
__ROM_OS_OsTask_ApplInitDeInit_VAR_END = _ROM_OS_OsTask_ApplInitDeInit_VAR_END;
__ROM_OS_OsTask_ApplInitDeInit_VAR_LIMIT = _ROM_OS_OsTask_ApplInitDeInit_VAR_LIMIT;

.ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT ROM(.OS_OsTask_ApplInitDeInit_VAR_NOINIT) :> .
_ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT);
_ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT_START = _ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT_START;
__ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT_END = _ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT_END;
__ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_ApplInitDeInit_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT ROM(.OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT);
_ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_START = _ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_END = _ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_ApplInitDeInit_VAR_FAST ROM(.OS_OsTask_ApplInitDeInit_VAR_FAST) :> .
_ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_START = ADDR(.ROM_OS_OsTask_ApplInitDeInit_VAR_FAST);
_ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_START = _ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_START;
__ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_END = _ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_END;
__ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_LIMIT = _ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_LIMIT;

.ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT ROM(.OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT);
_ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT
# undef OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT_FAR
# undef OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT_INIT
# undef OS_LINK_CONST_TASK_OSTASK_APPLINITDEINIT_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS_FAR )
.OS_OsTask_ApplMainFunctions_CONST ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_CONST_START = ADDR(.OS_OsTask_ApplMainFunctions_CONST);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_CONST_END = . - 1;
_OS_OsTask_ApplMainFunctions_CONST_LIMIT = .;
__OS_OsTask_ApplMainFunctions_CONST_START = _OS_OsTask_ApplMainFunctions_CONST_START;
__OS_OsTask_ApplMainFunctions_CONST_END = _OS_OsTask_ApplMainFunctions_CONST_END;
__OS_OsTask_ApplMainFunctions_CONST_LIMIT = _OS_OsTask_ApplMainFunctions_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR )
.OS_OsTask_ApplMainFunctions_CONST_FAST ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_CONST_FAST_START = ADDR(.OS_OsTask_ApplMainFunctions_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_CONST_FAST_END = . - 1;
_OS_OsTask_ApplMainFunctions_CONST_FAST_LIMIT = .;
__OS_OsTask_ApplMainFunctions_CONST_FAST_START = _OS_OsTask_ApplMainFunctions_CONST_FAST_START;
__OS_OsTask_ApplMainFunctions_CONST_FAST_END = _OS_OsTask_ApplMainFunctions_CONST_FAST_END;
__OS_OsTask_ApplMainFunctions_CONST_FAST_LIMIT = _OS_OsTask_ApplMainFunctions_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS_INIT )

.ROM_OS_OsTask_ApplMainFunctions_VAR ROM(.OS_OsTask_ApplMainFunctions_VAR) :> .
_ROM_OS_OsTask_ApplMainFunctions_VAR_START = ADDR(.ROM_OS_OsTask_ApplMainFunctions_VAR);
_ROM_OS_OsTask_ApplMainFunctions_VAR_END = . - 1;
_ROM_OS_OsTask_ApplMainFunctions_VAR_LIMIT = .;
__ROM_OS_OsTask_ApplMainFunctions_VAR_START = _ROM_OS_OsTask_ApplMainFunctions_VAR_START;
__ROM_OS_OsTask_ApplMainFunctions_VAR_END = _ROM_OS_OsTask_ApplMainFunctions_VAR_END;
__ROM_OS_OsTask_ApplMainFunctions_VAR_LIMIT = _ROM_OS_OsTask_ApplMainFunctions_VAR_LIMIT;

.ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT ROM(.OS_OsTask_ApplMainFunctions_VAR_NOINIT) :> .
_ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT);
_ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT_START = _ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT_START;
__ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT_END = _ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT_END;
__ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_ApplMainFunctions_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT ROM(.OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT);
_ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_START = _ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_END = _ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_ApplMainFunctions_VAR_FAST ROM(.OS_OsTask_ApplMainFunctions_VAR_FAST) :> .
_ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_START = ADDR(.ROM_OS_OsTask_ApplMainFunctions_VAR_FAST);
_ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_START = _ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_START;
__ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_END = _ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_END;
__ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_LIMIT = _ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_LIMIT;

.ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT ROM(.OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT);
_ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS
# undef OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS_FAR
# undef OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS_INIT
# undef OS_LINK_CONST_TASK_OSTASK_APPLMAINFUNCTIONS_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR )
.OS_OsTask_ApplTimedInitDeInit_CONST ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_CONST_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_CONST);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_CONST_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_CONST_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_CONST_START = _OS_OsTask_ApplTimedInitDeInit_CONST_START;
__OS_OsTask_ApplTimedInitDeInit_CONST_END = _OS_OsTask_ApplTimedInitDeInit_CONST_END;
__OS_OsTask_ApplTimedInitDeInit_CONST_LIMIT = _OS_OsTask_ApplTimedInitDeInit_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR )
.OS_OsTask_ApplTimedInitDeInit_CONST_FAST ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_CONST_FAST_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_CONST_FAST_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_CONST_FAST_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_CONST_FAST_START = _OS_OsTask_ApplTimedInitDeInit_CONST_FAST_START;
__OS_OsTask_ApplTimedInitDeInit_CONST_FAST_END = _OS_OsTask_ApplTimedInitDeInit_CONST_FAST_END;
__OS_OsTask_ApplTimedInitDeInit_CONST_FAST_LIMIT = _OS_OsTask_ApplTimedInitDeInit_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT_INIT )

.ROM_OS_OsTask_ApplTimedInitDeInit_VAR ROM(.OS_OsTask_ApplTimedInitDeInit_VAR) :> .
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_START = ADDR(.ROM_OS_OsTask_ApplTimedInitDeInit_VAR);
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_END = . - 1;
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_LIMIT = .;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_START = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_START;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_END = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_END;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_LIMIT = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_LIMIT;

.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT ROM(.OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT) :> .
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT);
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_START = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_START;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_END = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_END;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT ROM(.OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT);
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_START = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_END = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST ROM(.OS_OsTask_ApplTimedInitDeInit_VAR_FAST) :> .
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_START = ADDR(.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST);
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_START = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_START;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_END = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_END;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_LIMIT = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_LIMIT;

.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT ROM(.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT);
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT
# undef OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR
# undef OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT_INIT
# undef OS_LINK_CONST_TASK_OSTASK_APPLTIMEDINITDEINIT_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLVERIFY_FAR )
.OS_OsTask_ApplVerify_CONST ALIGN(4) :> .
_OS_OsTask_ApplVerify_CONST_START = ADDR(.OS_OsTask_ApplVerify_CONST);
. = ALIGN(4);
_OS_OsTask_ApplVerify_CONST_END = . - 1;
_OS_OsTask_ApplVerify_CONST_LIMIT = .;
__OS_OsTask_ApplVerify_CONST_START = _OS_OsTask_ApplVerify_CONST_START;
__OS_OsTask_ApplVerify_CONST_END = _OS_OsTask_ApplVerify_CONST_END;
__OS_OsTask_ApplVerify_CONST_LIMIT = _OS_OsTask_ApplVerify_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLVERIFY_NEAR )
.OS_OsTask_ApplVerify_CONST_FAST ALIGN(4) :> .
_OS_OsTask_ApplVerify_CONST_FAST_START = ADDR(.OS_OsTask_ApplVerify_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_ApplVerify_CONST_FAST_END = . - 1;
_OS_OsTask_ApplVerify_CONST_FAST_LIMIT = .;
__OS_OsTask_ApplVerify_CONST_FAST_START = _OS_OsTask_ApplVerify_CONST_FAST_START;
__OS_OsTask_ApplVerify_CONST_FAST_END = _OS_OsTask_ApplVerify_CONST_FAST_END;
__OS_OsTask_ApplVerify_CONST_FAST_LIMIT = _OS_OsTask_ApplVerify_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_CONST_TASK_OSTASK_APPLVERIFY_INIT )

.ROM_OS_OsTask_ApplVerify_VAR ROM(.OS_OsTask_ApplVerify_VAR) :> .
_ROM_OS_OsTask_ApplVerify_VAR_START = ADDR(.ROM_OS_OsTask_ApplVerify_VAR);
_ROM_OS_OsTask_ApplVerify_VAR_END = . - 1;
_ROM_OS_OsTask_ApplVerify_VAR_LIMIT = .;
__ROM_OS_OsTask_ApplVerify_VAR_START = _ROM_OS_OsTask_ApplVerify_VAR_START;
__ROM_OS_OsTask_ApplVerify_VAR_END = _ROM_OS_OsTask_ApplVerify_VAR_END;
__ROM_OS_OsTask_ApplVerify_VAR_LIMIT = _ROM_OS_OsTask_ApplVerify_VAR_LIMIT;

.ROM_OS_OsTask_ApplVerify_VAR_NOINIT ROM(.OS_OsTask_ApplVerify_VAR_NOINIT) :> .
_ROM_OS_OsTask_ApplVerify_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_ApplVerify_VAR_NOINIT);
_ROM_OS_OsTask_ApplVerify_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_ApplVerify_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_ApplVerify_VAR_NOINIT_START = _ROM_OS_OsTask_ApplVerify_VAR_NOINIT_START;
__ROM_OS_OsTask_ApplVerify_VAR_NOINIT_END = _ROM_OS_OsTask_ApplVerify_VAR_NOINIT_END;
__ROM_OS_OsTask_ApplVerify_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_ApplVerify_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT ROM(.OS_OsTask_ApplVerify_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT);
_ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT_START = _ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT_END = _ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_ApplVerify_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_ApplVerify_VAR_FAST ROM(.OS_OsTask_ApplVerify_VAR_FAST) :> .
_ROM_OS_OsTask_ApplVerify_VAR_FAST_START = ADDR(.ROM_OS_OsTask_ApplVerify_VAR_FAST);
_ROM_OS_OsTask_ApplVerify_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_ApplVerify_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_ApplVerify_VAR_FAST_START = _ROM_OS_OsTask_ApplVerify_VAR_FAST_START;
__ROM_OS_OsTask_ApplVerify_VAR_FAST_END = _ROM_OS_OsTask_ApplVerify_VAR_FAST_END;
__ROM_OS_OsTask_ApplVerify_VAR_FAST_LIMIT = _ROM_OS_OsTask_ApplVerify_VAR_FAST_LIMIT;

.ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT ROM(.OS_OsTask_ApplVerify_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT);
_ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLVERIFY
# undef OS_LINK_CONST_TASK_OSTASK_APPLVERIFY
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLVERIFY_FAR
# undef OS_LINK_CONST_TASK_OSTASK_APPLVERIFY_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLVERIFY_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_APPLVERIFY_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_APPLVERIFY_INIT
# undef OS_LINK_CONST_TASK_OSTASK_APPLVERIFY_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_CONST_TASK_OSTASK_BACKGROUND_FAR )
.OS_OsTask_Background_CONST ALIGN(4) :> .
_OS_OsTask_Background_CONST_START = ADDR(.OS_OsTask_Background_CONST);
. = ALIGN(4);
_OS_OsTask_Background_CONST_END = . - 1;
_OS_OsTask_Background_CONST_LIMIT = .;
__OS_OsTask_Background_CONST_START = _OS_OsTask_Background_CONST_START;
__OS_OsTask_Background_CONST_END = _OS_OsTask_Background_CONST_END;
__OS_OsTask_Background_CONST_LIMIT = _OS_OsTask_Background_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_CONST_TASK_OSTASK_BACKGROUND_NEAR )
.OS_OsTask_Background_CONST_FAST ALIGN(4) :> .
_OS_OsTask_Background_CONST_FAST_START = ADDR(.OS_OsTask_Background_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_Background_CONST_FAST_END = . - 1;
_OS_OsTask_Background_CONST_FAST_LIMIT = .;
__OS_OsTask_Background_CONST_FAST_START = _OS_OsTask_Background_CONST_FAST_START;
__OS_OsTask_Background_CONST_FAST_END = _OS_OsTask_Background_CONST_FAST_END;
__OS_OsTask_Background_CONST_FAST_LIMIT = _OS_OsTask_Background_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_CONST_TASK_OSTASK_BACKGROUND_INIT )

.ROM_OS_OsTask_Background_VAR ROM(.OS_OsTask_Background_VAR) :> .
_ROM_OS_OsTask_Background_VAR_START = ADDR(.ROM_OS_OsTask_Background_VAR);
_ROM_OS_OsTask_Background_VAR_END = . - 1;
_ROM_OS_OsTask_Background_VAR_LIMIT = .;
__ROM_OS_OsTask_Background_VAR_START = _ROM_OS_OsTask_Background_VAR_START;
__ROM_OS_OsTask_Background_VAR_END = _ROM_OS_OsTask_Background_VAR_END;
__ROM_OS_OsTask_Background_VAR_LIMIT = _ROM_OS_OsTask_Background_VAR_LIMIT;

.ROM_OS_OsTask_Background_VAR_NOINIT ROM(.OS_OsTask_Background_VAR_NOINIT) :> .
_ROM_OS_OsTask_Background_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_Background_VAR_NOINIT);
_ROM_OS_OsTask_Background_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_Background_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_Background_VAR_NOINIT_START = _ROM_OS_OsTask_Background_VAR_NOINIT_START;
__ROM_OS_OsTask_Background_VAR_NOINIT_END = _ROM_OS_OsTask_Background_VAR_NOINIT_END;
__ROM_OS_OsTask_Background_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_Background_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_Background_VAR_ZERO_INIT ROM(.OS_OsTask_Background_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_Background_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Background_VAR_ZERO_INIT);
_ROM_OS_OsTask_Background_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_Background_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_Background_VAR_ZERO_INIT_START = _ROM_OS_OsTask_Background_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_Background_VAR_ZERO_INIT_END = _ROM_OS_OsTask_Background_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_Background_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_Background_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_Background_VAR_FAST ROM(.OS_OsTask_Background_VAR_FAST) :> .
_ROM_OS_OsTask_Background_VAR_FAST_START = ADDR(.ROM_OS_OsTask_Background_VAR_FAST);
_ROM_OS_OsTask_Background_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_Background_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_Background_VAR_FAST_START = _ROM_OS_OsTask_Background_VAR_FAST_START;
__ROM_OS_OsTask_Background_VAR_FAST_END = _ROM_OS_OsTask_Background_VAR_FAST_END;
__ROM_OS_OsTask_Background_VAR_FAST_LIMIT = _ROM_OS_OsTask_Background_VAR_FAST_LIMIT;

.ROM_OS_OsTask_Background_VAR_FAST_NOINIT ROM(.OS_OsTask_Background_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_Background_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_Background_VAR_FAST_NOINIT);
_ROM_OS_OsTask_Background_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_Background_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_Background_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_Background_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_Background_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_Background_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_Background_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_Background_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_Background_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_Background_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BACKGROUND
# undef OS_LINK_CONST_TASK_OSTASK_BACKGROUND
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BACKGROUND_FAR
# undef OS_LINK_CONST_TASK_OSTASK_BACKGROUND_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BACKGROUND_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_BACKGROUND_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BACKGROUND_INIT
# undef OS_LINK_CONST_TASK_OSTASK_BACKGROUND_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS_FAR )
.OS_OsTask_BswMainFunctions_CONST ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_CONST_START = ADDR(.OS_OsTask_BswMainFunctions_CONST);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_CONST_END = . - 1;
_OS_OsTask_BswMainFunctions_CONST_LIMIT = .;
__OS_OsTask_BswMainFunctions_CONST_START = _OS_OsTask_BswMainFunctions_CONST_START;
__OS_OsTask_BswMainFunctions_CONST_END = _OS_OsTask_BswMainFunctions_CONST_END;
__OS_OsTask_BswMainFunctions_CONST_LIMIT = _OS_OsTask_BswMainFunctions_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR )
.OS_OsTask_BswMainFunctions_CONST_FAST ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_CONST_FAST_START = ADDR(.OS_OsTask_BswMainFunctions_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_CONST_FAST_END = . - 1;
_OS_OsTask_BswMainFunctions_CONST_FAST_LIMIT = .;
__OS_OsTask_BswMainFunctions_CONST_FAST_START = _OS_OsTask_BswMainFunctions_CONST_FAST_START;
__OS_OsTask_BswMainFunctions_CONST_FAST_END = _OS_OsTask_BswMainFunctions_CONST_FAST_END;
__OS_OsTask_BswMainFunctions_CONST_FAST_LIMIT = _OS_OsTask_BswMainFunctions_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS_INIT )

.ROM_OS_OsTask_BswMainFunctions_VAR ROM(.OS_OsTask_BswMainFunctions_VAR) :> .
_ROM_OS_OsTask_BswMainFunctions_VAR_START = ADDR(.ROM_OS_OsTask_BswMainFunctions_VAR);
_ROM_OS_OsTask_BswMainFunctions_VAR_END = . - 1;
_ROM_OS_OsTask_BswMainFunctions_VAR_LIMIT = .;
__ROM_OS_OsTask_BswMainFunctions_VAR_START = _ROM_OS_OsTask_BswMainFunctions_VAR_START;
__ROM_OS_OsTask_BswMainFunctions_VAR_END = _ROM_OS_OsTask_BswMainFunctions_VAR_END;
__ROM_OS_OsTask_BswMainFunctions_VAR_LIMIT = _ROM_OS_OsTask_BswMainFunctions_VAR_LIMIT;

.ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT ROM(.OS_OsTask_BswMainFunctions_VAR_NOINIT) :> .
_ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT);
_ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT_START = _ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT_START;
__ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT_END = _ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT_END;
__ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_BswMainFunctions_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT ROM(.OS_OsTask_BswMainFunctions_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT);
_ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_START = _ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_END = _ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_BswMainFunctions_VAR_FAST ROM(.OS_OsTask_BswMainFunctions_VAR_FAST) :> .
_ROM_OS_OsTask_BswMainFunctions_VAR_FAST_START = ADDR(.ROM_OS_OsTask_BswMainFunctions_VAR_FAST);
_ROM_OS_OsTask_BswMainFunctions_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_BswMainFunctions_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_BswMainFunctions_VAR_FAST_START = _ROM_OS_OsTask_BswMainFunctions_VAR_FAST_START;
__ROM_OS_OsTask_BswMainFunctions_VAR_FAST_END = _ROM_OS_OsTask_BswMainFunctions_VAR_FAST_END;
__ROM_OS_OsTask_BswMainFunctions_VAR_FAST_LIMIT = _ROM_OS_OsTask_BswMainFunctions_VAR_FAST_LIMIT;

.ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT ROM(.OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT);
_ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS
# undef OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS_FAR
# undef OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS_INIT
# undef OS_LINK_CONST_TASK_OSTASK_BSWMAINFUNCTIONS_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_CONST_TASK_OSTASK_COMMUNICATION_FAR )
.OS_OsTask_Communication_CONST ALIGN(4) :> .
_OS_OsTask_Communication_CONST_START = ADDR(.OS_OsTask_Communication_CONST);
. = ALIGN(4);
_OS_OsTask_Communication_CONST_END = . - 1;
_OS_OsTask_Communication_CONST_LIMIT = .;
__OS_OsTask_Communication_CONST_START = _OS_OsTask_Communication_CONST_START;
__OS_OsTask_Communication_CONST_END = _OS_OsTask_Communication_CONST_END;
__OS_OsTask_Communication_CONST_LIMIT = _OS_OsTask_Communication_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_CONST_TASK_OSTASK_COMMUNICATION_NEAR )
.OS_OsTask_Communication_CONST_FAST ALIGN(4) :> .
_OS_OsTask_Communication_CONST_FAST_START = ADDR(.OS_OsTask_Communication_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_Communication_CONST_FAST_END = . - 1;
_OS_OsTask_Communication_CONST_FAST_LIMIT = .;
__OS_OsTask_Communication_CONST_FAST_START = _OS_OsTask_Communication_CONST_FAST_START;
__OS_OsTask_Communication_CONST_FAST_END = _OS_OsTask_Communication_CONST_FAST_END;
__OS_OsTask_Communication_CONST_FAST_LIMIT = _OS_OsTask_Communication_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_CONST_TASK_OSTASK_COMMUNICATION_INIT )

.ROM_OS_OsTask_Communication_VAR ROM(.OS_OsTask_Communication_VAR) :> .
_ROM_OS_OsTask_Communication_VAR_START = ADDR(.ROM_OS_OsTask_Communication_VAR);
_ROM_OS_OsTask_Communication_VAR_END = . - 1;
_ROM_OS_OsTask_Communication_VAR_LIMIT = .;
__ROM_OS_OsTask_Communication_VAR_START = _ROM_OS_OsTask_Communication_VAR_START;
__ROM_OS_OsTask_Communication_VAR_END = _ROM_OS_OsTask_Communication_VAR_END;
__ROM_OS_OsTask_Communication_VAR_LIMIT = _ROM_OS_OsTask_Communication_VAR_LIMIT;

.ROM_OS_OsTask_Communication_VAR_NOINIT ROM(.OS_OsTask_Communication_VAR_NOINIT) :> .
_ROM_OS_OsTask_Communication_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_Communication_VAR_NOINIT);
_ROM_OS_OsTask_Communication_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_Communication_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_Communication_VAR_NOINIT_START = _ROM_OS_OsTask_Communication_VAR_NOINIT_START;
__ROM_OS_OsTask_Communication_VAR_NOINIT_END = _ROM_OS_OsTask_Communication_VAR_NOINIT_END;
__ROM_OS_OsTask_Communication_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_Communication_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_Communication_VAR_ZERO_INIT ROM(.OS_OsTask_Communication_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_Communication_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Communication_VAR_ZERO_INIT);
_ROM_OS_OsTask_Communication_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_Communication_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_Communication_VAR_ZERO_INIT_START = _ROM_OS_OsTask_Communication_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_Communication_VAR_ZERO_INIT_END = _ROM_OS_OsTask_Communication_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_Communication_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_Communication_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_Communication_VAR_FAST ROM(.OS_OsTask_Communication_VAR_FAST) :> .
_ROM_OS_OsTask_Communication_VAR_FAST_START = ADDR(.ROM_OS_OsTask_Communication_VAR_FAST);
_ROM_OS_OsTask_Communication_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_Communication_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_Communication_VAR_FAST_START = _ROM_OS_OsTask_Communication_VAR_FAST_START;
__ROM_OS_OsTask_Communication_VAR_FAST_END = _ROM_OS_OsTask_Communication_VAR_FAST_END;
__ROM_OS_OsTask_Communication_VAR_FAST_LIMIT = _ROM_OS_OsTask_Communication_VAR_FAST_LIMIT;

.ROM_OS_OsTask_Communication_VAR_FAST_NOINIT ROM(.OS_OsTask_Communication_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_Communication_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_Communication_VAR_FAST_NOINIT);
_ROM_OS_OsTask_Communication_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_Communication_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_Communication_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_Communication_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_Communication_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_Communication_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_Communication_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_Communication_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_Communication_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_COMMUNICATION
# undef OS_LINK_CONST_TASK_OSTASK_COMMUNICATION
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_COMMUNICATION_FAR
# undef OS_LINK_CONST_TASK_OSTASK_COMMUNICATION_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_COMMUNICATION_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_COMMUNICATION_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_COMMUNICATION_INIT
# undef OS_LINK_CONST_TASK_OSTASK_COMMUNICATION_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES_FAR )
.OS_OsTask_DcmSessionChanges_CONST ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_CONST_START = ADDR(.OS_OsTask_DcmSessionChanges_CONST);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_CONST_END = . - 1;
_OS_OsTask_DcmSessionChanges_CONST_LIMIT = .;
__OS_OsTask_DcmSessionChanges_CONST_START = _OS_OsTask_DcmSessionChanges_CONST_START;
__OS_OsTask_DcmSessionChanges_CONST_END = _OS_OsTask_DcmSessionChanges_CONST_END;
__OS_OsTask_DcmSessionChanges_CONST_LIMIT = _OS_OsTask_DcmSessionChanges_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES_NEAR )
.OS_OsTask_DcmSessionChanges_CONST_FAST ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_CONST_FAST_START = ADDR(.OS_OsTask_DcmSessionChanges_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_CONST_FAST_END = . - 1;
_OS_OsTask_DcmSessionChanges_CONST_FAST_LIMIT = .;
__OS_OsTask_DcmSessionChanges_CONST_FAST_START = _OS_OsTask_DcmSessionChanges_CONST_FAST_START;
__OS_OsTask_DcmSessionChanges_CONST_FAST_END = _OS_OsTask_DcmSessionChanges_CONST_FAST_END;
__OS_OsTask_DcmSessionChanges_CONST_FAST_LIMIT = _OS_OsTask_DcmSessionChanges_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES_INIT )

.ROM_OS_OsTask_DcmSessionChanges_VAR ROM(.OS_OsTask_DcmSessionChanges_VAR) :> .
_ROM_OS_OsTask_DcmSessionChanges_VAR_START = ADDR(.ROM_OS_OsTask_DcmSessionChanges_VAR);
_ROM_OS_OsTask_DcmSessionChanges_VAR_END = . - 1;
_ROM_OS_OsTask_DcmSessionChanges_VAR_LIMIT = .;
__ROM_OS_OsTask_DcmSessionChanges_VAR_START = _ROM_OS_OsTask_DcmSessionChanges_VAR_START;
__ROM_OS_OsTask_DcmSessionChanges_VAR_END = _ROM_OS_OsTask_DcmSessionChanges_VAR_END;
__ROM_OS_OsTask_DcmSessionChanges_VAR_LIMIT = _ROM_OS_OsTask_DcmSessionChanges_VAR_LIMIT;

.ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT ROM(.OS_OsTask_DcmSessionChanges_VAR_NOINIT) :> .
_ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT);
_ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT_START = _ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT_START;
__ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT_END = _ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT_END;
__ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_DcmSessionChanges_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT ROM(.OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT);
_ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_START = _ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_END = _ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_DcmSessionChanges_VAR_FAST ROM(.OS_OsTask_DcmSessionChanges_VAR_FAST) :> .
_ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_START = ADDR(.ROM_OS_OsTask_DcmSessionChanges_VAR_FAST);
_ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_START = _ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_START;
__ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_END = _ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_END;
__ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_LIMIT = _ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_LIMIT;

.ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT ROM(.OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT);
_ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES
# undef OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES_FAR
# undef OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES_INIT
# undef OS_LINK_CONST_TASK_OSTASK_DCMSESSIONCHANGES_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_CONST_TASK_OSTASK_DIMMING_FAR )
.OS_OsTask_Dimming_CONST ALIGN(4) :> .
_OS_OsTask_Dimming_CONST_START = ADDR(.OS_OsTask_Dimming_CONST);
. = ALIGN(4);
_OS_OsTask_Dimming_CONST_END = . - 1;
_OS_OsTask_Dimming_CONST_LIMIT = .;
__OS_OsTask_Dimming_CONST_START = _OS_OsTask_Dimming_CONST_START;
__OS_OsTask_Dimming_CONST_END = _OS_OsTask_Dimming_CONST_END;
__OS_OsTask_Dimming_CONST_LIMIT = _OS_OsTask_Dimming_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_CONST_TASK_OSTASK_DIMMING_NEAR )
.OS_OsTask_Dimming_CONST_FAST ALIGN(4) :> .
_OS_OsTask_Dimming_CONST_FAST_START = ADDR(.OS_OsTask_Dimming_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_Dimming_CONST_FAST_END = . - 1;
_OS_OsTask_Dimming_CONST_FAST_LIMIT = .;
__OS_OsTask_Dimming_CONST_FAST_START = _OS_OsTask_Dimming_CONST_FAST_START;
__OS_OsTask_Dimming_CONST_FAST_END = _OS_OsTask_Dimming_CONST_FAST_END;
__OS_OsTask_Dimming_CONST_FAST_LIMIT = _OS_OsTask_Dimming_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_CONST_TASK_OSTASK_DIMMING_INIT )

.ROM_OS_OsTask_Dimming_VAR ROM(.OS_OsTask_Dimming_VAR) :> .
_ROM_OS_OsTask_Dimming_VAR_START = ADDR(.ROM_OS_OsTask_Dimming_VAR);
_ROM_OS_OsTask_Dimming_VAR_END = . - 1;
_ROM_OS_OsTask_Dimming_VAR_LIMIT = .;
__ROM_OS_OsTask_Dimming_VAR_START = _ROM_OS_OsTask_Dimming_VAR_START;
__ROM_OS_OsTask_Dimming_VAR_END = _ROM_OS_OsTask_Dimming_VAR_END;
__ROM_OS_OsTask_Dimming_VAR_LIMIT = _ROM_OS_OsTask_Dimming_VAR_LIMIT;

.ROM_OS_OsTask_Dimming_VAR_NOINIT ROM(.OS_OsTask_Dimming_VAR_NOINIT) :> .
_ROM_OS_OsTask_Dimming_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_Dimming_VAR_NOINIT);
_ROM_OS_OsTask_Dimming_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_Dimming_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_Dimming_VAR_NOINIT_START = _ROM_OS_OsTask_Dimming_VAR_NOINIT_START;
__ROM_OS_OsTask_Dimming_VAR_NOINIT_END = _ROM_OS_OsTask_Dimming_VAR_NOINIT_END;
__ROM_OS_OsTask_Dimming_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_Dimming_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_Dimming_VAR_ZERO_INIT ROM(.OS_OsTask_Dimming_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_Dimming_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Dimming_VAR_ZERO_INIT);
_ROM_OS_OsTask_Dimming_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_Dimming_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_Dimming_VAR_ZERO_INIT_START = _ROM_OS_OsTask_Dimming_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_Dimming_VAR_ZERO_INIT_END = _ROM_OS_OsTask_Dimming_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_Dimming_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_Dimming_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_Dimming_VAR_FAST ROM(.OS_OsTask_Dimming_VAR_FAST) :> .
_ROM_OS_OsTask_Dimming_VAR_FAST_START = ADDR(.ROM_OS_OsTask_Dimming_VAR_FAST);
_ROM_OS_OsTask_Dimming_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_Dimming_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_Dimming_VAR_FAST_START = _ROM_OS_OsTask_Dimming_VAR_FAST_START;
__ROM_OS_OsTask_Dimming_VAR_FAST_END = _ROM_OS_OsTask_Dimming_VAR_FAST_END;
__ROM_OS_OsTask_Dimming_VAR_FAST_LIMIT = _ROM_OS_OsTask_Dimming_VAR_FAST_LIMIT;

.ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT ROM(.OS_OsTask_Dimming_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT);
_ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_Dimming_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_Dimming_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_DIMMING
# undef OS_LINK_CONST_TASK_OSTASK_DIMMING
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_DIMMING_FAR
# undef OS_LINK_CONST_TASK_OSTASK_DIMMING_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_DIMMING_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_DIMMING_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_DIMMING_INIT
# undef OS_LINK_CONST_TASK_OSTASK_DIMMING_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_CONST_TASK_OSTASK_NVMACCESS_FAR )
.OS_OsTask_NvmAccess_CONST ALIGN(4) :> .
_OS_OsTask_NvmAccess_CONST_START = ADDR(.OS_OsTask_NvmAccess_CONST);
. = ALIGN(4);
_OS_OsTask_NvmAccess_CONST_END = . - 1;
_OS_OsTask_NvmAccess_CONST_LIMIT = .;
__OS_OsTask_NvmAccess_CONST_START = _OS_OsTask_NvmAccess_CONST_START;
__OS_OsTask_NvmAccess_CONST_END = _OS_OsTask_NvmAccess_CONST_END;
__OS_OsTask_NvmAccess_CONST_LIMIT = _OS_OsTask_NvmAccess_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_CONST_TASK_OSTASK_NVMACCESS_NEAR )
.OS_OsTask_NvmAccess_CONST_FAST ALIGN(4) :> .
_OS_OsTask_NvmAccess_CONST_FAST_START = ADDR(.OS_OsTask_NvmAccess_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_NvmAccess_CONST_FAST_END = . - 1;
_OS_OsTask_NvmAccess_CONST_FAST_LIMIT = .;
__OS_OsTask_NvmAccess_CONST_FAST_START = _OS_OsTask_NvmAccess_CONST_FAST_START;
__OS_OsTask_NvmAccess_CONST_FAST_END = _OS_OsTask_NvmAccess_CONST_FAST_END;
__OS_OsTask_NvmAccess_CONST_FAST_LIMIT = _OS_OsTask_NvmAccess_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_CONST_TASK_OSTASK_NVMACCESS_INIT )

.ROM_OS_OsTask_NvmAccess_VAR ROM(.OS_OsTask_NvmAccess_VAR) :> .
_ROM_OS_OsTask_NvmAccess_VAR_START = ADDR(.ROM_OS_OsTask_NvmAccess_VAR);
_ROM_OS_OsTask_NvmAccess_VAR_END = . - 1;
_ROM_OS_OsTask_NvmAccess_VAR_LIMIT = .;
__ROM_OS_OsTask_NvmAccess_VAR_START = _ROM_OS_OsTask_NvmAccess_VAR_START;
__ROM_OS_OsTask_NvmAccess_VAR_END = _ROM_OS_OsTask_NvmAccess_VAR_END;
__ROM_OS_OsTask_NvmAccess_VAR_LIMIT = _ROM_OS_OsTask_NvmAccess_VAR_LIMIT;

.ROM_OS_OsTask_NvmAccess_VAR_NOINIT ROM(.OS_OsTask_NvmAccess_VAR_NOINIT) :> .
_ROM_OS_OsTask_NvmAccess_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_NvmAccess_VAR_NOINIT);
_ROM_OS_OsTask_NvmAccess_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_NvmAccess_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_NvmAccess_VAR_NOINIT_START = _ROM_OS_OsTask_NvmAccess_VAR_NOINIT_START;
__ROM_OS_OsTask_NvmAccess_VAR_NOINIT_END = _ROM_OS_OsTask_NvmAccess_VAR_NOINIT_END;
__ROM_OS_OsTask_NvmAccess_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_NvmAccess_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT ROM(.OS_OsTask_NvmAccess_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT);
_ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT_START = _ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT_END = _ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_NvmAccess_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_NvmAccess_VAR_FAST ROM(.OS_OsTask_NvmAccess_VAR_FAST) :> .
_ROM_OS_OsTask_NvmAccess_VAR_FAST_START = ADDR(.ROM_OS_OsTask_NvmAccess_VAR_FAST);
_ROM_OS_OsTask_NvmAccess_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_NvmAccess_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_NvmAccess_VAR_FAST_START = _ROM_OS_OsTask_NvmAccess_VAR_FAST_START;
__ROM_OS_OsTask_NvmAccess_VAR_FAST_END = _ROM_OS_OsTask_NvmAccess_VAR_FAST_END;
__ROM_OS_OsTask_NvmAccess_VAR_FAST_LIMIT = _ROM_OS_OsTask_NvmAccess_VAR_FAST_LIMIT;

.ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT ROM(.OS_OsTask_NvmAccess_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT);
_ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_NVMACCESS
# undef OS_LINK_CONST_TASK_OSTASK_NVMACCESS
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_NVMACCESS_FAR
# undef OS_LINK_CONST_TASK_OSTASK_NVMACCESS_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_NVMACCESS_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_NVMACCESS_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_NVMACCESS_INIT
# undef OS_LINK_CONST_TASK_OSTASK_NVMACCESS_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS_FAR )
.OS_OsTask_SelfDiagnostics_CONST ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_CONST_START = ADDR(.OS_OsTask_SelfDiagnostics_CONST);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_CONST_END = . - 1;
_OS_OsTask_SelfDiagnostics_CONST_LIMIT = .;
__OS_OsTask_SelfDiagnostics_CONST_START = _OS_OsTask_SelfDiagnostics_CONST_START;
__OS_OsTask_SelfDiagnostics_CONST_END = _OS_OsTask_SelfDiagnostics_CONST_END;
__OS_OsTask_SelfDiagnostics_CONST_LIMIT = _OS_OsTask_SelfDiagnostics_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS_NEAR )
.OS_OsTask_SelfDiagnostics_CONST_FAST ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_CONST_FAST_START = ADDR(.OS_OsTask_SelfDiagnostics_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_CONST_FAST_END = . - 1;
_OS_OsTask_SelfDiagnostics_CONST_FAST_LIMIT = .;
__OS_OsTask_SelfDiagnostics_CONST_FAST_START = _OS_OsTask_SelfDiagnostics_CONST_FAST_START;
__OS_OsTask_SelfDiagnostics_CONST_FAST_END = _OS_OsTask_SelfDiagnostics_CONST_FAST_END;
__OS_OsTask_SelfDiagnostics_CONST_FAST_LIMIT = _OS_OsTask_SelfDiagnostics_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS_INIT )

.ROM_OS_OsTask_SelfDiagnostics_VAR ROM(.OS_OsTask_SelfDiagnostics_VAR) :> .
_ROM_OS_OsTask_SelfDiagnostics_VAR_START = ADDR(.ROM_OS_OsTask_SelfDiagnostics_VAR);
_ROM_OS_OsTask_SelfDiagnostics_VAR_END = . - 1;
_ROM_OS_OsTask_SelfDiagnostics_VAR_LIMIT = .;
__ROM_OS_OsTask_SelfDiagnostics_VAR_START = _ROM_OS_OsTask_SelfDiagnostics_VAR_START;
__ROM_OS_OsTask_SelfDiagnostics_VAR_END = _ROM_OS_OsTask_SelfDiagnostics_VAR_END;
__ROM_OS_OsTask_SelfDiagnostics_VAR_LIMIT = _ROM_OS_OsTask_SelfDiagnostics_VAR_LIMIT;

.ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT ROM(.OS_OsTask_SelfDiagnostics_VAR_NOINIT) :> .
_ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT);
_ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT_START = _ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT_START;
__ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT_END = _ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT_END;
__ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_SelfDiagnostics_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT ROM(.OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT);
_ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_START = _ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_END = _ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_SelfDiagnostics_VAR_FAST ROM(.OS_OsTask_SelfDiagnostics_VAR_FAST) :> .
_ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_START = ADDR(.ROM_OS_OsTask_SelfDiagnostics_VAR_FAST);
_ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_START = _ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_START;
__ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_END = _ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_END;
__ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_LIMIT = _ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_LIMIT;

.ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT ROM(.OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT);
_ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS
# undef OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS_FAR
# undef OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS_INIT
# undef OS_LINK_CONST_TASK_OSTASK_SELFDIAGNOSTICS_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_CONST_TASK_OSTASK_TOUCH_FAR )
.OS_OsTask_Touch_CONST ALIGN(4) :> .
_OS_OsTask_Touch_CONST_START = ADDR(.OS_OsTask_Touch_CONST);
. = ALIGN(4);
_OS_OsTask_Touch_CONST_END = . - 1;
_OS_OsTask_Touch_CONST_LIMIT = .;
__OS_OsTask_Touch_CONST_START = _OS_OsTask_Touch_CONST_START;
__OS_OsTask_Touch_CONST_END = _OS_OsTask_Touch_CONST_END;
__OS_OsTask_Touch_CONST_LIMIT = _OS_OsTask_Touch_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_CONST_TASK_OSTASK_TOUCH_NEAR )
.OS_OsTask_Touch_CONST_FAST ALIGN(4) :> .
_OS_OsTask_Touch_CONST_FAST_START = ADDR(.OS_OsTask_Touch_CONST_FAST);
. = ALIGN(4);
_OS_OsTask_Touch_CONST_FAST_END = . - 1;
_OS_OsTask_Touch_CONST_FAST_LIMIT = .;
__OS_OsTask_Touch_CONST_FAST_START = _OS_OsTask_Touch_CONST_FAST_START;
__OS_OsTask_Touch_CONST_FAST_END = _OS_OsTask_Touch_CONST_FAST_END;
__OS_OsTask_Touch_CONST_FAST_LIMIT = _OS_OsTask_Touch_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_CONST_TASK_OSTASK_TOUCH_INIT )

.ROM_OS_OsTask_Touch_VAR ROM(.OS_OsTask_Touch_VAR) :> .
_ROM_OS_OsTask_Touch_VAR_START = ADDR(.ROM_OS_OsTask_Touch_VAR);
_ROM_OS_OsTask_Touch_VAR_END = . - 1;
_ROM_OS_OsTask_Touch_VAR_LIMIT = .;
__ROM_OS_OsTask_Touch_VAR_START = _ROM_OS_OsTask_Touch_VAR_START;
__ROM_OS_OsTask_Touch_VAR_END = _ROM_OS_OsTask_Touch_VAR_END;
__ROM_OS_OsTask_Touch_VAR_LIMIT = _ROM_OS_OsTask_Touch_VAR_LIMIT;

.ROM_OS_OsTask_Touch_VAR_NOINIT ROM(.OS_OsTask_Touch_VAR_NOINIT) :> .
_ROM_OS_OsTask_Touch_VAR_NOINIT_START = ADDR(.ROM_OS_OsTask_Touch_VAR_NOINIT);
_ROM_OS_OsTask_Touch_VAR_NOINIT_END = . - 1;
_ROM_OS_OsTask_Touch_VAR_NOINIT_LIMIT = .;
__ROM_OS_OsTask_Touch_VAR_NOINIT_START = _ROM_OS_OsTask_Touch_VAR_NOINIT_START;
__ROM_OS_OsTask_Touch_VAR_NOINIT_END = _ROM_OS_OsTask_Touch_VAR_NOINIT_END;
__ROM_OS_OsTask_Touch_VAR_NOINIT_LIMIT = _ROM_OS_OsTask_Touch_VAR_NOINIT_LIMIT;

.ROM_OS_OsTask_Touch_VAR_ZERO_INIT ROM(.OS_OsTask_Touch_VAR_ZERO_INIT) :> .
_ROM_OS_OsTask_Touch_VAR_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Touch_VAR_ZERO_INIT);
_ROM_OS_OsTask_Touch_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_Touch_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_Touch_VAR_ZERO_INIT_START = _ROM_OS_OsTask_Touch_VAR_ZERO_INIT_START;
__ROM_OS_OsTask_Touch_VAR_ZERO_INIT_END = _ROM_OS_OsTask_Touch_VAR_ZERO_INIT_END;
__ROM_OS_OsTask_Touch_VAR_ZERO_INIT_LIMIT = _ROM_OS_OsTask_Touch_VAR_ZERO_INIT_LIMIT;

.ROM_OS_OsTask_Touch_VAR_FAST ROM(.OS_OsTask_Touch_VAR_FAST) :> .
_ROM_OS_OsTask_Touch_VAR_FAST_START = ADDR(.ROM_OS_OsTask_Touch_VAR_FAST);
_ROM_OS_OsTask_Touch_VAR_FAST_END = . - 1;
_ROM_OS_OsTask_Touch_VAR_FAST_LIMIT = .;
__ROM_OS_OsTask_Touch_VAR_FAST_START = _ROM_OS_OsTask_Touch_VAR_FAST_START;
__ROM_OS_OsTask_Touch_VAR_FAST_END = _ROM_OS_OsTask_Touch_VAR_FAST_END;
__ROM_OS_OsTask_Touch_VAR_FAST_LIMIT = _ROM_OS_OsTask_Touch_VAR_FAST_LIMIT;

.ROM_OS_OsTask_Touch_VAR_FAST_NOINIT ROM(.OS_OsTask_Touch_VAR_FAST_NOINIT) :> .
_ROM_OS_OsTask_Touch_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_OsTask_Touch_VAR_FAST_NOINIT);
_ROM_OS_OsTask_Touch_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_OsTask_Touch_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_OsTask_Touch_VAR_FAST_NOINIT_START = _ROM_OS_OsTask_Touch_VAR_FAST_NOINIT_START;
__ROM_OS_OsTask_Touch_VAR_FAST_NOINIT_END = _ROM_OS_OsTask_Touch_VAR_FAST_NOINIT_END;
__ROM_OS_OsTask_Touch_VAR_FAST_NOINIT_LIMIT = _ROM_OS_OsTask_Touch_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT ROM(.OS_OsTask_Touch_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT);
_ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_START = _ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_START;
__ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_END = _ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_END;
__ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_TOUCH
# undef OS_LINK_CONST_TASK_OSTASK_TOUCH
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_TOUCH_FAR
# undef OS_LINK_CONST_TASK_OSTASK_TOUCH_FAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_TOUCH_NEAR
# undef OS_LINK_CONST_TASK_OSTASK_TOUCH_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_OSTASK_TOUCH_INIT
# undef OS_LINK_CONST_TASK_OSTASK_TOUCH_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR_FAR )
.OS_ADC0_SG1_CAT2_ISR_CONST ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_CONST_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_CONST_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_CONST_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_CONST_START = _OS_ADC0_SG1_CAT2_ISR_CONST_START;
__OS_ADC0_SG1_CAT2_ISR_CONST_END = _OS_ADC0_SG1_CAT2_ISR_CONST_END;
__OS_ADC0_SG1_CAT2_ISR_CONST_LIMIT = _OS_ADC0_SG1_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR_NEAR )
.OS_ADC0_SG1_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_CONST_FAST_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_CONST_FAST_START = _OS_ADC0_SG1_CAT2_ISR_CONST_FAST_START;
__OS_ADC0_SG1_CAT2_ISR_CONST_FAST_END = _OS_ADC0_SG1_CAT2_ISR_CONST_FAST_END;
__OS_ADC0_SG1_CAT2_ISR_CONST_FAST_LIMIT = _OS_ADC0_SG1_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR_INIT )

.ROM_OS_ADC0_SG1_CAT2_ISR_VAR ROM(.OS_ADC0_SG1_CAT2_ISR_VAR) :> .
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_START = ADDR(.ROM_OS_ADC0_SG1_CAT2_ISR_VAR);
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_START = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_START;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_END = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_END;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_LIMIT = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_LIMIT;

.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT ROM(.OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT);
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST ROM(.OS_ADC0_SG1_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST);
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_START = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_START;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_END = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_END;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR
# undef OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_ADC0_SG1_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR_FAR )
.OS_ADC1_SG1_CAT2_ISR_CONST ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_CONST_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_CONST_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_CONST_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_CONST_START = _OS_ADC1_SG1_CAT2_ISR_CONST_START;
__OS_ADC1_SG1_CAT2_ISR_CONST_END = _OS_ADC1_SG1_CAT2_ISR_CONST_END;
__OS_ADC1_SG1_CAT2_ISR_CONST_LIMIT = _OS_ADC1_SG1_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR_NEAR )
.OS_ADC1_SG1_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_CONST_FAST_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_CONST_FAST_START = _OS_ADC1_SG1_CAT2_ISR_CONST_FAST_START;
__OS_ADC1_SG1_CAT2_ISR_CONST_FAST_END = _OS_ADC1_SG1_CAT2_ISR_CONST_FAST_END;
__OS_ADC1_SG1_CAT2_ISR_CONST_FAST_LIMIT = _OS_ADC1_SG1_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR_INIT )

.ROM_OS_ADC1_SG1_CAT2_ISR_VAR ROM(.OS_ADC1_SG1_CAT2_ISR_VAR) :> .
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_START = ADDR(.ROM_OS_ADC1_SG1_CAT2_ISR_VAR);
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_START = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_START;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_END = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_END;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_LIMIT = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_LIMIT;

.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT ROM(.OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT);
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST ROM(.OS_ADC1_SG1_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST);
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_START = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_START;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_END = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_END;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR
# undef OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_ADC1_SG1_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0_FAR )
.OS_CanIsrGlobalRxFifo_0_CONST ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_CONST_START = ADDR(.OS_CanIsrGlobalRxFifo_0_CONST);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_CONST_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_CONST_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_CONST_START = _OS_CanIsrGlobalRxFifo_0_CONST_START;
__OS_CanIsrGlobalRxFifo_0_CONST_END = _OS_CanIsrGlobalRxFifo_0_CONST_END;
__OS_CanIsrGlobalRxFifo_0_CONST_LIMIT = _OS_CanIsrGlobalRxFifo_0_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0_NEAR )
.OS_CanIsrGlobalRxFifo_0_CONST_FAST ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_CONST_FAST_START = ADDR(.OS_CanIsrGlobalRxFifo_0_CONST_FAST);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_CONST_FAST_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_CONST_FAST_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_CONST_FAST_START = _OS_CanIsrGlobalRxFifo_0_CONST_FAST_START;
__OS_CanIsrGlobalRxFifo_0_CONST_FAST_END = _OS_CanIsrGlobalRxFifo_0_CONST_FAST_END;
__OS_CanIsrGlobalRxFifo_0_CONST_FAST_LIMIT = _OS_CanIsrGlobalRxFifo_0_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0_INIT )

.ROM_OS_CanIsrGlobalRxFifo_0_VAR ROM(.OS_CanIsrGlobalRxFifo_0_VAR) :> .
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_START = ADDR(.ROM_OS_CanIsrGlobalRxFifo_0_VAR);
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_END = . - 1;
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_LIMIT = .;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_START = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_START;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_END = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_END;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_LIMIT = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_LIMIT;

.ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT ROM(.OS_CanIsrGlobalRxFifo_0_VAR_NOINIT) :> .
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_START = ADDR(.ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT);
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_END = . - 1;
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_LIMIT = .;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_START = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_START;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_END = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_END;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_LIMIT = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_LIMIT;

.ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT ROM(.OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT) :> .
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT);
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_START = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_START;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_END = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_END;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_LIMIT = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_LIMIT;

.ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST ROM(.OS_CanIsrGlobalRxFifo_0_VAR_FAST) :> .
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_START = ADDR(.ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST);
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_END = . - 1;
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_LIMIT = .;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_START = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_START;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_END = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_END;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_LIMIT = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_LIMIT;

.ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT ROM(.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT) :> .
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT);
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_START = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_START;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_END = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_END;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_LIMIT = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT ROM(.OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT);
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_START = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_START;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_END = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_END;
__ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0
# undef OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0
#endif

#ifdef OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0_FAR
# undef OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0_NEAR
# undef OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0_INIT
# undef OS_LINK_CONST_ISR_CANISRGLOBALRXFIFO_0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_0_FAR )
.OS_CanIsrStatus_0_CONST ALIGN(4) :> .
_OS_CanIsrStatus_0_CONST_START = ADDR(.OS_CanIsrStatus_0_CONST);
. = ALIGN(4);
_OS_CanIsrStatus_0_CONST_END = . - 1;
_OS_CanIsrStatus_0_CONST_LIMIT = .;
__OS_CanIsrStatus_0_CONST_START = _OS_CanIsrStatus_0_CONST_START;
__OS_CanIsrStatus_0_CONST_END = _OS_CanIsrStatus_0_CONST_END;
__OS_CanIsrStatus_0_CONST_LIMIT = _OS_CanIsrStatus_0_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_0_NEAR )
.OS_CanIsrStatus_0_CONST_FAST ALIGN(4) :> .
_OS_CanIsrStatus_0_CONST_FAST_START = ADDR(.OS_CanIsrStatus_0_CONST_FAST);
. = ALIGN(4);
_OS_CanIsrStatus_0_CONST_FAST_END = . - 1;
_OS_CanIsrStatus_0_CONST_FAST_LIMIT = .;
__OS_CanIsrStatus_0_CONST_FAST_START = _OS_CanIsrStatus_0_CONST_FAST_START;
__OS_CanIsrStatus_0_CONST_FAST_END = _OS_CanIsrStatus_0_CONST_FAST_END;
__OS_CanIsrStatus_0_CONST_FAST_LIMIT = _OS_CanIsrStatus_0_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_CONST_ISR_CANISRSTATUS_0_INIT )

.ROM_OS_CanIsrStatus_0_VAR ROM(.OS_CanIsrStatus_0_VAR) :> .
_ROM_OS_CanIsrStatus_0_VAR_START = ADDR(.ROM_OS_CanIsrStatus_0_VAR);
_ROM_OS_CanIsrStatus_0_VAR_END = . - 1;
_ROM_OS_CanIsrStatus_0_VAR_LIMIT = .;
__ROM_OS_CanIsrStatus_0_VAR_START = _ROM_OS_CanIsrStatus_0_VAR_START;
__ROM_OS_CanIsrStatus_0_VAR_END = _ROM_OS_CanIsrStatus_0_VAR_END;
__ROM_OS_CanIsrStatus_0_VAR_LIMIT = _ROM_OS_CanIsrStatus_0_VAR_LIMIT;

.ROM_OS_CanIsrStatus_0_VAR_NOINIT ROM(.OS_CanIsrStatus_0_VAR_NOINIT) :> .
_ROM_OS_CanIsrStatus_0_VAR_NOINIT_START = ADDR(.ROM_OS_CanIsrStatus_0_VAR_NOINIT);
_ROM_OS_CanIsrStatus_0_VAR_NOINIT_END = . - 1;
_ROM_OS_CanIsrStatus_0_VAR_NOINIT_LIMIT = .;
__ROM_OS_CanIsrStatus_0_VAR_NOINIT_START = _ROM_OS_CanIsrStatus_0_VAR_NOINIT_START;
__ROM_OS_CanIsrStatus_0_VAR_NOINIT_END = _ROM_OS_CanIsrStatus_0_VAR_NOINIT_END;
__ROM_OS_CanIsrStatus_0_VAR_NOINIT_LIMIT = _ROM_OS_CanIsrStatus_0_VAR_NOINIT_LIMIT;

.ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT ROM(.OS_CanIsrStatus_0_VAR_ZERO_INIT) :> .
_ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT);
_ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT_START = _ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT_START;
__ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT_END = _ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT_END;
__ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT_LIMIT = _ROM_OS_CanIsrStatus_0_VAR_ZERO_INIT_LIMIT;

.ROM_OS_CanIsrStatus_0_VAR_FAST ROM(.OS_CanIsrStatus_0_VAR_FAST) :> .
_ROM_OS_CanIsrStatus_0_VAR_FAST_START = ADDR(.ROM_OS_CanIsrStatus_0_VAR_FAST);
_ROM_OS_CanIsrStatus_0_VAR_FAST_END = . - 1;
_ROM_OS_CanIsrStatus_0_VAR_FAST_LIMIT = .;
__ROM_OS_CanIsrStatus_0_VAR_FAST_START = _ROM_OS_CanIsrStatus_0_VAR_FAST_START;
__ROM_OS_CanIsrStatus_0_VAR_FAST_END = _ROM_OS_CanIsrStatus_0_VAR_FAST_END;
__ROM_OS_CanIsrStatus_0_VAR_FAST_LIMIT = _ROM_OS_CanIsrStatus_0_VAR_FAST_LIMIT;

.ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT ROM(.OS_CanIsrStatus_0_VAR_FAST_NOINIT) :> .
_ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT);
_ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT_START = _ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT_START;
__ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT_END = _ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT_END;
__ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT_LIMIT = _ROM_OS_CanIsrStatus_0_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT ROM(.OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT);
_ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_START = _ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_START;
__ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_END = _ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_END;
__ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_CANISRSTATUS_0
# undef OS_LINK_CONST_ISR_CANISRSTATUS_0
#endif

#ifdef OS_LINK_CONST_ISR_CANISRSTATUS_0_FAR
# undef OS_LINK_CONST_ISR_CANISRSTATUS_0_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRSTATUS_0_NEAR
# undef OS_LINK_CONST_ISR_CANISRSTATUS_0_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRSTATUS_0_INIT
# undef OS_LINK_CONST_ISR_CANISRSTATUS_0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRTX_0 ) || defined ( OS_LINK_CONST_ISR_CANISRTX_0_FAR )
.OS_CanIsrTx_0_CONST ALIGN(4) :> .
_OS_CanIsrTx_0_CONST_START = ADDR(.OS_CanIsrTx_0_CONST);
. = ALIGN(4);
_OS_CanIsrTx_0_CONST_END = . - 1;
_OS_CanIsrTx_0_CONST_LIMIT = .;
__OS_CanIsrTx_0_CONST_START = _OS_CanIsrTx_0_CONST_START;
__OS_CanIsrTx_0_CONST_END = _OS_CanIsrTx_0_CONST_END;
__OS_CanIsrTx_0_CONST_LIMIT = _OS_CanIsrTx_0_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRTX_0 ) || defined ( OS_LINK_CONST_ISR_CANISRTX_0_NEAR )
.OS_CanIsrTx_0_CONST_FAST ALIGN(4) :> .
_OS_CanIsrTx_0_CONST_FAST_START = ADDR(.OS_CanIsrTx_0_CONST_FAST);
. = ALIGN(4);
_OS_CanIsrTx_0_CONST_FAST_END = . - 1;
_OS_CanIsrTx_0_CONST_FAST_LIMIT = .;
__OS_CanIsrTx_0_CONST_FAST_START = _OS_CanIsrTx_0_CONST_FAST_START;
__OS_CanIsrTx_0_CONST_FAST_END = _OS_CanIsrTx_0_CONST_FAST_END;
__OS_CanIsrTx_0_CONST_FAST_LIMIT = _OS_CanIsrTx_0_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISRTX_0 ) || defined ( OS_LINK_CONST_ISR_CANISRTX_0_INIT )

.ROM_OS_CanIsrTx_0_VAR ROM(.OS_CanIsrTx_0_VAR) :> .
_ROM_OS_CanIsrTx_0_VAR_START = ADDR(.ROM_OS_CanIsrTx_0_VAR);
_ROM_OS_CanIsrTx_0_VAR_END = . - 1;
_ROM_OS_CanIsrTx_0_VAR_LIMIT = .;
__ROM_OS_CanIsrTx_0_VAR_START = _ROM_OS_CanIsrTx_0_VAR_START;
__ROM_OS_CanIsrTx_0_VAR_END = _ROM_OS_CanIsrTx_0_VAR_END;
__ROM_OS_CanIsrTx_0_VAR_LIMIT = _ROM_OS_CanIsrTx_0_VAR_LIMIT;

.ROM_OS_CanIsrTx_0_VAR_NOINIT ROM(.OS_CanIsrTx_0_VAR_NOINIT) :> .
_ROM_OS_CanIsrTx_0_VAR_NOINIT_START = ADDR(.ROM_OS_CanIsrTx_0_VAR_NOINIT);
_ROM_OS_CanIsrTx_0_VAR_NOINIT_END = . - 1;
_ROM_OS_CanIsrTx_0_VAR_NOINIT_LIMIT = .;
__ROM_OS_CanIsrTx_0_VAR_NOINIT_START = _ROM_OS_CanIsrTx_0_VAR_NOINIT_START;
__ROM_OS_CanIsrTx_0_VAR_NOINIT_END = _ROM_OS_CanIsrTx_0_VAR_NOINIT_END;
__ROM_OS_CanIsrTx_0_VAR_NOINIT_LIMIT = _ROM_OS_CanIsrTx_0_VAR_NOINIT_LIMIT;

.ROM_OS_CanIsrTx_0_VAR_ZERO_INIT ROM(.OS_CanIsrTx_0_VAR_ZERO_INIT) :> .
_ROM_OS_CanIsrTx_0_VAR_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrTx_0_VAR_ZERO_INIT);
_ROM_OS_CanIsrTx_0_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_CanIsrTx_0_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_CanIsrTx_0_VAR_ZERO_INIT_START = _ROM_OS_CanIsrTx_0_VAR_ZERO_INIT_START;
__ROM_OS_CanIsrTx_0_VAR_ZERO_INIT_END = _ROM_OS_CanIsrTx_0_VAR_ZERO_INIT_END;
__ROM_OS_CanIsrTx_0_VAR_ZERO_INIT_LIMIT = _ROM_OS_CanIsrTx_0_VAR_ZERO_INIT_LIMIT;

.ROM_OS_CanIsrTx_0_VAR_FAST ROM(.OS_CanIsrTx_0_VAR_FAST) :> .
_ROM_OS_CanIsrTx_0_VAR_FAST_START = ADDR(.ROM_OS_CanIsrTx_0_VAR_FAST);
_ROM_OS_CanIsrTx_0_VAR_FAST_END = . - 1;
_ROM_OS_CanIsrTx_0_VAR_FAST_LIMIT = .;
__ROM_OS_CanIsrTx_0_VAR_FAST_START = _ROM_OS_CanIsrTx_0_VAR_FAST_START;
__ROM_OS_CanIsrTx_0_VAR_FAST_END = _ROM_OS_CanIsrTx_0_VAR_FAST_END;
__ROM_OS_CanIsrTx_0_VAR_FAST_LIMIT = _ROM_OS_CanIsrTx_0_VAR_FAST_LIMIT;

.ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT ROM(.OS_CanIsrTx_0_VAR_FAST_NOINIT) :> .
_ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT);
_ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT_START = _ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT_START;
__ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT_END = _ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT_END;
__ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT_LIMIT = _ROM_OS_CanIsrTx_0_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT ROM(.OS_CanIsrTx_0_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT);
_ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_START = _ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_START;
__ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_END = _ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_END;
__ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_CANISRTX_0
# undef OS_LINK_CONST_ISR_CANISRTX_0
#endif

#ifdef OS_LINK_CONST_ISR_CANISRTX_0_FAR
# undef OS_LINK_CONST_ISR_CANISRTX_0_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRTX_0_NEAR
# undef OS_LINK_CONST_ISR_CANISRTX_0_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISRTX_0_INIT
# undef OS_LINK_CONST_ISR_CANISRTX_0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS_FAR )
.OS_CounterIsr_OsCounter_10ms_CONST ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_CONST_START = ADDR(.OS_CounterIsr_OsCounter_10ms_CONST);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_CONST_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_CONST_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_CONST_START = _OS_CounterIsr_OsCounter_10ms_CONST_START;
__OS_CounterIsr_OsCounter_10ms_CONST_END = _OS_CounterIsr_OsCounter_10ms_CONST_END;
__OS_CounterIsr_OsCounter_10ms_CONST_LIMIT = _OS_CounterIsr_OsCounter_10ms_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR )
.OS_CounterIsr_OsCounter_10ms_CONST_FAST ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_CONST_FAST_START = ADDR(.OS_CounterIsr_OsCounter_10ms_CONST_FAST);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_CONST_FAST_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_CONST_FAST_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_CONST_FAST_START = _OS_CounterIsr_OsCounter_10ms_CONST_FAST_START;
__OS_CounterIsr_OsCounter_10ms_CONST_FAST_END = _OS_CounterIsr_OsCounter_10ms_CONST_FAST_END;
__OS_CounterIsr_OsCounter_10ms_CONST_FAST_LIMIT = _OS_CounterIsr_OsCounter_10ms_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS_INIT )

.ROM_OS_CounterIsr_OsCounter_10ms_VAR ROM(.OS_CounterIsr_OsCounter_10ms_VAR) :> .
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_START = ADDR(.ROM_OS_CounterIsr_OsCounter_10ms_VAR);
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_END = . - 1;
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_LIMIT = .;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_START = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_START;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_END = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_END;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_LIMIT = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_LIMIT;

.ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT ROM(.OS_CounterIsr_OsCounter_10ms_VAR_NOINIT) :> .
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_START = ADDR(.ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT);
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_END = . - 1;
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_LIMIT = .;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_START = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_START;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_END = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_END;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_LIMIT = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_LIMIT;

.ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT ROM(.OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT) :> .
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_START = ADDR(.ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT);
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_START = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_START;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_END = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_END;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_LIMIT = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_LIMIT;

.ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST ROM(.OS_CounterIsr_OsCounter_10ms_VAR_FAST) :> .
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_START = ADDR(.ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST);
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_END = . - 1;
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_LIMIT = .;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_START = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_START;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_END = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_END;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_LIMIT = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_LIMIT;

.ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT ROM(.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT) :> .
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT);
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_START = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_START;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_END = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_END;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_LIMIT = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT ROM(.OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT);
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_START = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_START;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_END = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_END;
__ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS
# undef OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS_FAR
# undef OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS_FAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR
# undef OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS_INIT
# undef OS_LINK_CONST_ISR_COUNTERISR_OSCOUNTER_10MS_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR )
.OS_CounterIsr_SystemTimer_CONST ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_CONST_START = ADDR(.OS_CounterIsr_SystemTimer_CONST);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_CONST_END = . - 1;
_OS_CounterIsr_SystemTimer_CONST_LIMIT = .;
__OS_CounterIsr_SystemTimer_CONST_START = _OS_CounterIsr_SystemTimer_CONST_START;
__OS_CounterIsr_SystemTimer_CONST_END = _OS_CounterIsr_SystemTimer_CONST_END;
__OS_CounterIsr_SystemTimer_CONST_LIMIT = _OS_CounterIsr_SystemTimer_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR )
.OS_CounterIsr_SystemTimer_CONST_FAST ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_CONST_FAST_START = ADDR(.OS_CounterIsr_SystemTimer_CONST_FAST);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_CONST_FAST_END = . - 1;
_OS_CounterIsr_SystemTimer_CONST_FAST_LIMIT = .;
__OS_CounterIsr_SystemTimer_CONST_FAST_START = _OS_CounterIsr_SystemTimer_CONST_FAST_START;
__OS_CounterIsr_SystemTimer_CONST_FAST_END = _OS_CounterIsr_SystemTimer_CONST_FAST_END;
__OS_CounterIsr_SystemTimer_CONST_FAST_LIMIT = _OS_CounterIsr_SystemTimer_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT )

.ROM_OS_CounterIsr_SystemTimer_VAR ROM(.OS_CounterIsr_SystemTimer_VAR) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR);
_ROM_OS_CounterIsr_SystemTimer_VAR_END = . - 1;
_ROM_OS_CounterIsr_SystemTimer_VAR_LIMIT = .;
__ROM_OS_CounterIsr_SystemTimer_VAR_START = _ROM_OS_CounterIsr_SystemTimer_VAR_START;
__ROM_OS_CounterIsr_SystemTimer_VAR_END = _ROM_OS_CounterIsr_SystemTimer_VAR_END;
__ROM_OS_CounterIsr_SystemTimer_VAR_LIMIT = _ROM_OS_CounterIsr_SystemTimer_VAR_LIMIT;

.ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT ROM(.OS_CounterIsr_SystemTimer_VAR_NOINIT) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT);
_ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_END = . - 1;
_ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT = .;
__ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_START = _ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_START;
__ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_END = _ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_END;
__ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT = _ROM_OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT;

.ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT ROM(.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT);
_ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START = _ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START;
__ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END = _ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END;
__ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_LIMIT = _ROM_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_LIMIT;

.ROM_OS_CounterIsr_SystemTimer_VAR_FAST ROM(.OS_CounterIsr_SystemTimer_VAR_FAST) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_FAST);
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_END = . - 1;
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_LIMIT = .;
__ROM_OS_CounterIsr_SystemTimer_VAR_FAST_START = _ROM_OS_CounterIsr_SystemTimer_VAR_FAST_START;
__ROM_OS_CounterIsr_SystemTimer_VAR_FAST_END = _ROM_OS_CounterIsr_SystemTimer_VAR_FAST_END;
__ROM_OS_CounterIsr_SystemTimer_VAR_FAST_LIMIT = _ROM_OS_CounterIsr_SystemTimer_VAR_FAST_LIMIT;

.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT ROM(.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT);
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START = _ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START;
__ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END = _ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END;
__ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT = _ROM_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT ROM(.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT);
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START = _ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START;
__ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END = _ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END;
__ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_FAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR_FAR )
.OS_EXT_INTP_CH03_CAT2_ISR_CONST ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_CONST_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_CONST_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_CONST_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_CONST_START = _OS_EXT_INTP_CH03_CAT2_ISR_CONST_START;
__OS_EXT_INTP_CH03_CAT2_ISR_CONST_END = _OS_EXT_INTP_CH03_CAT2_ISR_CONST_END;
__OS_EXT_INTP_CH03_CAT2_ISR_CONST_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR )
.OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST_START = _OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST_START;
__OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST_END = _OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST_END;
__OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR_INIT )

.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR ROM(.OS_EXT_INTP_CH03_CAT2_ISR_VAR) :> .
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_START = ADDR(.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR);
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_START = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_START;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_END = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_END;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_LIMIT = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_LIMIT;

.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT ROM(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT);
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST ROM(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST);
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_START = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_START;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_END = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_END;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR
# undef OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_EXT_INTP_CH03_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR_FAR )
.OS_EXT_INTP_CH07_CAT2_ISR_CONST ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_CONST_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_CONST_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_CONST_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_CONST_START = _OS_EXT_INTP_CH07_CAT2_ISR_CONST_START;
__OS_EXT_INTP_CH07_CAT2_ISR_CONST_END = _OS_EXT_INTP_CH07_CAT2_ISR_CONST_END;
__OS_EXT_INTP_CH07_CAT2_ISR_CONST_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR )
.OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST_START = _OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST_START;
__OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST_END = _OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST_END;
__OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR_INIT )

.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR ROM(.OS_EXT_INTP_CH07_CAT2_ISR_VAR) :> .
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_START = ADDR(.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR);
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_START = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_START;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_END = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_END;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_LIMIT = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_LIMIT;

.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT ROM(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT);
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST ROM(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST);
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_START = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_START;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_END = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_END;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR
# undef OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_EXT_INTP_CH07_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR_FAR )
.OS_EXT_INTP_CH17_CAT2_ISR_CONST ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_CONST_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_CONST_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_CONST_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_CONST_START = _OS_EXT_INTP_CH17_CAT2_ISR_CONST_START;
__OS_EXT_INTP_CH17_CAT2_ISR_CONST_END = _OS_EXT_INTP_CH17_CAT2_ISR_CONST_END;
__OS_EXT_INTP_CH17_CAT2_ISR_CONST_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR )
.OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST_START = _OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST_START;
__OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST_END = _OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST_END;
__OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR_INIT )

.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR ROM(.OS_EXT_INTP_CH17_CAT2_ISR_VAR) :> .
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_START = ADDR(.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR);
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_START = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_START;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_END = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_END;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_LIMIT = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_LIMIT;

.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT ROM(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT);
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST ROM(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST);
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_START = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_START;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_END = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_END;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR
# undef OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_EXT_INTP_CH17_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_INTIIC0EE ) || defined ( OS_LINK_CONST_ISR_INTIIC0EE_FAR )
.OS_INTIIC0EE_CONST ALIGN(4) :> .
_OS_INTIIC0EE_CONST_START = ADDR(.OS_INTIIC0EE_CONST);
. = ALIGN(4);
_OS_INTIIC0EE_CONST_END = . - 1;
_OS_INTIIC0EE_CONST_LIMIT = .;
__OS_INTIIC0EE_CONST_START = _OS_INTIIC0EE_CONST_START;
__OS_INTIIC0EE_CONST_END = _OS_INTIIC0EE_CONST_END;
__OS_INTIIC0EE_CONST_LIMIT = _OS_INTIIC0EE_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_INTIIC0EE ) || defined ( OS_LINK_CONST_ISR_INTIIC0EE_NEAR )
.OS_INTIIC0EE_CONST_FAST ALIGN(4) :> .
_OS_INTIIC0EE_CONST_FAST_START = ADDR(.OS_INTIIC0EE_CONST_FAST);
. = ALIGN(4);
_OS_INTIIC0EE_CONST_FAST_END = . - 1;
_OS_INTIIC0EE_CONST_FAST_LIMIT = .;
__OS_INTIIC0EE_CONST_FAST_START = _OS_INTIIC0EE_CONST_FAST_START;
__OS_INTIIC0EE_CONST_FAST_END = _OS_INTIIC0EE_CONST_FAST_END;
__OS_INTIIC0EE_CONST_FAST_LIMIT = _OS_INTIIC0EE_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_INTIIC0EE ) || defined ( OS_LINK_CONST_ISR_INTIIC0EE_INIT )

.ROM_OS_INTIIC0EE_VAR ROM(.OS_INTIIC0EE_VAR) :> .
_ROM_OS_INTIIC0EE_VAR_START = ADDR(.ROM_OS_INTIIC0EE_VAR);
_ROM_OS_INTIIC0EE_VAR_END = . - 1;
_ROM_OS_INTIIC0EE_VAR_LIMIT = .;
__ROM_OS_INTIIC0EE_VAR_START = _ROM_OS_INTIIC0EE_VAR_START;
__ROM_OS_INTIIC0EE_VAR_END = _ROM_OS_INTIIC0EE_VAR_END;
__ROM_OS_INTIIC0EE_VAR_LIMIT = _ROM_OS_INTIIC0EE_VAR_LIMIT;

.ROM_OS_INTIIC0EE_VAR_NOINIT ROM(.OS_INTIIC0EE_VAR_NOINIT) :> .
_ROM_OS_INTIIC0EE_VAR_NOINIT_START = ADDR(.ROM_OS_INTIIC0EE_VAR_NOINIT);
_ROM_OS_INTIIC0EE_VAR_NOINIT_END = . - 1;
_ROM_OS_INTIIC0EE_VAR_NOINIT_LIMIT = .;
__ROM_OS_INTIIC0EE_VAR_NOINIT_START = _ROM_OS_INTIIC0EE_VAR_NOINIT_START;
__ROM_OS_INTIIC0EE_VAR_NOINIT_END = _ROM_OS_INTIIC0EE_VAR_NOINIT_END;
__ROM_OS_INTIIC0EE_VAR_NOINIT_LIMIT = _ROM_OS_INTIIC0EE_VAR_NOINIT_LIMIT;

.ROM_OS_INTIIC0EE_VAR_ZERO_INIT ROM(.OS_INTIIC0EE_VAR_ZERO_INIT) :> .
_ROM_OS_INTIIC0EE_VAR_ZERO_INIT_START = ADDR(.ROM_OS_INTIIC0EE_VAR_ZERO_INIT);
_ROM_OS_INTIIC0EE_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_INTIIC0EE_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_INTIIC0EE_VAR_ZERO_INIT_START = _ROM_OS_INTIIC0EE_VAR_ZERO_INIT_START;
__ROM_OS_INTIIC0EE_VAR_ZERO_INIT_END = _ROM_OS_INTIIC0EE_VAR_ZERO_INIT_END;
__ROM_OS_INTIIC0EE_VAR_ZERO_INIT_LIMIT = _ROM_OS_INTIIC0EE_VAR_ZERO_INIT_LIMIT;

.ROM_OS_INTIIC0EE_VAR_FAST ROM(.OS_INTIIC0EE_VAR_FAST) :> .
_ROM_OS_INTIIC0EE_VAR_FAST_START = ADDR(.ROM_OS_INTIIC0EE_VAR_FAST);
_ROM_OS_INTIIC0EE_VAR_FAST_END = . - 1;
_ROM_OS_INTIIC0EE_VAR_FAST_LIMIT = .;
__ROM_OS_INTIIC0EE_VAR_FAST_START = _ROM_OS_INTIIC0EE_VAR_FAST_START;
__ROM_OS_INTIIC0EE_VAR_FAST_END = _ROM_OS_INTIIC0EE_VAR_FAST_END;
__ROM_OS_INTIIC0EE_VAR_FAST_LIMIT = _ROM_OS_INTIIC0EE_VAR_FAST_LIMIT;

.ROM_OS_INTIIC0EE_VAR_FAST_NOINIT ROM(.OS_INTIIC0EE_VAR_FAST_NOINIT) :> .
_ROM_OS_INTIIC0EE_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_INTIIC0EE_VAR_FAST_NOINIT);
_ROM_OS_INTIIC0EE_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_INTIIC0EE_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_INTIIC0EE_VAR_FAST_NOINIT_START = _ROM_OS_INTIIC0EE_VAR_FAST_NOINIT_START;
__ROM_OS_INTIIC0EE_VAR_FAST_NOINIT_END = _ROM_OS_INTIIC0EE_VAR_FAST_NOINIT_END;
__ROM_OS_INTIIC0EE_VAR_FAST_NOINIT_LIMIT = _ROM_OS_INTIIC0EE_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT ROM(.OS_INTIIC0EE_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT);
_ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_START = _ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_START;
__ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_END = _ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_END;
__ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0EE
# undef OS_LINK_CONST_ISR_INTIIC0EE
#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0EE_FAR
# undef OS_LINK_CONST_ISR_INTIIC0EE_FAR
#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0EE_NEAR
# undef OS_LINK_CONST_ISR_INTIIC0EE_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0EE_INIT
# undef OS_LINK_CONST_ISR_INTIIC0EE_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_INTIIC0RI ) || defined ( OS_LINK_CONST_ISR_INTIIC0RI_FAR )
.OS_INTIIC0RI_CONST ALIGN(4) :> .
_OS_INTIIC0RI_CONST_START = ADDR(.OS_INTIIC0RI_CONST);
. = ALIGN(4);
_OS_INTIIC0RI_CONST_END = . - 1;
_OS_INTIIC0RI_CONST_LIMIT = .;
__OS_INTIIC0RI_CONST_START = _OS_INTIIC0RI_CONST_START;
__OS_INTIIC0RI_CONST_END = _OS_INTIIC0RI_CONST_END;
__OS_INTIIC0RI_CONST_LIMIT = _OS_INTIIC0RI_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_INTIIC0RI ) || defined ( OS_LINK_CONST_ISR_INTIIC0RI_NEAR )
.OS_INTIIC0RI_CONST_FAST ALIGN(4) :> .
_OS_INTIIC0RI_CONST_FAST_START = ADDR(.OS_INTIIC0RI_CONST_FAST);
. = ALIGN(4);
_OS_INTIIC0RI_CONST_FAST_END = . - 1;
_OS_INTIIC0RI_CONST_FAST_LIMIT = .;
__OS_INTIIC0RI_CONST_FAST_START = _OS_INTIIC0RI_CONST_FAST_START;
__OS_INTIIC0RI_CONST_FAST_END = _OS_INTIIC0RI_CONST_FAST_END;
__OS_INTIIC0RI_CONST_FAST_LIMIT = _OS_INTIIC0RI_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_INTIIC0RI ) || defined ( OS_LINK_CONST_ISR_INTIIC0RI_INIT )

.ROM_OS_INTIIC0RI_VAR ROM(.OS_INTIIC0RI_VAR) :> .
_ROM_OS_INTIIC0RI_VAR_START = ADDR(.ROM_OS_INTIIC0RI_VAR);
_ROM_OS_INTIIC0RI_VAR_END = . - 1;
_ROM_OS_INTIIC0RI_VAR_LIMIT = .;
__ROM_OS_INTIIC0RI_VAR_START = _ROM_OS_INTIIC0RI_VAR_START;
__ROM_OS_INTIIC0RI_VAR_END = _ROM_OS_INTIIC0RI_VAR_END;
__ROM_OS_INTIIC0RI_VAR_LIMIT = _ROM_OS_INTIIC0RI_VAR_LIMIT;

.ROM_OS_INTIIC0RI_VAR_NOINIT ROM(.OS_INTIIC0RI_VAR_NOINIT) :> .
_ROM_OS_INTIIC0RI_VAR_NOINIT_START = ADDR(.ROM_OS_INTIIC0RI_VAR_NOINIT);
_ROM_OS_INTIIC0RI_VAR_NOINIT_END = . - 1;
_ROM_OS_INTIIC0RI_VAR_NOINIT_LIMIT = .;
__ROM_OS_INTIIC0RI_VAR_NOINIT_START = _ROM_OS_INTIIC0RI_VAR_NOINIT_START;
__ROM_OS_INTIIC0RI_VAR_NOINIT_END = _ROM_OS_INTIIC0RI_VAR_NOINIT_END;
__ROM_OS_INTIIC0RI_VAR_NOINIT_LIMIT = _ROM_OS_INTIIC0RI_VAR_NOINIT_LIMIT;

.ROM_OS_INTIIC0RI_VAR_ZERO_INIT ROM(.OS_INTIIC0RI_VAR_ZERO_INIT) :> .
_ROM_OS_INTIIC0RI_VAR_ZERO_INIT_START = ADDR(.ROM_OS_INTIIC0RI_VAR_ZERO_INIT);
_ROM_OS_INTIIC0RI_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_INTIIC0RI_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_INTIIC0RI_VAR_ZERO_INIT_START = _ROM_OS_INTIIC0RI_VAR_ZERO_INIT_START;
__ROM_OS_INTIIC0RI_VAR_ZERO_INIT_END = _ROM_OS_INTIIC0RI_VAR_ZERO_INIT_END;
__ROM_OS_INTIIC0RI_VAR_ZERO_INIT_LIMIT = _ROM_OS_INTIIC0RI_VAR_ZERO_INIT_LIMIT;

.ROM_OS_INTIIC0RI_VAR_FAST ROM(.OS_INTIIC0RI_VAR_FAST) :> .
_ROM_OS_INTIIC0RI_VAR_FAST_START = ADDR(.ROM_OS_INTIIC0RI_VAR_FAST);
_ROM_OS_INTIIC0RI_VAR_FAST_END = . - 1;
_ROM_OS_INTIIC0RI_VAR_FAST_LIMIT = .;
__ROM_OS_INTIIC0RI_VAR_FAST_START = _ROM_OS_INTIIC0RI_VAR_FAST_START;
__ROM_OS_INTIIC0RI_VAR_FAST_END = _ROM_OS_INTIIC0RI_VAR_FAST_END;
__ROM_OS_INTIIC0RI_VAR_FAST_LIMIT = _ROM_OS_INTIIC0RI_VAR_FAST_LIMIT;

.ROM_OS_INTIIC0RI_VAR_FAST_NOINIT ROM(.OS_INTIIC0RI_VAR_FAST_NOINIT) :> .
_ROM_OS_INTIIC0RI_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_INTIIC0RI_VAR_FAST_NOINIT);
_ROM_OS_INTIIC0RI_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_INTIIC0RI_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_INTIIC0RI_VAR_FAST_NOINIT_START = _ROM_OS_INTIIC0RI_VAR_FAST_NOINIT_START;
__ROM_OS_INTIIC0RI_VAR_FAST_NOINIT_END = _ROM_OS_INTIIC0RI_VAR_FAST_NOINIT_END;
__ROM_OS_INTIIC0RI_VAR_FAST_NOINIT_LIMIT = _ROM_OS_INTIIC0RI_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT ROM(.OS_INTIIC0RI_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT);
_ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_START = _ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_START;
__ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_END = _ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_END;
__ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0RI
# undef OS_LINK_CONST_ISR_INTIIC0RI
#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0RI_FAR
# undef OS_LINK_CONST_ISR_INTIIC0RI_FAR
#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0RI_NEAR
# undef OS_LINK_CONST_ISR_INTIIC0RI_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0RI_INIT
# undef OS_LINK_CONST_ISR_INTIIC0RI_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_INTIIC0TEI ) || defined ( OS_LINK_CONST_ISR_INTIIC0TEI_FAR )
.OS_INTIIC0TEI_CONST ALIGN(4) :> .
_OS_INTIIC0TEI_CONST_START = ADDR(.OS_INTIIC0TEI_CONST);
. = ALIGN(4);
_OS_INTIIC0TEI_CONST_END = . - 1;
_OS_INTIIC0TEI_CONST_LIMIT = .;
__OS_INTIIC0TEI_CONST_START = _OS_INTIIC0TEI_CONST_START;
__OS_INTIIC0TEI_CONST_END = _OS_INTIIC0TEI_CONST_END;
__OS_INTIIC0TEI_CONST_LIMIT = _OS_INTIIC0TEI_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_INTIIC0TEI ) || defined ( OS_LINK_CONST_ISR_INTIIC0TEI_NEAR )
.OS_INTIIC0TEI_CONST_FAST ALIGN(4) :> .
_OS_INTIIC0TEI_CONST_FAST_START = ADDR(.OS_INTIIC0TEI_CONST_FAST);
. = ALIGN(4);
_OS_INTIIC0TEI_CONST_FAST_END = . - 1;
_OS_INTIIC0TEI_CONST_FAST_LIMIT = .;
__OS_INTIIC0TEI_CONST_FAST_START = _OS_INTIIC0TEI_CONST_FAST_START;
__OS_INTIIC0TEI_CONST_FAST_END = _OS_INTIIC0TEI_CONST_FAST_END;
__OS_INTIIC0TEI_CONST_FAST_LIMIT = _OS_INTIIC0TEI_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_INTIIC0TEI ) || defined ( OS_LINK_CONST_ISR_INTIIC0TEI_INIT )

.ROM_OS_INTIIC0TEI_VAR ROM(.OS_INTIIC0TEI_VAR) :> .
_ROM_OS_INTIIC0TEI_VAR_START = ADDR(.ROM_OS_INTIIC0TEI_VAR);
_ROM_OS_INTIIC0TEI_VAR_END = . - 1;
_ROM_OS_INTIIC0TEI_VAR_LIMIT = .;
__ROM_OS_INTIIC0TEI_VAR_START = _ROM_OS_INTIIC0TEI_VAR_START;
__ROM_OS_INTIIC0TEI_VAR_END = _ROM_OS_INTIIC0TEI_VAR_END;
__ROM_OS_INTIIC0TEI_VAR_LIMIT = _ROM_OS_INTIIC0TEI_VAR_LIMIT;

.ROM_OS_INTIIC0TEI_VAR_NOINIT ROM(.OS_INTIIC0TEI_VAR_NOINIT) :> .
_ROM_OS_INTIIC0TEI_VAR_NOINIT_START = ADDR(.ROM_OS_INTIIC0TEI_VAR_NOINIT);
_ROM_OS_INTIIC0TEI_VAR_NOINIT_END = . - 1;
_ROM_OS_INTIIC0TEI_VAR_NOINIT_LIMIT = .;
__ROM_OS_INTIIC0TEI_VAR_NOINIT_START = _ROM_OS_INTIIC0TEI_VAR_NOINIT_START;
__ROM_OS_INTIIC0TEI_VAR_NOINIT_END = _ROM_OS_INTIIC0TEI_VAR_NOINIT_END;
__ROM_OS_INTIIC0TEI_VAR_NOINIT_LIMIT = _ROM_OS_INTIIC0TEI_VAR_NOINIT_LIMIT;

.ROM_OS_INTIIC0TEI_VAR_ZERO_INIT ROM(.OS_INTIIC0TEI_VAR_ZERO_INIT) :> .
_ROM_OS_INTIIC0TEI_VAR_ZERO_INIT_START = ADDR(.ROM_OS_INTIIC0TEI_VAR_ZERO_INIT);
_ROM_OS_INTIIC0TEI_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_INTIIC0TEI_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_INTIIC0TEI_VAR_ZERO_INIT_START = _ROM_OS_INTIIC0TEI_VAR_ZERO_INIT_START;
__ROM_OS_INTIIC0TEI_VAR_ZERO_INIT_END = _ROM_OS_INTIIC0TEI_VAR_ZERO_INIT_END;
__ROM_OS_INTIIC0TEI_VAR_ZERO_INIT_LIMIT = _ROM_OS_INTIIC0TEI_VAR_ZERO_INIT_LIMIT;

.ROM_OS_INTIIC0TEI_VAR_FAST ROM(.OS_INTIIC0TEI_VAR_FAST) :> .
_ROM_OS_INTIIC0TEI_VAR_FAST_START = ADDR(.ROM_OS_INTIIC0TEI_VAR_FAST);
_ROM_OS_INTIIC0TEI_VAR_FAST_END = . - 1;
_ROM_OS_INTIIC0TEI_VAR_FAST_LIMIT = .;
__ROM_OS_INTIIC0TEI_VAR_FAST_START = _ROM_OS_INTIIC0TEI_VAR_FAST_START;
__ROM_OS_INTIIC0TEI_VAR_FAST_END = _ROM_OS_INTIIC0TEI_VAR_FAST_END;
__ROM_OS_INTIIC0TEI_VAR_FAST_LIMIT = _ROM_OS_INTIIC0TEI_VAR_FAST_LIMIT;

.ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT ROM(.OS_INTIIC0TEI_VAR_FAST_NOINIT) :> .
_ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT);
_ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT_START = _ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT_START;
__ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT_END = _ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT_END;
__ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT_LIMIT = _ROM_OS_INTIIC0TEI_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT ROM(.OS_INTIIC0TEI_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT);
_ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_START = _ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_START;
__ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_END = _ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_END;
__ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0TEI
# undef OS_LINK_CONST_ISR_INTIIC0TEI
#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0TEI_FAR
# undef OS_LINK_CONST_ISR_INTIIC0TEI_FAR
#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0TEI_NEAR
# undef OS_LINK_CONST_ISR_INTIIC0TEI_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_INTIIC0TEI_INIT
# undef OS_LINK_CONST_ISR_INTIIC0TEI_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR )
.OS_IRQDmaChannel2TransmitComplete_CONST ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_CONST_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_CONST);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_CONST_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_CONST_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_CONST_START = _OS_IRQDmaChannel2TransmitComplete_CONST_START;
__OS_IRQDmaChannel2TransmitComplete_CONST_END = _OS_IRQDmaChannel2TransmitComplete_CONST_END;
__OS_IRQDmaChannel2TransmitComplete_CONST_LIMIT = _OS_IRQDmaChannel2TransmitComplete_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR )
.OS_IRQDmaChannel2TransmitComplete_CONST_FAST ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_CONST_FAST_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_CONST_FAST);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_CONST_FAST_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_CONST_FAST_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_CONST_FAST_START = _OS_IRQDmaChannel2TransmitComplete_CONST_FAST_START;
__OS_IRQDmaChannel2TransmitComplete_CONST_FAST_END = _OS_IRQDmaChannel2TransmitComplete_CONST_FAST_END;
__OS_IRQDmaChannel2TransmitComplete_CONST_FAST_LIMIT = _OS_IRQDmaChannel2TransmitComplete_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_INIT )

.ROM_OS_IRQDmaChannel2TransmitComplete_VAR ROM(.OS_IRQDmaChannel2TransmitComplete_VAR) :> .
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_START = ADDR(.ROM_OS_IRQDmaChannel2TransmitComplete_VAR);
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_END = . - 1;
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_LIMIT = .;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_START = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_START;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_END = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_END;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_LIMIT = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_LIMIT;

.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT ROM(.OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT) :> .
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_START = ADDR(.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT);
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_END = . - 1;
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_LIMIT = .;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_START = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_START;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_END = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_END;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_LIMIT = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_LIMIT;

.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT ROM(.OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT) :> .
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_START = ADDR(.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT);
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_START = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_START;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_END = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_END;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_LIMIT = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_LIMIT;

.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST ROM(.OS_IRQDmaChannel2TransmitComplete_VAR_FAST) :> .
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_START = ADDR(.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST);
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_END = . - 1;
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_LIMIT = .;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_START = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_START;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_END = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_END;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_LIMIT = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_LIMIT;

.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT ROM(.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT) :> .
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT);
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_START = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_START;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_END = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_END;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_LIMIT = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT ROM(.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT);
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_START = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_START;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_END = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_END;
__ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE
#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR
#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_INIT
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR )
.OS_IRQDmaChannel5ReceiveComplete_CONST ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_CONST_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_CONST);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_CONST_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_CONST_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_CONST_START = _OS_IRQDmaChannel5ReceiveComplete_CONST_START;
__OS_IRQDmaChannel5ReceiveComplete_CONST_END = _OS_IRQDmaChannel5ReceiveComplete_CONST_END;
__OS_IRQDmaChannel5ReceiveComplete_CONST_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR )
.OS_IRQDmaChannel5ReceiveComplete_CONST_FAST ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_CONST_FAST_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_CONST_FAST);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_CONST_FAST_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_CONST_FAST_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_CONST_FAST_START = _OS_IRQDmaChannel5ReceiveComplete_CONST_FAST_START;
__OS_IRQDmaChannel5ReceiveComplete_CONST_FAST_END = _OS_IRQDmaChannel5ReceiveComplete_CONST_FAST_END;
__OS_IRQDmaChannel5ReceiveComplete_CONST_FAST_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_INIT )

.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR ROM(.OS_IRQDmaChannel5ReceiveComplete_VAR) :> .
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_START = ADDR(.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR);
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_END = . - 1;
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_LIMIT = .;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_START = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_START;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_END = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_END;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_LIMIT = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_LIMIT;

.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT ROM(.OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT) :> .
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_START = ADDR(.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT);
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_END = . - 1;
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_LIMIT = .;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_START = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_START;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_END = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_END;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_LIMIT = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_LIMIT;

.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT ROM(.OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT) :> .
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_START = ADDR(.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT);
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_START = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_START;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_END = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_END;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_LIMIT = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_LIMIT;

.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST ROM(.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST) :> .
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_START = ADDR(.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST);
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_END = . - 1;
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_LIMIT = .;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_START = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_START;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_END = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_END;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_LIMIT = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_LIMIT;

.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT ROM(.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT) :> .
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT);
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_START = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_START;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_END = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_END;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_LIMIT = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT ROM(.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT);
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_START = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_START;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_END = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_END;
__ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE
#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR
#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_INIT
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR )
.OS_IRQDmaChannel5TransmitComplete_CONST ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_CONST_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_CONST);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_CONST_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_CONST_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_CONST_START = _OS_IRQDmaChannel5TransmitComplete_CONST_START;
__OS_IRQDmaChannel5TransmitComplete_CONST_END = _OS_IRQDmaChannel5TransmitComplete_CONST_END;
__OS_IRQDmaChannel5TransmitComplete_CONST_LIMIT = _OS_IRQDmaChannel5TransmitComplete_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR )
.OS_IRQDmaChannel5TransmitComplete_CONST_FAST ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_CONST_FAST_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_CONST_FAST);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_CONST_FAST_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_CONST_FAST_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_CONST_FAST_START = _OS_IRQDmaChannel5TransmitComplete_CONST_FAST_START;
__OS_IRQDmaChannel5TransmitComplete_CONST_FAST_END = _OS_IRQDmaChannel5TransmitComplete_CONST_FAST_END;
__OS_IRQDmaChannel5TransmitComplete_CONST_FAST_LIMIT = _OS_IRQDmaChannel5TransmitComplete_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_INIT )

.ROM_OS_IRQDmaChannel5TransmitComplete_VAR ROM(.OS_IRQDmaChannel5TransmitComplete_VAR) :> .
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_START = ADDR(.ROM_OS_IRQDmaChannel5TransmitComplete_VAR);
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_END = . - 1;
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_LIMIT = .;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_START = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_START;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_END = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_END;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_LIMIT = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_LIMIT;

.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT ROM(.OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT) :> .
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_START = ADDR(.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT);
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_END = . - 1;
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_LIMIT = .;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_START = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_START;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_END = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_END;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_LIMIT = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_LIMIT;

.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT ROM(.OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT) :> .
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_START = ADDR(.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT);
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_START = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_START;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_END = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_END;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_LIMIT = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_LIMIT;

.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST ROM(.OS_IRQDmaChannel5TransmitComplete_VAR_FAST) :> .
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_START = ADDR(.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST);
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_END = . - 1;
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_LIMIT = .;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_START = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_START;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_END = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_END;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_LIMIT = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_LIMIT;

.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT ROM(.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT) :> .
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT);
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_START = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_START;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_END = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_END;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_LIMIT = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT ROM(.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT);
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_START = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_START;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_END = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_END;
__ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE
#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR
#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_INIT
# undef OS_LINK_CONST_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR )
.OS_SPI_CSIH0_TIR_CAT2_ISR_CONST ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR )
.OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR_INIT )

.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR ROM(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR) :> .
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_START = ADDR(.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR);
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_START = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_START;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_END = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_END;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_LIMIT = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_LIMIT;

.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT ROM(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT);
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST ROM(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST);
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_START = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_START;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_END = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_END;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR
# undef OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_SPI_CSIH0_TIR_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR )
.OS_SPI_CSIH2_TIR_CAT2_ISR_CONST ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR )
.OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR_INIT )

.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR ROM(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR) :> .
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_START = ADDR(.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR);
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_START = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_START;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_END = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_END;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_LIMIT = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_LIMIT;

.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT ROM(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT);
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST ROM(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST);
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_START = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_START;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_END = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_END;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR
# undef OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_SPI_CSIH2_TIR_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR )
.OS_SPI_CSIH3_TIR_CAT2_ISR_CONST ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR )
.OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR_INIT )

.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR ROM(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR) :> .
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_START = ADDR(.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR);
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_START = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_START;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_END = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_END;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_LIMIT = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_LIMIT;

.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT ROM(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT);
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST ROM(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST);
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_START = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_START;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_END = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_END;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR
# undef OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_SPI_CSIH3_TIR_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR_FAR )
.OS_TAUD0_CH00_CAT2_ISR_CONST ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_CONST_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_CONST_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_CONST_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_CONST_START = _OS_TAUD0_CH00_CAT2_ISR_CONST_START;
__OS_TAUD0_CH00_CAT2_ISR_CONST_END = _OS_TAUD0_CH00_CAT2_ISR_CONST_END;
__OS_TAUD0_CH00_CAT2_ISR_CONST_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR_NEAR )
.OS_TAUD0_CH00_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_CONST_FAST_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_CONST_FAST_START = _OS_TAUD0_CH00_CAT2_ISR_CONST_FAST_START;
__OS_TAUD0_CH00_CAT2_ISR_CONST_FAST_END = _OS_TAUD0_CH00_CAT2_ISR_CONST_FAST_END;
__OS_TAUD0_CH00_CAT2_ISR_CONST_FAST_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR_INIT )

.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR ROM(.OS_TAUD0_CH00_CAT2_ISR_VAR) :> .
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_START = ADDR(.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR);
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_START = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_START;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_END = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_END;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_LIMIT = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_LIMIT;

.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT ROM(.OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT);
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST ROM(.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST);
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_START = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_START;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_END = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_END;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR
# undef OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_TAUD0_CH00_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR_FAR )
.OS_TAUD0_CH01_CAT2_ISR_CONST ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_CONST_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_CONST_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_CONST_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_CONST_START = _OS_TAUD0_CH01_CAT2_ISR_CONST_START;
__OS_TAUD0_CH01_CAT2_ISR_CONST_END = _OS_TAUD0_CH01_CAT2_ISR_CONST_END;
__OS_TAUD0_CH01_CAT2_ISR_CONST_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR_NEAR )
.OS_TAUD0_CH01_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_CONST_FAST_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_CONST_FAST_START = _OS_TAUD0_CH01_CAT2_ISR_CONST_FAST_START;
__OS_TAUD0_CH01_CAT2_ISR_CONST_FAST_END = _OS_TAUD0_CH01_CAT2_ISR_CONST_FAST_END;
__OS_TAUD0_CH01_CAT2_ISR_CONST_FAST_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR_INIT )

.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR ROM(.OS_TAUD0_CH01_CAT2_ISR_VAR) :> .
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_START = ADDR(.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR);
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_START = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_START;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_END = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_END;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_LIMIT = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_LIMIT;

.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT ROM(.OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT);
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST ROM(.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST);
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_START = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_START;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_END = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_END;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR
# undef OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_TAUD0_CH01_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR_FAR )
.OS_TAUD0_CH02_CAT2_ISR_CONST ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_CONST_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_CONST_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_CONST_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_CONST_START = _OS_TAUD0_CH02_CAT2_ISR_CONST_START;
__OS_TAUD0_CH02_CAT2_ISR_CONST_END = _OS_TAUD0_CH02_CAT2_ISR_CONST_END;
__OS_TAUD0_CH02_CAT2_ISR_CONST_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR_NEAR )
.OS_TAUD0_CH02_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_CONST_FAST_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_CONST_FAST_START = _OS_TAUD0_CH02_CAT2_ISR_CONST_FAST_START;
__OS_TAUD0_CH02_CAT2_ISR_CONST_FAST_END = _OS_TAUD0_CH02_CAT2_ISR_CONST_FAST_END;
__OS_TAUD0_CH02_CAT2_ISR_CONST_FAST_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR_INIT )

.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR ROM(.OS_TAUD0_CH02_CAT2_ISR_VAR) :> .
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_START = ADDR(.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR);
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_START = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_START;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_END = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_END;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_LIMIT = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_LIMIT;

.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT ROM(.OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT);
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST ROM(.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST);
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_START = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_START;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_END = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_END;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR
# undef OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_TAUD0_CH02_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR_FAR )
.OS_TAUD0_CH04_CAT2_ISR_CONST ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_CONST_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_CONST_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_CONST_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_CONST_START = _OS_TAUD0_CH04_CAT2_ISR_CONST_START;
__OS_TAUD0_CH04_CAT2_ISR_CONST_END = _OS_TAUD0_CH04_CAT2_ISR_CONST_END;
__OS_TAUD0_CH04_CAT2_ISR_CONST_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR_NEAR )
.OS_TAUD0_CH04_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_CONST_FAST_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_CONST_FAST_START = _OS_TAUD0_CH04_CAT2_ISR_CONST_FAST_START;
__OS_TAUD0_CH04_CAT2_ISR_CONST_FAST_END = _OS_TAUD0_CH04_CAT2_ISR_CONST_FAST_END;
__OS_TAUD0_CH04_CAT2_ISR_CONST_FAST_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR_INIT )

.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR ROM(.OS_TAUD0_CH04_CAT2_ISR_VAR) :> .
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_START = ADDR(.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR);
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_START = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_START;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_END = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_END;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_LIMIT = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_LIMIT;

.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT ROM(.OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT);
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST ROM(.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST);
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_START = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_START;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_END = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_END;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR
# undef OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_TAUD0_CH04_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR_FAR )
.OS_TAUD0_CH05_CAT2_ISR_CONST ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_CONST_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_CONST_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_CONST_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_CONST_START = _OS_TAUD0_CH05_CAT2_ISR_CONST_START;
__OS_TAUD0_CH05_CAT2_ISR_CONST_END = _OS_TAUD0_CH05_CAT2_ISR_CONST_END;
__OS_TAUD0_CH05_CAT2_ISR_CONST_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR_NEAR )
.OS_TAUD0_CH05_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_CONST_FAST_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_CONST_FAST_START = _OS_TAUD0_CH05_CAT2_ISR_CONST_FAST_START;
__OS_TAUD0_CH05_CAT2_ISR_CONST_FAST_END = _OS_TAUD0_CH05_CAT2_ISR_CONST_FAST_END;
__OS_TAUD0_CH05_CAT2_ISR_CONST_FAST_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR_INIT )

.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR ROM(.OS_TAUD0_CH05_CAT2_ISR_VAR) :> .
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_START = ADDR(.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR);
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_START = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_START;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_END = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_END;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_LIMIT = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_LIMIT;

.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT ROM(.OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT);
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST ROM(.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST);
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_START = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_START;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_END = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_END;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR
# undef OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_TAUD0_CH05_CAT2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_CONST_FAST_LIMIT;
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_INIT )

.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR ROM(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR) :> .
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_START = ADDR(.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR);
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_END = . - 1;
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_LIMIT = .;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_START = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_START;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_END = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_END;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_LIMIT = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_LIMIT;

.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT ROM(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT) :> .
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_START = ADDR(.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT);
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_END = . - 1;
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_START = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_START;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_END = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_END;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_LIMIT = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_LIMIT;

.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT ROM(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT) :> .
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT);
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_START = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_START;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_END = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_END;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_LIMIT;

.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST ROM(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST) :> .
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_START = ADDR(.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST);
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_END = . - 1;
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_LIMIT = .;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_START = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_START;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_END = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_END;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_LIMIT = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_LIMIT;

.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT ROM(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT) :> .
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT);
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_START = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_START;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_END = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_END;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;

.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT ROM(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT) :> .
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT);
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _ROM_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;

#endif

#ifdef OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR
# undef OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR
# undef OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR
# undef OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_INIT
# undef OS_LINK_CONST_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_INIT
#endif



#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_APP
# undef OS_LINK_CONST_APP
#endif

#ifdef OS_LINK_CONST_TASK
# undef OS_LINK_CONST_TASK
#endif

#ifdef OS_LINK_CONST_ISR
# undef OS_LINK_CONST_ISR
#endif

#ifdef OS_LINK_CONST_KERNEL
# undef OS_LINK_CONST_KERNEL
#endif

#ifdef OS_LINK_CONST_KERNEL_FAR
# undef OS_LINK_CONST_KERNEL_FAR
#endif

#ifdef OS_LINK_CONST_KERNEL_NEAR
# undef OS_LINK_CONST_KERNEL_NEAR
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif

#ifdef OS_LINK_EXCVEC_CONST
# undef OS_LINK_EXCVEC_CONST
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_INIT )
.OS_CORE0_VAR ALIGN(4) :> .
_OS_CORE0_VAR_START = ADDR(.OS_CORE0_VAR);
. = ALIGN(4);
_OS_CORE0_VAR_END = . - 1;
_OS_CORE0_VAR_LIMIT = .;
__OS_CORE0_VAR_START = _OS_CORE0_VAR_START;
__OS_CORE0_VAR_END = _OS_CORE0_VAR_END;
__OS_CORE0_VAR_LIMIT = _OS_CORE0_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT )
.OS_CORE0_VAR_NOINIT ALIGN(4) :> .
_OS_CORE0_VAR_NOINIT_START = ADDR(.OS_CORE0_VAR_NOINIT);
. = ALIGN(4);
_OS_CORE0_VAR_NOINIT_END = . - 1;
_OS_CORE0_VAR_NOINIT_LIMIT = .;
__OS_CORE0_VAR_NOINIT_START = _OS_CORE0_VAR_NOINIT_START;
__OS_CORE0_VAR_NOINIT_END = _OS_CORE0_VAR_NOINIT_END;
__OS_CORE0_VAR_NOINIT_LIMIT = _OS_CORE0_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT )
.OS_CORE0_VAR_FAST ALIGN(4) :> .
_OS_CORE0_VAR_FAST_START = ADDR(.OS_CORE0_VAR_FAST);
. = ALIGN(4);
_OS_CORE0_VAR_FAST_END = . - 1;
_OS_CORE0_VAR_FAST_LIMIT = .;
__OS_CORE0_VAR_FAST_START = _OS_CORE0_VAR_FAST_START;
__OS_CORE0_VAR_FAST_END = _OS_CORE0_VAR_FAST_END;
__OS_CORE0_VAR_FAST_LIMIT = _OS_CORE0_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT )
.OS_CORE0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CORE0_VAR_FAST_NOINIT_START = ADDR(.OS_CORE0_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_CORE0_VAR_FAST_NOINIT_END = . - 1;
_OS_CORE0_VAR_FAST_NOINIT_LIMIT = .;
__OS_CORE0_VAR_FAST_NOINIT_START = _OS_CORE0_VAR_FAST_NOINIT_START;
__OS_CORE0_VAR_FAST_NOINIT_END = _OS_CORE0_VAR_FAST_NOINIT_END;
__OS_CORE0_VAR_FAST_NOINIT_LIMIT = _OS_CORE0_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT )
.OS_CORE0_VAR_NOCACHE ALIGN(4) :> .
_OS_CORE0_VAR_NOCACHE_START = ADDR(.OS_CORE0_VAR_NOCACHE);
. = ALIGN(4);
_OS_CORE0_VAR_NOCACHE_END = . - 1;
_OS_CORE0_VAR_NOCACHE_LIMIT = .;
__OS_CORE0_VAR_NOCACHE_START = _OS_CORE0_VAR_NOCACHE_START;
__OS_CORE0_VAR_NOCACHE_END = _OS_CORE0_VAR_NOCACHE_END;
__OS_CORE0_VAR_NOCACHE_LIMIT = _OS_CORE0_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT )
.OS_CORE0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CORE0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CORE0_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CORE0_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_CORE0_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_CORE0_VAR_NOCACHE_NOINIT_START = _OS_CORE0_VAR_NOCACHE_NOINIT_START;
__OS_CORE0_VAR_NOCACHE_NOINIT_END = _OS_CORE0_VAR_NOCACHE_NOINIT_END;
__OS_CORE0_VAR_NOCACHE_NOINIT_LIMIT = _OS_CORE0_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT )
.OS_CORE0_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CORE0_VAR_FAST_NOCACHE_START = ADDR(.OS_CORE0_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_CORE0_VAR_FAST_NOCACHE_END = . - 1;
_OS_CORE0_VAR_FAST_NOCACHE_LIMIT = .;
__OS_CORE0_VAR_FAST_NOCACHE_START = _OS_CORE0_VAR_FAST_NOCACHE_START;
__OS_CORE0_VAR_FAST_NOCACHE_END = _OS_CORE0_VAR_FAST_NOCACHE_END;
__OS_CORE0_VAR_FAST_NOCACHE_LIMIT = _OS_CORE0_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT )
.OS_CORE0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CORE0_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START = _OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START;
__OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END = _OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END;
__OS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_FAR )
.OS_PUBLIC_CORE0_VAR_NOINIT ALIGN(4) :> .
_OS_PUBLIC_CORE0_VAR_NOINIT_START = ADDR(.OS_PUBLIC_CORE0_VAR_NOINIT);
. = ALIGN(4);
_OS_PUBLIC_CORE0_VAR_NOINIT_END = . - 1;
_OS_PUBLIC_CORE0_VAR_NOINIT_LIMIT = .;
__OS_PUBLIC_CORE0_VAR_NOINIT_START = _OS_PUBLIC_CORE0_VAR_NOINIT_START;
__OS_PUBLIC_CORE0_VAR_NOINIT_END = _OS_PUBLIC_CORE0_VAR_NOINIT_END;
__OS_PUBLIC_CORE0_VAR_NOINIT_LIMIT = _OS_PUBLIC_CORE0_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_NEAR )
.OS_PUBLIC_CORE0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START = ADDR(.OS_PUBLIC_CORE0_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END = . - 1;
_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_LIMIT = .;
__OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START = _OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START;
__OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END = _OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END;
__OS_PUBLIC_CORE0_VAR_FAST_NOINIT_LIMIT = _OS_PUBLIC_CORE0_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_FAR )
.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START = _OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START;
__OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END = _OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END;
__OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_LIMIT = _OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_NEAR )
.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START = _OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START;
__OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END = _OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END;
__OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_FAR )
.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START = _OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START;
__OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END = _OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END;
__OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_LIMIT = _OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_NEAR )
.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START = _OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START;
__OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END = _OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END;
__OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif


#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_ALL_START = .;
__OS_SystemApplication_OsCore0_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT )
.OS_SystemApplication_OsCore0_VAR ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_START = ADDR(.OS_SystemApplication_OsCore0_VAR);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_START = _OS_SystemApplication_OsCore0_VAR_START;
__OS_SystemApplication_OsCore0_VAR_END = _OS_SystemApplication_OsCore0_VAR_END;
__OS_SystemApplication_OsCore0_VAR_LIMIT = _OS_SystemApplication_OsCore0_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT )
.OS_SystemApplication_OsCore0_VAR_NOINIT ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_NOINIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_NOINIT);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_NOINIT_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_NOINIT_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_NOINIT_START = _OS_SystemApplication_OsCore0_VAR_NOINIT_START;
__OS_SystemApplication_OsCore0_VAR_NOINIT_END = _OS_SystemApplication_OsCore0_VAR_NOINIT_END;
__OS_SystemApplication_OsCore0_VAR_NOINIT_LIMIT = _OS_SystemApplication_OsCore0_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT )
.OS_SystemApplication_OsCore0_VAR_ZERO_INIT ALIGN(4) :> .
.OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss CLEAR :> .
_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START = _OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START;
__OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END = _OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END;
__OS_SystemApplication_OsCore0_VAR_ZERO_INIT_LIMIT = _OS_SystemApplication_OsCore0_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT )
.OS_SystemApplication_OsCore0_VAR_FAST ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_FAST_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_FAST_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_FAST_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_FAST_START = _OS_SystemApplication_OsCore0_VAR_FAST_START;
__OS_SystemApplication_OsCore0_VAR_FAST_END = _OS_SystemApplication_OsCore0_VAR_FAST_END;
__OS_SystemApplication_OsCore0_VAR_FAST_LIMIT = _OS_SystemApplication_OsCore0_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT )
.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START = _OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START;
__OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END = _OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END;
__OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_LIMIT = _OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT )
.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START = _OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START;
__OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END = _OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END;
__OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_LIMIT = _OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT )
.OS_SystemApplication_OsCore0_VAR_NOCACHE ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_NOCACHE_START = ADDR(.OS_SystemApplication_OsCore0_VAR_NOCACHE);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_NOCACHE_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_NOCACHE_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_NOCACHE_START = _OS_SystemApplication_OsCore0_VAR_NOCACHE_START;
__OS_SystemApplication_OsCore0_VAR_NOCACHE_END = _OS_SystemApplication_OsCore0_VAR_NOCACHE_END;
__OS_SystemApplication_OsCore0_VAR_NOCACHE_LIMIT = _OS_SystemApplication_OsCore0_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT )
.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START = _OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START;
__OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END = _OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END;
__OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_LIMIT = _OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT )
.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START = _OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START;
__OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END = _OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END;
__OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT )
.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START = _OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START;
__OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END = _OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END;
__OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_LIMIT = _OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT )
.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START = _OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START;
__OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END = _OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END;
__OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
. = ALIGN(4);
_OS_SystemApplication_OsCore0_VAR_ALL_END = . - 1;
__OS_SystemApplication_OsCore0_VAR_ALL_END = . - 1;
_OS_SystemApplication_OsCore0_VAR_ALL_LIMIT = .;
__OS_SystemApplication_OsCore0_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
. = ALIGN(4);
_OS_Default_Init_Task_VAR_ALL_START = .;
__OS_Default_Init_Task_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT )
.OS_Default_Init_Task_VAR ALIGN(4) :> .
_OS_Default_Init_Task_VAR_START = ADDR(.OS_Default_Init_Task_VAR);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_END = . - 1;
_OS_Default_Init_Task_VAR_LIMIT = .;
__OS_Default_Init_Task_VAR_START = _OS_Default_Init_Task_VAR_START;
__OS_Default_Init_Task_VAR_END = _OS_Default_Init_Task_VAR_END;
__OS_Default_Init_Task_VAR_LIMIT = _OS_Default_Init_Task_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT )
.OS_Default_Init_Task_VAR_NOINIT ALIGN(4) :> .
_OS_Default_Init_Task_VAR_NOINIT_START = ADDR(.OS_Default_Init_Task_VAR_NOINIT);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_NOINIT_END = . - 1;
_OS_Default_Init_Task_VAR_NOINIT_LIMIT = .;
__OS_Default_Init_Task_VAR_NOINIT_START = _OS_Default_Init_Task_VAR_NOINIT_START;
__OS_Default_Init_Task_VAR_NOINIT_END = _OS_Default_Init_Task_VAR_NOINIT_END;
__OS_Default_Init_Task_VAR_NOINIT_LIMIT = _OS_Default_Init_Task_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT )
.OS_Default_Init_Task_VAR_ZERO_INIT ALIGN(4) :> .
.OS_Default_Init_Task_VAR_ZERO_INIT_bss CLEAR :> .
_OS_Default_Init_Task_VAR_ZERO_INIT_START = ADDR(.OS_Default_Init_Task_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_ZERO_INIT_END = . - 1;
_OS_Default_Init_Task_VAR_ZERO_INIT_LIMIT = .;
__OS_Default_Init_Task_VAR_ZERO_INIT_START = _OS_Default_Init_Task_VAR_ZERO_INIT_START;
__OS_Default_Init_Task_VAR_ZERO_INIT_END = _OS_Default_Init_Task_VAR_ZERO_INIT_END;
__OS_Default_Init_Task_VAR_ZERO_INIT_LIMIT = _OS_Default_Init_Task_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT )
.OS_Default_Init_Task_VAR_FAST ALIGN(4) :> .
_OS_Default_Init_Task_VAR_FAST_START = ADDR(.OS_Default_Init_Task_VAR_FAST);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_FAST_END = . - 1;
_OS_Default_Init_Task_VAR_FAST_LIMIT = .;
__OS_Default_Init_Task_VAR_FAST_START = _OS_Default_Init_Task_VAR_FAST_START;
__OS_Default_Init_Task_VAR_FAST_END = _OS_Default_Init_Task_VAR_FAST_END;
__OS_Default_Init_Task_VAR_FAST_LIMIT = _OS_Default_Init_Task_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT )
.OS_Default_Init_Task_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_Default_Init_Task_VAR_FAST_NOINIT_START = ADDR(.OS_Default_Init_Task_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_FAST_NOINIT_END = . - 1;
_OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT = .;
__OS_Default_Init_Task_VAR_FAST_NOINIT_START = _OS_Default_Init_Task_VAR_FAST_NOINIT_START;
__OS_Default_Init_Task_VAR_FAST_NOINIT_END = _OS_Default_Init_Task_VAR_FAST_NOINIT_END;
__OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT = _OS_Default_Init_Task_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT )
.OS_Default_Init_Task_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_Default_Init_Task_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START = ADDR(.OS_Default_Init_Task_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_Default_Init_Task_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START = _OS_Default_Init_Task_VAR_FAST_ZERO_INIT_START;
__OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END = _OS_Default_Init_Task_VAR_FAST_ZERO_INIT_END;
__OS_Default_Init_Task_VAR_FAST_ZERO_INIT_LIMIT = _OS_Default_Init_Task_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT )
.OS_Default_Init_Task_VAR_NOCACHE ALIGN(4) :> .
_OS_Default_Init_Task_VAR_NOCACHE_START = ADDR(.OS_Default_Init_Task_VAR_NOCACHE);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_NOCACHE_END = . - 1;
_OS_Default_Init_Task_VAR_NOCACHE_LIMIT = .;
__OS_Default_Init_Task_VAR_NOCACHE_START = _OS_Default_Init_Task_VAR_NOCACHE_START;
__OS_Default_Init_Task_VAR_NOCACHE_END = _OS_Default_Init_Task_VAR_NOCACHE_END;
__OS_Default_Init_Task_VAR_NOCACHE_LIMIT = _OS_Default_Init_Task_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT )
.OS_Default_Init_Task_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START = ADDR(.OS_Default_Init_Task_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_Default_Init_Task_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START = _OS_Default_Init_Task_VAR_NOCACHE_NOINIT_START;
__OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END = _OS_Default_Init_Task_VAR_NOCACHE_NOINIT_END;
__OS_Default_Init_Task_VAR_NOCACHE_NOINIT_LIMIT = _OS_Default_Init_Task_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT )
.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_START = _OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_START;
__OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_END = _OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_END;
__OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_Default_Init_Task_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT )
.OS_Default_Init_Task_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_Default_Init_Task_VAR_FAST_NOCACHE_START = ADDR(.OS_Default_Init_Task_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_FAST_NOCACHE_END = . - 1;
_OS_Default_Init_Task_VAR_FAST_NOCACHE_LIMIT = .;
__OS_Default_Init_Task_VAR_FAST_NOCACHE_START = _OS_Default_Init_Task_VAR_FAST_NOCACHE_START;
__OS_Default_Init_Task_VAR_FAST_NOCACHE_END = _OS_Default_Init_Task_VAR_FAST_NOCACHE_END;
__OS_Default_Init_Task_VAR_FAST_NOCACHE_LIMIT = _OS_Default_Init_Task_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT )
.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START = _OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_START;
__OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END = _OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_END;
__OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_Default_Init_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT )
.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_Default_Init_Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
. = ALIGN(4);
_OS_Default_Init_Task_VAR_ALL_END = . - 1;
__OS_Default_Init_Task_VAR_ALL_END = . - 1;
_OS_Default_Init_Task_VAR_ALL_LIMIT = .;
__OS_Default_Init_Task_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_DEFAULT_INIT_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_IO_TASK
. = ALIGN(4);
_OS_IO_Task_VAR_ALL_START = .;
__OS_IO_Task_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE_INIT )
.OS_IO_Task_VAR ALIGN(4) :> .
_OS_IO_Task_VAR_START = ADDR(.OS_IO_Task_VAR);
. = ALIGN(4);
_OS_IO_Task_VAR_END = . - 1;
_OS_IO_Task_VAR_LIMIT = .;
__OS_IO_Task_VAR_START = _OS_IO_Task_VAR_START;
__OS_IO_Task_VAR_END = _OS_IO_Task_VAR_END;
__OS_IO_Task_VAR_LIMIT = _OS_IO_Task_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE_NOINIT )
.OS_IO_Task_VAR_NOINIT ALIGN(4) :> .
_OS_IO_Task_VAR_NOINIT_START = ADDR(.OS_IO_Task_VAR_NOINIT);
. = ALIGN(4);
_OS_IO_Task_VAR_NOINIT_END = . - 1;
_OS_IO_Task_VAR_NOINIT_LIMIT = .;
__OS_IO_Task_VAR_NOINIT_START = _OS_IO_Task_VAR_NOINIT_START;
__OS_IO_Task_VAR_NOINIT_END = _OS_IO_Task_VAR_NOINIT_END;
__OS_IO_Task_VAR_NOINIT_LIMIT = _OS_IO_Task_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE_ZERO_INIT )
.OS_IO_Task_VAR_ZERO_INIT ALIGN(4) :> .
.OS_IO_Task_VAR_ZERO_INIT_bss CLEAR :> .
_OS_IO_Task_VAR_ZERO_INIT_START = ADDR(.OS_IO_Task_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_IO_Task_VAR_ZERO_INIT_END = . - 1;
_OS_IO_Task_VAR_ZERO_INIT_LIMIT = .;
__OS_IO_Task_VAR_ZERO_INIT_START = _OS_IO_Task_VAR_ZERO_INIT_START;
__OS_IO_Task_VAR_ZERO_INIT_END = _OS_IO_Task_VAR_ZERO_INIT_END;
__OS_IO_Task_VAR_ZERO_INIT_LIMIT = _OS_IO_Task_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE_INIT )
.OS_IO_Task_VAR_FAST ALIGN(4) :> .
_OS_IO_Task_VAR_FAST_START = ADDR(.OS_IO_Task_VAR_FAST);
. = ALIGN(4);
_OS_IO_Task_VAR_FAST_END = . - 1;
_OS_IO_Task_VAR_FAST_LIMIT = .;
__OS_IO_Task_VAR_FAST_START = _OS_IO_Task_VAR_FAST_START;
__OS_IO_Task_VAR_FAST_END = _OS_IO_Task_VAR_FAST_END;
__OS_IO_Task_VAR_FAST_LIMIT = _OS_IO_Task_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE_NOINIT )
.OS_IO_Task_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_IO_Task_VAR_FAST_NOINIT_START = ADDR(.OS_IO_Task_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_IO_Task_VAR_FAST_NOINIT_END = . - 1;
_OS_IO_Task_VAR_FAST_NOINIT_LIMIT = .;
__OS_IO_Task_VAR_FAST_NOINIT_START = _OS_IO_Task_VAR_FAST_NOINIT_START;
__OS_IO_Task_VAR_FAST_NOINIT_END = _OS_IO_Task_VAR_FAST_NOINIT_END;
__OS_IO_Task_VAR_FAST_NOINIT_LIMIT = _OS_IO_Task_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE_ZERO_INIT )
.OS_IO_Task_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_IO_Task_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_IO_Task_VAR_FAST_ZERO_INIT_START = ADDR(.OS_IO_Task_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_IO_Task_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_IO_Task_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_IO_Task_VAR_FAST_ZERO_INIT_START = _OS_IO_Task_VAR_FAST_ZERO_INIT_START;
__OS_IO_Task_VAR_FAST_ZERO_INIT_END = _OS_IO_Task_VAR_FAST_ZERO_INIT_END;
__OS_IO_Task_VAR_FAST_ZERO_INIT_LIMIT = _OS_IO_Task_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE_INIT )
.OS_IO_Task_VAR_NOCACHE ALIGN(4) :> .
_OS_IO_Task_VAR_NOCACHE_START = ADDR(.OS_IO_Task_VAR_NOCACHE);
. = ALIGN(4);
_OS_IO_Task_VAR_NOCACHE_END = . - 1;
_OS_IO_Task_VAR_NOCACHE_LIMIT = .;
__OS_IO_Task_VAR_NOCACHE_START = _OS_IO_Task_VAR_NOCACHE_START;
__OS_IO_Task_VAR_NOCACHE_END = _OS_IO_Task_VAR_NOCACHE_END;
__OS_IO_Task_VAR_NOCACHE_LIMIT = _OS_IO_Task_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE_NOINIT )
.OS_IO_Task_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IO_Task_VAR_NOCACHE_NOINIT_START = ADDR(.OS_IO_Task_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IO_Task_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_IO_Task_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_IO_Task_VAR_NOCACHE_NOINIT_START = _OS_IO_Task_VAR_NOCACHE_NOINIT_START;
__OS_IO_Task_VAR_NOCACHE_NOINIT_END = _OS_IO_Task_VAR_NOCACHE_NOINIT_END;
__OS_IO_Task_VAR_NOCACHE_NOINIT_LIMIT = _OS_IO_Task_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE_ZERO_INIT )
.OS_IO_Task_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IO_Task_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IO_Task_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_IO_Task_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IO_Task_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IO_Task_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IO_Task_VAR_NOCACHE_ZERO_INIT_START = _OS_IO_Task_VAR_NOCACHE_ZERO_INIT_START;
__OS_IO_Task_VAR_NOCACHE_ZERO_INIT_END = _OS_IO_Task_VAR_NOCACHE_ZERO_INIT_END;
__OS_IO_Task_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_IO_Task_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE_INIT )
.OS_IO_Task_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_IO_Task_VAR_FAST_NOCACHE_START = ADDR(.OS_IO_Task_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_IO_Task_VAR_FAST_NOCACHE_END = . - 1;
_OS_IO_Task_VAR_FAST_NOCACHE_LIMIT = .;
__OS_IO_Task_VAR_FAST_NOCACHE_START = _OS_IO_Task_VAR_FAST_NOCACHE_START;
__OS_IO_Task_VAR_FAST_NOCACHE_END = _OS_IO_Task_VAR_FAST_NOCACHE_END;
__OS_IO_Task_VAR_FAST_NOCACHE_LIMIT = _OS_IO_Task_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE_NOINIT )
.OS_IO_Task_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IO_Task_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_IO_Task_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IO_Task_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_IO_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_IO_Task_VAR_FAST_NOCACHE_NOINIT_START = _OS_IO_Task_VAR_FAST_NOCACHE_NOINIT_START;
__OS_IO_Task_VAR_FAST_NOCACHE_NOINIT_END = _OS_IO_Task_VAR_FAST_NOCACHE_NOINIT_END;
__OS_IO_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_IO_Task_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE_ZERO_INIT )
.OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_IO_Task_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK
. = ALIGN(4);
_OS_IO_Task_VAR_ALL_END = . - 1;
__OS_IO_Task_VAR_ALL_END = . - 1;
_OS_IO_Task_VAR_ALL_LIMIT = .;
__OS_IO_Task_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_IO_TASK
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_FAR
# undef OS_LINK_VAR_TASK_IO_TASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IO_TASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IO_TASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_NEAR
# undef OS_LINK_VAR_TASK_IO_TASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IO_TASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IO_TASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_ALL_START = .;
__OS_IdleTask_OsCore0_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT )
.OS_IdleTask_OsCore0_VAR ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_START = ADDR(.OS_IdleTask_OsCore0_VAR);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_END = . - 1;
_OS_IdleTask_OsCore0_VAR_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_START = _OS_IdleTask_OsCore0_VAR_START;
__OS_IdleTask_OsCore0_VAR_END = _OS_IdleTask_OsCore0_VAR_END;
__OS_IdleTask_OsCore0_VAR_LIMIT = _OS_IdleTask_OsCore0_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT )
.OS_IdleTask_OsCore0_VAR_NOINIT ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_NOINIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_NOINIT);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_NOINIT_END = . - 1;
_OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_NOINIT_START = _OS_IdleTask_OsCore0_VAR_NOINIT_START;
__OS_IdleTask_OsCore0_VAR_NOINIT_END = _OS_IdleTask_OsCore0_VAR_NOINIT_END;
__OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT = _OS_IdleTask_OsCore0_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT )
.OS_IdleTask_OsCore0_VAR_ZERO_INIT ALIGN(4) :> .
.OS_IdleTask_OsCore0_VAR_ZERO_INIT_bss CLEAR :> .
_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END = . - 1;
_OS_IdleTask_OsCore0_VAR_ZERO_INIT_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_ZERO_INIT_START = _OS_IdleTask_OsCore0_VAR_ZERO_INIT_START;
__OS_IdleTask_OsCore0_VAR_ZERO_INIT_END = _OS_IdleTask_OsCore0_VAR_ZERO_INIT_END;
__OS_IdleTask_OsCore0_VAR_ZERO_INIT_LIMIT = _OS_IdleTask_OsCore0_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT )
.OS_IdleTask_OsCore0_VAR_FAST ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_FAST_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_FAST_END = . - 1;
_OS_IdleTask_OsCore0_VAR_FAST_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_FAST_START = _OS_IdleTask_OsCore0_VAR_FAST_START;
__OS_IdleTask_OsCore0_VAR_FAST_END = _OS_IdleTask_OsCore0_VAR_FAST_END;
__OS_IdleTask_OsCore0_VAR_FAST_LIMIT = _OS_IdleTask_OsCore0_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT )
.OS_IdleTask_OsCore0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END = . - 1;
_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START = _OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START;
__OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END = _OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END;
__OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT = _OS_IdleTask_OsCore0_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT )
.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START = _OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START;
__OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END = _OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END;
__OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_LIMIT = _OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT )
.OS_IdleTask_OsCore0_VAR_NOCACHE ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_NOCACHE_START = ADDR(.OS_IdleTask_OsCore0_VAR_NOCACHE);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_NOCACHE_END = . - 1;
_OS_IdleTask_OsCore0_VAR_NOCACHE_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_NOCACHE_START = _OS_IdleTask_OsCore0_VAR_NOCACHE_START;
__OS_IdleTask_OsCore0_VAR_NOCACHE_END = _OS_IdleTask_OsCore0_VAR_NOCACHE_END;
__OS_IdleTask_OsCore0_VAR_NOCACHE_LIMIT = _OS_IdleTask_OsCore0_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT )
.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START = _OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START;
__OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END = _OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END;
__OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_LIMIT = _OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT )
.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_START = _OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_START;
__OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_END = _OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_END;
__OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT )
.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_END = . - 1;
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_START = _OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_START;
__OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_END = _OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_END;
__OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_LIMIT = _OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT )
.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START = _OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START;
__OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END = _OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END;
__OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
. = ALIGN(4);
_OS_IdleTask_OsCore0_VAR_ALL_END = . - 1;
__OS_IdleTask_OsCore0_VAR_ALL_END = . - 1;
_OS_IdleTask_OsCore0_VAR_ALL_LIMIT = .;
__OS_IdleTask_OsCore0_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_MYTASK
. = ALIGN(4);
_OS_MyTask_VAR_ALL_START = .;
__OS_MyTask_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_CACHE_INIT )
.OS_MyTask_VAR ALIGN(4) :> .
_OS_MyTask_VAR_START = ADDR(.OS_MyTask_VAR);
. = ALIGN(4);
_OS_MyTask_VAR_END = . - 1;
_OS_MyTask_VAR_LIMIT = .;
__OS_MyTask_VAR_START = _OS_MyTask_VAR_START;
__OS_MyTask_VAR_END = _OS_MyTask_VAR_END;
__OS_MyTask_VAR_LIMIT = _OS_MyTask_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_CACHE_NOINIT )
.OS_MyTask_VAR_NOINIT ALIGN(4) :> .
_OS_MyTask_VAR_NOINIT_START = ADDR(.OS_MyTask_VAR_NOINIT);
. = ALIGN(4);
_OS_MyTask_VAR_NOINIT_END = . - 1;
_OS_MyTask_VAR_NOINIT_LIMIT = .;
__OS_MyTask_VAR_NOINIT_START = _OS_MyTask_VAR_NOINIT_START;
__OS_MyTask_VAR_NOINIT_END = _OS_MyTask_VAR_NOINIT_END;
__OS_MyTask_VAR_NOINIT_LIMIT = _OS_MyTask_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_CACHE_ZERO_INIT )
.OS_MyTask_VAR_ZERO_INIT ALIGN(4) :> .
.OS_MyTask_VAR_ZERO_INIT_bss CLEAR :> .
_OS_MyTask_VAR_ZERO_INIT_START = ADDR(.OS_MyTask_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_MyTask_VAR_ZERO_INIT_END = . - 1;
_OS_MyTask_VAR_ZERO_INIT_LIMIT = .;
__OS_MyTask_VAR_ZERO_INIT_START = _OS_MyTask_VAR_ZERO_INIT_START;
__OS_MyTask_VAR_ZERO_INIT_END = _OS_MyTask_VAR_ZERO_INIT_END;
__OS_MyTask_VAR_ZERO_INIT_LIMIT = _OS_MyTask_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE_INIT )
.OS_MyTask_VAR_FAST ALIGN(4) :> .
_OS_MyTask_VAR_FAST_START = ADDR(.OS_MyTask_VAR_FAST);
. = ALIGN(4);
_OS_MyTask_VAR_FAST_END = . - 1;
_OS_MyTask_VAR_FAST_LIMIT = .;
__OS_MyTask_VAR_FAST_START = _OS_MyTask_VAR_FAST_START;
__OS_MyTask_VAR_FAST_END = _OS_MyTask_VAR_FAST_END;
__OS_MyTask_VAR_FAST_LIMIT = _OS_MyTask_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE_NOINIT )
.OS_MyTask_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_MyTask_VAR_FAST_NOINIT_START = ADDR(.OS_MyTask_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_MyTask_VAR_FAST_NOINIT_END = . - 1;
_OS_MyTask_VAR_FAST_NOINIT_LIMIT = .;
__OS_MyTask_VAR_FAST_NOINIT_START = _OS_MyTask_VAR_FAST_NOINIT_START;
__OS_MyTask_VAR_FAST_NOINIT_END = _OS_MyTask_VAR_FAST_NOINIT_END;
__OS_MyTask_VAR_FAST_NOINIT_LIMIT = _OS_MyTask_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE_ZERO_INIT )
.OS_MyTask_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_MyTask_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_MyTask_VAR_FAST_ZERO_INIT_START = ADDR(.OS_MyTask_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_MyTask_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_MyTask_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_MyTask_VAR_FAST_ZERO_INIT_START = _OS_MyTask_VAR_FAST_ZERO_INIT_START;
__OS_MyTask_VAR_FAST_ZERO_INIT_END = _OS_MyTask_VAR_FAST_ZERO_INIT_END;
__OS_MyTask_VAR_FAST_ZERO_INIT_LIMIT = _OS_MyTask_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE_INIT )
.OS_MyTask_VAR_NOCACHE ALIGN(4) :> .
_OS_MyTask_VAR_NOCACHE_START = ADDR(.OS_MyTask_VAR_NOCACHE);
. = ALIGN(4);
_OS_MyTask_VAR_NOCACHE_END = . - 1;
_OS_MyTask_VAR_NOCACHE_LIMIT = .;
__OS_MyTask_VAR_NOCACHE_START = _OS_MyTask_VAR_NOCACHE_START;
__OS_MyTask_VAR_NOCACHE_END = _OS_MyTask_VAR_NOCACHE_END;
__OS_MyTask_VAR_NOCACHE_LIMIT = _OS_MyTask_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE_NOINIT )
.OS_MyTask_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_MyTask_VAR_NOCACHE_NOINIT_START = ADDR(.OS_MyTask_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_MyTask_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_MyTask_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_MyTask_VAR_NOCACHE_NOINIT_START = _OS_MyTask_VAR_NOCACHE_NOINIT_START;
__OS_MyTask_VAR_NOCACHE_NOINIT_END = _OS_MyTask_VAR_NOCACHE_NOINIT_END;
__OS_MyTask_VAR_NOCACHE_NOINIT_LIMIT = _OS_MyTask_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE_ZERO_INIT )
.OS_MyTask_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_MyTask_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_MyTask_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_MyTask_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_MyTask_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_MyTask_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_MyTask_VAR_NOCACHE_ZERO_INIT_START = _OS_MyTask_VAR_NOCACHE_ZERO_INIT_START;
__OS_MyTask_VAR_NOCACHE_ZERO_INIT_END = _OS_MyTask_VAR_NOCACHE_ZERO_INIT_END;
__OS_MyTask_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_MyTask_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE_INIT )
.OS_MyTask_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_MyTask_VAR_FAST_NOCACHE_START = ADDR(.OS_MyTask_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_MyTask_VAR_FAST_NOCACHE_END = . - 1;
_OS_MyTask_VAR_FAST_NOCACHE_LIMIT = .;
__OS_MyTask_VAR_FAST_NOCACHE_START = _OS_MyTask_VAR_FAST_NOCACHE_START;
__OS_MyTask_VAR_FAST_NOCACHE_END = _OS_MyTask_VAR_FAST_NOCACHE_END;
__OS_MyTask_VAR_FAST_NOCACHE_LIMIT = _OS_MyTask_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE_NOINIT )
.OS_MyTask_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_MyTask_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_MyTask_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_MyTask_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_MyTask_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_MyTask_VAR_FAST_NOCACHE_NOINIT_START = _OS_MyTask_VAR_FAST_NOCACHE_NOINIT_START;
__OS_MyTask_VAR_FAST_NOCACHE_NOINIT_END = _OS_MyTask_VAR_FAST_NOCACHE_NOINIT_END;
__OS_MyTask_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_MyTask_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_MYTASK ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE_ZERO_INIT )
.OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_MyTask_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK
. = ALIGN(4);
_OS_MyTask_VAR_ALL_END = . - 1;
__OS_MyTask_VAR_ALL_END = . - 1;
_OS_MyTask_VAR_ALL_LIMIT = .;
__OS_MyTask_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_MYTASK
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_FAR
# undef OS_LINK_VAR_TASK_MYTASK_FAR
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_FAR_CACHE
# undef OS_LINK_VAR_TASK_MYTASK_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_MYTASK_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_MYTASK_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_MYTASK_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_MYTASK_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_NEAR
# undef OS_LINK_VAR_TASK_MYTASK_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE
# undef OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_MYTASK_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_MYTASK_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_ALL_START = .;
__OS_OsTask_ApplInitDeInit_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE_INIT )
.OS_OsTask_ApplInitDeInit_VAR ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_VAR_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_START = _OS_OsTask_ApplInitDeInit_VAR_START;
__OS_OsTask_ApplInitDeInit_VAR_END = _OS_OsTask_ApplInitDeInit_VAR_END;
__OS_OsTask_ApplInitDeInit_VAR_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE_NOINIT )
.OS_OsTask_ApplInitDeInit_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_VAR_NOINIT_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_NOINIT_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_NOINIT_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_NOINIT_START = _OS_OsTask_ApplInitDeInit_VAR_NOINIT_START;
__OS_OsTask_ApplInitDeInit_VAR_NOINIT_END = _OS_OsTask_ApplInitDeInit_VAR_NOINIT_END;
__OS_OsTask_ApplInitDeInit_VAR_NOINIT_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE_ZERO_INIT )
.OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_START = _OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_START;
__OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_END = _OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_END;
__OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE_INIT )
.OS_OsTask_ApplInitDeInit_VAR_FAST ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_VAR_FAST_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_FAST_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_FAST_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_FAST_START = _OS_OsTask_ApplInitDeInit_VAR_FAST_START;
__OS_OsTask_ApplInitDeInit_VAR_FAST_END = _OS_OsTask_ApplInitDeInit_VAR_FAST_END;
__OS_OsTask_ApplInitDeInit_VAR_FAST_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE_NOINIT )
.OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_START = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_START;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_END = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_END;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_START = _OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_END = _OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE_INIT )
.OS_OsTask_ApplInitDeInit_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_VAR_NOCACHE_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_NOCACHE_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_NOCACHE_START = _OS_OsTask_ApplInitDeInit_VAR_NOCACHE_START;
__OS_OsTask_ApplInitDeInit_VAR_NOCACHE_END = _OS_OsTask_ApplInitDeInit_VAR_NOCACHE_END;
__OS_OsTask_ApplInitDeInit_VAR_NOCACHE_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE_NOINIT )
.OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT_START = _OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT_END = _OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE_INIT )
.OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_START = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_START;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_END = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_END;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE_NOINIT )
.OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_ApplInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT
. = ALIGN(4);
_OS_OsTask_ApplInitDeInit_VAR_ALL_END = . - 1;
__OS_OsTask_ApplInitDeInit_VAR_ALL_END = . - 1;
_OS_OsTask_ApplInitDeInit_VAR_ALL_LIMIT = .;
__OS_OsTask_ApplInitDeInit_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLINITDEINIT_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_ALL_START = .;
__OS_OsTask_ApplMainFunctions_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE_INIT )
.OS_OsTask_ApplMainFunctions_VAR ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_VAR_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_START = _OS_OsTask_ApplMainFunctions_VAR_START;
__OS_OsTask_ApplMainFunctions_VAR_END = _OS_OsTask_ApplMainFunctions_VAR_END;
__OS_OsTask_ApplMainFunctions_VAR_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE_NOINIT )
.OS_OsTask_ApplMainFunctions_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_VAR_NOINIT_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_NOINIT_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_NOINIT_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_NOINIT_START = _OS_OsTask_ApplMainFunctions_VAR_NOINIT_START;
__OS_OsTask_ApplMainFunctions_VAR_NOINIT_END = _OS_OsTask_ApplMainFunctions_VAR_NOINIT_END;
__OS_OsTask_ApplMainFunctions_VAR_NOINIT_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE_ZERO_INIT )
.OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_START = _OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_START;
__OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_END = _OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_END;
__OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE_INIT )
.OS_OsTask_ApplMainFunctions_VAR_FAST ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_VAR_FAST_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_FAST_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_FAST_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_FAST_START = _OS_OsTask_ApplMainFunctions_VAR_FAST_START;
__OS_OsTask_ApplMainFunctions_VAR_FAST_END = _OS_OsTask_ApplMainFunctions_VAR_FAST_END;
__OS_OsTask_ApplMainFunctions_VAR_FAST_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE_NOINIT )
.OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_START = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_START;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_END = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_END;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_START = _OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_END = _OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE_INIT )
.OS_OsTask_ApplMainFunctions_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_VAR_NOCACHE_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_NOCACHE_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_NOCACHE_START = _OS_OsTask_ApplMainFunctions_VAR_NOCACHE_START;
__OS_OsTask_ApplMainFunctions_VAR_NOCACHE_END = _OS_OsTask_ApplMainFunctions_VAR_NOCACHE_END;
__OS_OsTask_ApplMainFunctions_VAR_NOCACHE_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE_NOINIT )
.OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT_START = _OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT_END = _OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE_INIT )
.OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_START = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_START;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_END = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_END;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE_NOINIT )
.OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_ApplMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS
. = ALIGN(4);
_OS_OsTask_ApplMainFunctions_VAR_ALL_END = . - 1;
__OS_OsTask_ApplMainFunctions_VAR_ALL_END = . - 1;
_OS_OsTask_ApplMainFunctions_VAR_ALL_LIMIT = .;
__OS_OsTask_ApplMainFunctions_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLMAINFUNCTIONS_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_ALL_START = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE_INIT )
.OS_OsTask_ApplTimedInitDeInit_VAR ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_START = _OS_OsTask_ApplTimedInitDeInit_VAR_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_END = _OS_OsTask_ApplTimedInitDeInit_VAR_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE_NOINIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_START = _OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_END = _OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE_ZERO_INIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_START = _OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_END = _OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE_INIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_FAST ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_START = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_END = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE_NOINIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_START = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_END = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_START = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_END = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE_INIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_START = _OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_END = _OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE_NOINIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT_START = _OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT_END = _OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE_INIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_START = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_END = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE_NOINIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_ApplTimedInitDeInit_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT
. = ALIGN(4);
_OS_OsTask_ApplTimedInitDeInit_VAR_ALL_END = . - 1;
__OS_OsTask_ApplTimedInitDeInit_VAR_ALL_END = . - 1;
_OS_OsTask_ApplTimedInitDeInit_VAR_ALL_LIMIT = .;
__OS_OsTask_ApplTimedInitDeInit_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLTIMEDINITDEINIT_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_ALL_START = .;
__OS_OsTask_ApplVerify_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE_INIT )
.OS_OsTask_ApplVerify_VAR ALIGN(4) :> .
_OS_OsTask_ApplVerify_VAR_START = ADDR(.OS_OsTask_ApplVerify_VAR);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_END = . - 1;
_OS_OsTask_ApplVerify_VAR_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_START = _OS_OsTask_ApplVerify_VAR_START;
__OS_OsTask_ApplVerify_VAR_END = _OS_OsTask_ApplVerify_VAR_END;
__OS_OsTask_ApplVerify_VAR_LIMIT = _OS_OsTask_ApplVerify_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE_NOINIT )
.OS_OsTask_ApplVerify_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplVerify_VAR_NOINIT_START = ADDR(.OS_OsTask_ApplVerify_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_NOINIT_END = . - 1;
_OS_OsTask_ApplVerify_VAR_NOINIT_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_NOINIT_START = _OS_OsTask_ApplVerify_VAR_NOINIT_START;
__OS_OsTask_ApplVerify_VAR_NOINIT_END = _OS_OsTask_ApplVerify_VAR_NOINIT_END;
__OS_OsTask_ApplVerify_VAR_NOINIT_LIMIT = _OS_OsTask_ApplVerify_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE_ZERO_INIT )
.OS_OsTask_ApplVerify_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplVerify_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplVerify_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_ApplVerify_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplVerify_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_ZERO_INIT_START = _OS_OsTask_ApplVerify_VAR_ZERO_INIT_START;
__OS_OsTask_ApplVerify_VAR_ZERO_INIT_END = _OS_OsTask_ApplVerify_VAR_ZERO_INIT_END;
__OS_OsTask_ApplVerify_VAR_ZERO_INIT_LIMIT = _OS_OsTask_ApplVerify_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE_INIT )
.OS_OsTask_ApplVerify_VAR_FAST ALIGN(4) :> .
_OS_OsTask_ApplVerify_VAR_FAST_START = ADDR(.OS_OsTask_ApplVerify_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_FAST_END = . - 1;
_OS_OsTask_ApplVerify_VAR_FAST_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_FAST_START = _OS_OsTask_ApplVerify_VAR_FAST_START;
__OS_OsTask_ApplVerify_VAR_FAST_END = _OS_OsTask_ApplVerify_VAR_FAST_END;
__OS_OsTask_ApplVerify_VAR_FAST_LIMIT = _OS_OsTask_ApplVerify_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE_NOINIT )
.OS_OsTask_ApplVerify_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_ApplVerify_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_ApplVerify_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_FAST_NOINIT_START = _OS_OsTask_ApplVerify_VAR_FAST_NOINIT_START;
__OS_OsTask_ApplVerify_VAR_FAST_NOINIT_END = _OS_OsTask_ApplVerify_VAR_FAST_NOINIT_END;
__OS_OsTask_ApplVerify_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_ApplVerify_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_START = _OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_END = _OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_ApplVerify_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE_INIT )
.OS_OsTask_ApplVerify_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_ApplVerify_VAR_NOCACHE_START = ADDR(.OS_OsTask_ApplVerify_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_NOCACHE_END = . - 1;
_OS_OsTask_ApplVerify_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_NOCACHE_START = _OS_OsTask_ApplVerify_VAR_NOCACHE_START;
__OS_OsTask_ApplVerify_VAR_NOCACHE_END = _OS_OsTask_ApplVerify_VAR_NOCACHE_END;
__OS_OsTask_ApplVerify_VAR_NOCACHE_LIMIT = _OS_OsTask_ApplVerify_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE_NOINIT )
.OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT_START = _OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT_END = _OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_ApplVerify_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_ApplVerify_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE_INIT )
.OS_OsTask_ApplVerify_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_ApplVerify_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_START = _OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_START;
__OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_END = _OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_END;
__OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE_NOINIT )
.OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_ApplVerify_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY
. = ALIGN(4);
_OS_OsTask_ApplVerify_VAR_ALL_END = . - 1;
__OS_OsTask_ApplVerify_VAR_ALL_END = . - 1;
_OS_OsTask_ApplVerify_VAR_ALL_LIMIT = .;
__OS_OsTask_ApplVerify_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_APPLVERIFY_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND
. = ALIGN(4);
_OS_OsTask_Background_VAR_ALL_START = .;
__OS_OsTask_Background_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE_INIT )
.OS_OsTask_Background_VAR ALIGN(4) :> .
_OS_OsTask_Background_VAR_START = ADDR(.OS_OsTask_Background_VAR);
. = ALIGN(4);
_OS_OsTask_Background_VAR_END = . - 1;
_OS_OsTask_Background_VAR_LIMIT = .;
__OS_OsTask_Background_VAR_START = _OS_OsTask_Background_VAR_START;
__OS_OsTask_Background_VAR_END = _OS_OsTask_Background_VAR_END;
__OS_OsTask_Background_VAR_LIMIT = _OS_OsTask_Background_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE_NOINIT )
.OS_OsTask_Background_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_Background_VAR_NOINIT_START = ADDR(.OS_OsTask_Background_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_Background_VAR_NOINIT_END = . - 1;
_OS_OsTask_Background_VAR_NOINIT_LIMIT = .;
__OS_OsTask_Background_VAR_NOINIT_START = _OS_OsTask_Background_VAR_NOINIT_START;
__OS_OsTask_Background_VAR_NOINIT_END = _OS_OsTask_Background_VAR_NOINIT_END;
__OS_OsTask_Background_VAR_NOINIT_LIMIT = _OS_OsTask_Background_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE_ZERO_INIT )
.OS_OsTask_Background_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Background_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Background_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_Background_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Background_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_Background_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_Background_VAR_ZERO_INIT_START = _OS_OsTask_Background_VAR_ZERO_INIT_START;
__OS_OsTask_Background_VAR_ZERO_INIT_END = _OS_OsTask_Background_VAR_ZERO_INIT_END;
__OS_OsTask_Background_VAR_ZERO_INIT_LIMIT = _OS_OsTask_Background_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE_INIT )
.OS_OsTask_Background_VAR_FAST ALIGN(4) :> .
_OS_OsTask_Background_VAR_FAST_START = ADDR(.OS_OsTask_Background_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_Background_VAR_FAST_END = . - 1;
_OS_OsTask_Background_VAR_FAST_LIMIT = .;
__OS_OsTask_Background_VAR_FAST_START = _OS_OsTask_Background_VAR_FAST_START;
__OS_OsTask_Background_VAR_FAST_END = _OS_OsTask_Background_VAR_FAST_END;
__OS_OsTask_Background_VAR_FAST_LIMIT = _OS_OsTask_Background_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE_NOINIT )
.OS_OsTask_Background_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_Background_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_Background_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_Background_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_Background_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_Background_VAR_FAST_NOINIT_START = _OS_OsTask_Background_VAR_FAST_NOINIT_START;
__OS_OsTask_Background_VAR_FAST_NOINIT_END = _OS_OsTask_Background_VAR_FAST_NOINIT_END;
__OS_OsTask_Background_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_Background_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_Background_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Background_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Background_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_Background_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Background_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_Background_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_Background_VAR_FAST_ZERO_INIT_START = _OS_OsTask_Background_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_Background_VAR_FAST_ZERO_INIT_END = _OS_OsTask_Background_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_Background_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_Background_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE_INIT )
.OS_OsTask_Background_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_Background_VAR_NOCACHE_START = ADDR(.OS_OsTask_Background_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_Background_VAR_NOCACHE_END = . - 1;
_OS_OsTask_Background_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_Background_VAR_NOCACHE_START = _OS_OsTask_Background_VAR_NOCACHE_START;
__OS_OsTask_Background_VAR_NOCACHE_END = _OS_OsTask_Background_VAR_NOCACHE_END;
__OS_OsTask_Background_VAR_NOCACHE_LIMIT = _OS_OsTask_Background_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE_NOINIT )
.OS_OsTask_Background_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Background_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Background_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_Background_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_Background_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_Background_VAR_NOCACHE_NOINIT_START = _OS_OsTask_Background_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_Background_VAR_NOCACHE_NOINIT_END = _OS_OsTask_Background_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_Background_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_Background_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_Background_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE_INIT )
.OS_OsTask_Background_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_Background_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_Background_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_Background_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_Background_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_Background_VAR_FAST_NOCACHE_START = _OS_OsTask_Background_VAR_FAST_NOCACHE_START;
__OS_OsTask_Background_VAR_FAST_NOCACHE_END = _OS_OsTask_Background_VAR_FAST_NOCACHE_END;
__OS_OsTask_Background_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_Background_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE_NOINIT )
.OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_Background_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_Background_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND
. = ALIGN(4);
_OS_OsTask_Background_VAR_ALL_END = . - 1;
__OS_OsTask_Background_VAR_ALL_END = . - 1;
_OS_OsTask_Background_VAR_ALL_LIMIT = .;
__OS_OsTask_Background_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BACKGROUND_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_ALL_START = .;
__OS_OsTask_BswMainFunctions_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE_INIT )
.OS_OsTask_BswMainFunctions_VAR ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_VAR_START = ADDR(.OS_OsTask_BswMainFunctions_VAR);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_START = _OS_OsTask_BswMainFunctions_VAR_START;
__OS_OsTask_BswMainFunctions_VAR_END = _OS_OsTask_BswMainFunctions_VAR_END;
__OS_OsTask_BswMainFunctions_VAR_LIMIT = _OS_OsTask_BswMainFunctions_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE_NOINIT )
.OS_OsTask_BswMainFunctions_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_VAR_NOINIT_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_NOINIT_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_NOINIT_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_NOINIT_START = _OS_OsTask_BswMainFunctions_VAR_NOINIT_START;
__OS_OsTask_BswMainFunctions_VAR_NOINIT_END = _OS_OsTask_BswMainFunctions_VAR_NOINIT_END;
__OS_OsTask_BswMainFunctions_VAR_NOINIT_LIMIT = _OS_OsTask_BswMainFunctions_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE_ZERO_INIT )
.OS_OsTask_BswMainFunctions_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_START = _OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_START;
__OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_END = _OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_END;
__OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_LIMIT = _OS_OsTask_BswMainFunctions_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE_INIT )
.OS_OsTask_BswMainFunctions_VAR_FAST ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_VAR_FAST_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_FAST_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_FAST_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_FAST_START = _OS_OsTask_BswMainFunctions_VAR_FAST_START;
__OS_OsTask_BswMainFunctions_VAR_FAST_END = _OS_OsTask_BswMainFunctions_VAR_FAST_END;
__OS_OsTask_BswMainFunctions_VAR_FAST_LIMIT = _OS_OsTask_BswMainFunctions_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE_NOINIT )
.OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_START = _OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_START;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_END = _OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_END;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_BswMainFunctions_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_START = _OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_END = _OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_BswMainFunctions_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE_INIT )
.OS_OsTask_BswMainFunctions_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_VAR_NOCACHE_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_NOCACHE_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_NOCACHE_START = _OS_OsTask_BswMainFunctions_VAR_NOCACHE_START;
__OS_OsTask_BswMainFunctions_VAR_NOCACHE_END = _OS_OsTask_BswMainFunctions_VAR_NOCACHE_END;
__OS_OsTask_BswMainFunctions_VAR_NOCACHE_LIMIT = _OS_OsTask_BswMainFunctions_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE_NOINIT )
.OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT_START = _OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT_END = _OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_BswMainFunctions_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_BswMainFunctions_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE_INIT )
.OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_START = _OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_START;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_END = _OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_END;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE_NOINIT )
.OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_BswMainFunctions_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS
. = ALIGN(4);
_OS_OsTask_BswMainFunctions_VAR_ALL_END = . - 1;
__OS_OsTask_BswMainFunctions_VAR_ALL_END = . - 1;
_OS_OsTask_BswMainFunctions_VAR_ALL_LIMIT = .;
__OS_OsTask_BswMainFunctions_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_BSWMAINFUNCTIONS_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION
. = ALIGN(4);
_OS_OsTask_Communication_VAR_ALL_START = .;
__OS_OsTask_Communication_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE_INIT )
.OS_OsTask_Communication_VAR ALIGN(4) :> .
_OS_OsTask_Communication_VAR_START = ADDR(.OS_OsTask_Communication_VAR);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_END = . - 1;
_OS_OsTask_Communication_VAR_LIMIT = .;
__OS_OsTask_Communication_VAR_START = _OS_OsTask_Communication_VAR_START;
__OS_OsTask_Communication_VAR_END = _OS_OsTask_Communication_VAR_END;
__OS_OsTask_Communication_VAR_LIMIT = _OS_OsTask_Communication_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE_NOINIT )
.OS_OsTask_Communication_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_Communication_VAR_NOINIT_START = ADDR(.OS_OsTask_Communication_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_NOINIT_END = . - 1;
_OS_OsTask_Communication_VAR_NOINIT_LIMIT = .;
__OS_OsTask_Communication_VAR_NOINIT_START = _OS_OsTask_Communication_VAR_NOINIT_START;
__OS_OsTask_Communication_VAR_NOINIT_END = _OS_OsTask_Communication_VAR_NOINIT_END;
__OS_OsTask_Communication_VAR_NOINIT_LIMIT = _OS_OsTask_Communication_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE_ZERO_INIT )
.OS_OsTask_Communication_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Communication_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Communication_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_Communication_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_Communication_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_Communication_VAR_ZERO_INIT_START = _OS_OsTask_Communication_VAR_ZERO_INIT_START;
__OS_OsTask_Communication_VAR_ZERO_INIT_END = _OS_OsTask_Communication_VAR_ZERO_INIT_END;
__OS_OsTask_Communication_VAR_ZERO_INIT_LIMIT = _OS_OsTask_Communication_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE_INIT )
.OS_OsTask_Communication_VAR_FAST ALIGN(4) :> .
_OS_OsTask_Communication_VAR_FAST_START = ADDR(.OS_OsTask_Communication_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_FAST_END = . - 1;
_OS_OsTask_Communication_VAR_FAST_LIMIT = .;
__OS_OsTask_Communication_VAR_FAST_START = _OS_OsTask_Communication_VAR_FAST_START;
__OS_OsTask_Communication_VAR_FAST_END = _OS_OsTask_Communication_VAR_FAST_END;
__OS_OsTask_Communication_VAR_FAST_LIMIT = _OS_OsTask_Communication_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE_NOINIT )
.OS_OsTask_Communication_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_Communication_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_Communication_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_Communication_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_Communication_VAR_FAST_NOINIT_START = _OS_OsTask_Communication_VAR_FAST_NOINIT_START;
__OS_OsTask_Communication_VAR_FAST_NOINIT_END = _OS_OsTask_Communication_VAR_FAST_NOINIT_END;
__OS_OsTask_Communication_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_Communication_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_Communication_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Communication_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_Communication_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_Communication_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_Communication_VAR_FAST_ZERO_INIT_START = _OS_OsTask_Communication_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_Communication_VAR_FAST_ZERO_INIT_END = _OS_OsTask_Communication_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_Communication_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_Communication_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE_INIT )
.OS_OsTask_Communication_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_Communication_VAR_NOCACHE_START = ADDR(.OS_OsTask_Communication_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_NOCACHE_END = . - 1;
_OS_OsTask_Communication_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_Communication_VAR_NOCACHE_START = _OS_OsTask_Communication_VAR_NOCACHE_START;
__OS_OsTask_Communication_VAR_NOCACHE_END = _OS_OsTask_Communication_VAR_NOCACHE_END;
__OS_OsTask_Communication_VAR_NOCACHE_LIMIT = _OS_OsTask_Communication_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE_NOINIT )
.OS_OsTask_Communication_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Communication_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Communication_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_Communication_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_Communication_VAR_NOCACHE_NOINIT_START = _OS_OsTask_Communication_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_Communication_VAR_NOCACHE_NOINIT_END = _OS_OsTask_Communication_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_Communication_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_Communication_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_Communication_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE_INIT )
.OS_OsTask_Communication_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_Communication_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_Communication_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_Communication_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_Communication_VAR_FAST_NOCACHE_START = _OS_OsTask_Communication_VAR_FAST_NOCACHE_START;
__OS_OsTask_Communication_VAR_FAST_NOCACHE_END = _OS_OsTask_Communication_VAR_FAST_NOCACHE_END;
__OS_OsTask_Communication_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_Communication_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE_NOINIT )
.OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_Communication_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_Communication_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION
. = ALIGN(4);
_OS_OsTask_Communication_VAR_ALL_END = . - 1;
__OS_OsTask_Communication_VAR_ALL_END = . - 1;
_OS_OsTask_Communication_VAR_ALL_LIMIT = .;
__OS_OsTask_Communication_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_COMMUNICATION_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_ALL_START = .;
__OS_OsTask_DcmSessionChanges_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE_INIT )
.OS_OsTask_DcmSessionChanges_VAR ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_VAR_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_START = _OS_OsTask_DcmSessionChanges_VAR_START;
__OS_OsTask_DcmSessionChanges_VAR_END = _OS_OsTask_DcmSessionChanges_VAR_END;
__OS_OsTask_DcmSessionChanges_VAR_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE_NOINIT )
.OS_OsTask_DcmSessionChanges_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_VAR_NOINIT_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_NOINIT_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_NOINIT_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_NOINIT_START = _OS_OsTask_DcmSessionChanges_VAR_NOINIT_START;
__OS_OsTask_DcmSessionChanges_VAR_NOINIT_END = _OS_OsTask_DcmSessionChanges_VAR_NOINIT_END;
__OS_OsTask_DcmSessionChanges_VAR_NOINIT_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE_ZERO_INIT )
.OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_START = _OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_START;
__OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_END = _OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_END;
__OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE_INIT )
.OS_OsTask_DcmSessionChanges_VAR_FAST ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_VAR_FAST_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_FAST_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_FAST_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_FAST_START = _OS_OsTask_DcmSessionChanges_VAR_FAST_START;
__OS_OsTask_DcmSessionChanges_VAR_FAST_END = _OS_OsTask_DcmSessionChanges_VAR_FAST_END;
__OS_OsTask_DcmSessionChanges_VAR_FAST_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE_NOINIT )
.OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_START = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_START;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_END = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_END;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_START = _OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_END = _OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE_INIT )
.OS_OsTask_DcmSessionChanges_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_VAR_NOCACHE_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_NOCACHE_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_NOCACHE_START = _OS_OsTask_DcmSessionChanges_VAR_NOCACHE_START;
__OS_OsTask_DcmSessionChanges_VAR_NOCACHE_END = _OS_OsTask_DcmSessionChanges_VAR_NOCACHE_END;
__OS_OsTask_DcmSessionChanges_VAR_NOCACHE_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE_NOINIT )
.OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT_START = _OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT_END = _OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE_INIT )
.OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_START = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_START;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_END = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_END;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE_NOINIT )
.OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_DcmSessionChanges_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES
. = ALIGN(4);
_OS_OsTask_DcmSessionChanges_VAR_ALL_END = . - 1;
__OS_OsTask_DcmSessionChanges_VAR_ALL_END = . - 1;
_OS_OsTask_DcmSessionChanges_VAR_ALL_LIMIT = .;
__OS_OsTask_DcmSessionChanges_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DCMSESSIONCHANGES_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_ALL_START = .;
__OS_OsTask_Dimming_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE_INIT )
.OS_OsTask_Dimming_VAR ALIGN(4) :> .
_OS_OsTask_Dimming_VAR_START = ADDR(.OS_OsTask_Dimming_VAR);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_END = . - 1;
_OS_OsTask_Dimming_VAR_LIMIT = .;
__OS_OsTask_Dimming_VAR_START = _OS_OsTask_Dimming_VAR_START;
__OS_OsTask_Dimming_VAR_END = _OS_OsTask_Dimming_VAR_END;
__OS_OsTask_Dimming_VAR_LIMIT = _OS_OsTask_Dimming_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE_NOINIT )
.OS_OsTask_Dimming_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_Dimming_VAR_NOINIT_START = ADDR(.OS_OsTask_Dimming_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_NOINIT_END = . - 1;
_OS_OsTask_Dimming_VAR_NOINIT_LIMIT = .;
__OS_OsTask_Dimming_VAR_NOINIT_START = _OS_OsTask_Dimming_VAR_NOINIT_START;
__OS_OsTask_Dimming_VAR_NOINIT_END = _OS_OsTask_Dimming_VAR_NOINIT_END;
__OS_OsTask_Dimming_VAR_NOINIT_LIMIT = _OS_OsTask_Dimming_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE_ZERO_INIT )
.OS_OsTask_Dimming_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Dimming_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Dimming_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_Dimming_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_Dimming_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_Dimming_VAR_ZERO_INIT_START = _OS_OsTask_Dimming_VAR_ZERO_INIT_START;
__OS_OsTask_Dimming_VAR_ZERO_INIT_END = _OS_OsTask_Dimming_VAR_ZERO_INIT_END;
__OS_OsTask_Dimming_VAR_ZERO_INIT_LIMIT = _OS_OsTask_Dimming_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE_INIT )
.OS_OsTask_Dimming_VAR_FAST ALIGN(4) :> .
_OS_OsTask_Dimming_VAR_FAST_START = ADDR(.OS_OsTask_Dimming_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_FAST_END = . - 1;
_OS_OsTask_Dimming_VAR_FAST_LIMIT = .;
__OS_OsTask_Dimming_VAR_FAST_START = _OS_OsTask_Dimming_VAR_FAST_START;
__OS_OsTask_Dimming_VAR_FAST_END = _OS_OsTask_Dimming_VAR_FAST_END;
__OS_OsTask_Dimming_VAR_FAST_LIMIT = _OS_OsTask_Dimming_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE_NOINIT )
.OS_OsTask_Dimming_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_Dimming_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_Dimming_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_Dimming_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_Dimming_VAR_FAST_NOINIT_START = _OS_OsTask_Dimming_VAR_FAST_NOINIT_START;
__OS_OsTask_Dimming_VAR_FAST_NOINIT_END = _OS_OsTask_Dimming_VAR_FAST_NOINIT_END;
__OS_OsTask_Dimming_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_Dimming_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_Dimming_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_Dimming_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_START = _OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_END = _OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_Dimming_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE_INIT )
.OS_OsTask_Dimming_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_Dimming_VAR_NOCACHE_START = ADDR(.OS_OsTask_Dimming_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_NOCACHE_END = . - 1;
_OS_OsTask_Dimming_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_Dimming_VAR_NOCACHE_START = _OS_OsTask_Dimming_VAR_NOCACHE_START;
__OS_OsTask_Dimming_VAR_NOCACHE_END = _OS_OsTask_Dimming_VAR_NOCACHE_END;
__OS_OsTask_Dimming_VAR_NOCACHE_LIMIT = _OS_OsTask_Dimming_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE_NOINIT )
.OS_OsTask_Dimming_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Dimming_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Dimming_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_Dimming_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_Dimming_VAR_NOCACHE_NOINIT_START = _OS_OsTask_Dimming_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_Dimming_VAR_NOCACHE_NOINIT_END = _OS_OsTask_Dimming_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_Dimming_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_Dimming_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_Dimming_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE_INIT )
.OS_OsTask_Dimming_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_Dimming_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_Dimming_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_Dimming_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_Dimming_VAR_FAST_NOCACHE_START = _OS_OsTask_Dimming_VAR_FAST_NOCACHE_START;
__OS_OsTask_Dimming_VAR_FAST_NOCACHE_END = _OS_OsTask_Dimming_VAR_FAST_NOCACHE_END;
__OS_OsTask_Dimming_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_Dimming_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE_NOINIT )
.OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_Dimming_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_Dimming_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING
. = ALIGN(4);
_OS_OsTask_Dimming_VAR_ALL_END = . - 1;
__OS_OsTask_Dimming_VAR_ALL_END = . - 1;
_OS_OsTask_Dimming_VAR_ALL_LIMIT = .;
__OS_OsTask_Dimming_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_DIMMING_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_ALL_START = .;
__OS_OsTask_NvmAccess_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE_INIT )
.OS_OsTask_NvmAccess_VAR ALIGN(4) :> .
_OS_OsTask_NvmAccess_VAR_START = ADDR(.OS_OsTask_NvmAccess_VAR);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_END = . - 1;
_OS_OsTask_NvmAccess_VAR_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_START = _OS_OsTask_NvmAccess_VAR_START;
__OS_OsTask_NvmAccess_VAR_END = _OS_OsTask_NvmAccess_VAR_END;
__OS_OsTask_NvmAccess_VAR_LIMIT = _OS_OsTask_NvmAccess_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE_NOINIT )
.OS_OsTask_NvmAccess_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_NvmAccess_VAR_NOINIT_START = ADDR(.OS_OsTask_NvmAccess_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_NOINIT_END = . - 1;
_OS_OsTask_NvmAccess_VAR_NOINIT_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_NOINIT_START = _OS_OsTask_NvmAccess_VAR_NOINIT_START;
__OS_OsTask_NvmAccess_VAR_NOINIT_END = _OS_OsTask_NvmAccess_VAR_NOINIT_END;
__OS_OsTask_NvmAccess_VAR_NOINIT_LIMIT = _OS_OsTask_NvmAccess_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE_ZERO_INIT )
.OS_OsTask_NvmAccess_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_NvmAccess_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_NvmAccess_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_NvmAccess_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_NvmAccess_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_ZERO_INIT_START = _OS_OsTask_NvmAccess_VAR_ZERO_INIT_START;
__OS_OsTask_NvmAccess_VAR_ZERO_INIT_END = _OS_OsTask_NvmAccess_VAR_ZERO_INIT_END;
__OS_OsTask_NvmAccess_VAR_ZERO_INIT_LIMIT = _OS_OsTask_NvmAccess_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE_INIT )
.OS_OsTask_NvmAccess_VAR_FAST ALIGN(4) :> .
_OS_OsTask_NvmAccess_VAR_FAST_START = ADDR(.OS_OsTask_NvmAccess_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_FAST_END = . - 1;
_OS_OsTask_NvmAccess_VAR_FAST_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_FAST_START = _OS_OsTask_NvmAccess_VAR_FAST_START;
__OS_OsTask_NvmAccess_VAR_FAST_END = _OS_OsTask_NvmAccess_VAR_FAST_END;
__OS_OsTask_NvmAccess_VAR_FAST_LIMIT = _OS_OsTask_NvmAccess_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE_NOINIT )
.OS_OsTask_NvmAccess_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_NvmAccess_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_NvmAccess_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_FAST_NOINIT_START = _OS_OsTask_NvmAccess_VAR_FAST_NOINIT_START;
__OS_OsTask_NvmAccess_VAR_FAST_NOINIT_END = _OS_OsTask_NvmAccess_VAR_FAST_NOINIT_END;
__OS_OsTask_NvmAccess_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_NvmAccess_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_START = _OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_END = _OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_NvmAccess_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE_INIT )
.OS_OsTask_NvmAccess_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_NvmAccess_VAR_NOCACHE_START = ADDR(.OS_OsTask_NvmAccess_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_NOCACHE_END = . - 1;
_OS_OsTask_NvmAccess_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_NOCACHE_START = _OS_OsTask_NvmAccess_VAR_NOCACHE_START;
__OS_OsTask_NvmAccess_VAR_NOCACHE_END = _OS_OsTask_NvmAccess_VAR_NOCACHE_END;
__OS_OsTask_NvmAccess_VAR_NOCACHE_LIMIT = _OS_OsTask_NvmAccess_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE_NOINIT )
.OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT_START = _OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT_END = _OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_NvmAccess_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_NvmAccess_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE_INIT )
.OS_OsTask_NvmAccess_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_NvmAccess_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_START = _OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_START;
__OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_END = _OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_END;
__OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE_NOINIT )
.OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_NvmAccess_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS
. = ALIGN(4);
_OS_OsTask_NvmAccess_VAR_ALL_END = . - 1;
__OS_OsTask_NvmAccess_VAR_ALL_END = . - 1;
_OS_OsTask_NvmAccess_VAR_ALL_LIMIT = .;
__OS_OsTask_NvmAccess_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_NVMACCESS_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_ALL_START = .;
__OS_OsTask_SelfDiagnostics_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE_INIT )
.OS_OsTask_SelfDiagnostics_VAR ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_VAR_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_START = _OS_OsTask_SelfDiagnostics_VAR_START;
__OS_OsTask_SelfDiagnostics_VAR_END = _OS_OsTask_SelfDiagnostics_VAR_END;
__OS_OsTask_SelfDiagnostics_VAR_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE_NOINIT )
.OS_OsTask_SelfDiagnostics_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_VAR_NOINIT_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_NOINIT_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_NOINIT_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_NOINIT_START = _OS_OsTask_SelfDiagnostics_VAR_NOINIT_START;
__OS_OsTask_SelfDiagnostics_VAR_NOINIT_END = _OS_OsTask_SelfDiagnostics_VAR_NOINIT_END;
__OS_OsTask_SelfDiagnostics_VAR_NOINIT_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE_ZERO_INIT )
.OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_START = _OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_START;
__OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_END = _OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_END;
__OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE_INIT )
.OS_OsTask_SelfDiagnostics_VAR_FAST ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_VAR_FAST_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_FAST_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_FAST_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_FAST_START = _OS_OsTask_SelfDiagnostics_VAR_FAST_START;
__OS_OsTask_SelfDiagnostics_VAR_FAST_END = _OS_OsTask_SelfDiagnostics_VAR_FAST_END;
__OS_OsTask_SelfDiagnostics_VAR_FAST_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE_NOINIT )
.OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_START = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_START;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_END = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_END;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_START = _OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_END = _OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE_INIT )
.OS_OsTask_SelfDiagnostics_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_VAR_NOCACHE_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_NOCACHE_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_NOCACHE_START = _OS_OsTask_SelfDiagnostics_VAR_NOCACHE_START;
__OS_OsTask_SelfDiagnostics_VAR_NOCACHE_END = _OS_OsTask_SelfDiagnostics_VAR_NOCACHE_END;
__OS_OsTask_SelfDiagnostics_VAR_NOCACHE_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE_NOINIT )
.OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT_START = _OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT_END = _OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE_INIT )
.OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_START = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_START;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_END = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_END;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE_NOINIT )
.OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_SelfDiagnostics_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS
. = ALIGN(4);
_OS_OsTask_SelfDiagnostics_VAR_ALL_END = . - 1;
__OS_OsTask_SelfDiagnostics_VAR_ALL_END = . - 1;
_OS_OsTask_SelfDiagnostics_VAR_ALL_LIMIT = .;
__OS_OsTask_SelfDiagnostics_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_SELFDIAGNOSTICS_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH
. = ALIGN(4);
_OS_OsTask_Touch_VAR_ALL_START = .;
__OS_OsTask_Touch_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE_INIT )
.OS_OsTask_Touch_VAR ALIGN(4) :> .
_OS_OsTask_Touch_VAR_START = ADDR(.OS_OsTask_Touch_VAR);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_END = . - 1;
_OS_OsTask_Touch_VAR_LIMIT = .;
__OS_OsTask_Touch_VAR_START = _OS_OsTask_Touch_VAR_START;
__OS_OsTask_Touch_VAR_END = _OS_OsTask_Touch_VAR_END;
__OS_OsTask_Touch_VAR_LIMIT = _OS_OsTask_Touch_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE_NOINIT )
.OS_OsTask_Touch_VAR_NOINIT ALIGN(4) :> .
_OS_OsTask_Touch_VAR_NOINIT_START = ADDR(.OS_OsTask_Touch_VAR_NOINIT);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_NOINIT_END = . - 1;
_OS_OsTask_Touch_VAR_NOINIT_LIMIT = .;
__OS_OsTask_Touch_VAR_NOINIT_START = _OS_OsTask_Touch_VAR_NOINIT_START;
__OS_OsTask_Touch_VAR_NOINIT_END = _OS_OsTask_Touch_VAR_NOINIT_END;
__OS_OsTask_Touch_VAR_NOINIT_LIMIT = _OS_OsTask_Touch_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE_ZERO_INIT )
.OS_OsTask_Touch_VAR_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Touch_VAR_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Touch_VAR_ZERO_INIT_START = ADDR(.OS_OsTask_Touch_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_ZERO_INIT_END = . - 1;
_OS_OsTask_Touch_VAR_ZERO_INIT_LIMIT = .;
__OS_OsTask_Touch_VAR_ZERO_INIT_START = _OS_OsTask_Touch_VAR_ZERO_INIT_START;
__OS_OsTask_Touch_VAR_ZERO_INIT_END = _OS_OsTask_Touch_VAR_ZERO_INIT_END;
__OS_OsTask_Touch_VAR_ZERO_INIT_LIMIT = _OS_OsTask_Touch_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE_INIT )
.OS_OsTask_Touch_VAR_FAST ALIGN(4) :> .
_OS_OsTask_Touch_VAR_FAST_START = ADDR(.OS_OsTask_Touch_VAR_FAST);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_FAST_END = . - 1;
_OS_OsTask_Touch_VAR_FAST_LIMIT = .;
__OS_OsTask_Touch_VAR_FAST_START = _OS_OsTask_Touch_VAR_FAST_START;
__OS_OsTask_Touch_VAR_FAST_END = _OS_OsTask_Touch_VAR_FAST_END;
__OS_OsTask_Touch_VAR_FAST_LIMIT = _OS_OsTask_Touch_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE_NOINIT )
.OS_OsTask_Touch_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_OsTask_Touch_VAR_FAST_NOINIT_START = ADDR(.OS_OsTask_Touch_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_FAST_NOINIT_END = . - 1;
_OS_OsTask_Touch_VAR_FAST_NOINIT_LIMIT = .;
__OS_OsTask_Touch_VAR_FAST_NOINIT_START = _OS_OsTask_Touch_VAR_FAST_NOINIT_START;
__OS_OsTask_Touch_VAR_FAST_NOINIT_END = _OS_OsTask_Touch_VAR_FAST_NOINIT_END;
__OS_OsTask_Touch_VAR_FAST_NOINIT_LIMIT = _OS_OsTask_Touch_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE_ZERO_INIT )
.OS_OsTask_Touch_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Touch_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_START = ADDR(.OS_OsTask_Touch_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_OsTask_Touch_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_OsTask_Touch_VAR_FAST_ZERO_INIT_START = _OS_OsTask_Touch_VAR_FAST_ZERO_INIT_START;
__OS_OsTask_Touch_VAR_FAST_ZERO_INIT_END = _OS_OsTask_Touch_VAR_FAST_ZERO_INIT_END;
__OS_OsTask_Touch_VAR_FAST_ZERO_INIT_LIMIT = _OS_OsTask_Touch_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE_INIT )
.OS_OsTask_Touch_VAR_NOCACHE ALIGN(4) :> .
_OS_OsTask_Touch_VAR_NOCACHE_START = ADDR(.OS_OsTask_Touch_VAR_NOCACHE);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_NOCACHE_END = . - 1;
_OS_OsTask_Touch_VAR_NOCACHE_LIMIT = .;
__OS_OsTask_Touch_VAR_NOCACHE_START = _OS_OsTask_Touch_VAR_NOCACHE_START;
__OS_OsTask_Touch_VAR_NOCACHE_END = _OS_OsTask_Touch_VAR_NOCACHE_END;
__OS_OsTask_Touch_VAR_NOCACHE_LIMIT = _OS_OsTask_Touch_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE_NOINIT )
.OS_OsTask_Touch_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Touch_VAR_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Touch_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_Touch_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_Touch_VAR_NOCACHE_NOINIT_START = _OS_OsTask_Touch_VAR_NOCACHE_NOINIT_START;
__OS_OsTask_Touch_VAR_NOCACHE_NOINIT_END = _OS_OsTask_Touch_VAR_NOCACHE_NOINIT_END;
__OS_OsTask_Touch_VAR_NOCACHE_NOINIT_LIMIT = _OS_OsTask_Touch_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_START = _OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_START;
__OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_END = _OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_END;
__OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_Touch_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE_INIT )
.OS_OsTask_Touch_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_OsTask_Touch_VAR_FAST_NOCACHE_START = ADDR(.OS_OsTask_Touch_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_FAST_NOCACHE_END = . - 1;
_OS_OsTask_Touch_VAR_FAST_NOCACHE_LIMIT = .;
__OS_OsTask_Touch_VAR_FAST_NOCACHE_START = _OS_OsTask_Touch_VAR_FAST_NOCACHE_START;
__OS_OsTask_Touch_VAR_FAST_NOCACHE_END = _OS_OsTask_Touch_VAR_FAST_NOCACHE_END;
__OS_OsTask_Touch_VAR_FAST_NOCACHE_LIMIT = _OS_OsTask_Touch_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE_NOINIT )
.OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT_START = _OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT_START;
__OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT_END = _OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT_END;
__OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_OsTask_Touch_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE_ZERO_INIT )
.OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_OsTask_Touch_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH
. = ALIGN(4);
_OS_OsTask_Touch_VAR_ALL_END = . - 1;
__OS_OsTask_Touch_VAR_ALL_END = . - 1;
_OS_OsTask_Touch_VAR_ALL_LIMIT = .;
__OS_OsTask_Touch_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_OSTASK_TOUCH_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_ALL_START = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE_INIT )
.OS_ADC0_SG1_CAT2_ISR_VAR ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_START = _OS_ADC0_SG1_CAT2_ISR_VAR_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_END = _OS_ADC0_SG1_CAT2_ISR_VAR_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_START = _OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_END = _OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_START = _OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_END = _OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE_INIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_START = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_END = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_START = _OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_END = _OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_ADC0_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR
. = ALIGN(4);
_OS_ADC0_SG1_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_ADC0_SG1_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_ADC0_SG1_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_ADC0_SG1_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC0_SG1_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_ALL_START = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE_INIT )
.OS_ADC1_SG1_CAT2_ISR_VAR ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_START = _OS_ADC1_SG1_CAT2_ISR_VAR_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_END = _OS_ADC1_SG1_CAT2_ISR_VAR_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_START = _OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_END = _OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_START = _OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_END = _OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE_INIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_START = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_END = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_START = _OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_END = _OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_ADC1_SG1_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR
. = ALIGN(4);
_OS_ADC1_SG1_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_ADC1_SG1_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_ADC1_SG1_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_ADC1_SG1_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC1_SG1_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_ALL_START = .;
__OS_CanIsrGlobalRxFifo_0_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE_INIT )
.OS_CanIsrGlobalRxFifo_0_VAR ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_VAR_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_START = _OS_CanIsrGlobalRxFifo_0_VAR_START;
__OS_CanIsrGlobalRxFifo_0_VAR_END = _OS_CanIsrGlobalRxFifo_0_VAR_END;
__OS_CanIsrGlobalRxFifo_0_VAR_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE_NOINIT )
.OS_CanIsrGlobalRxFifo_0_VAR_NOINIT ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_NOINIT);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_START = _OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_START;
__OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_END = _OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_END;
__OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE_ZERO_INIT )
.OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_START = _OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_START;
__OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_END = _OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_END;
__OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE_INIT )
.OS_CanIsrGlobalRxFifo_0_VAR_FAST ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_FAST);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_START = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_START;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_END = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_END;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE_NOINIT )
.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_START = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_START;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_END = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_END;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE_ZERO_INIT )
.OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_START = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_START;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_END = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_END;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE_INIT )
.OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_START = _OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_START;
__OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_END = _OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_END;
__OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE_NOINIT )
.OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT_START = _OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT_START;
__OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT_END = _OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT_END;
__OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE_ZERO_INIT )
.OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_START = _OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_START;
__OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_END = _OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_END;
__OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE_INIT )
.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_START = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_START;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_END = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_END;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE_NOINIT )
.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT_START = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT_START;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT_END = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT_END;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0 ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE_ZERO_INIT )
.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_CanIsrGlobalRxFifo_0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0
. = ALIGN(4);
_OS_CanIsrGlobalRxFifo_0_VAR_ALL_END = . - 1;
__OS_CanIsrGlobalRxFifo_0_VAR_ALL_END = . - 1;
_OS_CanIsrGlobalRxFifo_0_VAR_ALL_LIMIT = .;
__OS_CanIsrGlobalRxFifo_0_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRGLOBALRXFIFO_0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_ALL_START = .;
__OS_CanIsrStatus_0_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE_INIT )
.OS_CanIsrStatus_0_VAR ALIGN(4) :> .
_OS_CanIsrStatus_0_VAR_START = ADDR(.OS_CanIsrStatus_0_VAR);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_END = . - 1;
_OS_CanIsrStatus_0_VAR_LIMIT = .;
__OS_CanIsrStatus_0_VAR_START = _OS_CanIsrStatus_0_VAR_START;
__OS_CanIsrStatus_0_VAR_END = _OS_CanIsrStatus_0_VAR_END;
__OS_CanIsrStatus_0_VAR_LIMIT = _OS_CanIsrStatus_0_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE_NOINIT )
.OS_CanIsrStatus_0_VAR_NOINIT ALIGN(4) :> .
_OS_CanIsrStatus_0_VAR_NOINIT_START = ADDR(.OS_CanIsrStatus_0_VAR_NOINIT);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_NOINIT_END = . - 1;
_OS_CanIsrStatus_0_VAR_NOINIT_LIMIT = .;
__OS_CanIsrStatus_0_VAR_NOINIT_START = _OS_CanIsrStatus_0_VAR_NOINIT_START;
__OS_CanIsrStatus_0_VAR_NOINIT_END = _OS_CanIsrStatus_0_VAR_NOINIT_END;
__OS_CanIsrStatus_0_VAR_NOINIT_LIMIT = _OS_CanIsrStatus_0_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE_ZERO_INIT )
.OS_CanIsrStatus_0_VAR_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrStatus_0_VAR_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrStatus_0_VAR_ZERO_INIT_START = ADDR(.OS_CanIsrStatus_0_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_ZERO_INIT_END = . - 1;
_OS_CanIsrStatus_0_VAR_ZERO_INIT_LIMIT = .;
__OS_CanIsrStatus_0_VAR_ZERO_INIT_START = _OS_CanIsrStatus_0_VAR_ZERO_INIT_START;
__OS_CanIsrStatus_0_VAR_ZERO_INIT_END = _OS_CanIsrStatus_0_VAR_ZERO_INIT_END;
__OS_CanIsrStatus_0_VAR_ZERO_INIT_LIMIT = _OS_CanIsrStatus_0_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE_INIT )
.OS_CanIsrStatus_0_VAR_FAST ALIGN(4) :> .
_OS_CanIsrStatus_0_VAR_FAST_START = ADDR(.OS_CanIsrStatus_0_VAR_FAST);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_FAST_END = . - 1;
_OS_CanIsrStatus_0_VAR_FAST_LIMIT = .;
__OS_CanIsrStatus_0_VAR_FAST_START = _OS_CanIsrStatus_0_VAR_FAST_START;
__OS_CanIsrStatus_0_VAR_FAST_END = _OS_CanIsrStatus_0_VAR_FAST_END;
__OS_CanIsrStatus_0_VAR_FAST_LIMIT = _OS_CanIsrStatus_0_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE_NOINIT )
.OS_CanIsrStatus_0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CanIsrStatus_0_VAR_FAST_NOINIT_START = ADDR(.OS_CanIsrStatus_0_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_FAST_NOINIT_END = . - 1;
_OS_CanIsrStatus_0_VAR_FAST_NOINIT_LIMIT = .;
__OS_CanIsrStatus_0_VAR_FAST_NOINIT_START = _OS_CanIsrStatus_0_VAR_FAST_NOINIT_START;
__OS_CanIsrStatus_0_VAR_FAST_NOINIT_END = _OS_CanIsrStatus_0_VAR_FAST_NOINIT_END;
__OS_CanIsrStatus_0_VAR_FAST_NOINIT_LIMIT = _OS_CanIsrStatus_0_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE_ZERO_INIT )
.OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_START = ADDR(.OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_START = _OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_START;
__OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_END = _OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_END;
__OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_LIMIT = _OS_CanIsrStatus_0_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE_INIT )
.OS_CanIsrStatus_0_VAR_NOCACHE ALIGN(4) :> .
_OS_CanIsrStatus_0_VAR_NOCACHE_START = ADDR(.OS_CanIsrStatus_0_VAR_NOCACHE);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_NOCACHE_END = . - 1;
_OS_CanIsrStatus_0_VAR_NOCACHE_LIMIT = .;
__OS_CanIsrStatus_0_VAR_NOCACHE_START = _OS_CanIsrStatus_0_VAR_NOCACHE_START;
__OS_CanIsrStatus_0_VAR_NOCACHE_END = _OS_CanIsrStatus_0_VAR_NOCACHE_END;
__OS_CanIsrStatus_0_VAR_NOCACHE_LIMIT = _OS_CanIsrStatus_0_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE_NOINIT )
.OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT_START = _OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT_START;
__OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT_END = _OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT_END;
__OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT_LIMIT = _OS_CanIsrStatus_0_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE_ZERO_INIT )
.OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_START = _OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_START;
__OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_END = _OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_END;
__OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_CanIsrStatus_0_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE_INIT )
.OS_CanIsrStatus_0_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CanIsrStatus_0_VAR_FAST_NOCACHE_START = ADDR(.OS_CanIsrStatus_0_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_FAST_NOCACHE_END = . - 1;
_OS_CanIsrStatus_0_VAR_FAST_NOCACHE_LIMIT = .;
__OS_CanIsrStatus_0_VAR_FAST_NOCACHE_START = _OS_CanIsrStatus_0_VAR_FAST_NOCACHE_START;
__OS_CanIsrStatus_0_VAR_FAST_NOCACHE_END = _OS_CanIsrStatus_0_VAR_FAST_NOCACHE_END;
__OS_CanIsrStatus_0_VAR_FAST_NOCACHE_LIMIT = _OS_CanIsrStatus_0_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE_NOINIT )
.OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT_START = _OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT_START;
__OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT_END = _OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT_END;
__OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_CanIsrStatus_0_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0 ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE_ZERO_INIT )
.OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_CanIsrStatus_0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0
. = ALIGN(4);
_OS_CanIsrStatus_0_VAR_ALL_END = . - 1;
__OS_CanIsrStatus_0_VAR_ALL_END = . - 1;
_OS_CanIsrStatus_0_VAR_ALL_LIMIT = .;
__OS_CanIsrStatus_0_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRSTATUS_0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISRTX_0
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_ALL_START = .;
__OS_CanIsrTx_0_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE_INIT )
.OS_CanIsrTx_0_VAR ALIGN(4) :> .
_OS_CanIsrTx_0_VAR_START = ADDR(.OS_CanIsrTx_0_VAR);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_END = . - 1;
_OS_CanIsrTx_0_VAR_LIMIT = .;
__OS_CanIsrTx_0_VAR_START = _OS_CanIsrTx_0_VAR_START;
__OS_CanIsrTx_0_VAR_END = _OS_CanIsrTx_0_VAR_END;
__OS_CanIsrTx_0_VAR_LIMIT = _OS_CanIsrTx_0_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE_NOINIT )
.OS_CanIsrTx_0_VAR_NOINIT ALIGN(4) :> .
_OS_CanIsrTx_0_VAR_NOINIT_START = ADDR(.OS_CanIsrTx_0_VAR_NOINIT);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_NOINIT_END = . - 1;
_OS_CanIsrTx_0_VAR_NOINIT_LIMIT = .;
__OS_CanIsrTx_0_VAR_NOINIT_START = _OS_CanIsrTx_0_VAR_NOINIT_START;
__OS_CanIsrTx_0_VAR_NOINIT_END = _OS_CanIsrTx_0_VAR_NOINIT_END;
__OS_CanIsrTx_0_VAR_NOINIT_LIMIT = _OS_CanIsrTx_0_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE_ZERO_INIT )
.OS_CanIsrTx_0_VAR_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrTx_0_VAR_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrTx_0_VAR_ZERO_INIT_START = ADDR(.OS_CanIsrTx_0_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_ZERO_INIT_END = . - 1;
_OS_CanIsrTx_0_VAR_ZERO_INIT_LIMIT = .;
__OS_CanIsrTx_0_VAR_ZERO_INIT_START = _OS_CanIsrTx_0_VAR_ZERO_INIT_START;
__OS_CanIsrTx_0_VAR_ZERO_INIT_END = _OS_CanIsrTx_0_VAR_ZERO_INIT_END;
__OS_CanIsrTx_0_VAR_ZERO_INIT_LIMIT = _OS_CanIsrTx_0_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE_INIT )
.OS_CanIsrTx_0_VAR_FAST ALIGN(4) :> .
_OS_CanIsrTx_0_VAR_FAST_START = ADDR(.OS_CanIsrTx_0_VAR_FAST);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_FAST_END = . - 1;
_OS_CanIsrTx_0_VAR_FAST_LIMIT = .;
__OS_CanIsrTx_0_VAR_FAST_START = _OS_CanIsrTx_0_VAR_FAST_START;
__OS_CanIsrTx_0_VAR_FAST_END = _OS_CanIsrTx_0_VAR_FAST_END;
__OS_CanIsrTx_0_VAR_FAST_LIMIT = _OS_CanIsrTx_0_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE_NOINIT )
.OS_CanIsrTx_0_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CanIsrTx_0_VAR_FAST_NOINIT_START = ADDR(.OS_CanIsrTx_0_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_FAST_NOINIT_END = . - 1;
_OS_CanIsrTx_0_VAR_FAST_NOINIT_LIMIT = .;
__OS_CanIsrTx_0_VAR_FAST_NOINIT_START = _OS_CanIsrTx_0_VAR_FAST_NOINIT_START;
__OS_CanIsrTx_0_VAR_FAST_NOINIT_END = _OS_CanIsrTx_0_VAR_FAST_NOINIT_END;
__OS_CanIsrTx_0_VAR_FAST_NOINIT_LIMIT = _OS_CanIsrTx_0_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE_ZERO_INIT )
.OS_CanIsrTx_0_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_START = ADDR(.OS_CanIsrTx_0_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_START = _OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_START;
__OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_END = _OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_END;
__OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_LIMIT = _OS_CanIsrTx_0_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE_INIT )
.OS_CanIsrTx_0_VAR_NOCACHE ALIGN(4) :> .
_OS_CanIsrTx_0_VAR_NOCACHE_START = ADDR(.OS_CanIsrTx_0_VAR_NOCACHE);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_NOCACHE_END = . - 1;
_OS_CanIsrTx_0_VAR_NOCACHE_LIMIT = .;
__OS_CanIsrTx_0_VAR_NOCACHE_START = _OS_CanIsrTx_0_VAR_NOCACHE_START;
__OS_CanIsrTx_0_VAR_NOCACHE_END = _OS_CanIsrTx_0_VAR_NOCACHE_END;
__OS_CanIsrTx_0_VAR_NOCACHE_LIMIT = _OS_CanIsrTx_0_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE_NOINIT )
.OS_CanIsrTx_0_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrTx_0_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrTx_0_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_CanIsrTx_0_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_CanIsrTx_0_VAR_NOCACHE_NOINIT_START = _OS_CanIsrTx_0_VAR_NOCACHE_NOINIT_START;
__OS_CanIsrTx_0_VAR_NOCACHE_NOINIT_END = _OS_CanIsrTx_0_VAR_NOCACHE_NOINIT_END;
__OS_CanIsrTx_0_VAR_NOCACHE_NOINIT_LIMIT = _OS_CanIsrTx_0_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE_ZERO_INIT )
.OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_START = _OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_START;
__OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_END = _OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_END;
__OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_CanIsrTx_0_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE_INIT )
.OS_CanIsrTx_0_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CanIsrTx_0_VAR_FAST_NOCACHE_START = ADDR(.OS_CanIsrTx_0_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_FAST_NOCACHE_END = . - 1;
_OS_CanIsrTx_0_VAR_FAST_NOCACHE_LIMIT = .;
__OS_CanIsrTx_0_VAR_FAST_NOCACHE_START = _OS_CanIsrTx_0_VAR_FAST_NOCACHE_START;
__OS_CanIsrTx_0_VAR_FAST_NOCACHE_END = _OS_CanIsrTx_0_VAR_FAST_NOCACHE_END;
__OS_CanIsrTx_0_VAR_FAST_NOCACHE_LIMIT = _OS_CanIsrTx_0_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE_NOINIT )
.OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT_START = _OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT_START;
__OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT_END = _OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT_END;
__OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_CanIsrTx_0_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0 ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE_ZERO_INIT )
.OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_CanIsrTx_0_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0
. = ALIGN(4);
_OS_CanIsrTx_0_VAR_ALL_END = . - 1;
__OS_CanIsrTx_0_VAR_ALL_END = . - 1;
_OS_CanIsrTx_0_VAR_ALL_LIMIT = .;
__OS_CanIsrTx_0_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_CANISRTX_0
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_FAR
# undef OS_LINK_VAR_ISR_CANISRTX_0_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_NEAR
# undef OS_LINK_VAR_ISR_CANISRTX_0_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISRTX_0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_ALL_START = .;
__OS_CounterIsr_OsCounter_10ms_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE_INIT )
.OS_CounterIsr_OsCounter_10ms_VAR ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_VAR_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_START = _OS_CounterIsr_OsCounter_10ms_VAR_START;
__OS_CounterIsr_OsCounter_10ms_VAR_END = _OS_CounterIsr_OsCounter_10ms_VAR_END;
__OS_CounterIsr_OsCounter_10ms_VAR_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE_NOINIT )
.OS_CounterIsr_OsCounter_10ms_VAR_NOINIT ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_NOINIT);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_START = _OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_START;
__OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_END = _OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_END;
__OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE_ZERO_INIT )
.OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_START = _OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_START;
__OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_END = _OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_END;
__OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE_INIT )
.OS_CounterIsr_OsCounter_10ms_VAR_FAST ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_FAST);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_START = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_START;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_END = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_END;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE_NOINIT )
.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_START = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_START;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_END = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_END;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE_ZERO_INIT )
.OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_START = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_START;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_END = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_END;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE_INIT )
.OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_START = _OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_START;
__OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_END = _OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_END;
__OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE_NOINIT )
.OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT_START = _OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT_START;
__OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT_END = _OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT_END;
__OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE_ZERO_INIT )
.OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_START = _OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_START;
__OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_END = _OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_END;
__OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE_INIT )
.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_START = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_START;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_END = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_END;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE_NOINIT )
.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT_START = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT_START;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT_END = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT_END;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE_ZERO_INIT )
.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_CounterIsr_OsCounter_10ms_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS
. = ALIGN(4);
_OS_CounterIsr_OsCounter_10ms_VAR_ALL_END = . - 1;
__OS_CounterIsr_OsCounter_10ms_VAR_ALL_END = . - 1;
_OS_CounterIsr_OsCounter_10ms_VAR_ALL_LIMIT = .;
__OS_CounterIsr_OsCounter_10ms_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_OSCOUNTER_10MS_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_ALL_START = .;
__OS_CounterIsr_SystemTimer_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT )
.OS_CounterIsr_SystemTimer_VAR ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_START = ADDR(.OS_CounterIsr_SystemTimer_VAR);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_START = _OS_CounterIsr_SystemTimer_VAR_START;
__OS_CounterIsr_SystemTimer_VAR_END = _OS_CounterIsr_SystemTimer_VAR_END;
__OS_CounterIsr_SystemTimer_VAR_LIMIT = _OS_CounterIsr_SystemTimer_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT )
.OS_CounterIsr_SystemTimer_VAR_NOINIT ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_NOINIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_NOINIT);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_NOINIT_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_NOINIT_START = _OS_CounterIsr_SystemTimer_VAR_NOINIT_START;
__OS_CounterIsr_SystemTimer_VAR_NOINIT_END = _OS_CounterIsr_SystemTimer_VAR_NOINIT_END;
__OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT = _OS_CounterIsr_SystemTimer_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT )
.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START = _OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_START;
__OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END = _OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_END;
__OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_LIMIT = _OS_CounterIsr_SystemTimer_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT )
.OS_CounterIsr_SystemTimer_VAR_FAST ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_FAST_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_FAST_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_FAST_START = _OS_CounterIsr_SystemTimer_VAR_FAST_START;
__OS_CounterIsr_SystemTimer_VAR_FAST_END = _OS_CounterIsr_SystemTimer_VAR_FAST_END;
__OS_CounterIsr_SystemTimer_VAR_FAST_LIMIT = _OS_CounterIsr_SystemTimer_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START = _OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_START;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END = _OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_END;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT = _OS_CounterIsr_SystemTimer_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START = _OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_START;
__OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END = _OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_END;
__OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_LIMIT = _OS_CounterIsr_SystemTimer_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT )
.OS_CounterIsr_SystemTimer_VAR_NOCACHE ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_NOCACHE);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_NOCACHE_START = _OS_CounterIsr_SystemTimer_VAR_NOCACHE_START;
__OS_CounterIsr_SystemTimer_VAR_NOCACHE_END = _OS_CounterIsr_SystemTimer_VAR_NOCACHE_END;
__OS_CounterIsr_SystemTimer_VAR_NOCACHE_LIMIT = _OS_CounterIsr_SystemTimer_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT )
.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START = _OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_START;
__OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END = _OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_END;
__OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_LIMIT = _OS_CounterIsr_SystemTimer_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT )
.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_START = _OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_START;
__OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_END = _OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_END;
__OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_CounterIsr_SystemTimer_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_START = _OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_START;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_END = _OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_END;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_LIMIT = _OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START = _OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_START;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END = _OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_END;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT )
.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_CounterIsr_SystemTimer_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
. = ALIGN(4);
_OS_CounterIsr_SystemTimer_VAR_ALL_END = . - 1;
__OS_CounterIsr_SystemTimer_VAR_ALL_END = . - 1;
_OS_CounterIsr_SystemTimer_VAR_ALL_LIMIT = .;
__OS_CounterIsr_SystemTimer_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ALL_START = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE_INIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE_INIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH03_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR
. = ALIGN(4);
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_EXT_INTP_CH03_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_EXT_INTP_CH03_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH03_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ALL_START = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE_INIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE_INIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH07_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR
. = ALIGN(4);
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_EXT_INTP_CH07_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_EXT_INTP_CH07_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH07_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ALL_START = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE_INIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE_INIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_EXT_INTP_CH17_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR
. = ALIGN(4);
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_EXT_INTP_CH17_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_EXT_INTP_CH17_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_EXT_INTP_CH17_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_INTIIC0EE
. = ALIGN(4);
_OS_INTIIC0EE_VAR_ALL_START = .;
__OS_INTIIC0EE_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE_INIT )
.OS_INTIIC0EE_VAR ALIGN(4) :> .
_OS_INTIIC0EE_VAR_START = ADDR(.OS_INTIIC0EE_VAR);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_END = . - 1;
_OS_INTIIC0EE_VAR_LIMIT = .;
__OS_INTIIC0EE_VAR_START = _OS_INTIIC0EE_VAR_START;
__OS_INTIIC0EE_VAR_END = _OS_INTIIC0EE_VAR_END;
__OS_INTIIC0EE_VAR_LIMIT = _OS_INTIIC0EE_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE_NOINIT )
.OS_INTIIC0EE_VAR_NOINIT ALIGN(4) :> .
_OS_INTIIC0EE_VAR_NOINIT_START = ADDR(.OS_INTIIC0EE_VAR_NOINIT);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_NOINIT_END = . - 1;
_OS_INTIIC0EE_VAR_NOINIT_LIMIT = .;
__OS_INTIIC0EE_VAR_NOINIT_START = _OS_INTIIC0EE_VAR_NOINIT_START;
__OS_INTIIC0EE_VAR_NOINIT_END = _OS_INTIIC0EE_VAR_NOINIT_END;
__OS_INTIIC0EE_VAR_NOINIT_LIMIT = _OS_INTIIC0EE_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE_ZERO_INIT )
.OS_INTIIC0EE_VAR_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0EE_VAR_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0EE_VAR_ZERO_INIT_START = ADDR(.OS_INTIIC0EE_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_ZERO_INIT_END = . - 1;
_OS_INTIIC0EE_VAR_ZERO_INIT_LIMIT = .;
__OS_INTIIC0EE_VAR_ZERO_INIT_START = _OS_INTIIC0EE_VAR_ZERO_INIT_START;
__OS_INTIIC0EE_VAR_ZERO_INIT_END = _OS_INTIIC0EE_VAR_ZERO_INIT_END;
__OS_INTIIC0EE_VAR_ZERO_INIT_LIMIT = _OS_INTIIC0EE_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE_INIT )
.OS_INTIIC0EE_VAR_FAST ALIGN(4) :> .
_OS_INTIIC0EE_VAR_FAST_START = ADDR(.OS_INTIIC0EE_VAR_FAST);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_FAST_END = . - 1;
_OS_INTIIC0EE_VAR_FAST_LIMIT = .;
__OS_INTIIC0EE_VAR_FAST_START = _OS_INTIIC0EE_VAR_FAST_START;
__OS_INTIIC0EE_VAR_FAST_END = _OS_INTIIC0EE_VAR_FAST_END;
__OS_INTIIC0EE_VAR_FAST_LIMIT = _OS_INTIIC0EE_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE_NOINIT )
.OS_INTIIC0EE_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_INTIIC0EE_VAR_FAST_NOINIT_START = ADDR(.OS_INTIIC0EE_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_FAST_NOINIT_END = . - 1;
_OS_INTIIC0EE_VAR_FAST_NOINIT_LIMIT = .;
__OS_INTIIC0EE_VAR_FAST_NOINIT_START = _OS_INTIIC0EE_VAR_FAST_NOINIT_START;
__OS_INTIIC0EE_VAR_FAST_NOINIT_END = _OS_INTIIC0EE_VAR_FAST_NOINIT_END;
__OS_INTIIC0EE_VAR_FAST_NOINIT_LIMIT = _OS_INTIIC0EE_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE_ZERO_INIT )
.OS_INTIIC0EE_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0EE_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_START = ADDR(.OS_INTIIC0EE_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_INTIIC0EE_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_INTIIC0EE_VAR_FAST_ZERO_INIT_START = _OS_INTIIC0EE_VAR_FAST_ZERO_INIT_START;
__OS_INTIIC0EE_VAR_FAST_ZERO_INIT_END = _OS_INTIIC0EE_VAR_FAST_ZERO_INIT_END;
__OS_INTIIC0EE_VAR_FAST_ZERO_INIT_LIMIT = _OS_INTIIC0EE_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE_INIT )
.OS_INTIIC0EE_VAR_NOCACHE ALIGN(4) :> .
_OS_INTIIC0EE_VAR_NOCACHE_START = ADDR(.OS_INTIIC0EE_VAR_NOCACHE);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_NOCACHE_END = . - 1;
_OS_INTIIC0EE_VAR_NOCACHE_LIMIT = .;
__OS_INTIIC0EE_VAR_NOCACHE_START = _OS_INTIIC0EE_VAR_NOCACHE_START;
__OS_INTIIC0EE_VAR_NOCACHE_END = _OS_INTIIC0EE_VAR_NOCACHE_END;
__OS_INTIIC0EE_VAR_NOCACHE_LIMIT = _OS_INTIIC0EE_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE_NOINIT )
.OS_INTIIC0EE_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_INTIIC0EE_VAR_NOCACHE_NOINIT_START = ADDR(.OS_INTIIC0EE_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_INTIIC0EE_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_INTIIC0EE_VAR_NOCACHE_NOINIT_START = _OS_INTIIC0EE_VAR_NOCACHE_NOINIT_START;
__OS_INTIIC0EE_VAR_NOCACHE_NOINIT_END = _OS_INTIIC0EE_VAR_NOCACHE_NOINIT_END;
__OS_INTIIC0EE_VAR_NOCACHE_NOINIT_LIMIT = _OS_INTIIC0EE_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE_ZERO_INIT )
.OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_START = _OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_START;
__OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_END = _OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_END;
__OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_INTIIC0EE_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE_INIT )
.OS_INTIIC0EE_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_INTIIC0EE_VAR_FAST_NOCACHE_START = ADDR(.OS_INTIIC0EE_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_FAST_NOCACHE_END = . - 1;
_OS_INTIIC0EE_VAR_FAST_NOCACHE_LIMIT = .;
__OS_INTIIC0EE_VAR_FAST_NOCACHE_START = _OS_INTIIC0EE_VAR_FAST_NOCACHE_START;
__OS_INTIIC0EE_VAR_FAST_NOCACHE_END = _OS_INTIIC0EE_VAR_FAST_NOCACHE_END;
__OS_INTIIC0EE_VAR_FAST_NOCACHE_LIMIT = _OS_INTIIC0EE_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE_NOINIT )
.OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT_START = _OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT_START;
__OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT_END = _OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT_END;
__OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_INTIIC0EE_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE_ZERO_INIT )
.OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_INTIIC0EE_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE
. = ALIGN(4);
_OS_INTIIC0EE_VAR_ALL_END = . - 1;
__OS_INTIIC0EE_VAR_ALL_END = . - 1;
_OS_INTIIC0EE_VAR_ALL_LIMIT = .;
__OS_INTIIC0EE_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_INTIIC0EE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_FAR
# undef OS_LINK_VAR_ISR_INTIIC0EE_FAR
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE
# undef OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_NEAR
# undef OS_LINK_VAR_ISR_INTIIC0EE_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE
# undef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0EE_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_INTIIC0RI
. = ALIGN(4);
_OS_INTIIC0RI_VAR_ALL_START = .;
__OS_INTIIC0RI_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE_INIT )
.OS_INTIIC0RI_VAR ALIGN(4) :> .
_OS_INTIIC0RI_VAR_START = ADDR(.OS_INTIIC0RI_VAR);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_END = . - 1;
_OS_INTIIC0RI_VAR_LIMIT = .;
__OS_INTIIC0RI_VAR_START = _OS_INTIIC0RI_VAR_START;
__OS_INTIIC0RI_VAR_END = _OS_INTIIC0RI_VAR_END;
__OS_INTIIC0RI_VAR_LIMIT = _OS_INTIIC0RI_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE_NOINIT )
.OS_INTIIC0RI_VAR_NOINIT ALIGN(4) :> .
_OS_INTIIC0RI_VAR_NOINIT_START = ADDR(.OS_INTIIC0RI_VAR_NOINIT);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_NOINIT_END = . - 1;
_OS_INTIIC0RI_VAR_NOINIT_LIMIT = .;
__OS_INTIIC0RI_VAR_NOINIT_START = _OS_INTIIC0RI_VAR_NOINIT_START;
__OS_INTIIC0RI_VAR_NOINIT_END = _OS_INTIIC0RI_VAR_NOINIT_END;
__OS_INTIIC0RI_VAR_NOINIT_LIMIT = _OS_INTIIC0RI_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE_ZERO_INIT )
.OS_INTIIC0RI_VAR_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0RI_VAR_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0RI_VAR_ZERO_INIT_START = ADDR(.OS_INTIIC0RI_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_ZERO_INIT_END = . - 1;
_OS_INTIIC0RI_VAR_ZERO_INIT_LIMIT = .;
__OS_INTIIC0RI_VAR_ZERO_INIT_START = _OS_INTIIC0RI_VAR_ZERO_INIT_START;
__OS_INTIIC0RI_VAR_ZERO_INIT_END = _OS_INTIIC0RI_VAR_ZERO_INIT_END;
__OS_INTIIC0RI_VAR_ZERO_INIT_LIMIT = _OS_INTIIC0RI_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE_INIT )
.OS_INTIIC0RI_VAR_FAST ALIGN(4) :> .
_OS_INTIIC0RI_VAR_FAST_START = ADDR(.OS_INTIIC0RI_VAR_FAST);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_FAST_END = . - 1;
_OS_INTIIC0RI_VAR_FAST_LIMIT = .;
__OS_INTIIC0RI_VAR_FAST_START = _OS_INTIIC0RI_VAR_FAST_START;
__OS_INTIIC0RI_VAR_FAST_END = _OS_INTIIC0RI_VAR_FAST_END;
__OS_INTIIC0RI_VAR_FAST_LIMIT = _OS_INTIIC0RI_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE_NOINIT )
.OS_INTIIC0RI_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_INTIIC0RI_VAR_FAST_NOINIT_START = ADDR(.OS_INTIIC0RI_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_FAST_NOINIT_END = . - 1;
_OS_INTIIC0RI_VAR_FAST_NOINIT_LIMIT = .;
__OS_INTIIC0RI_VAR_FAST_NOINIT_START = _OS_INTIIC0RI_VAR_FAST_NOINIT_START;
__OS_INTIIC0RI_VAR_FAST_NOINIT_END = _OS_INTIIC0RI_VAR_FAST_NOINIT_END;
__OS_INTIIC0RI_VAR_FAST_NOINIT_LIMIT = _OS_INTIIC0RI_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE_ZERO_INIT )
.OS_INTIIC0RI_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0RI_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_START = ADDR(.OS_INTIIC0RI_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_INTIIC0RI_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_INTIIC0RI_VAR_FAST_ZERO_INIT_START = _OS_INTIIC0RI_VAR_FAST_ZERO_INIT_START;
__OS_INTIIC0RI_VAR_FAST_ZERO_INIT_END = _OS_INTIIC0RI_VAR_FAST_ZERO_INIT_END;
__OS_INTIIC0RI_VAR_FAST_ZERO_INIT_LIMIT = _OS_INTIIC0RI_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE_INIT )
.OS_INTIIC0RI_VAR_NOCACHE ALIGN(4) :> .
_OS_INTIIC0RI_VAR_NOCACHE_START = ADDR(.OS_INTIIC0RI_VAR_NOCACHE);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_NOCACHE_END = . - 1;
_OS_INTIIC0RI_VAR_NOCACHE_LIMIT = .;
__OS_INTIIC0RI_VAR_NOCACHE_START = _OS_INTIIC0RI_VAR_NOCACHE_START;
__OS_INTIIC0RI_VAR_NOCACHE_END = _OS_INTIIC0RI_VAR_NOCACHE_END;
__OS_INTIIC0RI_VAR_NOCACHE_LIMIT = _OS_INTIIC0RI_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE_NOINIT )
.OS_INTIIC0RI_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_INTIIC0RI_VAR_NOCACHE_NOINIT_START = ADDR(.OS_INTIIC0RI_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_INTIIC0RI_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_INTIIC0RI_VAR_NOCACHE_NOINIT_START = _OS_INTIIC0RI_VAR_NOCACHE_NOINIT_START;
__OS_INTIIC0RI_VAR_NOCACHE_NOINIT_END = _OS_INTIIC0RI_VAR_NOCACHE_NOINIT_END;
__OS_INTIIC0RI_VAR_NOCACHE_NOINIT_LIMIT = _OS_INTIIC0RI_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE_ZERO_INIT )
.OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_START = _OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_START;
__OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_END = _OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_END;
__OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_INTIIC0RI_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE_INIT )
.OS_INTIIC0RI_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_INTIIC0RI_VAR_FAST_NOCACHE_START = ADDR(.OS_INTIIC0RI_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_FAST_NOCACHE_END = . - 1;
_OS_INTIIC0RI_VAR_FAST_NOCACHE_LIMIT = .;
__OS_INTIIC0RI_VAR_FAST_NOCACHE_START = _OS_INTIIC0RI_VAR_FAST_NOCACHE_START;
__OS_INTIIC0RI_VAR_FAST_NOCACHE_END = _OS_INTIIC0RI_VAR_FAST_NOCACHE_END;
__OS_INTIIC0RI_VAR_FAST_NOCACHE_LIMIT = _OS_INTIIC0RI_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE_NOINIT )
.OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT_START = _OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT_START;
__OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT_END = _OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT_END;
__OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_INTIIC0RI_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE_ZERO_INIT )
.OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_INTIIC0RI_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI
. = ALIGN(4);
_OS_INTIIC0RI_VAR_ALL_END = . - 1;
__OS_INTIIC0RI_VAR_ALL_END = . - 1;
_OS_INTIIC0RI_VAR_ALL_LIMIT = .;
__OS_INTIIC0RI_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_INTIIC0RI
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_FAR
# undef OS_LINK_VAR_ISR_INTIIC0RI_FAR
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE
# undef OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_NEAR
# undef OS_LINK_VAR_ISR_INTIIC0RI_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE
# undef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0RI_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_INTIIC0TEI
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_ALL_START = .;
__OS_INTIIC0TEI_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE_INIT )
.OS_INTIIC0TEI_VAR ALIGN(4) :> .
_OS_INTIIC0TEI_VAR_START = ADDR(.OS_INTIIC0TEI_VAR);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_END = . - 1;
_OS_INTIIC0TEI_VAR_LIMIT = .;
__OS_INTIIC0TEI_VAR_START = _OS_INTIIC0TEI_VAR_START;
__OS_INTIIC0TEI_VAR_END = _OS_INTIIC0TEI_VAR_END;
__OS_INTIIC0TEI_VAR_LIMIT = _OS_INTIIC0TEI_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE_NOINIT )
.OS_INTIIC0TEI_VAR_NOINIT ALIGN(4) :> .
_OS_INTIIC0TEI_VAR_NOINIT_START = ADDR(.OS_INTIIC0TEI_VAR_NOINIT);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_NOINIT_END = . - 1;
_OS_INTIIC0TEI_VAR_NOINIT_LIMIT = .;
__OS_INTIIC0TEI_VAR_NOINIT_START = _OS_INTIIC0TEI_VAR_NOINIT_START;
__OS_INTIIC0TEI_VAR_NOINIT_END = _OS_INTIIC0TEI_VAR_NOINIT_END;
__OS_INTIIC0TEI_VAR_NOINIT_LIMIT = _OS_INTIIC0TEI_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE_ZERO_INIT )
.OS_INTIIC0TEI_VAR_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0TEI_VAR_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0TEI_VAR_ZERO_INIT_START = ADDR(.OS_INTIIC0TEI_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_ZERO_INIT_END = . - 1;
_OS_INTIIC0TEI_VAR_ZERO_INIT_LIMIT = .;
__OS_INTIIC0TEI_VAR_ZERO_INIT_START = _OS_INTIIC0TEI_VAR_ZERO_INIT_START;
__OS_INTIIC0TEI_VAR_ZERO_INIT_END = _OS_INTIIC0TEI_VAR_ZERO_INIT_END;
__OS_INTIIC0TEI_VAR_ZERO_INIT_LIMIT = _OS_INTIIC0TEI_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE_INIT )
.OS_INTIIC0TEI_VAR_FAST ALIGN(4) :> .
_OS_INTIIC0TEI_VAR_FAST_START = ADDR(.OS_INTIIC0TEI_VAR_FAST);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_FAST_END = . - 1;
_OS_INTIIC0TEI_VAR_FAST_LIMIT = .;
__OS_INTIIC0TEI_VAR_FAST_START = _OS_INTIIC0TEI_VAR_FAST_START;
__OS_INTIIC0TEI_VAR_FAST_END = _OS_INTIIC0TEI_VAR_FAST_END;
__OS_INTIIC0TEI_VAR_FAST_LIMIT = _OS_INTIIC0TEI_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE_NOINIT )
.OS_INTIIC0TEI_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_INTIIC0TEI_VAR_FAST_NOINIT_START = ADDR(.OS_INTIIC0TEI_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_FAST_NOINIT_END = . - 1;
_OS_INTIIC0TEI_VAR_FAST_NOINIT_LIMIT = .;
__OS_INTIIC0TEI_VAR_FAST_NOINIT_START = _OS_INTIIC0TEI_VAR_FAST_NOINIT_START;
__OS_INTIIC0TEI_VAR_FAST_NOINIT_END = _OS_INTIIC0TEI_VAR_FAST_NOINIT_END;
__OS_INTIIC0TEI_VAR_FAST_NOINIT_LIMIT = _OS_INTIIC0TEI_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE_ZERO_INIT )
.OS_INTIIC0TEI_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_START = ADDR(.OS_INTIIC0TEI_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_START = _OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_START;
__OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_END = _OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_END;
__OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_LIMIT = _OS_INTIIC0TEI_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE_INIT )
.OS_INTIIC0TEI_VAR_NOCACHE ALIGN(4) :> .
_OS_INTIIC0TEI_VAR_NOCACHE_START = ADDR(.OS_INTIIC0TEI_VAR_NOCACHE);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_NOCACHE_END = . - 1;
_OS_INTIIC0TEI_VAR_NOCACHE_LIMIT = .;
__OS_INTIIC0TEI_VAR_NOCACHE_START = _OS_INTIIC0TEI_VAR_NOCACHE_START;
__OS_INTIIC0TEI_VAR_NOCACHE_END = _OS_INTIIC0TEI_VAR_NOCACHE_END;
__OS_INTIIC0TEI_VAR_NOCACHE_LIMIT = _OS_INTIIC0TEI_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE_NOINIT )
.OS_INTIIC0TEI_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_INTIIC0TEI_VAR_NOCACHE_NOINIT_START = ADDR(.OS_INTIIC0TEI_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_INTIIC0TEI_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_INTIIC0TEI_VAR_NOCACHE_NOINIT_START = _OS_INTIIC0TEI_VAR_NOCACHE_NOINIT_START;
__OS_INTIIC0TEI_VAR_NOCACHE_NOINIT_END = _OS_INTIIC0TEI_VAR_NOCACHE_NOINIT_END;
__OS_INTIIC0TEI_VAR_NOCACHE_NOINIT_LIMIT = _OS_INTIIC0TEI_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE_ZERO_INIT )
.OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_START = _OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_START;
__OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_END = _OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_END;
__OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_INTIIC0TEI_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE_INIT )
.OS_INTIIC0TEI_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_INTIIC0TEI_VAR_FAST_NOCACHE_START = ADDR(.OS_INTIIC0TEI_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_FAST_NOCACHE_END = . - 1;
_OS_INTIIC0TEI_VAR_FAST_NOCACHE_LIMIT = .;
__OS_INTIIC0TEI_VAR_FAST_NOCACHE_START = _OS_INTIIC0TEI_VAR_FAST_NOCACHE_START;
__OS_INTIIC0TEI_VAR_FAST_NOCACHE_END = _OS_INTIIC0TEI_VAR_FAST_NOCACHE_END;
__OS_INTIIC0TEI_VAR_FAST_NOCACHE_LIMIT = _OS_INTIIC0TEI_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE_NOINIT )
.OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT_START = _OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT_START;
__OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT_END = _OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT_END;
__OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_INTIIC0TEI_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE_ZERO_INIT )
.OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_INTIIC0TEI_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI
. = ALIGN(4);
_OS_INTIIC0TEI_VAR_ALL_END = . - 1;
__OS_INTIIC0TEI_VAR_ALL_END = . - 1;
_OS_INTIIC0TEI_VAR_ALL_LIMIT = .;
__OS_INTIIC0TEI_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_INTIIC0TEI
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_FAR
# undef OS_LINK_VAR_ISR_INTIIC0TEI_FAR
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE
# undef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR
# undef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE
# undef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_INTIIC0TEI_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_ALL_START = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE_INIT )
.OS_IRQDmaChannel2TransmitComplete_VAR ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_START = _OS_IRQDmaChannel2TransmitComplete_VAR_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_END = _OS_IRQDmaChannel2TransmitComplete_VAR_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE_NOINIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_START = _OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_END = _OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE_ZERO_INIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_START = _OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_END = _OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE_INIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_FAST ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_FAST);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_START = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_END = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE_NOINIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_START = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_END = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE_ZERO_INIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_START = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_END = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE_INIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_START = _OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_END = _OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE_NOINIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT_START = _OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT_END = _OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE_ZERO_INIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_START = _OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_END = _OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE_INIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_START = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_END = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE_NOINIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT_START = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT_END = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE_ZERO_INIT )
.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_IRQDmaChannel2TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE
. = ALIGN(4);
_OS_IRQDmaChannel2TransmitComplete_VAR_ALL_END = . - 1;
__OS_IRQDmaChannel2TransmitComplete_VAR_ALL_END = . - 1;
_OS_IRQDmaChannel2TransmitComplete_VAR_ALL_LIMIT = .;
__OS_IRQDmaChannel2TransmitComplete_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL2TRANSMITCOMPLETE_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_ALL_START = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE_INIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE_NOINIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE_ZERO_INIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE_INIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE_NOINIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE_ZERO_INIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE_INIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE_NOINIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE_ZERO_INIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE_INIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE_NOINIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE_ZERO_INIT )
.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_IRQDmaChannel5ReceiveComplete_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE
. = ALIGN(4);
_OS_IRQDmaChannel5ReceiveComplete_VAR_ALL_END = . - 1;
__OS_IRQDmaChannel5ReceiveComplete_VAR_ALL_END = . - 1;
_OS_IRQDmaChannel5ReceiveComplete_VAR_ALL_LIMIT = .;
__OS_IRQDmaChannel5ReceiveComplete_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5RECEIVECOMPLETE_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_ALL_START = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE_INIT )
.OS_IRQDmaChannel5TransmitComplete_VAR ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_START = _OS_IRQDmaChannel5TransmitComplete_VAR_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_END = _OS_IRQDmaChannel5TransmitComplete_VAR_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE_NOINIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_START = _OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_END = _OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE_ZERO_INIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_START = _OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_END = _OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE_INIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_FAST ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_FAST);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_START = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_END = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE_NOINIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_START = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_END = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE_ZERO_INIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_START = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_END = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE_INIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_START = _OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_END = _OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE_NOINIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT_START = _OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT_END = _OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE_ZERO_INIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_START = _OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_END = _OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE_INIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_START = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_END = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE_NOINIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT_START = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT_END = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE_ZERO_INIT )
.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_IRQDmaChannel5TransmitComplete_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE
. = ALIGN(4);
_OS_IRQDmaChannel5TransmitComplete_VAR_ALL_END = . - 1;
__OS_IRQDmaChannel5TransmitComplete_VAR_ALL_END = . - 1;
_OS_IRQDmaChannel5TransmitComplete_VAR_ALL_LIMIT = .;
__OS_IRQDmaChannel5TransmitComplete_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_IRQDMACHANNEL5TRANSMITCOMPLETE_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ALL_START = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE_INIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE_INIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR
. = ALIGN(4);
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_SPI_CSIH0_TIR_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH0_TIR_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ALL_START = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE_INIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE_INIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR
. = ALIGN(4);
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_SPI_CSIH2_TIR_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH2_TIR_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ALL_START = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE_INIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE_INIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR
. = ALIGN(4);
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_SPI_CSIH3_TIR_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_SPI_CSIH3_TIR_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_ALL_START = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE_INIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE_INIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH00_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH00_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_TAUD0_CH00_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_TAUD0_CH00_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_TAUD0_CH00_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH00_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_ALL_START = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE_INIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE_INIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH01_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH01_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_TAUD0_CH01_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_TAUD0_CH01_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_TAUD0_CH01_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH01_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_ALL_START = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE_INIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE_INIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH02_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH02_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_TAUD0_CH02_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_TAUD0_CH02_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_TAUD0_CH02_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH02_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_ALL_START = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE_INIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE_INIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH04_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH04_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_TAUD0_CH04_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_TAUD0_CH04_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_TAUD0_CH04_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH04_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_ALL_START = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE_INIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE_INIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_TAUD0_CH05_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR
. = ALIGN(4);
_OS_TAUD0_CH05_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_TAUD0_CH05_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_TAUD0_CH05_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_TAUD0_CH05_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_TAUD0_CH05_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ALL_START = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ALL_START = .;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE_INIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE_NOINIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE_ZERO_INIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT ALIGN(4) :> .
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_bss CLEAR :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE_INIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE_NOINIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE_ZERO_INIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT ALIGN(4) :> .
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_bss CLEAR :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE_INIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE_NOINIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE_ZERO_INIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_NOCACHE_ZERO_INIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE_INIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE_NOINIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT ALIGN(4) :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_NOINIT_LIMIT;
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT )
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT ALIGN(4) :> .
.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss CLEAR :> .
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = ADDR(.OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT);
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT = _OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_LIMIT;
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR
. = ALIGN(4);
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ALL_END = . - 1;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ALL_END = . - 1;
_OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ALL_LIMIT = .;
__OS_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_VAR_ALL_LIMIT = .;
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_WDG_59_DRIVERA_TRIGGERFUNCTION_CAT2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif


#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif

#ifdef OS_LINK_VAR_APP
# undef OS_LINK_VAR_APP
#endif

#ifdef OS_LINK_VAR_TASK
# undef OS_LINK_VAR_TASK
#endif

#ifdef OS_LINK_VAR_ISR
# undef OS_LINK_VAR_ISR
#endif

#ifdef OS_LINK_KERNEL_TRACE
# undef OS_LINK_KERNEL_TRACE
#endif

#ifdef OS_LINK_KERNEL_TRACE_FAR
# undef OS_LINK_KERNEL_TRACE_FAR
#endif

#ifdef OS_LINK_KERNEL_TRACE_NEAR
# undef OS_LINK_KERNEL_TRACE_NEAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS
# undef OS_LINK_KERNEL_BARRIERS
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_FAR
# undef OS_LINK_KERNEL_BARRIERS_FAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_NEAR
# undef OS_LINK_KERNEL_BARRIERS_NEAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS
# undef OS_LINK_KERNEL_CORESTATUS
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_FAR
# undef OS_LINK_KERNEL_CORESTATUS_FAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_NEAR
# undef OS_LINK_KERNEL_CORESTATUS_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE
# undef OS_LINK_VAR_KERNEL_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif


