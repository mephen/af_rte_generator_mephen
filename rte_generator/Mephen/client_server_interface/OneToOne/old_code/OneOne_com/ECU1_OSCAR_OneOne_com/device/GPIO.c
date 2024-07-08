#include "iodefine.h"
#include "GPIO.h"

/******************************************************************************
** Function:    GPIO_init
** Description: set P10_3 and P8_5 output mode for LED1 and LED2
** Parameter:   None
** Return:      None
******************************************************************************/
void GPIO_init(void)
{
    /* Set P10_3 output mode to turn on the LED1 */
    P10 |= PIN3;        // Port Register: Holds the data to be output when it is output mode
                        // Set P10_3 outputs high level
    PM10 &= ~PIN3;      // Port Mode Register (0: Output mode, 1: Input mode)
                        // Set P10_3 output mode

    /* Set P8_5 output mode to turn on the LED2 */
    P8 |= PIN5;         // Port Register: Holds the data to be output when it is output mode
                        // Set P8_5 outputs high level
    PM8 &= ~PIN5;       // Port Mode Register (0: Output mode, 1: Input mode)
                        // Set P8_5 output mode
}
