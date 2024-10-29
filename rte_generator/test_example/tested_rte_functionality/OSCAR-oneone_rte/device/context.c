#include "context.h"
#include "scheduler.h"
#include "os.h"
#include "os_Cfg.h"
#include "system.h"

#define PSWCU2_1 0x10000
#define PSWUM 0x40000000

#pragma inline_asm SaveContext
void SaveContext (void) {
	stsr	0, r1, 2 				;get coreID
	shr		16, r1
	cmp		2, r1
	bz		_save_pe2				;_SaveContext+0x12
	mov     #_CurrentTask_core0, r1	;get OSKernel for pe1
	br 		_get_flag				;_SaveContext+0x18
_save_pe2:
	mov 	#_CurrentTask_core1, r1	;get OSKernel for pe2
_get_flag:
	ld.w	12[r1],r2               ;get needSaveContext flag of current task
	cmp     0x0, r2	                ;check value of needSaveContext flag
	;ld.w	0[r1], r2               ;get CurrentConst
	;ld.w	4[r2], r1               ;get context of current task
	bnz     _need_save       		;if needSaveContext not equals to zero, skip "jarl _SchedulerKernelISR" instruction
	;jmp     [lp]                   ;if needSaveContext equals to 0, return to ScheduleKernelISR
	jarl	_to_scheduler, lp 		;if needSaveContext equals to 0, jump to ScheduleKernelISR  _ScheduleKernelISR+0x32
_need_save:
	ld.w	0[r1], r2               ;get CurrentConst
	ld.w	4[r2], r1               ;get context of current task
	stsr	0, r2                   ;save eipc
	st.w	r2, 8[r1]	
	stsr    1, r2                   ;save eipsw
	st.w	r2, 12[r1]
	st.w	r4, 24[r1]              ;save general purpose registers
	st.w	r5, 28[r1]
	st.w	r6, 32[r1]
	st.w	r7, 36[r1]
	st.w	r8, 40[r1]
	st.w	r9, 44[r1]
	st.w	r10, 48[r1]
	st.w	r11, 52[r1]
	st.w	r12, 56[r1]
	st.w	r13, 60[r1]
	st.w	r14, 64[r1]
	st.w	r15, 68[r1]
	st.w	r16, 72[r1]
	st.w	r17, 76[r1]
	st.w	r18, 80[r1]
	st.w	r19, 84[r1]
	st.w	r20, 88[r1]
	st.w	r21, 92[r1]
	st.w	r22, 96[r1]
	st.w	r23, 100[r1]
	st.w	r24, 104[r1]
	st.w	r25, 108[r1]
	st.w	r26, 112[r1]
	st.w	r27, 116[r1]
	st.w	r28, 120[r1]
	st.w	r29, 124[r1]
	st.w	r30, 128[r1]
}

#pragma inline_asm LoadContext
void LoadContext (void) {
	stsr	0, r1, 2 				;get coreID
	shr		16, r1
	cmp		2, r1
	bz		_load_pe2				;_SaveContext+0x12
	mov     #_CurrentTask_core0, r1	;get OSKernel for pe1
	br 		_get_current			;_SaveContext+0x18
_load_pe2:
	mov 	#_CurrentTask_core1, r1	;get OSKernel for pe2
_get_current:
	ld.w	0[r1], r2               ;get CurrentConst
	ld.w	4[r2], r5               ;get context of current task
	ld.w    0[r5], sp               ;load sp(r3)
	ld.w	4[r5], lp               ;load lp(r31)
	ld.w	8[r5], r2               ;load eipc
	ldsr	r2, 0				
	ld.w	12[r5], r2              ;load eipsw
	ldsr	r2, 1				
	ld.w	20[r5], r2				;load current task register
	ld.w	24[r5], r4 			
	ld.w	32[r5], r6
	ld.w	36[r5], r7			
	ld.w	40[r5], r8
	ld.w	44[r5], r9			
	ld.w	48[r5], r10
	ld.w	52[r5], r11			
	ld.w	56[r5], r12
	ld.w	60[r5], r13			
	ld.w	64[r5], r14
	ld.w	68[r5], r15			
	ld.w	72[r5], r16
	ld.w	76[r5], r17			
	ld.w	80[r5], r18
	ld.w	84[r5], r19			
	ld.w	88[r5], r20
	ld.w	92[r5], r21
	ld.w	96[r5], r22			
	ld.w	100[r5], r23
	ld.w	104[r5], r24			
	ld.w	108[r5], r25
	ld.w	112[r5], r26			
	ld.w	116[r5], r27
	ld.w	120[r5], r28			
	ld.w	124[r5], r29
	ld.w	128[r5], r30
	ld.w	28[r5], r5					


	add		-0x04, sp				;spare 4 byte in stack
	st.w    r4, 0[sp]				;push r4 to stack
	ld.w    16[r1], r4 				;get MPM
	ld.w	0[r1], r1				;get CurrentConst
	ld.w	4[r1], r1				;get context of current task
	ld.w	16[r1], r1				;load r1
	ldsr	r4, 0, 5				;set MPM
	ld.w    0[sp],r4				;load r4 back
	add		0x04, sp				;return 4 byte in stack
	eiret							
}

