#include <stdio.h>

// a global in "file scope"
// For good code, don't use these
int global_int = 100;
// visibile to all functions in this file

// the exception is constants
// use these! use them a lot!
const int CONSTANT_INT = 200;
// constants should be all caps

const double pi = 3.14;

int a_function(int a_parameter) {
    printf("In a_function:\n");
    // we can't change constants:
    // this won't compile: 
    // CONSTANT_INT += 1;
    printf("global_int=%d\n", global_int);
    global_int += 1;
    printf("global_int=%d\n", global_int);
    int local_int = 400;
    // a "static local"
    // for good code, don't use these
    static int static_local_int = 500;
    // use these though
    static const int LOCAL_CONSTANT_INT = 600;
//     LOCAL_CONSTANT_INT += 1;
    printf("local_int=%d\n", local_int);
    local_int += 1;
    printf("local_int=%d\n", local_int);
    printf("static_local_int=%d\n", static_local_int);
    static_local_int += 1;
    printf("static_local_int=%d\n", static_local_int);
    printf("LOCAL_CONSTANT_INT=%d\n", LOCAL_CONSTANT_INT);
    {
        printf("inside braces: local_int=%d\n", local_int);
        int inside_int = 900;
        printf("inside braces: inside_int=%d\n", inside_int);
    }
    if (1) {
        printf("inside braces: local_int=%d\n", local_int);
        int inside_int = 900;
        printf("inside braces: inside_int=%d\n", inside_int);
    }
    printf("inside braces: inside_int=%d\n", inside_int);

    return 600;
}

int main() {
    printf("In main:\n");
    printf("CONSTANT_INT=%d\n", CONSTANT_INT);
    printf("global_int=%d\n", global_int);
    int local_int = 300;
    printf("local_int=%d\n", local_int);
    printf("a_function=%d\n", a_function(700));
    printf("a_function=%d\n", a_function(800));
    printf("In main:\n");
    printf("CONSTANT_INT=%d\n", CONSTANT_INT);
    printf("global_int=%d\n", global_int);
    printf("local_int=%d\n", local_int);
}
