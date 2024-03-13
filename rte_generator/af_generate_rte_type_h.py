import pdb
import os

from autosarfactory.autosarfactory import ImplementationDataType\
    , SwBaseType, SymbolProps, BaseTypeDefinition

from tsepp_modules import shared_function
from tsepp_modules.shared_data import shared_data_instance
from tsepp_modules.arnode_query import InputParameterError

class ImplDataTypeModule:
    def __init__(self):
        self.__typedefs_to_write = []
        self.__alerting_message = []

    def validate_typeEmitter(self, impldatatypes_dict):
        if isinstance(impldatatypes_dict, dict):
            for impldatatype in impldatatypes_dict.values():
                if isinstance(impldatatype, ImplementationDataType):
                    type_emitter= impldatatype.get_typeEmitter()
                    symbol = shared_function.get_impldatatype_symbol(impldatatype)
                    #[SWS_Rte_04632]
                    if type_emitter is not None and type_emitter.endswith('.h'):    
                        self.__typedefs_to_write.append(f'#include "{type_emitter}"') 
                    # [SWS_Rte_06712]
                    # 檢查 ImplementationDataType.typeEmitter 是否配置為 'RTE' 還是 “Undefined”
                    if (type_emitter not in (None, 'None', 'RTE'))or\
                        (type_emitter is not None and type_emitter.endswith('.h'))or \
                        (symbol.startswith('Rte_') or symbol.startswith('SchM_')):
                        # type_emitter ==  None 是 <TYPE-EMITTER> 完全沒有定義在 Impldatatype
                        # type_emitter == 'None' 是 <TYPE-EMITTER> 有定義在 Impldatatype，但是沒有填值
                        # 上述兩種情況，認為都是 Undefined
                        self.__alerting_message.extend([f'[WARNING]: "According to [SWS_Rte_06712],\
                                                        the type declarations of {impldatatype} will not be generated."'])
                else:
                    exception_messages = [f'Input parameter {impldatatype} has incorrect type. Expected type: ImplementationDataType']
                    raise InputParameterError(exception_messages)
            return True
        exception_messages = [f'Input parameter {impldatatypes_dict} has incorrect type. Expected type: dict']
        raise InputParameterError(exception_messages)

    def validate_all_symbols(self, impldatatypes_dict):
        if isinstance(impldatatypes_dict, dict):
            for impldatatype_key_i, impldatatype_value_i in impldatatypes_dict.items():
                #key = impldatatype path, value = impldatatype object 
                # 將比較基準設為 'SYMBOL' 或 'SHORT-NAME'
                symbol_i = shared_function.get_impldatatype_symbol(impldatatype_value_i) 
                
                # 將每個元素與其他所有元素進行比較
                for impldatatype_key_j, impldatatype_value_j in impldatatypes_dict.items():
                    if isinstance(impldatatype_value_i, ImplementationDataType):
                        if impldatatype_key_j == impldatatype_key_i:
                            continue
                        symbol_j = shared_function.get_impldatatype_symbol(impldatatype_value_j)       
                        if symbol_i == symbol_j:
                            typeEmitter_i = impldatatype_value_i.get_typeEmitter()
                            typeEmitter_j = impldatatype_value_j.get_typeEmitter() 
                            if typeEmitter_i != typeEmitter_j and\
                                typeEmitter_i not in (None, 'None', 'RTE') and\
                                    typeEmitter_j not in (None, 'None', 'RTE'):
                                # [SWS_Rte_03893] 
                                error_messages = [
                                    f'[REJECT]: Match found, {impldatatype_value_i} & {impldatatype_value_j}, '
                                    f' violating [SWS_Rte_CONSTR_09097] and [SWS_Rte_03893].'
                                    ]
                                self.__alerting_message.extend(error_messages)
                                return False
                    else:
                        exception_messages = [f'Input parameter {impldatatype_value_i} has incorrect type. Expected type: ImplementationDataType']
                        raise InputParameterError(exception_messages)  
            return True
        exception_messages = [f'Input parameter {impldatatypes_dict} has incorrect type. Expected type: dict']
        raise InputParameterError(exception_messages)

    def __validate_duplicate_typedef(self,typedef_str_for_validation):
        return_messages = []
        haved = False
        for typedef in self.__typedefs_to_write:
            if typedef_str_for_validation == typedef:
                #f'Based on [SWS_Rte_07105], the RTE Types Header File only include once this typedef "{typedef_str_for_validation}".',
                return_messages = [f'[WARNING]: {typedef_str_for_validation},[SWS_Rte_07105].']
                haved = True
                typedef_str = f'/* {typedef_str_for_validation} */'
                self.__typedefs_to_write.append(typedef_str)
                break
        return [haved, return_messages]
    
    def __declaration_typdef_primitive_impldatatype(self, impldatatype):
        return_messages = []
        type_emitter= impldatatype.get_typeEmitter()
        symbol = shared_function.get_impldatatype_symbol(impldatatype)
        # [SWS_Rte_07104] 
        sw_data_def_props= list(impldatatype.get_swDataDefProps().get_swDataDefPropsVariants())
        if not sw_data_def_props:
             return_messages = [
                 f'[ERROR]: The {impldatatype} must define SwDataDefProps.swDataDefPropsVariant.',
                 'Method __declaration_typdef_primitive_impldatatype failed.']
             return [False, return_messages]
       
        base_type_ref = sw_data_def_props[0].get_baseType()
        if base_type_ref is None:
            return_messages = [
                f'[ERROR]: The target referenced by the SwDataDefProps.baseType defined by {impldatatype} does not exist in the input ARXMLs,',
                f'         or it must define SwDataDefProps.baseType as required by TPS_SWCT [constr_1009].',
                f'Method __declaration_typdef_primitive_impldatatype failed.'
                    ]
            return [False,return_messages]    
        
        if isinstance(base_type_ref,SwBaseType):
            swbasetype_baseTypeDef = base_type_ref.get_baseTypeDefinition()
            if not isinstance(swbasetype_baseTypeDef,BaseTypeDefinition):
                return_messages = [
                                f'[ERROR]: The {base_type_ref} must define BaseTypeDefinition, as required by TPS_SWCT [constr_1910].',
                                f'Method __declaration_typdef_primitive_impldatatype failed.'
                                ]
                return [False,return_messages]
 
            native_dec = swbasetype_baseTypeDef.get_nativeDeclaration()
            if native_dec:
                if type_emitter in ('None', None, 'RTE'):
                    typedef_str_for_validation = f'typedef {native_dec} {symbol};'
                    haved = self.__validate_duplicate_typedef(typedef_str_for_validation)
                    # haved[0] == False, 表示 typedef_str_for_validation 沒有在 Rte_Type.h
                    if haved[0] == False:
                        self.__typedefs_to_write.append(typedef_str_for_validation)
                        return_messages = []
                    else:
                        return_messages = haved[1]
                # else:
                    # method validate_typeEmitter has already #include <type_emitter>,
                    # if the value of the attribute typeEmitter ends with ".h".
                    
                return [True,return_messages]
            else: 
                # native_dec is None
                if type_emitter not in ('None', None, 'RTE'):
                    # [SWS_Rte_06711]
                    return_messages = [f'[REJECT]: {impldatatype} violating [SWS_Rte_06711].',
                                        f'Method __declaration_typdef_primitive_impldatatype failed.']
                    return [False,return_messages]
                else:
                    typedef_str = f'/* {impldatatype}, no typedef is generated, implementation use one from Platform_Types.h */'
                    self.__typedefs_to_write.append(typedef_str)
                    return_messages = []
                    return [True,return_messages]
        exception_messages = [f'Input parameter {base_type_ref} has incorrect type. Expected type: SwBaseType']
        raise InputParameterError(exception_messages) 
               
    def __declaration_typdef_array_impldatatype(self):
        pass

    def __declaration_typdef_structure_impldatatype(self):
        pass

    def __declaration_typdef_union_impldatatype(self):
        pass

    def __declaration_typdef_redefinition_impldatatype(self):
        pass

    def __declaration_typdef_pointer_impldatatype(self):
        pass

    def declaration_typdef_main(self, impldatatypes_dict):
        if isinstance(impldatatypes_dict,dict):
            for impldatatype in impldatatypes_dict.values():
                if isinstance(impldatatype,ImplementationDataType):
                    type_emitter= impldatatype.get_typeEmitter()
                    symbol = shared_function.get_impldatatype_symbol(impldatatype)
                    # [SWS_Rte_03894], [SWS_Rte_06712]
                    if symbol.startswith('Rte_') or symbol.startswith('SchM_') or\
                        (type_emitter is not None and type_emitter.endswith('.h')) or\
                            type_emitter not in (None, 'None', 'RTE'):
                        continue
                    # [SWS_Rte_06709]、 [SWS_Rte_06710]
                    category = impldatatype.get_category()
                    if category == 'VALUE':
                        result = self.__declaration_typdef_primitive_impldatatype(impldatatype)
                        if result[0] is False:
                            self.__alerting_message.extend([f'[FAILED]: The {impldatatype} fail to generate typedef.'])
                            self.__alerting_message.extend(result[1] + ['\n']) 
                    elif category == 'ARRAY':
                        self.__declaration_typdef_array_impldatatype()
                    elif category == 'STRUCTUTE':
                        self.__declaration_typdef_structure_impldatatype()
                    elif category == 'UNION':
                        self.__declaration_typdef_union_impldatatype()
                    elif category == 'TYPE-REFERENCE':
                        self.__declaration_typdef_redefinition_impldatatype()
                    elif category == 'DATA-REFERENCE':
                        self.__declaration_typdef_pointer_impldatatype()
                    else:
                        print('Invalid category')
                        return False

        return True

