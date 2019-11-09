#include <stdio.h>

int main(int argc, char ** argv) {
    int n;
    printf("Enter length of the array: ");
    scanf("%d", &n);
    // Declare a Variable-Length Array
    // Requires C99 or better
    int a[n];
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            printf("Left-over junk value %d in array element %d!\n", a[i], i);
            a[i] = 0;
        }
    }
    return 0;
}
