#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char * s = "thingA";
    const char * t = "thingB";
    printf("%d ", strcmp(s, s));
    printf("%d\n", strcmp(s, t));
    printf("%d ", strcmp(t, s));
    printf("%d\n", strcmp(t, t));
    return 0;
}

/* What does this program print out and why? */

