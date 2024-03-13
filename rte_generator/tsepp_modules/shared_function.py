from autosarfactory.autosarfactory import VariableAccess\
    , RVariableInAtomicSwcInstanceRef, DataReceivedEvent, PortAPIOption\
    , ApplicationDataType, AutosarDataPrototype, ImplementationDataType\
    , SwDataDefPropsConditional, PortPrototype, SwComponentType, SymbolProps\
    , SwImplPolicyEnum, NonqueuedReceiverComSpec, NonqueuedSenderComSpec\
    , SenderReceiverToSignalMapping 

from tsepp_modules import alerting
from tsepp_modules.shared_data import shared_data_instance
from tsepp_modules.arnode_query import InputParameterError

import pdb

def extract_local_variable(variable_access):
    if isinstance(variable_access,VariableAccess):
        accessed_variable = variable_access.get_accessedVariable()
        if accessed_variable is None:
            return_messages = [f'[ERROR]: Accessed variable for {variable_access} is None.',
                                            f'Method extract_local_variable failed.']
            return return_messages
        
        accessed_local_variable = accessed_variable.get_localVariable()
        if accessed_local_variable is None:
                return_messages = [f'[ERROR]: Accessed localVariable for {variable_access} is None.',
                                                f'Method extract_local_variable failed.']
                return return_messages
        return accessed_local_variable
    exception_messages = [f'Input parameter {variable_access} has incorrect type. Expected type: VariableAccess']
    raise InputParameterError(exception_messages) 

def extract_autosar_variable(variable_access):
    if isinstance(variable_access,VariableAccess):
        accessed_variable = variable_access.get_accessedVariable()
        #Early return
        if accessed_variable is None:
            return_messages = [f'[ERROR]: Accessed variable for {variable_access} is None.',
                                            f'Method extract_autosar_variable failed.']
            return return_messages
        
        accessed_autosar_variable = accessed_variable.get_autosarVariable()
        if accessed_autosar_variable is None:
            return_messages = [f'[ERROR]: Accessed Autosar variable for {variable_access} is None.',
                                            f'Method extract_autosar_variable failed.']
            return return_messages
        
        referend_port_prototype = accessed_autosar_variable.get_portPrototype()
        if referend_port_prototype is None:
            return_messages = [f'[ERROR]: Referend port prototype for {variable_access} is None.',
                                            f'Method extract_autosar_variable failed.']
            return return_messages
        
        referend_target_data_prototype = accessed_autosar_variable.get_targetDataPrototype()
        if referend_target_data_prototype is None:
            return_messages = [f'[ERROR]: Referend target data prototype for {variable_access} is None.'
                                            f'Method extract_autosar_variable failed.']
            return return_messages
        
        return referend_port_prototype, referend_target_data_prototype

    exception_messages = [f'Input parameter {variable_access} has incorrect type. Expected type: VariableAccess']
    raise InputParameterError(exception_messages) 
        
def extract_r_variable_in_atomic_swc_instance_ref(target):
    if isinstance(target,RVariableInAtomicSwcInstanceRef):
        context_r_port = target.get_contextRPort()
        if context_r_port is None:
                return_messages = [f'[ERROR]: Accessed contextRPort for {target} is None.',
                                                f'Method extract_r_variable_in_atomic_swc_instance_ref failed.']
                return return_messages
        target_data_element = target.get_targetDataElement() 
        if target_data_element is None:
                return_messages = [f'[ERROR]: Accessed targetDataElement for {target} is None.',
                                                f'Method extract_r_variable_in_atomic_swc_instance_ref failed.']
                return return_messages
        
        return context_r_port, target_data_element 
        
    exception_messages = [f'Input parameter {target} has incorrect type. Expected type: RVariableInAtomicSwcInstanceRef']
    raise InputParameterError(exception_messages) 
        
def get_swc_symbol(the_swc):
    if isinstance(the_swc, SwComponentType):
        if isinstance(the_swc.get_symbolProps(),SymbolProps):
            if the_swc.get_symbolProps().get_symbol() not in (None,'','None'):
                return the_swc.get_symbolProps().get_symbol()
        return the_swc.get_shortName()
    
    exception_messages = [f'Input parameter {the_swc} has incorrect type. Expected type: SwComponentType']
    raise InputParameterError(exception_messages)

def get_impldatatype_symbol(impldatatype):
    if isinstance(impldatatype, ImplementationDataType):
        if isinstance(impldatatype.get_symbolProps(),SymbolProps):
            if impldatatype.get_symbolProps().get_symbol() not in (None,'','None'):
                return impldatatype.get_symbolProps().get_symbol()
        return impldatatype.get_shortName()
    exception_messages = [f'Input parameter {impldatatype} has incorrect type. Expected type: ImplementationDataType']
    raise InputParameterError(exception_messages)

