import xmltodict
import json
import os
import enum
import sys

def xml_file_to_json(input_file_path, output_file_path):
    with open(input_file_path, 'r') as file:
        xml_data = file.read()

    # Parse the XML string to an OrderedDict
    data_dict = xmltodict.parse(xml_data)
    
    # Convert the OrderedDict to a JSON-formatted string
    json_string = json.dumps(data_dict, indent=2)

    # Write the JSON data to a file with a '.json' extension
    with open(output_file_path, 'w') as json_file:
        json_file.write(json_string)
        

def print_prefix_tabs(string, num_tabs):
    for i in range(0, num_tabs+1):
        print("\t", end="")
    print(string)


def recursive_parse_val(elements, num_tabs, prev_container):
    #list the keys
    elements_keys = list(elements.keys())
    cur_container = ""
    #print(elements_keys)
    if(elements_keys[0] == "SHORT-NAME" and elements_keys[1] == "DEFINITION-REF"):
        definition = str(elements["DEFINITION-REF"]["#text"]).split("/")[-1]
        name = str(elements["SHORT-NAME"])
        #check spec with container
        cur_container = definition
        prev_container = cur_container
        print_prefix_tabs(definition + " " + name + " {", num_tabs)
        for i in range(2, len(elements_keys)):
            if(type(elements[elements_keys[i]]) is dict):
                recursive_parse_val(elements[elements_keys[i]], num_tabs+1, prev_container)
            elif(type(elements[elements_keys[i]]) is list):
                for j in range(0, len(elements[elements_keys[i]])):
                    recursive_parse_val(elements[elements_keys[i]][j], num_tabs+1, prev_container)
        print_prefix_tabs("}", num_tabs)
    
    elif("DEFINITION-REF" not in elements_keys and ("VALUE" not in elements_keys or ("VALUE-REF" not in elements_keys))):
        for i in range(0, len(elements_keys)):
            if(type(elements[elements_keys[i]]) is dict):
                recursive_parse_val(elements[elements_keys[i]], num_tabs, prev_container)
            elif(type(elements[elements_keys[i]]) is list):
                for j in range(0, len(elements[elements_keys[i]])):
                    recursive_parse_val(elements[elements_keys[i]][j], num_tabs, prev_container)
    
    else:
        if("VALUE" in elements_keys):
            definition = str(elements["DEFINITION-REF"]["#text"]).split("/")[-1]
            value = str(elements["VALUE"])           
            print_prefix_tabs(definition + " = " + value, num_tabs)
                
        elif("VALUE-REF" in elements_keys): 
            definition = str(elements["DEFINITION-REF"]["#text"]).split("/")[-1]
            value = str(elements["VALUE-REF"]["#text"]).split("/")[-1]
            value = value.strip('"')
            #if(type(elements["VALUE-REF"]) is str):
            #    print_prefix_tabs(definition + " = " + "\"" + value + "\"", num_tabs)
            #else:
            print_prefix_tabs(definition + " = " + value, num_tabs)


def merge_oil_files(file1, file2):
    with open(file1, 'a') as file1:
        with open(file2, 'r') as file2:
            file1.write(file2.read())


# Os_xml_json usage:
xml_file_path = "./ARXML/application_Os_ecuc.xml"
json_file_path = "./file/application_Os_ecuc.json"
xml_file_to_json(xml_file_path, json_file_path)

# Os_json_oil usage:
Os_input_f = open(json_file_path)
Os_output_f = open("osekout.oil", "w")
#json objects to python dict
data = json.load(Os_input_f)
data = data["AUTOSAR"]["AR-PACKAGES"]["AR-PACKAGE"]
data = data["ELEMENTS"]["ECUC-MODULE-CONFIGURATION-VALUES"]
data = data["CONTAINERS"]["ECUC-CONTAINER-VALUE"]
with Os_output_f as sys.stdout:
    print("AUTOSAR AUTOSAR {")
    prev_container = ""
    for elements in data:
        recursive_parse_val(elements, 0, prev_container)

Os_input_f.close()
Os_output_f.close()

# Hw_xml_json usage:
xml_file_path = './ARXML/application_Hw_ecuc.xml'
json_file_path = "./file/application_Hw_ecuc.json"
xml_file_to_json(xml_file_path, json_file_path)


# Hw_json_oil usage:
Hw_input_f = open(json_file_path)
Hw_output_f = open("./file/autosar_Hw.oil", "w")
#json objects to python dict
data = json.load(Hw_input_f)
data = data["AUTOSAR"]["AR-PACKAGES"]["AR-PACKAGE"]
data = data["ELEMENTS"]["ECUC-MODULE-CONFIGURATION-VALUES"]
data = data["CONTAINERS"]["ECUC-CONTAINER-VALUE"]
with Hw_output_f as sys.stdout:
    prev_container = ""
    for elements in data:
        recursive_parse_val(elements, 0, prev_container)
    print("}")

merge_oil_files("osekout.oil", "./file/autosar_Hw.oil")

