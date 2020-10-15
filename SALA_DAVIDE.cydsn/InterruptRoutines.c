/* ========================================
 *
 * Here all the acquisition of the bytes transmitted by the UART are saved in the header, tail and colour variables
 * Moreover, if the transimission is correct, the function to chnage the colour is called
 * 
 * ========================================
*/
#include "InterruptRoutines.h"
#include "ColourDefinition.h"


CY_ISR(Custom_UART_RX_ISR) {
    
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY) { //Control if a byte is acquired
        
        flag_reset_timer = 1; //flag for the reset of the timer --> trasmission within 5 seconds controlled in the main
        if (count == 0){ //first byte --> HEADER or V
            
            header = UART_ReadRxData(); //header is saved
            if (header == 'v'){ //control if the first byte is the "v" value
                flag_v = 1; //Flag used in the main to put in output the correct string and reset the UART
            }
            else if (header != CORRECT_HEADER){ //If the string in not the correct one
                flag_error = 1; //Flag used in the main to initialized the UART and display a message of error
            }
        }
        if (count == 1){ //second byte --> RED COLOUR
            
            c.red = UART_ReadRxData();
        }
        if (count == 2){ //third byte --> GREEN COLOUR
            
            c.green = UART_ReadRxData();
        }
        if (count == 3){ //fourth byte --> BLUE COLOUR
            
            c.blue = UART_ReadRxData();
        }
        if (count == 4){ //fifth bythe --> TAIL
            
            tail = UART_ReadRxData();
            if (tail != CORRECT_TAIL){ //If the tail is not the correct one
                flag_error = 1;
            }
            if (flag_error == 0){ //If all the values are correct
                flag_end_transmission = 1;
                SetColour(c); //The new colour is saved
            }
        }
        
        count ++; //the count variable is incremented by 1 to save the next byte
    }
    
}
/* [] END OF FILE */
