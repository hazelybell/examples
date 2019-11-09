#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv) {
    char *a = "Hello World!";
    for (size_t i = 0; i <= strlen(a); i++) {
        char *p1 = a + i;
        char *p2 = &a[i];
        printf("%p %p\n",
               p1,
               p2
        );
    }
    return 0;
}


