#ifndef _CHECKED_IO_H_
#define _CHECKED_IO_H_

#include <stdio.h>

FILE *checked_fopen_read(
    const char * path
);

FILE *checked_fopen_write(
    const char * path
);

char* checked_getline(
    FILE *stream
);

#endif /* _CHECKED_IO_H_ */


