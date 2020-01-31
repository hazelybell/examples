#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/*
DRY: Don't Repeat Yourself
* Don't write the same or similar code more than twice, generalize it and use a function

What makes a good function?
* Few parameters
* Few lines of code
* Each line is simple and easy to understand
* Does one thing
    * You should be able to describe it with just one "verbs a noun"
    * e.g. "starts the timer"
    * This should be obvious from its parameters, return type, and name
* Is well named
    * e.g. not "f"
    * e.g. not "gets"
* Not many nested things
    * for/if/while/do/switch
    * Max 2 nested things
    * If you need more nested things, break them into functions
* Lines are grouped logically
* Checks its assumptions
*/

#define N_PRIMES = 10;

typedef uint64_t Prime;
typedef Prime[N_PRIMES] Primes;

void print_primes(Primes primes) {
    printf("The first %z primes are: ", N_PRIMES);
    for (size_t prime_idx = 0;
         prime_idx < N_PRIMES;
         prime_idx++) {
        printf("%llu ", (long long unsigned) primes[prime_idx]);
    }
    printf("\n");
}

int save_prime(
    Primes primes,
    size_t primes_found,
    Prime candidate
) {
    // Checking my assumption!
    if (primes_found >= N_PRIMES) {
        abort();
    }
    primes[primes_found] = candidate;
}

int find_primes() {
    // How does this initialize the array?
    Primes primes = { 2 };
    size_t primes_found = 1;
    
    print_primes(primes);
    
    Prime candidate = 3;
    while (candidate <= N_PRIMES) {
        if (is_prime(candidate)) {
            save_prime(primes,
                       primes_found,
                       candidate);
            primes_found += 1;
            candidate += 1;
        }
    }
    
    print_primes(primes);
}

int main() {
    // not much in main
    find_primes();
}
