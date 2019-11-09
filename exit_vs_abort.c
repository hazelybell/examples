#include <stdio.h>
#include <stdlib.h>

void f() {
    abort();
    exit(2);
}

int main(int argc, char **argv) {
    f();
}
