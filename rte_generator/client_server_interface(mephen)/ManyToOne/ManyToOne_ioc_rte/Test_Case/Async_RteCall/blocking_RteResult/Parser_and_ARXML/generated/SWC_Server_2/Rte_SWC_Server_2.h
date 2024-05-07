//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_SWC_SERVER_2_H
#define RTE_SWC_SERVER_2_H

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_SWC_Server_2_Type.h"
#include "../Rte_Cs_Data_Management.h"

extern RingBuffer RB_request_Server2_SR1;//each server runnable has its own request buffer.
FUNC(Impl_uint16, AUTOMATIC) Server2_SR1();
#define RTE_RUNNABLE_Server2_SR1 Server2_SR1;

/********************************************/
//make sure only specific runnable.c can invoke these functions.
#ifdef RTE_Server2_SR1_C
Impl_uint16 Multiply_ImplUint16_Server2_SR1();
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_SWC_SERVER_2_H */