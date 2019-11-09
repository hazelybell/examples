#include <stdio.h>

int main(int argc, char ** argv) {
    int a = 1;
    int b = 10;
    int c = a+++b; // same as (a++)+b
    printf("a=%d b=%d c=%d\n", a, b, c);
    return 0;
}
