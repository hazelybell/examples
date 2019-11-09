// READ man 3 malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    size_t n = 10;
    // Allocate space for the array of pointers...
    int ** aoa = (int **) 
        malloc(n * sizeof(int *));
    for (size_t i = 0; i < n; i++) {
        // Allocate space for each row...
        aoa[i] = (int *)
            malloc(n * sizeof(int));
    }
    int k = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            aoa[i][j] = k++;
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            printf("%2d ", aoa[i][j]);
        }
        printf("\n");
    }
    
    // We need one free() for every malloc() !!!
    for (size_t i = 0; i < n; i++) {
        // Free space for each row...
        free(aoa[i]);
    }
    free(aoa); // deallocates or "frees" the memory we were using for array
    // Now ALL pointers to or into the array are invalid!
}
