#include <stdio.h>
#include <stdlib.h>

#define N 5

int main() {
    int c = 0;
    int ** m;
    m = malloc(sizeof(int) * N);
    for (size_t i = 0; i < N; i++) {
        m[i] = malloc(sizeof(int) * N);
        for (size_t j = 0; j < N; j++) {
            m[i][j] = c++;
        }
    }
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        free(m[i]);
        printf("\n");
    }
    free(m);
    return 0;
}

// What TYPE does malloc return?
/* This program should print out:
0 1 2 3 4 
5 6 7 8 9 
10 11 12 13 14 
15 16 17 18 19 
20 21 22 23 24 

But instead, it crashes. Why?
I've made a mistake somewhere... can you figure it 
out and fix it?
Scroll down for a hint.






































































































Hint: the mistake is on line 9!
*/

