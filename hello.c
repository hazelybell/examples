#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	printf("size of a pointer: %zu\n", sizeof(char *));
	printf("square root of 2: %g\n", sqrt(2.0));
	printf("I will now abort...\n");
	abort();
	return 0;
}
