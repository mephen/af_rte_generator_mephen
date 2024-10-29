#Schm 的簡易 parser，單純是為了能測試 RTE Life Cycle api 而生。
#Schm 的完整 parser 在 Jack 那，日後再整合。

import pdb
import platform
import os, shutil
from termcolor import colored

from autosarfactory import autosarfactory
from tsepp_modules import arnode_query
from autosarfactory.autosarfactory import DataTypeMappingSet\
    , RTEEvent, RunnableEntity, SwBaseType, ImplementationDataType\
    , SwComponentType, ApplicationSwComponentType, EcucModuleConfigurationValues,EcucModuleDef\
    , DataReceivedEvent, AssemblySwConnector, SystemMapping, SynchronousServerCallPoint, AsynchronousServerCallPoint\
    , OperationInvokedEvent, AsynchronousServerCallReturnsEvent, ARPackage, ARElement\
    , ApplicationPrimitiveDataType, ImplementationDataType, DataTypeMappingSet\
    ,BackgroundEvent, TimingEvent, InitEvent, SwcModeSwitchEvent, OperationInvokedEvent, AsynchronousServerCallReturnsEvent

from app_h import intra_partition, inter_partition, inter_ECU, dataType_mappingSets, client_server_component_list\
    , arpackages_list, swc_dict, in_task, direct_fn_call, trusted_fn_call, RteEventToTaskMapping_keys\
    ,used_app, task_to_app_mapping, check_server, event_to_task_mapping, ev_dict, rable_dict

#假設 timing_ev gcd 是 10s (Jack 會統一算)
period_gcd = 10

timing_ev_dict = arnode_query.find_arnode(arpackages_list, TimingEvent)

