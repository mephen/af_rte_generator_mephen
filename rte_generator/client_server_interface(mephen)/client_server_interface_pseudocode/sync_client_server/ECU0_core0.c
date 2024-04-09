//依照此 flow 的話，隨意 mapping runnable 到不同 task 也不會有問題。
//只是要根據不同的 task，調整 activate task、terminate task 的調用。
#include "Rte_Event_Cfg.h"

void rte_callback(){
    signal AsynchronousServerCallReturnsEvent_id = -1;
    com_receiveSignal(signal_2, &AsynchronousServerCallReturnsEvent_id);
    switch(AsynchronousServerCallReturnsEvent_id){
        case 4:
            GetLock(lock, lock_bit);
            rte_event[AsynchronousServerCallReturnsEvent_4]++; 
            ReleaseLock(lock, lock_bit);
            break;
        case 5:
            GetLock(lock, lock_bit);
            rte_event[AsynchronousServerCallReturnsEvent_5]++; 
            ReleaseLock(lock, lock_bit);
            break;
    }
    activateTask(T03);
    return;
}

isr{//com 收到資料後，觸發 isr
    rte_callback();
}

Impl_uint16 request_q[10];
ResponseInfoType response_q[10];
 

//activate init event
rte_event[InitEvent_1] = 1;
rte_event[InitEvent_2] = 1;
rte_event[InitEvent_3] = 1;

void rte_server_side_add();
void rte_server_side_sub();
std_return rte_client_side();
std_return ioc_client_side();
std_return com_client_side();


T01{//rte client side: 發送request
    //intra-partition
    //單核，不會有同時存取同一個 global variable 的問題
    if(rte_event[InitEvent_1]){
        GetLock(lock, lock_bit);
        rte_event[InitEvent_1]--;
        ReleaseLock(lock, lock_bit);

        RTE_RUNNABLE_Client1();//send parameters & transaction_handle.sequence_counter.
        /*以下四行寫在 RTE_RUNNABLE_Client1 中的 sync_rte_call 裡面*/
            // GetLock(lock, lock_bit);
            // rte_event[OperationInvokedEvent_1]++;//after sending request, increase OperationInvokedEvent. 
            // ReleaseLock(lock, lock_bit);
            // activateTask(T02);
    }
    if(rte_event[InitEvent_2]){
        GetLock(lock, lock_bit);
        rte_event[InitEvent_2]--;
        ReleaseLock(lock, lock_bit);

        RTE_RUNNABLE_Client2();
    }

    //inter-partition
    //假設 inter-partition case 連續發起兩個相同的 async request
    if(rte_event[InitEvent_3]){
        GetLock(lock, lock_bit);
        rte_event[InitEvent_3]--;
        ReleaseLock(lock, lock_bit);

        RTE_RUNNABLE_Client3();
        /*以下四行寫在 RTE_RUNNABLE_Client3 中的 sync_rte_call 裡面*/
            // GetLock(lock, lock_bit);
            // rte_event[OperationInvokedEvent_3]++;
            // ReleaseLock(lock, lock_bit);
            // activateTask(T11);
    }
    if(rte_event[InitEvent_4]){
        GetLock(lock, lock_bit);
        rte_event[InitEvent_4]--;
        ReleaseLock(lock, lock_bit);
        
        RTE_RUNNABLE_Client4();
        //[SWS_Rte_02658]: 不可能調用 RTE_RUNNABLE_Client3()，因為現在 RTE_RUNNABLE_Client3 已經有一個 unfinished c/s request.
    }

    //inter-ECU
    if(rte_event[InitEvent_5]){
        GetLock(lock, lock_bit);
        rte_event[InitEvent_5]--;
        ReleaseLock(lock, lock_bit);

        RTE_RUNNABLE_Client4();
        /*以下二行寫在 RTE_RUNNABLE_Client4 中的 sync_rte_call 裡面*/
            // int OperationInvokedEvent_id = 4;
            // com_sendSignal(signal_1, &OperationInvokedEvent_id);
    }
    if(rte_event[InitEvent_6]){
        GetLock(lock, lock_bit);
        rte_event[InitEvent_6]--;
        ReleaseLock(lock, lock_bit);
        
        RTE_RUNNABLE_Client5();
    }
}

