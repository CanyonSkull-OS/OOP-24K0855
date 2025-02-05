#include <iostream>
#include <string>
using namespace std;


string* createStringArr(int numstr){
    string* arr = new string[numstr];
    return arr;
}

void populateArr(string* arr, int numstr){
    for (int i = 0; i < numstr; i++)
    {
        cout << "Enter String " << i+1 << ": ";
        getline(cin, arr[i]);
    }
}

void sortStrings(string* arr, int numstr){
    string temp;
    for (int i = 0; i < numstr; i++)
    {
        for (int j = 0; j < numstr-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } 
    }
    cout << "Strings sorted" << endl;
}

void displayStrings(string* arr, int numstr){
    cout << endl;
    for (int i = 0; i < numstr; i++)
    {
        cout << "String " << i+1 << ": " << arr[i] << endl;
    }
    cout << endl;
}

void freeMemory(string* arr){
    delete[] arr;
    cout << "Memory Freed" << endl;
}

int main(){
    int numstr;
    cout << "Enter number of strings: ";
    cin >> numstr;
    cin.ignore();
    string* strarray = createStringArr(numstr);
    populateArr(strarray, numstr);
    displayStrings(strarray, numstr);
    sortStrings(strarray, numstr);
    displayStrings(strarray, numstr);
    freeMemory(strarray);

    return 0;
}