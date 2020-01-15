#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    int n = 4;
    // Counting from 0 to n-1 (3)
    for (int i = 0; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    // Counting from 1 to n (4)
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    // Counting from n-1 to 0
    for (int i = n-1; i >= 0; i--) {
        printf("%d ", i);
    }
    printf("\n");
    // Counting from n to 1
    for (int i = n; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
