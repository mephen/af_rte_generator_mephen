// [SWS_Rte_07508] All definitions within in the Module Interlink Header File shall be preceded by the following fragment:
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#ifndef BSW12_LIFECYCLE1_H
#define BSW12_LIFECYCLE1_H

#include "../ring_buffer.h"
#include "../SchM_Mode_Data_Management_Cfg.h"
#include "../SchM_Sender_Receive_Data_Management_Cfg.h"
#include "../SchM_Client_Server_Data_Management_Cfg.h"
#include "../Bsw_Event_Cfg.h"
#include "Bsw12_lifecycle1_Type.h"

FUNC(void,AUTOMATIC) SCHM_BE_background1();
#ifdef SCHM_API_BE_background1
#endif

FUNC(void,AUTOMATIC) SCHM_BE_timing1();
#ifdef SCHM_API_BE_timing1
#endif

#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */
