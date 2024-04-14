#ifndef RTE_EVENT_CFG_H
#define RTE_EVENT_CFG_H
#include "Rte_Type.h"

/*macro*/
/*Use macro instead of inㄤdex to access rte_event array*/
/*(when parsing arxml) according to the runnables that are mapped to task x, find the RTEEvents that task x can use*/
/*task T01*/
#define InitEvent_1_t01 0
#define InitEvent_2_t01 1
#define InitEvent_3_t01 2

/*task T02*/
#define OperationInvokedEvent_1_t02 0
#define OperationInvokedEvent_2_t02 1
#define AsynchronousServerCallReturnsEvent_1_t02 2
#define AsynchronousServerCallReturnsEvent_2_t02 3
#define AsynchronousServerCallReturnsEvent_3_t02 4

/*task T11*/
#define OperationInvokedEvent_3_t11 0

extern RteEventStatus* rte_event_t01[3];
extern RteEventStatus* rte_event_t02[5];
extern RteEventStatus* rte_event_t11[1];

#endif//RTE_EVENT_CFG_H