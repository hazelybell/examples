#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
    char a[] = "b";
    char b[] = "c";
    if (a == b) {
        printf("true\n");
    }
    printf("%d\n", strcmp(a, b));
    if (strcmp(a, b)) {
        printf("the strings are different\n");
    }
    printf("%d\n", !0);
    printf("%d\n", !293);
    return 0;
}
