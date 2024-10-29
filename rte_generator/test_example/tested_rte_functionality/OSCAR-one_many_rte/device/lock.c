#include "lock.h"


#pragma inline_asm GetLock
void GetLock(uint8 *byte, uint8 bit)
{
	set1 r7, [r6]		//instruction  length 4 byte
	bz _GetLock + 0x0c		//instruction  length 2 byte
	snooze				//instruction  length 4 byte
	br _GetLock		//instruction  length 2 byte, SWS_Os_00649
}

#pragma inline_asm TryLock
void TryLock(uint8 *byte, uint8 bit, uint32 *success)
{
	set1 r7, [r6]		 	//instruction  length 4 byte
	bnz _TryLock + 0x0c	//instruction  length 2 byte
	set1 r0, [r8]           //instruction  length 4 byte, SWS_Os_00652
	br _TryLock + 0x10   //instruction  length 2 byte
	clr1 r0, [r8]           //instruction  length 4 byte
}

#pragma inline_asm ReleaseLock
void ReleaseLock(uint8 *byte, uint8 bit)
{
	clr1 r7, [r6]		//SWS_Os_00655
}


#pragma inline_asm GetLockAsm
void GetLockAsm(uint8 *byte, uint8 bit)
{
	set1 r7, [r6]		//intruction length 4 byte
	bz _GetLockAsm + 0x0c		//intruction length 2 byte
	snooze				//intruction length 4 byte
	br _GetLockAsm		//intruction length 2 byte, SWS_Os_00649
}

#pragma inline_asm TryLockAsm
void TryLockAsm(uint8 *byte, uint8 bit, uint32 *success)
{
	set1 r7, [r6]		 	//intruction length 4 byte
	bnz _TryLockAsm + 0x0c	//intruction length 2 byte
	set1 r0, [r8]           //intruction length 4 byte, SWS_Os_00652
	br _TryLockAsm + 0x10   //intruction length 2 byte
	clr1 r0, [r8]           //intruction length 4 byte
}

#pragma inline_asm ReleaseLockAsm
void ReleaseLockAsm(uint8 *byte, uint8 bit)
{
	clr1 r7, [r6]		//SWS_Os_00655
}