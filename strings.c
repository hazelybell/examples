#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    char name[5] = "Hazel";
    printf("Hello, %s!\n", name);
    char name2[6] = "Hazel";
    printf("Hello, %s!\n", name2);
    
    printf("Enter your name: ");
    scanf("%5s", name2);
    printf("Hello, %s!\n", name2);
    for (int i = 0; i < 6; i++) {
        printf("%hhd ", name2[i]);
    }
    printf("\n");
    printf("It's %s!\n", "Friday the 13th");
    printf("It's %s!\n", "Friday\0 the 13th");
    printf("%lu\n", strlen("Friday\0 the 13th"));
    char name3[4] = "\u2603";
    printf("Hello, %s!\n", name3);
    for (int i = 0; i < 4; i++) {
        printf("%hhu ", name3[i]);
    }
    printf("\n");
    return 0;
}
