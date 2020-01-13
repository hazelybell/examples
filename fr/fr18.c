#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char * s = "X is my favourite letter!";
    s[0] = 'A' + rand() % 26;
    printf("%s\n", s);
    return 0;
}

// This program is essentially the same as fr17.c...
// Can you fix it so that it changes the first letter
// of s to a random capital letter and then prints s 
// out?
// Can you do it without changing the printf, using
// any additional variables, or additional
// functions from the printf family?



