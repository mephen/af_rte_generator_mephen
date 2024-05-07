#合併專案時，放到 af_generate_app_h.py 中。
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


def print_object(obj):
    print(f'{os.path.basename(obj.get_path())}')

def print_test(container):
    #ele of container: autoarfactory object
    if(type(container) != dict):
        for obj in container:
            print(os.path.basename(obj.get_path()))
    #ele of container: string
    else:
        for str in container:
            print(os.path.basename(str))
    print('')

def set_AsyncSerCallRetEv_startOnEvent(rable, event):
    event_name = os.path.basename(event.get_path())
    if(type(event) == AsynchronousServerCallReturnsEvent):
        rable_name = os.path.basename(rable.get_path())
        if((rable_name == 'Client_Response_1') and (event_name == 'AsynchronousServerCallReturnsEvent_1')) \
            or ((rable_name == 'Client_Response_2') and (event_name == 'AsynchronousServerCallReturnsEvent_2')) \
            or ((rable_name == 'Client_Response_3') and (event_name == 'AsynchronousServerCallReturnsEvent_3')):
            event.set_startOnEvent(rable)
            return True
    return False

#comm_tpye
inter_ECU = 'inter_ECU'
inter_partition = 'inter_partition'
intra_partition = 'intra_partition'
#runnable-invoke-type
in_task = 'in_task'
direct_fn_call = 'direct_fn_call'
trusted_fn_call = 'trusted_fn_call'
def set_client_server_component_list(arpackages_list, Rte, Os0, client_server_component_list, RteEventToTaskMapping_keys):
    swc_dict = arnode_query.find_arnode(arpackages_list, ApplicationSwComponentType)
    rable_dict = arnode_query.find_arnode(arpackages_list, RunnableEntity)
    ev_dict = arnode_query.find_arnode(arpackages_list, RTEEvent)
    
    osTask_appRef_dict = {} #osTask 被 map 到哪個 app
    app_ecucRef_dict = {} #app 被 map 到哪個 ecuc
    swc_instance_keys = [] #swc 在 os 上的 instances
    for container in Os0.get_containers():
        if(os.path.basename(container.get_definition()) == 'OsTask'):
            refs = container.get_referenceValues()
            for ref in refs:
                if(os.path.basename(ref.get_definition()) == 'OsTaskAccessingApplication'):
                    task_name = container.get_shortName()
                    app_ref = ref.get_value()
                    osTask_appRef_dict.update({f'{task_name}' : app_ref})
                    # print(task_name)
                    # print(app_ref)
                    # print('\n')
        if(os.path.basename(container.get_definition()) == 'OsApplication'):
            refs = container.get_referenceValues()
            for ref in refs:
                if(os.path.basename(ref.get_definition()) == 'OsAppEcucPartitionRef'):
                    app_name = container.get_shortName()
                    ecuc_ref = ref.get_value()
                    app_ecucRef_dict.update({f'{app_name}' : ecuc_ref})
                    # print(app_name)
                    # print(ecuc_ref)
                    # print('\n')
    # print(osTask_appRef_dict)

    for container in Rte.get_containers():
        if(os.path.basename(container.get_definition()) == 'RteSwComponentInstance'):
            swc_instance_keys.append(container)

    for swc_instance in swc_instance_keys:
        subContainers = swc_instance.get_subContainers()
        for subContainer in subContainers:
            if(os.path.basename(subContainer.get_definition()) == 'RteEventToTaskMapping'):
                RteEventToTaskMapping_keys.append(subContainer)
                # print(os.path.basename(subContainer.get_path()))

    client_runnable_list = []
    client_response_runnable_list = []
    server_runnable_list = []

    # 不知道為什麼 AsynchronousServerCallReturnsEvent 抓不到 startOnEvent，只好在 parser 這邊設定。
    for ev in ev_dict:
        for rable in rable_dict:
            set_finished = set_AsyncSerCallRetEv_startOnEvent(rable_dict[rable], ev_dict[ev])
            if(set_finished): break
        # if(type(ev_dict[ev])== AsynchronousServerCallReturnsEvent): print_object(ev_dict[ev].get_startOnEvent())

    # 準備 CR, CRR, SR 的 list
    for rable in rable_dict:
        scp_keys = rable_dict[rable].get_serverCallPoints()
        async_scrp_keys = rable_dict[rable].get_asynchronousServerCallResultPoints()
        # print_object(rable_dict[rable])
        # if(len(scp_keys) > 0):
        #     print_test(scp_keys)
        # if(len(async_scrp_keys) > 0):
        #     print_test(async_scrp_keys)
        # print('')
        if(len(scp_keys) > 0): #client runnable
            client_runnable_list.append(rable_dict[rable])
        if(len(async_scrp_keys) > 0): #client response runnable
            client_response_runnable_list.append(rable_dict[rable])
        for ev in ev_dict: #server runnable
            if((type(ev_dict[ev]) == OperationInvokedEvent) and (ev_dict[ev].get_startOnEvent() == rable_dict[rable])):
                server_runnable_list.append(rable_dict[rable])
                break
    
    # 準備 client_server_component_list
    mathed_op_evs = [] #已經配對過的 operationInvokedEvent
    id = 1
    for cr in client_runnable_list:
        component_dict = {'comm-type':None,\
                        'c/s-interface-invoke-type':None,\
                        'CR':cr, 'start_event':None, 'CR-task':None, 'CR_id':None,\
                        'CRR':None, 'AsynchronousServerCallReturnsEvent': None, 'CRR-task':None,\
                        'SR':None, 'operationInvokedEvent':None, 'SR-task':None} #"invoke-type": SR is called in task / direct fn. call / trusted fn. call; "comm-tpye": inter-ECU / inter-partition / intra-partition;
        component_dict['CR_id'] = id
        id += 1
        cr_scp_keys = cr.get_serverCallPoints()
        
        #判斷 event, runnable
        for ev in ev_dict:
            if(ev_dict[ev].get_startOnEvent() == cr):
                component_dict['start_event'] = ev_dict[ev]
                break
        for cr_scp in cr_scp_keys:
            if(type(cr_scp) == AsynchronousServerCallPoint): #CR needs CRR, and AsynchronousServerCallReturnsEvent are used to activate/unblock CRR
                for crr in client_response_runnable_list:
                    crr_scrp_keys = crr.get_asynchronousServerCallResultPoints()
                    for crr_scrp in crr_scrp_keys:
                        if(crr_scrp.get_asynchronousServerCallPoint() == cr_scp):
                            component_dict['CRR'] = crr
                            break
                for ev in ev_dict:
                    # print_object(ev_dict[ev])
                    # print_object(ev_dict[ev].get_startOnEvent())
                    if(ev_dict[ev].get_startOnEvent() == component_dict['CRR']):
                        component_dict['AsynchronousServerCallReturnsEvent'] = ev_dict[ev]
                        break
                # print('')
            elif(type(cr_scp) == SynchronousServerCallPoint): pass #sync rte_call case doesn't need AsynchronousServerCallReturnsEvent
        cr_scp_op = list(cr_scp_keys)[0].get_operation().get_targetRequiredOperation() # 不知道 client runnable 會呼叫幾次 rte_call，所以假設只呼叫一次
        for ev in ev_dict:
            if(ev in mathed_op_evs):
                continue
            if((type(ev_dict[ev]) == OperationInvokedEvent) and (ev_dict[ev].get_operation().get_targetProvidedOperation() == cr_scp_op)):
                mathed_op_evs.append(ev)
                component_dict['operationInvokedEvent'] = ev_dict[ev]
                component_dict['SR'] = ev_dict[ev].get_startOnEvent()
                break

        #找出 runnable 被 map 到哪個 task
        for ev_map in RteEventToTaskMapping_keys:
            refs = ev_map.get_referenceValues()
            ev_ref = None
            task_ref = None
            for ref in refs:
                if(os.path.basename(ref.get_definition()) == 'RteEventRef'):
                    ev_ref = ref.get_value()
                    # print(os.path.basename(ev_ref.get_path()))
                if(os.path.basename(ref.get_definition()) == 'RteMappedToTaskRef'):
                    task_ref = ref.get_value()
                    # print(os.path.basename(task_ref.get_path()))
            if(task_ref != None):
                if(os.path.basename(ev_ref.get_path()) == os.path.basename(component_dict['start_event'].get_path())): 
                    component_dict['CR-task'] = task_ref
                elif(os.path.basename(ev_ref.get_path()) == os.path.basename(component_dict['operationInvokedEvent'].get_path())):
                    component_dict['SR-task'] = task_ref
                elif(os.path.basename(ev_ref.get_path()) == os.path.basename(component_dict['AsynchronousServerCallReturnsEvent'].get_path())):
                    component_dict['CRR-task'] = task_ref
        
        #判斷 comm. type (inter-ECU, inter-partition, intra-partition)
        if(component_dict['CR-task'] != None and component_dict['SR-task'] != None):
            CR_ecuc = component_dict['CR-task'].get_path().split('/')[-2]
            SR_ecuc = component_dict['SR-task'].get_path().split('/')[-2]
            if(CR_ecuc != SR_ecuc): #inter-ECU
                component_dict['comm-type'] = inter_ECU
            else: #inter-partition / intra-partition
                cr_task_name = os.path.basename(component_dict['CR-task'].get_path())
                cr_task_appRef = osTask_appRef_dict[f'{cr_task_name}']
                cr_task_ecucRef = app_ecucRef_dict[f'{cr_task_appRef.get_shortName()}']
                sr_task_name = os.path.basename(component_dict['SR-task'].get_path())
                sr_task_appRef = osTask_appRef_dict[f'{sr_task_name}']
                sr_task_ecucRef = app_ecucRef_dict[f'{sr_task_appRef.get_shortName()}']
                # print(cr_task_appRef.get_shortName())
                # print(cr_task_ecucRef.get_shortName())
                # print(sr_task_appRef.get_shortName())
                # print(sr_task_ecucRef.get_shortName())
                # print('\n')
                if(cr_task_ecucRef != sr_task_ecucRef): #inter-partition
                    component_dict['comm-type'] = inter_partition
                else: #intra-partition
                    component_dict['comm-type'] = intra_partition

        #判斷 c/s-interface-invoke-type(how to invoke SR)
        #[SWS_Rte_07409]、[SWS_Rte_08904]
        if((component_dict['SR'].get_canBeInvokedConcurrently() == True) and (component_dict['AsynchronousServerCallReturnsEvent'] == None) and (component_dict['SR-task'] == None)):
            if(component_dict['comm-type'] == inter_partition):
                component_dict['c/s-interface-invoke-type'] = trusted_fn_call
            elif(component_dict['comm-type'] == intra_partition):
                component_dict['c/s-interface-invoke-type'] = direct_fn_call
        #優化
        elif((component_dict['SR'].get_canBeInvokedConcurrently() == True) and (component_dict['AsynchronousServerCallReturnsEvent'] == None) and (component_dict['CR-task'] == component_dict['SR-task'])):
            component_dict['c/s-interface-invoke-type'] = direct_fn_call
        else:
            component_dict['c/s-interface-invoke-type'] = in_task

        client_server_component_list.append(component_dict)

    # for component in client_server_component_list:
    #     for key in component:
    #         if(component[key] != None and key != 'comm-type' and key != 'c/s-interface-invoke-type' and key != 'CR_id'):
    #             print(f'{key}:  {colored(os.path.basename(component[key].get_path()), "blue")}')
    #         elif(component[key] != None and key == 'comm-type' or key == 'c/s-interface-invoke-type' or key == 'CR_id'):
    #             print(f'{key}:  {colored(component[key], "blue")}')
    #         else: print(f'{key}:  {colored(None, "red")}')
    #     print('')

