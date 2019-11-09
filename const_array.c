#include <stdio.h>

int main(int argc, char ** argv) {
    const char ARRAY[14] = "Hello, world!";
    const char JAY = 'J';
    const float PI = 3.2;
    printf("%s\n", ARRAY);
//     ARRAY[0] = 'J'; // can't do this
    const int GRAPH[5][5] = {
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 1, 1 },
        { 1, 0, 0, 0, 1 },
        { 1, 1, 0, 0, 1 },
        { 0, 1, 1, 1, 0 }
    };
    for (int i = 0; i < 5; i++) {
        printf("Vertex %d is connected to: ", i);
        for (int j = 0; j < 5; j++) {
            if (GRAPH[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            if (i != j) {
                if (GRAPH[i][j] && GRAPH[j][i]) {
                    printf("There's an edge between %d and %d\n", i, j);
                } else if (GRAPH[i][j]) {
                    printf("There's a directed edge from %d to %d\n", i, j);
                } else if (GRAPH[j][i]) {
                    printf("There's a directed edge from %d to %d\n", i, j);
                } else {
                    printf("%d and %d aren't directly connected\n", i, j);
                }
            } else {
                if (GRAPH[i][j]) {
                    printf("%d is connected to itself!", i);
                }
            }
        }
    }
    return 0;
}
