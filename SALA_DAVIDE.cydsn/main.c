/* ========================================
 *
 * THIRD ASSIGNMENT
 * DAVIDE SALA
 * 
 * ========================================
*/
#include "project.h"
#include "InterruptRoutines_UART.h"
#include "InterruptRoutines_TIMER.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    
    UART_Start(); // All the components are let started
    PWM_RG_Start();
    PWM_B_Start();
    
    isr_UART_StartEx(Custom_UART_RX_ISR);
    isr_TIMER_StartEx(Custom_TIMER_RX_ISR);
    
    for(;;)
    {
        if (flag_end_transmission == 1){ //If the trasmission is right and is completed (all 4 bytes have been saved) a message of correct acquisition is displayed 
            SetColour(c); //The new colour is saved
            UART_PutString("All the four bytes have been aquired\n");
            Timer_Stop();
            count = 0;
            flag_end_transmission = 0;
        }
        else if (flag_5_sec == 1){ //If 5 seconds are passed from the last byte acquisition 
            UART_PutString("5 seconds have been passed\n");
            UART_Init(); //Initialization of the UART to erase all the register     
            Timer_Stop(); //The timer is stopped to not call any isr of the timer if the trasmission does not occur
            count = 0;
            flag_5_sec = 0;
        }
        else if (flag_v == 1){ //If the "v" character is write, the predefined string is passed
            UART_PutString("RGB LED Program $$$");
            UART_Init();
            Timer_Stop();
            count = 0;
            flag_v = 0;
        }
        else if (flag_error == 1){ //If an error in the trasmission (not correct header or tail) occur a message is displayed
            UART_PutString("ERROR in the transmission\n");
            UART_Init();
            Timer_Stop();
            count = 0;
            flag_error = 0;
        }
    }
}

/* [] END OF FILE */
