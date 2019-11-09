#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stddef.h> // size_t

// Types go in the header!
struct matrix {
    double *m; /* pointer to first element of matrix */
    size_t rows; /* rows in matrix */
    size_t cols; /* cols in matrix */
};

struct cursor {
    struct matrix *m;
    size_t row;
    size_t col;
};

// Declarations of functions (function prototypes) go in the header!
int in(struct cursor *c);

size_t ij(struct cursor *c);

double set_element(
    struct cursor *c,
    double value
);

double get_element(struct cursor *c);

struct cursor zerozero(struct matrix *m);

void right(struct cursor *c);

void down(struct cursor *c);

void next(struct cursor *c);

void clear_matrix(struct matrix *m);

struct matrix new_matrix(size_t rows, size_t cols);

void free_matrix(struct matrix *m);
#endif /* _MATRIX_H_ */
