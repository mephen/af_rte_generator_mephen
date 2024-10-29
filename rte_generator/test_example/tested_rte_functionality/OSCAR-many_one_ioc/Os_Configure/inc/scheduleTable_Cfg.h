#ifndef SCHEDULETABLE_CFG_H
#define SCHEDULETABLE_CFG_H

/*==================[inclusions]=============================================*/
#include "ScheduleTable.h"
#include "typedefine.h"
/*==================[macros]=================================================*/
/* brief Definition of the DeclareAlarmCallback Macro */
#define DeclareCallback(name) void MILKSHOP_CALLBACK_ ## name (void)

/* brief count of scheduletables */
#define SCHEDULETABLE_COUNT_CORE0 2
#define SCHEDULETABLE_COUNT_CORE1 1
#define SCHEDULETABLE_COUNT 3

/* brief Definition of the ScheduleTable ScheduleTableA */
#define scheduletable1 0x00000000

extern ScheduleTableType ScheduleTableA;
/* brief Definition of the ScheduleTable ScheduleTableB */
#define scheduletable2 0x00000001

extern ScheduleTableType ScheduleTableB;

/* brief Definition of the ScheduleTable ScheduleTableA */
#define scheduletable3 0x00010000

#define INVALID_SCHEDULETABLE_ID 0x00020000

/*brief Definition of the AutoStart  ScheduleTable */
#define SCHEDULETABLE_AUTOSTART_COUNT_CORE0 0
#define SCHEDULETABLE_AUTOSTART_COUNT_CORE1 0
#define SCHEDULETABLE_AUTOSTART_COUNT 0

/*==================[external data declaration]=========================*/

/* brief ScheduleTable Variable Structure */
extern ScheduleTableVarType ScheduleTableVar_core0[SCHEDULETABLE_COUNT_CORE0];
extern ScheduleTableVarType ScheduleTableVar_core1[SCHEDULETABLE_COUNT_CORE1];

/* brief ScheduleTable Constant Structure */
extern const ScheduleTableConstType ScheduleTableConst_core0[SCHEDULETABLE_COUNT_CORE0];
extern const ScheduleTableConstType ScheduleTableConst_core1[SCHEDULETABLE_COUNT_CORE1];

/* brief Accessible App of ScheduleTable */
extern ScheduleTableAutosarType ScheduleTableAutosar_core0[SCHEDULETABLE_COUNT_CORE0];
extern ScheduleTableAutosarType ScheduleTableAutosar_core1[SCHEDULETABLE_COUNT_CORE1];

/* brief AutoStartScheduleTable Structure */
// extern const AutoStartScheduleTableType AutoStartScheduleTabl_core0[SCHEDULETABLE_AUTOSTART_COUNT_CORE0];

/* brief count of expirypoints */
#define EXPIRYPOINT_COUNT_0 2
/* brief ExpiryPoints Structure */
extern ExpiryPointType expiryPoints_0[EXPIRYPOINT_COUNT_0];

/* brief count of expirypoints */
#define EXPIRYPOINT_COUNT_1 1
/* brief ExpiryPoints Structure */
extern ExpiryPointType expiryPoints_1[EXPIRYPOINT_COUNT_1];

/* brief count of expirypoints */
#define EXPIRYPOINT_COUNT_3 1
/* brief ExpiryPoints Structure */
extern ExpiryPointType expiryPoints_3[EXPIRYPOINT_COUNT_3];


/* Brief Callback Declaration of Callback ExpiryPointCallbackFuncA */
DeclareCallback(ExpiryPointCallbackFuncA);
/* Brief Callback Declaration of Callback ExpiryPointCallbackFuncB */
DeclareCallback(ExpiryPointCallbackFuncB);
/* Brief Callback Declaration of Callback ExpiryPointCallbackFuncC */
DeclareCallback(ExpiryPointCallbackFuncC);



/*==================[end of file]============================================*/
#endif /* #ifndef SCHEDULETABLE_CFG_H */
