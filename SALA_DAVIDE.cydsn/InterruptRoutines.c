/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "InterruptRoutines.h"
#include "ColourDefinition.h"


CY_ISR(Custom_UART_RX_ISR) {
    
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY) {
        
        flag_reset_timer = 1;
        if (count == 0){
            
            header = UART_ReadRxData();
            if (header == 'v'){
                flag_v = 1;
            }
            else if (header != 0xA0){
                flag_error = 1;
            }
        }
        if (count == 1){
            
            c.red = UART_ReadRxData();
        }
        if (count == 2){
            
            c.green = UART_ReadRxData();
        }
        if (count == 3){
            
            c.blue = UART_ReadRxData();
        }
        if (count == 4){
            
            tail = UART_ReadRxData();
            if (tail != 0xC0){
                flag_error = 1;
            }
            if (flag_error == 0){
                flag_end_transmission = 1;
                SetColour(c);
                flag_error = 0;
            }
        }
        
        count ++;
    }
    
}
/* [] END OF FILE */
