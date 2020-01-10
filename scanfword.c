#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1024

int main() {
    char buffer[MAX_STRING_LENGTH+1];
    printf("Enter a line of text: ");
    int num_read = scanf("%1024s", buffer);
    if (num_read == 1) {
        printf("You entered: %s\n", buffer);
    } else {
        printf("Didn't read anything :(");
    }
	return 0;
}
