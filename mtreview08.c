/* Items to review: 
 * comma operator
 * initialization
 * increment operator
 * order of operations
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it!
 */

#include <stdio.h>

int main(int argc, char ** argv) {
    int a[4] = { 100, 200 }; // What are the initial values of a?
    a[3] = (a[1]++, a[2]++); // What happens here?
    // What happens if the parentheses are removed?
    printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
    return 0;
}

