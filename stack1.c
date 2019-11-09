#include <stdio.h>
#include <stdlib.h>

struct stack {
    size_t size;
    int *data;
};

struct stack new_stack() {
    struct stack new = {
        0,
        NULL
    };
    return new;
}

size_t realloc_called = 0;

void resize_stack(
    struct stack *s,
    size_t new_size
                 ) {
    s->size = new_size;
    s->data = realloc(
        s->data,
        new_size * sizeof(int)
    );
    realloc_called += 1;
}

// if we have a variable that's a pointer to a strcut like struct mystruct *m
// the we can get something out of the struct with m->field

// same as (*m).field

// if we have an actual struct (not just a pointer to one)
// then we can get something out of the struct like m.field 

void push(struct stack *s, int value) {
    // pushes value onto s
    resize_stack(s, s->size + 1);
    s->data[s->size - 1] 
        = value;
}

int pop(struct stack *s) {
    // pops a value off of s
    if (s->size < 1) abort(); // we need at least one thing to pop
    int value = s->data[s->size - 1];
    resize_stack(s, s->size - 1);
    return value;
}

void usage(char *argv0) {
    // prints out how to use the program and then exits
    fprintf(
        stderr,
        "Usage: %s [number]\n"
        "Where [number] is the number of\n"
        "items you wish to push onto a\n"
        "stack datastructure.\n"
        "Example: %s 1000\n",
        argv0,
        argv0
    );
    exit(1);
}

int main(int argc, char **argv) {
    struct stack a = new_stack();
    struct stack b = new_stack();
    size_t n = 0;
    if (argc != 2) usage(argv[0]);
    if (sscanf(argv[1], "%zu", &n) != 1) {
        usage(argv[0]);
    }
    printf("Pushing %zu integers onto two stacks.\n", n);
    for (size_t i = 0; i < n; i++) {
        int value = rand();
        push(&a, value);
        push(&b, value);
    }
    printf("Popping them back off!\n");
    for (size_t i = 0; i < n; i++) {
        int va = pop(&a);
        int vb = pop(&b);
        if (va != vb) abort();
    }
    if (a.size != 0) abort();
    if (b.size != 0) abort();
    printf("realloc() was called %zu times.\n", realloc_called);
    return 0;
}
