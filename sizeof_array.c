#include <stdio.h>
#include <string.h>

int main() {
    const char * string = "Ekans";
    printf("pointer: %zu bytes %zu bits example %p\n",
           sizeof(string),
           sizeof(string) * 8,
           string
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
