#ifndef TRUSTEDFUNC_CFG_H
#define TRUSTEDFUNC_CFG_H

/* This file content the generated configuration of task */

/*==================[inclusions]=============================================*/
#include "typedefine.h"

/*==================[macros]=================================================*/

#define TRUSTED_FUNC_COUNT_CORE0 3
#define TRUSTED_FUNC_COUNT_CORE1 2

#define TF_AIMER     0X00000000
#define TF_IKURA   0X00000001
#define TF_YORUSHIKA    0X00000002

#define TF_YUURI   0X00010000
#define TF_HITORIE    0X00010001

#define INVALID_TF_ID 0X00020000

extern TrustedFuncPtrType* TF_array[2];
extern TrustedFuncPtrType TF_array_core0[TRUSTED_FUNC_COUNT_CORE0];
extern TrustedFuncPtrType TF_array_core1[TRUSTED_FUNC_COUNT_CORE1];
extern TrustedFunctionAutosarType TrustedFuncAutosar_core0[TRUSTED_FUNC_COUNT_CORE0];
extern TrustedFunctionAutosarType TrustedFuncAutosar_core1[TRUSTED_FUNC_COUNT_CORE1];

/*============================================================================*/


// app_lion
extern void TRUSTED_TF_AIMER( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);
extern void TRUSTED_TF_IKURA( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);
extern void TRUSTED_TF_YORUSHIKA( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);

// app2
extern void TRUSTED_TF_YUURI( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);
extern void TRUSTED_TF_HITORIE( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para);

// extern TrustedFuncPtrType TF_array_core0[0];
// extern TrustedFuncPtrType TF_array_core1[0];

#endif /* TRUSTEDFUNC_CFG_H */