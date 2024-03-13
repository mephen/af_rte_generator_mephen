#ifdef __cplusplus /* [SWS_Rte_03709] */
extern "C" {
#endif /* __cplusplus */

#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE

#include "Rte_Controller_Type.h"
FUNC(void,AUTOMATIC) ReTxTemp();
#define RTE_RUNNABLE_ReTxTemp ReTxTemp

FUNC(void,AUTOMATIC) ReTxSpd();
#define RTE_RUNNABLE_ReTxSpd ReTxSpd

FUNC(void,AUTOMATIC) ReTxAcc();
#define RTE_RUNNABLE_ReTxAcc ReTxAcc

typedef struct Rte_CDS_Controller Rte_CDS_Controller;
//struct Rte_CDS_Controller { <component data sections> }; 
 
#ifdef RTE_RUNNABLEAPI_ReTxTemp
Std_ReturnType Rte_Send_PpIfTemperature_Temp(Impl_uint8 data, Std_TransformerError transformerError);
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxTemp
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxSpd
Std_ReturnType Rte_Write_PpIfVehSpd_Spd(Impl_uint8 data);
Std_ReturnType Rte_Invalidate_PpIfVehSpd_Spd();
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxSpd
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxAcc
Std_ReturnType Rte_Write_PpIfVehAcc_Acc(Impl_uint8 data, Std_TransformerForward forwardedStatus, Std_TransformerError transformerError);
Std_ReturnType Rte_Invalidate_PpIfVehAcc_Acc(Std_TransformerError transformerError);
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxAcc
 
#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */