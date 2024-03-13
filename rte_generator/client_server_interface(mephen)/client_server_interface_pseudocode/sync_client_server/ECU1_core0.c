//Sync Rte_call
    //Rte_event：unblock client runnable。
    //transaction handle：do response to request mapping。

T01{//假設 client runnables 都配置在 T01
    enqueue ioc transaction_handle_queue;
        C/S request_ioc;//client runnable: after sending data, wait for Rte_event
    enqueue ioc transaction_handle_queue;
        C/S request_ioc;

    enqueue rte transaction_handle_queue;
        C/S request_rte;
    enqueue rte transaction_handle_queue;
        C/S request_rte;
}

T02{//rte case: server-side
    while(rte transaction_handle_queue not empty){
        dequeue rte transaction_handle_queue;
        switch(transaction_handle){
            case a:
                rte_server_side_1();//call transformer, check error, do server operation, enqueue result
                Rte_event_1 = true;//喚醒 client runnable
                break;
            case b:
                rte_server_side_2();
                Rte_event_2 = true;
                break;
        }
    }
}

T03{//process rte_event -> unblock specific client runnable
    while(there is any Rte event be set){//use a global variable to record the number of set Rte_events
        if(Rte_event_1){ rte_client_side_1(); set Rte_events number--; setEvent(event1);}
        if(Rte_event_2){ rte_client_side_2(); set Rte_events number--; setEvent(event2);}
        if(Rte_event_3){ ioc_client_side_3(); set Rte_events number--; setEvent(event3);}
        if(Rte_event_4){ ioc_client_side_4(); set Rte_events number--; setEvent(event4);}
    }
}

//com case 還不確定他們 function 具體怎麼使用，所以暫時不寫。