/*******************************************************************************
Add to the program the rest of LEDs by using bit-wise operations 
*******************************************************************************/
#include "tm4c123gh6pm.h"

#define LED_RED     (1U << 1)
#define LED_BLUE    (1U << 2)
#define LED_GREEN   (1U << 3)

/*#define RCGCGPIO (*((unsigned int *)0x400FE608U))

#define GPIOF_BASE 0x40025000U
#define GPIOF_DIR (*((unsigned int *)(GPIOF_BASE + 0x400U)))
#define GPIOF_DEN (*((unsigned int *)(GPIOF_BASE + 0x51CU)))
#define GPIOF_DATA (*((unsigned int *)(GPIOF_BASE + 0x3FCU)))*/

int main() {
/*  // Exercise bit-wise operations in C

    unsigned int a = 0x5A5A5A5A;
    unsigned int b = 0xDEADBEEF;
    unsigned int c;
    
    c = a | b;          // OR
    c = a & b;          // AND
    c = a ^ b;          // XOR
    c = ~b;             // NOT
    c = b >> 1;         // Right-shift
    c = b << 3;         // Left=shift
    
    int x = 1024;
    int y = -1024;
    int z;
    
    z = x >> 3;         // Right-shift a signed int
    z = y >> 3;         // Right-shift a negative signed int;
*/  
  
    // Enable Clock for GPIO Port F
    SYSCTL_RCGCGPIO_R |= (1U << 5);         // General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)
    // Set Port F pins 1, 2 and 3 as outputs
    GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);          // GPIO Direction (GPIODIR)
    // Enable digital function  of PF1, PF2 and PF3
    GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);          // GPIO Digital Enable (GPIODEN)
    
    GPIO_PORTF_DATA_R |= LED_BLUE;      // Turn the blue LED on
    while (1) {
        // Switch the Red LED on
        GPIO_PORTF_DATA_R  |=  LED_RED;      // Coding idiom for  setting a bit in C
        // Delay
        int volatile counter = 0;
        while (counter < 1000000) {
            ++counter;
        }    
        // Switch the Red LED off
        GPIO_PORTF_DATA_R  &=  ~LED_RED;    // Coding idiom for  clearing a bit in C    
        counter = 0;
        while (counter < 1000000) {
            ++counter;
        }    
    }
  
    return 0;
}
