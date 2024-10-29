#ifndef IOC_H
#define IOC_H
/* This file content the generated configuration of ioc */
/*==================[inclusions]=============================================*/
#include "typedefine.h"
/*==================[macros]=================================================*/
#define IOC_SEND_QUE_SND0 0
#define IOC_SEND_QUE_SND1 1
#define IOC_RECEIVER_QUE_RCV 10
#define IOC_SEND_DEQUE_SND 2
#define IOC_RECEIVER_DEQUE_RCV 11
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
    uint32 *buffer; // point to the internel buffer
}IOCCB;

#define POP 0
#define PUSH 1
Std_ReturnType IOC_API(int id, void* input_data,int flag);
Std_ReturnType SetCallbackfunctionAction(ApplicationType ,void (*callback)(void));
void memcpy_j(int iocid, void *data, int size, int flag);

#define IOCID_COUNT 2

#define QUE 0
#define DEQUE 1
extern IocAutosarType Ioc_channel_sender[IOCID_COUNT];
extern IocAutosarType Ioc_channel_receiver[IOCID_COUNT];
struct IOC_QUE_struct{
    union{
        int data_1;
        int* data_1_r;
    };
};
struct IOC_DEQUE_struct{
    void* ptr_1;
    union{
        int data_2;
        int* data_2_r;
    };
    union{
        uint8 data_3;
        uint8* data_3_r;
    };
};
extern IOCCB icb[IOCID_COUNT];

extern uint16 lock_QUE ;
extern uint8 buffer_QUE[3];
extern ReceiverType receiver_QUE[1] ;

Std_ReturnType IocSend_QUE_SND0(int);
Std_ReturnType SysIocSend_QUE_SND0(int);

Std_ReturnType IocSend_QUE_SND1(int);
Std_ReturnType SysIocSend_QUE_SND1(int);

Std_ReturnType IocReceive_QUE_RCV(int);
Std_ReturnType SysIocReceive_QUE_RCV(int);

Std_ReturnType IocEmptyQueue_QUE(void);
Std_ReturnType SysIocEmptyQueue_QUE(void);

extern uint16 lock_DEQUE ;
extern uint8 buffer_DEQUE[5];
extern ReceiverType receiver_DEQUE[1] ;

Std_ReturnType IocSendGroup_DEQUE_SND(void*,int, int, uint8);
Std_ReturnType SysIocSendGroup_DEQUE_SND(void*,int, int, uint8);
Std_ReturnType IocReceiveGroup_DEQUE_RCV(void*,int*, int*, uint8*);
Std_ReturnType SysIocReceiveGroup_DEQUE_RCV(void*,int*, int*, uint8*);
Std_ReturnType IocEmptyQueue_DEQUE(void);
Std_ReturnType SysIocEmptyQueue_DEQUE(void);

void callback_QUE_QUE(void);
#endif
