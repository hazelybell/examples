#include <stdio.h>
#include <stdlib.h>

// This example compares using malloc to get space for a 2-D array vs using malloc to make space for a array of arrays.

int * alloc2d(size_t n) {
    // we can just do 1 malloc()
    return (int *) malloc(n * n * sizeof(int));
}

int ** alloc_aoa(size_t n) {
    // we have to do 1 + n malloc()s
    int ** p = malloc(n * sizeof(int *));
    for (size_t i = 0; i < n; i++) {
        p[i] = malloc(n * sizeof(int));
    }
    return p;
}

void free2d(int * p) {
    // we can just do 1 free()
    free(p);
}

void free_aoa(size_t n, int ** p) {
    // we have to do n + 1 free()s
    for (size_t i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
}

int get2d(size_t n, int * p, size_t i, size_t j) {
    return p[i * n + j];
}

int get_aoa(int **p, size_t i, size_t j) {
    return p[i][j];
}

int set2d(size_t n, int * p, size_t i, size_t j, int v) {
    return p[i * n + j] = v;
}

int set_aoa(int **p, size_t i, size_t j, int v) {
    return p[i][j] = v;
}

int main(int argc, char **argv) {
    printf("I'm going to make space for a big, square table in memory.\n");
    printf("How many rows and columns would you like to make space for? ");
    size_t n;
    int r = scanf("%zu", &n);
    if (r != 1) {
        printf("Sorry, I couldn't understand that :(\n");
    }
    // allocate them
    int *p2d = alloc2d(n);
    int **aoa = alloc_aoa(n);
    // initialize them
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            set2d(n, p2d, i, j, rand());
            set_aoa(aoa, i, j, rand());
        }
    }
    // print them out
    printf("2d:\n");
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            int x = get2d(n, p2d, i, j);
            printf("%d ", x);
        }
        printf("\b\n");
    }
    printf("aoa:\n");
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            int x = get_aoa(aoa, i, j);
            printf("%d ", x);
        }
        printf("\b\n");
    }
    // free them
    free2d(p2d);
    free_aoa(n, aoa);
}
