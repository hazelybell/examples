#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(int argc, char **argv) {
    int *a = (int *) malloc(
        N * sizeof(int)
                     );
    for (size_t i = 0; i < N; i++) {
        a[i] = 0;
    }
    for (size_t i = 0; i < N; i++) {
        printf("a[%zu]=%d\n", i, a[i]);
    }
    return 0;
}

