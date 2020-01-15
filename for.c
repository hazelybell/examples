#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    int a;
    for (a = 0; a < 5; a++) {
        printf("%d\n", a);
    }
    printf("---\n");
    a = 0;
    while (a < 5) {
        printf("%d\n", a);
        a++;
    }
    printf("---\n");
    printf("%d\n", a);
    // for (
    //  something that runs once ;
    //  a conditional that's checked 
    //      each time;
    //  something that happens each time ;
    // )
    printf("---\n");
    a = 0;
    for (; a < 5; a++) {
        printf("%d\n", a);
    }
    printf("---\n");
    a = 0;
    for (; a < 5; a++) {
        printf("%d\n", a);
        a = 5;
    }
    printf("---\n");
    printf("%d\n", a);
    printf("---\n");
    a = 0;
    for (; a < 5;) {
        printf("%d\n", a);
        a = 5;
    }
    printf("---\n");
    printf("%d\n", a);
    return 0;
}
