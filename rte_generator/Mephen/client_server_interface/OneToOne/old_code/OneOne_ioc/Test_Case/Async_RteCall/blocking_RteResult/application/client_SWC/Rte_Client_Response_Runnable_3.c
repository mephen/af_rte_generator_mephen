#define RTE_CLIENT_RESPONSERUNNABLE_3_C
#include "Rte_Client_Response_Runnable.h"
#include "../ringbuffer.h"
#include "../../kernel/alarm.h"
#include "../../kernel/event.h"
#include "../../OS_Configure/inc/event_Cfg.h"
#include "../../kernel/task.h"

//SWS_Rte_02528
ResponseInfoType response_buffer_CRR3[1];
RingBuffer RB_response_CRR3 = {
    response_buffer_CRR3,
    0,
    0,
    1,
    0
};

RteResultMetaData Rte_Result_Port1_AsyncIocMultiply_NonBlocking_metaData = {
    .transaction_handle = {
        .client_id = 3U,        //runnable ID, according to the configuration arxml
        .sequence_counter = 0U, //record how many c/s communication has been "finished".
    },
    "connected",
    "NotInExclusiveArea",
    "Can"
};
RteResultMetaData Rte_Result_Port1_AsyncIocMultiply_Blocking_metaData = {
    .transaction_handle = {
        .client_id = 3U,        //runnable ID, according to the configuration arxml
        .sequence_counter = 0U, //record how many c/s communication has been "finished".
    },
    "connected",
    "NotInExclusiveArea",
    "Can"
};

Std_ReturnType Rte_Result_Port1_AsyncIocMultiply_NonBlocking(Impl_uint16* response){
    SetRelAlarm(alarm3, 50, 0);
    Std_ReturnType rte_error = RTE_E_OK;
    if(Rte_Result_Port1_AsyncIocMultiply_NonBlocking_metaData.connected_unconnected == "unconnected"){
        rte_error = RTE_E_UNCONNECTED;
    }
    if(rte_error == RTE_E_OK){
        if(Rte_Result_Port1_AsyncIocMultiply_NonBlocking_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error == RTE_E_OK){
        if(Rte_Result_Port1_AsyncIocMultiply_NonBlocking_metaData.CanAccess == "CanNot"){
            rte_error = RTE_E_SEG_FAULT;
        }
    }
    if(rte_error == RTE_E_OK){
        //get server response from response queue
        ResponseInfoType server_response;
        RTE_Dequeue(&RB_response_CRR3, &server_response, sizeof(ResponseInfoType));
        rte_error = server_response.bsw_error;

        //check if there is outdated response, or timeout occur.
        if(rte_error == RTE_E_TIMEOUT){//timeout
            Rte_Result_Port1_AsyncIocMultiply_NonBlocking_metaData.transaction_handle.sequence_counter++; //means that x-th Rte_call will be finished (x = sequence_counter)
        }else if(Rte_Result_Port1_AsyncIocMultiply_NonBlocking_metaData.transaction_handle.sequence_counter > server_response.transaction_handle.sequence_counter){//outdated server_response, and discard it.
            rte_error = RTE_E_TIMEOUT; 
        }else if(Rte_Result_Port1_AsyncIocMultiply_NonBlocking_metaData.transaction_handle.sequence_counter == server_response.transaction_handle.sequence_counter){//not outdated, and not timeout
            Rte_Result_Port1_AsyncIocMultiply_NonBlocking_metaData.transaction_handle.sequence_counter++; 

            //check previous Rte_call return value
            Std_ReturnType rte_call_returnValue;
            RTE_Dequeue(&RB_returnValue_CR3, &rte_call_returnValue, sizeof(Std_ReturnType));
            if(rte_call_returnValue == RTE_E_SEG_FAULT || rte_call_returnValue == RTE_E_TRANSFORMER_LIMIT || rte_call_returnValue == RTE_E_HARD_TRANSFORMER_ERROR){
                rte_error = RTE_E_NO_DATA;
            }else{//correct response
                *response = server_response.response;
            }
        }
    }
    request_number_CR3 = 0;//CR3 request is finished
    //return value will follow the priority rule
    return rte_error;
}

Std_ReturnType Rte_Result_Port1_AsyncIocMultiply_Blocking(Impl_uint16* response){
    WaitEvent(event3); //wait for AsynchronousServerCallReturnsEvent
    //reset SetEvent bit
    ClearEvent(event3);
    SetRelAlarm(alarm3, 50, 0);
    Std_ReturnType rte_error = RTE_E_OK;
    if(Rte_Result_Port1_AsyncIocMultiply_Blocking_metaData.connected_unconnected == "unconnected"){
        rte_error = RTE_E_UNCONNECTED;
    }
    if(rte_error == RTE_E_OK){
        if(Rte_Result_Port1_AsyncIocMultiply_Blocking_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error == RTE_E_OK){
        if(Rte_Result_Port1_AsyncIocMultiply_Blocking_metaData.CanAccess == "CanNot"){
            rte_error = RTE_E_SEG_FAULT;
        }
    }
    if(rte_error == RTE_E_OK){
        //get server response from response queue
        ResponseInfoType server_response;
        RTE_Dequeue(&RB_response_CRR3, &server_response, sizeof(ResponseInfoType));
        rte_error = server_response.bsw_error;

        //check if there is outdated response, or timeout occur.
        if(rte_error == RTE_E_TIMEOUT){//timeout
            Rte_Result_Port1_AsyncIocMultiply_Blocking_metaData.transaction_handle.sequence_counter++; //means that x-th Rte_call will be finished (x = sequence_counter)
        }else if(Rte_Result_Port1_AsyncIocMultiply_Blocking_metaData.transaction_handle.sequence_counter > server_response.transaction_handle.sequence_counter){//outdated server_response, and discard it.
            rte_error = RTE_E_TIMEOUT; 
        }else if(Rte_Result_Port1_AsyncIocMultiply_Blocking_metaData.transaction_handle.sequence_counter == server_response.transaction_handle.sequence_counter){//not outdated, and not timeout
            Rte_Result_Port1_AsyncIocMultiply_Blocking_metaData.transaction_handle.sequence_counter++; 
            
            //check previous Rte_call return value
            Std_ReturnType rte_call_returnValue;
            RTE_Dequeue(&RB_returnValue_CR3, &rte_call_returnValue, sizeof(Std_ReturnType));
            if(rte_call_returnValue == RTE_E_SEG_FAULT || rte_call_returnValue == RTE_E_TRANSFORMER_LIMIT || rte_call_returnValue == RTE_E_HARD_TRANSFORMER_ERROR){
                rte_error = RTE_E_NO_DATA;
            }else{//correct response
                *response = server_response.response;
            }
        }
    }
    request_number_CR3 = 0;//CR3 request is finished
    return rte_error;
}

Impl_uint16 RTE_RUNNABLE_ClientResponse3(){
    //for developer to design the implementation
    Impl_uint16 response = 0;
    Std_ReturnType rte_error = Rte_Result_Port1_AsyncIocMultiply_Blocking(&response);
    return response;
}
