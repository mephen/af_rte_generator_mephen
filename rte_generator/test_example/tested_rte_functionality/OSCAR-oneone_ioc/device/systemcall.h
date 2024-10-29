#ifndef SYSTEMCALL_H
#define SYSTEMCALL_H

#include "system.h"

void innerEnterSystemCall(void);    /* Dis-MPU, Dis-All-INT, Set-SU */
void innerExitSystemCall(void);     /* ReSet-SU, En-All-INT, En-MPU */

void EnterSystemCall();

void ExitSystemCall();

void syscall_CallTrustedFunc();

// #define EnterSystemCall()                   \
//     do{                                     \
//         if (kernelSystemCallCounter == 0){  \
//             _EnterSystemCall();             \
//         }                                   \
//         kernelSystemCallCounter++;          \
//     } while(0)

// #define ExitSystemCall()                            \
//     do{                                             \
//         kernelSystemCallCounter--;                  \
//         if (kernelSystemCallCounter < 0){           \
//             kernelSystemCallCounter = 0;            \
//         }                                           \
//         else if (kernelSystemCallCounter == 0){     \
//             _ExitSystemCall();                      \
//         }                                           \
//         else { /* (kernelSystemCallCounter > 0) */  \
//             ; /* do noth, keep in syscall */        \
//         }                                           \
//     } while(0) 


    
void SetSupervisor(void);
void ResetSupervisor(void);



StatusType ActivateTaskUser(TaskType TaskID);
void pushStack(SysServiceParaType *para);
void popStack();
void getPara(SysServiceParaType *para);
void callService(SysServiceParaType *para);
void sysCallSystemService(void);
void sysCallPrintText(void);
void sysCallPrintText_R35(void);
void sysCallTrustFunc(void);
#endif