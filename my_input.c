#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_LEN 10

void checked_putc(char character) {
    // Writes a single character out to the terminal/file
    unsigned char uchar = character;
    int result = fputc(uchar, stdout);
    if (result != (int) uchar) {
        printf("\n%d != %hhd\n", result, uchar);
        abort();
    }
}

void my_print(const char * string) {
    for (size_t idx = 0; idx < strlen(string); idx++) {
        checked_putc(string[idx]);
    }
    checked_putc('\n');
}

char checked_getc() {
    int read = fgetc(stdin);
    if (read == EOF) {
        abort();
    }
    return (char) read;
}

void my_input(char * buffer, size_t buffer_len) {
    // reads a line from the terminal/file
    size_t len = 0;
    while (len < (buffer_len - 1)) {
        char read = checked_getc();
        if (read == '\n') {
            break;
        }
        buffer[len] = read;
        len += 1;
    }
    buffer[len] = '\0';
    // same as: buffer[len] = 0;
}

int main() {
    my_print("What do you say?");
    char buffer[BUFFER_LEN] = { 0 };
    my_input(buffer, BUFFER_LEN);
    my_print("You said:");
    my_print(buffer);
    return 0;
}
