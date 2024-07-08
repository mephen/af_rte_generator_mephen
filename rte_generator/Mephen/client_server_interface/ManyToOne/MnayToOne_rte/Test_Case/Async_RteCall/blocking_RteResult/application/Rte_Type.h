//Data Type Definitions
//----------------------------------------------------------------
#ifndef Rte_Type_h
#define Rte_Type_h
#include "Rte.h"

/* AUTOSAR Implementation data types, specific to software component */
typedef uint8 MyUint8OfVendorID;
typedef uint16 MyUint16OfVendorID;
typedef float32 MyFloat32;
typedef float64 MyFloat64;

//use uint8 will cause error when test with GetLock/ReleaseLock protection
typedef uint32 RteEventType;
typedef struct{
    RteEventType rteevent;
    RteEventType rteevent_disableinmode; //for mode switch interface
    RteEventType rteevent_flag; //for mode switch interface
} RteEventStatus;

//Define the Ring Buffer(FIFO) structure
typedef struct {
    void *buffer;          // buffer array
    size_t head;           // head index: point to the oldest data
    size_t tail;           // tail index: point to the next available position of the newest data
    size_t maxSize;        // maximum number of elements
    size_t currentSize;    // current number of elements
}RingBuffer;

typedef struct{ 
    uint16 client_id; //runnable ID
    uint16 sequence_counter; 
        //Async Rte_call: the sequence_counter record how many Async Rte_call has been "invoked", and the sequence_counter of rte_result records how many c/s communication has been "finished".
        //Sync Rte_call: the sequence_counter record how many c/s communication has been "finished".
}Rte_Cs_TransactionHandleType; //follow spec.

//each Rte_call(serverCallPoint) has its own metaData.(client server communication)
typedef struct{
    Rte_Cs_TransactionHandleType transaction_handle;
    char connected_unconnected[20];
    char in_exclusiveArea_or_not[20];
    char CanAccess[20];
}RteCallMetaData;

//each Rte_result has its own metaData.(Asynchronous client server communication)
typedef struct{
    Rte_Cs_TransactionHandleType transaction_handle;
    char connected_unconnected[20];
    char in_exclusiveArea_or_not[20];
    char CanAccess[20];
}RteResultMetaData;

typedef struct{
    Std_ReturnType bsw_error; //record bsw service error in the client_side_task which process the server_response during a c/s communication
    Rte_Cs_TransactionHandleType transaction_handle;
    uint16 response;
}ResponseInfoType;

typedef struct{
    uint16 status_uint16;
        // (LSB)0st-3th bit: rteevent counter. (count how many times this event is triggered)
        // 4th-8th bit: rteevent type. (for-loop in OsTask need this information to use different condition statement)
        // 9th bit: rteevent_disablemode. (rteevent can trigger the coreesponding runnable or not. If the para of Rte_Switch(mode) is irrelevant to this event , rteevent_disablemode will be cleared at the beginning of Rte_Switch, otherwise it will be set.)
        // 10th bit: runnable_execute. (runnable is executing or not. In a sync mode_switch, the mode manager has to wait until mode_disabling_dependency_runnable terminate.)
        // 11th-15th bit: Event type specific attribute
            //InitEvent:
                //11th-12th bit:trigger runnable type. (e.g. client runnable, sender runnable, mode requester runnable)
            //OperationInvokedEvent、AsynchronousServerCallReturnsEvent:
                //11th-12th bit: communication type. (inter-ecu / inter-partition / intra-partition)
    union{
        void (*Runnable_FuncPtr)();
        uint16 (*Runnable_FuncPtr_RVuint16)();
    };
} RteEvent;

typedef struct{
    union{
        void (*CR)();
        uint16 (*CR_RVuint16)(); //only for testing, CR doesn't return value in real case
    };
    union{
        void (*CRR)();
        uint16 (*CRR_RVuint16)(); //only for testing, CRR doesn't return value in real case
    };
    union{
        uint8 (*SR_RVuint8)();
        uint16 (*SR_RVuint16)();
    };
    uint16 client_id;
    RingBuffer* RB_request_ptr;
    RingBuffer* RB_response_ptr;
    RteEvent* async_return_ev;
    uint32 SR_task;
    uint32 CRR_task;
    enum {async = 0, sync = 1} rte_call_property;
    enum {not_used = 0, blocking = 1, non_blocking = 2} rte_result_property;
}Rte_Cs_metaData;

/*TaskType: 
//core0
#define IdleTask_core0  0x00000000
#define T01             0x00000001
#define T02             0x00000002
#define T03             0x00000003
#define T04             0x00000004
#define T05             0x00000005
#define T06             0x00000006
#define SysTask_core0  0x0000000B
// core1
#define IdleTask_core1  0x00010000
#define T11             0x00010001
#define T14             0x00010002
#define T12             0x00010003
#define T13             0x00010004
#define T15             0x00010005
#define T16             0x00010006
*/

/****************************************************************************************/
#endif//Rte_Type_h