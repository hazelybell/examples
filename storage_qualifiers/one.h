#ifndef _ONE_H_
#define _ONE_H_

extern int a;
extern const int G;

extern int (*hello)(int k);

// extern is the default on functions!
extern void print_a_one();
// exactly the same as:
// void print_a_one();


// like static, but asks the compiler to inline the function
// if we want to use it in other files we put the whole function in the header!
inline int n(int o) {
    o += 1;
    return o;
}

#endif /* _ONE_H_ */
