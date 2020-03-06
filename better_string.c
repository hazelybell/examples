#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This all assumes we're dealing with ASCII! */

typedef struct {
    size_t len;
    size_t buffer_len;
    char * chars;
} * String;

String new_string() {
    String new;
    new = malloc(sizeof(*new));
    if (new == NULL) {
        abort();
    }
    new->len = 0;
    new->buffer_len = 0;
    new->chars = NULL;
    return new;
}

void free_string(String string) {
    if (string->chars != NULL) {
        free(string->chars);
    }
    free(string);
}

void string_oob(String string, size_t pos) {
    if (pos >= string->len) {
        abort();
    }
    if (pos >= string->buffer_len) {
        abort();
    }
}

char get_char(String string, size_t pos) {
    string_oob(string, pos);
    return string->chars[pos];
}

void replace_char(
    String string,
    size_t pos,
    char new_char
) {
    string_oob(string, pos);
    string->chars[pos] = new_char;
}

void remove_char(String string, size_t pos) {
    string_oob(string, pos);
    
    size_t left_len = pos;
    size_t new_len = string->len - 1;
    
    size_t right_len = string->len - left_len - 1;
    
    char * right = &string->chars[pos + 1];
    char * dest = &string->chars[pos];
    
    // Double-check our math
    if (left_len + right_len != new_len) {
        abort();
    }
    // The + 1 here grabs the null byte too!
    memmove(dest, right, right_len + 1);
    
    string->len = new_len;
    if (string->chars[string->len] != '\0') {
        abort();
    }
}

void strip_newline(String string) {
    if (get_char(string, string->len-1) == '\n') {
        remove_char(string, string->len-1);
    }
}

String input() {
    String line = new_string();
    ssize_t got = getline(
        &(line->chars),
        &(line->buffer_len),
        stdin
    );
    
    if (got < 0) {
        free(line);
        return NULL;
    }
    
    line->len = got;
    strip_newline(line);
    return line;
}

int main() {
    while (true) {
        String line = input();
        printf("%zu %zu %s\n",
               line->len,
               line->buffer_len,
               line->chars
        );
        free_string(line);
    }
    return 0;
}
