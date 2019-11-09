/* Items to review: 
 * length of strings
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it!
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
    char a[] = "Hello World!";
    printf("strlen: %zu\n", strlen(a));
    printf("sizeof: %zu\n", sizeof(a));
    return 0;
}

