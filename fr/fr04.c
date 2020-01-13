#include <stdio.h>
#include <math.h>
#include <string.h>

enum k {
    ALPHA,
    BETA
};

struct q {
    unsigned int q: 1;
};

int main() {
    if (0) {
        printf("A ");
    } else {
        printf("a ");
    }
    if (1) {
        printf("B ");
    } else {
        printf("b ");
    }
    if (2) {
        printf("C ");
    } else {
        printf("c ");
    }
    if (NULL) {
        printf("D ");
    } else {
        printf("d ");
    }
    int e = 0;
    volatile int *p = &e;
    if (p) {
        printf("E ");
    } else {
        printf("e ");
    }
    if (0.0) {
        printf("F ");
    } else {
        printf("f ");
    }
    if (1.0) {
        printf("G ");
    } else {
        printf("g ");
    }
    if (0.00000000000000000001) {
        printf("H ");
    } else {
        printf("h ");
    }
    if (NAN) {
        printf("I ");
    } else {
        printf("i ");
    }
    char j = 'j';
    if (j) {
        printf("J ");
    } else {
        printf("j ");
    }
    if (ALPHA) {
        printf("K ");
    } else {
        printf("k ");
    }
    if (BETA) {
        printf("L ");
    } else {
        printf("l ");
    }
    char * m = "tasty";
    if (sscanf(m, "%d", &e)) {
        printf("M ");
    } else {
        printf("m ");
    }
    char n;
    if (sscanf(m, "%c", &n)) {
        printf("N ");
    } else {
        printf("n ");
    }
    if (*m) {
        printf("O ");
    } else {
        printf("o ");
    }
    m += 5;
    if (*m) {
        printf("P ");
    } else {
        printf("p ");
    }
    struct q q = { 0 };
    if (q.q) {
        printf("Q ");
    } else {
        printf("q ");
    }
    q.q += 1;
    if (q.q) {
        printf("R ");
    } else {
        printf("r ");
    }
    q.q += 1;
    if (q.q) {
        printf("S ");
    } else {
        printf("s ");
    }
    int t = -1;
    if (t % 2 == 1) {
        printf("T ");
    } else {
        printf("t ");
    }
    if (strcmp("u", "u")) {
        printf("U ");
    } else {
        printf("u ");
    }
    if (0x10 & 0x01) {
        printf("V ");
    } else {
        printf("v ");
    }
    if (0x10 & (1 << 4)) {
        printf("W ");
    } else {
        printf("w ");
    }
    if (0x10 ^ 0x10) {
        printf("Y ");
    } else {
        printf("y ");
    }
    if (0 | ~0) {
        printf("Z ");
    } else {
        printf("z ");
    }
    printf("\n");
}



// What does this program print... and why?

