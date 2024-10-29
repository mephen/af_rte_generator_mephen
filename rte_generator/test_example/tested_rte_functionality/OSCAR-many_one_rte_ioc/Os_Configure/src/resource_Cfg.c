/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009, 2014, 2015 Mariano Cerdeiro
 * Copyright 2014, ACSE & CADIEEL
 *      ACSE: http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *      CADIEEL: http://www.cadieel.org.ar
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* This file content the generated implementation of resource */

/*==================[inclusions]=============================================*/
#include "resource_Cfg.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
/* FreeOSEK to configured priority table
 *
 * This table show the relationship between the user selected
 * priorities and the OpenOSE priorities:
 *
 * Osek Priority start from 1.
 * Osek P 0 is for idle task.
 *
 * User P.         Osek P.
 * 5               3
 * 3               2
 * 1               1
 */

#pragma section
/* brief Resources Priorities */
const TaskPriorityType ResourcesPriority_core0[RESOURCES_COUNT_CORE0]  = {
    3,
    3,
    3,
    3,
    3,
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
        resourceApp1,                    /* id */
    },
    /* Sys resource resourceApp1 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resourceApp3 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceApp3,                    /* id */
    },
};

const TaskPriorityType ResourcesPriority_core1[RESOURCES_COUNT_CORE1]  = {
    3,
    3,
    3,
    3,
    3,
};

/* Brief ResourceVar Array */
ResourceVarType ResourceVar_core1[RESOURCES_COUNT_CORE1] = {
    /* General resource resource1 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core1[(resource4 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource4,                    /* id */
    },
    /* General resource resource2 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core1[(resource5 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resource5,                    /* id */
    },
    /* General resource resource3 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core1[(resource6 & 0xffff)], /* celingPriority */
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
        resourceApp2,                    /* id */
    },
    /* Sys resource resourceApp4 */
    {
        NULL,                         /* NextResource pointer */
        &ResourcesPriority_core0[(resourceApp4 & 0xffff)], /* celingPriority */
        0,                            /* previousPriority */
        0,                            /* owner */
        resourceApp4,                    /* id */
    },
};

ResourceAutosarType ResourceAutosar_core0[RESOURCES_COUNT_CORE0] = {
    /* Resource resource1 */
    {
        0 | (1 << app_lion) | (1 << app3) /* application mask */
    },
    /* Resource resource2 */
    {
        0 | (1 << app_lion) | (1 << app3)  /* application mask */
    },
    /* Resource resource3 */
    {
        0 | (1 << app_lion) | (1 << app3)  /* application mask */
    },
    /* Resource resourceApp1 */
    {
        0 | (1 << app_lion)  | (1 << app3)  /* application mask */
    },
    /* Resource resourceApp3 */
    {
        0 | (1 << app_lion) | (1 << app3)  /* application mask */
    },
};

ResourceAutosarType ResourceAutosar_core1[RESOURCES_COUNT_CORE1] = {
    /* Resource resource4 */
    {
        0 | (1 << app2) | (1 << app4) /* application mask */
    },
    /* Resource resource5 */
    {
        0 | (1 << app2) | (1 << app4) /* application mask */
    },
    /* Resource resource6 */
    {
        0 | (1 << app2) | (1 << app4) /* application mask */
    },
    /* Resource resourceApp2 */
    {
        0 | (1 << app2) | (1 << app4)  /* application mask */
    },
    /* Resource resourceApp4 */
    {
        0 | (1 << app2) | (1 << app4)  /* application mask */
    },
};

#pragma section


/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*==================[end of file]============================================*/

