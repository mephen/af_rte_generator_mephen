//---------------------------------------------------------------------------------------------------------------
//App1.c
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "counter.h"
#include "alarm.h"
#include "task.h"
#include "isr2.h"
#include "event.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "string_format_test.h"
#include "systemcall.h"
#include "application.h"
#include "ISRInit.h"
#include "isr_Cfg.h"
#include "spinlock.h"
#include "resource.h"
#include "memsection.h"
#include "trustedFunc_Cfg.h"
#include "ioc.h"
#include "lock.h"
#include "Rte_Event_Cfg.h"
#include "Transformer_stub.h"
#include "Rte_Cs_Data_Management.h"
#include "SWC_Client/Rte_SWC_Client.h"
#include "SWC_Server_1/Rte_SWC_Server_1.h"
#include "SWC_Server_2/Rte_SWC_Server_2.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

static uint8 lock = 0;
static uint8 lock_bit = 1;

static uint16 rte_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Impl_uint16 response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;

    uint16 para_arr[10];
    uint16 transformed_para_arr[10];
    //get request information (parameters & sequence_counter).
    RTE_Dequeue(&RB_requestInfo_core0, &len_args, sizeof(uint16));
    for(int i = 0; i < len_args; i++){
        RTE_Dequeue(&RB_requestInfo_core0, &para_arr[i], sizeof(Impl_uint16));
    }
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.client_id, sizeof(uint16));
    RTE_Dequeue(&RB_requestInfo_core0, &transaction_handle.sequence_counter, sizeof(uint16));

    //transform data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_arr[i], sizeof(uint16));
    }
    //enqueue request queue on server side
    for(int i = 0; i < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); i++){
        if(Server_Runnable == rte_cs_metaData_arr[i].SR_RVuint16){
            for(int j = 0; j < len_args; j++){
                RTE_Enqueue(rte_cs_metaData_arr[i].RB_request_ptr, &transformed_para_arr[j], sizeof(uint16));
            }
            response = rte_cs_metaData_arr[i].SR_RVuint16();//do server operation, SR will get paras in its own request_queue
            break;
        }
    }

    //transform data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType response_info = {
        RTE_E_OK,
        transaction_handle,
        transformed_response
    };
    RTE_Enqueue(&RB_responseInfo_core0, &response_info, sizeof(ResponseInfoType));//via rte_internal_buffer, store response information (response & sequence_counter)
    return transaction_handle.client_id;
}

static ResponseInfoType rte_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    RTE_Dequeue(&RB_responseInfo_core0, &response_info, sizeof(ResponseInfoType));

    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}

static uint16 ioc_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Impl_uint16 response;
    Rte_Cs_TransactionHandleType transaction_handle;
    Std_ReturnType bsw_error = RTE_E_OK;

    uint16 para_arr[10];
    uint16 transformed_para_arr[10];
    //get request information (parameters & sequence_counter).
    IocReceive_Q1(&len_args);
    for(int i = 0; i < len_args; i++){
        IocReceive_Q1(&para_arr[i]);
    }
    IocReceive_Q1(&transaction_handle.client_id);
    IocReceive_Q1(&transaction_handle.sequence_counter);

    //transform data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core0, (void*)&transformed_para_arr[i], sizeof(uint16));
    }

    //enqueue request queue on server side
    for(int i = 0; i < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); i++){
        if(Server_Runnable == rte_cs_metaData_arr[i].SR_RVuint16){
            for(int j = 0; j < len_args; j++){
                RTE_Enqueue(rte_cs_metaData_arr[i].RB_request_ptr, &transformed_para_arr[j], sizeof(uint16));
            }
            response = rte_cs_metaData_arr[i].SR_RVuint16();//do server operation, SR will get paras in its own request_queue
            break;
        }
    }

    //transform data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    //send response information (response & sequence_counter).
    IocSend_Q1_SND1(transaction_handle.client_id);//for server_response.transaction_handle.client_id
    IocSend_Q1_SND1(transaction_handle.sequence_counter);//for server_response.transaction_handle.sequence_counter
    IocSend_Q1_SND1(transformed_response);//for server_response.response
    return transaction_handle.client_id;
}

