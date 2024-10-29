//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_SWC_MODE_A_H
#define RTE_SWC_MODE_A_H

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_SWC_Mode_A_Type.h"

FUNC(void, AUTOMATIC) Runnable_modeSwitch_1();
#define RTE_RUNNABLE_Runnable_modeSwitch_1 Runnable_modeSwitch_1


FUNC(void, AUTOMATIC) Runnable_modeSwitch_2();
#define RTE_RUNNABLE_Runnable_modeSwitch_2 Runnable_modeSwitch_2


/********************************************/
//Runnable declaration shouldn't be put btw #ifdef~#endif, otherise, os application can't access it.
//make sure only specific runnable.c can invoke these functions.
#ifdef RTE_Runnable_modeSwitch_1_C
#endif
#ifdef RTE_Runnable_modeSwitch_2_C
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_SWC_MODE_A_H */