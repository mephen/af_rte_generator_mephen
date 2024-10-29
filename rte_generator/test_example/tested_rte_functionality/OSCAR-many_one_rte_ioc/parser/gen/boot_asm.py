from generator.config import config 
from generator import globals as gr

global config
gr.genfile = open(r"../device/boot.asm",'w')

gr.printFile("	USE_TABLE_REFERENCE_METHOD .set 1   ;I don't know why it's 0 before 20220731")
gr.printFile("    USE_SYSTEM_CALL .set 1")


gr.printFile("	.section \"RESET_PE1\", text\n" + "	.align	512\n" + "	jr32	__start ; RESET\n")
gr.printFile("	.align	16\n" + "	syncp\n" + "	jr32	_Dummy_SYSERR ; SYSERR\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_2\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_FETRAP ; FETRAP ; might need handler\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_TRAP0 ; TRAP0  ; might need handler\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_TRAP1 ; TRAP1  ; might need handler\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_RIE ; RIE    ;  execute an undefined opcode\n")
gr.printFile("	.align	16\n" + "	syncp\n" + "	jr32	_Dummy_FPP_FPI ; FPP/FPI\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_UCPOP ; UCPOP\n")

gr.printFile("	.align	16\n" + "	jr32	_MPU_FAULT_HANDLER ;_MPU_FAULT_HANDLER ; MIP/MDP aka. MPU fault\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_PIE ; PIE    ; execute an instruction without required privilege.\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_11\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_MAE ; MAE    ; result of address calculation is a misaligned address\n")
gr.printFile("	.align	16\n" + "	jr32	_Dummy_13\n")
gr.printFile("	.align	16\n" + "	syncp\n" + "	jr32	_Dummy_FENMI ; FENMI\n")
gr.printFile("	.align	16\n" + "	syncp\n" + "	jr32	_Dummy_FEINT ; FEINT\n")

for i in range(16):
	gr.printFile("	.align	16\n" + "	syncp\n" + "	jr32	_Dummy_EI ; INTn(priority{})\n".format(i))

gr.printFile("	.section \"EIINTTBL_PE1\", const\n" + "	.align	512\n")

isrs = config.getList("/AUTOSAR","OsIsr")
apps = config.getList("/AUTOSAR","OsApplication")


file_path = r"file\boot_asm_setting.txt"  # 請將檔案路徑替換為你的文本檔路徑

try:
    with open(file_path, 'r') as file:
        lines = file.readlines()
        for line in lines[5:]:  # 從第三行開始處理
            parts = line.strip().split(";")
            num = parts[0].strip()
            address = parts[1].strip()
            commit = parts[2].strip()
            flag = False
            for isr in isrs:
                isrchannel = config.getValue("/AUTOSAR/" + isr,"OsIsrInterruptSource")
                if num != isrchannel:
                    continue
                if address != "DA":
                    gr.error("This channel {} of {} should be changed".format(isrchannel, isr))
                flag = True
                isrcat = config.getValue("/AUTOSAR/" + isr,"OsIsrCategory")
                if isrcat == "CATEGORY_2":
                    gr.printFile("    .dw    #_ISR_{}_LAUNCHER    ; INT{} ".format(isr, num))
                elif isrcat == "CATEGORY_1":
                    gr.printFile("    .dw    #_Dummy_EI    ; INT{}    ; user ISR {}".format(num, isr))
                    break                
            if flag != True:
                if address == "DU" and commit != "":
                    gr.printFile("    .dw    #_Reserved_EI ; INT{}    ; {}".format(num, commit))
                elif address == "DU" and commit == "":
                    gr.printFile("    .dw    #_Reserved_EI ; INT{}    ".format(num))
                elif address == "DA" and commit != "":
                    gr.printFile("    .dw    #_Dummy_EI    ; INT{}    ; {}".format(num, commit))
                elif address == "DA" and commit == "":
                    gr.printFile("    .dw    #_Dummy_EI    ; INT{}    ".format(num))
                elif address != "DU" and address != "DA" and commit != "":
                    gr.printFile("    .dw    {} ; INT{}   ; {} ".format(address, num, commit))
                elif address != "DU" and address != "DA" and commit == "":
                    gr.printFile("    .dw    {} ; INT{}   ".format(address, num))


except FileNotFoundError:
    print(f"找不到檔案: {file_path}")
except Exception as e:
    print(f"讀取檔案時發生錯誤: {e}")

