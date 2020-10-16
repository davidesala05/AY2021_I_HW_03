/* ========================================
 *
 * SECOND ASSIGNMENT
 * DAVIDE SALA

 * ========================================
*/
#include "project.h"
#include "InterruptRoutines.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    
    UART_Start(); // All the components are let started
    Timer_Start();
    PWM_RG_Start();
    PWM_B_Start();
    
    isr_UART_StartEx(Custom_UART_RX_ISR);
    
    for(;;)
    {
        
        if (flag_reset_timer == 1){ //If an interrupt is called, the timer is reset to the period in order to count other 5 seconds
            Timer_WriteCounter(500);
            flag_reset_timer = 0;
        }
        if ((Timer_ReadCounter() == 0) && (count != 0)){ //If five seconds are passed the initialization of the UART is done and a message is displayed
            UART_PutString("5 seconds have been passed\n"); //The condition of the count != 0 is useful to not print the message every 5 seconds 
            count = 0;
            UART_Init(); //initialization of the UART to erase all the register 
        }
        if (flag_end_transmission == 1){ //If the trasmission is right and is completed (all 4 bytes have been saved) a message of correct acquisition is displayed 
            UART_PutString("All the four bytes have been aquired\n");
            count = 0;
            flag_end_transmission = 0;
        }
        if (flag_v == 1){ //If the "v" character is write, the predefined string is passed
            UART_PutString("RGB LED Program $$$\n");
            flag_v = 0;
            count = 0;
        }
        if (flag_error == 1){ //If an error in the trasmission (not correct header or tail) occur a message is displayed
            UART_PutString("ERROR in the transmission\n");
            count = 0;
            UART_Init();
            flag_error = 0;
        }
    }
}

/* [] END OF FILE */
