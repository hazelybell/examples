#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_array(size_t n, int from[n], int to[n]) {
    for (size_t i = 0; i < n; i++) {
        to[i] = from[i];
    }
}

void bubble_sort(size_t n, int a[n]) {
    unsigned long comparisons = 0;
    int swapped;
    do {
        swapped = 0;
        for (size_t i = 1; i < n; i++) {
            comparisons++;
            if (a[i-1] > a[i]) {
                int temp = a[i-1];
                a[i-1] = a[i];
                a[i] = temp;
                swapped = 1;
            }
        }
    } while (swapped);
    printf("Comparisons: %lu\n",             
           comparisons); 
}

void print_array(size_t n, int a[n]) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertion_sort(size_t n, int a[n]) {
    unsigned long comparisons = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i; j > 0; j--) {
            comparisons++;
            if (a[j-1] > a[j]) {
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            } else {
                break;
            }
        }
    }
    printf("Comparisons: %lu\n",             
           comparisons); 
}

unsigned long quicksort_r(
    size_t n, int a[n],
    size_t left, size_t right) {
    size_t partition;
    unsigned long comparisons = 0;
    if (left < right) {
        size_t middle = 
            left + (right - left) / 2;
        int pivot = a[middle];
        int i = left - 1;
        int j = right + 1;
        while (1) {
            do {
                i++;
                comparisons++;
            } while (a[i] < pivot);
            do {
                j--;
                comparisons++;
            } while (a[j] > pivot);
            if (i >= j) {
                partition = j;
                break;
            }
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        comparisons += 
        quicksort_r(n, a, left, partition);
        comparisons +=
        quicksort_r(n, a, partition+1, right);
        return comparisons;
    }
    return 0;
}

void quicksort(size_t n, int a[n]) {
    unsigned long comparisons;
    comparisons = quicksort_r(n, a, 0, n-1);
    printf("Comparisons: %lu\n", comparisons);            
}

unsigned long mergesort(size_t n, int a[n]) {
    if (n < 2) return 0;
    unsigned long comparisons = 0;
    size_t ln = n / 2;
    comparisons += mergesort(ln, a); 
    size_t rn = n / 2 + n % 2;
    comparisons += mergesort(rn, a + ln);
    int b[n];
    size_t i = 0;
    size_t j = ln;
    size_t k = 0;
    while (i < ln && j < n) {
        comparisons++;
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i < ln) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j < n) {
        b[k] = a[j];
        j++;
        k++;
    }
    for (k = 0; k < n; k++) {
        a[k] = b[k];
    }
    return comparisons;
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
    int a[n];
    for (size_t i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-b")) {
            printf("--- Bubble sort:\n");
            copy_array(n, numbers, a);
            bubble_sort(n, a);
            print_array(n, a);
        } else if (!strcmp(argv[i], "-i")) {
            printf("--- Insertion sort:\n");
            copy_array(n, numbers, a);
            insertion_sort(n, a);
            print_array(n, a);
        } else if (!strcmp(argv[i], "-q")) {
            printf("--- Quick sort:\n");
            copy_array(n, numbers, a);
            quicksort(n, a);
            print_array(n, a);
        } else if (!strcmp(argv[i], "-m")) {
            printf("--- Merge sort:\n");
            copy_array(n, numbers, a);
            unsigned long comparisons = mergesort(n, a);
            printf("Comparisons: %lu\n", comparisons);            
            print_array(n, a);
        } else {
            printf("Unknown argument: %s\n", argv[i]);
            exit(1);
        }
    }
    return 0;
}
