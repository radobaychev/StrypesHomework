#include <iostream>
#include <cmath>

void mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]) {

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j]) {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else {

            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }


    while (i < n1) {
        arr3[k++] = arr1[i++];
    }

    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
}

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

int main()
{
    int n1;
    std::cout << "Insert size fo arr1: ";
    std::cin >> n1;
    int* arr1 = new int[n1];
    fillArray(arr1, n1);

    int n2;
    std::cout << "Insert size fo arr2: ";
    std::cin >> n2;
    int* arr2 = new int[n2];
    fillArray(arr2, n2);

    int* arr3 = new int[n1 + n2];

    mergeArrays(arr1, arr2, n1, n2, arr3);

    std::cout << "Array after merging" << std::endl;
    for (int i = 0; i < n1 + n2; i++) {
        std::cout << arr3[i] << " ";
    }
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}
