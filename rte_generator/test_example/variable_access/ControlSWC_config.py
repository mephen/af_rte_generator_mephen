import os, sys
import pdb
from autosarfactory import autosarfactory
"""
導入 autosarfactory 包中的 autosarfactory 模塊，
而不是頂層的 autosarfactory 包。

這是因為 autosarfactory 檔案結構為這樣
autosarfactory/  <- folder
|-- __init__.py
|-- autosarfactory.py  <- target
|-- other_module.py
"""

"""
如果是寫入 import autosarfactory
則 new_file 要這樣寫 autosarfactory.autosarfactory.new_file

from autosarfactory import autosarfactory
上面的導入語句將導入名為 "autosarfactory" 的模塊，
該模塊可能是 "autosarfactory" 包中的一個模塊，或者是根級別(root level)的模塊。
在這種情況下，如果你想使用 "SwImplPolicyEnum"，需要使用
autosarfactory.SwImplPolicyEnum 的形式來訪問它。
"""
from autosarfactory.autosarfactory import DataTransformationErrorHandlingEnum\
    , DataTransformationStatusForwardingEnum, RteApiReturnValueProvisionEnum\
        
"""
上面的導入語句將直接導入 "autosarfactory.autosarfactory" 模塊中的特定元素。
在這種情況下，你可以直接使用 "SwImplPolicyEnum"，而無需前綴 "autosarfactory."。

如果沒有上面的 導入語句 就是需要寫成 autosarfactory.SwImplPolicyEnum
"""
from TPCComposition_PortInterface_config import SR_If1, SR_If1_DE_Acc, SR_If1_DE_Spd
from TPCComposition_PortInterface_config import SR_If2, SR_If2_DE_Temp 

component_file = os.path.join(os.path.dirname(__file__), 'swc', 'tpc_controller_component.arxml')

TPC_Composition_ARPackage= autosarfactory.new_file(component_file, defaultArPackage = 'TPC_Composition', overWrite = 'true')
Components_ARPackage = TPC_Composition_ARPackage.new_ARPackage('Components')

SWC_Controller = Components_ARPackage.new_ApplicationSwComponentType('Controller')
PpIfVehAcc = SWC_Controller.new_PPortPrototype('PpIfVehAcc')
PpIfVehAcc.set_providedInterface(SR_If1)
PpIfVehAcc_Nq_Scomspec = PpIfVehAcc.new_NonqueuedSenderComSpec()
PpIfVehAcc_Nq_Scomspec.set_dataElement(SR_If1_DE_Acc)
num_value_sepc = PpIfVehAcc_Nq_Scomspec.new_NumericalValueSpecification()
num_value_sepc.set_shortLabel('DefaultInitValue_Uint8')
num_value_sepc_value = num_value_sepc.new_Value()
num_value_sepc_value.set(777)

PpIfVehSpd = SWC_Controller.new_PPortPrototype('PpIfVehSpd')
PpIfVehSpd.set_providedInterface(SR_If1)
PpIfVehSpd_Nq_Scomspec = PpIfVehSpd.new_NonqueuedSenderComSpec()
PpIfVehSpd_Nq_Scomspec.set_dataElement(SR_If1_DE_Spd)
num_value_sepc = PpIfVehSpd_Nq_Scomspec.new_NumericalValueSpecification()
num_value_sepc.set_shortLabel('DefaultInitValue_Uint8')
num_value_sepc_value = num_value_sepc.new_Value()
num_value_sepc_value.set(666)

PpIfTemperature = SWC_Controller.new_PPortPrototype('PpIfTemperature')
PpIfTemperature.set_providedInterface(SR_If2)
PpIfTemperature_Q_Rcomspec = PpIfTemperature.new_QueuedSenderComSpec()
PpIfTemperature_Q_Rcomspec.set_dataElement(SR_If2_DE_Temp)
# num_value_sepc = PpIfTemperature_Q_Rcomspec.new_NumericalValueSpecification()
# num_value_sepc.set_shortLabel('DefaultInitValue_Uint8')
# num_value_sepc_value = num_value_sepc.new_Value()
# num_value_sepc_value.set(555)

