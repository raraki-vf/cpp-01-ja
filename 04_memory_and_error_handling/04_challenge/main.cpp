#include <iostream>
#include <stdexcept>
#include <vector>

int element_at(std::vector<int> numbers, int index){
    if (index >= numbers.size()) {
        throw std::out_of_range("Invalid index");
    }
    return numbers[index];
}

int main() {
    std::vector<int> numbers = {1, 3, 5, 7, 9};
    int index;
    int element;

    std::cin >> index;

    try{
        element = element_at(numbers, index);
        std::cout << element << std::endl;
    } catch (const std::out_of_range& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
    
}