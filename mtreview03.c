/* Items to review: 
 * goto
 * label
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it! 
 */

#include <stdio.h>

int main(int argc, char ** argv) {
    int i = 0;
    bark: printf("woof %d\n", i++);
    if (i < 10) goto bark;
}

