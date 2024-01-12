#include <iostream>

int main() {
    int x = 42;
    std::cout << &x << std::endl;

    int *p = &x;
    std::cout << *p << std::endl;

    return 0;
}