/* Items to review: 
 * 2d array
 * for loop
 * #define
 * printf formats
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it! 
 */

#include <stdio.h>

#define N 4 // what is this?

int main(int argc, char ** argv) {
    int a[N][N]; // How are the contents of a layed out in memory?
    // what kind of array is a?
    printf("a:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = i * N + j;
            printf("%-3d ", a[i][j]); // what does -3 do here?
        }
        printf("\n");
    }
    int *p = (int *) a;
    for (int i = 0; i < N*N; i++) {
        printf("p[%d]=a[%d][%d]=%d\n", i, p[i] / N, p[i] % N, p[i]);
    }
}

