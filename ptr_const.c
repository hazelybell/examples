#include <stdio.h>


int main() {
    int mut_i = 100; // mutable integer
    printf("mut_i = %d\n", mut_i);
    static const int const_i = 200; // constant integer
    // const int const_i = 200;
    // static const, the value is stored (in binary) in the compiled executable file itself
    // auto const (aka just const),
    // the value is stored on stack with all the other variables in this function
    const size_t TWO_HUNDRED = 200;

    // requires TWO_HUNDRED to be #define
    // if it's not, then array is a C99 VLA
//     int array[TWO_HUNDRED] = { 0 };
    
    
    printf("const_i = %d\n", const_i);
    
    // requires TWO_HUNDRED to be a varaible
//     int * two_hundred_p = &TWO_HUNDRED;
    
//     int * const_i_p = &const_i;
    
//     *const_i_p = 27;
//     printf("const_i = %d\n", const_i);
        
    // mutable pointer to mutable integer
    int * mut_p = &mut_i;
    printf("mut_p = %p\n", (void *) mut_p);
    printf("*mut_p = %d\n", *mut_p);
    // constant pointer to mutable integer
    int * const const_p = &mut_i;
    printf("const_p = %p\n", (void *) const_p);
    printf("*const_p = %d\n", *const_p);
    // mutable pointer to constant integer
    const int * p_to_const = &const_i;
    printf("p_to_const = %p\n", (void *) p_to_const);
    printf("*p_to_const = %d\n", *p_to_const);
    // constant pointer to constant integer
    const int * const const_p_to_const = &const_i;
    printf("const_p_to_const = %p\n", (void *) const_p_to_const);
    printf("*const_p_to_const = %d\n", *const_p_to_const);
    
    
    // Don't do this!
    // "warning: assignment discards ‘const’ qualifier from pointer target type"
//     mut_p = &const_i;
    
    const char *str_lit = "String literals are const char *";
    printf("%s\n", str_lit);
//     str_lit[0] = 'D';
    // but remember this means we can change str_lit to point to a different string!
    str_lit = "String literal #2";
    printf("%s\n", str_lit);
    
    // This protects us from:
    // str_lit[0] = 'D';

    // this is wrong:
    char *wrong = "We will try to change this string literal";
    printf("%s\n", wrong);
    
    // Because it doesn't protect us from:
//     wrong[0] = 'D';
    // what happens if you uncomment the above line?
    
    // This might be better:
    const char * const RIGHT = "Don't go changing on me!";
    printf("%s\n", RIGHT);
    // Because it protects us from:
//     RIGHT[0] = 'L';
    // what happens if you uncomment the above line?
    // and
    // RIGHT = wrong;
    // what happens if you uncomment the above line?
    
}
