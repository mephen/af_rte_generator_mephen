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
#define InitEvent_4_t01 3

/*task T02*/
#define OperationInvokedEvent_1_t02 0
#define OperationInvokedEvent_2_t02 1

/*task T03*/
#define AsynchronousServerCallReturnsEvent_1_t03 0
#define AsynchronousServerCallReturnsEvent_2_t03 1
#define AsynchronousServerCallReturnsEvent_3_t03 2
#define AsynchronousServerCallReturnsEvent_4_t03 3

/*task T11*/
#define OperationInvokedEvent_3_t11 0
#define OperationInvokedEvent_4_t11 1

extern RteEventStatus* rte_event_t01[4];
extern RteEventStatus* rte_event_t02[2];
extern RteEventStatus* rte_event_t03[4];
extern RteEventStatus* rte_event_t11[2];

#endif//RTE_EVENT_CFG_H