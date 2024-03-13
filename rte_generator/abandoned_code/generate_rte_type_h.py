import xmltodict
import json
import xml_query
import alerting

file_path = input("Please enter the name of the file to read: ")

Rte_type_file_contents = [
    '#ifndef Rte_Type_h',
    '#define Rte_Type_h',
    '#include "Rte.h"',
    '',
]

# 嘗試打開並讀取該文件
try:
    with open(file_path, "r") as file:
        xml_string = file.read()
        data = xmltodict.parse(xml_string)
        #使用 json dumps 來讓 print 出來的 string 是以巢狀式的列出，而非一直行
        #print(json.dumps(data,indent = 4))
except FileNotFoundError:
    print(f"No such file or directory: '{file_path}'")    

def check_typeEmitter(impldatatype):
    if isinstance(impldatatype, list):
        for item in impldatatype:
            if isinstance(item, dict):
                result = xml_query.find_key(item, "TYPE-EMITTER")
                #[SWS_Rte_04632]
                if result is not None and result.endswith(".h"):    
                    Rte_type_file_contents.append(f'#include "{result}"') 
                # typeEmitter 用於表示這個 data type 應該由 AUTOSAR 某個 toolchain 來提供 data type 的 definition
                # 根據 [SWS_Rte_06709]、 [SWS_Rte_06710]、[SWS_Rte_06712]，這個 API 用來檢查 arxml 中的 ImplementationDataType 的 typeEmitter 是否配置為 "RTE" 還是 “為配置”
                elif result is not None and result != "RTE" \
                    or (item.get("SYMBOL-PROPS", {}).get("SYMBOL", "").startswith("Rte_") or item.get("SYMBOL-PROPS", {}).get("SYMBOL", "").startswith("SchM_")) \
                            or (item["SHORT-NAME"].startswith("Rte_") or item["SHORT-NAME"].startswith("SchM_")) :
                    warning_messages = [
                        "Based on [SWS_Rte_06712], the Rte generator is not responsible for generating this Implementation Data Type.",
                        item,
                        ("Based on [SWS_Rte_06709] and [SWS_Rte_06710], the implementationDataType.typeEmitter must be defined as RTE or NOT defined"
                         "for the RTE generator to be responsible for providing the data type definition.")
                    ]
                    alerting.print_message(warning_messages,"warning")
                   
    Rte_type_file_contents.append('/* AUTOSAR Implementation data types, specific to software component */')
    return True

def check_symbol(impldatatype_list):
    if isinstance(impldatatype_list, list):
        required_parameters= ["SHORT-NAME","TYPE-EMITTER", "SYMBOL-PROPS"]
        extracted_table = xml_query.extract_fields(impldatatype_list,required_parameters)
        for i in range(len(extracted_table)):
            # 將比較基準設為 "SYMBOL" 或 "SHORT-NAME"
            if "SYMBOL-PROPS" in extracted_table[i] and extracted_table[i]["SYMBOL-PROPS"] is not None:
                compare_key = extracted_table[i]["SYMBOL-PROPS"]["SYMBOL"]
            else:
                compare_key = extracted_table[i]["SHORT-NAME"]
            
            # 將每個元素與其他所有元素進行比較
            for j in range(i, len(extracted_table)):
                if j == i:
                    continue
                if "SYMBOL-PROPS" in extracted_table[j] and extracted_table[j]["SYMBOL-PROPS"] is not None:
                    compare_key_2 = extracted_table[j]["SYMBOL-PROPS"]["SYMBOL"]
                else:
                    compare_key_2 = extracted_table[j]["SHORT-NAME"]
                
                if compare_key == compare_key_2:
                    #print(f"Match found: Item {i+1} matches with Item {j+1}")
                    if extracted_table[i]["TYPE-EMITTER"] != extracted_table[j]["TYPE-EMITTER"]:
                        error_messages = [
                            (f'Based on [SWS_Rte_06716] and [SWS_Rte_06717], {extracted_table[i]["SHORT-NAME"]} and '
                             f'{extracted_table[j]["SHORT-NAME"]} have the same Implementation Data Type symbol, '
                             f'but their TypeEmitters are different, violating [SWS_Rte_CONSTR_09097].')
                            ]
                        alerting.print_message(error_messages,"error")
                        return False
    return True

