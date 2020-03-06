#include <stdio.h>
#include <stdlib.h>

enum flavor {
    VANILLA,
    CHOCOLATE,
    STRAWBERRY,
};

int main() {
    printf("VANILLA=%d\n", VANILLA);
    printf("CHOCOLATE=%d\n", CHOCOLATE);
    printf("STRAWBERRY=%d\n", STRAWBERRY);
    printf("sizeof(enum flavor)=%zu\n",
           sizeof(enum flavor));
    
    enum flavor favourite = VANILLA;
    printf("favourite=%d\n", favourite);
    printf("sizeof(favourite)=%zu\n",
           sizeof(favourite));
    
    switch (favourite) {
        case VANILLA:
            printf("favourite=VANILLA\n");
            break;
        case CHOCOLATE:
            printf("favourite=CHOCOLATE\n");
            break;
        case STRAWBERRY:
            printf("favourite=STRAWBERRY\n");
            break;
        default:
            abort();
    }
}
