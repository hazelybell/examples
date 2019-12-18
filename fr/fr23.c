#include <stdio.h>

#define N 5

int *add_to_pointer(int a, int b) {
    static int sum;
    sum = a + b;
    return &sum;
}

int main() {
    int i = 5;
    int j = 10;
    int * p = add_to_pointer(i, j);
    int k = 3;
    int l = 4;
    int * q = add_to_pointer(k, l);
    printf("%d + %d = %d\n", i, j, *p);
    printf("%d + %d = %d\n", k, l, *q);
    return 0;
}

/*  This program is similar to f22.c except line 6 has 
    been changed.
    It doesn't crash anymore... but now its sums are 
    wrong! Can you figure out why?
*/


