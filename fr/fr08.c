#include <stdio.h>
#include <stdlib.h>

int main() {
    const char * c = "I'm C!";
    const char * d = malloc(sizeof(char) * 7);
    d = c;

    // What does this print... and why?
    printf("%s\n", d);

    // Valgrind reports a leak in this program. Why?
    // What line of code can I put here, where this comment is, to fix the leak?
}
