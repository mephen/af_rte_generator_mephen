#ifndef SYSTEM_H
#define SYSTEM_H

#include "typedefine.h"
#include "interrupt_ctl.h"
#include "os.h"
#include "os_Cfg.h"

/*********** SELF_AREA per-core variable **********/
extern CoreIdType _CoreID;

extern AppModeType activeApplicationMode;
extern uint32 systemFlag;
extern uint32 SysTaskCurrentHandlingApp;

//store kernel & user stack pointer, to imitate stack-switching mechanism 
extern uint32 mySysStackPtr[1];
extern uint32 myEISP[1];   

extern int serviceDisableAllInterruptsCounter;
extern int serviceSuspendAllInterruptsCounter;
extern int serviceSuspendOSInterruptsCounter;
extern int InTrustedFunctionCounter;

extern int kernelDisableAllInterruptsCounter;
extern int kernelDisableAllISRCounter;
extern int kernelDisableISR2Counter;
extern int kernelSystemCallCounter;

extern int kernelDisableMPUCounter;
extern int kernelDisableTimerCounter;
extern int kernelDisableCrossCoreCounter;
extern int kernelDisableSchedulerCounter;



/***************************************************/

/* Temp cross core data */
extern AlarmBaseType AlarmBaseForSharing;
extern TickType TickForSharing;
extern EventMaskType EventMaskForSharing;
extern TaskStateType TaskStateForSharing;
extern ScheduleTableStatusType STStatusForSharing;
extern ApplicationStateType AppStateForSharing;

/* System service */
void StartCore(CoreIdType CoreID, StatusType *Status);
void StartOS(AppModeType Mode);
void ShutdownOS (StatusType Error);
CoreIdType GetCoreID(void);
uint32 GetNumberOfActivatedCores(void);
AppModeType GetActiveApplicationMode (void);
void DisableAllInterrupts(void);
void EnableAllInterrupts(void);
void SuspendAllInterrupts(void);
void ResumeAllInterrupts(void);
void SuspendOSInterrupts(void);
void ResumeOSInterrupts(void);
void ShutdownAllCores(StatusType Error);
void StartNonAutosarCore(CoreIdType CoreID,StatusType* Status);

void SysStartCore(CoreIdType CoreID, StatusType *Status);
void SysStartOS(AppModeType Mode);
void SysShutdownOS (StatusType Error);
CoreIdType SysGetCoreID(void);
uint32 SysGetNumberOfActivatedCores(void);
AppModeType SysGetActiveApplicationMode (void);
void SysShutdownAllCores(StatusType Error);
void SysStartNonAutosarCore(CoreIdType CoreID,StatusType* Status);
void SysDisableAllInterrupts(void);
void SysEnableAllInterrupts(void);
void SysSuspendAllInterrupts(void);
void SysResumeAllInterrupts(void);
void SysSuspendOSInterrupts(void);
void SysResumeOSInterrupts(void);
void SysStartOSBot(AppModeType Mode);
void SysShutdownOSBot (StatusType Error);
void SysShutdownAllCoresBot(StatusType Error);          

/* Inner function */
uint32 CheckCoreSync(void);
void ServiceCrossCore(void);
// extern ShutdownHook()

/* EnterCritical() will Disable All Interrupts */
#define EnterCritical()                               \
    do {                                              \
        if (kernelDisableAllInterruptsCounter == 0){  \
            arch_disable_all_interrupts();            \
        }                                             \
        kernelDisableAllInterruptsCounter++;          \
    } while(0)

/* EnterCritical() will check if it can Enable All Interrupts */
#define ExitCritical()                                          \
    do{                                                         \
        kernelDisableAllInterruptsCounter--;                    \
        if (kernelDisableAllInterruptsCounter < 0){             \
            kernelDisableAllInterruptsCounter = 0;              \
        }                                                       \
        else if (kernelDisableAllInterruptsCounter == 0){       \
            if (kernelDisableAllISRCounter > 0){                \
                /* only enable timer INT */                     \
                arch_disable_all_ISR_interrupts();              \
            }                                                   \
            else if (kernelDisableISR2Counter > 0){             \
                /* enable timer and ISR1 */                     \
                arch_disable_only_ISR2_interrupts();            \
            }                                                   \
            else{ /* all 3-level Counter == 0*/                 \
                /* enable all INT*/                             \
                arch_enable_all_interrupts();                   \
            }                                                   \
        }                                                       \
        else { /* (kernelDisableAllInterruptsCounter > 0) */    \
            ; /* do noth, keep in EnterCritical */              \
        }                                                       \
    } while(0) 

/* kernelDisableAllISR() will Disable ISR1 and ISR2  */
#define kernelDisableAllISR()                                       \
    do {                                                            \
        if (kernelDisableAllISRCounter == 0){                       \
            if (kernelDisableAllInterruptsCounter > 0){             \
                ; /* do-nth, timer level is already disabled */     \
            }                                                       \
            else{                                                   \
                arch_disable_all_ISR_interrupts();                  \
            }                                                       \
        }                                                           \
        kernelDisableAllISRCounter++;                               \
    } while(0)

/* kernelEnableAllISR() will check if it can Enable ISR1 and ISR2 */
#define kernelEnableAllISR()                                        \
    do{                                                             \
        kernelDisableAllISRCounter--;                               \
        if (kernelDisableAllISRCounter < 0){                        \
            kernelDisableAllISRCounter = 0;                         \
        }                                                           \
        else if (kernelDisableAllISRCounter == 0){                  \
            if (kernelDisableAllInterruptsCounter > 0){             \
                ; /* do-nth, timer level is already disabled */     \
            }                                                       \
            else if (kernelDisableISR2Counter > 0){                 \
                /* only ISR2 need disable, enable timer and ISR1 */ \
                arch_disable_only_ISR2_interrupts();                \
            }                                                       \
            else{ /* all 3-level Counter == 0*/                     \
                /* enable all INT*/                                 \
                arch_enable_all_interrupts();                       \
            }                                                       \
        }                                                           \
        else { /* (kernelDisableAllISRCounter > 0) */               \
            ; /* do noth, keep in kernelEnableAllISR() */           \
        }                                                           \
    } while(0) 

/* kernelDisableISR2() will try to Disable ISR2  */
#define kernelDisableISR2()                                         \
    do {                                                            \
        if (kernelDisableISR2Counter == 0){                         \
            if (kernelDisableAllInterruptsCounter > 0){             \
                ; /* do-nth, timer level is already disabled */     \
            }                                                       \
            else if (kernelDisableAllISRCounter > 0){               \
                ; /* do-nth, ISR1 level is already disabled */      \
            }                                                       \
            else{                                                   \
                arch_disable_only_ISR2_interrupts();                \
            }                                                       \
        }                                                           \
        kernelDisableISR2Counter++;                                 \
    } while(0) 

/* kernelEnableISR2() will check if it can Enable ISR2 */
#define kernelEnableISR2()                                          \
    do{                                                             \
        kernelDisableISR2Counter--;                                 \
        if (kernelDisableISR2Counter < 0){                          \
            kernelDisableISR2Counter = 0;                           \
        }                                                           \
        else if (kernelDisableISR2Counter == 0){                    \
            if (kernelDisableAllInterruptsCounter > 0){             \
                ; /* do-nth, timer level is already disabled */     \
            }                                                       \
            else if (kernelDisableAllISRCounter > 0){               \
                ; /* do-nth, isr1 level is already disabled */      \
            }                                                       \
            else{ /* all 3-level Counter == 0*/                     \
                /* enable all INT*/                                 \
                arch_enable_all_interrupts();                       \
            }                                                       \
        }                                                           \
        else { /* (kernelDisableISR2Counter > 0) */                 \
            ; /* do noth, keep in kernelEnableISR2() */             \
        }                                                           \
    } while(0)




/* below are legacy code & macro */
// #define SYSTEMFLAG (SystemVar[_CoreID]->systemFlag)
// #define DISABLEALLINTERRUPTSCOUNTER (SystemVar[_CoreID]->disableAllInterruptsCounter)
// #define SUSPENDALLINTERRUPTSCOUNTER (SystemVar[_CoreID]->suspendAllInterruptsCounter)
// #define SUSPENDOSINTERRUPTSCOUNTER (SystemVar[_CoreID]->suspendOSInterruptsCounter)
// #define KERNELDISABLEINTERRUPTSCOUNTER (SystemVar[_CoreID]->kernelDisableInterruptsCounter)
// #define KERNELDISABLELOWPRIORITYINTERRUPTSCOUNTER (SystemVar[_CoreID]->kernelDisableLowPriorityInterruptsCounter)
// #define ACTIVEAPPLICATIONMODE (SystemVar[_CoreID]->activeApplicationMode)
// #define KERNELSYSTEMCALLCOUNTER (SystemVar[_CoreID]->kernelSystemCallCounter)

#endif /* #ifndef SYSTEM_H */