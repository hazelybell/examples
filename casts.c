#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

int main() {
    // (type you want) variable
    printf("%hhd -> %hd\n", 
           CHAR_MAX,
           (short) CHAR_MAX);
    printf("%hd -> %hhd\n",
           SHRT_MAX,
           (char) SHRT_MAX);
    // 2^7 = 128 = 0x80
    // 2^7 - 1 = 127 = 0x7f
    short s7f = 127;
    printf("%hd -> %hhd\n",
           s7f,
           (char) s7f);
    short s80 = 128;
    printf("%hd -> %hhd\n",
           s80,
           (char) s80);
    if (s80 > CHAR_MAX || s80 < CHAR_MIN) {
        printf("Error!\n");
    }
    // why?
    printf("0x%hx -> 0x%hhx\n",
           SHRT_MAX, 
           (char) SHRT_MAX
    );
    return 0;
}
