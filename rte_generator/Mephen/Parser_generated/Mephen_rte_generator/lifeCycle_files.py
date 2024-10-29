#將 parser 做模組化，每種 RTE API 都有對應的 generator function，方便日後整合。
#合併專案時，放到 af_generate_app_type_h.py 中。
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
    , ApplicationPrimitiveDataType, ImplementationDataType, DataTypeMappingSet, ModeActivationKind\
    ,BackgroundEvent, TimingEvent, InitEvent, SwcModeSwitchEvent, OperationInvokedEvent, AsynchronousServerCallReturnsEvent

from app_h import intra_partition, inter_partition, inter_ECU, dataType_mappingSets, client_server_component_list\
    , arpackages_list, swc_dict, in_task, direct_fn_call, trusted_fn_call, RteEventToTaskMapping_keys\
    ,used_app, task_to_app_mapping, check_server, event_to_task_mapping, ev_dict, rable_dict

class Container_Item:
    def __init__(self, str1, str2):
        self.initContainer_name = str1
        self.event_name = str2

#header of life cycle api
def gen_rte_main_h():
    dir_path = f'./generated'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = f'Rte_Main.h'
    file_path = os.path.join(dir_path, target_file_name)

    write_content = []
    write_content.extend([
        '#include "Rte_Type.h"',
        '',
        '/* EcuM_StartupTwo */',
        'void EcuM_StartupTwo(void);',
        '',
        '/* EcuM_GoDown */',
        'void EcuM_GoDown(void);',
        '',
        '/* BSW Scheduler Life-Cycle API */',
        'void SchM_Start(void);',
        'void SchM_Init(const SchM_ConfigType* ConfigPtr);',
        'void SchM_StartTiming(void);',
        'void SchM_Deinit(void);',
        'void SchM_GetVersionInfo(Std_VersionInfoType *versioninfo);',
        '',
        '/* RTE Life-Cycle API */',
        'Std_ReturnType Rte_Start(void);',
    ])
    
    initContainer = []
    for ev_path in ev_dict:
        ev_name = os.path.basename(ev_dict[ev_path].get_path())
        rable_name = os.path.basename(ev_dict[ev_path].get_startOnEvent().get_path())
        initContainer_name = event_to_task_mapping[ev_name].initContainer_name
        if((initContainer_name != None) and (initContainer_name not in initContainer)):
            initContainer.append(initContainer_name)
    for container in initContainer:
        write_content.extend([
            f'void Rte_Init_{container}(void);'
        ])
    
    write_content.extend([
        'void Rte_StartTiming(void);',
        'Std_ReturnType Rte_Stop(void);',
        '',
    ])

    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

