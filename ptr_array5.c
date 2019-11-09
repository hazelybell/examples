#include <stdio.h>
#include <string.h>

#define LENGTH 10

typedef int mytype;

int main(int argc, char ** argv) {
    mytype a[LENGTH];
    for (size_t i = 0; i < LENGTH; i++) {
        *a = (mytype) i; // stored i in the first element of the array, a[0]
        // a++; // Try uncommenting this line, it will produce an error!
    }
    return 0;
}


