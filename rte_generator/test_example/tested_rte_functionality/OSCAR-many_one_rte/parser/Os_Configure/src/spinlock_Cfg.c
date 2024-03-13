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
        0 | (1 << App1) | (1 << App2), /* application mask */
        0 /* LOCK_NOTHING */
    },
    /* spinlock2 */
    {
        spinlock2, /* spinlock id*/
        0 | (1 << App1) | (1 << App2), /* application mask */
        1 /* LOCK_ALL_INTERRUPTS */
    },
    /* spinlock6 */
    {
        spinlock6, /* spinlock id*/
        0 | (1 << App1) | (1 << App2), /* application mask */
        2 /* LOCK_CAT2_INTERRUPTS */
    },
    /* spinlock8 */
    {
        spinlock8, /* spinlock id*/
        0 | (1 << App1) | (1 << App2), /* application mask */
        3 /* LOCK_WITH_RES_SCHEDULER */
    },
    /* spinlock7 */
    {
        spinlock7, /* spinlock id*/
        0 | (1 << App1) | (1 << App2) | (1 << App3) | (1 << App4), /* application mask */
        0 /* LOCK_NOTHING */
    },
    /* spinlock3 */
    {
        spinlock3, /* spinlock id*/
        0 | (1 << App1) | (1 << App2) | (1 << App3) | (1 << App4), /* application mask */
        1 /* LOCK_ALL_INTERRUPTS */
    },
    /* spinlock5 */
    {
        spinlock5, /* spinlock id*/
        0 | (1 << App1) | (1 << App2) | (1 << App3) | (1 << App4), /* application mask */
        2 /* LOCK_CAT2_INTERRUPTS */
    },
    /* spinlock4 */
    {
        spinlock4, /* spinlock id*/
        0 | (1 << App1) | (1 << App2) | (1 << App3) | (1 << App4), /* application mask */
        3 /* LOCK_WITH_RES_SCHEDULER */
    },
};
SpinlockVarType SpinlockVar[SPINLOCKS_COUNT] = {
    /* spinlock1 */
    {
        {
            OBJECT_INVALID,
            0,
        },
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock2 */
    {
        {
            OBJECT_INVALID,
            0,
        },
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock6 */
    {
        {
            OBJECT_INVALID,
            0,
        },
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock8 */
    {
        {
            OBJECT_INVALID,
            0,
        },
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock7 */
    {
        {
            OBJECT_INVALID,
            0,
        },
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock3 */
    {
        {
            OBJECT_INVALID,
            0,
        },
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock5 */
    {
        {
            OBJECT_INVALID,
            0,
        },
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
    /* spinlock4 */
    {
        {
            OBJECT_INVALID,
            0,
        },
        OS_CORE_ID_INVALID,
        INVALID_TASK_ID
    },
};
#pragma section
/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*==================[end of file]============================================*/

