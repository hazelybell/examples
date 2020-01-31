#include <stdio.h>

int main() {
    unsigned char my_char = 0;
    printf("my_char=%hhu\n", my_char);
    printf("Enter a new value: ");
    scanf("%hhu", &my_char);
    printf("my_char=%hhu\n", my_char);
    my_char += 1;
    printf("my_char=%hhu\n", my_char);
}
