#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // needed for read()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> // needed for open()

struct buffer {
    size_t length;
    char *data;
    size_t allocated;
};

struct buffer new_buffer() {
    // constructs a new buffer
    struct buffer new = {
        0,
        NULL,
        0
    };
    return new;
}

void free_buffer(struct buffer *b) {
    b->length = 0;
    free(b->data);
    b->data = NULL;
    b->allocated = 0;
}

void expand_buffer(struct buffer *b) {
    // if needed, expand buffer b, adding unused space to it
    if (b->allocated > b->length) {
        // still has free space, we don't need to add any
        return;
    }
    if (b->allocated == 0) {
        b->allocated = 1;
    } else {
        b->allocated *= 2;
    }
    b->data = realloc(
        b->data,
        b->allocated * sizeof(int)
    );
}

size_t buffer_space(struct buffer *b) {
    // gets the amount of empty space available in buffer b
    if (b->length > b->allocated) abort();
    return b->allocated - b->length;
}

char * space_start(struct buffer *b) {
    // gets the start of the empty space in buffer b
    if (b->length > b->allocated) abort();
    return b->data + b->length;
};

void space_use(
    // marks some amount of space in buffer b as having been used
    struct buffer *b,
    size_t use
) {
    b->length += use;
    if (b->length > b->allocated) abort();
}

void shrinkwrap(struct buffer *b) {
    // free any unused space at the end of the buffer
    b->allocated = b->length;
    b->data = realloc(
        b->data,
        b->allocated * sizeof(int)
    );
}

int check_open(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd >= 0) {
        // everything went okay
        return fd;
    }
    // there must have been some error :(
    fprintf(
        stderr,
        "Error opening %s: %s\n",
        filename, strerror(fd)
    );
    exit(1);
}

struct buffer slurp(char * filename) {
    // read all the file into a character array
    struct buffer b = new_buffer();
    int fd = check_open(filename);
    while (1) {
        expand_buffer(&b);
        size_t space = buffer_space(&b);
        char * start = space_start(&b);
        
        // call the OS kernel directly to read data from a file
        ssize_t r = read(
            fd,
            start,
            space
        );
        
        // handle the return value of read()
        if (r > 0) {
            // r > 0 indicates how many bytes were read in 
            space_use(&b, r);
            continue;
        } else if (r == 0) {
            // r == 0 indicates end of file
            shrinkwrap(&b);
            return b;
        } else {
            // r < 0 indicates that there is some error condition
            fprintf(
                stderr,
                "Error reading %s: %s\n",
                filename, strerror(r)
            );
            abort();
        }
    };
}

void usage(char *progname) {
    // prints out how to use the program and then exits
    fprintf(
        stderr,
        "Usage: %s [filename]\n"
        "Where [filename] is the file\n"
        "you'd like to get\n"
        "information about\n"        "Example: %s my.txt\n",
        progname,
        progname
    );
    exit(1);
}

void print_info(struct buffer *b) {
    printf("Successfully read %zu bytes!\n", b->length);
    size_t null_bytes = 0;
    size_t newlines = 0;
    for (size_t i = 0; i < b->length; i++) {
        switch (b->data[i]) {
            case '\0':
                null_bytes += 1;
                break;
            case '\n':
                newlines += 1;
                break;
        }
    }
    printf("Found %zu newlines and %zu null_bytes.\n", newlines, null_bytes);
}

int main(int argc, char **argv) {
    if (argc != 2) usage(argv[0]);
    struct buffer b = slurp(argv[1]);
    print_info(&b);
    free_buffer(&b);
}


