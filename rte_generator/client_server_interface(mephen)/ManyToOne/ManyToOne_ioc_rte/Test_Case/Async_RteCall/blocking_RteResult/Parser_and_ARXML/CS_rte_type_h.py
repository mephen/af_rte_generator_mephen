#合併專案時，整合到 af_generate_rte_type_h.py 中。
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
    , ApplicationPrimitiveDataType, ImplementationDataType, DataTypeMappingSet
from CS_app_h import dataType_mappingSets, client_server_component_list, arpackages_list, swc_dict, check_server



def main():
    write_content = []
    write_content.extend([
        '//Data Type Definitions',
        '//----------------------------------------------------------------',
        '#ifndef Rte_Type_h',
        '#define Rte_Type_h',
        '#include "Rte.h"',
        '',
        '/* AUTOSAR Implementation data types, specific to software component */',
    ])

    #find swBaseType of ImplementationDataType
    implSymbol_baseType_mapping_dict = {}
    for arpackage in arpackages_list:
        if(arpackage.get_shortName() == 'CS_Composition'):
            arpackages_CS_Composition = arpackage.get_arPackages()
            for pack_cs in arpackages_CS_Composition:
                if(pack_cs.get_shortName() == 'Datatypes'):
                    packs_Datatypes = pack_cs.get_arPackages()
                    for pack_data in packs_Datatypes:
                        if(type(list(pack_data.get_elements())[0]) == ImplementationDataType):
                            impl_DTs = pack_data.get_elements()
                            # print(impl_DTs)
                            for impl_DT in impl_DTs:
                                swBase_DT = list(impl_DT.get_swDataDefProps().get_swDataDefPropsVariants())[0].get_baseType()
                                impl_DT_symbol = impl_DT.get_symbolProps().get_symbol()
                                # print(impl_DT_symbol)
                                implSymbol_baseType_mapping_dict[impl_DT_symbol] = swBase_DT
    # print(implSymbol_baseType_mapping_dict)

    for impl_symbol in implSymbol_baseType_mapping_dict:
        swBase_DT_name = implSymbol_baseType_mapping_dict[impl_symbol].get_shortName()
        write_content.append( f'typedef {swBase_DT_name.lower()} {impl_symbol};' )
    
    write_content.extend([
        '',
        '//use uint8 will cause error when test with GetLock/ReleaseLock protection',
        'typedef uint32 RteEventType;',
        'typedef struct{',
        '    RteEventType rteevent;',
        '    RteEventType rteevent_disableinmode; //for mode switch interface',
        '    RteEventType rteevent_flag; //for mode switch interface',
        '} RteEventStatus;',
        '',
        '//Define the Ring Buffer(FIFO) structure',
        'typedef struct {',
        '    void *buffer;          // buffer array',
        '    size_t head;           // head index: point to the oldest data',
        '    size_t tail;           // tail index: point to the next available position of the newest data',
        '    size_t maxSize;        // maximum number of elements',
        '    size_t currentSize;    // current number of elements',
        '}RingBuffer;',
        '',
        'typedef struct{',
        '    uint16 client_id; //runnable ID',
        '    uint16 sequence_counter;',
        '        //Async Rte_call: the sequence_counter record how many Async Rte_call has been "invoked", and the sequence_counter of rte_result records how many c/s communication has been "finished".',
        '        //Sync Rte_call: the sequence_counter record how many c/s communication has been "finished".',
        '}Rte_Cs_TransactionHandleType; //follow spec.',
        '',
        '//each Rte_call(serverCallPoint) has its own metaData.(client server communication)',
        'typedef struct{',
        '    Rte_Cs_TransactionHandleType transaction_handle;',
        '    char connected_unconnected[20];',
        '    char in_exclusiveArea_or_not[20];',
        '    char CanAccess[20];',
        '}RteCallMetaData;',
        '',
        '//each Rte_result has its own metaData.(Asynchronous client server communication)',
        'typedef struct{',
        '    Rte_Cs_TransactionHandleType transaction_handle;',
        '    char connected_unconnected[20];',
        '    char in_exclusiveArea_or_not[20];',
        '    char CanAccess[20];',
        '}RteResultMetaData;',
        '',
        'typedef struct{',
        '    Std_ReturnType bsw_error; //record bsw service error in the client_side_task which process the server_response during a c/s communication',
        '    Rte_Cs_TransactionHandleType transaction_handle;',
        '    uint16 response;',
        '}ResponseInfoType;',
        '',
        'typedef struct{',
        '    uint16 status_uint16;',
        '        // (LSB)0st-3th bit: rteevent counter. (count how many times this event is triggered)',
        '        // 4th-8th bit: rteevent type. (for-loop in OsTask need this information to use different condition statement)',
        '        // 9th bit: rteevent_disablemode. (rteevent can trigger the coreesponding runnable or not. If the para of Rte_Switch(mode) is irrelevant to this event , rteevent_disablemode will be cleared at the beginning of Rte_Switch, otherwise it will be set.)',
        '        // 10th bit: runnable_execute. (runnable is executing or not. In a sync mode_switch, the mode manager has to wait until mode_disabling_dependency_runnable terminate.)',
        '        // 11th-15th bit: Event type specific attribute',
        '            //OperationInvokedEvent, AsynchronousServerCallReturnsEvent:',
        '                //11th-12th bit: communication type. (inter-ecu / inter-partition / intra-partition)',
        '    union{',
        '        void (*Runnable_FuncPtr)();',
        '        uint16 (*Runnable_FuncPtr_RVuint16)();',
        '    };',
        '} RteEvent;',
        '/****************************************************************************************/',
        '#endif//Rte_Type_h',
    ])

    dir_path = f'./generated'
    if not os.path.exists(dir_path):
        os.makedirs(dir_path)
    target_file_name = f'Rte_Type.h'
    file_path = os.path.join(dir_path, target_file_name)
    # print(file_path)

    with open(file_path, 'w') as f:
        f.write('\n'.join(write_content))

if __name__ == '__main__':
    main()