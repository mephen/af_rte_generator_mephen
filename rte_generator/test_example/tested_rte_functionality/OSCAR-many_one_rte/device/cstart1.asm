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
;	system stack
;-----------------------------------------------------------------------------
STACKSIZE	.set	0x400
	.section	"system_pe1_stack.bss", bss
	.align	4
	.ds	(STACKSIZE)
	.align	4
_stacktop:

;-----------------------------------------------------------------------------
;	section initialize table
;-----------------------------------------------------------------------------
	
	; --- legacy code vvv ---------------------------------
	; .section	".INIT_DSEC.PE1.const", const
	; .align	4
	; .dw	#__s.data,	#__e.data,	#__s.data.R

	; .section	".INIT_BSEC.PE1.const", const
	; .align	4
	; .dw	#__s.bss,	#__e.bss

	; .section	".INIT_DSEC.GLOBAL.const", const
	; .align	4
	; .dw	#__sGLOBAL_RAM_A.data,	#__eGLOBAL_RAM_A.data,	#__sGLOBAL_RAM_A.data.R

	; .section	".INIT_BSEC.GLOBAL.const", const
	; .align	4
	; .dw	#__sGLOBAL_RAM_A.bss,	#__eGLOBAL_RAM_A.bss
	; --- legacy code ^^^ ------------------------------------

	; .section	"OS_DATA_INIT_BLK", const
	; .align	4
	; .dw	#__s.data,	#__e.data,	#__s.data.R

	; .section	"OS_BSS_INIT_BLK", const
	; .align	4
	; .dw	#__s.bss,	#__e.bss

;-----------------------------------------------------------------------------
;	startup
;-----------------------------------------------------------------------------
	.section	".text", text
	.public	__cstart_pe1
	.align	2
__cstart_pe1:
	mov	#_stacktop, sp		;  set sp register
	mov	#__gp_data, gp		;  set gp register
	mov	#__ep_data, ep		;  set ep register
	
	jarl	__BoardInit_pe1, lp
	
	;; --- legacy code below ------------------------------------
	;jarl    __lowinit, lp  		; low level init

	; mov	#__sOS_DATA_INIT_BLK, r6
	; mov	#__eOS_DATA_INIT_BLK, r7
	; mov	#__sOS_BSS_INIT_BLK, r8
	; mov	#__eOS_BSS_INIT_BLK, r9
	; jarl32	__INITSCT_RH, lp	;  initialize RAM area

	; mov	#__s.INIT_DSEC.PE1.const, r6
	; mov	#__e.INIT_DSEC.PE1.const, r7
	; mov	#__s.INIT_BSEC.PE1.const, r8
	; mov	#__e.INIT_BSEC.PE1.const, r9
	; jarl32	__INITSCT_RH, lp	;  initialize RAM area

	; mov	#__s.INIT_DSEC.GLOBAL.const, r6
	; mov	#__e.INIT_DSEC.GLOBAL.const, r7
	; mov	#__s.INIT_BSEC.GLOBAL.const, r8
	; mov	#__e.INIT_BSEC.GLOBAL.const, r9
	; jarl32	__INITSCT_RH, lp	;  initialize RAM area
	;; --- legacy code ablove ------------------------------------

	mov 0, r6	;coreID is 0
	jarl    _InitRomToRamMemArea, lp	; initialize RAM area

	;; --- FPU code not in use below ------------------------------------
	; enable FPU, '0' is disable 
; $if 0 ; disable this block when not using FPU
; 	stsr	6, r10, 1	; r10 <- PID
; 	shl	21, r10
; 	shr	30, r10
; 	bz	.L1			; detecting FPU
; 	stsr	5, r10, 0		; r10 <- PSW
; 	movhi	0x0001, r0, r11
; 	or	r11, r10
; 	ldsr	r10, 5, 0		; enable FPU

; 	movhi	0x0002, r0, r11
; 	ldsr	r11, 6, 0		; initialize FPSR
; 	ldsr	r0, 7, 0		; initialize FPEPC
; .L1:
; $endif
	;; --- FPU code not in use above ------------------------------------

	; set various flags to PSW via FEPSW

	EI
	stsr	5, r10, 0		; r10 <- PSW
	;xori	0x0020, r10, r10	; enable interrupt
	;movhi	0x4000, r0, r11
	;or	r11, r10		; supervisor mode -> user mode
	ldsr	r10, 3, 0		; FEPSW <- r10
	mov	#_exit, lp		; lp <- #_exit
	mov	#_main_pe1, r10
	ldsr	r10, 2, 0		; FEPC <- #_main

	; apply PSW and PC to start user mode
	feret

_exit:
	br	_exit			;  end of program


