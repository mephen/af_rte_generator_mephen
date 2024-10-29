import pdb
import platform
import os, shutil


from autosarfactory import autosarfactory 

from tsepp_modules.arnode_query import  ArxmlConfigurationError
from tsepp_modules.shared_data import shared_data_instance
from tsepp_modules import shared_function
import af_generate_rte_type_h
import af_generate_app_type_h
import af_generate_app_h
import af_generate_app_c
import af_generate_rte_c

if platform.system() == 'Windows':
    import pyreadline as readline
else:
    import readline
# 加入這個是讓 Terminal 可以正常使用方向鍵

def remove_previous_gen_file():
    # 資料夾的路徑
    dir_path = './generated'
    
    if os.path.isdir(dir_path):
        shutil.rmtree(dir_path)

def main():
    remove_previous_gen_file()
    
    ecuc_file_paths = input("Please enter the paths of ecuc descrptions, separated by (semicolon + space) : ") 
    swc_file_paths = input("Please enter the paths of software component descrptions, separated by (semicolon + space) : ")
    ecuc_file_paths_list = [path.strip() for path in ecuc_file_paths.split("; ")]
    swc_file_paths_list = [path.strip() for path in swc_file_paths.split("; ")]
    
    all_file_paths_list = ecuc_file_paths_list + swc_file_paths_list
    read_return = autosarfactory.read(all_file_paths_list)
    autosar_root_node = read_return[0]
    arpackages_list = list(autosar_root_node.get_arPackages())  
    reault = shared_data_instance.create_hash_table_from_input(arpackages_list)
    if isinstance(reault,list):
            raise ArxmlConfigurationError(reault)
        
    result = shared_function.validate_input_configuration()
    if isinstance(reault,list):
            raise ArxmlConfigurationError(reault)
    
    af_generate_rte_type_h.main()
    af_generate_app_type_h.main()
    af_generate_app_h.main()
    af_generate_app_c.main()
    af_generate_rte_c.main()
    
    
if __name__ == "__main__":
    main()
