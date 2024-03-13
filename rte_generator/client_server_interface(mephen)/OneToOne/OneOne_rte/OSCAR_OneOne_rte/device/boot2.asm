;   Copyright(c) 2013, 2016 Renesas Electronics Corporation
;   RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
;   This program must be used solely for the purpose for which
;   it was furnished by Renesas Electronics Corporation. No part of this
;   program may be reproduced or disclosed to others, in any
;   form, without the prior written permission of Renesas Electronics
;   Corporation.

;   NOTE       : THIS IS A TYPICAL EXAMPLE.
;   DATE       : Mon, Oct 24, 2016

;-----------------------------------------------------------------------------
;	exception vector table
;-----------------------------------------------------------------------------
	.section "RESET_PE2", text
	.align	512
	jr32	__start2 ; RESET

	.align	16
	syncp
	jr32	_Dummy_SYSERR ; SYSERR

	.align	16
	jr32	_Dummy_2

	.align	16
	jr32	_Dummy_FETRAP ; FETRAP ; might need handler

	.align	16
	jr32	_Dummy_TRAP0 ; TRAP0  ; might need handler

	.align	16
	jr32	_Dummy_TRAP1 ; TRAP1  ; might need handler

	.align	16
	jr32	_Dummy_RIE ; RIE    ;  execute an undefined opcode 

	.align	16
	syncp
	jr32	_Dummy_FPP_FPI ; FPP/FPI

	.align	16
	jr32	_Dummy_UCPOP ; UCPOP

	.align	16
	jr32	_MPU_FAULT_HANDLER ;_MPU_FAULT_HANDLER ; MIP/MDP aka. MPU fault

	.align	16
	jr32	_Dummy_PIE ; PIE    ; execute an instruction without required privilege.

	.align	16
	jr32	_Dummy_11

	.align	16
	jr32	_Dummy_MAE ; MAE    ; result of address calculation is a misaligned address

	.align	16
	jr32	_Dummy_13

	.align	16
	syncp
	jr32	_Dummy_FENMI ; FENMI

	.align	16
	syncp
	jr32	_Dummy_FEINT ; FEINT

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority0)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority1)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority2)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority3)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority4)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority5)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority6)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority7)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority8)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority9)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority10)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority11)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority12)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority13)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority14)

	.align	16
	syncp
	jr32	_Dummy_EI ; INTn(priority15)

	.section "EIINTTBL_PE2", const
	.align	512
	.dw	#_Dummy_EI ; INT0
	.dw	#_Dummy_EI ; INT1
	.dw	#_Dummy_EI ; INT2
	.rept	512 - 3
	.dw	#_Dummy_EI ; INTn
	.endm

	.section ".text", text
	.align	2

_Dummy:
	br	_Dummy

_Dummy_EI:
	br	_Dummy_EI

_Dummy_SYSERR:
    br _Dummy_SYSERR

_Dummy_2:
    br _Dummy_2

_Dummy_FETRAP:
    br _Dummy_FETRAP

_Dummy_TRAP0:
    br _Dummy_TRAP0

_Dummy_TRAP1:
    br _Dummy_TRAP1

_Dummy_RIE:
    br _Dummy_RIE

_Dummy_FPP_FPI:
    br _Dummy_FPP_FPI

_Dummy_UCPOP:
    br _Dummy_UCPOP

_AHA_MPU:
    br _AHA_MPU_hander

_Dummy_PIE:
    br _Dummy_PIE

_Dummy_11:
    br _Dummy_11

_Dummy_MAE:
    br _Dummy_MAE

_Dummy_13:
    br _Dummy_13

_Dummy_FENMI:
    br _Dummy_FENMI

_Dummy_FEINT:
    br _Dummy_FEINT

_SYSCALL_ERR_TEST:
    br  _SYSCALL_ERR_TEST
	
;-------------------- end of start up module -------------------;

__start2:
	STARTUP_LOCK	.set	0xFEF00000
	mov STARTUP_LOCK, r20
	mov 1, r21
	st.w r21, [r20]
_LOCK:
	ldl.w [r20], r21
	cmp r0, r21
	bnz _LOCK_wait
	mov 1, r21
	stc.w r21, [r20]
	cmp r0, r21
	bnz _LOCK_success
_LOCK_wait:
	snooze
	br _LOCK
_LOCK_success:
    jr32 __start
