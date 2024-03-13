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

/****************************************************************************************/
/*below structures are used in Rte_Client_Runnable_1.c*/

//To avoid long and complex type names
//not very useful, but it is a good practice to define the type name.(Rte_call_metaData is more flexible)
//[SWS_Rte_06810], [SWS_Rte_01150], [SWS_Rte_01148] -> (typedef Rte_instance_const_component const* const Rte_instance)
typedef struct{
    uint16 client_id;
}Rte_instance_component;
typedef CONSTP2CONST(Rte_instance_component, AUTOMATIC, RTE_CONST) Rte_instance;

typedef struct{
    uint16 client_id;
    uint16 sequence_counter;
    //below are meta data: help distinguish different tpye of Rte_call in the OsTask body.
    int communication_type; //(1:"com", 2:"ioc", 3:"rte")
    Std_ReturnType Async_rteCall_returnValue; //only for Async case
}Rte_Cs_TransactionHandleType;

//each Rte_call(serverCallPoint) has its own metaData.(client server communication)
typedef struct{
    Rte_Cs_TransactionHandleType transaction_handle;
    char port[20];
    char connected_unconnected[20];
    char in_exclusiveArea_or_not[20];
    char CanAccess[20];
    char sync_async[20];
    char operation[20];
    char run_stop[5];
}Rte_call_metaData;

//each Rte_result has its own metaData.(Asynchronous client server communication)
typedef struct{
    char connected_unconnected[20];
    char in_exclusiveArea_or_not[20];
    char CanAccess[20];
}Rte_result_metaData;

/****************************************************************************************/
#endif