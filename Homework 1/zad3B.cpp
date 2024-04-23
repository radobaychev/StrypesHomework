#include <iostream>
#include <cmath>


double calcuateVolume(double H, double R, double L){
    double area = std::acos((R-H)/R)*R*R-(R-H)*std::sqrt(2*R*H-H*H);
    double volume = area * L;
    std::cout << std::acos((R-H)/R)*R*R;
    return volume;
}


int main(){
    double H, R, L;
    std::cout << "Insert H(m), R(m) and L(m):";
    std::cin >> H >> R >> L;
    std::cout << calcuateVolume(H, R, L) << std::endl;
    return 0;
}
