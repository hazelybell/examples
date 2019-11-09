#include <stdio.h>
#include <string.h>

#define SIZE 4

int main(int argc, char ** argv) {
    int a[SIZE][SIZE]; // 2d array
    for (size_t i = 0; i < SIZE; i++) {
        printf("&a[%zu] = %p\n", i, &a[i]);
        printf("&a[%zu][0] = %p\n", i, &a[i][0]);
        for (size_t j = 0; j < SIZE; j++) {
            size_t o = i * SIZE + j;
            printf("%zu,%zu @ %p == %zu @ %p\n",
                i,
                j,
                &a[i][j],
                o,
                &a[0][0] + o
            );
        }
    }
}


