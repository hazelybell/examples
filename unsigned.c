#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>


int main(int argc, char ** argv) {
    unsigned char c = UCHAR_MAX;
    printf("char: %zu bytes %zu bits = %hhu\n",                     
           sizeof(c),
           sizeof(c) * 8,
           c
    );
    unsigned short s = USHRT_MAX;
    printf("short: %zu bytes %zu bits = %hu\n",                     
           sizeof(unsigned short),
           sizeof(unsigned short) * 8,
           s
    );
    unsigned int i = UINT_MAX;
    printf("int: %zu bytes %zu bits = %u\n",                     
           sizeof(i),
           sizeof(i) * 8,
           i
    );
    long l = LONG_MAX;
    printf("long: %zu bytes %zu bits = %lu\n",                     
           sizeof(l),
           sizeof(l) * 8,
           l
    );
    long long ll = LLONG_MAX;
    printf("long long: %zu bytes %zu bits = %llu\n",                     
           sizeof(ll),
           sizeof(long long) * 8,
           ll
    );
    return 0;
}
