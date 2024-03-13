//Async Rte_call + non-blokcing Rte_result。
    //transaction handle：用來做 response to request mapping。
    //Rte_event：trigger client response runnable。

T01{//假設 client runnables 都配置在 T01
    C/S request_ioc;
        enqueue ioc transaction_handle_queue;
    C/S request_ioc;
        enqueue ioc transaction_handle_queue;

    C/S request_rte;
        enqueue rte transaction_handle_queue;
    C/S request_rte;
        enqueue rte transaction_handle_queue;
}

T02{//rte case: server-side
    while(rte transaction_handle_queue not empty){
        dequeue rte transaction_handle_queue;
        switch(transaction_handle){
            case a:
                rte_server_side_1();//call transformer, check error, do server operation, and then enqueue result
                Rte_event_1 = true;
                break;
            case b:
                rte_server_side_2();
                Rte_event_2 = true;
                break;
        }
    }
}

T03{//假設 client response runnables 都配置在 T03
    while(there is any Rte event be set){//use a global variable to record the number of set Rte_events
        if(Rte_event_1){ rte_client_side_1(); response_runnable_1(); set Rte_events number--;}
        if(Rte_event_2){ rte_client_side_2(); response_runnable_1(); set Rte_events number--;}
        if(Rte_event_3){ ioc_client_side_1(); response_runnable_1(); set Rte_events number--;}
        if(Rte_event_4){ ioc_client_side_2(); response_runnable_1(); set Rte_events number--;}
    }
}


/*若 client response runnable 寫在不同 task 的情況*/
T03{
    while(!Rte_event_1){;}
    rte_client_side_1(); response_runnable_1(); set Rte_events number--;
}

T04{
    while(!Rte_event_2){;}
    rte_client_side_2(); response_runnable_2(); set Rte_events number--;
}

//com case 還不確定他們 function 具體怎麼使用，所以暫時不寫。