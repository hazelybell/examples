#include <stdio.h>
#include <stdlib.h>

void f(char a[14]) {
    printf("%p\n", a);
    a++;
    printf("%p\n", a);
}

int main(int argc, char **argv) {
    // can be read like a pointer, but not changed like a pointer
    char a[14] = "Hello, world!";
    printf("%p\n", a);
    /* Can't do this:
     * a++
     * because a is an array, not a pointer and we're in the same function */
    f(a);
}
