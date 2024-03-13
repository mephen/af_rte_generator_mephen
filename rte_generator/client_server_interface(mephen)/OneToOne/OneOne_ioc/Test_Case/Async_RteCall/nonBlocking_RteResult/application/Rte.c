// //app1.c
// #include "iodefine.h"
// #include "board.h"
// #include "os.h"
// #include "timer.h"
// #include "os_Cfg.h"
// #include "task_Cfg.h"
// #include "event_Cfg.h"
// #include "alarm_Cfg.h"
// #include "application_Cfg.h"
// #include "counter.h"
// #include "alarm.h"
// #include "task.h"
// #include "isr2.h"
// #include "event.h"
// #include "memsection.h"
// #include "memprot_Cfg.h"
// #include "string_format_test.h"
// #include "systemcall.h"
// #include "application.h"
// #include "ISRInit.h"
// #include "isr_Cfg.h"
// #include "spinlock.h"
// #include "resource.h"
// #include "memsection.h"
// #include "trustedFunc_Cfg.h"
// #include "ioc.h"
// #include "lock.h"
// #include "client_SWC/Rte_Client_Runnable.h"
// #include "client_SWC/Rte_Client_ResponseRunnable.h"
// #include "server_SWC/Rte_Server_Runnable.h"

// extern int PrintText(char *TextArray);
// extern int PrintText_R35(char *TextArray);

// /************* USER_SHARED_SEC *****************/
// #pragma section USER_SHARED_SEC

// extern int PrintText(char *TextArray);
// extern int PrintText_R35(char *TextArray);

// extern Std_ReturnType errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking;

// /*buffer*/
// //shared by all the client response runnables(Asyn case), client runnables(Sync case).
// extern RingBuffer Rte_response_RB_ioc;

// //in Async case, this can be used to help client response runnable
// Std_ReturnType previous_RteCall_returnValue_buffer[10];
// RingBuffer previous_RteCall_returnValue_RB = {
//     previous_RteCall_returnValue_buffer,
//     0,
//     0,
//     10,
//     0
// };
// //for RTE to ensure the order of client requests on the server side
// Rte_Cs_TransactionHandleType Rte_request_buffer[10];
// RingBuffer Rte_request_RB = {
//     Rte_request_buffer,
//     0,
//     0,
//     10,
//     0
// };
// Impl_uint16 transformer_buffer_ioc[20];
// RingBuffer transformer_RB_ioc = {
//     transformer_buffer_ioc,
//     0,//point to oldest data
//     0,
//     20,
//     0
// };

// int check_RTE_E_TRANSFORMER_LIMIT(RingBuffer* rb, Std_ReturnType* errorFlag){
//     if(IsFull(rb)){
//         *errorFlag = RTE_E_TRANSFORMER_LIMIT;
//         return 1;
//     }
//     return 0;
// }

// int check_RTE_TRANSFORMER_ERROR(RingBuffer* rb, uint8 transformer_error_code, Std_ReturnType* errorFlag){
//     int true_false = 0;
//     //in the priority rule of Rte_result: RTE_E_TRANSFORMER_LIMIT > RTE_E_HARD_TRANSFORMER_ERROR > RTE_E_SOFT_TRANSFORMER_ERROR
//     if(*errorFlag != RTE_E_TRANSFORMER_LIMIT){
//         if(transformer_error_code >= 0x01 && transformer_error_code <= 0x7F){
//             //soft transformer error won't cause immediate return
//             *errorFlag = RTE_E_SOFT_TRANSFORMER_ERROR;
//             true_false = 1;
//         }else if(transformer_error_code >= 0x80 && transformer_error_code <= 0xFF){
//             *errorFlag = RTE_E_HARD_TRANSFORMER_ERROR;
//             true_false = 1;
//         }
//     }
//     return true_false;
// }

