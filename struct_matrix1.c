#include <stdio.h>
#include <stdlib.h>

/* One really important use of structs is to group
 * related data together. For example, an array
 * and its size is an extremely good use of a struct!
 * 
 * You should use this often.
 * 
 * Imagine you're working with a matrix.
 * You need to know how big it is.
 */

struct matrix {
    int *elements;
    size_t rows;
    size_t cols;
};

typedef struct matrix Matrix;

/* If we always use this get_element function
 * to get elements out of our matrix,
 * we will never go out of bounds.
 * Of course weneed a set_element function too.
 * 
 * We can add our own bounds-checking to C!
 */

int get_element(Matrix matrix, size_t row, size_t col) {
    if (row >= matrix.rows) {
        printf("Error: row index out of bounds!\n");
        abort();
    }
    if (col >= matrix.cols) {
        printf("Error: col index out of bounds!\n");
        abort();
    }
    return matrix.elements[row * matrix.cols + col];
}

void set_element(
    Matrix matrix,
    size_t row,
    size_t col,
    int value
) {
    if (row >= matrix.rows) {
        printf("Error: row index out of bounds!\n");
        abort();
    }
    if (col >= matrix.cols) {
        printf("Error: col index out of bounds!\n");
        abort();
    }
    matrix.elements[row * matrix.cols + col] = value;
}

void init_matrix(Matrix matrix) {
    for (size_t row = 0; row < matrix.rows; row++) {
        for (size_t col = 0; col < matrix.cols; col++) {
            set_element(matrix, row, col, 0);
        }
    }
}

void print_matrix(Matrix matrix) {
    for (size_t row = 0; row < matrix.rows; row++) {
        for (size_t col = 0; col < matrix.cols; col++) {
            int elt = get_element(matrix, row, col);
            printf("%d ", elt);
        }
        printf("\n");
    }
}

int main() {
    size_t rows = 3;
    size_t cols = 3;
    // we will use our init_matrix function to initialize insead of an initializer. That way we don't have know the size of matrix_memory at compile time.
    int matrix_memory[rows * cols];
    Matrix matrix = { matrix_memory, rows, cols };
    init_matrix(matrix);
    print_matrix(matrix);
    printf("\n");
    set_element(matrix, 1, 1, 2);
    print_matrix(matrix);
}
