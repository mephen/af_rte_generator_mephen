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
	.section	"system_pe2_stack.bss", bss
	.align	4
	.ds	(STACKSIZE)
	.align	4
_stacktop2:

;-----------------------------------------------------------------------------
;	section initialize table
;-----------------------------------------------------------------------------

	; --- legacy code below ------------------------------------
	; .section	".INIT_DSEC.PE2.const", const
	; .align	4
	; .dw	#__sLOCAL_RAM_PE2.data,		#__eLOCAL_RAM_PE2.data,		#__sLOCAL_RAM_PE2.data.R

	; .section	".INIT_BSEC.PE2.const", const
	; .align	4
	; .dw	#__sLOCAL_RAM_PE2.bss,		#__eLOCAL_RAM_PE2.bss
	; --- legacy code above ------------------------------------

;-----------------------------------------------------------------------------
;	startup
;-----------------------------------------------------------------------------
	.section	".text", text
	.public	__cstart_pe2
	.align	2
__cstart_pe2:
	mov	#_stacktop2, sp		;  set sp register
	mov	#__gp_data, gp		;  set gp register
	mov	#__ep_data, ep		;  set ep register
	
	;jarl    __lowinit, lp  		; low level init
	jarl	__BoardInit_pe2, lp
	
	;; --- legacy code below ------------------------------------
	; mov	#__s.INIT_DSEC.PE2.const, r6
	; mov	#__e.INIT_DSEC.PE2.const, r7
	; mov	#__s.INIT_BSEC.PE2.const, r8
	; mov	#__e.INIT_BSEC.PE2.const, r9
	; jarl32	__INITSCT_RH, lp	;  initialize RAM area
	;; --- legacy code above ------------------------------------

	mov 1, r6	;coreID is 1
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
	mov	#_main_pe2, r10
	ldsr	r10, 2, 0		; FEPC <- #_main

	; apply PSW and PC to start user mode
	feret

_exit:
	br	_exit			;  end of program


