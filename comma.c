#include <stdio.h>

/* The comma operator:
 * You should never use it in your own code!
 * It evaluates the expression on the left side of the comma, and discards the result.
 * Then it evaluates the expression on the right side. The value on the right side is the value of the expression.
 */

int main() {
    int an_int;
    int array[2] = { 100, 200 };
    an_int = (1, 2), 3;
    printf("%d\n", an_int);
    return 0;
}
