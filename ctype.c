#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
    char my_char = 'a';
    printf("%hhd=%c\n", my_char, my_char);
    printf("%hhd=%c\n", toupper(my_char), toupper(my_char));
    // man 3 getchar
    // why do I need to hit enter?
    my_char = getchar();
    printf("%hhd=%c", my_char, my_char);
    if (('a' <= my_char) && (my_char <= 'z')) {
        printf(" a letter between a and z!");
    }
    putchar('\n');
    return 0;
}
