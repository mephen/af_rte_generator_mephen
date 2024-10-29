#將 parser 做模組化，每種 RTE API 都有對應的 generator function，方便日後整合。
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
    , ApplicationPrimitiveDataType, ImplementationDataType, DataTypeMappingSet\
    , BackgroundEvent, TimingEvent, InitEvent, SwcModeSwitchEvent, OperationInvokedEvent, AsynchronousServerCallReturnsEvent 

class eventToTaskMapping_Item:
    def __init__(self, attr1, attr2, attr3, attr4):
        self.task_name = attr1
        self.alarm_name = attr2
        self.initContainer_name = attr3
        self.position_in_task = attr4

class event_order_Item:
    def __init__(self, attr1, attr2, attr3):
        self.event_path = attr1
        self.task_name = attr2
        self.position_in_task = attr3

def print_object(obj):
    if(type(obj) == type(None)):
        print('None')
    else:
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

def find_taskToAppMapping_eventToTaskMapping(used_app, task_to_app_mapping, event_to_task_mapping):
    for container in Os0.get_containers():
        if(type(container.get_definition()) == type(None)):
            continue
        if(os.path.basename(container.get_definition()) == 'OsTask'):
            refs = container.get_referenceValues()
            for ref in refs:
                if(os.path.basename(ref.get_definition()) == 'OsTaskAccessingApplication'):
                    task_name = container.get_shortName()
                    app_ref = ref.get_value()
                    osTask_appRef_dict.update({f'{task_name}' : app_ref})
    
    task_to_app_mapping.update({'T01': 'App1'}) #RTE Task(專門處理 Timing event)
    
    print('----------------- eventToTaskMapping:-----------------')
    for ev_map in RteEventToTaskMapping_keys:
        refs = ev_map.get_referenceValues()
        task_name = None
        ev_name = None
        alarm_name = None
        initContainer_name = None
        position_in_task = None

        for ref in refs:
            if(os.path.basename(ref.get_definition()) == 'RteEventRef'):
                ev_ref = ref.get_value()
                ev_name = os.path.basename(ev_ref.get_path())
            if(os.path.basename(ref.get_definition()) == 'RteMappedToTaskRef'):
                task_ref = ref.get_value()
                task_name = task_ref.get_shortName()
                if task_ref not in task_to_app_mapping.keys():
                    # print(osTask_appRef_dict[task_ref.get_shortName()])
                    app = osTask_appRef_dict[task_ref.get_shortName()].get_shortName()
                    if app not in used_app:
                        used_app.append(app)
                    task_to_app_mapping.update({task_ref.get_shortName(): osTask_appRef_dict[task_ref.get_shortName()].get_shortName()})
            if(os.path.basename(ref.get_definition()) == 'RteUsedOsAlarmRef'):
                alarm_ref = ref.get_value()
                alarm_name = os.path.basename(alarm_ref.get_path())
                # print(alarm_name)
            if(os.path.basename(ref.get_definition()) == 'RteUsedInitFnc'):
                initContainer_name = os.path.basename(ref.get_value().get_path())
                # print(initContainer_name)
        
        paras = ev_map.get_parameterValues()
        for para in paras:
            if(os.path.basename(para.get_definition()) == 'RtePositionInTask'):
                position_in_task = para.get_value().get()
        
        event_to_task_mapping.update({ev_name: eventToTaskMapping_Item(task_name, alarm_name, initContainer_name, position_in_task)})
        print(ev_name, ",", event_to_task_mapping[ev_name].task_name, ",", event_to_task_mapping[ev_name].alarm_name, ",", event_to_task_mapping[ev_name].initContainer_name, ",", event_to_task_mapping[ev_name].position_in_task)
    print('------------------------------------------------------')

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

