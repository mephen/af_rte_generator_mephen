#ifdef __cplusplus /* [SWS_Rte_03709] */
extern "C" {
#endif /* __cplusplus */

#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE

#include "Rte_Observation_Type.h"
FUNC(void,AUTOMATIC) ReRxAcc();
#define RTE_RUNNABLE_ReRxAcc ReRxAcc

FUNC(void,AUTOMATIC) ReRxSpd();
#define RTE_RUNNABLE_ReRxSpd ReRxSpd

FUNC(void,AUTOMATIC) ReRxTemp();
#define RTE_RUNNABLE_ReRxTemp ReRxTemp

typedef struct Rte_CDS_Observation Rte_CDS_Observation;
//struct Rte_CDS_Observation { <component data sections> }; 
 
#ifdef RTE_RUNNABLEAPI_ReRxAcc
void Rte_Read_RpIfVehAcc_Acc(Impl_uint16* data, Std_TransformerError transformerError);
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxAcc
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxSpd
Impl_uint16 Rte_DRead_RpIfVehSpd_Spd();
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxSpd
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxTemp
void Rte_Receive_RpIfTemperature_Temp(Impl_uint16* data, Std_TransformerError transformerError);
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReRxTemp
 
#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */