#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    int n = 7;
    for (int i = 0; i < n; i++) {
        switch (i) {
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
                break;
        }
    }
    done:
    printf("\n");
    return 0;
}
