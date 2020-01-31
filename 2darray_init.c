#include <stdio.h>

#define ROWS 5
#define COLS 5

int main() {
    // 5x5 array
    int tda0[ROWS][COLS] = { { 0 } };
    
    for (size_t row = 0; row < ROWS; row++) {
        printf("row %zu: ", row);
        for (size_t col = 0; col < COLS; col++) {
            printf("%d ", tda0[row][col]);
        }
        printf("\n");
    }
    
    // tda[3][4] = get the 4th element from the 3rd row

    // 5x5 array
    int tda1[ROWS][COLS] = {
        { 0, 1, 2, 3, 4 },
        { 100, 101, 102, 103, 104 },
        { 200, 201, 202, 203, 204 },
        { 300, 301, 302, 303, 304 },
        { 400, 401, 402, 403, 404 },
    };
    
    for (size_t row = 0; row < ROWS; row++) {
        printf("row %zu: ", row);
        for (size_t col = 0; col < COLS; col++) {
            printf("%d ", tda1[row][col]);
        }
        printf("\n");
    }
}
