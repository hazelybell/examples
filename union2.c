#include <stdio.h>
#include <stdint.h>
#include <limits.h>

typedef union {
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    uint64_t u64;
} UInts;

void print_uints(UInts uints) {
    printf("uints.u8 =%14s0x%02hhx (=%hhu)\n", "", uints.u8, uints.u8);
    printf("uints.u16=%12s0x%04hx (=%hu)\n", "", uints.u16, uints.u16);
    printf("uints.u32=%8s0x%08x (=%u)\n", "", uints.u32, uints.u32);
    printf("uints.u64=0x%016lx (=%lu)\n", uints.u64, uints.u64);
}

int main() {
    UInts uints;
    
    uints.u64 = 0;
    print_uints(uints);
    
    uints.u8 = 0xff;
    printf("\n      uints.u8 = 0xff;\n");
    print_uints(uints);
    
    uints.u16 = 0xffff;
    printf("\n      uints.u16 = 0xffff;\n");
    print_uints(uints);
    
    uints.u8 = 0x0;
    printf("\n      uints.u8 = 0x0;\n");
    print_uints(uints);
    
    uints.u32 = 0xffffffff;
    printf("\n      uints.u32 = 0xffffffff;\n");
    print_uints(uints);
        
    uints.u16 = 0;
    printf("\n      uints.u16 = 0x0000;\n");
    print_uints(uints);    

    uints.u8 = 0xff;
    printf("\n      uints.u8 = 0xff;\n");
    print_uints(uints); 
    
    uints.u64 = 0xffffffffffffffff;
    printf("\n      uints.u64 = 0xffffffffffffffff;\n");
    print_uints(uints); 

    uints.u32 = 0x0;
    printf("\n      uints.u32 = 0x0;\n");
    print_uints(uints);

    uints.u16 = UINT16_MAX;
    printf("\n      uints.u16 = UINT16_MAX;\n");
    print_uints(uints);
    
    uints.u8 = 0x0;
    printf("\n      uints.u8 = 0x0;\n");
    print_uints(uints);
}
