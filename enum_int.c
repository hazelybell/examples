#include <stdio.h>
#include <stdlib.h>

enum flavor {
    VANILLA,
    CHOCOLATE,
    STRAWBERRY,
    N_FLAVORS
};

typedef enum flavor Flavor;

// Here we use the fact that enums are really just ints!
Flavor random_flavor() {
    return (rand() % N_FLAVORS);
}

void check_flavor(Flavor flavor) {
    if (flavor >= N_FLAVORS) {
        abort();
    }
    // Since a flavor is just an int, it could be negative...
    if (flavor < 0) {
        abort();
    }
}

const char * get_flavor_name(Flavor flavor) {
    check_flavor(flavor);
    // Here we use "Designated Initializers"!
    const char * const flavor_names[N_FLAVORS] = {
        [CHOCOLATE] = "Hamburger flavor",
        [VANILLA] = "Raspberry",
        [STRAWBERRY] = "Those packets that come in the ramen"
    };
    const char * flavor_name = flavor_names[flavor];
//     if (flavor_name == NULL) {
//         printf("Flavor not found!\n");
//         abort();
//     }
    return flavor_name;
}



int main() {
    Flavor flavor = random_flavor();
    printf(
        "flavor %d = %s\n",
        flavor,
        get_flavor_name(flavor)
    );
}
