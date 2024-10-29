#ifndef TYPEDEFINE_H
#define TYPEDEFINE_H

#define NULL (void *)(0U)

/*********** used for configuration file *****************************/
#define DISABLE 0
#define ENABLE 1

/*********** basic type definition ***********************************/
typedef unsigned char uint8;         
typedef unsigned short int uint16;   
typedef unsigned long uint32;         
typedef unsigned long long uint64;

/* This type is used to represent the return value of API services */
typedef unsigned char StatusType;

/* This type is used to describe the core ID in multicore system */
/* SWS_Os_00790 */
typedef uint16 CoreIdType;
typedef uint16 EcucPartitionIdType;

/* This type is used to indicate if core is activated or not */
typedef enum
{
    nonActivatedCore = 0,
    ActivatedCore = 1,
    beforeStartOS = 2,
    waitFirstSync = 3,
    waitSecondSync = 4,
    shutdownMaster = 5,
    waitSyncforshutdown = 6,
    nonAutosarCore = 7,
    shutdown = 8,
} CoreActivatedType;

/* This type is used to represent the os application mode */
typedef uint32 AppModeType;

/* This type is used to represent the IOC return type*/
typedef uint32 Std_ReturnType;

/*********** task configuration type definition **********************/

/* Brief Definition of the  DeclareTask Macro */



#define USING_OSEK_NAMING_CONVENTION 1
#if( USING_OSEK_NAMING_CONVENTION )
    #define DeclareTask(name) void MILKSHOP_TASK_##name (void) 
    #define TASK(name) void MILKSHOP_TASK_##name(void)
    #define ISR(name) void MILKSHOP_ISR_##name(void)
    #define ALARMCALLBACK(name) void MILKSHOP_CALLBACK_##name(void)

    #define TASK_ENTRY(name) MILKSHOP_TASK_##name
    #define ISR_ENTRY(name)  MILKSHOP_ISR_##name
#else 
    #define TASK(name) void AUTOSAR_TASK_##name(void)
    /* This macro shall be used to start the definition of all ISRs. */
    #define ISR(name) void AUTOSAR_ISR_##name(void)
#endif

typedef struct ROMTORAM_INIT_TABLE_TYPE{
    uint32 *rom_s; 
    uint32 *rom_e; 
    uint32 *ram_s;
    uint32 *bss_s; 
    uint32 *bss_e;
} RomToRamInitTableType;

typedef struct INT_SERVICE_RECORD_TYPE{
    uint8 DisableAll_Record;
    uint8 SuspendAll_Record;
    uint8 SuspendOS_Record;
} INTServiceRecordType;

/* SWS_Os_00779 */
typedef enum {
    OBJECT_INVALID = 0,
    OBJECT_TASK = 1,
    OBJECT_ISR = 2,
    OBJECT_ALARM = 3,
    OBJECT_RESOURCE = 4,
    OBJECT_COUNTER = 5,
    OBJECT_SCHEDULETABLE = 6,
    OBJECT_SPINLOCK = 7,
} ObjectTypeType;

typedef struct LOCKORDERTYPE{
    ObjectTypeType objectType;      
    uint32 objectId;         
} LockOrderType;

typedef struct SYS_CALL_PARA_TYPE{
    uint32 serviceID;      /*record which process, might need in error-hook */  
    uint32 trustedFuncID;  /*trusted-function-ID*/
    void* paraPtr;         /* pointer to a struct storing papameters, used by service or TF*/
    uint32 RetVal;         /*probably statusType*/
} SysCallInfoType;

typedef struct
{
    unsigned int extended : 1;
    unsigned int preemptive : 1;
    unsigned int isrTask : 1;
} TaskFlagsType;

typedef struct
{
    uint32 sp;
    uint32 lp;
    uint32 eipc;
    uint32 eipsw;
    uint32 gpr[29];
} TaskContextType;

