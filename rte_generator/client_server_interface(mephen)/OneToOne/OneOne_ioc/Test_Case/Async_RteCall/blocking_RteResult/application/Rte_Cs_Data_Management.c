#include "Rte_Cs_Data_Management.h"

/*****************************************************************************/
/*per pair of a client_runnable and a client_response_runnable*/
Std_ReturnType rteCall_returnValue_buffer_CR1[10];
RingBuffer RB_returnValue_CR1 = {
    rteCall_returnValue_buffer_CR1,
    0,
    0,
    10,
    0
};

Std_ReturnType rteCall_returnValue_buffer_CR2[10];
RingBuffer RB_returnValue_CR2 = {
    rteCall_returnValue_buffer_CR2,
    0,
    0,
    10,
    0
};

Std_ReturnType rteCall_returnValue_buffer_CR3[10];
RingBuffer RB_returnValue_CR3 = {
    rteCall_returnValue_buffer_CR3,
    0,
    0,
    10,
    0
};


/*****************************************************************************/
/*core0 c/s data structure*/
uint16 transformer_buffer_core0[20];
RingBuffer RB_transformer_core0 = {
    transformer_buffer_core0,
    0,
    0,
    20,
    0
};

uint16 requestInfo_buffer_core0[50];
RingBuffer RB_requestInfo_core0 = {
    requestInfo_buffer_core0,
    0,
    0,
    50,
    0
};

ResponseInfoType responseInfo_buffer_core0[50];
RingBuffer RB_responseInfo_core0 = {
    responseInfo_buffer_core0,
    0,
    0,
    50,
    0
};

/*****************************************************************************/
/*core1 c/s data structure*/
uint16 transformer_buffer_core1[20];
RingBuffer RB_transformer_core1 = {
    transformer_buffer_core1,
    0,
    0,
    20,
    0
};