gr.printFile("\n    .section \"SYSTEMCALLTBL\", const")
gr.printFile("    .align	512")
gr.printFile("    .dw    #_SYSCALL_ERR_TEST     -   #__sSYSTEMCALLTBL     ;0")
gr.printFile("    .dw    #_sysEnterSystemCall   -   #__sSYSTEMCALLTBL     ;1 ") 
gr.printFile("    .dw    #_sysExitSystemCall    -   #__sSYSTEMCALLTBL     ;2") 
gr.printFile("    .dw    #_sysCallSystemServiceHandler   -   #__sSYSTEMCALLTBL    ;3")
gr.printFile("    .dw    #_sysCallPrintTextHandler   -   #__sSYSTEMCALLTBL    ;4")
gr.printFile("    .dw    #_sysCallPrintText_R35Handler   -   #__sSYSTEMCALLTBL    ;5")
gr.printFile("    .dw    #_sysCallTrustFuncHandler   -   #__sSYSTEMCALLTBL    ;6")

gr.printFile("_Dummy:")
gr.printFile("	br	_Dummy\n")

gr.printFile("_Dummy_EI:")
gr.printFile("	br	_Dummy_EI\n")

gr.printFile("_Reserved_EI:")
gr.printFile("	br	_Reserved_EI\n")

gr.printFile("_Dummy_SYSERR:")
gr.printFile("    br _Dummy_SYSERR\n")

gr.printFile("_Dummy_2:")
gr.printFile("    br _Dummy_2\n")

gr.printFile("_Dummy_FETRAP:")
gr.printFile("    br _Dummy_FETRAP\n")

gr.printFile("_Dummy_TRAP0:")
gr.printFile("    br _Dummy_TRAP0\n")

gr.printFile("_Dummy_TRAP1:")
gr.printFile("    br _Dummy_TRAP1\n")

gr.printFile("_Dummy_RIE:")
gr.printFile("    br _Dummy_RIE\n")

gr.printFile("_Dummy_FPP_FPI:")
gr.printFile("    br _Dummy_FPP_FPI\n")

gr.printFile("_Dummy_UCPOP:")
gr.printFile("    br _Dummy_UCPOP\n")

gr.printFile("_AHA_MPU:")
gr.printFile("    br _AHA_MPU_hander\n")

gr.printFile("_Dummy_PIE:")
gr.printFile("    br _Dummy_PIE\n")

gr.printFile("_Dummy_11:")
gr.printFile("    br _Dummy_11\n")

gr.printFile("_Dummy_MAE:")
gr.printFile("    br _Dummy_MAE\n")

gr.printFile("_Dummy_13:")
gr.printFile("    br _Dummy_13\n")

gr.printFile("_Dummy_FENMI:")
gr.printFile("    br _Dummy_FENMI\n")

gr.printFile("_Dummy_FEINT:")
gr.printFile("    br _Dummy_FEINT\n")

gr.printFile("_SYSCALL_ERR_TEST:")
gr.printFile("    br  _SYSCALL_ERR_TEST\n")

gr.printFile("    .section \".text\", text")
gr.printFile("	.align	2\n")

gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile(";	startup")
gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile("    .section	\".text\", text")
gr.printFile("    .align	2")
gr.printFile("    .public	__start")
gr.printFile("__start:")
gr.printFile("$if 1	; initialize register")
gr.printFile("    $nowarning")
gr.printFile("    mov	r0, r1")
gr.printFile("    $warning")
for i in range(2,32):
    gr.printFile("    mov	r0, r{}".format(i))

gr.printFile("	ldsr	r0, 0, 0		;  EIPC")
gr.printFile("	ldsr	r0, 16, 0		;  CTPC")
gr.printFile("$endif\n")

gr.printFile("$if 1")
gr.printFile("	; jump to entry point of each PE")
gr.printFile("	stsr	0, r10, 2		; get HTCFG0")
gr.printFile("	shr	16, r10			    ; get PEID")
for i in range(1,8):
    gr.printFile("	cmp	{}, r10".format(i))
    gr.printFile("	bz	.L.entry_PE{}".format(i))
gr.printFile("__exit:")
gr.printFile("	br	__exit\n")

