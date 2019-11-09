#include <stdio.h>

#define N 10

int main(int argc, char **argv) {
    int a[N];
    for (size_t i = 0; i < N; i++) {
        printf("a[%zu]=%d\n", i, a[i]);
    }
    return 0;
}

