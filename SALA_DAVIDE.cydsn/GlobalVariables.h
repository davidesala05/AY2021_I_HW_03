/* ========================================
 *
 * Header file where all the global variables are declared 
 * 
 * ========================================
*/   

#include "cytypes.h"

extern uint8_t count; //To count the bytes transmitted
extern uint8_t header; //To save the HEADER
extern uint8_t tail; //To save the TAIL
extern uint8_t flag_end_transmission; //To save the new colour if no errors happen
extern uint8_t flag_v; //To put at output the string for the GUI
extern uint8_t flag_error; //To display an error message and initialize the UART
extern uint8_t flag_5_sec; //If 5 seconds are passed

/* [] END OF FILE */