SWC_Controller_IntBehav = SWC_Controller.new_InternalBehavior('SWC_Controller_InternalBehavior')
# SWC_Controller_IntBehav.set_supportsMultipleInstantiation(True)
SWC_Controller_IntBehav_ReTxTemp = SWC_Controller_IntBehav.new_Runnable('ReTxTemp')
SWC_Controller_IntBehav_ReTxTemp.set_symbol('ReTxTemp')
ReTxTemp_DSP = SWC_Controller_IntBehav_ReTxTemp.new_DataSendPoint('DataSendPoint_PpIfTemperature_Temp')
ReTxTemp_DSP.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReTxTemp_DSP_AV = ReTxTemp_DSP.new_AccessedVariable()
ReTxTemp_DSP_AV_AV = ReTxTemp_DSP_AV.new_AutosarVariable()
ReTxTemp_DSP_AV_AV.set_portPrototype(PpIfTemperature)
ReTxTemp_DSP_AV_AV.set_targetDataPrototype(SR_If2_DE_Temp)

EvTiTemp_20ms = SWC_Controller_IntBehav.new_TimingEvent('EvTiTemp_20ms')
EvTiTemp_20ms.set_startOnEvent(SWC_Controller_IntBehav_ReTxTemp)
EvTiTemp_20ms.set_period('0.02')

SWC_Controller_IntBehav_ReTxSpd = SWC_Controller_IntBehav.new_Runnable('ReTxSpd')
SWC_Controller_IntBehav_ReTxSpd.set_symbol('ReTxSpd')
ReTxSpd_DSP = SWC_Controller_IntBehav_ReTxSpd.new_DataSendPoint('DataSendPoint_PpIfVehMov_Spd')
ReTxSpd_DSP.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReTxSpd_DSP_AV = ReTxSpd_DSP.new_AccessedVariable()
ReTxSpd_DSP_AV_AV = ReTxSpd_DSP_AV.new_AutosarVariable()
ReTxSpd_DSP_AV_AV.set_portPrototype(PpIfVehSpd)
ReTxSpd_DSP_AV_AV.set_targetDataPrototype(SR_If1_DE_Spd)

EvTiSpd_20ms = SWC_Controller_IntBehav.new_TimingEvent('EvTiSpd_20ms')
EvTiSpd_20ms.set_startOnEvent(SWC_Controller_IntBehav_ReTxSpd)
EvTiSpd_20ms.set_period('0.02')

SWC_Controller_IntBehav_ReTxAcc = SWC_Controller_IntBehav.new_Runnable('ReTxAcc')
SWC_Controller_IntBehav_ReTxAcc.set_symbol('ReTxAcc')
ReTxAcc_DSP = SWC_Controller_IntBehav_ReTxAcc.new_DataSendPoint('DataSendPoint_PpIfVehMov_Acc')
ReTxAcc_DSP.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReTxAcc_DSP_AV = ReTxAcc_DSP.new_AccessedVariable()
ReTxAcc_DSP_AV_AV = ReTxAcc_DSP_AV.new_AutosarVariable()
ReTxAcc_DSP_AV_AV.set_portPrototype(PpIfVehAcc)
ReTxAcc_DSP_AV_AV.set_targetDataPrototype(SR_If1_DE_Acc)

EvTiAcc_20ms = SWC_Controller_IntBehav.new_TimingEvent('EvTiAcc_20ms')
EvTiAcc_20ms.set_startOnEvent(SWC_Controller_IntBehav_ReTxAcc)
EvTiAcc_20ms.set_period('0.02')

portAPIOption =SWC_Controller_IntBehav.new_PortAPIOption('PortAPIOption_PpIfVehAcc')
portAPIOption.set_port(PpIfVehAcc)
portAPIOption.set_transformerStatusForwarding(DataTransformationStatusForwardingEnum.VALUE_TRANSFORMER_STATUS_FORWARDING)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING)

portAPIOption =SWC_Controller_IntBehav.new_PortAPIOption('PortAPIOption_PpIfTemperature')
portAPIOption.set_port(PpIfTemperature)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING)


SWC_Controller_Implementation = Components_ARPackage.new_SwcImplementation('Controller_Implementation')
# SWC_Controller_CodeDescriptor = SWC_Controller_Implementation.new_CodeDescriptor('Code')
SWC_Controller_RequiredArtifact = SWC_Controller_Implementation.new_RequiredArtifact('source_implementation')
SWC_Controller_RequiredArtifact_ArtifactDescriptor = SWC_Controller_RequiredArtifact.new_ArtifactDescriptor()
SWC_Controller_RequiredArtifact_ArtifactDescriptor.set_shortLabel('Rte_Controller.c') 
SWC_Controller_RequiredArtifact_ArtifactDescriptor.set_category('SWSRC') 
SWC_Controller_RequiredArtifact_ArtifactDescriptor.set_domain('AUTOSAR') 
autosarfactory.save()
