;********************************************************
;* DO NOT CHANGE THIS FILE, IT IS GENERATED AUTOMATICALY*
;********************************************************

;   Copyright(c) 2013, 2016 Renesas Electronics Corporation
;   RENESAS ELECTRONICS CONFIDENTIAL AND PROPRIETARY.
;   This program must be used solely for the purpose for which
;   it was furnished by Renesas Electronics Corporation. No part of this
;   program may be reproduced or disclosed to others, in any
;   form, without the prior written permission of Renesas Electronics
;   Corporation.

;   NOTE       : THIS IS A TYPICAL EXAMPLE.
;   DATE       : Mon, Oct 24, 2016

	; if using eiint as table reference method,
	; enable next line's macro.

	USE_TABLE_REFERENCE_METHOD .set 1   ;I don't know why it's 0 before 20220731
    USE_SYSTEM_CALL .set 1

;-----------------------------------------------------------------------------
;	exception vector table
;-----------------------------------------------------------------------------
	.section "RESET_PE1", text
	.align	512
	jr32	__start ; RESET

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

	.section "EIINTTBL_PE1", const
    .align	512

    .dw    #_ServiceCrossCore ; INT0
    .dw    #_Dummy_EI ; INT1    ; reserve for Inter-processor INT(in use)
    .dw    #_Dummy_EI ; INT2    ; reserve for Inter-processor INT(not in use)1
    .dw    #_Dummy_EI ; INT3    ; reserve for Inter-processor INT(not in use)
    .dw    #_Dummy_EI ; INT4    ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT5    ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT6    ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT7    ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT8    ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT9    ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT10   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT11   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT12   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT13   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT14   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT15   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT16   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT17   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT18   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT19   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT20   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT21   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT22   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT23   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT24   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT25   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT26   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT27   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT28   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT29   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT30   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT31   ;WHEN USE CHANNEL 0-31, BE CAREFUL
    .dw    #_Dummy_EI ; INT32
    .dw    #_Dummy_EI ; INT33      20220307/not-used/INTRLIN30   /RLIN30-interrupt
    .dw    #_INTRLIN30UR0 ; INT34  20220307/  IN-USE/INTRLIN30UR0/RLIN30 transmit interrupt
    .dw    #_Dummy_EI ; INT35      20220307/not-used/INTRLIN30UR1/RLIN30-receive-complete-interrupt
    .dw    #_Dummy_EI ; INT36      20220307/not-used/INTRLIN30UR2/RLIN30-status-interrupt
    .dw    #_ScheduleKernelISR  ; INT37 core 0
    .dw    #_ScheduleKernelISR  ; INT38 core 1
    .dw    #_Dummy_EI ; INT39   ; autosar reserved 
    .dw    #_INTWDTA0 ; INT40   ; INTWDTA0
    .dw    #_INTWDTA1 ; INT41   ; INTWDTA1 
    .dw    #_Dummy_EI ; INT42
    .dw    #_ISR_I001_Launcher ; INT43   ; user ISR app_lion
    .dw    #_ISR_I002_Launcher ; INT44   ; user ISR app_lion
    .dw    #_Dummy_EI ; INT45   ; user ISR app_lion
    .dw    #_Dummy_EI ; INT46   
    .dw    #_Dummy_EI ; INT47   
    .dw    #_Dummy_EI ; INT48
    .dw    #_Dummy_EI ; INT49
    .dw    #_Dummy_EI ; INT50
    .dw    #_Dummy_EI ; INT51
    .dw    #_Dummy_EI ; INT52
    .dw    #_Dummy_EI ; INT53
    .dw    #_Dummy_EI ; INT54
    .dw    #_Dummy_EI ; INT55
    .dw    #_Dummy_EI ; INT56
    .dw    #_Dummy_EI ; INT57
    .dw    #_Dummy_EI ; INT58
    .dw    #_Dummy_EI ; INT59
    .dw    #_Dummy_EI ; INT60
    .dw    #_Dummy_EI ; INT61
    .dw    #_Dummy_EI ; INT62
    .dw    #_Dummy_EI ; INT63
    .dw    #_Dummy_EI ; INT64
    .dw    #_Dummy_EI ; INT65
    .dw    #_Dummy_EI ; INT66
    .dw    #_Dummy_EI ; INT67
    .dw    #_Dummy_EI ; INT68
    .dw    #_Dummy_EI ; INT69
    .dw    #_Dummy_EI ; INT70
    .dw    #_Dummy_EI ; INT71
    .dw    #_Dummy_EI ; INT72
    .dw    #_Dummy_EI ; INT73
    .dw    #_Dummy_EI ; INT74
    .dw    #_Dummy_EI ; INT75
    .dw    #_Dummy_EI ; INT76
    .dw    #_Dummy_EI ; INT77
    .dw    #_Dummy_EI ; INT78
    .dw    #_Dummy_EI ; INT79
    .dw    #_Dummy_EI ; INT80
    .dw    #_Dummy_EI ; INT81
    .dw    #_Dummy_EI ; INT82
    .dw    #_Dummy_EI ; INT83
    .dw    #_OSTM0_interrupt ; INT84
    .dw    #_Dummy_EI ; INT85
    .dw    #_Dummy_EI ; INT86
    .dw    #_Dummy_EI ; INT87
    .dw    #_Dummy_EI ; INT88
    .dw    #_Dummy_EI ; INT89
    .dw    #_Dummy_EI ; INT90
    .dw    #_Dummy_EI ; INT91
    .dw    #_Dummy_EI ; INT92
    .dw    #_Dummy_EI ; INT93  ; user ISR app3
    .dw    #_Dummy_EI ; INT94  ; user ISR app3
    .dw    #_Dummy_EI ; INT95  ; user ISR app3
    .dw    #_Dummy_EI ; INT96
    .dw    #_Dummy_EI ; INT97
    .dw    #_Dummy_EI ; INT98
    .dw    #_Dummy_EI ; INT99
    .dw    #_Dummy_EI ; INT100
    .dw    #_Dummy_EI ; INT101
    .dw    #_Dummy_EI ; INT102
    .dw    #_Dummy_EI ; INT103
    .dw    #_Dummy_EI ; INT104  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT105  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT106  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT107  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT108  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT109  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT110
    .dw    #_Dummy_EI ; INT111
    .dw    #_Dummy_EI ; INT112
    .dw    #_Dummy_EI ; INT113
    .dw    #_Dummy_EI ; INT114
    .dw    #_Dummy_EI ; INT115
    .dw    #_Dummy_EI ; INT116
    .dw    #_Dummy_EI ; INT117
    .dw    #_Dummy_EI ; INT118
    .dw    #_Dummy_EI ; INT119
    .dw    #_Dummy_EI ; INT120
    .dw    #_Dummy_EI ; INT121
    .dw    #_Dummy_EI ; INT122
    .dw    #_Dummy_EI ; INT123
    .dw    #_Dummy_EI ; INT124
    .dw    #_Dummy_EI ; INT125
    .dw    #_Dummy_EI ; INT126
    .dw    #_Dummy_EI ; INT127
    .dw    #_Dummy_EI ; INT128  ; user ISR app2
    .dw    #_ISR_I102_Launcher ; INT129  ; user ISR app2
    .dw    #_ISR_I103_Launcher ; INT130  ; user ISR app2
    .dw    #_Dummy_EI ; INT131
    .dw    #_Dummy_EI ; INT132
    .dw    #_Dummy_EI ; INT133
    .dw    #_Dummy_EI ; INT134
    .dw    #_Dummy_EI ; INT135
    .dw    #_Dummy_EI ; INT136  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT137  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT138  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT139  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT140  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT141  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT142
    .dw    #_Dummy_EI ; INT143
    .dw    #_Dummy_EI ; INT144
    .dw    #_Dummy_EI ; INT145
    .dw    #_Dummy_EI ; INT146
    .dw    #_Dummy_EI ; INT147
    .dw    #_Dummy_EI ; INT148
    .dw    #_Dummy_EI ; INT149
    .dw    #_Dummy_EI ; INT150
    .dw    #_Dummy_EI ; INT151
    .dw    #_Dummy_EI ; INT152
    .dw    #_Dummy_EI ; INT153
    .dw    #_Dummy_EI ; INT154
    .dw    #_Dummy_EI ; INT155
    .dw    #_Dummy_EI ; INT156
    .dw    #_Dummy_EI ; INT157
    .dw    #_Dummy_EI ; INT158
    .dw    #_Dummy_EI ; INT159
    .dw    #_Dummy_EI ; INT160
    .dw    #_Dummy_EI ; INT161
    .dw    #_Dummy_EI ; INT162
    .dw    #_Dummy_EI ; INT163
    .dw    #_Dummy_EI ; INT164
    .dw    #_Dummy_EI ; INT165
    .dw    #_Dummy_EI ; INT166
    .dw    #_Dummy_EI ; INT167
    .dw    #_Dummy_EI ; INT168
    .dw    #_Dummy_EI ; INT169
    .dw    #_Dummy_EI ; INT170
    .dw    #_Dummy_EI ; INT171
    .dw    #_Dummy_EI ; INT172  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT173
    .dw    #_Dummy_EI ; INT174
    .dw    #_Dummy_EI ; INT175
    .dw    #_Dummy_EI ; INT176
    .dw    #_Dummy_EI ; INT177
    .dw    #_Dummy_EI ; INT178
    .dw    #_Dummy_EI ; INT179
    .dw    #_Dummy_EI ; INT180
    .dw    #_Dummy_EI ; INT181
    .dw    #_Dummy_EI ; INT182
    .dw    #_Dummy_EI ; INT183
    .dw    #_Dummy_EI ; INT184
    .dw    #_Dummy_EI ; INT185
    .dw    #_Dummy_EI ; INT186  ; user ISR app4
    .dw    #_Dummy_EI ; INT187  ; user ISR app4
    .dw    #_Dummy_EI ; INT188  ; user ISR app4
    .dw    #_Dummy_EI ; INT189
    .dw    #_Dummy_EI ; INT190
    .dw    #_Dummy_EI ; INT191
    .dw    #_Dummy_EI ; INT192
    .dw    #_Dummy_EI ; INT193
    .dw    #_Dummy_EI ; INT194
    .dw    #_Dummy_EI ; INT195
    .dw    #_Dummy_EI ; INT196
    .dw    #_Dummy_EI ; INT197
    .dw    #_Dummy_EI ; INT198
    .dw    #_Dummy_EI ; INT199
    .dw    #_Dummy_EI ; INT200
    .dw    #_Dummy_EI ; INT201
    .dw    #_Dummy_EI ; INT202
    .dw    #_Dummy_EI ; INT203
    .dw    #_Dummy_EI ; INT204
    .dw    #_Dummy_EI ; INT205
    .dw    #_Dummy_EI ; INT206
    .dw    #_Dummy_EI ; INT207
    .dw    #_Dummy_EI ; INT208
    .dw    #_Dummy_EI ; INT209
    .dw    #_Dummy_EI ; INT210
    .dw    #_Dummy_EI ; INT211
    .dw    #_Dummy_EI ; INT212
    .dw    #_Dummy_EI ; INT213
    .dw    #_Dummy_EI ; INT214
    .dw    #_Dummy_EI ; INT215
    .dw    #_Dummy_EI ; INT216  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT217
    .dw    #_Dummy_EI ; INT218
    .dw    #_Dummy_EI ; INT219
    .dw    #_Dummy_EI ; INT220
    .dw    #_Dummy_EI ; INT221
    .dw    #_Dummy_EI ; INT222
    .dw    #_Dummy_EI ; INT223
    .dw    #_Dummy_EI ; INT224
    .dw    #_Dummy_EI ; INT225
    .dw    #_Dummy_EI ; INT226
    .dw    #_Dummy_EI ; INT227
    .dw    #_Dummy_EI ; INT228
    .dw    #_Dummy_EI ; INT229
    .dw    #_Dummy_EI ; INT230
    .dw    #_Dummy_EI ; INT231
    .dw    #_Dummy_EI ; INT232
    .dw    #_Dummy_EI ; INT233
    .dw    #_Dummy_EI ; INT234
    .dw    #_Dummy_EI ; INT235
    .dw    #_Dummy_EI ; INT236     20220515/not-used/INTRLIN35   /RLIN35-interrupt
    .dw    #_INTRLIN35UR0 ; INT237 20220515/  IN-USE/INTRLIN35UR0/RLIN35 transmit interrupt
    .dw    #_Dummy_EI ; INT238     20220515/not-used/INTRLIN30UR1/RLIN35-receive-complete-interrupt
    .dw    #_Dummy_EI ; INT239     20220515/not-used/INTRLIN30UR2/RLIN35-status-interrupt
    .dw    #_Dummy_EI ; INT240
    .dw    #_Dummy_EI ; INT241
    .dw    #_Dummy_EI ; INT242
    .dw    #_Dummy_EI ; INT243
    .dw    #_Dummy_EI ; INT244
    .dw    #_Dummy_EI ; INT245
    .dw    #_Dummy_EI ; INT246
    .dw    #_Dummy_EI ; INT247
    .dw    #_Dummy_EI ; INT248
    .dw    #_Dummy_EI ; INT249
    .dw    #_Dummy_EI ; INT250
    .dw    #_Dummy_EI ; INT251
    .dw    #_Dummy_EI ; INT252
    .dw    #_Dummy_EI ; INT253
    .dw    #_Dummy_EI ; INT254
    .dw    #_Dummy_EI ; INT255
    .dw    #_Dummy_EI ; INT256
    .dw    #_Dummy_EI ; INT257
    .dw    #_Dummy_EI ; INT258
    .dw    #_Dummy_EI ; INT259
    .dw    #_Dummy_EI ; INT260
    .dw    #_Dummy_EI ; INT261
    .dw    #_Dummy_EI ; INT262
    .dw    #_Dummy_EI ; INT263
    .dw    #_Dummy_EI ; INT264
    .dw    #_Dummy_EI ; INT265
    .dw    #_Dummy_EI ; INT266
    .dw    #_Dummy_EI ; INT267
    .dw    #_Dummy_EI ; INT268
    .dw    #_Dummy_EI ; INT269
    .dw    #_Dummy_EI ; INT270
    .dw    #_Dummy_EI ; INT271
    .dw    #_Dummy_EI ; INT272
    .dw    #_Dummy_EI ; INT273
    .dw    #_Dummy_EI ; INT274
    .dw    #_Dummy_EI ; INT275
    .dw    #_Dummy_EI ; INT276
    .dw    #_Dummy_EI ; INT277
    .dw    #_Dummy_EI ; INT278
    .dw    #_Dummy_EI ; INT279
    .dw    #_Dummy_EI ; INT280
    .dw    #_Dummy_EI ; INT281
    .dw    #_Dummy_EI ; INT282
    .dw    #_Dummy_EI ; INT283
    .dw    #_Dummy_EI ; INT284
    .dw    #_Dummy_EI ; INT285
    .dw    #_Dummy_EI ; INT286
    .dw    #_Dummy_EI ; INT287
    .dw    #_Dummy_EI ; INT288
    .dw    #_Dummy_EI ; INT289
    .dw    #_Dummy_EI ; INT290  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT291  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT292  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT293  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT294  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT295  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT296  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT297  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT298
    .dw    #_Dummy_EI ; INT299
    .dw    #_Dummy_EI ; INT300
    .dw    #_Dummy_EI ; INT301
    .dw    #_Dummy_EI ; INT302
    .dw    #_Dummy_EI ; INT303
    .dw    #_Dummy_EI ; INT304
    .dw    #_Dummy_EI ; INT305
    .dw    #_Dummy_EI ; INT306
    .dw    #_Dummy_EI ; INT307
    .dw    #_Dummy_EI ; INT308
    .dw    #_Dummy_EI ; INT309
    .dw    #_Dummy_EI ; INT310
    .dw    #_Dummy_EI ; INT311
    .dw    #_Dummy_EI ; INT312
    .dw    #_Dummy_EI ; INT313
    .dw    #_OSTM5_interrupt ; INT314
    .dw    #_Dummy_EI ; INT315
    .dw    #_Dummy_EI ; INT316
    .dw    #_Dummy_EI ; INT317
    .dw    #_Dummy_EI ; INT318
    .dw    #_Dummy_EI ; INT319
    .dw    #_Dummy_EI ; INT320
    .dw    #_Dummy_EI ; INT321
    .dw    #_Dummy_EI ; INT322
    .dw    #_Dummy_EI ; INT323
    .dw    #_Dummy_EI ; INT324  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT325  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT326
    .dw    #_Dummy_EI ; INT327
    .dw    #_Dummy_EI ; INT328
    .dw    #_Dummy_EI ; INT329
    .dw    #_Dummy_EI ; INT330
    .dw    #_Dummy_EI ; INT331
    .dw    #_Dummy_EI ; INT332
    .dw    #_Dummy_EI ; INT333
    .dw    #_Dummy_EI ; INT334
    .dw    #_Dummy_EI ; INT335  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT336  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT337  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT338  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT339  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT340  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT341  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT342  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT343  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT344  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT345  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT346  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT347  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT348  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT349  ;DO-NOT-USE, Reserved by hardware(f1h)
    .dw    #_Dummy_EI ; INT350  ;DO-NOT-USE, Reserved by hardware(f1h)

    .section "SYSTEMCALLTBL", const
    .align	512
    .dw    #_SYSCALL_ERR_TEST     -   #__sSYSTEMCALLTBL     ;0
    .dw    #_sysEnterSystemCall   -   #__sSYSTEMCALLTBL     ;1 
    .dw    #_sysExitSystemCall    -   #__sSYSTEMCALLTBL     ;2 
    .dw    #_sysCallSystemServiceHandler   -   #__sSYSTEMCALLTBL    ;3
    .dw    #_sysCallPrintTextHandler   -   #__sSYSTEMCALLTBL    ;4
    .dw    #_sysCallPrintText_R35Handler   -   #__sSYSTEMCALLTBL    ;5
    .dw    #_sysCallTrustFuncHandler   -   #__sSYSTEMCALLTBL    ;6

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

    .section ".text", text
	.align	2

