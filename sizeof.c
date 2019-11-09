#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>


int main(int argc, char ** argv) {
    char c = CHAR_MAX;
    printf("char: %zu bytes %zu bits = %hhd\n",                     
           sizeof(char),
           sizeof(char) * 8,
           c
    );
    short s = SHRT_MAX;
    printf("short: %zu bytes %zu bits = %hd\n",                     
           sizeof(short),
           sizeof(short) * 8,
           s
    );
    int i = INT_MAX;
    printf("int: %zu bytes %zu bits = %d\n",                     
           sizeof(int),
           sizeof(int) * 8,
           i
    );
    long l = LONG_MAX;
    printf("long: %zu bytes %zu bits = %ld\n",                     
           sizeof(long),
           sizeof(long) * 8,
           l
    );
    long long ll = LLONG_MAX;
    printf("long long: %zu bytes %zu bits = %lld\n",                     
           sizeof(long long),
           sizeof(long long) * 8,
           ll
    );
    float f = FLT_MAX;
    printf("float: %zu bytes %zu bits = %e\n",
           sizeof(float),
           sizeof(float) * 8,
           f
    );
    double d = DBL_MAX;
    printf("double: %zu bytes %zu bits = %e\n",
           sizeof(double),
           sizeof(double) * 8,
           d
    );
    long double ld = LDBL_MAX;
    printf("long double: %zu bytes %zu bits = %Le\n",
           sizeof(long double),
           sizeof(long double) * 8,
           ld
    );
    size_t z = SIZE_MAX;
    printf("size_t: %zu bytes %zu bits = %zu\n",
           sizeof(size_t),
           sizeof(size_t) * 8,
           z
           
    );
    printf("char **: %zu bytes %zu bits = %p\n",
           sizeof(argv),
           sizeof(argv) * 8,
           argv
    );
    // Types vary by platform!?
    // Use sizeof to determinie size of an array
    char ca[50] = "Hello world!";
    printf("Array length: %zu, string length: %zu = %s\n", 
           sizeof(ca)/sizeof(ca[0]), strlen(ca),
           ca
    );
    char cu[] = "Hello world 1.5!";
    printf("Array length: %zu, string length: %zu = %s\n", 
           sizeof(cu)/sizeof(cu[0]), strlen(cu),
           cu
    );
    // vvvv This doesn't work!
     char * cp = "Hello world 2.0!";
     printf("cp length: %zu, string length: %zu = %s\n", 
            sizeof(cp)/sizeof(cp[0]), strlen(cp),
           cp
    );
    return 0;
}
