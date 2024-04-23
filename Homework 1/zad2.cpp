#include <iostream>
#include <cmath>

//Old formula
void BMIcalcA(double height, double weight)
{
    double bmi = weight / std::pow(height, 2);
    std::cout <<"Your BMI is:" << bmi << std::endl;

}

//New formula
void BMIcalcB(double height, double weight)
{
    double bmi = 1.3*(weight / std::pow(height, 2.5));
    std::cout <<"Your BMI is:" << bmi << std::endl;


}

void GetInfo(double &height, double &weight)
{
    std::cout << "Weight(kg): " << std::endl;
    std::cin >> weight;
    std::cout << "\nHeight(m): " << std::endl;
    std::cin >> height;
}

int main()
{
    double height, weight;
    GetInfo(height, weight);
    BMIcalcA(height, weight);
    BMIcalcB(height, weight);

    return 0;
}