// void iocCase_client_side(){
//     uint8 server_response;
//     StatusType ioc_error_code = IocReceive_aa(&server_response);
//     Rte_Cs_TransactionHandleType transaction_handle; //for transformer stub.

//     /*transform received data, and fetch parameters form RTE buffer*/
//     check_RTE_E_TRANSFORMER_LIMIT(&transformer_RB_ioc, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking);
//     uint8 transformer_error_code = Xfrm_Inv_transformer_2_ioc(&transaction_handle, &transformer_RB_ioc, &transformer_RB_ioc.currentSize, server_response);
//     check_RTE_TRANSFORMER_ERROR(&transformer_RB_ioc, transformer_error_code, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking);
//     Impl_uint16 server_response_transformed;
//     RTE_Dequeue(&transformer_RB_ioc, (void*)&server_response_transformed, sizeof(Impl_uint16));

//     //put server response in RTE internal buffer, and Rte_result will fetch the server response from the buffer.
//     RTE_Enqueue(&Rte_response_RB_ioc, (void*)&server_response_transformed, sizeof(Impl_uint16));

//     Std_ReturnType previous_RteCall_returnValue;
//     RTE_Dequeue(&previous_RteCall_returnValue_RB, (void*)&previous_RteCall_returnValue, sizeof(Std_ReturnType));
//     //call the client response runnable
//     Impl_uint16 get_by_RteResult = Rte_Client_ResponseRunnable_1(previous_RteCall_returnValue);
//     if(get_by_RteResult == server_response_transformed){
//         PrintText("success\r\n\0");
//     }
//     return;
// }

// #pragma section TASK_T001_SEC
// uint32 temp1 = 10;
// TASK(T01)
// {
//     PrintText("T01 initiate a C/S op\r\n\0");
//     Rte_Cs_TransactionHandleType transaction_handle = Rte_Client_Runnable_1();
//     RTE_Enqueue(&Rte_request_RB, (void*)&transaction_handle, sizeof(Rte_Cs_TransactionHandleType));
//     RTE_Enqueue(&previous_RteCall_returnValue_RB, (void*)&transaction_handle.Async_rteCall_returnValue, sizeof(Std_ReturnType));

//     ActivateTask(T11);
//     TerminateTask();
// }

// #pragma section TASK_T002_SEC
// int T02_Global = 0;
// TASK(T02)
// {
//     for(int i = 0; i <10000; i++){
//         ;
//     }
//     PrintText("T02 do things after T11 send the server response\r\n\0");
//     iocCase_client_side();

//     TerminateTask();
// }

// #pragma section TASK_T003_SEC
// TASK(T03)
// {
//     //for timeout mechanism
//     errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking = RTE_E_TIMEOUT;
//     TerminateTask();
// }

// //------------------------------------------------------------------------------
// //app2.c
// #include "iodefine.h"
// #include "board.h"
// #include "os.h"
// #include "os_Cfg.h"
// #include "task_Cfg.h"
// #include "event_Cfg.h"
// #include "alarm_Cfg.h"
// #include "application_Cfg.h"
// #include "event.h"
// #include "task.h"
// #include "memsection.h"
// #include "memprot_Cfg.h"
// #include "string_format_test.h"
// #include "ISRInit.h"
// #include "systemcall.h"
// #include "application.h"
// #include "trustedFunc_Cfg.h"
// #include "ioc.h"
// #include "lock.h"
// #include "client_SWC/Rte_Client_Runnable.h"
// #include "client_SWC/Rte_Client_ResponseRunnable.h"
// #include "server_SWC/Rte_Server_Runnable.h"


// extern int PrintText(char *TextArray);
// extern int PrintText_R35(char *TextArray);

// /************* USER_SHARED_SEC *****************/
// #pragma section USER_SHARED_SEC

// extern Std_ReturnType errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking;

// /*buffer*/
// extern RingBuffer Rte_request_RB;
// Impl_uint16 transformer_buffer_ioc_2[20];
// RingBuffer transformer_RB_ioc_2 = {
//     transformer_buffer_ioc_2,
//     0,//point to oldest data
//     0,
//     20,
//     0
// };

