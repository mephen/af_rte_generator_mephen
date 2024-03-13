#ifndef APPLICATION_CFG_H
#define APPLICATION_CFG_H
/*==================[inclusions]=============================================*/
#include "typedefine.h"

/*==================[macros]=================================================*/
#define APPLICATIONS_COUNT_CORE0 2
#define APPLICATIONS_COUNT_CORE1 2
#define APPLICATIONS_COUNT 4
#define TRUSTED_APPLICATIONS_COUNT 2
#define TRUSTED_FUNCTIONS_COUNT 0
#define App1 0
#define App2 1
#define App3 2
#define App4 3
#define INVALID_OSAPPLICATION 4
/*==================[external data declaration]=========================*/
extern ApplicationVarType ApplicationVar[APPLICATIONS_COUNT];
/*the ApplicationObjectsType are currrently used only in application.c*/
extern ApplicationObjectsType ApplicationObjects_core0[APPLICATIONS_COUNT_CORE0];
extern ApplicationObjectsType ApplicationObjects_core1[APPLICATIONS_COUNT_CORE1];
extern LockType lockForApplicationState[APPLICATIONS_COUNT];
/*==================[end of file]============================================*/
#endif /* #ifndef APPLICATION_CFG_H */
