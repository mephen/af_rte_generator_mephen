//Predefined Error codes
//----------------------------------------------------------------
#ifndef RTE_H
#define RTE_H

#include "Std_Types.h"

#define RTE_E_OK 0U
#define RTE_E_INVALID 1U
#define RTE_E_LOST_DATA 64U
#define RTE_E_MAX_AGE_EXCEEDED 64U
#define RTE_E_COM_STOPPED 128U
#define RTE_E_TIMEOUT 129U
#define RTE_E_LIMIT 130U
#define RTE_E_NO_DATA 131U
#define RTE_E_TRANSMIT_ACK 132U
#define RTE_E_NEVER_RECEIVED 133U
#define RTE_E_UNCONNECTED 134U
#define RTE_E_IN_EXCLUSIVE_AREA 135U
#define RTE_E_SEG_FAULT 136U
#define RTE_E_OUT_OF_RANGE 137U
#define RTE_E_SERIALIZATION_ERROR 138U
#define RTE_E_HARD_TRANSFORMER_ERROR 138U
#define RTE_E_SERIALIZATION_LIMIT 139U
#define RTE_E_TRANSFORMER_LIMIT 139U
#define RTE_E_SOFT_TRANSFORMER_ERROR 140U
#define RTE_E_COM_BUSY 141U
#define RTE_E_RAM_UNCHANGED 142U
#define RTE_E_UNDEFINED 255U

//For flag
#define BIT0 ((int)1 << 0)
#define SET_BIT0(data) (*(data) |= BIT0)
#define CLEAR_BIT0(data) (*(data) &= ~BIT0)

# define RTE_VENDOR_ID (0x0000U)
# define RTE_MODULE_ID (0x0000U)
# define RTE_SW_PATCH_VERSION (0x0000U)

#endif