def set_client_server_component_list(arpackages_list, Rte, Os0, client_server_component_list, RteEventToTaskMapping_keys):
    osTask_appRef_dict = {} #osTask 被 map 到哪個 app
    app_ecucRef_dict = {} #app 被 map 到哪個 ecuc
    swc_instance_keys = [] #swc 在 os 上的 instances
    # print(Os0.get_containers())
    for container in Os0.get_containers():
        if(type(container.get_definition()) == type(None)):
            continue
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
        # print(container)
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

    # 不知道為什麼 AsynchronousServerCallReturnsEvent 抓不到 startOnEvent，只好在 parser 設定 startOnEvent。
    for ev in ev_dict:
        for rable in rable_dict:
            set_finished = set_AsyncSerCallRetEv_startOnEvent(rable_dict[rable], ev_dict[ev])
            if(set_finished): break
        # if(type(ev_dict[ev])== AsynchronousServerCallReturnsEvent): 
        #     print_object(ev_dict[ev].get_startOnEvent())

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
                        'CRR':None, 'AsynchronousServerCallReturnsEvent': None, 'CRR-task':None, 'Block_NonBlock' :None,\
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
                            WPs = crr.get_waitPoints()
                            nonblock_flag = True
                            for wp in WPs:
                                if(type(wp.get_trigger()) == AsynchronousServerCallReturnsEvent):
                                    nonblock_flag = False
                                    component_dict['Block_NonBlock'] = 'blocking'
                                    break
                            if(nonblock_flag):
                                component_dict['Block_NonBlock'] = 'non_blocking'
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
            if((ev_ref != None) and (task_ref != None)):
                if(os.path.basename(ev_ref.get_path()) == os.path.basename(component_dict['start_event'].get_path())): 
                    component_dict['CR-task'] = task_ref
                elif(os.path.basename(ev_ref.get_path()) == os.path.basename(component_dict['operationInvokedEvent'].get_path())):
                    component_dict['SR-task'] = task_ref
                elif((component_dict['AsynchronousServerCallReturnsEvent'] != None) and (os.path.basename(ev_ref.get_path()) == os.path.basename(component_dict['AsynchronousServerCallReturnsEvent'].get_path()))):
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
    #         if(component[key] != None and key != 'comm-type' and key != 'c/s-interface-invoke-type' and key != 'CR_id' and key != 'Block_NonBlock'):
    #             print(f'{key}:  {colored(os.path.basename(component[key].get_path()), "blue")}')
    #         elif(component[key] != None and key == 'comm-type' or key == 'c/s-interface-invoke-type' or key == 'CR_id' or key == 'Block_NonBlock'):
    #             print(f'{key}:  {colored(component[key], "blue")}')
    #         else: print(f'{key}:  {colored(None, "red")}')
    #     print('')

def check_server(event_of_swc, rable):
    for event in event_of_swc:
        if((type(event) == OperationInvokedEvent) and (event.get_startOnEvent() == rable)):
            return True

#client runnable
def gen_externData_CR(scp_keys, rable_name, write_content, first_dict):
    sync_rte_call = False
    for scp in scp_keys:
        if(type(scp) == SynchronousServerCallPoint): sync_rte_call = True
        break
    if(sync_rte_call == True): #in sync_rte_call case, client runnable needs response ringbuffer
        write_content.extend([
            '',
            f'extern RingBuffer RB_response_{rable_name};',
            f'extern int request_number_{rable_name};',
        ])
        if(first_dict['CR']):
            write_content[-2] += '//if client use sync_rte_call to get the response, each client runnable has its own response ringbuffer.'

#client response runnable
def gen_externData_CRR(rable, rables_of_swc, swc_name, rable_name, write_content, first_dict):
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

#server runnable
def gen_externData_SR(rable_name, write_content, first_dict):
    write_content.extend([
        '',
        f'extern RingBuffer RB_request_{rable_name};',
    ])
    if(first_dict['SR']):
        write_content[-1] += '//each server runnable has its own request buffer.'
        first_dict['SR'] = False

