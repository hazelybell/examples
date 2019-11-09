/* Items to review: 
 * uninitialized variable
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it!
 */

#include <stdio.h>

#define N 10

int main(int argc, char ** argv) {
    int a;
    int b;
    int c;
    int d;
    printf("%d %d %d %d\n", a, b, c, d);
    int x[N];
    for (int i = 0; i < N; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
    return 0;
}