#pragma inline_asm ScheduleKernelISR
void ScheduleKernelISR(void) {
	ldsr 	r0, 0, 5				;disable MPU
	add		-0x0C, sp
	st.w    r1, 8[sp]               ;push r1, r2, lp to stack, they would be used in SaveContext
	st.w	r2, 4[sp]
	st.w	lp, 0[sp]
	jarl	_SaveContext, lp        ;jump to SaveContext
	ld.w	4[sp], r2               ;load r2 back
	st.w	r2, 20[r1]              ;save r2
	mov 	r1, r4                  ;move pointer to currentConst from r1 to r4
	ld.w	8[sp], r2               ;load r1 back
	st.w	r2, 16[r4]              ;save r1
	ld.w	0[sp], r1               ;load lp back
	st.w	r1, 4[r4]               ;save lp
	add		0x0C, sp                ;add sp(r3) back to right value
	st.w	sp, 0[r4]               ;save sp(r3), all context have been saved
_to_scheduler:
	jarl	_Scheduler, lp          ;jump to Scheduler
	jarl	_LoadContext, lp        ;jump to LoadContext
}


//from user stack to kernel stack
#pragma inline_asm SwitchStackFromUtoK
void SwitchStackFromUtoK (void) {
	add		-0x04, sp                       ;spare 4 byte in stack
	st.w    r1, 0[sp]               		;push r1 to stack
	stsr	0, r1, 2 						;get HTCFG0
	shr		16, r1							;get PEID i.e. coreID
	cmp		2, r1							;is it pe2?
	bz		_UtoK_sp_manage_pe2				;

_UtoK_sp_manage_pe1:
    mov     #_myEISP, r1					;get myEISP 
	st.w    sp, 0[r1]               		;store user sp to myEISP
	mov     #_mySysStackPtr, r1				;get ptr to mySysStackPtr
	ld.w	0[r1], sp               		;load mySysStackPtr 
	br 		_UtoK_sp_manage_exit			;
	
_UtoK_sp_manage_pe2:
	mov     #_myEISP, r1					;get myEISP 
	st.w    sp, 0[r1]               		;store user sp to myEISP
	mov     #_mySysStackPtr, r1				;get ptr to mySysStackPtr
	ld.w	0[r1], sp               		;load mySysStackPtr

_UtoK_sp_manage_exit:
}

//from kernel stack to user stack
#pragma inline_asm SwitchStackFromKtoU
void SwitchStackFromKtoU (void) {
	stsr	0, r1, 2 						;get HTCFG0
	shr		16, r1							;get PEID i.e. coreID
	cmp		2, r1							;is it pe2?
	bz		_KtoU_sp_manage_pe2				;

_KtoU_sp_manage_pe1:
    mov     #_myEISP, r1					;get myEISP 
	ld.w	0[r1], sp               		;load back user sp from myEISP
	br 		_KtoU_sp_manage_exit			;
	
_KtoU_sp_manage_pe2:
	mov     #_myEISP, r1					;get myEISP 
	ld.w	0[r1], sp               		;get CurrentConst

_KtoU_sp_manage_exit:
	ld.w	0[sp], r1               		;load r1 back;
	add		0x04, sp                        ;return 4 byte in stack
}



// #pragma inline_asm SaveOSContext
// void SaveOSContext (void) {
// 	add		-0x0C, sp
// 	st.w    r1, 8[sp]               		;push r1, r2, lp to stack, 
// 	st.w	r2, 4[sp]						;they would be used in SaveOSContext
// 	st.w	lp, 0[sp]
		
// 	stsr	0, r1, 2 						;get HTCFG0
// 	shr		16, r1							;get PEID i.e. coreID
// 	cmp		2, r1							; is it pe2?
// 	bz		_os_save_pe2					;
// _os_save_pe1:
// 	mov     #_CurrentOSContextRef_core0, r1	;get _CurrentOSContextRef_core0 for pe1
// 	br 		_os_go_save						;
// _os_save_pe2:
// 	mov 	#_CurrentOSContextRef_core1, r1	;get _CurrentOSContextRef_core1 for pe2
// _os_go_save:
// 	stsr	0, r2                   ;get eipc
// 	st.w	r2, 8[r1]				;save eipc
// 	stsr    1, r2                   ;get eipsw
// 	st.w	r2, 12[r1]				;save eipsw
// 	stsr	0, r2,  5				;get MPM
// 	st.w	r2, 132[r1]				;save MPM

