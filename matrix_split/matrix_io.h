#ifndef _MATRIX_IO_H_
#define _MATRIX_IO_H_

#include "matrix.h"

struct matrix read_matrix();
void print_matrix(struct matrix *m);
void debug_matrix(struct matrix *m);

#endif /* _MATRIX_IO_H_ */