def gen_externData_and_runnable(rable, write_content, event_of_swc, swc, rables_of_swc, first_dict):
    swc_name = os.path.basename(swc.get_path())
    rable_name = os.path.basename(rable.get_path())
    scp_keys = rable.get_serverCallPoints()
    async_scrp_keys = rable.get_asynchronousServerCallResultPoints()
    
    #檢查 externData 是否需要宣告
    if(len(scp_keys) > 0): #client runnable
        gen_externData_CR(scp_keys, rable_name, write_content, first_dict)
    if(len(async_scrp_keys) > 0): #client response runnable
        gen_externData_CRR(rable, rables_of_swc, swc_name, rable_name, write_content, first_dict)
    if(check_server(event_of_swc, rable)): #server runnable
        gen_externData_SR(rable_name, write_content, first_dict)

    #宣告 runnable
    if(client_server_component_list == []):
        write_content.extend([
            '',
            f'FUNC(void, AUTOMATIC) {rable_name}();',
            f'#define RTE_RUNNABLE_{rable_name} {rable_name}',
            '',
        ])
    else: #test for C/S interface
        write_content.extend([
            '',
            f'FUNC(Impl_uint16, AUTOMATIC) {rable_name}();',
            f'#define RTE_RUNNABLE_{rable_name} {rable_name}',
            '',
        ])


    #註解
    if(len(scp_keys) > 0): #client runnable
        if(first_dict['CR']): 
            write_content[-4] += '//shared by 1 specific client response runnable'
            write_content[-3] += '//[SWS_Rte_07194] \'Impl_uint16\' only for test case, return value will be \'void\' in real case'
            write_content[-2] += '//[SWS_Rte_06713]'
            first_dict['CR'] = False
    if(len(async_scrp_keys) > 0): #client response runnable
        if(first_dict['CRR']):
            write_content[-3] += '//Impl_uint16 of return value is for testing'
            first_dict['CRR'] = False

def gen_Rte_Call(rable, write_content, scp_keys, rable_name):
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

def gen_Rte_Result(async_scrp_keys, rable, write_content, rable_name):
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
        nonblock_flag = True
        for wp in WPs:
            if(type(wp.get_trigger()) == AsynchronousServerCallReturnsEvent):
                write_content.extend([
                    f'Std_ReturnType Rte_Result_{r_port_name}_Blocking_{rable_name}({DT_impl_name}*);',
                ])
                nonblock_flag = False
                break
        # print(nonblock_flag)
        if(nonblock_flag):
            write_content.extend([
                f'Std_ReturnType Rte_Result_{r_port_name}_NonBlocking_{rable_name}({DT_impl_name}*);',
            ])

