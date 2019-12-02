/*******************************************************************************
Improve the program by using functions in C.
An example of recursive function.
*******************************************************************************/
#include "tm4c123gh6pm.h"
#include "delay.h"

#define LED_RED     (1U << 1)
#define LED_BLUE    (1U << 2)
#define LED_GREEN   (1U << 3)

unsigned fact(unsigned n);

int main() {
    unsigned volatile x;
    
    x = fact(0U);               // Assigning the return value to variable
    x = 2U + 3U*fact(1U);       // Example of calling function inside an expression
    (void)fact(5U);             // Recommended casting to void when don't care about the return value
    
  
  
  
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

unsigned fact(unsigned n) {
    // 0! = 1
    // n! = n * (n - 1)!    for n > 0
    if (n == 0U) {
        return 1U;
    } else {
        return (n * fact(n - 1U));
    }
}
