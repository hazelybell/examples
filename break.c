#include <stdio.h>

int main(int argc, char ** argv) {
    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i+j == n) {
                break;
            }
            printf("%d ", i+j);
        }
        printf("\n");
    }
}
