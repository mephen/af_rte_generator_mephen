#合併專案時，放到 af_generate_rte_c.py 中。
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
from CS_app_h import intra_partition, inter_partition, inter_ECU, dataType_mappingSets, client_server_component_list, arpackages_list, swc_dict, in_task, direct_fn_call, trusted_fn_call, RteEventToTaskMapping_keys, Os0, check_server

def find_used_app_and_task(used_app, used_task):
    osTask_appRef_dict = {} #osTask 被 map 到哪個 app
    for container in Os0.get_containers():
        if(os.path.basename(container.get_definition()) == 'OsTask'):
            refs = container.get_referenceValues()
            for ref in refs:
                if(os.path.basename(ref.get_definition()) == 'OsTaskAccessingApplication'):
                    task_name = container.get_shortName()
                    app_ref = ref.get_value()
                    osTask_appRef_dict.update({f'{task_name}' : app_ref})
    
    for ev_map in RteEventToTaskMapping_keys:
        refs = ev_map.get_referenceValues()
        ev_ref = None
        task_ref = None
        for ref in refs:
            if(os.path.basename(ref.get_definition()) == 'RteEventRef'):
                ev_ref = ref.get_value()
            if(os.path.basename(ref.get_definition()) == 'RteMappedToTaskRef'):
                task_ref = ref.get_value()
                if task_ref not in used_task.keys():
                    # print(osTask_appRef_dict[task_ref.get_shortName()])
                    app = osTask_appRef_dict[task_ref.get_shortName()].get_shortName()
                    if app not in used_app:
                        used_app.append(app)
                    used_task.update({task_ref.get_shortName(): osTask_appRef_dict[task_ref.get_shortName()].get_shortName()})

