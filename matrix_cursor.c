/* This is a program that reads in and
 * multiplies two matrices. It is 
 * intended to demonstrate several aspects
 * of C programming:
 * stderr
 * useful debugging constructs
 * useful preprocessor constructs
 * more uses of struct
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// turns debug(a) into fprintf(stderr, a)
// turns debug(a, b) into fprintf(stderr, a, b)
// turns debug(a, b, c) into fprintf(stderr, a, b, c)
// etc.
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

// struct: note the semicolons!

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

char *new_empty_string() {
    char *line = (char *) malloc(1 * sizeof(char));
    line[0] = '\0';
    return line;
}

char *read_line() {
    char * line = NULL;
    int r = scanf("%m[^\n]", &line);
    if (r == EOF) {
        return new_empty_string();
    }
    char c = 0;
    int nl = scanf("%c", &c);
    if (r == 1 && nl == 1 && c == '\n') {
        return line;
    }
    if (r == 0 && nl == 1 && c == '\n') {
        // this must be an empty line
        return new_empty_string();
    }
    printf("%d %d %d\n", r, nl, c);
    abort();
    return NULL;
}

size_t count_line(char * line) {
    double value;
    size_t count = 0;
    int chars_consumed = 0;
    if (line == NULL) abort();
    while (sscanf(line, "%lf%n", &value, &chars_consumed) == 1) {
        line += chars_consumed;
        count += 1;
    }
    return count;
}

void read_row(char * line,
            struct cursor *c
             ) {
    double element;
    int chars_consumed = 0;
    while (sscanf(line, "%lf%n", &element, &chars_consumed) == 1) {
        set_element(c, element);
        line += chars_consumed;
        right(c);
    }
}

struct matrix read_matrix() {
    size_t rows = 0;
    size_t cols = 0;
    char **lines = NULL;
    while (1) {
        char *line = read_line();
        if (line == NULL) abort();
        size_t line_cols = count_line(line);
        if (line_cols == 0) {
            free(line);
            break;
        }
        if (cols == 0) {
            cols = line_cols;
        }
        if (cols != line_cols) {
            printf("Inconsistent number of columns on row %zu\n", rows);
            abort();
        }
        // free(ptr) is kind of like realloc(ptr, 0)
        // malloc(size) is kind of like realloc(NULL, size)
        lines = realloc(lines, (rows+1) * sizeof(char *));
        lines[rows] = line;
        rows++;
    }
    if (rows == 0 || cols == 0) {
        printf("Rows or cols was 0?\n");
        abort();
    }
    struct matrix m = new_matrix(rows, cols);
    for (
        struct cursor c = zerozero(&m);
        in(&c);
        down(&c)
    ) {
        char *line = lines[c.row];
        struct cursor rowc = c;
        read_row(line, &rowc);
        if (cols != rowc.col) abort();
        free(line);
    }
    free(lines);
    return m;
}

void produce_element(
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
        if (!in(&colc)) abort();
        double v1 = get_element(&rowc);
        double v2 = get_element(&colc);
        accumulator += v1 * v2;
        right(&rowc);
        down(&colc);
    }
    if (in(&colc)) abort();
    set_element(c, accumulator);
}

struct matrix multiply_matrix(
    struct matrix *m1,
    struct matrix *m2
              ) {
    if (m1->cols != m2->rows) {
        printf("Matrix 1 is %zux%zu cols and matrix 2 is %zux%zu, can't multiply!\n", m1->rows, m1->cols,
               m2->rows, m2->cols);
        abort();
    }
    struct matrix r = new_matrix(m1->rows, m2->cols);
    for (struct cursor c = zerozero(&r);
         in(&c);
         next(&c)
    ) {
        produce_element(&c, m1, m2);
    }
    return r;
}

size_t get_len(double value) {
    char temp[101];
    int printed = snprintf(temp, 100, "%f", value);
    if (printed < 1) abort();
    size_t len = strlen(temp);
    return len;
}

size_t get_longest(struct matrix *m) {
    size_t longest = 0;
    for (
        struct cursor c = zerozero(m);
        in(&c);
        next(&c)
    ) {
        double elt = get_element(&c);
        size_t len =
            get_len(elt);
        if (len > longest) {
            longest = len;
        }
    }
    return longest;
}

void print_matrix(struct matrix *m) {
    size_t len = get_longest(m);
    char format[11];
    size_t printed = snprintf(format, 10, "%%%zuf ", len);
    if (printed < 1) abort();
    for (
        struct cursor c = zerozero(m);
        in(&c);
        down(&c)
    ) {
        for(
            c.col=0;
            in(&c);
            right(&c)
        ) {
            double elt = get_element(&c);
            printf(format, elt);
        }
        printf("\b\n");
        c.col = 0;
    }
}

void debug_matrix(struct matrix *m) {
#ifdef DEBUG
    size_t len = get_longest(m);
    char format[11];
    size_t printed = snprintf(format, 10, "%%%zuf ", len);
    if (printed < 1) abort();
    for (
        struct cursor c = zerozero(m);
        in(&c);
        down(&c)
    ) {
        for(
            c.col=0;
            in(&c);
            right(&c)
        ) {
            double elt = get_element(&c);
            debug(format, elt);
        }
        debug("\b\n");
        c.col = 0;
    }
#endif /* DEBUG */
}

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
