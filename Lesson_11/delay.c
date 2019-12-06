#include "delay.h"

void delay(int volatile iter) {          // Function definition     
    while (iter > 0) {    // Delay loop  
        --iter;
    } 
}