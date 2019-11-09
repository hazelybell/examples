/* This is a program that reads in and
 * multiplies two matrices. It is 
 * intended to demonstrate several aspects
 * of C programming:
 * structs
 * realloc
 * pseudo-constructors/destructors/methods
 * manual array bounds checking
 * mapping a 2D array onto 1D memory
 * NULL pointers
 * EOF
 * advanced scanf() usage
 * %m
 * %[]
 * sscanf()
 * snprintf()
 * Generating printf formats using printf
 * Reading inputs of unknown size
 * Matrix multiplication
 * abort() and gdb
 * pointers to structs and ->
 * structs and .
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct: note the semicolons!

struct matrix {
    double *m; /* pointer to first element of matrix */
    size_t rows; /* rows in matrix */
    size_t cols; /* cols in matrix */
};

double set_element(
    struct matrix *m,
    size_t row,
    size_t col,
    double value
       ) {
    // accessing an element of a pointer to a struct: ->
    if (row >= m->rows) abort();
    if (col >= m->cols) abort();
    // This maps a 2D array row and column onto a 1D array storage
    m->m[row * m->cols + col] = value;
    return value;
}

double get_element(
    struct matrix *m,
    size_t row,
    size_t col
       ) {
    if (row >= m->rows) abort();
    if (col >= m->cols) abort();
    // This maps a 2D array row and column onto a 1D array storage
    return m->m[row * m->cols + col];
}

void clear_matrix(struct matrix *m) {
    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->rows; j++) {
            set_element(m, i, j, 0.0);
        }
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

size_t read_row(char * line,
              size_t row,
              struct matrix *m
             ) {
    double element;
    size_t col = 0;
    int chars_consumed = 0;
    while (sscanf(line, "%lf%n", &element, &chars_consumed) == 1) {
        set_element(m, row, col, element);
        line += chars_consumed;
        col += 1;
    }
    return col;
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
    for (size_t i = 0; i < rows; i++) {
        char *line = lines[i];
        size_t cols_read = 
            read_row(line, i, &m);
        if (cols != cols_read) abort();
        free(line);
    }
    free(lines);
    return m;
}

void produce_element(
    struct matrix *r,
    struct matrix *m1,
    struct matrix *m2,
    size_t row,
    size_t col
     ) {
    double accumulator = 0.0;
    for (size_t i = 0; i < m1->cols; i++) {
        double v1 = get_element(m1, row, i);
        double v2 = get_element(m2, i, col);
        accumulator += v1 * v2;
    }
    set_element(r, row, col, accumulator);
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
    for (size_t i = 0; i < r.rows; i++) {
        for (size_t j = 0; j < r.cols; j++) {
            produce_element(&r, m1, m2, i, j);
        }
    }
    return r;
}

size_t get_len(double value) {
    // gets the length in characters of a floating point value when it's printed out
    // ex: 123 -> "123.00000" -> 9
    char temp[101];
    int printed = snprintf(temp, 100, "%f", value);
    if (printed < 1) abort();
    size_t len = strlen(temp);
    return len;
}

size_t get_longest(struct matrix *m) {
    size_t longest = 0;
    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            double elt = get_element(m, i, j);
            size_t len =
                get_len(elt);
            if (len > longest) {
                longest = len;
            }
        }
    }
    return longest;
}

// printf("%10f"

void print_matrix(struct matrix *m) {
    size_t len = get_longest(m);
    char format[11];
    size_t printed = snprintf(format, 10, "%%%zuf ", len);
    if (printed < 1) abort();
    for (size_t i = 0; i < m->rows; i++) {
        for (size_t j = 0; j < m->cols; j++) {
            double elt = get_element(m, i, j);
            printf(format, elt);
        }
        printf("\b\n");
    }
}

int main(int argc, char **argv) {
    printf("Enter two matrices seperated by a blank line.\n");
    struct matrix m1 = read_matrix();
    struct matrix m2 = read_matrix();
    struct matrix r 
        = multiply_matrix(&m1, &m2);
    print_matrix(&r);
    free_matrix(&m1);
    free_matrix(&m2);
    free_matrix(&r);
}
