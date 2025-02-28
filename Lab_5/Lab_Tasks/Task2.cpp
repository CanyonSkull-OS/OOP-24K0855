#include <iostream>
using namespace std;

class Student {
    int ID;
    string name;
    int* examScores;
    int size;

public:
    Student(int id, string n, int examScoreArr[], int s) : ID(id), name(n), size(s) {
        examScores = new int[size];
        for (int i = 0; i < size; i++) {
            examScores[i] = examScoreArr[i];
        }
    }

    Student(const Student &obj) {
        ID = obj.ID;
        name = obj.name;
        size = obj.size;
        examScores = new int[size];
        for (int i = 0; i < size; i++) {
            examScores[i] = obj.examScores[i];
        }
    }

    ~Student() {
        delete[] examScores; 
    }

    void displayDetails() {
        cout << "ID: " << &ID << endl;
        cout << "Name: " << &name << endl;
        cout << "Exam Scores: ";
        for (int i = 0; i < size; i++) {
            cout << &examScores[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter number of exams: ";
    cin >> size;

    int* ES = new int[size]; 
    cout << "Enter exam scores: ";
    for (int i = 0; i < size; i++) {
        cin >> ES[i];
    }

    
    Student std1(123, "Omer", ES, size);
    Student std2(std1); 

    std1.displayDetails();
    std2.displayDetails();

    delete[] ES; 

    return 0;
}
