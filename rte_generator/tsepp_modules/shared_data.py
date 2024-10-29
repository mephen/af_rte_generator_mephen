import pdb 

from autosarfactory.autosarfactory import DataTypeMappingSet\
    , RTEEvent, RunnableEntity, SwBaseType, ImplementationDataType\
    , SwComponentType, EcucModuleConfigurationValues,EcucModuleDef\
    , RTEEvent, DataReceivedEvent, AssemblySwConnector, SystemMapping
    
from tsepp_modules import alerting    
from tsepp_modules import arnode_query
from tsepp_modules.arnode_query import  ArxmlConfigurationError
from tsepp_modules.communication_structs import OsApplication\
    , RteEventToTaskMapping, SenderReceiverPair, RteSwComponentInstance\
    , CommunicationBoundaryPair, OsIoc

class SharedData():
    def __init__(self):
        self.__ecuc_module_conf_val_dict = {}
        self.__ecuc_module_def_dict = {}
        self.__system_mapping_dict = {}
        self.__com_ecuc_dict = {}
        self.__swctype_dict = {}
        self.__runnable_dict = {}
        self.__rte_event_dict = {}
        self.__impldatatype_dict = {}
        self.__os_application_dict = {}
        self.__data_type_mapping_set_dict = {}
        self.__sender_receiver_pair_dict = {}
        self.__task_to_osapp_mapping_dict = {}
        self.__rte_sw_component_instance_dict = {}
        self.__runnable_to_task_mapping_dict = {}
        self.__communication_boundary_pair_dict = {}
        self.__runnable_accessing_data_elements_dict = {}
        self.__task_impl_dict = {}
        self.__rte_sw_component_instance_list = []
        self.__os_task_list = []
        self.__os_application_list = []
        self.__os_ioc_ecuc_para_def = None

    def populate_ostask_into_task_impl_dict(self):
        os_task_list = self.get_os_task_list()
        for os_task in os_task_list:
            task_name = os_task.get_shortName()
            self.__task_impl_dict[task_name] = {}
    
    def populate_todo_list_into_task_impl_dict(self): 
        rte_sw_component_instance_dict = self.get_rte_sw_component_instance_dict()
        for rte_sw_component_instance in rte_sw_component_instance_dict.values():
            for rte_event_to_task_mapping in rte_sw_component_instance.rte_event_to_task_mapping_dict.values():
                if rte_event_to_task_mapping.rte_mapped_to_task_ref: 
                    task = rte_event_to_task_mapping.rte_mapped_to_task_ref.get_shortName()
                    rte_event = rte_event_to_task_mapping.rte_event_ref
                    runnable = rte_event_to_task_mapping.rte_event_ref.get_startOnEvent()
                    position = rte_event_to_task_mapping.rte_position_in_task
                    os_object = None
                    if rte_event_to_task_mapping.rte_used_os_alarm_ref: 
                        os_object = rte_event_to_task_mapping.rte_used_os_alarm_ref
                    elif rte_event_to_task_mapping.rte_used_os_event_ref: 
                        os_object = rte_event_to_task_mapping.rte_used_os_event_ref 
                    if position not in self.__task_impl_dict[task]:
                        self.__task_impl_dict[task][position] = []
                    self.__task_impl_dict[task][position].append((os_object, rte_event, runnable))
                
    def populate_runnable_to_task_mapping_dict(self):
        for rte_sw_component_instance in self.__rte_sw_component_instance_dict.values():
            for rte_event_to_task in rte_sw_component_instance.rte_event_to_task_mapping_dict.values(): 
                rte_event = rte_event_to_task.rte_event_ref
                if isinstance(rte_event, RTEEvent):
                    runnable = rte_event.get_startOnEvent()
                    if runnable and runnable not in self.__runnable_to_task_mapping_dict: 
                            self.__runnable_to_task_mapping_dict[runnable] = rte_event_to_task.rte_mapped_to_task_ref
                    # A blocking Rte_Receive API 使用的 runnable 是從 wait point 找, for [SWS_Rte_01290] case
                    elif isinstance(rte_event, DataReceivedEvent):
                        if rte_event.get_data:
                            runnables_dict = shared_data_instance.get_runnable_dict()
                            for runnable in runnables_dict.values():
                                wait_points = runnable.get_waitPoints()
                                if wait_points:
                                    for wait_point in wait_points:
                                        if wait_point.get_trigger() == rte_event:
                                            rte_event_to_task.runnable_wait_for_data_rcv_event = runnable
        
    def populate_rte_event_to_task_mapping_dict(self):
        mapping_dict = {
            'RteMappedToTaskRef': 'rte_mapped_to_task_ref',
            'RtePositionInTask': 'rte_position_in_task',
            'RteOsSchedulePoint': 'rte_os_schedule_point',
            'RteUsedOsEventRef': 'rte_used_os_event_ref',
            'RteUsedOsAlarmRef': 'rte_used_os_alarm_ref',
            'RteUsedOsSchTblExpiryPointRef': 'rte_used_os_sch_tbl_expiry_point_ref',
            'RteImmediateRestart': 'rte_immediate_restart',
            'RteUsedInitFnc': 'rte_used_init_fnc',
            'RteEventPredecessorSyncPointRef': 'rte_event_predecessor_sync_point_ref',
            'RteEventSuccessorSyncPointRef': 'rte_event_successor_sync_point_ref',
            'RteServerQueueLength': 'rte_server_queue_length'
        }

        for swc_instance in self.__rte_sw_component_instance_list:
            rte_event_to_task_mapping_dict = {}
            sub_containers = swc_instance.get_subContainers()
            for sub_container in sub_containers:
                # loop 所有 sub_container 找 RteEventToTaskMapping
                rte_event_path = None
                definition_path = arnode_query.get_definition(sub_container)
                if definition_path.endswith('/RteEventToTaskMapping'):
                    reference_values = sub_container.get_referenceValues()
                    # 基於 RteEventRef 內容值創建 RteEventToTaskMapping instance 來填值 
                    for reference_value in reference_values:
                            ref_v_definition_path = arnode_query.get_definition(reference_value)
                            if ref_v_definition_path.endswith('/RteEventRef'):
                                rte_event = reference_value.get_value()
                                if rte_event: 
                                    rte_event_path = rte_event.get_path() 
                                    rte_event_to_task_mapping_dict[rte_event_path] = RteEventToTaskMapping(rte_event)
                                    break 
                    # 不一定所有 rte_event 都會 mapping to Os-Task
                    if rte_event_path in  rte_event_to_task_mapping_dict:    
                        # 根據類型開始填值 
                        for reference_value in reference_values: 
                            ref_v_definition_path = arnode_query.get_definition(reference_value)
                            if ref_v_definition_path:
                                last_part = ref_v_definition_path.split('/')[-1]
                                attribute_name = mapping_dict.get(last_part)
                                if attribute_name:
                                    # setattr(object, attribute_name ,value)
                                    setattr(rte_event_to_task_mapping_dict[rte_event_path], attribute_name, reference_value.get_value())
                        
                        parameter_values = sub_container.get_parameterValues()
                        for parameter_value in parameter_values:
                            parm_v_definition_path = arnode_query.get_definition(parameter_value)
                            if parm_v_definition_path: 
                                last_part = parm_v_definition_path.split('/')[-1]
                                attribute_name = mapping_dict.get(last_part)
                                if attribute_name:
                                    setattr(rte_event_to_task_mapping_dict[rte_event_path], attribute_name, parameter_value.get_value().get())
            swc_instance_path = swc_instance.get_path()
            if  swc_instance_path not in self.__rte_sw_component_instance_dict:
                self.__rte_sw_component_instance_dict[swc_instance_path] =  RteSwComponentInstance(swc_instance.get_shortName())
            self.__rte_sw_component_instance_dict[swc_instance_path].rte_event_to_task_mapping_dict = rte_event_to_task_mapping_dict 
        return True
    
    def populate_os_application_dict(self):
        mapping_dict = {
            'OsTrusted': 'os_trusted',
            'OsAppAlarmRef': 'os_app_alarm_ref',
            'OsAppCounterRef': 'os_app_counter_ref',
            'OsAppEcucPartitionRef': 'os_app_ecuc_partition_ref',
            'OsApplicationCoreRef': 'os_application_core_ref',
            'OsAppIsrRef': 'os_app_isr_ref',
            'OsAppScheduleTableRef': 'os_app_schedule_table_ref',
            'OsAppTaskRef': 'os_app_task_ref',
            'OsTrustedApplicationDelayTimingViolationCall': 'os_trusted_application_delay_timing_violation_call',
            'OsTrustedApplicationWithProtection': 'os_trusted_application_with_protection',
            'OsMemoryMappingCodeLocationRef': 'os_memory_mapping_code_location_ref',
            'OsRestartTask': 'os_restart_task'
        }

        for os_application in self.__os_application_list:
            os_application_path = os_application.get_path()
            os_application_instance = OsApplication()
            os_application_instance.origin_arnode = os_application 
            reference_values = os_application.get_referenceValues()
            for reference_value in reference_values:
                ref_v_definition_path = arnode_query.get_definition(reference_value)
                if ref_v_definition_path:
                    last_part = ref_v_definition_path.split('/')[-1]
                    attribute_name = mapping_dict.get(last_part)
                    if attribute_name:
                        current_value = getattr(os_application_instance, attribute_name)
                        new_value = reference_value.get_value()

                        if isinstance(current_value, list):  # 如果當前的值是一個 list
                            current_value.append(new_value)
                        else:
                            setattr(os_application_instance, attribute_name, new_value)
                    
            parameter_values = os_application.get_parameterValues()
            for parameter_value in parameter_values:
                parm_v_definition_path = arnode_query.get_definition(parameter_value)
                if parm_v_definition_path: 
                    last_part = parm_v_definition_path.split('/')[-1]
                    attribute_name = mapping_dict.get(last_part)
                    if attribute_name:
                        current_value = getattr(os_application_instance, attribute_name)
                        new_value = parameter_value.get_value().get()

                        if isinstance(current_value, list):  # 如果當前的值是一個列表
                            current_value.append(new_value)
                        else:
                            setattr(os_application_instance, attribute_name, new_value)
                    
            self.__os_application_dict[os_application_path] = os_application_instance

    def populate_task_to_osapp_mapping_dict(self):
        for os_application in self.__os_application_dict.values():
            task_list = os_application.os_app_task_ref
            if task_list:
                for task in task_list:
                    self.__task_to_osapp_mapping_dict[task] =  os_application
                
    def populate_ecuc_lists(self):
        find_ecuc_rte_def = False
        for ecuc_arpackage in self.__ecuc_module_conf_val_dict.values():
            definition_path = ecuc_arpackage.get_definition()
            if isinstance(definition_path, EcucModuleDef):
                definition_path = definition_path.get_path()
                
            if definition_path.endswith('Rte'):
                find_ecuc_rte_def = True
                self.__rte_sw_component_instance_list = arnode_query.find_ecuc_parameter(ecuc_arpackage, definition_path, '/RteSwComponentInstance')
                if not self.__rte_sw_component_instance_list:
                    # rte_swc_instance_list is empty
                    error_messages = [f'No swc instance definition.']
                    alerting.print_message(error_messages,'error')
                self.populate_rte_event_to_task_mapping_dict()
                      
            if definition_path.endswith('Os'):
                self.__os_application_list = arnode_query.find_ecuc_parameter(ecuc_arpackage, definition_path, '/OsApplication')
                if not self.__os_application_list:
                    error_messages = [f'No os application definition.']
                    alerting.print_message(error_messages,'error') 
                self.populate_os_application_dict()
                
                self.__os_task_list = arnode_query.find_ecuc_parameter(ecuc_arpackage, definition_path, '/OsTask')
                if not self.__os_task_list:
                    error_messages = [f'No os task definition.']
                    alerting.print_message(error_messages,'error') 
                     
        if find_ecuc_rte_def is False:
            error_messages = [f'No ECUC Rte definition.']
            alerting.print_message(error_messages,'error') 
        
        self.populate_task_to_osapp_mapping_dict()
        self.populate_runnable_to_task_mapping_dict()
        return True 
    
    def populate_sender_receiver_pair_dict(self, arpackages_list):
        assembly_sw_connnector_dict = arnode_query.find_arnode(arpackages_list,AssemblySwConnector)
        for connector in assembly_sw_connnector_dict.values():
            provider = connector.get_provider().get_targetPPort() if connector.get_provider() else None
            requester = connector.get_requester().get_targetRPort() if connector.get_requester() else None

            if not (provider or requester):
                continue
            
            proviedComSpec = None
            requiredComSpec = None
            
            if provider:
                proviedComSpec = next(iter(provider.get_providedComSpecs()), None)
                if proviedComSpec:
                    data_prototype = proviedComSpec.get_dataElement()
                    key = data_prototype.get_path()
                    if key not in self.__sender_receiver_pair_dict:
                        self.__sender_receiver_pair_dict[key] = SenderReceiverPair(data_prototype)
                    self.__sender_receiver_pair_dict[key].senders[provider] = {}

            if requester:
                requiredComSpec = next(iter(requester.get_requiredComSpecs()), None)
                if requiredComSpec:
                    data_prototype = requiredComSpec.get_dataElement()
                    key = data_prototype.get_path()
                    if key not in self.__sender_receiver_pair_dict:
                        self.__sender_receiver_pair_dict[key] = SenderReceiverPair(data_prototype)
                    self.__sender_receiver_pair_dict[key].receivers[requester] = {}

            # 檢查 provider 和 requester 是否訪問相同的數據元素
            if provider and requester and proviedComSpec and requiredComSpec:
                if proviedComSpec.get_dataElement() != requiredComSpec.get_dataElement():
                    error_message = ('[ERROR]: The provider and requester access different data elements, '
                                    'but they have established a connection using SwConnector. '
                                    'Method populate_sender_receiver_pair_dict failed.')
                    return [error_message]

        return True
    
    def crate_os_ioc_parameter(self):         
        self.__os_ioc_ecuc_para_def = OsIoc()
        for ecuc_module_def_key, ecuc_module_def_value in self.__ecuc_module_def_dict.items():
            if ecuc_module_def_key.endswith('Os'):
                self.__os_ioc_ecuc_para_def.os = ecuc_module_def_value 
                for container in ecuc_module_def_value.get_children():
                    if container.get_path().endswith('OsIoc'):
                        self.__os_ioc_ecuc_para_def.os_ioc = container
                        break
                self.__os_ioc_ecuc_para_def.os_ioc_communication = self.__os_ioc_ecuc_para_def.os_ioc.get_children()[0]
                for sub_container in self.__os_ioc_ecuc_para_def.os_ioc_communication.get_children():
                    if sub_container.get_path().endswith('OsIocSenderProperties'):
                        self.__os_ioc_ecuc_para_def.os_ioc_sender_properties = sub_container
                        for para in sub_container.get_children():
                            if para.get_path().endswith('OsIocSenderId'):
                                self.__os_ioc_ecuc_para_def.os_ioc_sender_id = para
                            elif para.get_path().endswith('OsIocSendingOsApplicationRef'):
                                self.__os_ioc_ecuc_para_def.os_ioc_sending_os_application_ref= para
                            else:
                                # OsIocFunctionImplementationKind
                                self.__os_ioc_ecuc_para_def.os_ioc_snd_function_implementation_kind = para
                    elif sub_container.get_path().endswith('OsIocReceiverProperties'): 
                        self.__os_ioc_ecuc_para_def.os_ioc_receiver_properties = sub_container
                        for para in sub_container.get_children():
                            if para.get_path().endswith('OsIocReceiverId'):
                                self.__os_ioc_ecuc_para_def.os_ioc_receiver_id = para
                            elif para.get_path().endswith('OsIocReceivingOsApplicationRef'):
                                self.__os_ioc_ecuc_para_def.os_ioc_receiving_os_application_ref= para
                            elif para.get_path().endswith('OsIocReceiverPullCB'):
                                self.__os_ioc_ecuc_para_def.os_ioc_receiver_pull_cb = para
                            else:
                                # OsIocFunctionImplementationKind, 重複做了但沒差
                                self.__os_ioc_ecuc_para_def.os_ioc_rcv_function_implementation_kind = para 
                    elif sub_container.get_path().endswith('OsIocDataProperties'):
                        self.__os_ioc_ecuc_para_def.os_ioc_data_properties = sub_container
                        for para in sub_container.get_children(): 
                            if para.get_path().endswith('OsIocDataTypeRef'):
                                self.__os_ioc_ecuc_para_def.os_ioc_data_type_ref = para
                            elif para.get_path().endswith('OsMemoryMappingCodeLocationRef'):
                                self.__os_ioc_ecuc_para_def.os_memory_mapping_code_location_ref= para
                            elif para.get_path().endswith('OsIocInitValue'):
                                self.__os_ioc_ecuc_para_def.os_ioc_init_value = para
                            else:
                                # OsIocDataPropertyIndex
                                self.__os_ioc_ecuc_para_def.os_ioc_data_property_index= para  
                    else:
                        self.__os_ioc_ecuc_para_def.os_ioc_buffer_length = sub_container

    def create_hash_table_from_input(self,arpackages_list):
        self.__ecuc_module_def_dict = arnode_query.find_arnode(arpackages_list,EcucModuleDef)
        self.__ecuc_module_conf_val_dict = arnode_query.find_arnode(arpackages_list,EcucModuleConfigurationValues)
        self.__runnable_dict = arnode_query.find_arnode(arpackages_list, RunnableEntity)
        self.__rte_event_dict = arnode_query.find_arnode(arpackages_list, RTEEvent)
        self.__swctype_dict = arnode_query.find_arnode(arpackages_list,SwComponentType)
        self.__impldatatype_dict = arnode_query.find_arnode(arpackages_list,ImplementationDataType)
        self.__data_type_mapping_set_dict = arnode_query.find_arnode(arpackages_list,DataTypeMappingSet)
        self.__system_mapping_dict = arnode_query.find_arnode(arpackages_list,SystemMapping)
    
        reault = self.populate_sender_receiver_pair_dict(arpackages_list)
        if isinstance(reault,list):
            return_messages = reault + [f'Method initialize_properties failed.'] 
            return return_messages
        self.crate_os_ioc_parameter()
        self.populate_ecuc_lists()
        self.populate_ostask_into_task_impl_dict()
        self.populate_todo_list_into_task_impl_dict()
        
        return True  
    
    def get_task_impl_dict(self):
        return self.__task_impl_dict
    
    def get_com_ecuc_dict(self):
        if not self.__com_ecuc_dict:
            self.__com_ecuc_dict = {k: v for k, v in self.get_ecuc_module_conf_val_dict().items() if k.endswith('Com')}
        return self.__com_ecuc_dict 
    
    def get_system_mapping_dict(self):
        return self.__system_mapping_dict
    
    def get_os_ioc_ecuc_para_def(self):
        return self.__os_ioc_ecuc_para_def
    
    def get_ecuc_module_conf_val_dict(self):
        return self.__ecuc_module_conf_val_dict
    
    def get_ecuc_module_def_dict(self):
        return self.__ecuc_module_def_dict
    
    def get_runnable_dict(self):
        return self.__runnable_dict
    
    def get_rte_event_dict(self):
        return self.__rte_event_dict
    
    def get_swctype_dict(self):
        return self.__swctype_dict
    
    def get_impldatatype_dict(self):
        return self.__impldatatype_dict 
    
    def get_sender_receiver_pair_dict(self):
        return self.__sender_receiver_pair_dict
    
    def get_data_type_mapping_set_dict(self):
        return self.__data_type_mapping_set_dict
    
    def get_rte_sw_component_instance_dict(self):
        return self.__rte_sw_component_instance_dict
    
    def get_os_application_list(self):
        return self.__os_application_list
    
    def get_os_application_dict(self):
        return self.__os_application_dict
    
    def get_task_to_osapp_mapping_dict(self):
        return self.__task_to_osapp_mapping_dict
    
    def get_os_task_list(self):
        return self.__os_task_list
    
    def get_rte_sw_component_instance_list(self):
        return self.__rte_sw_component_instance_list
    
    def get_runnable_accessing_data_elements_dict(self):
        return self.__runnable_accessing_data_elements_dict
    
    def get_runnable_to_task_mapping_dict(self):
        return self.__runnable_to_task_mapping_dict
    
    def get_communication_boundary_pair_dict(self):
        return self.__communication_boundary_pair_dict
    
    def put_accessing_data_elements(self, runnable_path, data_element_path, role):
        if runnable_path not in self.__runnable_accessing_data_elements_dict:
            self.__runnable_accessing_data_elements_dict[runnable_path] = set()

        # 直接將 data_element 加入到 set 中
        self.__runnable_accessing_data_elements_dict[runnable_path].add((data_element_path, role)) 
    
    def put_sender_receiver_pair(self, create_sr_pair_info, put_sr_pair_info):
        data_prototype, data_semantic, role = create_sr_pair_info
        runnable, port_prototype, api_signature = put_sr_pair_info
        
        key = data_prototype.get_path()
        
        if key not in self.__sender_receiver_pair_dict:
            return [f'[ERROR]: {key} does not exist in sender_receiver_pair_dict, which is due to the absence of an established SwConnector.',
                   f'Method put_sender_receiver_pair failed.']
        
        sr_pair_instance = self.__sender_receiver_pair_dict[key]
        
        if role not in ['sender', 'receiver']:
            return [f'[ERROR]: Invalid role specified.',
                        f'Method put_sender_receiver_pair failed.']
            
        # 根據 role 選擇合適的方法。
        method = sr_pair_instance.add_sender if role == 'sender' else sr_pair_instance.add_receiver
        result = method(runnable, port_prototype, api_signature ,data_semantic)

        if isinstance(result, list):
            result = result + [f'Method put_sender_receiver_pair failed.']
            return result

    def put_communication_boundary_pair(self, create_cb_pair_info, put_cb_pair_info):
        port, data_prototype, data_semantic, impl_data_type = create_cb_pair_info
        boundary, role, runnable = put_cb_pair_info
        
        if boundary not in self.__communication_boundary_pair_dict:
            self.__communication_boundary_pair_dict[boundary] = {}
            
        key = data_prototype.get_path()
        if key not in self.__communication_boundary_pair_dict[boundary]:
            self.__communication_boundary_pair_dict[boundary][key] = CommunicationBoundaryPair(data_prototype, data_semantic, impl_data_type)
            
        cb_pair_instance = self.__communication_boundary_pair_dict[boundary][key]
         
        if role not in ['sender', 'receiver']:
            return [f'[ERROR]: Invalid role specified.',
                        f'Method put_communication_boundary_pair failed.']
        
        if role == 'sender':
            cb_pair_instance.pport = port
            cb_pair_instance.add_sender(runnable)
        else:
            cb_pair_instance.rport = port
            cb_pair_instance.add_receiver(runnable)
        # 根據 role 選擇合適的 method
        # if boundary == 'ioc': 
        #     method = cb_pair_instance.add_ioc_sender if role == 'sender' else cb_pair_instance.add_ioc_receiver
        #     result = method(runnable)
        #     if isinstance(result, list):
        #         result.append('Method put_communication_boundary_pair failed.')
        #         return result

# 創建一個 global 的 instnace
shared_data_instance = SharedData()
