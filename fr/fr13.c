#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

static void one() {
    printf("Hi, I'm one()!\n");
}

static void two() {
    printf("Hi, I'm two()!\n");
}

static void three() {
    printf("Hi, I'm three()!\n");
}

static void four() {
    printf("Hi, I'm four()!\n");
}

static void five() {
    printf("Hi, I'm five()!\n");
}

void (* functions[N])() = {
    one,
    two,
    three,
    four,
    five
};

int main() {
    srand(time(NULL));
    int n = rand() % N;
    functions[n]();
    return 0;
}

// What does this program print and why?


