#include <stdio.h>
#include <stdlib.h>

#define N 5

char * a(char * s) {
    printf("In a(\"%s\")...", s);
    if (strlen(s) < N) {
        printf("going down...\n");
        s -= 1;
        s[0] = 'a';
        return a(s);
    } else {
        printf("Base case!\n");
        return s;
    }
}

int main() {
    char * s = malloc(sizeof(char) * (N+1));
    s[N] = '\0';
    a(s+N);
    printf("s=\"%s\"\n", s);
}

// What does this program print... and why?

