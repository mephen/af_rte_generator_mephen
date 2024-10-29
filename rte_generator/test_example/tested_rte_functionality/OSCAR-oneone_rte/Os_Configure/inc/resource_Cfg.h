/********************************************************
 * DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
 ********************************************************/

/* Copyright 2008, 2009 Mariano Cerdeiro
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

#ifndef RESOURCE_CFG_H
#define RESOURCE_CFG_H

/* This file content the generated configuration of resource */

/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "application_Cfg.h"
/*==================[macros]=================================================*/
#define RES_SCHEDULER ((0x00000000))
/* brief Definition of the resource resource1 */
#define resource1 ((ResourceType)0x00000000)
/* brief Definition of the resource resource2 */
#define resource2 ((ResourceType)0x00000001)
/* brief Definition of the resource resource3 */
#define resource3 ((ResourceType)0x00000002)

/* App resource */
/* brief Definition of the resource resourceApp1 */
#define resourceApp1 ((ResourceType)0x00000003)
/* brief Definition of the resource resourceApp1 */
#define resourceApp3 ((ResourceType)0x00000004)



/* brief Definition of the resource resource4 */
#define resource4 ((ResourceType)0x00010000)
/* brief Definition of the resource resource5 */
#define resource5 ((ResourceType)0x00010001)
/* brief Definition of the resource resource6 */
#define resource6 ((ResourceType)0x00010002)

/* App resource */
/* brief Definition of the resource resourceApp1 */
#define resourceApp2 ((ResourceType)0x00010003)
/* brief Definition of the resource resourceApp1 */
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

/* brief Accessible App of Counter */
extern ResourceAutosarType ResourceAutosar_core0[RESOURCES_COUNT_CORE0];
extern ResourceAutosarType ResourceAutosar_core1[RESOURCES_COUNT_CORE1];

/*==================[end of file]============================================*/
#endif /* #ifndef RESOURCE_CFG_H */
