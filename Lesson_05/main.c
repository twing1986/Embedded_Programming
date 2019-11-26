/*******************************************************************************
Improving the program for blinking LED by adding macros and MCU header file
*******************************************************************************/
#include "tm4c123gh6pm.h"

/*#define RCGCGPIO (*((unsigned int *)0x400FE608U))

#define GPIOF_BASE 0x40025000U
#define GPIOF_DIR (*((unsigned int *)(GPIOF_BASE + 0x400U)))
#define GPIOF_DEN (*((unsigned int *)(GPIOF_BASE + 0x51CU)))
#define GPIOF_DATA (*((unsigned int *)(GPIOF_BASE + 0x3FCU)))*/

int main() {
    // Enable Clock for GPIO Port F
    SYSCTL_RCGCGPIO_R = 0x20U;                            // General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)
    // Set Port F pins 1, 2 and 3 as outputs
    GPIO_PORTF_DIR_R = 0x0EU;        // GPIO Direction (GPIODIR)
    // Enable digital function  of PF1, PF2 and PF3
    GPIO_PORTF_DEN_R = 0x0EU;        // GPIO Digital Enable (GPIODEN)
    
    while (1) {
        // Switch the Red LED on
        GPIO_PORTF_DATA_R  = 0x02U;        // GPIO Data (GPIODATA) register address: 0x40025000
                                                     // + bit mask [9:2] set for all: 11 1111 11 00 -> 0x3FC
        // Delay
        int volatile counter = 0;
        while (counter < 1000000) {
            ++counter;
        }    
        // Switch the Red LED off
        GPIO_PORTF_DATA_R  = 0x00U;
        counter = 0;
        while (counter < 1000000) {
            ++counter;
        }    
    }
  
    return 0;
}
