/*
Omer Shahid
24K-0855
*/
#include <iostream>
using namespace std;


int*** create3DArr(int n, int m, int l){
    int*** Arr3D = new int**[n];
    for (int i = 0; i < n; i++)
    {
        Arr3D[i] = new int*[m];
        for (int j = 0; j < l; j++)
        {
            Arr3D[i][j] = new int[l];
        }
    }
    cout << "3D Array created" << endl;
    return Arr3D;
}

void inputDetails(int*** arr, int n, int m, int l){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < l; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }
}

void displayArr(int*** arr, int n, int m, int l){
    cout << "Data: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "| ";
            for (int k = 0; k < l; k++)
            {
                cout << arr[i][j][k] << " | ";
            }
            cout << endl;
        }
        cout << endl;
    }
}


void freeMemory(int*** arr, int n, int m){
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < m; j++)
       {
            delete[] arr[i][j];
       }
        delete[] arr[i];
    }
    delete[] arr;
    cout << "Memory freed" << endl;

}

int main(){
    int size1, size2, size3;
    cout << "Enter Size1: ";
    cin >> size1;
    cout << "Enter Size2: ";
    cin >> size2;
    cout << "Enter Size3: ";
    cin >> size3;
    int*** arr3D = create3DArr(size1, size2, size3);

    inputDetails(arr3D, size1, size2, size3);

    displayArr(arr3D, size1, size2, size3);

    freeMemory(arr3D, size1, size2);

    return 0;
}