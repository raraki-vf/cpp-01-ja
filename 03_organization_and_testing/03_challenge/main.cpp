#include <iostream>
#include "math_operations.h"

int main(){

    float num1 {0.0};
    float num2 {0.0};
    char operation {'+'};
    float result {0.0};

    std::cout << "Enter a calculation: ";
    std::cin >> num1 >> operation >> num2;

    switch (operation)
    {
    case '+':
        result = MathOps::addition(num1, num2);
        std::cout << "Result: " << result << std::endl;
        break;
    
    case '-':
        result = MathOps::subtraction(num1, num2);
        std::cout << "Result: " << result << std::endl;
        break;

    case '*':
        result = MathOps::multiplication(num1, num2);
        std::cout << "Result: " << result << std::endl;
        break;

    case '/':
        if (num2 != float(0)){
            result = MathOps::division(num1, num2);
            std::cout << "Result: " << result << std::endl;
        } else {
            std::cout << "Result: Invalid Input" << std::endl;
        }
        break;

    default:
        std::cout << "Result: Invalid Input" << std::endl;
        break;
    }

    return 0;

}