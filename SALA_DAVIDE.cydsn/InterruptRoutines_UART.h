/* ========================================
 *
 * Header file of the ISR of the UART
 * The ISR is called every time the UART acquires a byte
 * 
 * ========================================
*/

#ifndef __INTERRUPT_ROUTINE_UART_
    #define __INTERRUPT_ROUTINE_UART_
    
    #include "cytypes.h"
    #include "project.h"
    #include "ColourDriver.h"
    #include "GlobalVariables.h"
    
    #define CORRECT_HEADER 0xA0 //Definition of the correct HEADER
    #define CORRECT_TAIL 0xC0 //Definition of the correct TAIL
    
    CY_ISR_PROTO(Custom_UART_RX_ISR);
    
#endif
    

/* [] END OF FILE */
