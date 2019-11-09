#include <stdio.h>
#include <stdlib.h>

// we end up with a lot of code that looks like if(!(some_assumption)) abort();
// if (something seems wrong) abort();

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

#define ASSERT(exp) assert(__FILE__, __LINE__, __func__, #exp, exp)

int main(int argc, char **argv) {
    ASSERT(1);
    ASSERT(2 == 2);
    ASSERT(2 == 3);
}
