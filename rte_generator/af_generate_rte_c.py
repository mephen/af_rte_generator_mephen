import pdb
import os
import re

from autosarfactory import autosarfactory
from autosarfactory.autosarfactory import TimingEvent\
    ,DataReceivedEvent\

from tsepp_modules import alerting
from tsepp_modules import arnode_query
from tsepp_modules import shared_function
from tsepp_modules.shared_data import shared_data_instance
from tsepp_modules.arnode_query import InputParameterError

class MappingModule():
    def __init__(self):
        self.__task_mapping_contents = []

    def geterate_task_mapping_contents(self):
        four_space = '    '
        task_impl_dict = shared_data_instance.get_task_impl_dict()
        for task_name, todo_lists in task_impl_dict.items():
            task_content = []
            task_content.append(f'TASK({task_name})' + '{')
            num_keys = len(todo_lists)
            wait_event_list = []
            os_object_content = []
            for i in range(1, num_keys + 1):
                if str(i) in todo_lists:
                    todo_list = todo_lists[str(i)]
                    for os_object, rte_event, runnable in todo_list:
                        if os_object and rte_event and runnable:
                            os_object_def = os_object.get_definition()
                            if isinstance(rte_event,TimingEvent) and os_object_def.endswith('OsAlarm'):
                                os_object_content.append(f'{four_space}{runnable.get_symbol()}();')
                            elif os_object_def.endswith('OsEvent'):
                                if os_object.get_shortName() not in wait_event_list: 
                                    wait_event_list.append(os_object.get_shortName())
                                os_object_content.extend([
                                    f'{four_space}{four_space}if(Event & {os_object.get_shortName()})' + '{',
                                    f'{four_space}{four_space}{four_space}ClearEvent({os_object.get_shortName()});',
                                    f'{four_space}{four_space}{four_space}{runnable.get_symbol()}();',
                                    f'{four_space}{four_space}' + '}'
                                ])
            if not wait_event_list:
                # Alarm case
                task_content.extend(os_object_content)
                task_content.append(f'{four_space}TerminateTask();') 
            else:
                # Event case
                wait_contest = []
                wait_contest.append(f'{four_space}EventMaskType Event;')
                wait_contest.append(f'{four_space}while(1) ' + '{')
                wait_event_str = f'{four_space}{four_space}WaitEvent('
                list_length = len(wait_event_list)
                for i, wait_event in enumerate(wait_event_list):
                    if i == list_length - 1:
                        wait_event_str = wait_event_str + wait_event + ')' 
                    else:
                        wait_event_str = wait_event_str + wait_event + ' | '
                        
                wait_contest.append(wait_event_str)
                wait_contest.append(f'{four_space}{four_space}GetEvent({task_name}, &Event);')
                wait_contest.extend(os_object_content)
                wait_contest.append(f'{four_space}' + '}')
                task_content.extend(wait_contest)
                
            task_content.append('}')
            self.__task_mapping_contents.extend(task_content)
            
class RteSrcFileGenerator(MappingModule):
    def __init__(self):
        super().__init__()
        self.__Rte_c_contents = []
        self.__alerting_message = []
        
    def _clear_lists_contents(self):
       self.__Rte_c_contents.clear()
       self._MappingModule__task_mapping_contents.clear()
       self.__alerting_message.clear()
       
    def _write___Rte_c_contents(self):
        dir_path = f'./generated' 
        
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
            
        target_file_name = f'Rte.c'
        file_path = os.path.join(dir_path, target_file_name)
         
        with open(file_path, 'w') as f:
            # include all application header file 
            # self.__Rte_c_contents.extend([
            #     f'#define RTE_RUNNABLEAPI_{}',
            #     f'#include "Rte_{}.h" '
            # ])
            # lclude all task code body
            self.__Rte_c_contents.extend(self._MappingModule__task_mapping_contents)
            f.write('\n'.join(self.__Rte_c_contents))
             
    def _write___alerting_message_contents(self):
        target_file_name = f'RTESrcFileGenerator_alerting_message.log'
        with open(target_file_name, 'a') as f:
            f.write('\n'.join(self.__alerting_message) + '\n') 
    
    def generate_rte_c(self):
        self.geterate_task_mapping_contents()
        self._write___Rte_c_contents()
        self._clear_lists_contents()

def main():
    ecu_instance = RteSrcFileGenerator()
    
    # 1. 獲取所有 OsTask 以及 Mapping 到 OsTask 的 runnable
    ecu_instance.generate_rte_c()
    # 2. 每個 OsTask 去生成 Code Body, 需要有 
    
    return True
            
if __name__ == '__main__':
    main()
