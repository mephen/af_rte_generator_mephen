/* [SWS_Rte_03709] */
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef APP2SWC_MODEUSER_H
#define APP2SWC_MODEUSER_H

#include "../ring_buffer.h"
#include "../Rte_Mode_Data_Management_Cfg.h"
#include "../Rte_Event_Cfg.h"
#include "App2Swc_ModeUser_Type.h"

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_Mode0_Entry();
#ifdef RTE_RUNNABLEAPI_RE_Mode0_Entry
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_Mode0_Exit();
#ifdef RTE_RUNNABLEAPI_RE_Mode0_Exit
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_Mode0_Transition();
#ifdef RTE_RUNNABLEAPI_RE_Mode0_Transition
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_Mode1_Entry();
#ifdef RTE_RUNNABLEAPI_RE_Mode1_Entry
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_Mode1_Exit();
#ifdef RTE_RUNNABLEAPI_RE_Mode1_Exit
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_Mode1_Transition();
#ifdef RTE_RUNNABLEAPI_RE_Mode1_Transition
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_Mode2_Entry();
#ifdef RTE_RUNNABLEAPI_RE_Mode2_Entry
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_Mode2_Exit();
#ifdef RTE_RUNNABLEAPI_RE_Mode2_Exit
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_Mode2_Transition();
#ifdef RTE_RUNNABLEAPI_RE_Mode2_Transition
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_0();
#ifdef RTE_RUNNABLEAPI_RE_0
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_1();
#ifdef RTE_RUNNABLEAPI_RE_1
#endif

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_2();
#ifdef RTE_RUNNABLEAPI_RE_2
#endif

#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */
