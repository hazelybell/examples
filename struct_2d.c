#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct twod_array {
    size_t rows;
    size_t cols;
    int * elts;
} TwoDAarry;

void bounds_check(TwoDAarry array, size_t row, size_t col) {
    if (row >= array.rows || col >= array.cols) {
        abort();
    }
}

int get_element(TwoDAarry array, size_t row, size_t col) {
    bounds_check(array, row, col);
    return array->elts[row * array.cols + col];
}

void set_element(TwoDAarry array, size_t row, size_t col, int value) {
    bounds_check(array, row, col);
    array->elts[row * array.cols + col] = value;
}


int main() {
    printf("\n");
    return 0;
}
