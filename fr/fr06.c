#include <stdio.h>

int main() {
    int a[3][3] = {
        { 0, 1, 2 },
        { 3, 4, 5 },
        { 6, 7, 8 },
    };
    printf("3,3 = %d\n", a[3][3]);
    printf("3,-3 = %d\n", a[3][-3]);
    printf("0,4 = %d\n", a[0][4]);
    return 0;
}

// What does this program print... and why?



