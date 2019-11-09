#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char ** argv) {
    int a = 0;
    int b = 0; // try removing this line
    while (a < 10) {
        printf("%d\n", a);
        a++;
    }
    for (int b = 0; b < 10; b++) {
        printf("%d\n", b);
    }
    printf("%d\n", b);
    return 0;
}
