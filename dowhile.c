#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_status() {
    return 0;
}

int main(int argc, char ** argv) {
    int a = 10;
    while (a < 10) {
        printf("%d\n", a);
        a++;
    }
    printf("---\n");
    do {
        printf("%d\n", a);
        a++;
    } while (a < 10);
    printf("---\n");
    printf("%d\n", a);
    printf("---\n");
    while (check_status()) {
        printf("true\n");
    }
    printf("---\n");
    while (scanf("%d", &a)) {
        printf("You entered: %d\n", a);
    }
    return 0;
}
