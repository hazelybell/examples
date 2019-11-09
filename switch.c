#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    int a = -1;
    printf("enter a number from 0-3 ");
    scanf("%d", &a);
    switch(a) {
        case 0:
            printf("zero\n");
            break;
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
        case 3:
            printf("two or three\n");
            break;
        default:
            printf("not a number from 0-3 :(\n");
    }
    return 0;
}
