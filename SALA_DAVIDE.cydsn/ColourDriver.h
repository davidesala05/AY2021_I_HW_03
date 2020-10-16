/* ========================================
 *
 * Header file where the structure of the colour and the function to change it are defined
 * 
 * ========================================
*/

#ifndef __COLOUR_DRIVER_
    #define __COLOUR_DRIVER_
    
    #include "cytypes.h"
    #include "project.h"
    
    typedef struct {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    }colour; //the colour is defined as a struct of three elements wich are the three duty cycles
    
    void SetColour(colour c); //function to set the duty cycles of the PWMs
    
    
    
#endif
/* [] END OF FILE */
