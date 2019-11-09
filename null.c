#include <stdio.h>

int main(int argc, char **argv) {
    printf("NULL: %p\n", NULL);
    printf("NULL: %llu\n", (long long unsigned) NULL);
    char *s = NULL;
    printf("%c\n", s[0]);
    return 0;
}
