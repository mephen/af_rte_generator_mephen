'''
record
=======================================
2024/04/03
JackChen
move typedef of RingBuffer from ringbuffer.h to Rte_Type.h
--- '#include "Rte.h"',
+++ '#include "Rte_Type.h"'

+++ # 'typedef struct {',
+++ # f'{four_space}void *buffer;          // buffer array',
+++ # f'{four_space}size_t head;           // head index',
+++ # f'{four_space}size_t tail;           // tail index',
+++ # f'{four_space}size_t maxSize;        // maximum number of elements',
+++ # f'{four_space}size_t currentSize;    // current number of elements',
+++ # '} RingBuffer;',
+++ # '',
=======================================
2024/03/15
JackChen
modify "ring_buffer.c" source code
--- f'{four_space}if (IsFull(rb) || dataSize > sizeof(byte_buffer)) {{',
+++ f'{four_space}if (IsFull(rb)) {{',
=======================================
'''
import pdb
import os
import re

from autosarfactory import autosarfactory
from autosarfactory.autosarfactory import ParameterSwComponentType\
    , NvBlockSwComponentType, SwImplPolicyEnum, HandleInvalidEnum\
    , QueuedReceiverComSpec, DataReceivedEvent\

from tsepp_modules import alerting
from tsepp_modules import arnode_query
from tsepp_modules import shared_function
from tsepp_modules.shared_data import shared_data_instance
from tsepp_modules.arnode_query import InputParameterError

