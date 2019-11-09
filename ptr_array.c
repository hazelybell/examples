#include <stdio.h>
#include <string.h>

void print_char_ptr(char *p) {
    printf("%p=%hhu '%c'\n", p, *p, *p);
}

int main(int argc, char ** argv) {
    char a[] = "Hello World!";
    printf("%s\n", a);
    print_char_ptr(a);
    printf("---\n");
    char *p = a;
    for (size_t i = 0; i <= strlen(a); i++) {
        print_char_ptr(p + i);
    }
    return 0;
}


