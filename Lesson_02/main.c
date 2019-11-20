/**** **************************************************************************
First simply program for veryfing if configuration of tool is correct.
Used to start with compiler & debugger (disassembly, memory, register, locals).
***************************************************************************** */

int main() {
//  int counter = 0;   // declaring a variable counter (signed integer) and initialize it to 0
    unsigned int counter = 0;   // declaring a variable
    
    while (counter < 20) {
        ++counter;  // increment the counter
        if ((counter & 1) != 0) {
            /* do something when the counter is odd */
        } else {
            /* do something when the counter is odd */
        }
    }
  
    return 0;
}
