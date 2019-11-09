#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <stdint.h>

void copy_array(size_t n, int from[n], int to[n]) {
    for (size_t i = 0; i < n; i++) {
        to[i] = from[i];
    }
}

void bubble_sort(size_t n, int a[n]) {
    int swapped;
    do {
        swapped = 0;
        for (size_t i = 1; i < n; i++) {
            if (a[i-1] > a[i]) {
                int temp = a[i-1];
                a[i-1] = a[i];
                a[i] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
}

void print_array(size_t n, int a[n]) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, char ** argv) {
    size_t n;
    printf("How many numbers to sort: ");
    scanf("%zu", &n);
    printf("n=%zu\n", n);
    int numbers[n];
    for (size_t i = 0; i < n; i++) {
        numbers[i] = rand()%1000;
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("---\n");
    int a[n];
    copy_array(n, numbers, a);
    bubble_sort(n, a);
    print_array(n, a);
    printf("---\n");
    return 0;
}
