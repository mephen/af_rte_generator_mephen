#include "rte_data_management.h"
#pragma section USER_SHARED_SEC

MyUint8OfVendorID R1_Spd = 111;
uint32 R1_Spd_first_reception_flag = 1U;

MyUint8OfVendorID R2_Acc = 111;
uint32 R2_Acc_first_reception_flag = 1U;

#define R3_Temp_MAX_SIZE 10
MyUint8OfVendorID R3_Temp[R3_Temp_MAX_SIZE];
RingBuffer RB_R3_Temp = {
    R3_Temp,
    0,
    0,
    R3_Temp_MAX_SIZE,
    0
};
