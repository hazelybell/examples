#include <stdio.h>

// scanf and printf have lots of options!
// be sure to check man 3 scanf
// and man 3 printf
// for all the details, or if you need a quick reference.

int main() {
    
    int i = 7;
    unsigned int u = 20;
    long int l = 7000000000000;
    
    printf("i=%d\n*%5d*\n*%-5d*\n*%-5.3d*\n%u\n0x%x\n%ld\n", i, i, i, i, u, u, l);
    
    float f = 19238.27;
    
    printf("f=%f\n%.2f\n*%10.2f*\nf=%e\n", f, f, f, f);
    printf("hello\bu\n\a\n");
    printf("a\tb\tc\n");
    printf("\\\n%%\n\"Hello!\"\n");
    
    int input;
    int input2;
    printf("Enter two integers: ");
    scanf("%d%d", &input, &input2);
    printf("You entered: %d and %d\n", input, input2);
    
    return 0;
}
