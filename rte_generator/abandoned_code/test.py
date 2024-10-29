from autosarfactory import autosarfactory
from autosarfactory.autosarfactory import ARPackage, ImplementationDataType


file_paths = []
file_path = input("Please enter the name of the file to read: ")
file_paths.append(file_path)

ws = autosarfactory.read(file_paths)
node = ws[0].get_children()
print(type(node))
if isinstance(node,list):
    for item in node:
        if isinstance(item,ARPackage):
            print(item.get_shortName())
            print("SHORT-NAME" in item.get_elements())
                
# Try to open and read the file
# try:
#     with open(file_path, "r") as file:
#         xml_string = file.auto read()
#         root = ET.fromstring(xml_string)
#         print(root)
#         print(AutosarNode.get_children(root))
#         print(AutosarNode._get_node_text(root, "SW-BASE-TYPE"))
# except FileNotFoundError:
#     print(f"No such file or directory: '{file_path}'")  
# except ET.ParseError:
#     print(f"Failed to parse XML from file: '{file_path}'")