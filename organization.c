
// C preprocessor directives
#include <stdio.h>
#include <stdlib.h>
// math functions... we have to compile with -lm to use these
#include <math.h>

// typedefs
typedef unsigned int my_unsigned;

// Constants
static const my_unsigned TWO = 2;

// Macros
// static const int N = 100;
#define N 100

// Global variables
my_unsigned primes[N] = {2};

// Function declarations
my_unsigned ul_sqrt(my_unsigned x);

// Function definitions
my_unsigned find_primes() {
    // local variables 
    my_unsigned p = 2;
    my_unsigned count = 1;
    while (1) {
        // label
        continue_outer:
        p++;
        
        // variables local to a {} block
        my_unsigned i = 0;
        my_unsigned d = 2;
        my_unsigned limit = ul_sqrt(p);
        while (d <= limit) {
            if (p % d == 0) {
                // p is not prime
                goto continue_outer;
            }
            
            i++;
            if (i >= N) {
                return count;
            }
            d = primes[i];
        }
        printf("%lu is prime.\n", 
               (unsigned long) p);
        if (count < N) {
            primes[count++] = p;
        } else {
            count++;
        }
    }
}

int main(int argc, char ** argv) {
    printf("Found %lu primes with %zu bytes of RAM!\n", (unsigned long) find_primes(), sizeof(my_unsigned)*N);
    return 0;
}

my_unsigned ul_sqrt(my_unsigned x) {
    // static local variables
    static unsigned long called = 0;
    
    // local variables
    my_unsigned result;
    
    called++;
    printf("u64_sqrt has been called %lu times\n", called);
    
    result = 
        (my_unsigned) floor(sqrt((double) x));
    return result;
}
