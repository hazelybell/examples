#include <stdio.h>
#include <stdlib.h>

#define N 5

int x[N][N]; // this makes space for N*N ints in statically allocated memory

// this one is stored in the compiled program itself and cannot be changed when the program is running!
const int c[N][N] = {
    { 0, 1, 2, 3, 4 },
    { 5, 6, 7, 8, 9 },
    { 10, 11, 12, 13, 14 },
    { 15, 16, 17, 18, 19 },
    { 20, 21, 22, 23, 24 }
};

void g(int a[N][N]) {
    // a here only uses enough space for one pointer on the stack
    // BUT NOTE: we have to have some way of knowning how big a is here...
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            a[i][j] = c[i][j];
        }
    }
}

void f() {
    int a[N][N]; // this puts N*N MORE ints on the stack... but only when the function is running. It's not using stack space before you call the function or after the function returns.
    printf("f's a @ %p\n", a);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            a[i][j] = i * N + j;
        }
    }
    g(a);
}

int main(int argc, char **argv) {
    printf("global/external x @ %p\n", x);
    printf("global/external c @ %p\n", c);
    int a[N][N]; // this puts N*N ints on the stack
    printf("main's a @ %p\n", a);
    f();
    g(a);
    int **p = malloc(N * N * sizeof(int)); // this makes enough space for N*N ints on the heap
    printf("heap p @ %p\n", p);
    g((int (*)[5]) p);
    
    char *s = "My favourite string!";
    // now s is a pointer, which is stored on the stack, but the string that s points to is stored in the program itself and cannot be changed, just like the c variable above.
    
    char t[] = "Worst string ever :(";
    // now t is an array which is stored on the stack, and the string it contains can be modified or whatever we want to do with it!
    
    printf("s @ %p\n", s);
    printf("I can read the string s... the first letter is '%c'.\n", s[0]);
    printf("I can read the string t... the first letter is '%c'.\n", t[0]);
    printf("I can change the string t... I'll change the first letter to 'B'\n");
    t[0] = 'B';
    printf("But I can't change the string s... if I try, this is what happens:\n");
    s[0] = 'B';
}
