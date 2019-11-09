#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <stdint.h>

typedef float number;
typedef unsigned long long integer;

void show_bits(number x) {
    char bit_string[65];
    if (sizeof(number) == sizeof(uint64_t)) {
        uint64_t u = *((uint64_t *) (&x));
        for (int b = 0; b < 64; b++) {
            bit_string[b] = (
                (
                    (u << b) & ((uint64_t) 1 << 63)
                ) ? '1' : '0'
            );
        }
        bit_string[64] = '\0';
        printf(
            "---\n"
            "%f %e %a\n0x%lx\n%s\n"
            "sign: %.1s exponent: %.11s\n"
            "fraction: %.52s\n",
            x, x, x,
            u,
            bit_string,
            bit_string, &bit_string[1],
            &bit_string[12]
        );
    }
    if (sizeof(number) == sizeof(uint32_t)) {
        uint32_t u = *((uint32_t *) (&x));
        for (int b = 0; b < 32; b++) {
            bit_string[b] = (
                (
                    (u << b) & ((uint32_t) 1 << 31)
                ) ? '1' : '0'
            );
        }
        bit_string[32] = '\0';
        printf(
            "---\n"
            "%f %e %a\n0x%x\n%s\n"
            "sign: %.1s exponent: %.8s\n"
            "fraction: 1.%.23s\n",
            x, x, x,
            u,
            bit_string,
            bit_string, &bit_string[1],
            &bit_string[9]
        );
    }
}

int main(int argc, char ** argv) {
    number x = 0.0;
    printf("number: %zu bytes %zu bits = %e\n",
           sizeof(number),
           sizeof(x) * 8,
           x
    );
    show_bits(0.0);
    show_bits(-0.0);
    if (-0.0) {
        printf("true");
    }
    show_bits(1.0);
    show_bits(2.0);
    show_bits(10.0);
    show_bits((number) INT8_MAX);
    show_bits((number) UINT8_MAX);
    show_bits((number) INT16_MAX);
    show_bits((number) UINT16_MAX);
    show_bits((number) INT32_MAX);
    show_bits((number) UINT32_MAX);
    show_bits((number) INT64_MAX);
    show_bits((number) UINT64_MAX);
    show_bits(FLT_MAX);
    show_bits(DBL_MAX);
    show_bits(INFINITY);
    show_bits(-INFINITY);
    show_bits(0x1p-7);
    show_bits(NAN);
    return 0;
}
