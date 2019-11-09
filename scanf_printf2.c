#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int input = 0;
    int input2 = 0;
    printf("Enter a fraction: ");
    int items_read = scanf("%d/%d", &input, &input2);
    if (items_read != 2) {
        printf("You didn't enter a recognizable fraction!\n");
        exit(1);
    }
    printf("Successfully read %d items\n", items_read);
    printf("You entered: %d and %d\n", input, input2);
    printf("decimal: %f\n", ((float) input)/((float) input2));
    return 0;
}
