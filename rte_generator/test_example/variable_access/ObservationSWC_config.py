import os, sys
import pdb
from autosarfactory import autosarfactory

from autosarfactory.autosarfactory import DataTransformationErrorHandlingEnum\
    , DataTransformationStatusForwardingEnum, RteApiReturnValueProvisionEnum\
   
from TPCComposition_PortInterface_config import SR_If1, SR_If1_DE_Acc, SR_If1_DE_Spd
from TPCComposition_PortInterface_config import SR_If2, SR_If2_DE_Temp 
 
component_file = os.path.join(os.path.dirname(__file__), 'swc', 'tpc_observation_component.arxml')

TPC_Composition_ARPackage= autosarfactory.new_file(component_file, defaultArPackage = 'TPC_Composition', overWrite = 'true')
Components_ARPackage = TPC_Composition_ARPackage.new_ARPackage('Components')

SWC_Observation = Components_ARPackage.new_ApplicationSwComponentType('Observation')
RpIfVehAcc = SWC_Observation.new_RPortPrototype('RpIfVehAcc')
RpIfVehAcc.set_requiredInterface(SR_If1)
RpIfVehAcc_Nq_Rcomspec = RpIfVehAcc.new_NonqueuedReceiverComSpec()
RpIfVehAcc_Nq_Rcomspec.set_dataElement(SR_If1_DE_Acc)
num_value_sepc = RpIfVehAcc_Nq_Rcomspec.new_NumericalValueSpecification()
num_value_sepc.set_shortLabel('DefaultInitValue_Uint16')
num_value_sepc_value = num_value_sepc.new_Value()
num_value_sepc_value.set(111)

RpIfVehSpd = SWC_Observation.new_RPortPrototype('RpIfVehSpd')
RpIfVehSpd.set_requiredInterface(SR_If1)
RpIfVehSpd_Nq_Rcomspec = RpIfVehSpd.new_NonqueuedReceiverComSpec()
RpIfVehSpd_Nq_Rcomspec.set_dataElement(SR_If1_DE_Spd)
num_value_sepc = RpIfVehSpd_Nq_Rcomspec.new_NumericalValueSpecification()
num_value_sepc.set_shortLabel('DefaultInitValue_Uint16')
num_value_sepc_value = num_value_sepc.new_Value()
num_value_sepc_value.set(333)

RpIfTemperature = SWC_Observation.new_RPortPrototype('RpIfTemperature')
RpIfTemperature.set_requiredInterface(SR_If2)
RpIfTemperature_Nq_Rcomspec = RpIfTemperature.new_QueuedReceiverComSpec()
RpIfTemperature_Nq_Rcomspec.set_dataElement(SR_If2_DE_Temp)
RpIfTemperature_Nq_Rcomspec.set_queueLength(10)
SR_If2_DE_Temp_ReceptionProps = RpIfTemperature_Nq_Rcomspec.new_ReceptionProps('SR_If2_DE_Temp_ReceptionProps')
SR_If2_DE_Temp_ReceptionProps.set_timeout(0.01)
# num_value_sepc = RpIfTemperature_Nq_Rcomspec.new_NumericalValueSpecification()
# num_value_sepc.set_shortLabel('DefaultInitValue_Uint16')
# num_value_sepc_value = num_value_sepc.new_Value()
# num_value_sepc_value.set(555)

SWC_Observation_IntBehav = SWC_Observation.new_InternalBehavior('SWC_Observation_InternalBehavior')
# SWC_Observation_IntBehav.set_supportsMultipleInstantiation(True)
SWC_Observation_IntBehav_ReRxAcc = SWC_Observation_IntBehav.new_Runnable('ReRxAcc')
SWC_Observation_IntBehav_ReRxAcc.set_symbol('ReRxAcc')
ReRxAcc_DSP = SWC_Observation_IntBehav_ReRxAcc.new_DataReceivePointByArgument('DataReceivePointByArgument_PpIfVehMov_Acc')
ReRxAcc_DSP.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReRxAcc_DSP_AV = ReRxAcc_DSP.new_AccessedVariable()
ReRxAcc_DSP_AV_AV = ReRxAcc_DSP_AV.new_AutosarVariable()
ReRxAcc_DSP_AV_AV.set_portPrototype(RpIfVehAcc)
ReRxAcc_DSP_AV_AV.set_targetDataPrototype(SR_If1_DE_Acc)
EvTiAcc_20ms = SWC_Observation_IntBehav.new_TimingEvent('EvTiAcc_20ms')
EvTiAcc_20ms.set_startOnEvent(SWC_Observation_IntBehav_ReRxAcc)
EvTiAcc_20ms.set_period('0.02')

