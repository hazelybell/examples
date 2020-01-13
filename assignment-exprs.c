#include <stdio.h>

int main() {
    int an_int = 5;
    printf("an_int=%d\n", an_int);
    // We can use an assignment as an expression!
    printf("(an_int = 2)=%d\n", an_int = 2);
    printf("(an_int = 5) > 5: ");
    if ((an_int = 5) > 5) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("an_int=%d\n", an_int);
    printf("(an_int *= 3) > 5: ");
    if ((an_int *= 3) > 5) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    // If you really want to do this put double parentheses so the compiler knows its really what you wanted
    if ((an_int = 4)) {
        printf("u wot m8?\n");
    }
    return 0;
}
