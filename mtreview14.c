/* Items to review: 
 * subsequence
 * scanf
 * strings in C
 * shortcutting
 * goto
 * exit
 */
/* This program produces a random 
 * subsequence of input sequences
 * of digits... how does it achieve that?
 */
#include <stdio.h>
#include <stdlib.h>

#define N 1000

int over() {
    exit(0);
    return 0;
}

int main(int argc, char ** argv) {
    char s[N+1];
    again: printf("Enter a sequence of digits: ");
    scanf("%1000s", s) > 0 || over(); // What does this statement do?
    // what does the "1000s" do?
    // why isn't it &s?
    // why is there a ||?
    // when does it return?
    int i = 0;
    while (1) { // when does this loop end?
        switch (s[i++]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                continue;
            case 0: // when does this happen?
                goto ok;
            default:
                goto again;
        }
    }
    ok: printf("Random subsequence: ");
    for (int j = 0; j < i; j++) { // why 'j < i'?
        if (rand() % 2) {
            printf("%c", s[j]); // what is "%c" ?
        }
    }
    printf("\n");
    goto again;
    return 0; // when does this happen?
}



