/* ========================================
 *
 * The only thing that is done in this isr is the setting of the state
 * This state = LATE is then used in the main to initialize the UART and print a message
 * 
 * ========================================
*/

#include "InterruptRoutines_TIMER.h"

CY_ISR(Custom_TIMER_RX_ISR) {
    
    Timer_ReadStatusRegister();
    state = LATE;
}
/* [] END OF FILE */

