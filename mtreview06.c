/* Items to review: 
 * do...while
 * break
 * continue
 * switch
 * scanf
 * block scope
 */
/* Try to understand what this program 
 * prints and how it works without running 
 * it!
 * Try the following inputs:
 * 1.5
 * 1
 * -1
 * 6 
 */

#include <stdio.h>

int main(int argc, char ** argv) {
    printf("Enter a sequence of numbers. Enter 0 to end the sequence! ");
    int i = 0;
    do { // How many times does this loop run?
        if (scanf("%d", &i)) { // how does this if work?
            switch (i % 3) {
                case 0:
                    printf("Divisible by 3!\n");
                    break; // what does this do?
                case 1:
                case 2:
                    printf("Not divisible by 3...\n");
                    break;
                default:
                    printf("???\n"); // when would this happen?
            }
        } else {
            continue; // what does this do?
        }
    } while (i != 0);
    return 0;
}

