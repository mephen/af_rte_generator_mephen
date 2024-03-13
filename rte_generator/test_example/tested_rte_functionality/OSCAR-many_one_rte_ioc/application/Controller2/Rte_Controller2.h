#ifdef __cplusplus /* [SWS_Rte_03709] */
extern "C" {
#endif /* __cplusplus */

#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE

#include "Rte_Controller2_Type.h"
FUNC(void,AUTOMATIC) ReTxTemp2();
#define RTE_RUNNABLE_ReTxTemp2 ReTxTemp2

FUNC(void,AUTOMATIC) ReTxSpd2();
#define RTE_RUNNABLE_ReTxSpd2 ReTxSpd2

FUNC(void,AUTOMATIC) ReTxAcc2();
#define RTE_RUNNABLE_ReTxAcc2 ReTxAcc2

typedef struct Rte_CDS_Controller2 Rte_CDS_Controller2;
//struct Rte_CDS_Controller2 { <component data sections> }; 
 
#ifdef RTE_RUNNABLEAPI_ReTxTemp2
Std_ReturnType Rte_Send_PpIfTemperature2_Temp(Impl_uint16 data, Std_TransformerError transformerError);
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxTemp2
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxSpd2
Std_ReturnType Rte_Write_PpIfVehSpd2_Spd(Impl_uint16 data);
Std_ReturnType Rte_Invalidate_PpIfVehSpd2_Spd();
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxSpd2
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxAcc2
Std_ReturnType Rte_Write_PpIfVehAcc2_Acc(Impl_uint16 data, Std_TransformerForward forwardedStatus, Std_TransformerError transformerError);
Std_ReturnType Rte_Invalidate_PpIfVehAcc2_Acc(Std_TransformerError transformerError);
 
#endif
 
#ifdef RTE_RUNNABLEAPI_ReTxAcc2
 
#endif

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */