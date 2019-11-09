#include <stdio.h>
#include <string.h>

int r(int depth);

int s(int depth) {
    return r(depth+1);
}

int r(int depth) {
    return s(depth+1);
}

int main(int argc, char ** argv) {
    printf("%d\n", r(1));
    return 0;
}


