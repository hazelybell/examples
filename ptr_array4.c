#include <stdio.h>
#include <string.h>

#define LENGTH 10

typedef int mytype;

int main(int argc, char ** argv) {
    mytype a[LENGTH];
    mytype *p = a;
    for (size_t i = 0; i < LENGTH; i++) {
        a[i] = (mytype) i;
    }
    while (p < &a[LENGTH]) {
        printf("%p %lld %p\n",
            p,
//             *p++,
//             (long long int) ++*p,
//             (*p)++, // increment value
//             ++(*p),
//             *(p++), // increment address
//             *(++p),
            p
        );
    }
    return 0;
}