def gen_Server_Opt(event_of_swc, write_content, rable, rable_name):
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
        gen_Rte_Call(rable, write_content, scp_keys, rable_name)
    if(len(async_scrp_keys) > 0): #client response runnable
        gen_Rte_Result(async_scrp_keys, rable, write_content, rable_name)
    if(check_server(event_of_swc, rable)): #server runnable
        gen_Server_Opt(event_of_swc, write_content, rable, rable_name)
    

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
    ])
    if client_server_component_list != []:
        write_content.extend([
            '#include "../Rte_Cs_Data_Management.h"',
        ])
    
    first_dict = {'CR': True, 'CRR': True, 'SR': True}
    for rable in rables_of_swc:
        # print(len(rables_of_swc))
        gen_externData_and_runnable(rable, write_content, event_of_swc, swc, rables_of_swc, first_dict)
    
    write_content.extend([
        '',
        '/********************************************/',
        '//Runnable declaration shouldn\'t be put btw #ifdef~#endif, otherise, os application can\'t access it.',
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

def gen_Rte_Cs_Data_Management_h():
    if(client_server_component_list == []):
        return

    dir_path = './generated'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = 'Rte_Cs_Data_Management.h'
    file_path = os.path.join(dir_path, target_file_name)
    write_content = []

    write_content.extend([
        '#ifndef RTE_CS_DATA_MANAGEMENT_H',
        '#define RTE_CS_DATA_MANAGEMENT_H',
        '',
        '#include "ringbuffer.h"',
        '#include "Rte_Type.h"',
        '',
        '//per core: Rte internal buffer of intra-parition communication',
        '//for application and client_runnable',
        'extern RingBuffer RB_requestInfo_core0; //client -> server intra-partition communication (store Request information: parameters & sequence_counter)',
        'extern RingBuffer RB_responseInfo_core0; //server -> client intra-partition communication (store response information: ResponseInfoType)',
        'extern RingBuffer RB_requestInfo_core1;',
        'extern RingBuffer RB_responseInfo_core1;',
        '',
        '//per core: transformer buffer for transformer use',
        '//for application and client_runnable',
        '//RTE should provide transformer buffer',
        'extern RingBuffer RB_transformer_core0;',
        'extern RingBuffer RB_transformer_core1;',
        '',
        '//per pair of a client_runnable and a client_response_runnable',
    ])
    
    for ele in swc_dict:
        swc = swc_dict[ele]
        rables_of_swc = [] #儲存一個 swc 的所有 runnables
        event_of_swc = [] #儲存一個 swc 的所有 events
        swc_ib_keys = swc.get_internalBehaviors() #internal behaviors
        
        for ib_key in swc_ib_keys:
            swc_ib_rable_keys = ib_key.get_runnables() #runnables
            event_keys = ib_key.get_events() #rte events
            # print_test(swc_ib_rable_keys)
            rables_of_swc.extend(swc_ib_rable_keys)
            event_of_swc.extend(event_keys)

        first_RB_retrunValue = False
        for rable in rables_of_swc:
            scp_keys = rable.get_serverCallPoints()
            if(len(scp_keys) > 0):
                for scp in scp_keys:
                    if(type(scp) == AsynchronousServerCallPoint):
                        rable_name = rable.get_shortName()
                        RB_returnValue_str = None
                        if(first_RB_retrunValue == False): 
                            write_content.extend([
                                f'extern RingBuffer RB_returnValue_{rable_name}; //for CRR to get the return_value of CR',
                            ])
                            first_RB_retrunValue = True
                        else:
                            write_content.extend([
                                f'extern RingBuffer RB_returnValue_{rable_name};',
                            ])
                        break
    
    num_of_in_task_CS_comm = 0
    for component in client_server_component_list:
        if(component['c/s-interface-invoke-type'] == in_task):
            num_of_in_task_CS_comm += 1

    write_content.extend([
        '',
        '//shared by one board(include 2 cores)',
        f'extern Rte_Cs_metaData rte_cs_metaData_arr[{num_of_in_task_CS_comm}];',
        '',
        '#endif // RTE_DATA_MANAGEMENT_H',
    ])

    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

def gen_Rte_Event_Cfg_h():
    dir_path = './generated'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = 'Rte_Event_Cfg.h'
    file_path = os.path.join(dir_path, target_file_name)

    write_content = []

    #event related function
    write_content.extend([
        '#ifndef RTE_EVENT_CFG_H',
        '#define RTE_EVENT_CFG_H',
        '#include "Rte_Type.h"',
    ])
    for key in swc_dict:
        swc_name = swc_dict[key].get_shortName()
        write_content.extend([
            f'#include "{swc_name}/Rte_{swc_name}.h"',
        ])
    write_content.extend([
        '',
        '//RteEvent common status',
        '#define get_rteevent_counter(event) event->status_uint16 & 0x0F',
        '#define trigger_rteevent(event) \\',
        '    if((event->status_uint16 & 0x0F) == 0x0F){ \\',
        '        event->status_uint16 &= 0xFFF0;\\',
        '    }else{ \\',
        '        event->status_uint16 += 1; \\',
        '    }',
        '#define release_rteevent(event) \\',
        '    if((event->status_uint16 & 0x0F) == 0x00){ \\',
        '        event->status_uint16 &= 0xFFF0;\\',
        '    }else{ \\',
        '        event->status_uint16 -= 1; \\',
        '    }',
        '',
        '#define TimingEvent 0x0000',
        '#define BackgroundEvent 0x0010',
        '#define DataReceivedEvent 0x0020',
        '#define DataReceiveErrorEvent 0x0030',
        '#define DataSendCompletedEvent 0x0040',
        '#define DataWriteCompletedEvent 0x0050',
        '#define OperationInvokedEvent 0x0060',
        '#define AsynchronousServerCallReturnsEvent 0x0070',
        '#define SwcModeSwitchEvent 0x0080',
        '#define ModeSwitchedAckEvent 0x0090',
        '#define SwcModeManagerErrorEvent 0x00A0',
        '#define ExternalTriggerOccurredEvent 0x00B0',
        '#define InternalTriggerOccurredEvent 0x00C0',
        '#define InitEvent 0x00D0',
        '#define TransformerHardErrorEvent 0x00E0',
        '#define OsTaskExecutionEvent 0x00F0',
        '#define get_rteevent_type(event) (event->status_uint16 & 0x1F0)',
        '',
        '#define get_rteevent_disablemode(event) ((event->status_uint16 & 0x200) >> 9)',
        '#define set_rteevent_disablemode(event) event->status_uint16 |= 0x200',
        '#define clear_rteevent_disablemode(event) event->status_uint16 &= ~(0x200)',
        '',
        '#define get_runnable_execute(event) (event->status_uint16 & 0x400) >> 10',
        '#define set_runnable_execute(event) event->status_uint16 |= 0x400',
        '#define clear_runnable_execute(event) event->status_uint16 &= ~(0x400)',
        '',
        '//RteEvent subclass specific status',
        '    //InitEvent: 11th-12th bit for trigger runnable type.',
        '#define ClientRunnable 0x000',
        '#define get_trigger_runnable_type(event) (event->status_uint16 & 0x1800)',
        '    //OperationInvokedEvent: 11th-12th bit for communication type.(bit start from 0)',
        '#define InterEcu 0x000',
        '#define InterPartition 0x800',
        '#define IntraPartition 0x1000',
        '#define get_communication_type(event) (event->status_uint16 & 0x1800)',
        '    //other RteEvent subclass specific status(if needed)',
        '',
        '',
    ])

    #event array of different task
    write_content.extend([
        '//event array of different task',
    ])
    task_ev_len_arr = {}
    for task_name in task_to_app_mapping:
        task_ev_len = 0
        for ev_name in event_to_task_mapping.keys():
            if(event_to_task_mapping[ev_name].task_name == task_name):
                task_ev_len += 1
        # for component in client_server_component_list:
        #     if(component['c/s-interface-invoke-type'] == in_task):
        #         if(component['CR-task'].get_shortName() == task_name):  task_ev_len += 1
        #         if(component['SR-task'].get_shortName() == task_name):  task_ev_len += 1
        #         if((component['CRR-task'] != None) and (component['CRR-task'].get_shortName() == task_name)):  task_ev_len += 1
        task_ev_len_arr.update({task_name.lower(): task_ev_len})
    for task_name in task_ev_len_arr.keys():
        # print(task_ev_len)
        task_ev_len = task_ev_len_arr[task_name]
        write_content.extend([
            f'extern RteEvent* rte_event_{task_name}[{task_ev_len}];',
        ])

    # for ev in ev_dict.values():
    #     print(ev.get_shortName())

    #event name macro
    write_content.extend([
        '',
        '//Use macro instead of index to access rte_event array',
        '//The event order in task_ev_arr is important, should follow the c/s comm. flow (init_ev -> op_ev -> async_return_ev)',
        '//(when parsing arxml) according to the runnables that are mapped to task x, find the RTEEvents that task x can use',
    ])

    for task_name in task_to_app_mapping:
        write_content.extend([
            f'//task {task_name}',
        ])
        
        event_array_index = 0
        
        ev_Background_macro = ''
        ev_Timing_macro = ''
        ev_Init_macro = ''
        ev_Modeswitch_macro = ''
        ev_OpInvok_macro = ''
        ev_AsyncReturn_macro = ''
        
        ev_Background_extern = ''
        ev_Timing_extern = ''
        ev_Init_extern = ''
        ev_Modeswitch_extern = ''
        ev_OpInvok_extern = ''
        ev_AsyncReturn_extern = ''

        ev_order_list_item = None #event_path, task_name, position_in_task
        ev_order_list_item_sameTask = [] #儲存 ev_order_list_item

        for ev_path in ev_dict:
            ev_name = os.path.basename(ev_dict[ev_path].get_path())
            # print(type(ev_dict[ev_path]))
            if(event_to_task_mapping[ev_name].task_name == task_name):
                if(type(ev_dict[ev_path]) == BackgroundEvent):
                    ev_Background_extern += f'extern RteEvent {ev_name}; \n'
                    if(event_to_task_mapping[ev_name].position_in_task != None):
                        position_in_task = event_to_task_mapping[ev_name].position_in_task
                        ev_Background_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index -1 + int(position_in_task)} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index -1 + int(position_in_task))
                        event_array_index -= 1 #避免 event_array_index+1 造成的誤差 
                    else:
                        ev_Background_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index)
                elif(type(ev_dict[ev_path]) == TimingEvent):
                    ev_Timing_extern += f'extern RteEvent {ev_name}; \n'
                    if(event_to_task_mapping[ev_name].position_in_task != None):
                        position_in_task = event_to_task_mapping[ev_name].position_in_task
                        ev_Timing_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index -1 + int(position_in_task)} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index -1 + int(position_in_task))
                        event_array_index -= 1 
                    else:
                        ev_Timing_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index)
                elif(type(ev_dict[ev_path]) == InitEvent):
                    ev_Init_extern += f'extern RteEvent {ev_name}; \n'
                    if(event_to_task_mapping[ev_name].position_in_task != None):
                        position_in_task = event_to_task_mapping[ev_name].position_in_task
                        ev_Init_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index -1 + int(position_in_task)} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index -1 + int(position_in_task))
                        event_array_index -= 1 
                    else:
                        ev_Init_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index)
                elif(type(ev_dict[ev_path]) == SwcModeSwitchEvent):
                    ev_Modeswitch_extern += f'extern RteEvent {ev_name}; \n'
                    if(event_to_task_mapping[ev_name].position_in_task != None):
                        position_in_task = event_to_task_mapping[ev_name].position_in_task
                        ev_Modeswitch_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index -1 + int(position_in_task)} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index -1 + int(position_in_task))
                        event_array_index -= 1 
                    else:
                        ev_Modeswitch_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index)
                elif(type(ev_dict[ev_path]) == OperationInvokedEvent):
                    ev_OpInvok_extern += f'extern RteEvent {ev_name}; \n'
                    if(event_to_task_mapping[ev_name].position_in_task != None):
                        position_in_task = event_to_task_mapping[ev_name].position_in_task
                        ev_OpInvok_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index -1 + int(position_in_task)} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index -1 + int(position_in_task))
                        event_array_index -= 1 
                    else:
                        ev_OpInvok_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index)
                elif(type(ev_dict[ev_path]) == AsynchronousServerCallReturnsEvent):
                    ev_AsyncReturn_extern += f'extern RteEvent {ev_name}; \n'
                    if(event_to_task_mapping[ev_name].position_in_task != None):
                        position_in_task = event_to_task_mapping[ev_name].position_in_task
                        ev_AsyncReturn_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index -1 + int(position_in_task)} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index -1 + int(position_in_task))
                        event_array_index -= 1 
                    else:
                        ev_AsyncReturn_macro += f'#define {ev_name}_{task_name.lower()} {event_array_index} \n'
                        ev_order_list_item = event_order_Item(ev_path, task_name, event_array_index)
                event_array_index += 1
                ev_order_list_item_sameTask.append(ev_order_list_item)
        
        #對同個 task event array 的 event 依種類和順序排序
        same_category_start = 0
        same_category_end = 0 #排序時不包含
        for index, ev_order_item in enumerate(ev_order_list_item_sameTask):
            ev_path = ev_order_list_item_sameTask[index].event_path
            if index+1 != len(ev_order_list_item_sameTask):
                next_ev_path = ev_order_list_item_sameTask[index+1].event_path
                # print(ev_dict[ev_path].get_shortName())
                # print(ev_dict[next_ev_path].get_shortName())
                if(type(ev_dict[ev_path]) == type(ev_dict[next_ev_path])):
                    same_category_end += 1
                    # print("same")
                else:
                    ev_order_list_item_sameTask = ev_order_list_item_sameTask[same_category_start : same_category_end] = sorted(ev_order_list_item_sameTask[same_category_start : same_category_end], key=lambda x: x.position_in_task)
                    same_category_start = index + 1
                    same_category_end = same_category_start
                    # print("diff")
                if index+1 == len(ev_order_list_item_sameTask)-1:
                    ev_order_list_item_sameTask = ev_order_list_item_sameTask[same_category_start : same_category_end+1] = sorted(ev_order_list_item_sameTask[same_category_start : same_category_end+1], key=lambda x: x.position_in_task)
        
        ev_order_list.extend(ev_order_list_item_sameTask)

        write_content.extend([
            ev_Background_extern + ev_Timing_extern + ev_Init_extern + ev_Modeswitch_extern + ev_OpInvok_extern + ev_AsyncReturn_extern + \
            ev_Background_macro + ev_Timing_macro + ev_Init_macro + ev_Modeswitch_macro + ev_OpInvok_macro + ev_AsyncReturn_macro,
        ])
        
        # event_array_index = 0
        # ev_ClientStart_macro = []
        # ev_OpInvok_macro = []
        # ev_AsyncReturn_macro = []
        # ev_ClientStart_extern = ''
        # ev_OpInvok_extern = ''
        # ev_AsyncReturn_extern = ''

        # for component in client_server_component_list:
        #     if(component['c/s-interface-invoke-type'] == in_task):
        #         if((component['start_event'] != None) and (component['CR-task'].get_shortName() == task_name)):
        #             ev_ClientStart_extern += f'extern RteEvent {component["start_event"].get_shortName()}; \n'
        #             ev_ClientStart_macro.append(f'#define {component["start_event"].get_shortName()}_{task_name.lower()}')
        #         if((component['operationInvokedEvent'] != None) and (component['SR-task'].get_shortName() == task_name)):
        #             ev_OpInvok_extern += f'extern RteEvent {component["operationInvokedEvent"].get_shortName()}; \n'
        #             ev_OpInvok_macro.append(f'#define {component["operationInvokedEvent"].get_shortName()}_{task_name.lower()}')
        #         if((component['AsynchronousServerCallReturnsEvent'] != None) and (component['CRR-task'].get_shortName() == task_name)):
        #             ev_AsyncReturn_extern += f'extern RteEvent {component["AsynchronousServerCallReturnsEvent"].get_shortName()}; \n'
        #             ev_AsyncReturn_macro.append(f'#define {component["AsynchronousServerCallReturnsEvent"].get_shortName()}_{task_name.lower()}')

        # for index in range(len(ev_ClientStart_macro)):
        #     ev_ClientStart_macro[index] += f' {event_array_index} \n'
        #     event_array_index += 1
        # for index in range(len(ev_OpInvok_macro)):
        #     ev_OpInvok_macro[index] += f' {event_array_index} \n'
        #     event_array_index += 1
        # for index in range(len(ev_AsyncReturn_macro)):
        #     ev_AsyncReturn_macro[index] += f' {event_array_index} \n'
        #     event_array_index += 1
        # write_content.extend([
        #     ev_ClientStart_extern + ev_OpInvok_extern + ev_AsyncReturn_extern,
        #     ev_ClientStart_macro + ev_OpInvok_macro + ev_AsyncReturn_macro,
        # ])
    
    write_content.extend([
        '#endif//RTE_EVENT_CFG_H',
    ])

    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

