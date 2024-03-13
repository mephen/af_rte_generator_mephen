//VFB interface(api) & Runnable Implementation
//----------------------------------------------------------------
#define RTE_CLIENT_RUNNABLE_1_C
#include "Rte_Client_Runnable.h"
#include "../ringbuffer.h"
#include "../../kernel/alarm.h"
#include "../../kernel/Ioc.h"
#include "../../kernel/event.h"
#include "../../OS_Configure/inc/event_Cfg.h"
#include "../../device/lock.h"

//for RTE to ensure the order of server responses on the client side
//shared by all the client response runnables
//Rte_Client_Runnable_1.c have to execute first, or other response runnables can't use Rte_response_RB_rte
Impl_uint16 Rte_response_buffer_rte[20];
RingBuffer Rte_response_RB_rte = {
    Rte_response_buffer_rte,
    0,
    0,
    20,
    0
};

//each intra-partition C/S communication has its own parameter buffer
Impl_uint16 Rte_parameter_buffer_rte[20];
RingBuffer Rte_parameter_RB_rte = {
    Rte_parameter_buffer_rte,
    0,
    0,
    20,
    0
};

//outside flag in OsTask body which can help sync Rte_call to check error type.
Std_ReturnType errorFlag_Rte_Call_Port1_IntraPartitionSynchronousAdd = RTE_E_OK;

//record running rte_call. used to check RTE_E_LIMIT in client server communication
#define client_record_request_MAX_SIZE 10
Rte_call_metaData rte_call_record_buffer[client_record_request_MAX_SIZE];
RingBuffer rte_call_record_RB = {
    rte_call_record_buffer,
    0,
    0,
    client_record_request_MAX_SIZE,
    0
};

Rte_call_metaData Rte_Call_Port1_IntraPartitionAsynchronousAdd_metaData = {
    .transaction_handle = {
        .client_id = 3U,        //according to the configuration arxml
        .sequence_counter = 0U, //default value
        .communication_type = 3, //rte
        .Async_rteCall_returnValue = RTE_E_OK
    },
    .port = "Port1",
    .connected_unconnected = "connected",
    .in_exclusiveArea_or_not = "NotInExclusiveArea",
    .CanAccess = "Can",
    .sync_async = "Asynchronous",
    .operation = "Add",
    .run_stop = "stop"
};

Rte_call_metaData Rte_Call_Port1_IntraPartitionSynchronousAdd_metaData = {
    .transaction_handle = {
        .client_id = 4U,        //according to the configuration arxml
        .sequence_counter = 0U, //default value
        .communication_type = 3, //rte
        .Async_rteCall_returnValue = RTE_E_OK
    },
    .port = "Port1",
    .connected_unconnected = "connected",
    .in_exclusiveArea_or_not = "NotInExclusiveArea",
    .CanAccess = "Can",
    .sync_async = "Synchronous",
    .operation = "Add",
    .run_stop = "stop"
};

int Search_RteCallMetadata_RingBuffer(RingBuffer* rb, Rte_call_metaData* target){
    Rte_call_metaData* buffer = rb->buffer;
    for (size_t i = rb->head; i != rb->tail; i = (i + 1) % rb->maxSize){
        if(buffer[i].sync_async == "Asynchronous" && buffer[i].port == target->port && buffer[i].operation == target->operation){
            return 1;//found
        }
    }
    return 0;//not found
}

Impl_uint16 transformer_buffer[20];
RingBuffer transformer_RB= {
    transformer_buffer,
    0,//point to oldest data
    0,
    20,
    0
};


