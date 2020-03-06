#include <stdio.h>

/* The important thing to notice here is that
 * structs are pass-by-value. Just like a single float,
 * when we pass a struct to a function it gets a COPY
 * of the original struct!
 * We can also assign structs and we get a COPY.
 * We can also return structs and we get a COPY.
 */

struct coordinate {
    float x;
    float y;
};

struct coordinate move_left(struct coordinate position) {
    position.x -= 1.0;
    return position;
}

int main() {
    struct coordinate position = { 0, 0 };
    printf("position=(%g,%g)\n",
           position.x,
           position.y
    );
    struct coordinate new_position = move_left(position);
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
