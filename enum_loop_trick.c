#include <stdio.h>
#include <stdlib.h>

// this only works as long as we don't provide our
// own values!

enum flavor {
    VANILLA,
    CHOCOLATE,
    STRAWBERRY,
    N_FLAVORS
};

typedef enum flavor Flavor;

int main() {
    printf("VANILLA=%d\n", VANILLA);
    printf("CHOCOLATE=%d\n", CHOCOLATE);
    printf("STRAWBERRY=%d\n", STRAWBERRY);
    printf("N_FLAVORS=%d\n", N_FLAVORS);
    printf("sizeof(Flavor)=%zu\n",
           sizeof(Flavor));
    
    for (Flavor flavor = 0; flavor < N_FLAVORS; flavor++) {
        switch (flavor) {
            case VANILLA:
                printf("flavor=VANILLA\n");
                break;
            case CHOCOLATE:
                printf("flavor=CHOCOLATE\n");
                break;
            case STRAWBERRY:
                printf("flavor=STRAWBERRY\n");
                break;
            default:
                abort();
        }
    }
}
