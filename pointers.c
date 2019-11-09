#include <stdio.h>

int inc_by_value(int n) {
    n = n + 1;
    return n;
}

void inc_by_ptr(int *np) {
    *np = *np + 1;
}

int main(int argc, char ** argv) {
    int n = 0;
    // unary & operator
    int *p = &n;
    // P's type: pointer to an int
    // P's value: the location of an int in memory
    printf("n=%d, p=%p, p=%lu\n", n, p, (unsigned long) p);
    printf("&n=%p\n", &n);
    // unary * operator
    printf("*p=%d\n", *p);
    printf("---\n");
    inc_by_value(n);
    printf("n=%d\n", n);
    printf("---\n");
    inc_by_ptr(&n);
    printf("n=%d\n", n);
    return 0;
}


