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
    RingBuffer response_Q;
    RingBuffer request_Q;
}RteClientServer;

/****************************************************************************************/
#endif//Rte_Type_h