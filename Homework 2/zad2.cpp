#include <iostream>
#include <cmath>
#include <limits>

// Function to compare two floating-point numbers with a specified epsilon (defaulting to machine epsilon)
bool compareFloats(float a, float b, float epsilon = std::numeric_limits<float>::epsilon()) {
    return std::fabs(a - b) < epsilon;
}

// Function to compare two double-precision floating-point numbers with a specified epsilon (defaulting to machine epsilon)
bool compareDoubles(double a, double b, double epsilon = std::numeric_limits<double>::epsilon()) {
    return std::fabs(a - b) < epsilon;
}

int main() {
    int correctFloatComparisons = 0;
    int incorrectFloatComparisons = 0;

    // Tests for comparing float numbers
    float float1 = 0.1f;
    float float2 = 0.2f;
    float float3 = 0.3f;

    if (compareFloats(float1 + float2, float3)) {
        std::cout << "Float addition is consistent with comparison." << std::endl;
        correctFloatComparisons++;
    } else {
        std::cout << "Float addition is NOT consistent with comparison." << std::endl;
        incorrectFloatComparisons++;
    }

    int correctDoubleComparisons = 0;
    int incorrectDoubleComparisons = 0;

    // Tests for comparing double numbers
    double double1 = 0.1;
    double double2 = 0.2;
    double double3 = 0.3;

    if (compareDoubles(double1 + double2, double3)) {
        std::cout << "Double addition is consistent with comparison." << std::endl;
        correctDoubleComparisons++;
    } else {
        std::cout << "Double addition is NOT consistent with comparison." << std::endl;
        incorrectDoubleComparisons++;
    }

    std::cout << "Float comparisons: Correct = " << correctFloatComparisons << ", Incorrect = " << incorrectFloatComparisons << std::endl;
    std::cout << "Double comparisons: Correct = " << correctDoubleComparisons << ", Incorrect = " << incorrectDoubleComparisons << std::endl;

    return 0;
}
