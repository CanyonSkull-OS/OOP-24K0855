//Omer Shahid
//24k-0855

#include <iostream>
using namespace std;

string printArr(string Event1[], string Event2[]){
    cout << "Event 1: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Name " << i+1 << ": " << Event1[i] << endl;
    }
    cout << endl;
    cout << "Event 2: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Name " << i+1 << ": " << Event2[i] << endl;
    }
}

void takeNames(string Event1[], string Event2[]){
    cout << "Enter names for Event 1: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> Event1[i];  
    }
    cout << "Enter names for Event 2: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> Event2[i];  
    }
}

int main(){
    string Event1[5];
    string Event2[5];
    takeNames(Event1, Event2);
    printArr(Event1, Event2);

    return 0;
}

![image](https://github.com/user-attachments/assets/5e7c1f8a-7454-450e-b029-4741c436d619)

