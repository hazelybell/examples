#include <stdio.h>

int pbv(int passed) {
    passed++;
    printf("   passed = %d\n", passed);
    printf("  &passed = %p\n", (void *) &passed);
    return passed;
}

void pbr(int *passed) {
    printf("   passed = %p\n", (void *) passed);
    printf("  *passed = %d\n", *passed);
    printf("  &passed = %p\n", (void *) &passed);
    (*passed)++;
}

/*
 * 4 byte integer (32-bit PC)
 * Example: our integer uses these 4 bytes
 * byte 4287409512 (0xff8cad68)
 * byte 4287409513 (0xff8cad69)
 * byte 4287409514 (0xff8cad6a)
 * byte 4287409515 (0xff8cad6b)
 */

int main() {
    int thing_1 = 100;
    int thing_2 = 200;

    // type: define a_pointer as a pointer to an int
    int *a_pointer = NULL;
    // type of a_pointer is "int *"
    // NULL: the NULL pointer, gives the pointer the value 0
    // used to indicate that the pointer doesn't point to anything
    
    printf("thing_1 = %d\n", thing_1);
    printf("thing_2 = %d\n", thing_2);
    printf("a_pointer = %p\n", (void *) a_pointer);
    printf("a_pointer = %zu\n", (size_t) a_pointer);
    
    printf("\nsizes:\n");
    printf("sizeof(thing_1) = %zu\n", sizeof(thing_1));
    printf("sizeof(thing_2) = %zu\n", sizeof(thing_2));
    printf("sizeof(a_pointer) = %zu (%zu bits)\n", sizeof(a_pointer), sizeof(a_pointer) * 8);

    // unary & operator: get address of (reference)
    a_pointer = &thing_1;
    
    printf("\na_pointer = &thing_1;\n");
    printf(" &thing_1 = %p\n", (void *) &thing_1);
    printf(" &thing_2 = %p\n", (void *) &thing_2);
    printf("a_pointer = %p\n", (void *) a_pointer);
    printf("a_pointer = %zu\n", (size_t) a_pointer);
    // unary * operator: get value at (dereference)
    printf("*a_pointer = %d\n", *a_pointer);

    a_pointer = &thing_2;
    printf("\na_pointer = &thing_2;\n");
    printf("a_pointer = %p\n", (void *) a_pointer);
    // unary * operator: get value at (dereference)
    printf("*a_pointer = %d\n", *a_pointer);
    
    printf("\ncopy value:\n");
    printf("\nint value = thing_1;\n");
    int value = thing_1;
    printf("thing_1 = %d\n", thing_1);
    printf("  value = %d\n", value);
    printf(" &thing_1 = %p\n", (void *) &thing_1);
    printf("   &value = %p\n", (void *) &value);

    printf("\ncopy value using pointer:\n");
    printf("\nvalue = *(&thing_2);\n");
    value = *(&thing_2);
    printf("thing_2 = %d\n", thing_2);
    printf("  value = %d\n", value);
    printf(" &thing_2 = %p\n", (void *) &thing_2);
    printf("   &value = %p\n", (void *) &value);
    
    printf("\ncopy value using pointer:\n");
    a_pointer = &thing_2;
    printf("\na_pointer = &thing_2;\n");
    printf("a_pointer = %p\n", (void *) a_pointer);
    // unary * operator: get value at (dereference)
    printf("*a_pointer = %d\n", *a_pointer);
    printf("value = *a_pointer;\n");
    value = *a_pointer;
    printf("thing_2 = %d\n", thing_2);
    printf("  value = %d\n", value);
    printf(" &thing_2 = %p\n", (void *) &thing_2);
    printf("   &value = %p\n", (void *) &value);

    printf("\npass-by-value (copy):\n");
    printf("\npbv(thing_1);\n");
    printf("  thing_1 = %d\n", thing_1);
    printf(" &thing_1 = %p\n", (void *) &thing_1);
    pbv(thing_1);
    printf("  thing_1 = %d\n", thing_1);
    printf(" &thing_1 = %p\n", (void *) &thing_1);
    
    printf("\npass-by-reference (no copy):\n");
    printf("\npbr(&thing_1);\n");
    printf("  thing_1 = %d\n", thing_1);
    printf(" &thing_1 = %p\n", (void *) &thing_1);
    pbr(&thing_1);
    printf("  thing_1 = %d\n", thing_1);
    printf(" &thing_1 = %p\n", (void *) &thing_1);

    return 0;
}

