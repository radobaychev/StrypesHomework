#include <iostream>
#include <cmath>

int main()
{
    double n1, n2, n3, max;
    std::cin >> n1 >> n2 >> n3;
    max = std::max(std::max(n1,n2),n3);
    std::cout << "Largest number: " << max << std::endl;
    return 0;
}


//rado@rado-Swift-SF314-56:~/Desktop$ g++ zad4.cpp
//rado@rado-Swift-SF314-56:~/Desktop$ ./a.out <  numbers.txt 
//Largest number: 1.111