;-----------------------------------------------------------------------------
;	startup
;-----------------------------------------------------------------------------
	.section	".text", text
	.align	2
	.public	__start
__start:
$if 1	; initialize register
	$nowarning
	mov	r0, r1
	$warning
	mov	r0, r2
	mov	r0, r3
	mov	r0, r4
	mov	r0, r5
	mov	r0, r6
	mov	r0, r7
	mov	r0, r8
	mov	r0, r9
	mov	r0, r10
	mov	r0, r11
	mov	r0, r12
	mov	r0, r13
	mov	r0, r14
	mov	r0, r15
	mov	r0, r16
	mov	r0, r17
	mov	r0, r18
	mov	r0, r19
	mov	r0, r20
	mov	r0, r21
	mov	r0, r22
	mov	r0, r23
	mov	r0, r24
	mov	r0, r25
	mov	r0, r26
	mov	r0, r27
	mov	r0, r28
	mov	r0, r29
	mov	r0, r30
	mov	r0, r31
	ldsr	r0, 0, 0		;  EIPC
	ldsr	r0, 16, 0		;  CTPC
$endif

$if 1
	; jump to entry point of each PE
	stsr	0, r10, 2		; get HTCFG0
	shr	16, r10			    ; get PEID
	cmp	1, r10
	bz	.L.entry_PE1
	cmp	2, r10
	bz	.L.entry_PE2
	cmp	3, r10
	bz	.L.entry_PE3
	cmp	4, r10
	bz	.L.entry_PE4
	cmp	5, r10
	bz	.L.entry_PE5
	cmp	6, r10
	bz	.L.entry_PE6
	cmp	7, r10
	bz	.L.entry_PE7
