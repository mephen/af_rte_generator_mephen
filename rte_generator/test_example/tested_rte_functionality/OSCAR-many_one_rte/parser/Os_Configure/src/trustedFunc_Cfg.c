/* This file content the generated configuration of trustedFunction */

/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "application_Cfg.h"
#include "trustedFunc_Cfg.h"
#include "resource_Cfg.h"

#pragma section

TrustedFuncPtrType* TF_array[2] = {
    TF_array_core0,
    TF_array_core1,
};

TrustedFuncPtrType TF_array_core0[TRUSTED_FUNC_COUNT_CORE0] = {
    TRUSTED_TF_cola,
    TRUSTED_TF_juice,
    TRUSTED_TF_water,
    TRUSTED_TF_yes,
};
TrustedFuncPtrType TF_array_core1[TRUSTED_FUNC_COUNT_CORE1] = {
    TRUSTED_TF_me,
    TRUSTED_TF_no,
};
trustedFunctionAutosarType trustedFunctionAutosar_core0[TRUSTED_FUNC_COUNT_CORE0] = {
    /* TRUSTED_TF_cola */
    {
        App1,
        0
    },
    /* TRUSTED_TF_juice */
    {
        App1,
        0
    },
    /* TRUSTED_TF_water */
    {
        App1,
        0
    },
    /* TRUSTED_TF_yes */
    {
        App3,
        0
    },
};
trustedFunctionAutosarType trustedFunctionAutosar_core0[TRUSTED_FUNC_COUNT_CORE1] = {
    /* TRUSTED_TF_me */
    {
        App2,
        0
    },
    /* TRUSTED_TF_no */
    {
        App4,
        0
    },
};
#pragma section
