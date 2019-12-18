#include <stdio.h>

int main() {
    printf("%zu ", sizeof(double));
    printf("%zu ", sizeof(float));
    printf("%zu ", sizeof('c'));
    printf("%zu ", sizeof("c"));
    printf("%zu ", sizeof(void *));
    printf("\n");
    return 0;
}

// What does this program print... and why?

// What is the type of 'c'?

// What is the type of "c"?