typedef struct CURRENT_OS_CONTEXT_TYPE
{
    uint32 sp;
    uint32 lp;
    uint32 pc;
    uint32 psw;
    uint32 gpr[29];
    uint32 MPM;
} CurrentOSContextType;
typedef CurrentOSContextType *CurrentOSContextRefType;

typedef unsigned char TaskPriorityType;

typedef unsigned char TaskStateType;

typedef TaskStateType *TaskStateRefType;

typedef uint8 TaskActivationsType;

typedef uint64 EventMaskType;

typedef uint32 ResourcesMaskType;

typedef uint32 ApplicationsMaskType;

typedef uint8 *StackPtrType;

typedef uint16 StackSizeType;

typedef TaskContextType *TaskContextRefType;

typedef void (*EntryPointType)(void);

typedef void (*CallbackType)(void);

typedef uint8 TaskTotalType;

typedef uint32 TaskType;

typedef TaskType *TaskRefType;

typedef uint32 ScheduleTableType;

typedef enum {
    FALSE = 0,
    TRUE = 1
} boolean;

typedef struct MEMPROTAREATYPE {
    uint32 MPLAn;
    uint32 MPUAn;
    uint32 MPATn;
} MemProtAreaType;

/*
    Brief Task Constant type definition

    This structure defines all constants and constant pointers
    needed to manage a task.
*/
typedef struct TASKCONSTTYPE
{
    EntryPointType entry;              /* point to the entry of this task */
    TaskContextRefType Context;        /* point to the space used to save context */
    StackPtrType stackZone;            /* point to the stack space */
    StackSizeType stackSize;           /* the size of stack */
    TaskType id;                       /* task id */
    TaskFlagsType Flags;               /* the flags to indicate the status of this task */
    TaskPriorityType staticPriority;   /* the static priority of this task */
    TaskActivationsType maxActivation; /* the maximal number of activations for this task */
    EventMaskType eventsMask;          /* the events mask of this task */
    ResourcesMaskType resourcesMask;   /* the resources mask of this task */
    RomToRamInitTableType RomToRamInitTable;     /* record the table for Rom to Ram init */
} TaskConstType;

/*
    Brief Task Variable type definition

    This structure defines all variables needed to manage a task
*/


/* in task_cfg.c you would notice that INTServiceRecordType and SysCallInfoType 
did not be given a initial value, 
this is because their value will be given when they are in-use */
/* IMPORTANT: if in later version you want to add new item in this struct (TaskVarType) 
insert them before INTServiceRecordType 
so that INTServiceRecordType and SysCallInfoType can remain un-initialized*/
typedef struct TASKVARTYPE
{
    const TaskConstType *StaticPtr;                   /* point to the static task structure */
    struct RESOURCEVARTYPE *Resources;                /* point to the list of resources */
    struct TASKVARTYPE *NextTask;                     /* point to the next variable task structure in ready list */
    TaskActivationsType activateCount;                /* the unmber of actual activations */
    TaskPriorityType priority;                        /* the actual priority of this task */
    TaskStateType state;                              /* the flags to indicate the status of this task */
    struct INTERNALRESOURCEVARTYPE *InternalResource; /* point to the internal resource */
    uint16 executingApp;            /* executing App */
    uint8 nestedTrustFuncCounter;         /* nesting trust function counter */
    boolean isDelay;                 /* indicate whether this task is delay by trusted function */
    INTServiceRecordType INTServiceRecord; /* record of INTControl service */
} TaskVarType;

/* Brief Current Task Type */
typedef struct CURRENT_TASK_TYPE
{
    const TaskConstType *CurrentConst;
    TaskVarType *CurrentVar;
    uint32 currentID;
    unsigned char needSaveContext;
    uint32 MPM;
    //TaskAutosarType *CurrentAutosar;
} CurrentTaskType;

typedef CurrentTaskType *CurrentTaskRefType;

typedef struct SYSCALL_EI_REG_TYPE{
    uint32 kernelSysCallEIPSW;
    uint32 kernelSysCallEIPC;
} SysCallEIRegType;


