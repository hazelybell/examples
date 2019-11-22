#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define TO_BINARY(in, out) {\
    int len = sizeof(in) * 8;\
    for (int i = 0; i < len; i++) {\
        out[len-i-1] = (\
          (in >> (i)) & 1\
          ? '1' : '0'\
        );\
    }\
    out[len] = 0;\
}

#define PRINT_EXPR(expr) { \
    char binary[9]; \
    unsigned char r = (unsigned char) (expr);\
    TO_BINARY(r, binary);\
    printf("%29s = %3hhu 0x%02hhx 0%03hho 0b%s\n", #expr, r, r, r, binary);\
}

#define PRINT_BOOL(expr) { \
    int r = (expr) && 1;\
    printf("%29s = %5s %d\n", #expr, (r ? "true" : "false"), r);\
}

#define VANILLA (1 << 0)
#define CHOCOLATE (1 << 1)
#define STRAWBERRY (1 << 2)
#define BLUEBERRY (1 << 3)
#define CARAMEL (1 << 4)
#define BUTTERSCOTCH (1 << 5)
#define RASPBERRY (1 << 6)
#define BANANA (1 << 7)
// same as:
// #define VANILLA 1
// #define CHOCOLATE 2
// #define STRAWBERRY 4
// #define BLUEBERRY 8
// #define CARAMEL 16
// #define BUTTERSCOTCH 32
// #define RASPBERRY 64
// #define BANANA 128

union BitPacked {
    struct {
        bool b:1;
        unsigned u1:1;
        unsigned u2:2;
        unsigned u4:4;
        unsigned u8:8;
        unsigned u16:16;
    };
    unsigned int u;
};

struct flavors {
    bool vanilla:1;
    bool chocolate:1;
    bool strawberry:1;
    bool blueberry:1;
    bool caramel:1;
    bool butterscotch:1;
    bool raspberry:1;
    bool banana:1;
};

