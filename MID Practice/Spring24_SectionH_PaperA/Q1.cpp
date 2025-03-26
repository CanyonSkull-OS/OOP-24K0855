#include <iostream>
using namespace std;


class Employee{
    static int nextEmployeeID;
    static const float MAX_SALARY;

    int employeeID;
    string name;
    float salary;
    
    
    public:
    Employee(string n) : name(n), salary(0){
        employeeID = generateEmployeeID();
    }
    
    
    static int generateEmployeeID(){
        return nextEmployeeID++;
    }
    
    void setSalary(float s){
        salary = (s > MAX_SALARY) ? MAX_SALARY : s;
    }
    
    void displayEmployeeInfo(){
        cout << "ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

int Employee::nextEmployeeID = 1;
const float Employee::MAX_SALARY = 50000;

int main(){
    Employee e1("Ahmed");
    Employee e2("Hamza");


    e1.setSalary(20000);
    e2.setSalary(60000);

    e1.displayEmployeeInfo();
    e2.displayEmployeeInfo();


    return 0;
}