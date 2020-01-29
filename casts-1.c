#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char ** argv) {
    char c = 'a';
    printf("%hhd=%c\n", c, c);
    printf("%hhd=%c\n", toupper(c), toupper(c));
    c = getchar();
    printf("%hhd=%c", c, c);
    if (('a' <= c) && (c <= 'z')) {
        printf(" a letter between a and z!");
    }
    putchar('\n');
    return 0;
}