// 	;st.w	r1, 16[r1]              ;ignored, will be saved at below
// 	;st.w	r2, 20[r1]              ;ignored, will be saved at below
// 	st.w	r4, 24[r1]              ;save general purpose registers
// 	st.w	r5, 28[r1]
// 	st.w	r6, 32[r1]
// 	st.w	r7, 36[r1]
// 	st.w	r8, 40[r1]
// 	st.w	r9, 44[r1]
// 	st.w	r10, 48[r1]
// 	st.w	r11, 52[r1]
// 	st.w	r12, 56[r1]
// 	st.w	r13, 60[r1]
// 	st.w	r14, 64[r1]
// 	st.w	r15, 68[r1]
// 	st.w	r16, 72[r1]
// 	st.w	r17, 76[r1]
// 	st.w	r18, 80[r1]
// 	st.w	r19, 84[r1]
// 	st.w	r20, 88[r1]
// 	st.w	r21, 92[r1]
// 	st.w	r22, 96[r1]
// 	st.w	r23, 100[r1]
// 	st.w	r24, 104[r1]
// 	st.w	r25, 108[r1]
// 	st.w	r26, 112[r1]
// 	st.w	r27, 116[r1]
// 	st.w	r28, 120[r1]
// 	st.w	r29, 124[r1]
// 	st.w	r30, 128[r1]

// 	ld.w	4[sp], r2               ;load r2 back
// 	st.w	r2, 20[r1]              ;save r2
// 	mov 	r1, r4                  ;move pointer from r1 to r4
// 	ld.w	8[sp], r2               ;load r1 back
// 	st.w	r2, 16[r4]              ;save r1
// 	ld.w	0[sp], r1               ;load lp back
// 	st.w	r1, 4[r4]               ;save lp
// 	add		0x0C, sp                ;add sp(r3) back to right value
// 	st.w	sp, 0[r4]               ;save sp(r3), all context have been saved
// }

// #pragma inline_asm LoadOSContextInMemHandler
// void LoadOSContextInMemHandler (void) {

// 	stsr	0, r1, 2 						;get HTCFG0
// 	shr		16, r1							;get PEID i.e. coreID
// 	cmp		2, r1							; is it pe2?
// 	bz		_os_load_pe2					;
// _os_load_pe1:
// 	mov     #_CurrentOSContextRef_core0, r1	;get _CurrentOSContextRef_core0 for pe1
// 	br 		_os_go_load						;
// _os_load_pe2:
// 	mov 	#_CurrentOSContextRef_core1, r1	;get _CurrentOSContextRef_core1 for pe2
// _os_go_load:

// 	ld.w	0[r1],  sp				;load sp
// 	add		-0x08, sp				;since we might use r1&r2 below, we save old value to stack
// 	ld.w	16[r1], r4				;load old r1
// 	st.w    r4, 0[sp]               ;push r1 to stack,
// 	ld.w	20[r1], r4				;load old r2
// 	st.w    r4, 4[sp]               ;push r2 to stack,

// 	ld.w	4[r1],  lp				;load lp
// 	ld.w	12[r1], r2 				;get old eipsw saved before
// 	ldsr	r2, 3 , 0               ;load to fepsw
// 	ld.w	8[r1],  r2              ;get old eipc saved before
// 	ldsr	r2, 2 , 0               ;load to fepc

// 	ld.w    132[r1], r2 			;get old MPM
// 	ldsr	r2, 0, 5				;set MPM

// 	;ld.w	16[r1], xx              ;ignored, will be load at below
// 	;ld.w	20[r1], xx              ;ignored, will be load at below
// 	ld.w	24[r1], r4              ;load general purpose registers
// 	ld.w	28[r1], r5			
// 	ld.w	32[r1], r6
// 	ld.w	36[r1], r7			
// 	ld.w	40[r1], r8
// 	ld.w	44[r1], r9			
// 	ld.w	48[r1], r10
// 	ld.w	52[r1], r11			
// 	ld.w	56[r1], r12
// 	ld.w	60[r1], r13			
// 	ld.w	64[r1], r14
// 	ld.w	68[r1], r15			
// 	ld.w	72[r1], r16
// 	ld.w	76[r1], r17			
// 	ld.w	80[r1], r18
// 	ld.w	84[r1], r19			
// 	ld.w	88[r1], r20
// 	ld.w	92[r1], r21
// 	ld.w	96[r1], r22			
// 	ld.w	100[r1], r23
// 	ld.w	104[r1], r24			
// 	ld.w	108[r1], r25
// 	ld.w	112[r1], r26			
// 	ld.w	116[r1], r27
// 	ld.w	120[r1], r28			
// 	ld.w	124[r1], r29
// 	ld.w	128[r1], r30

// 	ld.w	4[sp], r2               ;load r2 back
// 	ld.w	0[sp], r1               ;load r1 back
// 	add		0x08, sp                ;add sp(r3) back to right value

// 	feret							;return
// }
