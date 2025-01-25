//Omer Shahid
//24k-0855

//Task 1
#include <iostream>
using namespace std;

void printArr(string Event1[], string Event2[], int num1, int num2){
    cout << endl << "Event 1: " << endl;
    for (int i = 0; i < num1; i++)
    {
        cout << "Name " << i+1 << ": " << Event1[i] << endl;
    }
    cout << endl;
    cout << "Event 2: " << endl;
    for (int i = 0; i < num2; i++)
    {
        cout << "Name " << i+1 << ": " << Event2[i] << endl;
    }
}

void takeNames(string Event1[], string Event2[], int num1, int num2){
    cout << "Enter names for Event 1: " << endl;
    for (int i = 0; i < num1; i++)
    {
        cin >> Event1[i];
    }
    cout << "Enter names for Event 2: " << endl;
    for (int i = 0; i < num2; i++)
    {
        cin >> Event2[i];  
    }
}


//Task 2
void checkParticipant(string Event1[], string Event2[], int num1, int num2){
    string name;
    cout << endl << "Enter Name to search: ";
    cin >> name;
    for (int i = 0; i < num1; i++)
    {
        if (Event1[i] == name){
            cout << name << " is registered in Event 1" << endl;
        }     
    }
    for (int i = 0; i < num2; i++)
    {
        if (Event2[i] == name){
            cout << name << " is registered in Event 2" << endl;
        }     
    }
}


//Task 3
int calculateDonations(int num1, int num2){
    int sum = 0;
    for (int i = 0; i < num1; i++)
    {
        sum += 10;
    }
    for (int i = 0; i < num2; i++)
    {
        sum += 10;
    }
    return sum;
}


//Task 4
void displayReverse(string Event1[], string Event2[], int num1, int num2){
    cout << "Displaying in Reverse" << endl << "Event 1: " << endl;
    for (int i = num1-1; i >= 0; i--)
    {
        cout << "Name " << i+1 << ": " << Event1[i] << endl;
    }
    cout << endl;
    cout << "Event 2: " << endl;
    for (int i = num2-1; i >= 0; i--)
    {
        cout << "Name " << i+1 << ": " << Event2[i] << endl;
    }
}


//Task 5
void displayBarChart(int num1, int num2){
    cout << endl << "Bar Chart" << endl << "Event1: ";
    for (int i = 0; i < num1; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "Event2: ";
    for (int i = 0; i < num2; i++)
    {
        cout << "*";
    }
}



int main(){
    string Event1[5], Event2[5];
    int num1, num2;
    cout << "Enter Number of Participants for Event 1: ";
    cin >> num1;
    cout << "Enter Number of Participants for Event 2: ";
    cin >> num2;
    takeNames(Event1, Event2, num1, num2);
    printArr(Event1, Event2, num1, num2);
    checkParticipant(Event1, Event2, num1, num2);
    int sum = calculateDonations(num1, num2);
    cout << "Total Donations: " << sum << endl;
    displayReverse(Event1, Event2, num1, num2);
    displayBarChart(num1, num2);
    return 0;
}

