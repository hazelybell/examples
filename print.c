#include <stdio.h>

int main() {
    char string[10] = { 'B', 'l', 'a', 's', 't', 'o', 'i', 's', 'e', '\0' };
    // same as: char string[10] = "Blastoise";
    printf("%s\n", string);
}
