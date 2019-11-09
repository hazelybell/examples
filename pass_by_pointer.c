#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <stdint.h>

void swap(double * a, double * b) {
    // a and b are passed "by pointer"
    double temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char ** argv) {
    double x = 10.0;
    double y = 20.0;
    swap(&x, &y);
    printf("x: %f\n", x);
    printf("y: %f\n", y);
    return 0;
}