T02{//rte server side: 接收 request_info，處理 request，發送 response_info
    while(rte_event[OperationInvokedEvent_1]){
        GetLock(lock, lock_bit);
        rte_event[OperationInvokedEvent_1]--;
        ReleaseLock(lock, lock_bit);
        
        uint16 client_id = rte_server_side_add();//check error, call transformer, enqueue request queue, do operation, send response

        //因為執行 server runnable 後還需要進行資料處理(調用 transformer、傳輸資料)，所以無法把 server-side 的 Rte event 存取包到 server runnable 內部調用的 api 裡面。
        GetLock(lock, lock_bit);
        rte_event[AsynchronousServerCallReturnsEvent_1]++;
        ReleaseLock(lock, lock_bit);
        switch (client_id){
            case 1:
                ActivateTask(T03);
                break;
            case 2:
                ActivateTask(T04);//如果 client_id = 2 的 client runnable 處理 response info 的 client (response) runnable 配置在 T04
                break;
        }
    }
    while(rte_event[OperationInvokedEvent_2]){
        GetLock(lock, lock_bit);
        rte_event[OperationInvokedEvent_2]--;
        ReleaseLock(lock, lock_bit);

        uint16 client_id = rte_server_side_sub();

        GetLock(lock, lock_bit);
        rte_event[AsynchronousServerCallReturnsEvent_2]++;
        ReleaseLock(lock, lock_bit);
        switch (client_id){
            case 1:
                ActivateTask(T03);
                break;
            case 2:
                ActivateTask(T04);//如果 client_id = 2 的 client runnable 處理 response info 的 client (response) runnable 配置在 T04
                break;
        }
    }
    terminateTask();
}

T03{//client side: 接收response
    //intra-partition
    if(rte_event[AsynchronousServerCallReturnsEvent_1]){
        GetLock(lock, lock_bit);
        rte_event[AsynchronousServerCallReturnsEvent_1]--;
        ReleaseLock(lock, lock_bit);

        ResponseInfoType server_response = rte_client_side();//check error, call transformer, enqueue server_response into the response queue
        RTE_Enqueue(response_q_CR1, &server_response, sizeof(server_response));

        /*在 sync_rte_call 情況，setEvent 要寫在 client-side-task*/
        setEvent(T01, event1);//unblock the corresponding client runnable.
    }
    if(rte_event[AsynchronousServerCallReturnsEvent_2]){
        GetLock(lock, lock_bit);
        rte_event[AsynchronousServerCallReturnsEvent_2]--;
        ReleaseLock(lock, lock_bit);

        ResponseInfoType server_response = rte_client_side();//check error, call transformer, enqueue server_response into the response queue
        RTE_Enqueue(response_q_CR2, &server_response, sizeof(server_response));
        
        /*在 sync_rte_call 情況，setEvent 要寫在 client-side-task*/
        setEvent(T01, event1);//unblock the corresponding client runnable.
    }

    //inter-partition
    while(rte_event[AsynchronousServerCallReturnsEvent_3]){
        GetLock(lock, lock_bit);
        rte_event[AsynchronousServerCallReturnsEvent_3]--;
        ReleaseLock(lock, lock_bit);

        ResponseInfoType server_response = ioc_client_side();//check error, call transformer, enqueue server_response into the response queue
        RTE_Enqueue(response_q_CR3, &server_response, sizeof(server_response));
        
        /*在 sync_rte_call 情況，setEvent 要寫在 client-side-task*/
        setEvent(T01, event1);//unblock the corresponding client runnable.
    }

    //inter-ECU
    while(rte_event[AsynchronousServerCallReturnsEvent_4]){
        GetLock(lock, lock_bit);
        rte_event[AsynchronousServerCallReturnsEvent_4]--;
        ReleaseLock(lock, lock_bit);
        
        ResponseInfoType server_response = com_client_side();//check error, call transformer, enqueue server_response into the response queue
        RTE_Enqueue(response_q_CR4, &server_response, sizeof(server_response));
        
        /*在 sync_rte_call 情況，setEvent 要寫在 client-side-task*/
        setEvent(T01, event1);//unblock the corresponding client runnable.
    }
    while(rte_event[AsynchronousServerCallReturnsEvent_5]){
        GetLock(lock, lock_bit);
        rte_event[AsynchronousServerCallReturnsEvent_5]--;
        ReleaseLock(lock, lock_bit);

        ResponseInfoType server_response = com_client_side();//check error, call transformer, enqueue server_response into the response queue
        RTE_Enqueue(response_q_CR5, &server_response, sizeof(server_response));
        
        /*在 sync_rte_call 情況，setEvent 要寫在 client-side-task*/
        setEvent(T01, event1);//unblock the corresponding client runnable.
    }
    terminateTask();
}

