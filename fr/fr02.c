#include <stdio.h>

int main() {
    int a = 0;
    int b = a++;
    int c = ++a;
    printf("%d %d %d\n", a, b, c);
    return 0;
}

// What does this program print... and why?

