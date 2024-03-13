/*==================[inclusions]=============================================*/
#include "typedefine.h"

/*==================[macros]=================================================*/
#define SOFTWARETIMERS_COUNT_CORE0 1
#define SOFTWARETIMERS_COUNT_CORE1 1
#define SOFTWARETIMERS_COUNT 2
#define COUNTERS_COUNT_COUNTERLIST_1 4
#define COUNTERS_COUNT_COUNTERLIST_2 3
#define softwaretimer1 0x00000000
#define softwaretimer2 0x00010000
/*==================[external data declaration]=========================*/

/* brief Counter Var Structure */
extern SoftwareTimerVarType SoftwareTimerVar_core0[SOFTWARETIMERS_COUNT_CORE0];
extern SoftwareTimerVarType SoftwareTimerVar_core1[SOFTWARETIMERS_COUNT_CORE1];

/* brief Counter Const Structure */
extern const SoftwareTimerConstType SoftwareTimerConst_core0[SOFTWARETIMERS_COUNT_CORE0];
extern const SoftwareTimerConstType SoftwareTimerConst_core1[SOFTWARETIMERS_COUNT_CORE1];
extern uint32 HARDWARETIMER_PERIOD[OsNumberOfCores];
