#include <stdio.h>

void f(const char c[7]) {
    printf("%zu\n", sizeof(c));
}

int main() {
    const char * a = "I'm A!";
    const char b[] = "I'm B!";
    printf("%zu %zu ", sizeof(a), sizeof(b));
    f(b);
}

// What does this print... and why?
// Try to answer without compiling and running it!
// If you're stuck, try compiling it to get a hint.

