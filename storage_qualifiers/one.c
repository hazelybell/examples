#include "one.h"

#include <stdio.h>

int a = 1;

void print_a_one() {
    printf("in one.c: a=%d\n", a);
}

const int G = 70;

static int hi_one(int k) {
    printf("hello from one.c! k=%d\n", k);
    return k + 1;
}

int (*hello)(int k) = &hi_one;

// we need one of these to generate a copy that's not inlined
// this is necessary if optimizations arent enabled!
extern inline int n(int o);
