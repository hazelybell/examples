#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    int r = rand();
    if (0 < r < 10) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}

// What does this program print... and why?

