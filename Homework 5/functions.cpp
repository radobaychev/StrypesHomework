#include <iostream>
#include <cmath>


const double PI = 3.14159265358979323846;
//zad1

double CircleArea(double radius) {
    return PI * radius * radius;
}


//zad2
unsigned long long Factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    else {
       long long result = 1;
        for (int i = 2; i <= num; ++i) {
            result *= i;
        }
        return result;
    }
}

//zad3
bool isPrime(int num) {
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0) {
            
            return false;
        }

    }
    return true;
}

//zad4
int Fibonacci(int n) {
    if (n < 2) {
        return 0;
    }
    int prev = 0;
    int current = 1;
    int next = 0;
    for (int i = 2; i < n; ++i) {
        next = prev + current;
        prev = current;
        current = next;
    }
    return current;
}

//zad5
bool isPalindrome(int num) {
    int reversedNum = 0;
    int origNum = num;
    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return origNum == reversedNum;
}


int main() {
    
    std::cout << "Fibonacci(6): " << Fibonacci(6) << std::endl;
    std::cout << "CircleArea(4): " << CircleArea(4) << std::endl;
    std::cout << "Factorial(10): " << Factorial(10) << std::endl;
    std::cout << std::boolalpha << "Prime?(7): " << isPrime(7) << std::endl;
    std::cout << "Prime(6): " << isPrime(6) << std::endl;
    std::cout << "Palindrome?(121): " << isPalindrome(11) << std::endl;
    std::cout << "Palindrome?(10): " << isPalindrome(10) << std::endl;

    return 0;
}