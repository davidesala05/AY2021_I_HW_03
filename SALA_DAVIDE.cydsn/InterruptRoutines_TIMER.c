/* ========================================
 *
 * The only thing that is done in this isr is the setting of a flag
 * This flag is then used in the main to initialize the UART and to print a message
 * 
 * ========================================
*/

#include "InterruptRoutines_TIMER.h"


CY_ISR(Custom_TIMER_RX_ISR) {
    
    Timer_ReadStatusRegister();
    flag_5_sec = 1;
}
/* [] END OF FILE */

