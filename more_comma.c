#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    int a;
    int array[2] = { 100, 200 };
    a = (1, 2), 3;
    printf("%d\n", a);
    if (a == 2, a == 3) {
        printf("true\n");
    }
    /* In general: avoid
     * the comma operator
     * except in arrays:
     * it can be replaced by 
     * semicolons */
    int i, j;
    i = 1, j = 2;
    printf("%d %d\n", i, j);
    printf("---\n");
    i = 1;
    j = 2;
    printf("%d %d\n", i, j);
    printf("---\n");
    for (i = 0, j = 0;
         i <= j;
         i++, j = i % 4) 
    {
        printf("%d %d\n", i, j);
    }
    return 0;
}
