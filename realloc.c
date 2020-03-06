#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * realloc, in general:
 *  1. allocates new memory space
 *  2. copies the old memory to the new memory
 *  3. frees the old memory 
 * 
 * You must update your pointers with the return value
 * of realloc()!
 * Passing a NULL pointer to realloc tells it there was
 * no old memory space.
 * Giving realloc a size of 0 causes it to free the memory
 * and not allocate any new memory.
 */
/*
 * malloc(27)
 * is the same as:
 * realloc(NULL, 27)
 */

int main() {
    int * array_a = NULL;
    int * array_b = NULL;
    size_t len = 0;
    int input = 0;
    while (scanf("%d", &input) == 1) {
        len += 1;
        array_a = realloc(array_a, sizeof(int) * len);
        array_b = realloc(array_b, sizeof(int) * len);
        array_a[len-1] = input;
        array_b[len-1] = input;
        printf("array_a is %zu bytes at %p\n",
               sizeof(int) * len,
               (void *) array_a
        );
        printf("array_b is %zu bytes at %p\n",
               sizeof(int) * len,
               (void *) array_b
        );
    }
    free(array_a);
    /*
     * free(ptr) is the same as realloc(ptr, 0)
     */
    array_b = realloc(array_b, 0);
    printf("array_b is %zu bytes at %p\n",
            sizeof(int) * len,
            (void *) array_b
    );
    return 0;
}
