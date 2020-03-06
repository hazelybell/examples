#define _POSIX_C_SOURCE 200809L
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is an einputample of BAD CODE!
 * Can you use valgrind and gdb 
 * to figure out what's wrong with it?
 */

int main() {
    int input;
    printf("Enter an int:\n");
    scanf("%d", &input);
    printf("%d\n", input);
    return 0;
}