Std_ReturnType Rte_Call_Port1_IntraPartitionAsynchronousAdd(Impl_uint16 data_1, Impl_uint16 data_2){
    Std_ReturnType rte_error_code = RTE_E_OK;
    Impl_uint16 Enqueue_rte_call_RB = 0;//to check if the rte_call is enqueued
    if(Rte_Call_Port1_IntraPartitionAsynchronousAdd_metaData.connected_unconnected == "unconnected"){
        rte_error_code = RTE_E_UNCONNECTED;
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_IntraPartitionAsynchronousAdd_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error_code = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Search_RteCallMetadata_RingBuffer(&rte_call_record_RB, &Rte_Call_Port1_IntraPartitionAsynchronousAdd_metaData)){
            rte_error_code = RTE_E_LIMIT;
        }else{
            RTE_Enqueue(&rte_call_record_RB, &Rte_Call_Port1_IntraPartitionAsynchronousAdd_metaData, sizeof(Rte_call_metaData));
            Enqueue_rte_call_RB = 1;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_IntraPartitionAsynchronousAdd_metaData.CanAccess == "CanNot"){
            rte_error_code = RTE_E_SEG_FAULT;
        }
    }
    //intra-partition doesn't need transformer(used for inter-Ecu, inter-partition)
    if(rte_error_code == RTE_E_OK){
        RTE_Enqueue(&Rte_parameter_RB_rte, (void*)&data_1, sizeof(Impl_uint16));
        RTE_Enqueue(&Rte_parameter_RB_rte, (void*)&data_2, sizeof(Impl_uint16));
        Rte_Call_Port1_IntraPartitionAsynchronousAdd_metaData.transaction_handle.sequence_counter++;//means a rte_call is finished successfully
    }
    if(Enqueue_rte_call_RB == 1){
        RTE_Dequeue(&rte_call_record_RB, &Rte_Call_Port1_IntraPartitionAsynchronousAdd_metaData, sizeof(Rte_call_metaData));
    }
    //return value shall follow the priority rules
    return rte_error_code;
}

Std_ReturnType Rte_Call_Port1_IntraPartitionSynchronousAdd(Impl_uint16 data_1, Impl_uint16 data_2, Impl_uint16* response){
    SetRelAlarm(alarm3, 50, 0);
    Std_ReturnType rte_error_code = RTE_E_OK;
    Impl_uint16 Enqueue_rte_call_RB = 0;//to check if the rte_call is enqueued
    if(Rte_Call_Port1_IntraPartitionSynchronousAdd_metaData.connected_unconnected == "unconnected"){
        rte_error_code = RTE_E_UNCONNECTED;
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_IntraPartitionSynchronousAdd_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error_code = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Search_RteCallMetadata_RingBuffer(&rte_call_record_RB, &Rte_Call_Port1_IntraPartitionSynchronousAdd_metaData)){
            rte_error_code = RTE_E_LIMIT;
        }else{
            RTE_Enqueue(&rte_call_record_RB, &Rte_Call_Port1_IntraPartitionSynchronousAdd_metaData, sizeof(Rte_call_metaData));
            Enqueue_rte_call_RB = 1;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_IntraPartitionSynchronousAdd_metaData.CanAccess == "CanNot"){
            rte_error_code = RTE_E_SEG_FAULT;
        }
    }
    //intra-partition doesn't need transformer(used for inter-Ecu, inter-partition)
    if(rte_error_code == RTE_E_OK){
        RTE_Enqueue(&Rte_parameter_RB_rte, (void*)&data_1, sizeof(Impl_uint16));
        RTE_Enqueue(&Rte_parameter_RB_rte, (void*)&data_2, sizeof(Impl_uint16));
        
        //wait until server response is available
        WaitEvent(event1);
        if(errorFlag_Rte_Call_Port1_IntraPartitionSynchronousAdd != RTE_E_OK){
            rte_error_code = errorFlag_Rte_Call_Port1_IntraPartitionSynchronousAdd;
        }
    }
    if(rte_error_code == RTE_E_OK){
        RTE_Dequeue(&Rte_response_RB_rte, (void*)response, sizeof(Impl_uint16));
    }
    if(Enqueue_rte_call_RB == 1){
        RTE_Dequeue(&rte_call_record_RB, &Rte_Call_Port1_IntraPartitionSynchronousAdd_metaData, sizeof(Rte_call_metaData));
        Rte_Call_Port1_IntraPartitionSynchronousAdd_metaData.transaction_handle.sequence_counter++;//means a rte_call is finished successfully
    }
    //return value shall follow the priority rules
    return rte_error_code;
}

Std_ReturnType Rte_Client_Runnable_1(){
    //for developer to design the implementation
    Impl_uint16 data_1 = 4U;
    Impl_uint16 data_2 = 6U;
    Impl_uint16 response = 0U;
    Std_ReturnType rte_error_code = Rte_Call_Port1_IntraPartitionAsynchronousAdd(data_1, data_2);
    return rte_error_code;//check return value in test code. can be removed in real situation.(void Rte_Client_Runnable())
}