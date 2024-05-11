//---------------------------------------------------------------------------------------------------------------
//App1.c
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "counter.h"
#include "alarm.h"
#include "task.h"
#include "isr2.h"
#include "event.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "string_format_test.h"
#include "systemcall.h"
#include "application.h"
#include "ISRInit.h"
#include "isr_Cfg.h"
#include "spinlock.h"
#include "resource.h"
#include "memsection.h"
#include "trustedFunc_Cfg.h"
#include "ioc.h"
#include "lock.h"
#include "Rte_Event_Cfg.h"
#include "Transformer_stub.h"
#include "Rte_Cs_Data_Management.h"
#include "SWC_Client/Rte_SWC_Client.h"
#include "SWC_Server_1/Rte_SWC_Server_1.h"
#include "SWC_Server_2/Rte_SWC_Server_2.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

uint8 lock = 0;
uint8 lock_bit = 1;

void *(*SR_array[2])() = {RTE_Server1_SR1, RTE_Server2_SR1};
RingBuffer* RB_request_ptr_arr[2] = {RB_request_Server1_SR1, RB_request_Server2_SR1};

uint16 rte_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;

    //get request information (parameters & sequence_counter).
    RTE_Dequeue(&RB_requestInfo_core0, &len_args, sizeof(uint16));
    uint16 para_arr[len_args];
    uint16 transformed_para_arr[len_args];
    for(int i = 0; i < len_args; i++){
        RTE_Dequeue(&RB_requestInfo_core0, &para_arr[i], sizeof(Impl_uint16));
    }
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.client_id, sizeof(uint16));
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.sequence_counter, sizeof(uint16));

    //transforme data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_arr[i], sizeof(uint16));

        //enqueue request queue on server side
        for(int j = 0; j < sizeof(RB_request_ptr_arr)/sizeof(RingBuffer*); j++){
            if(Server_Runnable == (uint16 (*)())SR_array[j]){
                RTE_Enqueue(RB_request_ptr_arr[j], &transformed_para_arr[i], sizeof(uint16));
                break;
            }
        }
    }

    ImplementationDataType(/CS_Composition/Datatypes/ImplementationDataTypes/Impl_uint16) response = Server_Runnable(); //do server operation, server runnable will get paras in its own request_queue
    
    //transforme data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType response_info = {
        RTE_E_OK,
        transaction_handle,
        transformed_response
    };
    RTE_Enqueue(&RB_responseInfo_core0, &response_info, sizeof(ResponseInfoType));//via rte_internal_buffer, store response information (response & sequence_counter)
    return transaction_handle.client_id;
}

ResponseInfoType rte_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    RTE_Dequeue(&RB_responseInfo_core0, &response_info, sizeof(ResponseInfoType));

    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}

uint16 ioc_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;
    Std_ReturnType bsw_error = RTE_E_OK;

    //get request information (parameters & sequence_counter).
    IocReceive_Q1(&len_args);
    uint16 para_arr[len_args];
    uint16 transformed_para_arr[len_args];
    for(int i = 0; i < len_args; i++){
        IocReceive_Q1(&para_arr[i]);
    }
    IocReceive_Q1(&transaction_handle.client_id);
    IocReceive_Q1(&transaction_handle.sequence_counter);

    //transforme data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_arr[i], sizeof(uint16));

        //enqueue request queue on server side 
        for(int j = 0; j < sizeof(RB_request_ptr_arr)/sizeof(RingBuffer*); j++){
            if(Server_Runnable == (uint16 (*)())SR_array[j]){
                RTE_Enqueue(RB_request_ptr_arr[j], &transformed_para_arr[i], sizeof(uint16));
                break;
            }
        }
    }

    Impl_uint16 response = Server_Runnable(); //do "multiply" operation, SR will get paras in its own request_queue

    //transforme data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    //send response information (response & sequence_counter).
    IocSend_Q1_SND1(transaction_handle.client_id);//for server_response.transaction_handle.client_id
    IocSend_Q1_SND1(transaction_handle.sequence_counter);//for server_response.transaction_handle.sequence_counter
    IocSend_Q1_SND1(transformed_response);//for server_response.response
    return transaction_handle.client_id;
}

