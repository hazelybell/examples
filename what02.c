#include <stdio.h>

int main(int argc, char ** argv) {
    printf("Enter an integer: ");
    int x;
    scanf("%d", &x);
    if (x % 2 == 1) {
        printf("You entered an odd number.\n");
    } else {
        printf("You entered an even number.\n");
    }
    return 0;
}
