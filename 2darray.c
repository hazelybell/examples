#include <stdio.h>
#include <sys/types.h> // ssize_t
#include <stdbool.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int main() {
    // 5x5 array
    int tda[ROWS][COLS] = { { 0 } };
    
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS;
        col++) {
            tda[row][col] = row*100+col;
        }
    }

    for (size_t row = 0; row < ROWS; row++) {
        printf("row %zu: ", row);
        for (size_t col = 0; col < COLS; col++) {
            printf("%03d ", tda[row][col]);
        }
        printf("\n");
    }
    
    tda[2][2] = 666;
    
    for (size_t row = 0; row < ROWS; row++) {
        printf("row %zu: ", row);
        for (size_t col = 0; col < COLS; col++) {
            printf("%03d ", tda[row][col]);
        }
        printf("\n");
    }

    // What is row-major ordering?
    
    while (true) {
        size_t row = 0;
        printf("Row? ");
        int scanned = scanf("%zu", &row);
        if (scanned != 1) {
            printf("Error: didn't read row.");
            exit(1);
        }
        
        size_t col = 0;
        printf("Column? ");
        scanned = scanf("%zu", &col);
        if (scanned != 1) {
            printf("Error: didn't read col.");
            exit(1);
        }
        // How is the array stored in the computer's memory?
        printf("tda[%zu][%zu] = %03d\n", row, col, tda[row][col]);
    }
}