def check_server(event_of_swc, rable):
    for event in event_of_swc:
        if((type(event) == OperationInvokedEvent) and (event.get_startOnEvent() == rable)):
            return True

def gen_externData_and_runnable(scp_keys, async_scrp_keys, rable, write_content, event_of_swc, swc, rables_of_swc, client_server_component_list, first_dict):
    swc_name = os.path.basename(swc.get_path())
    rable_name = os.path.basename(rable.get_path())
    # print_object(rable)
    # print_test(scp_keys)
    #判斷是 client / client_response / server runnable
    if(len(scp_keys) > 0): #client runnable
        sync_rte_call = False
        for scp in scp_keys:
            if(type(scp) == SynchronousServerCallPoint): sync_rte_call = True
            break
        if(sync_rte_call == True): #in sync_rte_call case, client runnable needs response ringbuffer
            write_content.extend([
                '',
                f'extern RingBuffer RB_response_{rable_name};',
            ])
            if(first_dict['CR']):
                write_content[-1] += '//if client use sync_rte_call to get the response, each client runnable has its own response ringbuffer.'
        write_content.extend([
            f'extern int request_number_{rable_name};',
            f'FUNC(Impl_uint16, AUTOMATIC) {rable_name}();',
            f'#define RTE_RUNNABLE_{rable_name} {rable_name};',
            '',
        ])
        if(first_dict['CR']): 
            write_content[-4] += '//shared by 1 specific client response runnable'
            write_content[-3] += '//[SWS_Rte_07194] \'Impl_uint16\' only for test case, return value will be \'void\' in real case'
            write_content[-2] += '//[SWS_Rte_06713]'
        first_dict['CR'] = False

    if(len(async_scrp_keys) > 0): #client response runnable
        for component in client_server_component_list: #client runnable 和 client response runnable 在不同 swc 的情況
            if(component['CRR'] == rable):
                if component['CR'] not in rables_of_swc:
                    write_content.extend([
                        f'#include "Rte_{swc_name}.h"', 
                    ])
        write_content.extend([
            '',
            f'extern RingBuffer RB_response_{rable_name};',
        ])
        if(first_dict['CRR']):
            write_content[-1] += '//if client use Rte_result to get the response, each client response runnable has its own response ringbuffer.'
            write_content.extend([
                '//Runnable declaration shouldn\'t be put btw #ifdef~#endif, otherise, os application can\'t access it.',
            ])
        write_content.extend([
            f'FUNC(Impl_uint16, AUTOMATIC) {rable_name}();',
            f'#define RTE_RUNNABLE_{rable_name} {rable_name};',
            '',
        ])
        if(first_dict['CRR']):
            write_content[-3] += '//Impl_uint16 of return value is for testing'
        first_dict['CRR'] = False
    
    if(check_server(event_of_swc, rable)): #server runnable
        write_content.extend([
            '',
            f'extern RingBuffer RB_request_{rable_name};',
        ])
        if(first_dict['SR']):
            write_content[-1] += '//each server runnable has its own request buffer.'
        write_content.extend([
            f'FUNC(Impl_uint16, AUTOMATIC) {rable_name}();',
            f'#define RTE_RUNNABLE_{rable_name} {rable_name};',
            '',
        ])
        first_dict['SR'] = False

