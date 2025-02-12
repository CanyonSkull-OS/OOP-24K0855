/*
Omer Shahid
24K-0855
*/
#include <iostream>
using namespace std;

int** createMatrice(int row, int col) {
    int** matrice = new int*[row];
    for (int i = 0; i < row; i++) {
        matrice[i] = new int[col];
    }
    cout << "Matrice Created" << endl;
    return matrice;
}

void populateMatrice(int** matrice, int row, int col) {
    for (int i = 0; i < row; i++) {
        cout << "Enter Values for Row " << i + 1 << ": " << endl;
        for (int j = 0; j < col; j++) {
            cin >> matrice[i][j];
        }
    }
    cout << "Matrice populated" << endl;
}

int** multiplyMatrice(int** matrice1, int** matrice2, int row1, int col1, int col2) {
    int** resultMatrice = createMatrice(row1, col2); 
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            resultMatrice[i][j] = 0;
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                resultMatrice[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }
    return resultMatrice;
}

void displayMatrice(int** matrice, int row, int col) {
    for (int i = 0; i < row; i++) {
        cout << "| ";
        for (int j = 0; j < col; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

void freeMemory(int** matrice, int row) {
    for (int i = 0; i < row; i++) {
        delete[] matrice[i];
    }
    delete[] matrice;
    cout << "Memory freed" << endl;
}

int main() {
    int row1, col1, row2, col2;

    cout << "Enter Rows for Matrix 1: ";
    cin >> row1;
    cout << "Enter Cols for Matrix 1: ";
    cin >> col1;

    cout << "Enter Rows for Matrix 2: ";
    cin >> row2;
    cout << "Enter Cols for Matrix 2: ";
    cin >> col2;


    int** matrice1 = createMatrice(row1, col1);
    int** matrice2 = createMatrice(row2, col2);

    cout << "Populate Matrice 1:" << endl;
    populateMatrice(matrice1, row1, col1);

    cout << "Populate Matrice 2:" << endl;
    populateMatrice(matrice2, row2, col2);

    cout << "Matrice 1:" << endl;
    displayMatrice(matrice1, row1, col1);

    cout << "Matrice 2:" << endl;
    displayMatrice(matrice2, row2, col2);

    int** resMatrice = multiplyMatrice(matrice1, matrice2, row1, col1, col2);

    cout << "Resultant Matrix:" << endl;
    displayMatrice(resMatrice, row1, col2);

    freeMemory(matrice1, row1);
    freeMemory(matrice2, row2);
    freeMemory(resMatrice, row1);

    return 0;
}
