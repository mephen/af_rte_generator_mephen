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

component_file = os.path.join(os.path.dirname(__file__), 'swc', 'tpc_controller2_component.arxml')

TPC_Composition_ARPackage= autosarfactory.new_file(component_file, defaultArPackage = 'TPC_Composition', overWrite = 'true')
Components_ARPackage = TPC_Composition_ARPackage.new_ARPackage('Components')

SWC_Controller2 = Components_ARPackage.new_ApplicationSwComponentType('Controller2')
PpIfVehAcc2 = SWC_Controller2.new_PPortPrototype('PpIfVehAcc2')
PpIfVehAcc2.set_providedInterface(SR_If1)
PpIfVehAcc2_Nq_Scomspec = PpIfVehAcc2.new_NonqueuedSenderComSpec()
PpIfVehAcc2_Nq_Scomspec.set_dataElement(SR_If1_DE_Acc)
num_value_sepc = PpIfVehAcc2_Nq_Scomspec.new_NumericalValueSpecification()
num_value_sepc.set_shortLabel('DefaultInitValue_Uint8')
num_value_sepc_value = num_value_sepc.new_Value()
num_value_sepc_value.set(777)

PpIfVehSpd2 = SWC_Controller2.new_PPortPrototype('PpIfVehSpd2')
PpIfVehSpd2.set_providedInterface(SR_If1)
PpIfVehSpd2_Nq_Scomspec = PpIfVehSpd2.new_NonqueuedSenderComSpec()
PpIfVehSpd2_Nq_Scomspec.set_dataElement(SR_If1_DE_Spd)
num_value_sepc = PpIfVehSpd2_Nq_Scomspec.new_NumericalValueSpecification()
num_value_sepc.set_shortLabel('DefaultInitValue_Uint8')
num_value_sepc_value = num_value_sepc.new_Value()
num_value_sepc_value.set(666)

PpIfTemperature2 = SWC_Controller2.new_PPortPrototype('PpIfTemperature2')
PpIfTemperature2.set_providedInterface(SR_If2)
PpIfTemperature2_Q_Rcomspec = PpIfTemperature2.new_QueuedSenderComSpec()
PpIfTemperature2_Q_Rcomspec.set_dataElement(SR_If2_DE_Temp)
# num_value_sepc = PpIfTemperature2_Q_Rcomspec.new_NumericalValueSpecification()
# num_value_sepc.set_shortLabel('DefaultInitValue_Uint8')
# num_value_sepc_value = num_value_sepc.new_Value()
# num_value_sepc_value.set(555)

SWC_Controller2_IntBehav = SWC_Controller2.new_InternalBehavior('SWC_Controller2_InternalBehavior')
SWC_Controller2_IntBehav.set_supportsMultipleInstantiation(True)
SWC_Controller2_IntBehav_ReTxTemp2 = SWC_Controller2_IntBehav.new_Runnable('ReTxTemp2')
ReTxTemp2_DSP = SWC_Controller2_IntBehav_ReTxTemp2.new_DataWriteAcces('DataSendPoint_PpIfTemperature2_Temp')
ReTxTemp2_DSP.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReTxTemp2_DSP_AV = ReTxTemp2_DSP.new_AccessedVariable()
ReTxTemp2_DSP_AV_AV = ReTxTemp2_DSP_AV.new_AutosarVariable()
ReTxTemp2_DSP_AV_AV.set_portPrototype(PpIfTemperature2)
ReTxTemp2_DSP_AV_AV.set_targetDataPrototype(SR_If2_DE_Temp)

EvTiTemp_20ms = SWC_Controller2_IntBehav.new_TimingEvent('EvTiTemp_20ms')
EvTiTemp_20ms.set_startOnEvent(SWC_Controller2_IntBehav_ReTxTemp2)
EvTiTemp_20ms.set_period('0.02')

SWC_Controller2_IntBehav_ReTxSpd2 = SWC_Controller2_IntBehav.new_Runnable('ReTxSpd2')
ReTxSpd2_DSP = SWC_Controller2_IntBehav_ReTxSpd2.new_DataWriteAcces('DataSendPoint_PpIfVehMov_Spd')
ReTxSpd2_DSP.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReTxSpd2_DSP_AV = ReTxSpd2_DSP.new_AccessedVariable()
ReTxSpd2_DSP_AV_AV = ReTxSpd2_DSP_AV.new_AutosarVariable()
ReTxSpd2_DSP_AV_AV.set_portPrototype(PpIfVehSpd2)
ReTxSpd2_DSP_AV_AV.set_targetDataPrototype(SR_If1_DE_Spd)


EvTiSpd_20ms = SWC_Controller2_IntBehav.new_TimingEvent('EvTiSpd_20ms')
EvTiSpd_20ms.set_startOnEvent(SWC_Controller2_IntBehav_ReTxSpd2)
EvTiSpd_20ms.set_period('0.02')

SWC_Controller2_IntBehav_ReTxAcc2 = SWC_Controller2_IntBehav.new_Runnable('ReTxAcc2')
ReTxAcc2_DSP = SWC_Controller2_IntBehav_ReTxAcc2.new_DataWriteAcces('DataSendPoint_PpIfVehMov_Acc')
ReTxAcc2_DSP.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReTxAcc2_DSP_AV = ReTxAcc2_DSP.new_AccessedVariable()
ReTxAcc2_DSP_AV_AV = ReTxAcc2_DSP_AV.new_AutosarVariable()
ReTxAcc2_DSP_AV_AV.set_portPrototype(PpIfVehAcc2)
ReTxAcc2_DSP_AV_AV.set_targetDataPrototype(SR_If1_DE_Acc)

EvTiAcc_20ms = SWC_Controller2_IntBehav.new_TimingEvent('EvTiAcc_20ms')
EvTiAcc_20ms.set_startOnEvent(SWC_Controller2_IntBehav_ReTxAcc2)
EvTiAcc_20ms.set_period('0.02')

portAPIOption =SWC_Controller2_IntBehav.new_PortAPIOption('PortAPIOption_PpIfVehAcc2')
portAPIOption.set_port(PpIfVehAcc2)
portAPIOption.set_transformerStatusForwarding(DataTransformationStatusForwardingEnum.VALUE_TRANSFORMER_STATUS_FORWARDING)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING)

portAPIOption =SWC_Controller2_IntBehav.new_PortAPIOption('PortAPIOption_PpIfTemperature2')
portAPIOption.set_port(PpIfTemperature2)
portAPIOption.set_errorHandling(DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING)

autosarfactory.save()
