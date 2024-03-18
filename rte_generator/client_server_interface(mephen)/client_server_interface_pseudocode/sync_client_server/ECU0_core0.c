//依照此 flow 的話，隨意 mapping runnable 到不同 task 也不會有問題。
//只是要根據不同的 task，調整 activate task、terminate task 的調用。

void rte_callback(){
    signal rte_event_operation_invoked_id = -1;
    com_receiveSignal(signal_1, &rte_event_async_return_id);
    switch(rte_event_async_return_id){
        case 5:
            rte_event_async_return_5++; 
            break;
        case 6:
            rte_event_async_return_6++; 
            break;
    }
    activateTask(T03);
    return;
}

isr{//com 收到資料後，觸發 isr
    rte_callback();
}

//activate init event
int rte_event_init_1 = 1;
int rte_event_init_2 = 1;
int rte_event_init_3 = 1;

void rte_server_side();
std_return rte_client_side();
std_return ioc_client_side();
std_return com_client_side();


T01{//rte client side: 發送request
    //intra-partition
    //單核，不會有同時存取同一個 global variable 的問題
    if(rte_event_init_1){
        rte_event_init_1--;
        rte_event_operation_invoked_1++;

        client_runnable_1();//send parameters, transaction_handle, and operation string(e.g. "add", "sub")。還有 enqueue sequence counter
        //activateTask(T02) 寫在 sync_rte_call 中的 waitEvent 前

        terminateTask(); //因為 intra-partition 是單核，以完成一個 C/S 溝通為優先，而非發起多個 request 為優先。
    }
    if(rte_event_init_2){
        rte_event_init_2--;
        rte_event_operation_invoked_2++;

        client_runnable_2();
        //activateTask(T02) 寫在 sync_rte_call 中的 waitEvent 前

        terminateTask();
    }

    //inter-partition
    //可能會有同時存取同一個 global variable 的問題
    //假設 inter-partition case 連續發起兩個相同的 async request
    if(rte_event_init_3){
        getLock(lock_3, lock_bit);
        rte_event_init_3--;
        rte_event_operation_invoked_3++;
        releaseLock(lock_3, lock_bit);
        
        client_runnable_3();
        //activateTask(T11) 寫在 sync_rte_call 中的 waitEvent 前
    }
    if(rte_event_init_4){
        getLock(lock_3, lock_bit);
        rte_event_init_4--;
        rte_event_operation_invoked_3++;
        releaseLock(lock_3, lock_bit);

        client_runnable_3();
        //activateTask(T11) 寫在 sync_rte_call 中的 waitEvent 前
    }

    //inter-ECU
    //可能會有同時存取同一個 global variable 的問題
    if(rte_event_init_5){
        getLock(lock_5, lock_bit);
        rte_event_init_5--;
        releaseLock(lock_5, lock_bit);

        client_runnable_4();
        // int rte_event_operation_invoked_id = 5;
        // com_sendSignal(signal_1, &rte_event_operation_invoked_id);
        // 上面兩行寫在 sync_rte_call 中的 waitEvent 前
    }
    if(rte_event_init_6){
        getLock(lock_6, lock_bit);
        rte_event_init_6--;
        releaseLock(lock_6, lock_bit);
        
        client_runnable_5();
        // int rte_event_operation_invoked_id = 6;
        // com_sendSignal(signal_2, &rte_event_operation_invoked_id);
        // 上面兩行寫在 sync_rte_call 中的 waitEvent 前
    }
}

T02{//rte server side: 接收request，處理request，發送response
    if(rte_event_operation_invoked_1){
        rte_server_side();//check error, call transformer, enqueue request queue, do operation, send response

        rte_event_operation_invoked_1--;
        rte_event_async_return_1++;

        activateTask(T03);
        terminateTask();
    }
    if(rte_event_operation_invoked_2){
        rte_server_side();

        rte_event_operation_invoked_2--;
        rte_event_async_return_2++;

        activateTask(T03);
        terminateTask();
    }
}

