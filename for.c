#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT_TO 5

int main() {
    // like for range(0,5):
    for (int counter = 0; counter < COUNT_TO; counter++) {
        printf("%d\n", counter);
    }
    // I cannot do this:
    // printf("%d\n", counter);
    printf("Same as:\n");
    int counter;
    counter = 0;
    while (counter < COUNT_TO) {
        printf("%d\n", counter);
        counter++;
    }
    printf("---\n");
    printf("%d\n", counter);
    // for (
    //  something that runs once ;
    //  counter conditional that's checked 
    //      each time;
    //  something that happens each time ;
    // )
    printf("--- Don't do this:\n");
    counter = 0;
    for (; counter < COUNT_TO; counter++) {
        printf("%d\n", counter);
    }
    printf("--- Definitely don't do this:\n");
    for (counter = 0; counter < COUNT_TO; counter++) {
        printf("%d\n", counter);
        counter = COUNT_TO;
    }
    printf("---\n");
    printf("%d\n", counter);
    printf("--- Don't do this either:\n");
    counter = 0;
    for (; counter < COUNT_TO;) {
        printf("%d\n", counter);
        counter++;
    }
    printf("---\n");
    printf("%d\n", counter);
    return 0;
}
