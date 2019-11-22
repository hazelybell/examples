#define _POSIX_C_SOURCE 200809L

#include "checked_io.h"

#include <errno.h>
#include <stdlib.h>


FILE *checked_fopen_read(const char * path) {
    FILE *r = fopen(path, "r");
    if (r == NULL) {
        perror("Error opening file for reading: ");
        fprintf(stderr, "when opening %s", path);
        abort();
    }
    return r;
}

FILE *checked_fopen_write(const char * path) {
    FILE *r = fopen(path, "w");
    if (r == NULL) {
        perror("Error creating/opening file for writing: ");
        fprintf(stderr, "when opening %s", path);
        abort();
    }
    return r;
}

char* checked_getline(
    FILE *stream
        ) {
    char *line = NULL;
    size_t n = 0;
    ssize_t r = getline(&line, &n, stream);
    if (r < 0 && errno == 0) {
        free(line);
        return NULL;
    } else if (r < 0) {
        perror("getline error: ");
        abort();
    }
    return line;
}
