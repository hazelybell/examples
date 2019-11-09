#include <stdio.h>
#include <stdlib.h>

struct two_ints {
    int a;
    int b;
};

// Function that returns two things?
struct two_ints f() {
    struct two_ints ab = { 0, 1 };
    return ab;
}

struct array {
    int *data;
    size_t n_elements;
};


// Function that returns an array?
struct array new_array(size_t n) {
    struct array new = {
        (int *) malloc(n * sizeof(int)),
        n
    };
    for (size_t i = 0; i < n; i++) {
        new.data[i] = 0;
    }
    return new;
}

int main(int argc, char **argv) {
    printf("%d\n", f().a);
    printf("%d\n", f().b);
    struct array a = new_array(10);
}
