//Data Type Redefinition Name
//avoid the name clash form different SWCs (see SWS_RTE 5.3.4.10)
//----------------------------------------------------------------
//[SWS_Rte_07678]
#ifndef RTE_LIFECYCLE1_TYPE_H
#define RTE_LIFECYCLE1_TYPE_H
#ifdef __cplusplus /* [SWS_Rte_07125] */
extern "C" {
#endif /* __cplusplus */

#include "../Rte_Type.h"
#define Impl_uint16 MyUint16OfVendorID

#ifdef __cplusplus /* [SWS_Rte_07126]  */
} /* extern "C" */
#endif /* __cplusplus */
#endif/* RTE_LIFECYCLE1_TYPE_H */