def get_implementation_data_type(target):
    if isinstance(target, AutosarDataPrototype):
        target_data_type =  target.get_type()
        if isinstance(target_data_type,ApplicationDataType):
            data_type_map = find_data_type_map(target_data_type)
            if isinstance(data_type_map,list):
                return_messages = data_type_map + [f'Method get_implementation_data_type failed.'] 
                return return_messages
            
            target_data_type = data_type_map.get_implementationDataType()
        if isinstance(target_data_type,ImplementationDataType): 
            return target_data_type
    exception_messages = [f'Input parameter {target} has incorrect type. Expected type: AutosarDataPrototype']
    raise InputParameterError(exception_messages)

def get_sw_data_def_prop(target):
    def get_first_conditional_sw_data_def_props(sw_data_def_props):
        sw_data_def_props = list(target.get_swDataDefProps().get_swDataDefPropsVariants())
        if sw_data_def_props and isinstance(sw_data_def_props[0], SwDataDefPropsConditional):
            return sw_data_def_props[0]
        return None
    #[SWS_Rte_07196] 
    # overwrite 的粒度是直接整個蓋掉，有需求可以再設計更細變成 per attrituble，
    # 但是這會讓 user 用起來很不舒服。
    if isinstance(target,AutosarDataPrototype) and target.get_swDataDefProps(): 
        return get_first_conditional_sw_data_def_props(target.get_swDataDefProps())

    target_data_type =  target.get_type()
    if isinstance(target_data_type,ApplicationDataType):
        data_type_map = find_data_type_map(target_data_type)
        if isinstance(data_type_map,list):
            return_messages = data_type_map + [f'Method get_sw_data_def_prop failed.'] 
            return return_messages
        
        target_impl_data_type = data_type_map.get_implementationDataType()
        if isinstance(target_impl_data_type,ImplementationDataType) and target_impl_data_type.get_swDataDefProps():
            return get_first_conditional_sw_data_def_props(target_impl_data_type.get_swDataDefProps()) 
        else:
            # The target_impl_data_type does not have a defined sw_data_def_prop, 
            # so it uses the swDataDefProps from the ApplicationDataType
            return get_first_conditional_sw_data_def_props(target_data_type.get_swDataDefProps()) 

    elif isinstance(target_data_type,ImplementationDataType) and target_data_type.get_swDataDefProps():
        return get_first_conditional_sw_data_def_props(target.get_swDataDefProps()) 
    
    exception_messages = [f'Input parameter {target} has incorrect type. Expected type: AutosarDataPrototype or AutosarDataType']
    raise InputParameterError(exception_messages) 

def get_return_type(is_ref,target_data_prototype):
    if isinstance(target_data_prototype,AutosarDataPrototype):
        implementation_data_type = get_implementation_data_type(target_data_prototype)
        if isinstance(implementation_data_type,list):
                return_messages = implementation_data_type + [f'Method get_return_type failed.'] 
                return return_messages

        category = implementation_data_type.get_category()
        short_name = implementation_data_type.get_shortName()
        # [SWS_Rte_07070]
        if category == 'VALUE' and not is_ref: 
            return short_name 
        # [SWS_Rte_08300], [SWS_Rte_07071]
        elif category in {'STRUCTURE','UNION'} or is_ref:
            '''
                Please note that the FUNC_P2CONST macro is applicable if the RTE API is implemented as 
                an real function and the P2CONST might be used if the RTE API is implemented as a macro.
            ''' 
            return f'FUNC_P2CONST({short_name}, SwAddrMethod_name, RTE_CODE)'
        else:
            return 'void'
        
    exception_messages = [f'Input parameter {target_data_prototype} has incorrect type. Expected type: AutosarDataPrototype']
    raise InputParameterError(exception_messages)

def find_data_type_map(target):
    if isinstance(target,ApplicationDataType):
        data_type_mapping_sets_dict = shared_data_instance.get_data_type_mapping_set_dict()
        for data_type_mapping_set in data_type_mapping_sets_dict.values():
            data_type_mapping_set = data_type_mapping_set.get_dataTypeMaps()
            for data_type_mapping in data_type_mapping_set:
                if data_type_mapping.get_applicationDataType() == target:
                    return data_type_mapping
        # [SWS_Rte_07028]
        return_messages = [f'[REJECT]: {target} violating [SWS_Rte_07028].',
                            f'Method find_data_type_map failed.']
        return return_messages

    exception_messages = [f'Input parameter {target} has incorrect type. Expected type: ApplicationDataType']
    raise InputParameterError(exception_messages)

def find_port_api_option(port_api_options, port_prototype):
    if isinstance(port_prototype,PortPrototype):
        for port_api_option in port_api_options:
            if isinstance(port_api_option,PortAPIOption):
                if port_api_option.get_port() == port_prototype:
                    return port_api_option
        # 找不到不代表錯，代表沒配置而已
        return None
    exception_messages = [f'Input parameter {port_prototype} has incorrect type. Expected type: PortPrototype']
    raise InputParameterError(exception_messages)

