#include <iostream>

void multiplyMatrices(int** A, int** B, int** C, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rowsA = 2, colsA = 2, colsB = 2;
    
    int** A = new int*[rowsA];
    int** B = new int*[colsA];
    int** C = new int*[rowsA];
    
    for (int i = 0; i < rowsA; ++i) {
        A[i] = new int[colsA];
        C[i] = new int[colsB];
    }

    for (int i = 0; i < colsA; ++i) {
        B[i] = new int[colsB];
    }

    int value = 1;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            A[i][j] = value++;
        }
    }

    value = 5;
    for (int i = 0; i < colsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            B[i][j] = value++;
        }
    }

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::cout << "Product of matrices:" << std::endl;
    printMatrix(C, rowsA, colsB);

    for (int i = 0; i < rowsA; ++i) {
        delete[] A[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] C;

    for (int i = 0; i < colsA; ++i) {
        delete[] B[i];
    }
    delete[] B;

    return 0;
}