/* Brief Auto Start Structure Type */
typedef struct
{
    TaskTotalType TotalTasks; /* the unmber of total tasks on this app mode */
    TaskRefType TasksRef;     /* point to the array of autostart tasks on this app mode */
} AutoStartType;

/*********** resource configuration type definition **********************/
typedef uint32 ResourceType;

typedef struct RESOURCEVARTYPE
{
    struct RESOURCEVARTYPE *NextResource;
    const TaskPriorityType *ceilingPriority;
    TaskPriorityType previousPriority;
    TaskType owner;
    ResourceType id;
    LockOrderType prelock;    
} ResourceVarType;

typedef struct INTERNALRESOURCEVARTYPE
{
    const TaskPriorityType *ceilingPriority;
    TaskPriorityType previousPriority;
    TaskType owner;
    ResourceType id;
} InternalResourceVarType;

/************ alarm configuration type definition ***********************/
typedef uint32 TickType;
typedef uint32 HardwareTickType;
typedef uint32 AlarmType;
typedef uint32 CounterType;

typedef struct ALARMBASETYPE
{
    TickType maxallowedvalue;
    HardwareTickType ticksperbase;
    TickType mincycle;
} AlarmBaseType;

typedef AlarmBaseType *AlarmBaseRefType;
typedef TickType *TickRefType;

/*
    It is used to indicate if the alarm is active
    This type defines the possibly states of one alarm which are:
    0 inactive
    1 active
 */
typedef uint8 AlarmActiveType;

typedef enum
{
    ALARMCALLBACK = 0,
    SETEVENT = 1,
    ACTIVATETASK = 2,
    INCREMENTCOUNTER = 3,
    EPCALLBACK = 4
} AlarmActionType;

/*
    brief Alarm Action Info Type
    This type has extra information of the Alarm action
*/
typedef struct
{
    CallbackType callbackFunction;
    TaskType taskID;
    EventMaskType event;
    CounterType counterID;
    ScheduleTableType scheduletableID;
} AlarmActionInfoType;

typedef struct ALARMVARTYPE
{
    struct ALARMVARTYPE *NextAlarm;
    struct ALARMVARTYPE *PrevAlarm;
    AlarmType ID;
    AlarmActiveType active;
    TickType expireCount;
    TickType cycle;
} AlarmVarType;

typedef struct ALARMCONSTTYPE
{
    CounterType counter;
    AlarmActionType alarmAction;
    AlarmActionInfoType AlarmActionInfo;
} AlarmConstType;

typedef struct AUTOSTARTALARMTYPE
{
    AppModeType Mode;
    AlarmType Alarm;
    TickType AlarmTime;
    TickType AlarmCycleTime;
} AutoStartAlarmType;

/************ counter configuration type definition ***********************/
typedef enum
{
    HARDWARE,
    SOFTWARE   
} OSCounterType;

typedef struct COUNTERVARTYPE
{
    struct ALARMVARTYPE *FirstAlarm;
    struct ALARMVARTYPE *NextAlarm;
    HardwareTickType currentTicks;
    TickType currentCounts;
} CounterVarType;

typedef struct COUNTERCONSTTYPE
{
    TickType maxAllowedValue;
    TickType minCycle;
    HardwareTickType ticksPerBase;
    OSCounterType osCounterType;
} CounterConstType;
/************ softwaretimer configuration type definition ***********************/
typedef uint32 SoftwareTimerType;
typedef uint32 SoftwareTimerTickType;

typedef struct SOFTWARETIMERCONSTTYPE
{
    SoftwareTimerTickType maxAllowedValue;
    HardwareTickType tickPerBase;
    CounterType* counterList;
    uint32 listLength;
} SoftwareTimerConstType;
typedef struct SOFTWARETIMERVARTYPE
{
    HardwareTickType currentTicks;
    SoftwareTimerTickType currentCounts;
} SoftwareTimerVarType;

