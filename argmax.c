#include <stdio.h>
#include <stdlib.h>

int *argmax(int *a, int *b) {
    if (*a > *b)
        return a;
    else
        return b;
}

int main(int argc, char ** argv) {
    int m, n;
    printf("Enter two ints: ");
    if (scanf("%d%d", &m, &n) < 2)
        exit(1);
    int *a = argmax(&m, &n);
    if (a == &m) {
        printf("First int was bigger.\n");
    } else {
        printf("Second int was bigger.\n");
    }
    return 0;
}


