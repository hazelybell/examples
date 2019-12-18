#include <stdio.h>
#include <stdlib.h>

struct stack {
    double * p;
    size_t n;
};

typedef struct stack *Stack;

Stack new_stack() {
    Stack new = malloc(sizeof(struct stack));
    new->p = NULL;
    new->n = 0;
    return new;
}

void push(Stack s, double v) {
    s->n += 1;
    s->p = realloc(s->p, s->n * sizeof(double));
    s->p[s->n - 1] = v;
}

double pop(Stack s) {
    if (s->n == 0) abort();
    s->n -= 1;
    double v = s->p[s->n];
    s->p = realloc(s->p, s->n * sizeof(double));
    return v;
}

void free_stack(Stack s) {
    if (s->n != 0) abort();
    free(s);
}

int main() {
    Stack s = new_stack();
    push(s, 1.0);
    push(s, 2.0);
    push(s, 3.0);
    printf("%e\n", pop(s));
    printf("%e\n", pop(s));
    printf("%e\n", pop(s));
    free_stack(s);
}

/* What's going on here? 
 * Why am I using -> everywhere?
 */


