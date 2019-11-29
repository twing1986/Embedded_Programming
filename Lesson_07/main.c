/*******************************************************************************
Change the blinking LED program by using dedicated registers for GPIO pins and
pointer arithmetic. Then change APB bus for AHB (faster).
*******************************************************************************/
#include "tm4c123gh6pm.h"

#define LED_RED     (1U << 1)
#define LED_BLUE    (1U << 2)
#define LED_GREEN   (1U << 3)


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
        // GPIO_PORTF_DATA_R  |=  LED_RED;                      // Coding idiom for setting a bit in C
        // *((unsigned int volatile *)(0x40025000 + (LED_RED << 2))) = LED_RED;         // Using an individual register for PF1
        // *(GPIO_PORTF_DATA_BITS_R + LED_RED) = LED_RED;       // Using an individual register for PF1 with pointer arithmetic
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
        
        // Delay loop
        int volatile counter[2] = {0, 0};   // Initialize an array of counters 
        while (counter[0] < 1000000) {
            ++counter[0];
        }    
        // Switch the Red LED off
        // GPIO_PORTF_DATA_R  &=  ~LED_RED;    // Coding idiom for  clearing a bit in C    
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        
        // counter = 0;
        while (*(counter + 1) < 1000000) {      // An exapmle of pointer arithmetic
            ++counter[1];
        }    
    }
  
    return 0;
}
