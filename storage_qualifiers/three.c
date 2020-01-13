#include "three.h"

#include <stdio.h>

void print_a_three() {
    extern int a;
    printf("in three.c: a=%d\n", a);
    a = 10000;
}

// I can't do this, it causes an error when I go to link my files together!
// int a = 3;
