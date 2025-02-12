#include <iostream>
using namespace std;

int main(){
    int var = 300;
    int *ptr = &var;
    int **ptr1 = &ptr;

    cout << "Value of Var: " << var << endl;
    cout << "Address of Var: " << &var << endl;

    cout << "Value of var using ptr: " << *ptr << endl;
    cout << "Address of var using ptr: " << ptr << endl;

    cout << "Address of ptr: " << &ptr << endl;

    cout << "Value of var using ptr1: " << **ptr1 << endl;
    cout << "Address of var using ptr1: " << *ptr1 << endl;
    cout << "Address of ptr using ptr1: " << ptr1 << endl;

    cout << "Address of ptr1: " << ptr1 << endl;


    return 0;
}