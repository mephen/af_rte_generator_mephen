#include "core.h"
#include "dr7f701527.dvf.h"
#include "typedefine.h"
#include "task_Cfg.h"
#include "os_Cfg.h"
#include "board.h"

#define STARTUP_LOCK 0xFEF00000

#pragma inline_asm ReleaseCore_pe2
void ReleaseCore_pe2 (void) {
	add		-0x04, sp
	st.w	r20, 0[sp]
	mov 	STARTUP_LOCK, r20
	st.w 	r0, 0[r20]
	ld.w	0[sp], r20
	add		0x04, sp
}

void _StartCore(CoreIdType CoreID)
{
    switch (CoreID)
	{
	case OS_CORE_ID_0:
		//preBoardInit_pe1();
		//ReleaseCore_pe1();
		break;
	case OS_CORE_ID_1:
		preBoardInit_pe2();		//used to set the PE2-only interrupt
		ReleaseCore_pe2();		//release the lock in boot2.asm
		break;
	default:
		break;
	}
}

/* SWS_Os_00627 */
#pragma inline_asm GetPhyCoreID
CoreIdType GetPhyCoreID(void)
{
	stsr	0, r10, 2 	; get HTCFG0
	shr		16, r10		; get PEID
	add		-1, r10		
}

/* Request a interrupt to target core */
void InterruptToCore(CoreIdType CoreID)
{
	switch (CoreID)
	{
	case 0: /* PE1 */
		IPIR_CH0 |= 0x1; // Request interrupt to PE1
		break;
	case 1: /* PE2 */
		IPIR_CH0 |= 0x2; // Request interrupt to PE2
		break;
	}
	return;
}



// #pragma inline_asm SystemCall
// void SystemCall(uint32 Index)
// {
// 	syscall 2
// }

// CoreIdType _GetCoreID(void)
// {
// 	CoreIdType CoreId;
// 	__GetCoreID();

// 	return CoreId;
// }