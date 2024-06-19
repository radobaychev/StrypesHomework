#include <iostream>
#include <cassert>

struct SparseMatrix {
    // FIXME
    int rows;
    int cols;
    int* offsets;
    int* data;
    int* rowIndex;
    int* colIndex;
};

// Алокира памет за компресираното представяне + каквато помощна информация е необходима,
// извършва компресирането и връща структура, съдържаща всички данни.
// ВАЖНО: не можем да сметнем предварително колко памет ще е нужна за компресирането
// => за целите на това домашно може да алокирате масив с размер numRows*numCols, и да попълвате в него.
SparseMatrix makeSparse(const int* mat[], const int numRows, const int numCols) {
    // FIXME
    int size = numRows*numCols;
    SparseMatrix sm{numRows, numCols, new int[numRows], new int[size], new int[size], new int[size]};

    int offset = 0;
    for(int row = 0; row < numRows; ++row){
        for(int col = 0; col < numCols; ++col){
            if(sm.data[offset + col] != 0 && mat[row][col] != 0){
                col = -1;
                offset++;
            }
        }
        sm.offsets[row] = offset;
        for(int col = 0; col < numCols; ++col){
            if(mat[row][col] != 0){
                int pos = offset + col;

                sm.data[pos] = mat[row][col];
                sm.rowIndex[pos] = row;
                sm.colIndex[pos] = col;
            }
        }
    }

    return sm;
}

// Връща елемента на дадената позиция в оригиналната матрица.
int get(const SparseMatrix& sm, const int row, const int col) {
    // FIXME: проверка дали row и col са валидни индекси
    assert(row >= 0 && row < sm.rows && col >= 0 && col <= sm.cols);
    
    if(sm.rowIndex[sm.offsets[row] + col] != row || sm.colIndex[sm.offsets[row] + col] != col){
        return 0;
    }

    return sm.data[sm.offsets[row] + col];
}

// Освобождава паметта, алокирана в makeSparse() и съхранена в член-данните на sm.
void freeSparse(SparseMatrix& sm) {
    // FIXME
    delete[] sm.offsets;
    delete[] sm.data;
    delete[] sm.rowIndex;
    delete[] sm.colIndex;
}

void testEasy(const int* mat[], const int numRows, const int numCols) {
    SparseMatrix sm = makeSparse(mat, numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            assert(mat[i][j] == 0 || mat[i][j] == get(sm, i, j)); 
        }
    }
    freeSparse(sm);
}

void testHard(const int* mat[], const int numRows, const int numCols) {
    SparseMatrix sm = makeSparse(mat, numRows, numCols);
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            // Проблем: ако mat[i][j] == 0, в компресираното представяне може
            // тази дупка да е била запълнена от елемент от различен ред :(
            // Как можем да ги различим с възможно най-малко допълнителна информация, съхранявана в SparseMatrix обекта?
            assert(mat[i][j] == get(sm, i, j));
        }
    }
    freeSparse(sm);
}

int main(){
    
    return 0;
}
