#include <iostream>
#include <cmath>


double waterVolume(double H, double R){
    double volume = 3.14159*R*R*H;
    return volume;
}


int main(){
    double H, R;
    std::cout << "Insert H and R:";
    std::cin >> H >> R;
    std::cout << waterVolume(H, R) << std::endl;
    return 0;
}
