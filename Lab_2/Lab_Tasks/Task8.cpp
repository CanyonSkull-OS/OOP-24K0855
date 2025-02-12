/*
Omer Shahid
24K-0855
*/
#include <iostream>
using namespace std;

int** createPArr(int size, int Esize){
    int** arr = new int*[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[Esize];
    }
    cout << "Array of pointers created" << endl;
    return arr;
}

void populateArr(int** arr, int size, int Esize){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < Esize; j++)
        {
            cout << "Enter Integers for Pointer " << i+1 << ": " << endl;;
            cin >> arr[i][j];
        }
    }
}

void displayArr(int** arr, int size, int Esize){
    cout << "Array: " << endl;
    for (int i = 0; i < size; i++)
    {  
        for(int j = 0; j < Esize; j++){
            cout << arr[i][j] << ", ";
        }
    }
    cout << endl;
}

void freeMemory(int** arr, int size){
    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    cout << "Memory freed" << endl;
}

int main(){
    int size, Esize;
    cout << "Enter size of Array: ";
    cin >> size;
    cout << "Enter size of Elements: ";
    cin >> Esize;

    int** PArr = createPArr(size, Esize);

    populateArr(PArr, size, Esize);

    displayArr(PArr, size, Esize);

    freeMemory(PArr, size);

    return 0;
}