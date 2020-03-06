#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

char *fixed_string_copy(
    char * destination,
    const char * source,
    size_t max_size
) {
    size_t length = 0;
    while (
        source[length] != '\0'
        && length < (max_size - 1)
    ) {
        destination[length] = source[length];
        length += 1;
    }
    destination[length] = '\0';
    return destination;
}

int main() {
    const char * message = "Minccino";
    char string[BUFFER_SIZE] = { 0 };
//     fixed_string_copy(string, message, BUFFER_SIZE);
    printf(
        "message = %p %s\n",
        (void *) message,
        message
    );
    printf(
        "string = %p %s\n",
        (void *) string,
        string
    );
    string[0] = 'T';
    printf("string = %s\n", string);
    return 0;
}
