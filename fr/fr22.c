#include <stdio.h>

#define N 5

int *add_to_pointer(int a, int b) {
    int sum = a + b;
    return &sum;
}

int main() {
    int i = 5;
    int j = 10;
    int * p = add_to_pointer(i, j);
    printf("%d + %d = %d", i, j, *p);
    return 0;
}

/*
This program crashes with a segmentation fault.
Can you figure out why without compiling it?
If you're stuck, try compiling it, and see if the 
compiler gives you a hint.
*/

