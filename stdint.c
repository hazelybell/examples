#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char ** argv) {
    printf("int8_t: %zu bytes %zu bits\n",                     
           sizeof(int8_t),
           sizeof(int8_t) * 8
    );
    printf("int16_t: %zu bytes %zu bits\n",                     
           sizeof(int16_t),
           sizeof(int16_t) * 8
    );
    printf("int32_t: %zu bytes %zu bits\n",                     
           sizeof(int32_t),
           sizeof(int32_t) * 8
    );
    printf("int64_t: %zu bytes %zu bits\n",                     
           sizeof(int64_t),
           sizeof(int64_t) * 8
    );
    printf("intmax_t: %zu bytes %zu bits\n",
           sizeof(intmax_t),
           sizeof(intmax_t) * 8
    );
    return 0;
}
