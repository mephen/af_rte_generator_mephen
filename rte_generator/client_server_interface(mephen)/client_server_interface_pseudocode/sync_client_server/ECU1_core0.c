void com_server_side();

void rte_callback(){
    signal rte_event_operation_invoked_id = -1;
    com_receiveSignal(signal_1, &rte_event_operation_invoked_id);
    switch(rte_event_operation_invoked_id){
        case 5:
            rte_event_operation_invoked_5++;
            break;
        case 6:
            rte_event_operation_invoked_6++;
            break;
    }
    activateTask(T01);
    return;
}

isr{//com 收到資料後，觸發 isr
    rte_callback();
}

T01{//com server side: 接收request，處理request，發送response
    while(operation_invoked_5){
        com_server_side();//check error, call transformer, enqueue request queue, do operation, send response

        getLock(lock_5, lock_bit);
        rte_event_operation_invoked_5--;
        releaseLock(lock_5, lock_bit);
        
        signal rte_event_async_return_id = 5;
        com_sendSignal(signal_2, &rte_event_async_return_id);
    }
    while(operation_invoked_6){
        com_server_side();//check error, call transformer, enqueue request queue, do operation, send response

        getLock(lock_6, lock_bit);
        rte_event_operation_invoked_6--;
        releaseLock(lock_6, lock_bit);
        
        signal rte_event_async_return_id = 6;
        com_sendSignal(signal_2, &rte_event_async_return_id);
    }
}

void com_server_side(){
    com_receiveSignal(signal_3, &data);//接收 parameters, transaction_handle, and operation string(e.g. "add", "sub")
    if(data.operation_string == "add"){
        check_transformer_buffer();
        error = transformer(&transformed_data_1, data.parameters[0]);
        check_transformer_hard_soft_error();

        if(error == e_ok){
            rte_enqueue(&transformed_data_1, request_queue);//在 server side enqueue request queue

            response = server_runnable_1();//do "add" operation, add operation 會自己去 request_queue 裡面拿參數。
            com_sendSignal(signal_4, &data.transaction_handle);
            com_sendSignal(signal_5, &response);
        }
    }
    if(data.operation_string == "sub"){
        std_return error_1, error_2;
        
        check_transformer_buffer();
        error_1 = transformer(&transformed_data_1, data.parameters[0]);
        check_transformer_hard_soft_error();

        check_transformer_buffer();
        error_2 = transformer(&transformed_data_2, data.parameters[1]);
        check_transformer_hard_soft_error();
        
        if(error_1 == e_ok && error_2 == e_ok){
            rte_enqueue(&transformed_data_1, request_queue);
            rte_enqueue(&transformed_data_2, request_queue);

            response = server_runnable_2();//do "sub" operation, sub operation 會自己去 request_queue 裡面拿參數。
            com_sendSignal(signal_4, &data.transaction_handle);
            com_sendSignal(signal_5, &response);
        }
    }
};