int main(int argc, char ** argv) {
    printf("Small unsigned ints:\n");
    PRINT_EXPR(1);
    PRINT_EXPR(2);
    PRINT_EXPR(3);
    PRINT_EXPR(4);
    PRINT_EXPR(5);
    PRINT_EXPR(6);
    PRINT_EXPR(7);
    PRINT_EXPR(0x8);
    PRINT_EXPR(0x9);
    PRINT_EXPR(0xa);
    PRINT_EXPR(0xb);
    PRINT_EXPR(0xc);
    PRINT_EXPR(0xd);
    PRINT_EXPR(0xe);
    
    printf("Different ways to write ints:\n");
    PRINT_EXPR(15);
    PRINT_EXPR(0xf);
    PRINT_EXPR(0x0f);
    PRINT_EXPR(017);
    PRINT_EXPR(16);
    PRINT_EXPR(0x10);
    PRINT_EXPR(020);
    PRINT_EXPR(255);
    PRINT_EXPR(0xff);
    PRINT_EXPR(0377);
    unsigned char o;
    printf("remember, assignments evaluate to the new value!\n");
    PRINT_EXPR(o = 0);
    printf("logical or:\n");
    // remember logical operators?
    PRINT_EXPR(o = o || 1);
    printf("bitwise or:\n");
    // there are also bitwise operators
    PRINT_EXPR(7 | 1);
    PRINT_EXPR(7 | 2);
    PRINT_EXPR(7 | 3);
    PRINT_EXPR(7);
    PRINT_EXPR(8);
    PRINT_EXPR(7 | 8);
    PRINT_EXPR(7 || 8);
    PRINT_EXPR(7 | 9);
    PRINT_EXPR(0x0f | 0x00);
    PRINT_EXPR(0x0f | 0x0f);
    PRINT_EXPR(0xf0);
    PRINT_EXPR(0x0f | 0xf0);
    PRINT_EXPR(0x0f | 0xff);
    PRINT_EXPR(o = o | 2);
    // and bitwise assignment operators
    printf("bitwise or assignment:\n");
    PRINT_EXPR(o |= 4);
    // logical and
    printf("logical and:\n");
    PRINT_EXPR(7 && 1);
    // bitwise and
    printf("bitwise and:\n");
    PRINT_EXPR(7 & 1);
    PRINT_EXPR(7 & 2);
    PRINT_EXPR(7 & 3);
    PRINT_EXPR(7);
    PRINT_EXPR(8);
    PRINT_EXPR(7 & 8);
    PRINT_EXPR(7);
    PRINT_EXPR(9);
    PRINT_EXPR(7 & 9);
    PRINT_EXPR(0x0f & 0x00);
    PRINT_EXPR(0x0f & 0x0f);
    PRINT_EXPR(0x0f & 0xf0);
    PRINT_EXPR(0x0f & 0xff);
    PRINT_EXPR(o = 2);
    printf("multiplication and assignment:\n");
    PRINT_EXPR(o *= 10);
    PRINT_EXPR(o);
    printf("bitwise and assignment:\n");
    PRINT_EXPR(o &= 0x03);
    // bitwise XOR
    printf("bitwise xor:\n");
    PRINT_EXPR(7 ^ 1);
    PRINT_EXPR(7 ^ 2);
    PRINT_EXPR(7 ^ 3);
    PRINT_EXPR(7 ^ 8);
    PRINT_EXPR(7);
    PRINT_EXPR(9);
    PRINT_EXPR(7 ^ 9);
    PRINT_EXPR(0x0f ^ 0x00);
    PRINT_EXPR(0x0f ^ 0x0f);
    PRINT_EXPR(0x0f ^ 0xf0);
    PRINT_EXPR(0x0f ^ 0xff);
    printf("bitwise xor assignment:\n");
    PRINT_EXPR(o ^= 0x03);
    printf("bitwise not (inversion):\n");
    PRINT_EXPR(~1);
    PRINT_EXPR(2);
    PRINT_EXPR(~2);
    PRINT_EXPR(~3);
    PRINT_EXPR(~8);
    PRINT_EXPR(~9);
    PRINT_EXPR(~15);
    PRINT_EXPR(~255);
    PRINT_EXPR(0x0f);
    PRINT_EXPR(~0x0f);
    printf("bitwise shift left:\n");
    PRINT_EXPR(1);
    PRINT_EXPR(1 << 1);
    printf("bitwise shift right:\n");
    PRINT_EXPR(2 >> 1);
    PRINT_EXPR(1 << 2);
    PRINT_EXPR(4 >> 2);
    PRINT_EXPR(0xff);
    PRINT_EXPR(0xff >> 4);
    PRINT_EXPR(0xff << 4);
    printf("xor swap trick:\n");
    uint8_t a;
    uint8_t b;
    PRINT_EXPR(a = 1);
    PRINT_EXPR(b = 3);
    PRINT_EXPR(a ^= b);
    PRINT_EXPR(b ^= a);
    PRINT_EXPR(a ^= b);
    PRINT_EXPR(a);
    PRINT_EXPR(b);
    printf("Common usage as flags:\n");
    PRINT_EXPR(VANILLA);
    PRINT_EXPR(CHOCOLATE);
    PRINT_EXPR(STRAWBERRY);
    PRINT_EXPR(BLUEBERRY);
    PRINT_EXPR(CARAMEL);
    PRINT_EXPR(BUTTERSCOTCH);
    PRINT_EXPR(RASPBERRY);
    PRINT_EXPR(BANANA);
    PRINT_EXPR(VANILLA | CHOCOLATE | CARAMEL);
    PRINT_EXPR(o = BLUEBERRY | RASPBERRY);
    PRINT_BOOL(o & VANILLA);
    PRINT_BOOL(o & CHOCOLATE);
    PRINT_BOOL(o & STRAWBERRY);
    PRINT_BOOL(o & BLUEBERRY);
    PRINT_BOOL(o & CARAMEL);
    PRINT_BOOL(o & BUTTERSCOTCH);
    PRINT_BOOL(o & RASPBERRY);
    PRINT_BOOL(o & BANANA);
    union BitPacked packed;
    PRINT_EXPR(sizeof(packed));
    PRINT_EXPR(packed.b = false);
    PRINT_EXPR(packed.b = true);
    PRINT_EXPR(packed.u1 = 0);
    PRINT_EXPR(packed.u1 = 1);
    PRINT_EXPR(packed.u2 = 3);
    PRINT_EXPR(packed.u2 = 0);
    PRINT_EXPR(packed.u4 = 0);
    PRINT_EXPR(packed.u2 += 1);
    PRINT_EXPR(packed.u2 += 1);
    PRINT_EXPR(packed.u2 += 1);
    PRINT_EXPR(packed.u2 += 1);
    PRINT_EXPR(packed.u4);
    PRINT_EXPR(packed.u4 = 0xf);
    // uh oh type punning!
    PRINT_EXPR(packed.u);
    PRINT_EXPR(sizeof(struct flavors));
    struct flavors neapolitan = { 1,1,1 };
    PRINT_EXPR(*((unsigned *) &neapolitan));
    return 0;
}
