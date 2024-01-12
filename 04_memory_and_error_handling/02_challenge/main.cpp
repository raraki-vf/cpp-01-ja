#include <iostream>

void swap_int(int *pa, int *pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main() {
    int a = 10;
    int b = 20;

    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    
    swap_int(&a, &b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}