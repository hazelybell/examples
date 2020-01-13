#include <stdio.h>

union unsigned_ints {
    unsigned char c;
    unsigned short s;
    unsigned int i;
    unsigned long l;
};


int main() {
    union unsigned_ints u;
    printf("%zu bytes\n", sizeof(u));
    u.l = 0;
    printf("0x%02hhx 0x%04hx 0x%08x 0x%016lx\n", 
           u.c, u.s, u.i, u.l);
    u.l = 0xFFFFFFFFFFFFFFFF;
    printf("0x%02hhx 0x%04hx 0x%08x 0x%016lx\n", 
           u.c, u.s, u.i, u.l);
    u.c = 0;
    printf("0x%02hhx 0x%04hx 0x%08x 0x%016lx\n", 
           u.c, u.s, u.i, u.l);
    u.s = 0;
    printf("0x%02hhx 0x%04hx 0x%08x 0x%016lx\n", 
           u.c, u.s, u.i, u.l);
    u.c = 0xFF;
    printf("0x%02hhx 0x%04hx 0x%08x 0x%016lx\n", 
           u.c, u.s, u.i, u.l);
    u.i = 0;
    printf("0x%02hhx 0x%04hx 0x%08x 0x%016lx\n", 
           u.c, u.s, u.i, u.l);
    u.s = 0xFFFF;
    printf("0x%02hhx 0x%04hx 0x%08x 0x%016lx\n", 
           u.c, u.s, u.i, u.l);
    u.c = 0;
    printf("0x%02hhx 0x%04hx 0x%08x 0x%016lx\n", 
           u.c, u.s, u.i, u.l);
    u.l = 0x0123456789abcdef;
    printf("0x%02hhx 0x%04hx 0x%08x 0x%016lx\n", 
           u.c, u.s, u.i, u.l);
    return 0;
}

/* What does this program print... and why?
 */



