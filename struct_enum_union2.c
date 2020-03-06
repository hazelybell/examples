#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

struct multi_type {
    enum {
        NOTHING,
        AN_INT,
        A_FLOAT
    } which;
    union {
        int32_t an_int;
        float a_float;
    } value;
};
typedef struct multi_type MultiType;

void print_mt(MultiType mt) {
    if (mt.which == NOTHING) {
        printf("nothing");
    } else if (mt.which == AN_INT) {
        printf("%d", (int) mt.value.an_int);
    } else if (mt.which == A_FLOAT) {
        printf("%e", mt.value.a_float);
    } else {
        abort();
    }
}

void print_mt_array(MultiType *mt_array, size_t length) {
    for (size_t idx = 0; idx < length; idx++) {
        print_mt(mt_array[idx]);
        printf(" ");
    }
    printf("\n");
}

int main() {
    MultiType mt_array[4] = {
        { NOTHING },
        { AN_INT, { .an_int=10 } },
        { A_FLOAT, { .a_float=0.1 } }
    };
    printf("\n");
    print_mt_array(mt_array, 4);
}
