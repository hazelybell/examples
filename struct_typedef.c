#include <stdio.h>

/* A common thing to do is to typedef a struct
 * so that you don't have to type struct whatever
 * so often.
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

Coordinate move_left(Coordinate position) {
    position.x -= 1.0;
    return position;
}

int main() {
    Coordinate position = { 0, 0 };
    printf("position=(%g,%g)\n",
           position.x,
           position.y
    );
    Coordinate new_position = move_left(position);
    printf("position=(%g,%g)\n",
           position.x,
           position.y
    );
    printf("new_position=(%g,%g)\n",
           new_position.x,
           new_position.y
    );
    position = move_left(move_left(position));
    printf("position=(%g,%g)\n",
           position.x,
           position.y
    );
}
