#include <stdio.h>
#include <limits.h>

int main(int argc, char ** argv) {
    int x; int d;
    printf("Enter an integer between %d and %d: ", INT_MIN, INT_MAX);
    scanf("%d", &x);
    scanf("%d", &d);
    printf("%d * %d = %d\n",
           x,
           d,
           x * d
          );
    printf("%d / %d = %d\n",
           x,
           d,
           x / d
          );
}

// try entering -2147483648
// try the same thing with -ftrapv
