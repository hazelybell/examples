#include <stdio.h>
#include <stdlib.h>

char *genseq(size_t n) {
    const char alphabet[] = "ACGT";
    char *s = (char *) 
        malloc((n+1) * sizeof(char));
    for (size_t i = 0; i < n; i++) {
        s[i] = alphabet[rand() % 4];
    }
    s[n] = '\0';
    return s;
}

int main(int argc, char ** argv) {
    size_t n;
    if (argc < 2 || sscanf(argv[1], "%zu", &n) != 1) {
        printf("Please run the program like\n%s 10\nfor a length-10 string.\n", argv[0]);
        exit(1);
    }
    char * a = genseq(n);
    printf("New sequence: %s\n", a);
    free(a);
}
