#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

void make_sla() {
    // the length of this array is known at "compile time"
    // Remember: C uses {} for initializers
    int sla[LENGTH] 
        = { 0, 1, 2, 3, 4 };
    
    for (size_t index = 0; index < LENGTH; index++) {
        printf("sla[%zu]=%d\n", index, sla[index]);
    }
}

void partial_initializer() {
    // the length of this array is known at "compile time"
    // Remember: C uses {} for initializers
    char sla[LENGTH] = { 123 };
    
    for (size_t index = 0; index < LENGTH; index++) {
        printf("sla[%zu]=%hhd\n", index, sla[index]);
    }
}

void make_vla() {
    // the length of this array isn't know at compile time!
    
    size_t user_length = 0;
    int scanned = 0;
    printf("How long should the array be? ");
    scanned = scanf("%zu", &user_length);
    if (scanned != 1) {
        printf("scanned=%d\n", scanned);
        printf("Error: couldn't read array size!\n");
        exit(1);
    }

    // We can't initialize it with { }
    // declaration has to come AFTER we know how long its going to be
    int vla[user_length];
    
    // So we intitialize it with an idiomatic for loop
    for (size_t index = 0; index < user_length; index++) {
        vla[index] = index;
    }
    // If you're doing something that uses the size of something use, size_t
    // Here it's the number of elements in the array, an d indexing into an array!
    
    
    for (size_t index = 0; index < user_length; index++) {
        printf("vla[%zu]=%d\n", index, vla[index]);
    }
}

int main() {
    make_sla();
    partial_initializer();
    make_vla();
}
