#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i+j == n) {
                continue;
            }
            printf("%d ", i+j);
        }
        printf("\n");
    }
}
