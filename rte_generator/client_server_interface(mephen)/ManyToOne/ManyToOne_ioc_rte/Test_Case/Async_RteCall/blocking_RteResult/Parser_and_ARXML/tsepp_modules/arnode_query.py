import pdb
from autosarfactory.autosarfactory import ARPackage, ARElement\
    , RTEEvent, RunnableEntity, EcucModuleDef, SwConnector, SystemMapping

from tsepp_modules import alerting 

class ExtractionError(Exception):
    def __init__(self, message):
        super().__init__(message)

class InputParameterError(Exception):
    def __init__(self, message):
        super().__init__(message)

class ArxmlConfigurationError(Exception):
    def __init__(self, message):
        super().__init__(message)

def convert_to_dict(target):
    result_dict = {}
    for element in target:
        key = element.get_path()
        result_dict[key] = element 
    return result_dict
    
def find_arnode(arpackages_list, target):
    # 建立一個空的字典來存儲節點
    target_dict = {}
    
    def get_method_str(target):
        if issubclass(target, RTEEvent):
            return 'get_events'
        elif issubclass(target, RunnableEntity):
            return 'get_runnables'
        elif issubclass(target, SwConnector):
            return 'get_connectors'
        elif issubclass(target, SystemMapping):
            return 'get_mappings' 
        
    def handle_element(element):
        if isinstance(element, ARPackage):
            for child in element.get_children():
                handle_element(child)
    
        if issubclass(target, ARElement):
            if isinstance(element, target):
                path = element.get_path()
                target_dict[path] = element
        else:
            # target inside ARElement
            if hasattr(element, 'get_children'):
                for child in element.get_children():
                    method_str = get_method_str(target)
                    if hasattr(child, method_str):
                        method = getattr(child, method_str)  # 使用getattr來獲取方法
                        for childchild in method():  # 調用方法
                            if isinstance(childchild, target):
                                path = childchild.get_path()
                                target_dict[path] = childchild

    if isinstance(arpackages_list, list):
        for arpackage in arpackages_list:
            if isinstance(arpackage, ARPackage):
                handle_element(arpackage)
                
    # alerting.print_nodeinfo(target_dict)
    return target_dict

def get_definition(target):
    definition_path = target.get_definition()
    if isinstance(definition_path, EcucModuleDef):
        definition_path = definition_path.get_path()
    return definition_path 

def find_ecuc_parameter(ecuc_arpackage, prifix_definition_path ,target):
    target_list = []
    containers = ecuc_arpackage.get_containers()
    # alerting.print_nodeinfo(containers)
    for ecu_container_value in containers:
        # alerting.print_nodeinfo(ecu_container_value)
        definition_path = get_definition(ecu_container_value)
        if definition_path.startswith(prifix_definition_path):
            if definition_path.endswith(target):
                target_list.append(ecu_container_value)
    return target_list