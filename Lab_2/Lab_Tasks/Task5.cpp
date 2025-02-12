/*
Omer Shahid
24K-0855
*/
#include <iostream>
using namespace std;


int* createArr(int n){
    int* intArr = new int[n];
    cout << "Array Created" << endl;
    return intArr;
}

void populateArr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Integer " << i+1 << ": " << endl;
        cin >> arr[i];
    }
}

void displayArr(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Integer " << i+1 << ": " << *(arr + i) << endl;
    }
}

void calcSum(int* arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    cout << "Sum of integers: " << sum << endl;
}

void freeMemory(int* arr){
    delete[] arr;
    cout << endl << "Memory Freed" << endl;
}

int main(){
    int size;
    cout << "Enter number of integers: ";
    cin >> size;
    int* array = createArr(size);
    populateArr(array, size);
    displayArr(array, size);
    calcSum(array, size);
    freeMemory(array);

    return 0;
}