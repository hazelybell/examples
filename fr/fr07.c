#include <stdio.h>

int main() {
    const char * a = "I'm A!";
    const char * b = "I'm B!";
    const char * c = "I'm C!";
    const char * d = malloc(sizeof(char) * 7);
    d = c;

    // What does this print... and why?
    printf("%s\n", d);
    
    // The program crashes here... why?
    free(d);
}




