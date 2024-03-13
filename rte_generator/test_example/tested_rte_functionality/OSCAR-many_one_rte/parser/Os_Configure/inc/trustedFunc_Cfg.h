#ifndef TRUSTEDFUNC_CFG_H
#define TRUSTEDFUNC_CFG_H
/* This file content the generated configuration of task */

/*==================[inclusions]=============================================*/
#include "typedefine.h"
/*==================[macros]=================================================*/
#define TRUSTED_FUNC_COUNT_CORE0 4
#define TRUSTED_FUNC_COUNT_CORE1 2

#define TF_cola    0x00000000
#define TF_juice    0x00000001
#define TF_water    0x00000002
#define TF_yes    0x00000003
#define TF_me    0x00010000
#define TF_no    0x00010001
#define INVALID_TF_ID 0X00020000

/*============================================================================*/
extern TrustedFuncPtrType* TF_array[2];
extern TrustedFuncPtrType TF_array_core0[TRUSTED_FUNC_COUNT_CORE0];
extern TrustedFuncPtrType TF_array_core1[TRUSTED_FUNC_COUNT_CORE1];
extern TrustedFunctionAutosarType TrustedFuncAutosar_core0[TRUSTED_FUNC_COUNT_CORE0];
extern TrustedFunctionAutosarType TrustedFuncAutosar_core1[TRUSTED_FUNC_COUNT_CORE1];
/*============================================================================*/
/* App1 */
extern void TRUSTED_TF_cola( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);
extern void TRUSTED_TF_juice( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);
extern void TRUSTED_TF_water( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);
/* App2 */
extern void TRUSTED_TF_me( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);
/* App3 */
extern void TRUSTED_TF_yes( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);
/* App4 */
extern void TRUSTED_TF_no( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);
/*==================[end of file]============================================*/
#endif /* TRUSTEDFUNC_CFG_H */