def gen_runnable_specific_RTEapi(scp_keys, async_scrp_keys, rable, write_content, event_of_swc, swc, rables_of_swc, client_server_component_list, dataType_mappingSets):
    swc_name = os.path.basename(swc.get_path())
    rable_name = os.path.basename(rable.get_path())
    # print_object(rable)
    # print_test(scp_keys)
    #存取權保護
    write_content.extend([
        f'#ifdef RTE_{rable_name}_C',
    ])

    #判斷是 client / client_response / server runnable
    if(len(scp_keys) > 0): #client runnable
        #CR 需要判斷 comm. type
        for component in client_server_component_list:
            # print(rable)
            # print(component['CR'])
            # print('\n')
            if(component['CR'] == rable):
                write_content.extend([
                    f"/*{component['comm-type']}*/",
                ])
                break
        #宣告 Rte_Call
        for scp in scp_keys:
            r_port = scp.get_operation().get_contextRPort()
            r_port_name = os.path.basename(r_port.get_path())
            op = scp.get_operation().get_targetRequiredOperation()
            op_name = op.get_shortName().split('_')[0]
            # print(op_name)
            # print(op.get_shortName())
            op_args = scp.get_operation().get_targetRequiredOperation().get_arguments()
            DT_app = list(op_args)[0].get_type()
            # print_test(op_args)
            DT_impl = None
            DT_impl_name = None
            #找出 arg 對應的 DT_impl
            for DT_mappingSet_instance in dataType_mappingSets:
                # print(DT_mappingSet_instance)
                # print(type(DT_mappingSet_instance))
                DT_maps = DT_mappingSet_instance.get_dataTypeMaps()
                for DT_map in DT_maps:
                    # print(list(op_args)[0].get_type())
                    if((DT_map.get_applicationDataType() == DT_app)):
                        DT_impl = DT_map.get_implementationDataType()
                        DT_impl_name = os.path.basename(DT_impl.get_path())
                        break
                        # print(DT_impl)
                        # print('\n')

            #判斷 comm_type
            comm_type = None
            for component in client_server_component_list:
                if(component['CR'] == rable):
                    if(component['comm-type'] == intra_partition):
                        comm_type = 'Rte'
                    elif(component['comm-type'] == inter_partition):
                        comm_type = 'Ioc'
                    elif(component['comm-type'] == inter_ECU):
                        comm_type = 'Com'
                    break

            if(type(scp) == SynchronousServerCallPoint):
                write_content.extend([
                    f'Std_ReturnType Rte_Call_{r_port_name}_Sync{comm_type}{op_name}_{rable_name}({DT_impl_name}, {DT_impl_name}, {DT_impl_name}*);',
                ])
            else:
                write_content.extend([
                    f'Std_ReturnType Rte_Call_{r_port_name}_AsyncRte{comm_type}{op_name}_{rable_name}({DT_impl_name}, {DT_impl_name});',
                ])

    if(len(async_scrp_keys) > 0): #client response runnable
        #宣告 Rte_Result
        for async_scrp in async_scrp_keys:
            r_port = async_scrp.get_asynchronousServerCallPoint().get_operation().get_contextRPort()
            r_port_name = os.path.basename(r_port.get_path())
            # print(r_port)
            op_args = async_scrp.get_asynchronousServerCallPoint().get_operation().get_targetRequiredOperation().get_arguments()
            DT_app = list(op_args)[0].get_type()
            # print_test(op_args)
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

            WPs = rable.get_waitPoints()
            nonblock_falg = True
            for wp in WPs:
                if(type(wp.get_trigger()) == AsynchronousServerCallReturnsEvent):
                    write_content.extend([
                        f'Std_ReturnType Rte_Result_{r_port_name}_Blocking_{rable_name}({DT_impl_name}*);',
                    ])
                    nonblock_falg = False
                    break
            # print(nonblock_falg)
            if(nonblock_falg):
                write_content.extend([
                    f'Std_ReturnType Rte_Result_{r_port_name}_NonBlocking_{rable_name}({DT_impl_name}*);',
                ])

    if(check_server(event_of_swc, rable)): #server runnable
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
        DT_impl_name = None
        #找出 arg 對應的 DT_impl
        for DT_mappingSet_instance in dataType_mappingSets:
            DT_maps = DT_mappingSet_instance.get_dataTypeMaps()
            for DT_map in DT_maps:
                if((DT_map.get_applicationDataType() == DT_app)):
                    DT_impl = DT_map.get_implementationDataType()
                    DT_impl_name = os.path.basename(DT_impl.get_path())
                    break
        #宣告 server operation
        write_content.extend([
            f'{DT_impl_name} {op_name}_{rable_name}();',
        ])

    #存取權保護
    write_content.extend([
        f'#endif',
    ])

