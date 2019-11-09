#include <stdio.h>
#include <string.h>

#define LENGTH 10

typedef int mytype;

// Compile and debug: 
// gcc --std=c99 -Wall -ftrapv -ggdb -o ptr_fail ptr_fail.c && gdb ./ptr_fail


int main(int argc, char ** argv) {
    mytype a[LENGTH];
    
    for (size_t i = 0; i <= LENGTH || 1; i++) {
        mytype *p1 = a + i;
        mytype *p2 = &a[i];
        char *p3 = ((char *) a) + i;
        printf("%p %p %p %lld\n",
               p1,
               p2,
               p3,
               (long long int) *p1
        );
    }
    return 0;
}


// Most useful gdb commands:
// run [arglist]
// print expr (print a variable/expression)
// bt (get a backtrace)
// quit
// see man gdb for more


