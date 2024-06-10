#include <iostream>

void rotateMatrix(int** matrix, int N) {
    for (int x = 0; x < N / 2; x++) {
        for (int y = x; y < N - x - 1; y++) {
            int temp = matrix[x][y];
            matrix[x][y] = matrix[N - 1 - y][x];
            matrix[N - 1 - y][x] = matrix[N - 1 - x][N - 1 - y];
            matrix[N - 1 - x][N - 1 - y] = matrix[y][N - 1 - x];
            matrix[y][N - 1 - x] = temp;
        }
    }
}

void printMatrix(int** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int N = 3;
    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[N];
    }

    int value = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = value++;
        }
    }

    std::cout << "Original matrix:" << std::endl;
    printMatrix(matrix, N);

    rotateMatrix(matrix, N);

    std::cout << "Rotated matrix:" << std::endl;
    printMatrix(matrix, N);

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
