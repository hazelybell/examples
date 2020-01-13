#include <stdio.h>

int main() {
    char * s = "Hi!";
    s[0] = 'X';
    return 0;
}

// This program crashes. Why?
// Can you modify the type of s so that it gives a 
// the relevant compiler error, instead?

