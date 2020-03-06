#include <stdio.h>
#include <stdlib.h>

enum flavor {
    VANILLA = 100,
    CHOCOLATE = 200,
    STRAWBERRY = 300,
};

typedef enum flavor Flavor;

int main() {
    printf("VANILLA=%d\n", VANILLA);
    printf("CHOCOLATE=%d\n", CHOCOLATE);
    printf("STRAWBERRY=%d\n", STRAWBERRY);
    printf("sizeof(Flavor)=%zu\n",
           sizeof(Flavor));
}
