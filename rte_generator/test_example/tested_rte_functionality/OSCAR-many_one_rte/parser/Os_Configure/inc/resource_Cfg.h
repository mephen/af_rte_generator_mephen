#ifndef RESOURCE_CFG_H
#define RESOURCE_CFG_H
/* This file content the generated configuration of resource */
/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "application_Cfg.h"
/*==================[macros]=================================================*/


#define RES_SCHEDULER ((0x00000000))
/* brief Definition of the standard resource resource1 */
#define resource1 ((ResourceType)0x00000000)

/* brief Definition of the standard resource resource2 */
#define resource2 ((ResourceType)0x00000001)

/* brief Definition of the standard resource resource3 */
#define resource3 ((ResourceType)0x00000002)

/* brief Definition of the standard resource resource4 */
#define resource4 ((ResourceType)0x00010000)

/* brief Definition of the standard resource resource5 */
#define resource5 ((ResourceType)0x00010001)

/* brief Definition of the standard resource resource6 */
#define resource6 ((ResourceType)0x00010002)

#define resourceApp1 ((ResourceType)0x00000003)

#define resourceApp2 ((ResourceType)0x00010003)

#define resourceApp3 ((ResourceType)0x00000004)

#define resourceApp4 ((ResourceType)0x00010004)

/* brief Count of resources */
/* the count includes RES_SCHEDULER if the oil set it 'true'*/
#define RESOURCES_COUNT_CORE0 5
#define RESOURCES_COUNT_CORE1 5
#define RESOURCES_COUNT 10

/* brief Count of internal resources */
#define INTERNAL_RESOURCES_COUNT_CORE0 0
#define INTERNAL_RESOURCES_COUNT_CORE1 0
#define INTERNAL_RESOURCES_COUNT 0


/*==================[external data declaration]==============================*/
/*
    Brief Resource Variable on core 0
    Contents all variables needed to manage all resources
*/
extern ResourceVarType ResourceVar_core0[RESOURCES_COUNT_CORE0];
/* brief Resources Priorities */
extern const TaskPriorityType ResourcesPriority_core0[RESOURCES_COUNT_CORE0];

/*
    Brief Resource Variable on core 1
    Contents all variables needed to manage all resources
*/
extern ResourceVarType ResourceVar_core1[RESOURCES_COUNT_CORE1];
/* brief Resources Priorities */
extern const TaskPriorityType ResourcesPriority_core1[RESOURCES_COUNT_CORE1];

/* There is no defined internal resource */

/* There is no defined internal resource */

/* brief Accessible App of Counter */
extern ResourceAutosarType ResourceAutosar_core0[RESOURCES_COUNT_CORE0];
extern ResourceAutosarType ResourceAutosar_core1[RESOURCES_COUNT_CORE1];

/*==================[end of file]============================================*/
#endif /* #ifndef RESOURCE_CFG_H */
