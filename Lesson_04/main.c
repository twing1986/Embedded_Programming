/*******************************************************************************
Short program for blinking LED
*******************************************************************************/

int main() {
    // Enable Clock for GPIO Port F
    *(unsigned int *)0x400FE608U = 0x20U;        // General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)
    // Set Port F pins 1, 2 and 3 as outputs
    *(unsigned int *)0x40025400U = 0x0EU;        // GPIO Direction (GPIODIR)
    // Enable digital function  of PF1, PF2 and PF3
    *(unsigned int *)0x4002551CU = 0x0EU;        // GPIO Digital Enable (GPIODEN)
    
    while (1) {
        // Switch the Red LED on
        *(unsigned int *)0x400253FCU = 0x02U;        // GPIO Data (GPIODATA) register address: 0x40025000
                                                     // + bit mask [9:2] set for all: 11 1111 11 00 -> 0x3FC
        // Delay
        int counter = 0;
        while (counter < 1000000) {
            ++counter;
        }    
        // Switch the Red LED off
        *(unsigned int *)0x400253FCU = 0x00U;
        counter = 0;
        while (counter < 1000000) {
            ++counter;
        }    
    }
  
    return 0;
}
