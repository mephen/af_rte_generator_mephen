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
target_file = os.path.join(os.path.dirname(__file__), 'ecuc', 'ioc_ecuc_parameter.arxml')
ecuc_ARPackage= autosarfactory.new_file(target_file, defaultArPackage = 'EcuC', overWrite = 'true')
os_ECUCPara = ecuc_ARPackage.new_EcucModuleDef('Os')
# os_ECUCPara.set_lowerMultiplicity('0')
# os_ECUCPara.set_upperMultiplicity('1')

os_ioc_ECUCPara = os_ECUCPara.new_EcucParamConfContainerDef('OsIoc')
# os_ioc_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_ECUCPara.set_upperMultiplicity('1')

os_ioc_comm_ECUCPara = os_ioc_ECUCPara.new_EcucParamConfContainerDef('OsIocCommunication')
# os_ioc_comm_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_comm_ECUCPara.set_upperMultiplicity('*')
os_ioc_buffer_len_ECUCPara = os_ioc_comm_ECUCPara.new_EcucIntegerParamDef('OsIocBufferLength')
# os_ioc_buffer_len_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_buffer_len_ECUCPara.set_upperMultiplicity('1')

os_ioc_sdr_props_ECUCPara = os_ioc_comm_ECUCPara.new_EcucParamConfContainerDef('OsIocSenderProperties')
# os_ioc_sdr_props_ECUCPara.set_lowerMultiplicity('1')
# os_ioc_sdr_props_ECUCPara.set_upperMultiplicity('*')
os_ioc_sdr_id_ECUCPara = os_ioc_sdr_props_ECUCPara.new_EcucIntegerParamDef('OsIocSenderId')
# os_ioc_sdr_id_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_sdr_id_ECUCPara.set_upperMultiplicity('1')
os_ioc_sding_osapp_ref_ECUCPara = os_ioc_sdr_props_ECUCPara.new_EcucReferenceDef('OsIocSendingOsApplicationRef')
# os_ioc_sding_osapp_ref_ECUCPara.set_lowerMultiplicity('1')
# os_ioc_sding_osapp_ref_ECUCPara.set_upperMultiplicity('1')
os_ioc_func_impl_kind_ECUCPara = os_ioc_sdr_props_ECUCPara.new_EcucEnumerationParamDef('OsIocFunctionImplementationKind')
# os_ioc_func_impl_kind_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_func_impl_kind_ECUCPara.set_upperMultiplicity('1')

os_ioc_rcv_props_ECUCPara = os_ioc_comm_ECUCPara.new_EcucParamConfContainerDef('OsIocReceiverProperties')
# os_ioc_rcv_props_ECUCPara.set_lowerMultiplicity('1')
# os_ioc_rcv_props_ECUCPara.set_upperMultiplicity('*')
os_ioc_rcv_id_ECUCPara = os_ioc_rcv_props_ECUCPara.new_EcucIntegerParamDef('OsIocReceiverId')
# os_ioc_rcv_id_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_rcv_id_ECUCPara.set_upperMultiplicity('1')
os_ioc_rving_osapp_ref_ECUCPara = os_ioc_rcv_props_ECUCPara.new_EcucReferenceDef('OsIocReceivingOsApplicationRef')
# os_ioc_rving_osapp_ref_ECUCPara.set_lowerMultiplicity('1')
# os_ioc_rving_osapp_ref_ECUCPara.set_upperMultiplicity('1')
os_ioc_func_impl_kind_ECUCPara = os_ioc_rcv_props_ECUCPara.new_EcucEnumerationParamDef('OsIocFunctionImplementationKind')
# os_ioc_func_impl_kind_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_func_impl_kind_ECUCPara.set_upperMultiplicity('1')
os_ioc_rcv_pull_cb_ECUCPara = os_ioc_rcv_props_ECUCPara.new_EcucFunctionNameDef('OsIocReceiverPullCB')
# os_ioc_rcv_pull_cb_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_rcv_pull_cb_ECUCPara.set_upperMultiplicity('1')

os_ioc_data_props_ECUCPara = os_ioc_comm_ECUCPara.new_EcucParamConfContainerDef('OsIocDataProperties')
# os_ioc_data_props_ECUCPara.set_lowerMultiplicity('1')
# os_ioc_data_props_ECUCPara.set_upperMultiplicity('*')
os_ioc_data_type_ref_ECUCPara = os_ioc_data_props_ECUCPara.new_EcucForeignReferenceDef('OsIocDataTypeRef')
# os_ioc_data_type_ref_ECUCPara.set_lowerMultiplicity('1')
# os_ioc_data_type_ref_ECUCPara.set_upperMultiplicity('1')
os_ioc_init_value_ECUCPara = os_ioc_data_props_ECUCPara.new_EcucStringParamDef('OsIocInitValue')
# os_ioc_init_value_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_init_value_ECUCPara.set_upperMultiplicity('1')
os_ioc_data_props_idx_ECUCPara = os_ioc_data_props_ECUCPara.new_EcucIntegerParamDef('OsIocDataPropertyIndex')
# os_ioc_data_props_idx_ECUCPara.set_lowerMultiplicity('0')
# os_ioc_data_props_idx_ECUCPara.set_upperMultiplicity('1')
os_sw_addr_ECUCPara = os_ioc_data_props_ECUCPara.new_EcucForeignReferenceDef('OsMemoryMappingCodeLocationRef')
# os_sw_addr_ECUCPara.set_lowerMultiplicity('0')
# os_sw_addr_ECUCPara.set_upperMultiplicity('1')

autosarfactory.save()
