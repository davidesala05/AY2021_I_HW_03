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
extern uint8_t state; //To switch between the states of the main

#define IDLE 0 //The program is ready for a new transmission
#define END 1 //All the transmission goes well, te new colour can be set
#define ERROR 2 //The HEADER or the TAIL are wrong
#define V 3 //The character "v" is written in input
#define LATE 4 //5 seconds are passed after the previous byte

/* [] END OF FILE */
