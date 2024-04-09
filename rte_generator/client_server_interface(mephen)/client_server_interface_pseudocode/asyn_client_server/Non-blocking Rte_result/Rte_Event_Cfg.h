#ifndef Rte_Event_Cfg_H
#define Rte_Event_Cfg_H
#include "Rte_Type.h"

/*macro*/
/*use macro instead of index to access rte_event array*/
#define InitEvent_1 0
#define InitEvent_2 1
#define InitEvent_3 2
#define InitEvent_4 3
#define InitEvent_5 4
#define InitEvent_6 5

#define OperationInvokedEvent_1 6
#define OperationInvokedEvent_2 7
#define OperationInvokedEvent_3 8
#define OperationInvokedEvent_4 9
#define OperationInvokedEvent_5 10

#define AsynchronousServerCallReturnsEvent_1 11
#define AsynchronousServerCallReturnsEvent_2 12
#define AsynchronousServerCallReturnsEvent_3 13
#define AsynchronousServerCallReturnsEvent_4 14
#define AsynchronousServerCallReturnsEvent_5 15

typedef uint8 Rte_event_type;

extern uint8 rte_event[16];
#endif//Rte_Event_Cfg_H