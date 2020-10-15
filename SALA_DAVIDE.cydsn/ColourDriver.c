/* ========================================
 *
 * Here there is the fuction udes in theInterruprRoutines.c file to change the colour of the RGB led
 * 
 * ========================================
*/
#include "ColourDriver.h"

void SetColour (colour c ) {
    
    PWM_RG_WriteCompare1(c.red); //Both the duty cycles of the first PWM (RED and GREEN) are changed
    PWM_RG_WriteCompare2(c.green);
    PWM_B_WriteCompare(c.blue); //The second PWM (BLUE) is changed
    
}
/* [] END OF FILE */
