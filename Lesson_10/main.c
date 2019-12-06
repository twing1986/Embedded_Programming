/*******************************************************************************
Improve the program by using functions in C.
An example of recursive function. Collaborate with stack overflow.
Make a blinking LED pattern more interesting by changing delays.
*******************************************************************************/
#include "tm4c123gh6pm.h"
#include "delay.h"

#define LED_RED     (1U << 1)
#define LED_BLUE    (1U << 2)
#define LED_GREEN   (1U << 3)

/*
unsigned fact(unsigned n);                              // Prototype of fact function
*/

/*
void swap(int *x, int *y);
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
*/

int *swap(int *x, int *y);
int *swap(int *x, int *y) {
    static int tmp[2];                  // Alocate a local variable out of the stack
    tmp[0] = *x;
    tmp[1] = *y;
    *x = tmp[1];
    *y = tmp[0];
    return tmp;
}


int main() {
    
    /*
    x = fact(0U);
    x = 2U + 3U*fact(1U);
    (void)fact(7U);
 
    int x = 1;
    int y = 2;
    swap(&x, &y);
    */
  
  
    // Enable Clock for GPIO Port F
    SYSCTL_RCGCGPIO_R |= (1U << 5);                                // General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)
    // Enable AHB for GPIO Port F
    SYSCTL_GPIOHBCTL_R |= (1U << 5);                               // After this change all GPIO register to _AHB!
    // Set Port F pins 1, 2 and 3 as outputs
    GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);      // GPIO Direction (GPIODIR)
    // Enable digital function  of PF1, PF2 and PF3
    GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);      // GPIO Digital Enable (GPIODEN)
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;               // Turn the blue LED on
    while (1) {
        int x = 1000000;
        int y = 1000000/2;
        int *p = swap(&x, &y);
        
        // Switch the Red LED on
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
  //      int volatile x = 1000000;                                  // Declaration of an argument for delay function
        delay(p[0]);
   
        // Switch the Red LED off  
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        
        delay(p[1]);   
    }
  
    // return 0;
}
/*
unsigned fact(unsigned n) {
    // 0! = 1
    // n! = n * (n - 1)!    for n > 0
    unsigned foo[6];
    foo[n] = n;
    
    if (n == 0U) {
        return 1U;
    } else {
        return (foo[n] * fact(n - 1U));
    }
}
*/
















