void ioc_server_side();

T11{//ioc server side: 接收request，處理request，發送response
    while(operation_invoked_3){
        rte_server_side();//check error, call transformer, enqueue request queue, do operation, send response

        getLock(lock_3, lock_bit);
        rte_event_operation_invoked_3--;
        rte_event_async_return_3++;
        releaseLock(lock_3, lock_bit);

        activateTask(T03);
    }
}

void ioc_server_side(){
    ioc_receive_cc(&data);//接收 parameters, transaction_handle, and operation string(e.g. "add", "sub")
    if(data.operation_string == "add"){
        check_transformer_buffer();
        error = transformer(&transformed_data_1, data.parameters[0]);
        check_transformer_hard_soft_error();

        if(error == e_ok){
            rte_enqueue(&transformed_data_1, request_queue);//在 server side enqueue request queue

            response = server_runnable_1();//do "add" operation, add operation 會自己去 request_queue 裡面拿參數。
            ioc_send_aa(&data.transaction_handle);
            ioc_send_bb(&response);
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
            ioc_send_aa(&data.transaction_handle);
            ioc_send_bb(&response);
        }
    }
};

