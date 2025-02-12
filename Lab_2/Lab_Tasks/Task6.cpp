/*
Omer Shahid
24K-0855
*/
#include <iostream>
using namespace std;

struct Student{
    string name;
    int rollNumber;
    int marks[3];
};


Student* createArr(int n){
    Student* stdArr = new Student[n];
    cout << "Array of students Created" << endl;
    return stdArr;
}


void inputDetails(Student* stdarr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Details for student " << i+1 << ": " << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, stdarr[i].name);
        cout << "Roll Number: ";
        cin >> stdarr[i].rollNumber;
        for (int j = 0; j < 3; j++)
        {
            cout << "Marks for subject " << j+1 << ": ";
            cin >> stdarr[i].marks[j];
        }
        
    }
    
}

double* calcMarks(Student* arr, int n){
    double* avg = new double[n];
    for (int i = 0; i < n; i++)
    {
        avg[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            avg[i] += arr[i].marks[j];
        }
        avg[i] /= 3;
    }
    return avg;
}

void displayAvg(Student* stdarr,double* avg, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Average of " << stdarr[i].name << ": " 
        << avg[i] + 0.0 << endl;
    }
    
}

int main(){
    int size;
    cout << "Enter number of students: ";
    cin >> size;
    Student* arr = createArr(size);
    inputDetails(arr, size);
    double* avg = calcMarks(arr, size);
    displayAvg(arr, avg, size);


    return 0;
}