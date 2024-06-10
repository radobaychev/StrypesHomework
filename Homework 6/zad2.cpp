#include <iostream>

void fillArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
}

int findMajority(int arr[], int size){
    int counter = 0;
    int m = 0;
    for(int i = 0; i<size; ++i){
        if(counter == 0){
            m = arr[i];
            counter = 1;
        }else if(m == arr[i]){
            counter += 1;
        }else{
            counter -= 1;
        }
    }
    counter = 0;
    for(int i=0; i < size; ++i){
        if(m == arr[i]){
            counter += 1;
        }
    }
    return counter > size/2 ? m:-1;

}


int main(){
    int size;
    std::cout << "Input size for arr: ";
    std::cin >> size;
    int* arr = new int[size];
    fillArray(arr, size);
    std::cout << findMajority(arr, size);
    
    delete[] arr;

    return 0;
}