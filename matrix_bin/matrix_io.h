#ifndef _MATRIX_IO_H_
#define _MATRIX_IO_H_

#include <stdio.h>
#include "matrix.h"

struct matrix read_matrix(FILE * stream);
void print_matrix(
    struct matrix *m,
    FILE * stream
);
void debug_matrix(struct matrix *m);

void write_matrix_binary(
    struct matrix * matrix,
    FILE * stream
);

struct matrix read_matrix_binary(
    FILE * stream
);


#endif /* _MATRIX_IO_H_ */
