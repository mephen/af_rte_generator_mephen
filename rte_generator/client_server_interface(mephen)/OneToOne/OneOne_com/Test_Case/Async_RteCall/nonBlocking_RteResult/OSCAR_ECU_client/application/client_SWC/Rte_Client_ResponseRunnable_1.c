#define RTE_CLIENT_RESPONSERUNNABLE_1_C
#include "Rte_Client_ResponseRunnable.h"
#include "../ringbuffer.h"
#include "../../kernel/alarm.h"
#include "../../kernel/event.h"
#include "../../OS_Configure/inc/event_Cfg.h"


extern RingBuffer Rte_response_RB_ioc;

Std_ReturnType errorFlag_Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking = RTE_E_OK;
Std_ReturnType errorFlag_Rte_Result_Port1_InterEcuAsynchronousAdd_Blocking = RTE_E_OK;

Rte_result_metaData Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking_metaData = {
    "connected",
    "NotInExclusiveArea",
    "Can"
};
Rte_result_metaData Rte_Result_Port1_InterEcuAsynchronousAdd_Blocking_metaData = {
    "connected",
    "NotInExclusiveArea",
    "Can"
};

Std_ReturnType Rte_Result_Port1_InterEcuAsynchronousAdd_Blocking(Std_ReturnType Previous_RteCall_returnValue, Impl_uint16* response){
    WaitEvent(event1);
    SetRelAlarm(alarm3, 50, 0);
    Std_ReturnType rte_error_code = RTE_E_OK;
    if(Rte_Result_Port1_InterEcuAsynchronousAdd_Blocking_metaData.connected_unconnected == "unconnected"){
        rte_error_code = RTE_E_UNCONNECTED;
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Result_Port1_InterEcuAsynchronousAdd_Blocking_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error_code = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Result_Port1_InterEcuAsynchronousAdd_Blocking_metaData.CanAccess == "CanNot"){
            rte_error_code = RTE_E_SEG_FAULT;
        }
    }
    //return value should follow the priority rule
    if(rte_error_code == RTE_E_OK){
        if(errorFlag_Rte_Result_Port1_InterEcuAsynchronousAdd_Blocking != RTE_E_OK){
            rte_error_code = errorFlag_Rte_Result_Port1_InterEcuAsynchronousAdd_Blocking;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Previous_RteCall_returnValue == RTE_E_SEG_FAULT || Previous_RteCall_returnValue == RTE_E_TRANSFORMER_LIMIT || Previous_RteCall_returnValue == RTE_E_HARD_TRANSFORMER_ERROR){
            rte_error_code = RTE_E_NO_DATA;
        }
    }
    if(rte_error_code == RTE_E_OK){
        RTE_Dequeue(&Rte_response_RB_ioc, (void*)response, sizeof(Impl_uint16));
    }
    //reset the error flag
    errorFlag_Rte_Result_Port1_InterEcuAsynchronousAdd_Blocking = RTE_E_OK;
    return rte_error_code;
}

Std_ReturnType Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking(Std_ReturnType Previous_RteCall_returnValue, Impl_uint16* response){
    SetRelAlarm(alarm3, 50, 0);
    Std_ReturnType rte_error_code = RTE_E_OK;
    if(Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking_metaData.connected_unconnected == "unconnected"){
        rte_error_code = RTE_E_UNCONNECTED;
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking_metaData.in_exclusiveArea_or_not == "InExclusiveArea"){
            rte_error_code = RTE_E_IN_EXCLUSIVE_AREA;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking_metaData.CanAccess == "CanNot"){
            rte_error_code = RTE_E_SEG_FAULT;
        }
    }
    //return value should follow the priority rule
    //transformer, com, and timeout error are checked in OsTask body
    if(rte_error_code == RTE_E_OK){
        if(errorFlag_Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking != RTE_E_OK){
            rte_error_code = errorFlag_Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking;
        }
    }
    if(rte_error_code == RTE_E_OK){
        if(Previous_RteCall_returnValue == RTE_E_SEG_FAULT || Previous_RteCall_returnValue == RTE_E_TRANSFORMER_LIMIT || Previous_RteCall_returnValue == RTE_E_HARD_TRANSFORMER_ERROR){
            rte_error_code = RTE_E_NO_DATA;
        }
    }
    if(rte_error_code == RTE_E_OK){
        RTE_Dequeue(&Rte_response_RB_ioc, (void*)response, sizeof(Impl_uint16));
    }
    //reset the error flag
    errorFlag_Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking = RTE_E_OK;
    return rte_error_code;
}

Impl_uint16 Rte_Client_ResponseRunnable_1(Std_ReturnType Previous_RteCall_returnValue){
    //for developer to design the implementation
    Impl_uint16 response = 0;
    Rte_Result_Port1_InterEcuAsynchronousAdd_NonBlocking(Previous_RteCall_returnValue, &response);
    return response;
}
