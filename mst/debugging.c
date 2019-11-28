#include "debugging.h"
#include <stdio.h>

void assert(
    const char * file,
    int line,
    const char * func,
    const char * expr,
    int value
) {
    if (value) return;
    fprintf(
        stderr, 
        "Assertion in %s at %s:%d (%s) failed.\n",
        func,
        file,
        line,
        expr
    );
    abort();
}
