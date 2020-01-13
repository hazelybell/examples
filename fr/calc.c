#include <stdio.h>
#include <stdlib.h>

#ifdef OFF

double add(double a, double b) {
    double r = a + b;
    printf("%g + %g = %g\n", a, b, r);
    return r;
}

double subtract(double a, double b) {
    double r = a - b;
    printf("%g - %g = %g\n", a, b, r);
    return r;
}

double multiply(double a, double b) {
    double r = a * b;
    printf("%g * %g = %g\n", a, b, r);
    return r;
}

double divide(double a, double b) {
    double r = a / b;
    printf("%g / %g = %g\n", a, b, r);
    return r;
}

double (* operations[127])(double a, double b) = {
    ['+'] = &add,
    ['-'] = &subtract,
    ['*'] = &multiply,
    ['/'] = &divide
};

void unknown(char c) {
    printf("Unknown operation %c (%d)!\n", c, c);
    exit(1);
}

int try_number() {
    double number;
    int used = 0;
    int r = scanf("%lf%n", &used);
    if (r != 1) { 
        return 0; 
    }
    printf("got %g\n", number);
    return used;
}

int try_operation() {
    unsigned char operation = '?';
    int r = scanf(" %c", &operation);
    if (r != 1) {
        return 0;
    }
    if (operation > 127) unknown(operation);
    if (operations[operation] == NULL) unknown(operation);
    printf("got %c (%d)\n", operation, operation);
    double a = 1.0;
    double b = 1.0;

    double number = operations[operation](a, b);
    printf("result %g\n", number);
    return 1;
}

void parse_input(const char * input) {
    while (strlen(input)) {
        int used = 0;
        if (used = try_number(input)) {
            
        } else if (used = try_operation(input)) {
            
        } else {
            abort();
        }
        input += used;
    }
}

int main(int argc, char ** argv) {
    
    while (1) {
        char * input = NULL;
        int r = scanf("%ms", &input);
        if (r != 1) {
            printf("Done?\n")
            break;
        }
        parse_input(input);
    }
    return 0;
}
#else

int main() {}


#endif
