#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1024

int main() {
    char buffer[MAX_STRING_LENGTH+1];
    printf("Enter a line of text: ");
    char newline;
    int num_read = scanf("%1024[^\n]%c", buffer, &newline);
    if (num_read == 2) {
        printf("You entered: %s\n", buffer);
        printf("First char in buffer: %c (%hhu)\n", buffer[0], buffer[0]);
        printf("Newline char: %c (%hhu)\n", newline, newline);
    } else {
        printf("Error :(");
    }
	return 0;
}
