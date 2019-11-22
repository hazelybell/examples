#include <string.h>

#define DEBUG

#include "matrix.h"
#include "matrix_io.h"
#include "matrix_ops.h"
#include "debugging.h"
#include "checked_io.h"

static const char * argv0;

void print_usage() {
    fprintf(stderr, "\n");
    fprintf(stderr,
    "Usage: %s [-i inputfilename] "
    "[-o outputfilename]\n",
    argv0);
    fprintf(stderr,
            "%20s   %s\n",
            "-i inputfilename",
            "Specify an optional file to read the two matrices from.");
    fprintf(stderr,
            "%20s   %s\n",
            "-o outputfilename",
            "Specify an optional file to write the product matrix to.");
    fprintf(stderr, "\n");
}

void error_usage() {
    print_usage();
    abort();
}

int main(int argc, char **argv) {
    if (0 < argc) {
        argv0 = argv[0];
    }
    FILE * inputfile = stdin;
    FILE * outputfile = stdout;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-i requires an argument!\n");
                error_usage();
            }
            inputfile = checked_fopen_read(argv[i]);
        }
        else if (strcmp(argv[i], "-o") == 0) {
            i++;
            if (!(i < argc)) {
                fprintf(stderr, "-o requires an argument!\n");
                error_usage();
            }
            outputfile = checked_fopen_write(argv[i]);
        } else {
            fprintf(stderr, "Unrecognized argument: %s\n", argv[i]);
            error_usage();
        }
    }
    if (inputfile == stdin) {
        printf("Enter two matrices seperated by a blank line.\n");
    }
    struct matrix m1 = read_matrix(inputfile);
    struct matrix m2 = read_matrix(inputfile);
    debug("Input matrix 1:\n");
    debug_matrix(&m1);
    debug("Input matrix 2:\n");
    debug_matrix(&m2);
    struct matrix r 
        = multiply_matrix(&m1, &m2);
    debug("Result:\n");
    print_matrix(&r, outputfile);
    free_matrix(&m1);
    free_matrix(&m2);
    free_matrix(&r);
}