class RteTypesHdrFileGenerator(ImplDataTypeModule):
    def __init__(self):
        ImplDataTypeModule.__init__(self)
        self.__alerting_message = []
        self.__Rte_Type_h_contents = []
        
    def _clear_lists_contents(self):
        self.__alerting_message.clear()
        self.__Rte_Type_h_contents.clear()
        self._ImplDataTypeModule__alerting_message.clear()
        self._ImplDataTypeModule__typedefs_to_write.clear() 
    
    def _write___alerting_message_contents(self):
        dir_path = './generated'
        
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
    
        target_file_name = f'Rte_Type.h_alerting_message.log' 
        file_path = os.path.join(dir_path, target_file_name)

        with open(file_path, 'w') as f:
            self.__alerting_message.extend(self._ImplDataTypeModule__alerting_message) 
            f.write('\n'.join(self.__alerting_message) + '\n')
            
    def _write___Rte_Type_h_contents(self):
        dir_path = './generated'
        
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
            
        target_file_name = 'Rte_Type.h'
        file_path = os.path.join(dir_path, target_file_name)
        
        with open(file_path, 'w') as f:
            self.__Rte_Type_h_contents.extend([
                '#ifndef RTE_TYPE_H',
                '#define RTE_TYPE_H',
                '#include "Rte.h"',
                '',
                '/* AUTOSAR Implementation data types, specific to software component */'
            ])
            self.__Rte_Type_h_contents.extend(self._ImplDataTypeModule__typedefs_to_write)
            self.__Rte_Type_h_contents.extend([f'#endif // RTE_TYPE_H']) 
            f.write('\n'.join(self.__Rte_Type_h_contents))
            
    def generate_Rte_Type_h(self):
        self._clear_lists_contents()
         
        impldatatypes_dict = shared_data_instance.get_impldatatype_dict()
        
        if not self.validate_typeEmitter(impldatatypes_dict):
            return False

        if not self.validate_all_symbols(impldatatypes_dict):
            return False

        if not self.declaration_typdef_main(impldatatypes_dict):
            return False
        
        self._write___alerting_message_contents()
        self._write___Rte_Type_h_contents()
        
def main():
    ecu_instance = RteTypesHdrFileGenerator()
    ecu_instance.generate_Rte_Type_h()
    return True

if __name__ == '__main__':
    main()
