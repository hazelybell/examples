#include <stdint.h>
#include <stdio.h>

#define LENGTH 5

void use_p(int * int_p) {
    // treat a pointer like an array
    // this is always what really happens when we pass an array!
    for (size_t idx = 0; idx < LENGTH; idx++) {
        printf("  int_p[%zu]   = %d\n", idx, int_p[idx]);
        printf(" &int_p[%zu]   = %p\n", idx, (void *) &int_p[idx]);
        printf("  int_p + %zu  = %p\n", idx, (void *) (&int_p[0] + idx));
        printf("*(int_p + %zu) = %d\n", idx, *(int_p + idx));
    }
}

int main() {
    int array[LENGTH] = { 0 };
    
    // you can get the address of an array element just like anything else, with &
    for (size_t idx = 0; idx < LENGTH; idx++) {
        array[idx] = idx + 100;
        
        printf(" array[%zu] = %d\n", idx, array[idx]);
        printf("&array[%zu] = %p\n", idx, (void *) &array[idx]);
        printf(" array[%zu] is %zu bytes: ", idx, sizeof(array[idx]));
        for (size_t byte = 0; byte < sizeof(array[idx]); byte++) {
            printf("%p ", ((void *) &array[idx]) + byte);
        }
        printf("\n");
    }
    
    printf("\n");
    int *int_p = &array[0];
    use_p(int_p);

    printf("\n");
    const char strng[] = "Growlithe!";
    printf(" &array[0]      = %p\n", (void *) &array[0]);
    printf("(&array[0]) + 1 = %p\n", (void *) ((&array[0]) + 1));
    printf(" &strng[0]      = %p\n", (void *) &strng[0]);
    printf("(&strng[0]) + 1 = %p\n", (void *) ((&strng[0]) + 1));
    
    printf("\n");
    printf("&array     = %p (%zu)\n", &array, (size_t) &array);
    printf("&array + 1 = %p (%zu)\n", &array + 1, (size_t) (&array + 1));
    // what is the type of &array?
    // int (*)[5] !!!
    
    /* Basically, you should avoid pointer arithmetic at all costs.
     * Always use pointer[index] instead and keep track of indices,
     * not pointers!
     * Just be aware of what's really happening, behind the scenes!
     * 
     * only the following arithmetic really makes sense:
     * (and you should still avoid it)
     * pointer + offset (e.g. pointer + 2)
     * 
     * 
     * This can be done but really shouldn't!
     * pointer - pointer
     * pointer - offset (e.g. poitner - 2)
     */
    
    printf("\n");
    // how far away (in ints) is int_p2 from int_p?
    int *int_p2 = &array[2];
    printf(" int_p2 -  int_p = %zu\n", int_p2 - int_p);
    
    // Casting pointers... avoid this!
    char *char_p = (char *) int_p;
    char *char_p2 = (char *) int_p2;
    printf("char_p2 - char_p = %zu\n", char_p2 - char_p);
    
    printf("\n");
    for (size_t idx = 0; idx < LENGTH; idx++) {
        printf("  int_p[%zu]   = %d\n", idx, int_p[idx]);
    }
    // If we try to treat a pointer to the first element of an array of ints,
    // as a pointer to the first element of an array of another type,
    // things get weird!
    // We're using program memory for one thing, but then re-interpreting
    // it to mean another thing!
    for (size_t idx = 0; idx < LENGTH; idx++) {
        printf(" char_p[%zu]   = %d\n", idx, char_p[idx]);
    }
    
    printf("\n");
    // Example: re interpreting the memory storing a floating-point value as
    // a signed 32-bit integer!
    float hundred = 100.0;
    printf("hundred = %d\n", *( (int32_t *) &hundred));
}




