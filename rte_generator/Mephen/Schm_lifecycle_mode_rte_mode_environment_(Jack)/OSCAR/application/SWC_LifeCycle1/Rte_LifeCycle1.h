//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_LifeCycle1
#define RTE_LifeCycle1

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_LifeCycle1_Type.h"

FUNC(void, AUTOMATIC) RTE_timing1();
#define RTE_RUNNABLE_RTE_timing1 RTE_timing1

FUNC(void, AUTOMATIC) RTE_background1();
#define RTE_RUNNABLE_RTE_background1 RTE_background1

FUNC(void, AUTOMATIC) RTE_init1();
#define RTE_RUNNABLE_RTE_init1 RTE_init1

FUNC(void, AUTOMATIC) RTE_init2();
#define RTE_RUNNABLE_RTE_init2 RTE_init2

/********************************************/
//make sure only specific runnable.c can invoke these functions.
#if defined(RTE_TIMING1_C) || defined(RTE_EVENT_CFG_C)
    //VFB interface(RTE api) 
#endif

#if defined(RTE_BACKGROUND1_C) || defined(RTE_EVENT_CFG_C)
    //VFB interface(RTE api) 
#endif

#if defined(RTE_INIT1_C) || defined(RTE_EVENT_CFG_C)
    //VFB interface(RTE api) 
#endif

#if defined(RTE_INIT2_C) || defined(RTE_EVENT_CFG_C)
    //VFB interface(RTE api) 
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_LifeCycle1 */