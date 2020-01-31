#include <stdio.h>

#define ROWS 5
#define COLS 5

// what is this argument REALLY?
void print_array(int array[ROWS][COLS]) { // <-- same arguments
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            printf("%03d ", array[row][col]);
        }
        printf("\n");
    }
}

void init_array(int (*array)[COLS]) { // <-- same arguments
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            array[row][col] = row * 100 + col;
        }
    }
}

void array_memory(int array[][COLS]) { // <-- same arguments
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            printf("%p ", (void *) &array[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int array[ROWS][COLS] = { 0 };
    
    print_array(array);
    
    printf("\n");
    init_array(array);
    print_array(array);
    
    printf("\n");
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            printf("%p ", (void *) &array[row][col]);
        }
        printf("\n");
    }

    printf("\n");
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            printf("%zu ", (size_t) &array[row][col]);
        }
        printf("\n");
    }
    
    printf("\n");
    // so what is array[row][col] really doing?
    size_t start_byte = (size_t) &array[0][0];
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            size_t element_start_byte = 
                start_byte
                + (row * COLS * sizeof(int))
                + (col * sizeof(int));
            printf("%zu ", element_start_byte);
        }
        printf("\n");
    }
    
    printf("\n");
    // so what is array[row][col] really doing?
    int *start_p = &array[0][0];
    for (size_t row = 0; row < ROWS; row++) {
        for (size_t col = 0; col < COLS; col++) {
            int *element_p = 
                start_p
                + (row * COLS)
                + (col);
            printf("%p ", (void *) element_p);
        }
        printf("\n");
    }
    
    
    printf("\n");
    // so what type is &array?
    // int (*)[5][5]
    printf("      &array=%p\n", (void *) &array);
    // so what type is &array[0]?
    // int (*)[5]
    printf("   &array[0]=%p\n", (void *) &array[0]);
    // so what type is &array[0][0]?
    // int *
    printf("&array[0][0]=%p\n", (void *) &array[0][0]);
}

