#ifndef APPLICATION_H
#define APPLICATION_H

#include "typedefine.h"

#define GET_RESULT_BY_CHECKING_OWNER_OSAPP_STATE( ownerAppID, result )                              \
    do{                                                                                 \
        if ( getAppStateIntenal( (ownerAppID) != APPLICATION_ACCESSIBLE )               \
             && ExecutingApp[_CoreID] != (ownerAppID)                    )              \
        {   /* when NOT in APPLICATION_ACCESSIBLE, */                                   \
            /* only the App's own object is allowed to modify object in same App */     \
            (result) = E_OS_ACCESS; /* SWS_Os_00504 SWS_Os_00509 */                     \
        }                                                                               \
    } while()

/* System service */
ApplicationType GetApplicationID(void);
ApplicationType GetCurrentApplicationID(void);
ObjectAccessType CheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, uint32 objectID);
ApplicationType CheckObjectOwnership( ObjectTypeType ObjectType, uint32 objectID);
StatusType TerminateApplication(ApplicationType Application, RestartType RestartOption);
StatusType AllowAccess(void);
StatusType GetApplicationState(ApplicationType Application, ApplicationStateRefType Value);
AccessType CheckISRMemoryAccess(ISRType ISRID, MemoryStartAddressType Address, MemorySizeType Size);
AccessType CheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size);
StatusType CallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);



ApplicationType SysGetApplicationID(void);
ApplicationType SysGetCurrentApplicationID(void);
ObjectAccessType SysCheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, uint32 objectID);
ApplicationType SysCheckObjectOwnership( ObjectTypeType ObjectType, uint32 objectID);
StatusType SysTerminateApplication(ApplicationType Application, RestartType RestartOption);
StatusType SysAllowAccess(void);
StatusType SysGetApplicationState(ApplicationType Application, ApplicationStateRefType Value);
AccessType SysCheckISRMemoryAccess(ISRType ISRID, MemoryStartAddressType Address, MemorySizeType Size);
AccessType SysCheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size);
StatusType TrustfunctionChecking(TrustedFunctionIndexType FunctionID, TrustedFunctionParameterRefType FunctionParams);
StatusType SysCallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams,uint32 *functionpointer);

StatusType MyCallTrustedFunc( TrustedFunctionIndexType id, TrustedFunctionParameterRefType para );


/******* OS-Application management internal function *******/
ApplicationStateType getAppStateIntenal(ApplicationType Application);
void setAppStateIntenal(ApplicationType Application, ApplicationStateType value);

void TerminateAppInternal(ApplicationType AppID);
void TerminateAppTask(ApplicationType Application);
void DisableAppISR(ApplicationType Application);
void EnableAppISR(ApplicationType Application);
void StopAppAlarm(ApplicationType Application);
void StopAppScheduleTable(ApplicationType Application);

void SetAPPErrorHookAction(StatusType Error);
void APPErrorHook(StatusType Error);

#endif