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
 *              File: Os_Cfg.h
 *   Generation Time: 2023-05-29 13:28:37
 *           Project: application - Version 1.0
 *          Delivery: CBD1600802_D03
 *      Tool Version: DaVinci Configurator  5.23.45 SP4
 *
 *
 *********************************************************************************************************************/

#ifndef OS_CFG_H
# define OS_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */

/* Os module declarations */

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Configuration major version identification. */
# define OS_CFG_MAJOR_VERSION                    (2u)

/*! Configuration minor version identification. */
# define OS_CFG_MINOR_VERSION                    (56u)

/*! Defines which platform is used. */
# define OS_CFG_PLATFORM_RH850     (STD_ON)

/*! Defines which derivative group is configured. */
# define OS_CFG_DERIVATIVEGROUP_RH850F1KM     (STD_ON)

/*! Defines which derivative is configured. */
# define OS_CFG_DERIVATIVE_RH850_1646     (STD_ON)

/*! Defines which compiler is configured. */
# define OS_CFG_COMPILER_GREENHILLS     (STD_ON)

/*! Defines whether access macros to get context related information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_PARAMETERACCESS              (STD_OFF)

/*! Defines whether access macros to get service ID information in the error hook are enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERR_GETSERVICEID                 (STD_OFF)

/*! Defines whether the pre-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_PRETASKHOOK                      (STD_OFF)

/*! Defines whether the post-task hook is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_POSTTASKHOOK                     (STD_OFF)

/*! Defines whether the OS shall call the panic hook (STD_ON) or not (STD_OFF). */
# define OS_CFG_PANICHOOK                        (STD_OFF)

/*! Defines whether the system startup hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_STARTUPHOOK_SYSTEM               (STD_OFF)

/*! Defines whether the system shutdown hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_SHUTDOWNHOOK_SYSTEM              (STD_ON)

/*! Defines whether the system error hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_ERRORHOOK_SYSTEM                 (STD_ON)

/*! Defines whether the system protection hook is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_PROTECTIONHOOK_SYSTEM            (STD_OFF)

/*! Defines whether backward compatibility defines are needed (STD_ON) or not (STD_OFF). */
# define OS_CFG_PERIPHERAL_COMPATIBILITY         (STD_OFF)

/*! Defines whether interrupt only use case is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_INTERRUPT_ONLY                   (STD_OFF)

/* OS application modes */
# define DONOTCARE     ((AppModeType)0)
# define OS_APPMODE_NONE     ((AppModeType)0)
# define OSDEFAULTAPPMODE     ((AppModeType)1)
# define OS_APPMODE_ANY     ((AppModeType)255)

