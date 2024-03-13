#ifndef SPINLOCK_CFG_H
#define SPINLOCK_CFG_H
/* This file content the generated configuration of task */
/*==================[inclusions]=============================================*/
#include "typedefine.h"
/*==================[macros]=================================================*/
#define SPINLOCKS_COUNT 8
#define spinlock1 0
#define spinlock2 1
#define spinlock6 2
#define spinlock8 3
#define spinlock7 4
#define spinlock3 5
#define spinlock5 6
#define spinlock4 7
#define INVALID_SPINLOCK 8
/*==================[external data declaration]=========================*/
extern LockType SpinLockList[SPINLOCKS_COUNT];

extern SpinlockConstType SpinlockConst[SPINLOCKS_COUNT];

extern SpinlockVarType SpinlockVar[SPINLOCKS_COUNT];

/*==================[external functions declaration]=========================*/
/*==================[end of file]============================================*/
#endif /* #ifndef SPINLOCK_CFG_H */
