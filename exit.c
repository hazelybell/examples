#include <stdio.h>
#include <stdlib.h>

void f() {
    int error_code = 23;
    exit(error_code);
    return 0;
}

int main(int argc, char ** argv) {
    char a[] = "Hello World!";
//     a[1200000] = 'X'; // cause a segfault
    printf("%s\n", a);
    f();
    printf("This won't run...\n");
    return 0;
}

// gcc --std=c99 -Wall -g -o exit exit.c && ./exit
