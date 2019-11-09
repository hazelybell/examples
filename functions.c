#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <stdint.h>

int g = 0;

void seperator() {
    printf("---\n");
}

// has to come before!
double average2(double a, double b);

double average_n(size_t n, double a[n]) {
//     printf("sizeof length: %zu\n", sizeof(a)/sizeof(a[0])); // nope, this returns the wrong answer
    printf("length: %zu\n", n);
    double accumulator = 0.0;
    for (size_t i = 0; i < n; i++) {
        accumulator += a[i];
    }
    double average 
        = accumulator/((double) n);
    a[0] = 100.0;
    return average;
}

int davids_main(int argc, char ** argv) {
    double x = 10.0;
    double y = 20.0;
    printf("average: %f\n", average2(x, y));
    printf("x: %f\n", x);
    printf("y: %f\n", y);
//     printf("b: %f\n", b); // can't do this
    seperator();
    size_t n;
    printf("Enter a positive integer: ");
    scanf("%zu", &n);
    printf("n=%zu\n", n);
    double numbers[n];
    for (size_t i = 0; i < n; i++) {
        numbers[i] = (double) i;
    }
    double average = average_n(n, numbers);
    printf("average of ints 0 through %zu: %f\n", n-1, average);
    printf("numbers[0]: %f\n", numbers[0]);    
    return 0;
}

int main(int argc, char ** argv) {
    return davids_main(argc, argv);
}

double average2(double a, double b) {
    // a and b are passed "by value"
    double average = (a + b) / 2.0;
    a += 2.0;
    return average;
}
