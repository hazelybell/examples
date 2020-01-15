#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT_TO 5

int main() {
    int counter;
    for (counter = 0; counter < COUNT_TO; counter++) {
        printf("%d\n", counter);
    }
    printf("---\n");
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
    printf("---\n");
    counter = 0;
    for (; counter < COUNT_TO; counter++) {
        printf("%d\n", counter);
    }
    printf("---\n");
    counter = 0;
    for (; counter < COUNT_TO; counter++) {
        printf("%d\n", counter);
        counter = COUNT_TO;
    }
    printf("---\n");
    printf("%d\n", counter);
    printf("---\n");
    counter = 0;
    for (; counter < COUNT_TO;) {
        printf("%d\n", counter);
        counter = COUNT_TO;
    }
    printf("---\n");
    printf("%d\n", counter);
    return 0;
}