def generate_typdef(nested_dict, impldatatype):
    # 未來要加入辨識 impldatatype 的 Code
    list_basetyperef = []
    if isinstance(impldatatype, list):
        for item in impldatatype:
            if isinstance(item, dict):
                result = xml_query.find_key(item, "BASE-TYPE-REF")
                if result is not None:
                    list_basetyperef.append(result)
                else:
                    error_messages = [
                            f'The attribute BASE-TYPE-REF defined in {item["SHORT-NAME"]} does not exist.'
                        ]
                    alerting.print_message(error_messages,"error") 
                    return False

    elif isinstance(impldatatype, dict):
        result = xml_query.find_key(impldatatype, "BASE-TYPE-REF")
        if result is not None:
            list_basetyperef.append(result)
        else:
            error_messages = [
                f'The attribute BASE-TYPE-REF defined in {impldatatype["SHORT-NAME"]} does not exist.'
            ]
            alerting.print_message(error_messages,"error")
            return False
    #找尋 ImplementationDataType 指定的 SwBaseType
    for  index,item in enumerate(list_basetyperef):
        alerting.print_lookupinfo(impldatatype[index]["SHORT-NAME"],item['#text'])
        haved = xml_query.find_unipath(nested_dict, item['@DEST'] ,item['#text'])
        
        if haved is not None:
            if "BASE-TYPE-DEFINITION" in haved:
                haved = haved["BASE-TYPE-DEFINITION"]["BASE-TYPE-DIRECT-DEFINITION"]
            if "NATIVE-DECLARATION" in haved and (impldatatype[index].get("TYPE-EMITTER") == None or impldatatype[index].get("TYPE-EMITTER") == 'RTE'):
                if "SYMBOL-PROPS" in impldatatype[index]:
                    if not (impldatatype[index].get("SYMBOL-PROPS", {}).get("SYMBOL", "").startswith("Rte_") or impldatatype[index].get("SYMBOL-PROPS", {}).get("SYMBOL", "").startswith("SchM_")):
                        Rte_type_file_contents.append(f'typedef {haved["NATIVE-DECLARATION"]} {impldatatype[index]["SYMBOL-PROPS"]["SYMBOL"]};')
                        success_messages = [
                            f'Based on [SWS_Rte_06717], "typedef {haved["NATIVE-DECLARATION"]} {impldatatype[index]["SYMBOL-PROPS"]["SYMBOL"]}" emit success.'
                        ]
                        alerting.print_message(success_messages,"success")
                else:
                    if not (impldatatype[index]["SHORT-NAME"].startswith("Rte_") or impldatatype[index]["SHORT-NAME"].startswith("SchM_")) :
                        Rte_type_file_contents.append(f'typedef {haved["NATIVE-DECLARATION"]} {impldatatype[index]["SHORT-NAME"]};')
                        success_messages = [
                            f'Based on [SWS_Rte_06716],"typedef {haved["NATIVE-DECLARATION"]} {impldatatype[index]["SHORT-NAME"]}" emit success.'
                            ]
                        alerting.print_message(success_messages,"success")

            elif "NATIVE-DECLARATION" not in haved and not (impldatatype[index].get("TYPE-EMITTER") == None or impldatatype[index]["TYPE-EMITTER"] == 'RTE'):
                error_messages = [
                    (f'Based on [SWS_Rte_06711], TYPE-EMITTER must be defined as RTE or it should not be defined. '
                     f'Additionally, NATIVE-DECLARATION should be defined in {item["#text"]}')
                    ]
                alerting.print_message(error_messages,"error")
                return False
        else:
            error_messages = [
                f'The path {item} does not exist.'
                ]
            alerting.print_message(error_messages,"error")
            return False
    
    with open('Rte_Type.h', 'w') as f:
        content = '\n'.join(Rte_type_file_contents)
        f.write(content)
    return True

def main():
    impldatatypes = xml_query.find_key(data,"IMPLEMENTATION-DATA-TYPE")
    #print(json.dumps(impldatatypes,indent = 4))
    check = False
    check = check_typeEmitter(impldatatypes) and check_symbol(impldatatypes) and generate_typdef(data,impldatatypes)
    if check is False:
        return "88"

main()