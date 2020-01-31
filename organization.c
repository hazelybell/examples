// Copyright 2020 Hazel Victoria Campbell
// organization.c: A simple C program to demonstrate the organization of C programs

#include <stdio.h>

#define N 4

/* Typedefs are often in CamelCase to distinguish them, or they are all lowercase followed by a _t */
typedef int Count;
typedef int count_t;

const Count main_counts = 0;

/* Order:

In C, you need to put things in the correct
order in your file... the things being used
need to go BEFORE the things using them.
* In general, main will be LAST.

In general:

0. copyright
0. program description
1. includes
2. defines
3. type
4. constants
5. functions

However this chan change subject to the rule above.
*/

Count callee(Count counter) {
    printf("In callee!\n");
    return counter + 1;
}

Count caller(Count counter) {
    printf("In caller!\n");
    return callee(counter + 1);
}

int main() {
    Count counter = 0;
    printf("In main!\n");
    counter += main_counts;
    counter = caller(counter);
    printf("counter=%d\n", counter);
    return 0;
}

