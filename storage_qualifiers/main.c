#include "one.h"
#include "two.h"
#include "three.h"

#include <stdio.h>
#include <limits.h>
#include <fenv.h>
extern int feenableexcept(int excepts);

extern int a;

static int e = 50;

static void f() {
    printf("in f: -----\n");
    auto int b = 20; // auto is the default!
    // exactly the same as:
    // int b = 20;
    printf(
        "auto int b @ %p = %d\n", 
        (void *) &b, 
        b
    );
    b += 1;
    static int c = 30;
    printf(
        "static int c @ %p = %d\n",
        (void *) &c,
        c
    );
    c += 1;
    register int d = 40;
    printf("register int d = %d\n", d);
    // we can't do this, because d is a register var so we can't get its address!
//     printf(
//         "register int d @ %p = %d\n",
//         (void *) &d, 
//         d
//     );
    d += 1;
    extern int e;
    printf(
        "extern int e @ %p = %d\n", 
        (void *) &e, 
        e
    );
    e += 1;
    auto const int F = 60;
    // exactly the same as:
    // const int F = 60;
    printf(
        "const auto int F @ %p = %d\n", 
        (void *) &F, 
        F
    );
}

static void g() {
    f();
}

static void v() {
    volatile double h = 0.0;
    volatile double i = 1.0;
    i += 2.0;
    volatile double j = i/h;
    printf("i/h=j=%g\n", j);
}

static int hi_main(int k) {
    printf("hello from main.c! k=%d\n", k);
    return k + 1;
}

static void increment(int *p) {
    *p += 1;
}

static void increment_r(int * restrict p) {
    *p += 1;
}

static void increment_two(
    int * restrict p1,
    int * restrict p2
) {
    *p1 += 1;
    *p2 += 2;
}


int main() {
    printf("in main.c: a=%d\n", a);
    print_a_one();
    print_a_two();
    print_a_three();
    printf("in main.c: a=%d\n", a);
    f();
    g();
    printf("in main.c: G=%d\n", G);
    v();
    feenableexcept(FE_ALL_EXCEPT);
//     v();
    // can't do this! C99 forbids conversion of a function pointer to a data pointer!
//     printf("in main.c: hello @ %p\n",
//            (void *) hello
//           );
    printf("in main.c: hello @ 0x%zx\n",
           (size_t) hello
          );
    hello(80);
    hello = &hi_main;
    hello(80);
    printf("------\n");
    void (*print_a[])() = { print_a_one, print_a_two, print_a_three };
    for (int i = 0; i < 3; i++) {
        printf("in main.c: print_a @ 0x%zx\n",
           (size_t) print_a[i]
          );
        print_a[i]();
    }
    printf("------\n");
    const char *sb = "Bulbasaur";
    const char *sc = "Charmander";
    printf("%s %s\n", sb, sc);
    // we can't do this because sb POINTS TO const data!
//     sb[0] = 'C';
    sb = sc;
    printf("%s %s\n", sb, sc);
    char * const ss = "Squirtle";
    // we can't do this because ss IS A CONSTANT POINTER
//     ss = sc;
    // but this compiles... but it crashes!
    // or does nothing with optimizations on!
    ss[0] = 'T';
    printf("%s\n", ss);
    
    const char * const sp = "Pikachu";
    // we can't do this because sp IS A CONSTANT POINTER
//     sp = sc;
    // we can't do this because sp POINTS TO CONSTANT DATA
//     sp[0] = 'Q';
    
    printf("%s\n", sp);

    volatile char * const sv = "Eevee";
    // we can't do this because ss IS A CONSTANT POINTER
//     ss = sc;
    // but this compiles... but it crashes!
    // at least it does the same thing with optimizations on -_-;;
//     sv[0] = 'A';
    printf("%s\n", sv);
    printf("------\n");
    int l = 100;
    int m = 200;
    printf("l=%d m=%d\n", l, m);
    increment(&l);
    printf("l=%d m=%d\n", l, m);
    increment_r(&l);
    printf("l=%d m=%d\n", l, m);
    // we can do this:
    increment_two(&l, &m);
    // but we can't do this!
//     increment_two(&l, &l);
    printf("l=%d m=%d\n", l, m);
    int q = 300;
    q = n(q);
    printf("q=%d\n", q);
    return 0;
}
