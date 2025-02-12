#include <iostream>
using namespace std;


int** allocateMemory(int rows, int cols){
    int **ptr = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        ptr[i] = new int[cols];
    }
    return ptr;
}

void inputArray(int** ptr, int rows, int cols){
        cout << "Enter 2D Array: " << endl;
    for (int i = 0; i < rows; i++){
        cout << "Enter Elements for row: " << i+1 << endl;
        for (int j = 0; j < cols; j++){
            cout << "Enter Elements for row: " << i+1 << " and col: " << j+1 << ": ";
            cin >> *(*(ptr + i) + j);
        }
    }
}


void freeArray(int** ptr, int rows, int cols){
    cout << "Array's First Element before deletion: " << ptr[0][0] << endl;

    for (int i = 0; i < rows; i++){
        delete[] ptr[i];
    }
    delete[] ptr;

    cout << "Array's First Element after deletion: " << ptr[0][0] << endl;
}

void displayArray(int** ptr, int rows, int cols){
        for (int i = 0; i < rows; i++){
        cout << "| ";
        for (int j = 0; j < cols; j++){
            cout << *(*(ptr + i) + j) << "| ";
        }
        cout << endl;
    }
}


int main(){
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of cols: ";
    cin >> cols;
    
    int** ptr = allocateMemory(rows, cols);
    inputArray(ptr, rows, cols);
    displayArray(ptr, rows, cols);
    freeArray(ptr, rows, cols);




}