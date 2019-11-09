#include "matrix.h"
#include "matrix_io.h"
#include "matrix_ops.h"
#include "debugging.h"

int main(int argc, char **argv) {
    printf("Enter two matrices seperated by a blank line.\n");
    struct matrix m1 = read_matrix();
    struct matrix m2 = read_matrix();
    debug("Input matrix 1:\n");
    debug_matrix(&m1);
    debug("Input matrix 2:\n");
    debug_matrix(&m2);
    struct matrix r 
        = multiply_matrix(&m1, &m2);
    debug("Result:\n");
    print_matrix(&r);
    free_matrix(&m1);
    free_matrix(&m2);
    free_matrix(&r);
}
