#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a_number = -1;
    printf("enter a number from 0-3: ");
    int scanf_result = scanf("%d", &a_number);
    if (scanf_result != 1) {
        printf("Error: didn't read a number!\n");
        abort();
    }
    
    if (a_number < 2) {
        printf("a_number less than two\n");
    } else if (a_number == 2) {
        printf("a_number is two\n");
    } else {
        printf("a_number is greater than two\n");
    }
    
    printf("(a_number < 2)=%d\n", a_number < 2);
    
    printf("(a_number == 2)=%d\n", a_number == 2);
    
    // using true and false by name: be sure to include <stdbool.h>
    printf("true=%d\n", true);
    printf("false=%d\n", false);
    
    bool lt_two = a_number < 2;
    printf("lt_two=%d\n", lt_two);
    
    printf("(lt_two): ");
    if (lt_two) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    // infinite loop:
    // while (1) {}
    // while (true) {}
    
    int lt_two_int = a_number < 2;
    printf("lt_two_int=%d\n", lt_two_int);
    
    printf("(lt_two_int): ");
    if (lt_two_int) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    // NEVER do == true, because any number that's not 0 is true.
    printf("(1 == true): %d\n", 1 == true);
    printf("(2 == true): %d\n", 2 == true);
    
    
    // to fix this 4 < a && a < 10
    printf("4 < a_number < 10: ");
    if (4 < a_number < 10) { // This is always true! Why?
    // (4 < a_number < 10)
    // (1 < 10) or (0 < 10)
    // (1) which is true
    // if we wanted to fix it:
    // if (4 < a_number && a_number < 10) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    printf("(a_number < 2 ? 111 : 222)=%d\n", (a_number < 2 ? 111 : 222));
    // operand: a_number < 2
    // operand: 111
    // operand: 222
    // Same as:
//      int meaningful_var;
//     if (a_number < 2) {
//         meaningful_var = 111;
//     } else {
//         meaningful_var = 222;
//     }
//      printf(... meaningful_var);
    return 0;
}
