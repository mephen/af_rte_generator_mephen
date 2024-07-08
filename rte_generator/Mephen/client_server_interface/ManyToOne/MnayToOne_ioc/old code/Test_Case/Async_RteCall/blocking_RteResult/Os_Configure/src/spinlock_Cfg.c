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

/* This file content the generated implementation of os */

/*==================[inclusions]=============================================*/
#include "spinlock_Cfg.h"
#include "application_Cfg.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

#pragma section 

LockType SpinLockList[SPINLOCKS_COUNT];

SpinlockConstType SpinlockConst[SPINLOCKS_COUNT] = {
    /* spinlock1 */
    {
        spinlock1, /* spinlock id*/
        0 | (1 << app_lion) | (1 << app2), /* application mask */
        0 /* LOCK_NOTHING */
    },
    /* spinlock2 */
    {
        spinlock2, /* spinlock id*/
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), /* application mask */
        1 /* LOCK_ALL_INTERRUPTS */
    },
    /* spinlock6 */
    {
        spinlock6, /* spinlock id*/
        0 | (1 << app_lion) | (1 << app2), /* application mask */
        2 /* LOCK_CAT2_INTERRUPTS */
    },
    /* spinlock8 */
    {
        spinlock8, /* spinlock id*/
        0 | (1 << app_lion) | (1 << app2), /* application mask */
        3 /* LOCK_WITH_RES_SCHEDULER */
    },
    /* spinlock7 */
    {
        spinlock7, /* spinlock id*/
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), /* application mask */
        0 /* LOCK_NOTHING */
    },
    /* spinlock3 */
    {
        spinlock3, /* spinlock id*/
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), /* application mask */
        1 /* LOCK_ALL_INTERRUPTS */
    },
    /* spinlock5 */
    {
        spinlock5, /* spinlock id*/
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), /* application mask */
        2 /* LOCK_CAT2_INTERRUPTS */
    },
    /* spinlock4 */
    {
        spinlock4, /* spinlock id*/
        0 | (1 << app_lion) | (1 << app2) | (1 << app3) | (1 << app4), /* application mask */
        3 /* LOCK_WITH_RES_SCHEDULER */
    }
};

SpinlockVarType SpinlockVar[SPINLOCKS_COUNT] = {
    /* spinlock1 */
    {
        INVALID_SPINLOCK,
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock2 */
    {
        INVALID_SPINLOCK,
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock6 */
    {
        INVALID_SPINLOCK,
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock8 */
    {
        INVALID_SPINLOCK,
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock7 */
    {
        INVALID_SPINLOCK,
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock3 */
    {
        INVALID_SPINLOCK,
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock5 */
    {
        INVALID_SPINLOCK,
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock4 */
    {
        INVALID_SPINLOCK,
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    }
};

#pragma section

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*==================[end of file]============================================*/

