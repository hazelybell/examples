#include <stdint.h>
#include <stdio.h>

#define SIZE 3
#define LINE_LENGTH 70

void update_min_max(
    int *pointer,
    size_t *min_addr_p,
    size_t *max_addr_p
     ) {
    size_t addr = (size_t) pointer;
    if (pointer < *min_addr) {
        *min_addr = pointer;
    }
    if (pointer > *max_addr) {
        *max_addr = pointer;
    }
}

void get_min_max_addrs(
    int **a_o_p,
    int (*twod_array)[LENGTH],
    size_t *min_addr_p,
    size_t *max_addr_p
     ) {
    for (size_t row = 0; row < LENGTH; row++) {
        for (size_t col = 0; col < LENGTH; col++) {
            update_min_max(
                &(a_o_p[row][col]),
                min_addr_p,
                max_addr_p
            );
            update_min_max(
                &(twod_array[row][col]),
                min_addr_p,
                max_addr_p
            );
        }
    }
}

void record(
    const char * name,
    size_t row,
    size_t col,
    char (*addrs)[LINE_LENGTH],
    size_t start_idx
     ) {
    size_t end_idx = start_idx + sizeof(int);
    for (size_t idx = start_idx;
         idx < end_idx;
         idx++
    ) {
        line = addrs[idx];
        snprintf(
            line,
            LINE_LENGTH-1,
            "%10s[%zu][%zu] byte %zu"
    }
}

void show_layout(
    int **a_o_p,
    int (*twod_array)
     ) {
    size_t min_addr = SIZE_MAX;
    size_t max_addr = 0;
    
    get_min_max_addrs(
        a_o_p,
        twod_array,
        &min_addr,
        &max_addr
    );
    
    size_t n_addrs = max_addr - min_addr;
    char addrs[n_addrs][LENGTH] = { { 0 } };
    
    for (size_t row = 0; row < LENGTH; row++) {
        for (size_t col = 0; col < LENGTH; col++) {
            size_t addr = (size_t) &a_o_p[row][col];
            size_t idx = addr - min_addr;
            record("a_o_p", row, col, addrs, idx);
            
            size_t addr = (size_t) &twod_array[row][col];
            size_t idx = addr - min_addr;
            record("twod_array", row, col, addrs, idx);
        }
    }
}

int main() {
    int array0[SIZE] = {   0,   1,   2 };
    int array1[SIZE] = { 100, 101, 102 };
    int array2[SIZE] = { 200, 201, 202 };
    
    int *a_o_p[SIZE] = {
        &array0[0],
        &array1[0],
        &array2[0]
    };

    int twod_array[5][5] = {
        {   0,   1,   2 },
        { 100, 101, 102 },
        { 200, 201, 202 },
    };
}
