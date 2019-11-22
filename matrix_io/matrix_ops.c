#include "matrix_ops.h"
#include "debugging.h"

static void produce_element(
    struct cursor *c,
    struct matrix *m1,
    struct matrix *m2
     ) {
    struct cursor rowc = zerozero(m1);
    rowc.row = c->row;
    struct cursor colc = zerozero(m2);
    colc.col = c->col;
    double accumulator = 0.0;
    while (in(&rowc)) {
        ASSERT(in(&colc));
        double v1 = get_element(&rowc);
        double v2 = get_element(&colc);
        accumulator += v1 * v2;
        right(&rowc);
        down(&colc);
    }
    ASSERT(!in(&colc));
    ASSERT(!in(&rowc));
    set_element(c, accumulator);
}

struct matrix multiply_matrix(
    struct matrix *m1,
    struct matrix *m2
              ) {
    DASSERT(
        m1->cols == m2->rows,
        "Matrix 1 is %zux%zu cols and matrix 2 is %zux%zu, can't multiply!",
        m1->rows,
        m1->cols,
        m2->rows,
        m2->cols
    );
    struct matrix r = new_matrix(m1->rows, m2->cols);
    for (struct cursor c = zerozero(&r);
         in(&c);
         next(&c)
    ) {
        produce_element(&c, m1, m2);
    }
    return r;
}
