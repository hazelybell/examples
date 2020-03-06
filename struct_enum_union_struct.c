#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

#define BUFFER_SIZE 80

typedef struct {
    int32_t numerator;
    uint32_t denominator;
} Fraction;

struct multi_type {
    enum {
        NOTHING,
        AN_INT,
        A_FLOAT,
        A_FRACTION
    } which;
    union {
        int32_t an_int;
        float a_float;
        Fraction a_fraction;
    } value;
};
typedef struct multi_type MultiType;

MultiType input_mt() {
    char line[BUFFER_SIZE];
    if (fgets(line, BUFFER_SIZE, stdin) == NULL) {
        abort();
    }
    line[BUFFER_SIZE-1] = '\0';
    int32_t numerator;
    uint32_t denominator;
    if (sscanf(line, "%d/%u", &numerator, &denominator) == 2) {
        return new_mt_fraction(numerator, denominator);
    }
    int chars_consumed;
    size_t line_length = strlen(line)-1;
    float a_float;
    int scanned = sscanf("%f%n", &float, &chars_consumed);
    if (scanned == 1 && chars_consumed == line_length) {
        return new_mt_float(a_float);
    }
    scanned = sscanf("%f%n", &float, &chars_consumed);
}

void print_mt(MultiType mt) {
    if (mt.which == NOTHING) {
        printf("nothing");
    } else if (mt.which == AN_INT) {
        printf("%d", (int) mt.value.an_int);
    } else if (mt.which == A_FLOAT) {
        printf("%e", mt.value.a_float);
    } else if (mt.which == A_FRACTION) {
        printf("%d/%u", mt.value.a_fraction.numerator, mt.value.a_fraction.denominator);
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
    new.value.an_int = value;
    return new;
}

MultiType new_mt_float(float value) {
    MultiType new;
    new.which = A_FLOAT;
    new.value.a_float = value;
    return new;
}

MultiType new_mt_fraction(int32_t numerator, uint32_t denominator) {
    MultiType new;
    new.which = A_FRACTION;
    new.value.a_fraction.numerator = numerator;
    new.value.a_fraction.denominator = denominator;
    return new;
}

int main() {
    MultiType mt_array[4] = { { NOTHING } };
    mt_array[0] = new_mt_int(24);
    mt_array[1] = new_mt_int(48);
    mt_array[2] = new_mt_float(0.24);
    mt_array[3] = new_mt_fraction(-1, 12);
    printf("\n");
    print_mt_array(mt_array, 4);
}
