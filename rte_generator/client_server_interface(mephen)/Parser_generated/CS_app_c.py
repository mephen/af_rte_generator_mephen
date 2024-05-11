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
from CS_app_h import intra_partition, inter_partition, inter_ECU, dataType_mappingSets, client_server_component_list\
    , arpackages_list, swc_dict, in_task, direct_fn_call, trusted_fn_call, RteEventToTaskMapping_keys, check_server

def gen_app_c(swc):
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
    
    for rable in rables_of_swc:
        rable_name = rable.get_shortName()
        target_file_name = f'Rte_{rable_name}.c'
        file_path = os.path.join(dir_path, target_file_name)
        scp_keys = rable.get_serverCallPoints()
        async_scrp_keys = rable.get_asynchronousServerCallResultPoints()

        write_content = []
        write_content.extend([
            '//VFB interface(api) & Runnable Implementation',
            '//----------------------------------------------------------------',
            f'#define RTE_{rable_name}_C',
            f'#include "Rte_{swc_name}.h"',
            '#include "../ringbuffer.h"',
            '#include "../Transformer_stub.h"',
            '#include "../Rte_Cs_Data_Management.h"',
            '#include "../Rte_Event_Cfg.h"',
            '#include "../../kernel/alarm.h"',
            '#include "../../kernel/event.h"',
            '#include "../../device/lock.h"',
            '#include "../../OS_Configure/inc/event_Cfg.h"',
            '#include "../../kernel/task.h"',
            '',
        ])

        #判斷是 client / client_response / server runnable
        if(len(scp_keys) > 0): #client runnable
            CS_component = None
            for component in client_server_component_list:
                if(component['CR'] == rable):
                    CS_component = component
                    break
            
            comm_type = None
            if(CS_component['comm-type'] == intra_partition):
                comm_type = 'Rte'
            elif(CS_component['comm-type'] == inter_partition):
                comm_type = 'Ioc'
            elif(CS_component['comm-type'] == inter_ECU):
                comm_type = 'Com'

            write_content.extend([
                f'ResponseInfoType response_buffer_{rable_name}[1];//for sync rte_call',
                f'RingBuffer RB_response_{rable_name}' ' = { //for sync rte_call',
                f'    response_buffer_{rable_name},',
                '    0,',
                '    0,',
                '    1,',
                '    0',
                '};',
                '',
            ])

            #初始化 RteCallMetaData
            for scp in scp_keys:
                r_port = scp.get_operation().get_contextRPort()
                r_port_name = os.path.basename(r_port.get_path())
                op = scp.get_operation().get_targetRequiredOperation()
                op_name = op.get_shortName().split('_')[0]
                
                if(type(scp) == SynchronousServerCallPoint):
                    write_content.extend([
                        f'static RteCallMetaData Rte_Call_{r_port_name}_Sync{comm_type}{op_name}_{rable_name}_metaData = ''{',
                    ])
                else:
                    write_content.extend([
                        f'static RteCallMetaData Rte_Call_{r_port_name}_Async{comm_type}{op_name}_{rable_name}_metaData = ''{',
                    ])

                write_content.extend([
                    '    .transaction_handle = {',
                    f'        .client_id = {CS_component["CR_id"]},        //start from 1, each CR has its own client_id',
                ])
                
                if(type(scp) == SynchronousServerCallPoint):
                    write_content.extend([
                        '        .sequence_counter = 0U, //record how many c/s communication has been "finished".',
                    ])
                else:
                    write_content.extend([
                        '        .sequence_counter = 0U, //recore how many Rte_call has been "invoked" -> sequence_counter of rte_result record how many c/s communication has been "finished".',
                    ])
                
                write_content.extend([
                    '    },',
                    '    .connected_unconnected = "connected",',
                    '    .in_exclusiveArea_or_not = "NotInExclusiveArea",',
                    '    .CanAccess = "Can",',
                    '};',
                    '',
                ])

            write_content.extend([
                'static uint8 lock = 0;',
                'static uint8 lock_bit = 1;',
                'static int running_asyncApi_number  = 0; //record the number of running async Rte_call',
                f'int request_number_{rable_name} = 0; //(SWS_Rte_02658), max: 1, shared by CR & CRR in Async case; only used by CR in Sync case.',
            ])

            # print(rable_name)
            #實作 Rte_Call
            for scp in scp_keys:
                r_port = scp.get_operation().get_contextRPort()
                r_port_name = os.path.basename(r_port.get_path())
                op = scp.get_operation().get_targetRequiredOperation()
                op_name = op.get_shortName().split('_')[0]
                op_args = scp.get_operation().get_targetRequiredOperation().get_arguments()
                DT_app = list(op_args)[0].get_type()
                DT_impl = None
                #找出 op_args 對應的 DT_impl
                for DT_mappingSet_instance in dataType_mappingSets:
                    DT_maps = DT_mappingSet_instance.get_dataTypeMaps()
                    for DT_map in DT_maps:
                        if((DT_map.get_applicationDataType() == DT_app)):
                            DT_impl = DT_map.get_implementationDataType()
                            break
                
                sync_async = None
                if(type(scp) == SynchronousServerCallPoint):
                    sync_async = 'Sync'
                else:
                    sync_async = 'Async'
                
                api_head = f'Std_ReturnType Rte_Call_{r_port_name}_{sync_async}{comm_type}{op_name}_{rable_name}('
                for index, op_arg in enumerate(op_args):
                    api_head += f'{DT_impl.get_shortName()} para_{index+1}'
                    if(op_arg != list(op_args)[-1]):
                        api_head += ', '
                    else:
                        if(type(scp) == SynchronousServerCallPoint): 
                            api_head += f', {DT_impl.get_shortName()}* response'
                        api_head += '){'
                write_content.extend([
                    api_head,
                ])
                write_content.extend([
                    f'    if(request_number_{rable_name} == 0)''{//one client can only has one request at a time.',
                    f'        request_number_{rable_name} = 1;',
                    '',
                ])
                if(type(scp) == SynchronousServerCallPoint): 
                    write_content.extend([
                        '        //in sync rte_call, don\'t need to check RTE_ELIMIT',
                        '        SetRelAlarm(alarm3, 50, 0); //check timeout',
                    ])
                else:
                    write_content.extend([
                        f'        //in async rte_call, don\'t need to check timeout',
                        '        GetLock(&lock, lock_bit);',
                        '        running_asyncApi_number++;',
                        '        ReleaseLock(&lock, lock_bit);',
                    ])
                write_content.extend([
                    '',
                    '        Std_ReturnType rte_error = RTE_E_OK;',
                    '',
                    f'        if(Rte_Call_{r_port_name}_{sync_async}{comm_type}{op_name}_{rable_name}_metaData.connected_unconnected == "unconnected")' '{',
                    '            rte_error = RTE_E_UNCONNECTED;',
                    '        }',
                    '        if(rte_error == RTE_E_OK){',
                    f'            if(Rte_Call_{r_port_name}_{sync_async}{comm_type}{op_name}_{rable_name}_metaData.in_exclusiveArea_or_not == "InExclusiveArea")' '{',
                    '                rte_error = RTE_E_IN_EXCLUSIVE_AREA;',
                    '            }',
                    '        }',
                ])
                if(type(scp) == AsynchronousServerCallPoint): 
                    write_content.extend([
                    '        if(rte_error == RTE_E_OK){',
                    '            if (running_asyncApi_number > 1) { ',
                    '                rte_error = RTE_E_LIMIT;',
                    '            }',
                    '        }',
                    ])
                write_content.extend([
                    '        if(rte_error == RTE_E_OK){',
                    f'            if(Rte_Call_{r_port_name}_{sync_async}{comm_type}{op_name}_{rable_name}_metaData.CanAccess == "CanNot")' '{',
                    '                rte_error = RTE_E_SEG_FAULT;',
                    '            }',
                    '        }',
                ])
                if(CS_component['c/s-interface-invoke-type'] == in_task):
                    write_content.extend([ '        //transform parameters', ])
                    for index, op_arg in enumerate(op_args):
                        write_content.extend([
                        '        if(rte_error == RTE_E_OK){',
                        '            rte_error = Check_Transformer_Buffer(&RB_transformer_core0);', 
                        f'            uint8 transformer_error = Xfrm_transformer(&Rte_Call_{r_port_name}_{sync_async}{comm_type}{op_name}_{rable_name}_metaData.transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_{index+1});',
                        '            rte_error = Check_Transformer_Error(transformer_error, rte_error);',
                        '        }',
                        ])
                    write_content.extend([
                        '        //get transformed parameters & send to server side',
                        '        if(rte_error == RTE_E_OK || rte_error == RTE_E_SOFT_TRANSFORMER_ERROR){',
                        '            //prefetch data from transformer buffer',
                    ])
                    signal_DT_name = None
                    if(comm_type == 'Rte'):
                        signal_DT_name = DT_impl.get_shortName()
                    else:
                        signal_DT_name = swBase_DT = list(DT_impl.get_swDataDefProps().get_swDataDefPropsVariants())[0].get_baseType().get_shortName().lower()
                    for index, op_arg in enumerate(op_args):
                        write_content.extend([
                        f'            {signal_DT_name} transformed_para_{index+1};',
                        f'            RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_{index+1}, sizeof({signal_DT_name}));',
                        ])
                    for index, op_arg in enumerate(op_args):
                        if(comm_type == 'Rte'):
                            if(index == 0):
                                write_content.extend([
                                    '',
                                    f'            {signal_DT_name} len_arg = {len(op_args)}; //parser will decide the value of len_arg',
                                    '            //send request info by Rte_internal_buffer()',
                                    f'            RTE_Enqueue(&RB_requestInfo_core0, &len_arg, sizeof({signal_DT_name}));',
                                ])
                            write_content.extend([
                                f'            RTE_Enqueue(&RB_requestInfo_core0, &transformed_para_{index+1}, sizeof({signal_DT_name}));',
                            ])
                        elif(comm_type == 'Ioc'):
                            if(index == 0):
                                write_content.extend([
                                    '',
                                    f'            {signal_DT_name} len_arg = {len(op_args)}; //parser will decide the value of len_arg',
                                    '            IocSend_Q1_SND1(&len_arg);',
                                ])
                            write_content.extend([
                                f'            IocSend_Q1_SND1(transformed_para_{index+1});',
                            ])
                        #inter-ECU 因為還不知道如何使用，所以先暫放
                    
                    if(comm_type == 'Rte'):
                        write_content.extend([
                            f'            RTE_Enqueue(&RB_requestInfo_core0, &Rte_Call_{r_port_name}_{sync_async}{comm_type}{op_name}_{rable_name}_metaData.transaction_handle.client_id, sizeof(uint16));',
                            f'            RTE_Enqueue(&RB_requestInfo_core0, &Rte_Call_{r_port_name}_{sync_async}{comm_type}{op_name}_{rable_name}_metaData.transaction_handle.sequence_counter, sizeof(uint16));',
                        ])
                    elif(comm_type == 'Ioc'):
                        write_content.extend([
                            f'            IocSend_Q1_SND1(Rte_Call_{r_port_name}_{sync_async}{comm_type}{op_name}_{rable_name}_metaData.transaction_handle.client_id);',
                            f'            IocSend_Q1_SND1(Rte_Call_{r_port_name}_{sync_async}{comm_type}{op_name}_{rable_name}_metaData.transaction_handle.sequence_counter);',
                        ])
                    
                    op_ev_name = CS_component['operationInvokedEvent'].get_shortName()
                    SR_task_name = CS_component['SR-task'].get_shortName()
                    SR_name = CS_component['SR'].get_shortName()
                    # print(SR_name)
                    if(type(scp) == AsynchronousServerCallPoint):
                        write_content.extend([
                            '',
                            f'            Rte_Call_{r_port_name}_Async{comm_type}{op_name}_{rable_name}_metaData.transaction_handle.sequence_counter++; //means that x-th Rte_call is finished (x = sequence_counter)',
                            '        }',
                            '        //send return_value to coreesponding Rte_result',
                            f'        RTE_Enqueue(&RB_returnValue_{rable_name}, &rte_error, sizeof(Std_ReturnType));',
                            '',
                            '        GetLock(&lock, lock_bit);',
                            '        running_asyncApi_number--;',
                            '        ReleaseLock(&lock, lock_bit);',
                            '',
                            '        //trigger coreesponding OperationInvokedEvent',
                            '        GetLock(&lock, lock_bit);',
                            f'        trigger_rteevent(rte_event_{SR_task_name.lower()}[{op_ev_name}_{SR_task_name.lower()}]);',
                            '        ReleaseLock(&lock, lock_bit);',
                            f'        ActivateTask({SR_task_name});',
                            '',
                        ])
                    elif(type(scp) == SynchronousServerCallPoint):
                        #尋找 async return event 對應的 os event
                        os_ev = 'event1'
                        write_content.extend([
                            '',
                            '            //trigger coreesponding OperationInvokedEvent',
                            '            GetLock(&lock, lock_bit);',
                            f'            trigger_rteevent(rte_event_{SR_task_name.lower()}[{op_ev_name}_{SR_task_name.lower()}]);',
                            '            ReleaseLock(&lock, lock_bit);',
                            f'            ActivateTask({SR_task_name});',
                            '',
                            f'            WaitEvent({os_ev}); //wait until server response is available',
                            f'            ClearEvent({os_ev}); //reset SetEvent bit',
                            '',
                            '            //get server response from response queue',
                            '            ResponseInfoType server_response;',
                            f'            RTE_Dequeue(&RB_response_{rable_name}, &server_response, sizeof(ResponseInfoType));',
                            '            rte_error = server_response.bsw_error;',
                            '',
                            '            //check if there is outdated response, or timeout occur.',
                            '            if(rte_error == RTE_E_TIMEOUT){//timeout',
                            f'                Rte_Call_{r_port_name}_Sync{comm_type}{op_name}_{rable_name}_metaData.transaction_handle.sequence_counter++; //means that x-th Rte_call will be finished (x = sequence_counter)',
                            '            }' f'else if(Rte_Call_{r_port_name}_Sync{comm_type}{op_name}_{rable_name}_metaData.transaction_handle.sequence_counter > server_response.transaction_handle.sequence_counter)' '{//outdated server_response, and discard it.',
                            '                rte_error = RTE_E_TIMEOUT; ',
                            '            }' f'else if(Rte_Call_{r_port_name}_Sync{comm_type}{op_name}_{rable_name}_metaData.transaction_handle.sequence_counter == server_response.transaction_handle.sequence_counter)' '{//correct response',
                            f'                Rte_Call_{r_port_name}_Sync{comm_type}{op_name}_{rable_name}_metaData.transaction_handle.sequence_counter++; ',
                            '                *response = server_response.response;',
                            '            }',
                            '        }',
                            f'        request_number_{rable_name} = 0;//request finished',
                        ])
                elif(CS_component['c/s-interface-invoke-type'] == direct_fn_call):
                    enQ_str = ''
                    for index, op_arg in enumerate(op_args):
                        enQ_str += f'        RTE_Enqueue(&RB_request_{SR_name}, &para_{index+1}, sizeof({DT_impl.get_shortName()}))\n',
                    write_content.extend([
                        '        //direct function call',
                        enQ_str,
                        f'        RTE_RUNNABLE_{SR_name}',
                    ])
                #trusted function call 在配置條件上有 bug，暫放

                write_content.extend([
                    '        //return value follow the priority rules of RTE spec.',
                    '        return rte_error;',
                    '    }else{//wait for the previous request to be finished.',
                    '        return 2;//user defined error',
                    '    }',
                    '}',
                    '',
                ])
            
            #CR 框架
            write_content.extend([
                f'Impl_uint16 RTE_RUNNABLE_{rable_name}()' '{',
                '    //for developer to design the implementation',
                '    Impl_uint16 data_1 = 3U;',
                '    Impl_uint16 data_2 = 5U;',
                '    Impl_uint16 response;',
                f'    Std_ReturnType rte_error = Rte_Call_{r_port_name}_Async{comm_type}{op_name}_{rable_name}(data_1, data_2);',
                '    return response;',
                '}',
            ])

        if(len(async_scrp_keys) > 0): #client_response runnable
            CS_component = None
            for component in client_server_component_list:
                if(component['CRR'] == rable):
                    CS_component = component
                    break
            
            write_content.extend([
                '//SWS_Rte_02528',
                f'ResponseInfoType response_buffer_{rable_name}[1];',
                f'RingBuffer RB_response_{rable_name} = ' '{',
                f'    response_buffer_{rable_name},',
                '    0,',
                '    0,',
                '    1,',
                '    0',
                '};',
            ])
            
            #初始化 RteResultMetaData
            for async_scrp in async_scrp_keys:
                r_port = async_scrp.get_asynchronousServerCallPoint().get_operation().get_contextRPort()
                r_port_name = os.path.basename(r_port.get_path())
                op = async_scrp.get_asynchronousServerCallPoint().get_operation().get_targetRequiredOperation()
                op_name = op.get_shortName().split('_')[0]
                
                #判斷 blocking / non-blocking
                WPs = rable.get_waitPoints()
                block_nonblock = 'NonBlocking'
                for wp in WPs:
                    if(type(wp.get_trigger()) == AsynchronousServerCallReturnsEvent):
                        block_nonblock = 'Blocking'
                        break
                
                write_content.extend([
                    f'RteResultMetaData Rte_Result_{r_port_name}_{block_nonblock}_{rable_name}_metaData = ' '{',
                    '    .transaction_handle = {',
                    f'        .client_id = {CS_component["CR_id"]}U,        //same as corresponding CR',
                    '        .sequence_counter = 0U, //record how many c/s communication has been "finished".',
                    '    },',
                    '    "connected",',
                    '    "NotInExclusiveArea",',
                    '    "Can"',
                    '};',
                ])

            write_content.extend([
                '//difference between blocking & non-blocking rte_result are only',
                '//1. wait/set event at the beginning',
                '//2. metaData',
            ])
            
            #實作 Rte_Result
            for async_scrp in async_scrp_keys:
                r_port = async_scrp.get_asynchronousServerCallPoint().get_operation().get_contextRPort()
                r_port_name = os.path.basename(r_port.get_path())
                op = async_scrp.get_asynchronousServerCallPoint().get_operation().get_targetRequiredOperation()
                op_name = op.get_shortName().split('_')[0]
                
                #判斷 blocking / non-blocking
                WPs = rable.get_waitPoints()
                block_nonblock = 'NonBlocking'
                for wp in WPs:
                    if(type(wp.get_trigger()) == AsynchronousServerCallReturnsEvent):
                        block_nonblock = 'Blocking'
                        break
                
                #找出 arg 對應的 DT_impl
                op_args = op.get_arguments()
                DT_app = list(op_args)[0].get_type()
                DT_impl = None
                for DT_mappingSet_instance in dataType_mappingSets:
                    DT_maps = DT_mappingSet_instance.get_dataTypeMaps()
                    for DT_map in DT_maps:
                        if((DT_map.get_applicationDataType() == DT_app)):
                            DT_impl = DT_map.get_implementationDataType()
                            break

                write_content.extend([
                    f'Std_ReturnType Rte_Result_{r_port_name}_{block_nonblock}_{rable_name}({DT_impl.get_shortName()}* response)' '{',
                ])

                #找出 RteUsedOsEventRef (async case)
                async_return_ev_name = CS_component['AsynchronousServerCallReturnsEvent'].get_shortName()
                async_ev_map = None
                os_ev = None
                for ev_map in RteEventToTaskMapping_keys:
                    for ref in ev_map.get_referenceValues():
                        if(os.path.basename(ref.get_definition()) == 'RteEventRef' and ref.get_value().get_shortName() == async_return_ev_name):
                            async_ev_map = ev_map
                            for ref in async_ev_map.get_referenceValues():
                                if(os.path.basename(ref.get_definition()) == 'RteUsedOsEventRef'):
                                    os_ev = ref.get_value()
                                    break
                            if(os_ev != None):
                                break

                if(block_nonblock == 'Blocking'):
                    write_content.extend([
                        f'    WaitEvent({os_ev.get_shortName()}); //wait for AsynchronousServerCallReturnsEvent',
                        f'    ClearEvent({os_ev.get_shortName()});//reset SetEvent bit',
                    ])
                
                write_content.extend([
                    '    SetRelAlarm(alarm3, 50, 0);',
                    '    Std_ReturnType rte_error = RTE_E_OK;',
                    f'    if(Rte_Result_{r_port_name}_{block_nonblock}_{rable_name}_metaData.connected_unconnected == "unconnected")' '{',
                    '        rte_error = RTE_E_UNCONNECTED;',
                    '    }',
                    '    if(rte_error == RTE_E_OK){',
                    f'        if(Rte_Result_{r_port_name}_{block_nonblock}_{rable_name}_metaData.in_exclusiveArea_or_not == "InExclusiveArea")' '{',
                    '            rte_error = RTE_E_IN_EXCLUSIVE_AREA;',
                    '        }',
                    '    }',
                    '    if(rte_error == RTE_E_OK){',
                    f'        if(Rte_Result_{r_port_name}_{block_nonblock}_{rable_name}_metaData.CanAccess == "CanNot")' '{',
                    '            rte_error = RTE_E_SEG_FAULT;',
                    '        }',
                    '    }',
                    '    if(rte_error == RTE_E_OK){',
                    '        //get server response from response queue',
                    '        ResponseInfoType server_response;',
                    f'        RTE_Dequeue(&RB_response_{rable_name}, &server_response, sizeof(ResponseInfoType));',
                    '        rte_error = server_response.bsw_error;',
                    '',
                    '        //check if there is outdated response, or timeout occur.',
                    '        if(rte_error == RTE_E_TIMEOUT){//timeout',
                    f'            Rte_Result_{r_port_name}_{block_nonblock}_{rable_name}_metaData.transaction_handle.sequence_counter++; //means that x-th Rte_call will be finished (x = sequence_counter)',
                    '        }' f'else if(Rte_Result_{r_port_name}_{block_nonblock}_{rable_name}_metaData.transaction_handle.sequence_counter > server_response.transaction_handle.sequence_counter)' '{//outdated server_response, and discard it.',
                    '            rte_error = RTE_E_TIMEOUT; ',
                    '        }' f'else if(Rte_Result_{r_port_name}_{block_nonblock}_{rable_name}_metaData.transaction_handle.sequence_counter == server_response.transaction_handle.sequence_counter)' '{//not outdated, and not timeout',
                    f'            Rte_Result_{r_port_name}_{block_nonblock}_{rable_name}_metaData.transaction_handle.sequence_counter++; ',
                    '',
                    '            //check previous Rte_call return value',
                    '            Std_ReturnType rte_call_returnValue;',
                    f'            RTE_Dequeue(&RB_returnValue_{CS_component["CR"].get_shortName()}, &rte_call_returnValue, sizeof(Std_ReturnType));',
                    '            if(rte_call_returnValue == RTE_E_SEG_FAULT || rte_call_returnValue == RTE_E_TRANSFORMER_LIMIT || rte_call_returnValue == RTE_E_HARD_TRANSFORMER_ERROR){',
                    '                rte_error = RTE_E_NO_DATA;',
                    '            }else{//correct response',
                    '                *response = server_response.response;',
                    '            }',
                    '        }',
                    '    }',
                    f'    request_number_{CS_component["CR"].get_shortName()} = 0;//{CS_component["CR"].get_shortName()} request is finished',
                    '    return rte_error; //return value will follow the priority rule',
                    '}',
                ])

            #CRR 框架
            write_content.extend([
                f'Impl_uint16 RTE_RUNNABLE_{rable_name}()' '{ //Impl_uint16 is for testing',
                '    //for developer to design the implementation',
                '    Impl_uint16 response = 0;',
                f'    Std_ReturnType rte_error = Rte_Result_{r_port_name}_NonBlocking_{rable_name}(&response);',
                '    return response;',
                '}',
            ])

        if(check_server(event_of_swc, rable)): #server runnable
            server_ev = None
            for event in event_of_swc:
                if((type(event) == OperationInvokedEvent) and (event.get_startOnEvent() == rable)):
                    server_ev = event
                    break
            op = server_ev.get_operation().get_targetProvidedOperation()
            op_name = op.get_shortName()
            op_args = op.get_arguments()
            DT_app = list(op_args)[0].get_type()
            DT_impl = None
            DT_impl_name = None
            #找出 arg 對應的 DT_impl
            for DT_mappingSet_instance in dataType_mappingSets:
                DT_maps = DT_mappingSet_instance.get_dataTypeMaps()
                for DT_map in DT_maps:
                    if((DT_map.get_applicationDataType() == DT_app)):
                        DT_impl = DT_map.get_implementationDataType()
                        DT_impl_name = os.path.basename(DT_impl.get_path())
                        break
            
            args_str = ''
            for index in range(len(op_args)):
                if(index != len(op_args)-1):
                    args_str += f'data_{index+1}, '
                else:
                    args_str += f'data_{index+1};'

            write_content.extend([
                f'{DT_impl_name} request_buffer_{rable_name}[20];',
                f'RingBuffer RB_request_{rable_name} = ' '{',
                f'    request_buffer_{rable_name},',
                '    0,',
                '    0,',
                '    20,',
                '    0',
                '};',
                '',
                f'{DT_impl_name} {op_name}_{rable_name}()' '{', #實作 server operation
                f'    {DT_impl_name} 'f'{args_str}',
            ])
            for index in range(len(op_args)):
                write_content.extend([
                    f'    RTE_Dequeue(&RB_request_SR1, &data_{index+1}, sizeof({DT_impl_name}));',
                ])
            
            operator = None
            if(op_name == 'Add'): operator = '+'
            elif(op_name == 'Sub'): operator = '-'
            elif(op_name == 'Multiply'): operator = '*'
            elif(op_name == 'Divide'): operator = '/'
            else: operator = 'unknown'

            write_content.extend([
                f'    return data_1 {operator} data_2;',
                '}',
                '',
                f'{DT_impl_name} RTE_{rable_name}()' '{', #SR 框架
                '    //for developer to design the implementation',
                f'    {DT_impl_name} server_response = {op_name}_{rable_name}();',
                '    return server_response;',
                '}',
            ])

        #覆寫
        with open(file_path, 'w') as f:
            f.write('\n'.join(write_content))

def gen_Rte_Cs_Data_Management_c():
    dir_path = './generated'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = 'Rte_Cs_Data_Management.c'
    file_path = os.path.join(dir_path, target_file_name)
    write_content = []

    write_content.extend([
        '#include "Rte_Cs_Data_Management.h"',
    ])

    #rte_cs_metaData_arr
    write_content.extend([
        '/*****************************************************************************/',
        '/*for:',
        '1. server_side_fn.',
        '2. initEv & async_return_Ev case of for-loop event_check_fn. in os-task-body',
        '*/',
        '#include "Rte_Event_Cfg.h"',
    ])
    for key in swc_dict:
        swc_name = swc_dict[key].get_shortName()
        write_content.extend([
            f'#include "{swc_name}/Rte_{swc_name}.h"'
        ])
    for component in client_server_component_list:
        pass

    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

def gen_Rte_Event_Cfg_c():
    dir_path = './generated'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = 'Rte_Event_Cfg.c'
    file_path = os.path.join(dir_path, target_file_name)
    write_content = []

    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

def main():
    for swc in swc_dict:
        gen_app_c(swc_dict[swc])
    gen_Rte_Cs_Data_Management_c()
    gen_Rte_Event_Cfg_c()

if __name__ == '__main__':
    main()