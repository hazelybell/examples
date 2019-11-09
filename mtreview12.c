/* Items to review: 
 * array initialization
 * bounds checking
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it!
 */

#include <stdio.h>

#define N 10

int main(int argc, char ** argv) {
    int x[N] = { };
    for (int i = 0; i < N; i++) {
        printf("%d ", x[i]);
    }
    printf("\n\n");
    for (int i = -1; i <= N; i++) {
        printf("%d ", x[i]);
    }
    return 0;
}



