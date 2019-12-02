#include "delay.h"

void delay(int iter) {          // Function definition
    int volatile counter = 0;   // Initialize counter 
          
    while (counter < iter) {    // Delay loop  
        ++counter;
    } 
}