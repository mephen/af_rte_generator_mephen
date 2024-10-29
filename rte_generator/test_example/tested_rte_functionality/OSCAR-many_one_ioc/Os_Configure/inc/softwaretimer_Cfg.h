#include "typedefine.h"

/* brief COUNTERS_COUNT define */
#define SOFTWARETIMERS_COUNT_CORE0 2
#define SOFTWARETIMERS_COUNT_CORE1 2
#define SOFTWARETIMERS_COUNT 4
#define COUNTERS_COUNT_COUNTERLIST_1 2
#define COUNTERS_COUNT_COUNTERLIST_2 2


/* brief Definition of the Counter counter2 */
#define softwaretimer1 0x00000000
/* brief Definition of the Counter counter4 */
#define softwaretimer2 0x00000001
/* brief Definition of the Counter counter1 */
#define softwaretimer3 0x00010000
/* brief Definition of the Counter counter3 */
#define softwaretimer4 0x00010001
/*==================[external data declaration]=========================*/

/* brief Counter Var Structure */
extern SoftwareTimerVarType SoftwareTimerVar_core0[SOFTWARETIMERS_COUNT_CORE0];
extern SoftwareTimerVarType SoftwareTimerVar_core1[SOFTWARETIMERS_COUNT_CORE1];

/* brief Counter Const Structure */
extern const SoftwareTimerConstType SoftwareTimerConst_core0[SOFTWARETIMERS_COUNT_CORE0];
extern const SoftwareTimerConstType SoftwareTimerConst_core1[SOFTWARETIMERS_COUNT_CORE1];
extern uint32 HARDWARETIMER_PERIOD[OsNumberOfCores];