#include <stdio.h>



int main() {
    int a[5] = { 0, 1, 2, 3, 4 };
    printf(" a[0]=%d\n", a[0]);
    printf("&a[0]=%p\n", &a[0]);
    printf(" a[0]=%d\n", a[0]);
    printf("    a=%p\n", a);
    printf("   &a=%p\n", &a);
    return 0;
}

/*
 * On line 10, why don't I need a & to get a pointer?
 * On 11 what is the most correct type of the pointer?
*/



