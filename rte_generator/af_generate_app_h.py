import pdb
import os
import re

from autosarfactory.autosarfactory import CompositionSwComponentType\
    , HandleInvalidEnum, DataTransformationStatusForwardingEnum, SwImplPolicyEnum\
    , DataTransformationErrorHandlingEnum, ParameterSwComponentType\
    , NvBlockSwComponentType, AutosarDataPrototype, SymbolProps\
    , NonqueuedReceiverComSpec, HandleTimeoutEnum, PortPrototype\
    , RteApiReturnValueProvisionEnum


from tsepp_modules import alerting
from tsepp_modules import arnode_query
from tsepp_modules import shared_function
from tsepp_modules.shared_data import shared_data_instance
from tsepp_modules.arnode_query import InputParameterError

class VFBIfDeclModule():
    def __init__(self):
        self.__entry_point_prototype_to_write_app_h = []
        self.__srapi_to_write_app_h = []
        self.__alerting_message = []

    def generate_error_log(self, object, error_msg, result):
        methods_str = "\n".join([f"         - {result}" for result in result[1:]])
        self.__alerting_message.extend([f'[FAILED]: {object} '])
        self.__alerting_message.extend([f'   - {error_msg} '])
        self.__alerting_message.extend([f'   - Due to {result[0]} '])
        self.__alerting_message.extend([f'   - Affected Methods: '])
        self.__alerting_message.extend([f'{methods_str}\n'])
        
    def extract_and_prepare_data(self, variable_access):
        autosar_variable = shared_function.extract_autosar_variable(variable_access)
        if isinstance(autosar_variable,list):
                return_messages = autosar_variable + [f'Method extract_and_prepare_data failed.'] 
                return return_messages
        
        port_prototype, target_data_prototype = autosar_variable 
        
        target_impldatatype = shared_function.get_implementation_data_type(target_data_prototype)
        if isinstance(target_impldatatype,list):
                return_messages = target_impldatatype + [f'Method extract_and_prepare_data failed.'] 
                return return_messages
        
        sw_data_def_prop = shared_function.get_sw_data_def_prop(target_data_prototype)
        if isinstance(sw_data_def_prop,list):
            return_messages = sw_data_def_prop + [f'Method extract_and_prepare_data failed.'] 
            return return_messages
        
        if not all([port_prototype, target_data_prototype, target_impldatatype, sw_data_def_prop]):
            return None

        return port_prototype, target_data_prototype, target_impldatatype, sw_data_def_prop
                 
    def define_api_signature(self, supports_multi_inst, runnable, port_api_options):
        attributes = [
            'asynchronousServerCallResultPoints','dataReadAccess','dataReceivePointByArguments','dataReceivePointByValues',
            'dataSendPoints','dataWriteAccess','externalTriggeringPoints','internalTriggeringPoints','modeAccessPoints',
            'modeSwitchPoints','parameterAccess','readLocalVariables','serverCallPoints','writtenLocalVariables'
        ]

        def __append_implicit_signature(as_function, return_type, role, prefix, re, port_prototype, target_data_prototype, arg_list):
            if isinstance(port_prototype,PortPrototype) and isinstance(target_data_prototype,AutosarDataPrototype):
                p = port_prototype.get_path().split('/')[-1]
                o = target_data_prototype.get_path().split('/')[-1]
                args = ', '.join(arg_list)  # Converts list elements into a string separated by commas
                api_signature = f'{return_type} {prefix}_{re}_{p}_{o}({args});'
                sw_data_def_prop = shared_function.get_sw_data_def_prop(target_data_prototype)
                data_semantic = sw_data_def_prop.get_swImplPolicy()
                
                create_sr_pair_info = (target_data_prototype, data_semantic, role)
                put_sr_pair_info = (runnable, port_prototype, api_signature)
                result = shared_data_instance.put_sender_receiver_pair(create_sr_pair_info, put_sr_pair_info)
                if isinstance(result,list):
                    return_messages = result + [f'Method __append_implicit_signature failed.'] 
                    return return_messages
                
                shared_data_instance.put_accessing_data_elements(runnable.get_path() , target_data_prototype.get_path(), role) 
                
                if as_function: 
                    self.__srapi_to_write_app_h.append(api_signature)
                else:
                    macro_api_signature = f'#define ' + api_signature
                    if sw_data_def_prop.get_invalidValue():
                        invalid_value = sw_data_def_prop.get_invalidValue().get_value().get()
                        
                        macro_api_content = f'((instance)->{re}_{p}_{o}->value = ({invalid_value}))'
                        self.__srapi_to_write_app_h.append(macro_api_signature + macro_api_content)
                    
                return api_signature 
            
            exception_messages = [f'Input parameter {port_prototype} has incorrect type. Expected type: PortPrototype',
                          f'Input parameter {target_data_prototype} has incorrect type. Expected type: AutosarDataPrototype']
            raise InputParameterError(exception_messages) 
        
        def __append_explicit_signature(return_type, role ,prefix, port_prototype, target_data_prototype, arg_list):
            if isinstance(port_prototype,PortPrototype) and isinstance(target_data_prototype,AutosarDataPrototype):
                p = port_prototype.get_path().split('/')[-1]
                o = target_data_prototype.get_path().split('/')[-1]
                args = ', '.join(arg_list)  # Converts list elements into a string separated by commas
                api_signature = f'{return_type} {prefix}_{p}_{o}({args});'
                sw_data_def_prop = shared_function.get_sw_data_def_prop(target_data_prototype)
                data_semantic = sw_data_def_prop.get_swImplPolicy()
                
                create_sr_pair_info = (target_data_prototype, data_semantic, role)
                put_sr_pair_info = (runnable, port_prototype, api_signature)
                result = shared_data_instance.put_sender_receiver_pair(create_sr_pair_info, put_sr_pair_info)
                if isinstance(result,list):
                    return_messages = result + [f'Method __append_explicit_signature failed.'] 
                    return return_messages
                
                shared_data_instance.put_accessing_data_elements(runnable.get_path() , target_data_prototype.get_path(), role) 
                
                self.__srapi_to_write_app_h.append(api_signature)
                return api_signature
                
            exception_messages = [f'Input parameter {port_prototype} has incorrect type. Expected type: PortPrototype',
                          f'Input parameter {target_data_prototype} has incorrect type. Expected type: AutosarDataPrototype']
            raise InputParameterError(exception_messages)  
        
        def __generate_Rte_IRead_and_Rte_IReadRef(variable_access,re, arg_list):
            result = self.extract_and_prepare_data(variable_access)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IRead_and_Rte_IReadRef failed.'] 
                return return_messages

            port_prototype, target_data_prototype , _ , sw_data_def_prop = result
            # [constr_2020] 
            if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                return_messages = [f'[REJECT]: {runnable} violating [constr_2020]',
                                            f'Method __generate_Rte_IRead_and_Rte_IReadRef failed.']
                return return_messages
            # [SWS_Rte_01301]
            return_type = shared_function.get_return_type(False, target_data_prototype)
            result = __append_implicit_signature(True, return_type , 'receiver', 'Rte_IRead', 
                                                        re, port_prototype, target_data_prototype, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IRead_and_Rte_IReadRef failed.'] 
                return return_messages
            # [SWS_Rte_04578]
            # get_return_type 第一個  paramter 表示這次 API Signature 的 <return> 是回傳 reference 
            return_type = shared_function.get_return_type(True, target_data_prototype)
            result =__append_implicit_signature(True, return_type, 'receiver', 'Rte_IReadRef',
                                                        re, port_prototype, target_data_prototype, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IRead_and_Rte_IReadRef failed.'] 
                return return_messages
            return True
            
        def __generate_Rte_IStatus(variable_access,re, arg_list):
            result = self.extract_and_prepare_data(variable_access)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IStatus failed.'] 
                return return_messages
            
            port_prototype, target_data_prototype , _ , sw_data_def_prop = result
            # [constr_2020] 
            if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                return_messages = [f'[REJECT]: {runnable} violating [constr_2020]',
                                            f'Method __generate_Rte_IStatus failed.']
                return return_messages
            required_com_spec = shared_function.find_required_com_spec(port_prototype, target_data_prototype)
            if isinstance(required_com_spec,list): 
                return_messages = required_com_spec + [f'Method __generate_Rte_IStatus failed.']
                return return_messages
            
             # [SWS_Rte_02600]
            prefix = '' 
            if isinstance(required_com_spec, NonqueuedReceiverComSpec):
                alive_timeout = required_com_spec.get_aliveTimeout()
                handle_data_status = required_com_spec.get_handleDataStatus()
                handle_never_received = required_com_spec.get_handleNeverReceived()
                handle_out_of_range = required_com_spec.get_handleOutOfRange()
                if handle_never_received or handle_data_status\
                    or alive_timeout and alive_timeout>0\
                        or handle_out_of_range and handle_out_of_range == HandleTimeoutEnum.VALUE_NONE:
                            prefix = 'Rte_IStatus' 
                invalidation_policies = port_prototype.get_requiredInterface().get_invalidationPolicies()
                for invalidation_policy in invalidation_policies:
                    if target_data_prototype == invalidation_policy.get_dataElement():
                        handle_invalid = invalidation_policy.get_handleInvalid()
                        if handle_invalid == HandleInvalidEnum.VALUE_KEEP:
                            prefix = 'Rte_IStatus'
                if prefix == 'Rte_IStatus':                    
                    arg_list = ['Rte_Instance instance'] if supports_multi_inst else [] 
                    port_api_option = shared_function.find_port_api_option(port_api_options, port_prototype)
                    if port_api_option:
                        # arg1
                        # [SWS_Rte_08574], [SWS_Rte_08568]
                        if port_api_option.get_errorHandling() == DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING:
                            arg_list.append('Std_TransformerError transformerError')
                    return_type = 'Std_ReturnType'
                    # __append_implicit_signature 的第一個 parameter 是 as_function 設定成 True 代表生成成Function，反之為 macro
                    result = __append_implicit_signature(True, return_type, 'receiver', prefix, 
                                                         re, port_prototype, target_data_prototype, arg_list) 
                    if isinstance(result,list):
                        return_messages = result + [f'Method __generate_Rte_IStatus failed.'] 
                        return return_messages
                    return True

        def __generate_Rte_IWrite_and_Rte_IWriteRef(variable_access,re, arg_list):
            result = self.extract_and_prepare_data(variable_access)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IWrite_and_Rte_IWriteRef failed.'] 
                return return_messages

            port_prototype, target_data_prototype, target_impldatatype, sw_data_def_prop = result
            # [constr_2020] 
            if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                return_messages = [f'[REJECT]: {runnable} violating [constr_2020]',
                                            f'Method __generate_Rte_IWrite_and_Rte_IWriteRef failed.']
                return return_messages
            # arg1
            category = target_impldatatype.get_category()
             #[SWS_Rte_01017]
            in_data = target_impldatatype.get_shortName() + ' data'
            #[SWS_Rte_01018] #[SWS_Rte_05107]
            if category in {'STRUCTUTE','UNION', 'ARRAY'}: 
                #[SWS_Rte_07086]
                # AUTOMATIC: To be used for local non static variables 
                in_data = f'P2CONST({target_impldatatype.get_shortName()}, RTE_CODE, AUTOMATIC)' + ' data'    
            arg_list.append(in_data)

            port_api_option = shared_function.find_port_api_option(port_api_options, port_prototype)
            if port_api_option:
                # arg2
                # [SWS_Rte_04575]{DRAFT}, [SWS_Rte_04576]{DRAFT} 
                if port_api_option.get_transformerStatusForwarding() == DataTransformationStatusForwardingEnum.VALUE_TRANSFORMER_STATUS_FORWARDING:
                    arg_list.append('Std_TransformerForward forwardedStatus')
                    
            return_type = 'void'
            # [SWS_Rte_01302] 
            result = __append_implicit_signature(True, return_type, 'sender', 'Rte_IWrite',
                                                        re, port_prototype, target_data_prototype, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IWrite_and_Rte_IWriteRef failed.'] 
                return return_messages
            # [SWS_Rte_06808]
            # <PREFIX>_APP_DATA: To be used for references on application data (expected to be in RAM or ROM) passed via API
            return_reference = f'FUNC_P2VAR({target_impldatatype.get_shortName()}, RTE_APPL_DATA, RTE_CODE)'
            # 將 Rte_IWrite 會使用的 arg "IN <data>" 取出 
            filtered_lst = [item for item in arg_list if item != in_data]
            # [SWS_Rte_05510] 
            result = __append_implicit_signature(True, return_reference, 'sender', 'Rte_IWriteRef',
                                                        re, port_prototype, target_data_prototype, filtered_lst) 
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IWrite_and_Rte_IWriteRef failed.'] 
                return return_messages
            return True
            
        def __generate_Rte_IInvalidate(variable_access, re,arg_list):
            result = self.extract_and_prepare_data(variable_access)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IInvalidate failed.'] 
                return return_messages
            
            port_prototype, target_data_prototype , _ , sw_data_def_prop = result

            provided_com_spec = shared_function.find_provided_com_spec(port_prototype, target_data_prototype)
            if isinstance(provided_com_spec,list): 
                return_messages = provided_com_spec + [f'Method __generate_Rte_IInvalidate failed.']
                return return_messages
            
             # [SWS_Rte_03801]
            prefix = ''
            invalidation_policies = port_prototype.get_providedInterface().get_invalidationPolicies()
            for invalidation_policy in invalidation_policies:
                if target_data_prototype == invalidation_policy.get_dataElement():
                    # [constr_1219], [SWS_Rte_06727]  
                    if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                        # event semantic 的 VariableDataPrototype 不會有 __generate_Rte_IInvalidate 
                        return_messages = [f'[REJECT]: {runnable} violating [SWS_Rte_06727]',
                                                   f'Method __generate_Rte_IInvalidate failed.']
                        return return_messages
                    
                    handle_invalid = invalidation_policy.get_handleInvalid()
                    if (provided_com_spec and provided_com_spec.get_initValue() and sw_data_def_prop.get_invalidValue()):
                        init_value = provided_com_spec.get_initValue().get_value().get()
                        invalid_value = sw_data_def_prop.get_invalidValue().get_value().get()
                        # [SWS_Rte_05024]
                        if handle_invalid in (HandleInvalidEnum.VALUE_KEEP,HandleInvalidEnum.VALUE_EXTERNAL_REPLACEMENT,\
                            HandleInvalidEnum.VALUE_EXTERNAL_REPLACEMENT):
                            if not invalid_value:
                                return_messages = [f'[REJECT]: {runnable} violating [SWS_Rte_05024]',
                                                    f'Method __generate_Rte_Invalidate failed.']
                                return return_messages
                        # [SWS_Rte_08007] 
                        if handle_invalid == HandleInvalidEnum.VALUE_REPLACE:
                                if init_value == invalid_value:
                                    return_messages = [f'[REJECT]: {runnable} violating [SWS_Rte_08007]',
                                                    f'Method __generate_Rte_Invalidate failed.']
                                    return return_messages
                                return return_messages
                            
                    if handle_invalid in (HandleInvalidEnum.VALUE_REPLACE, HandleInvalidEnum.VALUE_EXTERNAL_REPLACEMENT, HandleInvalidEnum.VALUE_KEEP):
                        # [SWS_Rte_03802]
                        # 雖然 supports_multi_inst 不是 __generate_Rte_Invalidate 的 parameter ，
                        # 但是 __generate_Rte_Invalidate 是 define_api_signature 的 sub-mthod 可以直接用 define_api_signature。 
                        arg_list = ['instance'] if supports_multi_inst else []
                        prefix = 'Rte_IInvalidate' 
                        return_type = ''
                        # __append_implicit_signature 的第一個 parameter 是 as_function 設定成 True 代表生成成Function，反之為 macro
                        result = __append_implicit_signature(False, return_type, 'sender', prefix, 
                                                                    re, port_prototype, target_data_prototype, arg_list)
                        if isinstance(result,list):
                            return_messages = result + [f'Method __generate_Rte_IInvalidate failed.'] 
                            return return_messages 
                        return True 

        def __generate_Rte_Write_or_Rte_Send(variable_access,arg_list):
            # Initialize variables to None
            result = self.extract_and_prepare_data(variable_access)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_Write_or_Rte_Send failed.'] 
                return return_messages
            
            port_prototype, target_data_prototype, target_impldatatype, sw_data_def_prop = result
            # [SWS_Rte_01280], [SWS_Rte_01281]
            prefix = 'Rte_Send' if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED else 'Rte_Write'
            
            # arg1
            category = target_impldatatype.get_category()
             #[SWS_Rte_01017]
            in_data = target_impldatatype.get_shortName() + ' data'
            #[SWS_Rte_01018] #[SWS_Rte_05107]
            if category in {'STRUCTUTE','UNION', 'ARRAY'}: 
                #[SWS_Rte_07086] 
                in_data = f'P2CONST({target_impldatatype.get_shortName()}, memclass, ptrclass)' + ' data'    
            arg_list.append(in_data)

            port_api_option = shared_function.find_port_api_option(port_api_options, port_prototype)
            if port_api_option:
                # arg2
                # [SWS_Rte_04573]{DRAFT}, [SWS_Rte_04574]{DRAFT}
                if port_api_option.get_transformerStatusForwarding() == DataTransformationStatusForwardingEnum.VALUE_TRANSFORMER_STATUS_FORWARDING:
                    arg_list.append('Std_TransformerForward forwardedStatus')
                # arg4
                # [SWS_Rte_08574], [SWS_Rte_08562]
                if port_api_option.get_errorHandling() == DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING:
                    arg_list.append('Std_TransformerError transformerError')
            
            return_type = 'void' if variable_access.get_returnValueProvision() in {RteApiReturnValueProvisionEnum.VALUE_NO_RETURN_VALUE_PROVIDED, None,'None'} else 'Std_ReturnType' 
            result = __append_explicit_signature(return_type, 'sender', prefix, port_prototype, target_data_prototype, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_Write_or_Rte_Send failed.'] 
                return return_messages  
            return True
        
        def __generate_Rte_Invalidate(variable_access, arg_list):
            # 雖然 supports_multi_inst 不是 __generate_Rte_Invalidate 的 parameter ，
            # 但是 __generate_Rte_Invalidate 是 define_api_signature 的 sub-mthod 可以直接用 define_api_signature。
            arg_list = ['Rte_Instance instance'] if supports_multi_inst else []
            result = self.extract_and_prepare_data(variable_access)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_Invalidate failed.'] 
                return return_messages
        
            port_prototype, target_data_prototype , _ , sw_data_def_prop = result
           
            provided_com_spec = shared_function.find_provided_com_spec(port_prototype, target_data_prototype)
            if isinstance(provided_com_spec,list): 
                return_messages = provided_com_spec + [f'Method __generate_Rte_Invalidate failed.']
                return return_messages
            
             # [SWS_Rte_01282]
            prefix = ''
            invalidation_policies = port_prototype.get_providedInterface().get_invalidationPolicies()
            for invalidation_policy in invalidation_policies:
                if target_data_prototype == invalidation_policy.get_dataElement():
                     # [constr_1219], [SWS_Rte_06727]  
                    if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                        # event semantic 的 VariableDataPrototype 不會有 __generate_Rte_Invalidate 
                        return_messages = [f'[REJECT]: {runnable} violating [SWS_Rte_06727]',
                                                   f'Method __generate_Rte_Invalidate failed.']
                        return return_messages
                    
                    handle_invalid = invalidation_policy.get_handleInvalid()
                    if (provided_com_spec and provided_com_spec.get_initValue() and sw_data_def_prop.get_invalidValue()):
                        init_value = provided_com_spec.get_initValue().get_value().get()
                        invalid_value = sw_data_def_prop.get_invalidValue().get_value().get()
                        # [SWS_Rte_05024]
                        if handle_invalid in (HandleInvalidEnum.VALUE_KEEP,HandleInvalidEnum.VALUE_EXTERNAL_REPLACEMENT,\
                            HandleInvalidEnum.VALUE_EXTERNAL_REPLACEMENT):
                            if not invalid_value:
                                return_messages = [f'[REJECT]: {runnable} violating [SWS_Rte_05024]',
                                                    f'Method __generate_Rte_Invalidate failed.']
                                return return_messages
                        # [SWS_Rte_08007] 
                        if handle_invalid == HandleInvalidEnum.VALUE_REPLACE:
                                if init_value == invalid_value:
                                    return_messages = [f'[REJECT]: {runnable} violating [SWS_Rte_08007]',
                                                    f'Method __generate_Rte_Invalidate failed.']
                                    return return_messages
                            
                    if handle_invalid in (HandleInvalidEnum.VALUE_REPLACE, HandleInvalidEnum.VALUE_EXTERNAL_REPLACEMENT, HandleInvalidEnum.VALUE_KEEP):
                        prefix = 'Rte_Invalidate' 
                        port_api_option = shared_function.find_port_api_option(port_api_options, port_prototype)
                        if port_api_option:
                            # [SWS_Rte_08562]
                            if port_api_option.get_errorHandling() == DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING:
                                arg_list.append('Std_TransformerError transformerError')
                        
                        return_type = 'void' if variable_access.get_returnValueProvision() in {RteApiReturnValueProvisionEnum.VALUE_NO_RETURN_VALUE_PROVIDED,None ,'None'} else 'Std_ReturnType' 
                        result = __append_explicit_signature(return_type, 'sender', prefix, port_prototype, target_data_prototype, arg_list)
                        if isinstance(result,list):
                            return_messages = result + [f'Method __generate_Rte_Invalidate failed.'] 
                            return return_messages  
                        return True
         
        def __generate_Rte_Read_or_Rte_Receive(variable_access, arg_list):
            result = self.extract_and_prepare_data(variable_access)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_Read_or_Rte_Receive failed.'] 
                return return_messages
            
            port_prototype, target_data_prototype, target_impldatatype, sw_data_def_prop = result
            # [SWS_Rte_01288], [SWS_Rte_01289]
            prefix = ''
            if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                prefix = 'Rte_Receive'
            else: 
                prefix = 'Rte_Read'
            
            # arg1
            out_data = target_impldatatype.get_shortName() + '* data' #[SWS_Rte_01019], [SWS_Rte_07082]
            if target_impldatatype.get_category() == 'ARRAY':
                   out_data = target_impldatatype.get_shortName() + ' data[]'  
            arg_list.append(out_data)
            port_api_option = shared_function.find_port_api_option(port_api_options, port_prototype)
            if port_api_option:
                # arg2
                # [SWS_Rte_08563], [SWS_Rte_08564]
                if port_api_option.get_errorHandling() == DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING:
                    arg_list.append('Std_TransformerError transformerError')
            return_type = 'void' if variable_access.get_returnValueProvision() in {RteApiReturnValueProvisionEnum.VALUE_NO_RETURN_VALUE_PROVIDED, None,'None'} else 'Std_ReturnType'
            result = __append_explicit_signature(return_type, 'receiver', prefix, port_prototype, target_data_prototype, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_Read_or_Rte_Receive failed.'] 
                return return_messages 
            return True
        
        def __generate_Rte_DRead(variable_access, arg_list):
            result = self.extract_and_prepare_data(variable_access)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_DRead failed.'] 
                return return_messages
            port_prototype, target_data_prototype, target_impldatatype, sw_data_def_prop = result
            # [SWS_Rte_07395]
            if target_impldatatype.get_category() != 'VALUE':
                return_messages = [f'[REJECT]: {variable_access} violating [SWS_Rte_07395].',
                                f'Method __generate_Rte_DRead failed.']
                return return_messages 
            # [SWS_Rte_07638]
            if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                return_messages = [f'[REJECT]: {variable_access} violating [SWS_Rte_07638].',
                                f'Method __generate_Rte_DRead failed.']
                return return_messages
                
            # [SWS_Rte_CONSTR_09096], [SWS_Rte_03892]
            port_api_option = shared_function.find_port_api_option(port_api_options, port_prototype)
            if port_api_option:
                if port_api_option.get_errorHandling() == DataTransformationErrorHandlingEnum.VALUE_TRANSFORMER_ERROR_HANDLING:
                    return_messages = [f'[REJECT]: {variable_access} violating [SWS_Rte_CONSTR_09096] and [SWS_Rte_03892].',
                                f'Method __generate_Rte_DRead failed.']
                    return return_messages

            prefix = 'Rte_DRead'
                    
            return_type = target_impldatatype.get_shortName() 
            result = __append_explicit_signature(return_type, 'receiver', prefix, port_prototype, target_data_prototype, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_DRead failed.'] 
                return return_messages  
            return True
        
        re = runnable.get_shortName()
        self.__srapi_to_write_app_h.append(' ' + '\n' + f'#ifdef RTE_RUNNABLEAPI_{re}') #[SWS_Rte_02751]
        for attr in attributes:
            getter_method = f'get_{attr}'
            variable_accesses = getattr(runnable, getter_method)()
            # [SWS_Rte_CONSTR_09015], [SWS_Rte_CONSTR_09016], [SWS_Rte_CONSTR_09018], [SWS_Rte_CONSTR_09023] 
            # [SWS_Rte_CONSTR_09084], [SWS_Rte_CONSTR_09094], [SWS_Rte_CONSTR_09083], [SWS_Rte_CONSTR_09022]
            # [SWS_Rte_CONSTR_09021], [SWS_Rte_CONSTR_09085], [SWS_Rte_CONSTR_09086]
            arg_list = ['Rte_Instance instance'] if supports_multi_inst else []
            if variable_accesses is not None:
                for variable_access in variable_accesses:
                    if attr == 'dataReadAccess':
                        # [SWS_Rte_03741], [SWS_Rte_04577]
                        result = __generate_Rte_IRead_and_Rte_IReadRef(variable_access,re, arg_list)
                        if isinstance(result,list):
                            self.generate_error_log(runnable, 
                                                    'Unable to generate Rte_IRead and Rte_IReadRef API signature.',
                                                    result)
                        # [SWS_Rte_02599]
                        result = __generate_Rte_IStatus(variable_access,re, arg_list)
                        if isinstance(result,list):
                            self.generate_error_log(runnable, 
                                                    'Unable to generate Rte_IStatus API signature.',
                                                    result)
                    elif attr == 'dataWriteAccess': 
                        # [SWS_Rte_03744], [SWS_Rte_05509]
                        result = __generate_Rte_IWrite_and_Rte_IWriteRef(variable_access,re, arg_list)
                        if isinstance(result,list):
                           self.generate_error_log(runnable, 
                                                    'Unable to generate Rte_IWrite and Rte_IWriteRef API signature.',
                                                    result) 
                        # [SWS_Rte_03800]
                        result = __generate_Rte_IInvalidate(variable_access,re, arg_list)
                        if isinstance(result,list):
                           self.generate_error_log(runnable, 
                                                    'Unable to generate Rte_IInvalidate API signature.',
                                                    result) 
                    elif attr == 'dataSendPoints':
                        # [SWS_Rte_01071], [SWS_Rte_01072]
                        result = __generate_Rte_Write_or_Rte_Send(variable_access,arg_list)
                        if isinstance(result,list):
                            self.generate_error_log(runnable, 
                                                    'Unable to generate Rte_Write or Rte_Send API signature.',
                                                    result) 
                        # [SWS_Rte_01206]
                        result = __generate_Rte_Invalidate(variable_access,arg_list) 
                        if isinstance(result,list):
                            self.generate_error_log(runnable, 
                                                    'Unable to generate Rte_Invalidate API signature.',
                                                    result) 
                    elif attr == 'dataReceivePointByArguments': 
                        # [SWS_Rte_01091], [SWS_Rte_01092]   
                        result = __generate_Rte_Read_or_Rte_Receive(variable_access,arg_list) 
                        if isinstance(result,list):
                            self.generate_error_log(runnable, 
                                                    'Unable to generate Rte_Read or Rte_Receive API signature.',
                                                    result) 
                    elif attr == 'dataReceivePointByValues':
                        # [SWS_Rte_07394]
                        result = __generate_Rte_DRead(variable_access,arg_list) 
                        if isinstance(result,list):
                            self.generate_error_log(runnable, 
                                                    'Unable to generate Rte_DRead API signature.',
                                                    result) 

        self.__srapi_to_write_app_h.append(' ' + '\n' + f'#endif') #[SWS_Rte_02751]
        
    def define_irv_api_signature(self, supports_multi_inst, runnable, explicit_inter_runnable_variables, implicit_inter_runnable_variables):
        
        def is_local_variable_in_dict(local_variable, explicit_access_dict, implicit_access_list):
            accessed_local_variable = shared_function.extract_local_variable(local_variable)
            if isinstance(accessed_local_variable, list):
                return accessed_local_variable + ['Method is_local_variable_in_dict failed.']
            key = accessed_local_variable.get_path()
            in_explicit_access_dict = False
            in_implicit_access_dict = False
            
            if key in explicit_access_dict:
                in_explicit_access_dict = True
             # [SWS_Rte_01303], [SWS_Rte_04580], [SWS_Rte_01304], [SWS_Rte_06208]
            if key in implicit_access_list:
                in_implicit_access_dict = True
             
            return [in_explicit_access_dict, in_implicit_access_dict, accessed_local_variable]
                    
        def __append_irv_signature(as_function, return_type, role, prefix, re, local_variable, arg_list):
            if isinstance(local_variable,AutosarDataPrototype):
                o = local_variable.get_path().split('/')[-1]
                args = ', '.join(arg_list)  # Converts list elements into a string separated by commas
                api_signature = f'{return_type} {prefix}_{re}_{o}({args})'
                
                # result = shared_data_instance.put_sender_receiver_pair(local_variable, SwImplPolicyEnum.VALUE_QUEUED ,role, runnable, 'implicit', api_signature)
                # if isinstance(result,list):
                #     return_messages = result + [f'Method __append_irv_signature failed.'] 
                #     return return_messages 
                
                # shared_data_instance.put_accessing_data_elements(runnable.get_path(), local_variable.get_path(), role) 
                
                if as_function: 
                    self.__srapi_to_write_app_h.append(api_signature)
                else:
                    macro_api_signature = f'#define {return_type} {prefix}_{re}_{o}({args}) '
                    sw_data_def_prop = shared_function.get_sw_data_def_prop(local_variable)
                    if sw_data_def_prop.get_invalidValue():
                        invalid_value = sw_data_def_prop.get_invalidValue().get_value().get()
                        macro_api_content = f'((instance)->{re}_{o}->value = ({invalid_value}))'
                        self.__srapi_to_write_app_h.append(macro_api_signature + macro_api_content)
                        
                return api_signature  
            
            exception_messages = [f'Input parameter {local_variable} has incorrect type. Expected type: AutosarDataPrototype']
            raise InputParameterError(exception_messages) 
        
        def __generate_Rte_IrvIRead_and_Rte_IrvIReadRef(local_variable, re, arg_list):
            sw_data_def_prop = shared_function.get_sw_data_def_prop(local_variable)
            if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                return_messages = [f'[REJECT]: {runnable} violating [constr_2020]',
                                            f'Method __generate_Rte_IrvIRead_and_Rte_IrvIReadRef failed.']
                return return_messages
            # [SWS_Rte_01301]
            return_type = shared_function.get_return_type(False, local_variable)
            result = __append_irv_signature(True, return_type, 'receicer', 'Rte_IrvIRead', re, local_variable, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IrvIRead_and_Rte_IrvIReadRef failed.'] 
                return return_messages 
            # [SWS_Rte_04578]
            # get_return_type 第一個  paramter 表示這次 API Signature 的 <return> 是回傳 reference 
            return_type = shared_function.get_return_type(True, local_variable)
            result = __append_irv_signature(True, return_type, 'receicer', 'Rte_IrvIReadRef', re, local_variable, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IrvIRead_and_Rte_IrvIReadRef failed.'] 
                return return_messages  
            return True
        
        def __generate_Rte_IrvIWrite_and_Rte_IrvIWriteRef(local_variable, re , arg_list):
            target_impldatatype = shared_function.get_implementation_data_type(local_variable)
            if isinstance(target_impldatatype,list):
                    return_messages = target_impldatatype + [f'Method __generate_Rte_IrvIWrite_and_Rte_IrvIWriteRef failed.'] 
                    return return_messages
            sw_data_def_prop = shared_function.get_sw_data_def_prop(local_variable)
            if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                return_messages = [f'[REJECT]: {runnable} violating [constr_2020]',
                                            f'Method __generate_Rte_IrvIWrite_and_Rte_IrvIWriteRef failed.']
                return return_messages
             # arg1
            category = target_impldatatype.get_category()
             #[SWS_Rte_01017]
            in_data = target_impldatatype.get_shortName() + ' data'
            #[SWS_Rte_01018] #[SWS_Rte_05107]
            if category in {'STRUCTUTE','UNION', 'ARRAY'}: 
                #[SWS_Rte_07086]
                # AUTOMATIC: To be used for local non static variables 
                in_data = f'P2CONST({target_impldatatype.get_shortName()}, RTE_CODE, AUTOMATIC)' + ' data'    
            arg_list.append(in_data)

            return_type = 'void'
            result = __append_irv_signature(True, return_type, 'sender', 'Rte_IrvIWrite', re, local_variable, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IrvIWrite_and_Rte_IrvIWriteRef failed.'] 
                return return_messages
            # get_return_type 第一個  paramter 表示這次 API Signature 的 <return> 是回傳 reference 
            # [SWS_Rte_06808]
            # <PREFIX>_APP_DATA: To be used for references on application data (expected to be in RAM or ROM) passed via API
            return_reference = f'FUNC_P2VAR({target_impldatatype.get_shortName()}, RTE_APPL_DATA, RTE_CODE)'
            filtered_lst = [item for item in arg_list if item != in_data]
            result = __append_irv_signature(True, return_reference, 'sender', 'Rte_IrvWriteRef', re, local_variable, filtered_lst)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IrvIWrite_and_Rte_IrvIWriteRef failed.'] 
                return return_messages 
            return True
        
        def __generate_Rte_IrvRead(local_variable, re, arg_list):
            target_impldatatype = shared_function.get_implementation_data_type(local_variable)
            if isinstance(target_impldatatype,list):
                    return_messages = target_impldatatype + [f'Method __generate_Rte_IrvRead failed.'] 
                    return return_messages  
            sw_data_def_prop = shared_function.get_sw_data_def_prop(local_variable)
            if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                return_messages = [f'[REJECT]: {runnable} violating [constr_2020]',
                                            f'Method __generate_Rte_IrvRead failed.']
                return return_messages
            # arg1
            return_type = ''
            category = target_impldatatype.get_category()
            if  category == 'VALUE':
                return_type = shared_function.get_return_type(False, local_variable)
            else:
                return_type = 'void'
                if category == 'STRUCTURE' or category == 'UNION':
                    # [SWS_Rte_07082] 
                    out_data = target_impldatatype.get_shortName() + '* data' 
                if category == 'ARRAY':
                    # [SWS_Rte_05108]
                    out_data = target_impldatatype.get_shortName() + ' data[]' 
                arg_list.append(out_data)
                
            # [SWS_Rte_01305]
            result = __append_irv_signature(True, return_type,  'receicer', 'Rte_IrvRead', re, local_variable, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IrvRead failed.'] 
                return return_messages
            return True
        
        def __generate_Rte_IrvWrite(local_variable, re, arg_list):
            target_impldatatype = shared_function.get_implementation_data_type(local_variable)
            if isinstance(target_impldatatype,list):
                    return_messages = target_impldatatype + [f'Method __generate_Rte_IrvWrite failed.'] 
                    return return_messages 
            sw_data_def_prop = shared_function.get_sw_data_def_prop(local_variable)
            if sw_data_def_prop.get_swImplPolicy() == SwImplPolicyEnum.VALUE_QUEUED:
                return_messages = [f'[REJECT]: {runnable} violating [constr_2020]',
                                            f'Method __generate_Rte_IrvWrite failed.']
                return return_messages
            # arg1
            category = target_impldatatype.get_category()
             #[SWS_Rte_01017]
            in_data = target_impldatatype.get_shortName() + ' data'
            #[SWS_Rte_01018] #[SWS_Rte_05107]
            if category in {'STRUCTUTE','UNION', 'ARRAY'}: 
                #[SWS_Rte_07086]
                # AUTOMATIC: To be used for local non static variables 
                in_data = f'P2CONST({target_impldatatype.get_shortName()}, RTE_CODE, AUTOMATIC)' + ' data'    
            arg_list.append(in_data)

            return_type = 'void'
            # [SWS_Rte_01306]
            result = __append_irv_signature(True, return_type, 'sender', 'Rte_IrvWrite', re, local_variable, arg_list)
            if isinstance(result,list):
                return_messages = result + [f'Method __generate_Rte_IrvWrite failed.'] 
                return return_messages 
            return True
            
        re = runnable.get_shortName()
        # [SWS_Rte_CONSTR_09087], [SWS_Rte_CONSTR_09095], [SWS_Rte_CONSTR_09092]
        # [SWS_Rte_CONSTR_09088], [SWS_Rte_CONSTR_09092], [SWS_Rte_CONSTR_09089]
        # [SWS_Rte_CONSTR_09090]
        self.__srapi_to_write_app_h.append(' ' + '\n' + f'#ifdef RTE_RUNNABLEAPI_{re}') #[SWS_Rte_02751]
         
        implicit_inter_runnable_variables_dict = arnode_query.convert_to_dict(implicit_inter_runnable_variables)
        explicit_inter_runnable_variables_dict = arnode_query.convert_to_dict(explicit_inter_runnable_variables)
        arg_list = ['Rte_Instance instance'] if supports_multi_inst else []
        
        read_local_variables = runnable.get_readLocalVariables()
        if read_local_variables:
            for read_local_variable in read_local_variables:
                in_explicit_access_dict, in_implicit_access_dict, accessed_local_variable =\
                    is_local_variable_in_dict(read_local_variable, explicit_inter_runnable_variables_dict, implicit_inter_runnable_variables_dict)
                if in_explicit_access_dict:
                    # [SWS_Rte_03560]
                    result =  __generate_Rte_IrvRead(accessed_local_variable, re, arg_list)
                    if isinstance(result,list):
                        self.generate_error_log(runnable, 
                                                'Unable to generate Rte_IrvRead API signature.',
                                                result)
                if in_implicit_access_dict:
                    # [SWS_Rte_03550], [SWS_Rte_04579]
                    result =  __generate_Rte_IrvIRead_and_Rte_IrvIReadRef(accessed_local_variable, re, arg_list)
                    if isinstance(result,list):
                        self.generate_error_log(runnable, 
                                                'Unable to generate Rte_IrvIRead and Rte_IrvIReadRef API signature.',
                                                result)

        written_local_variables = runnable.get_writtenLocalVariables()
        if written_local_variables:
            for written_local_variable in written_local_variables:
                in_explicit_access_dict, in_implicit_access_dict, accessed_local_variable =\
                    is_local_variable_in_dict(written_local_variable, explicit_inter_runnable_variables_dict, implicit_inter_runnable_variables_dict)
                    
                if in_explicit_access_dict:
                    # [SWS_Rte_03565]
                    result =  __generate_Rte_IrvWrite(accessed_local_variable, re, arg_list)
                    if isinstance(result,list):
                        self.generate_error_log(runnable, 
                                                'Unable to generate Rte_IrvWrite API signature.',
                                                result) 
                if in_implicit_access_dict: 
                    # [SWS_Rte_03553], [SWS_Rte_06207]
                    result = __generate_Rte_IrvIWrite_and_Rte_IrvIWriteRef(accessed_local_variable, re, arg_list)
                    if isinstance(result,list):
                        self.generate_error_log(runnable, 
                                                'Unable to generate Rte_IrvIWrite and Rte_IrvIWriteRef API signature.',
                                                result)
        
        
                    
        self.__srapi_to_write_app_h.append(' ' + '\n' + f'#endif') #[SWS_Rte_02751]

    def define_entry_point_prototype(self, swctype, runnable):
        # [SWS_Rte_07194], [SWS_Rte_06713]
        swctype_short_name = swctype.get_shortName()
        swctype_symbol =  f''
        if isinstance(swctype.get_symbolProps(),SymbolProps):
            if swctype.get_symbolProps().get_symbol() not in (None,'','None'):
                swctype_symbol = swctype.get_symbolProps().get_symbol()

        runnable_symbol = runnable.get_symbol()
        
        # ready_to_write = [
        #     f'#define {swctype_short_name}_START_SEC',
        #     f'#include "{swctype_short_name}_MemMap.h"',
        #     f'',
        #     f'FUNC(void,AUTOMATIC) {swctype_symbol}{runnable_symbol}();',
        #     f'#define RTE_RUNNABLE_{runnable.get_shortName()} {swctype_symbol}{runnable_symbol}',
        #     f'',
        #     f'#define {swctype_short_name}_STOP_SEC',
        #     f'#include "{swctype_short_name}_MemMap.h"',
        #     f''
        # ]
        ready_to_write = [
            f'FUNC(void,AUTOMATIC) {swctype_symbol}{runnable_symbol}();',
            f'#define RTE_RUNNABLE_{runnable.get_shortName()} {swctype_symbol}{runnable_symbol}',
            f''
        ]
        self.__entry_point_prototype_to_write_app_h.extend(ready_to_write)
                                      
class SWCDSModule():
    def __init__(self):
       self.__swc_ds_to_write_app_h = []
       self.__alerting_message = []
        
    def define_swc_struct(self, swc_symbol):
        # No Return
        structure_synbol = f'Rte_CDS_{swc_symbol}'
        self.__swc_ds_to_write_app_h.append(f'typedef struct {structure_synbol} {structure_synbol};')
        self.__swc_ds_to_write_app_h.append(
            (f'//struct {structure_synbol} ' 
             '{ <component data sections> }; ')
            )

class AppHdrFileGenerator(SWCDSModule,VFBIfDeclModule):
    def __init__(self):
        SWCDSModule.__init__(self)
        VFBIfDeclModule.__init__(self) 
        self.__Rte_SWCSymbol_h_contents = []
        self.__strings_to_write = []
        self.__alerting_message = []
        
    def _clear_lists_contents(self):
        self._VFBIfDeclModule__entry_point_prototype_to_write_app_h.clear()
        self._VFBIfDeclModule__srapi_to_write_app_h.clear()
        self._VFBIfDeclModule__alerting_message.clear()
        self._SWCDSModule__swc_ds_to_write_app_h.clear()
        self._SWCDSModule__alerting_message.clear()
        self.__Rte_SWCSymbol_h_contents.clear()
        self.__strings_to_write.clear()
        self.__alerting_message.clear()
       
    def _write___alerting_message_contents(self,SWCSymbol):
        dir_path = f'./generated/{SWCSymbol}'
        
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
             
        if SWCSymbol == 'AppHdrFileGenerator':
            target_file_name = f'AppHdrFileGenerator_alerting_message.log'
            file_path = os.path.join(dir_path, target_file_name)
            with open(file_path, 'a') as f:
                self.__alerting_message.extend(self._VFBIfDeclModule__alerting_message) 
                self.__alerting_message.extend(self._SWCDSModule__alerting_message)
                f.write('\n'.join(self.__alerting_message) + '\n') 
        else:
           target_file_name = f'Rte_{SWCSymbol}.h_alerting_message.log' 
           file_path = os.path.join(dir_path, target_file_name)
           with open(file_path, 'w') as f:
                self.__alerting_message.extend(self._VFBIfDeclModule__alerting_message) 
                self.__alerting_message.extend(self._SWCDSModule__alerting_message) 
                f.write('\n'.join(self.__alerting_message) + '\n') 
        
    def _write___Rte_SWCSymbol_h_contents(self,SWCSymbol):
        dir_path = f'./generated/{SWCSymbol}' 
        
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
            
        target_file_name = f'Rte_{SWCSymbol}.h'
        file_path = os.path.join(dir_path, target_file_name)
         
        with open(file_path, 'w') as f:
            self.__Rte_SWCSymbol_h_contents.extend([
            '#ifdef __cplusplus /* [SWS_Rte_03709] */',
            'extern "C" {',
            '#endif /* __cplusplus */',
            '',
            '#ifdef RTE_APPLICATION_HEADER_FILE',
            '#error Multiple application header files included.',
            '#endif /* RTE_APPLICATION_HEADER_FILE */',
            '#define RTE_APPLICATION_HEADER_FILE',
            '',
            ])
            self.__Rte_SWCSymbol_h_contents.extend(self.__strings_to_write)
            self.__Rte_SWCSymbol_h_contents.extend(self._VFBIfDeclModule__entry_point_prototype_to_write_app_h) 
            self.__Rte_SWCSymbol_h_contents.extend(self._SWCDSModule__swc_ds_to_write_app_h) 
            self.__Rte_SWCSymbol_h_contents.extend(self._VFBIfDeclModule__srapi_to_write_app_h) 
            self.__Rte_SWCSymbol_h_contents.extend([
            '',
            '#ifdef __cplusplus /* [SWS_Rte_03710] */',
            '} /* extern "C" */',
            '#endif /* __cplusplus */',
            ])
            f.write('\n'.join(self.__Rte_SWCSymbol_h_contents))
 
    def generate_application_h(self,swctype):
        # 清空上一個 SWCType 的寫入內容
        self._clear_lists_contents()
        
        if isinstance(swctype, NvBlockSwComponentType) or\
                isinstance(swctype, ParameterSwComponentType) or\
                    isinstance(swctype, CompositionSwComponentType):
                        self.__alerting_message.extend([f'[WARNING]: {swctype},[SWS_Rte_01000].']) 
        else:
            swctype_symbol = shared_function.get_swc_symbol(swctype)
            self.__strings_to_write.append(f'#include "Rte_{swctype_symbol}_Type.h"')
            # self.__strings_to_write.append(f'#include "Rte_DataHandleType.h"')
            swctype_internal_behavior = swctype.get_internalBehaviors()
            swctype_internal_behavior = list(swctype_internal_behavior)[0]
            supports_multi_inst = swctype_internal_behavior.get_supportsMultipleInstantiation() 
            
            self.define_swc_struct(swctype_symbol)
            runnables = swctype_internal_behavior.get_runnables()
            explicit_inter_runnable_variables = swctype_internal_behavior.get_explicitInterRunnableVariables()
            implicit_inter_runnable_variables = swctype_internal_behavior.get_implicitInterRunnableVariables()
            port_api_options = swctype_internal_behavior.get_portAPIOptions()
            if runnables: 
                for runnable in runnables:
                    self.define_entry_point_prototype(swctype, runnable)
                    self.define_api_signature(supports_multi_inst, runnable, port_api_options)
                    self.define_irv_api_signature(supports_multi_inst, runnable,
                                                  explicit_inter_runnable_variables,
                                                  implicit_inter_runnable_variables)
            self._write___alerting_message_contents(swctype_symbol) 
            self._write___Rte_SWCSymbol_h_contents(swctype_symbol)          

def main():
    ecu_instance = AppHdrFileGenerator()
    
    # [SWS_Rte_01000]
    swctype_dict = shared_data_instance.get_swctype_dict()
    for swctype in swctype_dict.values():    
            ecu_instance.generate_application_h(swctype)
    
    return True
               
if __name__ == '__main__':
    main()