/************ event configuration type definition ***********************/
typedef EventMaskType *EventMaskRefType;
typedef struct EVENTSVARTYPE
{
    EventMaskType eventsSet;
    EventMaskType eventsWait;
} EventsVarType;
/************ Schedule Table configuration type definition ***********************/

typedef enum
{
    SCHEDULETABLE_STOPPED = 0,
    SCHEDULETABLE_NEXT = 1,
    SCHEDULETABLE_WAITING = 2, 
    SCHEDULETABLE_RUNNING = 3,
    SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS = 4,
} ScheduleTableStatusType;

typedef ScheduleTableStatusType *ScheduleTableStatusRefType;

/*ECUC_Os_00065*/
typedef enum{
    EXPLICIT,
    IMPLICIT,
    NONE
} SyncStrategyType;


/* For auto start */
typedef enum{
    ABSOLUTE,
    RELATIVE,
    SYNCHRON
} ScheduleTableAutoStartType;

typedef struct AUTOSTARTSCHEDULETABLETYPE
{
    AppModeType mode;   
    ScheduleTableAutoStartType autoStartType;   /*ECUC_Os_00056*/
    uint64 startValue;                          /*ECUC_Os_00057*/                    /*ECUC_Os_00058*/
    ScheduleTableType scheduleTable;            /*id of the schedule table*/
} AutoStartScheduleTableType;

/*list of event to set*/
typedef struct 
{
    TaskType TaskID;
    EventMaskType Mask;
} EventSetting;


/* expiry point */
typedef struct EXPIRYPOINTTYPE
{
    TickType offset;                    /*offset of this expiry point*/
    uint32 taskStart;                   /*index of the start in task array*/
    uint32 taskEnd;                     /*index of the end in task array*/
    uint32 eventStart;                  /*index of the start in event array*/
    uint32 eventEnd;                    /*index of the end in event array*/
    TickType maxShorten;                /*OsScheduleTableMaxShorten*/
    TickType maxLengthen;               /*OsScheduleTableMaxLengthen*/
    struct EXPIRYPOINTTYPE *next;       /*pointer of next expirypoint*/
} ExpiryPointType;

typedef struct SCHEDULETABLEVARTYPE
{
    ScheduleTableStatusType status;     /*[SWS_Os_00784]*/
    long long deviation;                 /*deviation calculated via syncScheduleTable()*/
    uint32 currentEPIndex;              /*index of the current expiry point*/
    ScheduleTableType next;             /*points to next schedule (via NextScheduleTable())*/
} ScheduleTableVarType;

typedef struct SCHEDULETABLECONSTTYPE
{
    SyncStrategyType syncStrategy;          /*OsScheduleTblSyncStrategy*/
    boolean repeating;                        /*0 for singleshot 1 for repeating*/
    CounterType counter;                    /*driver counter*/
    CounterType syncCounter;                /*synchronization counter*/
    TickType explicitPrecision;             /*OsScheduleTblExplicitPrecision*/
    uint32 EPAmount;                        /*amount of expiry points*/
    TickType duration;                  /*duration of the schedule table*/
    TickType initOffset;                /*initial offset*/
    TickType finalDelay;                /*final delay*/
    AlarmType callbackAlarm;                /*id of alarm for callback function*/
    ExpiryPointType *expiryPoints;          /*points to the list of expiry points*/
    TaskType *taskArray;                    /*points to the array of tasks*/
    EventSetting *eventArray;               /*points to the array of events*/
} ScheduleTableConstType;

/************ Os-Application configuration type definition ***********************/

/* SWS_Os_00772 */
typedef uint32 ApplicationType;

typedef ApplicationType *ApplicationRefType;

/* SWS_Os_00773 */
typedef enum APPLICATIONSTATETYPE
{
    APPLICATION_ACCESSIBLE = 0,
    APPLICATION_RESTARTING = 1,
    APPLICATION_TERMINATED = 2
} ApplicationStateType;

/* SWS_Os_00774 */
typedef ApplicationStateType *ApplicationStateRefType;

typedef boolean OsTrustedType;

/* SWS_Os_00775 */
typedef uint32 TrustedFunctionIndexType;

/* SWS_Os_00776 */
typedef uint32 *TrustedFunctionParameterRefType;

typedef void (*TrustedFuncPtrType)( TrustedFunctionIndexType, TrustedFunctionParameterRefType);

typedef struct TRUSTED_FUNCTION_AUTOSAR_TYPE{
    ApplicationType owner;
    ApplicationsMaskType applicationsMask;    
} TrustedFunctionAutosarType;

/* SWS_Os_00787 */
/* This data type identifies a value which controls */ 
/* further actions of the OS on return from the protection hook. */
typedef enum {
    PRO_IGNORE = 0,                 //ignore
    PRO_TERMINATETASKISR = 1,       //TerminateTask()
    PRO_TERMINATEAPPL = 2,          //TerminateApplication
    PRO_TERMINATEAPPL_RESTART = 3,  //TerminateApplication w. restart
    PRO_SHUTDOWN = 4                //shutdownOS
}ProtectionReturnType; 

/* This type is used to store objects id */
typedef struct {
    void *objectsRef;
    uint16 objectsCount;
} AppObjectsType;

/* This type is used to store objects id which belong to a os-app */
typedef struct
{
    AppObjectsType Tasks;
    AppObjectsType Counters;
    AppObjectsType Alarms;
    AppObjectsType ScheduleTables;
    AppObjectsType ISRs;
    AppObjectsType TFs;     //trusted function
} ApplicationObjectsType;

typedef ApplicationObjectsType *ApplicationObjectsRefType;

typedef struct CORE_APP_TYPE{
    ApplicationType* AppsRef;
    uint16 AppsCount;
} AppsInCoreType;

/* SWS_Os_91000 */
/* AreaIdType identifies a peripheral area and is used by the API  */
/* functions: ReadPeripheralX, Write PeripheralX and ModifyPeripheralX */
typedef uint16 AreaIdType;

//peripheral information v1
// typedef struct PERI_ACCESS_INFO_TYPE
// {
//     uint16 area_num; 
//     AreaIdType *area_array;
// } PeriAccessInfoType;

typedef struct
{
    uint32 OsperipheralAreaStartAddress;
    uint32 OsperipheralAreaEndAddress;
}peri_info;

typedef struct {
    void (*StartupHookFunc)(void);
    void (*ShutdownHookFunc)(StatusType Error);
    void (*ErrorHookFunc)(StatusType Error);
} AppHookFuncArrayType;

typedef void (*StartupHookFuncPtrType)(void);
typedef void (*ShutdownHookFuncPtrType)(StatusType Error);
typedef void (*ErrorHookFuncPtrType)(StatusType Error);
/*
    Brief OS-Application Variable type definition
    This structure defines all variables and constant needed to manage a OS-Application
    "trustWithProt" is correspond to OsTrustedApplicationWithProtection in SPEC
*/
typedef struct
{
    ApplicationType id;
    ApplicationStateType State;
    OsTrustedType OsTrusted;
    EcucPartitionIdType EcucRef;
    CoreIdType CoreRef;
    uint8 OsTrustedApplicationWithProtection;
    uint8 OsTrustedAppWithTimingProt;
    uint8 OsTrustedApplicationDelayTimingViolationCall;
    TaskType RestartTaskID;       /*which ID is the restart task, if not cfg, will be assign INVALID_TASK_ID*/
    ApplicationObjectsRefType Objects;
    AppHookFuncArrayType AppHookFuncArray;
    RomToRamInitTableType RomToRamInitTable;         /* record the table for Rom to Ram init */
    MemProtAreaType *MemArea;
    ResourceType Resource;     /* resource for trusted function */
} ApplicationVarType;
#define WithoutMemProt 0   /* default is WithoutMemProt for "OsTrustedApplicationWithProtection" */
#define WithMemProt 1
#define NonTrust 2
#define WithoutTimeProt 0   /* default is WithoutTimeProt for "trustWithTimeProt" */
#define WithTimeProt 1

typedef ApplicationVarType *ApplicationVarRefType;

/*SWS_Os_00777*/
/* using only LSB 4 bits for [IS_STACK, S_EXECUTABLE, IS_WRITABLE, IS_READABLE]*/
typedef uint32 AccessType;

/* SWS_Os_00778 */
typedef enum {
    NO_ACCESS = 0,
    ACCESS = 1
} ObjectAccessType;

/* SWS_Os_00788 */
/* This data type defines the use of a Restart Task */
/* after terminating an OS-Application */
typedef enum {
    NO_RESTART = 0,
    RESTART = 1
} RestartType;

/* SWS_Os_00782 */
typedef uint32 ISRType;
typedef ISRType *ISRRefType;    //for convenience, like TaskRefType

/*SWS_Os_00780*/
/*pointer which is able to point to any location in the MCU address space.*/
typedef void* MemoryStartAddressType;

/*SWS_Os_00781*/
/*This data type holds the size (in bytes) of a memory region*/
typedef uint32 MemorySizeType;

typedef struct MEMORY_AREA_INFO_TYPE{
    MemoryStartAddressType MemoryStartAddr;
    MemorySizeType MemorySize;
}MemoryAreaInfoType;

typedef struct OS_PERI_AREA_INFO_TYPE{
    uint32 OsPeriAreaID;
    uint32 OsPeriAreaStartAddr;
    uint32 OsPeriAreaEndAddr;
    ApplicationsMaskType applicationsMask;
}OsPeriAreaInfoType;

/* Attributes of ISR */
#define ISR_CAT_1 1 //ISR category 1
#define ISR_CAT_2 2 //ISR category 2
typedef struct ISRCONSTTYPE
{
    ISRType isrID; 
    uint8 ISRcategory;
    uint8 ISRprio;
    uint16 ISRchannel;
    TaskType ISR2TaskRefIndex;    //isr2-task relative TaskID-index to get TaskAutosarType
} IsrConstType;
typedef IsrConstType* IsrConstRefType;

typedef struct {
    void (*disableSource)(void);
    void (*enableSource)(void);
    void (*clearPending)(void);
} IsrControlType;
typedef IsrControlType* IsrControlRefType;

#define DISABLE_SOURCE(name)       void disableSource_ ## name(void)
#define DISABLE_SOURCE_ENTRY(name) disableSource_ ## name
#define ENABLE_SOURCE(name)        void enableSource_ ## name(void)
#define ENABLE_SOURCE_ENTRY(name)  enableSource_ ## name
#define CLEAR_PENDING(name)        void clearPending_ ## name(void)
#define CLEAR_PENDING_ENTRY(name)  clearPending_ ## name

/* SWS_Os_00791 */
typedef uint16 SpinlockIdType;

/* This type is used to lock of spinlock, a bit correspond to a spinlock */
typedef uint8 LockType;

/* This type is used to represent the method of disable interrupt when get a spinlock */
typedef uint8 LockMethodType;

/* SWS_Os_00792 */
typedef enum {
    TRYTOGETSPINLOCK_NOSUCCESS = 0,
    TRYTOGETSPINLOCK_SUCCESS = 1
} TryToGetSpinlockType;

/*
    Brief Spinlock Constant type definition

    This structure defines all constants and constant pointers
    needed to manage a spinlock.
*/
typedef struct {
    SpinlockIdType id;                      /* spinlock id */
    ApplicationsMaskType applicationsMask;  /* the access application */ 
    LockMethodType lockMethod;              /* the method of disable interrupt */
} SpinlockConstType;

/*
    Brief Spinlock Variable type definition

    This structure defines all variables needed to manage a spinlock
*/
typedef struct {
    // SpinlockIdType preSpinlock;
    LockOrderType preLock;
    CoreIdType ownerCoreID;
    TaskType ownerTaskID;
} SpinlockVarType;


// typedef struct MEMPROTTYPE {
//     uint32 MPRC;
//     uint8 areaCount;
//     uint8 initAreaCount;
//     MemProtAreaType *MemArea;
// } MemProtType;

typedef enum {
    IDLETASKBUDGET = 0,
    EXECUTEBUDGET = 1,
    TIMEFRAME = 2,
    INTLOCKBUDGET = 3,
    RESLOCKBUDGET = 4
} TimingProtTypeType;

typedef struct TIMINGPROTCOUNTERTYPE{
    TimingProtTypeType ProtectionType;
    HardwareTickType Bound;
    HardwareTickType Counter;
    struct TIMINGPROTCOUNTERTYPE *PreTimgingCounter;
    struct TIMINGPROTCOUNTERTYPE *NextTimingCounter;
} TimingProtCounterType;

typedef struct {
    HardwareTickType ExecuteBudget;
    HardwareTickType TimeFrame;
    const struct LOCKBUDGETTYPE *LockBudgetRef;
} TimingProtBudgetType;

typedef struct LOCKBUDGETTYPE {
    uint32 LockBudgetID;
    HardwareTickType LockBudget;
} LockBudgetType;

typedef struct {
    TimingProtCounterType *TaskExecutingCounter;
    TimingProtCounterType *TaskArrivalCounter;
    TimingProtCounterType *ResourceTimingCounter;
    TimingProtCounterType *InterruptTimingCounter;
    const TimingProtBudgetType *TimingBudget;
} SystemTimingCounterType;

/* Autosar Type: Additional data structure for objects (task, alarm, counter etc.) when use autosar spec. */
typedef struct {
    ApplicationType owner;
    ApplicationsMaskType applicationsMask;
    SpinlockIdType lastSpinlock;
    MemProtAreaType *MemArea;
    LockOrderType lastLock;
} TaskAutosarType;

typedef struct {
    ApplicationType owner;
    ApplicationsMaskType applicationsMask;      
    //SpinlockIdType lastSpinlock;              //record in TaskAutosarType as isr2-task
    //MemProtType MemProtect;                   //record in TaskAutosarType as isr2-task
} IsrAutosarType;

typedef struct {
    ApplicationType owner;
    ApplicationsMaskType applicationsMask;
} AlarmAutosarType;

typedef struct {
    ApplicationType owner;
    ApplicationsMaskType applicationsMask;
} CounterAutosarType;

typedef struct {
    ApplicationType owner;
    ApplicationsMaskType applicationsMask;
} ScheduleTableAutosarType;

typedef struct {
    ApplicationsMaskType applicationsMask;
} ResourceAutosarType;

typedef struct{
    ApplicationsMaskType applicationsMask;
}IocAutosarType;
typedef struct{
    ApplicationsMaskType applicationsMask;
}PeripheralAutosarType;

// config order 
typedef struct {
    uint8 tasksCount;
    uint8 isrsCount;
    uint8 alarmsCount;
    uint8 countersCount;
    uint8 scheduletablesCount;
    uint8 resourcesCount;
    uint8 trustfunctoncount;
    TaskAutosarType *TaskAutosar;
    IsrAutosarType *IsrAutosar;     
    AlarmAutosarType *AlarmAutosar;
    CounterAutosarType *CounterAutosar;
    ScheduleTableAutosarType *ScheduleTableAutosar;
    ResourceAutosarType *ResourceAutosar;
    IocAutosarType *IocAutosar_s;
    IocAutosarType *IocAutosar_r;
    PeripheralAutosarType *PeripheralAutosar;
    TrustedFunctionAutosarType *trustedFunctionAutosar;

} SystemObjectAutosarType;

typedef SystemObjectAutosarType *SystemObjectAutosarRefType;



