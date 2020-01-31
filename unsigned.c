#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>


int main() {
    unsigned char c = UCHAR_MAX;
    printf("char: %zu bytes %zu bits max %hhu\n",                     
           sizeof(c),
           sizeof(c) * 8,
           c
    );
    unsigned short s = USHRT_MAX;
    printf("short: %zu bytes %zu bits max %hu\n",                     
           sizeof(unsigned short),
           sizeof(unsigned short) * 8,
           s
    );
    unsigned int i = UINT_MAX;
    printf("int: %zu bytes %zu bits max %u\n",                     
           sizeof(i),
           sizeof(i) * 8,
           i
    );
    unsigned long l = ULONG_MAX;
    printf("ulong: %zu bytes %zu bits max %lu\n",                     
           sizeof(l),
           sizeof(l) * 8,
           l
    );
    unsigned long long ll = ULLONG_MAX;
    printf("long long: %zu bytes %zu bits max %llu\n",                     
           sizeof(ll),
           sizeof(long long) * 8,
           ll
    );
    size_t z = SIZE_MAX;
    printf("size_t: %zu bytes %zu bits max %zu\n",                     
           sizeof(z),
           sizeof(z) * 8,
           z
    );
    return 0;
}
