#include "Rte_Event_Cfg.h"

Request_type request_q[10];
ResponseInfoType response_q[10];
 

void ioc_server_side_multiply();
extern Rte_client_server_type rte_client_server;

T11{//ioc server side: 接收和處理 request info，發送response
    while(rte_event[OperationInvokedEvent_3]){//use while instead of if. Because inter-partition communication is multi-core, so there may be multiple requests coming when the server is processing the request.
        GetLock(lock, lock_bit);
        rte_event[OperationInvokedEvent_3]--;
        ReleaseLock(lock, lock_bit);
        
        ioc_server_side_multiply();//check error, call transformer, enqueue request queue, do operation, send response

        //因為執行 server runnable 後還需要調用 transformer 進行資料轉換，所以無法把 server-side 的 Rte event 存取包到 server runnable 內部調用的 api 裡面。
        GetLock(lock, lock_bit);
        rte_event[AsynchronousServerCallReturnsEvent_3]++;
        ReleaseLock(lock, lock_bit);
        ActivateTask(T03); 
    }
}

uint16 ioc_server_side_multiply(){
    uint16 para1, para2, transformed_para_1, transformed_para_2, transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;
    Std_ReturnType bsw_error = RTE_E_OK;
    
    //get request information (parameters & sequence_counter).
    IocReceive_Q1(&para1);
    IocReceive_Q1(&para2);
    IocReceive_Q1(&transaction_handle.client_id);
    IocReceive_Q1(&transaction_handle.sequence_counter);
    
    //transforme data into DataType for server_operation
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    uint8 transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, para1);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, (void*)&transformed_para_1, sizeof(uint16));

    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, para2);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, (void*)&transformed_para_2, sizeof(uint16));
    
    RTE_Enqueue(&RB_request_SR3, &transformed_para_1, sizeof(uint16));//在 server side enqueue request queue
    RTE_Enqueue(&RB_request_SR3, &transformed_para_2, sizeof(uint16));
    Impl_uint16 response = RTE_RUNNABLE_Server3();//do "multiply" operation, multiply operation 會自己去 request_queue 裡面拿參數。
    
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

