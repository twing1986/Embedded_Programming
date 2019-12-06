/*******************************************************************************
Improve the program by using functions in C.
An example of recursive function. Collaborate with stack overflow.
Make a blinking LED pattern more interesting by changing delays.
*******************************************************************************/
#include <stdint.h>     // C99 Standard

#include "tm4c123gh6pm.h"
#include "delay.h"

#define LED_RED     (1U << 1)
#define LED_BLUE    (1U << 2)
#define LED_GREEN   (1U << 3)

/*
int x;
unsigned y;
short s;
unsigned short t;
long u;
unsigned long v;
char c;
unsigned char uc;
*/

uint8_t u8a, u8b;
uint16_t u16c, u16d;
uint32_t u32e, u32f;

int8_t s8;
int16_t s16;
int32_t s32;


int main() {
    
    u8a = sizeof(u8a);
    u16c = sizeof(uint16_t);
    u32e = sizeof(uint32_t);
    
    u8a = 0xA1U;
    u16c = 0xC1C2U;
    u32e = 0xE1E2E3E4U;
    
    u8b = u8a;
    u16d = u16c;
    u32f = u32e;
    
    u16c = 40000U;
    u16d = 30000U;
    u32e = u16c + u16d;                 // Automatic promotion to 32-bit for ARM processors. Code is not portable!
    // u32e = (uint32_t)u16c + u16d;    // Force the promotion for processors where int is 16-bit
  
    u16c = 100U;
    s32 = 10 - u16c;                    // Mixing signed and unsigned variables promotes both of them to unsigned!
    // s32 = 10 - (int16_t)u16c;        // Casting the unsigned variable to a signed type.
    
    //if (u32e > -1) {                  // Compiler warning: the result is always false (-1 promoted to unsigned type is 0xFFFFFFFF).
    if ((int16_t)u32e > -1) {           // Fixed.
        u8a = 1U;
    } else {
        u8a = 0U;
    }
    
    u8a = 0xFFU;
    // if (~u8a == 0x00U) {                // Comparison will always be false because byte u8a will be promoted to int.
    if ((uint8_t)(~u8a) == 0x00U) {  // Fixed.
        u8b = 1U;
    }
    
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
        // Switch the Red LED on
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
  //      int volatile x = 1000000;                                  // Declaration of an argument for delay function
        delay(1000000);
   
        // Switch the Red LED off  
        GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        
        delay(500000);   
    }
  
    // return 0;
}











