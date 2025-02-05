#include <iostream>
using namespace std;


struct Employee{
    string name;
    int hoursWorked;
    double hourlyRate;
    double totalSalary;
};

Employee* createEmployees(int n){
    Employee* employees = new Employee[n];
    cout << "Employees Created" << endl;
    return employees;
}

void inputDetails(Employee* employees, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Details for Employee " << i+1 << ": " << endl;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Hours Worked: ";
        cin >> employees[i].hoursWorked;
        cout << "Hourly Rate: ";
        cin >> employees[i].hourlyRate;
    }
}

void calcSalary(Employee* employees, int n){
    for (int i = 0; i < n; i++)
    {
        employees[i].totalSalary = 
        employees[i].hourlyRate * employees[i].hoursWorked;
    }
}

void displaySalary(Employee* employees, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Salary for Employee " << i+1 << ": " << 
        employees[i].totalSalary << endl;
    }
    
}

void freeMemory(Employee* employees, int n){
    delete[] employees;
    cout << "Memory Freed" << endl;
}

int main(){
    int size;
    cout << "Enter Size: ";
    cin >> size;
    Employee* employees = createEmployees(size);
    inputDetails(employees, size);
    calcSalary(employees, size);
    displaySalary(employees, size);
    freeMemory(employees, size);

    return 0;
}

