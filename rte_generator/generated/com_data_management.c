#include "com_data_management.h"
#pragma section USER_SHARED_SEC

MyUint16OfVendorID ComSignal1_1_Spd = 666;
uint32 ComSignal1_1_Spd_first_reception_flag = 1U;

MyUint16OfVendorID ComSignal2_2_Acc = 777;
uint32 ComSignal2_2_Acc_first_reception_flag = 1U;

#define ComSignal3_3_Temp_MAX_SIZE 10
MyUint16OfVendorID ComSignal3_3_Temp[ComSignal3_3_Temp_MAX_SIZE];
RingBuffer RB_ComSignal3_3_Temp = {
    ComSignal3_3_Temp,
    0,
    0,
    ComSignal3_3_Temp_MAX_SIZE,
    0
};
