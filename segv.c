#define _POSIX_C_SOURCE 200809L
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is an example of BAD CODE!
 * Can you use valgrind and gdb 
 * to figure out what's wrong with it?
 */


int main() {
    size_t size;
    printf("How big?\n");
    if (scanf("%zu", &size) != 1) {
        abort();
    }

    int *array = malloc(sizeof(int) * size);
    for (size_t idx = 0; idx < size; idx++) {
        array[idx] = 0;
    }
    
    printf("%d\n", array[1000000]);
    free(array);
    return 0;
}
