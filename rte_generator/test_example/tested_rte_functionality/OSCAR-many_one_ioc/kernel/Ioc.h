#ifndef IOC_H
#define IOC_H
/* This file content the generated configuration of ioc */
/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "../application/Rte_Type.h"
/*==================[macros]=================================================*/
#define IOC_SEND_Q1_SND1 0
#define IOC_SEND_Q1_SND2 1
#define IOC_RECEIVER_Q1_RCV1 10
#define IOC_SEND_Q2_SND1 2
#define IOC_SEND_Q2_SND2 3
#define IOC_RECEIVER_Q2_RCV1 11
#define IOC_SEND_Q3_SND1 4
#define IOC_SEND_Q3_SND2 5
#define IOC_RECEIVER_Q3_RCV1 12
#define IOC_EMPTY 20

/*define*/
typedef struct{
    ApplicationType appID;
    void (*callback)(void);
}ReceiverType;

typedef struct IOCCB{
    uint32 head; //internel buffer index
    uint32 tail; //internel buffer index
    uint32 length; // internel buffer length
    uint32 channel_receive_num; // the number of receiver
    ReceiverType *receiver; // point to array that store the receiver and callback function informationl
    uint8 callbackFlag; // if the callback function is set, set this flag
    uint8 lostFlag; // if the data is lost, set this flag
    uint8* buffer; // point to the internel buffer
}IOCCB;

#define POP 0
#define PUSH 1
Std_ReturnType IOC_API(int id, void* input_data,int flag);
Std_ReturnType SetCallbackfunctionAction(ApplicationType ,void (*callback)(void));
void memcpy_j(int iocid, void *data, int size, int flag);

#define IOCID_COUNT 3

extern IocAutosarType Ioc_channel_sender[IOCID_COUNT];
extern IocAutosarType Ioc_channel_receiver[IOCID_COUNT];
#define Q1 0
#define Q2 1
#define Q3 2
extern IocAutosarType Ioc_channel_sender[IOCID_COUNT];
extern IocAutosarType Ioc_channel_receiver[IOCID_COUNT];
struct IOC_Q1_struct{
    union{
        MyUint16OfVendorID data_1;
        MyUint16OfVendorID* data_1_r;
    };
};
struct IOC_Q2_struct{
    union{
        MyUint16OfVendorID data_1;
        MyUint16OfVendorID* data_1_r;
    };
};
struct IOC_Q3_struct{
    union{
        MyUint16OfVendorID data_1;
        MyUint16OfVendorID* data_1_r;
    };
};
extern IOCCB icb[IOCID_COUNT];

Std_ReturnType IocWrite_Q1_SND1(MyUint16OfVendorID);
Std_ReturnType SysIocWrite_Q1_SND1(MyUint16OfVendorID);
Std_ReturnType IocWrite_Q1_SND2(MyUint16OfVendorID);
Std_ReturnType SysIocWrite_Q1_SND2(MyUint16OfVendorID);
Std_ReturnType IocRead_Q1_RCV1(MyUint16OfVendorID*);
Std_ReturnType SysIocRead_Q1_RCV1(MyUint16OfVendorID*);


Std_ReturnType IocWrite_Q2_SND1(MyUint16OfVendorID);
Std_ReturnType SysIocWrite_Q2_SND1(MyUint16OfVendorID);
Std_ReturnType IocWrite_Q2_SND2(MyUint16OfVendorID);
Std_ReturnType SysIocWrite_Q2_SND2(MyUint16OfVendorID);
Std_ReturnType IocRead_Q2_RCV1(MyUint16OfVendorID*);
Std_ReturnType SysIocRead_Q2_RCV1(MyUint16OfVendorID*);



extern uint16 lock_Q3 ;
extern uint8 buffer_Q3[10];
extern ReceiverType receiver_Q3[1] ;
Std_ReturnType IocSend_Q3_SND1(MyUint16OfVendorID);
Std_ReturnType SysIocSend_Q3_SND1(MyUint16OfVendorID);
Std_ReturnType IocSend_Q3_SND2(MyUint16OfVendorID);
Std_ReturnType SysIocSend_Q3_SND2(MyUint16OfVendorID);
Std_ReturnType IocReceive_Q3(MyUint16OfVendorID*);
Std_ReturnType SysIocReceive_Q3(MyUint16OfVendorID*);
Std_ReturnType IocEmptyQueue_Q3(void);
Std_ReturnType SysIocEmptyQueue_Q3(void);

#endif
