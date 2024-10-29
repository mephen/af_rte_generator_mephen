//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_SWC_LIFECYCLE_H
#define RTE_SWC_LIFECYCLE_H

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_SWC_LifeCycle_Type.h"

FUNC(void, AUTOMATIC) Runnable_background_1();
#define RTE_RUNNABLE_Runnable_background_1 Runnable_background_1


FUNC(void, AUTOMATIC) Runnable_timing_1();
#define RTE_RUNNABLE_Runnable_timing_1 Runnable_timing_1


FUNC(void, AUTOMATIC) Runnable_init_1();
#define RTE_RUNNABLE_Runnable_init_1 Runnable_init_1


FUNC(void, AUTOMATIC) Runnable_init_2();
#define RTE_RUNNABLE_Runnable_init_2 Runnable_init_2


/********************************************/
//Runnable declaration shouldn't be put btw #ifdef~#endif, otherise, os application can't access it.
//make sure only specific runnable.c can invoke these functions.
#ifdef RTE_Runnable_background_1_C
#endif
#ifdef RTE_Runnable_timing_1_C
#endif
#ifdef RTE_Runnable_init_1_C
#endif
#ifdef RTE_Runnable_init_2_C
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_SWC_LIFECYCLE_H */