__exit:
	br	__exit

.L.entry_PE1:
	jarl	_hdwinit_PE1, lp	; initialize hardware
$ifdef USE_TABLE_REFERENCE_METHOD
	mov	    #__sEIINTTBL_PE1, r6
	jarl	_set_table_reference_method, lp ; set table reference method
$endif
$ifdef USE_SYSTEM_CALL
    mov	    #__sSYSTEMCALLTBL, r6    ; used as SCBP value
    mov     6, r7                    ; we use syscall 1~2, so set 2 to SCCFG (0 is default)
    jarl    _set_system_call_reg, lp ; set SCBP, SCCFG
$endif
	jr32	__cstart_pe1

.L.entry_PE2:
	jarl	_hdwinit_PE2, lp	; initialize hardware
$ifdef USE_TABLE_REFERENCE_METHOD
	mov     #__sEIINTTBL_PE1, r6            ; here, if you really want, you can set other table
	jarl    _set_table_reference_method, lp ; set table reference method
$endif
$ifdef USE_SYSTEM_CALL
    mov	    #__sSYSTEMCALLTBL, r6    ; used as SCBP value
    mov     6, r7                    ; we use syscall 1~2, so set 2 to SCCFG (0 is default)
    jarl    _set_system_call_reg, lp ; set SCBP, SCCFG