def find_provided_com_spec(port_prototype, target_data_prototype):
    if isinstance(port_prototype,PortPrototype) and isinstance(target_data_prototype,AutosarDataPrototype):
        provided_com_specs = port_prototype.get_providedComSpecs()
        for provided_com_spec in provided_com_specs:
            if provided_com_spec.get_dataElement() == target_data_prototype:
                return provided_com_spec 
        return_messages = [f'[ERROR]: In {port_prototype}, not a single providedComSpec.dataElement specifies the {target_data_prototype}.',
                            f'Method find_provided_com_spec failed.']
        return return_messages
    
    exception_messages = [f'Input parameter {port_prototype} has incorrect type. Expected type: PortPrototype',
                        f'Input parameter {target_data_prototype} has incorrect type. Expected type: AutosarDataPrototype']
    raise InputParameterError(exception_messages)

def find_required_com_spec(port_prototype, target_data_prototype):
    if isinstance(port_prototype,PortPrototype) and isinstance(target_data_prototype,AutosarDataPrototype):
        required_com_specs = port_prototype.get_requiredComSpecs()
        for required_com_spec in required_com_specs:
            if required_com_spec.get_dataElement() == target_data_prototype:
                return required_com_spec 
        return_messages = [f'[ERROR]: In {port_prototype}, not a single providedComSpec.dataElement specifies the {target_data_prototype}.',
                            f'Method find_required_com_spec failed.']
        return return_messages
    
    exception_messages = [f'Input parameter {port_prototype} has incorrect type. Expected type: PortPrototype',
                        f'Input parameter {target_data_prototype} has incorrect type. Expected type: AutosarDataPrototype']
    raise InputParameterError(exception_messages)

def validate_input_configuration():
    def validate_data_received_event_configuration():
        return_messages = [] 
        runnables_dict = shared_data_instance.get_runnable_dict()
        for runnable in runnables_dict.values():
            wait_points = runnable.get_waitPoints()
            if wait_points:
                for wait_point in wait_points:
                    trigger = wait_point.get_trigger()
                    if isinstance(trigger, DataReceivedEvent):
                        # [SWS_Rte_03018]
                        if trigger.get_data():
                            result = extract_r_variable_in_atomic_swc_instance_ref(trigger.get_data())
                            if isinstance(result, list):
                                return_messages = result + [f'Method validate__data_received_event_configuration failed.'] 
                                return return_messages
                            # 底線 _ 作為一個占位符，以便忽略不需要的值。用於表示“我不關心這個值”。
                            _ , target_data_element = result
                            sw_data_def_prop = get_sw_data_def_prop(target_data_element) 
                            if sw_data_def_prop.get_swImplPolicy() is not SwImplPolicyEnum.VALUE_QUEUED:
                                return_messages = [f'[REJECT]: {trigger} violating [SWS_Rte_03018].',
                                                        f'Method validate__data_received_event_configuration failed.']
                                return return_messages 
                        # [SWS_Rte_01313] 
                        if trigger.get_startOnEvent(): 
                                return_messages = [f'[REJECT]: {trigger} violating [SWS_Rte_01313].',
                                                    f'Method validate__data_received_event_configuration failed.']
                                return return_messages
        return True
    
    passed = True
    result = validate_data_received_event_configuration()
    if isinstance(result, list):
        return result + [f'Method validate_input_configuration failed.']

    return passed

def get_ecu_instance_with_osapp(osapp):
    ecuc_partition = osapp.os_app_ecuc_partition_ref
    ecu_partition = list(ecuc_partition.get_referenceValues())[0].get_value()
    ecu_instance_path = ecu_partition.get_path().rsplit('/', 1)[0]
    return ecu_instance_path 

def determine_communication_boundary(task1, task2):
    task_to_osapp_mapping_dict = shared_data_instance.get_task_to_osapp_mapping_dict() 
    if task1 in task_to_osapp_mapping_dict and task2 in task_to_osapp_mapping_dict:
        osapp1 = task_to_osapp_mapping_dict[task1]
        osapp2 = task_to_osapp_mapping_dict[task2]
        if osapp1 == osapp2:
            return 'rte' 
        else:
            ecu_partition1 = get_ecu_instance_with_osapp(osapp1)
            ecu_partition2 = get_ecu_instance_with_osapp(osapp2) 
            if ecu_partition1 == ecu_partition2:
                return 'ioc'
            else:
                return 'com' 
            
    else:
        pass

