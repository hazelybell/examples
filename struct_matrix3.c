#include <stdio.h>
#include <stdlib.h>

/* But we don't just want to avoid duplicate function
 * parameters, we want to avoid duplicate code too!
 * Noticing that our bounds checking code appears
 * twice, let's refactor...
 */

struct matrix {
    int *elements;
    size_t rows;
    size_t cols;
};

typedef struct matrix Matrix;

struct matrix_element {
    Matrix matrix;
    size_t row;
    size_t col;
};

typedef struct matrix_element MatrixElement;

/* We can add our own bounds-checking to C!
 */

void bounds_check(MatrixElement elt) {
    if (elt.row >= elt.matrix.rows) {
        printf("Error: row index out of bounds!\n");
        abort();
    }
    if (elt.col >= elt.matrix.cols) {
        printf("Error: col index out of bounds!\n");
        abort();
    }
}

int get_element(MatrixElement elt) {
    bounds_check(elt);
    return elt.matrix.elements[
        elt.row * elt.matrix.cols + elt.col
    ];
}

void set_element(
    MatrixElement elt,
    int value
) {
    bounds_check(elt);
    elt.matrix.elements[
        elt.row * elt.matrix.cols + elt.col
    ] = value;
}

void init_matrix(Matrix matrix) {
    MatrixElement elt = {matrix, 0, 0};
    for (elt.row = 0; elt.row < matrix.rows; elt.row++) {
        for (elt.col = 0; elt.col < matrix.cols; elt.col++) {
            set_element(elt, 0);
        }
    }
}

void print_matrix(Matrix matrix) {
    MatrixElement elt = {matrix, 0, 0};
    for (elt.row = 0; elt.row < matrix.rows; elt.row++) {
        for (elt.col = 0; elt.col < matrix.cols; elt.col++) {
            int value = get_element(elt);
            printf("%d ", value);
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
    MatrixElement elt = {matrix, 1, 1};
    set_element(elt, 2);
    print_matrix(matrix);
}