$endif
	jr32	__cstart_pe2
	br	__exit

.L.entry_PE3:
	br	__exit
.L.entry_PE4:
	br	__exit
.L.entry_PE5:
	br	__exit
.L.entry_PE6:
	br	__exit
.L.entry_PE7:
	br	__exit
$endif

;-----------------------------------------------------------------------------
;	hdwinit_PE1
; Specify RAM addresses suitable to your system if needed.
;-----------------------------------------------------------------------------
	GLOBAL_RAM_A_ADDR	.set	0xFEEF8000
	GLOBAL_RAM_A_END    .set	0xFEEFFFFF
	GLOBAL_RAM_B_ADDR	.set	0xFEFF0000
	GLOBAL_RAM_B_END    .set	0xFEFFFFFF
    RETENTION_RAM_ADDR	.set	0xFEF01000  ; there is a special area for STARTUP_LOCK in boot2.asm
	RETENTION_RAM_END	.set	0xFEF0FFFF  ; so we start from 0xFEF01000 instead of 0xFEF00000
    SELF_RAM_PE1_ADDR	.set	0xFEDC0000
	SELF_RAM_PE1_END	.set	0xFEDFFFFF
	LOCAL_RAM_PE1_ADDR	.set	0xFEBC0000
	LOCAL_RAM_PE1_END	.set	0xFEBFFFFF

	.align	2
