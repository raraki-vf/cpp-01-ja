#include <iostream>

int main() {

float num {0.0000f};

std::cout << "Input Number: " << std::endl;
std::cin >> num ;

if (num < 0.0000){
    std::cout << "The Number is Minus." << std::endl;
} else if (num > 0.0000) {
    std::cout << "The Number is Plus." << std::endl;
} else {
    std::cout << "The Number is Zero." << std::endl;
}

return 0;

}