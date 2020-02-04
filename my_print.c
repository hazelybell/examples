#include <stdio.h>
#include <stdlib.h>

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
    // Prints a string to the terminal/file
    for (size_t idx = 0; idx < 1024; idx++) {
        if (string[idx] == '\0') {
            break;
        }
        checked_putc(string[idx]);
    }
    checked_putc('\n');
}

int main() {
    const char message[8] = "Wurmple";
    my_print(message);
    return 0;
}
