#include <stdio.h>

int main(int argc, char ** argv) {
    int n = 0;
    printf("Enter an int: ");
    scanf("%d", &n); // makes sense?
    int *p = &n; // ptr to the first byte of n
    printf("*p=%d\n", *p);
    unsigned char *pc 
        = (unsigned char *) p;
    for (size_t i = 0;
         i < sizeof(int); i++) {
        unsigned char *bp = pc + i;
        printf("byte %zu (%p) = %hhu\n",
               i, bp, *bp);
    }
    return 0;
}



