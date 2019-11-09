#include <stdio.h>
#include <stdlib.h>

// This example demonstrates the differences between two-d arrays, arrays of arrays and pointers

#define N 5

void should_be_true(int x) {
    if (!x) abort();
}

void f(int a[N][N]);

int main(int argc, char **argv) {
    int twod_array[N][N]; // an NxN two-dimensional array of ints (NOT a pointer)
    int (*row_ptr)[N]; // a pointer to a row of ints with N columns
    int *array_of_ptrs[N]; // an array of pointers to ints (NOT a pointer)
    int **ptr_ptr; // a pointer to a pointer to an int
    
    // initialize our 2-d array to something
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            twod_array[i][j] = rand();
        }
    }
    
    printf("twod_array is @ %p\n", twod_array); // twod_array is not a pointer, but it's being silenly converted to one here!
    
    // *twod_array; // twod_array is not a pointer, but it's being silently converted to one here!
    
//     twod_array += 1; // this line will give a compile error. 
    // twod_array is not a pointer, so we can't change it!

    row_ptr = twod_array; // this is correct: silently convert twod_array to a pointer to it's first row and store that pointer
    should_be_true(
        row_ptr == 
         (int (*)[N]) &twod_array
    ); // same as this, isn't it?
    should_be_true(
        row_ptr == &twod_array[0]
    ); // same thing again
    should_be_true(
        row_ptr == 
            (int (*)[N]) &twod_array[0][0]
    ); // same thing again
    
    // Initialize our array of pointers
    for (size_t i = 0; i < N; i++) {
        array_of_ptrs[i] 
            = &(twod_array[i][0]);
        // get a pointer to the first element of the ith row of twod_array
        // it's a pointer to an int so we can put it in our array of pointers to ints
    }
    
    ptr_ptr = array_of_ptrs;
    should_be_true(
        ptr_ptr == 
            (int **) &array_of_ptrs
    ); // this looks familiar...
    should_be_true(
        ptr_ptr == &(array_of_ptrs[0])
    ); // this looks familiar...
    
    // Now they can all be used with [i][j]...
    // twod_array[i][j] is the same as row_ptr[i][j] is the same as array_of_ptrs[i][j] is the same as ptr_ptr[i][j]
    // HOWEVER we get to the same element in four different ways...
    // and this depends on the pointers being correctly initialized!
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            should_be_true(
                twod_array[i][j]
                == row_ptr[i][j]
            );
            should_be_true(
                twod_array[i][j]
                == array_of_ptrs[i][j]
            );
            should_be_true(
                twod_array[i][j]
                == ptr_ptr[i][j]
            );
        }
    }
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            should_be_true(
                &(twod_array[i][j])
                == &(row_ptr[i][j])
            );
            should_be_true(
                &(twod_array[i][j])
                == &(array_of_ptrs[i][j])
            );
            should_be_true(
                &(twod_array[i][j])
                == &(ptr_ptr[i][j])
            );
        }
    }
    
    // In fact &twod_array &twod_array[0]  and &twod_array[0][0] are all pointers to the same location in memory BUT they have different types!
    
    should_be_true(
        &twod_array[0][0] ==
            (int *) &twod_array[0]
    );
    should_be_true(
        &twod_array[0][0] ==
            (int *) &twod_array
    );
    
    // That's definitely not true for ptr_ptr... they're all different pointers!
    should_be_true(
        &ptr_ptr[0][0] !=
            (int *) &ptr_ptr[0]
    );
    should_be_true(
        &twod_array[0][0] !=
            (int *) &ptr_ptr
    );
    
    // It's half-true for the others...
    should_be_true(
        &row_ptr[0][0] == 
            (int *) &row_ptr[0]
    );
    should_be_true(
        &row_ptr[0][0] != 
            (int *) &row_ptr
    );
    
    should_be_true(
        &array_of_ptrs[0] == 
            (int **) &array_of_ptrs
    );
    should_be_true(
        &array_of_ptrs[0][0] != 
            (int *) &array_of_ptrs
    );
    
    // Another difference is in the sizes...
    
    should_be_true(
        sizeof(twod_array)
            == N * N * sizeof(int)
    );
    should_be_true(
        sizeof(row_ptr) == sizeof(void *)
    );
    should_be_true(
        sizeof(array_of_ptrs) 
            == N * sizeof(void *)
    );
    should_be_true(
        sizeof(ptr_ptr) == sizeof(void *)
    );
    
    f(twod_array); // It looks like we are passing a 2-D array to the function f, but we're not actually! The array is silently being converted to a pointer to the first thing in the array. In this case, the first row in the 2-D array.
    f((int (*)[N]) twod_array); // This is the exact same thing as the previous line!
}

void f(int a[N][N]) {
    // is a really a 2-D array?
    // if a is really a 2-D array, then it will have the same properties of twod_array in main...
    // specifically, &a &a[0] and &a[0][0] would all be pointers to the same location in memory...
    // but a is a parameter of f!
    // which means it's actually like row_ptr, not like twod_array, even though it looks like twod_array.
    
    should_be_true(
        &a[0][0] == 
            (int *) &a[0]
    );
    should_be_true(
        &a[0][0] != 
            (int *) &a
    );
    
    // Plus, we can change the value of a, which is definitely not something we can do with actual arrays...
    
    a += 1;
    
    // It's also exactly as big as any other pointer to any other data
    // In fact, gcc will give us a handy warning, reminding us that we can't use sizeof here to find the size of the array
    should_be_true(
        sizeof(a) == sizeof(void *)
    );
}
