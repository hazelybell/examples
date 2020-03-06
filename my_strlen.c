#define _POSIX_C_SOURCE 200809L // Enables getting strnlen() from string.h
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Unless _POSIX_C_SOURCE is >= 200809L this won't get us strnlen!

/* This is like strlen from <string.h>,
 * but it's probably slower.
 * You should use strlen, not your own function.
 * This is just to demonstrate how it works.
 * 
 * What happens if the null '\0' 0 termination character
 * is missing?
 */

#define BUFFER_SIZE 10

size_t string_length(const char *string) {
    size_t length = 0;
    while (string[length] != '\0') {
        length += 1;
    }
    return length;
}

/* If we know we only have so much space at most
 * to store the string, as we do when we use a
 * fixed-length buffer, this is a better approach,
 * because it will never overrun the buffer!
 * This is provided by strnlen(), but we have
 * to #define _POSIX_C_SOURCE before we
 * #include <string.h> to get strnlen().
 */

size_t fixed_string_length(
    const char *string,
    size_t max_length
) {
    size_t length = 0;
    while (
        length < max_length
        && string[length] != '\0'
    ) {
        length += 1;
    }
    return length;
}

int main() {
    const char *string = "Zigzagoon";
    printf("string=%s\n", string);
    printf("string_length=%zu\n", string_length(string));
    printf("strlen=%zu\n", strlen(string));

    char buffer[BUFFER_SIZE] = {
        'W', 'h', 'i', 's', 'm', 'u', 'r', '\0'
    };
    printf("buffer=%s\n", buffer);
    printf("string_length=%zu\n", string_length(buffer));
    printf("strlen=%zu\n", strlen(buffer));
    
    for (size_t idx = 0; idx < BUFFER_SIZE; idx++) {
        buffer[idx] = 'a';
    }
    printf("buffer=%s\n", buffer);
    printf("string_length=%zu\n", string_length(buffer));
    printf("strlen=%zu\n", strlen(buffer));
    printf("buffer=%.10s\n", buffer);
    printf("fixed_string_length=%zu\n", fixed_string_length(buffer, BUFFER_SIZE));
    printf("strnlen=%zu\n", strnlen(buffer, BUFFER_SIZE));
}


