#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define COLS 3

int main() {
    printf("\n");
    
    /* 2d array: one malloc one free */
    
    int (*twod_array)[COLS] = NULL;
    twod_array = malloc(sizeof(*twod_array) * ROWS);
    printf("twod_array is %zu bytes at %p\n",
            sizeof(*twod_array) * ROWS,
            (void *) twod_array
    );
    
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            twod_array[row][col] = rand() % 10;
        }
    } 
    printf("\n");
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            printf("%p ", (void*) &twod_array[row][col]);
        }
        printf("\n");
    } 
    printf("\n");
    
    free(twod_array);
    
    /* array of arrays: 1+rows mallocs, 1+rows free */
    
    int **aoa = NULL;
    aoa = malloc(sizeof(*aoa) * ROWS);
    printf("aoa is %zu bytes at %p\n",
            sizeof(*aoa) * ROWS,
            (void *) aoa
    );
    for (size_t row = 0; row < ROWS; row++) {
        aoa[row] = malloc(sizeof(**aoa) * COLS);
        printf(
            "aoa[%zu] is %zu bytes at %p\n",
            row,
            sizeof(**aoa) * COLS,
            (void *) aoa[row]
        );
    }

    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            aoa[row][col] = rand() % 10;
        }
    } 
    printf("\n");
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            printf("%p ", (void*) &aoa[row][col]);
        }
        printf("\n");
    } 
    printf("\n");
    
    for (size_t row = 0; row < ROWS; row++) {
        free(aoa[row]);
    }
    free(aoa);
    
    return 0;
}

/* How to declare a function that takes one argument
 * (fill_value)
 * and returns pointer to a row of COLS ints
 */

int (*new_twod_array(int fill_value))[COLS] {
    int (*twod_array)[COLS] = NULL;
    /* allocate */
    twod_array = malloc(sizeof(*twod_array) * ROWS);
    /* set all the elements to fill_value */
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            twod_array[row][col] = fill_value;
        }
    } 
    return twod_array;
}
