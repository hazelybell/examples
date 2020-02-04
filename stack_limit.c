#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

int main() {
    uint8_t board[SIZE][SIZE];
    for (size_t row = 0; row < SIZE; row++) {
        for (size_t col = 0; col < SIZE; col++) {
            board[row][col] = rand() % 26 + 'A';
        }
    }
    
    for (size_t row = 0; row < SIZE; row++) {
        for (size_t col = 0; col < SIZE; col++) {
            printf("%c", (char) board[row][col]);
        }
        printf("\n");
    }
    
    printf("board is %zu mebibytes!\n", sizeof(board)/(1024*1024));
}
