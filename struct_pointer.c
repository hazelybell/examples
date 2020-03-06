#include <stdio.h>

/* Using pointers to structs is very common.
 * 
 * This lets us modify them without returning
 * a copy and assigning it over the old value.
 */

struct coordinate {
    float x;
    float y;
};

// We use a capital first letter to indicate a type
// This is a newer style.
typedef struct coordinate Coordinate;
// Or we could use "_t" at the end.
// This is an older style. Remember uint64_t?
typedef struct coordinate coordinate_t;

// When we have a pointer to a struct, we use
// "->" instead of "." to talk about a field.

void move_left(Coordinate *position) {
    position->x -= 1.0;
}

// "ptr->field" is just shorthand for "(*ptr).field"

void move_up(Coordinate *position) {
    (*position).y -= 1.0;
}


int main() {
    Coordinate position = { 0, 0 };
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