SWC_Observation_IntBehav_ReRxSpd = SWC_Observation_IntBehav.new_Runnable('ReRxSpd')
SWC_Observation_IntBehav_ReRxSpd.set_symbol('ReRxSpd')
ReRxSpd_DSP = SWC_Observation_IntBehav_ReRxSpd.new_DataReceivePointByValue('DataReceivePointByValue_PpIfVehMov_Spd')
ReRxSpd_DSP_AV = ReRxSpd_DSP.new_AccessedVariable()
ReRxSpd_DSP_AV_AV = ReRxSpd_DSP_AV.new_AutosarVariable()
ReRxSpd_DSP_AV_AV.set_portPrototype(RpIfVehSpd)
ReRxSpd_DSP_AV_AV.set_targetDataPrototype(SR_If1_DE_Spd)
EvTiSpd_20ms = SWC_Observation_IntBehav.new_TimingEvent('EvTiSpd_20ms')
EvTiSpd_20ms.set_startOnEvent(SWC_Observation_IntBehav_ReRxSpd)
EvTiSpd_20ms.set_period('0.02')

SWC_Observation_IntBehav_ReRxTemp = SWC_Observation_IntBehav.new_Runnable('ReRxTemp')
SWC_Observation_IntBehav_ReRxTemp.set_symbol('ReRxTemp')
ReRxTemp_DSP = SWC_Observation_IntBehav_ReRxTemp.new_DataReceivePointByArgument('DataReceivePointByValue_PpIfTemperature_Temp')
ReRxTemp_DSP.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReRxTemp_DSP_AV = ReRxTemp_DSP.new_AccessedVariable()
ReRxTemp_DSP_AV_AV = ReRxTemp_DSP_AV.new_AutosarVariable()
ReRxTemp_DSP_AV_AV.set_portPrototype(RpIfTemperature)
ReRxTemp_DSP_AV_AV.set_targetDataPrototype(SR_If2_DE_Temp)
# EvTiTemp_20ms = SWC_Observation_IntBehav.new_TimingEvent('EvTiTemp_20ms')
# EvTiTemp_20ms.set_startOnEvent(ReRxTemp)
# EvTiTemp_20ms.set_period('0.02')

Obv_Ev_DR = SWC_Observation_IntBehav.new_DataReceivedEvent('Obv_Ev_DR')
Obv_Ev_DR_Aces_DataElement= Obv_Ev_DR.new_Data('Obv_Ev_DR_Aces_DataElement')
Obv_Ev_DR_Aces_DataElement.set_contextRPort(RpIfTemperature)
Obv_Ev_DR_Aces_DataElement.set_targetDataElement(SR_If2_DE_Temp)

ReRxTemp_WP = SWC_Observation_IntBehav_ReRxTemp.new_WaitPoint('ReRxTemp_WaitPoint')
ReRxTemp_WP.set_trigger(Obv_Ev_DR)

# SWS_Rte_01313
# Obv_Ev_DR.set_startOnEvent(SWC_Observation_IntBehav_ReRxTemp)

portAPIOption =SWC_Observation_IntBehav.new_PortAPIOption('PortAPIOption_RpIfVehAcc')
portAPIOption.set_port(RpIfVehAcc)
portAPIOption.set_transformerStatusForwarding(DataTransformationStatusForwardingEnum.VALUE_TRANSFORMER_STATUS_FORWARDING)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING)

portAPIOption =SWC_Observation_IntBehav.new_PortAPIOption('PortAPIOption_RpIfVehSpd')
portAPIOption.set_port(RpIfVehSpd)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_NO_TRANSFORMER_ERROR_HANDLING)

portAPIOption =SWC_Observation_IntBehav.new_PortAPIOption('PortAPIOption_PpIfTemperature')
portAPIOption.set_port(RpIfTemperature)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING)

autosarfactory.save()
