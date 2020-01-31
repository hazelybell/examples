#include <stdio.h>

#define LENGTH 500

int main() {
    int sla[LENGTH];
    
    // an initialization for loop should go here

    for (size_t index = 0; index < LENGTH; index++) {
        printf("sla[%zu] = %d\n", index, sla[index]);
    }
    
    return 0;
}

