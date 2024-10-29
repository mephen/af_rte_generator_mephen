// [SWS_Rte_07508] All definitions within in the Module Interlink Header File shall be preceded by the following fragment:
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef BSW1_ENGINE_CONTROLLER_H
#define BSW1_ENGINE_CONTROLLER_H

#include "../ring_buffer.h"
#include "../SchM_Mode_Data_Management_Cfg.h"
#include "../SchM_Sender_Receive_Data_Management_Cfg.h"
#include "../SchM_Client_Server_Data_Management_Cfg.h"
#include "../Bsw_Event_Cfg.h"
#include "Bsw1_Engine_Controller_Type.h"

extern int IB_Engine_Controller_timeout_count;
FUNC(void,AUTOMATIC) SCHM_BE_Engine_ModeSwitch();
#ifdef SCHM_API_BE_Engine_ModeSwitch
Std_ReturnType SchM_Switch_Bsw1_Engine_Controller_Engine_MDGroup(SchMModeType mode);
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Engine_Test();
#ifdef SCHM_API_BE_Engine_Test
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Engine_ModeSwitchAck();
#ifdef SCHM_API_BE_Engine_ModeSwitchAck
#endif

#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */
