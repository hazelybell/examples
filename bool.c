#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv) {
    int a = -1;
    printf("enter a number from 0-3 ");
    scanf("%d", &a);
    if (a < 2) {
        printf("a less than two\n");
    } else if (a == 2) {
        printf("a is two\n");
    } else {
        printf("a is greater than two\n");
    }
    printf("%d\n", a < 2);
    // to fix this 4 < a && a < 10
    if ((4 < a) < 10) {
        printf("true\n");
    }
    if (true) {
        printf("true\n");
    }
    int b;
    b = (a < 8 ? 100 : 1000) * 2;
    printf("b=%d\n", b);
    return 0;
}
