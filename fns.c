#include <stdio.h>


#define LENGTH 1


// what is the difference here?
void callee(int value, int array[]) {
// exactly the same as: void callee(int value, int* array) {
    // inside this function we have NO IDEA how big array[] is
    value += 1;
    array[0] += 1;
    printf("elts in array: %zu\n", sizeof(array)/sizeof(array[0]));
}

// void fns don't return anything
void caller() {
    int value = 5;
    int array[LENGTH] = { 5 };
    
    printf("value = %d\n", value);
    printf("array[0] = %d\n", array[0]);
    // %zu prints out a size_t
    // we have no len()
    // sizeof(array)/sizeof(array[0]) is as close as we get but...
    // it only works in the SAME FUNCTION
    // and you should use it
    // you should always ALREADY KNOW how long your array is (in another variable, using #define, etc.)
    printf("elts in array: %zu\n", sizeof(array)/sizeof(array[0]));
    
    // hidden conversion of array to an (int *)
    callee(value, array);

    printf("value = %d\n", value);
    printf("array[0] = %d\n", array[0]);
}

// you can also specify void in the arguments list, this is the same as specifing no arguments like
// double trouble() {
double trouble(void) {
    printf("Here comes trouble!\n");
    return 2.0;
}

double double_(double amount) {
    printf("Make it double! %e\n", amount);
    return amount * 2.0;
}

// you cannot return an array!
// int[5] ret_array() {
//     int array[5] = { 0, 1, 2, 3, 4 };
//     return array;
// }

// this returns a copy of the 1st element 
int make_array() {
    int array[5] = { 100, 200, 300, 400, 500 };
    return array[0];
}

int main() {
    printf("caller():\n");
    caller();
    printf("trouble():\n");
    double_(trouble());
    int retval = make_array();
    // prevent the compiler from complaining...
    // ...but avoid doing this.
    (void) retval;
}

