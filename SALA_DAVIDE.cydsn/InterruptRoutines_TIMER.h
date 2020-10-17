/* ========================================
 *
 * Header file of the ISR of the TIMER
 * The ISR is called every time the counter of the timer reaches the 0
 *
 * ========================================
*/
#ifndef __INTERRUPT_ROUTINE_TIMER_
    #define __INTERRUPT_ROUTINE_TIMER_
    
    #include "project.h"
    #include "GlobalVariables.h"
  
    CY_ISR_PROTO(Custom_TIMER_RX_ISR);
    
#endif
/* [] END OF FILE */
