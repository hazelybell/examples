#include <stdio.h>
#include <string.h>

#define BUFFER_LEN 1024

int main() {
    const char * message = "Minccino";
    size_t message_len = strlen(message);
    size_t buffer_len = message_len + 1;
    char string[buffer_len]; // C99 VLA
    strncpy(string, message, buffer_len);
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
    return 0;
}
