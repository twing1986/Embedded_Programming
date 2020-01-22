/*******************************************************************************
Improve the program by using functions in C.
An example of recursive function. Collaborate with stack overflow.
Make a blinking LED pattern more interesting by changing delays.
*******************************************************************************/
#include <stdint.h>     // C99 Standard

#include "tm4c_cmsis.h"
#include "bsp.h"


int main() {

    // Enable Clock for GPIO Port F
    //SYSCTL_RCGCGPIO_R |= (1U << 5);                                // General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)
    SYSCTL->RCGC2 |= (1U << 5);
    
    // Enable AHB for GPIO Port F
    //SYSCTL_GPIOHBCTL_R |= (1U << 5);                               // After this change all GPIO register to _AHB!
    SYSCTL->GPIOHSCTL |= (1U << 5);
    
    // Set Port F pins 1, 2 and 3 as outputs
    //GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);      // GPIO Direction (GPIODIR)
    GPIOF_HS->DIR |= (LED_RED | LED_BLUE | LED_GREEN);
    
    // Enable digital function  of PF1, PF2 and PF3
    //GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);      // GPIO Digital Enable (GPIODEN)
    GPIOF_HS->DEN |= (LED_RED | LED_BLUE | LED_GREEN); 
    
    // Configure SysTick
    SysTick->LOAD = SYS_CLOCK_HZ/4U - 1U;                            // Period: 0.5s
    SysTick->VAL = 0U;
    SysTick->CTRL = (1U << 2) | (1U << 1) | 1U;
    
    //__enable_interrupt();                                            // Clears the PRIMASK bit
    __NVIC_EnableIRQ(SysTick_IRQn);
    
    //GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;               // Turn the blue LED on
    //GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE;
    while (1) {
        /*
        // Toggle the Red LED
        GPIOF_HS->DATA_Bits[LED_RED] ^= LED_RED;                     // Toggle the output by XOR operation
        delay(500000); 
        */
    }
  
    // return 0;
}











