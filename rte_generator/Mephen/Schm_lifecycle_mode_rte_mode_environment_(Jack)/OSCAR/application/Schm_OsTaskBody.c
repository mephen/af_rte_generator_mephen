/* Task Body*/
Task(T01){
    if (init_flag_0 == 0) {
        EcuM_StartupTwo(); //lifecycle test
        init_flag_0 = 1;
    } else {
        core0_time_counter();
    }
}

Task(T11){
    if (init_flag_1 == 0) {
        init_flag_1 = 1;
    } else {
        core1_time_counter();
    }
}

Task(T02){
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t02)/sizeof(bsw_event_t02[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t02[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t02[i]);
            uint16 ev_type = get_event_type(bsw_event_t02[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t02[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswAsynchronousServerCallReturnsEvent:
                            /*in async case, client side: receive and handle response_info*/
                            //AsynchronousServerCallReturnsEvent: tell a specific client that the response is ready, and [SWS_Rte_02658] says that "Before a request of the client is finished, the client can't send a new c/s request"
                            ResponseInfoType server_response;
                            switch(get_communication_type(bsw_event_t02[i])){
                                case IntraPartition:
                                    server_response = rte_client_side_core0();//check error, call transformer, dequeue response queue
                                    break;
                                case InterPartition:
                                    server_response = ioc_client_side_core0();//check error, call transformer, dequeue response queue
                                    break;
                            }

                            for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){
                                if(rte_cs_metaData_arr[metaData_arr_index].client_id == server_response.transaction_handle.client_id){
                                    RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)
                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == non_blocking){
                                        Impl_uint16 result = bsw_event_t02[i]->Entity_FuncPtr_RVuint16();
                                    }
                                }
                            }
                            break;
                        case BswOperationInvokedEvent:
                            break;
                        case BswTimingEvent:
                            //rte client side: send c/s request¡C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(bsw_event_t02[i]) == ClientRunnable) {
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == bsw_event_t02[i]->Entity_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                        } else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                        }
                                    }
                                }
                            } else {
                                bsw_event_t02[i]->Entity_FuncPtr();
                            }
                            break;
                        case BswModeSwitchedAckEvent:
                            break;
                        default:
                            bsw_event_t02[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t02[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t02[i]);
                ev_triggerred = get_event_counter(bsw_event_t02[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    TerminateTask();
}

Task(T15){
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t15)/sizeof(bsw_event_t15[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t15[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t15[i]);
            uint16 ev_type = get_event_type(bsw_event_t15[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t15[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswAsynchronousServerCallReturnsEvent:
                            break;
                        case BswOperationInvokedEvent:
                            break;
                        case BswTimingEvent:
                            //rte client side: send c/s request¡C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(bsw_event_t15[i]) == ClientRunnable) {
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == bsw_event_t15[i]->Entity_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                        } else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                        }
                                    }
                                }
                            } else {
                                bsw_event_t15[i]->Entity_FuncPtr();
                            }
                            break;
                        case BswModeSwitchedAckEvent:
                            break;
                        default:
                            bsw_event_t15[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t15[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t15[i]);
                ev_triggerred = get_event_counter(bsw_event_t15[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    TerminateTask();
}

Task(T13){
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t13)/sizeof(bsw_event_t13[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t13[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t13[i]);
            uint16 ev_type = get_event_type(bsw_event_t13[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t13[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswAsynchronousServerCallReturnsEvent:
                            break;
                        case BswOperationInvokedEvent:
                            /*server side: receive request_info, handle request, and send response_info*/
                            //server side task use while-loop to check rte_event_arr: Because there may be multiple runnable invoke same server-side runnable simultaneously.
                            //It's impossible that a same client runnable be called concurrently(SWS_Rte_02658: RTE shall allow only one request per client at any time)
                            uint16 client_id = -1;
                            switch(get_communication_type(bsw_event_t13[i])) {
                                case IntraPartition:
                                    client_id = rte_server_side_core1(bsw_event_t13[i]->Entity_FuncPtr_RVuint16);
                                    break;
                                case InterPartition:
                                    client_id = ioc_server_side_core1(bsw_event_t13[i]->Entity_FuncPtr_RVuint16);
                                    break;
                            }
                            //the server_response got from server runnable still need data_processinng(transformer, check transaction_handle, enqueue responseQ...), so we can't trigger Async_return_ev in the api of SR.
                            for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){
                                if(rte_cs_metaData_arr[metaData_arr_index].client_id == client_id){
                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                        /*receive and handle response_info*/
                                        ResponseInfoType server_response;
                                        switch(get_communication_type(bsw_event_t13[i])){
                                            case IntraPartition:
                                                server_response = rte_client_side_core1();//check error, call transformer, dequeue response queue
                                                break;
                                            case InterPartition:
                                                server_response = ioc_client_side_core1();//check error, call transformer, dequeue response queue
                                                break;
                                        }
                                        RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)
                                        SetEvent(T02, event1);
                                    } else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                        GetLock(&share_function_lock_q,share_function_lock_bit);
                                        trigger_event(rte_cs_metaData_arr[metaData_arr_index].async_return_ev); //trigger async_return_ev to : unblock the CRR who use blocking_rte_result / activate the CRR who use non_blocking_rte_result
                                        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                                        if(rte_cs_metaData_arr[metaData_arr_index].SR_task != rte_cs_metaData_arr[metaData_arr_index].CRR_task){
                                            GetTaskState(rte_cs_metaData_arr[metaData_arr_index].CRR_task, &get_task_state);
                                            if (get_task_state == SUSPENDED) {
                                                ActivateTask(rte_cs_metaData_arr[metaData_arr_index].CRR_task); //the task where client handle responseInfo
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case BswTimingEvent:
                            //rte client side: send c/s request¡C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(bsw_event_t13[i]) == ClientRunnable) {
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == bsw_event_t13[i]->Entity_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                        } else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                        }
                                    }
                                }
                            } else {
                                bsw_event_t13[i]->Entity_FuncPtr();
                            }
                            break;
                        case BswModeSwitchedAckEvent:
                            break;
                        default:
                            bsw_event_t13[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t13[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t13[i]);
                ev_triggerred = get_event_counter(bsw_event_t13[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    TerminateTask();
}

Task(T12){
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t12)/sizeof(bsw_event_t12[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t12[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t12[i]);
            uint16 ev_type = get_event_type(bsw_event_t12[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t12[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswAsynchronousServerCallReturnsEvent:
                            break;
                        case BswOperationInvokedEvent:
                            break;
                        case BswTimingEvent:
                            //rte client side: send c/s request¡C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(bsw_event_t12[i]) == ClientRunnable) {
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == bsw_event_t12[i]->Entity_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                        } else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                        }
                                    }
                                }
                            } else {
                                bsw_event_t12[i]->Entity_FuncPtr();
                            }
                            break;
                        case BswModeSwitchedAckEvent:
                            break;
                        default:
                            bsw_event_t12[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t12[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t12[i]);
                ev_triggerred = get_event_counter(bsw_event_t12[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    TerminateTask();
}

Task(T14){
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t14)/sizeof(bsw_event_t14[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t14[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t14[i]);
            uint16 ev_type = get_event_type(bsw_event_t14[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t14[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswAsynchronousServerCallReturnsEvent:
                            break;
                        case BswOperationInvokedEvent:
                            break;
                        case BswTimingEvent:
                            //rte client side: send c/s request¡C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(bsw_event_t14[i]) == ClientRunnable) {
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == bsw_event_t14[i]->Entity_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                        } else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                        }
                                    }
                                }
                            } else {
                                bsw_event_t14[i]->Entity_FuncPtr();
                            }
                            break;
                        case BswModeSwitchedAckEvent:
                            break;
                        default:
                            bsw_event_t14[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t14[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t14[i]);
                ev_triggerred = get_event_counter(bsw_event_t14[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    TerminateTask();
}

Task(T16){
    for ( int i = 0 ; i<(sizeof(bsw_event_t16)/sizeof(bsw_event_t16[0])) ; i++ ) {
        GetLock(&share_function_lock_q,share_function_lock_bit);
        trigger_event(bsw_event_t16[i]);
        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
    }

    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t16)/sizeof(bsw_event_t16[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t16[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t16[i]);
            uint16 ev_type = get_event_type(bsw_event_t16[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t16[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswAsynchronousServerCallReturnsEvent:
                            break;
                        case BswOperationInvokedEvent:
                            break;
                        case BswTimingEvent:
                            //rte client side: send c/s request¡C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(bsw_event_t16[i]) == ClientRunnable) {
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == bsw_event_t16[i]->Entity_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                        } else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                        }
                                    }
                                }
                            } else {
                                bsw_event_t16[i]->Entity_FuncPtr();
                            }
                            break;
                        case BswModeSwitchedAckEvent:
                            break;
                        default:
                            bsw_event_t16[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t16[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t16[i]);
                ev_triggerred = get_event_counter(bsw_event_t16[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    TerminateTask();
}

Task(T03){
    TaskStateType get_task_state;
    int count = 1;
    while (count) {
        count = 0;
        for ( int i = 0 ; i<(sizeof(bsw_event_t03)/sizeof(bsw_event_t03[0])) ; i++ ) {
            GetLock(&share_function_lock_q,share_function_lock_bit);
            uint16 ev_triggerred = get_event_counter(bsw_event_t03[i]);
            uint16 ev_disablemode = get_event_disablemode(bsw_event_t03[i]);
            uint16 ev_type = get_event_type(bsw_event_t03[i]);
            ReleaseLock(&share_function_lock_q,share_function_lock_bit);

            while (ev_triggerred != 0) {
                if (ev_disablemode == 0) {
                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    set_entity_execute(bsw_event_t03[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);

                    switch(ev_type) {
                        case BswAsynchronousServerCallReturnsEvent:
                            break;
                        case BswOperationInvokedEvent:
                            /*server side: receive request_info, handle request, and send response_info*/
                            //server side task use while-loop to check rte_event_arr: Because there may be multiple runnable invoke same server-side runnable simultaneously.
                            //It's impossible that a same client runnable be called concurrently(SWS_Rte_02658: RTE shall allow only one request per client at any time)
                            uint16 client_id = -1;
                            switch(get_communication_type(bsw_event_t03[i])) {
                                case IntraPartition:
                                    client_id = rte_server_side_core0(bsw_event_t03[i]->Entity_FuncPtr_RVuint16);
                                    break;
                                case InterPartition:
                                    client_id = ioc_server_side_core0(bsw_event_t03[i]->Entity_FuncPtr_RVuint16);
                                    break;
                            }
                            //the server_response got from server runnable still need data_processinng(transformer, check transaction_handle, enqueue responseQ...), so we can't trigger Async_return_ev in the api of SR.
                            for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){
                                if(rte_cs_metaData_arr[metaData_arr_index].client_id == client_id){
                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                        /*receive and handle response_info*/
                                        ResponseInfoType server_response;
                                        switch(get_communication_type(bsw_event_t03[i])){
                                            case IntraPartition:
                                                server_response = rte_client_side_core0();//check error, call transformer, dequeue response queue
                                                break;
                                            case InterPartition:
                                                server_response = ioc_client_side_core0();//check error, call transformer, dequeue response queue
                                                break;
                                        }
                                        RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)
                                        SetEvent(T02, event1);
                                    } else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                        GetLock(&share_function_lock_q,share_function_lock_bit);
                                        trigger_event(rte_cs_metaData_arr[metaData_arr_index].async_return_ev); //trigger async_return_ev to : unblock the CRR who use blocking_rte_result / activate the CRR who use non_blocking_rte_result
                                        ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                                        if(rte_cs_metaData_arr[metaData_arr_index].SR_task != rte_cs_metaData_arr[metaData_arr_index].CRR_task){
                                            GetTaskState(rte_cs_metaData_arr[metaData_arr_index].CRR_task, &get_task_state);
                                            if (get_task_state == SUSPENDED) {
                                                ActivateTask(rte_cs_metaData_arr[metaData_arr_index].CRR_task); //the task where client handle responseInfo
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case BswTimingEvent:
                            //rte client side: send c/s request¡C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(bsw_event_t03[i]) == ClientRunnable) {
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == bsw_event_t03[i]->Entity_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                        } else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                        }
                                    }
                                }
                            } else {
                                bsw_event_t03[i]->Entity_FuncPtr();
                            }
                            break;
                        case BswModeSwitchedAckEvent:
                            break;
                        default:
                            bsw_event_t03[i]->Entity_FuncPtr();
                            break;
                    }

                    GetLock(&share_function_lock_q,share_function_lock_bit);
                    clear_entity_execute(bsw_event_t03[i]);
                    ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                }
                GetLock(&share_function_lock_q,share_function_lock_bit);
                release_event(bsw_event_t03[i]);
                ev_triggerred = get_event_counter(bsw_event_t03[i]);
                ReleaseLock(&share_function_lock_q,share_function_lock_bit);
                count++;
            }
        };
    };
    TerminateTask();
}

