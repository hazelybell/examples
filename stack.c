#define _POSIX_C_SOURCE 200809L // <-- needed for getline
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Let's define Stack as a pointer to a struct,
 * which itself contains the pointer to the actual
 * data on the stack, which are pointers to chars (strings).
 * 
 * This is so that when we realloc() and update elts,
 * we don't have to worry about some other piece of code
 * having the old value of elts.
 * 
 * If we didn't hide our pointer that gets realloc'd behind
 * another pointer, it is easy to have an old copy of the
 * realloc'd pointer (which is now invalid) floating around.
 * 
 * But by putting it behind a pointer, new_stack() can
 * create the single copy of the struct, which contains
 * the elts pointer that changes. Since the sizeof the
 * actual struct never changes, we never have to realloc
 * that pointer, so we can ensure we only have one version
 * of elts at all times. This is similar to how
 * Java/Python/JS handle arrays internally.
 * 
 */

typedef struct stack {
    size_t size;
    char ** elts;
} * Stack;

void show_stack(Stack stack) {
    printf("Stack %p: %zu items starting at %p\n",
           (void *) stack,
           stack->size,
           (void *) stack->elts
    );
}

Stack new_stack() {
    /* Constructor */
    Stack new = malloc(sizeof(*new));
    new->size = 0;
    new->elts = NULL;
    show_stack(new);
    return new;
}

/* this function deduplicates code from push and pop */
void resize(Stack stack, size_t new_size) {
    stack->elts = realloc(
        stack->elts,
        sizeof(char *) * new_size
    );
    
    /* make sure any new elements are initialized */
    size_t first_new_elt = stack->size;
    for (size_t idx = first_new_elt;
         idx < new_size;
         idx++) {
        stack->elts[idx] = NULL;
    }
    
    stack->size = new_size;
}

void push(Stack stack, char * string) {
    resize(stack, stack->size + 1);
    stack->elts[stack->size-1] = string;
    show_stack(stack);
}

char * pop(Stack stack) {
    if (stack->size == 0) {
        abort();
    }
    char * string = stack->elts[stack->size-1];
    resize(stack, stack->size - 1);
    show_stack(stack);
    return string;
}

/* Destructor */
void free_stack(Stack stack) {
    resize(stack, 0);
    free(stack);
}

char * checked_getline() {
    char * line = NULL;
    size_t alloc_len = 0;
    ssize_t got = getline(&line, &alloc_len, stdin);
    if (got < 0) {
        if (line != NULL) {
            free(line);
        }
        return NULL;
    } else {
        return line;
    }
}

void push_input_lines(Stack stack) {
    printf("Enter some lines. Press ctrl-d (EOF) to end.\n");
    char * line = NULL;
    while ((line = checked_getline()) != NULL) {
        push(stack, line);
    }
}

void pop_lines(Stack stack) {
    while (stack->size > 0) {
        char * line = pop(stack);
        printf(line);
        free(line);
    }
}

int main() {
    Stack stack1 = new_stack();
    Stack stack2 = stack1;
/* Because stack is a pointer, stack1 and stack2 are 
 * actually the same stack!
 * Because the actual struct doesn't need to change size,
 * these pointers will be valid until we call free_stack()
 */
    push_input_lines(stack1);
    pop_lines(stack2);
    free_stack(stack1);
    return 0;
}

