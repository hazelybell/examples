#include <stdio.h>
#include <sys/types.h> // ssize_t

#define LENGTH 5
#define UNTIL -100000

int main() {
    int sla[LENGTH] = { 0 };
    
    for (ssize_t index = 0; index > UNTIL; index--) {
        printf("sla[%zd] = %d\n", index, sla[index]);
    }
    
    return 0;
}

// What is "Segmentation fault"?
