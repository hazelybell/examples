#include <stdio.h>
#include <stdlib.h>

int main() {
    int one = 1;
    int two = 2;
    int three = one = two;
    printf("one=%d\n", one);
    printf("two=%d\n", two);
    printf("three=%d\n", three);
    printf("(one++)=%d (one*=2)=%d\n", one++, one *= 2);
    return 0;
}
