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
#include "ColourDriver.h"

void SetColour (colour c ) {
    
    PWM_RG_WriteCompare1(c.red);
    PWM_RG_WriteCompare2(c.green);
    PWM_B_WriteCompare(c.blue);
    
}
/* [] END OF FILE */
