#include <stdio.h>

int f(int x) {
    return x -= 1;
}

int main() {
    int a = 0;
    int b = a += 1;
    int c = f(a = 10);
    printf("%d %d %d\n", a, b, c);
    return 0;
}

// What does this program print... and why?

