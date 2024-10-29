#ifndef SPINLOCK_H
#define SPINLOCK_H

#include "typedefine.h"

#define LOCK_NOTHING ((LockMethodType)0U)
#define LOCK_ALL_INTERRUPTS ((LockMethodType)1U)
#define LOCK_CAT2_INTERRUPTS ((LockMethodType)2U)
#define LOCK_WITH_RES_SCHEDULER ((LockMethodType)3U)

StatusType GetSpinlock(SpinlockIdType SpinlockId);
StatusType ReleaseSpinlock(SpinlockIdType SpinlockId);
StatusType TryToGetSpinlock(SpinlockIdType SpinlockId, TryToGetSpinlockType* Success);

StatusType SysGetSpinlock(SpinlockIdType SpinlockId);
StatusType SysReleaseSpinlock(SpinlockIdType SpinlockId);
StatusType SysTryToGetSpinlock(SpinlockIdType SpinlockId, TryToGetSpinlockType* Success);


#endif