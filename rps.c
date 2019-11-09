#include <stdio.h>
#include <stdlib.h>

enum move {
    ROCK,
    PAPER,
    SCISSORS
};

const char * move_to_string(enum move m) {
    switch(m) {
        case ROCK:
            return "rock";
        case PAPER:
            return "paper";
        case SCISSORS:
            return "scissors";
        default:
            abort();
    }
}

enum move string_to_move(const char * s) {
    switch(s[0]) {
        case 'r':
        case 'R':
            return ROCK;
        case 'p':
        case 'P':
            return PAPER;
        case 's':
        case 'S':
            return SCISSORS;
        default:
            fprintf(stderr, "I don't know what %s is!\n", s);
            exit(1);
    }
}

int beats(enum move a, enum move b) {
    // returns true if a beats b
    switch(b) {
        case ROCK:
            return (a == PAPER);
        case PAPER:
            return (a == SCISSORS);
        case SCISSORS:
            return (a == ROCK);
        default:
            abort();
    }
}

enum move random_move() {
    return rand() % 3;
}

int get_choice(char *s) {
    printf("Rock, paper, or scissors? ");
    return scanf("%8s", s);
}

int main(int argc, char **argv) {
    char choice[9];
    while (get_choice(choice) == 1) {
        enum move human = string_to_move(choice);
        printf("You played %s!\n", move_to_string(human));
        enum move computer = random_move();
        printf("I played %s!\n", move_to_string(computer));
        if (beats(human, computer)) {
            printf("You win!\n");
        } else if (beats(computer, human)) {
            printf("You lose!\n");
        } else {
            printf("Draw!\n");
        }
        printf("Let's play again!\n");
    }
}
