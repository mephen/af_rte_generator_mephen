#ifndef RTE_TYPE_H
#define RTE_TYPE_H
#include "Rte.h"

//sw_base_type base_type mapping
typedef	uint8	Uint8;
typedef	uint16	Uint16;
typedef	float32	Float32;
typedef	float64	Float64;

//implementation_data_type sw_base_type mapping
typedef	Uint8	MyUint8OfVendorID;
typedef	Uint16	MyUint16OfVendorID;
typedef	Float32	MyFloat32;
typedef	Float64	MyFloat64;

typedef struct {
    uint16 status_uint16;
    // (LSB)0st-3th bit: event counter. (count how many times this event is triggered)
    // 4th-8th bit: event type. (for-loop in OsTask need this information to use different condition statement)
    // 9th bit: event_disablemode. (event can trigger the coreesponding entity or not. At the beginning of a mode switch, the RTE shall activate the mode disablings of the next mode)
    // 10th bit: entity_execute. (entity is executing or not. In a sync mode_switch, the mode manager has to wait until mode_disabling_dependency_entity terminate.)
    // 11th-15th bit: Event type specific attribute
        // OperationInvokedEvent, AsynchronousServerCallReturnsEvent:
        // 11th-12th bit: communication type. (inter-ecu / inter-partition / intra-partition)
    union {
        void (*Entity_FuncPtr)();
        uint16 (*Entity_FuncPtr_RVuint16)();
    };
} Event;

typedef uint32 RteModeType;
typedef uint32 RteEventType;

/* AUTOSAR Implementation data types, specific to software component */// Define the Ring Buffer structure
typedef struct {
    void *buffer;          // buffer array
    size_t head;           // head index
    size_t tail;           // tail index
    size_t maxSize;        // maximum number of elements
    size_t currentSize;    // current number of elements
} RingBuffer;

typedef uint32 SchMModeType;

typedef struct {
    int switch_status;
    int previousmode;
    int currentmode;
    int nextmode;
} ModeStatusType;

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
    union{
        void (*CR)();
        uint16 (*CR_RVuint16)(); //only for testing, CR doesn't return value in real case
    };
    union{
        void (*CRR)();
        uint16 (*CRR_RVuint16)(); //only for testing, CRR doesn't return value in real case
    };
    uint16 client_id;
    RingBuffer* RB_request_ptr;
    RingBuffer* RB_response_ptr;
    Event* async_return_ev;
    uint32 SR_task;
    uint32 CRR_task;
    enum {async = 0, sync = 1} rte_call_property;
    enum {not_used = 0, blocking = 1, non_blocking = 2} rte_result_property;
}Rte_Cs_metaData;

#define RTE_STATE_UNINIT        0
#define RTE_STATE_SCHM_START    1
#define RTE_STATE_SCHM_INIT     2
#define RTE_STATE_START         3
#define RTE_STATE_INIT          4
#define RTE_STATE_STOP          5

typedef struct {
    uint8 schedulerId;
} SchM_ConfigType;

#endif // RTE_TYPE_H
