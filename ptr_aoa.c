#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
    char *a = "Help!";
    char *b = "Stuck";
    char *c = "In";
    char *d = "Array";
    char *e = "Factory!";
    char *aoa[5] = {a, b, c, d, e};
    for (size_t i = 0; i < 5; i++) {
        printf("%p %p\n", &aoa[i], 
               &aoa[i][0]);
        // &aoa[i] = aoa + i
        // aoa[i] = &aoa[i][0]
        for (size_t j = 0; 
             aoa[i][j] != 0; j++) {
            printf("%c ", aoa[i][j]);
        }
        printf("\n");
    }
}


