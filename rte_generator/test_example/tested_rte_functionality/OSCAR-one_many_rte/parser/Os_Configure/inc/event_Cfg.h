#ifndef EVENT_CFG_H
#define EVENT_CFG_H
/* This file content the generated configuration of event */
/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "task_Cfg.h"
/*==================[macros]=================================================*/
/* Define the events */
/* brief Count of events */
#define EVENTS_COUNT 3

/* brief Definition of the Event event1 */
#define event1 0x0cULL
/* brief Definition of the Event event2 */
#define event2 0x03ULL
/* brief Definition of the Event event3 */
#define event3 0x07ULL
/*==================[external data declaration]==============================*/
extern EventsVarType EventsVar_core0[EXTENDED_TASKS_COUNT_CORE0];
extern EventsVarType EventsVar_core1[EXTENDED_TASKS_COUNT_CORE1];

/*==================[end of file]============================================*/
#endif /* #ifndef EVENT_CFG_H */
