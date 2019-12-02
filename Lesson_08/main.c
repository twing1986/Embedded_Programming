/*******************************************************************************
Improve the program by using functions in C.
*******************************************************************************/
#include "tm4c123gh6pm.h"

#define LED_RED     (1U << 1)
#define LED_BLUE    (1U << 2)
#define LED_GREEN   (1U << 3)

void delay(int iter);           // Function declaration (prototype)

void delay(int iter) {          // Function definition
    int volatile counter = 0;   // Initialize counter 
    // Delay loop        
    while (counter < iter) {
        ++counter;
    } 
}

int main() {
    // Enable Clock for GPIO Port F
    SYSCTL_RCGCGPIO_R |= (1U << 5);                            // General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)
    // Enable AHB for GPIO Port F
    SYSCTL_GPIOHBCTL_R |= (1U << 5);                           // After this change all GPIO register to _AHB!
    // Set Port F pins 1, 2 and 3 as outputs
    GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);      // GPIO Direction (GPIODIR)
    // Enable digital function  of PF1, PF2 and PF3
    GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);      // GPIO Digital Enable (GPIODEN)
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;                             // Turn the blue LED on
    while (1) {
        // Switch the Red LED on
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
        
        delay(1000000);
   
        // Switch the Red LED off  
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        
        delay(500000);   
    }
  
    return 0;
}
