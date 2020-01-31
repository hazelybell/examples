#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STOP_BEFORE 7

int main() {
    for (int counter = 0; counter < STOP_BEFORE; counter++) {
        switch (counter) {
            case 0:
                printf("zero ");
                break;
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            default:
                printf("error!\n");
                goto done;
        }
    }
    done:
    printf("done \n");
    return 0;
}
