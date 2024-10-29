#include "resource_Cfg.h"
/* brief Resources Priorities */
const TaskPriorityType ResourcesPriority_core0[RESOURCES_COUNT_CORE0] = {
    5,
    5,
    5,
    5,
    5,
};

/* Brief ResourceVar Array */
ResourceVarType ResourceVar_core0[RESOURCES_COUNT_CORE0] = {

    /* General resource resource1 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resource1 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource1,                    /* id */
    },
    /* General resource resource2 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resource2 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource2,                    /* id */
    },
    /* General resource resource3 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resource3 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource3,                    /* id */
    },
    /* Sys resource resourceApp1 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resourceApp1 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceApp1                            /* id */
    },
    /* Sys resource resourceApp3 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resourceApp3 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceApp3                            /* id */
    },
};

/* brief Resources Priorities */
const TaskPriorityType ResourcesPriority_core1[RESOURCES_COUNT_CORE1] = {
    3,
    3,
    3,
    3,
    3,
};

/* Brief ResourceVar Array */
ResourceVarType ResourceVar_core1[RESOURCES_COUNT_CORE1] = {

    /* General resource resource4 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority1[(resource4 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource4,                    /* id */
    },
    /* General resource resource5 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority1[(resource5 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource5,                    /* id */
    },
    /* General resource resource6 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority1[(resource6 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource6,                    /* id */
    },
    /* Sys resource resourceApp2 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resourceApp2 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceApp2                            /* id */
    },
    /* Sys resource resourceApp4 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resourceApp4 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceApp4                            /* id */
    },
};

ResourceAutosarType ResourceAutosar_core0[RESOURCES_COUNT_CORE0] = {
    /* Resource resource1 */
    {
        0 | (1 << App1) | (1 << App3) 
    },
    /* Resource resource2 */
    {
        0 | (1 << App1) | (1 << App3) 
    },
    /* Resource resource3 */
    {
        0 | (1 << App1) | (1 << App3) 
    },
    /* Resource resourceApp1 */
    {
        0 | (1 << App1) | (1 << App3) 
    },
    /* Resource resourceApp3 */
    {
        0 | (1 << App1) | (1 << App3) 
    },
};

ResourceAutosarType ResourceAutosar_core1[RESOURCES_COUNT_CORE1] = {
    /* Resource resource4 */
    {
        0 | (1 << App2) | (1 << App4) 
    },
    /* Resource resource5 */
    {
        0 | (1 << App2) | (1 << App4) 
    },
    /* Resource resource6 */
    {
        0 | (1 << App2) | (1 << App4) 
    },
    /* Resource resourceApp2 */
    {
        0 | (1 << App2) | (1 << App4) 
    },
    /* Resource resourceApp4 */
    {
        0 | (1 << App2) | (1 << App4) 
    },
};

#pragma section