T03{//rte client side: 接收response
    //intra-partition
    while(rte_event_async_return_1 || response_runnable_1_outside_error_flag == RTE_E_TIMEOUT){
        rte_dequeue(&sequence_counter, response_runnable_1_sequence_counter_queue);
        if(rte_event_async_return_1){
            rte_dequeue(&transaction_handle, rte_internal_queue_transaction_handle);
            if(sequence_counter == transaction_handle.sequence_counter){
                error = rte_client_side();//check error, call transformer, enqueue response queue
                response_runnable_1_outside_error_flag = error;
                setEvent(T01, event1);//unblock client_response_runnable1() in T01
                response_runnable_1_outside_error_flag == RTE_E_OK;//reset the error_flag 
                rte_event_async_return_1--;
            }
        }
        activateTask(T01); //讓下一個 intra-partition request 可以發起，但下次會從這裡繼續執行，所以要用 while loop。
    }
    while(rte_event_async_return_2 || response_runnable_2_outside_error_flag == RTE_E_TIMEOUT){
        rte_dequeue(&sequence_counter, response_runnable_2_sequence_counter_queue);
        if(rte_event_async_return_2){
            rte_dequeue(&transaction_handle, rte_internal_queue_transaction_handle);
            if(sequence_counter == transaction_handle.sequence_counter){
                error = rte_client_side();
                response_runnable_2_outside_error_flag = error;
                setEvent(T01, event2);
                response_runnable_2_outside_error_flag == RTE_E_OK;
                rte_event_async_return_2--;
            }
        }
        activateTask(T01);
    }

    //inter-partition
    while(rte_event_async_return_3 || response_runnable_3_outside_error_flag == RTE_E_TIMEOUT){
        rte_dequeue(&sequence_counter, response_runnable_3_sequence_counter_queue);
        if(rte_event_async_return_3){
            ioc_receive_aa(&transaction_handle);
            if(sequence_counter == transaction_handle.sequence_counter){
                error = ioc_client_side();
                response_runnable_3_outside_error_flag = error;
                setEvent(T01, event3);
                response_runnable_3_outside_error_flag == RTE_E_OK;
                rte_event_async_return_3--;
            }
        }
    }

    //inter-ECU
    while(rte_event_async_return_5 || response_runnable_5_outside_error_flag == RTE_E_TIMEOUT){
        rte_dequeue(&sequence_counter, response_runnable_5_sequence_counter_queue);
        if(rte_event_async_return_5){
            com_receiveSignal(signal_4, &transaction_handle);
            if(sequence_counter == transaction_handle.sequence_counter){
                error = com_client_side();
                response_runnable_5_outside_error_flag = error;
                setEvent(T01, event4);
                response_runnable_5_outside_error_flag == RTE_E_OK;
                rte_event_async_return_5--;
            }
        }
    }
    while(rte_event_async_return_6 || response_runnable_6_outside_error_flag == RTE_E_TIMEOUT){
        rte_dequeue(&sequence_counter, response_runnable_6_sequence_counter_queue);
        if(rte_event_async_return_6){
            com_receiveSignal(signal_4, &transaction_handle);
            if(sequence_counter == transaction_handle.sequence_counter){
                error = com_client_side();
                response_runnable_6_outside_error_flag = error;
                setEvent(T01, event5);
                response_runnable_6_outside_error_flag == RTE_E_OK;
                rte_event_async_return_6--;
            }
        }
    }
}

void rte_server_side(){
    rte_dequeue(&data, rte_internal_queue);//拿出 parameters, transaction_handle, and operation string(e.g. "add", "sub")
    if(data.operation_string == "add"){
        check_transformer_buffer();
        error = transformer(&transformed_data_1, data.parameters[0]);
        check_transformer_hard_soft_error();

        if(error == e_ok){
            rte_enqueue(&transformed_data_1, request_queue);//在 server side enqueue request queue
            response = server_runnable_1();//do "add" operation, add operation 會自己去 request_queue 裡面拿參數。
            rte_enqueue(&data.transaction_handle, rte_internal_queue_transaction_handle);
            rte_enqueue(&response, rte_internal_queue_response);
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
            rte_enqueue(&data.transaction_handle, rte_internal_queue_transaction_handle);
            rte_enqueue(&response, rte_internal_queue_response);
        }
    }
}

std_return rte_client_side(){
    std_return error = RTE_E_OK;
    rte_dequeue(&response, rte_internal_queue);
    
    check_transformer_buffer();
    error = transformer(&transformed_response, response);
    check_transformer_hard_soft_error();

    if(error == RTE_E_OK){
        rte_enqueue(&transformed_response, response_queue);
    }

    return error;
}

std_return ioc_client_side(){
    std_return error = RTE_E_OK;
    ioc_receive_bb(&response);
    
    check_transformer_buffer();
    error = transformer(&transformed_response, response);
    check_transformer_hard_soft_error();

    if(error == RTE_E_OK){
        rte_enqueue(&transformed_response, response_queue);
    }

    return error;
}

std_return com_client_side(){
    std_return error = RTE_E_OK;
    com_receiveSignal(signal_5, &response);
    
    check_transformer_buffer();
    error = transformer(&transformed_response, response);
    check_transformer_hard_soft_error();

    if(error == RTE_E_OK){
        rte_enqueue(&transformed_response, response_queue);
    }

    return error;
}