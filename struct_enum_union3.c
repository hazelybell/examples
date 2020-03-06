#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

// This is super useful, but we can't do it in C99

struct multi_type {
    enum {
        NOTHING,
        AN_INT,
        A_FLOAT
    } which;
    union {
        int32_t an_int;
        float a_float;
    };
};
typedef struct multi_type MultiType;

void print_mt(MultiType mt) {
    if (mt.which == NOTHING) {
        printf("nothing");
    } else if (mt.which == AN_INT) {
        printf("%d", (int) mt.an_int);
    } else if (mt.which == A_FLOAT) {
        printf("%e", mt.a_float);
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

MultiType new_mt_int(int value) {
    MultiType new;
    new.which = AN_INT;
    new.an_int = value;
    return new;
}

MultiType new_mt_float(float value) {
    MultiType new;
    new.which = A_FLOAT;
    new.a_float = value;
    return new;
}

int main() {
    MultiType mt_array[4] = { { NOTHING } };
    mt_array[0] = new_mt_int(24);
    mt_array[1] = new_mt_int(48);
    mt_array[2] = new_mt_float(0.24);
    mt_array[3] = new_mt_float(0.12);
    printf("\n");
    print_mt_array(mt_array, 4);
}
