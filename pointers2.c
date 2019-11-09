#include <stdio.h>

int main(int argc, char ** argv) {
    printf("--- A:\n");
    int n = 0;
    int m = n; // copy the value of n to m
    m++;
    printf("n=%d, m=%d\n", n, m);
    printf("&n=%p, &m=%p\n", &n, &m);
    
    printf("--- B:\n");
    int *p;
    p = &n; // copy the address of n to p
    int *o = &m;
    *o = *p; // copy the value AT p to the value AT o
    printf("n=%d, m=%d\n", n, m);

    printf("--- C:\n");
    *p = 10; // set the value AT p to 10
    printf("n=%d, m=%d\n", n, m);
    
    printf("--- D:\n");
    o = p; // copy the address in p to o
    printf("p=%p, o=%p\n", p, o);
    printf("*p=%d, *o=%d\n", *p, *o);
    
    printf("--- E:\n");
//     p = m; // don't do this!
    printf("n=%d, m=%d\n", n, m);
    
    printf("--- F:\n");
    int **q; // p is a pointer to a pointer to an int
    q = &p; // cpy the address of p to q
    printf("n=%d, p=%p, q=%p\n", n, p, q);
    printf("q=%p, *q=%p, **q=%d\n", q, *q, **q);
    
    printf("--- G:\n");
    (*p)++; // increment the int at address stored in p
    printf("n=%d, p=%p, *p=%d\n", n, p, *p);

//     printf("--- H:\n");
//     *p++; // increment the address stored in p
//     // uh oh!
//     printf("n=%d, p=%p, *p=%d\n", n, p, *p);
//     *p = 1;
//     // who knows what we're overwriting...
//     printf("n=%d, p=%p, *p=%d\n", n, p, *p);
    
    printf("--- I:\n");
    int *r; // r uninitialized
    *r = 1; // set some junk address to 1
    return 0;
}