def gen_app_h(swc, client_server_component_list, dataType_mappingSets):
    # print_object(swc)
    rables_of_swc = [] #儲存一個 swc 的所有 runnables
    event_of_swc = [] #儲存一個 swc 的所有 events
    swc_ib_keys = swc.get_internalBehaviors() #internal behaviors
    # print_test(swc_ib_keys)
    # print(type(_swc_client_ib_keys)) #dict.keys
    
    for ib_key in swc_ib_keys:
        swc_ib_rable_keys = ib_key.get_runnables() #runnables
        event_keys = ib_key.get_events() #rte events
        # print_test(swc_ib_rable_keys)
        rables_of_swc.extend(swc_ib_rable_keys)
        event_of_swc.extend(event_keys)
        # print_test(swc_ib_ev_keys)
    # print_test(rables_of_swc)

    swc_name = os.path.basename(swc.get_path())
    dir_path = f'./generated/{swc_name}'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = f'Rte_{swc_name}.h'
    file_path = os.path.join(dir_path, target_file_name)
    
    write_content = []
    write_content.extend([
        '//VFB interface(api) & Runnable Declaration',
        '//----------------------------------------------------------------',
        f'#ifndef RTE_{swc_name.upper()}_H',
        f'#define RTE_{swc_name.upper()}_H',
        '',
        '#ifdef __cplusplus /* [SWS_Rte_07125] */',
        'extern "C" {',
        '#endif /* __cplusplus */',
        '',
        f'#include "Rte_{swc_name}_Type.h"',
        '#include "../Rte_Cs_Data_Management.h"',
    ])
    
    first_dict = {'CR': True, 'CRR': True, 'SR': True}
    for rable in rables_of_swc:
        # print(len(rables_of_swc))
        scp_keys = rable.get_serverCallPoints()
        async_scrp_keys = rable.get_asynchronousServerCallResultPoints()
        gen_externData_and_runnable(scp_keys, async_scrp_keys, rable, write_content, event_of_swc, swc, rables_of_swc, client_server_component_list, first_dict)
    
    write_content.extend([
        '/********************************************/',
        f'//make sure only specific runnable.c can invoke these functions.',
    ])

    for rable in rables_of_swc:
        scp_keys = rable.get_serverCallPoints()
        async_scrp_keys = rable.get_asynchronousServerCallResultPoints()
        gen_runnable_specific_RTEapi(scp_keys, async_scrp_keys, rable, write_content, event_of_swc, swc, rables_of_swc, client_server_component_list, dataType_mappingSets)
    
    write_content.extend([
        '/********************************************/',
        '',
        '#ifdef __cplusplus /* [SWS_Rte_07126]  */',
        '} /* extern "C" */',
        '#endif /* __cplusplus */',
        '',
        f'#endif /* RTE_{swc_name.upper()}_H */',
    ])
    
    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

