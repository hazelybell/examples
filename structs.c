#include <stdio.h>

/* Structs let us create a new type out of a sequence
 * of fields with their own types.
 * 
 * Of course, the struct will take at least as much 
 * memory as all of the fields do.
 */

struct coordinate {
    float x;
    int y;
};

int main() {
    struct coordinate position = { 0, 0 };
    printf("Currently at: (%g,%d)\n",
           position.x,
           position.y
    );
    printf("sizeof(position.x)=%zu\n",
           sizeof(position.x));
    printf("sizeof(position.y)=%zu\n",
           sizeof(position.y));
    printf("sizeof(position)=%zu\n",
           sizeof(position));
}
