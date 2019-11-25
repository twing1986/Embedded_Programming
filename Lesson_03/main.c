/*******************************************************************************
Short program for start playing with pointers
*******************************************************************************/

int counter = 0;   // declaring a variable

int main() {
//  int counter = 0;    // declaring a variable counter (signed integer) and initialize it to 0
    int *p_int;         // declaring a pointer (integer type)
    p_int = &counter;   // assign address of counter vaariable to pointer
    
    while (*p_int < 20) {       // 

        ++(*p_int);  // increment the counter
    }
    
    p_int = (int *)0x20000002U;
    *p_int = 0xDEADBEEF;
  
    return 0;
}