_hdwinit_PE1:
	mov	lp, r14    ; save return address

	; clear Local RAM PE1
	mov	LOCAL_RAM_PE1_ADDR, r6
	mov	LOCAL_RAM_PE1_END, r7
	jarl	_zeroclr4, lp
	
    ; clear SELF RAM PE1
	mov	SELF_RAM_PE1_ADDR, r6
	mov	SELF_RAM_PE1_END, r7
	jarl	_zeroclr4, lp

    ; clear RETENTION RAM 
	mov	RETENTION_RAM_ADDR, r6
	mov	RETENTION_RAM_END, r7
	jarl	_zeroclr4, lp

	; clear Global RAM 1
	mov	GLOBAL_RAM_A_ADDR, r6
	mov	GLOBAL_RAM_A_END, r7
	jarl	_zeroclr4, lp
	
	; clear Global RAM 2
	mov	GLOBAL_RAM_B_ADDR, r6
	mov	GLOBAL_RAM_B_END, r7
	jarl	_zeroclr4, lp

	mov	r14, lp
	jmp	[lp]

;-----------------------------------------------------------------------------
;	hdwinit_PE2
; Specify RAM addresses suitable to your system if needed.
;-----------------------------------------------------------------------------
	SELF_RAM_PE2_ADDR	.set	0xFEDE0000
	SELF_RAM_PE2_END	.set	0xFEDFFFFF
    LOCAL_RAM_PE2_ADDR	.set	0xFE9E0000
	LOCAL_RAM_PE2_END	.set	0xFE9FFFFF
    ;RETENTION_RAM_RESERVED_PE2_ADDR .set	0xFEF00000  ; there is a special area for STARTUP_LOCK in boot2.asm
	;RETENTION_RAM_RESERVED_PE2_END  .set	0xFEF01000  ; so we let PE2 clear this area 

	.align	2
