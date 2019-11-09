#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    printf("Enter a string: ");
    char *s;
    scanf("%ms", &s);
    printf("You entered: %s\n", s);
    printf("Length: %zu\n", strlen(s));
    free(s); // don't forget to free
    return 0;
}
