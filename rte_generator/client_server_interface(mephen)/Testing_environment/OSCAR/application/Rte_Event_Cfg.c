#include "Rte_Event_Cfg.h"

// RteEventStatus InitEvent_1 = {1,0,0};
// RteEventStatus InitEvent_2 = {1,0,0};
// RteEventStatus InitEvent_3 = {1,0,0};
// RteEventStatus* rte_event_t01[3] = {
//     /*InitEvents are initialized to 1 by Rte_Init*/
//     /*InitEvent_1_t01*/
//     &InitEvent_1,
//     /*InitEvent_2_t01*/
//     &InitEvent_2,
//     /*InitEvent_3_t01*/
//     &InitEvent_3
// };

// RteEventStatus OperationInvokedEvent_1 = {0,0,0};
// RteEventStatus OperationInvokedEvent_2 = {0,0,0};
// RteEventStatus* rte_event_t02[2] = {
//     /*OperationInvokedEvent_1_t02*/
//     &OperationInvokedEvent_1,
//     /*OperationInvokedEvent_2_t02*/
//     &OperationInvokedEvent_2
// };

// RteEventStatus AsynchronousServerCallReturnsEvent_1 = {0,0,0};
// RteEventStatus AsynchronousServerCallReturnsEvent_2 = {0,0,0};
// RteEventStatus AsynchronousServerCallReturnsEvent_3 = {0,0,0};
// RteEventStatus* rte_event_t03[3] = {
//     /*AsynchronousServerCallReturnsEvent_1_t03*/
//     &AsynchronousServerCallReturnsEvent_1,
//     /*AsynchronousServerCallReturnsEvent_2_t03*/
//     &AsynchronousServerCallReturnsEvent_2,
//     /*AsynchronousServerCallReturnsEvent_3_t03*/
//     &AsynchronousServerCallReturnsEvent_3
// };

// RteEventStatus OperationInvokedEvent_3 = {0,0,0};
// RteEventStatus* rte_event_t11[1] = {
//     /*OperationInvokedEvent_3_t11*/
//     &OperationInvokedEvent_3
// };



//test
#include "client_SWC/Rte_Client_Runnable.h"
#include "server_SWC/Rte_Server_Runnable.h"
#include "client_SWC/Rte_Client_Response_Runnable.h"
RteEvent InitEvent_1 = {(uint16)InitEvent+0x1, Client_1}; //+1 means triggered once
RteEvent InitEvent_2 = {(uint16)InitEvent+0x1, Client_2};
RteEvent* rte_event_t01[2] = {
    &InitEvent_1,
    &InitEvent_2,
};

// RteEvent AsynchronousServerCallReturnsEvent_1 = {(uint16)AsynchronousServerCallReturnsEvent+InterPartition, ClientResponse_1};
// RteEvent AsynchronousServerCallReturnsEvent_2 = {(uint16)AsynchronousServerCallReturnsEvent+InterPartition, ClientResponse_2};
// RteEvent* rte_event_t02[2] = {
//     &AsynchronousServerCallReturnsEvent_1,
//     &AsynchronousServerCallReturnsEvent_2,
// };

RteEvent OperationInvokedEvent_1 = {(uint16)OperationInvokedEvent+InterPartition, Server_1};
RteEvent OperationInvokedEvent_2 = {(uint16)OperationInvokedEvent+InterPartition, Server_1};
RteEvent* rte_event_t11[2] = {
    &OperationInvokedEvent_1,
    &OperationInvokedEvent_2
};