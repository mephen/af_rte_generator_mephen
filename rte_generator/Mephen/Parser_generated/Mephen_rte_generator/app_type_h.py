#合併專案時，放到 af_generate_app_type_h.py 中。
import pdb
import platform
import os, shutil
from termcolor import colored

from autosarfactory import autosarfactory
from tsepp_modules import arnode_query
from autosarfactory.autosarfactory import DataTypeMappingSet\
    , RTEEvent, RunnableEntity, SwBaseType, ImplementationDataType\
    , SwComponentType, ApplicationSwComponentType, EcucModuleConfigurationValues,EcucModuleDef\
    , DataReceivedEvent, AssemblySwConnector, SystemMapping, SynchronousServerCallPoint, AsynchronousServerCallPoint\
    , OperationInvokedEvent, AsynchronousServerCallReturnsEvent, ARPackage, ARElement\
    , ApplicationPrimitiveDataType, ImplementationDataType, DataTypeMappingSet
from app_h import dataType_mappingSets, client_server_component_list, arpackages_list, swc_dict, check_server

def gen_app_type_h(swc):
    rables_of_swc = [] #儲存一個 swc 的所有 runnables
    event_of_swc = [] #儲存一個 swc 的所有 events
    swc_ib_keys = swc.get_internalBehaviors() #internal behaviors
    for ib_key in swc_ib_keys:
        swc_ib_rable_keys = ib_key.get_runnables() #runnables
        event_keys = ib_key.get_events() #rte events
        rables_of_swc.extend(swc_ib_rable_keys)
        event_of_swc.extend(event_keys)

    swc_name = os.path.basename(swc.get_path())
    dir_path = f'./generated/{swc_name}'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = f'Rte_{swc_name}_Type.h'
    file_path = os.path.join(dir_path, target_file_name)
    # print(file_path)
    
    write_content = []
    write_content.extend([
        '//Data Type Redefinition Name',
        '//avoid the name clash form different SWCs (see SWS_RTE 5.3.4.10)',
        '//----------------------------------------------------------------',
        '//[SWS_Rte_07678]',
        '#ifndef RTE_CLIENT_RUNNABLE_TYPE_h',
        '#define RTE_CLIENT_RUNNABLE_TYPE_h',
        '#ifdef __cplusplus /* [SWS_Rte_07125] */',
        'extern "C" {',
        '#endif /* __cplusplus */',
        '',
        '#include "../Rte_Type.h"',
    ])

    DT_impl_name_list = []
    DT_impl_symbol_list = []
    #"data type redefinition" for client / client_response / server runnables of a swc
    for rable in rables_of_swc:
        scp_keys = rable.get_serverCallPoints()
        async_scrp_keys = rable.get_asynchronousServerCallResultPoints()
        if(len(scp_keys) > 0): #client runnable
            for scp in scp_keys:
                op_args = scp.get_operation().get_targetRequiredOperation().get_arguments()
                DT_app = list(op_args)[0].get_type()
                DT_impl = None
                for DT_mappingSet_instance in dataType_mappingSets:
                    DT_maps = DT_mappingSet_instance.get_dataTypeMaps()
                    for DT_map in DT_maps:
                        if((DT_map.get_applicationDataType() == DT_app)):
                            DT_impl = DT_map.get_implementationDataType()
                            break
                if((DT_impl != None) and (DT_impl.get_shortName() not in DT_impl_name_list) and (DT_impl.get_symbolProps().get_symbol() not in DT_impl_symbol_list)):
                    DT_impl_name_list.append(DT_impl.get_shortName())
                    DT_impl_symbol_list.append(DT_impl.get_symbolProps().get_symbol())
        if(len(async_scrp_keys) > 0): #client response runnable
            for async_scrp in async_scrp_keys:
                op_args = async_scrp.get_asynchronousServerCallPoint().get_operation().get_targetRequiredOperation().get_arguments()
                DT_app = list(op_args)[0].get_type()
                DT_impl = None
                #找出 arg 對應的 DT_impl
                for DT_mappingSet_instance in dataType_mappingSets:
                    DT_maps = DT_mappingSet_instance.get_dataTypeMaps()
                    for DT_map in DT_maps:
                        if((DT_map.get_applicationDataType() == DT_app)):
                            DT_impl = DT_map.get_implementationDataType()
                            break
                if((DT_impl != None) and (DT_impl.get_shortName() not in DT_impl_name_list) and (DT_impl.get_symbolProps().get_symbol() not in DT_impl_symbol_list)):
                    DT_impl_name_list.append(DT_impl.get_shortName())
                    DT_impl_symbol_list.append(DT_impl.get_symbolProps().get_symbol())
        if(check_server(event_of_swc, rable)): #server runnable
            server_ev = None
            for event in event_of_swc:
                if((type(event) == OperationInvokedEvent) and (event.get_startOnEvent() == rable)):
                    server_ev = event
                    break
            op = server_ev.get_operation().get_targetProvidedOperation()
            op_args = op.get_arguments()
            DT_app = list(op_args)[0].get_type()
            DT_impl = None
            #找出 arg 對應的 DT_impl
            for DT_mappingSet_instance in dataType_mappingSets:
                DT_maps = DT_mappingSet_instance.get_dataTypeMaps()
                for DT_map in DT_maps:
                    if((DT_map.get_applicationDataType() == DT_app)):
                        DT_impl = DT_map.get_implementationDataType()
                        break
            if((DT_impl != None) and (DT_impl.get_shortName() not in DT_impl_name_list) and (DT_impl.get_symbolProps().get_symbol() not in DT_impl_symbol_list)):
                DT_impl_name_list.append(DT_impl.get_shortName())
                DT_impl_symbol_list.append(DT_impl.get_symbolProps().get_symbol())
    # print(DT_impl_name_list)
    # print(DT_impl_symbol_list)

    for i in range(len(DT_impl_name_list)):
        DT_impl_name = DT_impl_name_list[i]
        DT_impl_symbol = DT_impl_symbol_list[i]
        if(DT_impl_name != DT_impl_symbol):
            write_content.extend([
                f'#define {DT_impl_name} {DT_impl_symbol}',
            ])

    write_content.extend([
        '',
        '#ifdef __cplusplus /* [SWS_Rte_07126]  */',
        '} /* extern "C" */',
        '#endif /* __cplusplus */',
        '#endif/* RTE_CLIENT_RUNNABLE_TYPE_h */',
    ])

    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

def main():
    for swc in swc_dict:
        gen_app_type_h(swc_dict[swc])

if __name__ == '__main__':
    main()
