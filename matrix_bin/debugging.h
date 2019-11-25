// the contents of the header are wrapped in a a big ifdef to prevent the contents from being included twice!
// Do this with every header!
#ifndef _DEBUGGING_H_
#define _DEBUGGING_H_

#include <stdio.h>
#include <stdlib.h>

// turns debug(a) into fprintf(stderr, a)
// turns debug(a, b) into fprintf(stderr, a, b)
// turns debug(a, b, c) into fprintf(stderr, a, b, c)
// etc.
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else /* DEBUG */
#define debug(...)
#endif /* DEBUG */

void assert(
    const char * file,
    int line,
    const char * func,
    const char * expr,
    int value
);

#define ASSERT(exp) assert(__FILE__, __LINE__, __func__, #exp, exp)

#define DASSERT(exp, ...) {\
    if (!(exp)) {\
        fprintf(stderr, "Fatal error: ");\
        fprintf(stderr, __VA_ARGS__);\
        fprintf(\
            stderr, \
            "\n    in %s at %s:%d (%s) failed.\n",\
            __func__,\
            __FILE__,\
            __LINE__,\
            #exp\
        );\
        abort();\
    }\
}

#endif /* _DEBUGGING_H_ */
// its good practice to make a comment after #endif to remind the reader which #ifdef is being ended
