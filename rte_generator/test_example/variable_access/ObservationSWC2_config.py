import os, sys
import pdb
from autosarfactory import autosarfactory

from autosarfactory.autosarfactory import DataTransformationErrorHandlingEnum\
    , DataTransformationStatusForwardingEnum, RteApiReturnValueProvisionEnum\
    
component_file = os.path.join(os.path.dirname(__file__), 'swc', 'tpc_observation2_component.arxml')

from TPCComposition_PortInterface_config import SR_If1, SR_If1_DE_Acc, SR_If1_DE_Spd
from TPCComposition_PortInterface_config import SR_If2, SR_If2_DE_Temp 

TPC_Composition_ARPackage= autosarfactory.new_file(component_file, defaultArPackage = 'TPC_Composition', overWrite = 'true')
Components_ARPackage = TPC_Composition_ARPackage.new_ARPackage('Components')

SWC_Observation2 = Components_ARPackage.new_ApplicationSwComponentType('Observation2')
RpIfVehAcc2 = SWC_Observation2.new_RPortPrototype('RpIfVehAcc2')
RpIfVehAcc2.set_requiredInterface(SR_If1)
RpIfVehAcc2_Nq_Rcomspec = RpIfVehAcc2.new_NonqueuedReceiverComSpec()
RpIfVehAcc2_Nq_Rcomspec.set_dataElement(SR_If1_DE_Acc)
num_value_sepc = RpIfVehAcc2_Nq_Rcomspec.new_NumericalValueSpecification()
num_value_sepc.set_shortLabel('DefaultInitValue_Uint16')
num_value_sepc_value = num_value_sepc.new_Value()
num_value_sepc_value.set(222)

RpIfVehSpd2 = SWC_Observation2.new_RPortPrototype('RpIfVehSpd2')
RpIfVehSpd2.set_requiredInterface(SR_If1)
RpIfVehSpd2_Nq_Rcomspec = RpIfVehSpd2.new_NonqueuedReceiverComSpec()
RpIfVehSpd2_Nq_Rcomspec.set_dataElement(SR_If1_DE_Spd)
num_value_sepc = RpIfVehSpd2_Nq_Rcomspec.new_NumericalValueSpecification()
num_value_sepc.set_shortLabel('DefaultInitValue_Uint16')
num_value_sepc_value = num_value_sepc.new_Value()
num_value_sepc_value.set(444)

RpIfTemperature2 = SWC_Observation2.new_RPortPrototype('RpIfTemperature2')
RpIfTemperature2.set_requiredInterface(SR_If2)
RpIfTemperature2_Nq_Rcomspec = RpIfTemperature2.new_QueuedReceiverComSpec()
RpIfTemperature2_Nq_Rcomspec.set_dataElement(SR_If2_DE_Temp)
RpIfTemperature2_Nq_Rcomspec.set_queueLength(10)
# num_value_sepc = RpIfTemperature2_Nq_Rcomspec.new_NumericalValueSpecification()
# num_value_sepc.set_shortLabel('DefaultInitValue_Uint16')
# num_value_sepc_value = num_value_sepc.new_Value()
# num_value_sepc_value.set(555)

SWC_Observation2_IntBehav = SWC_Observation2.new_InternalBehavior('SWC_Observation2_InternalBehavior')
# SWC_Observation2_IntBehav.set_supportsMultipleInstantiation(True)
SWC_Observation2_IntBehav_ReRxAcc = SWC_Observation2_IntBehav.new_Runnable('ReRxAcc2')
SWC_Observation2_IntBehav_ReRxAcc.set_symbol('ReRxAcc2')
ReRxAcc_DSP = SWC_Observation2_IntBehav_ReRxAcc.new_DataReadAcces('DataReceivePointByArgument_PpIfVehMov_Acci')
ReRxAcc_DSP.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReRxAcc_DSP_AV = ReRxAcc_DSP.new_AccessedVariable()
ReRxAcc_DSP_AV_AV = ReRxAcc_DSP_AV.new_AutosarVariable()
ReRxAcc_DSP_AV_AV.set_portPrototype(RpIfVehAcc2)
ReRxAcc_DSP_AV_AV.set_targetDataPrototype(SR_If1_DE_Acc)
EvTiAcc_20ms = SWC_Observation2_IntBehav.new_TimingEvent('EvTiAcc_20ms')
EvTiAcc_20ms.set_startOnEvent(SWC_Observation2_IntBehav_ReRxAcc)
EvTiAcc_20ms.set_period('0.02')