def main():
    for ele in swc_dict:
        gen_app_h(swc_dict[ele], client_server_component_list, dataType_mappingSets)

# ecuc_file_paths = input('Please enter the paths of ecuc descrptions, separated by (semicolon + space) : ') 
# swc_file_paths = input('Please enter the paths of software component descrptions, separated by (semicolon + space) : ')
ecuc_file_paths = './ARXML/ecuc'
swc_file_paths = './ARXML/swc'
ecuc_file_paths_list = [path.strip() for path in ecuc_file_paths.split('; ')]
swc_file_paths_list = [path.strip() for path in swc_file_paths.split('; ')]
# print(ecuc_file_paths_list)
# print(swc_file_paths_list)
all_file_paths_list = ecuc_file_paths_list + swc_file_paths_list
# print(all_file_paths_list)
read_return = autosarfactory.read(all_file_paths_list)
autosar_root_node = read_return[0]
# print(autosar_root_node)
arpackages_list = list(autosar_root_node.get_arPackages())
# print(arpackages_list)
ActiveEcuC, Rte, Os0 = None, None, None
for arpackage in arpackages_list:
    if(arpackage.get_shortName() == 'ActiveEcuC'):
        ActiveEcuC = arpackage
        break
for ele in ActiveEcuC.get_elements():
    if(ele.get_shortName() == 'Rte'):
        Rte = ele
    elif(ele.get_shortName() == 'Os0'):
        Os0 = ele