class VFBIfImplModule():
    def __init__(self):
        self.__vfb_interface_contents = []

    def populate_communication_boundary_pair_dict(self):
        sender_receiver_pair_dict = shared_data_instance.get_sender_receiver_pair_dict()
        runnable_to_task_mapping_dict = shared_data_instance.get_runnable_to_task_mapping_dict()

        for sender_receiver_pair in sender_receiver_pair_dict.values():
            if len(sender_receiver_pair.senders) > 0 and len(sender_receiver_pair.receivers) > 0:
                for pport ,sender_runnables in sender_receiver_pair.senders.items():
                    for sender_runnable in sender_runnables:
                        for rport, receiver_runnables in sender_receiver_pair.receivers.items():
                            for receiver_runnable in receiver_runnables:
                                task1 = runnable_to_task_mapping_dict[sender_runnable]
                                task2 = runnable_to_task_mapping_dict[receiver_runnable]
                                boundary = shared_function.determine_communication_boundary(task1, task2)
                                data_prototype = sender_receiver_pair.data_prototype
                                data_semantic = sender_receiver_pair.data_semantic
                                impl_data_type = shared_function.get_implementation_data_type(data_prototype)

                                create_cb_pair_info = (pport, data_prototype, data_semantic, impl_data_type)
                                put_cb_pair_info = (boundary, 'sender', sender_runnable)
                                shared_data_instance.put_communication_boundary_pair(create_cb_pair_info, put_cb_pair_info)

                                create_cb_pair_info = (rport, data_prototype, data_semantic, impl_data_type)
                                put_cb_pair_info = (boundary, 'receiver', receiver_runnable)
                                shared_data_instance.put_communication_boundary_pair(create_cb_pair_info, put_cb_pair_info)
            # unconnected condition: only sender
            elif len(sender_receiver_pair.senders) > 0:
                for pport ,sender_runnables in sender_receiver_pair.senders.items():
                    for sender_runnable in sender_runnables:
                        data_prototype = sender_receiver_pair.data_prototype
                        data_semantic = sender_receiver_pair.data_semantic
                        impl_data_type = shared_function.get_implementation_data_type(data_prototype)

                        create_cb_pair_info = (pport, data_prototype, data_semantic, impl_data_type)
                        put_cb_pair_info = ('unconnected', 'sender', sender_runnable)
                        shared_data_instance.put_communication_boundary_pair(create_cb_pair_info, put_cb_pair_info)
            # unconnected condition: only receiver
            elif len(sender_receiver_pair.receivers) > 0:
                for rport, receiver_runnables in sender_receiver_pair.receivers.items():
                    for receiver_runnable in receiver_runnables:
                        data_prototype = sender_receiver_pair.data_prototype
                        data_semantic = sender_receiver_pair.data_semantic
                        impl_data_type = shared_function.get_implementation_data_type(data_prototype)

                        create_cb_pair_info = (rport, data_prototype, data_semantic, impl_data_type)
                        put_cb_pair_info = ('unconnected', 'receiver', receiver_runnable)
                        shared_data_instance.put_communication_boundary_pair(create_cb_pair_info, put_cb_pair_info)

    # rte internal service 相關的生成
    def generate_ring_buffer_service(self):
        four_space = '    '
        def __write___ring_buffer_h_contents():
            static_hdr_contents = [
                '#ifndef RING_BUFFER_H',
                '#define RING_BUFFER_H',
                '',
                '#include "Rte_Type.h"',
                # '// Define the Ring Buffer structure',
                # 'typedef struct {',
                # f'{four_space}void *buffer;          // buffer array',
                # f'{four_space}size_t head;           // head index',
                # f'{four_space}size_t tail;           // tail index',
                # f'{four_space}size_t maxSize;        // maximum number of elements',
                # f'{four_space}size_t currentSize;    // current number of elements',
                # '} RingBuffer;',
                # '',
                '// Function declarations',
                f'int IsFull(RingBuffer* rb);',
                f'int IsEmpty(RingBuffer* rb);',
                f'void* memcpy_t(void* dest, const void* src, size_t n);',
                f'Std_ReturnType RTE_Enqueue(RingBuffer* rb, void* data, size_t dataSize);',
                f'Std_ReturnType RTE_Dequeue(RingBuffer* rb, void* data, size_t dataSize);',
                f'Std_ReturnType RTE_Update(void* target, void* data, size_t dataSize);',
                f'Std_ReturnType RTE_Fetch(void* target, const void* source, size_t dataSize);'
                ''
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'ring_buffer.h'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                static_hdr_contents.append(f'#endif // RING_BUFFER_H')
                f.write('\n'.join(static_hdr_contents))

        def __write___ring_buffer_c_contents():
            static_src_contents = [
                '#include "ring_buffer.h"'
                '// Function to check if the buffer is full',
                'int IsFull(RingBuffer* rb) {',
                f'{four_space}return rb->currentSize == rb->maxSize;',
                '}',
                '',
                '// Function to check if the buffer is empty',
                'int IsEmpty(RingBuffer* rb) {',
                f'{four_space}return rb->currentSize == 0;',
                '}',
                '',
                'void* memcpy_t(void* dest, const void* src, size_t n) {',
                f'{four_space}char* d = (char*) dest;',
                f'{four_space}const char* s = (const char*) src;',
                f'{four_space}for (size_t i = 0; i < n; i++) {{',
                f'{four_space}{four_space}d[i] = s[i];',
                f'{four_space}}}',
                f'{four_space}return dest;',
                '}',
                '// Function to add an element to the buffer',
                'Std_ReturnType RTE_Enqueue(RingBuffer* rb, void* data, size_t dataSize) {',
                f'{four_space}char* byte_buffer = (char*)rb->buffer;',
                f'{four_space}if (IsFull(rb)) {{',
                f'{four_space}{four_space}return RTE_E_LIMIT;',
                f'{four_space}}}',
                f'size_t offset = rb->tail * dataSize;',
                f'{four_space}memcpy_t(byte_buffer+offset, data, dataSize);  // Convert to int* then assign',
                f'{four_space}rb->tail = (rb->tail + 1) % rb->maxSize;',
                f'{four_space}rb->currentSize++;',
                f'{four_space}return RTE_E_OK;',
                '}',
                '',
                '// Function to remove an element from the buffer',
                'Std_ReturnType RTE_Dequeue(RingBuffer* rb, void* data, size_t dataSize) {',
                f'{four_space}if (IsEmpty(rb)) {{',
                f'{four_space}{four_space}return RTE_E_NO_DATA;',
                f'{four_space}}}',
                f'{four_space}char* byte_buffer = (char*)rb->buffer;',
                f'{four_space}size_t offset = rb->head * dataSize;',
                f'{four_space}memcpy_t(data, byte_buffer+offset, dataSize);',
                f'{four_space}rb->head = (rb->head + 1) % rb->maxSize;',
                f'{four_space}rb->currentSize--;',
                f'{four_space}return RTE_E_OK;',
                '}',
                '',
                'Std_ReturnType RTE_Update(void* target, void* data, size_t dataSize) {',
                f'{four_space}memcpy_t(target, data, dataSize);',
                f'{four_space}return RTE_E_OK;',
                '}',
                '',
                'Std_ReturnType RTE_Fetch(void* target, const void* source, size_t dataSize) {',
                f'{four_space}memcpy_t(target, source, dataSize);',
                f'{four_space}return RTE_E_OK;',
                '}'
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'ring_buffer.c'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                f.write('\n'.join(static_src_contents))

        __write___ring_buffer_h_contents()
        __write___ring_buffer_c_contents()

    def generate_rte_data_management(self):
        four_space = '    '
        src_data_type = []
        generated_src_contents = []

        def __write___rte_data_management_h_contents():
            static_hdr_contents = [
                '#ifndef RTE_DATA_MANAGEMENT_H',
                '#define RTE_DATA_MANAGEMENT_H',
                '',
                '#include "ring_buffer.h"',
                '#include "Rte_Type.h"'
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'rte_data_management.h'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                static_hdr_contents.append(f'#endif // RTE_DATA_MANAGEMENT_H')
                f.write('\n'.join(static_hdr_contents))

        def __write___rte_data_management_c_contents():
            static_src_contents = [
                '#include "rte_data_management.h"',
                '#pragma section USER_SHARED_SEC',
                ''
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'rte_data_management.c'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                merges_src_contents = static_src_contents + generated_src_contents
                f.write('\n'.join(merges_src_contents))

        communication_boundary_pair_dict = shared_data_instance.get_communication_boundary_pair_dict()
        if 'rte' in communication_boundary_pair_dict:
            for index, cb_pair_instance in enumerate(communication_boundary_pair_dict['rte'].values()):
                # REJECT Queued N:M Communication
                if len(cb_pair_instance.senders) > 1 & len(cb_pair_instance.receivers) > 1:
                    if cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                        return_messages = [f'RTE does not support QUEUED N:M Communication.',
                                        f'Method generate_rte_data_management failed.']
                        return return_messages

                rte_comm_short_name = f'R{index+1}'
                data_symbol = cb_pair_instance.data_prototype.get_shortName()
                data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                src_data_type.append(data_type)
                # Queued 1:N Communication -> 拆成 N * Queued 1:1 Communication
                if len(cb_pair_instance.senders) == 1 and len(cb_pair_instance.receivers) > 1 and cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                        sender = next(iter(cb_pair_instance.senders))
                        for idx, receiver in enumerate(cb_pair_instance.receivers):
                            rte_comm_short_name_idx = rte_comm_short_name + f'_{idx+1}'

                            data_signature = f'{rte_comm_short_name_idx}_{data_symbol}'
                            required_com_spec = shared_function.find_required_com_spec(cb_pair_instance.rport, cb_pair_instance.data_prototype)

                            if isinstance(required_com_spec, QueuedReceiverComSpec):
                                buffer_length = required_com_spec.get_queueLength()
                                generated_src_contents.append(f'#define {data_signature}_MAX_SIZE {buffer_length}')
                                generated_src_contents.append(f'{data_type} {data_signature}[{data_signature}_MAX_SIZE];')
                                generated_src_contents.extend([
                                    f'RingBuffer RB_{data_signature} = '+'{',
                                    f'{four_space}{data_signature},',
                                    f'{four_space}0,',
                                    f'{four_space}0,',
                                    f'{four_space}{data_signature}_MAX_SIZE,',
                                    f'{four_space}0',
                                    '};',
                                    ''
                                ])
                            cb_pair_instance.receivers[receiver].append(f'RB_{data_signature}')
                            cb_pair_instance.senders[sender].append(f'RB_{data_signature}')
                else:
                    # Unqueued N:1 & 1:1 Communication, Queued N:1 & 1:1 Communication
                    # Unqueued N:M Communication, Unqueued 1:N Communication
                    data_signature = f'{rte_comm_short_name}_{data_symbol}'
                    required_com_spec = shared_function.find_required_com_spec(cb_pair_instance.rport, cb_pair_instance.data_prototype)
                    if cb_pair_instance.data_semantic is SwImplPolicyEnum.VALUE_QUEUED:
                        if isinstance(required_com_spec, QueuedReceiverComSpec):
                            buffer_length = required_com_spec.get_queueLength()
                            generated_src_contents.append(f'#define {data_signature}_MAX_SIZE {buffer_length}')
                            generated_src_contents.append(f'{data_type} {data_signature}[{data_signature}_MAX_SIZE];')
                            generated_src_contents.extend([
                                f'RingBuffer RB_{data_signature} = '+'{',
                                f'{four_space}{data_signature},',
                                f'{four_space}0,',
                                f'{four_space}0,',
                                f'{four_space}{data_signature}_MAX_SIZE,',
                                f'{four_space}0',
                                '};',
                                ''
                            ])
                    else:
                        init_value = required_com_spec.get_initValue().get_value().get()
                        generated_src_contents.append(f'{data_type} {data_signature} = {init_value};')
                        generated_src_contents.append(f'uint32 {data_signature}_first_reception_flag = 1U;')
                        generated_src_contents.append(f'')

                    for idx, sender in enumerate(cb_pair_instance.senders):
                        if cb_pair_instance.data_semantic is SwImplPolicyEnum.VALUE_QUEUED:
                            cb_pair_instance.senders[sender].append(f'RB_{data_signature}')
                        else:
                            cb_pair_instance.senders[sender].append(f'{data_signature}')

                    for idx, receiver in enumerate(cb_pair_instance.receivers):
                        if cb_pair_instance.data_semantic is SwImplPolicyEnum.VALUE_QUEUED:
                            cb_pair_instance.receivers[receiver].append(f'RB_{data_signature}')
                        else:
                            cb_pair_instance.receivers[receiver].append(f'{data_signature}')

            __write___rte_data_management_h_contents()
            __write___rte_data_management_c_contents()

    # ioc.arxml 的生成
    def generate_ioc_configuration(self):
        # ECUC Val
        os_ecucv_container  = None
        os_ioc_ecucv_container = None
        # ECUC Parameter
        os_ioc_ecuc_para_def = shared_data_instance.get_os_ioc_ecuc_para_def()

        runnable_to_task_mapping_dict = shared_data_instance.get_runnable_to_task_mapping_dict()
        task_to_osapp_mapping_dict = shared_data_instance.get_task_to_osapp_mapping_dict()

        def __new_os_ioc_communication(os_ioc_communication_short_name):
            os_ioc_communication_instance = os_ioc_ecucv_container.new_SubContainer(os_ioc_communication_short_name)
            os_ioc_communication_instance.set_definition(os_ioc_ecuc_para_def.os_ioc_communication)
            return os_ioc_communication_instance

        def __put_data_prop_to_os_ioc_comm(os_ioc_comm_instance, cb_pair_instance):
            data_short_name = 'IOC_QUE_DATA' if cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED else 'IOC_UNQUE_DATA'

            data_prop_container = os_ioc_comm_instance.new_SubContainer(data_short_name)
            data_prop_container.set_definition(os_ioc_ecuc_para_def.os_ioc_data_properties)
            if not cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                provided_com_spec = shared_function.find_provided_com_spec(cb_pair_instance.pport, cb_pair_instance.data_prototype)
                required_com_spec = shared_function.find_required_com_spec(cb_pair_instance.rport, cb_pair_instance.data_prototype)
                init_value = shared_function.determine_init_value(provided_com_spec, required_com_spec)
                if init_value:
                    data_prop_init_value= data_prop_container.new_EcucTextualParamValue()
                    data_prop_init_value.set_definition(os_ioc_ecuc_para_def.os_ioc_init_value)
                    data_prop_init_value.set_value(str(init_value))

            # symbol = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
            data_prop_data_type_ref = data_prop_container.new_EcucReferenceValue()
            data_prop_data_type_ref.set_definition(os_ioc_ecuc_para_def.os_ioc_data_type_ref)
            data_prop_data_type_ref.set_value(cb_pair_instance.datatype)

        def __put_sender_to_os_ioc_comm(os_ioc_comm_instance , sender, index):
            sender_short_name = f'SND{index+1}'
            sender_container = os_ioc_comm_instance.new_SubContainer(sender_short_name)
            sender_container.set_definition(os_ioc_ecuc_para_def.os_ioc_sender_properties)

            sender_id = sender_container.new_EcucNumericalParamValue()
            sender_id.set_definition(os_ioc_ecuc_para_def.os_ioc_sender_id)
            value = sender_id.new_Value()
            value.set(index)
            sender_id.set_value(value)

            sender_func_impl_kind = sender_container.new_EcucTextualParamValue()
            sender_func_impl_kind.set_definition(os_ioc_ecuc_para_def.os_ioc_snd_function_implementation_kind)
            sender_func_impl_kind.set_value('FUNCTION')

            task = runnable_to_task_mapping_dict[sender]
            osapp = task_to_osapp_mapping_dict[task]
            sending_osapp_ref = sender_container.new_EcucReferenceValue()
            sending_osapp_ref.set_definition(os_ioc_ecuc_para_def.os_ioc_sending_os_application_ref)
            sending_osapp_ref.set_value(osapp.origin_arnode)
            return sender_short_name

        def __put_receiver_to_os_ioc_comm(os_ioc_comm_instance , receiver, index):
            receiver_short_name = f'RCV{index+1}'
            receiver_container = os_ioc_comm_instance.new_SubContainer(receiver_short_name)
            receiver_container.set_definition(os_ioc_ecuc_para_def.os_ioc_receiver_properties)

            receiver_id = receiver_container.new_EcucNumericalParamValue()
            receiver_id.set_definition(os_ioc_ecuc_para_def.os_ioc_receiver_id)
            value = receiver_id.new_Value()
            value.set(index)
            receiver_id.set_value(value)

            receiver_func_impl_kind = receiver_container.new_EcucTextualParamValue()
            receiver_func_impl_kind.set_definition(os_ioc_ecuc_para_def.os_ioc_rcv_function_implementation_kind)
            receiver_func_impl_kind.set_value('FUNCTION')

            task = runnable_to_task_mapping_dict[receiver]
            osapp = task_to_osapp_mapping_dict[task]
            sending_osapp_ref = receiver_container.new_EcucReferenceValue()
            sending_osapp_ref.set_definition(os_ioc_ecuc_para_def.os_ioc_receiving_os_application_ref)
            sending_osapp_ref.set_value(osapp.origin_arnode)
            return receiver_short_name

        communication_boundary_pair_dict = shared_data_instance.get_communication_boundary_pair_dict()
        if 'ioc' in communication_boundary_pair_dict:
            target_file = os.path.join(os.path.dirname(__file__),  'generated', 'ioc.arxml')
            ecuc_ARPackage= autosarfactory.new_file(target_file, defaultArPackage = 'ActiveEcuC', overWrite = 'true')
            os_ecucv_container = ecuc_ARPackage.new_EcucModuleConfigurationValues('OS')
            os_ecucv_container.set_definition(os_ioc_ecuc_para_def.os)
            os_ioc_ecucv_container = os_ecucv_container.new_Container('IOC')
            os_ioc_ecucv_container.set_definition(os_ioc_ecuc_para_def.os_ioc)

            for index, cb_pair_instance in enumerate(communication_boundary_pair_dict['ioc'].values()):

                # REJECT Queued N:M Communication
                if len(cb_pair_instance.senders) > 1 and len(cb_pair_instance.receivers) > 1:
                    if cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                        return_messages = [f'RTE does not support QUEUED N:M Communication.',
                                        f'Method generate_ioc_configuration failed.']
                        return return_messages

                os_ioc_communication_short_name = f'Q{index+1}'
                # Queued 1:N Communication -> 拆成 N * Queued 1:1 Communication
                if len(cb_pair_instance.senders) == 1 and len(cb_pair_instance.receivers) > 1 and cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                        sender = next(iter(cb_pair_instance.senders))
                        for idx, receiver in enumerate(cb_pair_instance.receivers):
                            os_ioc_communication_short_name_idx = os_ioc_communication_short_name + f'_{idx+1}'
                            os_ioc_comm_instance = __new_os_ioc_communication(os_ioc_communication_short_name_idx)
                            __put_data_prop_to_os_ioc_comm(os_ioc_comm_instance, cb_pair_instance)
                            receiver_id = __put_receiver_to_os_ioc_comm(os_ioc_comm_instance, receiver, 0)
                            cb_pair_instance.receivers[receiver].append(('IocReceive', os_ioc_communication_short_name_idx, receiver_id))
                            # sender 有 n 個 IOC API 可以使用來傳輸到相應的 Recevier Buffer
                            sender_id = __put_sender_to_os_ioc_comm(os_ioc_comm_instance,sender, 0)
                            cb_pair_instance.senders[sender].append(('IocSend', os_ioc_communication_short_name_idx ,sender_id))
                else:
                    # Unqueued N:1 & 1:1 Communication, Queued N:1 & 1:1 Communication
                    # Unqueued N:M Communication, Unqueued 1:N Communication
                    os_ioc_comm_instance = __new_os_ioc_communication(os_ioc_communication_short_name)
                    __put_data_prop_to_os_ioc_comm(os_ioc_comm_instance, cb_pair_instance)

                    service_name = f'IocWrite'
                    if cb_pair_instance.data_semantic is SwImplPolicyEnum.VALUE_QUEUED:
                        service_name = f'IocSend'
                    for idx, sender in enumerate(cb_pair_instance.senders):
                        sender_id = __put_sender_to_os_ioc_comm(os_ioc_comm_instance, sender, idx)
                        cb_pair_instance.senders[sender].append((service_name, os_ioc_communication_short_name,sender_id))

                    service_name = f'IocRead'
                    if cb_pair_instance.data_semantic is SwImplPolicyEnum.VALUE_QUEUED:
                        service_name = f'IocReceive'

                    for idx, receiver in enumerate(cb_pair_instance.receivers):
                        receiver_id = __put_receiver_to_os_ioc_comm(os_ioc_comm_instance, receiver, idx)
                        cb_pair_instance.receivers[receiver].append((service_name, os_ioc_communication_short_name, receiver_id))

            autosarfactory.save()

    def generate_ioc_data_management(self):
        four_space = '    '
        generated_src_contents = []

        def __write_ioc_data_management_h_contents():
            static_hdr_contents = [
                '#ifndef IOC_DATA_MANAGEMENT_H',
                '#define IOC_DATA_MANAGEMENT_H',
                '',
                '#include "Rte_Type.h"',
                f'#include "../kernel/ioc.h"',
                f'#include "../kernel/os.h"'
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'ioc_data_management.h'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                static_hdr_contents.append(f'#endif // IOC_DATA_MANAGEMENT_H')
                f.write('\n'.join(static_hdr_contents))

        def __write_ioc_data_management_c_contents():
            static_src_contents = [
                '#include "ioc_data_management.h"',
                ''
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'ioc_data_management.c'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                merges_src_contents = static_src_contents + generated_src_contents
                f.write('\n'.join(merges_src_contents))

        communication_boundary_pair_dict = shared_data_instance.get_communication_boundary_pair_dict()
        if 'ioc' in communication_boundary_pair_dict:
            for index, cb_pair_instance in enumerate(communication_boundary_pair_dict['ioc'].values()):
                if cb_pair_instance.data_semantic is not SwImplPolicyEnum.VALUE_QUEUED:
                    ioc_comm_short_name = f'Q{index+1}'
                    data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                    symbol = cb_pair_instance.data_prototype.get_shortName()
                    data_signature = f'{ioc_comm_short_name}_{symbol}'
                    required_com_spec = shared_function.find_required_com_spec(cb_pair_instance.rport, cb_pair_instance.data_prototype)
                    init_value = required_com_spec.get_initValue().get_value().get()
                    # generated_hdr_contents.append(f'uint32 {data_signature}_first_reception_flag;')
                    generated_src_contents.append(f'uint32 {data_signature}_first_reception_flag = (uint32)1;')
            __write_ioc_data_management_h_contents()
            __write_ioc_data_management_c_contents()

    def generate_com_data_management(self):
        four_space = '    '
        generated_src_contents = []

        def __write_com_data_management_h_contents():
            static_hdr_contents = [
                '#ifndef COM_DATA_MANAGEMENT_H',
                '#define COM_DATA_MANAGEMENT_H',
                '',
                '#include "ring_buffer.h"',
                '#include "Rte_Type.h"'
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'com_data_management.h'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                static_hdr_contents.append(f'#endif // COM_DATA_MANAGEMENT_H')
                f.write('\n'.join(static_hdr_contents))

        def __write_com_data_management_c_contents():
            static_src_contents = [
                f'#include "com_data_management.h"',
                f'#pragma section USER_SHARED_SEC',
                f''
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'com_data_management.c'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                merges_src_contents = static_src_contents + generated_src_contents
                f.write('\n'.join(merges_src_contents))

        communication_boundary_pair_dict = shared_data_instance.get_communication_boundary_pair_dict()
        if 'com' in communication_boundary_pair_dict:
            for cb_pair_instance in communication_boundary_pair_dict['com'].values():
                # REJECT Queued N:M Communication
                if len(cb_pair_instance.senders) > 1 & len(cb_pair_instance.receivers) > 1:
                    if cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                        return_messages = [f'RTE does not support QUEUED N:M Communication.',
                                        f'Method generate_rte_data_management failed.']
                        return return_messages

                data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                com_handle_symbol = shared_function.get_com_handle_symbol(cb_pair_instance.data_prototype)
                data_symbol = cb_pair_instance.data_prototype.get_shortName()
                com_handle_id = com_handle_symbol.split("_")[-1]
                # Queued 1:N Communication -> 拆成 N * Queued 1:1 Communication
                if len(cb_pair_instance.senders) == 1 and len(cb_pair_instance.receivers) > 1 and cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                        sender = next(iter(cb_pair_instance.senders))
                        for idx, receiver in enumerate(cb_pair_instance.receivers):
                            com_comm_short_name_idx = com_handle_symbol + f'_{idx+1}'

                            data_signature = f'{com_comm_short_name_idx}_{data_symbol}'
                            required_com_spec = shared_function.find_required_com_spec(cb_pair_instance.rport, cb_pair_instance.data_prototype)

                            if isinstance(required_com_spec, QueuedReceiverComSpec):
                                buffer_length = required_com_spec.get_queueLength()
                                generated_src_contents.append(f'#define {data_signature}_MAX_SIZE {buffer_length}')
                                generated_src_contents.append(f'{data_type} {data_signature}[{data_signature}_MAX_SIZE];')
                                generated_src_contents.extend([
                                    f'RingBuffer RB_{data_signature} = '+'{',
                                    f'{four_space}{data_signature},',
                                    f'{four_space}0,',
                                    f'{four_space}0,',
                                    f'{four_space}{data_signature}_MAX_SIZE,',
                                    f'{four_space}0',
                                    '};',
                                    ''
                                ])
                            # RTE API 使用 Com service，receiver 需要有一個 buffer 暫存 Com buffer 的 data
                            cb_pair_instance.receivers[receiver].append((f'RB_{data_signature}',com_handle_id))
                        cb_pair_instance.senders[sender].append(com_handle_id)
                else:
                    # Unqueued N:1 & 1:1 Communication, Queued N:1 & 1:1 Communication
                    # Unqueued N:M Communication, Unqueued 1:N Communication
                    data_signature = f'{com_handle_symbol}_{data_symbol}'
                    required_com_spec = shared_function.find_required_com_spec(cb_pair_instance.rport, cb_pair_instance.data_prototype)
                    if cb_pair_instance.data_semantic is SwImplPolicyEnum.VALUE_QUEUED:
                        if isinstance(required_com_spec, QueuedReceiverComSpec):
                            buffer_length = required_com_spec.get_queueLength()
                            generated_src_contents.append(f'#define {data_signature}_MAX_SIZE {buffer_length}')
                            generated_src_contents.append(f'{data_type} {data_signature}[{data_signature}_MAX_SIZE];')
                            generated_src_contents.extend([
                                f'RingBuffer RB_{data_signature} = '+'{',
                                f'{four_space}{data_signature},',
                                f'{four_space}0,',
                                f'{four_space}0,',
                                f'{four_space}{data_signature}_MAX_SIZE,',
                                f'{four_space}0',
                                '};',
                                ''
                            ])
                    else:
                        init_value = required_com_spec.get_initValue().get_value().get()
                        generated_src_contents.append(f'{data_type} {data_signature} = {init_value};')
                        generated_src_contents.append(f'uint32 {data_signature}_first_reception_flag = 1U;')
                        generated_src_contents.append(f'')

                    for sender in cb_pair_instance.senders:
                            cb_pair_instance.senders[sender].append(com_handle_id)

                    for receiver in cb_pair_instance.receivers:
                        if cb_pair_instance.data_semantic is SwImplPolicyEnum.VALUE_QUEUED:
                            cb_pair_instance.receivers[receiver].append((f'RB_{data_signature}',com_handle_id))
                        else:
                            cb_pair_instance.receivers[receiver].append((f'{data_signature}',com_handle_id))

            __write_com_data_management_h_contents()
            __write_com_data_management_c_contents()

    def generate_rte_cbk_hdr_file(self):
        four_space = '    '
        generated_hdr_contents = []
        generated_src_contents = []

        def __write_rte_cbk_h_contents():
            static_hdr_contents = [
                '#ifndef RTE_CBK_H',
                '#define RTE_CBK_H',
                '',
                '#include "ring_buffer.h"',
                '#include "Rte_Type.h"'
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'Rte_Cbk.h'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                merges_src_contents = static_hdr_contents + generated_hdr_contents
                merges_src_contents.append(f'#endif // RTE_CBK_H')
                f.write('\n'.join(merges_src_contents))

        def __write_rte_cbk_c_contents():
            static_src_contents = [
                f'#include "Rte_Cbk.h"',
                f''
            ]
            dir_path = f'./generated'

            if not os.path.exists(dir_path):
                os.makedirs(dir_path)

            target_file_name = f'Rte_Cbk.c'
            file_path = os.path.join(dir_path, target_file_name)

            with open(file_path, 'w') as f:
                merges_src_contents = static_src_contents + generated_src_contents
                f.write('\n'.join(merges_src_contents))

        communication_boundary_pair_dict = shared_data_instance.get_communication_boundary_pair_dict()
        if 'com' in communication_boundary_pair_dict:
            first_value = next(iter(communication_boundary_pair_dict['com'].values()))  # 直接获取第一个值
            data_type = shared_function.get_impldatatype_symbol(first_value.datatype)

            generated_hdr_contents.append(f'#include "com_data_management.h"')
            generated_hdr_contents.append(f'void Rte_COMCbk (CbkHandleIdType ComUserCbkHandleId);')

            generated_src_contents.append(f'void Rte_COMCbk (CbkHandleIdType ComUserCbkHandleId)' + '{')
            generated_src_contents.append(f'{four_space}{data_type} temp = 0;')
            generated_src_contents.append(f'{four_space}Std_ReturnType return_value = Com_ReceiveSignal(ComUserCbkHandleId, &temp);')
            generated_src_contents.append(f'{four_space}if(return_value == E_OK)' + '{')
            generated_src_contents.append(f'{four_space}{four_space}switch(ComUserCbkHandleId)' + '{')
            for cb_pair_instance in communication_boundary_pair_dict['com'].values():
                for receiver in cb_pair_instance.receivers:
                    # cbk_info = ('rte internal data instance', 'ComUserCbkHandleId')
                    cbk_info = cb_pair_instance.receivers[receiver][0]
                    call_service = None
                    if cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                        call_service = f'{four_space}{four_space}{four_space}{four_space}return_value = RTE_Enqueue(&{cbk_info[0]}, &temp, sizeof({data_type}));'
                    else:
                        call_service = f'{four_space}{four_space}{four_space}{four_space}return_value = RTE_Update(temp, &{cbk_info[0]}, sizeof({data_type}));'
                    generated_src_contents.extend([
                        f'{four_space}{four_space}{four_space}case {cbk_info[1]}:',
                        call_service,
                        f'{four_space}{four_space}{four_space}{four_space}break;'
                    ])
            generated_src_contents.extend([
                f'{four_space}{four_space}{four_space}default:',
                f'{four_space}{four_space}{four_space}{four_space}break;'
            ])
            generated_src_contents.append(f'{four_space}{four_space}' + '}')
            generated_src_contents.append(f'{four_space}' + '}')
            generated_src_contents.append('}')
            __write_rte_cbk_h_contents()
            __write_rte_cbk_c_contents()

    def runnable_declaration(self, runnable):
        # [SWS_Rte_06713]
        runnable_declaration = [
            f'void RTE_RUNNABLE_{runnable.get_shortName()}()'+'{',
            f'/* The algorithm of {runnable.get_shortName()} */',
            f'return;',
            '}',
            f''
        ]
        self.__vfb_interface_contents.extend(runnable_declaration)

    def generate_vfb_interface(self, runnable, sr_pair, apis):
        four_space = '     '
        total_return_value_count = [0]
        communication_boundary_pair_dict = shared_data_instance.get_communication_boundary_pair_dict()

        Rte_Write_ioc_return_value_decision = [
            f'{four_space}switch(final_return_value)' + '{',
            f'{four_space}{four_space}case IOC_E_OK:',
            f'{four_space}{four_space}{four_space}return RTE_E_OK;',
            f'{four_space}{four_space}case IOC_E_NOK:',
            f'{four_space}{four_space}{four_space}return RTE_E_NOK;',
            f'{four_space}{four_space}default:',
            f'{four_space}{four_space}{four_space}return RTE_E_UNDEFINED;',
            f'{four_space}' +'}',
            f'{four_space}return RTE_E_UNDEFINED;'
        ]

        Rte_Send_return_value_decision = [
            f'{four_space}switch(final_return_value)' + '{',
            f'{four_space}{four_space}case IOC_E_OK:',
            f'{four_space}{four_space}{four_space}return RTE_E_OK;',
            f'{four_space}{four_space}case IOC_E_NOK:',
            f'{four_space}{four_space}{four_space}return RTE_E_NOK;',
            f'{four_space}{four_space}case IOC_E_LIMIT:',
            f'{four_space}{four_space}{four_space}return RTE_E_LIMIT',
            f'{four_space}{four_space}default:'
            f'{four_space}{four_space}{four_space}return RTE_E_UNDEFINED;'
            f'{four_space}' +'}',
            f'{four_space}return RTE_E_UNDEFINED;'
        ]

        def __include_hdr_for_communication_boundary(communication_boundarys):
            include_statements = {
                'ioc': '#include "../ioc_data_management.h"',
                'rte': '#include "../rte_data_management.h"',
                'com': '#include "../com_data_management.h"'
            }

            for key in communication_boundarys:
                if key in include_statements:
                    include_statement = include_statements[key]
                    if include_statement not in self.__vfb_interface_contents:
                        self.__vfb_interface_contents.append(include_statement)

        def __add_extern_var(role, communication_boundarys):
            for communication_boundary in communication_boundarys:
                if communication_boundary == 'rte':
                    cb_pair_instance = communication_boundarys['rte']
                    if runnable in getattr(cb_pair_instance, role):
                        for data_signature in getattr(cb_pair_instance, role)[runnable]:
                            data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                            # 檢查並添加 extern {data_type} {data_signature};
                            extern_declaration = f'extern {data_type} {data_signature};'
                            if cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                                extern_declaration = f'extern RingBuffer {data_signature};'
                            if extern_declaration not in self.__vfb_interface_contents:
                                self.__vfb_interface_contents.append(extern_declaration)

                            # 檢查並添加 extern uint32 {data_signature}_first_reception_flag;
                            if role == 'receivers' and cb_pair_instance.data_semantic != SwImplPolicyEnum.VALUE_QUEUED:
                                extern_flag_declaration = f'extern uint32 {data_signature}_first_reception_flag;'
                                if extern_flag_declaration not in self.__vfb_interface_contents:
                                    self.__vfb_interface_contents.append(extern_flag_declaration)

                elif communication_boundary == 'ioc':
                    cb_pair_instance = communication_boundarys['ioc']
                    if runnable in getattr(cb_pair_instance, role):
                        for _, ioc_id, _ in getattr(cb_pair_instance, role)[runnable]:
                            # 檢查並添加 extern uint32 {data_signature}_first_reception_flag;
                            if role == 'receivers' and cb_pair_instance.data_semantic != SwImplPolicyEnum.VALUE_QUEUED:
                                symbol = cb_pair_instance.data_prototype.get_shortName()
                                data_signature = f'{ioc_id}_{symbol}'
                                extern_flag_declaration = f'extern uint32 {data_signature}_first_reception_flag;'
                                if extern_flag_declaration not in self.__vfb_interface_contents:
                                    self.__vfb_interface_contents.append(extern_flag_declaration)

                elif communication_boundary == 'com':
                    cb_pair_instance = communication_boundarys['com']
                    if role == 'receivers' and cb_pair_instance.receivers[runnable]:
                        for data_signature, _ in cb_pair_instance.receivers[runnable]:
                            data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                            # 檢查並添加 extern {data_type} {data_signature};
                            extern_declaration = f'extern {data_type} {data_signature};'
                            if cb_pair_instance.data_semantic == SwImplPolicyEnum.VALUE_QUEUED:
                                extern_declaration = f'extern RingBuffer {data_signature};'
                            if extern_declaration not in self.__vfb_interface_contents:
                                self.__vfb_interface_contents.append(extern_declaration)

                            # 檢查並添加 extern uint32 {data_signature}_first_reception_flag;
                            if cb_pair_instance.data_semantic != SwImplPolicyEnum.VALUE_QUEUED:
                                extern_flag_declaration = f'extern uint32 {data_signature}_first_reception_flag;'
                                if extern_flag_declaration not in self.__vfb_interface_contents:
                                    self.__vfb_interface_contents.append(extern_flag_declaration)

        def __extract_communication_details():
            communication_boundarys = {}
            keys = ['rte', 'ioc', 'com', 'unconnected']  # 鍵的列表

            for key in keys:
                path = sr_pair.data_prototype.get_path()
                value = communication_boundary_pair_dict.get(key, {}).get(path)

                if value is not None:
                    communication_boundarys[key] = value

            return communication_boundarys

        def __merage_all_return_value():
            # 創建一個包含所有 return_value{i} 的列表
            return_values = [f"return_value{index}" for index in range(total_return_value_count[0])]

            # 將所有 return_value{i} 使用 OR 運算符 | 連接
            final_return_value = " | ".join(return_values)
            final_return_statement = f"{four_space}Std_ReturnType final_return_value = {final_return_value};\n"

            # 將最終的賦值語句添加到內容中
            self.__vfb_interface_contents.append(final_return_statement)

        def __handle_data_first_reception(flagid, cb_pair_instance):
            error_check = []
            # 實現 SWS_RTE R21-11 Figure 4.46
            def first_reception_check(handle_invalid, handle_never_received, init_value, invalid_value):
                symbol = cb_pair_instance.data_prototype.get_shortName()
                data_signature = f'{flagid}_{symbol}'
                error_check.append(f'{four_space}if ({data_signature}_first_reception_flag | BIT0) {{')
                if handle_invalid == HandleInvalidEnum.VALUE_EXTERNAL_REPLACEMENT:
                    error_check.append(' // data = return external replacement value;')
                if handle_never_received == True:
                    error_check.append(f'{four_space}{four_space}return RTE_E_NEVER_RECEIVED;')
                elif handle_never_received in (None, 'None', False):
                    if init_value == invalid_value:
                        error_check.append(f'{four_space}{four_space}return RTE_E_INVALID;')
                    else:
                        error_check.append(f'{four_space}{four_space}return RTE_E_OK;')
                error_check.append(f'{four_space}}}')

            port_prototype = cb_pair_instance.rport
            invalidation_policy = shared_function.get_invalidation_policy(port_prototype,cb_pair_instance)
            sw_data_def_prop = shared_function.get_sw_data_def_prop(cb_pair_instance.data_prototype)
            required_com_spec = shared_function.find_required_com_spec(port_prototype, cb_pair_instance.data_prototype)
            if (invalidation_policy and required_com_spec and sw_data_def_prop and\
                required_com_spec.get_initValue() and sw_data_def_prop.get_invalidValue() and\
                invalidation_policy.get_handleInvalid()):
                    init_value = required_com_spec.get_initValue().get_value().get()
                    invalid_value = sw_data_def_prop.get_invalidValue().get_value().get()
                    handle_never_received = required_com_spec.get_handleNeverReceived()
                    handle_invalid = invalidation_policy.get_handleInvalid()
                    # [SWS_Rte_08005], [SWS_Rte_08008], [SWS_Rte_08009]
                    # [SWS_Rte_08046], [SWS_Rte_08047], [SWS_Rte_08048]
                    # [SWS_Rte_08096], [SWS_Rte_08097], [SWS_Rte_08098]
                    first_reception_check(handle_invalid, handle_never_received, init_value, invalid_value)
            return error_check

        def __determine_blocking(runn):
            # [SWS_Rte_01290]
            rte_event_dict = shared_data_instance.get_rte_event_dict()
            for rte_event in rte_event_dict.values():
                if isinstance(rte_event, DataReceivedEvent):
                    if rte_event.get_data():
                        result = shared_function.extract_r_variable_in_atomic_swc_instance_ref(rte_event.get_data())
                        if isinstance(result, list):
                            return_messages = result + [f'Method __determine_blocking failed.']
                            return return_messages
                        # 底線 _ 作為一個占位符，以便忽略不需要的值。這是 Python中的一個常見慣例，用於表示“我不關心這個值”。
                        _ , target_data_element = result
                        if target_data_element == sr_pair.data_prototype:
                            wait_points = runn.get_waitPoints()
                            if wait_points:
                                for wait_point in wait_points:
                                    trigger = wait_point.get_trigger()
                                    if trigger == rte_event:
                                        return True
            return False

        def __handle_invalid(cb_pair_instance):
            error_check = []
            port_prototype = cb_pair_instance.rport
            invalidation_policy = shared_function.get_invalidation_policy(port_prototype,cb_pair_instance)
            sw_data_def_prop = shared_function.get_sw_data_def_prop(cb_pair_instance.data_prototype)
            required_com_spec = shared_function.find_required_com_spec(port_prototype, cb_pair_instance.data_prototype)
            if (invalidation_policy and required_com_spec and sw_data_def_prop and\
                required_com_spec.get_initValue() and sw_data_def_prop.get_invalidValue() and\
                invalidation_policy.get_handleInvalid()):
                    init_value = required_com_spec.get_initValue().get_value().get()
                    invalid_value = sw_data_def_prop.get_invalidValue().get_value().get()
                    handle_invalid = invalidation_policy.get_handleInvalid()

                    error_check.append(f'{four_space}if ( *data == {invalid_value}) ' + '{')
                    if handle_invalid == HandleInvalidEnum.VALUE_EXTERNAL_REPLACEMENT:
                        error_check.append(' // data = return external replacement value;')
                    elif handle_invalid == HandleInvalidEnum.VALUE_REPLACE:
                        error_check.append(f'{four_space}{four_space}*data = {init_value};')

                    if handle_invalid == HandleInvalidEnum.VALUE_KEEP:
                        error_check.append(f'{four_space}{four_space}return RTE_E_INVALID;')
                    error_check.append(f'{four_space}' + '}')
            return error_check

        def __generate_Rte_Write_implementation(rte_api):
            __add_extern_var('senders', communication_boundarys)

            rte_api = rte_api.replace(';', '') + '{\n'
            self.__vfb_interface_contents.append(rte_api)
            for key, cb_pair_instance in communication_boundarys.items():
                if runnable in cb_pair_instance.senders:
                    if key == 'ioc':
                        for service_name, ioc_id, sender_id in cb_pair_instance.senders[runnable]:
                            call_service = f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = {service_name}_{ioc_id}_{sender_id}(data);'
                            self.__vfb_interface_contents.append(call_service)

                            if not rte_api.startswith('void'):
                                error_check = [f'{four_space}if(return_value{total_return_value_count[0]} == IOC_E_NOK) {{',
                                               f'{four_space}{four_space}return RTE_E_NOK;',
                                               f'{four_space}}}'
                                               ]
                            self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    elif key == 'com':
                        for com_handle_id in cb_pair_instance.senders[runnable]:
                            self.__vfb_interface_contents.append(f'{four_space}Com_SignalIdType com_handle_id = {com_handle_id};')
                            call_service =  f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = Com_SendSignal(com_handle_id, &data);'
                            self.__vfb_interface_contents.append(call_service)

                            if not rte_api.startswith('void'):
                                error_check = [f'{four_space}if(return_value{total_return_value_count[0]} == COM_SERVICE_NOT_AVAILABLE) {{',
                                               f'{four_space}{four_space}return RTE_E_COM_STOPPED;',
                                               f'{four_space}}}',
                                               f'{four_space}else if(return_value{total_return_value_count[0]} == COM_BUSY) {{',
                                               f'{four_space}{four_space}return RTE_E_COM_BUSY;',
                                               f'{four_space}}}'
                                               ]
                            self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    elif key == 'rte':
                        for data_signature in cb_pair_instance.senders[runnable]:
                            data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                            call_service = f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = RTE_Update(&{data_signature}, &data, sizeof({data_type}));'
                            self.__vfb_interface_contents.append(call_service)
                            total_return_value_count[0] += 1
                    else:
                        #key == 'unconnected':
                        # [SWS_Rte_01332]
                        if not rte_api.startswith('void'):
                            self.__vfb_interface_contents.append(f'{four_space}return RTE_E_OK;')
                            break
            if not rte_api.startswith('void'):
                self.__vfb_interface_contents.append(f'{four_space}return RTE_E_OK;')
            else:
                self.__vfb_interface_contents.append(f'{four_space}return;')
            self.__vfb_interface_contents.append('}')
            total_return_value_count[0] = 0

        def __generate_Rte_Invalidate_implementation(rte_api):
            __add_extern_var('senders', communication_boundarys)

            rte_api = rte_api.replace(';', '') + '{\n'
            self.__vfb_interface_contents.append(rte_api)
            keys_of_interest = ['ioc', 'com', 'rte']
            cb_pair_instance = next((communication_boundarys[key] for key in keys_of_interest if key in communication_boundarys), None)
            if cb_pair_instance is not None:
                data_type = cb_pair_instance.datatype.get_shortName()
                port_prototype = cb_pair_instance.rport
                invalidation_policy = shared_function.get_invalidation_policy(port_prototype,cb_pair_instance)
                sw_data_def_prop = shared_function.get_sw_data_def_prop(cb_pair_instance.data_prototype)
                if (invalidation_policy and sw_data_def_prop and sw_data_def_prop.get_invalidValue() and\
                    invalidation_policy.get_handleInvalid()):
                        invalid_value = sw_data_def_prop.get_invalidValue().get_value().get()
                        handle_invalid = invalidation_policy.get_handleInvalid()

                        if handle_invalid == HandleInvalidEnum.VALUE_EXTERNAL_REPLACEMENT:
                            self.__vfb_interface_contents.append(f'{data_type} // data = return external replacement value;')
                        elif handle_invalid in (HandleInvalidEnum.VALUE_KEEP, HandleInvalidEnum.VALUE_REPLACE):
                            self.__vfb_interface_contents.append(f'{four_space}// Write the invalid value that config in SwDataDefProps.InvalidValue')
                            self.__vfb_interface_contents.append(f'{four_space}{data_type} data = {invalid_value};')

            for key, cb_pair_instance in communication_boundarys.items():
                if runnable in cb_pair_instance.senders:
                    if key == 'ioc':
                        for service_name, ioc_id, sender_id in cb_pair_instance.senders[runnable]:
                            # call_service = f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = {service_name}_{ioc_id}(data);'
                            # if len(cb_pair_instance.senders) > 1:
                            call_service = f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = {service_name}_{ioc_id}_{sender_id}(data);'
                            self.__vfb_interface_contents.append(call_service)

                            if not rte_api.startswith('void'):
                                error_check = [f'{four_space}if(return_value{total_return_value_count[0]} == IOC_E_NOK) {{',
                                               f'{four_space}{four_space}return RTE_E_NOK;',
                                               f'{four_space}}}'
                                               ]
                            self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    elif key == 'com':
                        for com_handle_id in cb_pair_instance.senders[runnable]:
                            self.__vfb_interface_contents.append(f'{four_space}Com_SignalIdType com_handle_id = {com_handle_id};')
                            call_service =  f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = Com_SendSignal(com_handle_id, &data);'
                            self.__vfb_interface_contents.append(call_service)

                            if not rte_api.startswith('void'):
                                error_check = [f'{four_space}if(return_value{total_return_value_count[0]} == COM_SERVICE_NOT_AVAILABLE) {{',
                                               f'{four_space}{four_space}return RTE_E_COM_STOPPED;',
                                               f'{four_space}}}',
                                               f'{four_space}else if(return_value{total_return_value_count[0]} == COM_BUSY) {{',
                                               f'{four_space}{four_space}return RTE_E_COM_BUSY;',
                                               f'{four_space}}}'
                                               ]
                            self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    elif key == 'rte':
                        for data_signature in cb_pair_instance.senders[runnable]:
                            data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                            call_service = f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = RTE_Update(&{data_signature}, &data, sizeof({data_type}));'
                            self.__vfb_interface_contents.append(call_service)
                            total_return_value_count[0] += 1
                    else:
                        #key == 'unconnected':
                        # [SWS_Rte_03783]
                        if not rte_api.startswith('void'):
                            self.__vfb_interface_contents.append(f'{four_space}return RTE_E_OK;')
                            break
            if not rte_api.startswith('void'):
                self.__vfb_interface_contents.append(f'{four_space}return RTE_E_OK;')
            else:
                self.__vfb_interface_contents.append(f'{four_space}return;')
            self.__vfb_interface_contents.append('}')
            total_return_value_count[0] = 0

        def __generate_Rte_Send_implementation(rte_api):
            __add_extern_var('senders', communication_boundarys)

            rte_api = rte_api.replace(';', '') + '{\n'
            self.__vfb_interface_contents.append(rte_api)
            for key, cb_pair_instance in communication_boundarys.items():
                if runnable in cb_pair_instance.senders:
                    if key == 'ioc':
                        for service_name, ioc_id, sender_id in cb_pair_instance.senders[runnable]:
                            # Queued 1:N Communication -> 拆成 N * Queued 1:1 Communication
                            # for loop 會 call {service_name}_{ioc_id}(data) N次
                            # call_service = f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = {service_name}_{ioc_id}(data);'
                            # if len(cb_pair_instance.senders) > 1:
                            call_service = f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = {service_name}_{ioc_id}_{sender_id}(data);'
                            self.__vfb_interface_contents.append(call_service)

                            mapped_os_object = None
                            for the_runnable in cb_pair_instance.receivers.keys():
                                wait_points = the_runnable.get_waitPoints()
                                if wait_points:
                                    mapped_os_object = shared_function.get_mapped_os_object(the_runnable)
                                if mapped_os_object:
                                    self.__vfb_interface_contents.append(f'{four_space}SetEvent(T11,{mapped_os_object.get_shortName()});')
                            if not rte_api.startswith('void'):
                                error_check = [f'{four_space}if(return_value{total_return_value_count[0]} == IOC_E_LIMIT) {{',
                                               f'{four_space}{four_space}return RTE_E_LIMIT;',
                                               f'{four_space}}}',
                                               f'{four_space}else if(return_value{total_return_value_count[0]} == IOC_E_NOK) {{',
                                               f'{four_space}{four_space}return RTE_E_NOK;',
                                               f'{four_space}}}'
                                               ]
                                self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    elif key == 'com':
                        for com_handle_id in cb_pair_instance.senders[runnable]:
                            self.__vfb_interface_contents.append(f'{four_space}Com_SignalIdType com_handle_id = {com_handle_id};')
                            call_service =  f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = Com_SendSignal(com_handle_id, &data);'
                            self.__vfb_interface_contents.append(call_service)

                            mapped_os_object = None
                            for the_runnable in cb_pair_instance.receivers.keys():
                                wait_points = the_runnable.get_waitPoints()
                                if wait_points:
                                    mapped_os_object = shared_function.get_mapped_os_object(the_runnable)
                                if mapped_os_object:
                                    self.__vfb_interface_contents.append(f'{four_space}SetEvent(T11,{mapped_os_object.get_shortName()});')

                            if not rte_api.startswith('void'):
                                error_check = [f'{four_space}if(return_value{total_return_value_count[0]} == COM_SERVICE_NOT_AVAILABLE) {{',
                                               f'{four_space}{four_space}return RTE_E_COM_STOPPED;',
                                               f'{four_space}}}',
                                               f'{four_space}else if(return_value{total_return_value_count[0]} == COM_BUSY) {{',
                                               f'{four_space}{four_space}return RTE_E_COM_BUSY;',
                                               f'{four_space}}}'
                                               ]
                            self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1

                    elif key == 'rte':
                        for data_signature in cb_pair_instance.senders[runnable]:
                            data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                            call_service = f'{four_space}Std_ReturnType return_value{total_return_value_count[0]} = RTE_Enqueue(&{data_signature}, &data, sizeof({data_type}));'
                            self.__vfb_interface_contents.append(call_service)

                            mapped_os_object = None
                            for the_runnable in cb_pair_instance.receivers.keys():
                                wait_points = the_runnable.get_waitPoints()
                                if wait_points:
                                    mapped_os_object = shared_function.get_mapped_os_object(the_runnable)
                                if mapped_os_object:
                                    self.__vfb_interface_contents.append(f'{four_space}SetEvent(T02,{mapped_os_object.get_shortName()});')

                            if not rte_api.startswith('void'):
                                error_check = [f'{four_space}if(return_value{total_return_value_count[0]} == RTE_E_LIMIT) {{',
                                               f'{four_space}{four_space}return RTE_E_LIMIT;',
                                               f'{four_space}}}'
                                               ]
                            self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    else:
                        # key == 'unconnected'
                        # [SWS_Rte_01332]
                        if not rte_api.startswith('void'):
                            self.__vfb_interface_contents.append(f'{four_space}return RTE_E_OK;')
                            break

            if not rte_api.startswith('void'):
                self.__vfb_interface_contents.append(f'{four_space}return RTE_E_OK;')
            else:
                self.__vfb_interface_contents.append(f'{four_space}return;')
            self.__vfb_interface_contents.append('}')
            total_return_value_count[0] = 0

        def __generate_Rte_Read_implementation(rte_api):
            # communication_boundarys = __extract_communication_details()
            # __include_hdr_for_communication_boundary(communication_boundarys)
            __add_extern_var('receivers', communication_boundarys)

            rte_api = rte_api.replace(';', '') + '{\n'
            self.__vfb_interface_contents.append(rte_api)
            for key, cb_pair_instance in communication_boundarys.items():
                if runnable in cb_pair_instance.receivers:
                    if key == 'ioc':
                        for service_name, ioc_id, receiver_id in cb_pair_instance.receivers[runnable]:
                            call_service = f'return_value{total_return_value_count[0]} = {service_name}_{ioc_id}_{receiver_id}(data);'
                            self.__vfb_interface_contents.append(f'{four_space}Std_ReturnType ' + call_service)

                            port_prototype = cb_pair_instance.rport
                            required_com_spec = shared_function.find_required_com_spec(port_prototype, cb_pair_instance.data_prototype)
                            init_value = required_com_spec.get_initValue().get_value().get()
                            symbol = cb_pair_instance.data_prototype.get_shortName()
                            data_signature = f'{ioc_id}_{symbol}'
                            self.__vfb_interface_contents.extend([
                                    f'{four_space}//clear first_reception_flag check',
                                    f'{four_space}if (*data != {init_value} & {data_signature}_first_reception_flag){{',
                                    f'{four_space}{four_space}CLEAR_BIT0(&{data_signature}_first_reception_flag);',
                                    f'{four_space}}}'
                                ])
                            if not rte_api.startswith('void'):
                                self.__vfb_interface_contents.append(f'{four_space}{four_space}//invalid check')
                                error_check = __handle_invalid(cb_pair_instance)
                                self.__vfb_interface_contents.extend(error_check)

                            total_return_value_count[0] += 1
                    elif key == 'com':
                        for data_signature, _ in cb_pair_instance.receivers[runnable]:
                            data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                            call_service = f'{four_space}return_value{total_return_value_count[0]} = RTE_Fetch(data, &{data_signature}, sizeof({data_type}));'
                            self.__vfb_interface_contents.append(call_service)

                            port_prototype = cb_pair_instance.rport
                            required_com_spec = shared_function.find_required_com_spec(port_prototype, cb_pair_instance.data_prototype)
                            init_value = required_com_spec.get_initValue().get_value().get()
                            com_handle_symbol = shared_function.get_com_handle_symbol(cb_pair_instance.data_prototype)
                            symbol = cb_pair_instance.data_prototype.get_shortName()
                            data_signature = f'{com_handle_symbol}_{symbol}'
                            self.__vfb_interface_contents.extend([
                                    f'{four_space}//clear first_reception_flag check',
                                    f'{four_space}if (*data != {init_value} & {data_signature}_first_reception_flag){{',
                                    f'{four_space}{four_space}CLEAR_BIT0(&{data_signature}_first_reception_flag);',
                                    f'{four_space}}}'
                                ])
                            if not rte_api.startswith('void'):
                                self.__vfb_interface_contents.append(f'{four_space}{four_space}//invalid check')
                                error_check = __handle_invalid(cb_pair_instance)
                                self.__vfb_interface_contents.extend(error_check)

                                error_check = [f'{four_space}if(return_value{total_return_value_count[0]} == COM_SERVICE_NOT_AVAILABLE) {{',
                                               f'{four_space}{four_space}return RTE_E_COM_STOPPED;',
                                               f'{four_space}}}',
                                               f'{four_space}else if(return_value{total_return_value_count[0]} == COM_BUSY) {{',
                                               f'{four_space}{four_space}return RTE_E_COM_BUSY;',
                                               f'{four_space}}}'
                                               ]
                                self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    elif key == 'rte':
                        for data_signature in cb_pair_instance.receivers[runnable]:
                            data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                            call_service = f'{four_space}return_value{total_return_value_count[0]} = RTE_Fetch(data, &{data_signature}, sizeof({data_type}));'
                            self.__vfb_interface_contents.append(f'{four_space}Std_ReturnType ' + call_service)

                            port_prototype = cb_pair_instance.rport
                            required_com_spec = shared_function.find_required_com_spec(port_prototype, cb_pair_instance.data_prototype)
                            init_value = required_com_spec.get_initValue().get_value().get()
                            self.__vfb_interface_contents.extend([
                                    f'{four_space}//clear first_reception_flag check',
                                    f'{four_space}if (*data != {init_value} & {data_signature}_first_reception_flag){{',
                                    f'{four_space}{four_space}CLEAR_BIT0(&{data_signature}_first_reception_flag);',
                                    f'{four_space}}}'
                                ])
                            if not rte_api.startswith('void'):
                                self.__vfb_interface_contents.append(f'{four_space}{four_space}//invalid check')
                                error_check = __handle_invalid(cb_pair_instance)
                                self.__vfb_interface_contents.extend(error_check)

                            total_return_value_count[0] += 1
            if not rte_api.startswith('void'):
                self.__vfb_interface_contents.append(f'{four_space}return RTE_E_OK;')
            else:
                self.__vfb_interface_contents.append(f'{four_space}return;')
            self.__vfb_interface_contents.append('}')
            total_return_value_count[0] = 0

        def __generate_Rte_DRead_implementation(rte_api):
            # if 'rte' in communication_boundarys:
            #     cb_pair_instance = communication_boundarys['rte']
            #     if runnable in cb_pair_instance.receivers:
            #         for data_signature in cb_pair_instance.receivers[runnable]:
            #             data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
            #             self.__vfb_interface_contents.append(f'extern {data_type} {data_signature};')
            __add_extern_var('receivers', communication_boundarys)

            rte_api = rte_api.replace(';', '') + '{\n'
            self.__vfb_interface_contents.append(rte_api)
            keys_of_interest = ['ioc', 'com', 'rte']
            cb_pair_instance = next((communication_boundarys[key] for key in keys_of_interest if key in communication_boundarys), None)
            if cb_pair_instance is not None:
                data_type = cb_pair_instance.datatype.get_shortName()
                self.__vfb_interface_contents.append(f'{four_space}{data_type} dataValue = 0;')
                self.__vfb_interface_contents.append(f'{four_space}{data_type}* data = &dataValue;')
            for key, cb_pair_instance in communication_boundarys.items():
                if runnable in cb_pair_instance.receivers:
                    if key == 'ioc':
                        for service_name, ioc_id, receiver_id in cb_pair_instance.receivers[runnable]:

                            call_service = f'return_value{total_return_value_count[0]} = {service_name}_{ioc_id}_{receiver_id}(data);'
                            self.__vfb_interface_contents.append(f'{four_space}Std_ReturnType ' + call_service)
                            total_return_value_count[0] += 1
                    elif key == 'com':
                        for data_signature, _ in cb_pair_instance.receivers[runnable]:
                            call_service = f'return_value{total_return_value_count[0]} = RTE_Fetch(data, &{data_signature}, sizeof({data_type}));'
                            self.__vfb_interface_contents.append(f'{four_space}Std_ReturnType ' + call_service)
                            total_return_value_count[0] += 1
                    elif key == 'rte':
                        for data_signature in cb_pair_instance.receivers[runnable]:

                            call_service = f'return_value{total_return_value_count[0]} = RTE_Fetch(data, &{data_signature}, sizeof({data_type}));'
                            self.__vfb_interface_contents.append(f'{four_space}Std_ReturnType ' + call_service)
                            total_return_value_count[0] += 1

            self.__vfb_interface_contents.append(f'{four_space}return *data;')
            self.__vfb_interface_contents.append('}')
            total_return_value_count[0] = 0

        def __generate_Rte_Receive_implementation(rte_api):

            # communication_boundarys = __extract_communication_details()
            # __include_hdr_for_communication_boundary(communication_boundarys)
            __add_extern_var('receivers', communication_boundarys)

            rte_api = rte_api.replace(';', '') + '{\n'
            self.__vfb_interface_contents.append(rte_api)
            for key, cb_pair_instance in communication_boundarys.items():
                if runnable in cb_pair_instance.receivers:
                    if key == 'ioc':
                        for service_name, ioc_id, receiver_id in cb_pair_instance.receivers[runnable]:
                            call_service = f'return_value{total_return_value_count[0]} = {service_name}_{ioc_id}(data);'
                            # if len(cb_pair_instance.receivers) > 1:
                                # call_service = f'return_value{total_return_value_count[0]} = {service_name}_{ioc_id}_{receiver_id}(data);'
                            self.__vfb_interface_contents.append(f'{four_space}Std_ReturnType ' + call_service)
                            mapped_os_object = None
                            if __determine_blocking(runnable) == True:
                                # 獲取 wait.timeout確認可以接受的等待時間
                                time_out_value  = 0
                                wait_points = runnable.get_waitPoints()
                                if wait_points:
                                    for wait_point in wait_points:
                                        time_out_value = time_out_value + wait_point.get_timeout()  * 1000
                                mapped_os_object = shared_function.get_mapped_os_object(runnable)
                            wait_event_content = []
                            if mapped_os_object:
                                wait_event_content.extend([
                                    f'{four_space}{four_space}TickType max = 0;',
                                    f'{four_space}{four_space}GetAlarm(alarm1,&max);',
                                    f'{four_space}{four_space}max = max + 10;',
                                    f'{four_space}{four_space}TickType temp = 0;',
                                    f'{four_space}{four_space}WaitEvent({mapped_os_object.get_shortName()});',
                                    f'{four_space}{four_space}GetAlarm(alarm1,&temp);',
                                    f'{four_space}{four_space}if(temp >= max) {{',
                                    f'{four_space}{four_space}{four_space}return RTE_E_TIMEOUT;',
                                    f'{four_space}{four_space}}}',
                                ])
                            if not rte_api.startswith('void'):
                                error_check = []
                                if len (wait_event_content) > 0:
                                    error_check.append(f'{four_space}if(return_value{total_return_value_count[0]} == IOC_E_NO_DATA) ' + '{')
                                    error_check.extend(wait_event_content)
                                    error_check.append(f'{four_space}{four_space}{service_name}_{ioc_id}(data);')
                                    error_check.append(f'{four_space}' + '}')
                                else:
                                    error_check.append( f'{four_space}if(return_value{total_return_value_count[0]} == IOC_E_NO_DATA) ' + '{')
                                    error_check.append(f'{four_space}{four_space}return RTE_E_NO_DATA;')
                                    error_check.append(f'{four_space}' + '}')
                                error_check.extend([
                                    f'{four_space}else if(return_value{total_return_value_count[0]} == IOC_E_NOK) {{',
                                    f'{four_space}{four_space}return RTE_E_NOK;',
                                    f'{four_space}}}'
                                ])
                                self.__vfb_interface_contents.extend(error_check)
                            else:
                                error_check = []
                                error_check.append(f'{four_space}if(return_value{total_return_value_count[0]} == IOC_E_NO_DATA) ' + '{')
                                error_check.extend(wait_event_content)
                                error_check.append(f'{four_space}{four_space}{service_name}_{ioc_id}(data);')
                                error_check.append(f'{four_space}' + '}')
                                self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    elif key == 'com':
                        for data_signature, _ in cb_pair_instance.receivers[runnable]:
                            data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                            call_service = f'return_value{total_return_value_count[0]} = RTE_Dequeue(&{data_signature}, data, sizeof({data_type}));'
                            self.__vfb_interface_contents.append(f'{four_space}Std_ReturnType ' + call_service)
                            mapped_os_object = None
                            if __determine_blocking(runnable) == True:
                                # 獲取 wait.timeout確認可以接受的等待時間
                                time_out_value  = 0
                                wait_points = runnable.get_waitPoints()
                                if wait_points:
                                    for wait_point in wait_points:
                                        time_out_value = time_out_value + wait_point.get_timeout()  * 1000
                                mapped_os_object = shared_function.get_mapped_os_object(runnable)
                            wait_event_content = []
                            if mapped_os_object:
                                wait_event_content.extend([
                                    f'{four_space}{four_space}TickType max = 0;',
                                    f'{four_space}{four_space}GetAlarm(alarm1,&max);',
                                    f'{four_space}{four_space}max = max + 10;',
                                    f'{four_space}{four_space}TickType temp = 0;',
                                    f'{four_space}{four_space}WaitEvent({mapped_os_object.get_shortName()});',
                                    f'{four_space}{four_space}GetAlarm(alarm1,&temp);',
                                    f'{four_space}{four_space}if(temp >= max) {{',
                                    f'{four_space}{four_space}{four_space}return RTE_E_TIMEOUT;',
                                    f'{four_space}{four_space}}}',
                                ])
                            if not rte_api.startswith('void'):
                                error_check = []
                                if len (wait_event_content) > 0:
                                    error_check.append(f'{four_space}if(return_value{total_return_value_count[0]} == RTE_E_NO_DATA) ' + '{')
                                    error_check.extend(wait_event_content)
                                    error_check.append(f'{four_space}{four_space}RTE_Dequeue(&{data_signature}, data, sizeof({data_type}));')
                                    error_check.append(f'{four_space}' + '}')
                                else:
                                    error_check.append( f'{four_space}if(return_value{total_return_value_count[0]} == RTE_E_NO_DATA) ' + '{')
                                    error_check.append(f'{four_space}{four_space}return RTE_E_NO_DATA;')
                                    error_check.append(f'{four_space}' + '}')
                                error_check.extend([
                                    f'{four_space}else if(return_value{total_return_value_count[0]} == RTE_E_NOK) {{',
                                    f'{four_space}{four_space}return RTE_E_NOK;',
                                    f'{four_space}}}'
                                ])
                                self.__vfb_interface_contents.extend(error_check)
                            else:
                                error_check = []
                                error_check.append(f'{four_space}if(return_value{total_return_value_count[0]} == RTE_E_NO_DATA) ' + '{')
                                error_check.extend(wait_event_content)
                                error_check.append(f'{four_space}{four_space}RTE_Dequeue(&{data_signature}, data, sizeof({data_type}));')
                                error_check.append(f'{four_space}' + '}')
                                self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    elif key == 'rte':
                        for data_signature in cb_pair_instance.receivers[runnable]:
                            data_type = shared_function.get_impldatatype_symbol(cb_pair_instance.datatype)
                            call_service = f'return_value{total_return_value_count[0]} = RTE_Dequeue(&{data_signature}, data, sizeof({data_type}));'
                            self.__vfb_interface_contents.append(f'{four_space}Std_ReturnType ' + call_service)
                            # 獲取 wait.timeout確認可以接受的等待時間
                            mapped_os_object = None
                            if __determine_blocking(runnable) == True:
                                # 獲取 wait.timeout確認可以接受的等待時間
                                time_out_value  = 0
                                wait_points = runnable.get_waitPoints()
                                if wait_points:
                                    for wait_point in wait_points:
                                        time_out_value = time_out_value + wait_point.get_timeout()  * 1000
                                mapped_os_object = shared_function.get_mapped_os_object(runnable)
                            wait_event_content = []
                            if mapped_os_object:
                                wait_event_content.extend([
                                    f'{four_space}{four_space}TickType max = 0;',
                                    f'{four_space}{four_space}GetAlarm(alarm1,&max);',
                                    f'{four_space}{four_space}max = max + 10;',
                                    f'{four_space}{four_space}TickType temp = 0;',
                                    f'{four_space}{four_space}WaitEvent(T11,{mapped_os_object.get_shortName()});',
                                    f'{four_space}{four_space}GetAlarm(alarm1,&temp);',
                                    f'{four_space}{four_space}if(temp >= max) {{',
                                    f'{four_space}{four_space}{four_space}return RTE_E_TIMEOUT;',
                                    f'{four_space}{four_space}}}',
                                ])
                            if not rte_api.startswith('void'):
                                error_check = []
                                if len (wait_event_content) > 0:
                                    error_check.append(f'{four_space}if(return_value{total_return_value_count[0]} == RTE_E_NO_DATA) ' + '{')
                                    error_check.extend(wait_event_content)
                                    error_check.append(f'{four_space}{four_space}RTE_Dequeue(&{data_signature}, data, sizeof({data_type}));')
                                    error_check.append(f'{four_space}' + '}')
                                else:
                                    error_check.append( f'{four_space}if(return_value{total_return_value_count[0]} == RTE_E_NO_DATA) ' + '{')
                                    error_check.append(f'{four_space}{four_space}return RTE_E_NO_DATA;')
                                    error_check.append(f'{four_space}' + '}')
                                error_check.extend([
                                    f'{four_space}else if(return_value{total_return_value_count[0]} == RTE_E_NOK) {{',
                                    f'{four_space}{four_space}return RTE_E_NOK;',
                                    f'{four_space}}}'
                                ])
                                self.__vfb_interface_contents.extend(error_check)
                            else:
                                error_check = []
                                error_check.append(f'{four_space}if(return_value{total_return_value_count[0]} == RTE_E_NO_DATA) ' + '{')
                                error_check.extend(wait_event_content)
                                error_check.append(f'{four_space}{four_space}RTE_Dequeue(&{data_signature}, data, sizeof({data_type}));')
                                error_check.append(f'{four_space}' + '}')
                                self.__vfb_interface_contents.extend(error_check)
                            total_return_value_count[0] += 1
                    else:
                        # key == 'unconnected'
                        # [SWS_Rte_01331]
                        if not rte_api.startswith('void'):
                            self.__vfb_interface_contents.append(f'{four_space}return RTE_E_UNCONNECTED;')
                            break

            if not rte_api.startswith('void'):
                self.__vfb_interface_contents.append(f'{four_space}return RTE_E_OK;')
            else:
                self.__vfb_interface_contents.append(f'{four_space}return;')
            self.__vfb_interface_contents.append('}')
            total_return_value_count[0] = 0

        communication_boundarys = __extract_communication_details()
        __include_hdr_for_communication_boundary(communication_boundarys)

        for api in apis:
            if 'Rte_Write' in api:
                __generate_Rte_Write_implementation(api)
            elif 'Rte_Send' in api:
                for runnables in sr_pair.receivers.values():
                    for the_runnable in runnables.keys():
                        if __determine_blocking(the_runnable) == True:
                            if '#include "../../kernel/event.h"' not in self.__vfb_interface_contents:
                                self.__vfb_interface_contents.append('#include "../../kernel/event.h"')
                            if '#include "../../Os_Configure/inc/task_Cfg.h"' not in self.__vfb_interface_contents:
                                self.__vfb_interface_contents.append('#include "../../Os_Configure/inc/task_Cfg.h"')
                            if '#include "../../Os_Configure/inc/event_Cfg.h"' not in self.__vfb_interface_contents:
                                self.__vfb_interface_contents.append('#include "../../Os_Configure/inc/event_Cfg.h"')
                            break
                __generate_Rte_Send_implementation(api)
            elif 'Rte_Read' in api:
                __generate_Rte_Read_implementation(api)
            elif 'Rte_DRead' in api:
                __generate_Rte_DRead_implementation(api)
            elif 'Rte_Receive' in api:
                if __determine_blocking(runnable) == True:
                    #Add Os Alarm & Event service
                    if '#include "../../kernel/alarm.h"' not in self.__vfb_interface_contents:
                        self.__vfb_interface_contents.append('#include "../../kernel/alarm.h"')
                    if '#include "../../kernel/event.h"' not in self.__vfb_interface_contents:
                        self.__vfb_interface_contents.append('#include "../../kernel/event.h"')
                    if '#include "../../Os_Configure/inc/event_Cfg.h"' not in self.__vfb_interface_contents:
                        self.__vfb_interface_contents.append('#include "../../Os_Configure/inc/event_Cfg.h"')
                __generate_Rte_Receive_implementation(api)
            elif 'Rte_Invalidate' in api:
                __generate_Rte_Invalidate_implementation(api)

class AppSrcFileGenerator(VFBIfImplModule):
    def __init__(self):
        super().__init__()
        self.__Rte_SWCSymbol_c_contents = []
        self.__alerting_message = []

    def _clear_lists_contents(self):
       self.__Rte_SWCSymbol_c_contents.clear()
       self._VFBIfImplModule__vfb_interface_contents.clear()
       self.__alerting_message.clear()

    def _write___Rte_SWCSymbol_c_contents(self,SWCSymbol, runnable_symbol):
        dir_path = f'./generated/{SWCSymbol}'

        if not os.path.exists(dir_path):
            os.makedirs(dir_path)

        target_file_name = f'Rte_{SWCSymbol}_{runnable_symbol}.c'
        file_path = os.path.join(dir_path, target_file_name)

        with open(file_path, 'w') as f:
            self.__Rte_SWCSymbol_c_contents.extend([
                f'#define RTE_RUNNABLEAPI_{runnable_symbol}',
                f'#include "Rte_{SWCSymbol}.h" '
            ])
            self.__Rte_SWCSymbol_c_contents.extend(self._VFBIfImplModule__vfb_interface_contents)
            f.write('\n'.join(self.__Rte_SWCSymbol_c_contents))

    def _write___alerting_message_contents(self,SWCSymbol):
        target_file_name = f'AppSrcFileGenerator_alerting_message.log'
        with open(target_file_name, 'a') as f:
            f.write('\n'.join(self.__alerting_message) + '\n')

    def generate_application_c(self,rte_sw_component_instance):
        runnable_accessing_data_elements_dict = shared_data_instance.get_runnable_accessing_data_elements_dict()
        sender_receiver_pair_dict = shared_data_instance.get_sender_receiver_pair_dict()

        if not rte_sw_component_instance.rte_event_to_task_mapping_dict:
            return

        for rte_event_to_task_mapping in rte_sw_component_instance.rte_event_to_task_mapping_dict.values():
            rte_event = rte_event_to_task_mapping.rte_event_ref
            runnable = rte_event.get_startOnEvent()
            if isinstance(rte_event, DataReceivedEvent):
                continue
                # runnable = rte_event_to_task_mapping.runnable_wait_for_data_rcv_event

            data_element_path = None
            if runnable and runnable.get_path() in runnable_accessing_data_elements_dict:
                # 從  runnable_accessing_data_elements_dict 取出 runnable 會 access 的 data elements 以及 role( sender or receiver)
                accessing_data_elements = runnable_accessing_data_elements_dict[runnable.get_path()]
                for data_element_path, role in accessing_data_elements:
                    for runnables in getattr(sender_receiver_pair_dict[data_element_path], role+'s').values():
                        # 找目標 runnable，要取出所有他會使用的 VFB Interface
                        for run, apis in runnables.items():
                            if runnable == run:
                                self.generate_vfb_interface(runnable, sender_receiver_pair_dict[data_element_path], apis)
                self.runnable_declaration(runnable)
                self._write___Rte_SWCSymbol_c_contents(rte_sw_component_instance.swc_type_symbol, runnable.get_shortName())
                self._clear_lists_contents()

    def check_the_swctype_exist(self, rte_swc_instance):
        alerting.print_nodeinfo(rte_swc_instance)
        """
        在 autosarfactory 中是使用 dict to preserve the order of elements
        但是 dict_keys 不能用 index 方式取值，用 for 不是很好的表示，而且 EcucContainerValue 的 referenceValue 只有一個，
        所以就先轉成 list  然後用 index 我認為表達會比較好
        """
        return_messages = []
        ecuc_reference_value = list(rte_swc_instance.get_referenceValues())[0]
        referred_swcprototype = ecuc_reference_value.get_value()
        if  referred_swcprototype is None:
            return_messages = [f'The path of the SwComponentPrototype referenced by {rte_swc_instance} does not exist.']
        else:
            referred_swctype = referred_swcprototype.get_type()
            if referred_swctype is None:
                return_messages = [f'The path of the SwComponentType referenced by {referred_swcprototype} does not exist.']

            else:
                info_messages = [(f'The paths of the SwComponentPrototype and SwComponentType referenced by '
                                f'{rte_swc_instance} both exist. It can correctly reference the application header file.')]
                alerting.print_message(info_messages,'info')
                return referred_swctype

        return_messages.extend([f'Method check_the_swctype_exist failed.'])
        self.__alerting_message.extend(return_messages)
        self._write___alerting_message_contents("AppHdrFileGenerator")
        return None

def main():
    ecu_instance = AppSrcFileGenerator()
    ecu_instance.populate_communication_boundary_pair_dict()

    communication_boundary_pair_dict = shared_data_instance.get_communication_boundary_pair_dict()
    ecu_instance.generate_ring_buffer_service()
    if 'com' in communication_boundary_pair_dict:
        ecu_instance.generate_com_data_management()
    if 'ioc' in communication_boundary_pair_dict:
        ecu_instance.generate_ioc_configuration()
        ecu_instance.generate_ioc_data_management()
    if 'rte' in communication_boundary_pair_dict:
        ecu_instance.generate_rte_data_management()
    ecu_instance.generate_rte_cbk_hdr_file()

    rte_sw_component_instance_dict = shared_data_instance.get_rte_sw_component_instance_dict()
    # rte_sw_component_instance_dict 是用來讓 Code 寫起來更好看的！
    rte_sw_component_instance_list= shared_data_instance.get_rte_sw_component_instance_list()
    for rte_swc_instance in rte_sw_component_instance_list:
        referred_swctype = ecu_instance.check_the_swctype_exist(rte_swc_instance)
        if referred_swctype is None:
            continue
        if isinstance(referred_swctype, NvBlockSwComponentType) or\
                isinstance(referred_swctype, ParameterSwComponentType):
                    ecu_instance.__alerting_message.extend([f'[WARNING]: {referred_swctype},[SWS_Rte_01000].'])
                    continue
        alerting.print_nodeinfo(referred_swctype)

        rte_swc_instance_path = rte_swc_instance.get_path()
        if rte_sw_component_instance_dict[rte_swc_instance_path]:
            rte_sw_component_instance_dict[rte_swc_instance_path].swc_type_symbol = shared_function.get_swc_symbol(referred_swctype)
            ecu_instance.generate_application_c(rte_sw_component_instance_dict[rte_swc_instance_path])
    return True

if __name__ == '__main__':
    main()