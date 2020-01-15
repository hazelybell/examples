#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int count_to = 4;
    // Counting from 0 to count_to-1 (3)
    for (int counter = 0; counter < count_to; counter++) {
        printf("%d ", counter);
    }
    printf("\n");
    // Counting from 1 to count_to (4)
    for (int counter = 1; counter <= count_to; counter++) {
        printf("%d ", counter);
    }
    printf("\n");
    // Counting from count_to-1 to 0
    for (int counter = count_to-1; counter >= 0; counter--) {
        printf("%d ", counter);
    }
    printf("\n");
    // Counting from count_to to 1
    for (int counter = count_to; counter >= 1; counter--) {
        printf("%d ", counter);
    }
    printf("\n");
    return 0;
}
