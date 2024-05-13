#include <iostream>
#include <fstream>

int main() {

    std::ifstream file("numbers.txt");
    int num1;
    int num2;

   while (file >> num1 && file >> num2) {
    if (num1 != 0 && num1 != 1) {
        std::cerr << "Error: Invalid input. Please enter 0 or 1." << std::endl;
        return 1;
    }

    if (num2 != 0 && num2 != 1) {
        std::cerr << "Error: Invalid input. Please enter 0 or 1." << std::endl;
        return 1;
    }

    std::cout << "Num1: " << num1 << std::endl;
    std::cout << "Num2: " << num2 << std::endl;
    int result = num1 ^ num2;

    
    std::cout << "Result of XOR operation: " << result << std::endl;
   }
    return 0;
}
