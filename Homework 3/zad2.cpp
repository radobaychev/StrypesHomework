#include <iostream>


bool F_by1(int a, int b, int c) {
    return (!a && !b && !c) || (!a && b && !c) || (!a && b && c) || (a && b && c);
}


bool F_by0(int a, int b, int c) {
    return !((!a && !b && c) || (a && !b && !c) || (a && !b && c) || (a && b && !c));
}

bool F_min(int a, int b, int c){
   return (b && c) || (!a && !c);
}

int main() {

    int a, b, c;
    std::cout << "Enter values for a, b, c (0 or 1): ";
    std::cin >> a >> b >> c;

    
    std::cout << "Result (F_by1): " << F_by1(a, b, c) << std::endl;
    std::cout << "Result (F_by0): " << F_by0(a, b, c) << std::endl;
    std::cout << "Result (F_min): " << F_min(a, b, c) << std::endl;





    return 0;
}
