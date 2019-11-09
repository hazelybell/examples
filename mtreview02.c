/* Items to review: 
 * if
 * while
 * booleans
 * %
 * \n
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it! 
 */

#include <stdio.h>

int main(int argc, char ** argv) {
    int i = 0;
    while (i < 10) { // When does this loop stop?
        if (i++ % 2) // Why is there no { ?
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

