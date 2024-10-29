/* [SWS_Rte_03709] */
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef APP1SWC_MODEMANAGER_MODE_H
#define APP1SWC_MODEMANAGER_MODE_H

#include "../ring_buffer.h"
#include "../Rte_Mode_Data_Management_Cfg.h"
#include "../Rte_Event_Cfg.h"
#include "App1Swc_ModeManager_Mode_Type.h"

FUNC(void,AUTOMATIC) RTE_RUNNABLE_RE_AC_ModeSwitch();
#ifdef RTE_RUNNABLEAPI_RE_AC_ModeSwitch
void Rte_Switch_ModeSwitchInterface_PPort_AC_Manager_MDGroup(RteModeType mode);
#endif

#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */
