#ifdef __cplusplus /* [SWS_Rte_03709] */
extern "C" {
#endif /* __cplusplus */

#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE

#include "Rte_Observation2_Type.h"
FUNC(void,AUTOMATIC) ReRxAcc2();
#define RTE_RUNNABLE_ReRxAcc2 ReRxAcc2

FUNC(void,AUTOMATIC) ReRxSpd2();
#define RTE_RUNNABLE_ReRxSpd2 ReRxSpd2

FUNC(void,AUTOMATIC) ReRxTemp2();
#define RTE_RUNNABLE_ReRxTemp2 ReRxTemp2

typedef struct Rte_CDS_Observation2 Rte_CDS_Observation2;
//struct Rte_CDS_Observation2 { <component data sections> }; 
 
#ifdef RTE_RUNNABLEAPI_ReRxAcc2
Std_ReturnType Rte_Read_RpIfVehAcc2_Acc(Impl_uint16* data, Std_TransformerError transformerError);
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxAcc2
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxSpd2
Impl_uint16 Rte_DRead_RpIfVehSpd2_Spd();
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxSpd2
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxTemp2
void Rte_Receive_RpIfTemperature2_Temp(Impl_uint16* data, Std_TransformerError transformerError);
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxTemp2
 
#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */