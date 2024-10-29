//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_CLIENT_H
#define RTE_CLIENT_H

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_Client_Type.h"

FUNC(Impl_uint16, AUTOMATIC) Client();
#define RTE_RUNNABLE_Client Client

#ifdef RTE_CLIENT_C
Impl_uint8 Rte_Prm_ClientRport_speed();
Impl_uint16 Rte_Prm_ClientRport_height();
#endif

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_CLIENT_H */