#include "Rte_Event_Cfg.h"

Request_type request_q[10];
ResponseInfoType response_q[10];
 

void com_server_side_divide();
void com_server_side_mod();

void rte_callback(){
    signal OperationInvokedEvent_id = -1;
    com_receiveSignal(signal_1, &OperationInvokedEvent_id);
    switch(OperationInvokedEvent_id){
        case 4:
            GetLock(lock, lock_bit);
            rte_event[OperationInvokedEvent_4]++;
            ReleaseLock(lock, lock_bit);
            break;
        case 5:
            GetLock(lock, lock_bit);
            rte_event[OperationInvokedEvent_5]++;
            ReleaseLock(lock, lock_bit);
            break;
    }
    activateTask(T01);  
    return;
}

isr{//com 收到資料後，觸發 isr
    rte_callback();
}

T01{//com server side: 接收request，處理request，發送response
    while(rte_event[OperationInvokedEvent_4]){//use while instead of if. Because inter-partition communication is multi-core, so there may be multiple requests coming when the server is processing the request.
        GetLock(lock, lock_bit);
        rte_event[OperationInvokedEvent_4]--;
        ReleaseLock(lock, lock_bit);
        
        com_server_side_divide();//check error, call transformer, enqueue request queue, do operation, send response
    
        //因為執行 server runnable 後還需要調用 transformer 進行資料轉換，所以無法把 server-side 的 Rte event 存取包到 server runnable 內部調用的 api 裡面。
        signal AsynchronousServerCallReturnsEvent_id = 4;
        com_sendSignal(signal_2, &AsynchronousServerCallReturnsEvent_id);//send rte_event_id back to client side.
    }
    while(rte_event[OperationInvokedEvent_5]){
        GetLock(lock, lock_bit);
        rte_event[OperationInvokedEvent_5]--;
        ReleaseLock(lock, lock_bit);
        
        com_server_side_mod();

        signal AsynchronousServerCallReturnsEvent_id = 5;
        com_sendSignal(signal_2, &AsynchronousServerCallReturnsEvent_id);//send rte_event_id back to client side.
    }
}



void com_server_side_divide(){
    ReuqestInfoType request_info;
    com_receiveSignal(signal_3, &request_info);//接收 parameters, transaction_handle.sequence_counter, and operation string(e.g. "add", "sub")
    
    check_transformer_buffer();
    transformer(&transformed_para_1, request_info.parameters[0]);
    Check_transformer_error(error);

    check_transformer_buffer();
    error = transformer(&transformed_para_2, request_info.parameters[1]);
    Check_transformer_error(error);
    
    rte_enqueue(&transformed_para_1,  request_q);//在 server side enqueue request queue
    rte_enqueue(&transformed_para_2,  request_q);
    Impl_uint16 response;
    response = RTE_RUNNABLE_Server4();//do "divide" operation, add operation 會自己去 request_queue 裡面拿參數。
    
    Check_transformer_buffer();
    error = transformer(&transformed_response, response);
    Check_transformer_error(error);

    ResponseInfoType response_info = {
        request_info.transaction_handle,
        transformed_response
    };

    com_sendSignal(signal_4, &response_info);

    return;
}

void com_server_side_mod(){
    ReuqestInfoType request_info;
    com_receiveSignal(signal_3, &request_info);//接收 parameters, transaction_handle.sequence_counter, and operation string(e.g. "add", "sub")
    
    check_transformer_buffer();
    transformer(&transformed_para_1, request_info.parameters[0]);
    Check_transformer_error(error);

    check_transformer_buffer();
    transformer(&transformed_para_2, request_info.parameters[1]);
    Check_transformer_error(error);

    rte_enqueue(&transformed_para_1,  request_q);//在 server side enqueue request queue
    rte_enqueue(&transformed_para_2,  request_q);
    Impl_uint16 response;
    response = RTE_RUNNABLE_Server5();//do "mod" operation, add operation 會自巙去 request_queue 裡面拿參數。
    
    Check_transformer_buffer();
    error = transformer(&transformed_response, response);
    Check_transformer_error(error);

    ResponseInfoType response_info = {
        request_info.transaction_handle,
        transformed_response
    };
    
    com_sendSignal(signal_4, &response_info);

    return;
}


