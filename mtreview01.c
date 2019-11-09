/* Items to review: 
 * functions
 * increment/decrement operator
 * organization of a program
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it! 
 */

#include <stdio.h>

int f(int x); // why is this here?

int main(int argc, char ** argv) {
    int i = 0;
    printf("%d %d\n", f(i), i);
    return 0;
}

int f(int x) {
    return x++;
}

