
#ifndef IOC_H
#define IOC_H
#include "typedefine.h" 


#define IOC_SEND1 0
#define IOC_SEND2 1
#define IOC_SEND3 2
#define IOC_SEND4 3
#define IOC_SEND5 4
#define IOC_SEND6 5
#define IOC_SEND7 6
#define IOC_SEND8 7
#define IOC_SEND9 8
#define IOC_SEND10 9
#define IOC_RECEIVER1 10
#define IOC_RECEIVER2 11
#define IOC_RECEIVER3 12
#define IOC_RECEIVER4 13
#define IOC_RECEIVER5 14
#define IOC_RECEIVER6 15
#define IOC_RECEIVER7 16
#define IOC_RECEIVER8 17
#define IOC_RECEIVER9 18
#define IOC_RECEIVER10 19
#define IOC_EMPTY 20


/* 
per channel has one IOCCB, with IOCCB 
we can get the  information of the communication of channel
*/
typedef struct{
    ApplicationType appID;
    void (*callback)(void);
}ReceiverType;
typedef struct IOCCB{
    uint32 head; //internal buffer index
    uint32 tail; //internal buffer index
    uint32 length; // internal buffer length
    uint32 channel_receive_num; // the number of receiver
    ReceiverType *receiver; // point to array that store the receiver and callback function information
    uint8 callbackFlag; // if the callback function is set, set this flag
    uint8 lostFlag; // if the data is lost, set this flag
    uint8 *buffer; // point to the internal buffer
}IOCCB;

#define POP 0
#define PUSH 1
Std_ReturnType IOC_API(int id, void* input_data,int flag);
Std_ReturnType SetCallbackfunctionAction(ApplicationType ,void (*callback)(void));
void memcpy_j(int iocid, void *data, int size, int flag);

/***************/
#define IOCID_COUNT 5
#define aa 0 
#define bb 1
#define cc 2
#define dd 3
#define ee 4
/*mask*/
extern IocAutosarType Ioc_channel_sender[IOCID_COUNT];
extern IocAutosarType Ioc_channel_receiver[IOCID_COUNT];
typedef struct str_cc{
    int a;
    char b;
    int c;
}str_cc;

struct IOC_aa_struct{
    union {
        int data;
        int* data_r;
    };
};


struct IOC_bb_struct{
    void* ptr;
    union{
        uint16 length;
        uint16* length_r;
    };
};
struct IOC_cc_struct{
    str_cc* ptr;
};
struct IOC_dd_struct{
    union{
        int data;
        int* data_r;
    };
    void* ptr;
    union{
        uint16 length;
        uint16* length_r;
    };
};

struct IOC_ee_struct{
    void* ptr;
    union{
        uint16 length;
        uint16* length_r;
    };
};
extern uint16 lock_aa ;
extern uint16 lock_bb ;
extern uint16 lock_cc ;
extern uint16 lock_dd ;
void callback_bb(void);
void callback_cc(void);
void callback_dd(void);
extern uint8 buffer_aa[30];
extern uint8 buffer_bb[30];
extern uint8 buffer_cc[30];
extern uint8 buffer_dd[30];
extern ReceiverType receiver_aa[1] ;
extern ReceiverType receiver_bb[1] ;
extern ReceiverType receiver_cc[1] ;
extern ReceiverType receiver_dd[1] ;

extern IOCCB icb[IOCID_COUNT]; 
Std_ReturnType IocSend_aa(uint8 data);
Std_ReturnType SysIocSend_aa(uint8 data);
Std_ReturnType IocReceive_aa(uint8 *data);
Std_ReturnType SysIocReceive_aa(uint8 *data);
Std_ReturnType IocEmptyQueue_aa(void);
Std_ReturnType SysIocEmptyQueue_aa(void);
void callback_aa(void);

/***********************************************/
//(*arr,length)
extern int arr_bb[];
Std_ReturnType IocSend_bb(void*,uint16);
Std_ReturnType SysIocSend_bb(void*,uint16);
Std_ReturnType IocReceive_bb(void*,uint16*);
Std_ReturnType SysIocReceive_bb(void*,uint16*);
Std_ReturnType IocEmptyQueue_bb(void);
Std_ReturnType SysIocEmptyQueue_bb(void);
void callback_bb(void);

/***********************************************/
//(struct type* ptr)
// 不知道pack會不會影響

Std_ReturnType IocSend_cc(str_cc*);
Std_ReturnType SysIocSend_cc(str_cc*);
Std_ReturnType IocReceive_cc(str_cc*);
Std_ReturnType SysIocReceive_cc(str_cc*);
Std_ReturnType IocEmptyQueue_cc(void);
Std_ReturnType SysIocEmptyQueue_cc(void);
void callback_cc(void);

/***********************************************/
//(data,*arr,length)
Std_ReturnType IocSendGroup_dd(int,void*,uint16);
Std_ReturnType SysIocSendGroup_dd(int,void*,uint16);
Std_ReturnType IocReceiveGroup_dd(int*,void*,uint16*);
Std_ReturnType SysIocReceiveGroup_dd(int*,void*,uint16*);
Std_ReturnType IocEmptyQueue_dd(void);
Std_ReturnType SysIocEmptyQueue_dd(void);
void callback_dd(void);

/***********************************************/
Std_ReturnType IocWrite_ee_sender1(void*,uint16);
Std_ReturnType SysIocWrite_ee_sender1(void*,uint16);
Std_ReturnType IocWrite_ee_sender2(void*,uint16);
Std_ReturnType SysIocWrite_ee_sender2(void*,uint16);
Std_ReturnType IocWrite_ee_sender3(void*,uint16);
Std_ReturnType SysIocWrite_ee_sender3(void*,uint16);
Std_ReturnType IocRead_ee_receiver1(void*,uint16*);
Std_ReturnType SysIocRead_ee_receiver1(void*,uint16*);
Std_ReturnType IocRead_ee_receiver2(void*,uint16*);
Std_ReturnType SysIocRead_ee_receiver2(void*,uint16*);
void callback_ee_1(void);
void callback_ee_2(void);
#endif