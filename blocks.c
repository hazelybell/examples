#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int some_num = 3;
    
    printf("Will print 0 if 0 is true:\n");
    if (0) printf("0\n");
    
    printf("Will print 1 if 1 is true:\n");
    if (1)
        printf("1\n");
    
    if (2) printf("2 is true\n");
    else printf("2 is false\n");
    
    printf("------------------------------\n");
    
    printf("outside of if some_num=%d\n", some_num);
    if (1) {
        int some_num = 2;
        printf("inside of if some_num=%d\n", some_num);
    }
    printf("outside of if some_num=%d\n", some_num);
    
    return 0;
}
