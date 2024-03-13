from autosarfactory import autosarfactory
from autosarfactory.autosarfactory import ARPackage, SwBaseType 
from tsepp_modules import alerting
# 假設 Node 是一個表示節點的類
class Node:
    def __init__(self, path_name, data):
        self.path_name = path_name
        self.data = data


def create_hashing_table(root_arpackages):
    # 建立一個空的字典來存儲節點
    hashing_table = autosarfactory.__pathsToNodeDict__
    print(hashing_table)
    if "/TPC_Composition/DataTypes/SwBaseTypes/float32" in hashing_table:
        print(type(hashing_table))
    alerting.print_nodeinfo(root_arpackages)
    if isinstance(root_arpackages,list):
        for arpackage in root_arpackages:
            alerting.print_nodeinfo(arpackage)
            if isinstance(arpackage,ARPackage):
                # elements = arpackage.get_elements()
                path = arpackage.get_path()
                print(path) 
                arpackage_children = arpackage.get_children()
                alerting.print_nodeinfo(arpackage_children)
                for chid in arpackage_children:
                    alerting.print_nodeinfo(chid)
                    alerting.print_nodeinfo(chid.get_children())
    return hashing_table
