#ifndef RTE_EVENT_CFG_H
#define RTE_EVENT_CFG_H
#include "Rte_Type.h"

/*macro*/
/*Use macro instead of inㄤdex to access rte_event array*/
/*(when parsing arxml) according to the runnables that are mapped to task x, find the RTEEvents that task x can use*/
/*task T01*/
#define OperationInvokedEvent_2_t01 0

extern RteEventStatus* rte_event_t01[1];

#endif//RTE_EVENT_CFG_H