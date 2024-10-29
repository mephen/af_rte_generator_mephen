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
from autosarfactory.autosarfactory import SwImplPolicyEnum ,SwCalibrationAccessEnum\
    , HandleInvalidEnum, DataTransformationErrorHandlingEnum\
    , DataTransformationStatusForwardingEnum, RteApiReturnValueProvisionEnum\
        
"""
上面的導入語句將直接導入 "autosarfactory.autosarfactory" 模塊中的特定元素。
在這種情況下，你可以直接使用 "SwImplPolicyEnum"，而無需前綴 "autosarfactory."。

如果沒有上面的 導入語句 就是需要寫成 autosarfactory.SwImplPolicyEnum
"""
from TPCComposition_DataType_config import App_uint8, Impl_float64, App_uint16

component_file = os.path.join(os.path.dirname(__file__), 'swc', 'tpc_controller3_component.arxml')

TPC_Composition_ARPackage= autosarfactory.new_file(component_file, defaultArPackage = 'TPC_Composition', overWrite = 'true')
Components_ARPackage = TPC_Composition_ARPackage.new_ARPackage('Components')

SWC_Controller3 = Components_ARPackage.new_ApplicationSwComponentType('Controller3')
SWC_Controller3_IntBehav = SWC_Controller3.new_InternalBehavior('SWC_Controller3_InternalBehavior')
SWC_Controller3_IntBehav.set_supportsMultipleInstantiation(True)

Local_DE_Temp = SWC_Controller3_IntBehav.new_ExplicitInterRunnableVariable('Local_DE_Temp')
# Local_DE_Temp = SWC_Controller3_IntBehav.new_ImplicitInterRunnableVariable('Local_DE_Temp')
Local_DE_Temp.set_category('VALUE')
Local_DE_Temp.set_type(Impl_float64)
Local_DE_Temp_SwDDP = Local_DE_Temp.new_SwDataDefProps()
Local_DE_Temp_SwDDP_Variant1 = Local_DE_Temp_SwDDP.new_SwDataDefPropsVariant()
Local_DE_Temp_SwDDP_Variant1.set_swImplPolicy(SwImplPolicyEnum.VALUE_QUEUED)
Local_DE_Temp_SwDDP_Variant1.set_swCalibrationAccess(SwCalibrationAccessEnum.VALUE_READ_ONLY)

SWC_Controller3_IntBehav_ReTxTemp = SWC_Controller3_IntBehav.new_Runnable('ReTxTemp')
ReTxTemp_WLV = SWC_Controller3_IntBehav_ReTxTemp.new_WrittenLocalVariable('WrittenLocalVariable_Temp')
ReTxTemp_WLV.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReTxTemp_WLV_AV = ReTxTemp_WLV.new_AccessedVariable()
ReTxTemp_WLV_AV.set_localVariable(Local_DE_Temp)

EvTiTxTemp_20ms = SWC_Controller3_IntBehav.new_TimingEvent('EvTiTxTemp_20ms')
EvTiTxTemp_20ms.set_startOnEvent(SWC_Controller3_IntBehav_ReTxTemp)
EvTiTxTemp_20ms.set_period('0.02')

SWC_Controller3_IntBehav_ReRxTemp = SWC_Controller3_IntBehav.new_Runnable('ReRxTemp')
ReRxTemp_RLV = SWC_Controller3_IntBehav_ReRxTemp.new_ReadLocalVariable('ReadLocalVariable_Temp')
ReRxTemp_RLV_AV = ReRxTemp_RLV.new_AccessedVariable()
ReRxTemp_RLV_AV.set_localVariable(Local_DE_Temp)

EvTiRxTemp_20ms = SWC_Controller3_IntBehav.new_TimingEvent('EvTiRxTemp_20ms')
EvTiRxTemp_20ms.set_startOnEvent(SWC_Controller3_IntBehav_ReRxTemp)
EvTiRxTemp_20ms.set_period('0.02')

Local_DE_Spd = SWC_Controller3_IntBehav.new_ExplicitInterRunnableVariable('Local_DE_Spd')
# Local_DE_Spd = SWC_Controller3_IntBehav.new_ImplicitInterRunnableVariable('Local_DE_Spd')
Local_DE_Spd.set_category('VALUE')
Local_DE_Spd.set_type(App_uint16)
Local_DE_Spd_SwDDP = Local_DE_Spd.new_SwDataDefProps()
Local_DE_Spd_SwDDP_Variant1 = Local_DE_Spd_SwDDP.new_SwDataDefPropsVariant()
Local_DE_Spd_SwDDP_Variant1.set_swImplPolicy(SwImplPolicyEnum.VALUE_STANDARD)
Local_DE_Spd_SwDDP_Variant1.set_swCalibrationAccess(SwCalibrationAccessEnum.VALUE_READ_ONLY)
swDefProps_num_value_sepc = Local_DE_Spd_SwDDP_Variant1.new_NumericalValueSpecification()
swDefProps_num_value_sepc.set_shortLabel('DefaultInvalidValue_Local_DE_Spd')
swDefProps_num_value_sepc_value = swDefProps_num_value_sepc.new_Value()
swDefProps_num_value_sepc_value.set(392)

