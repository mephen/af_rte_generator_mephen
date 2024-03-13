//VFB interface(api) & Runnable Implementation
//----------------------------------------------------------------
#define RTE_CLIENT_RUNNABLE_1_C
#include "Rte_Client_Runnable.h"
#include "../ringbuffer.h"
#include "../../kernel/alarm.h"
#include "../../kernel/Ioc.h"
#include "../../kernel/event.h"

//for RTE to ensure the order of server responses on the client side
//shared by all the client response runnables
//Rte_Client_Runnable_1.c have to execute first, or other response runnables can't use Rte_response_RB_com
Impl_uint16 Rte_response_buffer_com[20];
RingBuffer Rte_response_RB_com = {
    Rte_response_buffer_com,
    0,
    0,
    20,
    0
};

//outside flag in OsTask body which can help sync Rte_call to check error type.
Std_ReturnType errorFlag_Rte_Call_Port1_InterEcuSynchronousAdd = RTE_E_OK;

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

Rte_call_metaData Rte_Call_Port1_InterEcuAsynchronousAdd_metaData = {
    .transaction_handle = {
        .client_id = 1U,        //according to the configuration arxml
        .sequence_counter = 0U, //default value
        .communication_type = 1, //com
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

Rte_call_metaData Rte_Call_Port1_InterEcuSynchronousAdd_metaData = {
    .transaction_handle = {
        .client_id = 2U,        //according to the configuration arxml
        .sequence_counter = 0U, //default value
        .communication_type = 1, //com
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

uint8 transformer_buffer_com[20];
RingBuffer transformer_RB_com = {
    transformer_buffer_com,
    0,//point to oldest data
    0,
    20,
    0
};

/*[SWS_Xfrm_00038]*/
uint8 Xfrm_transformer_com(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, Impl_uint16 data_1, Impl_uint16 data_2){
    signal signal_1 = (signal)data_1;
    signal signal_2 = (signal)data_2;
    RTE_Enqueue(buffer, (void*)&signal_1, sizeof(signal));
    RTE_Enqueue(buffer, (void*)&signal_2, sizeof(signal));
    return E_OK;
}
/*[SWS_Xfrm_00044]*/
uint8 Xfrm_Inv_transformer_com(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, signal signal_1){
    Impl_uint16 data_1 = (Impl_uint16)signal_1;
    RTE_Enqueue(buffer, (void*)&data_1, sizeof(Impl_uint16));
    return E_OK;
}
uint8 Xfrm_transformer_2_com(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, Impl_uint16 data_1){
    signal signal_1 = (signal)data_1;
    RTE_Enqueue(buffer, (void*)&signal_1, sizeof(signal));
    return E_OK;
}
uint8 Xfrm_Inv_transformer_2_com(const Rte_Cs_TransactionHandleType* TransactionHandle, RingBuffer* buffer, uint32* bufferLength, signal signal_1){
    Impl_uint16 data_1 = (Impl_uint16)signal_1;
    RTE_Enqueue(buffer, (void*)&data_1, sizeof(Impl_uint16));
    return E_OK;
}

uint8 Com_SendSignal(Com_SignalIdType signalId, const void* signalDataPtr){
    return E_OK;
}

uint8 Com_ReceiveSignal(Com_SignalIdType signalId, void* signalDataPtr){
    return E_OK;
}

Std_ReturnType Rte_Call_Port1_InterEcuAsynchronousAdd(Impl_uint16 data_1, Impl_uint16 data_2){
    Std_ReturnType rte_error_code = RTE_E_OK;
    Impl_uint16 Enqueue_rte_call_RB = 0;//to check if the rte_call is enqueued
    if(Rte_Call_Port1_InterEcuAsynchronousAdd_metaData.connected_unconnected == "unconnected"){
        rte_error_code = RTE_E_UNCONNECTED;
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_InterEcuAsynchronousAdd_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error_code = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Search_RteCallMetadata_RingBuffer(&rte_call_record_RB, &Rte_Call_Port1_InterEcuAsynchronousAdd_metaData)){
            rte_error_code = RTE_E_LIMIT;
        }else{
            RTE_Enqueue(&rte_call_record_RB, &Rte_Call_Port1_InterEcuAsynchronousAdd_metaData, sizeof(Rte_call_metaData));
            Enqueue_rte_call_RB = 1;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_InterEcuAsynchronousAdd_metaData.CanAccess == "CanNot"){
            rte_error_code = RTE_E_SEG_FAULT;
        }
    }
    if(rte_error_code == RTE_E_OK){
        //The RTE is not able to allocate the buffer needed to transform the data
        if(IsFull(&transformer_RB_com)){
            rte_error_code = RTE_E_TRANSFORMER_LIMIT;
        }
    }
    if(rte_error_code == RTE_E_OK){
        uint8 transformer_error_code = Xfrm_transformer_com(&Rte_Call_Port1_InterEcuAsynchronousAdd_metaData.transaction_handle, &transformer_RB_com, &transformer_RB_com.currentSize, data_1, data_2);
        if(transformer_error_code >= 0x01 && transformer_error_code <= 0x7F){
            //soft transformer error won't cause immediate return
            rte_error_code = RTE_E_SOFT_TRANSFORMER_ERROR;
        }else if(transformer_error_code >= 0x80 && transformer_error_code <= 0xFF){
            rte_error_code = RTE_E_HARD_TRANSFORMER_ERROR;
        }
    }
    if(rte_error_code == RTE_E_OK || rte_error_code == RTE_E_SOFT_TRANSFORMER_ERROR){
        signal signal_1;
        RTE_Dequeue(&transformer_RB_com, (void*)&signal_1, sizeof(signal));
        uint8 com_error_code = Com_SendSignal(1U, &signal_1);
        if(com_error_code == COM_SERVICE_NOT_AVAILABLE){
            rte_error_code = RTE_E_COM_STOPPED;
        }else if(com_error_code == COM_BUSY){
            rte_error_code = RTE_E_COM_BUSY;
        }
    }
    if(rte_error_code == RTE_E_OK || rte_error_code == RTE_E_SOFT_TRANSFORMER_ERROR){
        signal signal_2;
        RTE_Dequeue(&transformer_RB_com, (void*)&signal_2, sizeof(signal));
        uint8 com_error_code = Com_SendSignal(2U, &signal_2);
        if(com_error_code == COM_SERVICE_NOT_AVAILABLE){
            rte_error_code = RTE_E_COM_STOPPED;
        }else if(com_error_code == COM_BUSY){
            rte_error_code = RTE_E_COM_BUSY;
        }
    }
    if(Enqueue_rte_call_RB == 1){
        RTE_Dequeue(&rte_call_record_RB, &Rte_Call_Port1_InterEcuAsynchronousAdd_metaData, sizeof(Rte_call_metaData));
    }
    //return value shall follow the priority rules
    return rte_error_code;
}

Std_ReturnType Rte_Call_Port1_InterEcuSynchronousAdd(Impl_uint16 data_1, Impl_uint16 data_2, Impl_uint16* response){
    SetRelAlarm(alarm3, 50, 0);
    Std_ReturnType rte_error_code = RTE_E_OK;
    Impl_uint16 Enqueue_rte_call_RB = 0;//to check if the rte_call is enqueued
    if(Rte_Call_Port1_InterEcuSynchronousAdd_metaData.connected_unconnected == "unconnected"){
        rte_error_code = RTE_E_UNCONNECTED;
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_InterEcuSynchronousAdd_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error_code = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Search_RteCallMetadata_RingBuffer(&rte_call_record_RB, &Rte_Call_Port1_InterEcuSynchronousAdd_metaData)){
            rte_error_code = RTE_E_LIMIT;
        }else{
            RTE_Enqueue(&rte_call_record_RB, &Rte_Call_Port1_InterEcuSynchronousAdd_metaData, sizeof(Rte_call_metaData));
            Enqueue_rte_call_RB = 1;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Call_Port1_InterEcuSynchronousAdd_metaData.CanAccess == "CanNot"){
            rte_error_code = RTE_E_SEG_FAULT;
        }
    }
    if(rte_error_code == RTE_E_OK){
        //The RTE is not able to allocate the buffer needed to transform the data
        if(IsFull(&transformer_RB_com)){
            rte_error_code = RTE_E_TRANSFORMER_LIMIT;
        }
    }
    if(rte_error_code == RTE_E_OK){
        uint8 transformer_error_code = Xfrm_transformer_com(&Rte_Call_Port1_InterEcuSynchronousAdd_metaData.transaction_handle, &transformer_RB_com, &transformer_RB_com.currentSize, data_1, data_2);
        if(transformer_error_code >= 0x01 && transformer_error_code <= 0x7F){
            //soft transformer error won't cause immediate return
            rte_error_code = RTE_E_SOFT_TRANSFORMER_ERROR;
        }else if(transformer_error_code >= 0x80 && transformer_error_code <= 0xFF){
            rte_error_code = RTE_E_HARD_TRANSFORMER_ERROR;
        }
    }
    if(rte_error_code == RTE_E_OK || rte_error_code == RTE_E_SOFT_TRANSFORMER_ERROR){
        signal signal_1;
        RTE_Dequeue(&transformer_RB_com, (void*)&signal_1, sizeof(signal));
        uint8 com_error_code = Com_SendSignal(1U, &signal_1);
        if(com_error_code == COM_SERVICE_NOT_AVAILABLE){
            rte_error_code = RTE_E_COM_STOPPED;
        }else if(com_error_code == COM_BUSY){
            rte_error_code = RTE_E_COM_BUSY;
        }
    }
    if(rte_error_code == RTE_E_OK || rte_error_code == RTE_E_SOFT_TRANSFORMER_ERROR){
        signal signal_2;
        RTE_Dequeue(&transformer_RB_com, (void*)&signal_2, sizeof(signal));
        uint8 com_error_code = Com_SendSignal(2U, &signal_2);
        if(com_error_code == COM_SERVICE_NOT_AVAILABLE){
            rte_error_code = RTE_E_COM_STOPPED;
        }else if(com_error_code == COM_BUSY){
            rte_error_code = RTE_E_COM_BUSY;
        }
    }
    if(rte_error_code == RTE_E_OK || rte_error_code == RTE_E_SOFT_TRANSFORMER_ERROR){
        WaitEvent(event1);
        if(errorFlag_Rte_Call_Port1_InterEcuSynchronousAdd != RTE_E_OK){
            rte_error_code = errorFlag_Rte_Call_Port1_InterEcuSynchronousAdd;
        }
    }
    if(rte_error_code == RTE_E_OK || rte_error_code == RTE_E_SOFT_TRANSFORMER_ERROR){
        RTE_Dequeue(&Rte_response_RB_com, (void*)response, sizeof(Impl_uint16));
    }
    if(Enqueue_rte_call_RB == 1){
        RTE_Dequeue(&rte_call_record_RB, &Rte_Call_Port1_InterEcuSynchronousAdd_metaData, sizeof(Rte_call_metaData));
    }
    return rte_error_code;
}

Impl_uint16 Rte_Client_Runnable_1(){
    //for developer to design the implementation
    Impl_uint16 data_1 = 4U;
    Impl_uint16 data_2 = 6U;
    Impl_uint16 response = 0U;
    Std_ReturnType rte_error_code = Rte_Call_Port1_InterEcuSynchronousAdd(data_1, data_2, &response);
    return response;
}