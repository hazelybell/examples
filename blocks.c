#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    int a = 3;
    if (0) printf("0\n");
    printf("a\n");
    if (1)
        printf("1\n");
    printf("b\n");
    if (1) {
        int a = 2;
        printf("%d\n", a);
    }
    printf("%d\n", a);
    return 0;
}
