/* Items to review: 
 * logical operators
 * scanf
 * exit
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it!
 * Try these inputs:
 * 0 1
 * 1 0
 * 0 0
 * 1 1
 * 1.1
 */

#include <stdio.h>
#include <stdlib.h> // why is this here?

int ptf(int boolean) { // why do we use type 'int' here?
    if (boolean) {
        printf("true ");
    } else {
        printf("false ");
    }
    return boolean;
}

int main(int argc, char ** argv) {
    int a;
    int b;
    printf("Enter two ints: ");
    int scanned = scanf("%d%d", &a, &b);
    if (scanned < 2) {
        exit(1);
    }
    ptf(ptf(a) || ptf(b));
    printf("\n");
    ptf(ptf(a) && ptf(b));
    printf("\n");
    ptf(!ptf(a));
    printf("\n");
    return 0;
}



