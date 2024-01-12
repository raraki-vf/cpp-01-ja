#include <iostream>
#include <vector>

std::vector<int> double_elements(const std::vector<int>& numbers){
    std::vector<int> double_numbers = numbers;

    for(int i=0; i<numbers.size(); i++){
        double_numbers[i] = numbers[i]*2;
    }

    return double_numbers;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> double_numbers = double_elements(numbers);

    for(int elements : numbers){
        std::cout << elements << " ";
    }
    std::cout << std::endl;

    for(int elements : double_numbers){
        std::cout << elements << " ";
    }
    std::cout << std::endl;

    return 0;
}