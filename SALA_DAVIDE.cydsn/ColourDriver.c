/* ========================================
 *
 * Here there is the fuction used in the InterruptRoutines.c file to change the colour of the RGB led
 * 
 * ========================================
*/
#include "ColourDriver.h"

colour c = {0,0,0}; //The Colour variable is inizialied to {0,0,0} to set all the LEDs OFF

void SetColour (colour c ) {
    
    PWM_RG_WriteCompare1(c.red); //Both the duty cycles of the first PWM (RED and GREEN) are changed
    PWM_RG_WriteCompare2(c.green);
    PWM_B_WriteCompare(c.blue); //The second PWM (BLUE) is changed
    
}
/* [] END OF FILE */
