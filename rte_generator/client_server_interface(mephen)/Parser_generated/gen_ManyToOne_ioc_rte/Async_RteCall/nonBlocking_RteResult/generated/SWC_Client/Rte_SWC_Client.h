//VFB interface(api) & Runnable Declaration
//----------------------------------------------------------------
#ifndef RTE_SWC_CLIENT_H
#define RTE_SWC_CLIENT_H

#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "Rte_SWC_Client_Type.h"
#include "../Rte_Cs_Data_Management.h"

extern RingBuffer RB_response_Client_1;//if client use sync_rte_call to get the response, each client runnable has its own response ringbuffer.
extern int request_number_Client_1;//shared by 1 specific client response runnable
FUNC(Impl_uint16, AUTOMATIC) Client_1();//[SWS_Rte_07194] 'Impl_uint16' only for test case, return value will be 'void' in real case
#define RTE_RUNNABLE_Client_1 Client_1//[SWS_Rte_06713]


extern RingBuffer RB_response_Client_Response_1;//if client use Rte_result to get the response, each client response runnable has its own response ringbuffer.
//Runnable declaration shouldn't be put btw #ifdef~#endif, otherise, os application can't access it.
FUNC(Impl_uint16, AUTOMATIC) Client_Response_1();//Impl_uint16 of return value is for testing
#define RTE_RUNNABLE_Client_Response_1 Client_Response_1


extern RingBuffer RB_response_Client_2;
extern int request_number_Client_2;
FUNC(Impl_uint16, AUTOMATIC) Client_2();
#define RTE_RUNNABLE_Client_2 Client_2


extern RingBuffer RB_response_Client_Response_2;
FUNC(Impl_uint16, AUTOMATIC) Client_Response_2();
#define RTE_RUNNABLE_Client_Response_2 Client_Response_2


extern RingBuffer RB_response_Client_3;
extern int request_number_Client_3;
FUNC(Impl_uint16, AUTOMATIC) Client_3();
#define RTE_RUNNABLE_Client_3 Client_3


extern RingBuffer RB_response_Client_Response_3;
FUNC(Impl_uint16, AUTOMATIC) Client_Response_3();
#define RTE_RUNNABLE_Client_Response_3 Client_Response_3

/********************************************/
//make sure only specific runnable.c can invoke these functions.
#ifdef RTE_Client_1_C
/*intra_partition*/
Std_ReturnType Rte_Call_SWC_Client_Rport1_SyncRteAdd_Client_1(Impl_uint16, Impl_uint16, Impl_uint16*);
Std_ReturnType Rte_Call_SWC_Client_Rport1_AsyncRteRteAdd_Client_1(Impl_uint16, Impl_uint16);
#endif
#ifdef RTE_Client_Response_1_C
Std_ReturnType Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_1(Impl_uint16*);
#endif
#ifdef RTE_Client_2_C
/*intra_partition*/
Std_ReturnType Rte_Call_SWC_Client_Rport1_SyncRteAdd_Client_2(Impl_uint16, Impl_uint16, Impl_uint16*);
Std_ReturnType Rte_Call_SWC_Client_Rport1_AsyncRteRteAdd_Client_2(Impl_uint16, Impl_uint16);
#endif
#ifdef RTE_Client_Response_2_C
Std_ReturnType Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_2(Impl_uint16*);
#endif
#ifdef RTE_Client_3_C
/*inter_partition*/
Std_ReturnType Rte_Call_SWC_Client_Rport1_SyncIocMultiply_Client_3(Impl_uint16, Impl_uint16, Impl_uint16*);
Std_ReturnType Rte_Call_SWC_Client_Rport1_AsyncRteIocMultiply_Client_3(Impl_uint16, Impl_uint16);
#endif
#ifdef RTE_Client_Response_3_C
Std_ReturnType Rte_Result_SWC_Client_Rport1_NonBlocking_Client_Response_3(Impl_uint16*);
#endif
/********************************************/

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_SWC_CLIENT_H */