#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    char s1[1001];
    char s2[1001];
    scanf("%1000s", s1);
    scanf("%1000s", s2);
    printf("Hello, %s!\n", s1);
    printf("Goodbye, %s!\n", s2);
    return 0;
}