void rte_server_side_add(){
    ReuqestInfoType request_info;
    RTE_Dequeue(&RB_RequestResponseInfo, &request_info, sizeof(request_info));//get request information (parameters & transaction_handle.sequence_counter).
    
    Check_transformer_buffer();
    error = transformer(&transformed_para_1, request_info.parameters[0]);
    Check_transformer_error(error);

    Check_transformer_buffer();
    error = transformer(&transformed_para_2, request_info.parameters[0]);
    Check_transformer_error(error);
    
    RTE_Enqueue( request_q,&transformed_para_1, sizeof(transformed_para_1));//在 server side enqueue request queue
    RTE_Enqueue( request_q,&transformed_para_2, sizeof(transformed_para_1));
    Impl_uint16 response = RTE_RUNNABLE_Server1();//do "add" operation, add operation 會自己去 request_queue 裡面拿參數。

    Check_transformer_buffer();
    error = transformer(&transformed_response, response);
    Check_transformer_error(error);

    ResponseInfoType response_info = {
        request_info.transaction_handle,
        transformed_response
    };

    RTE_Enqueue(RB_RequestResponseInfo, &response_info,sizeof(response_info));//send response information (response & transaction_handle) to client side

    return;
}

void rte_server_side_sub(){
    ReuqestInfoType request_info;
    RTE_Dequeue(&RB_RequestResponseInfo, &request_info, sizeof(request_info));

    check_transformer_buffer();
    transformer_error = transformer(&transformed_para_1, request_info.parameters[0]);
    Check_transformer_error(transformer_error);

    check_transformer_buffer();
    transformer(&transformed_para_2, request_info.parameters[1]);
    Check_transformer_error(transformer_error);
    
    RTE_Enqueue( request_q, &transformed_para_1, sizeof(transformed_para_1));
    RTE_Enqueue( request_q, &transformed_para_2, sizeof(transformed_para_2));
    Impl_uint16 response = RTE_RUNNABLE_Server2();//do "sub" operation, add operation 會自己去 request_queue 裡面拿參數。
    
    Check_transformer_buffer();
    error = transformer(&transformed_response, response);
    Check_transformer_error(error);

    ResponseInfoType response_info = {
        request_info.transaction_handle,
        transformed_response
    };

    RTE_Enqueue(RB_RequestResponseInfo, &response_info, sizeof(response_info));//store response information

    return;
}

ResponseInfoType rte_client_side(){
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    RTE_Dequeue(&RB_RequestResponseInfo, &response_info, sizeof(response_info));
    
    bsw_error = check_transformer_buffer();
    transformer_error = transformer(&transformed_response, response_info.response);
    bsw_error = Check_transformer_error(transformer_error);

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle.sequence_counter,
        transformed_response
    };
    return server_response;
}

void ioc_client_side(){
    std_return bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    ioc_receive_bb(&response_info);
    
    bsw_error = check_transformer_buffer();
    transformer_error = transformer(&transformed_response, response_info.response);
    bsw_error = Check_transformer_error(transformer_error);

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle.sequence_counter,
        transformed_response
    };
    return;
}

void com_client_side(){
    std_return bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    com_receiveSignal(signal_4, &response_info);
    
    bsw_error = check_transformer_buffer();
    transformer_error = transformer(&transformed_response, response_info.response);
    bsw_error = Check_transformer_error(transformer_error);
    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle.sequence_counter,
        transformed_response
    };
    return;
}