gr.printFile(".L.entry_PE1:")
gr.printFile("	jarl	_hdwinit_PE1, lp	; initialize hardware")
gr.printFile("$ifdef USE_TABLE_REFERENCE_METHOD")
gr.printFile("	mov	    #__sEIINTTBL_PE1, r6")
gr.printFile("	jarl	_set_table_reference_method, lp ; set table reference method")
gr.printFile("$endif")
gr.printFile("$ifdef USE_SYSTEM_CALL")
gr.printFile("    mov	    #__sSYSTEMCALLTBL, r6    ; used as SCBP value")
gr.printFile("    mov     6, r7                    ; we use syscall 1~2, so set 2 to SCCFG (0 is default)")
gr.printFile("    jarl    _set_system_call_reg, lp ; set SCBP, SCCFG")
gr.printFile("$endif")
gr.printFile("	jr32	__cstart_pe1\n")

gr.printFile(".L.entry_PE2:")
gr.printFile("	jarl	_hdwinit_PE2, lp	; initialize hardware")
gr.printFile("$ifdef USE_TABLE_REFERENCE_METHOD")
gr.printFile("	mov     #__sEIINTTBL_PE1, r6            ; here, if you really want, you can set other table")
gr.printFile("	jarl    _set_table_reference_method, lp ; set table reference method")
gr.printFile("$endif")
gr.printFile("$ifdef USE_SYSTEM_CALL")
gr.printFile("    mov	    #__sSYSTEMCALLTBL, r6    ; used as SCBP value")
gr.printFile("    mov     6, r7                    ; we use syscall 1~2, so set 2 to SCCFG (0 is default)")
gr.printFile("    jarl    _set_system_call_reg, lp ; set SCBP, SCCFG")
gr.printFile("$endif")
gr.printFile("	jr32	__cstart_pe2")
gr.printFile("	br	__exit\n")

for i in range(3,8):
    gr.printFile(".L.entry_PE{}:".format(i))
    gr.printFile("	br	__exit")
gr.printFile("$endif")
gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile(";	hdwinit_PE1")
gr.printFile("; Specify RAM addresses suitable to your system if needed.")
gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile("	GLOBAL_RAM_A_ADDR	.set	0xFEEF8000")
gr.printFile("	GLOBAL_RAM_A_END    .set	0xFEEFFFFF")
gr.printFile("	GLOBAL_RAM_B_ADDR	.set	0xFEFF0000")
gr.printFile("	GLOBAL_RAM_B_END    .set	0xFEFFFFFF")
gr.printFile("    RETENTION_RAM_ADDR	.set	0xFEF01000  ; there is a special area for STARTUP_LOCK in boot2.asm")
gr.printFile("	RETENTION_RAM_END	.set	0xFEF0FFFF  ; so we start from 0xFEF01000 instead of 0xFEF00000")
gr.printFile("    SELF_RAM_PE1_ADDR	.set	0xFEDC0000")
gr.printFile("	SELF_RAM_PE1_END	.set	0xFEDFFFFF")
gr.printFile("	LOCAL_RAM_PE1_ADDR	.set	0xFEBC0000")
gr.printFile("	LOCAL_RAM_PE1_END	.set	0xFEBFFFFF\n")

gr.printFile("	.align	2")
gr.printFile("_hdwinit_PE1:")
gr.printFile("	mov	lp, r14    ; save return address\n")

gr.printFile("	; clear Local RAM PE1")
gr.printFile("	mov	LOCAL_RAM_PE1_ADDR, r6")
gr.printFile("	mov	LOCAL_RAM_PE1_END, r7")
gr.printFile("	jarl	_zeroclr4, lp\n")
	
gr.printFile("    ; clear SELF RAM PE1")
gr.printFile("	mov	SELF_RAM_PE1_ADDR, r6")
gr.printFile("	mov	SELF_RAM_PE1_END, r7")
gr.printFile("	jarl	_zeroclr4, lp\n")

gr.printFile("    ; clear RETENTION RAM") 
gr.printFile("	mov	RETENTION_RAM_ADDR, r6")
gr.printFile("	mov	RETENTION_RAM_END, r7")
gr.printFile("	jarl	_zeroclr4, lp\n")

gr.printFile("	; clear Global RAM 1")
gr.printFile("	mov	GLOBAL_RAM_A_ADDR, r6")
gr.printFile("	mov	GLOBAL_RAM_A_END, r7")
gr.printFile("	jarl	_zeroclr4, lp\n")
	
