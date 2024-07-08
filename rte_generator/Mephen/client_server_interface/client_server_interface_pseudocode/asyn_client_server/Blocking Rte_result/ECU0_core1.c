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

void ioc_server_side_multiply(){
    ReuqestInfoType request_info;
    ioc_receive_aa(&request_info);//拿出 parameters & transaction_handle.sequence_counter
    
    Check_transformer_buffer();
    error = transformer(&transformed_para_1, request_info.parameters[0]);
    Check_transformer_error(error);
    
    Check_transformer_buffer();
    error = transformer(&transformed_para_2, request_info.parameters[0]);
    Check_transformer_error(error);
    
    RTE_Enqueue( request_q, &transformed_para_1, sizeof(transformed_para_1));//在 server side enqueue request queue
    RTE_Enqueue( request_q, &transformed_para_2, sizeof(transformed_para_2));
    Impl_uint16 response = RTE_RUNNABLE_Server3();//do "multiply" operation, add operation 會自己去 request_queue 裡面拿參數。
    
    Check_transformer_buffer();
    error = transformer(&transformed_response, response);
    Check_transformer_error(error);

    ResponseInfoType response_info = {
        request_info.transaction_handle,
        transformed_response
    };

    ioc_send_bb(response_info);

    return;
}

