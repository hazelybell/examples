#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f(int x) {
    return x++;
}

int g(int x) {
    return --x;
}

int h(int x) {
    return x *= 2;
}

void usage(char * me) {
    printf("Usage: %s -f|-g|-h\n", me);
    exit(0);
}

int main(int argc, char ** argv) {
    int (*fp)(int x) = NULL;
    for (int i = 0; i < argc; i++) {
        if (strcmp("-f", argv[i]) == 0) {
            fp = &f;
        }
        else if (strcmp("-g", argv[i]) == 0) {
            fp = &g;
        }
        else if (strcmp("-h", argv[i]) == 0) {
            fp = &h;
        }
    }
    int x = 10;
    int y = fp(x);
    printf("%d %d\n", x, y);
    return 0;
}

// What does this program print when you run it...
// with -f
// with -g
// with -h
// with -f -g -h
// with no arguments
// with -x
//... and why?

// Can you fix it to call usage() when the arguments 
// are wrong?

