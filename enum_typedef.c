#include <stdio.h>
#include <stdlib.h>

enum flavor {
    VANILLA,
    CHOCOLATE,
    STRAWBERRY,
};

typedef enum flavor Flavor;

int main() {
    Flavor favourite = VANILLA;
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