SWC_Controller3_IntBehav_ReTxSpd = SWC_Controller3_IntBehav.new_Runnable('ReTxSpd')
ReTxSpd_WLV = SWC_Controller3_IntBehav_ReTxSpd.new_WrittenLocalVariable('WrittenLocalVariable_Spd')
ReTxSpd_WLV.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReTxSpd_WLV_AV = ReTxSpd_WLV.new_AccessedVariable()
ReTxSpd_WLV_AV.set_localVariable(Local_DE_Spd)

EvTiTxSpd_20ms = SWC_Controller3_IntBehav.new_TimingEvent('EvTiTxSpd_20ms')
EvTiTxSpd_20ms.set_startOnEvent(SWC_Controller3_IntBehav_ReTxSpd)
EvTiTxSpd_20ms.set_period('0.02')

SWC_Controller3_IntBehav_ReRxSpd = SWC_Controller3_IntBehav.new_Runnable('ReRxSpd')
ReRxSpd_RLV = SWC_Controller3_IntBehav_ReRxSpd.new_ReadLocalVariable('ReadLocalVariable_Spd')
ReRxSpd_RLV_AV = ReRxSpd_RLV.new_AccessedVariable()
ReRxSpd_RLV_AV.set_localVariable(Local_DE_Spd)

EvTiRxSpd_20ms = SWC_Controller3_IntBehav.new_TimingEvent('EvTiRxSpd_20ms')
EvTiRxSpd_20ms.set_startOnEvent(SWC_Controller3_IntBehav_ReRxSpd)
EvTiRxSpd_20ms.set_period('0.02')

Local_DE_Acc = SWC_Controller3_IntBehav.new_ExplicitInterRunnableVariable('Local_DE_Acc')
# Local_DE_Acc = SWC_Controller3_IntBehav.new_ImplicitInterRunnableVariable('Local_DE_Acc')
Local_DE_Acc.set_category('VALUE')
Local_DE_Acc.set_type(App_uint16)
Local_DE_Acc_SwDDP = Local_DE_Acc.new_SwDataDefProps()
Local_DE_Acc_SwDDP_Variant1 = Local_DE_Acc_SwDDP.new_SwDataDefPropsVariant()
Local_DE_Acc_SwDDP_Variant1.set_swImplPolicy(SwImplPolicyEnum.VALUE_STANDARD)
Local_DE_Acc_SwDDP_Variant1.set_swCalibrationAccess(SwCalibrationAccessEnum.VALUE_READ_ONLY)
swDefProps_num_value_sepc = Local_DE_Acc_SwDDP_Variant1.new_NumericalValueSpecification()
swDefProps_num_value_sepc.set_shortLabel('DefaultInvalidValue_Local_DE_Acc')
swDefProps_num_value_sepc_value = swDefProps_num_value_sepc.new_Value()
swDefProps_num_value_sepc_value.set(392)

SWC_Controller3_IntBehav_ReTxAcc = SWC_Controller3_IntBehav.new_Runnable('ReTxAcc')
ReTxAcc_WLV = SWC_Controller3_IntBehav_ReTxAcc.new_WrittenLocalVariable('ReadLocalVariable_PpIfVehMov_Acc')
ReTxAcc_WLV.set_returnValueProvision(RteApiReturnValueProvisionEnum.VALUE_RETURN_VALUE_PROVIDED)
ReTxAcc_WLV_AV = ReTxAcc_WLV.new_AccessedVariable()
ReTxAcc_WLV_AV.set_localVariable(Local_DE_Acc)

EvTiTxAcc_20ms = SWC_Controller3_IntBehav.new_TimingEvent('EvTiTxAcc_20ms')
EvTiTxAcc_20ms.set_startOnEvent(SWC_Controller3_IntBehav_ReTxAcc)
EvTiTxAcc_20ms.set_period('0.02')

SWC_Controller3_IntBehav_ReRxAcc = SWC_Controller3_IntBehav.new_Runnable('ReRxAcc')
ReRxAcc_RLV = SWC_Controller3_IntBehav_ReRxAcc.new_ReadLocalVariable('ReadLocalVariable_PpIfVehMov_Acc')
ReRxAcc_RLV_AV = ReRxAcc_RLV.new_AccessedVariable()
ReRxAcc_RLV_AV.set_localVariable(Local_DE_Acc)

EvTiRxAcc_20ms = SWC_Controller3_IntBehav.new_TimingEvent('EvTiRxAcc_20ms')
EvTiRxAcc_20ms.set_startOnEvent(SWC_Controller3_IntBehav_ReRxAcc)
EvTiRxAcc_20ms.set_period('0.02')

autosarfactory.save()
