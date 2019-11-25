#include <string.h>
#include <stdbool.h>

#include "matrix.h"
#include "matrix_io.h"
#include "matrix_ops.h"
#include "debugging.h"
#include "checked_io.h"

static const char * argv0;

static void print_usage() {
    fprintf(stderr, "\n");
    fprintf(stderr,
    "Usage: %s -i[b] inputfilename "
    "[-i[b] inputfilename ...] "
    "-o outputfilename\n",
    argv0);
    fprintf(stderr,
            "%20s   %s\n",
            "-i inputfilename",
            "Specify a file to read a matrix from. If you specify more than one file, the matrices will be multiplied. Specify - for standard input.");
    fprintf(stderr,
            "%20s   %s\n",
            "-ib inputfilename",
            "Specify a binary file to read a matrix from.");
    fprintf(stderr,
            "%20s   %s\n",
            "-o outputfilename",
            "Specify a file to write the product matrix to. Specify - for standard output.");
    fprintf(stderr,
            "%20s   %s\n",
            "-ob outputfilename",
            "Specify a binary file to write the product matrix to.");
    fprintf(stderr, "\n");
}

static void error_usage() {
    print_usage();
    abort();
}

struct matrix_file {
    FILE * stream;
    bool binary;
};

struct inputs {
    struct matrix_file * list;
    size_t n;
};

static void add_input(
    struct inputs * inputs,
    char * path,
    bool binary
) {
    inputs->n += 1;
    inputs->list = realloc(
        inputs->list,
        sizeof(struct matrix_file)
        * inputs->n
    );
    size_t idx = inputs->n-1;
    if (strcmp(path, "-") == 0) {
        inputs->list[idx].stream = stdin;
    } else {
        inputs->list[idx].stream
            = checked_fopen_read(path, binary);
    }
    inputs->list[idx].binary = binary;
}

static void select_output(
    struct matrix_file * output,
    char * path,
    bool binary
            ) {
    if (strcmp(path, "-") == 0) {
        output->stream = stdout;
    } else {
        output->stream = checked_fopen_write(path, binary);
    }
    output->binary = binary;
}


int main(int argc, char **argv) {
    if (0 < argc) {
        argv0 = argv[0];
    }
    struct inputs inputs = {
        list: NULL,
        n: 0,
    };
    struct matrix_file output = {
        stream: NULL,
        binary: false,
    };
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-i requires an argument!\n");
                error_usage();
            }
            add_input(&inputs, argv[i], false);
        } else if (
            strcmp(argv[i], "-ib") == 0
        ) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-i requires an argument!\n");
                error_usage();
            }
            add_input(&inputs, argv[i], true);
        } else if (
            strcmp(argv[i], "-o") == 0
        ) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-o requires an argument!\n");
                error_usage();
            }
            select_output(&output, argv[i], false);
        } else if (
            strcmp(argv[i], "-ob") == 0
        ) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-ob requires an argument!\n");
                error_usage();
            }
            select_output(&output, argv[i], true);
        } else {
            fprintf(stderr, "Unrecognized argument: %s\n", argv[i]);
            error_usage();
        }
    }
    if (inputs.n < 0) {
        fprintf(stderr, "No inputs specified.\n");
        error_usage();
    }
    if (output.stream == NULL) {
        fprintf(stderr, "No output specified.\n");
        error_usage();
    }
    struct matrix_file input = inputs.list[0];
    struct matrix left;
    if (input.binary) {
        debug("Reading binary matrix...\n");
        left = read_matrix_binary(input.stream);
    } else {
        debug("Reading text matrix...\n");
        left = read_matrix(input.stream);
    }
    debug("Input matrix 0:\n");
    debug_matrix(&left);
    for (size_t i = 1; i < inputs.n; i++) {
        struct matrix right;
        input = inputs.list[i];
        if (input.binary) {
            debug("Reading binary matrix...\n");
            right = read_matrix_binary(input.stream);
        } else {
            debug("Reading text matrix...\n");
            right = read_matrix(input.stream);
        }
        debug("Input matrix %zu:\n", i);
        debug_matrix(&right);
        struct matrix product = multiply_matrix(&left, &right);
        debug("Product %zu:\n", i);
        debug_matrix(&product);
        free_matrix(&left);
        free_matrix(&right);
        left = product;
    }
    if (output.binary) {
            write_matrix_binary(&left, output.stream);
    } else {
            print_matrix(&left, output.stream);
    }
    free_matrix(&left);
    for (size_t i = 1; i < inputs.n; i++) {
        input = inputs.list[i];
        if (input.stream != stdin) {
            checked_fclose(input.stream);
        }
    }
    if (output.stream != stdout) {
        checked_fclose(output.stream);
    }
}
