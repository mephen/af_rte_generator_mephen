import pdb
import os
import re

from autosarfactory.autosarfactory import CompositionSwComponentType\
    , AbstractProvidedPortPrototype, AbstractRequiredPortPrototype\
    , ParameterSwComponentType, NvBlockSwComponentType\
    , ImplementationDataType, SymbolProps


from tsepp_modules import alerting
from tsepp_modules import arnode_query
from tsepp_modules import shared_function
from tsepp_modules.shared_data import shared_data_instance
from tsepp_modules.arnode_query import InputParameterError    
    
class DataTypeRedefineModule():
    def __init__(self):
        self.__strings_to_write = [] 
        pass
    
    def redefine_implementation_data_type_symbol(self, swctype):
        def __validate_duplicate_define(define_str_for_validation):
            not_have = True
            for define in self.__strings_to_write:
                if define_str_for_validation == define:
                    not_have = False 
                    break
            return not_have
        # 要收集 SWC 會使用到的 ImplemeneationDataType -> 可以從 PortProtoype 找
        swc_ports = swctype.get_ports()
        for swc_port in swc_ports:
            com_specs = None
            if isinstance(swc_port, AbstractProvidedPortPrototype):
                com_specs = swc_port.get_providedComSpecs()
            elif isinstance(swc_port, AbstractRequiredPortPrototype):
                com_specs = swc_port.get_requiredComSpecs()
            
            for com_sepc in com_specs:
                data_prototype = com_sepc.get_dataElement()
                impl_data_type = shared_function.get_implementation_data_type(data_prototype)
                if isinstance(impl_data_type, ImplementationDataType):
                    if isinstance(impl_data_type.get_symbolProps(),SymbolProps):
                        #沒定義 symbol 的話，symbol = shortName of Impl_DT，只要宣告在 Rte_Type.h，不需要宣告在 app type header file
                        #[SWS_Rte_06718]
                        if impl_data_type.get_symbolProps().get_symbol() not in (None,'','None') and \
                            (impl_data_type.get_symbolProps().get_symbol() != impl_data_type.get_shortName()):
                            define_str_for_validation = f'#define {impl_data_type.get_shortName()} {impl_data_type.get_symbolProps().get_symbol()}'
                            if __validate_duplicate_define(define_str_for_validation):
                                self.__strings_to_write.append(define_str_for_validation)
class AppTypeHdrFileGenerator(DataTypeRedefineModule):
    def __init__(self):
        super().__init__()
        self.__Rte_SWCSymbol_Type_h_contents = [] 
        self.__alerting_message = []
        
    def _clear_lists_contents(self):
        self.__Rte_SWCSymbol_Type_h_contents.clear()
        self._DataTypeRedefineModule__strings_to_write.clear()
        self.__alerting_message.clear()
    
    def _write___alerting_message_contents(self,SWCSymbol):
        dir_path = f'./generated/{SWCSymbol}'
        
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
            
        if SWCSymbol == 'AppTypeHdrFileGenerator':
            target_file_name = f'AppTypeHdrFileGenerator_alerting_message.log'
            file_path = os.path.join(dir_path, target_file_name)
            with open(file_path, 'a') as f:
                f.write('\n'.join(self.__alerting_message) + '\n') 
        else:
            target_file_name = f'Rte_{SWCSymbol}_Type.h_alerting_message.log' 
            file_path = os.path.join(dir_path, target_file_name)
            with open(file_path, 'w') as f:
                f.write('\n'.join(self.__alerting_message) + '\n') 
        
    def _write___Rte_SWCSymbol_Type_h_contents(self,SWCSymbol):
        dir_path = f'./generated/{SWCSymbol}' 
        
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
            
        target_file_name = f'Rte_{SWCSymbol}_Type.h'
        file_path = os.path.join(dir_path, target_file_name)
        
        with open(file_path, 'w') as f:
            self.__Rte_SWCSymbol_Type_h_contents.extend([
            '#ifdef __cplusplus /* [SWS_Rte_07125] */',
            'extern "C" {',
            '#endif /* __cplusplus */',
            '',
            '//[SWS_Rte_07678]',
            f'#ifndef RTE_{SWCSymbol}_TYPE_H',
            f'#define RTE_{SWCSymbol}_TYPE_H',
            '',
            ])
            self.__Rte_SWCSymbol_Type_h_contents.extend(self._DataTypeRedefineModule__strings_to_write)
            
            self.__Rte_SWCSymbol_Type_h_contents.extend([
            '#endif',
            '',
            '#ifdef __cplusplus /* [SWS_Rte_07126]  */',
            '} /* extern "C" */',
            '#endif /* __cplusplus */',
            ])
            f.write('\n'.join(self.__Rte_SWCSymbol_Type_h_contents))
        
    def generate_application_type_h(self, swctype):
        # 清空上一個 SWCType 的寫入內容
        self._clear_lists_contents()
        if isinstance(swctype, NvBlockSwComponentType) or\
                isinstance(swctype, ParameterSwComponentType) or\
                    isinstance(swctype, CompositionSwComponentType):
                        self.__alerting_message.extend([f'[WARNING]: {swctype},[SWS_Rte_01000].']) 
        else:
            swctype_symbol = shared_function.get_swc_symbol(swctype)
            self._DataTypeRedefineModule__strings_to_write.append(f'#include "../Rte_Type.h"')
            self.redefine_implementation_data_type_symbol(swctype)
            
            self._write___alerting_message_contents(swctype_symbol) 
            self._write___Rte_SWCSymbol_Type_h_contents(swctype_symbol)          

def main():
    ecu_instance = AppTypeHdrFileGenerator()
    
    # [SWS_Rte_01000]
    swctype_dict = shared_data_instance.get_swctype_dict()
    for swctype in swctype_dict.values():    
            ecu_instance.generate_application_type_h(swctype)
    
    return True

if __name__ == '__main__':
    main()