// extern int check_RTE_E_TRANSFORMER_LIMIT(RingBuffer* rb, Std_ReturnType* errorFlag);
// extern int check_RTE_TRANSFORMER_ERROR(RingBuffer* rb, uint8 transformer_error_code, Std_ReturnType* errorFlag);

// void iocCase_server_side(){
//     uint8 data_1;
//     uint8 data_2;
//     StatusType ioc_error_code = IocReceive_aa(&data_1);
//     ioc_error_code = IocReceive_aa(&data_2);
    
//     Rte_Cs_TransactionHandleType transaction_handle; //for transformer stub.
//     /*transform received data, and fetch parameters form RTE buffer*/
//     check_RTE_E_TRANSFORMER_LIMIT(&transformer_RB_ioc_2, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking);
//     uint8 transformer_error_code = Xfrm_Inv_transformer_ioc(&transaction_handle, &transformer_RB_ioc_2, &transformer_RB_ioc_2.currentSize, data_1);
//     check_RTE_TRANSFORMER_ERROR(&transformer_RB_ioc_2, transformer_error_code, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking);
//     Impl_uint16 data_1_transformed;
//     RTE_Dequeue(&transformer_RB_ioc_2, (void*)&data_1_transformed, sizeof(Impl_uint16));

//     check_RTE_E_TRANSFORMER_LIMIT(&transformer_RB_ioc_2, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking);
//     transformer_error_code = Xfrm_Inv_transformer_ioc(&transaction_handle, &transformer_RB_ioc_2, &transformer_RB_ioc_2.currentSize, data_2);
//     check_RTE_TRANSFORMER_ERROR(&transformer_RB_ioc_2, transformer_error_code, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking);
//     Impl_uint16 data_2_transformed;
//     RTE_Dequeue(&transformer_RB_ioc_2, (void*)&data_2_transformed, sizeof(Impl_uint16));

//     /*call server runnable*/
//     Impl_uint16 server_response = Rte_Server_Runnable(data_1_transformed, data_2_transformed);

//     /*transform server response*/
//     check_RTE_E_TRANSFORMER_LIMIT(&transformer_RB_ioc_2, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking);
//     transformer_error_code = Xfrm_transformer_2_ioc(&transaction_handle, &transformer_RB_ioc_2, &transformer_RB_ioc_2.currentSize, server_response);
//     check_RTE_TRANSFORMER_ERROR(&transformer_RB_ioc_2, transformer_error_code, &errorFlag_Rte_Result_Port1_InterPartitionAsynchronousAdd_NonBlocking);
//     uint8 server_response_transformed;
//     RTE_Dequeue(&transformer_RB_ioc_2, (void*)&server_response_transformed, sizeof(uint8));

//     ioc_error_code = IocSend_aa((int)server_response_transformed);
//     return;
// }

// #pragma section TASK_T101_SEC
// TASK(T11)
// {
//     for(int i = 0; i <10000; i++){
//         ;
//     }
    
//     PrintText("T11 do things after T01 initiate a C/S op\r\n\0");
//     Rte_Cs_TransactionHandleType transaction_handle;
//     RTE_Dequeue(&Rte_request_RB, &transaction_handle, sizeof(Rte_Cs_TransactionHandleType));
//     switch(transaction_handle.communication_type){
//         case 1: //com
//             break;
//         case 2: //ioc
//             iocCase_server_side();
//             break;
//         case 3: //rte
//             break;
//         default:
//             PrintText("undefined communication type\r\n\0");
//             break;
//     }

//     ActivateTask(T02);//activate client side task
//     TerminateTask();
// }

// #pragma section TASK_T102_SEC
// TASK(T12)
// {
// }

// #pragma section TASK_T103_SEC
// TASK(T13)
// {
// }