static ResponseInfoType ioc_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    IocReceive_Q1(&response_info.transaction_handle.client_id);
    IocReceive_Q1(&response_info.transaction_handle.sequence_counter);
    IocReceive_Q1(&response_info.response);
    
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core0);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core0, &RB_transformer_core0.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core0, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}

TASK(T01)
{
    PrintText("hello T01\r\n\0");

    //assumption: runnable can use only one Rte_call (becuase parser doesn't know how the user implements the runnable).
    int count = 1;
    //avoid the situation that a runnable of Task_A use Rte api to trigger a Rte event of another Task_B,
    //but Task_B has checked the Rte event before Task_A triggers it, and Task_B is still running.(may cause some triggerred RTE events be ignored)
    while(count){
        count = 0;
        for(int ev_t01_index =0; ev_t01_index<(sizeof(rte_event_t01)/sizeof(rte_event_t01[0]));ev_t01_index++){
            GetLock(&lock, lock_bit);
            uint8 ev_triggerred = get_rteevent_counter(rte_event_t01[ev_t01_index]);
            ReleaseLock(&lock, lock_bit);
            //task priority may cause the runnable pending(even if the rte_event is triggerred). Rte event may be triggerred multiple times, so we need to use "while-loop" to check rte_event_counter
            while(ev_triggerred){ //check if the event is triggered
                GetLock(&lock, lock_bit);
                uint8 ev_disablemode = get_rteevent_disablemode(rte_event_t01[ev_t01_index]);
                ReleaseLock(&lock, lock_bit);
                if(!(ev_disablemode)){ //check if the event can activate corresponding runnable
                    GetLock(&lock, lock_bit);
                    set_runnable_execute(rte_event_t01[ev_t01_index]);//set_runnable_execute before invoking the runnable
                    ReleaseLock(&lock, lock_bit);

                    switch (get_rteevent_type(rte_event_t01[ev_t01_index])){ //check RTEEvent type
                        case InitEvent:
                            //rte client side: send c/s request�C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(rte_event_t01[ev_t01_index]) == ClientRunnable){
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == rte_event_t01[ev_t01_index]->Runnable_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                            if((ev_t01_index==0 && result == 8) || (ev_t01_index==1 && result == 8U) || (ev_t01_index==2 && result == 15U)){
                                                PrintText("success\r\n\0");
                                            }
                                        }else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                            if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == blocking){
                                                Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CRR_RVuint16(); // CRR use blocking_rte_result: wait for async_return_ev to unblock it
                                                if((ev_t01_index==0 && result == 8) || (ev_t01_index==1 && result == 8U) || (ev_t01_index==2 && result == 15U)){
                                                    PrintText("success\r\n\0");
                                                }
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        case OperationInvokedEvent:
                            /*server side: receive request_info, handle request, and send response_info*/
                            //server side task use while-loop to check rte_event_arr: Because there may be multiple runnable invoke same server-side runnable simultaneously.
                            //It's impossible that a same client runnable be called concurrently(SWS_Rte_02658: RTE shall allow only one request per client at any time)
                            uint16 client_id = -1;
                            switch(get_communication_type(rte_event_t01[ev_t01_index])){
                                case IntraPartition:
                                    client_id = rte_server_side(rte_event_t01[ev_t01_index]->Runnable_FuncPtr_RVuint16);//check error, call transformer, enqueue request queue, do operation, send response
                                    break;
                                case InterPartition:
                                    client_id = ioc_server_side(rte_event_t01[ev_t01_index]->Runnable_FuncPtr_RVuint16);
                                    break;
                                case InterEcu:
                                    /*com_server_side fn.*/
                                    break;
                            }
                            //the server_response got from server runnable still need data_processinng(transformer, check transaction_handle, enqueue responseQ...), so we can't trigger Async_return_ev in the api of SR.
                            for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){
                                if(rte_cs_metaData_arr[metaData_arr_index].client_id == client_id){
                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                        /*receive and handle response_info*/
                                        ResponseInfoType server_response;
                                        switch(get_communication_type(rte_event_t01[ev_t01_index])){
                                            case IntraPartition:
                                                server_response = rte_client_side();//check error, call transformer, dequeue response queue
                                                break;
                                            case InterPartition:
                                                server_response = ioc_client_side();
                                                break;
                                            case InterEcu:
                                                /*com client side fn.*/
                                                break;
                                        }
                                        RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)
                                        SetEvent(T01, event1);//unblock the CR who use sync_rte_call (sync_rte_call doesn't configure waitPoint, so we assume event1)
                                    }else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                        GetLock(&lock, lock_bit);
                                        trigger_rteevent(rte_cs_metaData_arr[metaData_arr_index].async_return_ev); //trigger async_return_ev to : unblock the CRR who use blocking_rte_result / activate the CRR who use non_blocking_rte_result
                                        ReleaseLock(&lock, lock_bit);
                                        if(rte_cs_metaData_arr[metaData_arr_index].SR_task != rte_cs_metaData_arr[metaData_arr_index].CRR_task){
                                            ActivateTask(rte_cs_metaData_arr[metaData_arr_index].CRR_task); //the task where client handle responseInfo
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        case AsynchronousServerCallReturnsEvent:
                            /*in async case, client side: receive and handle response_info*/
                            //AsynchronousServerCallReturnsEvent: tell a specific client that the response is ready, and [SWS_Rte_02658] says that "Before a request of the client is finished, the client can't send a new c/s request"
                            ResponseInfoType server_response;
                            switch(get_communication_type(rte_event_t01[ev_t01_index])){
                                case IntraPartition:
                                    server_response = rte_client_side();//check error, call transformer, dequeue response queue
                                    break;
                                case InterPartition:
                                    server_response = ioc_client_side();
                                    break;
                                case InterEcu:
                                    /*com client side fn.*/
                                    break;
                            }

                            for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){
                                if(rte_cs_metaData_arr[metaData_arr_index].client_id == server_response.transaction_handle.client_id){
                                    RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)
                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == blocking){
                                        SetEvent(T01, event1); //unblock the CRR who use blocking_rte_result
                                    }else if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == non_blocking){
                                        Impl_uint16 result = rte_event_t01[ev_t01_index]->Runnable_FuncPtr_RVuint16(); // activate the CRR who use non_blocking_rte_result
                                        if((ev_t01_index==0 && result == 8) || (ev_t01_index==1 && result == 8U) || (ev_t01_index==2 && result == 15U)){
                                            PrintText("success\r\n\0");
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        default:
                            //other 13 RTEEvent type case...
                            break;
                    }

                    GetLock(&lock, lock_bit);
                    clear_runnable_execute(rte_event_t01[ev_t01_index]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_rteevent(rte_event_t01[ev_t01_index]); //release the event
                ev_triggerred = get_rteevent_counter(rte_event_t01[ev_t01_index]);
                ReleaseLock(&lock, lock_bit);
                count++;
            }
        }
    }
    
    TerminateTask();
}
TASK(T02)
{
    PrintText("hello T02\r\n\0");

    //assumption: runnable can use only one Rte_call (becuase parser doesn't know how the user implements the runnable).
    int count = 1;
    //avoid the situation that a runnable of Task_A use Rte api to trigger a Rte event of another Task_B,
    //but Task_B has checked the Rte event before Task_A triggers it, and Task_B is still running.(may cause some triggerred RTE events be ignored)
    while(count){
        count = 0;
        for(int ev_t02_index =0; ev_t02_index<(sizeof(rte_event_t02)/sizeof(rte_event_t02[0]));ev_t02_index++){
            GetLock(&lock, lock_bit);
            uint8 ev_triggerred = get_rteevent_counter(rte_event_t02[ev_t02_index]);
            ReleaseLock(&lock, lock_bit);
            //task priority may cause the runnable pending(even if the rte_event is triggerred). Rte event may be triggerred multiple times, so we need to use "while-loop" to check rte_event_counter
            while(ev_triggerred){ //check if the event is triggered
                GetLock(&lock, lock_bit);
                uint8 ev_disablemode = get_rteevent_disablemode(rte_event_t02[ev_t02_index]);
                ReleaseLock(&lock, lock_bit);
                if(!(ev_disablemode)){ //check if the event can activate corresponding runnable
                    GetLock(&lock, lock_bit);
                    set_runnable_execute(rte_event_t02[ev_t02_index]);//set_runnable_execute before invoking the runnable
                    ReleaseLock(&lock, lock_bit);

                    switch (get_rteevent_type(rte_event_t02[ev_t02_index])){ //check RTEEvent type
                        case InitEvent:
                            //rte client side: send c/s request�C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(rte_event_t02[ev_t02_index]) == ClientRunnable){
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == rte_event_t02[ev_t02_index]->Runnable_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                            if((ev_t02_index==2 && result == 8) || (ev_t02_index==3 && result == 8U) || (ev_t02_index==4 && result == 15U)){
                                                PrintText("success\r\n\0");
                                            }
                                        }else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                            if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == blocking){
                                                Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CRR_RVuint16(); // CRR use blocking_rte_result: wait for async_return_ev to unblock it
                                                if((ev_t02_index==2 && result == 8) || (ev_t02_index==3 && result == 8U) || (ev_t02_index==4 && result == 15U)){
                                                    PrintText("success\r\n\0");
                                                }
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        case OperationInvokedEvent:
                            /*server side: receive request_info, handle request, and send response_info*/
                            //server side task use while-loop to check rte_event_arr: Because there may be multiple runnable invoke same server-side runnable simultaneously.
                            //It's impossible that a same client runnable be called concurrently(SWS_Rte_02658: RTE shall allow only one request per client at any time)
                            uint16 client_id = -1;
                            switch(get_communication_type(rte_event_t02[ev_t02_index])){
                                case IntraPartition:
                                    client_id = rte_server_side(rte_event_t02[ev_t02_index]->Runnable_FuncPtr_RVuint16);//check error, call transformer, enqueue request queue, do operation, send response
                                    break;
                                case InterPartition:
                                    client_id = ioc_server_side(rte_event_t02[ev_t02_index]->Runnable_FuncPtr_RVuint16);
                                    break;
                                case InterEcu:
                                    /*com_server_side fn.*/
                                    break;
                            }
                            //the server_response got from server runnable still need data_processinng(transformer, check transaction_handle, enqueue responseQ...), so we can't trigger Async_return_ev in the api of SR.
                            for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){
                                if(rte_cs_metaData_arr[metaData_arr_index].client_id == client_id){
                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                        /*receive and handle response_info*/
                                        ResponseInfoType server_response;
                                        switch(get_communication_type(rte_event_t02[ev_t02_index])){
                                            case IntraPartition:
                                                server_response = rte_client_side();//check error, call transformer, dequeue response queue
                                                break;
                                            case InterPartition:
                                                server_response = ioc_client_side();
                                                break;
                                            case InterEcu:
                                                /*com client side fn.*/
                                                break;
                                        }
                                        RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)
                                        SetEvent(T01, event1);//unblock the CR who use sync_rte_call (sync_rte_call doesn't configure waitPoint, so we assume event1)
                                    }else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                        GetLock(&lock, lock_bit);
                                        trigger_rteevent(rte_cs_metaData_arr[metaData_arr_index].async_return_ev); //trigger async_return_ev to : unblock the CRR who use blocking_rte_result / activate the CRR who use non_blocking_rte_result
                                        ReleaseLock(&lock, lock_bit);
                                        if(rte_cs_metaData_arr[metaData_arr_index].SR_task != rte_cs_metaData_arr[metaData_arr_index].CRR_task){
                                            ActivateTask(rte_cs_metaData_arr[metaData_arr_index].CRR_task); //the task where client handle responseInfo
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        case AsynchronousServerCallReturnsEvent:
                            /*in async case, client side: receive and handle response_info*/
                            //AsynchronousServerCallReturnsEvent: tell a specific client that the response is ready, and [SWS_Rte_02658] says that "Before a request of the client is finished, the client can't send a new c/s request"
                            ResponseInfoType server_response;
                            switch(get_communication_type(rte_event_t02[ev_t02_index])){
                                case IntraPartition:
                                    server_response = rte_client_side();//check error, call transformer, dequeue response queue
                                    break;
                                case InterPartition:
                                    server_response = ioc_client_side();
                                    break;
                                case InterEcu:
                                    /*com client side fn.*/
                                    break;
                            }

                            for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){
                                if(rte_cs_metaData_arr[metaData_arr_index].client_id == server_response.transaction_handle.client_id){
                                    RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)
                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == blocking){
                                        SetEvent(T01, event1); //unblock the CRR who use blocking_rte_result
                                    }else if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == non_blocking){
                                        Impl_uint16 result = rte_event_t02[ev_t02_index]->Runnable_FuncPtr_RVuint16(); // activate the CRR who use non_blocking_rte_result
                                        if((ev_t02_index==2 && result == 8) || (ev_t02_index==3 && result == 8U) || (ev_t02_index==4 && result == 15U)){
                                            PrintText("success\r\n\0");
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        default:
                            //other 13 RTEEvent type case...
                            break;
                    }

                    GetLock(&lock, lock_bit);
                    clear_runnable_execute(rte_event_t02[ev_t02_index]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_rteevent(rte_event_t02[ev_t02_index]); //release the event
                ev_triggerred = get_rteevent_counter(rte_event_t02[ev_t02_index]);
                ReleaseLock(&lock, lock_bit);
                count++;
            }
        }
    }

    TerminateTask();
}
//---------------------------------------------------------------------------------------------------------------
//App2.c
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "counter.h"
#include "alarm.h"
#include "task.h"
#include "isr2.h"
#include "event.h"
#include "memsection.h"
#include "memprot_Cfg.h"
#include "string_format_test.h"
#include "systemcall.h"
#include "application.h"
#include "ISRInit.h"
#include "isr_Cfg.h"
#include "spinlock.h"
#include "resource.h"
#include "memsection.h"
#include "trustedFunc_Cfg.h"
#include "ioc.h"
#include "lock.h"
#include "Rte_Event_Cfg.h"
#include "Transformer_stub.h"
#include "Rte_Cs_Data_Management.h"
#include "SWC_Client/Rte_SWC_Client.h"
#include "SWC_Server_1/Rte_SWC_Server_1.h"
#include "SWC_Server_2/Rte_SWC_Server_2.h"

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC

static uint8 lock = 0;
static uint8 lock_bit = 1;

static uint16 rte_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Impl_uint16 response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;

    uint16 para_arr[10];
    uint16 transformed_para_arr[10];
    //get request information (parameters & sequence_counter).
    RTE_Dequeue(&RB_requestInfo_core1, &len_args, sizeof(uint16));
    for(int i = 0; i < len_args; i++){
        RTE_Dequeue(&RB_requestInfo_core1, &para_arr[i], sizeof(Impl_uint16));
    }
    RTE_Dequeue(&RB_requestInfo_core1, &transaction_handle.client_id, sizeof(uint16));
    RTE_Dequeue(&RB_requestInfo_core1, &transaction_handle.sequence_counter, sizeof(uint16));

    //transform data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core1, (void*)&transformed_para_arr[i], sizeof(uint16));
    }
    //enqueue request queue on server side
    for(int i = 0; i < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); i++){
        if(Server_Runnable == rte_cs_metaData_arr[i].SR_RVuint16){
            for(int j = 0; j < len_args; j++){
                RTE_Enqueue(rte_cs_metaData_arr[i].RB_request_ptr, &transformed_para_arr[j], sizeof(uint16));
            }
            response = rte_cs_metaData_arr[i].SR_RVuint16();//do server operation, SR will get paras in its own request_queue
            break;
        }
    }

    //transform data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    ResponseInfoType response_info = {
        RTE_E_OK,
        transaction_handle,
        transformed_response
    };
    RTE_Enqueue(&RB_responseInfo_core1, &response_info, sizeof(ResponseInfoType));//via rte_internal_buffer, store response information (response & sequence_counter)
    return transaction_handle.client_id;
}

