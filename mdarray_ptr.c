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
    
    
    printf("  array_p = %p\n", (void *) array_p);
    printf("    tab_p = %p\n", (void *) tab_p);
    printf("    row_p = %p\n", (void *) row_p);
    printf("element_p = %p\n", (void *) element_p);

    printf("  array_p = %p\n", (void *) (array_p + 1));
    printf("    tab_p = %p\n", (void *) (tab_p + 1));
    printf("    row_p = %p\n", (void *) (row_p + 1));
    printf("element_p = %p\n", (void *) (element_p + 1));

    // these all refer to the same int in memory
    array_p[0][0][0][1];
    tab_p[0][0][1];
    row_p[0][1];
    element_p[1];
    
    /*
     * FIRST 4 BYTES ARRAY[0][0][0]
     * NEXT 4 BYTES ARRAY[0][0][1]
     * ...
     * ARRAY[0][1][0]
     * ..
     * ARRAY[1][0][0]
     */
    
}
