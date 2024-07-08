//VFB interface(api) & Runnable Implementation
//----------------------------------------------------------------
#define RTE_Client_Response_2_C
#include "Rte_SWC_Client.h"
#include "../ringbuffer.h"
#include "../Transformer_stub.h"
#include "../Rte_Cs_Data_Management.h"
#include "../Rte_Event_Cfg.h"
#include "../../kernel/alarm.h"
#include "../../kernel/event.h"
#include "../../device/lock.h"
#include "../../OS_Configure/inc/event_Cfg.h"
#include "../../kernel/task.h"

//SWS_Rte_02528
ResponseInfoType response_buffer_Client_Response_2[1];
RingBuffer RB_response_Client_Response_2 = {
    response_buffer_Client_Response_2,
    0,
    0,
    1,
    0
};
RteResultMetaData Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2_metaData = {
    .transaction_handle = {
        .client_id = 2U,        //same as corresponding CR
        .sequence_counter = 0U, //record how many c/s communication has been "finished".
    },
    "connected",
    "NotInExclusiveArea",
    "Can"
};
//difference between blocking & non-blocking rte_result are only
//1. wait/set event at the beginning
//2. metaData
Std_ReturnType Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2(Impl_uint16* response){
    SetRelAlarm(alarm3, 50, 0);
    Std_ReturnType rte_error = RTE_E_OK;
    if(Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2_metaData.connected_unconnected == "unconnected"){
        rte_error = RTE_E_UNCONNECTED;
    }
    if(rte_error == RTE_E_OK){
        if(Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error == RTE_E_OK){
        if(Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2_metaData.CanAccess == "CanNot"){
            rte_error = RTE_E_SEG_FAULT;
        }
    }
    if(rte_error == RTE_E_OK){
        //get server response from response queue
        ResponseInfoType server_response;
        RTE_Dequeue(&RB_response_Client_Response_2, &server_response, sizeof(ResponseInfoType));
        rte_error = server_response.bsw_error;

        //check if there is outdated response, or timeout occur.
        if(rte_error == RTE_E_TIMEOUT){//timeout
            Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2_metaData.transaction_handle.sequence_counter++; //means that x-th Rte_call will be finished (x = sequence_counter)
        }else if(Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2_metaData.transaction_handle.sequence_counter > server_response.transaction_handle.sequence_counter){//outdated server_response, and discard it.
            rte_error = RTE_E_TIMEOUT; 
        }else if(Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2_metaData.transaction_handle.sequence_counter == server_response.transaction_handle.sequence_counter){//not outdated, and not timeout
            Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2_metaData.transaction_handle.sequence_counter++; 

            //check previous Rte_call return value
            Std_ReturnType rte_call_returnValue;
            RTE_Dequeue(&RB_returnValue_Client_2, &rte_call_returnValue, sizeof(Std_ReturnType));
            if(rte_call_returnValue == RTE_E_SEG_FAULT || rte_call_returnValue == RTE_E_TRANSFORMER_LIMIT || rte_call_returnValue == RTE_E_HARD_TRANSFORMER_ERROR){
                rte_error = RTE_E_NO_DATA;
            }else{//correct response
                *response = server_response.response;
            }
        }
    }
    request_number_Client_2 = 0;//Client_2 request is finished
    return rte_error; //return value will follow the priority rule
}
Impl_uint16 RTE_RUNNABLE_Client_Response_2(){ //Impl_uint16 is for testing
    //for developer to design the implementation
    Impl_uint16 response = 0;
//    Std_ReturnType rte_error = Rte_Result_SWC_Client_Rport1_Blocking_Client_Response_2(&response);
//    Std_ReturnType rte_error = Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2(&response);
    return response;
}