ResponseInfoType ioc_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    IocReceive_Q1(&response_info.transaction_handle.client_id);
    IocReceive_Q1(&response_info.transaction_handle.sequence_counter);
    IocReceive_Q1(&response_info.response);
    
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}
//---------------------------------------------------------------------------------------------------------------
//App2.c
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "counter.h"
#include "alarm.h"
#include "task.h"
#include "isr2.h"
#include "event.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "string_format_test.h"
#include "systemcall.h"
#include "application.h"
#include "ISRInit.h"
#include "isr_Cfg.h"
#include "spinlock.h"
#include "resource.h"
#include "memsection.h"
#include "trustedFunc_Cfg.h"
#include "ioc.h"
#include "lock.h"
#include "Rte_Event_Cfg.h"
#include "Transformer_stub.h"
#include "Rte_Cs_Data_Management.h"
#include "SWC_Client/Rte_SWC_Client.h"
#include "SWC_Server_1/Rte_SWC_Server_1.h"
#include "SWC_Server_2/Rte_SWC_Server_2.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

uint8 lock = 0;
uint8 lock_bit = 1;

void *(*SR_array[2])() = {RTE_Server1_SR1, RTE_Server2_SR1};
RingBuffer* RB_request_ptr_arr[2] = {RB_request_Server1_SR1, RB_request_Server2_SR1};

uint16 rte_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;

    //get request information (parameters & sequence_counter).
    RTE_Dequeue(&RB_requestInfo_core1, &len_args, sizeof(uint16));
    uint16 para_arr[len_args];
    uint16 transformed_para_arr[len_args];
    for(int i = 0; i < len_args; i++){
        RTE_Dequeue(&RB_requestInfo_core1, &para_arr[i], sizeof(Impl_uint16));
    }
    RTE_Dequeue(&RB_requestInfo_core1, &transaction_handle.client_id, sizeof(uint16));
    RTE_Dequeue(&RB_requestInfo_core1, &transaction_handle.sequence_counter, sizeof(uint16));

    //transforme data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core1, (void*)&transformed_para_arr[i], sizeof(uint16));

        //enqueue request queue on server side
        for(int j = 0; j < sizeof(RB_request_ptr_arr)/sizeof(RingBuffer*); j++){
            if(Server_Runnable == (uint16 (*)())SR_array[j]){
                RTE_Enqueue(RB_request_ptr_arr[j], &transformed_para_arr[i], sizeof(uint16));
                break;
            }
        }
    }

    ImplementationDataType(/CS_Composition/Datatypes/ImplementationDataTypes/Impl_uint16) response = Server_Runnable(); //do server operation, server runnable will get paras in its own request_queue
    
    //transforme data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    ResponseInfoType response_info = {
        RTE_E_OK,
        transaction_handle,
        transformed_response
    };
    RTE_Enqueue(&RB_responseInfo_core1, &response_info, sizeof(ResponseInfoType));//via rte_internal_buffer, store response information (response & sequence_counter)
    return transaction_handle.client_id;
}

ResponseInfoType rte_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    RTE_Dequeue(&RB_responseInfo_core1, &response_info, sizeof(ResponseInfoType));

    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}

uint16 ioc_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;
    Std_ReturnType bsw_error = RTE_E_OK;

    //get request information (parameters & sequence_counter).
    IocReceive_Q1(&len_args);
    uint16 para_arr[len_args];
    uint16 transformed_para_arr[len_args];
    for(int i = 0; i < len_args; i++){
        IocReceive_Q1(&para_arr[i]);
    }
    IocReceive_Q1(&transaction_handle.client_id);
    IocReceive_Q1(&transaction_handle.sequence_counter);

    //transforme data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core1, (void*)&transformed_para_arr[i], sizeof(uint16));

        //enqueue request queue on server side 
        for(int j = 0; j < sizeof(RB_request_ptr_arr)/sizeof(RingBuffer*); j++){
            if(Server_Runnable == (uint16 (*)())SR_array[j]){
                RTE_Enqueue(RB_request_ptr_arr[j], &transformed_para_arr[i], sizeof(uint16));
                break;
            }
        }
    }

    Impl_uint16 response = Server_Runnable(); //do "multiply" operation, SR will get paras in its own request_queue

    //transforme data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    //send response information (response & sequence_counter).
    IocSend_Q1_SND1(transaction_handle.client_id);//for server_response.transaction_handle.client_id
    IocSend_Q1_SND1(transaction_handle.sequence_counter);//for server_response.transaction_handle.sequence_counter
    IocSend_Q1_SND1(transformed_response);//for server_response.response
    return transaction_handle.client_id;
}

ResponseInfoType ioc_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    IocReceive_Q1(&response_info.transaction_handle.client_id);
    IocReceive_Q1(&response_info.transaction_handle.sequence_counter);
    IocReceive_Q1(&response_info.response);
    
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}