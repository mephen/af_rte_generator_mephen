import pdb
from autosarfactory.autosarfactory import SwImplPolicyEnum
from tsepp_modules.arnode_query import InputParameterError

class OsApplication():
    # ECUC Value
    def __init__(self):
        self.origin_arnode = None # linked to arnode instance
        self.os_trusted = None  # Multiplicity: 1 (But it's initialized as None here and can be set later)
        self.os_trusted_application_delay_timing_violation_call = None # Multiplicity: 1
        self.os_trusted_application_with_protection =None # Multiplicity: 1
        self.os_restart_task = None  # Multiplicity: 0~1
        self.os_memory_mapping_code_location_ref = None  # Multiplicity: 0~1
        self.os_app_ecuc_partition_ref = None  # Multiplicity: 0~1
        self.os_application_core_ref = None  # Multiplicity: 0~1
        self.os_app_alarm_ref = []  # Multiplicity: 0~n
        self.os_app_counter_ref = []  # Multiplicity: 0~n
        self.os_app_isr_ref = []  # Multiplicity: 0~n
        self.os_app_task_ref = []  # Multiplicity: 0~n
        self.os_app_schedule_table_ref = []  # Multiplicity: 0~n
        
class RteEventToTaskMapping():
    # ECUC Value
    def __init__(self, rte_event_ref):
        self.rte_event_ref = rte_event_ref
        self.runnable_wait_for_data_rcv_event = None #在等待期間是不是可以切換到其他 Task
        self.rte_mapped_to_task_ref = None
        self.rte_position_in_task = None
        self.rte_os_schedule_point = None
        self.rte_used_os_event_ref = None
        self.rte_used_os_alarm_ref = None
        self.rte_used_os_sch_tbl_expiry_point_ref = None
        self.rte_immediate_restart = None
        self.rte_used_init_fnc = None
        self.rte_event_predecessor_sync_point_ref = None
        self.rte_event_successor_sync_point_ref = None
        self.rte_server_queue_length = None

class RteSwComponentInstance():
    #ECUC Value
      def __init__(self, short_name):
          self.short_name = short_name
          self.swc_type_symbol = None
          self.rte_event_to_task_mapping_dict = {}  

class OsIoc():
    # ECUC Parameter
    def __init__(self):
        self.os = None
        self.os_ioc = None
        self.os_ioc_communication = None
        self.os_ioc_sender_properties = None
        self.os_ioc_sender_id = None
        self.os_ioc_sending_os_application_ref = None
        self.os_ioc_snd_function_implementation_kind = None
        self.os_ioc_receiver_properties = None
        self.os_ioc_receiver_id = None
        self.os_ioc_receiver_pull_cb = None
        self.os_ioc_receiving_os_application_ref = None
        self.os_ioc_rcv_function_implementation_kind = None
        self.os_ioc_data_properties = None
        self.os_ioc_data_type_ref = None
        self.os_memory_mapping_code_location_ref = None
        self.os_ioc_init_value = None
        self.os_ioc_data_property_index = None
        self.os_ioc_buffer_length = None
        
class Pair:
    def __init__(self, data_prototype, data_semantic=None):
        self.data_prototype = data_prototype
        self.data_semantic = data_semantic
        self.senders = {}  # 使用字典來存儲sender和其api的組合
        self.receivers = {}  # 使用字典來存儲receiver和其api的組合

class CommunicationBoundaryPair(Pair):
    def __init__(self, data_prototype, data_semantic, impl_data_type):
        super().__init__(data_prototype, data_semantic)
        self.datatype = impl_data_type
        self.pport = None
        self.rport = None
    
    def add_sender(self, runnable):
        if runnable not in self.senders:
           self.senders[runnable]  = []
    
    def add_receiver(self, runnable):
        if runnable not in self.receivers:
           self.receivers[runnable]  = []
    
class SenderReceiverPair(Pair):
    def __init__(self, data_prototype):
        super().__init__(data_prototype)
        self.rte_event = None

    def is_valid_configuration(self):
        if self.data_semantic is SwImplPolicyEnum.VALUE_QUEUED: 
            if len(self.senders) > 1 and len(self.receivers) > 1:
                return_messages = [f'RTE does not support QUEUED N:M Communication.']
                return return_messages
        return True

    def add_sender(self, sender, port_prototype, api_signature, data_semantic):
        result = self.is_valid_configuration()
        if isinstance(result, list):
            return_messages = result + [f'Method add_sender failed.'] 
            return return_messages 
        
        if port_prototype not in self.senders:
            return [f'[ERROR]: {port_prototype} does not exist in sender_receiver_pair, which is due to the absence of an established SwConnector.',
                   f'Method add_sender failed.']

        if self.data_semantic is None or self.data_semantic == data_semantic:
            self.data_semantic = data_semantic
        else:
            return [f'[ERROR]: The dataElement set in {port_prototype} has a different data semantic compared to other port prototypes.', 
                    f'Method add_sender failed.']

        if sender not in self.senders[port_prototype]:
           self.senders[port_prototype][sender] = []
        # put tuple in to senders[port_prototype] 
        self.senders[port_prototype][sender].append(api_signature)
        return True

    def add_receiver(self, receiver, port_prototype, api_signature, data_semantic):
        result = self.is_valid_configuration()
        if isinstance(result, list):
            return_messages = result + [f'Method add_receiver failed.'] 
            return return_messages
        
        if port_prototype not in self.receivers:
            return [f'[ERROR]: {port_prototype} does not exist in sender_receiver_pair, which is due to the absence of an established SwConnector.',
                   f'Method add_sender failed.']

        if self.data_semantic is None or self.data_semantic == data_semantic:
            self.data_semantic = data_semantic
        else:
            return [f'[ERROR]: The dataElement set in {port_prototype} has a different data semantic compared to other port prototypes.', 
                    f'Method add_receiver failed.']
        if receiver not in self.receivers[port_prototype]:
           self.receivers[port_prototype][receiver] = []
        # put tuple in to receivers[port_prototype] 
        self.receivers[port_prototype][receiver].append(api_signature) 
        return True

