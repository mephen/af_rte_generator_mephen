#ifndef SCHEDULETABLE_CFG_H
#define SCHEDULETABLE_CFG_H

/*==================[inclusions]=============================================*/
#include "typedefine.h"
#include "ScheduleTable.h"
/*==================[macros]=================================================*/
/* brief Definition of the DeclareAlarmCallback Macro */
#define DeclareCallback(name) void MILKSHOP_CALLBACK_ ## name (void)
/* brief count of scheduletables */
#define SCHEDULETABLE_COUNT_CORE0 2
#define SCHEDULETABLE_COUNT_CORE1 1
#define SCHEDULETABLE_COUNT 3

/* brief Definition of the ScheduleTable ST2 */
#define ST2 0x00000000
/* brief Definition of the ScheduleTable ST3 */
#define ST3 0x00000001
/* brief Definition of the ScheduleTable ST1 */
#define ST1 0x00010000
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

/* brief count of expirypoints */
#define EXPIRYPOINT_COUNT_ST2 2
/* brief ExpiryPoints Structure */
extern ExpiryPointType expirypoint_ST2[EXPIRYPOINT_COUNT_ST2];

/* brief count of expirypoints */
#define EXPIRYPOINT_COUNT_ST3 2
/* brief ExpiryPoints Structure */
extern ExpiryPointType expirypoint_ST3[EXPIRYPOINT_COUNT_ST3];

/* brief count of expirypoints */
#define EXPIRYPOINT_COUNT_ST1 2
/* brief ExpiryPoints Structure */
extern ExpiryPointType expirypoint_ST1[EXPIRYPOINT_COUNT_ST1];

/*==================[end of file]============================================*/
#endif /* #ifndef SCHEDULETABLE_CFG_H */
