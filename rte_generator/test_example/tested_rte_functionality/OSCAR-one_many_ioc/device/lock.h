#ifndef LOCK_H
#define LOCK_H

#include "typedefine.h"

extern void GetLockAsm(uint8 *byte, uint8 bit);
extern void TryLockAsm(uint8 *byte, uint8 bit, uint32 *success);
extern void ReleaseLockAsm(uint8 *byte, uint8 bit);
void GetLock(uint8 *byte, uint8 bit);
void TryLock(uint8 *byte, uint8 bit, uint32 *success);
void ReleaseLock(uint8 *byte, uint8 bit);
#define LOCKBIT 0x1

#endif 