#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>


int main(int argc, char ** argv) {
    // (type you want) variable
    printf("%hhd -> %hd\n", 
           CHAR_MAX,
           (short) CHAR_MAX);
    printf("%hd -> %hhd\n",
           SHRT_MAX,
           (char) SHRT_MAX);
    short s = 127;
    printf("%hd -> %hhd\n",
           s,
           (char) s);
    s = 128;
    printf("%hd -> %hhd\n",
           s,
           (char) s);
    if (s > CHAR_MAX || s < CHAR_MIN) {
        printf("Error!\n");
    }
    // why?
    printf("0x%hx -> 0x%hhx\n",
           SHRT_MAX, 
           (char) SHRT_MAX
    );
    return 0;
}
