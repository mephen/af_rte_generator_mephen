T11{//ioc case: server-side
    while(ioc transaction_handle_queue not empty){
        dequeue ioc transaction_handle_queue;
        switch(transaction_handle){
            case a:
                server_side_1();//call transformer, check error, do server operation, send result to client
                Rte_event_3 = true;//喚醒 client runnable
                break;
            case b:
                server_side_2();
                Rte_event_4 = true;
                break;
        }
    }
}