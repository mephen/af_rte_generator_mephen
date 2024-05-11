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
from CS_app_h import intra_partition, inter_partition, inter_ECU, dataType_mappingSets, client_server_component_list\
    , arpackages_list, swc_dict, in_task, direct_fn_call, trusted_fn_call, RteEventToTaskMapping_keys, Os0\
    ,osTask_appRef_dict, check_server, find_used_app_and_task



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

        #include header
        write_content.extend([
            '//---------------------------------------------------------------------------------------------------------------',
            f'//{app}.c',
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
            'static uint8 lock = 0;',
            'static uint8 lock_bit = 1;',
            '',
        ])

        #rte_server_side
        write_content.extend([
            f'static {DT_base} rte_server_side({DT_base} (*Server_Runnable)())' '{',
            '    uint8 transformer_error;',
            f'    {DT_base} len_args, transformed_response;',
            f'    {DT_impl.get_shortName()} response;',
            '    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.',
            '    Std_ReturnType bsw_error = RTE_E_OK;',
            '',
            f'    {DT_base} para_arr[10];',
            f'    {DT_base} transformed_para_arr[10];',
            '    //get request information (parameters & sequence_counter).',
            f'    RTE_Dequeue(&RB_requestInfo_{core}, &len_args, sizeof({DT_base}));',
            '    for(int i = 0; i < len_args; i++){',
            f'        RTE_Dequeue(&RB_requestInfo_{core}, &para_arr[i], sizeof({DT_impl.get_shortName()}));',
            '    }',
            f'    RTE_Dequeue(&RB_requestInfo_{core}, &transaction_handle.client_id, sizeof({DT_base}));',
            f'    RTE_Dequeue(&RB_requestInfo_{core}, &transaction_handle.sequence_counter, sizeof({DT_base}));',
            '',
            '    //transform data into DataType for server_operation',
            '    for(int i = 0; i < len_args; i++){',
            f'        bsw_error = Check_Transformer_Buffer(&RB_transformer_{core});',
            f'        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_{core}, &RB_transformer_{core}.currentSize, para_arr[i]);',
            '        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);',
            f'        RTE_Dequeue(&RB_transformer_{core}, (void*)&transformed_para_arr[i], sizeof({DT_base}));',
            '    }',
            '    //enqueue request queue on server side',
            '    for(int i = 0; i < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); i++){',
            '        if(Server_Runnable == rte_cs_metaData_arr[i].SR_RVuint16){',
            '            for(int j = 0; j < len_args; j++){',
            f'                RTE_Enqueue(rte_cs_metaData_arr[i].RB_request_ptr, &transformed_para_arr[j], sizeof({DT_base}));',
            '            }',
            '            response = rte_cs_metaData_arr[i].SR_RVuint16();//do server operation, SR will get paras in its own request_queue',
            '            break;',
            '        }',
            '    }',
            '',
            '    //transform data into DataType for Rte_Enqueue the rte_internal_buffer',
            f'    bsw_error = Check_Transformer_Buffer(&RB_transformer_{core});',
            f'    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_{core}, &RB_transformer_{core}.currentSize, response);',
            '    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);',
            f'    RTE_Dequeue(&RB_transformer_{core}, &transformed_response, sizeof({DT_base}));',
            '',
            '    ResponseInfoType response_info = {',
            '        RTE_E_OK,',
            '        transaction_handle,',
            '        transformed_response',
            '    };',
            f'    RTE_Enqueue(&RB_responseInfo_{core}, &response_info, sizeof(ResponseInfoType));//via rte_internal_buffer, store response information (response & sequence_counter)',
            '    return transaction_handle.client_id;',
            '}',
            '',
        ])

        #rte_client_side
        write_content.extend([
            'static ResponseInfoType rte_client_side(){',
            f'    {DT_base} transformed_response;',
            '    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.',
            '    Std_ReturnType bsw_error = RTE_E_OK;',
            '    ResponseInfoType response_info;',
            f'    RTE_Dequeue(&RB_responseInfo_{core}, &response_info, sizeof(ResponseInfoType));',
            '',
            f'    bsw_error = Check_Transformer_Buffer(&RB_transformer_{core});',
            f'    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_{core}, &RB_transformer_{core}.currentSize, response_info.response);',
            '    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);',
            f'    RTE_Dequeue(&RB_transformer_{core}, &transformed_response, sizeof({DT_base}));',
            '',
            '    ResponseInfoType server_response = {',
            '        bsw_error,',
            '        response_info.transaction_handle,',
            '        transformed_response',
            '    };',
            '    return server_response;',
            '}',
            '',
        ])

        #ioc_server_side
        write_content.extend([
            f'static {DT_base} ioc_server_side({DT_base} (*Server_Runnable)())' '{',
            '    uint8 transformer_error;',
            f'    {DT_base} len_args, transformed_response;',
            f'    {DT_impl.get_shortName()} response;',
            '    Rte_Cs_TransactionHandleType transaction_handle;',
            '    Std_ReturnType bsw_error = RTE_E_OK;',
            '',
            f'    {DT_base} para_arr[10];',
            f'    {DT_base} transformed_para_arr[10];',
            '    //get request information (parameters & sequence_counter).',
            '    IocReceive_Q1(&len_args);',
            '    for(int i = 0; i < len_args; i++){',
            '        IocReceive_Q1(&para_arr[i]);',
            '    }',
            '    IocReceive_Q1(&transaction_handle.client_id);',
            '    IocReceive_Q1(&transaction_handle.sequence_counter);',
            '',
            '    //transform data into DataType for server_operation',
            '    for(int i = 0; i < len_args; i++){',
            f'        bsw_error = Check_Transformer_Buffer(&RB_transformer_{core});',
            f'        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_{core}, &RB_transformer_{core}.currentSize, para_arr[i]);',
            '        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);',
            f'        RTE_Dequeue(&RB_transformer_{core}, (void*)&transformed_para_arr[i], sizeof({DT_base}));',
            '    }',
            '',
            '    //enqueue request queue on server side',
            '    for(int i = 0; i < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); i++){',
            '        if(Server_Runnable == rte_cs_metaData_arr[i].SR_RVuint16){',
            '            for(int j = 0; j < len_args; j++){',
            f'                RTE_Enqueue(rte_cs_metaData_arr[i].RB_request_ptr, &transformed_para_arr[j], sizeof({DT_base}));',
            '            }',
            '            response = rte_cs_metaData_arr[i].SR_RVuint16();//do server operation, SR will get paras in its own request_queue',
            '            break;',
            '        }',
            '    }',
            '',
            '    //transform data into DataType for Rte_Enqueue the rte_internal_buffer',
            f'    bsw_error = Check_Transformer_Buffer(&RB_transformer_{core});',
            f'    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_{core}, &RB_transformer_{core}.currentSize, response);',
            '    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);',
            f'    RTE_Dequeue(&RB_transformer_{core}, &transformed_response, sizeof(uint16));',
            '',
            '    //send response information (response & sequence_counter).',
            '    IocSend_Q1_SND1(transaction_handle.client_id);//for server_response.transaction_handle.client_id',
            '    IocSend_Q1_SND1(transaction_handle.sequence_counter);//for server_response.transaction_handle.sequence_counter',
            '    IocSend_Q1_SND1(transformed_response);//for server_response.response',
            '    return transaction_handle.client_id;',
            '}',
            '',
        ])

        #ioc_client_side
        write_content.extend([
            'static ResponseInfoType ioc_client_side(){',
            f'    {DT_base} transformed_response;',
            '    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.',
            '    Std_ReturnType bsw_error = RTE_E_OK;',
            '    ResponseInfoType response_info;',
            '    IocReceive_Q1(&response_info.transaction_handle.client_id);',
            '    IocReceive_Q1(&response_info.transaction_handle.sequence_counter);',
            '    IocReceive_Q1(&response_info.response);',
            '    ',
            f'    bsw_error = Check_Transformer_Buffer(&RB_transformer_{core});',
            f'    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_{core}, &RB_transformer_{core}.currentSize, response_info.response);',
            '    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);',
            f'    RTE_Dequeue(&RB_transformer_{core}, &transformed_response, sizeof({DT_base}));',
            '',
            '    ResponseInfoType server_response = {',
            '        bsw_error,',
            '        response_info.transaction_handle,',
            '        transformed_response',
            '    };',
            '    return server_response;',
            '}',
            '',
        ])

        #os task body
        for task_name in used_task.keys():
            # print(task_name)
            task_name_low = task_name.lower()
            # print(used_task[task_name], app)
            if(used_task[task_name] == app):
                test_index = 0
                if(task_name == 'T02'): test_index = 2
                write_content.extend([
                    f'TASK({task_name})',
                    '{',
                    rf'    PrintText("hello {task_name}\r\n\0");',
                    '',
                    '    //assumption: runnable can use only one Rte_call (becuase parser doesn\'t know how the user implements the runnable).',
                    f'    for(int ev_{task_name_low}_index =0; ev_{task_name_low}_index<(sizeof(rte_event_{task_name_low})/sizeof(rte_event_{task_name_low}[0]));ev_{task_name_low}_index++)' '{',
                    '        //task priority may cause the runnable pending(even if the rte_event is triggerred). Rte event may be triggerred multiple times, so we need to use "while-loop" to check rte_event_counter',
                    f'        while(get_rteevent_counter(rte_event_{task_name_low}[ev_{task_name_low}_index]))' '{ //check if the event is triggered',
                    f'            if(!get_rteevent_disablemode(rte_event_{task_name_low}[ev_{task_name_low}_index]))''{ //check if the event can activate corresponding runnable',
                    '                GetLock(&lock, lock_bit);',
                    f'                set_runnable_execute(rte_event_{task_name_low}[ev_{task_name_low}_index]);//set_runnable_execute before invoking the runnable',
                    '                ReleaseLock(&lock, lock_bit);',
                    '',
                    f'                switch (get_rteevent_type(rte_event_{task_name_low}[ev_{task_name_low}_index]))''{ //check RTEEvent type',
                    '                    case InitEvent:',
                    '                        //rte client side: send c/s request。(All CRs that send the request should be put in a same task, or we don\'t where to activate those different tasks who include CRs)',
                    f'                        if(get_trigger_runnable_type(rte_event_{task_name_low}[ev_{task_name_low}_index]) == ClientRunnable)''{',
                    '                            for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){',
                    f'                                if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == rte_event_{task_name_low}[ev_{task_name_low}_index]->Runnable_FuncPtr_RVuint16)''{ //RVuint16 is for testing, will be replaced by void in real case',
                    '                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){',
                    '                                        Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it',
                    f'                                        if((ev_{task_name_low}_index=={test_index} && result == 8) || (ev_{task_name_low}_index=={test_index+1} && result == 8U) || (ev_{task_name_low}_index=={test_index+2} && result == 15U))''{',
                    r'                                            PrintText("success\r\n\0");',
                    '                                        }',
                    '                                    }else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){',
                    '                                        rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request',
                    '                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == blocking){',
                    '                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CRR_RVuint16(); // CRR use blocking_rte_result: wait for async_return_ev to unblock it',
                    f'                                            if((ev_{task_name_low}_index=={test_index} && result == 8) || (ev_{task_name_low}_index=={test_index+1} && result == 8U) || (ev_{task_name_low}_index=={test_index+2} && result == 15U))''{',
                    r'                                                PrintText("success\r\n\0");',
                    '                                            }',
                    '                                        }',
                    '                                    }',
                    '                                    break;',
                    '                                }',
                    '                            }',
                    '                        }',
                    '                        break;',
                    '                    case OperationInvokedEvent:',
                    '                        /*server side: receive request_info, handle request, and send response_info*/',
                    '                        //server side task use while-loop to check rte_event_arr: Because there may be multiple runnable invoke same server-side runnable simultaneously.',
                    '                        //It\'s impossible that a same client runnable be called concurrently(SWS_Rte_02658: RTE shall allow only one request per client at any time)',
                    '                        uint16 client_id = -1;',
                    f'                        switch(get_communication_type(rte_event_{task_name_low}[ev_{task_name_low}_index]))''{',
                    '                            case IntraPartition:',
                    f'                                client_id = rte_server_side(rte_event_{task_name_low}[ev_{task_name_low}_index]->Runnable_FuncPtr_RVuint16);//check error, call transformer, enqueue request queue, do operation, send response',
                    '                                break;',
                    '                            case InterPartition:',
                    f'                                client_id = ioc_server_side(rte_event_{task_name_low}[ev_{task_name_low}_index]->Runnable_FuncPtr_RVuint16);',
                    '                                break;',
                    '                            case InterEcu:',
                    '                                /*com_server_side fn.*/',
                    '                                break;',
                    '                        }',
                    '                        //the server_response got from server runnable still need data_processinng(transformer, check transaction_handle, enqueue responseQ...), so we can\'t trigger Async_return_ev in the api of SR.',
                    '                        for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){',
                    '                            if(rte_cs_metaData_arr[metaData_arr_index].client_id == client_id){',
                    '                                if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){',
                    '                                    /*receive and handle response_info*/',
                    '                                    ResponseInfoType server_response;',
                    f'                                    switch(get_communication_type(rte_event_{task_name_low}[ev_{task_name_low}_index]))''{',
                    '                                        case IntraPartition:',
                    '                                            server_response = rte_client_side();//check error, call transformer, dequeue response queue',
                    '                                            break;',
                    '                                        case InterPartition:',
                    '                                            server_response = ioc_client_side();',
                    '                                            break;',
                    '                                        case InterEcu:',
                    '                                            /*com client side fn.*/',
                    '                                            break;',
                    '                                    }',
                    '                                    RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)',
                    '                                    SetEvent(T01, event1);//unblock the CR who use sync_rte_call (sync_rte_call doesn\'t configure waitPoint, so we assume event1)',
                    '                                }else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){',
                    '                                    GetLock(&lock, lock_bit);',
                    '                                    trigger_rteevent(rte_cs_metaData_arr[metaData_arr_index].async_return_ev); //trigger async_return_ev to : unblock the CRR who use blocking_rte_result / activate the CRR who use non_blocking_rte_result',
                    '                                    ReleaseLock(&lock, lock_bit);',
                    '                                    if(rte_cs_metaData_arr[metaData_arr_index].SR_task != rte_cs_metaData_arr[metaData_arr_index].CRR_task){',
                    '                                        ActivateTask(rte_cs_metaData_arr[metaData_arr_index].CRR_task); //the task where client handle responseInfo',
                    '                                    }',
                    '                                }',
                    '                                break;',
                    '                            }',
                    '                        }',
                    '                        break;',
                    '                    case AsynchronousServerCallReturnsEvent:',
                    '                        /*in async case, client side: receive and handle response_info*/',
                    '                        //AsynchronousServerCallReturnsEvent: tell a specific client that the response is ready, and [SWS_Rte_02658] says that "Before a request of the client is finished, the client can\'t send a new c/s request"',
                    '                        ResponseInfoType server_response;',
                    f'                        switch(get_communication_type(rte_event_{task_name_low}[ev_{task_name_low}_index]))''{',
                    '                            case IntraPartition:',
                    '                                server_response = rte_client_side();//check error, call transformer, dequeue response queue',
                    '                                break;',
                    '                            case InterPartition:',
                    '                                server_response = ioc_client_side();',
                    '                                break;',
                    '                            case InterEcu:',
                    '                                /*com client side fn.*/',
                    '                                break;',
                    '                        }',
                    '',
                    '                        for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){',
                    '                            if(rte_cs_metaData_arr[metaData_arr_index].client_id == server_response.transaction_handle.client_id){',
                    '                                RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)',
                    '                                if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == blocking){',
                    f'                                    SetEvent(T01, event1); //unblock the CRR who use blocking_rte_result',
                    '                                }else if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == non_blocking){',
                    f'                                    Impl_uint16 result = rte_event_{task_name_low}[ev_{task_name_low}_index]->Runnable_FuncPtr_RVuint16(); // activate the CRR who use non_blocking_rte_result',
                    f'                                    if((ev_{task_name_low}_index=={test_index} && result == 8) || (ev_{task_name_low}_index=={test_index+1} && result == 8U) || (ev_{task_name_low}_index=={test_index+2} && result == 15U))''{',
                    r'                                        PrintText("success\r\n\0");',
                    '                                    }',
                    '                                }',
                    '                                break;',
                    '                            }',
                    '                        }',
                    '                        break;',
                    '                    default:',
                    '                        //other 13 RTEEvent type case...',
                    '                        break;',
                    '                }',
                    '',
                    '                GetLock(&lock, lock_bit);',
                    f'                clear_runnable_execute(rte_event_{task_name_low}[ev_{task_name_low}_index]);',
                    '                ReleaseLock(&lock, lock_bit);',
                    '            }',
                    '            GetLock(&lock, lock_bit);',
                    f'            release_rteevent(rte_event_{task_name_low}[ev_{task_name_low}_index]); //release the event',
                    '            ReleaseLock(&lock, lock_bit);',
                    '        }',
                    '    }',
                    '',
                    '    TerminateTask();',
                    '}',
                ])

    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))


def main():
    used_app = []
    used_task = {} #key: task_name, value: app
    find_used_app_and_task(used_app, used_task)
    gen_rte_c(used_app, used_task)

if __name__ == '__main__':
    main()