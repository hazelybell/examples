#include <stdio.h>

#define LENGTH 5

int main() {
    int sla[LENGTH] 
        = { 0, 1, 2, 3, 4 };
/* "int sla[LENGTH]" read "sla is an array of 5 ints"
 * but if we try to pass it to another function
 * it becomes "int *" read "pointer to an int"
 * This is the same as explicitly casting it:
 * e.g. (int *) sla
 */
    // Gives warning:
    printf("sla as a pointer: %p\n", sla);
    printf("sla as a pointer: %p\n", (void *) sla);
    
    int *ptr_to_int = sla;
    
    // Gives warning:
    printf("sla as a pointer: %p\n", ptr_to_int);
    printf("sla as a pointer: %p\n", (void *) ptr_to_int);
    
    printf("What's it point to? %d\n", *ptr_to_int);
    printf("What's it point to? %d\n", ptr_to_int[0]);

/* Note: You CANNOT cast to an array!
 * You cannot specify the array type without a name!
 * You cannot copy the array either!
 */
//     int sla2[LENGTH] = sla;

    return 0;
}

