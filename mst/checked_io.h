#ifndef _CHECKED_IO_H_
#define _CHECKED_IO_H_

#include <stdio.h>
#include <stdbool.h>

FILE *checked_fopen_read(
    const char * path,
    bool binary
);

FILE *checked_fopen_write(
    const char * path,
    bool binary
);

char* checked_getline(
    FILE *stream
);

void checked_fread(
    void * destination,
    size_t type_size,
    size_t number,
    FILE * stream
);

void checked_fwrite(
    void * destination,
    size_t type_size,
    size_t number,
    FILE * stream
);

void checked_fclose(FILE * stream);

#endif /* _CHECKED_IO_H_ */


