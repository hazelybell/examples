#include "matrix_io.h"
#include "debugging.h"
#include "checked_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// static functions and variables are NOT accessible from other functions, and should not be included in the header
static size_t count_line(char * line) {
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

static void read_row(char * line,
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

struct matrix read_matrix(FILE *stream) {
    size_t rows = 0;
    size_t cols = 0;
    char **lines = NULL;
    while (1) {
        char *line = checked_getline(stream);
        if (line == NULL) {
            break;
        }
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

static size_t get_len(double value) {
    char temp[101];
    int printed = snprintf(temp, 100, "%f", value);
    if (printed < 1) abort();
    size_t len = strlen(temp);
    return len;
}

static size_t get_longest(struct matrix *m) {
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

void print_matrix(
    struct matrix *m,
    FILE *stream
) {
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
            fprintf(stream, format, elt);
        }
        fprintf(stream, "\b\n");
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
