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
#include "project.h"
#include "InterruptRoutines.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    Timer_Start();
    PWM_RG_Start();
    PWM_B_Start();
    
    isr_UART_StartEx(Custom_UART_RX_ISR);
    
    for(;;)
    {
        /* Place your application code here. */
        if (flag_reset_timer == 1){
            Timer_WriteCounter(500);
            flag_reset_timer = 0;
        }
        if ((Timer_ReadCounter() == 0) && (count != 0)){
            UART_PutString("5 seconds have been passed\n");
            count = 0;
            UART_Init();
        }
        if (flag_end_transmission == 1){
            UART_PutString("All the four bytes have been aquired\n");
            count = 0;
            flag_end_transmission = 0;
        }
        if (flag_v == 1){
            UART_PutString("RGB LED Program $$$\n");
            flag_v = 0;
            count = 0;
        }
        if (flag_error == 1){
            UART_PutString("ERROR in the transmission\n");
            count = 0;
            UART_Init();
            flag_error = 0;
        }
    }
}

/* [] END OF FILE */
