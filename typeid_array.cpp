#include <iostream>
// From https://stackoverflow.com/a/30438837
#include <typeinfo>
#define printType(a) std::cout << typeid(a).name() << std::endl;
// End from

int main() {
    int array[5];
    printType(array);
    int * array_p = array;
    printType(array_p);
    return 0;
}