def gen_rte_c(used_app, used_task):
    dir_path = f'./generated'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    file_path = os.path.join(dir_path, 'Rte.c')
    
    #base type for args of SR
    DT_base = None
    DT_impl = None
    for swc in swc_dict.values():
        rables_of_swc = [] #儲存一個 swc 的所有 runnables
        event_of_swc = [] #儲存一個 swc 的所有 events
        swc_ib_keys = swc.get_internalBehaviors() #internal behaviors
        swc_name = swc.get_shortName()
        for ib_key in swc_ib_keys:
            swc_ib_rable_keys = ib_key.get_runnables() #runnables
            event_keys = ib_key.get_events() #rte events
            rables_of_swc.extend(swc_ib_rable_keys)
            event_of_swc.extend(event_keys)
        for rable in rables_of_swc:
            if(check_server(event_of_swc, rable)):
                server_ev = None
                for event in event_of_swc:
                    if((type(event) == OperationInvokedEvent) and (event.get_startOnEvent() == rable)):
                        server_ev = event
                        break
                op = server_ev.get_operation().get_targetProvidedOperation()
                op_name = os.path.basename(op.get_path())
                op_args = op.get_arguments()
                DT_app = list(op_args)[0].get_type()
                DT_impl = None
                for DT_mappingSet_instance in dataType_mappingSets:
                    DT_maps = DT_mappingSet_instance.get_dataTypeMaps()
                    for DT_map in DT_maps:
                        if((DT_map.get_applicationDataType() == DT_app)):
                            DT_impl = DT_map.get_implementationDataType()
                            break
                DT_base = list(DT_impl.get_swDataDefProps().get_swDataDefPropsVariants())[0].get_baseType().get_shortName().lower()
                break
        if DT_base != None:
            break

    write_content = []
    
    for app in used_app:
        core = None
        if(app == 'App1' or app == 'App3'):
            core = 'core0'
        elif(app == 'App2' or app == 'App4'):
            core = 'core1'

        write_content.extend([
            f'//{app}.c',
            '//-------------------------------------',
            '#include "event_Cfg.h"',
            '#include "alarm_Cfg.h"',
            '#include "application_Cfg.h"',
            '#include "counter.h"',
            '#include "alarm.h"',
            '#include "task.h"',
            '#include "isr2.h"',
            '#include "event.h"',
            '#include "memsection.h"',
            '#include "memprot_Cfg.h"',
            '#include "string_format_test.h"',
            '#include "systemcall.h"',
            '#include "application.h"',
            '#include "ISRInit.h"',
            '#include "isr_Cfg.h"',
            '#include "spinlock.h"',
            '#include "resource.h"',
            '#include "memsection.h"',
            '#include "trustedFunc_Cfg.h"',
            '#include "ioc.h"',
            '#include "lock.h"',
            '#include "Rte_Event_Cfg.h"',
            '#include "Transformer_stub.h"',
            '#include "Rte_Cs_Data_Management.h"',
        ])

        for swc in swc_dict.values():
            rables_of_swc = [] #儲存一個 swc 的所有 runnables
            event_of_swc = [] #儲存一個 swc 的所有 events
            swc_ib_keys = swc.get_internalBehaviors() #internal behaviors
            swc_name = swc.get_shortName()
            for ib_key in swc_ib_keys:
                swc_ib_rable_keys = ib_key.get_runnables() #runnables
                event_keys = ib_key.get_events() #rte events
                rables_of_swc.extend(swc_ib_rable_keys)
                event_of_swc.extend(event_keys)

            write_content.extend([
                f'#include "{swc_name}/Rte_{swc_name}.h"',
            ])
        
        write_content.extend([
            '',
            'extern int PrintText(char *TextArray);',
            'extern int PrintText_R35(char *TextArray);',
            '',
            '/************* USER_SHARED_SEC *****************/',
            '#pragma section USER_SHARED_SEC',
            '',
            'uint8 lock = 0;',
            'uint8 lock_bit = 1;',
            '',
            f'{DT_base} rte_server_side({DT_base} (*Server_Runnable)())' '{',
            '    uint8 transformer_error;',
            f'    {DT_base} len_args, transformed_response;',
            '    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.',
            '    Std_ReturnType bsw_error = RTE_E_OK;',
            '',
            '    //get request information (parameters & sequence_counter).',
            f'    RTE_Dequeue(&RB_requestInfo_{core}, &len_args, sizeof({DT_base}));',
            f'    {DT_base} para_arr[len_args];',
            f'    {DT_base} transformed_para_arr[len_args];',
            '    for(int i = 0; i < len_args; i++){',
            f'        RTE_Dequeue(&RB_requestInfo_{core}, &para_arr[i], sizeof({DT_impl.get_shortName()}));',
            '    }',
            f'    RTE_Dequeue(&RB_requestInfo_{core}, &transaction_handle.client_id, sizeof({DT_base}));',
            f'    RTE_Dequeue(&RB_requestInfo_{core}, &transaction_handle.sequence_counter, sizeof({DT_base}));',
            '',
            '    //transforme data into DataType for server_operation',
            '    for(int i = 0; i < len_args; i++){',
            '        bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);',
            '        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_arr[i]);',
            '        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);',
            '        RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_arr[i], sizeof(uint16));',
            '        ',
            '        if(Server_Runnable == RTE_RUNNABLE_Server1){',
            '            RTE_Enqueue(&RB_request_SR1, &transformed_para_arr[i], sizeof(uint16));//在 server side enqueue request queue',
            '        }else if(Server_Runnable == RTE_RUNNABLE_Server2){',
            '            RTE_Enqueue(&RB_request_SR2, &transformed_para_arr[i], sizeof(uint16));',
            '        }else{/*if other server runnable of intra-partition comm. is configured*/}',
            '    }',
            '',
            '    Impl_uint16 response = Server_Runnable();//do server operation, server runnable 會自己去 request_queue 裡面拿參數。',
            '    ',
            '    //transforme data into DataType for Rte_Enqueue the rte_internal_buffer',
            '    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);',
            '    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response);',
            '    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);',
            '    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));',
            '',
            '    ResponseInfoType response_info = {',
            '        RTE_E_OK,',
            '        transaction_handle,',
            '        transformed_response',
            '    };',
            '    RTE_Enqueue(&RB_responseInfo_core0, &response_info, sizeof(ResponseInfoType));//via rte_internal_buffer, store response information (response & sequence_counter)',
            '    return transaction_handle.client_id;',
            '}',
        ])


    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))


def main():
    used_app = []
    used_task = {} #key: app, value: task
    find_used_app_and_task(used_app, used_task)
    gen_rte_c(used_app, used_task)

if __name__ == '__main__':
    main()