# print(ActiveEcuC, Rte, Os0)

#1. 用 arnode_query.find_arnode 能讓你快速找到某 class 的所有 instance (dict 'key:value' 為 '路徑:類別')。
#2. 用 autosarfactory 的 get fn. 則能讓你容易看出 object 的上下階層關係，但回傳的是 dict.keys，
#且 key 代表 '類別'，'透過list轉型' 抓出某個 key 才能再用其他 autosarfactory fn.)
swc_dict = arnode_query.find_arnode(arpackages_list, ApplicationSwComponentType) #swc
# print(swc_dict) #dict

client_server_component_list = [] #儲存一個 C/S comm. 需要的 client, client_response, server runnables, operationInvoked event, AsynchronousServerCallReturnsEvent, comm. type(inter-ECU, inter-partition, intra-partition). (sync case 不會有 client response runnable)
RteEventToTaskMapping_keys = []
set_client_server_component_list(arpackages_list, Rte, Os0, client_server_component_list, RteEventToTaskMapping_keys)

dataType_mappingSets = []
for arpackage in arpackages_list:
    if(arpackage.get_shortName() == 'CS_Composition'):
        arpackages_CS_Composition = arpackage.get_arPackages()
        for pack_cs in arpackages_CS_Composition:
            if(pack_cs.get_shortName() == 'Datatypes'):
                # print(pack_cs.get_shortName())
                packs_Datatypes = pack_cs.get_arPackages()
                # print(packs_Datatypes)
                for pack_data in packs_Datatypes:
                    # print(pack_data)
                    if(type(list(pack_data.get_elements())[0]) == DataTypeMappingSet):
                        for mappingSet in pack_data.get_elements():
                            dataType_mappingSets.append(mappingSet)

if __name__ == '__main__':
    main()