def gen_rte_c():
    dir_path = f'./generated'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = f'Rte.c'
    file_path = os.path.join(dir_path, target_file_name)

    write_content = []
    
    #-----------------------------------------------------------------------
    #Jack 已定義好的部分
    write_content.extend([
        '#include "../Os_Configure/inc/task_Cfg.h"',
        '#include "../Os_Configure/inc/event_Cfg.h"',
        '#include "../Os_Configure/inc/alarm_Cfg.h"',
        '#include "../device/lock.h"',
        '#include "../kernel/os.h"',
        '#include "../kernel/alarm.h"',
        '#include "../kernel/task.h"',
        '',
        '#include "Rte_Type.h"',
        '#include "Rte_Main.h"',
        '#include "Bsw_Event_Cfg.h"',
        '#include "Rte_Event_Cfg.h"',
        '#include "Share_Function.h"',
        '//#include "App2Swc_ModeUser.h"',
        '',
        'const SchM_ConfigType SchM_ConfigSet1 = {',
        '    .schedulerId = 1,',
        '};',
        'SchM_ConfigType scheduler;',
        'Rte_InitState = RTE_STATE_UNINIT;',
        '',
        'void SchM_Start(void) {',
        '    Rte_InitState = RTE_STATE_SCHM_START;',
        '}',
        '',
        '//info. of Bsw initialMode',
        '/*',
        'ModeEventInfo mode_manager_initialMode_disable_mode = {',
        '    .event_ptr = {&bsw_event_t15[BswModeSwitchEvent_EV_10_T15], NULL},',
        '    .func_ptr = {NULL},',
        '    .task = {NULL},',
        '    .num = 1',
        '};',
        'ModeEventInfo mode_manager_initialMode_on_entry = {',
        '    .event_ptr = {NULL},',
        '    .func_ptr = {SCHM_BE_Mode0_Entry, NULL},',
        '    .task = { NULL},',
        '    .num = 0',
        '};',
        '*/',
        '',
        'void SchM_Init(const SchM_ConfigType* ConfigPtr) {',
        '    TaskStateType get_task_state;',
        '    if (ConfigPtr != NULL) {',
        '        scheduler.schedulerId = ConfigPtr->schedulerId;',
        '    }',
        '',
        '    /*',
        '    // Disable events for initial mode',
        '    set_disable_mode(&mode_manager_initialMode_disable_mode);',
        '    //Execute the on-entry Entitys of all initial modes',
        '    set_event(&mode_manager_initialMode_on_entry);',
        '    activate_task(&mode_manager_initialMode_on_entry);',
        '    */',
        '',
        '    GetTaskState(T16, &get_task_state);',
        '    if (get_task_state == SUSPENDED) {',
        '        ActivateTask(T16); //ActivateTask low priority task(background task)',
        '    }',
        '    Rte_InitState = RTE_STATE_SCHM_INIT;',
        '}',
        '',
        'void SchM_StartTiming(void) {',
        '    SetRelAlarm(Countalarm1,9999,10000); //activate core0 RTE Task periodically. First activation is at (GCD-1)ms to assure RTE Task runs before timing events',
        '    SetRelAlarm(Countalarm3,9999,10000); //activate core1 RTE Task periodically',
        '    //SetRelAlarm(alarm3,20000,20000); //activate the OS task containing the TimingEvent periodically.',
        '    //SetRelAlarm(alarm1,30000,30000);',
        '}',
        '',
        'void SchM_Deinit(void) {',
        '    //CancelAlarm(alarm3);',
        '    //CancelAlarm(alarm1);',
        '',
        '    dinit_flag = 1;',
        '    Rte_InitState = RTE_STATE_UNINIT;',
        '}',
        '',
        'void SchM_GetVersionInfo(Std_VersionInfoType *versioninfo) {',
        '    versioninfo->vendorID = RTE_VENDOR_ID;',
        '    versioninfo->moduleID = RTE_MODULE_ID;',
        '    versioninfo->sw_patch_version = RTE_SW_PATCH_VERSION;',
        '}',
        '',
    ])
    #-----------------------------------------------------------------------

    #自己寫的部分：
    #info. of RTE initialMode
    #rte event：disable_mode = initmode (for Rte_Start() to set disable_mode)
    onEntry_initMode = []
    write_content.extend([
        '//info. of RTE initialMode',
        'ModeEventInfo RTE_initialMode_disable_mode = {',
    ])
    for ev_path in ev_dict:
        ev_name = os.path.basename(ev_dict[ev_path].get_path())
        disable_mode = ev_dict[ev_path].get_disabledModes()
        if(len(disable_mode) > 0):
            iniMode_disable_list = []
            for mode in disable_mode:
                mode_name = os.path.basename(mode.get_targetModeDeclaration().get_path())
                if(mode_name.lower() == 'initmode'):
                    iniMode_disable_list.append(mode_name)
            for mode in iniMode_disable_list:
                task_ev_array = 'rte_event_' + event_to_task_mapping[ev_name].task_name.lower()
                index = f'{ev_name}_{event_to_task_mapping[ev_name].task_name.lower()}'
                write_content.extend([
                    '    .event_ptr = ' + '{' + f'&{task_ev_array}[{index}]',
                ])
                if(mode != iniMode_disable_list[-1]):
                    write_content.extend([
                        ', ',
                    ])
                else:
                    write_content[-1] += ', NULL},'
            write_content.extend([
                '    .func_ptr = {NULL},',
                '    .task = {NULL},',
                f'    .num = {len(iniMode_disable_list)}',
                '};',
            ])
    
    #info. of RTE initialMode
    #mode switch event：activation = onEntry, 且 mode 屬性引用 init mode (for Rte_Start() to execute on-entry Entitys of all initial modes)
    write_content.extend([
        'ModeEventInfo RTE_initialMode_on_entry_runnables = {',
    ])
    for ev_path in ev_dict:
        if(type(ev_dict[ev_path]) == SwcModeSwitchEvent):
            ev_name = os.path.basename(ev_dict[ev_path].get_path())
            activation = ev_dict[ev_path].get_activation()
            ref_modes = ev_dict[ev_path].get_modes()
            if(len(ref_modes) > 0):
                for mode in ref_modes:
                    mode_name = os.path.basename(mode.get_targetModeDeclaration().get_path())
                    if(activation == ModeActivationKind.VALUE_ON_ENTRY and mode_name.lower() == 'initmode'):
                        rable_name = os.path.basename(ev_dict[ev_path].get_startOnEvent().get_path())
                        write_content.extend([
                            '    .event_ptr = {NULL},',
                            '    .func_ptr = {' + f'{rable_name}, NULL' + '},',
                            '    .task = { NULL},',
                            '    .num = 0',
                            '};',
                        ])
                        onEntry_initMode.append(ev_name)
                        break

    #event meta data for Rte_Start() and Rte_Init()
    event_triggered_by_RteStart = []
    event_triggered_by_RteInit_diffContainers = [] #儲存  (initContainer_name,  event_name (不用管順序，因為順序已經在 Rte_event_cfg.c 設定好)
    init_events = arnode_query.find_arnode(arpackages_list, InitEvent)
    init_events_name_list = []
    for initEv_path in init_events.keys():
        init_events_name_list.append(os.path.basename(initEv_path))
    for ev_name in (init_events_name_list + onEntry_initMode):
        if(event_to_task_mapping[ev_name].initContainer_name != None):
            initContainer_name = event_to_task_mapping[ev_name].initContainer_name
            event_triggered_by_RteInit_diffContainers.append(Container_Item(initContainer_name, ev_name))
        else:
            event_triggered_by_RteStart.append(ev_name)
    print(event_triggered_by_RteStart)
    # for item in event_triggered_by_RteInit_diffContainers:
    #     print(item.initContainer_name, item.event_name)

    #若有 init event & specific mode siwtch event of initmode "沒有 mapped" 到 initContainer
    write_content.extend([
        '',
        '//[Rte_06766]:',
        '//About Rte_Start(). If specific modeSwitchEvents(on-entry & init mode) aren\'t mapped to init containers, Rte_Start() shall trigger those specific modeSwitchEvents',
        '//Similarly, if initEvents aren\'t mapped to init containers, Rte_Start shall trigger those initEvents',
        'ModeEventInfo RTE_event_triggered_by_RteStart = {',
        '    .event_ptr = {',
    ])
    for ev_name in event_triggered_by_RteStart:
        task_ev_array = 'rte_event_' + event_to_task_mapping[ev_name].task_name.lower()
        index = f'{ev_name}_{event_to_task_mapping[ev_name].task_name.lower()}'
        if ev_name != event_triggered_by_RteStart[-1]:
            write_content[-1] += f'&{task_ev_array}[{index}], '
        else:
            write_content[-1] += f'&{task_ev_array}[{index}],'+ ' NULL},'
            write_content.extend([
                '    .func_ptr = {NULL},',
                '    .task = {NULL},',
                f'    .num = {len(event_triggered_by_RteStart)}',
                '};',
                '',
            ])

    #若有 init event & specific mode siwtch event of initmode "mapped" 到 initContainer
    initContainer_list = []
    for item in event_triggered_by_RteInit_diffContainers:
        initContainer_name = item.initContainer_name
        if initContainer_name not in initContainer_list:
            initContainer_list.append(initContainer_name)
    write_content.extend([
        '//[Rte_06767, Rte_06751]:',
        '//Rte_Init(): trigger events contained in init containers',
        '//[Rte_CONSTR_09063] init Containers: contain initEvents & specific modeSwitchEvents(on-entry & init mode)',
    ])
    for initContainer_name in initContainer_list:
        Same_container_task_list = []
        Same_container_event_list = []
        #找出同一個 initContainer_name 的 event，並找出對應的 task
        for item in event_triggered_by_RteInit_diffContainers:
            if(item.initContainer_name == initContainer_name):
                Same_container_event_list.append(item.event_name)
                task_name = event_to_task_mapping[item.event_name].task_name
                if task_name not in Same_container_task_list:
                    Same_container_task_list.append(task_name)
        # print(Same_container_task_list)
        # print(Same_container_event_list)
        
        #定義 RTE_<initContainer_name>
        write_content.extend([
            f'ModeEventInfo RTE_{initContainer_name} = '+'{',
            '    .event_ptr = {',
        ])
        for ev_name in Same_container_event_list:
            task_ev_array = 'rte_event_' + event_to_task_mapping[ev_name].task_name.lower()
            index = f'{ev_name}_{event_to_task_mapping[ev_name].task_name.lower()}'
            if ev_name != Same_container_event_list[-1]:
                write_content[-1] += f'&{task_ev_array}[{index}], '
            else:
                write_content[-1] += f'&{task_ev_array}[{index}],'+ ' NULL},'
                write_content.extend([
                    '    .func_ptr = {NULL},',
                    '    .task = {'
                ])
                for task in Same_container_task_list:
                    if task != Same_container_task_list[-1]:
                        write_content[-1] += f'&{task}, '
                    else:
                        write_content[-1] += f'{task},' + ' NULL},'
                        write_content.extend([
                            f'    .num = {len(Same_container_event_list)}',
                            '};',
                            '',
                        ])

    #Rte_Start()
    write_content.extend([
        'Std_ReturnType Rte_Start(void){',
        '    Std_ReturnType ret = RTE_E_OK;',
        '    TaskStateType get_task_state;',
        '',
        '    //Disable part of events of initial mode (which can\'t be triggerd in initial mode)',
        '    set_disable_mode(&RTE_initialMode_disable_mode);',
        '    ',
        '    //Execute the on-entry Entitys of all initial modes, and activate the task where these on-entry Entitys are mapped',
        '    set_event(&RTE_initialMode_on_entry_runnables);',
        '    activate_task(&RTE_initialMode_on_entry_runnables);',
        '',
        '    //Rte_06766',
        '    //if initEvents or specific modeSwitchEvents(on-entry & init mode) aren\'t mapped to init containers, Rte_Start shall trigger those specific events',
    ])
    if event_triggered_by_RteStart:
        write_content.extend([
            '    set_event(&RTE_event_triggered_by_RteStart);',
        ])
    write_content.extend([
        '',
        '    /*If the Rte_StartTiming() does not exist, Rte_Start() shall handle RTE BackgroundEvents & RTE TimingEvents*/',
    ])
    if not event_triggered_by_RteInit_diffContainers: #Rte_init() doesn't exist, so Rte_StartTiming doesn't exist either
        write_content.extend([
            '    //handle RTE BackgroundEvents',
            '    GetTaskState(T16, &get_task_state);',
            '    if (get_task_state == SUSPENDED) {',
            '        ActivateTask(T16); //ActivateTask low priority task(background task)',
            '    }',
            '',
            '    //handle RTE TimingEvents',
            '    //don\'t need to set alarms to activate RTE Task and backgroud Task periodically, because their alarms are already set in SchM_StartTiming()',
            '    //if case4 happens, activate the OS task containing the TimingEvent periodically. (case4:In eventToTaskMapping, eventRef, taskRef, and alarmRef are all set)',
        ])
        for ev_path in ev_dict:
            if(type(ev_dict[ev_path]) == TimingEvent): #只有 TimingEvent(有period屬性) 才能配 alarm
                ev_name = os.path.basename(ev_path)
                if(event_to_task_mapping[ev_name].task_name != None \
                        and event_to_task_mapping[ev_name].alarm_name != None): 
                    alarm = event_to_task_mapping[ev_name].alarm_name
                    period = ev_dict[ev_path].get_period()
                    write_content.extend([
                        f'    ret = SetRelAlarm({alarm}, {int(period*1000)}, {int(period*1000)}); //activate the OS task containing the TimingEvent periodically.',
                    ])
    write_content.extend([
        '',
        '    Rte_InitState = RTE_STATE_START;',
        '',
        '    if(ret != RTE_E_OK){',
        '        return RTE_E_LIMIT;',
        '    }',
        '    return ret;',
        '}',
    ])

    #Rte_Init()
    write_content.extend([
        '',
        '//if any RteInitializationRunnableBatch container is configured, create its corresponding Rte_Init_<container> function',
    ])
    if initContainer_list:
        for initContainer_name in initContainer_list:
            write_content.extend([
                f'void Rte_Init_{initContainer_name}(void)' + '{',
                '    //Rte_06767, Rte_06751',
                f'    set_event(&RTE_{initContainer_name});',
                f'    activate_task(&RTE_{initContainer_name});',
                '',
                '    Rte_InitState = RTE_STATE_INIT;',
                '}'
            ])

    #Rte_StartTiming()
    write_content.extend([
        '',
        '//if any Rte_init() exit, create Rte_StartTiming()',
    ])
    if initContainer_list:
        write_content.extend([
            'void Rte_StartTiming(void){',
            '    TaskStateType get_task_state;',
            '',
            '    /*---------------------------------------------------------------------------------------------------------*/',
            '    /*If the Rte_StartTiming() exist, it shall handle RTE BackgroundEvents & RTE TimingEvents*/',
            '    //handle RTE BackgroundEvents',
            '    GetTaskState(T16, &get_task_state);',
            '    if (get_task_state == SUSPENDED){',
            '        ActivateTask(T16); //ActivateTask low priority task(background task)',
            '    }',
            '',
            '    //handle RTE TimingEvents',
            '    //don\'t need to set alarms to activate RTE Task and backgroud Task periodically, because their alarms are already set in SchM_StartTiming()',
            '    //if case4 happens, activate the OS task containing the TimingEvent periodically. (case4:In eventToTaskMapping, eventRef, taskRef, and alarmRef are all set)',
        ])
        #case4:In eventToTaskMapping, eventRef, taskRef, and alarmRef are all set
        for ev_path in ev_dict:
            if(type(ev_dict[ev_path]) == TimingEvent): #只有 TimingEvent(有period屬性) 才能配 alarm
                ev_name = os.path.basename(ev_path)
                if(event_to_task_mapping[ev_name].task_name != None \
                        and event_to_task_mapping[ev_name].alarm_name != None): 
                    alarm = event_to_task_mapping[ev_name].alarm_name
                    period = ev_dict[ev_path].get_period()
                    write_content.extend([
                        f'    SetRelAlarm({alarm}, {int(period*1000)}, {int(period*1000)}); //activate the OS task containing the TimingEvent periodically.',
                    ])
        write_content.extend([
            '}',
        ])

    #Rte_Stop()
    write_content.extend([
        '',
        '//cancel timing_ev related alarms',
        'Std_ReturnType Rte_Stop(void){',
    ])
    for ev_path in ev_dict:
        if(type(ev_dict[ev_path]) == TimingEvent): #只有 TimingEvent(有period屬性) 才能配 alarm
            ev_name = os.path.basename(ev_path)
            if(event_to_task_mapping[ev_name].task_name != None \
                    and event_to_task_mapping[ev_name].alarm_name != None): 
                alarm = event_to_task_mapping[ev_name].alarm_name
                period = ev_dict[ev_path].get_period()
                write_content.extend([
                    f'    CancelAlarm({alarm});',
                ])
    write_content.extend([
        '',
        '    dinit_flag = 1;',
        '    Rte_InitState = RTE_STATE_STOP;',
        '}',
    ])

    #-----------------------------------------------------------------------
    #Jack 已定義好的部分
    write_content.extend([
        '',
        '/* EcuM for test */',
        'void EcuM_StartupTwo(void) {',
        '    SchM_Start();',
        '    SchM_Init(&SchM_ConfigSet1);',
        '    SchM_StartTiming();',
        '    Rte_Start();',
        '    //if the RteInitializationRunnableBatch container is configured',
    ])
    if initContainer_list:
        for initContainer_name in initContainer_list:
            write_content.extend([
                f'    Rte_Init_{initContainer_name}();',
            ])
        write_content.extend([
            '    Rte_StartTiming(); //if any Rte_Init() is created',
        ])
    write_content.extend([
        '}',
        '',
        '/* EcuM for test */',
        'void EcuM_GoDown(void) {',
        '    Rte_Stop();',
        '    SchM_Deinit();',
        '}',
    ])
    #-----------------------------------------------------------------------

    #覆寫
    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

def main():
    gen_rte_main_h()
    gen_rte_c()

if __name__ == '__main__':
    main()


