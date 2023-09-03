#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Simple Calculator\n";
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter an operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
                return 1;
            }
            break;
        default:
            std::cout << "Error: Invalid operation.\n";
            return 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
