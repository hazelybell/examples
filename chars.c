#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // <--- _MIN/_MAX
#include <float.h>
#include <stdint.h>

int main() {
    signed char scmax = SCHAR_MAX;
    signed char scmin = SCHAR_MIN;
    printf("signed char: %hhd to %hhd\n",
           scmin,
           scmax
    );
    unsigned char ucmax = UCHAR_MAX;
    unsigned char ucmin = 0;
    printf("UNsigned char: %hhu to %hhu\n",
           ucmin,
           ucmax
    );
    char cmax = CHAR_MAX;
    char cmin = CHAR_MIN;
    printf("plain char: %hhd to %hhd\n",
           cmin,
           cmax
    );
    if (cmin == 0) {
        printf("By default, char is UNsigned!\n");
    } else if (cmin < 0) {
        printf("By default, char is signed!\n");
    } else {
        printf("Error!\n");
        abort();
    }
    return 0;
}
