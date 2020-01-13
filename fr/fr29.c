#include <stdio.h>

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

int main() {
    printf("%d %d %d %d\n", UP, DOWN, LEFT, RIGHT);
    return 0;
}

/* What does this program print... and why?
 * Why can I use %d to print out the values of the 
 * enum?
 */



