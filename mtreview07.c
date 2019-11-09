/* Items to review: 
 * scanf
 * variable-length array
 * passing arrays
 * exit/return
 * parts of a float
 * precision of a float
 * assignment operators
 * printf formats
 */
/* Try to understand how this program 
 * works and why it works the way that
 * it does...
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    printf("How many numbers would you like generate? ");
    unsigned long n;
    if (!scanf("%lu", &n)) {
        exit(1);
    }
    float a[n];
    for (unsigned long i = 0; i < n; i++) {
        int sign = rand() % 2; // 2 = 2^1. Why choose 2^1?
        int exp = rand() % 256 - 127; // 256 = 2^8. Why choose 2^8?
        int frac = rand() % 8388608; // 2^23. Why choose 2^23?
        float powtwo = a[i] = 1.0; // what happens here?
        while (frac) { // when does this loop end?
            powtwo /= 2.0;
            if (frac % 2) {
                a[i] += powtwo;
            }
            frac /= 2;
        }
        int j = 0;
        while (j != exp) {
            if (exp < 0) {
                a[i] /= 2.0;
                j--;
            } else {
                a[i] *= 2.0;
                j++;
            }
        }
        if (sign) a[i] = -a[i];
        printf("%.4e\n", a[i]); // How will the output be formatted? What does 'e' mean? What does .4 mean?
    }
}

