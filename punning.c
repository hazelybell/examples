#include <stdio.h>
#include <stdlib.h>

union pun {
    int i;
    unsigned char c[sizeof(int)];
};

void print_details(union pun p) {
    printf("You entered: %d\n", p.i);
    for (size_t i = 0; i < sizeof(int); i++) {
        printf("c[%zu]=%hhu\n", i, p.c[i]);
    }
    printf("Pointer to integer: %p\n", &p.i);
    for (size_t i = 0; i < sizeof(int); i++) {
        printf("Pointer to c[%zu]: %p\n", i, &(p.c[i]));
    }
}

int main(int argc, char **argv) {
    union pun p;
    printf("Enter an integer: ");
    int r = scanf("%d", &p.i);
    if (r != 1) exit(1);
    print_details(p);
    printf("Enter four chars: ");
    r = scanf("%hhu%hhu%hhu%hhu", &p.c[0], &p.c[1], &p.c[2], &p.c[3]);
    print_details(p);
}
