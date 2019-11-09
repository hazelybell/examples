// READ man 3 malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char hello[] = "Enter an array size: ";
    size_t n;
    printf("%s", hello);
    scanf("%zu", &n);
    // int array[n]; // VLA gets put on the stack
    int *array; // array has type "ptr to an int"
    double d;
    int x;
    x = (int) d;
    array = (int *) // cast result of malloc to "ptr to an int"
        malloc(n * sizeof(int));
    for (size_t i; i < n; i++) {
        printf("%d ", array[i]);
        // same as printf("%d ", *(array + i));
    }
    free(array); // deallocates or "frees" the memory we were using for array
    for (size_t i; i < n; i++) {
        printf("%d ", array[i]);
    }
}
