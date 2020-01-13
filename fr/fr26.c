#include <stdio.h>
#include <stdlib.h>

int a = 1;
const int b = 2;


int f(int c) {
    int d = 4;
    static int e = 5;
    auto int g = 7;
    register int h = 8;
    volatile int i = 9;
    const int j = 10;
    static const int k = 11;
    int o[1] = { 15 };
    int *p = malloc(sizeof(int) * 1);
    p[0] = 16;
    const char * s = "18";
    return 6;
}

static int l = 12;
static const int m = 13;
extern int n;

int main() {
    return f(3);
}

/* For each, where is it stored?
 * a?
 * b?
 * c?
 * d?
 * e?
 * the return value of f?
 * g?
 * h?
 * i?
 * j?
 * k?
 * l?
 * m?
 * n?
 * o?
 * o[0]?
 * p?
 * p[0]?
 * s?
 * s[0]?
 */



