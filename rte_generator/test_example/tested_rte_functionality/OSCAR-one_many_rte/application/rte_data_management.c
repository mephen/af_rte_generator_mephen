#include "rte_data_management.h"
#pragma section USER_SHARED_SEC

MyUint16OfVendorID R1_Spd = 444;
uint32 R1_Spd_first_reception_flag = 1U;

MyUint16OfVendorID R2_Acc = 222;
uint32 R2_Acc_first_reception_flag = 1U;

#define R3_1_Temp_MAX_SIZE 10
MyUint16OfVendorID R3_1_Temp[R3_1_Temp_MAX_SIZE];
RingBuffer RB_R3_1_Temp = {
    R3_1_Temp,
    0,
    0,
    R3_1_Temp_MAX_SIZE,
    0
};

#define R3_2_Temp_MAX_SIZE 10
MyUint16OfVendorID R3_2_Temp[R3_2_Temp_MAX_SIZE];
RingBuffer RB_R3_2_Temp = {
    R3_2_Temp,
    0,
    0,
    R3_2_Temp_MAX_SIZE,
    0
};
