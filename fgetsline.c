#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1024

int main() {
    // A string in C is a sequence of chars in memory, which end with the \0 char (aka the number 0)
    // Thus we need to make sure we have enough space
    // to store the \0, so we add one.
    // This declares an array of chars
    // We can use the array to hold our string...
    char buffer[MAX_STRING_LENGTH+1];
    printf("Enter a line of text: ");
    char *returned = fgets(buffer, MAX_STRING_LENGTH, stdin);
    if (returned == NULL) {
        printf("Error: Didn't read anything :(");
    } else {
        printf("You entered: %s\n", buffer);
    }
	return 0;
}
