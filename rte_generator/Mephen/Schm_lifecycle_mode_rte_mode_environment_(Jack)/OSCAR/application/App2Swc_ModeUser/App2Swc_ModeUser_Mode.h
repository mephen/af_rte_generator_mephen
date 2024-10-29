/* [SWS_Rte_03709] */
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef APP2SWC_MODEUSER_MODE_H
#define APP2SWC_MODEUSER_MODE_H

#include "../ring_buffer.h"
#include "../Rte_Mode_Data_Management_Cfg.h"
#include "../Rte_Event_Cfg.h"
#include "App2Swc_ModeUser_Mode_Type.h"

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_3();
#ifdef RTE_RUNNABLEAPI_RE_3
RteModeType Rte_Mode_ModeSwitchInterface_RPort_AC_Manager_MDGroup();
#endif

#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */
