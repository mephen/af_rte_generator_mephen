#include "Rte_Type.h"

/* EcuM_StartupTwo */
void EcuM_StartupTwo(void);

/* EcuM_GoDown */
void EcuM_GoDown(void);

/* BSW Scheduler Life-Cycle API */
void SchM_Start(void);
void SchM_Init(const SchM_ConfigType* ConfigPtr);
void SchM_StartTiming(void);
void SchM_Deinit(void);
void SchM_GetVersionInfo(Std_VersionInfoType *versioninfo);

/* RTE Life-Cycle API */
Std_ReturnType Rte_Start(void);
void Rte_StartTiming(void);
Std_ReturnType Rte_Stop(void);
