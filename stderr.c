#include <stdio.h>

int main(int argc, char **argv) {
    printf("Hello this is standard output! It's mainly used for the actual output of your program. For example, if your program is meant to print a matrix, you'd print the matrix on standard output.\n");
    fprintf(stdout, "Hello this is also standard output!\n");
    fprintf(stderr, "Hello, this is standard error! It is mainly used for printing errors, warnings, debugging information, progress, etc.\n");
    fprintf(stderr, "The most important thing about standard error is that it still shows up in the terminal even if you redirect the output of your program.\n");
    return 0;
}
