#include <stdio.h>

#define LENGTH 5

int main() {
    int  *var1 [LENGTH]; // what's this?
    int (*var2)[LENGTH]; // what's this?

    printf("sizeof(var1)=%zu\n", sizeof(var1));
    printf("sizeof(var2)=%zu\n", sizeof(var2));
    
    // array 1 is an array of 5 pointers to ints
    // array 2 is a pointer to an array of 5 ints
    
    // Let's say we have some arrays (of 5 ints)
    
    int array0[5] = {   0,   1,   2,   3,   4 };
    int array1[5] = { 100, 101, 102, 103, 104 };
    int array2[5] = { 200, 201, 202, 203, 204 };
    int array3[5] = { 300, 301, 302, 303, 304 };
    int array4[5] = { 400, 401, 402, 403, 404 };
    
    // Then we can get pointers to them and put them in an array of course...
    int *a_o_p[5] = {
        &array0[0],
        &array1[0],
        &array2[0],
        &array3[0],
        &array4[0]
    };
    
    printf("\n");
    // Now, accessing a_o_p looks just like accessing a 5x5 2-D array!
    for (size_t row = 0; row < LENGTH; row++) {
        for (size_t col = 0; col < LENGTH; col++) {
            printf("%03d ", a_o_p[row][col]);
        }
        printf("\n");
    }
    // but what's really happening?
    // a_o_p[row] gets us a pointer out of our array of pointers
    // [col] takes that pointer, and gets the (col)th int after it!
    // its the same as:
    printf("\n");
    for (size_t row = 0; row < LENGTH; row++) {
        for (size_t col = 0; col < LENGTH; col++) {
            int *row_start = a_o_p[row];
            printf("%03d ", *(row_start + col));
        }
        printf("\n");
    }
    
    printf("\n");
    // if we pass a 2-D array to a function we pass 1 pointer to 1 array!
    // if we pass an array of pointers to arrays to a function, we an extra pointer for every sub-array!
    // Note that they have very different types:
    // array of pointers is:    int *a_o_p[5]
    // when passed it's just    int **
    // 2-D array is:            int matrix[5][5]
    // when passed:             int (*)[5]
}