static ResponseInfoType rte_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    RTE_Dequeue(&RB_responseInfo_core1, &response_info, sizeof(ResponseInfoType));

    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}

static uint16 ioc_server_side(uint16 (*Server_Runnable)()){
    uint8 transformer_error;
    uint16 len_args, transformed_response;
    Impl_uint16 response;
    Rte_Cs_TransactionHandleType transaction_handle;
    Std_ReturnType bsw_error = RTE_E_OK;

    uint16 para_arr[10];
    uint16 transformed_para_arr[10];
    //get request information (parameters & sequence_counter).
    IocReceive_Q1(&len_args);
    for(int i = 0; i < len_args; i++){
        IocReceive_Q1(&para_arr[i]);
    }
    IocReceive_Q1(&transaction_handle.client_id);
    IocReceive_Q1(&transaction_handle.sequence_counter);

    //transform data into DataType for server_operation
    for(int i = 0; i < len_args; i++){
        bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
        transformer_error = Xfrm_Inv_transformer(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, para_arr[i]);
        bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
        RTE_Dequeue(&RB_transformer_core1, (void*)&transformed_para_arr[i], sizeof(uint16));
    }

    //enqueue request queue on server side
    for(int i = 0; i < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); i++){
        if(Server_Runnable == rte_cs_metaData_arr[i].SR_RVuint16){
            for(int j = 0; j < len_args; j++){
                RTE_Enqueue(rte_cs_metaData_arr[i].RB_request_ptr, &transformed_para_arr[j], sizeof(uint16));
            }
            response = rte_cs_metaData_arr[i].SR_RVuint16();//do server operation, SR will get paras in its own request_queue
            break;
        }
    }

    //transform data into DataType for Rte_Enqueue the rte_internal_buffer
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    transformer_error = Xfrm_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    //send response information (response & sequence_counter).
    IocSend_Q1_SND1(transaction_handle.client_id);//for server_response.transaction_handle.client_id
    IocSend_Q1_SND1(transaction_handle.sequence_counter);//for server_response.transaction_handle.sequence_counter
    IocSend_Q1_SND1(transformed_response);//for server_response.response
    return transaction_handle.client_id;
}

