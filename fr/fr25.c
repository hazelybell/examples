#include <stdio.h>

int square(int x) {
    return x * x;
}

int main() {
    printf("location of the square function: %p\n", (void*) &square);
    return 0;
}

/* This program compiles and works fine... it does 
 * what it's supposed to, print out the location of 
 * the square function in memory.
 * Well, if you compile it with gcc -std=c99 -Wall it
 * compiles fine.
 * GCC has an additional option, -pedantic, which 
 * makes it more strict about complying to the 
 * standard you selected. (In this case, c99.)
 * What warning do you get if you compile it with
 * gcc -std=c99 -pedantic -Wall ?
 * 
 * Why is that rule in the C99 standard?
 */