#comm-type
inter_ECU = 'inter_ECU'
inter_partition = 'inter_partition'
intra_partition = 'intra_partition'
#c/s-interface-invoke-type
in_task = 'in_task'
direct_fn_call = 'direct_fn_call'
trusted_fn_call = 'trusted_fn_call'

osTask_appRef_dict = {} #osTask 被 map 到哪個 app
used_app = []
task_to_app_mapping = {} #key: task_name, value: app

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
# print(autosar_root_node._AUTOSAR__arPackages)
# print(dir(arpackages_list[0]))
# print(arpackages_list[0].get_elements())
# print(arpackages_list[1].get_arPackages())

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
swc_dict = arnode_query.find_arnode(arpackages_list, ApplicationSwComponentType) #swc
rable_dict = arnode_query.find_arnode(arpackages_list, RunnableEntity)
ev_dict = arnode_query.find_arnode(arpackages_list, RTEEvent)
sorted_ev_dict = dict(sorted(ev_dict.items(), key=lambda x:str(x[1]))) #把相同種類的 event 放在一起
ev_dict = sorted_ev_dict
# print(ev_dict.values())

ev_order_list = [] #event ordered by its position in task(if it has)，儲存 event_order_Item

client_server_component_list = [] #儲存一個 C/S comm. 需要的 client, client_response, server runnables, operationInvoked event, AsynchronousServerCallReturnsEvent, comm. type(inter-ECU, inter-partition, intra-partition). (sync case 不會有 client response runnable)
RteEventToTaskMapping_keys = [] #儲存有哪些 RteEventToTaskMapping
event_to_task_mapping = {} #key: event_name, value: eventToTaskMapping_Item

set_client_server_component_list(arpackages_list, Rte, Os0, client_server_component_list, RteEventToTaskMapping_keys)
# print(RteEventToTaskMapping_keys)
find_taskToAppMapping_eventToTaskMapping(used_app, task_to_app_mapping, event_to_task_mapping)

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

gen_Rte_Cs_Data_Management_h()
gen_Rte_Event_Cfg_h()
def main():
    for ele in swc_dict:
        gen_app_h(swc_dict[ele], client_server_component_list, dataType_mappingSets)

if __name__ == '__main__':
    main()
    # for ev in ev_order_list:
    #     print(ev_dict[(ev.event_path)].get_shortName(), ev.task_name, ev.position_in_task)
    print(task_to_app_mapping)