static ResponseInfoType ioc_client_side(){
    uint16 transformed_response;
    Rte_Cs_TransactionHandleType transaction_handle;//for transformer stub.
    Std_ReturnType bsw_error = RTE_E_OK;
    ResponseInfoType response_info;
    IocReceive_Q1(&response_info.transaction_handle.client_id);
    IocReceive_Q1(&response_info.transaction_handle.sequence_counter);
    IocReceive_Q1(&response_info.response);
    
    bsw_error = Check_Transformer_Buffer(&RB_transformer_core1);
    uint8 transformer_error = Xfrm_Inv_transformer_2(&transaction_handle, &RB_transformer_core1, &RB_transformer_core1.currentSize, response_info.response);
    bsw_error = Check_Transformer_Error(transformer_error, bsw_error);
    RTE_Dequeue(&RB_transformer_core1, &transformed_response, sizeof(uint16));

    ResponseInfoType server_response = {
        bsw_error,
        response_info.transaction_handle,
        transformed_response
    };
    return server_response;
}

TASK(T11)
{
    PrintText("hello T11\r\n\0");

    //assumption: runnable can use only one Rte_call (becuase parser doesn't know how the user implements the runnable).
    int count = 1;
    //avoid the situation that a runnable of Task_A use Rte api to trigger a Rte event of another Task_B,
    //but Task_B has checked the Rte event before Task_A triggers it, and Task_B is still running.(may cause some triggerred RTE events be ignored)
    while(count){
        count = 0;
        for(int ev_t11_index =0; ev_t11_index<(sizeof(rte_event_t11)/sizeof(rte_event_t11[0]));ev_t11_index++){
            GetLock(&lock, lock_bit);
            uint8 ev_triggerred = get_rteevent_counter(rte_event_t11[ev_t11_index]);
            ReleaseLock(&lock, lock_bit);
            //task priority may cause the runnable pending(even if the rte_event is triggerred). Rte event may be triggerred multiple times, so we need to use "while-loop" to check rte_event_counter
            while(ev_triggerred){ //check if the event is triggered
                GetLock(&lock, lock_bit);
                uint8 ev_disablemode = get_rteevent_disablemode(rte_event_t11[ev_t11_index]);
                ReleaseLock(&lock, lock_bit);
                if(!(ev_disablemode)){ //check if the event can activate corresponding runnable
                    GetLock(&lock, lock_bit);
                    set_runnable_execute(rte_event_t11[ev_t11_index]);//set_runnable_execute before invoking the runnable
                    ReleaseLock(&lock, lock_bit);

                    switch (get_rteevent_type(rte_event_t11[ev_t11_index])){ //check RTEEvent type
                        case InitEvent:
                            //rte client side: send c/s request�C(All CRs that send the request should be put in a same task, or we don't where to activate those different tasks who include CRs)
                            if(get_trigger_runnable_type(rte_event_t11[ev_t11_index]) == ClientRunnable){
                                for(int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(rte_cs_metaData_arr[0]); metaData_arr_index++){
                                    if(rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16 == rte_event_t11[ev_t11_index]->Runnable_FuncPtr_RVuint16){ //RVuint16 is for testing, will be replaced by void in real case
                                        if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                            Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use sync_rte_call : wait for SR to unblock it
                                            if((ev_t11_index==0 && result == 8) || (ev_t11_index==1 && result == 8U) || (ev_t11_index==2 && result == 15U)){
                                                PrintText("success\r\n\0");
                                            }
                                        }else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                            rte_cs_metaData_arr[metaData_arr_index].CR_RVuint16(); // CR use async_rte_call : only send request
                                            if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == blocking){
                                                Impl_uint16 result = rte_cs_metaData_arr[metaData_arr_index].CRR_RVuint16(); // CRR use blocking_rte_result: wait for async_return_ev to unblock it
                                                if((ev_t11_index==0 && result == 8) || (ev_t11_index==1 && result == 8U) || (ev_t11_index==2 && result == 15U)){
                                                    PrintText("success\r\n\0");
                                                }
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        case OperationInvokedEvent:
                            /*server side: receive request_info, handle request, and send response_info*/
                            //server side task use while-loop to check rte_event_arr: Because there may be multiple runnable invoke same server-side runnable simultaneously.
                            //It's impossible that a same client runnable be called concurrently(SWS_Rte_02658: RTE shall allow only one request per client at any time)
                            uint16 client_id = -1;
                            switch(get_communication_type(rte_event_t11[ev_t11_index])){
                                case IntraPartition:
                                    client_id = rte_server_side(rte_event_t11[ev_t11_index]->Runnable_FuncPtr_RVuint16);//check error, call transformer, enqueue request queue, do operation, send response
                                    break;
                                case InterPartition:
                                    client_id = ioc_server_side(rte_event_t11[ev_t11_index]->Runnable_FuncPtr_RVuint16);
                                    break;
                                case InterEcu:
                                    /*com_server_side fn.*/
                                    break;
                            }
                            //the server_response got from server runnable still need data_processinng(transformer, check transaction_handle, enqueue responseQ...), so we can't trigger Async_return_ev in the api of SR.
                            for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){
                                if(rte_cs_metaData_arr[metaData_arr_index].client_id == client_id){
                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == sync){
                                        /*receive and handle response_info*/
                                        ResponseInfoType server_response;
                                        switch(get_communication_type(rte_event_t11[ev_t11_index])){
                                            case IntraPartition:
                                                server_response = rte_client_side();//check error, call transformer, dequeue response queue
                                                break;
                                            case InterPartition:
                                                server_response = ioc_client_side();
                                                break;
                                            case InterEcu:
                                                /*com client side fn.*/
                                                break;
                                        }
                                        RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)
                                        SetEvent(T01, event1);//unblock the CR who use sync_rte_call (sync_rte_call doesn't configure waitPoint, so we assume event1)
                                    }else if(rte_cs_metaData_arr[metaData_arr_index].rte_call_property == async){
                                        GetLock(&lock, lock_bit);
                                        trigger_rteevent(rte_cs_metaData_arr[metaData_arr_index].async_return_ev); //trigger async_return_ev to : unblock the CRR who use blocking_rte_result / activate the CRR who use non_blocking_rte_result
                                        ReleaseLock(&lock, lock_bit);
                                        if(rte_cs_metaData_arr[metaData_arr_index].SR_task != rte_cs_metaData_arr[metaData_arr_index].CRR_task){
                                            ActivateTask(rte_cs_metaData_arr[metaData_arr_index].CRR_task); //the task where client handle responseInfo
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        case AsynchronousServerCallReturnsEvent:
                            /*in async case, client side: receive and handle response_info*/
                            //AsynchronousServerCallReturnsEvent: tell a specific client that the response is ready, and [SWS_Rte_02658] says that "Before a request of the client is finished, the client can't send a new c/s request"
                            ResponseInfoType server_response;
                            switch(get_communication_type(rte_event_t11[ev_t11_index])){
                                case IntraPartition:
                                    server_response = rte_client_side();//check error, call transformer, dequeue response queue
                                    break;
                                case InterPartition:
                                    server_response = ioc_client_side();
                                    break;
                                case InterEcu:
                                    /*com client side fn.*/
                                    break;
                            }

                            for (int metaData_arr_index = 0; metaData_arr_index < sizeof(rte_cs_metaData_arr)/sizeof(Rte_Cs_metaData); metaData_arr_index++){
                                if(rte_cs_metaData_arr[metaData_arr_index].client_id == server_response.transaction_handle.client_id){
                                    RTE_Enqueue(rte_cs_metaData_arr[metaData_arr_index].RB_response_ptr, &server_response, sizeof(ResponseInfoType)); //RB_response_CRx: response Q of client_runnable_x (Sync server call point configuration)
                                    if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == blocking){
                                        SetEvent(T01, event1); //unblock the CRR who use blocking_rte_result
                                    }else if(rte_cs_metaData_arr[metaData_arr_index].rte_result_property == non_blocking){
                                        Impl_uint16 result = rte_event_t11[ev_t11_index]->Runnable_FuncPtr_RVuint16(); // activate the CRR who use non_blocking_rte_result
                                        if((ev_t11_index==0 && result == 8) || (ev_t11_index==1 && result == 8U) || (ev_t11_index==2 && result == 15U)){
                                            PrintText("success\r\n\0");
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        default:
                            //other 13 RTEEvent type case...
                            break;
                    }

                    GetLock(&lock, lock_bit);
                    clear_runnable_execute(rte_event_t11[ev_t11_index]);
                    ReleaseLock(&lock, lock_bit);
                }
                GetLock(&lock, lock_bit);
                release_rteevent(rte_event_t11[ev_t11_index]); //release the event
                ev_triggerred = get_rteevent_counter(rte_event_t11[ev_t11_index]);
                ReleaseLock(&lock, lock_bit);
                count++;
            }
        }
    }

    TerminateTask();
}