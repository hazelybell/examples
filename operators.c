#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int a = 10;
    long b = 5;
    printf("%ld\n", a + b);
    // because we're adding two different types,
    // first C will convert a to a long
    // then it will add
    // the result will be a long
    int c = 10;
    int d = 5;
    int e = 2;
    printf("%d\n", c + d * e); // multiplication is performed before addition
    c = c + 1;
    c += 1; // these four do the same thing
    c++;
    ++c;
    printf("%d\n", c);
    printf("%d\n", c++); // increment and return old value
    printf("%d\n", c);
    printf("%d\n", ++c); // increment and return new value
    printf("---\n");
    printf("%d\n", c);
    c += c++;
    printf("%d\n", c);
    printf("%d\n", c % 2);
    if (0) {
        printf("0 is true\n");
    } else {
        printf("0 is false\n");
    }
    if (129) {
        printf("129 is true\n");
    } else {
        printf("129 is false\n");
    }
    printf("%d\n", 3 < 2);
    printf("%d\n", 3 > 2);
    printf("%d\n", 3 > 2 && 1 > 0); // "and"
    printf("%d\n", 3 > 2 || 1 > 0); // "or"
    printf("%d\n", ! (3 > 2 || 1 > 0)); // "not or"
    return 0;
}
