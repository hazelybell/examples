#include <stdio.h>
#include <string.h>

#define BUFFER_LEN 1024

int main() {
    const char * message = "Minccino";
    char string[BUFFER_LEN] = { 0 };
    strncpy(string, message, BUFFER_LEN);
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
