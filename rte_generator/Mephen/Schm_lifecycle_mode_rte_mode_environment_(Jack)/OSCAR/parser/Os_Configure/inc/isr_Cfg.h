#ifndef ISR_CFG_H
#define ISR_CFG_H
#/* This file content the generated configuration of isr */
/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "os_Cfg.h"
#include "iodefine.h"
#/*==================[macros]=================================================*/

#define ISR1_COUNT_CORE0 4U
#define ISR2_COUNT_CORE0 2U
#define ISR_ALL_COUNT_CORE0 6U

#define ISR1_COUNT_CORE1 4U
#define ISR2_COUNT_CORE1 2U
#define ISR_ALL_COUNT_CORE1 6U

#define ISR_ALL_COUNT_ALL_CORE 12U

/* core0 */
#define I005 0x00000000
#define I006 0x00000001
#define I001 0x00000002  //isr1
#define I002 0x00000003  //isr1
#define I003 0x00000004  //isr1
#define I004 0x00000005  //isr1
/* core1 */
#define I105 0x00010000
#define I106 0x00010001
#define I101 0x00010002  //isr1
#define I102 0x00010003  //isr1
#define I103 0x00010004  //isr1
#define I104 0x00010005  //isr1
#define INVALID_ISR_ID   0X00020000

extern IsrConstType Isr_const_core0[ISR_ALL_COUNT_CORE0];
extern IsrConstType Isr_const_core1[ISR_ALL_COUNT_CORE1];
extern IsrConstRefType Isr_const[OsNumberOfCores];

extern IsrAutosarType IsrAutosar_core0[ISR_ALL_COUNT_CORE0];
extern IsrAutosarType IsrAutosar_core1[ISR_ALL_COUNT_CORE1];

/*==================[external functions declaration]=========================*/
/*==================[end of file]============================================*/
#endif /* #ifndef ISR_CFG_H */
