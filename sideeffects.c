#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int i = 1;
    int j = -i;
    printf("%d\n", j);
    int k = +j;
    printf("%d\n", k);
    if ((i = 0)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    i = j = k = 72;
    i = (j = (k = 72));
    i += j += k; // same as i += (j += k);
    printf("%d %d %d\n", i, j, k);
    i = 1;
    j = 10;
    k = ++i + j++;
    // should be like k = 2 + 10;
    // order of operations here is:
    // postfix (j++ j-- etc.)
    // prefix (--j ++j etc. unary + and -)
    // multiplication (* / %)
    // addition (+ -)
    // assignments (= += *= etc.)
    printf("%d %d %d\n", i, j, k);
    return 0;
}
