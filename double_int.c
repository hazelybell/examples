#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define N 5

enum kind {
    U64,
    I64,
    DBL
};

union intdbl {
    uint64_t u;
    int64_t i;
    double d;
};

struct numbery {
    enum kind kind;
    union intdbl id;
};

struct numbery dbl(double x) {
    struct numbery new = {
        DBL,
        { .d = x }
    };
    return new;
}

struct numbery i64(int64_t x) {
    struct numbery new = {
        I64,
        { .i = x }
    };
    return new;
}

struct numbery u64(uint64_t x) {
    struct numbery new = {
        U64,
        { .u = x }
    };
    return new;
}

char * stringify(struct numbery n) {
    size_t length = 20;
    char *s = malloc((length+1) * sizeof(char));
    switch (n.kind) {
        case (U64):
            snprintf(s, length, "%lu", n.id.u);
            break;
        case (I64):
            snprintf(s, length, "%ld", n.id.i);
            break;
        case (DBL):
            snprintf(s, length, "%e", n.id.d);
            break;
        default:
            abort();
    }
    return s; // don't forget to free this later
}

int main(int argc, char **argv) {
    struct numbery array[N];
    for (size_t i = 0; i < N; i++) {
        int k = rand() % 3;
        if (k == U64) {
            array[i] = u64(rand());
        } else if (k == I64) {
            array[i] = i64(-rand());
        } else if (k == DBL) {
            array[i] = dbl(rand());
        }
    }
    for (size_t i = 0; i < N; i++) {
        char *s = stringify(array[i]);
        printf("%s ", s);
        free(s);
    }
    printf("\n");
    return 0;
}
