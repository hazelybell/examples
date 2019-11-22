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

#endif /* _MATRIX_IO_H_ */
