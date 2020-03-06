#include <stdio.h>

/* Using pointers to structs is very common.
 * 
 * Using typedef to define a type that is a pointer
 * to a particular kind of struct is also very common
 * to avoid having to write the pointer everywhere.
 * 
 * This allows us to make a sort of 
 * object-like variable.
 */

struct coordinate {
    float x;
    float y;
};

typedef struct coordinate *Coordinate;
typedef struct coordinate *coordinate_t;

// When we have a pointer to a struct, we use
// "->" instead of "." to talk about a field.

void move_left(Coordinate position) {
    position->x -= 1.0;
}

// "ptr->field" is just shorthand for "(*ptr).field"

void move_up(Coordinate position) {
    position->y -= 1.0;
}

int main() {
    struct coordinate position = { 0, 0 };
    printf("position=(%g,%g)\n",
           position.x,
           position.y
    );
    move_left(&position);
    move_up(&position);
    printf("position=(%g,%g)\n",
           position.x,
           position.y
    );
}