def determine_init_value(provided_com_spec, required_com_spec):
    if not isinstance(provided_com_spec, NonqueuedSenderComSpec):
        # Should not be executed here.
        return
    if not isinstance(required_com_spec, NonqueuedReceiverComSpec):
        # Should not be executed here.
        return  
    
    init_value = None 
    if required_com_spec:
        # [SWS_Rte_04502]
        init_value = required_com_spec.get_initValue().get_value().get()
    else:
        # [SWS_Rte_04501]
        init_value =  provided_com_spec.get_initValue().get_value().get()
    
    return init_value 
    # if init_value is None:
    #     return_messages = [f'[REJECT]: {provided_com_spec} and {required_com_spec} violating [SWS_Rte_07642]',
    #                        f'Method determine_init_value failed.']
        
def get_invalidation_policy(port_prototype, cb_pair_instance):
    invalidation_policies = port_prototype.get_requiredInterface().get_invalidationPolicies()
    for invalidation_policy in invalidation_policies:                        
        if cb_pair_instance.data_prototype == invalidation_policy.get_dataElement():
            return invalidation_policy
    return None

def get_com_handle_symbol(data_prototype):
    '''
    com_handle_symbol = comSignal.shortName + comSignal.comHandleId 
        找  data_prototype 是跟哪個 ComSignal 關聯
            從 SenderReceiverToSignalMapping.dataElementIRef.targetDataPrototypeRef
            找 Reference 是 data_prototype 的 SenderReceiverToSignalMapping。
            並從 SenderReceiverToSignalMapping.systemSinalRef 取出 SystemSignal(假設為 SSA)。
            
            從 ComSignal.ComSystemTemplateSystemSignalRef 所 Reference 的 
            ISignalToIPduMapping.iSignalRef 找 iSignal。
            再從 ISignal.systemSignalRef 找 Reference 是 SSA 的，找到就是代表
            這個 ComSignal 是負責用來給 data_prototype 做 Communication 的。
            
            之後就回傳 ComSignal.ComHandleId

    '''
    system_mapping_dict = shared_data_instance.get_system_mapping_dict()
    system_signal_1 = None
    for system_mapping in system_mapping_dict.values():
        data_mappings = system_mapping.get_dataMappings()
        for data_mapping in data_mappings:
            if isinstance(data_mapping, SenderReceiverToSignalMapping):
                data_element = data_mapping.get_dataElement().get_targetDataPrototype()
                if data_element == data_prototype:
                    system_signal_1 = data_mapping.get_systemSignal()
    
    if not system_signal_1:
        return_messages = [f'[REJECT]: {data_prototype} requires using the Com Service but has not established an association with SystemSignal.',
                            f'Method get_com_handle_id failed.']
        return return_messages 
    
    com_ecuc = list(shared_data_instance.get_com_ecuc_dict().values())[0]
    for find_com_config in com_ecuc.get_children():
        if find_com_config.get_path().endswith('ComConfig'):
            for find_com_signal in find_com_config.get_subContainers():
                if find_com_signal.get_definition().endswith('/ComSignal'):
                    for ref in find_com_signal.get_referenceValues():
                        if ref.get_definition().endswith('/ComSystemTemplateSystemSignalRef'):
                            system_signal_2 = ref.get_value().get_iSignal().get_systemSignal()
                            if system_signal_1 == system_signal_2:
                                for param in find_com_signal.get_parameterValues():
                                    if param.get_definition().endswith('/ComHandleId'):
                                        return find_com_signal.get_shortName() + '_' + param.get_value().get()
           
def get_mapped_os_object(runnable):
    rte_sw_component_instance_dict = shared_data_instance.get_rte_sw_component_instance_dict()
    for rte_sw_component_instance in rte_sw_component_instance_dict.values():
        for rte_event_to_task_mapping in rte_sw_component_instance.rte_event_to_task_mapping_dict.values():
            if isinstance(rte_event_to_task_mapping.rte_event_ref, DataReceivedEvent):
                wait_points = runnable.get_waitPoints()
                if wait_points:
                    for wait_point in wait_points:
                        trigger = wait_point.get_trigger()
                        if trigger == rte_event_to_task_mapping.rte_event_ref: 
                            if rte_event_to_task_mapping.rte_used_os_alarm_ref: 
                                return rte_event_to_task_mapping.rte_used_os_alarm_ref
                            elif rte_event_to_task_mapping.rte_used_os_event_ref: 
                                return rte_event_to_task_mapping.rte_used_os_event_ref
            else:
                the_runnable = rte_event_to_task_mapping.rte_event_ref.get_startOnEvent()
                if the_runnable == runnable:
                    if rte_event_to_task_mapping.rte_used_os_alarm_ref: 
                        return rte_event_to_task_mapping.rte_used_os_alarm_ref
                    elif rte_event_to_task_mapping.rte_used_os_event_ref: 
                        return rte_event_to_task_mapping.rte_used_os_event_ref
    return None
   
     