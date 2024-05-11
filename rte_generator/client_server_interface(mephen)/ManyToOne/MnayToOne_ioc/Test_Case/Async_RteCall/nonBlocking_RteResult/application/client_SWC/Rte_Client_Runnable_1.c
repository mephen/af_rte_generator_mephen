//VFB interface(api) & Runnable Implementation
//----------------------------------------------------------------
#define RTE_CLIENT_RUNNABLE_1_C
#include "Rte_Client_Runnable.h"
#include "../ringbuffer.h"
#include "../Transformer_stub.h"
#include "../Rte_Cs_Data_Management.h"
#include "../Rte_Event_Cfg.h"
#include "../../kernel/alarm.h"
#include "../../kernel/Ioc.h"
#include "../../kernel/event.h"
#include "../../device/lock.h"
#include "../../OS_Configure/inc/event_Cfg.h"

//SWS_Rte_02528
ResponseInfoType response_buffer_CR1[1];
RingBuffer RB_response_CR1 = {
    response_buffer_CR1,
    0,
    0,
    1,
    0
};

static RteCallMetaData Rte_Call_Port1_AsyncIocMultiply_CR1_metaData = {
    .transaction_handle = {
        .client_id = 1U,         
        .sequence_counter = 0U, //recore how many Rte_call has been "invoked" -> sequence_counter of rte_result record how many c/s communication has been "finished".
    },
    .connected_unconnected = "connected",
    .in_exclusiveArea_or_not = "NotInExclusiveArea",
    .CanAccess = "Can",
};

static RteCallMetaData Rte_Call_Port1_SyncIocMultiply_CR1_metaData = {
    .transaction_handle = {
        .client_id = 1U,         
        .sequence_counter = 0U, //record how many c/s communication has been "finished".
    },
    .connected_unconnected = "connected",
    .in_exclusiveArea_or_not = "NotInExclusiveArea",
    .CanAccess = "Can",
};

static uint8 lock = 0;
static uint8 lock_bit = 1;
static int running_asyncApi_number  = 0; //record the number of running async Rte_call
int request_number_CR1 = 0; //max: 1 (SWS_Rte_02658), shared by CRR1.

Std_ReturnType Rte_Call_Port1_SyncIocMultiply_CR1(Impl_uint16 para_1, Impl_uint16 para_2, Impl_uint16* response){
    if(request_number_CR1 == 0){//one client can only has one request at a time.
        request_number_CR1 = 1;
        //in sync rte_call, don't need to check RTE_ELIMIT
        SetRelAlarm(alarm3, 50, 0); //check timeout

        Std_ReturnType rte_error = RTE_E_OK;

        if(Rte_Call_Port1_SyncIocMultiply_CR1_metaData.connected_unconnected == "unconnected"){
            rte_error = RTE_E_UNCONNECTED;
        }
        if(rte_error == RTE_E_OK){
            if(Rte_Call_Port1_SyncIocMultiply_CR1_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
                rte_error = RTE_E_IN_EXCLUSIVE_AREA;
            }
        }
        if(rte_error == RTE_E_OK){
            if(Rte_Call_Port1_SyncIocMultiply_CR1_metaData.CanAccess == "CanNot"){
                rte_error = RTE_E_SEG_FAULT;
            }
        }
        //transform parameter1
        if(rte_error == RTE_E_OK){
            rte_error = Check_Transformer_Buffer(&RB_transformer_core0);
            uint8 transformer_error = Xfrm_transformer(&Rte_Call_Port1_SyncIocMultiply_CR1_metaData.transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_1);
            rte_error = Check_Transformer_Error(transformer_error, rte_error);
        }
        //transform parameter1
        if(rte_error == RTE_E_OK){
            rte_error = Check_Transformer_Buffer(&RB_transformer_core0);
            uint8 transformer_error = Xfrm_transformer(&Rte_Call_Port1_SyncIocMultiply_CR1_metaData.transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_2);
            rte_error = Check_Transformer_Error(transformer_error, rte_error);
        }
        //get transformed parameters & send to server side, and then wait for server_response
        if(rte_error == RTE_E_OK || rte_error == RTE_E_SOFT_TRANSFORMER_ERROR){
            //prefetch data from transformer buffer
            uint16 transformed_para_1;
            RTE_Dequeue(&RB_transformer_core0, &transformed_para_1, sizeof(uint16));
            uint16 transformed_para_2;
            RTE_Dequeue(&RB_transformer_core0, &transformed_para_2, sizeof(uint16));
            
            uint16 len_arg = 2; //parser will decide the value of len_arg
            IocSend_Q1_SND1(len_arg);
            IocSend_Q1_SND1(transformed_para_1);
            IocSend_Q1_SND1(transformed_para_2);
            IocSend_Q1_SND1(Rte_Call_Port1_SyncIocMultiply_CR1_metaData.transaction_handle.client_id);
            IocSend_Q1_SND1(Rte_Call_Port1_SyncIocMultiply_CR1_metaData.transaction_handle.sequence_counter);

            //trigger coreesponding OperationInvokedEvent
            GetLock(&lock, lock_bit);
            trigger_rteevent(rte_event_t11[OperationInvokedEvent_1_t11]);
            ReleaseLock(&lock, lock_bit);
            ActivateTask(T11);
            //wait until server response is available
            WaitEvent(event1);
            //reset SetEvent bit
            ClearEvent(event1);

            ResponseInfoType server_response;
            RTE_Dequeue(&RB_response_CR1, &server_response, sizeof(ResponseInfoType));
            rte_error = server_response.bsw_error;
            //check if there is outdated response, or timeout occur.
            if(rte_error == RTE_E_TIMEOUT){//timeout
                Rte_Call_Port1_SyncIocMultiply_CR1_metaData.transaction_handle.sequence_counter++; //means that x-th Rte_call will be finished (x = sequence_counter)
            }else if(Rte_Call_Port1_SyncIocMultiply_CR1_metaData.transaction_handle.sequence_counter > server_response.transaction_handle.sequence_counter){//outdated server_response, and discard it.
                rte_error = RTE_E_TIMEOUT; 
            }else if(Rte_Call_Port1_SyncIocMultiply_CR1_metaData.transaction_handle.sequence_counter == server_response.transaction_handle.sequence_counter){//correct response
                Rte_Call_Port1_SyncIocMultiply_CR1_metaData.transaction_handle.sequence_counter++;
                *response = server_response.response;
            }
        }
        request_number_CR1 = 0;//request finished
        //return value shall follow the priority rules
        return rte_error;
    }else{//wait for the previous request to be finished.
        return 2;//user defined error
    }
}

