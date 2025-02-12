/*
Omer Shahid
24K-0855
*/
#include <iostream>
using namespace std;


int** createMatrice(int rows, int cols){
    int** matrice = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrice[i] = new int[cols];
    }
    cout << "Matrice Created" << endl;
    return matrice;
}

void populateMatrice(int** matrice, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter Values for Row " << i+1 << endl;
        for (int j = 0; j < cols; j++)
        {
            cin >> matrice[i][j];
        }
    }
    cout << "Matrice Populated" << endl << endl;

}



void addMatrices(int** matrice1, int** matrice2, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrice1[i][j] += matrice2[i][j];
        }
    }
    cout << "Matrices Added" << endl;
}

void subtractMatrices(int** matrice1, int** matrice2, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrice1[i][j] -= matrice2[i][j];
        }
    }
    cout << "Matrices Subtracted" << endl;
}

void displayMatrice(int** matrice1, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        cout << "| ";
        for (int j = 0; j < cols; j++)
        {
            cout << matrice1[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}


void freeMemory(int** matrice1, int** matrice2, int rows){
    for (int i = 0; i < rows; i++)
    {
        delete[] matrice1[i];
    }
    delete[] matrice1;
    cout << endl << "Memory freed for Matrice 1" << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] matrice2[i];
    }
    delete[] matrice2;
    cout << endl << "Memory freed for Matrice 2" << endl;
}

int main(){
    int rows, cols;
    cout << "Enter Rows: ";
    cin >> rows;
    cout << "Enter Cols: ";
    cin >> cols;
    int** matrice1 = createMatrice(rows, cols);
    int** matrice2 = createMatrice(rows, cols);
    populateMatrice(matrice1, rows, cols);
    populateMatrice(matrice2, rows, cols);
    displayMatrice(matrice1, rows, cols);
    addMatrices(matrice1, matrice2, rows, cols);
    displayMatrice(matrice1, rows, cols);
    freeMemory(matrice1, matrice2, rows);

    return 0;

}