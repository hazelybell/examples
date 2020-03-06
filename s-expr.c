#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4095


/* This program reads s-exprs like:
 * 
 * ( a ( b ( ) ) ( c d e f ) ( ) )
 * 
 * Every thing has to be seperated by spaces
 * so we can be lazy with scanf.
 * 
 * This is the unfinished version.
 */

struct item;
typedef struct item Item;

typedef struct {
    size_t len;
    Item * items;
} * List;

struct item {
    enum {
        LIST,
        STRING
    } kind;
    union {
        char * string;
        List list;
    } data;
};

List new_list() {
    List new;
    new = malloc(sizeof(*new));
    new->len = 0;
    new->items = NULL;
    return new;
}

void grow(List list) {
    list->len += 1;
    list->items = realloc(
        list->items,
        sizeof(Item) * list->len
                  );
}

Item new_list_item(List list) {
    Item new;
    new.kind = LIST;
    new.data.list = list;
    return new;
}

Item new_string_item(char * string) {
    Item new;
    new.kind = STRING;
    new.data.string = string;
    return new;
}

void append_sublist(List list, List sublist) {
    grow(list);
    Item item = new_list_item(sublist);
    list->items[list->len - 1] = item;
}

void append_string(List list, char * buffer) {
    grow(list);
    Item item = new_string_item(buffer);
    list->items[list->len - 1] = item;
}

List read_list() {
    List list = new_list();
    char * buffer = NULL;
    while (scanf("%ms", &buffer) == 1) {
        if (strcmp(buffer, "(") == 0) {
            // start a new sub-list
            free(buffer);
            List sublist = read_list();
            append_sublist(list, sublist);
        } else if (strcmp(buffer, ")") == 0) {
            free(buffer);
            return list;
        } else {
            // put a string in our list
            append_string(list, buffer);
            buffer = NULL;
        }
    }
    return list;
}

void print_list(List list);

void print_item(Item item) {
    if (item.kind == LIST) {
        print_list(item.data.list);
    } else if (item.kind == STRING) {
        printf("%s\n", item.data.string);
    }
}

void print_list(List list) {
    for (size_t idx = 0; idx < list->len; idx++) {
        Item item = list->items[idx];
        print_item(item);
    }
}

void free_list(List list) {
}

int main() {
    List list = read_list();
    print_list(list);
    free_list(list);
    return 0;
}
