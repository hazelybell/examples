#include <stdio.h>

#define N 5

int main() {
    int an_int = 5;
    printf("an_int=%d\n", an_int);
    an_int = 2;
    printf("an_int=%d\n", an_int);
    // an_int is an "lvalue"
    // aka. left value
    // anything that can appear on the left of an assignment
    // we can also use ++ and -- with lvalues
    an_int += 20;
    // Exactly the same as:
    // an_int = an_int + 20;
    printf("an_int=%d\n", an_int);
    printf("an_int++=%d\n", an_int++);
    printf("an_int=%d\n", an_int);
    printf("++an_int=%d\n", ++an_int);
    printf("an_int=%d\n", an_int);
    an_int *= 10;
    // Exactly the same as:
    // an_int = an_int * 10;
    printf("an_int=%d\n", an_int);
    printf("an_int--=%d\n", an_int--);
    printf("an_int=%d\n", an_int);
    printf("--an_int=%d\n", --an_int);
    printf("an_int=%d\n", an_int);
    // None of the following work, because they are NOT lvalues!
    // 5 = 2;
    // 5 *= 10;
    // 5++;
    // N = 2;
    // N *= 10;
    // N++;
    return 0;
}
