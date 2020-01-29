#include <stdio.h>

#define LENGTH 5
#define UNTIL 10000

int main() {
    // this is a properly initialized static-length array
    int sla[LENGTH] = { 0 };
    
    for (size_t index = 0; index < UNTIL; index++) {
        printf("sla[%zu] = %d\n", index, sla[index]);
    }
    
    return 0;
}

// What is "Segmentation fault"?
// Your program is trying to access memory:
// * that it doesn't have
// * that it's not allowed to access
// You program is trying to change memory
// * that is read-only

