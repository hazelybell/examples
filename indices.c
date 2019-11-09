#include <stdio.h>
#include <stdlib.h>

// This shows that C does not check your index (subscripts)

int main(int argc, char **argv) {
    int a[5][5] = {
        { 0, 1, 2, 3, 4 },
        { 5, 6, 7, 8, 9 },
        { 10, 11, 12, 13, 14 },
        { 15, 16, 17, 18, 19 },
        { 20, 21, 22, 23, 24 }
    };
    printf("%d\n", a[-2][10]);
    return a[-5][25];
}
