#define _POSIX_C_SOURCE 200809L // Enables getting strnlen() from string.h
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Unless _POSIX_C_SOURCE is >= 200809L this won't get us strnlen!

/* This is like strncmp from <string.h>,
 * but it's probably slower.
 * You should use strncmp, not your own function.
 * This is just to demonstrate how it works.
 * 
 * What happens if the null '\0' 0 termination character
 * is missing?
 * 
 * Just like with strlen and strnlen, there's 
 * strcmp which doesn't take a maximum length,
 * and strncmp which does. You should use strncmp
 * if you know the maximum length, like when
 * you're using a fixed-length buffer.
 * 
 * The idea here is to return an int:
 * LESS than 0 if left is LESS than right,
 * GREATER than 0 if left is GREATER than right,
 * and EQUAL to 0 if left is EQUAL to right.
 */

#define BUFFER_SIZE 10

size_t fixed_string_compare(
    const char *left,
    const char *right,
    size_t max_length
) {
    size_t length = 0;
    int compared = 0;
    while (
        compared == 0
        && (left[length] != '\0' || right[length] != '\0')
        && length < max_length
    ) {
        if (
            left[length] < right[length]
            || left[length] == '\0'
            || right[length] < left[length]
            || right[length] == '\0'
        ) {
            compared = left[length] - right[length];
        } else {
            length += 1;
        }
    }
    return compared;
}

char checked_getc() {
    int read = fgetc(stdin);
    if (read == EOF) {
        abort();
    }
    return (char) read;
}

void my_input(char * buffer, size_t buffer_size) {
    // reads a line from the terminal/file
    size_t len = 0;
    while (len < (buffer_size - 1)) {
        char read = checked_getc();
        if (read == '\n') {
            break;
        }
        buffer[len] = read;
        len += 1;
    }
    buffer[len] = '\0';
}

int main() {
    char buffers[2][BUFFER_SIZE] = { '\0' };
    printf("Enter a line of text: ");
    my_input(buffers[0], BUFFER_SIZE);
    printf("Enter a line of text: ");
    my_input(buffers[1], BUFFER_SIZE);
    
    buffers[0][BUFFER_SIZE-1] = 'a';
    
    int compared = fixed_string_compare(
        buffers[0],
        buffers[1],
        BUFFER_SIZE
    );
    
    char relationship = '?';
    
    if (compared < 0) {
        relationship = '<';
    } else if (compared > 0) {
        relationship = '>';
    } else {
        relationship = '=';
    }
    
    printf(
        "%s %c %s %d\n",
        buffers[0],
        relationship,
        buffers[1],
        compared
    );
}