SWC_Observation2_IntBehav_ReRxSpd = SWC_Observation2_IntBehav.new_Runnable('ReRxSpd2')
SWC_Observation2_IntBehav_ReRxSpd.set_symbol('ReRxSpd2')
ReRxSpd_DSP = SWC_Observation2_IntBehav_ReRxSpd.new_DataReadAcces('DataReceivePointByArgument_PpIfVehMov_Spd')
ReRxSpd_DSP_AV = ReRxSpd_DSP.new_AccessedVariable()
ReRxSpd_DSP_AV_AV = ReRxSpd_DSP_AV.new_AutosarVariable()
ReRxSpd_DSP_AV_AV.set_portPrototype(RpIfVehSpd2)
ReRxSpd_DSP_AV_AV.set_targetDataPrototype(SR_If1_DE_Spd)
EvTiSpd_20ms = SWC_Observation2_IntBehav.new_TimingEvent('EvTiSpd_20ms')
EvTiSpd_20ms.set_startOnEvent(SWC_Observation2_IntBehav_ReRxSpd)
EvTiSpd_20ms.set_period('0.02')

SWC_Observation2_IntBehav_ReRxTemp = SWC_Observation2_IntBehav.new_Runnable('ReRxTemp2')
SWC_Observation2_IntBehav_ReRxTemp.set_symbol('ReRxTemp2')
ReRxTemp_DSP = SWC_Observation2_IntBehav_ReRxTemp.new_DataReadAcces('DataReceivePointByArgument_PpIfTemperature_Temp')
ReRxTemp_DSP_AV = ReRxTemp_DSP.new_AccessedVariable()
ReRxTemp_DSP_AV_AV = ReRxTemp_DSP_AV.new_AutosarVariable()
ReRxTemp_DSP_AV_AV.set_portPrototype(RpIfTemperature2)
ReRxTemp_DSP_AV_AV.set_targetDataPrototype(SR_If2_DE_Temp)
# EvTiTemp_20ms = SWC_Observation2_IntBehav.new_TimingEvent('EvTiTemp_20ms')
# EvTiTemp_20ms.set_startOnEvent(ReRxTemp)
# EvTiTemp_20ms.set_period('0.02')

Obv_Ev_DR = SWC_Observation2_IntBehav.new_DataReceivedEvent('Obv_Ev_DR')
Obv_Ev_DR_Aces_DataElement= Obv_Ev_DR.new_Data('Obv_Ev_DR_Aces_DataElement')
Obv_Ev_DR_Aces_DataElement.set_contextRPort(RpIfTemperature2)
Obv_Ev_DR_Aces_DataElement.set_targetDataElement(SR_If2_DE_Temp)

ReRxTemp_WP = SWC_Observation2_IntBehav_ReRxTemp.new_WaitPoint('ReRxTemp_WaitPoint')
ReRxTemp_WP.set_trigger(Obv_Ev_DR)

# Obv_Ev_DR.set_startOnEvent(SWC_Controller_IntBehav_ReTxTemp)

portAPIOption =SWC_Observation2_IntBehav.new_PortAPIOption('PortAPIOption_RpIfVehAcc2')
portAPIOption.set_port(RpIfVehAcc2)
portAPIOption.set_transformerStatusForwarding(DataTransformationStatusForwardingEnum.VALUE_TRANSFORMER_STATUS_FORWARDING)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING)

portAPIOption =SWC_Observation2_IntBehav.new_PortAPIOption('PortAPIOption_RpIfVehSpd2')
portAPIOption.set_port(RpIfVehSpd2)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING)

portAPIOption =SWC_Observation2_IntBehav.new_PortAPIOption('PortAPIOption_RpIfTemperature2')
portAPIOption.set_port(RpIfTemperature2)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING)

autosarfactory.save()
