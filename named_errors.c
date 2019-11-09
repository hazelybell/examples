#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h> // allows us to use getrandom()

int really_random(int stop) {
    // produces a random integer from 0 to stop-1
    unsigned long long u;
    // ask the OS kernel directly for random bytes
    ssize_t r = getrandom(&u, sizeof(u), 0);
    // should return the number of random bytes written
    if (r != sizeof(u)) abort();
    return (int) (u % stop);
}

enum named_error {
    SUCCESS,
    BAD_BEEF,
    WILTED_LETTUCE,
    OLD_MAYONAISE,
    N_ERRORS
};

const char * describe_error(int e) {
    switch(e) {
        case SUCCESS:
            return "Success.";
        case BAD_BEEF:
            return "The beef was bad.";
        case WILTED_LETTUCE:
            return "The lettuce got too hot and wilted.";
        case OLD_MAYONAISE:
            return "The mayonnaise has expired.";
        default:
            return "Unknown error.";
    }
};

void check(int e) {
    if (e == SUCCESS) return;
    printf("Error: %s\n", describe_error(e));
    exit(e);
}

int make_burger() {
    return really_random(N_ERRORS);
}

int main(int argc, char **argv) {
    check(make_burger());
    return SUCCESS;
}
