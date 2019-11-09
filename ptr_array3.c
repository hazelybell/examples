#include <stdio.h>
#include <string.h>

#define LENGTH 10

typedef int mytype;

int main(int argc, char ** argv) {
    mytype a[LENGTH];
    for (size_t i = 0; i <= LENGTH; i++) {
        mytype *p1 = a + i;
        mytype *p2 = &a[i];
        char *p3 = ((char *) a) + i;
        printf("%p %p %p %lld\n",
               p1,
               p2,
               p3,
               (long long int) *p1
        );
    }
    return 0;
}


