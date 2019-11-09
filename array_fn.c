#include <stdio.h>
#include <string.h>

void f1(char a[13]) {
    a++; // a is a pointer
    printf("%p=%hhu '%c'\n", a, *a, *a);
}

int main(int argc, char ** argv) {
    char a[13] = "Hello World!";
    // a is an array
    f1(a);
    return 0;
}


