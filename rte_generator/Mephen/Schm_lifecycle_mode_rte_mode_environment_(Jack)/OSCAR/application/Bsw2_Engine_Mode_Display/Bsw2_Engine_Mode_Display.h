// [SWS_Rte_07508] All definitions within in the Module Interlink Header File shall be preceded by the following fragment:
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef BSW2_ENGINE_MODE_DISPLAY_H
#define BSW2_ENGINE_MODE_DISPLAY_H

#include "../ring_buffer.h"
#include "../SchM_Mode_Data_Management_Cfg.h"
#include "../SchM_Sender_Receive_Data_Management_Cfg.h"
#include "../SchM_Client_Server_Data_Management_Cfg.h"
#include "../Bsw_Event_Cfg.h"
#include "Bsw2_Engine_Mode_Display_Type.h"

FUNC(void,AUTOMATIC) SCHM_BE_0();
#ifdef SCHM_API_BE_0
#endif

FUNC(void,AUTOMATIC) SCHM_BE_1();
#ifdef SCHM_API_BE_1
#endif

FUNC(void,AUTOMATIC) SCHM_BE_2();
#ifdef SCHM_API_BE_2
#endif

FUNC(void,AUTOMATIC) SCHM_BE_3();
#ifdef SCHM_API_BE_3
#endif

FUNC(void,AUTOMATIC) SCHM_BE_4();
#ifdef SCHM_API_BE_4
#endif

FUNC(void,AUTOMATIC) SCHM_BE_5();
#ifdef SCHM_API_BE_5
SchMModeType SchM_Mode_Bsw2_Engine_Mode_Display_Engine_MDGroup();
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode0_Exit();
#ifdef SCHM_API_BE_Mode0_Exit
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode0_Transition();
#ifdef SCHM_API_BE_Mode0_Transition
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode0_Entry();
#ifdef SCHM_API_BE_Mode0_Entry
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode1_Exit();
#ifdef SCHM_API_BE_Mode1_Exit
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode1_Transition();
#ifdef SCHM_API_BE_Mode1_Transition
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode1_Entry();
#ifdef SCHM_API_BE_Mode1_Entry
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode2_Exit();
#ifdef SCHM_API_BE_Mode2_Exit
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode2_Transition();
#ifdef SCHM_API_BE_Mode2_Transition
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode2_Entry();
#ifdef SCHM_API_BE_Mode2_Entry
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode3_Exit();
#ifdef SCHM_API_BE_Mode3_Exit
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode3_Transition();
#ifdef SCHM_API_BE_Mode3_Transition
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode3_Entry();
#ifdef SCHM_API_BE_Mode3_Entry
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode4_Exit();
#ifdef SCHM_API_BE_Mode4_Exit
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode4_Transition();
#ifdef SCHM_API_BE_Mode4_Transition
#endif

FUNC(void,AUTOMATIC) SCHM_BE_Mode4_Entry();
#ifdef SCHM_API_BE_Mode4_Entry
#endif

#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */
