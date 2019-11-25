#define _POSIX_C_SOURCE 200809L
// necessary to use getline()
// we have to define _POSIX_C_SOURCE before any includes!
// this tells the system libraries that we want more modern library functions (up to August 2008)

#include "checked_io.h"

#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *checked_fopen_read(
    const char * path,
    bool binary
) {
    FILE *r;
    if (binary) {
        r = fopen(path, "rb");
    } else {
        r = fopen(path, "r");
    }
    if (r == NULL) {
        perror("Error opening file for reading");
        fprintf(stderr, "when opening %s\n", path);
        abort();
    }
    return r;
}

FILE *checked_fopen_write(
    const char * path,
    bool binary
) {
    FILE *r;
    if (binary) {
        r = fopen(path, "wb");
    } else {
        r = fopen(path, "w");
    }
    if (r == NULL) {
        perror("Error creating/opening file for writing");
        fprintf(stderr, "Error opening %s\n", path);
        abort();
    }
    return r;
}

void checked_fclose(FILE *stream) {
    int r = fclose(stream);
    if (r == 0) return;
    perror("Error closing file for writing");
    abort();
}

char* checked_getline(FILE *stream) {
    char *line = NULL;
    size_t n = 0;
    ssize_t r = getline(&line, &n, stream);
    if (r < 0 && errno == 0) {
        free(line);
        return NULL;
    } else if (r < 0) {
        perror("getline error");
        abort();
    }
    return line;
}

void checked_fread(
    void * destination,
    size_t type_size,
    size_t number,
    FILE * stream
) {
    size_t n_read = fread(
        destination,
        type_size,
        number,
        stream
    );
    if (n_read == number) return;
    if (errno) {
        perror("Error reading binary matrix file");
        abort();
    }
    if (feof(stream)) {
        fprintf(stderr, "File was smaller than it was supposed to be.\n");
        abort();
    }
    if (ferror(stream)) {
        fprintf(stderr, "Error reading binary matrix file.\n");
        abort();
    }
    abort();
}

void checked_fwrite(
    void * destination,
    size_t type_size,
    size_t number,
    FILE * stream
) {
    size_t n_written = fwrite(
        destination,
        type_size,
        number,
        stream
    );
    if (n_written == number) {
        fflush(stream);
        return;
    };
    if (errno) {
        perror("Error writing binary matrix file");
        abort();
    }
    if (ferror(stream)) {
        fprintf(stderr, "Error writing binary matrix file.\n");
        abort();
    }
    abort();
}


