#ifdef __cplusplus /* [SWS_Rte_03709] */
extern "C" {
#endif /* __cplusplus */

#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif /* RTE_APPLICATION_HEADER_FILE */
#define RTE_APPLICATION_HEADER_FILE

#include "Rte_Actuator_Type.h"
#include "Rte_DataHandleType.h"
typedef struct Rte_CDS_Actuator Rte_CDS_Actuator
struct Rte_CDS_Actuator { <component data sections> }; 
#ifdef RTE_RUNNABLEAPI_Actuator_Init
#ifdef RTE_RUNNABLEAPI_Actuator_Step
Std_ReturnType Rte_Write_ThrCmd_Percent_Value(void, Float, IN Std_TransformerForward forwardedStatus)
void Rte_IWrite_Actuator_Step_ThrCmd_HwIO_Value(void)

#ifdef __cplusplus /* [SWS_Rte_03710] */
} /* extern "C" */
#endif /* __cplusplus */