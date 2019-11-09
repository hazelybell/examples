/* Items to review: 
 * logical operators
 * scanf
 * void
 * exit
 * passing arrays to functions
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it!
 * Try entering sequences of numbers with 
 * an odd number of elements and an even
 * number of elements!
 */

#include <stdio.h>
#include <stdlib.h>

void reverse(unsigned long n, int a[n]) {
    for (unsigned long i = 0; i < n/2; i++) {
        int temp = a[i];
        a[i] = a[n - i - 1]; // why is it 'n - i - 1'?
        a[n - i - 1] = temp;
    }
}

int main(int argc, char ** argv) {
    unsigned long n;
    printf("How many numbers would you like to reverse? ");
    if (!scanf("%lu", &n)) {
        return 1;
    }
    int a[n];
    for (unsigned long i = 0; i < n; i++) {
        a[i] = rand() % 99;
        printf("%d ", a[i]);
    }
    printf("\n");
    reverse(n, a);
    for (unsigned long i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}