Std_ReturnType Rte_Call_Port1_AsyncIocMultiply_CR1(Impl_uint16 para_1, Impl_uint16 para_2){
    if(request_number_CR1 == 0){//one client can only has one request at a time.
        request_number_CR1 = 1;
        //in async rte_call, don't need to check timeout
        GetLock(&lock, lock_bit);
        running_asyncApi_number++;
        ReleaseLock(&lock, lock_bit);

        Std_ReturnType rte_error = RTE_E_OK;

        if(Rte_Call_Port1_AsyncIocMultiply_CR1_metaData.connected_unconnected == "unconnected"){
            rte_error = RTE_E_UNCONNECTED;
        }
        if(rte_error == RTE_E_OK){
            if(Rte_Call_Port1_AsyncIocMultiply_CR1_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
                rte_error = RTE_E_IN_EXCLUSIVE_AREA;
            }
        }
        if(rte_error == RTE_E_OK){
            if (running_asyncApi_number > 1) { 
                rte_error = RTE_E_LIMIT;
            }
        }
        if(rte_error == RTE_E_OK){
            if(Rte_Call_Port1_AsyncIocMultiply_CR1_metaData.CanAccess == "CanNot"){
                rte_error = RTE_E_SEG_FAULT;
            }
        }
        //transform parameter1
        if(rte_error == RTE_E_OK){
            rte_error = Check_Transformer_Buffer(&RB_transformer_core0);
            uint8 transformer_error = Xfrm_transformer(&Rte_Call_Port1_AsyncIocMultiply_CR1_metaData.transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_1);
            rte_error = Check_Transformer_Error(transformer_error, rte_error);
        }
        //transform parameter1
        if(rte_error == RTE_E_OK){
            rte_error = Check_Transformer_Buffer(&RB_transformer_core0);
            uint8 transformer_error = Xfrm_transformer(&Rte_Call_Port1_AsyncIocMultiply_CR1_metaData.transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_2);
            rte_error = Check_Transformer_Error(transformer_error, rte_error);
        }
        //get transformed parameters & send to server side
        if(rte_error == RTE_E_OK || rte_error == RTE_E_SOFT_TRANSFORMER_ERROR){
            uint16 transformed_para_1;
            RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_1, sizeof(uint16));
            uint16 transformed_para_2;
            RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_2, sizeof(uint16));

            uint16 len_arg = 2; //parser will decide the value of len_arg
            IocSend_Q1_SND1(len_arg);
            IocSend_Q1_SND1(transformed_para_1);
            IocSend_Q1_SND1(transformed_para_2);
            IocSend_Q1_SND1(Rte_Call_Port1_AsyncIocMultiply_CR1_metaData.transaction_handle.client_id);
            IocSend_Q1_SND1(Rte_Call_Port1_AsyncIocMultiply_CR1_metaData.transaction_handle.sequence_counter);
            Rte_Call_Port1_AsyncIocMultiply_CR1_metaData.transaction_handle.sequence_counter++; //means that x-th Rte_call is finished (x = sequence_counter)
        }
        //send return_value to coreesponding Rte_result
        RTE_Enqueue(&RB_returnValue_CR1, &rte_error, sizeof(Std_ReturnType));

        GetLock(&lock, lock_bit);
        running_asyncApi_number--;
        ReleaseLock(&lock, lock_bit);

        //trigger coreesponding OperationInvokedEvent
        GetLock(&lock, lock_bit);
        trigger_rteevent(rte_event_t11[OperationInvokedEvent_1_t11]);
        ReleaseLock(&lock, lock_bit);
        ActivateTask(T11);

        //return value follow the priority rules of RTE spec.
        return rte_error;
    }else{//wait for the previous request to be finished.
        return 2;//user defined error
    }
}

Impl_uint16 RTE_RUNNABLE_Client1(){
    //for developer to design the implementation
    Impl_uint16 data_1 = 3U;
    Impl_uint16 data_2 = 5U;
    Impl_uint16 response;
    Std_ReturnType rte_error = Rte_Call_Port1_AsyncIocMultiply_CR1(data_1, data_2);
    return response;
}