_hdwinit_PE2:
	mov	lp, r14    ; save return address

	; clear Local RAM PE2
	mov	LOCAL_RAM_PE2_ADDR, r6
	mov	LOCAL_RAM_PE2_END, r7
	jarl	_zeroclr4, lp

    ; clear SELF RAM PE2
	mov	SELF_RAM_PE2_ADDR, r6
	mov	SELF_RAM_PE2_END, r7
	jarl	_zeroclr4, lp

    ; clear RETENTION_RAM RESERVED for PE2
	;mov	RETENTION_RAM_RESERVED_PE2_ADDR, r6
	;mov	RETENTION_RAM_RESERVED_PE2_END, r7
	;jarl	_zeroclr4, lp

	mov	r14, lp
	jmp	[lp]

;-----------------------------------------------------------------------------
;	zeroclr4
;-----------------------------------------------------------------------------
	.align	2
_zeroclr4:
	br	.L.zeroclr4.2
.L.zeroclr4.1:
	st.w	r0, [r6]
	add	4, r6
.L.zeroclr4.2:
	cmp	r6, r7
	bh	.L.zeroclr4.1
	jmp	[lp]


;-----------------------------------------------------------------------------
;	set table reference method
;-----------------------------------------------------------------------------
$ifdef USE_TABLE_REFERENCE_METHOD
	; interrupt control register address
	ICBASE	.set	0xfffeea00

	.align	2
_set_table_reference_method:
	ldsr	r6, 4, 1		; set INTBP
    ;ldsr	r7, 12, 1		; set SCBP ;20221016 why set here? we can set it at _set_system_call_reg

	mov	ICBASE, r10		; get interrupt control register address
	set1	6, 0[r10]		; set INT0  as table reference
	set1	6, 2[r10]		; set INT1  as table reference
	set1	6, 4[r10]		; set INT2  as table reference
    ;20221016 we only set 3 INT above, as an initialization example 
    ;but in fact, in ISR-Init, we set INT (which we use) as table reference one by one

	jmp	[lp]
$endif

$ifdef USE_SYSTEM_CALL
_set_system_call_reg:
	ldsr	r6, 12, 1		; set SCBP
    ldsr	r7, 11, 1		; set SCCFG
	jmp	[lp]
$endif