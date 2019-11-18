#include "matrix.h"
#include "debugging.h"
#include <stdlib.h>

// struct: note the semicolons!

int in(struct cursor *c) {
    if (c->row >= c->m->rows) return 0;
    if (c->col >= c->m->cols) return 0;
    return 1;
}

size_t ij(struct cursor *c) {
    if (!in(c)) abort();
    return c->row * c->m->cols + c->col;
    
}

double set_element(
    struct cursor *c,
    double value
       ) {
    // accessing an element of a pointer to a struct: ->
    // This maps a 2D array row and column onto a 1D array storage
    c->m->m[ij(c)] = value;
    return value;
}

double get_element(
    struct cursor *c
       ) {
    debug("Get element: %f\n", c->m->m[ij(c)]);
    return c->m->m[ij(c)];
}

struct cursor zerozero(struct matrix *m) {
    struct cursor new = {
        m,
        0,
        0
    };
    return new;
}

void right(struct cursor *c) {
    c->col += 1;
    debug("Move cursor right to (%zu,%zu)\n", c->row, c->col);
}

void down(struct cursor *c) {
    c->row += 1;
    debug("Move cursor down to (%zu,%zu)\n", c->row, c->col);
}

void next(struct cursor *c) {
    right(c);
    if (!in(c)) {
        debug("Next row!\n");
        c->col = 0;
        down(c);
    }
}

void clear_matrix(struct matrix *m) {
    for (
        struct cursor c = zerozero(m);
        in(&c);
        next(&c)
    ) {
        set_element(&c, 0.0);
    }
}

struct matrix new_matrix(size_t rows, size_t cols) {
    struct matrix new = {
        NULL,  // *m
        rows,  // rows
        cols   // cols
    };
    // accessing an element of a struct .
    new.m = (double *) malloc(
            rows 
            * cols 
            * sizeof(double)
        );
    // arrow is like (*m).
    clear_matrix(&new);
    return new;
}

void free_matrix(struct matrix *m) {
    free(m->m);
    m->m = NULL; // null pointer = 0
    m->rows = 0;
    m->cols = 0;
}

