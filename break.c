#include <stdio.h>

int main() {
    int count_to = 4;
    for (int i = 0; i < count_to; i++) {
        for (int j = 0; j < count_to; j++) {
            if (i+j == count_to) {
                break;
            }
            printf("%d ", i+j);
        }
        printf("\n");
    }
}