gr.printFile("	; clear Global RAM 2")
gr.printFile("	mov	GLOBAL_RAM_B_ADDR, r6")
gr.printFile("	mov	GLOBAL_RAM_B_END, r7")
gr.printFile("	jarl	_zeroclr4, lp\n")

gr.printFile("	mov	r14, lp")
gr.printFile("	jmp	[lp]\n")

gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile(";	hdwinit_PE2")
gr.printFile("; Specify RAM addresses suitable to your system if needed.")
gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile("	SELF_RAM_PE2_ADDR	.set	0xFEDE0000")
gr.printFile("	SELF_RAM_PE2_END	.set	0xFEDFFFFF")
gr.printFile("    LOCAL_RAM_PE2_ADDR	.set	0xFE9E0000")
gr.printFile("	LOCAL_RAM_PE2_END	.set	0xFE9FFFFF")
gr.printFile("    ;RETENTION_RAM_RESERVED_PE2_ADDR .set	0xFEF00000  ; there is a special area for STARTUP_LOCK in boot2.asm")
gr.printFile("	;RETENTION_RAM_RESERVED_PE2_END  .set	0xFEF01000  ; so we let PE2 clear this area\n") 

gr.printFile("	.align	2")
gr.printFile("_hdwinit_PE2:")
gr.printFile("	mov	lp, r14    ; save return address\n")

gr.printFile("	; clear Local RAM PE2")
gr.printFile("	mov	LOCAL_RAM_PE2_ADDR, r6")
gr.printFile("	mov	LOCAL_RAM_PE2_END, r7")
gr.printFile("	jarl	_zeroclr4, lp\n")

gr.printFile("    ; clear SELF RAM PE2")
gr.printFile("	mov	SELF_RAM_PE2_ADDR, r6")
gr.printFile("	mov	SELF_RAM_PE2_END, r7")
gr.printFile("	jarl	_zeroclr4, lp\n")

gr.printFile("    ; clear RETENTION_RAM RESERVED for PE2")
gr.printFile("	;mov	RETENTION_RAM_RESERVED_PE2_ADDR, r6")
gr.printFile("	;mov	RETENTION_RAM_RESERVED_PE2_END, r7")
gr.printFile("	;jarl	_zeroclr4, lp\n")

gr.printFile("	mov	r14, lp")
gr.printFile("	jmp	[lp]\n")

gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile(";	zeroclr4")
gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile("	.align	2")
gr.printFile("_zeroclr4:")
gr.printFile("	br	.L.zeroclr4.2")
gr.printFile(".L.zeroclr4.1:")
gr.printFile("	st.w	r0, [r6]")
gr.printFile("	add	4, r6")
gr.printFile(".L.zeroclr4.2:")
gr.printFile("	cmp	r6, r7")
gr.printFile("	bh	.L.zeroclr4.1")
gr.printFile("	jmp	[lp]\n\n")


gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile(";	set table reference method")
gr.printFile(";-----------------------------------------------------------------------------")
gr.printFile("$ifdef USE_TABLE_REFERENCE_METHOD")
gr.printFile("	; interrupt control register address")
gr.printFile("	ICBASE	.set	0xfffeea00\n")

gr.printFile("	.align	2")
gr.printFile("_set_table_reference_method:")
gr.printFile("	ldsr	r6, 4, 1		; set INTBP")
gr.printFile("    ;ldsr	r7, 12, 1		; set SCBP ;20221016 why set here? we can set it at _set_system_call_reg\n")

gr.printFile("	mov	ICBASE, r10		; get interrupt control register address")
gr.printFile("	set1	6, 0[r10]		; set INT0  as table reference")
gr.printFile("	set1	6, 2[r10]		; set INT1  as table reference")
gr.printFile("	set1	6, 4[r10]		; set INT2  as table reference")
gr.printFile("    ;20221016 we only set 3 INT above, as an initialization example") 
gr.printFile("    ;but in fact, in ISR-Init, we set INT (which we use) as table reference one by one\n")

gr.printFile("	jmp	[lp]")
gr.printFile("$endif\n")

gr.printFile("$ifdef USE_SYSTEM_CALL")
gr.printFile("_set_system_call_reg:")
gr.printFile("	ldsr	r6, 12, 1		; set SCBP")
gr.printFile("    ldsr	r7, 11, 1		; set SCCFG")
gr.printFile("	jmp	[lp]")
gr.printFile("$endif\n")
