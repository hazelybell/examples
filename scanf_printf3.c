#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv) {
    float f;
    printf("Enter a float: ");
    scanf("%f", &f);
    printf("You entered: %.2f\n", f);
    return 0;
}