/*! Defines whether EVENT is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_EVENT                            (STD_ON)

/* Event masks */
# define Rte_Ev_Cyclic2_OsTask_BswMainFunctions_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic2_OsTask_BswMainFunctions_0_20ms     ((EventMaskType)2uLL)
# define Rte_Ev_Cyclic_IO_Task_0_200ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_OsTask_ApplMainFunctions_0_10ms     ((EventMaskType)1uLL)
# define Rte_Ev_Cyclic_OsTask_ApplMainFunctions_0_1ms     ((EventMaskType)2uLL)
# define Rte_Ev_Cyclic_OsTask_ApplTimedInitDeInit_0_1ms     ((EventMaskType)1uLL)
# define Rte_Ev_MS_OsTask_ApplInitDeInit     ((EventMaskType)4uLL)
# define Rte_Ev_OnEntry_OsTask_ApplInitDeInit_SwcDisplayControl_PpSwcDispCtrlDisplayMode_Mode_INIT     ((EventMaskType)1uLL)
# define Rte_Ev_OnEntry_OsTask_ApplInitDeInit_SwcDisplayControl_PpSwcDispCtrlDisplayMode_Mode_UNINIT     ((EventMaskType)2uLL)
# define Rte_Ev_OnEntry_OsTask_ApplMainFunctions_ComM_UM_CN_MIBCAN_49695965_currentMode_COMM_FULL_COMMUNICATION     ((EventMaskType)4uLL)
# define Rte_Ev_OnEntry_OsTask_ApplMainFunctions_ComM_UM_CN_MIBCAN_49695965_currentMode_COMM_NO_COMMUNICATION     ((EventMaskType)8uLL)
# define Rte_Ev_OnEntry_OsTask_DcmSessionChanges_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_DEFAULT_SESSION     ((EventMaskType)1uLL)
# define Rte_Ev_OnExit_OsTask_ApplInitDeInit_SwcDisplayControl_PpSwcDispCtrlDisplayMode_Mode_OFF     ((EventMaskType)8uLL)
# define Rte_Ev_OnExit_OsTask_ApplInitDeInit_SwcDisplayControl_PpSwcDispCtrlDisplayMode_Mode_UNINIT     ((EventMaskType)16uLL)
# define Rte_Ev_OnExit_OsTask_ApplMainFunctions_ComM_UM_CN_MIBCAN_49695965_currentMode_COMM_FULL_COMMUNICATION     ((EventMaskType)16uLL)
# define Rte_Ev_OnExit_OsTask_ApplMainFunctions_ComM_UM_CN_MIBCAN_49695965_currentMode_COMM_NO_COMMUNICATION     ((EventMaskType)32uLL)
# define Rte_Ev_OnRx_OsTask_ApplMainFunctions_CddButton_PpCddBtnButtonStatus_buttonStatus     ((EventMaskType)64uLL)
# define Rte_Ev_OnRx_OsTask_ApplMainFunctions_DI_Screendesign_oZentralrechner_01_oMIBCAN_be1aac5d_Rx     ((EventMaskType)128uLL)
# define Rte_Ev_OnRx_OsTask_Touch_CddTouchCypressGen7_PpCddTouchDisplayData_fingerData     ((EventMaskType)1uLL)
# define Rte_Ev_Run1_CddBoosterMaximMAX20069_CddBstr_Verify     ((EventMaskType)1uLL)
# define Rte_Ev_Run1_CddDebugInfo_CddDbgInfo_OnTxReady     ((EventMaskType)256uLL)
# define Rte_Ev_Run1_CddHWRNXPRT1171_CddHwr_OnUartRxReady     ((EventMaskType)512uLL)
# define Rte_Ev_Run1_CddHeadUnitInterface_CddHUIf_OnButtonHold     ((EventMaskType)2uLL)
# define Rte_Ev_Run1_CddHeadUnitInterface_CddHUIf_OnZrResetComplete     ((EventMaskType)4uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrBlockCounterApp     ((EventMaskType)1uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrBlockCounterBl     ((EventMaskType)2uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrBlockCounterHwr     ((EventMaskType)4uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrBlockCounterNvm     ((EventMaskType)8uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrBlockCounterTchBu     ((EventMaskType)16uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrDowngradeProtectionGlobalVersionNumber     ((EventMaskType)32uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrDowngradeProtectionVersionApp     ((EventMaskType)64uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrDowngradeProtectionVersionBl     ((EventMaskType)128uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrDowngradeProtectionVersionHwr     ((EventMaskType)256uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrDowngradeProtectionVersionNvm     ((EventMaskType)512uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrDowngradeProtectionVersionTchBu     ((EventMaskType)1024uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrECUProgInfo     ((EventMaskType)2048uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrFingerPrintApp     ((EventMaskType)4096uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrFingerPrintBl     ((EventMaskType)8192uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrFingerPrintHwr     ((EventMaskType)16384uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrFingerPrintNvm     ((EventMaskType)32768uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrFingerPrintTchBu     ((EventMaskType)65536uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrSparePartNr     ((EventMaskType)131072uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddDlMngrVersionHistory     ((EventMaskType)262144uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddHwrSwdlDlState     ((EventMaskType)1024uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddTempMonTempMinMax     ((EventMaskType)524288uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddTouchDeviceCfg     ((EventMaskType)1048576uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddVoltMonVoltageMinMax     ((EventMaskType)2097152uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddWUDetNvmData     ((EventMaskType)4194304uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessCddWUDetNvmData2     ((EventMaskType)8388608uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcComRxCfg     ((EventMaskType)16777216uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcComTxBlockCntrs     ((EventMaskType)33554432uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcComTxEventCntrs     ((EventMaskType)67108864uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcDimDimNvData     ((EventMaskType)134217728uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcDispInfoCfg     ((EventMaskType)268435456uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcDispInfoLogisticData     ((EventMaskType)536870912uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcErrorErrorCounters     ((EventMaskType)1073741824uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcErrorErrorTrace     ((EventMaskType)2147483648uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcErrorMinimumSeverities     ((EventMaskType)4294967296uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcHWRCfg     ((EventMaskType)8589934592uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcSecAccessSa2SecAttemptCntrs     ((EventMaskType)17179869184uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcSelfDiagEcuInfo     ((EventMaskType)34359738368uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcTempCorDeratingCount     ((EventMaskType)68719476736uLL)
# define Rte_Ev_Run1_CddNvMManager_CddNvMMngr_ProcessSwcVerifyVerifyMode     ((EventMaskType)137438953472uLL)
# define Rte_Ev_Run1_CddSliderBackLightTiSN1903001_CddSldr_OnReadSeqReady     ((EventMaskType)2048uLL)
# define Rte_Ev_Run1_CddSliderBackLightTiSN1903001_CddSldr_OnWriteSeqReady     ((EventMaskType)4096uLL)
# define Rte_Ev_Run1_CddTouchCypressGen7_CddTouch_Timeout     ((EventMaskType)8192uLL)
# define Rte_Ev_Run1_CddWakeupDetect_CddWUDet_ClearResetStatus     ((EventMaskType)16384uLL)
# define Rte_Ev_Run1_SwcComHandlerRx_SwcComRx_ProcessZrPlatform     ((EventMaskType)32768uLL)
# define Rte_Ev_Run1_SwcComHandlerRx_SwcComRx_WakeupReasonTimeout     ((EventMaskType)65536uLL)
# define Rte_Ev_Run1_SwcHidKeys_SwcHidKeys_OnButtonHold     ((EventMaskType)131072uLL)
# define Rte_Ev_Run1_SwcHidKeys_SwcHidKeys_TxConfirmationTimeout     ((EventMaskType)1uLL)
# define Rte_Ev_Run1_SwcSelfDiagnostics_SwcSelfDiag_UpdateCpuLoad     ((EventMaskType)1uLL)
# define Rte_Ev_Run1_SwcTemperatureCorrection_SwcTempCor_MainFunction     ((EventMaskType)1uLL)
# define Rte_Ev_Run1_SwcTestInterface_SwcTestIf_ProcessTouchData     ((EventMaskType)262144uLL)
# define Rte_Ev_Run1_SwcTouch_SwcTouch_MainFunction     ((EventMaskType)8uLL)
# define Rte_Ev_Run2_SwcTestInterface_SwcTestIf_ProcessTouchData     ((EventMaskType)524288uLL)
# define Rte_Ev_Run_CanTp_CanTp_MainFunction     ((EventMaskType)4uLL)
# define Rte_Ev_Run_CddBoosterMaximMAX20069_CddBstr_ProcessSwcDispCtrlModeReq     ((EventMaskType)1048576uLL)
# define Rte_Ev_Run_CddComTp_CddComTp_Transmit     ((EventMaskType)2uLL)
# define Rte_Ev_Run_CddDeserializerTIDS90Ux948_CddDser_ProcessSwcDispCtrlModeReq     ((EventMaskType)2097152uLL)
# define Rte_Ev_Run_CddDownloadManager_CddDlMngr_OnEntryProgrammingSession     ((EventMaskType)2uLL)
# define Rte_Ev_Run_CddDownloadManager_CddDlMngr_OnExitProgrammingSession     ((EventMaskType)4uLL)
# define Rte_Ev_Run_CddDownloadManager_CddDownloadManager_OnEntryDcmDefaultSession     ((EventMaskType)8uLL)
# define Rte_Ev_Run_CddDownloadManager_CddDownloadManager_OnEntryDcmProgrammingSession     ((EventMaskType)16uLL)
# define Rte_Ev_Run_CddDownloadManager_CddDownloadManager_OnExitDcmProgrammingSession     ((EventMaskType)32uLL)
# define Rte_Ev_Run_CddHWRNXPRT1171Swdl_CddHwrSwdl_ProcessCddHwrAppVersion     ((EventMaskType)4194304uLL)
# define Rte_Ev_Run_CddHWRNXPRT1171Swdl_CddHwrSwdl_ProcessHwrHealthStatus     ((EventMaskType)8388608uLL)
# define Rte_Ev_Run_CddHWRNXPRT1171Swdl_CddHwrSwdl_SwUpdateOnEnter     ((EventMaskType)16777216uLL)
# define Rte_Ev_Run_CddHWRNXPRT1171_CddHwr_ProcessSwUpdateReq     ((EventMaskType)33554432uLL)
# define Rte_Ev_Run_CddHWRNXPRT1171_CddHwr_ProcessSwcDispCtrlModeReq     ((EventMaskType)67108864uLL)
# define Rte_Ev_Run_CddHeadUnitInterface_CddHUIf_ProcessButtonStatus     ((EventMaskType)4uLL)
# define Rte_Ev_Run_CddKnockout_CddKo_ProcessBem02Data     ((EventMaskType)8uLL)
# define Rte_Ev_Run_CddNvMManager_CddNvMMngr_ProcessCddDlMngrSystemVersion     ((EventMaskType)274877906944uLL)
# define Rte_Ev_Run_CddPanelHimaxHx8249B_CddPnl_ProcessSwcDispCtrolModeReq     ((EventMaskType)134217728uLL)
# define Rte_Ev_Run_CddSliderBackLightTiSN1903001_CddSldr_ProcessSwcDispCtrlModeReq     ((EventMaskType)268435456uLL)
# define Rte_Ev_Run_CddTouchCypressGen7_CddTouch_ModeReq     ((EventMaskType)536870912uLL)
# define Rte_Ev_Run_CddUart_CddUart_MainFunction     ((EventMaskType)8uLL)
# define Rte_Ev_Run_CddWakeupDetect_CddWUDet_ProcessBem02Data     ((EventMaskType)1073741824uLL)
# define Rte_Ev_Run_CddWakeupDetect_CddWUDet_ProcessSi01Data     ((EventMaskType)2147483648uLL)
# define Rte_Ev_Run_CddWakeupDetect_CddWUDet_ProcessZr01Data     ((EventMaskType)4294967296uLL)
# define Rte_Ev_Run_CpSaInteriorLightStateFront_RCtSaInteriorLightSwitchLight     ((EventMaskType)2uLL)
# define Rte_Ev_Run_ShA_Ivd_CurrentMode_PostRun     ((EventMaskType)32uLL)
# define Rte_Ev_Run_ShA_Ivd_CurrentMode_Run     ((EventMaskType)64uLL)
# define Rte_Ev_Run_ShA_Ivd_MainFunction     ((EventMaskType)8589934592uLL)
# define Rte_Ev_Run_SwcComHandlerRx_SwcComRx_ProcessWakeupReason     ((EventMaskType)17179869184uLL)
# define Rte_Ev_Run_SwcComHandlerTx_SwcComTx_OnEntryRxTxNorm     ((EventMaskType)64uLL)
# define Rte_Ev_Run_SwcComHandlerTx_SwcComTx_OnExitDefaultSession     ((EventMaskType)128uLL)
# define Rte_Ev_Run_SwcComHandlerTx_SwcComTx_OnExitRxTxNorm     ((EventMaskType)256uLL)
# define Rte_Ev_Run_SwcComHandlerTx_SwcComTx_ProcessKs01Msg     ((EventMaskType)34359738368uLL)
# define Rte_Ev_Run_SwcComHandlerTx_SwcComTx_ProcessWakeupReason     ((EventMaskType)16uLL)
# define Rte_Ev_Run_SwcDimming_SwcDim_ProcessDeratingLimit     ((EventMaskType)68719476736uLL)
# define Rte_Ev_Run_SwcDimming_SwcDim_ProcessDim01Data     ((EventMaskType)137438953472uLL)
# define Rte_Ev_Run_SwcDisplayControl_SwcDispCtrl_OnEnterDefaultSession     ((EventMaskType)512uLL)
# define Rte_Ev_Run_SwcDisplayControl_SwcDispCtrl_OnEnterSldrBacklightEnabled     ((EventMaskType)274877906944uLL)
# define Rte_Ev_Run_SwcDisplayControl_SwcDispCtrl_OnExitSldrBacklightEnabled     ((EventMaskType)549755813888uLL)
# define Rte_Ev_Run_SwcDisplayControl_SwcDispCtrl_ProcessBist     ((EventMaskType)32uLL)
# define Rte_Ev_Run_SwcDisplayControl_SwcDispCtrl_ProcessDim01Data     ((EventMaskType)1099511627776uLL)
# define Rte_Ev_Run_SwcDisplayControl_SwcDispCtrl_ProcessZr01Data     ((EventMaskType)2199023255552uLL)
# define Rte_Ev_Run_SwcDisplayInfo_SwcDispInfo_ProcessSteeringWheelPos     ((EventMaskType)4398046511104uLL)
# define Rte_Ev_Run_SwcError_SwcError_OnEntryDcmDefaultSession     ((EventMaskType)1024uLL)
# define Rte_Ev_Run_SwcHWR_SwcHWR_DeviceNotReady     ((EventMaskType)8796093022208uLL)
# define Rte_Ev_Run_SwcHWR_SwcHWR_DeviceReady     ((EventMaskType)17592186044416uLL)
# define Rte_Ev_Run_SwcHidKeys_SwcHidKeys_DeInit     ((EventMaskType)128uLL)
# define Rte_Ev_Run_SwcHidKeys_SwcHidKeys_ProcessButtonStatus     ((EventMaskType)16uLL)
# define Rte_Ev_Run_SwcIVD_AdaptionCodingOrDsdl2_Data     ((EventMaskType)35184372088832uLL)
# define Rte_Ev_Run_SwcIVD_AppData_Dsdl1_AdrRange     ((EventMaskType)70368744177664uLL)
# define Rte_Ev_Run_SwcIVD_AppData_Dsdl1_Data     ((EventMaskType)140737488355328uLL)
# define Rte_Ev_Run_SwcSelfDiagnostics_SwcSelfDiag_EvaluateBacklightTemp     ((EventMaskType)2uLL)
# define Rte_Ev_Run_SwcSelfDiagnostics_SwcSelfDiag_EvaluateBatteryVoltage     ((EventMaskType)4uLL)
# define Rte_Ev_Run_SwcSelfDiagnostics_SwcSelfDiag_EvaluateBlTempDeratingLimit     ((EventMaskType)8uLL)
# define Rte_Ev_Run_SwcSelfDiagnostics_SwcSelfDiag_UpdateRuntime     ((EventMaskType)16uLL)
# define Rte_Ev_Run_SwcTemperatureCorrection_SwcTempCor_ProcessBacklightTemp     ((EventMaskType)2uLL)
# define Rte_Ev_Run_SwcTouch_SwcTouch_ProcessDisplayDataLO     ((EventMaskType)32uLL)
# define Rte_Ev_Run_SwcTouch_SwcTouch_ProcessSliderData     ((EventMaskType)64uLL)

/* Software counter timing macros */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Cfg.h
 *********************************************************************************************************************/