/*********** core configuration type definition **********************/
typedef struct 
{
    uint8 isAutosarOS;
    CoreActivatedType CoreActivated;
} CoreStatusType;


typedef struct SIMU_ECUC_PARTITION_SETTING_TYPE 
{
    char* EcuName;
    char* CoreName;
    uint8 CoreNum;
    uint8 isSupportMPU;
} SimuEcucPartitionSettingType;

/*
    Brief system variable type definition

    This structure defines all system variable.
*/
typedef struct
{
    AppModeType activeApplicationMode;
    uint32 systemFlag;
    signed char disableAllInterruptsCounter;
    signed char suspendAllInterruptsCounter;
    signed char suspendOSInterruptsCounter;
    int kernelDisableInterruptsCounter;
    int kernelDisableLowPriorityInterruptsCounter;
    int kernelSystemCallCounter;
} SystemVarType;

typedef SystemVarType *SystemVarRefType;

typedef struct 
{
    uint32 readyListFlag;
    struct TASKVARTYPE **ReadyList;
    struct TASKVARTYPE **ReadyListTail;
} SystemReadyListType;

typedef SystemReadyListType *SystemReadyListRefType;

/*
    Brief system objects variable type definition

    This structure defines all system objects variable.
*/
typedef struct
{
    uint8 tasksCount;
    uint8 extendedTasksCount;
    uint8 isr2TaskCount;
    uint8 taskObjectsCount;
    uint8 isrAllCount;
    uint8 resourcesCount;
    uint8 alarmsCount;
    uint8 alarmsAutoStartConunt;
    uint8 countersCount;
    uint8 scheduletableCount; 
    uint8 ScheduleTableAutoStartCount;
    uint8 SoftwareTimerCount;

    const TaskConstType *  TaskConst;
    TaskVarType *TaskVar;
    IsrConstType *IsrConst;
    EventsVarType *EventsVar;
    //TaskPriorityType *ResourcesPriority;
    ResourceVarType *ResourceVar;

    const AlarmConstType *AlarmConst;
    AlarmVarType *AlarmVar;
    AutoStartAlarmType *AutoStartAlarm;

    const CounterConstType *CounterConst;
    CounterVarType *CounterVar;
    
    const ScheduleTableConstType *ScheduleTableConst;
    ScheduleTableVarType *ScheduleTableVar;
    AutoStartScheduleTableType *AutoStartScheduleTable;
    
    const struct SOFTWARETIMERCONSTTYPE* SoftwareTimerConst;
    struct SOFTWARETIMERVARTYPE* SoftwareTimerVar;
} SystemObjectsType;

typedef SystemObjectsType *SystemObjectsRefType; 

/* This structure is used to store the information of API calling when the API need to cross core access */
typedef struct {
    ApplicationType App;
    uint8 serviceID;
    uint32 para1;
    uint32 para2;
    uint32 para3;
    StatusType result;
} ServiceParaType;

/* IdleModeType */
typedef uint8 IdleModeType;

/* This structure is used to store the information of the system service*/
typedef struct {
    uint8 serviceID;
    uint32 para1;
    uint32 para2;
    uint32 para3;
    StatusType result;
} SysServiceParaType;

/* Define systask action*/
typedef enum
{
    STARTUPHOOK,
    SHUTDOWNHOOK,
    APPLERRORHOOK,
    IOCCALLBACK,
    BOTSTARTOS,
    BOTSHUTDOWNOS,
    BOTSHUTDOWNALLCORES,
} SysTaskActionType;


/* This structure define SysTask action */
typedef struct{
    SysTaskActionType SysTaskAction;
    ApplicationType ApplID;
    void (* FunctionPointer)(StatusType Error);
    uint32 para;
} SysTaskInformationType;

typedef struct{
    SysTaskInformationType *SysTaskInformation;
    uint8 length;
    uint8 head;
    uint8 tail;
    boolean isEmpty;
} SysTaskActionQueueType;


#endif /* #ifndef TYPEDEFINE_H */