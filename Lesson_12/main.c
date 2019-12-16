/*******************************************************************************
Improve the program by using functions in C.
An example of recursive function. Collaborate with stack overflow.
Make a blinking LED pattern more interesting by changing delays.
*******************************************************************************/
#include <stdint.h>     // C99 Standard

#include "tm4c_cmsis.h"
#include "delay.h"

#define LED_RED     (1U << 1)
#define LED_BLUE    (1U << 2)
#define LED_GREEN   (1U << 3)

/*
struct Point {
    uint16_t x;                         // Struct members
    uint8_t y;
};                                      // You can define here new variables immediately

// struct Point pa, pb;

typedef struct Point Point              // Different memory location for typedef and struct, so Point Point is allowed
*/

// typedef __packed struct {            // Allocates all members in memory without spaces - padding avoing
                                        // odd memory addresses may be less efficient than regular un-packed structures
typedef struct {                        // Typedef form without the struct tag
    uint16_t x;
    uint8_t y;
} Point;

Point p1, p2;                           // After typedef using, you don't have to use keyword struct anymore

typedef struct {
    Point top_left;
    Point bottom_right;
} Window;

typedef struct {
    Point corners[3];
} Triangle;

Window w, w2;
Triangle t;


int main() {
  
    Point *pp;
    Window *wp;
  
    p1.x = sizeof(Point);
    p1.y = 0xAAU;
    
    w.top_left.x = 1U;
    w.bottom_right.y = 2U;
    
    t.corners[0].x = 1U;
    t.corners[2].y = 2U;
    
    p2 = p1;
    w2 = w;
  
    pp = &p1;
    wp = &w2;
    
    (*pp).x = 1U;                       // (*pp) are necessary because the precedence of the '.' operator is very high
    (*wp).top_left = *pp;
    
    pp->x = 1U;                         // Equivalent to line above
    wp->top_left = *pp;
  
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
    
    
    //GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;               // Turn the blue LED on
    GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE;
    while (1) {
        // Switch the Red LED on
        //GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
        GPIOF_HS->DATA_Bits[LED_RED] = LED_RED;
  //      int volatile x = 1000000;                                  // Declaration of an argument for delay function
        delay(1000000);
   
        // Switch the Red LED off  
        //GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
        GPIOF_HS->DATA_Bits[LED_RED] = 0;
        
        delay(500000);   
    }
  
    // return 0;
}











