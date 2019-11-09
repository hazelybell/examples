/* Items to review: 
 * size of various types
 */
/* Try compiling this program with -m32
 * (or without it) and see if the output
 * changes. (-m32 tells gcc to compile
 * for a 32-bit PC)
 */
#include <stdio.h>

int main(int argc, char ** argv) {
    printf("char: %zu\n", sizeof(char));
    printf("short: %zu\n", sizeof(short));
    printf("int: %zu\n", sizeof(int));
    printf("long: %zu\n", sizeof(long));
    printf("long long: %zu\n", sizeof(long long));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    printf("long double: %zu\n", sizeof(long double));
    return 0;
}

