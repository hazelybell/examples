/* Items to review: 
 * adjacency matrix
 * edges
 * adjacent edges
 * scanf
 * printf formatting
 * static local variables
 */
/* This program takes a matching as input,
 * checks to make sure it's valid,
 * and prints out an adjacency matrix.
 * Try to understand how this program
 * accomplishes this.
 */

#include <stdio.h>

#define N 1000

int maxv(int v) {
    static int max = -1; // what does this do? Why -1? What is 'static' here?
    if (v > max) {
        max = v;
    }
    return max;
}

int main(int argc, char ** argv) {
    int am[N][N] = {}; // What do the '{}' do?
    printf("Enter a matching of the form 0,1 2,3 4,5 ... where 1 and 2 are vertices: ");
    int a, b;
    while (scanf("%d,%d", &a, &b) == 2) {
        if (maxv(a), maxv(b) > N) { // What does this do?
            printf("Graph is too big... I can only hold vertices 0 through %d\n", N);
            return 2;
        }
        if (a == b) {
            printf("Not a matching: %d,%d is adjacent to itself\n",
                a, b
            );
            return 1;
        }
        for (int i = 0; i < maxv(-1); i++) {
            if (am[a][i]) {
                printf("Not a matching: %d,%d is adjacent to %d,%d\n",
                    a, i, a, b 
                );
                return 1;
            }
            if (am[i][b]) {
                printf("Not a matching: %d,%d is adjacent to %d,%d\n",
                    i, b, a, b 
                );
                return 1;
            }
        }
        am[a][b] = 1;
        am[b][a] = 1; // Why [a][b] and [b][a] ?
    }
    for (int i = 0; i <= maxv(-1); i++) { // Why <=?
        for (int j = 0; j <= maxv(-1); j++) {
            printf("%2d", am[i][j]);
        }
        printf("\n");
    }
    return 0;
}

