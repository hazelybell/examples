#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lcs_calls = 0;

int lcs(char s1[], char s2[], int m, int n) {
    lcs_calls++;
    printf("calls: %d\n", lcs_calls);
    if (m == 0) {
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    int a = lcs(s1, s2, m-1, n);
    int b = lcs(s1, s2, m, n-1);
    int c = lcs(s1, s2, m-1, n-1);
    if (s1[m-1] == s2[n-1]) {
        c++;
    }
    if (a >= b && a >= c) {
        return a;
    }
    if (b >= a && b >= c) {
        return b;
    }
    if (c >= a && c >= b) {
        return c;
    }
    printf("Error! Error!\n");
    return 0;
}

int main(int argc, char ** argv) {
    char s1[1001] = "adfasd";
    char s2[1001] = "adfads";
    int m = strlen(s1);
    int n = strlen(s2);
    int length = lcs(s1, s2, m, n);
    printf("LCS length: %d\n", length);
    return 0;
}
