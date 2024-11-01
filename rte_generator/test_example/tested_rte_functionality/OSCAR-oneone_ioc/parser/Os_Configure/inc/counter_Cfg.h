#ifndef COUNTER_CFG_H
#define COUNTER_CFG_H

/*==================[inclusions]=============================================*/
#include "typedefine.h"

/*==================[macros]=================================================*/
#define COUNTERS_COUNT_CORE0 4
#define COUNTERS_COUNT_CORE1 3
#define COUNTERS_COUNT 7

/* brief Definition of the Counter counter2 */
#define counter2 0x00000000
/* brief Definition of the Counter counter4 */
#define counter4 0x00000001
/* brief Definition of the Counter counter_ST2 */
#define counter_ST2 0x00000002
/* brief Definition of the Counter counter_ST3 */
#define counter_ST3 0x00000003
/* brief Definition of the Counter counter1 */
#define counter1 0x00010000
/* brief Definition of the Counter counter3 */
#define counter3 0x00010001
/* brief Definition of the Counter counter_ST1 */
#define counter_ST1 0x00010002


#define INVALID_COUNTER_ID 0x00020000

/* brief Definition of the Counter DriveCounter */
#define DriveCounter 0

/*==================[external data declaration]=========================*/
/* brief Counter Var Structure */
extern CounterVarType CounterVar_core0[COUNTERS_COUNT_CORE0];
extern CounterVarType CounterVar_core1[COUNTERS_COUNT_CORE1];

/* brief Counter Const Structure */
extern const CounterConstType CounterConst_core0[COUNTERS_COUNT_CORE0];
extern const CounterConstType CounterConst_core1[COUNTERS_COUNT_CORE1];

/* brief Accessible App of Counter */
extern CounterAutosarType CounterAutosar_core0[COUNTERS_COUNT_CORE0];
extern CounterAutosarType CounterAutosar_core1[COUNTERS_COUNT_CORE1];

/*==================[end of file]============================================*/
#endif /* #ifndef COUNTER_CFG_H */
