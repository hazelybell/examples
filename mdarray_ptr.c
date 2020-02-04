#include <stdio.h>

#define TABS 10
#define ROWS 11
#define COLS 12

int main() {
    int array[TABS][ROWS][COLS] = { { { 0 } } };
    
    int (*array_p)[TABS][ROWS][COLS] = &array;
    
    int (*tab_p)[ROWS][COLS] = array; // same as = &array[0]
    
    int (*row_p)[COLS] = array[0]; // same as = &array[0][0]
    
    int *element_p = array[0][0]; // same as = &array[0][0][0]
    
    /*
     * FIRST 4 BYTES ARRAY[0][0][0]
     * NEXT 4 BYTES ARRAY[0][0][1]
     * ...
     * ARRAY[0][1][0]
     * ..
     * ARRAY[1][0][0]
     */
    
}