def gen_share_function_c():
    dir_path = f'./generated'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = f'Share_Function.c'
    file_path = os.path.join(dir_path, target_file_name)

    write_content = []
    
    #-----------------------------------------------------------------------
    #Jack 已定義好的部分
    write_content.extend([
        '#include "Share_Function.h"',
        '//#include "Rte_Event_Cfg.h"',
        '',
        'uint32 share_function_lock_q = 0;',
        'uint32 share_function_lock_bit = 1;',
        'uint32 schm_not_init = 0;',
        'uint32 schm_stop = 0;',
        '',
        'int count_0 = 0;',
        'int count_1 = 0;',
        'int init_flag_0 = 0;',
        'int init_flag_1 = 0;',
        'int dinit_flag = 0;',
        'int modes_witch_count = 0;',
        'int mode_mamager_wakeup_count = 0;',
        '',
        'void activate_task(ModeEventInfo *current_event_union){',
        '    TaskStateType get_task_state;',
        '    int p = 0;',
        '    int *act_task = current_event_union->task;',
        '    while(*act_task != NULL && p != -1){',
        '        if (act_task[p] != NULL) {',
        '            GetTaskState(act_task[p], &get_task_state);',
        '            if (get_task_state == SUSPENDED) {',
        '                ActivateTask(act_task[p]);',
        '            }',
        '            p++;',
        '        } else {',
        '            p = -1;',
        '        }',
        '    }',
        '    p = 0;',
        '    while(current_event_union->func_ptr != NULL && p != -1) {',
        '        if (current_event_union->func_ptr[p] != NULL) {',
        '            current_event_union->func_ptr[p]();',
        '            p++;',
        '        } else {',
        '            p = -1;',
        '        }',
        '    }',
        '}',
        '',
        'void set_disable_mode (ModeEventInfo *current_event_union) {',
        '    if (current_event_union != NULL) {',
        '        Event **event_ptrs = current_event_union->event_ptr;',
        '        int p = 0;',
        '        GetLock(&share_function_lock_q,share_function_lock_bit);',
        '        while(*event_ptrs != NULL && p != -1) {',
        '            Event **current_event_ptr = event_ptrs[p];',
        '            if (current_event_ptr != NULL) {',
        '                Event *current_event = *current_event_ptr;',
        '                set_event_disablemode(current_event);',
        '                p++;',
        '            } else {',
        '                p = -1;',
        '            }',
        '        }',
        '        ReleaseLock(&share_function_lock_q,share_function_lock_bit);',
        '    }',
        '}',
        '',
        'void clear_disable_mode (ModeEventInfo *current_event_union) {',
        '    if (current_event_union != NULL) {',
        '        Event **event_ptrs = current_event_union->event_ptr;',
        '        int p = 0;',
        '        GetLock(&share_function_lock_q,share_function_lock_bit);',
        '        while(*event_ptrs != NULL && p != -1) {',
        '            Event **current_event_ptr = event_ptrs[p];',
        '            if (current_event_ptr != NULL) {',
        '                Event *current_event = *current_event_ptr;',
        '                clear_event_disablemode(current_event);',
        '                p++;',
        '            } else {',
        '                p = -1;',
        '            }',
        '        }',
        '        ReleaseLock(&share_function_lock_q,share_function_lock_bit);',
        '    }',
        '}',
        '',
        'void set_event (ModeEventInfo *current_event_union) {',
        '    if (current_event_union != NULL) {',
        '        Event **event_ptrs = current_event_union->event_ptr;',
        '        int p = 0;',
        '        GetLock(&share_function_lock_q,share_function_lock_bit);',
        '        while(*event_ptrs != NULL && p != -1) {',
        '            Event **current_event_ptr = event_ptrs[p];',
        '            if (current_event_ptr != NULL) {',
        '                Event *current_event = *current_event_ptr;',
        '                trigger_event(current_event);',
        '                p++;',
        '            } else {',
        '                p = -1;',
        '            }',
        '        }',
        '        ReleaseLock(&share_function_lock_q,share_function_lock_bit);',
        '    }',
        '}',
        '',
        'void wait_executed_finish (ModeEventInfo *current_event_union) {',
        '    if (current_event_union != NULL) {',
        '        Event **event_ptrs = current_event_union->event_ptr;',
        '        int p = 0;',
        '        while(*event_ptrs != NULL && p != -1) {',
        '            Event **current_event_ptr = event_ptrs[p];',
        '            if (current_event_ptr != NULL) {',
        '                Event *current_event = *current_event_ptr;',
        '                while (get_entity_execute(current_event) != 0 ) {}',
        '                p++;',
        '            } else {',
        '                p = -1;',
        '            }',
        '        }',
        '    }',
        '}',
        '',
    ])
    #-----------------------------------------------------------------------
    
    #自己寫的部分：
    evinfo_core0 = []
    evinfo_core0_count = 0
    evinfo_core1 = []
    evinfo_core1_count = 0
    evinfo_direct_fn = []
    evinfo_direct_fn_count = 0
    
    #timing_ev meta data
    for ev_path in timing_ev_dict:
        ev_name = os.path.basename(ev_path)
        ev_period = ev_dict[ev_path].get_period()
        rable_name = os.path.basename(ev_dict[ev_path].get_startOnEvent().get_path())
        #case1: direct_fn_call
        if(event_to_task_mapping[ev_name].task_name == None\
                and event_to_task_mapping[ev_name].alarm_name == None):
            print('case1')
            evinfo_direct_fn_count += 1
            write_content.extend([
                f'TimingEventInfo {ev_name}_info = ' + '{',
                '    .event_ptr = NULL,',
                f'    .event_func_ptr = {rable_name},',
                '    .event_task = NULL,',
                f'    .period_multiple = {int(ev_period/period_gcd)},',
                '};',
            ])
            evinfo_direct_fn.append(f'{ev_name}_info')
        #case3: In eventToTaskMapping, eventRef and taskRef are set
        elif(event_to_task_mapping[ev_name].task_name != None\
                and event_to_task_mapping[ev_name].alarm_name == None):
            print('case3')
            match event_to_task_mapping[ev_name].task_name:
                case 'T01' | 'T02' | 'T03' | 'T04' | 'T05' | 'T06' :
                    evinfo_core0_count += 1
                    evinfo_core0.append(f'{ev_name}_info')
                case _:
                    evinfo_core1_count += 1
                    evinfo_core1.append(f'{ev_name}_info')
            write_content.extend([
                f'TimingEventInfo {ev_name}_info = ' + '{',
                f'    .event_ptr = &{ev_name},',
                '    .event_func_ptr = NULL,',
                f'    .event_task = {event_to_task_mapping[ev_name].task_name},',
                f'    .period_multiple = {int(ev_period/period_gcd)},',
                '};',
            ])
        #case4:In eventToTaskMapping, eventRef, taskRef, and alarmRef are all set
        elif(event_to_task_mapping[ev_name].task_name != None\
                and event_to_task_mapping[ev_name].alarm_name != None):
            print('case4')
            match event_to_task_mapping[ev_name].task_name:
                case 'T01' | 'T02' | 'T03' | 'T04' | 'T05' | 'T06' :
                    evinfo_core0_count += 1
                    evinfo_core0.append(f'{ev_name}_info')
                case _:
                    evinfo_core1_count += 1
                    evinfo_core1.append(f'{ev_name}_info')
            write_content.extend([
                f'TimingEventInfo {ev_name}_info = ' + '{',
                f'    .event_ptr = &{ev_name},',
                '    .event_func_ptr = NULL,',
                '    .event_task = NULL,',
                f'    .period_multiple = {int(ev_period/period_gcd)},',
                '};',
            ])
        else:
            print('wrong case')
    
    #timing_ev_info array 
    #   core0
    if evinfo_core0_count != 0:
        write_content.extend([
            '',
            f'#define TimingEventCore0_ArraySize {evinfo_core0_count + evinfo_direct_fn_count}',
            f'TimingEventInfo *TimingEventCore0[TimingEventCore0_ArraySize] =' + ' {'
        ])
        combined_list = evinfo_core0 + evinfo_direct_fn
        for evinfo in combined_list:
            write_content[-1] += (f'&{evinfo}')
            if evinfo != combined_list[-1]:
                write_content[-1] += ', '
        write_content[-1] += '};'
    else:
        write_content.extend([
            '',
            '#define TimingEventCore0_ArraySize 0',
            'TimingEventInfo *TimingEventCore0;',
        ])
    #   core1
    if evinfo_core1_count != 0:
        write_content.extend([
            '',
            f'#define TimingEventCore1_ArraySize {evinfo_core1_count}',
            f'TimingEventInfo *TimingEventCore1[TimingEventCore1_ArraySize] =' + ' {'
        ])
        for evinfo in evinfo_core1:
            write_content[-1] += (f'&{evinfo}')
            if evinfo != evinfo_core1[-1]:
                write_content[-1] += ', '
        write_content[-1] += '};'
    else:
        write_content.extend([
            '',
            '#define TimingEventCore1_ArraySize 0',
            'TimingEventInfo *TimingEventCore1;',
        ])
    
    #-----------------------------------------------------------------------
    #Jack 已定義好的部分
    write_content.extend([
        '',
        '// core0 period counter(gcd)',
        'void core0_period_counter(){',
        '    TaskStateType get_task_state;',
        '    count_0++;',
        '    for (int i=0 ; i<TimingEventCore0_ArraySize ; i++ ){',
        '        if (count_0 % TimingEventCore0[i]->period_multiple == 0 && dinit_flag == 0) {',
        '            if (TimingEventCore0[i]->event_func_ptr == NULL) {',
        '                GetLock(&share_function_lock_q,share_function_lock_bit);',
        '                trigger_event(TimingEventCore0[i]->event_ptr);',
        '                ReleaseLock(&share_function_lock_q,share_function_lock_bit);',
        '                ',
        '                //avoid multiple activation of the same task',
        '                if (TimingEventCore0[i]->event_task != NULL) { ',
        '                    GetTaskState(TimingEventCore0[i]->event_task, &get_task_state);',
        '                    if (get_task_state == SUSPENDED) {',
        '                        ActivateTask(TimingEventCore0[i]->event_task);',
        '                    }',
        '                }',
        '            } else { //direct fn. call',
        '                TimingEventCore0[i]->event_func_ptr();',
        '            }',
        '        }',
        '    }',
        '}',
        '',
        '// core1 period counter(gcd)',
    ])
    if evinfo_core1_count == 0:
        write_content.extend(['/*'])
    write_content.extend([
        'void core1_period_counter(){',
        '    TaskStateType get_task_state;',
        '    count_1++;',
        '    for (int i=0 ; i<TimingEventCore1_ArraySize ; i++ ){',
        '        if (count_1 % TimingEventCore1[i]->period_multiple == 0 && dinit_flag == 0) {',
        '            if (TimingEventCore1[i]->event_func_ptr == NULL) {',
        '                GetLock(&share_function_lock_q,share_function_lock_bit);',
        '                trigger_event(TimingEventCore1[i]->event_ptr);',
        '                ReleaseLock(&share_function_lock_q,share_function_lock_bit);',
        '                if (TimingEventCore1[i]->event_task != NULL) {',
        '                    GetTaskState(TimingEventCore1[i]->event_task, &get_task_state);',
        '                    if (get_task_state == SUSPENDED) {',
        '                        ActivateTask(TimingEventCore1[i]->event_task);',
        '                    }',
        '                }',
        '            } else {',
        '                TimingEventCore1[i]->event_func_ptr();',
        '            }',
        '        }',
        '    }',
        '}',
    ])
    if evinfo_core1_count == 0:
        write_content.extend(['*/'])
    #-----------------------------------------------------------------------

    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

def main():
    #share_function.h 使用現成檔案
    #share_function.c 因為要定義 timing_ev meta data，所以要自己寫
    gen_share_function_c()

if __name__ == '__main__':
    main()