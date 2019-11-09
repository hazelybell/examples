// Define 2: The reckoning!

#include <stdio.h>
#include <stdlib.h>

#define N 11

// define1.c

void n() {
    printf("N=%d\n", N);
}

// #define THING
#define STUFF

#ifdef THING
void f() {
    printf("THING is defined!\n");
}
#else
void f() {
    printf("THING isn't defined :(\n");
}
#endif

void g() {
#ifdef STUFF
    printf("STUFF is defined!\n");
#else
    printf("STUFF isn't defined :(");
#endif
}

#define ENABLE_H_FUNCTION

#ifdef ENABLE_H_FUNCTION
void h() {
    printf("H function is available.\n");
}
#endif /* ENABLE_H_FUNCTION */

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

#ifndef M
#define M 10001
#endif

void m() {
    printf("M=%d\n", M);
}

int main(int argc, char **argv) {
    printf("n():\n");
    n();
    printf("f():\n");
    f();
    printf("g():\n");
    g();
    printf("h():\n");
    h();
    printf("max():\n");
    printf("%d\n", max(-23, 0));
    printf("%d\n", max(23, 0));
    printf("MAX():\n");
#define MAX(a, b) ((a > b) ? a : b)
    printf("%d\n", MAX(-23, 0));
    printf("%d\n", MAX(23, 0));
#define AT_LEAST_0(a) MAX(a, 0)
    printf("AT_LEAST_0():\n");
    printf("%d\n", AT_LEAST_0(-23));
    printf("%d\n", AT_LEAST_0(23));
    printf("m():\n");
    m();
    return 0;
}
