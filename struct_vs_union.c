#include <stdio.h>

struct uints {
    unsigned char a_char;
    unsigned short a_short;
    unsigned int an_int;
    unsigned long a_long;
};
typedef struct uints UInts;

int main() {
    UInts uints;
    uints.a_long = 0;
    printf("sizeof(uints)=%zu\n", sizeof(uints));
    printf("sizeof(uints.a_char)=%zu\n", sizeof(uints.a_char));
    printf("sizeof(uints.a_short)=%zu\n", sizeof(uints.a_short));
    printf("sizeof(uints.an_int)=%zu\n", sizeof(uints.an_int));
    printf("sizeof(uints.a_long)=%zu\n", sizeof(uints.a_long));
    printf("&uints=        %p\n", (void *) &uints);
    printf("&uints.a_char= %p\n", (void *) &(uints.a_char));
    printf("&uints.a_short=%p\n", (void *) &(uints.a_short));
    printf("&uints.an_int= %p\n", (void *) &(uints.an_int));
    printf("&uints.a_long= %p\n", (void *) &(uints.a_long));
}
