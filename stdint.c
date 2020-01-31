#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* For more info:
 * https://en.cppreference.com/w/c/types/integer
 */

int main() {
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
    printf("int_fast8_t: %zu bytes %zu bits\n",
           sizeof(int_fast8_t),
           sizeof(int_fast8_t) * 8
    );
    printf("int_fast16_t: %zu bytes %zu bits\n",
           sizeof(int_fast16_t),
           sizeof(int_fast16_t) * 8
    );
    return 0;
}
