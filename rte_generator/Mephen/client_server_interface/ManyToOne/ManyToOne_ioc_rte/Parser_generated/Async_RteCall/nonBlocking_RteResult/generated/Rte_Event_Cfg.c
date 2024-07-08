#include "Rte_Event_Cfg.h"

#include "SWC_Client/Rte_SWC_Client.h"
#include "SWC_Server_1/Rte_SWC_Server_1.h"
#include "SWC_Server_2/Rte_SWC_Server_2.h"

//task T01
RteEvent InitEvent_1 = {(uint16)InitEvent+0x1, Client_1}; 
RteEvent InitEvent_2 = {(uint16)InitEvent+0x1, Client_2}; 
RteEvent InitEvent_3 = {(uint16)InitEvent+0x1, Client_3}; 
RteEvent* rte_event_t01[3] = {
    &InitEvent_1, 
    &InitEvent_2, 
    &InitEvent_3, 
};

//task T02
RteEvent OperationInvokedEvent_1 = {(uint16)OperationInvokedEvent+IntraPartition, Server1_SR1}; 
RteEvent OperationInvokedEvent_2 = {(uint16)OperationInvokedEvent+IntraPartition, Server1_SR1}; 
RteEvent AsynchronousServerCallReturnsEvent_1 = {(uint16)AsynchronousServerCallReturnsEvent+IntraPartition, Client_Response_1}; 
RteEvent AsynchronousServerCallReturnsEvent_2 = {(uint16)AsynchronousServerCallReturnsEvent+IntraPartition, Client_Response_2}; 
RteEvent AsynchronousServerCallReturnsEvent_3 = {(uint16)AsynchronousServerCallReturnsEvent+InterPartition, Client_Response_3}; 
RteEvent* rte_event_t02[5] = {
    &OperationInvokedEvent_1, 
    &OperationInvokedEvent_2, 
    &AsynchronousServerCallReturnsEvent_1, 
    &AsynchronousServerCallReturnsEvent_2, 
    &AsynchronousServerCallReturnsEvent_3, 
};

//task T11
RteEvent OperationInvokedEvent_3 = {(uint16)OperationInvokedEvent+InterPartition, Server2_SR1}; 
RteEvent* rte_event_t11[1] = {
    &OperationInvokedEvent_3, 
};
