/* ========================================
 *
 * Header file of the ISR
 * The ISR is called every time the UART acquire a byte
 * ========================================
*/

#ifndef __INTERRUPT_ROUTINE_
    #define __INTERRUPT_ROUTINE_
    
    #include "cytypes.h"
    #include "project.h"
    #include "ColourDriver.h"
    #include "GlobalVariables.h"
    
    #define CORRECT_HEADER 0xA0
    #define CORRECT_TAIL 0xC0
    
    CY_ISR_PROTO(Custom_UART_RX_ISR);
    
#endif
    

/* [] END OF FILE */
