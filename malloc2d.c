// READ man 3 malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Option 3:
// In functions... just a 2-D array as normal...
// ...we could use either int a[n][n] OR
// int a[][n], but NOT a[][]!
void print_2d(size_t n, int a[][n]) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    size_t n = 10;
    int * array = (int *) // cast result of malloc to "ptr to an int"
        malloc(n * n * sizeof(int));
    int (*array2d)[n] = (int (*)[n]) array;
    int k = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            // Option 1:
            // Use a 1-D array and arithmetic
            array[i * n + j] = k++;
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            // Option 2:
            // Use 2-D array
            printf("%2d ", array2d[i][j]);
        }
        printf("\n");
    }
    print_2d(n, (int(*)[n]) array);
    free(array); // deallocates or "frees" the memory we were using for array
    // Now ALL pointers to or into the array are invalid!
}
