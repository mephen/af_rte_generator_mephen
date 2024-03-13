/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :Mon, Oct 24, 2016                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#include "iodefine.h"
#include "board.h"
#include "os.h"
#include "os_Cfg.h"
#include "task_Cfg.h"
#include "event_Cfg.h"
#include "alarm_Cfg.h"
#include "application_Cfg.h"
#include "event.h"
#include "task.h"
#include "memsection.h"
#include "memprot_Cfg.h"

#include "string_format_test.h"
#include "ISRInit.h"
#include "systemcall.h"

#pragma section

extern int PrintText(char *TextArray);
extern int PrintText_R35(char *TextArray);

void main_pe2(void)
{
    StartOS(DONOTCARE);
    while (1);
}

/************* USER_SHARED_SEC *****************/
#pragma section USER_SHARED_SEC







