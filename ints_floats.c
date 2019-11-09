#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv) {
    // 1234 = 4*1 + 3*10 + 2*100 + 1*1000
    // 01010101 = 1*1 + 0*2 + 1*4 + 0*8 + 1*16...
    int a = 2147483648-1; // 31 bits for the number and 1 bit for sign
    printf("%d\n", a);
    unsigned int b = 4294967296-1;
    printf("%u\n", b);
    b = b + 1;
    printf("%u\n", b);
    int c = 0; // this is always going to take 4 bytes of memory
    
    float d = 16777216.0;
    // just like scientific notation: 2.1*10^9
    // 1 bit for the sign
    // 8 bits for the exponent -126 to 127 (like our 9)
    // remaining 23 bits for the fraction (like our 2.1)
    // it doesn't make sense to write 0.1 * 10^9 when you could write 1 * 10^8
    printf("%f\n", d);
    d = d + 1; // we want something like 1.000000000000000000000001 * 2^24
                // but we only get 1.00000000000000000000000 * 2^24
    printf("%f\n", d); 
    printf("%f\n", 1/0);
    return 0;
}






