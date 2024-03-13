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

// extern Std_ReturnType errorFlag_Rte_Call_Port1_IntraPartitionSynchronousAdd;

// /*buffer*/
// //shared by all the client response runnables(Asyn case), client runnables(Sync case).
// extern RingBuffer Rte_response_RB_rte;
// extern RingBuffer Rte_parameter_RB_rte;
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

// Impl_uint16 transformer_buffer_rte[20];
// RingBuffer transformer_RB_rte = {
//     transformer_buffer_rte,
//     0,//point to oldest data
//     0,
//     20,
//     0
// };

// void rteCase_server_side(){
//     Impl_uint16 data_1;
//     Impl_uint16 data_2;
//     RTE_Dequeue(&Rte_parameter_RB_rte, (void*)&data_1, sizeof(Impl_uint16));
//     RTE_Dequeue(&Rte_parameter_RB_rte, (void*)&data_2, sizeof(Impl_uint16));    

//     /*call server runnable*/
//     Impl_uint16 server_response = Rte_Server_Runnable(data_1, data_2);

//     RTE_Enqueue(&Rte_response_RB_rte, (void*)&server_response, sizeof(Impl_uint16));
//     return;
// }

// void rteCase_client_side(){
//     Impl_uint16 server_response;
//     RTE_Dequeue(&Rte_response_RB_rte, (void*)&server_response, sizeof(Impl_uint16));

//     //put server response in RTE internal buffer, and sync Rte_call will fetch the server response from the buffer.
//     RTE_Enqueue(&Rte_response_RB_rte, (void*)&server_response, sizeof(Impl_uint16));
    
//     return;
// }


// #pragma section TASK_T001_SEC
// TASK(T01)
// {
//     ActivateTask(T02);

//     PrintText("T01 initiate a C/S op\r\n\0");
//     //WaitEvent(event1);
//     Impl_uint16 response = Rte_Client_Runnable_1();
//     if(response == 10U){
//         PrintText("success\r\n\0");
//     }

//     TerminateTask();
    
// }

// #pragma section TASK_T002_SEC
// TASK(T02)
// {
//     for(int i = 0; i <1000; i++){
//         ;
//     }
//     rteCase_server_side();

//     rteCase_client_side();
//     PrintText("T02 set event to wake up T01\r\n\0");
//     SetEvent(T01, event1);
//     TerminateTask();
// }

// #pragma section TASK_T003_SEC
// TASK(T03)
// {
//     //for timeout mechanism
//     //intra-partition doesn't need transformer
//     errorFlag_Rte_Call_Port1_IntraPartitionSynchronousAdd = RTE_E_TIMEOUT;
//     TerminateTask();
// }
