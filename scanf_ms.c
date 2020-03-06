#define _POSIX_C_SOURCE 200809L
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * scanf %ms: like %s but allocates!
 * (also works for c and [)
 */

int main() {
    printf("Enter your name: ");
    char * name = NULL;
    scanf("%ms", &name);
    printf("Hello, %s!\n", name);
}
