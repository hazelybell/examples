/* Items to review: 
 * 2d array
 * for loop
 * #define
 * static-length array
 */

#include <stdio.h>

#define N 4

int main(int argc, char ** argv) {
    int a[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = i * N + j;
        }
    }
    int *p = a;
    for (int i = 0; i < N*N; i++) {
        printf("p[%d]=%d\n", i, p[i]);
    }
}

