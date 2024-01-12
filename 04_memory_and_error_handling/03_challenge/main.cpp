#include <iostream>
#include <vector>

std::vector<int> double_elements(std::vector<int> numbers){

    for(int i=0; i<numbers.size(); i++){
        numbers[i] = numbers[i]*2;
    }

    return numbers;
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