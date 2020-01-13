#include <stdio.h>

int f1(int x) {
    return x++;
}

int g1(int x) {
    return ++x;
}

int h1(int x) {
    return x += 1;
}

void one() {
    printf("one:\n");
    int a = 0;
    int b = 0;
    int c = 0;
    printf("%d %d %d\n", a, b, c);
    int af = f1(a);
    int bg = g1(b);
    int ch = h1(c);
    printf("%d %d %d\n", a, b, c);
    printf("%d %d %d\n", af, bg, ch);
}

int f2(int *x) {
    return (*x)++;
}

int g2(int *x) {
    return ++(*x);
}

int h2(int *x) {
    return (*x) += 1;
}

void two() {
    printf("one:\n");
    int a = 0;
    int b = 0;
    int c = 0;
    printf("%d %d %d\n", a, b, c);
    int af = f2(&a);
    int bg = g2(&b);
    int ch = h2(&c);
    printf("%d %d %d\n", a, b, c);
    printf("%d %d %d\n", af, bg, ch);
    printf("- - -\n");
}

int f3(int x[1]) {
    return x[0]++;
}

int g3(int x[1]) {
    return ++x[0];
}

int h3(int *x) {
    return x[0] += 1;
}

void three() {
    printf("three:\n");
    int a[1] = { 0 };
    int b[1] = { 0 };
    int c[1] = { 0 };
    printf("%d %d %d\n", a[0], b[0], c[0]);
    int af = f3(a);
    int bg = g3(b);
    int ch = h3(c);
    printf("%d %d %d\n", a[0], b[0], c[0]);
    printf("%d %d %d\n", af, bg, ch);
    printf("- - -\n");
}

struct n {
    int n;
};

typedef struct n N;

int f4(N x) {
    return x.n++;
}

int g4(N x) {
    return ++x.n;
}

int h4(N x) {
    return x.n += 1;
}

void four() {
    printf("four:\n");
    N a = { 0 };
    N b = { 0 };
    N c = { 0 };
    printf("%d %d %d\n", a.n, b.n, c.n);
    int af = f4(a);
    int bg = g4(b);
    int ch = h4(c);
    printf("%d %d %d\n", a.n, b.n, c.n);
    printf("%d %d %d\n", af, bg, ch);
    printf("- - -\n");
}

int f5(N *x) {
    return x->n++;
}

int g5(N *x) {
    return ++x->n;
}

int h5(N *x) {
    return x->n += 1;
}

void five() {
    printf("five:\n");
    N a = { 0 };
    N b = { 0 };
    N c = { 0 };
    printf("%d %d %d\n", a.n, b.n, c.n);
    int af = f5(&a);
    int bg = g5(&b);
    int ch = h5(&c);
    printf("%d %d %d\n", a.n, b.n, c.n);
    printf("%d %d %d\n", af, bg, ch);
    printf("- - -\n");
}

int main() {
    one();
    two();
    three();
    four();
    five();
}

// What does this print... and why?
// Try to answer without compiling and running it!

